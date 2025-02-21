---
title: Windows - Windows10绕过登录（修改）密码登录：未验证
date: 2023-07-05 16:47:37
tags: [其他, Windows]
---

## 前言

今日在[BiliBili](https://www.bilibili.com/video/BV12X4y1q7hZ/)上看到有UP主修改Win10密码开机成功的视频，发现思路很新，特记录之。

## 原理

Win10登录界面有“轻松访问”按钮：

<center>
    <svg width="102.000000" height="93.000000" viewBox="0 0 102 93" fill="none" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink">
        <desc>
            Author: LetMeFly(https://www.letmefly.xyz). Created with Pixso(https://pixso.cn/).
        </desc>
        <defs/>
        <rect width="102.000000" height="93.000000" fill="#FFFFFF"/>
        <circle id="椭圆 1" r="41.500000" transform="matrix(1 0 0 1 46 47)" stroke="#000000" stroke-width="7.000000"/>
        <rect id="矩形 1" x="40.000000" width="53.000000" height="51.000000" fill="#FFFFFF"/>
        <line id="直线 1" x1="46.000000" y1="45.000000" x2="46.000000" y2="0.000000" stroke="#000000" stroke-width="7.000000"/>
        <line id="直线 1" x1="55.000000" y1="45.000000" x2="95.000000" y2="45.000000" stroke="#000000" stroke-width="7.000000"/>
        <path id="多边形 1" d="M102 44.5L92.25 35.4067L92.25 53.5933L102 44.5Z" fill-rule="evenodd" fill="#000000"/>
        <line id="直线 3" x1="53.000000" y1="47.000000" x2="55.000000" y2="47.000000" stroke="#000000" stroke-width="3.000000"/>
        <line id="直线 2" x1="51.000000" y1="49.000000" x2="58.000000" y2="39.000000" stroke="#FFFFFF" stroke-width="3.000000"/>
        <line id="直线 4" x1="9.000000" y1="45.000000" x2="0.000000" y2="45.000000" stroke="#FFFFFF" stroke-width="3.000000"/>
        <line id="直线 4" x1="11.000000" y1="16.000000" x2="17.363953" y2="22.363953" stroke="#FFFFFF" stroke-width="3.000000"/>
        <line id="直线 4" x1="11.000000" y1="77.363968" x2="17.363953" y2="71.000000" stroke="#FFFFFF" stroke-width="3.000000"/>
        <line id="直线 4" x1="73.000000" y1="73.000000" x2="79.363968" y2="79.363968" stroke="#FFFFFF" stroke-width="3.000000"/>
        <line id="直线 4" x1="46.000000" y1="93.000000" x2="46.000000" y2="84.000000" stroke="#FFFFFF" stroke-width="3.000000"/>
        <path id="多边形 1" d="M46.5 52L55.5933 42.25L37.4067 42.25L46.5 52Z" fill-rule="evenodd" fill="#000000"/>
    </svg>
</center>

其实执行的是```C:\windows\system32\utilman.exe```。

如果使用“cmd.exe”替换“utilman.exe”，那么在登录界面点击“轻松访问”按钮就会调用“cmd.exe”，在cmd中更改当前用户的密码即可。

怎么在不登录的情况下将utilman.exe替换为cmd.exe呢？我们需要借助“U盘重装系统”。并不是真的重装系统，而是借助重装系统之名，对utilman.exe进行替换。

**1. 制作PE盘**

使用一个不小于8G的U盘，下载```https://www.microsoft.com/zh-cn/software-download/windows10```，选择“为另一台电脑安装介质（U盘、DVD 或 ISO文件）”。

**2. 替换utilman.exe**

接着将U盘插入要绕过登录密码的电脑，在电脑开机时进入BIOS，选择“通过U盘启动”。

在U盘的“系统安装向导”界面按```Shift + F10```，弹出CMD命令窗口。这就基本上想干什么就能干什么了。

```bash
cd C:\windows\system32\
ren utilman.exe utilman_backup.exe
copy cmd.exe utilman.exe
```

取消安装。

**3. 正常进入电脑并在登录界面点击“轻松访问”**

关机，拔U盘，开机，在系统登陆界面点击“轻松访问”，即可弹出CMD窗口。

修改当前用户登录密码：

```bash
net user 用户名 新密码
```

即可使用新密码登录该用户。

## More

为什么不在U盘重装系统时的CMD中修改用户密码呢？权限不够？CMD执行者非当前用户？

> 原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/07/05/Other-Windows-LoginWindowsWithoutPassword/)哦~
> [https://blog.letmefly.xyz/2023/07/05/Other-Windows-LoginWindowsWithoutPassword/](https://blog.letmefly.xyz/2023/07/05/Other-Windows-LoginWindowsWithoutPassword/)

