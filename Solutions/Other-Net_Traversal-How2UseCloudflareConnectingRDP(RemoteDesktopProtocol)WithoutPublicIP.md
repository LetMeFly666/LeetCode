---
title: 内网穿透：如何借助Cloudflare连接没有公网的电脑的远程桌面(RDP)-含详细原理配置说明介绍
date: 2024-10-21 15:55:52
tags: [其他, 内网穿透, 远程桌面, RDP]
---

# 内网穿透：如何借助Cloudflare连接没有公网的电脑的远程桌面(RDP)-含详细原理配置说明介绍

## 前言

远程桌面协议(RDP, Remote Desktop Protocol)可用于远程桌面连接，Windows系统（家庭版除外）也是支持这种协议的，无需安装额外客户端即可实现类似向日葵、toDesk等的远程桌面访问与控制。

但是前提是被控制的电脑有公网ip或者可以被局域网访问。没有公网ip又不在同一个局域网中的电脑如何使用这个协议进行远程连接呢？那就试试大名鼎鼎的cloudflare的内网穿透`零信任tunnel`技术吧！

## 准备

+ 需要有两台电脑，一台配置好[远程桌面](https://support.microsoft.com/zh-cn/windows/%E5%A6%82%E4%BD%95%E4%BD%BF%E7%94%A8%E8%BF%9C%E7%A8%8B%E6%A1%8C%E9%9D%A2-5fe128d5-8fb1-7a23-3b8a-41e636865e8c)用于被[远程访问](https://blog.csdn.net/qq_44665283/article/details/122716174)，一台电脑用于连接这台电脑。
+ 需要注册[Cloudflare](https://dash.cloudflare.com/)账号并且绑定一个[域名](https://www.cnblogs.com/eslzzyl/p/17765702.html)。

## 方法

1. 进入Cloudflare零信任控制台（`控制台主页` -> `ZeroTrust` -> `Networks` -> `Tunnels`）

    ![进入Cloudflare零信任控制台，并点击Create Tunnel](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/35682e0aa2a34253b55e605aadfe9232.png)

2. 新建Tunnel（`Create Tunnel` -> `Select Cloudflared` -> `起个名字` -> `Save tunnel`）

   ![创建tunnel](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/8c4cf63fea154cbba20980cbeac5a04d.png)

3. 两台电脑都下载并安装[cloudflared客户端](https://github.com/cloudflare/cloudflared/releases/latest/download/cloudflared-windows-amd64.msi)，并且复制`命令行代码`

   ![安装cloudflared客户端，并记录密钥(命令)](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/f8739f8f25194d429d46cc72710eb69e.png)

4. 在被控制的电脑上运行刚才复制的命令（`Win + S` -> `cmd` -> `右键“命令提示符”` -> `以管理员身份运行` -> `在弹出的小黑框中输入刚才复制的命令并回车`）

   ![命令提示符](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/bdda499c3ac14011a92cc3f6d3b98ea4.png)

   配置成功后应该能在下方`Connectors`列表中看到一个“连接者”。

5. 配置域名（外网访问与内网映射规则）（`点击网页上的Next` -> `选择一个域名` -> `协议选择RDP` -> `URL输入localhost://3389`因为rdp默认端口是3389 -> `Save Tunnel`）

   ![Next](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/9b76b1b2466942a4b82c95fec61ba4b8.png)

   ![配置域名](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/b913ef86a84b46baa522ef386d21b2f1.png)

6. 在控制者电脑上同样打开“命令提示符”，输入命令`cloudflared.exe access rdp --hostname test.letmefly.xyz --url rdp://localhost:1234`，就可以远程连接另一台电脑了（`Win + R` -> `cmd` -> `回车` -> `替换这个命令并回车` -> `Win + R` -> `mstsc` -> `回车` -> `localhost:3089` -> `填写远程连接的用户名并回车` -> `输入密码并完成远程连接`）

## 原理解释

> 关于我为什么要写这篇文章，是因为网上很多现有文章之说操作步骤不讲原理。有的跟着配置下来在自己电脑上还会踩上不少坑。因此我想简单介绍下它的原理，以及为什么这么操作。

**整体原理**

被控制电脑没有公网IP也没有处于控制者电脑所在局域网中，控制者电脑想要连接它但是访问不到它。

但是Cloudflare有公网IP，因此被控制电脑要安装`cloudflared`客户端并输入命令，其实是被控制电脑与cloudflare服务器建立了一个持久性连接（隧道）。

控制者电脑访问配置的域名，流量到达cloudflare服务器，借助cloudflare服务器实现与被控制者的通信。

准确来说，不知道这样能否被称为是内网穿透（因为所有流量大概都需要经过cloudflare服务器转发一下，并没有控制者与被控制者两台电脑的直接通信），应该是属于内网穿透的吧。

**新建Tunnel是在干什么**

新建`Tunnel`就是新建一个cloudflare与被控制者之间的“隧道”，二者通过“隧道”保持持久化连接。

**被控制者电脑为何要安装cloudflared客户端并输入那一串命令**

安装客户端是因为要借助客户端来建立与cloudflare服务器之间的隧道。

那串命令是为了让cloudflare服务器知道这台电脑要连接哪个隧道（起识别作用的是命令最后的那串“乱码”）。

**配置域名（外网访问与内网映射规则）是在干什么，具体应该怎么配置**

配置了访问规则，cloudflare才知道流量到来时才能如何转发、通过哪个隧道以及什么规则转发给哪个机器。

第一行是控制者(访问者)相关的配置。`子域名（Subdomain）`是自己定义的，`域名（Domain）`是你购买/拥有的绑定在Cloudflare的域名，`路径（Path）`是访问哪个路径时转发规则生效。

第二行是被控制者(被访问者)相关的配置。`Type`是协议类型（RDP是微软远程桌面连接的协议），`URL`是流量要被转发到哪里（被访问者的RDP服务的地址）。

例如我上述配置中，`Subdomain`是`test`，`Domain`是`letmefly.xyz`，`Type`是`RDP`，`URL`是`localhost:3389`。因此我在控制者电脑上使用`RDP`协议访问`test.letmefly.xyz`时，流量会被转发到被控制者的`localhost:3389`上。

**访问者电脑上的配置是怎么回事**

访问者电脑上输入的那串命令相当于是把对于`localhost:1234`的`RDP`访问转发到`test.letmefly.xyz`上，因此`mstsc`后输入`localhost:1234`流量就可以被转发到`test.letmefly.xyz`然后被通过隧道转发到被控制机器的`localhost:3389`上，从而实现了远程桌面连接。

注意，命令中的`test.letmefly.xyz`需要修改成你所配置的域名，`1234`可以修改，但注意不要和其他端口冲突（比如控制者主机上也开启了RDP能被其他设备控制的话3389端口很可能被占用了）。

## 后记

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/10/21/Other-Net_Traversal-How2UseCloudflareConnectingRDP(RemoteDesktopProtocol)WithoutPublicIP/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/143114828](https://letmefly.blog.csdn.net/article/details/143114828)