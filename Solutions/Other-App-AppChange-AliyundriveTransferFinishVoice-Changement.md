---
title: App - 程序修改 - 修改阿里云盘电脑端传输完成时提示音（Windows系统）
date: 2023-08-04 08:31:21
tags: [其他, App, 趣, 整活]
---

# App - 程序修改 - 修改阿里云盘电脑端传输完成时提示音（Windows系统）

## 为什么修改

阿里云盘电脑端下载完成时提示音不明显，很难听到，并且**一点都不萌！**

于是想着看看能不能修改传输完成时的提示音，毕竟**老婆的声音谁不爱呢？**

## 探索过程

先找到```阿里云盘安装目录```（在快捷方式中 右键->打开文件所在位置 即可），以下记为```{AliyunDriveAppDir}```。

发现该目录下并无直接的音频文件，但是有两个文件夹：locales和resources。

打开resources文件夹，发现其中有文件夹叫resource，一路打开到底，发现有一条```transfer-finished.mp3```。

很明显，这就是传输完成时的提示音。将这个音频替换为你想要的老婆的声音，使用阿里云盘下载一个文件，完成时听到了老婆的：“xxxxx”

## 方法总结

进入```{AliyunDriveAppDir}/resource/common/audio/```文件夹，将其中的```transfer-finished.mp3```替换为你想要的声音，即可在传输完成时自动播放。（记得将老婆的声音命名为```transfer-finished.mp3```）

## Q&A

### 你的方法适用于哪些版本？

截至写稿日期（2023.8.4），阿里云盘Windows电脑端[最新版](https://www.aliyundrive.com/download)4.9.0可用。

### 为什么我的阿里云盘传输完成时没有提示音？

请查看提示音是否开启：设置->通知->传输完成消息提示音。

并且，经过不完全测试，提示音似乎只有在阿里云盘处于后台时才会发出。

> 原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/08/04/Other-App-AppChange-AliyundriveTransferFinishVoice-Changement/)哦~
> 同步发文于CSDN：[https://letmefly.blog.csdn.net/article/details/132096003](https://letmefly.blog.csdn.net/article/details/132096003)
