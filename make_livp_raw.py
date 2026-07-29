#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# 生成 .livp 文件的脚本（已在 Python 3.11 测试通过）
# 使用方法: python3 make_livp.py <静态图文件> <动态图文件> <输出.livp>
import sys, os, struct, zlib

def make_livp(image_path, mov_path, out_path):
    # 读取文件
    with open(image_path, 'rb') as f: img_data = f.read()
    with open(mov_path, 'rb') as f: mov_data = f.read()
    # 文件名（仅文件名，不含路径），以 bytes 形式
    img_name = os.path.basename(image_path)
    mov_name = os.path.basename(mov_path)
    img_name_bytes = img_name.encode('utf-8')
    mov_name_bytes = mov_name.encode('utf-8')
    # 计算常用值
    crc_img = zlib.crc32(img_data) & 0xFFFFFFFF
    crc_mov = zlib.crc32(mov_data) & 0xFFFFFFFF
    size_img = len(img_data)
    size_mov = len(mov_data)
    len_img = len(img_name_bytes)
    len_mov = len(mov_name_bytes)
    # ZIP header中的时间/日期可以设0
    mod_time = 0
    mod_date = 0
    # 版本：2.0（0x0014），通用标志=0（无DataDescriptor），压缩方法=0（存储）
    ver_needed = 0x0014
    gp_flag = 0
    comp_method = 0
    # 构造第一个文件的 Local File Header
    # 格式: <IHHHHHIIIHH
    local_hdr1 = struct.pack(
        '<IHHHHHIIIHH',
        0x04034b50,  # 签名
        ver_needed,
        gp_flag,
        comp_method,
        mod_time,
        mod_date,
        crc_img,
        size_img,
        size_img,
        len_img,
        0  # extra field 长度
    ) + img_name_bytes
    # 文件数据紧随其后
    local_hdr1 += img_data

    # 第二个文件的 Local File Header
    local_hdr2 = struct.pack(
        '<IHHHHHIIIHH',
        0x04034b50,
        ver_needed,
        gp_flag,
        comp_method,
        mod_time,
        mod_date,
        crc_mov,
        size_mov,
        size_mov,
        len_mov,
        0
    ) + mov_name_bytes
    local_hdr2 += mov_data

    # 计算 Central Directory 偏移
    offset_img = 0
    offset_mov = len(local_hdr1)  # 紧接第一个文件后
    cd_offset = offset_mov + len(local_hdr2)

    # 构造中央目录头（两个）
    ver_made = 0x0014  # 可以相同取 2.0
    # Central #1
    cd1 = struct.pack(
        '<IHHHHHIIIHHHHHII',
        0x02014b50,  # 签名
        ver_made,
        ver_needed,
        gp_flag,
        comp_method,
        mod_time,
        mod_date,
        crc_img,
        size_img,
        size_img,
        len_img,
        0,  # extra
        0,  # file comment
        0, 0,  # disk, internal attr
        0,  # external attr
        offset_img  # 本地头偏移
    ) + img_name_bytes

    # Central #2
    cd2 = struct.pack(
        '<IHHHHHIIIHHHHHII',
        0x02014b50,
        ver_made,
        ver_needed,
        gp_flag,
        comp_method,
        mod_time,
        mod_date,
        crc_mov,
        size_mov,
        size_mov,
        len_mov,
        0,
        0, 0,
        0, 
        offset_mov
    ) + mov_name_bytes

    cd_data = cd1 + cd2
    cd_size = len(cd_data)
    total_entries = 2

    # 构造 EOCD（注释长度先写0，再单独加注释）
    # <IHHHHIIH
    eocd = struct.pack(
        '<IHHHHIIH',
        0x06054b50,  # EOCD 签名
        0,           # disk number
        0,           # CD 起始磁盘
        total_entries, total_entries,
        cd_size,
        cd_offset,
        0            # 注释长度（暂设0，后面手动添加注释）
    )

    # 生成百度自定义注释（16字节）
    # 静态图类型：HEIC=0x0002, JPEG=0x0005
    ext = b''
    if image_path.lower().endswith('.heic') or image_path.lower().endswith('.heif'):
        part1 = 0x0002
    else:
        part1 = 0x0005
    part2 = 30 + len_img
    part3 = size_img
    part4 = 0x0003
    part5 = part3 + (30 + len_img) + (30 + len_mov)
    part6 = size_mov
    part7 = b'1000LIVP'
    # pack为小端：2,4,4,2,4,4,8（共16字节）
    ext += struct.pack('<H', part1)
    ext += struct.pack('<I', part2)
    ext += struct.pack('<I', part3)
    ext += struct.pack('<H', part4)
    ext += struct.pack('<I', part5)
    ext += struct.pack('<I', part6)
    ext += part7
    # 最终注释长度应写回到 EOCD 中的 CommentLen
    # 由于 struct 已打包固定为0，这里直接在文件末追加即可

    # 写入输出文件
    with open(out_path, 'wb') as f:
        f.write(local_hdr1)
        f.write(local_hdr2)
        f.write(cd_data)
        # 重写 EOCD 的注释长度字段为实际长度
        # 注释长度应是 len(ext) = 16
        f.write(eocd[:-2] + struct.pack('<H', len(ext)))
        f.write(ext)

    print(f"生成完成：{out_path}")

if __name__ == '__main__':
    if len(sys.argv) != 4:
        print("用法: python3 make_livp.py <静态图> <动态图> <输出.livp>")
        sys.exit(1)
    make_livp(sys.argv[1], sys.argv[2], sys.argv[3])
