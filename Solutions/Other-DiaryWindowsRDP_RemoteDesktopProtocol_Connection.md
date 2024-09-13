---
title: 日记 - Windows远程桌面(RDP, Remote Desktop Protocol)跳坑指北
date: 2024-09-13 00:14:12
tags: [日记, Windows]
---

# 日记 - Windows远程桌面(RDP, Remote Desktop Protocol)跳坑指北

## 前言

局域网下，RDP确实很好用。但由于Windows配置起来涉及到的东西有点多（防火墙、策略组、xxx），看似简单的设置却很容易踩坑。

今日踩坑了半小时，终于找到原因了。

## 原因

原因是在设置中开启远程连接后，默认监听的端口号竟然不是3389！而连接的时候默认的端口号是3389。

可以查看注册表：`HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Terminal Server\WinStations\RDP-Tcp`的`PortNumber`这个值，这个值对应的是端口号。

## 方法

方法有二：

1. 修改这个值为十进制下的3389，这样在另一台主机上直接属于这台主机的ip就好了
2. 不修改这个值（假设默认值为1234），在另一台主机上连接时输入`ip:1234`

## End

<center><font size="6px" face="Ink Free">The End, thanks!</font></center>

> 原文链接[https://blog.letmefly.xyz/2024/09/13/Other-DiaryWindowsRDP_RemoteDesktopProtocol_Connection](https://blog.letmefly.xyz/2024/09/13/Other-DiaryWindowsRDP_RemoteDesktopProtocol_Connection)
