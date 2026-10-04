---
title: 两台旧电脑修复 —— 绕过WinXP密码登录、备份和恢复Win7数据、安装Win10
date: 2026-10-03 17:28:33
tags: [其他, Windows, 重装, 系统恢复]
categories: [技术思考]
---

# 两台旧电脑修复 —— 绕过WinXP密码登录、备份和恢复Win7数据、安装Win10

## 前言

国庆回家邻居有两台旧电脑，一台是WinXP系统的台式机忘记了密码，一台是Win7系统的笔记本电脑完全无法进入系统。故寻求我来帮忙修复这两台电脑。

## PE盘制作

恰逢手中PE盘被某位格外讨人喜欢的同事征用，故重做一枚。

### U盘数据备份

临时找了一个U盘，借助手中Mac制作一个镜像到Mac上，待U盘重装的使命完成后再恢复。

第一次使用了`dd`命令：

```bash
sudo dd if=/dev/rdisk4 of=~/Downloads/usb-backup.img bs=4m
```

结果发现U盘里面只有几十M的文件，而这个命令需要制作U盘总容量等大的DMG。故改用了`hdiutil`命令只保存已使用内容并带上一部分的压缩算法：

```bash
hdiutil create -srcdevice /dev/rdisk4 -format UDZO -o /Users/tisfy/Downloads/usb-backup.dmg
```

### 启动盘制作



### U盘数据还原

```bash
diskutil list external
diskutil info /dev/disk4
diskutil info /dev/disk4 | grep Protocol  # 确认USB是/dev/disk4
diskutil unmountDisk /dev/disk4

hdiutil attach -nomount /Users/tisfy/Downloads/usb-backup.dmg
diskutil list  # 新挂载了/dev/disk5，名字就是当时U盘的名字
hdiutil detach /dev/disk5
```

看下要还原多少数据：

```bash
cat > /tmp/restore-dmg-sparse.py <<'PY'
#!/usr/bin/env python3

import base64
import plistlib
import struct
import subprocess
import sys

DMG = "/Users/tisfy/Downloads/usb-backup.dmg"
SECTOR_SIZE = 512

DATA_TYPES = {
    0x00000001,  # raw
    0x80000004,  # ADC
    0x80000005,  # zlib / UDZO
    0x80000006,  # bzip2
    0x80000007,  # LZFSE
}

xml = subprocess.check_output(
    ["hdiutil", "udifderez", "-xml", DMG]
)

plist = plistlib.loads(xml)
rf = plist.get("resource-fork", plist)
blkx_list = rf["blkx"]

chunks = []

for entry in blkx_list:
    mish = entry["Data"]

    if isinstance(mish, str):
        mish = base64.b64decode(mish)

    if mish[:4] != b"mish":
        raise RuntimeError("发现无效的 BLKX/MISH 数据")

    image_sector = struct.unpack_from(">Q", mish, 8)[0]
    count = struct.unpack_from(">I", mish, 200)[0]

    for i in range(count):
        off = 204 + i * 40

        typ, comment, sector, sector_count, compressed_offset, compressed_length = \
            struct.unpack_from(">IIQQQQ", mish, off)

        if typ == 0xFFFFFFFF:
            break

        if typ == 0x7FFFFFFE:       # comment
            continue

        if typ in (0x00000000, 0x00000002):
            # zero/free run，不需要从镜像读取
            continue

        if typ not in DATA_TYPES:
            raise RuntimeError(
                f"遇到未处理的 chunk 类型: 0x{typ:08x}"
            )

        absolute_sector = image_sector + sector

        chunks.append((
            absolute_sector,
            sector_count,
            typ,
        ))

chunks.sort()

total = sum(count * SECTOR_SIZE for _, count, _ in chunks)

print(f"需要写入的实际数据: {total:,} bytes")
print(f"约 {total / 1024 / 1024:.2f} MiB")
print(f"数据块数量: {len(chunks)}")
print()

for sector, count, typ in chunks:
    print(
        f"sector={sector:<10} "
        f"count={count:<10} "
        f"bytes={count * SECTOR_SIZE:<12} "
        f"type=0x{typ:08x}"
    )
PY

python3 /tmp/restore-dmg-sparse.py
rm /tmp/restore-dmg-sparse.py
```

运行结果

```text
hdiutil: WARNING: udifderez is deprecated
需要写入的实际数据: 49,443,328 bytes
约 47.15 MiB
数据块数量: 59

sector=0          count=1          bytes=512          type=0x80000005
sector=32         count=2048       bytes=1048576      type=0x80000005
sector=2080       count=2048       bytes=1048576      type=0x80000005
sector=4128       count=2048       bytes=1048576      type=0x80000005
sector=6176       count=2048       bytes=1048576      type=0x80000005
sector=8224       count=2048       bytes=1048576      type=0x80000005
sector=10272      count=2048       bytes=1048576      type=0x80000005
sector=12320      count=2048       bytes=1048576      type=0x80000005
sector=14368      count=2048       bytes=1048576      type=0x80000005
sector=16416      count=2048       bytes=1048576      type=0x80000005
sector=18464      count=2048       bytes=1048576      type=0x80000005
sector=20512      count=2048       bytes=1048576      type=0x80000005
sector=22560      count=2048       bytes=1048576      type=0x80000005
sector=24608      count=2048       bytes=1048576      type=0x80000005
sector=26656      count=2048       bytes=1048576      type=0x80000005
sector=28704      count=2048       bytes=1048576      type=0x80000005
sector=30752      count=2048       bytes=1048576      type=0x80000005
sector=32800      count=2048       bytes=1048576      type=0x80000005
sector=34848      count=192        bytes=98304        type=0x80000005
sector=754272     count=8          bytes=4096         type=0x80000005
sector=1122872    count=8          bytes=4096         type=0x80000005
sector=4749208    count=8          bytes=4096         type=0x80000005
sector=4773288    count=2048       bytes=1048576      type=0x80000005
sector=4775336    count=2048       bytes=1048576      type=0x00000001
sector=4777384    count=2048       bytes=1048576      type=0x00000001
sector=4779432    count=2048       bytes=1048576      type=0x00000001
sector=4781480    count=2048       bytes=1048576      type=0x00000001
sector=4783528    count=2048       bytes=1048576      type=0x00000001
sector=4785576    count=2048       bytes=1048576      type=0x00000001
sector=4787624    count=2048       bytes=1048576      type=0x00000001
sector=4789672    count=2048       bytes=1048576      type=0x00000001
sector=4791720    count=2048       bytes=1048576      type=0x00000001
sector=4793768    count=2048       bytes=1048576      type=0x00000001
sector=4795816    count=2048       bytes=1048576      type=0x00000001
sector=4797864    count=2048       bytes=1048576      type=0x00000001
sector=4799912    count=2048       bytes=1048576      type=0x00000001
sector=4801960    count=2048       bytes=1048576      type=0x80000005
sector=4804008    count=1808       bytes=925696       type=0x80000005
sector=4810896    count=2048       bytes=1048576      type=0x00000001
sector=4812944    count=2048       bytes=1048576      type=0x80000005
sector=4814992    count=2048       bytes=1048576      type=0x80000005
sector=4817040    count=2048       bytes=1048576      type=0x00000001
sector=4819088    count=2048       bytes=1048576      type=0x00000001
sector=4821136    count=2048       bytes=1048576      type=0x00000001
sector=4823184    count=2048       bytes=1048576      type=0x00000001
sector=4825232    count=2048       bytes=1048576      type=0x00000001
sector=4827280    count=2048       bytes=1048576      type=0x00000001
sector=4829328    count=2048       bytes=1048576      type=0x00000001
sector=4831376    count=208        bytes=106496       type=0x80000005
sector=9992088    count=2048       bytes=1048576      type=0x80000005
sector=9994136    count=2048       bytes=1048576      type=0x80000005
sector=9996184    count=424        bytes=217088       type=0x80000005
sector=10007328   count=24         bytes=12288        type=0x80000005
sector=10011120   count=1168       bytes=598016       type=0x80000005
sector=10023688   count=1336       bytes=684032       type=0x80000005
sector=10029416   count=744        bytes=380928       type=0x80000005
sector=10046472   count=120        bytes=61440        type=0x80000005
sector=10617384   count=400        bytes=204800       type=0x80000005
sector=11040712   count=8          bytes=4096         type=0x80000005
```

写入数据：

```bash
cat > /tmp/restore-dmg-sparse-write.py <<'PY'
#!/usr/bin/env python3

import base64
import os
import plistlib
import re
import struct
import subprocess
import sys

DMG = "/Users/tisfy/Downloads/usb-backup.dmg"
TARGET = "/dev/disk4"
SECTOR_SIZE = 512

DATA_TYPES = {
    0x00000001,  # raw
    0x80000004,  # ADC
    0x80000005,  # zlib
    0x80000006,  # bzip2
    0x80000007,  # LZFSE
}


def run(*args):
    return subprocess.check_output(args, text=True)


# ------------------------------------------------------------
# 1. DMG 保持未挂载，先读取 blkx
# ------------------------------------------------------------

xml = subprocess.check_output(
    ["hdiutil", "udifderez", "-xml", DMG]
)

plist = plistlib.loads(xml)
rf = plist.get("resource-fork", plist)

chunks = []

for entry in rf["blkx"]:
    mish = entry["Data"]

    if isinstance(mish, str):
        mish = base64.b64decode(mish)

    if mish[:4] != b"mish":
        raise RuntimeError("Invalid MISH block map")

    image_sector = struct.unpack_from(">Q", mish, 8)[0]
    count = struct.unpack_from(">I", mish, 200)[0]

    for i in range(count):
        off = 204 + i * 40

        typ, comment, sector, sector_count, _, _ = \
            struct.unpack_from(">IIQQQQ", mish, off)

        if typ == 0xFFFFFFFF:
            break

        if typ == 0x7FFFFFFE:
            continue

        # 空白块 / 0 填充块
        if typ in (0x00000000, 0x00000002):
            continue

        if typ not in DATA_TYPES:
            raise RuntimeError(
                f"Unsupported chunk type: 0x{typ:08x}"
            )

        chunks.append((
            image_sector + sector,
            sector_count
        ))

chunks.sort()

total = sum(count * SECTOR_SIZE for _, count in chunks)

print(f"DMG: {DMG}")
print(f"目标: {TARGET}")
print(f"实际写入: {total:,} bytes ({total / 1024 / 1024:.2f} MiB)")
print(f"数据块: {len(chunks)}")
print()


# ------------------------------------------------------------
# 2. 卸载目标 U 盘
# ------------------------------------------------------------

subprocess.run(
    ["diskutil", "unmountDisk", TARGET],
    check=True
)


# ------------------------------------------------------------
# 3. 挂载 DMG，但不挂载其中的文件系统
# ------------------------------------------------------------

attach_output = subprocess.check_output(
    ["hdiutil", "attach", "-nomount", "-readonly", DMG],
    text=True,
    stderr=subprocess.STDOUT
)

print(attach_output)

match = re.search(
    r"^(/dev/disk\d+)\s+FDisk_partition_scheme\s*$",
    attach_output,
    re.MULTILINE
)

if not match:
    raise RuntimeError(
        "无法从 hdiutil attach 输出中找到磁盘设备"
    )

source_disk = match.group(1)
source_raw = source_disk.replace("/dev/disk", "/dev/rdisk")

print(f"源虚拟磁盘: {source_raw}")
print(f"目标物理磁盘: {TARGET}")
print()


# ------------------------------------------------------------
# 4. 最后一次人工确认
# ------------------------------------------------------------

print("即将进行稀疏恢复。")
print()
print(f"源 : {source_raw}  ← usb-backup.dmg")
print(f"目标: {TARGET}  ← U 盘")
print()
print(f"将写入约 {total / 1024 / 1024:.2f} MiB，而不是整个 8 GB。")
print()

answer = input("确认目标确实是 U 盘并继续？输入 YES：")

if answer != "YES":
    print("已取消，没有写入 U 盘。")
    subprocess.run(["hdiutil", "detach", source_disk])
    sys.exit(1)


# ------------------------------------------------------------
# 5. 只写 blkx 中实际存在的数据区域
# ------------------------------------------------------------

src = os.open(source_raw, os.O_RDONLY)
dst = os.open(
    TARGET.replace("/dev/disk", "/dev/rdisk"),
    os.O_RDWR
)

try:
    done = 0

    for index, (sector, sector_count) in enumerate(chunks, 1):
        offset = sector * SECTOR_SIZE
        remaining = sector_count * SECTOR_SIZE

        os.lseek(src, offset, os.SEEK_SET)
        os.lseek(dst, offset, os.SEEK_SET)

        while remaining:
            size = min(1024 * 1024, remaining)

            data = os.read(src, size)

            if len(data) != size:
                raise RuntimeError(
                    f"读取源失败: sector={sector}, "
                    f"expected={size}, got={len(data)}"
                )

            written = 0

            while written < len(data):
                n = os.write(dst, data[written:])

                if n <= 0:
                    raise RuntimeError("写入目标 U 盘失败")

                written += n

            remaining -= size
            done += size

        print(
            f"[{index:2d}/{len(chunks)}] "
            f"{done / 1024 / 1024:7.2f} / "
            f"{total / 1024 / 1024:.2f} MiB",
            flush=True
        )

    os.fsync(dst)

    print()
    print("恢复完成。")

finally:
    os.close(src)
    os.close(dst)

    subprocess.run(
        ["hdiutil", "detach", source_disk],
        check=False
    )
PY
```

再确认一次`diskutil info /dev/disk4 | grep Protocol`，确认是目标USB，运行：

```bash
sudo python3 /tmp/restore-dmg-sparse-write.py
rm /tmp/restore-dmg-sparse-write.py
```

运行结果：

```text
sudo python3 /tmp/restore-dmg-sparse-write.py
hdiutil: WARNING: udifderez is deprecated
DMG: /Users/tisfy/Downloads/usb-backup.dmg
目标: /dev/disk4
实际写入: 49,443,328 bytes (47.15 MiB)
数据块: 59

Unmount of all volumes on disk4 was successful
预计CRC32 $168A17EE
hdiutil: WARNING: 'hdiutil attach -nomount -readonly ...' is deprecated. Please use 'diskutil image attach --noMount --readOnly ...' instead.
/dev/disk5          	FDisk_partition_scheme         	
/dev/disk5s1        	DOS_FAT_32                     	

源虚拟磁盘: /dev/rdisk5
目标物理磁盘: /dev/disk4

即将进行稀疏恢复。

源 : /dev/rdisk5  ← usb-backup.dmg
目标: /dev/disk4  ← U 盘

将写入约 47.15 MiB，而不是整个 8 GB。

确认目标确实是 U 盘并继续？输入 YES：YES
[ 1/59]    0.00 / 47.15 MiB
[ 2/59]    1.00 / 47.15 MiB
[ 3/59]    2.00 / 47.15 MiB
[ 4/59]    3.00 / 47.15 MiB
[ 5/59]    4.00 / 47.15 MiB
[ 6/59]    5.00 / 47.15 MiB
[ 7/59]    6.00 / 47.15 MiB
[ 8/59]    7.00 / 47.15 MiB
[ 9/59]    8.00 / 47.15 MiB
[10/59]    9.00 / 47.15 MiB
[11/59]   10.00 / 47.15 MiB
[12/59]   11.00 / 47.15 MiB
[13/59]   12.00 / 47.15 MiB
[14/59]   13.00 / 47.15 MiB
[15/59]   14.00 / 47.15 MiB
[16/59]   15.00 / 47.15 MiB
[17/59]   16.00 / 47.15 MiB
[18/59]   17.00 / 47.15 MiB
[19/59]   17.09 / 47.15 MiB
[20/59]   17.10 / 47.15 MiB
[21/59]   17.10 / 47.15 MiB
[22/59]   17.11 / 47.15 MiB
[23/59]   18.11 / 47.15 MiB
[24/59]   19.11 / 47.15 MiB
[25/59]   20.11 / 47.15 MiB
[26/59]   21.11 / 47.15 MiB
[27/59]   22.11 / 47.15 MiB
[28/59]   23.11 / 47.15 MiB
[29/59]   24.11 / 47.15 MiB
[30/59]   25.11 / 47.15 MiB
[31/59]   26.11 / 47.15 MiB
[32/59]   27.11 / 47.15 MiB
[33/59]   28.11 / 47.15 MiB
[34/59]   29.11 / 47.15 MiB
[35/59]   30.11 / 47.15 MiB
[36/59]   31.11 / 47.15 MiB
[37/59]   32.11 / 47.15 MiB
[38/59]   32.99 / 47.15 MiB
[39/59]   33.99 / 47.15 MiB
[40/59]   34.99 / 47.15 MiB
[41/59]   35.99 / 47.15 MiB
[42/59]   36.99 / 47.15 MiB
[43/59]   37.99 / 47.15 MiB
[44/59]   38.99 / 47.15 MiB
[45/59]   39.99 / 47.15 MiB
[46/59]   40.99 / 47.15 MiB
[47/59]   41.99 / 47.15 MiB
[48/59]   42.99 / 47.15 MiB
[49/59]   43.09 / 47.15 MiB
[50/59]   44.09 / 47.15 MiB
[51/59]   45.09 / 47.15 MiB
[52/59]   45.30 / 47.15 MiB
[53/59]   45.31 / 47.15 MiB
[54/59]   45.88 / 47.15 MiB
[55/59]   46.53 / 47.15 MiB
[56/59]   46.90 / 47.15 MiB
[57/59]   46.95 / 47.15 MiB
[58/59]   47.15 / 47.15 MiB
[59/59]   47.15 / 47.15 MiB

恢复完成。
hdiutil: WARNING: 'hdiutil detach ...' is deprecated. Please use 'diskutil eject ...' instead.
"disk5" ejected.
```

## 绕过WinXP密码登录

WinXP系统的古早台式机，

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/167038314)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/10/03/Other-Windows-ReInstall_bypassWinXPPassword_BackupRecoryWin7Data_Win10Install/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
