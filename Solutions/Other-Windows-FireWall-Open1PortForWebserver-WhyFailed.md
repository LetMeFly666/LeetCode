---
title: Windows - 防火墙 - 如何开启单个端口以供Web应用访问(以82端口为例) - 开启端口后还是访问失败了？
date: 2024-01-31 17:45:31
tags: [其他, Windows, FireWall]
description: 无效搜索：windows防火墙开放了端口 局域网还是无法访问 | windows开启防火墙的某个端口 | （已解决）同一局域网下关闭了windows防火墙，外部仍然无法访问本机的java服务 | windows开放防火墙端口之后，为何在外部链接不成功呢【系统内部开通0.0.0.0监听且防火墙开通才能访问】
---

# Windows - 防火墙 - 如何开启单个端口以供Web应用访问(以82端口为例) - 开启端口后还是访问失败了？

## 前言

在网上搜“防火墙开启某个端口”供其他机器访问，都是只讲到了“如何允许某个端口被访问”，而没有后续了。

我之前就遇到过这个问题，开启端口后仍然无法在局域网内的其他机器上访问我的主机，关掉防火墙后就可以访问了。

百思不得其解，突然灵光一闪，一试果然可以。

## Why

单单开放本设备的82端口，其他设备是可以访问本设备的82端口了。但是想要从82端口转发到提供web服务的程序（后面以Python为例），还需要保证“允许Python穿过防火墙”，或者说“不拒绝Python穿过防火墙”。

之前在运行Python程序的时候弹出过“是否允许Python穿过防火墙”，没有点“允许”而是关掉了，导致防火墙多了一条“禁止Python穿过防火墙”的规则。

因此其他设备的访问到达本机的82端口后，没有被转发给Web服务的提供着Python，其他设备上无法看到页面。

![Python被禁止穿过防火墙](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/direct/ea101f65d2834b53875403c0f6694e8d.png)

## How

分为两步：

1. 允许82端口的入站
2. 不禁止Python穿过防火墙

### 1. 允许82端口的入站

（```Win + R``` + ```contrl``` + ```回车```或其他方式）打开控制面板，访问```控制面板\所有控制面板项\Windows Defender 防火墙```，点击```高级设置```。

![防火墙高级设置](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/direct/6030ac0a090f44cfa1a15ba3bd14d9a6.png)

点击```入站规则```，点击```新建规则```，选择```端口```，```下一页```。

![第一步](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/direct/41024e70e4f049549847b6e6fc53d0b3.png)

选择你要开启的协议类型（网页服务的话一般是TCP），输入你要开放的端口（后端服务提供程序的端口），```下一页```。

![第二步](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/direct/d8465771bfcb4301827233ee60e8e6ca.png)

选择```允许连接```，```下一页```。

![第三步](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/direct/90c56072231740eca536a3ce42e9b5c0.png)

选择你允许访问的网络，若不清楚你当前连接的网络类型，则全选即可。```下一页```。

![第四步](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/direct/207333c33a8247c6aea4da63e487bc98.png)

随便起个名字，点击```完成```，大功告成。

![第五步](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/direct/7e15765976bb487283b98a7f330010ca.png)

这时候可以在局域网（wifi、校园网、热点等）或公网（如有）下使用其他设备连接本设备的ip地址加端口号，看能否访问成功。

### 2. 不禁止Python穿过防火墙

若第```1.```步后仍无法访问，则需要在入站规则中查看是否有禁止 服务提供程序 穿过防火墙的规则。

以我写的[一个通过网页在其他设备上向电脑发送快捷键的脚本](https://github.com/LetMeFly666/PressByWeb)为例，这个脚本是用Python运行的，它开启的是```82```端口。我在第```1.```步已经开启了```82```端口的```TCP```入栈规则，还是无法在其他设备上访问。

于是我找了一下入栈规则，发现有一条禁止```Python```穿过防火墙的规则。

删掉这个规则（你也可以选择禁用该规则），手机就能访问电脑提供的网页了。

![找到禁止Python穿过防火墙的规则并禁用或删除](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/direct/41024e70e4f049549847b6e6fc53d0b3.png)

若规则列表中没有找到```Python```，你可以在```程序```这一列寻找是否有Python。若你的服务提供程序不是Python，则需要找到相应程序的对应规则。这些规则可能不是你主动添加的，而是“不小心”或其他程序添加的。总之，删掉就好。

## End

> 原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/01/31/Other-Windows-FireWall-Open1PortForWebserver-WhyFailed/)哦~
> [https://letmefly.blog.csdn.net/article/details/135981716](https://letmefly.blog.csdn.net/article/details/135981716)

