其中四个livp的comment是：
0002 00000030  000E26AB 0003 000E270A 004B806E  313030304C495650
0002 00000030  0010B331 0003 0010B390 004208DB  313030304C495650
0002 00000030  0016BD7A 0003 0016BDD9 00432342  313030304C495650
0002 00000030  001AD3A2 0003 001AD401 00430C1B  313030304C495650

313030304C495650的ASCII是1000LIVP

第一个文件使用以下命令可以被成功识别

zip -0 -X -z remake.livp IMG_4792.HEIC.heic IMG_4792.HEIC.mov <<EOF
0002000000300016BD7A00030016BDD900432342313030304C495650
EOF

而以下不可

zip -z remake.livp IMG_4792.HEIC.heic IMG_4792.HEIC.mov <<EOF
0002000000300016BD7A00030016BDD900432342313030304C495650
EOF

现在我比较好奇这段comment是什么

又找了个老livp，0002 00000030  001AD3A2 0003 001AD401 00430C1B  313030304C495650
unzip后发现组成是：IMG_0194.HEIC.heic、IMG_0194.HEIC.mov

我把IMG_4792.HEIC.heic IMG_4792.HEIC.mov重命名为IMG_4793.HEIC.heic IMG_4793.HEIC.mov
然后重新压缩
zip -0 -X -z remake.livp IMG_4793.HEIC.heic IMG_4793.HEIC.mov <<EOF
0002000000300016BD7A00030016BDD900432342313030304C495650
EOF
诶，comment没有变文件名变了，但还是能完美识别live图

我把2.zip的两个文件（原本是000200000030000E26AB0003000E270A004B806E313030304C495650）
重新压缩并comment为刚才那张图的comment：
zip -0 -X -z remake2.livp IMG_4800.HEIC.heic IMG_4800.HEIC.mov <<EOF
0002000000300016BD7A00030016BDD900432342313030304C495650
EOF

啊，还是成功识别为了实况图

试试FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF313030304C495650
zip -0 -X -z remakeFFFF.livp IMG_4800.HEIC.heic IMG_4800.HEIC.mov <<EOF
试试FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF313030304C495650
EOF
不行，识别不了了

去掉comment
zip -0 -X remakeNoComment.livp IMG_4800.HEIC.heic IMG_4800.HEIC.mov 
果然不行，识别不了。

把原有的
000200000030000E26AB0003000E270A004B806E313030304C495650 修改为
000200000030000E26AB0003000E270A00432342313030304C495650
                                --------
也就是把：
zip -0 -X -z remakeCan.livp IMG_4800.HEIC.heic IMG_4800.HEIC.mov <<EOF
000200000030000E26AB0003000E270A004B806E313030304C495650
EOF
改为：
zip -0 -X -z remakeTest6.livp IMG_4800.HEIC.heic IMG_4800.HEIC.mov <<EOF
000200000030000E26AB0003000E270A00432342313030304C495650
EOF
！还是可以识别的


回顾每个comment的7个部分，第1、2、4、7部分固定，
第3部分+0x5F是第5部分，第6部分意义不明。

直接猜测：
第1、2、4、7部分固定
第5、6部分rand且长度和之前相同（保证第5部分加上0x5F后长度不变），第3部分=第5部分+0x5F
```python
import random
PART1 = "0002"
PART2 = "00000030"
PART4 = "0003"
PART7 = "313030304C495650"
# 保证 part5 + 0x5F 不会溢出到 9 位
part5_int = random.randint(0, 0xFFFFFFA0)
part3_int = part5_int + 0x5F
part6_int = random.randint(0, 0xFFFFFFFF)
part3 = f"{part3_int:08X}"
part5 = f"{part5_int:08X}"
part6 = f"{part6_int:08X}"
parts = [PART1, PART2, part3, PART4, part5, part6, PART7]
print(" ".join(parts))
print("".join(parts))
```
得到
0002 00000030 C73C6FAA 0003 C73C6F4B 913EE91F 313030304C495650
000200000030C73C6FAA0003C73C6F4B913EE91F313030304C495650
之后：
zip -0 -X -z remakeParts.livp IMG_4800.HEIC.heic IMG_4800.HEIC.mov <<EOF
000200000030C73C6FAA0003C73C6F4B913EE91F313030304C495650
EOF
Ohh Damn，不行，识别不了了。

再回看这些合法的数字，part3都是000x到001x，part5也是，而part6都是004x，满足这个试试
```python
import random
PART1 = "0002"
PART2 = "00000030"
PART4 = "0003"
PART7 = "313030304C495650"
while True:
    # part5: 000x**** 或 001x****
    part5_int = random.randint(0x00000000, 0x001FFF40)
    part3_int = part5_int + 0x5F
    # 确保 part3 仍然属于 000x 或 001x
    if part3_int <= 0x001FFFFF:
        break
# part6: 004x****
part6_int = random.randint(0x00400000, 0x004FFFFF)
part3 = f"{part3_int:08X}"
part5 = f"{part5_int:08X}"
part6 = f"{part6_int:08X}"
parts = [
    PART1,
    PART2,
    part3,
    PART4,
    part5,
    part6,
    PART7,
]
print(" ".join(parts))
print("".join(parts))
```
0002 00000030 00114DC1 0003 00114D62 0042B479 313030304C495650
00020000003000114DC1000300114D620042B479313030304C495650
zip -0 -X -z remakeParts2.livp IMG_4800.HEIC.heic IMG_4800.HEIC.mov <<EOF
00020000003000114DC1000300114D620042B479313030304C495650
EOF
Ohhhh，可以识别了竟然！！！
共生成3个
zip -0 -X -z remakeParts2-2.livp IMG_4800.HEIC.heic IMG_4800.HEIC.mov <<EOF
0002000000300017DE4900030017DDEA00472DD2313030304C495650
EOF
zip -0 -X -z remakeParts2-3.livp IMG_4800.HEIC.heic IMG_4800.HEIC.mov <<EOF
0002000000300016D77B00030016D71C00440068313030304C495650
EOF
上传到一刻相册并播放，肉眼看不出任何区别！


现在重整这4个comment：
0002 00000030  000E26AB 0003 000E270A 004B806E  313030304C495650
0002 00000030  0010B331 0003 0010B390 004208DB  313030304C495650
0002 00000030  0016BD7A 0003 0016BDD9 00432342  313030304C495650
0002 00000030  001AD3A2 0003 001AD401 00430C1B  313030304C495650
修改为
00020000003000 0E26AB 000300 0E270A 004 B806E  313030304C495650
00020000003000 10B331 000300 10B390 004 208DB  313030304C495650
00020000003000 16BD7A 000300 16BDD9 004 32342  313030304C495650
00020000003000 1AD3A2 000300 1AD401 004 30C1B  313030304C495650
```python
import random
PREFIX1 = "00020000003000"
PREFIX2 = "000300"
PREFIX3 = "004"
SUFFIX = "313030304C495650"
# 保证 part5 + 0x5F 仍然是 6 位
part5_int = random.randint(0, 0xFFFFA0)
part3_int = part5_int + 0x5F
part6_int = random.randint(0, 0xFFFFF)
part3 = f"{part3_int:06X}"
part5 = f"{part5_int:06X}"
part6 = f"{part6_int:05X}"
parts = [
    PREFIX1,
    part3,
    PREFIX2,
    part5,
    PREFIX3,
    part6,
    SUFFIX,
]
print(" ".join(parts))
print("".join(parts))
```
zip -0 -X -z remakeParts2-4.livp IMG_4800.HEIC.heic IMG_4800.HEIC.mov <<EOF
000200000030006DE2FD0003006DE29E0042E0AB313030304C495650
EOF
zip -0 -X -z remakeParts2-5.livp IMG_4800.HEIC.heic IMG_4800.HEIC.mov <<EOF
000200000030006E4A9D0003006E4A3E0041853B313030304C495650
EOF
哦吼，都是识别不了的
发现新生成的第2部分变成了6E4A9D，所以识别不了了。但是点开倒是能播放，只是没有预览图。
说明这些其实不是乱码，应该还是有一定的含义的。
不如限制第二部分的第一位是0或1
```python
import random
PREFIX1 = "00020000003000"
PREFIX2 = "000300"
PREFIX3 = "004"
SUFFIX = "313030304C495650"
# P5 第一位只能是 0 或 1，同时保证 +0x5F 后仍然属于 1FFFFF 以内
part5_int = random.randint(0x000000, 0x1FFFA0)
part3_int = part5_int + 0x5F
part6_int = random.randint(0x00000, 0xFFFFF)
part3 = f"{part3_int:06X}"
part5 = f"{part5_int:06X}"
part6 = f"{part6_int:05X}"
parts = [
    PREFIX1,
    part3,
    PREFIX2,
    part5,
    PREFIX3,
    part6,
    SUFFIX,
]
print(" ".join(parts))
print("".join(parts))
```
zip -0 -X -z remakeParts2-6.livp IMG_4800.HEIC.heic IMG_4800.HEIC.mov <<EOF
00020000003000105C04000300105BA50046B024313030304C495650
EOF
zip -0 -X -z remakeParts2-7.livp IMG_4800.HEIC.heic IMG_4800.HEIC.mov <<EOF
0002000000300006B00800030006AFA9004F7B54313030304C495650
EOF
zip -0 -X -z remakeParts2-8.livp IMG_4800.HEIC.heic IMG_4800.HEIC.mov <<EOF
000200000030000C67B00003000C675100483B3E313030304C495650
EOF
zip -0 -X -z remakeParts2-9.livp IMG_4800.HEIC.heic IMG_4800.HEIC.mov <<EOF
000200000030001141550003001140F60044C4A4313030304C495650
EOF
坏了，这个识别不了
00020000003000 06B008 000300 06AFA9 004 F7B54 313030304C495650
0002000000300006B00800030006AFA9004F7B54313030304C495650
是不是06太小了，别人的最小是0E

那就再来点数据吧
```python
import zipfile
import os
from pathlib import Path

basedir = Path("~/Downloads/20LiveFiles").expanduser()
for name in os.listdir(basedir):
    filename = os.path.join(basedir, name)
    with zipfile.ZipFile(filename) as z:
        print(z.comment.decode())
```
00020000003000 1BA85C 000300 1BA8BB 004 8AD4F 313030304C495650
00020000003000 40EFF2 000300 40F051 005 FA6B2 313030304C495650
00020000003000 10B331 000300 10B390 004 208DB 313030304C495650
00020000003000 361343 000300 3613A2 004 E9378 313030304C495650
00020000003000 207D5C 000300 207DBB 004 C4ACF 313030304C495650
00020000003000 2E36C7 000300 2E3726 003 8D203 313030304C495650
00020000003000 14E077 000300 14E0D6 003 FC9D5 313030304C495650
00020000003000 2BED90 000300 2BEDEF 004 EE532 313030304C495650
00020000003000 300C0E 000300 300C6D 002 DEA07 313030304C495650
00020000003000 2221A3 000300 222202 004 8065E 313030304C495650
00020000003000 2E841C 000300 2E847B 004 C5FD8 313030304C495650
00020000003000 3D18DD 000300 3D193C 005 6E8C1 313030304C495650
00020000003000 240F9E 000300 240FFD 005 2EAED 313030304C495650
00020000003000 15340A 000300 153469 004 CA087 313030304C495650
00020000003000 197C18 000300 197C77 003 363B1 313030304C495650
00020000003000 22FF18 000300 22FF77 004 32EA5 313030304C495650
00020000003000 1CE360 000300 1CE3BF 004 BBC1C 313030304C495650
00020000003000 192596 000300 1925F5 004 CF4B8 313030304C495650
00020000003000 22175F 000300 2217BE 003 D8A51 313030304C495650
00020000003000 23F7F3 000300 23F852 005 0AD13 313030304C495650
让ChatGPT写一段脚本获取其中更多的信息：
```python
import zipfile
import os
from pathlib import Path
import struct

basedir = Path("~/Downloads/20LiveFiles").expanduser()

def get_central_directory_offset(zip_path):
    """解析 EOCD 获取 central directory offset"""
    with open(zip_path, "rb") as f:
        data = f.read()

    # EOCD signature: 0x06054b50
    sig = b"\x50\x4b\x05\x06"

    idx = data.rfind(sig)
    if idx == -1:
        return None

    # EOCD layout:
    # 0-3   signature
    # 16-19 offset of central directory
    offset = struct.unpack_from("<I", data, idx + 16)[0]
    return offset


def analyze_zip(filename):
    with zipfile.ZipFile(filename) as z:
        info = {}

        # comment
        info["comment"] = z.comment.decode(errors="ignore")

        # HEIC / MOV size
        for name in z.namelist():
            if name.lower().endswith(".heic") or name.lower().endswith(".heic.heic"):
                info["heic_size"] = z.getinfo(name).file_size
            elif name.lower().endswith(".mov"):
                info["mov_size"] = z.getinfo(name).file_size

        # central directory offset
        info["central_dir_offset"] = get_central_directory_offset(filename)

        return info


for name in os.listdir(basedir):
    path = os.path.join(basedir, name)
    try:
        r = analyze_zip(path)
        print(name, r)
    except Exception as e:
        print(name, "ERROR:", e)
```
2026-06-18 194008.zip {'comment': '000200000030001BA85C0003001BA8BB0048AD4F313030304C495650', 'heic_size': 1812572, 'mov_size': 4762959, 'central_dir_offset': 6575626}
2026-06-18 164420(1).zip {'comment': '0002000000300040EFF200030040F051005FA6B2313030304C495650', 'heic_size': 4255730, 'mov_size': 6268594, 'central_dir_offset': 10524419}
2026-06-18 192906.zip {'comment': '0002000000300010B33100030010B390004208DB313030304C495650', 'heic_size': 1094449, 'mov_size': 4327643, 'central_dir_offset': 5422187}
2026-06-18 155929.zip {'comment': '000200000030003613430003003613A2004E9378313030304C495650', 'heic_size': 3543875, 'mov_size': 5149560, 'central_dir_offset': 8693530}
2026-06-18 160936.zip {'comment': '00020000003000207D5C000300207DBB004C4ACF313030304C495650', 'heic_size': 2129244, 'mov_size': 4999887, 'central_dir_offset': 7129226}
2026-06-18 163032.zip {'comment': '000200000030002E36C70003002E37260038D203313030304C495650', 'heic_size': 3028679, 'mov_size': 3723779, 'central_dir_offset': 6752553}
2026-06-18 164428.zip {'comment': '0002000000300014E07700030014E0D6003FC9D5313030304C495650', 'heic_size': 1368183, 'mov_size': 4180437, 'central_dir_offset': 5548715}
2026-06-18 163035.zip {'comment': '000200000030002BED900003002BEDEF004EE532313030304C495650', 'heic_size': 2878864, 'mov_size': 5170482, 'central_dir_offset': 8049441}
2026-06-18 162923.zip {'comment': '00020000003000300C0E000300300C6D002DEA07313030304C495650', 'heic_size': 3148814, 'mov_size': 3009031, 'central_dir_offset': 6157940}
2026-06-18 192353.zip {'comment': '000200000030002221A30003002222020048065E313030304C495650', 'heic_size': 2236835, 'mov_size': 4720222, 'central_dir_offset': 6957152}
2026-06-18 162922.zip {'comment': '000200000030002E841C0003002E847B004C5FD8313030304C495650', 'heic_size': 3048476, 'mov_size': 5005272, 'central_dir_offset': 8053843}
2026-06-18 160650.zip {'comment': '000200000030003D18DD0003003D193C0056E8C1313030304C495650', 'heic_size': 4004061, 'mov_size': 5695681, 'central_dir_offset': 9699837}
2026-06-18 162656.zip {'comment': '00020000003000240F9E000300240FFD0052EAED313030304C495650', 'heic_size': 2363294, 'mov_size': 5434093, 'central_dir_offset': 7797482}
2026-06-18 164427.zip {'comment': '0002000000300015340A000300153469004CA087313030304C495650', 'heic_size': 1389578, 'mov_size': 5021831, 'central_dir_offset': 6411504}
2026-06-18 164454.zip {'comment': '00020000003000197C18000300197C77003363B1313030304C495650', 'heic_size': 1670168, 'mov_size': 3367857, 'central_dir_offset': 5038120}
2026-06-18 162543.zip {'comment': '0002000000300022FF1800030022FF7700432EA5313030304C495650', 'heic_size': 2293528, 'mov_size': 4402853, 'central_dir_offset': 6696476}
2026-06-18 162635.zip {'comment': '000200000030001CE3600003001CE3BF004BBC1C313030304C495650', 'heic_size': 1893216, 'mov_size': 4963356, 'central_dir_offset': 6856667}
2026-06-18 164453.zip {'comment': '000200000030001925960003001925F5004CF4B8313030304C495650', 'heic_size': 1648022, 'mov_size': 5043384, 'central_dir_offset': 6691501}
2026-06-18 162750.zip {'comment': '0002000000300022175F0003002217BE003D8A51313030304C495650', 'heic_size': 2234207, 'mov_size': 4033105, 'central_dir_offset': 6267407}
2026-06-18 162801.zip {'comment': '0002000000300023F7F300030023F8520050AD13313030304C495650', 'heic_size': 2357235, 'mov_size': 5287187, 'central_dir_offset': 7644517}
heic_size 1812572 就是 part2的 1BA85C！
```python
print(1812572 == 0x1BA85C)
```
mov_size 4762959 就是 part5+part6 的 004 8AD4F！
```python
print(4762959 == 0x0048AD4F)
```
问题解了！
这个comment的含义解了！


现在重整下结构：

0002 00000030 000E26AB 0003 000E270A 004B806E 313030304C495650
0002 00000030 0010B331 0003 0010B390 004208DB 313030304C495650
part1  part2    part3  part4  part5   part6       part7

part1: 0002
part2: 00000030
part3: heic字节数
part4: 0003
part5: part3+0x5F
part6: mov字节数
part7: 313030304C495650(1000LIVP)
part3和part6的8位的字节数最大$2^{4\times 8}-1$字节也就是4 GiB - 1（为了防止溢出还要保证part3+0x5F还是8位十六进制）
part7含义：
```python
hex_str = "313030304C495650"

bytes_obj = bytes.fromhex(hex_str)
ascii_str = bytes_obj.decode("ascii")

print(ascii_str)  # 1000LIVP
```
现在直接写个代码由文件夹生成comment（要保证文件夹下只有一个xx.heic和对应的xx.mov）
```python
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

# python livp.py ~/Downloads/2026-06-18_162750
if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python livp.py <folder>")
        sys.exit(1)

    folder = sys.argv[1]
    print(generate_comment(folder))
```

对了，zip的版本是：
This is Zip 3.0 (July 5th 2008), by Info-ZIP, with modifications by Apple Inc.
Compiled with gcc Apple LLVM 21.0.0 (clang-2100.0.123.2) [+internal-os] for Unix (Mac OS X) on Apr 18 2026.

还有：
zip -0 -z remakeNoX.livp IMG_4770.HEIC.heic IMG_4770.HEIC.mov <<EOF
0002000000300022175F0003002217BE003D8A51313030304C495650
EOF
上面不带-X不可，下面带上-X可以
zip -0 -X -z remakeWithXParamWhenZipping.livp IMG_4770.HEIC.heic IMG_4770.HEIC.mov <<EOF
0002000000300022175F0003002217BE003D8A51313030304C495650
EOF

单个求.livp comment的脚本改为直接处理整个文件夹下所有子文件夹中照片的脚本的prompt:
```
这是一个把某文件夹中图片转为.livp格式的脚本，修改这个脚本：
1. 同样一个图片是一个“子”文件夹，如一个文件夹中可能有.heic+.mov，也可能只有一个静态图
2. 如果是live图则转为.livp，如果是静态图则直接复制并导出
3. 如果某文件夹下不只有一个.heic和.mov，不直接抛出错误，而是记录报错并最终统一呈现结果
4. 函数接收参数将变成这些照片文件夹所在文件夹路径，即使是静态图也会有一个专门的子文件夹
5. 程序要在父文件夹中创建`exported`文件夹并将所有导出照片放到这个文件夹下（无需再创建子文件夹）
```


--- 第二天(2026.7.5)发现不同文件名长度part5可能需要不同 ---
part3： IMG_5164.HEIC.heic的字节数 0x24E4F8=2417912
part5：0x24E557=2418007，而IMG_5164.HEIC.mov的local header offset是2417960，
    2418007 - 2417960 = 47 文件名是17的话 47-17还有30不知道是什么，而ZIP 的 Local File Header固定就是30字节

现在咱们先研究静态图在zip中的Central directory entry #1而动态图在zip中的#2的情况：
part1: 0002
part2: 00000030
part3: heic字节数
part4: 0003
part5: #2的offset+30+mov文件名长度(长度为17的mov文件名的情况下等于part3+0x5F)
part6: mov字节数
part7: 313030304C495650(1000LIVP)
其中part5验证：
```python
hex(2417960 + 30 + len('IMG_5164.HEIC.mov'))  # 0x24e557
```
0002000000300024E4F800030024E557004AF675313030304C495650
offset of local header from start of archive:   2417960
并且#2的offset=静态图的filesize+30+静态图filename
这个0x5F也就是95=(30+filename1.len)+(30+filename2.len)
坏了，算出了一个0002000000300024E4F800030024E559004AF675313030304C495650（1IMG_5164.HEIC.heic、 1IMG_5164.HEIC.mov） 还是不对。
00020000003000 24E4F8 000300 24E559 004AF675 313030304C495650
0x24E4F8=2417912 = #1 1IMG_5164.HEIC.heic filesize
0x24E559=2418009 = 2417912 + 97
0x4AF675=4912757 = #2 1IMG_5164.HEIC.mov  filesize

修改为IMG_5190.H1IC.heic和IMG_5190.H1IC.mov是可以识别的
len('IMG_5190.H1IC.heic') == len('1234567890123.heic')
len('IMG_5190.H1IC.mov') == len('s5f=3z81sfx23.mov')
修改为1234567890123.heic和s5f=3z81sfx23.mov还是可以识别的！
.heic加一位都不行，但是.mov加一位可以！
00020000003000 212BCA 000300 212C3B 004E9961 313030304C495650
1234567890123.heic
s5f=3z81sfx231sfjli298ksjfkJKjf.mov
甚至这样都可以！
0x212BCA=2173898 = #1 1234567890123.heic filesize
0x212C3B=2174011 = 2173898 + 113 = 2173898 + (30 + len('1234567890123.heic')) + (30 + len('s5f=3z81sfx231sfjli298ksjfkJKjf.mov'))
0x4E9961=5151073 = #2 s5f=3z81sfx231sfjli298ksjfkJKjf.mov filesize
但是#1的filename len变化似乎就不行了。


此外：
zip命令是怎么确定#1和#2的？
似乎是zip命令的文件顺序。


现在试试静态图长度从传统的18改为19时候，part5从part3+50测试到part3+128，哪个可以渲染
```bash
#!/bin/bash
set -e

HEIC="/Users/tisfy/Downloads/Photos/IMG_5190/22345678901231.heic"
MOV="/Users/tisfy/Downloads/Photos/IMG_5190/15f=3z81sfx231sfjli298ksjfkJKjf.mov"

OUTDIR="/Users/tisfy/Downloads/Photos/exported"
mkdir -p "$OUTDIR"

# 获取文件大小（macOS / Linux 通用）
filesize() {
    stat -f%z "$1" 2>/dev/null || stat -c%s "$1"
}

HEIC_SIZE=$(filesize "$HEIC")
MOV_SIZE=$(filesize "$MOV")

# 转8位大写16进制
hex8() {
    printf "%08X" "$1"
}

PART3=$(hex8 "$HEIC_SIZE")
PART6=$(hex8 "$MOV_SIZE")

echo "HEIC size: $HEIC_SIZE ($PART3)"
echo "MOV  size: $MOV_SIZE ($PART6)"

for offset in $(seq 50 128); do
    PART5=$(hex8 $((HEIC_SIZE + offset)))

    COMMENT="000200000030${PART3}0003${PART5}${PART6}313030304C495650"

    OUTFILE=$(printf "%s/%03d.livp" "$OUTDIR" "$offset")

    zip -q -0 -X -z "$OUTFILE" "$HEIC" "$MOV" <<EOF
$COMMENT
EOF

    echo "Generated $(basename "$OUTFILE")  part5=$PART5"
done

echo "Done."
```
00020000003000212BCA000300212C3C004E9961313030304C495650 IMG_5190.livp

00020000003000212BCA000300212C3C004E9961313030304C495650 114.livp
00020000003000212BCA000300212C3D004E9961313030304C495650 115.livp
00020000003000212BCA000300212C3E004E9961313030304C495650 116.livp
00020000003000212BCA000300212C3F004E9961313030304C495650

一个都不行？
忽然发现add的是 Users/tisfy/Downloads/Photos/IMG_5190/22345678901231.heic 而不是 22345678901231.heic 

```bash
#!/bin/bash
set -e

HEIC="22345678901231.heic"
MOV="15f=3z81sfx231sfjli298ksjfkJKjf.mov"

OUTDIR="../exported"
mkdir -p "$OUTDIR"

# 获取文件大小（macOS / Linux 通用）
filesize() {
    stat -f%z "$1" 2>/dev/null || stat -c%s "$1"
}

HEIC_SIZE=$(filesize "$HEIC")
MOV_SIZE=$(filesize "$MOV")

# 转8位大写16进制
hex8() {
    printf "%08X" "$1"
}

PART3=$(hex8 "$HEIC_SIZE")
PART6=$(hex8 "$MOV_SIZE")

echo "HEIC size: $HEIC_SIZE ($PART3)"
echo "MOV  size: $MOV_SIZE ($PART6)"

for offset in $(seq 100 120); do
    PART5=$(hex8 $((HEIC_SIZE + offset)))

    COMMENT="000200000030${PART3}0003${PART5}${PART6}313030304C495650"

    OUTFILE=$(printf "%s/%03d.livp" "$OUTDIR" "$offset")

    zip -q -0 -X -z "$OUTFILE" "$HEIC" "$MOV" <<EOF
$COMMENT
EOF

    echo "Generated $(basename "$OUTFILE")  part5=$PART5"
done

echo "Done."
```
```
HEIC size: 2173898 (00212BCA)
MOV  size: 5151073 (004E9961)
Generated 100.livp  part5=00212C2E
Generated 101.livp  part5=00212C2F
Generated 102.livp  part5=00212C30
Generated 103.livp  part5=00212C31
Generated 104.livp  part5=00212C32
Generated 105.livp  part5=00212C33
Generated 106.livp  part5=00212C34
Generated 107.livp  part5=00212C35
Generated 108.livp  part5=00212C36
Generated 109.livp  part5=00212C37
Generated 110.livp  part5=00212C38
Generated 111.livp  part5=00212C39
Generated 112.livp  part5=00212C3A
Generated 113.livp  part5=00212C3B
Generated 114.livp  part5=00212C3C
Generated 115.livp  part5=00212C3D
Generated 116.livp  part5=00212C3E
Generated 117.livp  part5=00212C3F
Generated 118.livp  part5=00212C40
Generated 119.livp  part5=00212C41
Generated 120.livp  part5=00212C42
Done.
```
```
c31fb8b4f87398aa2017f3deb4940158314cf13c5d85d216cbcaa1fb5a18bb46  exported/IMG_5190.livp
c31fb8b4f87398aa2017f3deb4940158314cf13c5d85d216cbcaa1fb5a18bb46  exported/114.livp
```
改为IMG_51901.HEIC.heic和IMG_5190.HEIC.mov（因为IMG_5190.HEIC.heic时候是可以识别的）
坏了，085.livp到105.livp都不可被识别
（原脚本和096.livp的comment结果是一样的）
坏了，000.livp到225.livp都不可被识别
那就先保证静态图的文件名长度固定为18吧。

最后再试试第一个文件名长度变化但是part5不随之变化：静态动态文件名长度分别为18和17时候以下comment合法
00020000003000212BCA000300212C29004E9961313030304C495650
zip -0 -X -z can.livp IMG_5190.HEIC.heic IMG_5190.HEIC.mov <<EOF
00020000003000212BCA000300212C29004E9961313030304C495650
EOF
修改静态文件名为17，继续使用这个comment
zip -0 -X -z canOrCannot.livp IMG_519.HEIC.heic IMG_5190.HEIC.mov <<EOF
00020000003000212BCA000300212C29004E9961313030304C495650
EOF
坏了不行，看来不是和第一个文件名长度计算时候无关。

还是那句话：那就先保证静态图的文件名长度固定为18吧。
共测了24张各种类型的图，livp2.py完美胜任，全部可以识别。
美中不足的是这样在网页端上传，系统没办法自动识别图片拍摄日期（后面也可以尝试修改压缩包修改时间试试）
