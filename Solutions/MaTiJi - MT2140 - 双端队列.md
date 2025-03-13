---
title: 码蹄集 - MT2140 - 双端队列
date: 2022-09-28 21:30:36
tags: [题解, 码蹄集, 简单, 双端队列, 队列, 模拟]
categories: [题解, 马蹄集]
---

@[TOC](传送门)


---


## 双端队列

+ <a href="https://matiji.net/exam/brushquestion/140/3181/1DC60EA6DF83A333301CFFE1407FBA59"> 双端队列</a> <a href="https://matiji.net/exam/dohomework/1956/3">.</a>

<small>时间限制：1秒</small>
<small>空间限制：128M</small>



---



### 题目描述

小码哥想创建一个双端队列，即，两头都能进，两头都能访问，两头都能出。请你创建一个这样的双端队列并帮他实现以下三种操作：

1. 1 x  //将整数x增加到头部
1. 2 x  //将整数x增加到尾部
1. 3    //访问头部的元素
1. 4    //访问尾部的元素
1. 5    //弹出(删除)头部的元素
1. 6    //弹出(删除)尾部的元素

这个双端数列一开始是空的。

---

### 输入描述

第一行输入一个整数n，表示操作个数。
接下来n行，每行输入一个操作，格式如题目描述中所示。

#### 数据范围

保证：对于100%的数据：1<=n<=1,000,000，x在int类型范围内，数列为空时只进行操作1和2。



---


### 输出描述



对于每个操作3和4，输出一行一个整数表示答案。



---


### 样例一

#### 输入

```
11
1 3
1 6
2 9
3
4
5
2 7
2 8
6
3
4
```

#### 输出

```
6
9
3
7
```




# 题目分析

本片题解提供一种使用C++ list 模拟双端队列的方法

list可以很方便地进行头部和尾部的插入删除取值操作，正好是题目要求进行的6种操作。

+ 插入头部：push_front
+ 插入尾部：push_back
+ 访问头部：*.first
+ 访问尾部：back
+ 删除头部：pop_front
+ 删除尾部：pop_back

因此直接进行模拟即可。

# AC代码

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2022-09-28 20:33:04
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-28 20:35:15
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
int main() {
    int N;
    cin >> N;
    list<int> li;
    while (N--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            li.push_front(x);
        }
        else if (op == 2) {
            int x;
            cin >> x;
            li.push_back(x);
        }
        else if (op == 3) {
            cout << *li.begin() << endl;
        }
        else if (op == 4) {
            cout << li.back() << endl;
        }
        else if (op == 5) {
            li.pop_front();
        }
        else {
            li.pop_back();
        }
    }
    return 0;
}
```

<font color="black" face="楷体" size="5px">虽然代码可以复制，但最好还是自己理解后再敲哦</font>

<!-- <font color="black" face="楷体" size="5px">每周提前更新菁英班周赛题解，点关注，不迷路</font> -->

>原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/09/28/MaTiJi%20-%20MT2140%20-%20%E5%8F%8C%E7%AB%AF%E9%98%9F%E5%88%97/)哦~
>Tisfy：[https://letmefly.blog.csdn.net/article/details/127097523](https://letmefly.blog.csdn.net/article/details/127097523)