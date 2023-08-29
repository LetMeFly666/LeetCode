---
title: Windows - UWP - 为UWP应用创建桌面快捷方式
date: 2023-08-12 22:18:02
tags: [其他, Windows, UWP]
---

# Windows - UWP - 为UWP应用创建桌面快捷方式

## 前言

这是一个较为简单的方式，不需要过多的命令行。

## How

首先```Win + R -> shell:AppsFolder -> 回车```，

![Win+R](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/20563c6194104c218b5281629262f86d.jpeg)

这将显示电脑上的已安装应用（Win32 & UWP）：

![Applications](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/92a23d855c64466eb4923d697f0ac5e1.jpeg)

找到想要创建快捷方式的UWP应用（这里以QQ音乐UWP为例），```右键 -> 创建快捷方式```

![创建快捷方式](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/37a1acd4d6be49399c79fcfea03b1688.jpeg)

接着会弹出“是否在桌面创建快捷方式”的提醒：

![是否在桌面创建快捷方式](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/2b2ae5e9fea84783b7d4be084d413a43.png)

选择“是”即可

![shortcuts](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/559fc56596c0439685938ed4b9f8e117.png)

其中用到的命令（可复制）

```bash
shell:AppsFolder
```

## 参考

+ [微软Q&A: Desktop shortcut of an UWP app](https://learn.microsoft.com/en-us/answers/questions/69921/desktop-shortcut-of-an-uwp-app)
+ 网络不好的情况下安装UWP：[https://letmefly.blog.csdn.net/article/details/132257018](https://blog.tisfy.eu.org/2023/08/13/Other-Windows-UWP-InstallingUWPinMSStoreUsingTroubleInternet/)

> 原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2023/08/12/Other-Windows-UWP-createShortcutOnDesktop/)哦~
> [https://letmefly.blog.csdn.net/article/details/132254567](https://letmefly.blog.csdn.net/article/details/132254567)

