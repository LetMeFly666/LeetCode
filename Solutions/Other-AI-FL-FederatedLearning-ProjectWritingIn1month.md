---
title: 人工智能 - 联邦学习(安全性) - 自用(ProjectDoing)
date: 2024-01-06 12:32:45
tags: [其他, AI, DL, 人工智能, 深度学习, 联邦学习]
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

> 原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2024/01/06/Other-AI-FL-FederatedLearning-ProjectWritingIn1month/)哦~
> [https://blog.letmefly.xyz/2024/01/06/Other-AI-FL-FederatedLearning-ProjectWritingIn1month/](https://blog.letmefly.xyz/2024/01/06/Other-AI-FL-FederatedLearning-ProjectWritingIn1month/)