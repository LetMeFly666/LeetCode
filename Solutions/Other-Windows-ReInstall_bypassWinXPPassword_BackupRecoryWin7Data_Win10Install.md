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
import struct
import subprocess

DMG = "/Users/tisfy/Downloads/usb-backup.dmg"
SOURCE = "/dev/rdisk5"
TARGET = "/dev/rdisk4"
SECTOR_SIZE = 512

DATA_TYPES = {
    0x00000001,  # raw
    0x80000004,  # ADC
    0x80000005,  # zlib
    0x80000006,  # bzip2
    0x80000007,  # LZFSE
}

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

        # zero / empty block，原镜像这里本来就是 0，
        # 为了避免整盘写入，跳过。
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

print(f"源镜像: {SOURCE}")
print(f"目标磁盘: {TARGET}")
print(f"待写入: {total:,} bytes ({total / 1024 / 1024:.2f} MiB)")
print(f"数据块: {len(chunks)}")
print()

src = os.open(SOURCE, os.O_RDONLY)
dst = os.open(TARGET, os.O_RDWR)

try:
    done = 0

    for index, (sector, sector_count) in enumerate(chunks, 1):
        src_offset = sector * SECTOR_SIZE
        remaining = sector_count * SECTOR_SIZE

        os.lseek(src, src_offset, os.SEEK_SET)
        os.lseek(dst, src_offset, os.SEEK_SET)

        while remaining:
            size = min(1024 * 1024, remaining)

            data = os.read(src, size)
            if len(data) != size:
                raise RuntimeError(
                    f"读取失败: sector={sector}, "
                    f"expected={size}, got={len(data)}"
                )

            view = memoryview(data)
            while view:
                n = os.write(dst, view)
                if n <= 0:
                    raise RuntimeError("写入 U 盘失败")
                view = view[n:]

            remaining -= size
            done += size

        print(
            f"[{index}/{len(chunks)}] "
            f"已写入 {done / 1024 / 1024:.2f} MiB",
            flush=True
        )

    os.fsync(dst)
    print("\n恢复完成")

finally:
    os.close(src)
    os.close(dst)
PY
```

再确认一次`diskutil info /dev/disk4 | grep Protocol`，确认是目标USB，运行：

```bash
sudo python3 /tmp/restore-dmg-sparse-write.py
rm /tmp/restore-dmg-sparse-write.py
```

## 绕过WinXP密码登录

WinXP系统的古早台式机，

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/167038314)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/10/03/Other-Windows-ReInstall_bypassWinXPPassword_BackupRecoryWin7Data_Win10Install/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
