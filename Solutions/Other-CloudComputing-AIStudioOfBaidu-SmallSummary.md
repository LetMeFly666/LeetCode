---
title: 云计算 - 百度AIStudio使用小结
date: 2023-08-28 11:38:16
tags: [其他, 云计算, AI Studio, PaddlePaddle]
description: Cloud Computing, 飞桨
---

# 云计算 - 百度AIStudio使用小结

## 前言

本文以[ffmpeg处理视频](https://aistudio.baidu.com/projectdetail/6678917)为例，小结一下[AI Studio](https://aistudio.baidu.com/index)的使用体验及一些避坑技巧。

## 算力获得

免费的算力获得方式为：每日登录后运行一个项目（只需要点击运行，不需要真正运行）即可获得8小时算力卡。

项目哪里来？可以随便Fork一个项目例如：[Project 5900035](https://aistudio.baidu.com/projectdetail/5900035)

![fork](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/ce6444f7ea1344b0b2cfab4b7a286281.jpeg)

然后点“环境启动”：

![环境启动](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/f119623911ff41f7ac33061ca20059de.png)

只需要弹出这个界面就说明今日获得8h算力了：

![算力已获得](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/18a4335df36344a2bd2f414a210dbc1e.png)

## 项目创建

### 项目分类

项目创建分为两种，一种是```脚本类```，一种是```NoteBook```类。

脚本类的项目是你提前编写好脚本，提交任务，任务执行完成后你可以下载输出结果；NoteBook类型的项目就像本地的Jupyter一样，可以交互。

脚本类项目在编辑时是不消耗算力的，而Notebook类项目只有在启动后才能编辑，只要启动了就会消耗算力时长。

### 创建运行

进入[个人中心](https://aistudio.baidu.com/usercenter)，点击```项目 -> 创建和Fork的项目 -> 创建项目```:

![项目创建](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/963cc090de414718b05c7634ff717aa6.png)

之后选择什么类型的项目、什么配置按照需求即可，如果不知道如何选择，那就随便选吧（都能运行）。

本文以```脚本类```项目为例：

![创建项目具体步骤](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/98d17177e23043b8bad91be51233d244.png)

查看详情：

![查看详情](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/a3d196463f5147acbad28a5adb2896fa.png)

编辑项目

![编辑项目](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/2243a0c6e1f14f4fb354f73cc1ba9dfd.png)

忽略警告

![确定](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/ccdfeece687a47e7b18a956582c9d8ab.png)

编辑脚本并提交运行就好了

![编辑脚本提交运行](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/b93c5f48d3c14381b9b2a5c835a4b261.png)

项目上传文件收到限制，不能上传大文件。因此若有处理大文件的需求，可以通过挂载数据集的方式来实现。

## 数据集创建

### 创建数据集

在[个人中心](https://aistudio.baidu.com/usercenter)，点击```创建的数据集 -> 创建数据集```即可。

![数据集创建](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/ebd3b9a32a6144cbaa54dffec8b697c8.png)

文件总大小不得超过50G，文件数量不得超过10个。因此多文件可以打包成一个压缩包再上传。

### 挂载数据集

回到[上上一步](创建运行)所创建的（脚本类）[项目](https://aistudio.baidu.com/clusterprojectdetail/6678917)，点击```修改```

![修改](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/f6935327fc6040ec97da3425bccd3590.png)

添加“个人数据集”，最后保存即可：

![具体步骤](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/97bc958920f04edc94e96d8c4fa74e94.png)

数据集如何使用呢？```脚本类```的项目数据集将被挂载到```/root/paddlejob/workspace/train_data/datasets/```目录下。

通过点击```数据集```可以查看所挂载数据集的具体路径。

![数据集具体路径](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/1b47b922912b4443bef78a31d2d56bcf.png)

上图中的```Fonts.zip```的绝对路径为```/root/paddlejob/workspace/train_data/datasets/data236492/Fonts.zip```

所有输出到```/root/paddlejob/workspace/output/```下的文件都将被作为```输出文件```，在任务完成后，点击```下载输出```即可下载该目录下所有文件的压缩包：

![下载输出](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/bd87e3a864bf43c7bc772103305a5f3b.png)

## 避坑技巧

1. 脚本类型的项目，提交任务时不会自动获得算力卡，需要点击一个Notebook类型的项目[运行一下](#算力获得)
2. 脚本类项目中，脚本执行完成后可能不会立即退出，大约15分钟后才会退出
3. 输出日志中可能会有重复（一行显示好几遍）
4. 4张V100（第二个选项）的算力大约是1张V100（第一个选项）的4倍（有时不只4倍，甚至能达到7.9倍），算力时长消耗4张是1张的8倍（但快确实爽）

> 原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/08/13/Other-CloudComputing-AIStudioOfBaidu-SmallSummary/)哦~
> 同步发文于CSDN：[https://letmefly.blog.csdn.net/article/details/132535648](https://letmefly.blog.csdn.net/article/details/132535648)
