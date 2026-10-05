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

Mac上制作PE盘，使用了Ventoy，使用第三方的`fcjr/ventoy2disk-cli`安装到U盘上。

Ventoy启动盘占据U盘空间很小，剩余空间则直接将ISO文件拷贝到根目录上即可自动识别。但是Ventoy官方只支持Windows和Linux系统，所以可以使用第三方的[fcjr/ventoy-mac](https://github.com/fcjr/ventoy-mac)在Mac上制作Ventoy启动盘。

```bash
brew install --cask fcjr/fcjr/ventoy2disk-cli
diskutil list external  # 确认USB是/dev/disk4
sudo ventoy2disk -i /dev/disk4
```

结果`ventoy2disk`下载最新版的Ventoy 1.1.17很慢，故手动从[Ventoy Releases](https://github.com/ventoy/Ventoy/releases)下载了最新版[ventoy-1.1.17-linux.tar.gz](https://github.com/ventoy/Ventoy/releases/download/v1.1.17/ventoy-1.1.17-linux.tar.gz)，解压得到了`ventoy-1.1.17`文件夹，之后指定ventoy的位置并制作启动盘：

```bash
sudo ventoy2disk -i /dev/disk4 --pack ~/Downloads/ventoy-1.1.17
```

stdout如下：

```bash
Password:

**********************************************
      ventoy2disk for macOS  (0.1.2)
      Ventoy: https://www.ventoy.net
**********************************************

Disk : /dev/disk4
Size : 127 GiB
Style: MBR

Ventoy version: 1.1.17
Secure boot support: YES

WARNING: All data on /dev/disk4 will be lost!
Continue? (y/n) y

WARNING: All data on /dev/disk4 will be lost!
Double-check. Continue? (y/n) y
Clearing old partition data ...
Formatting partition 1 (exFAT, label 'Ventoy') ...
Writing EFI partition image ...
Writing boot image ...
Writing partition table ...
Syncing ...

Install Ventoy 1.1.17 to /dev/disk4 successfully finished.
You can now copy ISO files to the 'Ventoy' volume once macOS remounts it.
```

之后把要安装的ios镜像拷贝到这个叫`Ventoy`的U盘根目录上就好了。

我一共下载拷贝了三个镜像，下文会详细说明来源和用途：

1. cd140201.iso
2. WePE_64_V2.3.iso
3. Win10_22H2_Chinese_Simplified_x64v1.iso

### U盘数据还原

```bash
diskutil list external
diskutil info /dev/disk4
diskutil info /dev/disk4 | grep Protocol  # 确认USB是/dev/disk4
diskutil unmountDisk /dev/disk4
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

这样相当于是备份和恢复U盘都（几乎）只读写了实际使用的数据，而不是整个U盘的容量。

只是有些曲折罢了。

## 绕过WinXP密码登录

邻居家WinXP系统的古早台式机，多年未使用，忘记了密码无法登录。尝试一些常见密码无果，尝试了`Ctrl+Alt+Del`两次进入经典登录界面仍然无法登录。

在[Offline NT Password & Registry Editor（chntpw）官网](http://www.chntpw.com/)[下载](http://www.chntpw.com/download/)了[cd140201.zip](http://pogostick.net/~pnh/ntpasswd/cd140201.zip)，解压得到了一个17.9MB的ISO文件`cd140201.iso`，拷贝到Ventoy启动盘上。

Windows XP 的本地账户信息主要存在 `C:\Windows\System32\config\SAM`，SAM全称是`Security Accounts Manager`，它不是一个普通的文本文件，而是 Windows Registry hive（注册表配置单元）。里面保存了本地账户相关的数据，包括账户标识、密码验证所需的信息、账户状态等。

而`cd140201.iso`自己启动的是一个非常小的 Linux 环境，包含了 访问`NTFS`文件系统 和 操作`SAM`文件 的必要组件。Linux 可以直接把 NTFS 分区挂载起来，然后读取这个文件；chntpw 再按照 Windows Registry Hive 的格式解析它，获取账户信息，并清除掉密码。

具体操作过程如下：

插入U盘并选择U盘启动后，Ventoy 会先显示自身菜单。选择 `cd140201.iso` 后，进入该镜像的引导菜单。

```
┌─────────────────────────────────────────────────────┐
│              Ventoy 引导菜单                         │
│─────────────────────────────────────────────────────│
│  Boot in normal mode          ← 选择此项             │
│  Boot in grub2 mode                                  │
│  Boot in memdisk mode                                │
│  File checksum                                       │
│  Return to previous menu                             │
│─────────────────────────────────────────────────────│
│ 1.1.17 BIOS    L:Language  F1:Help  F2:Browse       │
│ F3:TreeView  F4:Localboot  F5:Tools  F6:ExMenu      │
└─────────────────────────────────────────────────────┘
```

选择 `Boot in normal mode` 正常启动即可。进入 chntpw 的引导提示符后，直接按回车使用默认参数启动：

```
┌─────────────────────────────────────────────────────┐
│  Windows Reset Password / Registry Editor            │
│  (c) 1998-2014 Petter Nordahl-Hagen                 │
│─────────────────────────────────────────────────────│
│  DISCLAIMER: THIS SOFTWARE COMES WITH ABSOLUTELY    │
│  NO WARRANTY...                                      │
│─────────────────────────────────────────────────────│
│  CD build date: Sat Feb 1 17:35:02 CET 2014         │
│─────────────────────────────────────────────────────│
│  Press enter to boot, or give linux kernel boot     │
│  options first.                                      │
│  Some that I have to use once in a while:           │
│  boot nousb       - to turn off USB if not used     │
│  boot irqpoll     - if some drivers hang            │
│  boot vga=ask     - if video mode problems          │
│  boot nodrivers   - skip automatic disk driver      │
│─────────────────────────────────────────────────────│
│  boot: _                                             │
└─────────────────────────────────────────────────────┘
```

之后系统会自动扫描磁盘，列出所有分区并检测 Windows 安装位置：

```
┌────────────────────────────────────────────────────────────┐
│  Step ONE: Select disk partition where the Windows         │
│  installation is located                                   │
│────────────────────────────────────────────────────────────│
│  DISK PARTITIONS:                                          │
│  1  sda1   249856000 7  243996                             │
│  2  sda2   32768     3  32                                 │
│  3  sdb1   52429072  7  51200      ← NTFS, 有Windows       │
│  4  sdb5   14575236  139 142336                            │
│  5  sdb6   14575236  139 142336                            │
│  6  sdb7   14445191  137 141066                            │
│────────────────────────────────────────────────────────────│
│  51200MB Partition sdb1 is NTFS:                           │
│  Found WINDOWS on: WINDOWS/system32/config                 │
│────────────────────────────────────────────────────────────│
│  Possible windows installations found:                     │
│  1  sdb1    51200MB WINDOWS/system32/config                │
│────────────────────────────────────────────────────────────│
│  Select: [1] _                                             │
└────────────────────────────────────────────────────────────┘
```

其中`sda1`和`sda2`是U盘的两个分区，`sdb*`是电脑硬盘的分区。`chntpw`在`sdb1`分区找到了Windows安装位置，输入`1`，回车：

```
Selected 1
Mounting from /dev/sdb1 with filesystem type NTFS
Yes, read-write, seems OK
Success!
```

```
┌─────────────────────────────────────────────────────┐
│  Step TWO: Select registry files                    │
│─────────────────────────────────────────────────────│
│  drwxrwxrwx  1  0  0  262144  May 17 2025  All Users│
│  drwxrwxrwx  1  0  0  262144  Dec 31 2025  DEFAULT  │
│  drwxrwxrwx  1  0  0  131072  Dec 31 2025  SECURITY │
│  drwxrwxrwx  1  0  0  6553600  Dec 31 2025  software│
│  drwxrwxrwx  1  0  0  262144  Jan 1 2026   system   │
│  drwxrwxrwx  1  0  0  6553600  Dec 31 2025  userdiff │
│─────────────────────────────────────────────────────│
│  Select which part of registry to load:             │
│  1 - Password reset [sam]         ← 选择此项        │
│  2 - RecoveryConsole parameters [software]          │
│  3 - quit almost any other parameter...             │
│  Select: [1] _                                      │
└─────────────────────────────────────────────────────┘
```

直接按回车（默认选择 `1 - Password reset [sam]`），屏幕显示 `Loaded hives: <SAM>`，表示 SAM 数据库已成功加载。工具自动列出了所有本地用户：

```
┌──────────────────────────────────────────────────────┐
│  chntpw Edit User Info & Passwords                   │
│──────────────────────────────────────────────────────│
│  RID   User Name           Admin?    Lock?           │
│  01f4  Administrator       ADMIN     dis/lock       │
│  01f5  Guest               -         dis/lock       │
│  03eb  HelpAssistant       -         dis/lock       │
│  03ea  SUPPORT_388945a0    -         dis/lock       │
│──────────────────────────────────────────────────────│
│  Please enter user number (RID) or 0 to exit: [1f4]  │
│──────────────────────────────────────────────────────│
│  RID: 0500 [01f4]                                    │
│  Username: Administrator                             │
│  Fullname: Administrator                             │
│  Comment:  **X                                       │
│──────────────────────────────────────────────────────│
│  Account bits: 0x0214                                │
│  [ ] Disabled              [X] Normal account       │
│  [ ] Temp duplicate        [ ] Wks trust act.       │
│  [X] Pwd don't expire      [ ] Auto lockout         │
│──────────────────────────────────────────────────────│
│  Failed login count: 276, while max tries is: 0      │
│  Total login count: 276                              │
│──────────────────────────────────────────────────────│
│  User Edit Menu:                                     │
│  1 - Clear (blank) user password                     │
│  2 - Unlock and enable user account                  │
│  3 - Promote user to administrator                   │
│  4 - Add user to a group                             │
│  5 - Remove user from a group                        │
│  q - Quit editing user, back to user select          │
│  Select: [q] > _                                     │
└──────────────────────────────────────────────────────┘
```

输入`1f4`回车选中`Administrator`，发现已经尝试了`276`次失败登录，`Lock?` 列显示 `dis/lock`表示账户已禁用且锁定。先输入`2`解锁账户，再输入`1`清除密码：

```
┌──────────────────────────────────────────────────────┐
│  Select: [q] > 2                                     │
│  Unlocked!                                           │
│──────────────────────────────────────────────────────│
│  Failed login count: 0    ← 已归零                   │
│  Account bits: 0x0214                                │
│  [ ] Disabled              [X] Normal account       │
│  [X] Pwd don't expire      [ ] Auto lockout         │
│──────────────────────────────────────────────────────│
│  Select: [q] > 1                                     │
│  Password cleared!                                   │
│──────────────────────────────────────────────────────│
│  Select: [q] > _                                     │
└──────────────────────────────────────────────────────┘
```

之后需要逐级退出并保存更改：

1. 输入 `q` 退出用户编辑菜单
2. 再次输入 `q` 退回到主菜单
3. 主菜单询问 `Write changes?`，**必须输入 `y`** 并回车（不保存的话前面操作相当于白做了）
4. 继续按 `q` 退出，直到能输入命令
5. 输入 `reboot` 重启电脑

当系统完成关机拔掉U盘，系统启动正常进入XinXP系统，没有密码直接进入了桌面，数据也都完好无损。

## 坏得不能再坏的Win7->Win10系统重装

邻居家还有一台坏得不能再坏的Win7系统，完全无法进入系统，需要备份+重装。

下载Win10镜像，先访问[官网](https://www.microsoft.com/zh-cn/software-download/windows10)，`选择版本`选`Windows 10（多版本ISO）`，`选择产品语言`找到`简体中文`，点击`确认`可以获得两个有效期为24小时的下载链接，选择`64位下载`即可。将得到的`Win10_22H2_Chinese_Simplified_x64v1.iso`拷贝到Ventoy启动盘上。

笔记本为多年前联想ThinkPad，启动按`F8`，上下按键选中USB，回车。进入`Ventoy`菜单，选择`Win10_22H2_Chinese_Simplified_x64v1.iso`，回车，继续选择`Boot in normal mode`，进入安装界面。

### 数据备份

在看到图形化界面后，`Fn + Shift + F10`打开命令行：

```bat
E:
mkdir FromC
robocopy C:\Users\Administrator E:\FromC\Administrator /E /R:1 /W:1
```

过一阵子发现开始递归了，路径越来越长：

```
windows\system32\cmd.exe robocopy C:\Users\Administrator E:\fromC\Administrator /R:1 /W:1
目录
Data\Application Data 0  C:\Users\Administrator\AppData\Local\Application Data\Application Data
Data\Application Data\Application Data  C:\Users\Administrator\AppData\Local\Application Data\Application Data
Data\Application Data\Application Data\Application Data  C:\Users\Administrator\AppData\Local\Application Data\Application Data\Application Data
源目录 Filter\
Data\Application Data 0  C:\Users\Administrator\AppData\Local\Application Data\Application Data
Data\Application Data\Application Data  C:\Users\Administrator\AppData\Local\Application Data\Application Data\Application Data
Data\Application Data\Application Data\Application Data  C:\Users\Administrator\AppData\Local\Application Data\Application Data\Application Data\Application Data
新目录
Data\Application Data 0  C:\Users\Administrator\AppData\Local\Application Data\Application Data
Data\Application Data\Application Data  C:\Users\Administrator\AppData\Local\Application Data\Application Data\Application Data
Data\Application Data\Application Data\Application Data  C:\Users\Administrator\AppData\Local\Application Data\Application Data\Application Data\Application Data
新目录
Data\Application Data 0  C:\Users\Administrator\AppData\Local\Application Data\Application Data
Data\Application Data\Application Data  C:\Users\Administrator\AppData\Local\Application Data\Application Data\Application Data
新目录
Data\Application Data 2  C:\Users\Administrator\AppData\Local\Application Data\Application Data
Data\Application Data\Application Data  C:\Users\Administrator\AppData\Local\Application Data\Application Data\Application Data
新文件
                      195.6 m      CEF_AndrowsStore.log
                                    PC_YYB_SDK.log
```

`Ctrl+C`终止，尝试使用图形界面备份。在命令行输入`notepad`打开记事本，点击`文件`->`打开`，诶，资源管理器出现了。在C盘找到`C:\Users\Administrator`右键`复制`，在E盘删除重建`FromC`文件夹并右键`粘贴`，还是卡死。

```bat
X:\Windows\System32\taskkill.exe /f /im notepad.exe
```

强行终止并删掉重建`FromC`文件夹，改为只备份重要的数据：

```bat
robocopy "C:\Users\Administrator\Desktop" "E:\FromC\Desktop" /E /XJ /R:1 /W:1
robocopy "C:\Users\Administrator\Documents" "E:\FromC\Documents" /E /XJ /R:1 /W:1
robocopy "C:\Users\Administrator\Downloads" "E:\FromC\Downloads" /E /XJ /R:1 /W:1
robocopy "C:\Users\Administrator\Pictures" "E:\FromC\Pictures" /E /XJ /R:1 /W:1
```

之后格式化C盘，准备开始重装：

```bat
diskpart
list disk
select disk 0
clean
```

好家伙！忽然想起来三个分区在物理上是一块硬盘，这一下子给全部格式化了。

立刻停止操作，关机，回去做恢复盘。

### 数据恢复

于是想到了大名鼎鼎的微PE，微PE默认只支持Windows系统，官网无ios镜像，官方的iso镜像获取方式是运行微PE的可执行程序（.exe）生成iso镜像。于是在网上找了个 微PE ISO镜像（不知是否官方但实测可用）。

下载地址：[Internet Archive We PE 64 V 2.3 微PE工具箱](https://archive.org/download/we-pe-64-v-2.3/WePE_64_V2.3.iso)，结果下载下来 和 [Ventoy Issue](https://github.com/ventoy/Ventoy/issues/3267) 以及 [Ventoy 官网iso 列表](https://www.ventoy.net/cn/distro_iso/winpe.html) 的sha值`b687e3f3b6eb09e531fcf57eb8c5cf0d236925ea`对不上，我的是`43b9ccf9024929ff4625cd3c3aa68b1435807770`。

这次铤而走险倒是没出现什么幺蛾子，后续对应这么常用的东西还是在主机上也备份一份吧。

镜像放入Ventoy启动盘，在ThinkPad上进入Ventoy后选择`WePE_64_V2.3.iso`启动，打开`DiskGenius`，选中被格式化的硬盘，上方菜单栏 `工具 -> 搜索已丢失分区（重建分区表）`，选择 `整个磁盘` 开始搜索，好在一点点搜索找到了原来的三个分区，点击左上角`保存更改`，之前的数据回来了。

### Win10重装

继续在微PE里面格式化C盘，由于该笔记本是比较老的`Legacy BIOS`和`MBR`分区模式，所以也不需要一个额外的系统引导分区，微PE的Windows安装器选择`Win10_22H2_Chinese_Simplified_x64v1.iso`、引导驱动器位置和安装驱动器位置都选择C盘，点击安装。等进度条读完就好了。

安装过程中我还遇到了好几次，安装一般系统直接关机。一摸笔记本好烫家伙，猜测是过热断电保护。于是使用一盒牛奶让笔记本底部悬空，使用邻家小娃的小风扇吹着，终于顺利安装完毕。

## End

> 本文v1版本ASCII图绘制自DeepSeek。

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/167038314)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/10/03/Other-Windows-ReInstall_bypassWinXPPassword_BackupRecoryWin7Data_Win10Install/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
