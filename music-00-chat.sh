#!/bin/bash
###
 # @Author: LetMeFly
 # @Date: 2026-03-29 12:31:05
 # @LastEditors: LetMeFly.xyz
 # @LastEditTime: 2026-03-29 12:38:11
### 



写几个bash脚本：
1. 将 GoodMusic 文件夹下的所有zip文件解密到 original 文件夹中，密码是LetMeFly。
    - 其中每个zip文件夹都是音乐名.zip，里面只有一个音乐文件，如aLIEz - SawanoHiroyuki[nZk] (泽野弘之) + 瑞葵 (mizuki).zip解压会得到aLIEz - SawanoHiroyuki[nZk] (泽野弘之) + 瑞葵 (mizuki).flac。当然也有可能会是其他格式
2. 将original文件夹下的每个文件重新压缩为zip，压缩等级最高，密码仍为LetMeFly，但是zip文件名需要带上原始音乐的后缀，如aLIEz - SawanoHiroyuki[nZk] (泽野弘之) + 瑞葵 (mizuki).flac压缩为aLIEz - SawanoHiroyuki[nZk] (泽野弘之) + 瑞葵 (mizuki).flac.zip，放到GoodMusic-zipped文件夹下
3. 比较  mp3+m4a版音乐  这个文件夹和 original 文件夹中的音乐内容，比较方式是文件名加后缀，生成一个list-original.txt列举所有 original 文件夹中的音乐名字加后缀，生成一个list-diff.txt列举在 mp3+m4a版音乐 这个文件夹中存在但在 original 文件夹中不存在的音乐（主要是后缀不同）
4. 将list-diff.txt中列举的文件 （都是mp3+m4a版音乐 文件夹中文件）压缩为zip，密码LetMeFly，压缩等级最高，放到diff文件夹下

以上所有文件夹均在当前目录中，这几个脚本分开写



修改.sh文件名，前缀加上music-，如music-01-unzip.sh
上传这4个文件