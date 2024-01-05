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

注意虽然b和a不同，但修改b中的元素可能会导致a中元素的改变（可以理解为b是a的另一个视图）

```python
a = torch.arange(12)
b = a.reshape(3, 4)
print(id(a) == id(b))
b[:] = 2
print(a)
```

运行结果：

```
False
tensor([2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2])
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
print(x == y)
```

运行结果：

```
tensor([ 3.,  4.,  6., 10.])
tensor([-1.,  0.,  2.,  6.])
tensor([ 2.,  4.,  8., 16.])
tensor([0.5000, 1.0000, 2.0000, 4.0000])
tensor([ 1.,  4., 16., 64.])
tensor([2.7183e+00, 7.3891e+00, 5.4598e+01, 2.9810e+03])
tensor([False,  True, False, False])
```

**向量连接(concatenate)：torch.cat**

```python
X = torch.arange(12, dtype=torch.float32).reshape((3, 4))
Y = torch.tensor([[2.0, 1, 4, 3], [1, 2, 3, 4], [4, 3, 2, 1]])
torch.cat((X, Y), dim=0), torch.cat((X, Y), dim=1)
```

运行结果：

```
(tensor([[ 0.,  1.,  2.,  3.],
         [ 4.,  5.,  6.,  7.],
         [ 8.,  9., 10., 11.],
         [ 2.,  1.,  4.,  3.],
         [ 1.,  2.,  3.,  4.],
         [ 4.,  3.,  2.,  1.]]),
 tensor([[ 0.,  1.,  2.,  3.,  2.,  1.,  4.,  3.],
         [ 4.,  5.,  6.,  7.,  1.,  2.,  3.,  4.],
         [ 8.,  9., 10., 11.,  4.,  3.,  2.,  1.]]))
```

默认dim = 0

```python
x = torch.tensor([[1, 2], [3, 4]])
y = torch.tensor([[5, 6]])
print(torch.cat((x, y)))
```

运行结果：

```
tensor([[1, 2],
        [3, 4],
        [5, 6]])
```

只有拼接的那一维度的长度可以不同，其他维度必须相同（By Let，未完全验证）。例如下面代码会报错：

```python
x = torch.tensor([[1, 2], [3, 4]])
y = torch.tensor([[5, 6]])
torch.cat((x, y), dim=1)
```

运行结果：

```
---------------------------------------------------------------------------
RuntimeError                              Traceback (most recent call last)
Cell In[15], line 3
      1 x = torch.tensor([[1, 2], [3, 4]])
      2 y = torch.tensor([[5, 6]])
----> 3 torch.cat((x, y), dim=1)
```

**求和：x.sum()**

产生一个只有一个元素的张量：

```python
print(x)
print(x.sum())
```

运行结果：

```
tensor([[1, 2],
        [3, 4]])
tensor(10)
```

**广播机制：形状不同的向量进行运算**

```python
a = torch.arange(3).reshape((3, 1))
b = torch.arange(2).reshape((1, 2))
print(a)
print(b)
print(a + b)
print(a - b)
print(a * b)
print(a / b)
print(a == b)
```

相当于是把```a```复制成了```3 x 2```，把```b```也复制成了```3 x 2```。

运行结果：

```
tensor([[0],
        [1],
        [2]])
tensor([[0, 1]])
tensor([[0, 1],
        [1, 2],
        [2, 3]])
tensor([[ 0, -1],
        [ 1,  0],
        [ 2,  1]])
tensor([[0, 0],
        [0, 1],
        [0, 2]])
tensor([[nan, 0.],
        [inf, 1.],
        [inf, 2.]])
tensor([[ True, False],
        [False,  True],
        [False, False]])
```

同理

**取元素/改元素：[第一维列表操作, 第二维列表操作, 第三维]**

```python
x = torch.arange(12).reshape(3, 4)
print(x)
print(x[0:2, 1:3])
x[:, -1] = 0
print(x)
x[0] = -1
print(x)
print(x[1, 2] == x[1][2])
```

运行结果：

```
tensor([[ 0,  1,  2,  3],
        [ 4,  5,  6,  7],
        [ 8,  9, 10, 11]])
tensor([[1, 2],
        [5, 6]])
tensor([[ 0,  1,  2,  0],
        [ 4,  5,  6,  0],
        [ 8,  9, 10,  0]])
tensor([[-1, -1, -1, -1],
        [ 4,  5,  6,  0],
        [ 8,  9, 10,  0]])
tensor(True)
```

**一些操作可能导致为结果重新分配内存：**

```python
before = id(Y)
print(before)
Y = X + Y
after = id(Y)
print(after)
print(before == after)
```

运行结果：

```
139769251739696
139769252745984
False
```

那是当然的，X + Y肯定要新赋值给一个元素，不能把X或Y的值给修改掉。

原地执行操作：

```python
before = id(Y)
Y += X
after = id(Y)
print(before == after)
```

运行结果：

```
True
```

原地执行：

```python
Z = torch.zeros_like(Y)
before = id(Z)
Z[:] = X + Y
after = id(Z)
print(before == after)
```

运行结果：

```
True
```


**转为Numpy张量**

```python
A = x.numpy()
print(type(A), type(x))
```

运行结果：

```
<class 'numpy.ndarray'> <class 'torch.Tensor'>
```

**将大小为1的张量转为Python的标量：**

```python
x = torch.tensor([1])
print(x, x.item(), float(x), int(x))
y = torch.tensor([1.])
print(y, y.item(), float(y), int(y))
```

运行结果：

```
tensor([1]) 1 1.0 1
tensor([1.]) 1.0 1.0 1
```

### 数据预处理

新建一个数据集

```python
dataFile = "data.csv"
with open(dataFile, 'w') as f:
    f.write('NumRooms,Alley,Price\n')
    f.write('NA,Pave,127500\n')
    f.write('2,NA,106000\n')
    f.write('4,NA,178100\n')
    f.write('NA,NA,140000\n')
```

读取到pandas中

```python
import pandas as pd  # pip install pandas
data = pd.read_csv(dataFile)
print(data)
data  # 在jupyter中直接调用data输出效果会更好
```

运行结果：

```
   NumRooms Alley   Price
0       NaN  Pave  127500
1       2.0   NaN  106000
2       4.0   NaN  178100
3       NaN   NaN  140000
```

**获取输入和输出**

```python
# pandas的数据需要.iloc之后才能向torch那样取值
inputs, outputs = data.iloc[:, 0:2], data.iloc[:, 2]
```

**处理缺失值**

使用平均值填补NaN：

```python
inputs = inputs.fillna(inputs.mean())
print(inputs)
```

运行结果：

```
   NumRooms Alley
0       3.0  Pave
1       2.0   NaN
2       4.0   NaN
3       3.0   NaN
/tmp/ipykernel_13420/2420151946.py:1: FutureWarning: The default value of numeric_only in DataFrame.mean is deprecated. In a future version, it will default to False. In addition, specifying 'numeric_only=None' is deprecated. Select only valid columns or specify the value of numeric_only to silence this warning.
  inputs = inputs.fillna(inputs.mean())
```

警告的意思是说在未来的版本中，numeric_only将不设置默认值。因此手动添加```numeric_only=True```以消除警告：

```python
inputs = inputs.fillna(inputs.mean(numeric_only=True))
```

**将pandas中的Nan视为一个类别**

```python
inputs = pd.get_dummies(inputs, dummy_na=True)
print(inputs)
```

运行结果：

```
   NumRooms  Alley_Pave  Alley_nan
0       3.0           1          0
1       2.0           0          1
2       4.0           0          1
3       3.0           0          1
```

**将数据转为torch的张量**

```python
print(inputs.values)
import torch
X, y = torch.tensor(inputs.values), torch.tensor(outputs.values)
print(X)
print(y)
```

运行结果：

```
[[3. 1. 0.]
 [2. 0. 1.]
 [4. 0. 1.]
 [3. 0. 1.]]
tensor([[3., 1., 0.],
        [2., 0., 1.],
        [4., 0., 1.],
        [3., 0., 1.]], dtype=torch.float64)
tensor([127500, 106000, 178100, 140000])
```

注意这里X的dtype是64位浮点数。但其实64位运行较慢，实际使用时经常使用32位浮点数。

```python
X = X.to(dtype=torch.float32)
print(X)
print(X.dtype)
```

运行结果：

```
X = X.to(dtype=torch.float32)
print(X)
print(X.dtype)
```

## 线性代数基础

**矩阵转置x.T：**

```python
x = torch.arange(12).reshape(3, 4)
print(x)
print(x.T)
```

运行结果：

```
tensor([[ 0,  1,  2,  3],
        [ 4,  5,  6,  7],
        [ 8,  9, 10, 11]])
tensor([[ 0,  4,  8],
        [ 1,  5,  9],
        [ 2,  6, 10],
        [ 3,  7, 11]])
```

## 自动求导

**自动求导：requires_grad**

```python
x = torch.arange(4.)
x.requires_grad_(True)  # 等价于 x = torch.arange(4., requires_grad=True)
print(x)
y = 2 * torch.dot(x, x)  # y = 2x^2
print(y)
y.backward()  # 反向求导
x.grad
print(x.grad == 4 * x)  # y' = 4x
```

运行结果：

```
tensor([0., 1., 2., 3.], requires_grad=True)
tensor(28., grad_fn=<MulBackward0>)
tensor([True, True, True, True])
```

**清除梯度：x.grad.zero_**

默认情况torch会把梯度累积起来，因此计算下一个梯度是时候记得清除掉之前的梯度

```python
x = torch.arange(4., requires_grad=True)
y = 2 * torch.dot(x, x)
y.backward()
print(x.grad)
y = torch.dot(x, x)
y.backward()
print(x.grad)  # 两个grad的累加
x.grad.zero_()
y = torch.dot(x, x)
y.backward()
print(x.grad)  # y=x^2的真正的grad
```

运行结果：

```
tensor([ 0.,  4.,  8., 12.])
tensor([ 0.,  6., 12., 18.])
tensor([0., 2., 4., 6.])
```

**将某些计算结果移动到记录的计算图之外：y.detach()**

```python
x = torch.arange(4., requires_grad=True)
y = x * x
print(y)
u = y.detach()  # u视为一个对x的常数
print(u)
z = u * x
z.sum().backward()
print(x.grad == u)
```

运行结果：

```
tensor([0., 1., 4., 9.], grad_fn=<MulBackward0>)
tensor([0., 1., 4., 9.])
tensor([True, True, True, True])
```

但注意y.detach()不改变y，y仍是关于x的函数

```python
x.grad.zero_()
y.sum().backward()
print(x.grad == 2 * x)
```

运行结果：

```
tensor([True, True, True, True])
```

## 线性回归

**线性回归手动实现**

```python
import random
import torch
from d2l import torch as d2l

def synthetic_data(w, b, num_examples):
    """生成y = Xw + b + 噪声"""
    X = torch.normal(0, 1, (num_examples, len(w)))  # 生成均值是0，标准差是1的正态分布。每个值的shape为(num_examples, len(w))
    y = torch.matmul(X, w) + b
    y += torch.normal(0, 0.01, y.shape)
    return X, y.reshape((-1, 1))

true_w = torch.tensor([2, -3.4])
true_b = 4.2
features, labels = synthetic_data(true_w, true_b, 1000)  # features是1000x2的矩阵，labels是1000x1的矩阵

def data_iter(batch_size, features, labels):
    num_examples = len(features)
    indices = list(range(num_examples))
    random.shuffle(indices)
    for i in range(0, num_examples, batch_size):
        batch_indices = torch.tensor(indices[i:min(i + batch_size, num_examples)])  # min(i + batch_size, num_examples)：防止num_example不是batch_size整数倍
        yield features[batch_indices], labels[batch_indices]

batch_size = 10
w = torch.normal(0, 0.01, size=(2, 1), requires_grad=True)
b = torch.zeros(1, requires_grad=True)

def linreg(X, w, b):
    """线性回归模型"""
    # print(X.shape, w.shape)
    # print(torch.matmul(X, w).shape)
    return torch.matmul(X, w) + b

def squared_loss(y_hat, y):
    """均方损失"""
    # print(y_hat.shape)
    # print(y.shape)
    # print(((y_hat - y.reshape(y_hat.shape)) ** 2 / 2).shape)
    return (y_hat - y.reshape(y_hat.shape)) ** 2 / 2

def sgd(params, lr, batch_size):
    """小批量梯度下降算法"""
    with torch.no_grad():
        for param in params:
            param -= lr * param.grad / batch_size
            param.grad.zero_()
lr = 0.03
num_epochs = 3
net = linreg
loss = squared_loss

for epoch in range(num_epochs):
    for X, y in data_iter(batch_size, features, labels):
        l = loss(net(X, w, b), y)
        l.sum().backward()
        sgd([w, b], lr, batch_size)
    with torch.no_grad():
        train_l = loss(net(features, w, b), labels)
        print(f'epoch {epoch + 1}, loss {float(train_l.mean()):f}')

print(f'w的估计误差: {true_w - w.reshape(true_w.shape)}')
print(f'b的估计误差: {true_b - b}')
```

运行结果：

```
epoch 1, loss 0.038151
epoch 2, loss 0.000152
epoch 3, loss 0.000048
w的估计误差: tensor([-0.0003, -0.0008], grad_fn=<SubBackward0>)
b的估计误差: tensor([0.0008], grad_fn=<RsubBackward1>)
```

**借助Pytorch实现**

```python
import numpy as np
import torch
from torch.utils import data

def synthetic_data(w, b, num_examples):
    """生成y = Xw + b + 噪声"""
    X = torch.normal(0, 1, (num_examples, len(w)))  # 生成均值是0，标准差是1的正态分布。每个值的shape为(num_examples, len(w))
    y = torch.matmul(X, w) + b
    y += torch.normal(0, 0.01, y.shape)
    return X, y.reshape((-1, 1))

true_w = torch.tensor([2, -3.4])
true_b = 4.2
features, labels = synthetic_data(true_w, true_b, 1000)

def load_array(data_arrays, batch_size, is_train=True):
    """构造一个PyTorch数据迭代器"""
    dataset = data.TensorDataset(*data_arrays)
    return data.DataLoader(dataset, batch_size, shuffle=is_train)

batch_size = 10
data_iter = load_array((features, labels), batch_size)

from torch import nn
net = nn.Sequential(nn.Linear(2, 1))
net[0].weight.data.normal_(0, 0.01)
net[0].bias.data.fill_(0)
loss = nn.MSELoss()
trainer = torch.optim.SGD(net.parameters(), lr=0.03)

num_epochs = 3
for epoch in range(num_epochs):
    for X, y in data_iter:
        l = loss(net(X), y)
        trainer.zero_grad()
        l.backward()
        trainer.step()
    l = loss(net(features), labels)
    print(f'epoch {epoch + 1}, loss {l:f}')


w = net[0].weight.data
print('w的估计误差：', true_w - w.reshape(true_w.shape))
b = net[0].bias.data
print('b的估计误差：', true_b - b)
```

运行结果：

```
epoch 1, loss 0.000258
epoch 2, loss 0.000101
epoch 3, loss 0.000100
w的估计误差： tensor([-0.0003,  0.0005])
b的估计误差： tensor([0.0012])
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

> 原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/03/15/Other-AI-LearnAIWithLiMu/)哦~
> [https://blog.tisfy.eu.org/2023/03/15/Other-AI-LearnAIWithLiMu/](https://blog.tisfy.eu.org/2023/03/15/Other-AI-LearnAIWithLiMu/)
