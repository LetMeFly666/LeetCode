---
title: iOS：压缩和解压live图(.livp)——百度一刻相册+百度网盘识别支持
date: 2026-07-04 19:38:47
tags: [VsCode, 简单, Mac, MacOS, iPhone, iOS, 百度网盘, 一刻相册, 照片同步]
categories: [技术思考]
description: 市面上首篇把静态图+mov短视频打包回live图的方案
excerpt: 市面上首篇把静态图+mov短视频打包回live图的方案
---

市面上首篇把静态图+mov短视频打包回live图的方案。

<!-- more -->

# iOS：压缩和解压live图(.livp)——百度一刻相册+百度网盘识别支持

> 重磅好文!

## 背景

iPhone拍照的live图实际上是一个静态图+一个短视频，如果你把它导入电脑会得到一个文件夹(里面为xx.heic静态图+xx.mov短视频)，如果你把它导入网盘或照片同步工具(如一刻相册)则会得到一个.livp格式的文件(其实是xx.heic静态图和xx.mov短视频的zip)。

截至<span title="2026-07-04 19:38:47">今日</span>市面上有**大量**的 live图/.livp文件 解压或转静态图的方案，但**未能找到任何**关于如何把 .heic静态图+.mov短视频 压缩/打包 回软件可以识别的live图的方案。(直接压缩为zip的话网盘/第三方相册识别不了的)

经过一个下午的研究，终于找到了*稳定的*可以把 静态图+短视频 打包回 百度网盘和一刻相册可以直接识别的(.livp格式)live图的方案。

## livp文件组成介绍

首先需要明确的是，.livp文件的得到方式是 xx.heic静态图+xx.mov短视频 这两个文件直接压缩为.zip压缩包，然后修改后缀.zip为.livp。

关于网盘/第三方相册能否识别的核心就在于压缩为.zip时候的具体压缩方式。具体的zip压缩需要满足以下几点：

1. 不压缩（别扭吗？不别扭）。`zip`命令添加参数`-0`代表只打包不做压缩，保持原始字节。
2. 去掉额外的文件属性（eXclude extra file attributes）。`zip`命令添加参数`-X`代表 不保存文件的Unix UID/GID等信息。
3. 注释。还需要使用`-z`参数给`.zip`文件添加形如`0002000000300022175F0003002217BE003D8A51313030304C495650`的注释，用来快速获取原始文件数据在zip文件中的位置信息。

至于*注释*是什么含义？*注释*一共有以下几部分组成：

```
0002 00000030 000E26AB 0003 000E270A 004B806E 313030304C495650
0002 00000030 0010B331 0003 0010B390 004208DB 313030304C495650
part1  part2    part3  part4  part5   part6       part7
```

+ part1: 0002
+ part2: 00000030
+ part3: heic字节数(16进制)
+ part4: 0003
+ part5: part3+0x5F
+ part6: mov字节数(16进制)
+ part7: 313030304C495650(ASCII含义为1000LIVP)

part3和part6的8位的字节数最大$2^{4\times 8}-1$字节也就是4 GiB - 1（实际上由于part5=part3+95字节所以最大静态图的大小为4GiB-96字节，最大动态小视频的大小为4GiB-1字节）。

part1、part2、part4、part7都为固定值，part7的ASCII含义为1000LIVP。

```python
hex_str = "313030304C495650"
bytes_obj = bytes.fromhex(hex_str)
ascii_str = bytes_obj.decode("ascii")
print(ascii_str)  # 1000LIVP
```

## 文件夹转livp方法

若能保证某文件夹只有 一个.heic后缀的静态图、一个.mov后缀的动态视频，则可以将以下代码保存为`gen_livp_comment.py`并调用`python gen_livp_comment.py 文件夹路径名`命令获取这个文件的comment：

```python
'''
Author: LetMeFly
Date: 2026-07-04 16:41:49
LastEditors: LetMeFly.xyz
LastEditTime: 2026-07-04 20:16:21
'''
import os
import glob
import sys

def u32_hex(x: int) -> str:
    """转 8位大写十六进制（32-bit）"""
    return f"{x & 0xFFFFFFFF:08X}"

def find_single(pattern: str) -> str:
    files = glob.glob(pattern)
    if len(files) != 1:
        raise RuntimeError(f"Expected exactly 1 file for {pattern}, got {len(files)}: {files}")
    return files[0]

def generate_comment(folder: str) -> str:
    # heic_path = find_single(os.path.join(folder, "*.HEIC.heic"))
    # mov_path  = find_single(os.path.join(folder, "*.HEIC.mov"))
    heic_path = find_single(os.path.join(folder, "*.heic"))
    mov_path  = find_single(os.path.join(folder, "*.mov"))

    heic_size = os.path.getsize(heic_path)
    mov_size  = os.path.getsize(mov_path)

    # part3 / part5 / part6
    part3 = heic_size
    part6 = mov_size

    # part5 = part3 + 0x5F (必须保证 32-bit 不溢出)
    part5 = part3 + 0x5F

    if part3 < 0 or part3 > 0xFFFFFFFF:
        raise ValueError("HEIC size out of 32-bit range")
    if part5 > 0xFFFFFFFF:
        raise ValueError("part5 overflow 32-bit, invalid HEIC size")

    part1 = "0002"
    part2 = "00000030"
    part4 = "0003"
    part7 = "313030304C495650"

    comment = (
        part1 +
        part2 +
        u32_hex(part3) +
        part4 +
        u32_hex(part5) +
        u32_hex(part6) +
        part7
    )

    return comment

# python gen_livp_comment.py ~/Downloads/2026-06-18_162750
if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python livp.py <folder>")
        sys.exit(1)

    folder = sys.argv[1]
    print(generate_comment(folder))
```

这个脚本可以得到一串长为56的16进制数字组成的字符串（如`0002000000300022175F0003002217BE003D8A51313030304C495650`），之后再使用如下`zip`命令将这个文件夹下的静态图(`IMG_4770.HEIC.heic`)和动态视频(`IMG_4770.HEIC.mov`)压缩为live图文件：

```bash
zip -0 -X -z LetMeFly.xyz.Handsome.livp IMG_4770.HEIC.heic IMG_4770.HEIC.mov <<EOF
0002000000300022175F0003002217BE003D8A51313030304C495650
EOF
```

这样你将会得到一个`LetMeFly.xyz.Handsome.livp`文件，把这个文件拖入百度网盘或者一刻相册，你就能得到一个可以直接预览和播放的live图了。

## 杂念

为何没有两图压为live图的方案？因为实际上`.livp`格式的live图本来就不是Apple公司官方定义的，只是大多互联网厂商为了适配苹果live图推出的不约而同的格式。

把相册中live图下载后解压缩比较容易，但是由于没有官方的压缩方案，所以压缩回去就比较困难了。

## Mac/iOS系统上的live图方案（以及传输到Windows上）

iOS拍摄的live图如果想通过iCloud之外的方式同步到其他电脑/设备，主要有两个地方可以设置：

1. 数据线传输时：`iPhone -> 设置(settings) -> 应用(Apps) -> 照片(photos) -> 最下面的“传输到Mac或PC”(Transfer to Mac or PC) -> 保留原片(Keep Originals)`
2. AirDrop时：`分享 -> 选项(Options) -> 打开“所有照片数据”(All Photos Data)`

这样分享一张照片会在电脑上得到一个文件夹。

## 将一个文件夹下所有的live图文件夹们打包成.livp文件的脚本

将手机上一堆照片传输到电脑上后，会得到一个个如`IMG_5526`的文件夹。

将这些文件夹所在的文件夹路径记下来（如果在下载文件夹下则路径为`~/Downloads`），把以下脚本保存为`lets_export_photos.py`，并运行命令`python lets_export_photos.py 照片文件夹所在路径`命令，即可在`照片文件夹所在路径/exported`文件夹下找到一个个导出的照片文件，有的是静态图有的是live图，直接拖拽到百度网盘或一刻相册即可直接上传。

```python
'''
Author: LetMeFly
Date: 2026-07-04 16:41:49
LastEditors: LetMeFly.xyz
LastEditTime: 2026-07-05 10:20:24
'''
import os
import shutil
import subprocess
import sys


IMAGE_EXTS = {
    ".heic",
    ".jpg",
    ".jpeg",
    ".png",
    ".gif",
    ".bmp",
    ".tif",
    ".tiff",
    ".webp",
}


def u32_hex(x: int) -> str:
    return f"{x & 0xFFFFFFFF:08X}"


def generate_comment(heic_path: str, mov_path: str) -> str:
    heic_size = os.path.getsize(heic_path)
    mov_size = os.path.getsize(mov_path)

    part3 = heic_size
    part5 = part3 + 0x5F
    part6 = mov_size

    if part5 > 0xFFFFFFFF:
        raise ValueError("HEIC file too large")

    return (
        "0002"
        "00000030"
        + u32_hex(part3)
        + "0003"
        + u32_hex(part5)
        + u32_hex(part6)
        + "313030304C495650"
    )


def find_files(folder):
    files = [
        f
        for f in os.listdir(folder)
        if os.path.isfile(os.path.join(folder, f))
    ]

    heics = []
    movs = []
    images = []

    for f in files:
        ext = os.path.splitext(f)[1].lower()
        path = os.path.join(folder, f)

        if ext == ".heic":
            heics.append(path)
            images.append(path)
        elif ext == ".mov":
            movs.append(path)
        elif ext in IMAGE_EXTS:
            images.append(path)

    return heics, movs, images


def export_live(heic_path, mov_path, output_path):
    comment = generate_comment(heic_path, mov_path)

    cmd = [
        "zip",
        "-0",
        "-X",
        "-z",
        output_path,
        os.path.basename(heic_path),
        os.path.basename(mov_path),
    ]

    subprocess.run(
        cmd,
        cwd=os.path.dirname(heic_path),
        input=comment + "\n",
        text=True,
        check=True,
    )


def process_parent(parent_folder):
    exported = os.path.join(parent_folder, "exported")
    os.makedirs(exported, exist_ok=True)

    errors = []
    success = 0

    for name in sorted(os.listdir(parent_folder)):
        folder = os.path.join(parent_folder, name)

        if not os.path.isdir(folder):
            continue

        if name == "exported":
            continue

        try:
            heics, movs, images = find_files(folder)

            # Live Photo
            if len(heics) == 1 and len(movs) == 1:
                output = os.path.join(exported, name + ".livp")
                export_live(heics[0], movs[0], output)
                success += 1
                continue

            # 静态图片
            if len(images) == 1 and len(movs) == 0:
                src = images[0]
                dst = os.path.join(exported, os.path.basename(src))
                shutil.copy2(src, dst)
                success += 1
                continue

            errors.append(
                f"{name}: "
                f"{len(heics)} heic, "
                f"{len(movs)} mov, "
                f"{len(images)} image(s)"
            )

        except Exception as e:
            errors.append(f"{name}: {e}")

    print(f"导出成功 {success} 个")

    if errors:
        print()
        print("=" * 60)
        print("以下目录处理失败：")
        for err in errors:
            print(" -", err)
        print("=" * 60)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage:")
        print("python livp.py <parent_folder>")
        sys.exit(1)

    process_parent(sys.argv[1])

```

> 特别说明：
>
> 你需要保证你系统上有python环境、zip命令。
> 
> 上述脚本的执行过程中，例如目录结构为：
> 
> ```
> Photos/
> ├── IMG_0001/
> │   ├── a.heic
> │   └── a.mov
> ├── IMG_0002/
> │   └── b.heic
> ├── IMG_0003/
> │   ├── c.heic
> │   ├── d.heic
> │   └── c.mov
> └── ...
> ```
> 
> 则执行`python lets_export_photos.py ~/Downloads/Photos`将会生成：
> 
> ```
> Photos/
> ├── exported/
> │   ├── IMG_0001.livp
> │   ├── IMG_0002.heic
> │   └── ...
> ├── IMG_0001/
> ├── IMG_0002/
> └── ...
> ```

## The End

后续将创建一个 专门把两图压缩为百度系产品可直接识别的live图的 Github开源脚本仓库，敬请期待。

> 这个是原探究过程，可忽略：

````markdown
TODO:
````

<center><font size="6px" face="Ink Free">The End, Thanks!</font></center>

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/162586089)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/07/04/Other-iOS-zipAndUnzipingLivp-BaiduYikePhoto/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
