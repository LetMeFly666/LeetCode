---
title: Windows - DWM - 桌面窗口管理器内存泄漏BUG（桌面窗口管理器内存占用过高）
date: 2023-08-25 21:44:59
tags: [其他, Windows]
categories: [技术思考]
---

# Windows - DWM - 桌面窗口管理器内存泄漏BUG（桌面窗口管理器内存占用过高）

## 前言

有时候笔记本使用者使用者就感觉不对劲，有种强烈的延时感。打开任务管理器一看，好家伙，```桌面窗口管理器```（Desktop Window Manager）能占用好几个G。右键结束运行，电脑黑屏一下就恢复了。

但有时候电脑长时间没动，回来的时候内存快干满了，巨卡。。。直到最后有一次电脑直接黑屏死机了，我忍无可忍，决定解决之，并记录了下来。

其实本来是想写一个后台脚本，每隔一定时间监控正在运行的进程的，若DWM占用内存过高则kill之，但最后想想这样毕竟不是根治。

[@NSJim](https://blog.csdn.net/NSJim/)的博文帮了我很多：[一](https://blog.csdn.net/NSJim/article/details/130536410)、[二](https://blog.csdn.net/NSJim/article/details/130562802)、[三](https://blog.csdn.net/NSJim/article/details/125861398)。

## 原因

原因可见Intel官网：[dwm.exe（桌面窗口管理程序）使用更新于 27.20.100.8587 的驱动程序产生内存泄漏](https://www.intel.cn/content/www/cn/zh/support/articles/000058381/graphics.html)，因此只要确保使用修复这个BUG的驱动即可。

## 方法

你也可以看完三个步骤后，按三一二的顺序进行。

### 一、卸载旧驱动

卸载所有Intel核显驱动，可以使用软件[Display Driver Uninstaller(DDU)](https://www.wagnardsoft.com/content/DDU-Guide-Tutorial)，软件很小巧很干净。

下载方式：访问[Release页](https://www.wagnardsoft.com/display-driver-uninstaller-ddu-)，选择一个版本（如```Display Driver Uninstaller (DDU) V18.0.6.6 Released.```），点击```Read More```，点击[Click here for DOWNLOAD & SUPPORT.](https://www.wagnardsoft.com/forums/viewtopic.php?t=4666)，点击[*** Download DDU "Portable / self-extracting" ***](https://www.wagnardsoft.com/DDU/download/DDU%20v18.0.6.6.exe)

运行自解压程序，解压到一个位置后，运行```Display Driver Uninstaller.exe```，右侧“设备种类/设备供应商”选择“显卡/Intel”，点击左侧“清除并重启”。重启后电脑分辨率可能会降低。

至于为什么卸载旧驱动而不是直接安装新驱动，一个是BUG版旧驱动似乎没什么用了，一个是防止“不小心”回滚到BUG版。

### 二、安装新驱动

在新[驱动安装页面](https://www.intel.com/content/www/us/en/download/19344/732078/intel-graphics-windows-dch-drivers.html)选择30开头的驱动，下载```igfx_win_xx.exe```，运行，同意许可，安装。

### 三、禁止Windows自动更新驱动

正当我以为万事大吉时，电脑右下角突然多出来了一个“Windows更新”的图标。点开一看，```Intel Graphxx 27.20.100.xxx```正等待重新启动。

好家伙，反向更新驱动是吧？？？

于是我又进行了第一、第二步的操作，并设置了禁止Windows自动更新驱动（不是禁止Windows自动更新）。

#### 一、修改系统设置

```Windows设置 -> 搜索“系统高级设置” -> 硬件 -> 设备安装设置(S) -> 否 -> 保存更改```。

仅仅这样Windows还是会自动更新驱动。

#### 二、修改策略组

```Win + R 并回车 -> gpedit.msc 并回车```

需要进行两个设置：

1. ```计算机配置 - 管理模板 - 系统 - Internet通信管理 - Internet通信设置 -> 双击 关闭Windows更新设备驱动程序搜索 -> 选中“已启用” -> 确定```
2. ```计算机配置 - 管理模板 - Windows组件 - Windows更新 -> 双击 Windows更新不包括驱动程序 -> 选中“已启用” -> 确定```

#### 三、修改注册表

保险起见，可以：

```Win + R 并回车 -> regedit 并回车 -> 计算机\HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\DriverSearching -> 将 SearchOrderConfig 的值修改为0```

## End

挺繁琐的，但BUG修复了还是比较开心的。对了，设置成功的话，还能够在设置中“Windows系统更新”页面，看到红色的```*某些设置由你的组织来管理```。出现这个就比较放心系统再自动更新驱动了。

啊咧，操作教程，竟然没图？

> 文章原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/08/25/Other-Windows-DWM-MemoreLeakBug-Fixment/)哦~
> 同步发文于CSDN：[https://letmefly.blog.csdn.net/article/details/132503580](https://letmefly.blog.csdn.net/article/details/132503580)
