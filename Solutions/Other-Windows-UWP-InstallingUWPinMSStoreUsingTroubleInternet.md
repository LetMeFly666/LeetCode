---
title: Windows - UWP - 网络不好的情况下安装（微软商店）MicrosoftStore的应用
date: 2023-08-13 10:03:09
tags: [其他, Windows, UWP]
description: microsoft store无法安装、0x80070005
---

# Windows - UWP - 网络不好的情况下安装（微软商店）MicrosoftStore的应用

## 前言

UWP虽然几乎被微软抛弃了，但不得不否认UWP应用给用户带来的体验。沙箱的运行方式加上微软的审核，用户使用起来非常放心，并且完美契合Windows，资源占用非常小。

但是微软商店神奇的网络，使得安装过程十分看脸，经常出现下载失败的现象。

## How

### 一、在微软商店网页版找到想要下载的应用

微软商店地址：[apps.microsoft.com](https://apps.microsoft.com)

可以在左侧搜索，之后点击今日应用页面。例如[QQ音乐UWP](https://apps.microsoft.com/store/detail/qq%E9%9F%B3%E4%B9%90uwp/9WZDNCRFJ1Q1)

### 二、打开MS Generation Project下载“安装包”

MS Generation Project：[store.rg-adguard.net](https://store.rg-adguard.net/)

进入上述网站后，粘贴QQ音乐UWP的地址，点击“对号”搜索。

在出现的列表中，选择```.appxbundle```结尾或```.appx```结尾的文件，点击下载。

![find](https://img-blog.csdnimg.cn/31e4af1ff8264c8cb1bdf8f4971c4b9b.png)

如果点击后没反应，可以试试```右键 -> 复制连接地址```，之后```新建标签页 -> 输入地址```。

这样下载速度可能还是很慢，但是既然是浏览器下载，就可以使用IDM等特殊手段了。

也可以使用我下载好的版本（不保证时效性，失效不补）：[AliyunDrive](https://www.aliyundrive.com/s/eJaoesB1tUr)（阿里云盘禁止分享zip、appbundle格式的文件，单独修改后缀也不可以。因此我提取了QQ音乐UWP的图标，使用WinRAR制作了一个自解压文件，可以放心运行。运行后将会获得```903DB504.QQWP_4.2.3.0_neutral_~_a99ra4d2cbcxa.AppxBundle```。大概不会有人去下载吧QAQ）

### 三、安装

下载完成后，双击就可以安装了。

## More

### 文件

我下载的文件是```903DB504.QQWP_4.2.3.0_neutral_~_a99ra4d2cbcxa.AppxBundle```，默认安装位置```C:\Program Files\WindowsApps\903DB504.QQWP_4.2.3.0_x64__a99ra4d2cbcxa```，默认缓存位置是```C:\Users\LetMe\AppData\Local\Packages\903DB504.QQWP_a99ra4d2cbcxa```

### 我对QQ音乐UWP的评价

我在微软商店给了个5⭐好评hh

```
虽然与win32相比少了很多功能，也存在很多BUG，但是系统开销是真的小，界面也算美观，虽然成本可能很高，但还是很支持腾讯开发QQ音乐的UWP[Doge]。
```

## 参考

> 原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2023/08/13/Other-Windows-UWP-InstallingUWPinMSStoreUsingTroubleInternet/)哦~
> 同步发文于CSDN：[https://letmefly.blog.csdn.net/article/details/132257018](https://letmefly.blog.csdn.net/article/details/132257018)
