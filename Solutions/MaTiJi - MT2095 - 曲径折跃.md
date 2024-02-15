---
title: 码蹄集 - MT2095 - 曲径折跃
date: 2022-07-21 12:31:47
tags: [题解, 码蹄集, 简单, 模拟, LOL]
---

@[TOC](传送门)


---


## 曲径折跃
+ <a href="https://matiji.net/exam/brushquestion/95/3181/1DC60EA6DF83A333301CFFE1407FBA59"> 曲径折跃</a> <a href="https://matiji.net/exam/dohomework/1284/2">.</a>

<small>时间限制：1秒</small>
<small>空间限制：128M</small>



---



### 题目描述

小码哥特别狠，经常会把队友送到一些奇奇怪怪的地方去。这一次，他又将曲径折跃放在了jiejie的脚下。由于jiejie不想被打乱自己的节奏，所以他选择赶紧逃出升天。jiejie玩的是皇子，技能eq连招能位移x码的距离，eq位移是不消耗时间的。同时，jiejie的移动速度为n码每秒，曲径折跃的半径为r码。jiejie的技能可能在cd，e和q任意一个技能在cd都不能使用技能位移。曲径折跃生效时间为2秒。现在他想知道自己能不能逃出曲径折跃
​


---

### 输入描述


5个整数

e：e技能cd（为0时可使用）

q：q技能cd

x：移动距离

n：移速

r：半径

#### 数据范围

e、q为非负整数，x、r、n为正整数

---


### 输出描述

如果能逃出输出yes

否则输出no



---


### 样例一

#### 输入

```
0 0 500 100 700
```

#### 输出

```
yes
```





这道题我读了很久~（可能是因为没咋玩过LOL）~

读懂题目后就很简单了

# 题目大意

问你$2$秒内，能否移动$\geq r$的距离。

移动方式有两种：

1. 步行：每秒可以移动$n$米
2. 瞬移：不消耗时间，可以瞬间移动$x$米。但是前提是$e\leq 2且q\leq 2$ 

# 题目分析

读懂了题目后，直接模拟即可。

两秒内，步行可以移动$2\times n$米，

如果$e\leq 2且q\leq 2$ ，那么还可以再瞬移$x$米。

看最终移动距离是否$\geq r$即可。

# AC代码

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2022-07-21 10:29:45
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-21 10:33:26
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
int main() {
    int e, q, x, n, r;
    cin >> e >> q >> x >> n >> r;
    r -= 2 * n;
    if (e <= 2 && q <= 2)
        r -= x;
    if (r <= 0)
        puts("yes");
    else
        puts("no");
    return 0;
}
```

<font color="black" face="楷体" size="5px">虽然代码可以复制，但最好还是自己理解后再敲哦</font>

<!-- <font color="black" face="楷体" size="5px">每周提前更新菁英班周赛题解，点关注，不迷路</font> -->

>原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/07/21/MaTiJi%20-%20MT2095%20-%20%E6%9B%B2%E5%BE%84%E6%8A%98%E8%B7%83/)哦~
>Tisfy：[https://letmefly.blog.csdn.net/article/details/125909920](https://letmefly.blog.csdn.net/article/details/125909920)