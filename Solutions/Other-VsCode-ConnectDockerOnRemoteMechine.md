---
title: VsCode容器开发 - VsCode连接远程服务器上的docker
date: 2024-01-22 10:45:09
tags: [VsCode, 简单, Docker]
---

# VsCode容器开发 - VsCode连接远程服务器上的docker

## 前言

之前在服务器上的[Docker](https://blog.tisfy.eu.org/2023/10/07/Other-Docker-Note/)内开发，文件编辑起来就很不爽。不如**使用VsCode直接打开远程服务器上的Docker**，这样就能在VsCode里直接无缝编辑Docker里的文件了。

但是[百度](https://web.archive.org/web/20240122030455/https://www.baidu.com/s?wd=VsCode%E8%BF%9E%E6%8E%A5%E8%BF%9C%E7%A8%8B%E6%9C%8D%E5%8A%A1%E5%99%A8%E4%B8%8A%E7%9A%84docker)和[必应](https://web.archive.org/web/20240122030037/https://www.bing.com/search?q=VsCode%E8%BF%9E%E6%8E%A5%E8%BF%9C%E7%A8%8B%E6%9C%8D%E5%8A%A1%E5%99%A8%E4%B8%8A%E7%9A%84docker&rdr=1&rdrig=7596A6693EFF4E13AF5DBB24A2105E29)得到的中文结果都很奇葩，都是什么“给docker添加端口映射”、“给服务器开放被映射的端口”、“远程连接到这个端口”就连接到了Docker里。

emm，远程连接一个docker还需要服务器上专门开个端口？还得给docker添加一个**额外**的端口映射？

要么搜索结果就是“使用Docker拓展”，但Docker拓展其实并没有这功能。。。

为什么同学VsCode的“远程资源管理器”里除了“远程(隧道/SSH)”外还有“开发容器”的选项，而我即使安装了Docker拓展也没有这个选项呢？

## How

安装插件[```Dev Containers```](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers)。

使用VsCode[```Remote - SSH```](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-ssh)插件连接到远程服务器（具体方法在插件页都有介绍）

点击VsCode左侧的```远程资源管理器```图标，选择```开发容器```，选中你像连接的容器就能直接连接进去开发了。

## End

> 原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2024/01/22/Other-VsCode-ConnectDockerOnRemoteMechine/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135743708](https://letmefly.blog.csdn.net/article/details/135743708)

<center><font size="6px" face="Ink Free">The End, thanks!</font></center>
