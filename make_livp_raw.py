# make_livp_raw.py
import sys, os, struct, binascii, time

def calc_crc_size(filepath):
    """计算文件的CRC32和大小（流式处理）"""
    crc = 0
    size = 0
    with open(filepath, 'rb') as f:
        while True:
            chunk = f.read(8192)
            if not chunk:
                break
            size += len(chunk)
            crc = binascii.crc32(chunk, crc)
    return crc & 0xFFFFFFFF, size

def dos_date_time(timestamp=None):
    """返回DOS格式的日期和时间字段"""
    if timestamp is None:
        timestamp = time.time()
    t = time.localtime(timestamp)
    dos_time = (t.tm_hour << 11) | (t.tm_min << 5) | (t.tm_sec // 2)
    dos_date = ((t.tm_year - 1980) << 9) | (t.tm_mon << 5) | t.tm_mday
    return dos_time, dos_date

def pack_livp(static_path, dynamic_path, output_path):
    # 读取文件名和计算CRC/大小
    static_name = os.path.basename(static_path)
    dynamic_name = os.path.basename(dynamic_path)
    static_crc, static_size = calc_crc_size(static_path)
    dynamic_crc, dynamic_size = calc_crc_size(dynamic_path)

    # DOS 时间日期
    dos_time, dos_date = dos_date_time()

    # 准备注释字段
    # 静态类型
    ext1 = static_name.split('.')[-1].lower()
    part1 = b'\x00\x02' if ext1 in ('heic','heif') else b'\x00\x05'
    part4 = b'\x00\x03'  # MOV

    part2 = struct.pack('>L', 30 + len(static_name))
    part3 = struct.pack('>L', static_size)
    part5 = struct.pack('>L', static_size + 30 + len(static_name) + 30 + len(dynamic_name))
    part6 = struct.pack('>L', dynamic_size)
    part7 = b"1000LIVP".encode('ascii')  # ASCII to bytes, is 8 bytes

    comment = part1 + part2 + part3 + part4 + part5 + part6 + part7
    comment_len = len(comment)

    # 计算偏移
    # 第一个本地头在0位置
    local1_offset = 0
    lh1_len = 30 + len(static_name)
    local2_offset = local1_offset + lh1_len + static_size
    lh2_len = 30 + len(dynamic_name)
    central_offset = local1_offset + lh1_len + static_size + lh2_len + dynamic_size

    # 构造第一个本地头（静态图）
    with open(output_path, 'wb') as f:
        # Local Header 1
        f.write(struct.pack('<IHHHHHLLLHH',
            0x04034b50,     # 本地头签名
            0x000A,         # 版本（最低解压）
            0x0000,         # 标志位
            0x0000,         # 压缩方法（store）
            dos_time,       # 时间
            dos_date,       # 日期
            static_crc,     # CRC-32
            static_size,    # 压缩后大小
            static_size,    # 原始大小
            len(static_name),  # 文件名长度
            0               # 扩展字段长度
        ))
        f.write(static_name.encode('utf-8'))
        # 写入静态图数据
        with open(static_path, 'rb') as fs:
            while True:
                chunk = fs.read(8192)
                if not chunk: break
                f.write(chunk)

        # Local Header 2 (动态图)
        f.write(struct.pack('<IHHHHHLLLHH',
            0x04034b50,     # 本地头签名
            0x000A,         # 版本
            0x0000,         # 标志位
            0x0000,         # 压缩方法
            dos_time,
            dos_date,
            dynamic_crc,
            dynamic_size,
            dynamic_size,
            len(dynamic_name),
            0
        ))
        f.write(dynamic_name.encode('utf-8'))
        with open(dynamic_path, 'rb') as fd:
            while True:
                chunk = fd.read(8192)
                if not chunk: break
                f.write(chunk)

        # Central Directory Entry 1 (静态图)
        f.write(struct.pack('<IHHHHHHLLLHHHHHLL',
            0x02014b50,     # Central dir 签名
            0x0014,         # 版本made by
            0x000A,         # 版本needed
            0x0000,         # 标志
            0x0000,         # 压缩方法
            dos_time, dos_date,
            static_crc,
            static_size,
            static_size,
            len(static_name), 0, 0, 0, 0,
            0x0000,         # 内部属性
            0x00000000,     # 外部属性
            local1_offset   # 本地头偏移
        ))
        f.write(static_name.encode('utf-8'))

        # Central Directory Entry 2 (动态图)
        f.write(struct.pack('<IHHHHHHLLLHHHHHLL',
            0x02014b50,
            0x0014,
            0x000A,
            0x0000,
            0x0000,
            dos_time, dos_date,
            dynamic_crc,
            dynamic_size,
            dynamic_size,
            len(dynamic_name), 0, 0, 0, 0,
            0x0000,
            0x00000000,
            local2_offset
        ))
        f.write(dynamic_name.encode('utf-8'))

        # EOCD 记录
        cd_size = (46 + len(static_name)) + (46 + len(dynamic_name))
        f.write(struct.pack('<IHHHHLLH',
            0x06054b50,   # EOCD 签名
            0x0000,       # 本磁盘号
            0x0000,       # CD 起始磁盘
            0x0002,       # 本磁盘条目数
            0x0002,       # 总条目数
            cd_size,
            central_offset,
            comment_len
        ))
        # 写入自定义注释
        f.write(comment)

if __name__ == '__main__':
    if len(sys.argv) != 4:
        print("用法: python make_livp_raw.py 静态图.heic 视频.mov 输出.livp")
        sys.exit(1)
    static_file = sys.argv[1]
    dynamic_file = sys.argv[2]
    out_file = sys.argv[3]
    pack_livp(static_file, dynamic_file, out_file)
    print(f"生成完成: {out_file}")
