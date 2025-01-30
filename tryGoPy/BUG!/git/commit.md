<!--
 * @Author: LetMeFly
 * @Date: 2025-01-30 17:33:48
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-30 17:38:16
-->
```powershell
git version
# git version 2.42.0.windows.2
echo $psversiontable
# Name                           Value
# ----                           -----
# PSVersion                      5.1.19041.5369
# PSEdition                      Desktop
# PSCompatibleVersions           {1.0, 2.0, 3.0, 4.0...}
# BuildVersion                   10.0.19041.5369
# CLRVersion                     4.0.30319.42000
# WSManStackVersion              3.0
# PSRemotingProtocolVersion      2.3
# SerializationVersion           1.1.0.1

mkdir temp
cd temp
git init

echo 1 > 1
git add .
git commit -s -m "1

#2
"
git log
```

得到结果：

```
commit 4d17d9a324736aa1a66317c378790d55f445c9de (HEAD -> master)
Author: LetMeFly666 <814114971@qq.com>
Date:   Thu Jan 30 17:35:10 2025 +0800

    1

    Signed-off-by: LetMeFly666 <814114971@qq.com>

    #2
```

这个#2跑signed-off下面去了。

最初发现于：

https://github.com/LetMeFly666/douyinec/commit/cb1dca1344cec7bf07ff991391ada2d22ac98ed5

但是如果

```powershell
git commit -s -m "1

2"
```

的话就一切正常。
