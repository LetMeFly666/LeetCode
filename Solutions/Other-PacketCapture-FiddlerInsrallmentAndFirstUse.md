---
title: 抓包 - 经典抓包工具Fiddler的安装与初使用
date: 2023-02-04 21:11:20
tags: [其他, 中等, 抓包, Fiddler]
---

# 抓包之Fiddler的安装与初使用

## 下载

免费版Fiddler（老版本Fiddler，体积小但功能已经很全了）

下载页面：[https://www.telerik.com/download/fiddler](https://www.telerik.com/download/fiddler)

填写邮箱、用途与国家后点击“Download For Windows”即可跳转到真正的下载链接（我的下载链接是：[https://telerik-fiddler.s3.amazonaws.com/fiddler/FiddlerSetup.exe](https://telerik-fiddler.s3.amazonaws.com/fiddler/FiddlerSetup.exe)）

下载速度约20kB/s，但安装包体积很小（6.52 MB），大约几分钟可以下载完成

## 安装

接着双击安装（需要管理员权限，也可以在虚拟机上安装后将文件拷贝至主机）

## 初始配置

初始默认不能抓取HTTPS包，需要点击“Tools->Options->HTTPS”，勾选上“Capture HTTPS CONNECTs”的复选框

这时候可能会弹出“是否安装证书”等字样，期间可能还会请求一次管理员权限，同意安装即可。

## 使用

首次配置成功后**重启**，进行一些HTTP和HTTPS请求即可看到左侧抓包成功。

## 卸载证书

若想要卸载掉Fiddler安装的用来抓取HTTPS网络包的证书，可以打开“windows证书管理器”

ㅤ```Win + R```，```certmgr.msc```，在左侧的各个文件夹（各类证书）内能找到很多颁发者为“DO_NOT_TRUST_FiddlerRoot”的证书，这些一般都是由Fiddler安装所至。(可以点击证书列表的“颁发者”以颁发者名称为依据对证书进行排序)

**当然，使用Fiddler自带的卸载工具也可以**

## What's more

今天发现Fiddler在抓包的过程中，python的requests库是会报错的。。。

```
ValueError: check_hostname requires server_hostname
```

想要python模拟发包时记得关下抓包（```File -> Capture Traffic(F12)```）

> 原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/02/04/Other-PacketCapture-FiddlerInsrallmentAndFirstUse/)哦~
> [https://blog.tisfy.eu.org/2023/02/04/Other-PacketCapture-FiddlerInsrallmentAndFirstUse/](https://blog.tisfy.eu.org/2023/02/04/Other-PacketCapture-FiddlerInsrallmentAndFirstUse/)
