---
title: 提瓦特小助手 - 原神抓包的一个不错的Powershell脚本
date: 2022-12-01 14:58:57
tags: [其他, Powershell, 中等, 抓包, 原神, Genshin, 游戏辅助]
categories: [技术思考]
---

昨日见到了<a title="冯凌云">@FLY</a>的“提瓦特小助手”抽卡分析截图，觉得不错，今日搜了一下“提瓦特小助手”，关注了公众号，里面有教程文章：<a href="https://mp.weixin.qq.com/s/ChJwm-ENxrMZKax3YBOoZQ">https://mp.weixin.qq.com/s/ChJwm-ENxrMZKax3YBOoZQ</a>

大致原理是（通过抓包或登录）获取原神的Cookie，再通过此Cookie获取抽奖历史记录，最后存储在“提瓦特小助手”的云端，以便后期显示与分析。

其中介绍了电脑端抓包的方式。一种是安装抓包软件Fiddler手动找到原神抽卡记录的数据包，一种是直接执行脚本，下载一个应用程序，通过应用程序抓包并分析。

命令很简单：

```powershell
iex(irm 'https://lelaer.com/d.ps1')
```

大概原理估计是从```https://lelaer.com/d.ps```下载```powershell```脚本并执行

其中该脚本为：

```powershell
$logLocation = "%userprofile%\AppData\LocalLow\miHoYo\Genshin Impact\output_log.txt";
$logLocationChina = "%userprofile%\AppData\LocalLow\miHoYo\$([char]0x539f)$([char]0x795e)\output_log.txt";

$reg = $args[0]

Write-Host "$([char]0x6b63)$([char]0x5728)$([char]0x83b7)$([char]0x53d6)$([char]0x62bd)$([char]0x5361)$([char]0x5206)$([char]0x6790)$([char]0x94fe)$([char]0x63a5)..." -ForegroundColor Green
Write-Host " "
$logLocation = $logLocationChina

$tmps = $env:TEMP + '\pm.ps1';
if ([System.IO.File]::Exists($tmps)) {
  ri $tmps
}

$path = [System.Environment]::ExpandEnvironmentVariables($logLocation);
if (-Not [System.IO.File]::Exists($path)) {
    Write-Host "$([char]0x627e)$([char]0x4e0d)$([char]0x5230)$([char]0x539f)$([char]0x795e)$([char]0x65e5)$([char]0x5fd7)$([char]0x6587)$([char]0x4ef6)$([char]0x8bf7)$([char]0x81f3)$([char]0x5c11)$([char]0x6253)$([char]0x5f00)$([char]0x7948)$([char]0x613f)$([char]0x5386)$([char]0x53f2)$([char]0x754c)$([char]0x9762)$([char]0x4e00)$([char]0x6b21)" -ForegroundColor Red
  
    if (-NOT ([Security.Principal.WindowsPrincipal][Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole] "Administrator")) {  
        Write-Host "$([char]0x662f)$([char]0x5426)$([char]0x4ee5)$([char]0x7ba1)$([char]0x7406)$([char]0x5458)$([char]0x8eab)$([char]0x4efd)$([char]0x6765)$([char]0x8fd0)$([char]0x884c)$([char]0x811a)$([char]0x672c)$([char]0x003f)$([char]0x6309)$([char]0x0045)$([char]0x006e)$([char]0x0074)$([char]0x0065)$([char]0x0072)$([char]0x952e)$([char]0x6765)$([char]0x7ee7)$([char]0x7eed)$([char]0x6216)$([char]0x6309)$([char]0x5176)$([char]0x4ed6)$([char]0x952e)$([char]0x6765)$([char]0x53d6)$([char]0x6d88)"
        $keyInput = [Console]::ReadKey($true).Key
        if ($keyInput -ne "13") {
            return
        }

        $myinvocation.mycommand.definition > $tmps

        Start-Process powershell -Verb runAs -ArgumentList "-noexit", $tmps, $reg
        break
    }

    return
}

$logs = Get-Content -Path $path
$m = $logs -match "(?m).:/.+(GenshinImpact_Data|YuanShen_Data)"
$m[0] -match "(.:/.+(GenshinImpact_Data|YuanShen_Data))" >$null

if ($matches.Length -eq 0) {
    Write-Host "$([char]0x627e)$([char]0x4e0d)$([char]0x5230)$([char]0x539f)$([char]0x795e)$([char]0x65e5)$([char]0x5fd7)$([char]0x6587)$([char]0x4ef6)$([char]0x8bf7)$([char]0x81f3)$([char]0x5c11)$([char]0x6253)$([char]0x5f00)$([char]0x7948)$([char]0x613f)$([char]0x5386)$([char]0x53f2)$([char]0x754c)$([char]0x9762)$([char]0x4e00)$([char]0x6b21)" -ForegroundColor Red
    return
}

$gamedir = $matches[1]
$cachefile = "$gamedir/webCaches/Cache/Cache_Data/data_2"
$tmpfile = "$env:TEMP/ch_data_2"

Copy-Item $cachefile -Destination $tmpfile

$content = Get-Content -Encoding UTF8 -Raw $tmpfile
$splitted = $content -split "1/0/"
$found = $splitted -match "https.+webstatic.mihoyo.com/.+?game_biz=hk4e_(global|cn)"

$found = $found[$found.Length - 1] -match "(https.+?game_biz=hk4e_(global|cn))"

Remove-Item $tmpfile

if (-Not $found) {

Write-Host "$([char]0x627e)$([char]0x4e0d)$([char]0x5230)$([char]0x539f)$([char]0x795e)$([char]0x65e5)$([char]0x5fd7)$([char]0x6587)$([char]0x4ef6)$([char]0x8bf7)$([char]0x81f3)$([char]0x5c11)$([char]0x6253)$([char]0x5f00)$([char]0x7948)$([char]0x613f)$([char]0x5386)$([char]0x53f2)$([char]0x754c)$([char]0x9762)$([char]0x4e00)$([char]0x6b21)" -ForegroundColor Red
Try{
$tempPath = mkdir "c:\temp" -Force
}
catch{
$tempPath = mkdir "d:\temp" -Force
}

Try{
Invoke-WebRequest -Uri "https://api.lelaer.com/gachalink.exe" -OutFile "$tempPath\gachalink.exe"
Write-Host $tempPath
&"$tempPath\gachalink.exe"
Start-Sleep -m 1000
$url = get-clipboard
Write-Host $url
Write-Host ""
Write-Host "$([char]0x62bd)$([char]0x5361)$([char]0x5206)$([char]0x6790)$([char]0x5730)$([char]0x5740)$([char]0x83b7)$([char]0x53d6)$([char]0x6210)$([char]0x529f)$([char]0xff0c)$([char]0x8bf7)$([char]0x590d)$([char]0x5236)$([char]0x5230)$([char]0x201c)$([char]0x63d0)$([char]0x74e6)$([char]0x7279)$([char]0x5c0f)$([char]0x52a9)$([char]0x624b)$([char]0x201d)$([char]0x4f7f)$([char]0x7528)" -ForegroundColor Green
Write-Host "$([char]0x63d0)$([char]0x74e6)$([char]0x7279)$([char]0x5c0f)$([char]0x52a9)$([char]0x624b)$([char]0x795d)$([char]0x60a8)$([char]0x6c14)$([char]0x6ee1)$([char]0x6ee1)$([char]0xff0c)$([char]0x5341)$([char]0x8fde)$([char]0x51fa)$([char]0x91d1)$([char]0xff0c)$([char]0x5c0f)$([char]0x4fdd)$([char]0x5e95)$([char]0x5fc5)$([char]0x4e2d)$([char]0xff01)" -ForegroundColor Yellow
read-host
}catch{
Write-Host "$([char]0x62bd)$([char]0x5361)$([char]0x5730)$([char]0x5740)$([char]0x83b7)$([char]0x53d6)$([char]0x5931)$([char]0x8d25)$([char]0xff0c)$([char]0x8bf7)$([char]0x624b)$([char]0x52a8)$([char]0x590d)$([char]0x5236) https://lelaer.com/gachalink.exe $([char]0x4e0b)$([char]0x8f7d)$([char]0x5e76)$([char]0x8fd0)$([char]0x884c)$([char]0x7a0b)$([char]0x5e8f)" -ForegroundColor Red
read-host
}

}else{
$wishHistoryUrl = $matches[0] + "#/log"
Write-Host $wishHistoryUrl
Set-Clipboard -Value $wishHistoryUrl
Write-Host " "
Write-Host "$([char]0x62bd)$([char]0x5361)$([char]0x5206)$([char]0x6790)$([char]0x5730)$([char]0x5740)$([char]0x83b7)$([char]0x53d6)$([char]0x6210)$([char]0x529f)$([char]0xff0c)$([char]0x8bf7)$([char]0x590d)$([char]0x5236)$([char]0x5230)$([char]0x201c)$([char]0x63d0)$([char]0x74e6)$([char]0x7279)$([char]0x5c0f)$([char]0x52a9)$([char]0x624b)$([char]0x201d)$([char]0x4f7f)$([char]0x7528)" -ForegroundColor Green
Write-Host "$([char]0x63d0)$([char]0x74e6)$([char]0x7279)$([char]0x5c0f)$([char]0x52a9)$([char]0x624b)$([char]0x795d)$([char]0x60a8)$([char]0x6c14)$([char]0x6ee1)$([char]0x6ee1)$([char]0xff0c)$([char]0x5341)$([char]0x8fde)$([char]0x51fa)$([char]0x91d1)$([char]0xff0c)$([char]0x5c0f)$([char]0x4fdd)$([char]0x5e95)$([char]0x5fc5)$([char]0x4e2d)$([char]0xff01)" -ForegroundColor Yellow

}
read-host
```

我觉得脚本写的挺好的，这种直接通过一行命令下载脚本并执行的方式也很不错。

特写此文以记之。

**脚本来源：**

[提瓦特小助手官网](https://www.lelaer.com/about.php)

**开发者很赞👍**

> 原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/12/01/Other-Powershell-TiWaTeXiaoZuShouZhuaBao/)哦~
> [https://blog.letmefly.xyz/2022/12/01/Other-Powershell-TiWaTeXiaoZuShouZhuaBao/](https://blog.letmefly.xyz/2022/12/01/Other-Powershell-TiWaTeXiaoZuShouZhuaBao/)
