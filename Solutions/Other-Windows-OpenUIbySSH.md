---
title: Windows(奇思妙想) - 通过ssh打开带有图形界面的程序 - 一种通过计划任务的曲折实现方式
date: 2025-02-21 21:38:08
tags: [其他, Windows, SSH, 奇思妙想]
categories: [技术思考]
index_img: https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/8fca3be9af1443b9897f432edf83b7bf.png
---

# Windows(奇思妙想) - 通过ssh打开带有图形界面的程序 - 一种通过计划任务的曲折实现方式

## 前言

Windows启用OpenSSH客户端后就可以通过SSH的方式访问Windows了。但是通过SSH启动的程序：

1. 无法显示图形界面
2. 会随着SSH进程的结束而结束

于是想到了一种通过执行“计划任务”的方式脱离SSH以本机的名义执行不随SSH进程结束而结束的带图形界面的应用程序的方式。

## Windows开启SSH

这个教程一搜一大把，这里仅仅列举主要内容以及容易踩坑的地方。

如何开启并连接：

1. 在`Windows设置–>应用–>应用和功能-可选功能`安装`OpenSSH客户端`（过程可能十分缓慢，魔法也难以加速）。
2. 启动`OpenSSH SSH Server(sshd)`服务。（可在`services.msc`通过鼠标启动，也通过命令行`net start sshd`启动）。
3. 保证局域网或公网可访问目标主机，在另一台机器上执行`ssh 用户名@ip地址`并输入密码即可。

踩坑：

1. 如果你是正版Windows并登录了微软账号，有可能你输入系统用户名和开机密码无法访问，但是输入你的微软账户邮箱和密码可以正常登录控制。

## 直接通过SSH启动其他程序效果不尽人意

有了终端，似乎一切都可以执行了。但是当我想执行带“图形界面”的`爱心.exe`时，若执行`start 爱心.exe`，则目标主机和你的主机上都没有任何踪迹，但是可以在任务管理器中看到。

![在后台执行并且不显示界面](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/8fca3be9af1443b9897f432edf83b7bf.png)

可以发现`爱心.exe`在后台执行了，但是不会显示界面。这时候如果断开`ssh`进程连接，则后台的`爱心.exe`也会随之消失。

大概是因为：

> ~~在Windows系统中通过SSH启动GUI程序时无法显示界面，通常是因为SSH会话与图形界面会话隔离导致的。SSH连接默认运行在非交互式控制台会话（通常为Session0），而图形界面程序需要运行在用户的交互式桌面会话（如Session1）~~（未验证）

## 通过任务计划启动UI程序

也就是说，如果能让Windows以为是它自己启动的一个程序，而不是`SSH`调用执行的一个后台程序，就可以正常执行显示界面并且不受SSH进程的约束了。

Windows自己启动一个程序？任务计划不就是干这个的么？

> 理论上，我创建一个到时间自动运行`爱心.exe`的任务计划，Windows到时间自己运行这个程序，那不就脱离我的ssh进程并且能正常显示界面了吗？
>
> 甚至，我直接通过SSH调用命令“立即执行这个计划任务”，是不是就达到了我想要的效果？

于是思路就变成了`创建执行爱心.exe的任务计划 -> 立即执行任务 -> 删除任务计划`。

```batch
schtasks /create /tn "tempStartAiXin" /sc ONCE /tr "cmd /c start 爱心.exe" /ru %USERNAME% /st 00:00
schtasks /run /tn "tempStartAiXin"
schtasks /delete /tn "tempStartAiXin" /f
```

完美！`爱心.exe`在目标主机上成功运行，且不随我ssh会话的结束而终结。

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/145786262)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/02/21/Other-Windows-OpenUIbySSH/)哦~
