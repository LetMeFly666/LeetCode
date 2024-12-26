---
title: WebDAV(or SMB) - 本地编辑远程服务器中文件 - 简单使用(Windows为例)
date: 2024-12-25 15:39:55
tags: [其他, WebDAV]
---

# WebDAV(or SMB) - 本地编辑远程服务器中文件 - 简单使用(Windows为例)

## 前言

WebDAV（Web-based Distributed Authoring and Versioning）是一种基于 HTTP 协议的扩展协议，旨在允许用户在远程服务器上管理和编辑文件。

想要像本地一样访问远程服务器上的内容，可以直接使用WebDAV协议将远程内容映射为一个“盘符”（如果远程服务器提供了WebDAV服务）。

## 准备工作

在Windows中，记得打开`WebClient`服务。

`Win + R` -> `services.msc` -> `回车`，找到WebClient，`右键` -> `属性` -> `启动`。也可以将启动方式设置为`自动`以便开机自启该服务。

![启动WebClient服务](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/4383a87b9363439b837f8967677a8148.png)

## 添加方法

### 方法一、操作图形界面添加

`Win + E`打开资源管理器，在`此电脑`上右键，`映射网络驱动器`

![映射网络驱动器](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/44400923e5394ff794b71b97ca8fe55d.png)

文件夹选择服务器的WebDAV地址，勾选`登录时重新连接`，之后输入用户名和密码即可添加成功。

![输入WebDAV地址](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/d689665a07294e31843c23d9436e77cb.png)

### 方法二、使用命令行添加

`Win + R` -> `cmd` -> `回车`打开终端，输入以下命令

```powershell
net use Z: https://example.com /user:youruser yourpassword
```

就能将`https://example.com`这个WebDAV服务添加到`D`盘了。

## 使用效果

添加成功后，就能像访问本地文件一样访问服务器上的资源了。

![使用效果](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/bb6acdd961bf42ea96a984dd88426031.png)

成功将一个服务器映射为了一个盘。

## What's more

### 如何查看自己都添加了哪些服务？

在`终端`中使用`net use`命令即可。

### 我有支持SMB协议的服务，如何添加？

和`WebDAV`一样，将地址换成`\\ip`即可。

### 实现原理 缓存相关问题（未完全考证）

主机默认只从服务器上下载文件相关信息。

打开某文件时，主机下载服务器上相关文件到临时目录并打开；创建(上传)某文件时，主机先将本地文件移动到临时目录并上传。

临时目录中的文件会由Windows的缓存管理机制适时自动删除。

## End

<center><font size="6px" face="Ink Free">The Real End, Thanks!</font></center>

> 原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2024/12/25/Other-WebDAV-SampleUsage_Windows/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/144721292](https://letmefly.blog.csdn.net/article/details/144721292)