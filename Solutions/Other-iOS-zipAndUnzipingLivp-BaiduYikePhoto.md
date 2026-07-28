---
title: iOS：压缩和解压live图(.livp)——百度一刻相册+百度网盘识别支持
date: 2026-07-04 19:38:47
tags: [Mac, MacOS, iPhone, iOS, 百度网盘, 一刻相册, 照片同步, 逆向]
categories: [技术思考]
description: 市面上首篇把静态图+mov短视频打包回live图的方案，不需要iPhone参与
---

市面上首篇把静态图+mov短视频打包回live图的方案， **不需要iPhone参与** 。

# iOS：压缩和解压live图(.livp)——百度一刻相册+百度网盘识别支持

> 重磅原创!

## 背景

iPhone拍照的live图实际上是一个静态图+一个短视频，如果你把它导入电脑会得到一个文件夹(里面为xx.heic静态图+xx.mov短视频)，如果你把它导入网盘或照片同步工具(如一刻相册)则会得到一个.livp格式的文件(其实是xx.heic静态图和xx.mov短视频的zip)。

截至<span title="2026-07-04 19:38:47">今日</span>市面上有**大量**的 live图/.livp文件 解压或转静态图的方案，但**未能找到任何**关于如何把 .heic静态图+.mov短视频 压缩/打包 回软件可以识别的live图的方案(直接压缩为zip的话网盘/第三方相册识别不了的)。现有的生成live图的方案均需iOS参与，实际上是调用了iOS系统接口存了静态图和动态视频到相册中，无法独立于iPhone相册备份和分享。

经过两个下午的研究，终于找到了*稳定的*可以把 静态图+短视频 打包回 百度网盘和一刻相册可以直接识别的(.livp格式)live图的方案。

## livp文件组成介绍

首先需要明确的是，.livp文件的得到方式是 xx.heic静态图+xx.mov短视频 这两个文件直接压缩为.zip压缩包，然后修改后缀.zip为.livp。

关于网盘/第三方相册能否识别的核心就在于压缩为.zip时候的具体压缩方式。具体的zip压缩需要满足以下几点：

1. 不压缩（别扭吗？不别扭）。`zip`命令添加参数`-0`代表只打包不做压缩，保持原始字节。
2. 去掉额外的文件属性（eXclude extra file attributes）。`zip`命令添加参数`-X`代表 不保存文件的Unix UID/GID等信息。
3. 注释。还需要使用`-z`参数给`.zip`文件添加形如`0002000000300022175F0003002217BE003D8A51313030304C495650`的注释(字符串类型)，用来快速获取原始文件数据在zip文件中的位置信息。

至于*注释*是什么含义？*注释*一共有以下七部分组成：

```
0002 00000030 000E26AB 0003 000E270A 004B806E 313030304C495650
0002 00000030 0010B331 0003 0010B390 004208DB 313030304C495650
0005 00000034 000A0B3C 0003 000A0BA3 001BF0C7 313030304C495650
part1  part2    part3  part4  part5   part6       part7
```

||含义|举例|
|:--:|:--:|:--:|
|part1|静态图类型|0002代表heic<br/>0005代表jepg|
|part2|30+静态图文件名长度|如00000034|
|part3|静态图字节数|如000A0B3C|
|part4|动态图类型|0003代表mov|
|part5|part3<br/>+(30+静态图文件名长度)<br/>+(30+动态图文件名长度)|如000A0BA3|
|part6|动态图字节数|如001BF0C7|
|part7|`1000LIVP`的ASCII码|固定为313030304C495650|

说明：

+ part数值皆为16进制
+ 有关文件名长度皆为30+文件名长度，其中的30是因为ZIP的`Local File Header`固定是30字节
+ part2：若为00000034，0x34等于十进制下的30+22，说明静态图文件名长度为22
+ part5：若为000A0BA3，0x000A0BA3=0x000A0B3C+(30+len(静态图文件名))+(30+len(动态图文件名))，说明静态图文件名长度+动态图文件名长度=43。由part2可知静态图文件名长度为22，故可退出动态图文件名长度为21
+ part3和part6的8位的字节数最大约$2^{4\times 8}$字节，说明静态文件和动态文件的最大大小约为4 GiB
+ 关于静态图和动态图的文件类型，当前静态图仅支持jpeg和heic，动态图仅支持mov

软性规范：

> 前文中的说明是硬性规范，若不遵守则打包出来的.livp不可被识别。
> 
> 在收集到的样本中，还都满足以下(若不遵守还可能能被正常识别的)约束：

+ 文件名中不包含中文、空格
+ zip中Central Directory顺序为 静态图在#1、动态图在#2
+ 静态图、动态图文件名（除后缀）相同，且为`xx.静态图类型`。如`123.JPG.jpeg` + `123.JGP.mov`

<details><summary>
所收集样本如下：
</summary>

| 文件名 | zip comment | part1 | part2 | part3 | part4 | part5 | part6 | part7 | 静态图 | 动态视频 | 静态大小 | 视频大小 | Central Directory顺序 | 静态是否CD Entry #1 | part2文件名验证 | part3大小验证 | part5 offset验证 | part6大小验证 | part7 magic验证 | comment整体验证 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| byDouyinPinglun-1785162346395.zip | 00050000004C0000DEB700030000DF4E00119398313030304C495650 | 0005 | 76 | 57015 | 0003 | 57166 | 1151896 | 313030304C495650 | DB4381BF-ECF6-42C3-A127-5E12F1BD90C1.jpeg.jpeg | DB4381BF-ECF6-42C3-A127-5E12F1BD90C1.jpeg.mov | 57015 | 1151896 | 1:DB4381BF-ECF6-42C3-A127-5E12F1BD90C1.jpeg.jpeg<br>2:DB4381BF-ECF6-42C3-A127-5E12F1BD90C1.jpeg.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| byDouyinPinglun-1785162619642.zip | 00050000004C0003380F0003000338A60044827C313030304C495650 | 0005 | 76 | 210959 | 0003 | 211110 | 4489852 | 313030304C495650 | 476EF0DD-D610-4565-B337-A414D3B446A0.jpeg.jpeg | 476EF0DD-D610-4565-B337-A414D3B446A0.jpeg.mov | 210959 | 4489852 | 1:476EF0DD-D610-4565-B337-A414D3B446A0.jpeg.jpeg<br>2:476EF0DD-D610-4565-B337-A414D3B446A0.jpeg.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| byIPhoneAlbum-2026-06-18 164454.zip | 00020000003000197C18000300197C77003363B1313030304C495650 | 0002 | 48 | 1670168 | 0003 | 1670263 | 3367857 | 313030304C495650 | IMG_4791.HEIC.heic | IMG_4791.HEIC.mov | 1670168 | 3367857 | 1:IMG_4791.HEIC.heic<br>2:IMG_4791.HEIC.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| byWeChat-1785161814000.zip | 0002000000500006754E0003000675ED0004E1A7313030304C495650 | 0002 | 80 | 423246 | 0003 | 423405 | 319911 | 313030304C495650 | 0c39bb34b965b43f4360177c35e63c_livephoto.HEIC.heic | 0c39bb34b965b43f4360177c35e63c_livephoto.HEIC.mov | 423246 | 319911 | 1:0c39bb34b965b43f4360177c35e63c_livephoto.HEIC.heic<br>2:0c39bb34b965b43f4360177c35e63c_livephoto.HEIC.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| byWeibo-1785162196670.zip | 0005000000470002023E0003000202CB0049FE63313030304C495650 | 0005 | 71 | 131646 | 0003 | 131787 | 4849251 | 313030304C495650 | b240fc8f0bf3a4e9124eb274bfc27647.JPG.jpeg | b240fc8f0bf3a4e9124eb274bfc27647.JPG.mov | 131646 | 4849251 | 1:b240fc8f0bf3a4e9124eb274bfc27647.JPG.jpeg<br>2:b240fc8f0bf3a4e9124eb274bfc27647.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| byWeibo-1785162215750.zip | 0005000000470001420E00030001429B0008DB69313030304C495650 | 0005 | 71 | 82446 | 0003 | 82587 | 580457 | 313030304C495650 | 513b1eb80638e900ee3c82c24b624ac2.JPG.jpeg | 513b1eb80638e900ee3c82c24b624ac2.JPG.mov | 82446 | 580457 | 1:513b1eb80638e900ee3c82c24b624ac2.JPG.jpeg<br>2:513b1eb80638e900ee3c82c24b624ac2.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| byiOSLivpMakerA1785140204190.zip | 000200000032000095230003000095860003549D313030304C495650 | 0002 | 50 | 38179 | 0003 | 38278 | 218269 | 313030304C495650 | IMB_TVfDT6.HEIC.heic | IMB_TVfDT6.HEIC.mov | 38179 | 218269 | 1:IMB_TVfDT6.HEIC.heic<br>2:IMB_TVfDT6.HEIC.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| byiOSLivpMakerB1785140239500.zip | 000200000032000095230003000095860003549D313030304C495650 | 0002 | 50 | 38179 | 0003 | 38278 | 218269 | 313030304C495650 | IMB_TItMiu.HEIC.heic | IMB_TItMiu.HEIC.mov | 38179 | 218269 | 1:IMB_TItMiu.HEIC.heic<br>2:IMB_TItMiu.HEIC.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1784822885314.zip | 00050000003400013DA8000300013E0F00290B76313030304C495650 | 0005 | 52 | 81320 | 0003 | 81423 | 2689910 | 313030304C495650 | 1784822885312.JPG.jpeg | 1784822885312.JPG.mov | 81320 | 2689910 | 1:1784822885312.JPG.jpeg<br>2:1784822885312.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1784825599569.zip | 000500000034000282320003000282990026E509313030304C495650 | 0005 | 52 | 164402 | 0003 | 164505 | 2549001 | 313030304C495650 | 1784825599568.JPG.jpeg | 1784825599568.JPG.mov | 164402 | 2549001 | 1:1784825599568.JPG.jpeg<br>2:1784825599568.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1784826018626.zip | 000500000034000A0B3C0003000A0BA3001BF0C7313030304C495650 | 0005 | 52 | 658236 | 0003 | 658339 | 1831111 | 313030304C495650 | 1784826018625.JPG.jpeg | 1784826018625.JPG.mov | 658236 | 1831111 | 1:1784826018625.JPG.jpeg<br>2:1784826018625.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1784826025025.zip | 000500000034000154F2000300015559002AF65D313030304C495650 | 0005 | 52 | 87282 | 0003 | 87385 | 2815581 | 313030304C495650 | 1784826025024.JPG.jpeg | 1784826025024.JPG.mov | 87282 | 2815581 | 1:1784826025024.JPG.jpeg<br>2:1784826025024.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1784826240957.zip | 00050000003400019C03000300019C6A000A5C44313030304C495650 | 0005 | 52 | 105475 | 0003 | 105578 | 678980 | 313030304C495650 | 1784826240956.JPG.jpeg | 1784826240956.JPG.mov | 105475 | 678980 | 1:1784826240956.JPG.jpeg<br>2:1784826240956.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1784826455816.zip | 0005000000340000EFF400030000F05B00117DE0313030304C495650 | 0005 | 52 | 61428 | 0003 | 61531 | 1146336 | 313030304C495650 | 1784826455815.JPG.jpeg | 1784826455815.JPG.mov | 61428 | 1146336 | 1:1784826455815.JPG.jpeg<br>2:1784826455815.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1784826525504.zip | 0005000000340002CEB100030002CF1800404F27313030304C495650 | 0005 | 52 | 183985 | 0003 | 184088 | 4214567 | 313030304C495650 | 1784826525503.JPG.jpeg | 1784826525503.JPG.mov | 183985 | 4214567 | 1:1784826525503.JPG.jpeg<br>2:1784826525503.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1784826548924.zip | 0005000000340000CB3F00030000CBA6004394F4313030304C495650 | 0005 | 52 | 52031 | 0003 | 52134 | 4429044 | 313030304C495650 | 1784826548923.JPG.jpeg | 1784826548923.JPG.mov | 52031 | 4429044 | 1:1784826548923.JPG.jpeg<br>2:1784826548923.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1784826551937.zip | 0005000000340000D4B800030000D51F0024B200313030304C495650 | 0005 | 52 | 54456 | 0003 | 54559 | 2404864 | 313030304C495650 | 1784826551936.JPG.jpeg | 1784826551936.JPG.mov | 54456 | 2404864 | 1:1784826551936.JPG.jpeg<br>2:1784826551936.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1784826661272.zip | 00050000003400026F41000300026FA8002AB14F313030304C495650 | 0005 | 52 | 159553 | 0003 | 159656 | 2797903 | 313030304C495650 | 1784826661271.JPG.jpeg | 1784826661271.JPG.mov | 159553 | 2797903 | 1:1784826661271.JPG.jpeg<br>2:1784826661271.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1784826682972.zip | 0005000000340001A4BC00030001A5230043B766313030304C495650 | 0005 | 52 | 107708 | 0003 | 107811 | 4437862 | 313030304C495650 | 1784826682971.JPG.jpeg | 1784826682971.JPG.mov | 107708 | 4437862 | 1:1784826682971.JPG.jpeg<br>2:1784826682971.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1784826735475.zip | 000500000034000171880003000171EF0020E9EF313030304C495650 | 0005 | 52 | 94600 | 0003 | 94703 | 2157039 | 313030304C495650 | 1784826735474.JPG.jpeg | 1784826735474.JPG.mov | 94600 | 2157039 | 1:1784826735474.JPG.jpeg<br>2:1784826735474.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785111017642.zip | 0005000000340000E80400030000E86B001BB639313030304C495650 | 0005 | 52 | 59396 | 0003 | 59499 | 1816121 | 313030304C495650 | 1785111017640.JPG.jpeg | 1785111017640.JPG.mov | 59396 | 1816121 | 1:1785111017640.JPG.jpeg<br>2:1785111017640.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785111037676.zip | 0005000000340001B61D00030001B68400323B34313030304C495650 | 0005 | 52 | 112157 | 0003 | 112260 | 3291956 | 313030304C495650 | 1785111037674.JPG.jpeg | 1785111037674.JPG.mov | 112157 | 3291956 | 1:1785111037674.JPG.jpeg<br>2:1785111037674.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785111049618.zip | 0005000000340002FA9F00030002FB06002DAE1B313030304C495650 | 0005 | 52 | 195231 | 0003 | 195334 | 2993691 | 313030304C495650 | 1785111049616.JPG.jpeg | 1785111049616.JPG.mov | 195231 | 2993691 | 1:1785111049616.JPG.jpeg<br>2:1785111049616.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785111053035.zip | 0005000000340001B37000030001B3D7003D97C7313030304C495650 | 0005 | 52 | 111472 | 0003 | 111575 | 4036551 | 313030304C495650 | 1785111053034.JPG.jpeg | 1785111053034.JPG.mov | 111472 | 4036551 | 1:1785111053034.JPG.jpeg<br>2:1785111053034.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785111299968.zip | 000500000034000511890003000511F0003DF3B6313030304C495650 | 0005 | 52 | 332169 | 0003 | 332272 | 4060086 | 313030304C495650 | 1785111299966.JPG.jpeg | 1785111299966.JPG.mov | 332169 | 4060086 | 1:1785111299966.JPG.jpeg<br>2:1785111299966.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785111362419.zip | 000500000034000106000003000106670020D1E6313030304C495650 | 0005 | 52 | 67072 | 0003 | 67175 | 2150886 | 313030304C495650 | 1785111362417.JPG.jpeg | 1785111362417.JPG.mov | 67072 | 2150886 | 1:1785111362417.JPG.jpeg<br>2:1785111362417.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785111370279.zip | 000500000034000177640003000177CB001B8306313030304C495650 | 0005 | 52 | 96100 | 0003 | 96203 | 1803014 | 313030304C495650 | 1785111370277.JPG.jpeg | 1785111370277.JPG.mov | 96100 | 1803014 | 1:1785111370277.JPG.jpeg<br>2:1785111370277.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785111573040.zip | 000500000034000151EF000300015256001057C8313030304C495650 | 0005 | 52 | 86511 | 0003 | 86614 | 1071048 | 313030304C495650 | 1785111573038.JPG.jpeg | 1785111573038.JPG.mov | 86511 | 1071048 | 1:1785111573038.JPG.jpeg<br>2:1785111573038.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785111584071.zip | 000500000034000177DC000300017843003F9CD5313030304C495650 | 0005 | 52 | 96220 | 0003 | 96323 | 4168917 | 313030304C495650 | 1785111584070.JPG.jpeg | 1785111584070.JPG.mov | 96220 | 4168917 | 1:1785111584070.JPG.jpeg<br>2:1785111584070.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785111593304.zip | 0005000000340000FCB000030000FD1700251F38313030304C495650 | 0005 | 52 | 64688 | 0003 | 64791 | 2432824 | 313030304C495650 | 1785111593302.JPG.jpeg | 1785111593302.JPG.mov | 64688 | 2432824 | 1:1785111593302.JPG.jpeg<br>2:1785111593302.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785111596758.zip | 00050000003400018D06000300018D6D001E17FD313030304C495650 | 0005 | 52 | 101638 | 0003 | 101741 | 1972221 | 313030304C495650 | 1785111596756.JPG.jpeg | 1785111596756.JPG.mov | 101638 | 1972221 | 1:1785111596756.JPG.jpeg<br>2:1785111596756.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785111677659.zip | 000500000034000165530003000165BA001AAB93313030304C495650 | 0005 | 52 | 91475 | 0003 | 91578 | 1747859 | 313030304C495650 | 1785111677658.JPG.jpeg | 1785111677658.JPG.mov | 91475 | 1747859 | 1:1785111677658.JPG.jpeg<br>2:1785111677658.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785111744347.zip | 000500000034000269960003000269FD00309257313030304C495650 | 0005 | 52 | 158102 | 0003 | 158205 | 3183191 | 313030304C495650 | 1785111744344.JPG.jpeg | 1785111744344.JPG.mov | 158102 | 3183191 | 1:1785111744344.JPG.jpeg<br>2:1785111744344.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785111749921.zip | 00050000003400023E90000300023EF70033207B313030304C495650 | 0005 | 52 | 147088 | 0003 | 147191 | 3350651 | 313030304C495650 | 1785111749919.JPG.jpeg | 1785111749919.JPG.mov | 147088 | 3350651 | 1:1785111749919.JPG.jpeg<br>2:1785111749919.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785111935438.zip | 0005000000340003853800030003859F003AE8EB313030304C495650 | 0005 | 52 | 230712 | 0003 | 230815 | 3860715 | 313030304C495650 | 1785111935436.JPG.jpeg | 1785111935436.JPG.mov | 230712 | 3860715 | 1:1785111935436.JPG.jpeg<br>2:1785111935436.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785112043181.zip | 00050000003400010A40000300010AA700216568313030304C495650 | 0005 | 52 | 68160 | 0003 | 68263 | 2188648 | 313030304C495650 | 1785112043179.JPG.jpeg | 1785112043179.JPG.mov | 68160 | 2188648 | 1:1785112043179.JPG.jpeg<br>2:1785112043179.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785112047699.zip | 0005000000340001315F0003000131C6001B82B1313030304C495650 | 0005 | 52 | 78175 | 0003 | 78278 | 1802929 | 313030304C495650 | 1785112047697.JPG.jpeg | 1785112047697.JPG.mov | 78175 | 1802929 | 1:1785112047697.JPG.jpeg<br>2:1785112047697.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785112087161.zip | 00050000003400046E43000300046EAA0035FBE3313030304C495650 | 0005 | 52 | 290371 | 0003 | 290474 | 3537891 | 313030304C495650 | 1785112087159.JPG.jpeg | 1785112087159.JPG.mov | 290371 | 3537891 | 1:1785112087159.JPG.jpeg<br>2:1785112087159.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785112137552.zip | 00050000003400008BB2000300008C19000C3D77313030304C495650 | 0005 | 52 | 35762 | 0003 | 35865 | 802167 | 313030304C495650 | 1785112137550.JPG.jpeg | 1785112137550.JPG.mov | 35762 | 802167 | 1:1785112137550.JPG.jpeg<br>2:1785112137550.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785112141114.zip | 0005000000340001F30400030001F36B002EB1C2313030304C495650 | 0005 | 52 | 127748 | 0003 | 127851 | 3060162 | 313030304C495650 | 1785112141112.JPG.jpeg | 1785112141112.JPG.mov | 127748 | 3060162 | 1:1785112141112.JPG.jpeg<br>2:1785112141112.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785112153488.zip | 0005000000340002E11300030002E17A003BCB65313030304C495650 | 0005 | 52 | 188691 | 0003 | 188794 | 3918693 | 313030304C495650 | 1785112153486.JPG.jpeg | 1785112153486.JPG.mov | 188691 | 3918693 | 1:1785112153486.JPG.jpeg<br>2:1785112153486.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785112251656.zip | 0005000000340002513400030002519B0027B47F313030304C495650 | 0005 | 52 | 151860 | 0003 | 151963 | 2602111 | 313030304C495650 | 1785112251654.JPG.jpeg | 1785112251654.JPG.mov | 151860 | 2602111 | 1:1785112251654.JPG.jpeg<br>2:1785112251654.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785112256399.zip | 0005000000340001B6AA00030001B711001EC00D313030304C495650 | 0005 | 52 | 112298 | 0003 | 112401 | 2015245 | 313030304C495650 | 1785112256396.JPG.jpeg | 1785112256396.JPG.mov | 112298 | 2015245 | 1:1785112256396.JPG.jpeg<br>2:1785112256396.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785112262047.zip | 000500000034000433F600030004345D000F4363313030304C495650 | 0005 | 52 | 275446 | 0003 | 275549 | 1000291 | 313030304C495650 | 1785112262045.JPG.jpeg | 1785112262045.JPG.mov | 275446 | 1000291 | 1:1785112262045.JPG.jpeg<br>2:1785112262045.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785112523798.zip | 000500000034000445BA00030004462100343063313030304C495650 | 0005 | 52 | 279994 | 0003 | 280097 | 3420259 | 313030304C495650 | 1785112523797.JPG.jpeg | 1785112523797.JPG.mov | 279994 | 3420259 | 1:1785112523797.JPG.jpeg<br>2:1785112523797.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785112535334.zip | 0005000000340001371700030001377E00222ABD313030304C495650 | 0005 | 52 | 79639 | 0003 | 79742 | 2239165 | 313030304C495650 | 1785112535332.JPG.jpeg | 1785112535332.JPG.mov | 79639 | 2239165 | 1:1785112535332.JPG.jpeg<br>2:1785112535332.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785112544283.zip | 000500000034000114F1000300011558001B48FF313030304C495650 | 0005 | 52 | 70897 | 0003 | 71000 | 1788159 | 313030304C495650 | 1785112544281.JPG.jpeg | 1785112544281.JPG.mov | 70897 | 1788159 | 1:1785112544281.JPG.jpeg<br>2:1785112544281.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785112718011.zip | 00050000003400028A03000300028A6A0016BD95313030304C495650 | 0005 | 52 | 166403 | 0003 | 166506 | 1490325 | 313030304C495650 | 1785112718009.JPG.jpeg | 1785112718009.JPG.mov | 166403 | 1490325 | 1:1785112718009.JPG.jpeg<br>2:1785112718009.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785112817780.zip | 0005000000340005C3FB00030005C462003CCE1C313030304C495650 | 0005 | 52 | 377851 | 0003 | 377954 | 3984924 | 313030304C495650 | 1785112817778.JPG.jpeg | 1785112817778.JPG.mov | 377851 | 3984924 | 1:1785112817778.JPG.jpeg<br>2:1785112817778.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785112877488.zip | 0005000000340003092300030003098A00270D80313030304C495650 | 0005 | 52 | 198947 | 0003 | 199050 | 2559360 | 313030304C495650 | 1785112877486.JPG.jpeg | 1785112877486.JPG.mov | 198947 | 2559360 | 1:1785112877486.JPG.jpeg<br>2:1785112877486.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785112881541.zip | 0005000000340004335A0003000433C100345D30313030304C495650 | 0005 | 52 | 275290 | 0003 | 275393 | 3431728 | 313030304C495650 | 1785112881538.JPG.jpeg | 1785112881538.JPG.mov | 275290 | 3431728 | 1:1785112881538.JPG.jpeg<br>2:1785112881538.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785112890568.zip | 000500000034000311A700030003120E0018E081313030304C495650 | 0005 | 52 | 201127 | 0003 | 201230 | 1630337 | 313030304C495650 | 1785112890566.JPG.jpeg | 1785112890566.JPG.mov | 201127 | 1630337 | 1:1785112890566.JPG.jpeg<br>2:1785112890566.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785112937682.zip | 0005000000340004D5A900030004D610006FE812313030304C495650 | 0005 | 52 | 316841 | 0003 | 316944 | 7333906 | 313030304C495650 | 1785112937679.JPG.jpeg | 1785112937679.JPG.mov | 316841 | 7333906 | 1:1785112937679.JPG.jpeg<br>2:1785112937679.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785112942839.zip | 0005000000340004B69E00030004B70500343BCA313030304C495650 | 0005 | 52 | 308894 | 0003 | 308997 | 3423178 | 313030304C495650 | 1785112942837.JPG.jpeg | 1785112942837.JPG.mov | 308894 | 3423178 | 1:1785112942837.JPG.jpeg<br>2:1785112942837.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |
| 1785112957966.zip | 0005000000340003020600030003026D0028F833313030304C495650 | 0005 | 52 | 197126 | 0003 | 197229 | 2684979 | 313030304C495650 | 1785112957964.JPG.jpeg | 1785112957964.JPG.mov | 197126 | 2684979 | 1:1785112957964.JPG.jpeg<br>2:1785112957964.JPG.mov | YES | PASS | PASS | PASS | PASS | PASS | PASS |

<details><summary>
样本说明，TL;DR：
</summary>

`纯数字.zip`的样本来自小红书，文件名以字母开头的样本来源见文件名描述。

样本统计脚本（将所有样本放到一个*专门的*文件夹下运行脚本可得到`livp_analysis.md`）：

```python
# Mainly by ChatGPT

import zipfile
from pathlib import Path


IMAGE_EXT = (
    ".jpg",
    ".jpeg",
    ".heic",
    ".heif",
)

VIDEO_EXT = (
    ".mov",
    ".mp4",
)


def parse_comment(comment: bytes):

    text = comment.decode(
        "ascii",
        errors="replace"
    )

    if len(text) < 48:
        return {}

    return {
        "part1": text[0:4],
        "part2": int(text[4:12], 16),
        "part3": int(text[12:20], 16),
        "part4": text[20:24],
        "part5": int(text[24:32], 16),
        "part6": int(text[32:40], 16),
        "part7": text[40:],
    }


def check_yesno(v):
    return "PASS" if v else "FAIL"


def analyze(zip_path):

    result = {
        "filename": zip_path.name,
        "zip_comment": "",

        "part1": "",
        "part2": "",
        "part3": "",
        "part4": "",
        "part5": "",
        "part6": "",
        "part7": "",

        "static": "",
        "video": "",
        "unknown": "",

        "static_size": "",
        "video_size": "",

        "cd_order": "",

        "static_cd_entry1": "",

        "check_part2_filename": "",
        "check_part3_size": "",
        "check_part5_offset": "",
        "check_part6_size": "",
        "check_part7_magic": "",

        "comment_check": "",
    }


    with zipfile.ZipFile(zip_path, "r") as z:

        result["zip_comment"] = (
            z.comment
            .decode(
                "ascii",
                errors="replace"
            )
        )

        parts = parse_comment(z.comment)

        if parts:
            result.update(parts)


        infos = z.infolist()

        cd_names = []

        unknown = []

        static_info = None
        video_info = None


        for idx, info in enumerate(infos, start=1):

            name = info.filename

            cd_names.append(
                f"{idx}:{name}"
            )

            lower = name.lower()


            if lower.endswith(IMAGE_EXT):

                result["static"] = name
                static_info = info


            elif lower.endswith(VIDEO_EXT):

                result["video"] = name
                video_info = info


            else:
                unknown.append(name)



        result["unknown"] = ",".join(unknown)

        result["cd_order"] = (
            "<br>".join(cd_names)
        )


        if static_info:

            result["static_size"] = (
                static_info.file_size
            )

            result["static_cd_entry1"] = (
                "YES"
                if infos[0].filename
                == static_info.filename
                else "NO"
            )


        if video_info:

            result["video_size"] = (
                video_info.file_size
            )


        #
        # 验证
        #

        checks = []


        if parts and static_info:

            ok = (
                parts["part2"]
                ==
                30 + len(static_info.filename)
            )

            result["check_part2_filename"] = (
                check_yesno(ok)
            )

            checks.append(ok)


            ok = (
                parts["part3"]
                ==
                static_info.file_size
            )

            result["check_part3_size"] = (
                check_yesno(ok)
            )

            checks.append(ok)


        if parts and static_info and video_info:

            ok = (
                parts["part5"]
                ==
                parts["part3"]
                +
                (
                    30
                    +
                    len(static_info.filename)
                )
                +
                (
                    30
                    +
                    len(video_info.filename)
                )
            )

            result["check_part5_offset"] = (
                check_yesno(ok)
            )

            checks.append(ok)


            ok = (
                parts["part6"]
                ==
                video_info.file_size
            )

            result["check_part6_size"] = (
                check_yesno(ok)
            )

            checks.append(ok)



        if parts:

            ok = (
                parts["part7"]
                ==
                "1000LIVP".encode("ascii").hex().upper()  # HERE FIX BY LETMEFLY
            )
            # print(parts["part7"])
            # print("1000LIVP".encode("ascii").hex().upper())

            result["check_part7_magic"] = (
                check_yesno(ok)
            )

            checks.append(ok)


        if checks:
            result["comment_check"] = (
                "PASS"
                if all(checks)
                else "FAIL"
            )


    return result



def md_escape(v):

    return (
        str(v)
        .replace("|", "\\|")
        .replace("\n", "<br>")
    )


def main():

    rows = []

    for p in sorted(
        Path(".").glob("*.zip")
    ):

        print(
            "Analyzing",
            p
        )

        rows.append(
            analyze(p)
        )


    headers = [

        "文件名",
        "zip comment",

        "part1",
        "part2",
        "part3",
        "part4",
        "part5",
        "part6",
        "part7",

        "静态图",
        "动态视频",

        "静态大小",
        "视频大小",

        "Central Directory顺序",

        "静态是否CD Entry #1",

        "part2文件名验证",
        "part3大小验证",
        "part5 offset验证",
        "part6大小验证",
        "part7 magic验证",

        "comment整体验证",
    ]


    with open(
        "livp_analysis.md",
        "w",
        encoding="utf-8"
    ) as f:


        f.write(
            "# LIVP分析结果\n\n"
        )


        f.write(
            "| "
            +
            " | ".join(headers)
            +
            " |\n"
        )

        f.write(
            "| "
            +
            " | ".join(
                ["---"] * len(headers)
            )
            +
            " |\n"
        )


        for r in rows:

            values = [

                r["filename"],
                r["zip_comment"],

                r["part1"],
                r["part2"],
                r["part3"],
                r["part4"],
                r["part5"],
                r["part6"],
                r["part7"],

                r["static"],
                r["video"],

                r["static_size"],
                r["video_size"],

                r["cd_order"],

                r["static_cd_entry1"],

                r["check_part2_filename"],
                r["check_part3_size"],
                r["check_part5_offset"],
                r["check_part6_size"],
                r["check_part7_magic"],

                r["comment_check"],
            ]


            f.write(
                "| "
                +
                " | ".join(
                    md_escape(x)
                    for x in values
                )
                +
                " |\n"
            )


if __name__ == "__main__":
    main()
```

</details>

</details>



## 静态图+动态图->live图脚本

如果你有一个.jpg/.jpeg格式的静态图和一个.mov格式的动态视频，则可以使用[以下脚本](https://github.com/LetMeFly666/2livp/blob/9a32caee3c3c12fc3b28501a933dd377b8e9edfc/livp_pack1.py)将其打包为一个动态图。

<details>
<summary>脚本点我展开</summary>


```python
"""
livp_pack1.py

将一个静态图 + 一个动态图打包为可识别的 .livp 文件。

支持：

静态图：
    *.jpeg
    *.jpg
    *.heic
    *.HEIC.heic

动态图：
    *.mov


生成规则：

ZIP:
    - 不压缩
    - 不保存 extra attributes
    - Central Directory:
        静态图
        动态图

ZIP comment:

    part1 part2 part3 part4 part5 part6 part7

其中：

part1:
    静态类型
        heic = 0002
        jpeg = 0005

part2:
    30 + 静态文件名长度

part3:
    静态文件大小

part4:
    mov
        0003

part5:
    静态 offset + 30 + static_name_len
               + 30 + dynamic_name_len

part6:
    动态文件大小

part7:
    1000LIVP ASCII hex
"""


import argparse
import os
import struct
import subprocess
import tempfile
import shutil


MAGIC = "313030304C495650"


STATIC_TYPES = {
    ".heic": "0002",
    ".jpeg": "0005",
    ".jpg": "0005",
}


def detect_static_type(filename):
    """
    判断静态图片类型
    """

    lower = filename.lower()

    if lower.endswith(".heic"):
        return "0002"

    if lower.endswith(".jpeg") or lower.endswith(".jpg"):
        return "0005"

    raise ValueError(
        f"不支持的静态图片类型: {filename}"
    )


def check_inputs(static, dynamic):

    if not os.path.isfile(static):
        raise FileNotFoundError(static)

    if not os.path.isfile(dynamic):
        raise FileNotFoundError(dynamic)

    if not dynamic.lower().endswith(".mov"):
        raise ValueError(
            "动态图必须为 mov"
        )


def check_filename_rule(static, dynamic):

    """
    软规范：

    xxx.xxx.jpeg
    xxx.xxx.mov

    去掉最后扩展名后必须一致
    """

    s = os.path.basename(static)
    d = os.path.basename(dynamic)

    s_prefix = os.path.splitext(s)[0]
    d_prefix = os.path.splitext(d)[0]

    if s_prefix != d_prefix:
        raise ValueError(
            "静态图和动态图文件名主体不一致:\n"
            f"{s}\n{d}"
        )


def build_comment(static, dynamic):

    static_name = os.path.basename(static)
    dynamic_name = os.path.basename(dynamic)

    static_type = detect_static_type(static)

    static_size = os.path.getsize(static)
    dynamic_size = os.path.getsize(dynamic)


    # Local File Header 固定30字节
    static_name_len = len(
        static_name.encode("utf-8")
    )

    dynamic_name_len = len(
        dynamic_name.encode("utf-8")
    )


    # static offset
    #
    # 第一个文件永远 offset 0
    #

    static_offset = 0


    part2 = 30 + static_name_len


    #
    # dynamic Local Header offset:
    #
    # static local header
    # + static data
    #

    dynamic_offset = (
        static_offset
        + 30
        + static_name_len
        + static_size
    )


    part5 = (
        dynamic_offset
        + 30
        + dynamic_name_len
    )


    parts = [
        static_type,
        f"{part2:08X}",
        f"{static_size:08X}",
        "0003",
        f"{part5:08X}",
        f"{dynamic_size:08X}",
        MAGIC,
    ]


    return "".join(parts)



def create_zip(static, dynamic, output):

    """
    使用系统 zip 创建基础包

    注意：
    不能用 Python zipfile
    """

    with tempfile.TemporaryDirectory() as tmp:

        temp_zip = os.path.join(
            tmp,
            "tmp.zip"
        )


        #
        # -0:
        #   store only
        #
        # -X:
        #   exclude extra attributes
        #

        cmd = [
            "zip",
            "-0",
            "-X",
            temp_zip,
            os.path.basename(static),
            os.path.basename(dynamic),
        ]


        subprocess.run(
            cmd,
            cwd=os.path.dirname(static),
            check=True,
            stdout=subprocess.DEVNULL,
        )


        #
        # 写入 comment
        #

        comment = build_comment(
            static,
            dynamic
        )


        with open(temp_zip, "rb") as f:
            data = f.read()


        #
        # ZIP End Of Central Directory:
        #
        # signature:
        # 4 bytes
        #
        # comment length:
        # offset +20
        #

        eocd = data.rfind(
            b"PK\x05\x06"
        )

        if eocd < 0:
            raise RuntimeError(
                "不是有效zip"
            )


        old_len = struct.unpack(
            "<H",
            data[eocd+20:eocd+22]
        )[0]


        #
        # 去掉旧comment
        #

        data = (
            data[:eocd+20]
            +
            struct.pack(
                "<H",
                len(comment)
            )
            +
            data[eocd+22+old_len:]
        )


        data += comment.encode(
            "ascii"
        )


        with open(output, "wb") as f:
            f.write(data)



def main():

    parser = argparse.ArgumentParser(
        description=
        "将静态图+动态图打包为 livp"
    )


    parser.add_argument(
        "static",
        help="静态图片"
    )

    parser.add_argument(
        "dynamic",
        help="动态图 mov"
    )

    parser.add_argument(
        "output",
        help="输出 .livp"
    )


    args = parser.parse_args()


    check_inputs(
        args.static,
        args.dynamic
    )


    check_filename_rule(
        args.static,
        args.dynamic
    )


    if not args.output.endswith(".livp"):
        raise ValueError(
            "输出文件必须为 .livp"
        )


    create_zip(
        args.static,
        args.dynamic,
        args.output
    )


    print(
        "完成:",
        args.output
    )


if __name__ == "__main__":
    main()
```


</details>

脚本使用方式：

```bash
python live_pack1.py 静态文件路径 动态文件路径 导出livp文件路径
# 如：python live_pack1.py a.JPG.jpeg a.JPG.mov LetMeFly.xyz.Handsome.livp
```

最新脚本请见[Github@LetMeFly666/2livp](https://github.com/LetMeFly666/2livp)

## 杂念

为何没有两图压为live图的方案？因为实际上`.livp`格式的live图本来就不是Apple公司官方定义的，只是大多互联网厂商为了适配苹果live图推出的不约而同的格式。

把相册中live图下载后解压缩比较容易，但是由于没有官方的压缩方案，所以压缩回去就比较困难了。

## Mac/iOS系统上的live图方案（以及传输到Windows上）

iOS拍摄的live图如果想通过iCloud之外的方式同步到其他电脑/设备，主要有两个地方可以设置：

1. 数据线传输时：`iPhone -> 设置(settings) -> 应用(Apps) -> 照片(photos) -> 最下面的“传输到Mac或PC”(Transfer to Mac or PC) -> 保留原片(Keep Originals)`
2. AirDrop时：`分享 -> 选项(Options) -> 打开“所有照片数据”(All Photos Data)`

这样分享一张照片会在电脑上得到一个文件夹。

## 将一个文件夹下所有的图片(甚至非图片文件)导出，能合成动态图则合成

将手机上一堆照片传输到电脑上后，会得到一个个如`IMG_5526`的文件夹。

将这些文件夹所在的文件夹路径记下来（如果在下载文件夹下则路径为`~/Downloads`），把[以下脚本](https://github.com/LetMeFly666/2livp/blob/9a32caee3c3c12fc3b28501a933dd377b8e9edfc/livp_export.py)保存为`lets_export_photos.py`，运行`python lets_export_photos.py 照片文件夹所在路径`命令，即可在`照片文件夹所在路径/_exported`文件夹下找到一个个导出的照片文件，有的是静态图有的是live图，直接拖拽到百度网盘或一刻相册即可直接上传。

脚本默认会使用硬链接的方式导出图片(或文件)，不会占用额外空间。

<details>
<summary>脚本点我展开</summary>


```python
"""
livp_export.py

递归导出图片目录。

规则：

1.
如果一个目录中存在：

    xxx.jpeg.jpeg
    xxx.jpeg.mov

或者：

    xxx.HEIC.heic
    xxx.HEIC.mov

则：

    打包为 xxx.livp

    不导出原始两个文件。


2.
否则：

    导出目录中的所有文件。


输出：

默认：

    输入目录/_exported


如果存在：

    _exported_xxxxxxxx


所有文件直接放在输出目录：

    output/
        a.jpeg
        b.mov
        c.livp


文件冲突自动增加：

    _1
    _2


普通文件：

优先硬链接：

    os.link()

失败：

    shutil.copy2()
"""


import argparse
import os
import shutil
import subprocess
import uuid


STATIC_EXTENSIONS = {
    ".jpg",
    ".jpeg",
    ".heic",
}


def is_static(filename):

    lower = filename.lower()

    return any(
        lower.endswith(x)
        for x in STATIC_EXTENSIONS
    )



def is_dynamic(filename):

    return filename.lower().endswith(
        ".mov"
    )



def exported_name(path):

    """
    解决同名文件

    xxx.jpg

    xxx_1.jpg
    xxx_2.jpg
    """

    if not os.path.exists(path):
        return path


    dirname = os.path.dirname(path)

    filename = os.path.basename(path)


    name, ext = os.path.splitext(filename)


    i = 1

    while True:

        new = os.path.join(
            dirname,
            f"{name}_{i}{ext}"
        )


        if not os.path.exists(new):
            return new

        i += 1



def safe_link(src, dst):

    """
    优先硬链接

    失败复制
    """

    try:

        os.link(
            src,
            dst
        )

    except OSError:

        shutil.copy2(
            src,
            dst
        )



def create_output_dir(src, user_output):

    if user_output:

        os.makedirs(
            user_output,
            exist_ok=True
        )

        return user_output


    base = os.path.join(
        src,
        "_exported"
    )


    if not os.path.exists(base):

        os.makedirs(base)

        return base


    while True:

        name = (
            "_exported_"
            +
            uuid.uuid4()
            .hex[:8]
        )


        path = os.path.join(
            src,
            name
        )


        if not os.path.exists(path):

            os.makedirs(path)

            return path



def find_live_pairs(files):

    """
    返回：

    [
        (
          static,
          mov
        )
    ]

    """

    statics = {}
    movs = {}


    for f in files:

        full = f


        base, ext = os.path.splitext(
            os.path.basename(f)
        )


        if is_static(f):

            statics[base] = full


        elif is_dynamic(f):

            movs[base] = full



    pairs = []


    for key in statics:

        if key in movs:

            pairs.append(
                (
                    statics[key],
                    movs[key]
                )
            )


    return pairs



def pack_live(static, mov, output):

    """
    调用脚本一
    """

    script = os.path.join(
        os.path.dirname(
            os.path.abspath(__file__)
        ),
        "livp_pack.py"
    )


    subprocess.run(
        [
            "python3",
            script,
            static,
            mov,
            output,
        ],
        check=True
    )



def export_directory(src, output):

    """
    处理单个目录

    """

    files = []

    for name in os.listdir(src):

        path = os.path.join(
            src,
            name
        )

        if os.path.isfile(path):

            files.append(path)



    handled = set()


    #
    # 先处理 live pair
    #

    pairs = find_live_pairs(files)


    for static, mov in pairs:


        base = os.path.splitext(
            os.path.basename(static)
        )[0]


        out = exported_name(
            os.path.join(
                output,
                base + ".livp"
            )
        )


        print(
            "[LIVP]",
            static,
            "+",
            mov,
            "->",
            out
        )


        pack_live(
            static,
            mov,
            out
        )


        handled.add(
            static
        )

        handled.add(
            mov
        )



    #
    # 其他全部导出
    #

    for f in files:


        if f in handled:

            continue


        out = exported_name(
            os.path.join(
                output,
                os.path.basename(f)
            )
        )


        print(
            "[FILE]",
            f,
            "->",
            out
        )


        safe_link(
            f,
            out
        )



def main():

    parser = argparse.ArgumentParser(
        description=
        "递归导出图片并转换 live 图为 livp"
    )


    parser.add_argument(
        "input",
        help="输入目录"
    )


    parser.add_argument(
        "--output",
        help="输出目录"
    )


    args = parser.parse_args()



    src = os.path.abspath(
        args.input
    )


    if not os.path.isdir(src):

        raise ValueError(
            "输入必须是目录"
        )


    output = create_output_dir(
        src,
        args.output
    )


    print(
        "输出目录:",
        output
    )



    #
    # 递归遍历
    #

    for root, dirs, files in os.walk(src):


        #
        # 不扫描输出目录
        #

        if os.path.abspath(root) == os.path.abspath(output):

            continue



        paths = [
            os.path.join(root, x)
            for x in files
        ]


        if paths:

            export_directory(
                root,
                output
            )



    print(
        "完成"
    )



if __name__ == "__main__":
    main()

"""
run result:
python /Users/tisfy/Projects/2livp/livp_export.py . 
输出目录: /Users/tisfy/Downloads/1/_exported
[FILE] /Users/tisfy/Downloads/1/.DS_Store -> /Users/tisfy/Downloads/1/_exported/.DS_Store
[FILE] /Users/tisfy/Downloads/1/IMG_5114/IMG_5114.PNG -> /Users/tisfy/Downloads/1/_exported/IMG_5114.PNG
[FILE] /Users/tisfy/Downloads/1/1/.DS_Store -> /Users/tisfy/Downloads/1/_exported/.DS_Store_1
[FILE] /Users/tisfy/Downloads/1/1/2/某线上AI峰会电话.m4a -> /Users/tisfy/Downloads/1/_exported/某线上AI峰会电话.m4a
[LIVP] /Users/tisfy/Downloads/1/IMG_5120/IMG_5120.HEIC + /Users/tisfy/Downloads/1/IMG_5120/IMG_5120.MOV -> /Users/tisfy/Downloads/1/_exported/IMG_5120.livp
完成: /Users/tisfy/Downloads/1/_exported/IMG_5120.livp
"""
```

</details>

最新脚本请见[Github@LetMeFly666/2livp](https://github.com/LetMeFly666/2livp)


> 特别说明：
>
> 你需要保证你系统上有python环境、zip命令。
> 
> 上述脚本的执行过程中，例如目录结构为：
> 
> ```
> Photos/
> ├── 1
> │   └── 2
> │       └── 某线上AI峰会电话.m4a
> ├── emptyFolder
> ├── IMG_5114
> │   └── IMG_5114.PNG
> └── IMG_5120
>     ├── IMG_5120.HEIC
>     └── IMG_5120.MOV
> ```
> 
> 则执行`python lets_export_photos.py ~/Downloads/Photos`将会生成：
> 
> ```
> Photos/
> ├── _exported
> │   ├── IMG_5114.PNG
> │   ├── IMG_5120.livp
> │   └── 某线上AI峰会电话.m4a
> ├── 1
> │   └── 2
> │       └── 某线上AI峰会电话.m4a
> ├── emptyFolder
> ├── IMG_5114
> │   └── IMG_5114.PNG
> └── IMG_5120
>     ├── IMG_5120.HEIC
>     └── IMG_5120.MOV
> ```

## The End

Github仓库：[LetMeFly666/2livp](https://github.com/LetMeFly666/2livp)

<details><summary>
这个是原探究过程，TL;DR：
</summary>

````markdown
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
````

</details>

<details><summary>这个是版本2(<a href="https://github.com/LetMeFly666/2livp/releases/tag/v1.1.0">v1.1.0</a>)的探究过程，TL;DR：</summary>

0002000000300022175F0003002217BE003D8A51313030304C495650
0002 00000030 0010B331 0003 0010B390 004208DB 313030304C495650
part1  part2    part3  part4  part5   part6       part7
+ part1: 0002
+ part2: 00000030
+ part3: heic字节数(16进制)
+ part4: 0003
+ part5: part3+(30+静态图文件名长度)+(30+动态图文件名长度)，目前来看其中**静态图文件名长度必须是18**
+ part6: mov字节数(16进制)
+ part7: 313030304C495650(ASCII含义为1000LIVP)

000500000034000A0B3C0003000A0BA3001BF0C7313030304C495650
0005 00000034 000A0B3C 0003 000A0BA3 001BF0C7 313030304C495650
part1  part2    part3  part4  part5   part6       part7
+ part1: 之前的0002->现在的0005
+ part2: 30+静态图文件名长度，30+len('1784826018625.JPG.jpeg')=0x34，之前的30+18=0x30也符合
+ part3: 静态图字节数(16进制) 658236=0x000A0B3C
+ part4: 目前还是0003
+ part5: part3+(30+静态图文件名长度)+(30+动态图文件名长度)，0x000A0B3C+(30+len('1784826018625.JPG.jpeg'))+(30+len('1784826018625.JPG.mov'))=0x000A0BA3
+ part6: mov字节数(16进制) 1831111=0x001BF0C7
+ part7: 313030304C495650(ASCII含义为1000LIVP)

猜测0002-heic、0003-mov、0005-jpeg

感谢万能的小红书，让我收集到了47张实况图。


---

我收集了47张实况图（在当前文件夹下如1784822885314.zip、1784825599569.zip等共计47个.zip文件）
有没有办法写一个脚本统计：文件名、zipfile comment、zip里面静态图文件名、zip里面动态视频文件名；以及额外的：part1、静态图文件名、part4、动态视频文件名
这些字段？
并保存为markdown。



不对嗷，comment长这样，part含义如下：
0005 00000034 000A0B3C 0003 000A0BA3 001BF0C7 313030304C495650
part1  part2    part3  part4  part5   part6       part7
+ part1: xxx
+ part2: xxx
+ part3: xxx
+ part4: xxx
+ part5: xxx
+ part6: xxx
+ part7: xxx
此外，你静态动态文件的判断再加个else吧，万一有文件不在你的枚举范围内
此外表格再加个字段，静态图是否总是Central directory entry #1

---

题外话：小红书保存的livp图片似乎都是时间戳（毫秒版）.xxx

---

目前找到的抖音图文的live图下载下来都是视频，不是live图，只有评论区的才是

---

>>> bytes.fromhex('313030304C495650').decode("ascii")
'1000LIVP'


---

请编写两个脚本，满足以下所有规范（硬性+软性）

脚本一：
打包一个静态图和一个动态图为.livp

脚本二：
导出一个文件夹下的所有图片：
当一个文件夹或子文件夹中存在且存在满足命名要求的静态图和动态的时，将其打包为.livp，不再导出原始两张图片；否则将原始文件导出（不论文件种类）。
导出文件夹默认为给定文件夹下新建一个_exported文件夹，如已经存在这个文件夹则新建一个暂不存在的_exported_random后缀文件夹，也可指定导出文件夹位置。所有文件直接在这个导出文件夹中，不再创建子文件夹。
如果将两个文件打包为了.livp，则直接写文件到对应位置；否则尽量将文件硬链接到对应位置。注意原始文件夹中可能存在子文件夹，导出时候若存在同名文件记得加上后缀。

脚本中写清楚使用说明。

一定满足上面所有要求、下面所有规范。

--- 以下是规范 ---



</details>

<center><font size="6px" face="Ink Free">The Real End, Thanks!</font></center>

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/162586089)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/07/04/Other-iOS-zipAndUnzipingLivp-BaiduYikePhoto/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
