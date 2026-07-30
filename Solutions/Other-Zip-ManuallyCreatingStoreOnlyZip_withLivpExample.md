---
title: Zip：手动生成仅存储的zip文件（以百度系iOS动态图.livp为例）
title_en: "ZIP: Manually Creating a Store-Only ZIP Archive (Using Baidu iOS Live Photo .livp as an Example)"
date: 2026-07-29 21:51:32
tags: [Mac, MacOS, iPhone, iOS, 百度网盘, 一刻相册, 照片同步, 逆向, zip]
categories: [技术思考]
description: 不借助zip工具生成仅存储的zip文件；未压缩的zip文件；手搓zip、手搓压缩文件
---

# Zip：手动生成仅存储的zip文件（以百度系iOS动态图.livp为例）

## 背景

本系列上篇文章[逆向(iOS)：压缩和解压live图(.livp)——百度一刻相册+百度网盘识别支持](https://blog.letmefly.xyz/2026/07/04/Other-iOS-zipAndUnzipingLivp-BaiduYikePhoto/)分析了第三方厂商对Apple动态图的封装规则。由于压缩强度为0（仅存储），故本篇以此为例探究如何手搓仅归档的zip压缩文件。

如无特殊说明，本篇默认以打包生成.livp格式动态live图为例。

## 简单回顾

Apple系列支持通过系统接口像相册中写入live图，但未曾公开过导出方式。第三方厂商为了适配live图几乎都选择将静态图和动态视频打包成一个.livp文件便于备份、传输、分享，其本质上是一个带有一定格式约束的.zip压缩包。

百度系列的动态图压缩包需要满足以下条件：

+ 不压缩（仅存储）
+ 静态图在前动态图在后
+ 56字节长度的注释（注释构成见[上篇文章](https://blog.letmefly.xyz/2026/07/04/Other-iOS-zipAndUnzipingLivp-BaiduYikePhoto/)）

既然zip的格式是已知且公开的，并且生成zip的过程不涉及原始文件压缩，因此我们完全可以不借助zip工具，直接手搓一个.zip文件出来，还能被百度系产品识别为live图。

## 样本介绍

样本：[byiOSLivpMakerB1785140239500.livp](https://github.com/LetMeFly666/2livp/releases/download/v2.0.0/byiOSLivpMakerB1785140239500.livp)

该文件即为百度系产品支持识别的live图，其本质是一个压缩包，包含两个文件：

+ 文件一（静态图）：IMB_TItMiu.HEIC.heic，大小38179字节
+ 文件二（动态视频）：IMB_TItMiu.HEIC.mov，大小218269 字节

包含一个注释：

```
000200000032000095230003000095860003549D313030304C495650
```

压缩方式为仅存储。

<details>
<summary><code>zipinfo -v byiOSLivpMakerB1785140239500.livp</code></summary>

```swift
Archive:  byiOSLivpMakerB1785140239500.livp
The zipfile comment is 56 bytes long and contains the following text:
======================== zipfile comment begins ==========================
000200000032000095230003000095860003549D313030304C495650
========================= zipfile comment ends ===========================

End-of-central-directory record:
-------------------------------

  Zip archive file size:                    256756 (000000000003EAF4h)
  Actual end-cent-dir record offset:        256678 (000000000003EAA6h)
  Expected end-cent-dir record offset:      256678 (000000000003EAA6h)
  (based on the length of the central directory and its expected offset)

  This zipfile constitutes the sole disk of a single-part archive; its
  central directory contains 2 entries.
  The central directory is 131 (0000000000000083h) bytes long,
  and its (expected) offset in bytes from the beginning of the zipfile
  is 256547 (000000000003EA23h).


Central directory entry #1:
---------------------------

  IMB_TItMiu.HEIC.heic

  offset of local header from start of archive:   0
                                                  (0000000000000000h) bytes
  file system or operating system of origin:      MS-DOS, OS/2 or NT FAT
  version of encoding software:                   0.0
  minimum file system compatibility required:     MS-DOS, OS/2 or NT FAT
  minimum software version required to extract:   2.0
  compression method:                             none (stored)
  file security status:                           not encrypted
  extended local header:                          no
  file last modified on (DOS date/time):          2026 Jul 27 16:17:18
  32-bit CRC value (hex):                         73d17195
  compressed size:                                38179 bytes
  uncompressed size:                              38179 bytes
  length of filename:                             20 characters
  length of extra field:                          0 bytes
  length of file comment:                         0 characters
  disk number on which file begins:               disk 1
  apparent file type:                             binary
  non-MSDOS external file attributes:             000000 hex
  MS-DOS file attributes (00 hex):                none

  There is no file comment.

Central directory entry #2:
---------------------------

  IMB_TItMiu.HEIC.mov

  offset of local header from start of archive:   38229
                                                  (0000000000009555h) bytes
  file system or operating system of origin:      MS-DOS, OS/2 or NT FAT
  version of encoding software:                   0.0
  minimum file system compatibility required:     MS-DOS, OS/2 or NT FAT
  minimum software version required to extract:   2.0
  compression method:                             none (stored)
  file security status:                           not encrypted
  extended local header:                          no
  file last modified on (DOS date/time):          2026 Jul 27 16:17:18
  32-bit CRC value (hex):                         4e6acfdb
  compressed size:                                218269 bytes
  uncompressed size:                              218269 bytes
  length of filename:                             19 characters
  length of extra field:                          0 bytes
  length of file comment:                         0 characters
  disk number on which file begins:               disk 1
  apparent file type:                             binary
  non-MSDOS external file attributes:             000000 hex
  MS-DOS file attributes (00 hex):                none

  There is no file comment.
```

</details>

## Zip格式

### 总格式

zip格式如下：

```swift
[Local File Header #1][文件名1][文件数据1]
[Local File Header #2][文件名2][文件数据2]
[Central Directory File Header #1]
[Central Directory File Header #2]
[End Of Central Directory (EOCD)]
[ZIP 注释]
```

Local File Header、Central Directory File Header、End Of Central Directory长啥样？咱们结合样本进行分析。

### 分析方式

```bash
xxd byiOSLivpMakerB1785140239500.livp | less
```

可以得到如：

```swift
00000000: 504b 0304 1400 0000 0000 2982 fb5c 9571  PK........)..\.q
00000010: d173 2395 0000 2395 0000 1400 0000 494d  .s#...#.......IM
00000020: 425f 5449 744d 6975 2e48 4549 432e 6865  B_TItMiu.HEIC.he
00000030: 6963 0000 0024 6674 7970 6865 6963 0000  ic...$ftypheic..
00000040: 0000 6d69 6631 4d69 5072 6d69 6166 4d69  ..mif1MiPrmiafMi
00000050: 4842 6865 6963 0000 06aa 6d65 7461 0000  HBheic....meta..
```

一共有三部分，最左边的：

```swift
00000000
00000010
00000020
00000030
00000040
00000050
```

代表起始地址。

中间的：

```swift
504b 0304 1400 0000 0000 2982 fb5c 9571
d173 2395 0000 2395 0000 1400 0000 494d
```

代表该起始地址的16字节的数据。一个数字代表半个字节，如前4个数字`504b`，其中的`50`是一个字节。

例如第一行的`00000000: 504b 0304 1400 0000 0000 2982 fb5c 9571`就代表起始地址是`0`的16个字节内容为`504b 0304 1400 0000 0000 2982 fb5c 9571`。

右边部分的：

```swift
PK........)..\.q
.s#...#.......IM
B_TItMiu.HEIC.he
ic...$ftypheic..
..mif1MiPrmiafMi
HBheic....meta..
```

代表左边字节对应的ASCII码，如第一行的前两个字节`504b`对应的ASCII码为`PK`：

```python
>>> hex(ord('P'))
'0x50'
>>> hex(ord('K'))
'0x4b'
```

继续回到[总格式](#总格式)章节的zip格式：

```swift
[Local File Header #1][文件名1][文件数据1]
[Local File Header #2][文件名2][文件数据2]
[Central Directory File Header #1]
[Central Directory File Header #2]
[End Of Central Directory (EOCD)]
[ZIP 注释（百度自定义）]
```

zip首先就是一个一个的文件。咱们先来分析第一个文件。

### 第一个文件：[Local File Header #1][文件名1][文件数据1]

|字段|偏移|长度|样本对应值|含义|
|:--:|:--:|:--:|:--|:--|
|签名        | 0 | 4字节 |504B 0304  |固定魔数，`PK\x03\x04` |
|版本        | 4 | 2字节 |1400       |提取所需最低版本<br/>一般设为 0x0014（2.0，即 decimal 20） |
|通用位标志  | 6 | 2字节  |0000      | General Purpose Bit Flag(GPBF)<ul><li/>`0x0000`代表CRC、压缩大小、原始大小已经知道，直接写在 Local File Header 中</li><li/>`0x0008`代表CRC、大小暂时未知，稍后通过 Data Descriptor 写入</li> </ul> |
|压缩方法    | 8 | 2字节  |0000      | 0x0000 = 存储（store，无压缩）。 |
|修改时间    | 10 | 2字节  |2982      | <ul><li>bit 15-11 小时(5 bit)</li><li>bit 10-5 分钟(6 bit)</li><li>bit 4-0 秒/2(5 bit)</ul>0x8229 = 1000 0010 0010 1001<ul><li>小时10000 = 16</li><li>分钟010001 = 17</li><li>秒/2 01001 = 9</li></ul> 16:17:18 |
|修改日期    | 12 | 2字节  |fb5c      | <ul><li>bit 15-9 年份偏移(从1980开始)</li><li>bit 8-5 月</li><li>bit 4-0 日</ul>0x5cfb = 0101 1100 1111 1011<ul><li>年diff 年0101110=46</li><li>月0111=7</li><li>日11011=27</ul>2026年7月27日 |
|CRC32       | 14 | 4字节 |9571 d173  |0x73d17195 <pre><code class="hljs python">import zlib<br/>import sys<br/><br/>filename = sys.argv[1]<br/>data = open(filename, 'rb').read()<br/>crc32 = zlib.crc32(data)<br/>print(hex(crc32))</code></pre> |
|压缩大小    | 18 | 4字节  |2395 0000 |  0x9523<pre><code class="hljs bash">stat -f "%z" IMB_TItMiu.HEIC.heic</code></pre>得38179（字节），hex(38179)=0x9523 |
|未压缩大小  | 22 | 4字节  |2395 0000 |  同上 |
|文件名长度  | 26 | 2字节  |1400      |  0x14 = len('IMB_TItMiu.HEIC.heic') |
|额外字段长度| 28 | 2字节  |0000      | 本样本中无此字段，暂不研究 |
|文件名      | 30 | 文件名长度 字节 |494d 425f 5449 744d 6975 2e48 4549 432e 6865 6963 | 运行<pre><code class="hljs python">print(<br/>    bytes.fromhex("494d 425f 5449 744d 6975 2e48 4549 432e 6865 6963")<br/>    .decode("ascii")<br/>)</code></pre>可得`IMB_TItMiu.HEIC.heic` |
|文件数据    | 30+文件名长度 | 字节  |0000 0024 6674 7970 6865 6963 ... | ...$ftypheic.. |

文件1数据起始偏移地址 16x3+2=50

文件1大小：38179（字节）

文件1结束后第二个文件起始偏移地址：50 + 38179 = 0x9555

### 第二个文件：[Local File Header #2][文件名2][文件数据2]

执行`xxd -s 0x9555 byiOSLivpMakerB1785140239500.livp | less`得到

```swift
00009555: 504b 0304 1400 0000 0000 2982 fb5c dbcf  PK........)..\..
00009565: 6a4e 9d54 0300 9d54 0300 1300 0000 494d  jN.T...T......IM
00009575: 425f 5449 744d 6975 2e48 4549 432e 6d6f  B_TItMiu.HEIC.mo
00009585: 7600 0000 1466 7479 7071 7420 2000 0000  v....ftypqt  ...
```

由最右边部分可以看到文件名`IMB_TItMiu.HEIC.mov`的最后一个字符`v`对应着起始地址`0x00009585`的字节`76`。

文件起始地址 0x9585 + 1，文件大小 218269 字节 ，可得ZIP下一部分Central Directory File Header #1 起始地址 0x9585 + 1 + 218269 = '0x3ea23'。

### 中央目录1：[Central Directory File Header #1]

执行`xxd -s 0x3ea23 byiOSLivpMakerB1785140239500.zip`得到：

```swift
0003ea23: 504b 0102 0000 1400 0000 0000 2982 fb5c  PK..........)..\
0003ea33: 9571 d173 2395 0000 2395 0000 1400 0000  .q.s#...#.......
0003ea43: 0000 0000 0000 0000 0000 0000 0000 494d  ..............IM
0003ea53: 425f 5449 744d 6975 2e48 4549 432e 6865  B_TItMiu.HEIC.he
0003ea63: 6963 504b 0102 0000 1400 0000 0000 2982  icPK..........).
0003ea73: fb5c dbcf 6a4e 9d54 0300 9d54 0300 1300  .\..jN.T...T....
0003ea83: 0000 0000 0000 0000 0000 0000 5595 0000  ............U...
0003ea93: 494d 425f 5449 744d 6975 2e48 4549 432e  IMB_TItMiu.HEIC.
0003eaa3: 6d6f 7650 4b05 0600 0000 0002 0002 0083  movPK...........
0003eab3: 0000 0023 ea03 0038 0030 3030 3230 3030  ...#...8.0002000
0003eac3: 3030 3033 3230 3030 3039 3532 3330 3030  0003200009523000
0003ead3: 3330 3030 3039 3538 3630 3030 3335 3439  3000095860003549
0003eae3: 4433 3133 3033 3033 3034 4334 3935 3635  D313030304C49565
0003eaf3: 30     
```

Central Directory File Header #1 格式如下：

|字段|偏移|长度|样本对应值|含义|
|:--:|:--:|:--:|:--|:--|
|签名Signature|         0         | 4字节        | 504b 0102   | 固定魔数 |
|版本VerMade|           4         | 2字节        | 0000        | 创建此文件所用版本，一般也用2.0（14 00） |
|版本VerNeeded|         6         | 2字节        | 1400        | 提取所需最低版本，同 Local Header |
|通用位标志GPFlag|      8         | 2字节        |  0000       |  GPBF |
|压缩方法CompMethod|    10        | 2字节        |  0000       |  0x0000 = 存储（store，无压缩） |
|修改时间ModTime|       12        | 2字节        |  2982       |  同Local File Header |
|修改日期ModDate|       14        | 2字节        |  fb5c       |  同Local File Header |
|CRC32|                 16        | 4字节       | 9571 d173    | 同Local File Header |
|压缩大小CompSize|      20        | 4字节        | 2395 0000   |  同Local File Header |
|未压缩大小UncompSize|  24        | 4字节        |  2395 0000  |   同Local File Header |
|文件名长度NameLen|     28        | 2字节        |  1400       |  同Local File Header |
|额外字段长度ExtraLen|  30        | 2字节        |  0000       |  同Local File Header |
|文件注释长度CommentLen| 32        | 2字节        |  0000       |  代表无注释 |
|磁盘号DiskStart|       34        | 2字节       | 0000        | 此文件起始于第几号磁盘（一般0） |
|内部属性IntAttr|       36        | 2字节       |  0000       | 内部文件属性，一般 0 |
|外部属性ExtAttr|       38        | 4字节       |  0000 0000  | 外部文件属性，一般 0 |
|相对偏移RelOffset|     42        | 4字节       |  0000 0000  | 从 ZIP 文件起始到对应 Local Header 的偏移（字节数）。示例：第一个文件偏移 0。第二个文件按此计算。 |
|文件名|                46        | 文件名长度 字节 |   494d 425f 5449 744d 6975 2e48 4549 432e 6865 6963 | 同Local File Header |
|（可选）额外字段/注释| 46+文件名长度 | |||

### 中央目录2：[Central Directory File Header #2]

大多都与中央目录#1相同

+ 相同：504b 0102 0000 1400 0000 0000 2982 fb5c
+ CRC32：dbcf 6a4e
+ 未压缩大小：9d54 0300
+ 压缩大小：9d54 0300
+ 文件名长度：1300
+ 相同：0000 0000 0000 0000 0000 0000
+ 相对偏移RelOffset 5595 0000 ，符合前面计算的0x9555（也就是0x00009555）
+ 文件名494d 425f 5449 744d 6975 2e48 4549 432e 6d6f 76：运行`print(bytes.fromhex("494d 425f 5449 744d 6975 2e48 4549 432e 6d6f 76").decode("ascii"))`可得`IMB_TItMiu.HEIC.mov`

中央目录2以文件名结束，结束位置快速检索：`0003eaa3: 6d6f 76`，可得ZIP文件下一部分（EOCD）的起始地址为 0x3eaa3 + 3 = 0x3eaa6。

### EOCD [End Of Central Directory]

执行`xxd -s 0x3eaa6 byiOSLivpMakerB1785140239500.livp`可得：

```swift
0003eaa6: 504b 0506 0000 0000 0200 0200 8300 0000  PK..............
0003eab6: 23ea 0300 3800 3030 3032 3030 3030 3030  #...8.0002000000
0003eac6: 3332 3030 3030 3935 3233 3030 3033 3030  3200009523000300
0003ead6: 3030 3935 3836 3030 3033 3534 3944 3331  0095860003549D31
0003eae6: 3330 3330 3330 3443 3439 3536 3530       3030304C495650
```

End Of Central Directory格式如下：

|字段|偏移|长度|样本对应值|含义|
|:--:|:--:|:--:|:--|:--|
|签名Signature            |  0         | 4字节   | 504b 0506    |         固定魔数，标志 EOCD 开始  |
|当前磁盘号DiskNum        |  4         | 2字节   |  0000        |          本磁盘号，一般0  |
|CD起始磁盘号DiskStart    |  6         | 2字节   |  0000        |          中央目录所在磁盘号（一般0）  |
|磁盘内条目数EntriesOnDisk|  8         | 2字节    |  0200       |           本磁盘上的目录条目数。示例0x0002=2（图片+视频）。  |
|总条目数TotalEntries     |  10        | 2字节   |  0200        |          ZIP 文件中目录总条目数。示例2。  |
|CD大小CDSize             |  12        | 4字节   | 8300 0000    |         （CD#1 46+20，CD#2 46+19，共计46+20+46+19=131=0x83）中央目录总大小（字节）。等于所有 Central 头长度之和（不含 EOCD 自身和注释）。其中CD是EOCD前面的 中央目录 Central Directory的缩写  |
|CD偏移CDOffset           |  16        | 4字节   | 23ea 0300    |         0x3eaa6-0x83=0x03ea23中央目录起始位置相对 ZIP 开始的偏移（字节数）。  |
|注释长度CommentLen       |  20        | 2字节   | 3800         |          0x38=56  |

### Comment [ZIP 注释]

剩下部分全部是注释内容：

```swift
3030 3032 3030 3030 3030 3332 3030 3030 3935 3233 3030 3033 3030 3030 3935 3836 3030 3033 3534 3944 3331 3330 3330 3330 3443 3439 3536 3530
```

对应的ASCII码可由以下python脚本求出：

```python
print(
  bytes.fromhex("3030 3032 3030 3030 3030 3332 3030 3030 3935 3233 3030 3033 3030 3030 3935 3836 3030 3033 3534 3944 3331 3330 3330 3330 3443 3439 3536 3530")
  .decode("ascii")
)
```

运行结果：

```
000200000032000095230003000095860003549D313030304C495650
```

关于注释含义在上篇文章[逆向(iOS)：压缩和解压live图(.livp)——百度一刻相册+百度网盘识别支持](https://blog.letmefly.xyz/2026/07/04/Other-iOS-zipAndUnzipingLivp-BaiduYikePhoto/)中已经分析。

### file内容分析

逐字节分析了上面的内容，还剩下最后一个跳过的部分：文件。

运行以下命令，没有任何输出，说明zip中文件部分逐字节和原始文件相同。

```bash
cmp <(dd if=byiOSLivpMakerB1785140239500.livp bs=1 skip=50 count=38179 status=none) IMB_TItMiu.HEIC.heic
cmp <(dd if=byiOSLivpMakerB1785140239500.livp bs=1 skip=0x9586 count=218269 status=none) IMB_TItMiu.HEIC.mov
```

整个分析下来，和`zipinfo`命令得到的结果完全相同。至此，我们已经具备手搓这种仅存储二进制zip的全部必备知识了。

### 为什么这样设计？

先文件再中央文件目录的设计，是为了zip可以边压缩边写，支持流式写入，永不回头。

前面有过Local File Header了，后面还有一个专门的Directory File Header，并且二者还有大量重复内容。这样设计是为了存储完成后便于快速从文件尾检索定位。

至于为什么comment要放在EOCD后，我也不是很清楚。大概是因为zip设计之初Comment最大支持长度为65535，所以从文件尾向前检索也很快。

## 手搓zip

至此，我们已经获得了所有构造.livp文件时需要的数据格式了。花了三个半小时编写了一个脚本，测试通过：

```python
'''
Author: LetMeFly
Date: 2026-07-30 14:49:28
LastEditors: LetMeFly.xyz
LastEditTime: 2026-07-30 18:03:15
Description: 不借助zip工具生成.livp
Description: All Writen By Hand
Description: What A Beautiful Design(bushi
'''
from sys import argv
from io import BufferedWriter
from os.path import getmtime, basename
from time import localtime
from struct import pack
from zlib import crc32


class File:
    def __init__(self, filename: str):
        self.filename = filename
        self.name = basename(filename).encode("utf-8")
        self.size = 0
        self.crc32 = 0
        self.data = b""  # 先给干内存里得了。
        self.offset = 0  # 文件头起始位置在zip文件里的偏移量
    
    def get_dos_datetime(self) -> tuple[int, int]:
        t = localtime(getmtime(self.filename))
        year = min(max(t.tm_year, 1980), 2107)  #仅支持1980-2107年
        dos_time = (t.tm_hour << 11) | (t.tm_min << 5) | (t.tm_sec // 2)
        dos_date = ((year - 1980) << 9) | (t.tm_mon << 5) | t.tm_mday
        return dos_time, dos_date
    
    def get_crc32(self) -> int:
        if self.crc32:
            return self.crc32
        return self.__calc_crc32()
    
    def get_data(self) -> bytes:
        if not self.data:
            with open(self.filename, "rb") as f:
                self.data = f.read()
        return self.data

    def get_size(self) -> int:
        if not self.size:
            self.size = len(self.get_data())
        return self.size
    
    def __calc_crc32(self) -> int:
        data = self.get_data()
        self.crc32 = crc32(data) & 0xffffffff  # 只取32位（&0xffffffff是为了兼容python2写法）
        return self.crc32


class Zip:
    def __init__(self, *files: File):
        self.files = files
        self.comment = self.t()
        self.cd_len = 0  # 中央目录总长度
    
    def t(self) -> bytes:
        # 这样是为了方便后面的拓展
        return ZipCommenter.create(self.files).get_comment()

    def _write1file(self, file: File, out: BufferedWriter):
        file.offset = out.tell()
        dos_time, dos_date = file.get_dos_datetime()
        # 现在支持的版本标志位=0x0000，要么读两遍文件，要么seek回来覆盖掉crc32，暂时选择读两遍文件
        crc32 = file.get_crc32()
        size = file.get_size()
        out.write(pack(
            "<IHHHHHIIIHH",
            0x04034b50,      # 签名
            0x0014,          # 版本2.0
            0x0000,          # 标志位
            0x0000,          # 压缩方法(仅存储)
            dos_time,        # 修改时间
            dos_date,        # 修改日期
            crc32,           # CRC32
            size,            # 压缩大小
            size,            # 原始大小
            len(file.name),  # 文件名长度
            0x0000           # 额外字段长度
        ))
        out.write(file.name)
        out.write(file.get_data())
    
    def _write_central_directory(self, file: File, out: BufferedWriter):
        dos_time, dos_date = file.get_dos_datetime()
        crc32 = file.get_crc32()
        size = file.get_size()
        out.write(pack(
            "<IHHHHHHIIIHHHHHII",
            0x02014b50,      # 签名
            0x0000,          # 创建此文件所用版本
            0x0014,          # 提取所需最低版本，同 Local Header(版本2.0)
            0x0000,          # 标志位
            0x0000,          # 压缩方法(仅存储)
            dos_time,        # 修改时间
            dos_date,        # 修改日期
            crc32,           # CRC32
            size,            # 压缩大小
            size,            # 原始大小
            len(file.name),  # 文件名长度
            0x0000,          # 额外字段长度
            0x0000,          # 文件注释长度
            0x0000,          # 磁盘号
            0x0000,          # 内部文件属性
            0x00000000,      # 外部文件属性
            file.offset      # 文件头起始位置在zip文件中的偏移量
        ))
        out.write(file.name)
        self.cd_len += 46 + len(file.name)
    
    def _write_end_of_central_directory(self, out: BufferedWriter):
        out.write(pack(
            "<IHHHHIIH",
            0x06054b50,                # 签名
            0x0000,                    # 磁盘号
            0x0000,                    # 中央目录起始磁盘号
            len(self.files),           # 本磁盘上中央目录记录数   
            len(self.files),           # 中央目录记录总数
            self.cd_len,               # 中央目录大小
            out.tell() - self.cd_len,  # 中央目录起始位置相对于起始磁盘的偏移量
            len(self.comment)          # zip文件注释长度
        ))
    

    def _write_comment(self, out: BufferedWriter):
        out.write(self.comment)

    def write(self, output: str):
        with open(output, "wb") as out:
            for file in self.files:
                self._write1file(file, out)
            for file in self.files:
                self._write_central_directory(file, out)
            self._write_end_of_central_directory(out)
            self._write_comment(out)


class ZipCommenter:
    def get_comment(self) -> bytes:
        return b"generated by LetMeFly.xyz"

    @staticmethod
    def create(files: list[File]) -> "ZipCommenter":
        if len(files) == 2:
            return LivpCommenter(files[0], files[1])
        return ZipCommenter()


class LivpCommenter(ZipCommenter):
    def __init__(self, static_file: File, dynamic_file: File):
        self.static_file = static_file
        self.dynamic_file = dynamic_file
        self.static_file_type = self.static_file.name.rsplit(b".", 1)[-1].lower()
        assert self.static_file_type in [b"jpg", b"jpeg", b"heic"]
        self.dynamic_file_type = self.dynamic_file.name.rsplit(b".", 1)[-1].lower()
        assert self.dynamic_file_type in [b"mov"]
    
    @staticmethod
    def _val(val: int, length: int) -> str:
        return f"{val:0{length}X}"
    
    def get_comment(self) -> bytes:
        comment = ""
        if self.static_file_type == b"heic":
            comment += self._val(2, 4)
        elif self.static_file_type in [b"jpg", b"jpeg"]:
            comment += self._val(5, 4)
        comment += self._val(30 + len(self.static_file.name), 8)
        comment += self._val(self.static_file.get_size(), 8)
        if self.dynamic_file_type == b"mov":
            comment += self._val(3, 4)
        comment += self._val(
            self.static_file.get_size()
            + 30 + len(self.static_file.name)
            + 30 + len(self.dynamic_file.name),
            8
        )
        comment += self._val(self.dynamic_file.get_size(), 8)
        comment += "313030304C495650"
        return comment.encode("ascii")

def help(filename: str):
    print(f"Usage: python {filename} <static_file> <dynamic_file> <output_file>")


if __name__ == "__main__":
    if len(argv) != 4:
        print("there must be 3 arguments, but got %d" % (len(argv) - 1))
        help(argv[0])
        exit(1)    
    zip = Zip(File(argv[1]), File(argv[2]))
    zip.write(argv[3])
```

其中的 `struct.pack("<IHHHHHIIIHH", ...)`：

+ `<`代表[小端序(little-endian)](https://github.com/LetMeFly666/LeetCode/blob/46a444928f1d248648e7379556ad36c1898e1e94/Solutions/Other-Accumulation-SomeTips.md?plain=1#L1956-L1996)
+ `I`代表unsigned int（4字节）
+ `H`代表unsigned short（2字节）
+ `Q`代表unsigned long long（8字节）
+ `B`代表unsigned char（1字节）

此脚本也同步更新到了GitHub仓库：[Github@LetMeFly666/2livp/livp_maker.py](https://github.com/LetMeFly666/2livp/blob/a1d561f9b9128e7d280bbc5ee2d54d1c8710b14a/livp_maker.py)

## The End

<center><font size="6px" face="Ink Free">The End, Thanks!</font></center>

Github仓库：[LetMeFly666/2livp](https://github.com/LetMeFly666/2livp)

zip格式调研报告：[byChatGPT](https://chatgpt.com/share/6a6a0d7e-9254-83ec-a48b-bb63b69f99cd)（不要看其生成的脚本[，]((https://chatgpt.com/c/6a6960ff-68e8-83ec-9e6a-73f27531bd77))不可用）

样本逐字节分析验证(+撰文制表)：All by Hand with Heart❤️.

Phillip Katz的Zip故事[：](https://chatgpt.com/c/6a6aafcf-4be0-83ec-a3bf-c3f055065fac)[看ChatGPT的第二段对话](https://chatgpt.com/s/t_6a6ab4b9e9448191b2aca675febd828b)

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/163313641)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/07/29/Other-Zip-ManuallyCreatingStoreOnlyZip_withLivpExample/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)

特辑此文以飨读者。
