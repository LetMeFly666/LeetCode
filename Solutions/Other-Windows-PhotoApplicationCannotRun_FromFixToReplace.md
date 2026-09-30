---
title: Windows照片应用无法运行 - 从尝试修复到弃坑（ImageGlass使用）
date: 2026-09-30 10:28:30
tags: [其他, VsCode, Windows, BUG]
categories: [技术思考]
---

# Windows照片应用无法运行 - 从尝试修复到弃坑（ImageGlass使用）

## 前言

今天打开某古早文件，突然：

```
+------------------------------------------------------+
| F:\桌面\考试时间.png                              [X] |
+------------------------------------------------------+
|                                                      |
|   (X)   F:\桌面\考试时间.png                          |
|                                                      |
|         包无法进行更新、相关性或冲突验证。              |
|                                                      |
|                                                      |
|                                             [ 确定 ] |
+------------------------------------------------------+
```

还以为是文件损坏了。后面发现原来是Windows`照片`应用无法正常运行了。

## 尝试修复过程

控制变量，尝试打开其他图片，均出现上述错误提示；打开该目录下其他同时期文件，一切正常。

`Win + S`搜索`应用`，跳转到`设置`的`应用和功能Tab`，搜索`照片`，点击`...`，选择`高级选项`，点击`修复`，然并卵。点击`重置`，直接整个应用都不见了！

打开`Microsoft Store`，搜索`照片`，搜不到；搜索`Microsoft 照片`，搜到了。但是一看，好家伙，`1G`大小。并且介绍是“专为Win11 AI+PC打造”、“onedrive集成”等各种杂七杂八我不需要的功能。我只是想要一个照片查看器。果断放弃。

## 去GitHub找开源 （ImageGlass）

简单搜了一下似乎[imageglass](https://github.com/d2phap/imageglass)的评价还不错，[官网](https://imageglass.org/)[价格对比页面](https://imageglass.org/pricing)找到`Classic`并点击`Get Classic`，下滑找到`Pick Your Platform`，我选了`Windows`的`Windows x64 MSIX`。

一共40M+，下载完成后安装就好了。

安装完成后启动一下，设置语言、我选择的个人（没选专业）、设置添加到注册表（注册表添加后卸载时不会自动清除,如果有卸载的那一天再说吧），开始使用。（我这里出现了bug，进行了两次初始化设置，看图软件默认是ImageGlass了）

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/166889862)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/09/30/Other-Windows-PhotoApplicationCannotRun_FromFixToReplace/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
