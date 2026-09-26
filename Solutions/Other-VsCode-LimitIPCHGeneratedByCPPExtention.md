---
title: VsCode缓存清理 - 限制C++拓展的缓存文件ipch空间占用
date: 2026-09-09 10:51:42
tags: [其他, VsCode, Windows, 磁盘清理]
categories: [技术思考]
---

# VsCode缓存清理 - 限制C++拓展的缓存文件ipch空间占用

前文《[VsCode缓存清理 - 轻量级的VsCode为何越用越大？为什么吃了我C盘10G？如何无痛清理VsCode缓存？手把手教你为C盘瘦身](https://blog.letmefly.xyz/2022/07/30/Other-VsCode-WhyLightweightVsCodeCanEatMyCDrive10G/)》通过Windows上的bat脚本实现了VsCode缓存的清理，可以释放大量空间。但是使用一段时间后空间占用还会逐渐增大。如果你是C++用户，那么也许你需要关注一下本篇文章。

## 缓存文件介绍

`ipch` 是 Microsoft C/C++ 扩展用于 IntelliSense 的缓存目录，主要用于缓存预编译头（Precompiled Header）等 IntelliSense 数据。

默认情况下，Windows 存放在 `%LocalAppData%\Microsoft\vscode-cpptools`，即`C:\Users\<用户名>\AppData\Local\Microsoft\vscode-cpptools`。

其中包含：

1. 数个数字和字母组成的哈希文件夹，每个几十M，想删就删（特别是不只有一个这样的文件夹的时候），下次还会自动生成。

    这个文件无法通过配置设置存放位置、大小，但好在空间占用不算大。
2. ipch文件夹。

    里面有很多数字和字母组成的哈希文件夹，哈希为cpp源文件的路径映射，每个cpp文件对应一个哈希文件夹。
    
    ipch文件夹默认总大小为5G。对于某些C盘吃紧的老设备还是有点挑战的。

## 缓存配置

可以在`settings.json`（打开方式可以为`Ctrl + Shift + P -> Preferences: Open User settings (JSON)`）中新增如下配置：

```json
"C_Cpp.intelliSenseCachePath": "F:\\FromC\\VsCode\\ipch",
"C_Cpp.intelliSenseCacheSize": 4096,
"settingsSync.ignoredSettings": [
    "-C_Cpp.intelliSenseCachePath"
],
```

第一个`C_CPP.intelliSenseCachePath`配置为`ipch`缓存文件存放路径，第二个`C_Cpp.intelliSenseCacheSize`配置为`ipch`缓存文件最大占用空间（单位为MB）。

第三个`settingsSync.ignoredSettings`是配置哪些配置不跨设备同步，由于缓存路径位置在不同电脑上可能不同，所以这里我设置ipch缓存位置不随设备同步，这样在其他设备登录VsCode账号，会同步其他配置而不同步这个，就可以实现每个设备配置不同的ipch缓存位置了。

当配置路径不存在时会存放到默认位置。

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/164727169)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/09/09/Other-VsCode-LimitIPCHGeneratedByCPPExtention/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
