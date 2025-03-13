---
title: 码蹄集 - MT2065 - 整数大小比较
date: 2022-08-21 21:03:25
tags: [题解, 码蹄集, 简单, 模拟, 比大小]
categories: [题解, 马蹄集]
---

@[TOC](传送门)


---


## 整数大小比较
+ <a href="https://matiji.net/exam/brushquestion/65/3181/1DC60EA6DF83A333301CFFE1407FBA59"> 整数大小比较</a> <a href="https://matiji.net/exam/dohomework/1500/2">.</a>

<small>时间限制：1秒</small>
<small>空间限制：128M</small>



---



### 题目描述

给出两个正整数，判断他们的大小


---

### 输入描述


两个正整数

#### 数据范围

保证所有数在$2^{100}$以内

---


### 输出描述


若前者大，输出>

若后者大，输出<

若一样大，输出=



---


### 样例一

#### 输入

```
1412894619244619891 23762842222
```

#### 输出

```
>
```




# 题目分析

这道题用python的话，那就是入门级别的难度。

提供2种用C/C++的思路：

## C/C++ 方法一：字符串

把输入当作字符串来处理，首先判断字符串长度，若不同，则长者大。

若相同，则前到后比较，遇到第一个不同的为止，大者大。

若遍历到字符串尾也未发现不同，那就说明相等。

## C/C++ 方法二：__int128

```__int128```能存储```128```位二进制数据，题目范围的```100```位绰绰有余

但有些编译器不支持```__int128```

# AC代码

```python
'''
Author: LetMeFly
Date: 2022-08-21 11:03:24
LastEditors: LetMeFly
LastEditTime: 2022-08-21 11:03:26
'''
a, b = map(int, input().split())
if a > b:
    print(">")
elif a == b:
    print("=")
else:
    print("<")
```

<font color="black" face="楷体" size="5px">虽然代码可以复制，但最好还是自己理解后再敲哦</font>

<!-- <font color="black" face="楷体" size="5px">每周提前更新菁英班周赛题解，点关注，不迷路</font> -->

>原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/08/21/MaTiJi%20-%20MT2065%20-%20%E6%95%B4%E6%95%B0%E5%A4%A7%E5%B0%8F%E6%AF%94%E8%BE%83/)哦~
>Tisfy：[https://letmefly.blog.csdn.net/article/details/126455447](https://letmefly.blog.csdn.net/article/details/126455447)