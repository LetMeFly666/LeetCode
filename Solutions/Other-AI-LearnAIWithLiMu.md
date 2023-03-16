---
title: 人工智能 - 跟李沐学AI
date: 2023-03-15 16:05:24
tags: [其他, AI, DL, 人工智能, 深度学习, Notes]
---

# 跟李沐学AI

B站链接：[https://space.bilibili.com/1567748478/channel/seriesdetail?sid=358497](https://space.bilibili.com/1567748478/channel/seriesdetail?sid=358497)

课程官网：[https://courses.d2l.ai/zh-v2/](https://courses.d2l.ai/zh-v2/)

## 环境配置

在一台新的Ubuntu机器上：

首先更新软件包：```sudo apt update```

安装gcc之类的东西：```sudo apt install build-essential```

安装Python：```sudo apt install python3.8```

安装Miniconda：

> 先进入miniconda的官方文档：```https://docs.conda.io/en/latest/miniconda.html```
> 找到```#linux-installers```
> 在里面选中python3.8，复制链接地址
> 在服务器中将其下载下来：```wget 刚刚复制的地址 ```（例如```https://repo.anaconda.com/miniconda/Miniconda3-py38_23.1.0-1-Linux-x86_64.sh```）
> 直接```bash 刚刚下载下来的.sh文件```（例如```bash Miniconda3-py38_23.1.0-1-Linux-x86_64.sh```）
> 再运行一下```bash```命令就进入conda环境了

安装所需要的Python包：```pip install jupyter d2l torch torchvision```（torchvision是pytorch的一个图形库）

下载[d2l官网](https://zh-v2.d2l.ai/)的[jupyter记事本](https://zh-v2.d2l.ai/d2l-zh.zip)：```wget https://zh-v2.d2l.ai/d2l-zh.zip```

安装解压用的zip：```sudo apt install zip```

解压刚刚的zip：```unzip d2l-zh.zip```

解压出来有三个文件夹（mxnet版本、pytorch版本、transformer版本）

# TODO: 等完成地差不多了发布至CSDN

> 原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2023/03/15/Other-AI-LearnAIWithLiMu/)哦~
> [https://leetcode.letmefly.xyz/2023/03/15/Other-AI-LearnAIWithLiMu/](https://leetcode.letmefly.xyz/2023/03/15/Other-AI-LearnAIWithLiMu/)
