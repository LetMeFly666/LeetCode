---
title: 人工智能 - 联邦学习(安全性) - 自用(ProjectDoing)
date: 2024-01-06 12:32:45
tags: [其他, AI, DL, 人工智能, 深度学习, 联邦学习]
categories: [自用]
---

# FL

## 一点名词解释

后门攻击成功的指标：

+ 干净数据准确率（Clean Data Accuracy, CDA）：不带trigger的干净样本被成功预测的概率
+ 攻击成功率（Attack Success Rate, ASR）：带trigger的样本被预测为攻击者指定类的概率

## 2024.1.4(15:00)-2024.1.6(14:30)

**任务**

Learn FL，找数据集

**数据集**

其中[LEAF](https://leaf.cmu.edu/)提供了几个联邦学习的基准数据集。

准备选择下面列表中的前3个。

+ MNIST: 手写数字识别（[官网(访问需要密码)](https://yann.lecun.com/exdb/mnist/)、[官网的Web Archive](https://web.archive.org/web/20231229081350/http://yann.lecun.com/exdb/mnist/)、[Kaggle数据集](https://www.kaggle.com/datasets/hojjatk/mnist-dataset)）
+ CIFAR-10：airplane automobile bird cat deer dog frog horse ship truck（[官网](https://www.cs.toronto.edu/~kriz/cifar.html)、[数据集](https://www.cs.toronto.edu/~kriz/cifar-10-python.tar.gz)）
+ FEMINIST: 识别英文字母和数字（[官方数据预处理与划分代码](https://github.com/TalwalkarLab/leaf)，[下载地址1 by_class](https://s3.amazonaws.com/nist-srd/SD19/by_class.zip)、[下载地址2 by_write](https://s3.amazonaws.com/nist-srd/SD19/by_write.zip)）
+ FMINIST(FashionMNIST): 物品识别

## 2024.1.6(16:10)-2024.1.9(10:00)

**任务**

- [x] 数据集的更换
- [ ] 搞懂FL、ViT（理解 + Code）
- [x] 过程中遇到有帮助的图留意下
- [x] 完成后预定1.8日晚或1.9日早的会议

**数据集**

数据集最终决定使用这三个：

+ MNIST: 手写数字识别（[官网(访问需要密码)](https://yann.lecun.com/exdb/mnist/)、[官网的Web Archive](https://web.archive.org/web/20231229081350/http://yann.lecun.com/exdb/mnist/)、[Kaggle数据集](https://www.kaggle.com/datasets/hojjatk/mnist-dataset)）
+ CIFAR-10: airplane automobile bird cat deer dog frog horse ship truck（[官网](https://www.cs.toronto.edu/~kriz/cifar.html)、[数据集](https://www.cs.toronto.edu/~kriz/cifar-10-python.tar.gz)）
+ OrganAMNIST: 其实是属于[MedMNIST](https://www.nature.com/articles/s41597-022-01721-8)（[MedMNIST数据集](https://zenodo.org/records/6496656)、[OrganAMNIST](https://zenodo.org/records/6496656/files/organamnist.npz?download=1)）

## 2024.1.9(19:00)-近几天(待定)

**任务**

- [ ] 看模型结构(2024.1.10)
- [ ] ViT敏感层确定
- [ ] 画出实验图
- [ ] 写理论部分
- [ ] 设计实验并执行

其他（小杂）：

+ 攻击找两三个backdoor；防御 现有的 替换个
+ 安全性（识别、结果、...）
+ 名字：mask（安全掩码）
+ 图：选层 放大
+ 1. ViT选层、2. 放大、3. cos计算（信用）

## 2024.5.14-2024.5.19

暂时停止在[原有](https://github.com/LetMeFly666/FLDefinder/commit/c830b55950ba84a8dd657bbd4ecfa247c6c3e8a5)基础上继续更改，[开始](https://github.com/LetMeFly666/FLDefinder/commit/fd9f0fa1c57a6f9194e49d14c3fd0ac00779f3a4)寻找现有的联邦学习ViT Backdoor的代码并在此基础上进行更改。

小目标：跑通某个现有代码，达到应有的准确率。

## 2024.6.3-2024.6.27

全力写本子。

## 2024.7.1-2024.7.10

+ 7.1-7.2(上午)：再熟悉一下FL(攻防)基本知识
+ 7.2(下午)-7.3：定下最终思路
+ 7.4-7.8：代码实现/实验结果跑完
+ 7.9-7.10：初稿写完

### 思路一

经典特征层提取。

根据[Better Together](https://dl.acm.org/doi/abs/10.1145/3564625.3564658)，此类实验主要有三个指标：

1. 鲁棒性
2. 保真度
3. 效率

特征层提取的话，对于鲁棒性，**未完待续**

## 2024.7.1-2024.7.15

IEEE UIC2024的[ViT-MGI](https://github.com/LetMeFly666/ViT-MGI)初稿已定，几乎不会怎么改了。

## 2024.7.18 - 2024.7.22(周一)

扩刊idea。主要有以下两个方面：

1. 深入一下ViT，有无能更加针对ViT的工作？
2. 读一些最新攻防，高级攻击如何防？

以上以2为主。

周一找赞哥讨论。

## ~~2024.7.23 - 2024.7.29(周一)~~

更具体一点的idea。

周一找赞哥讨论。

## 2024.7.22(下午) - 2024.7.23(下午/晚上)

1. 了解一下北邮超算平台，使用赞哥工号开通一个
2. 了解大模型，什么样才算大模型，大模型一般怎么训(冻结调参?)，如何与视觉挂钩(甚至是ViT)，能否联邦学习
3. 确定两个视觉相关大模型(能训得出来那种比较小的大模型)，确定两个数据集，确定具体怎么训

**参数量：** 没有明确定义，通常具有数十亿规模参数甚至更多。当然也有较小的几千万参数的“大模型”。

**能否联邦学习：** 能，ViT就FL了。

**大模型选择：**

1. ViT也能算得上大模型，尤其是`ViT-Large`和`ViT-Huge`。
   + `ViT-Base (ViT-B/16)`：8600万参数
   + `ViT-Large (ViT-L/16)`：3.07亿参数
   + `ViT-Huge (ViT-H/14)`：6.32亿参数
2. Swin Transformer：是一种分层视觉Transformer模型，在图像分类、目标检测和图像分割等任务上表现出色。
   + `Swin-Tiny`：2900万参数
   + `Swin-Small`：5000万参数
   + `Swin-Base`：8800万参数
   + `Swin-Large`：1.97亿参数
3. ResNet-152：是一种深层卷积神经网络，在多个视觉任务中表现优异。
   + 6000万参数

| 特点              | Vision Transformer (ViT)                | Swin Transformer                             |
|-------------------|-----------------------------------------|----------------------------------------------|
| 架构              | 直接使用Transformer架构处理patch        | 分层设计，使用窗口注意力和移动窗口机制        |
| 优点              | 强大表示能力，简化设计                  | 计算效率高，适合多任务和高分辨率图像         |
| 缺点              | 计算资源要求高，处理高分辨率图像复杂    | 结构复杂，需要精细设计和调优                 |
| 图像分类性能      | 大规模数据上表现优异                    | 各种数据规模上表现良好                      |
| 目标检测和图像分割| 可能表现不如专门设计的模型              | 表现出色                                    |
| 计算复杂度        | 高，尤其是高分辨率图像                  | 较低，适合高分辨率图像处理                  |

**数据集选择：**

| 数据集名称        | 数据量       | 标签数  | 特点                                             | 主要应用模型                      | 数据集类型                          |
|-------------------|--------------|---------|--------------------------------------------------|-----------------------------------|------------------------------------|
| ImageNet-1k       | 120万      | 1,000   | 大规模图像分类基准，常用于模型预训练和评估         | ViT, Swin Transformer, DeiT       | 自然图像分类                        |
| ImageNet-21k      | 1400万       | 21,000  | 包含更多类别，适合大规模预训练                      | ViT, Swin Transformer             | 自然图像分类                        |
| CIFAR-10          | 60,000       | 10      | 小规模数据集，常用于快速验证模型性能                | ViT, DeiT                         | 小型自然图像分类                    |
| CIFAR-100         | 60,000       | 100     | 与CIFAR-10类似，但分类更细致                        | ViT, DeiT                         | 小型自然图像分类                    |
| Tiny ImageNet     | 100,000      | 200     | 中等规模数据集，适用于模型性能验证                  | ViT, DeiT                         | 自然图像分类                        |
| COCO              | 330,000      | 80      | 多任务数据集，广泛用于目标检测和图像分割            | Swin Transformer, SegFormer       | 目标检测、图像分割、物体识别        |
| ADE20K            | 25,000       | 150     | 用于语义分割任务的标准数据集                        | Swin Transformer, SegFormer       | 语义分割                            |
| Cityscapes        | 5,000        | 30      | 专用于城市街景图像分割，评估模型在真实场景的表现    | Swin Transformer, SegFormer       | 城市街景图像分割                    |
| Pascal VOC        | 9,000        | 20      | 经典的目标检测和分类数据集，应用广泛                | Swin Transformer, SegFormer       | 目标检测和分类                      |

## 2024.7.23(晚上) - 2024.7.24(暂定晚上)

前面的调研不中。

+ 大模型的具体步骤
+ 视觉大模型的具体步骤

可以找找近两年论文里图像分类的大模型都用的啥，具体是怎么微调的。

# End

> 原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2024/01/06/Other-AI-FL-FederatedLearning-ProjectWritingIn1month/)哦~
> [https://blog.letmefly.xyz/2024/01/06/Other-AI-FL-FederatedLearning-ProjectWritingIn1month/](https://blog.letmefly.xyz/2024/01/06/Other-AI-FL-FederatedLearning-ProjectWritingIn1month/)