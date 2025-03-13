---
title: C语言：使用 御坂美琴(misakamikoto)形状的C代码 播放OnlyMyRailgun
date: 2023-08-02 21:44:08
tags: [C, 控制台, 输出控制, 音乐播放, 趣, 整活]
categories: [技术思考]
---

# C语言：使用 御坂美琴(misakamikoto)形状的C代码 播放OnlyMyRailgun

+ 项目地址：[Github@3150601355/code_in_paojie](https://github.com/3150601355/code_in_paojie)
+ B站视频：[BiliBili@偶尔有点小迷糊/『整活』当你把C语言代码写成炮姐的样子](https://www.bilibili.com/video/BV1N54y1o7m9/)

## 使用方法

1. VS→创建新项目→C++空项目→解决方案资源管理器→源文件（右键）→添加→现有项→（选中railgun.c）添加
2. 调试→xx调试属性→C/C++→命令行→其他选项→添加```/D_CRT_SECURE_NO_WARNINGS```→确定
3. 本地Windows调试器

之后就能弹出一个控制台窗口，播放歌曲《Only My Railgun》背景音乐的前一小段，并在播放完一句后显示歌词。

如果将歌词缩小（VS似乎最小缩小到20%），能看出来代码的形状是炮姐。

## 代码及编译好的可执行文件

+ Gist代码：[https://gist.github.com/LetMeFly666/e69a49728c3f985bbb961df787a57746](https://gist.github.com/LetMeFly666/e69a49728c3f985bbb961df787a57746)
+ 可执行exe（需要VS环境）：[https://github.com/LetMeFly666/LeetCode/releases/download/v2.4.1/misaka.exe](https://github.com/LetMeFly666/LeetCode/releases/download/v2.4.1/misaka.exe)

> 原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/08/02/Other-C-PlayOnlyMyRailgunByCodeShapedAsMisakamikoto/)哦~
> Tisfy：[https://blog.letmefly.xyz/2023/08/02/Other-C-PlayOnlyMyRailgunByCodeShapedAsMisakamikoto/](https://blog.letmefly.xyz/2023/08/02/Other-C-PlayOnlyMyRailgunByCodeShapedAsMisakamikoto/)
