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

本课程主要使用Pytorch版本。此外，本课程还将使用幻灯片版本的“记事本”：```git clone https://github.com/d2l-ai/d2l-zh-pytorch-slides```  并进入：```cd .\d2l-zh-pytorch-slides\```

打开jupyter：```jupyter notebook```。这样将会在机器上开辟一个8888端口。

如果是在服务器上进行的上述操作，也可以将远端的端口映射到本地```ssh -L8888:localhost:8888 root@www.letmefly.xyz```

可以安装一个插件，```pip install rise```来以幻灯片格式显示。

## Pytorch基础

```python
import torch
```

### 张量（数组）的创建与基本操作

**从0到11的数组：**

```python
x = torch.arange(12)
print(x)
```

运行结果：

```
tensor([ 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11])
```

**使用列表初始化数组：**

```python
torch.tensor([[1, 2], [3, 1]])
```

运行结果：

```
tensor([[1, 2],
        [3, 1]])
```

**数组形状更改reshape：**

注意x自身并不会发生改变，这个函数只是返回一个改变后的副本

```python
x2 = x.reshape(3, 4)
print(x2)
```

运行结果：

```
tensor([[ 0,  1,  2,  3],
        [ 4,  5,  6,  7],
        [ 8,  9, 10, 11]])
```

**获取数组形状shape：**

注意```.shape```是一个“成员”但不是一个“方法”

```python
print(x2.shape)
```

运行结果：

```
torch.Size([3, 4])
```

**获取数组中元素总个数：**

```python
print(x2.numel())
```

运行结果：

```
12
```

**生成全是1的数组：**

```python
x = torch.ones(2, 3)
print(x)
```

运行结果：

```
tensor([[1., 1., 1.],
        [1., 1., 1.]])
```

指定数据类型：

```python
x = torch.ones(2, 3, dtype=int)
print(x)
```

运行结果：

```
tensor([[1, 1, 1],
        [1, 1, 1]])
```

**张量间的+-乘除等运算：**

```python
x = torch.tensor([1., 2, 4, 8])
y = torch.tensor([2, 2, 2, 2])
print(x + y)
print(x - y)
print(x * y)
print(x / y)
print(x ** y)
print(torch.exp(x))  # e ^ 1, e ^ 2, e ^ 3, e ^ 4
```

运行结果：

```
tensor([ 3.,  4.,  6., 10.])
tensor([-1.,  0.,  2.,  6.])
tensor([ 2.,  4.,  8., 16.])
tensor([0.5000, 1.0000, 2.0000, 4.0000])
tensor([ 1.,  4., 16., 64.])
tensor([2.7183e+00, 7.3891e+00, 5.4598e+01, 2.9810e+03])
```

**：**

```python

```

运行结果：

```

```

**：**

```python

```

运行结果：

```

```

**：**

```python

```

运行结果：

```

```

# TODO: 等完成地差不多了发布至CSDN

> 原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2023/03/15/Other-AI-LearnAIWithLiMu/)哦~
> [https://leetcode.letmefly.xyz/2023/03/15/Other-AI-LearnAIWithLiMu/](https://leetcode.letmefly.xyz/2023/03/15/Other-AI-LearnAIWithLiMu/)
