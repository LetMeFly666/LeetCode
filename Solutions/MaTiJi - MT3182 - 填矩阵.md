---
title: 码蹄集 - MT3182 - 填矩阵
date: 2022-07-21 18:16:12
tags: [题解, 码蹄集, 中等, 模拟, 方案数, 动态规划, DP]
---

@[TOC](传送门)


---


## 填矩阵
+ <a href="https://matiji.net/exam/brushquestion/182/3846/4C6668FEB8CFD6520DE73B365B31D1A4"> 填矩阵</a> <a href="https://matiji.net/exam/dohomework/1284/4">.</a>

<small>时间限制：1秒</small>
<small>空间限制：128M</small>



---



### 题目描述

有一个$1\times n$的矩阵，现在往里面填方块，一共有三种方块：$1\times 1$的白块，$1\times 1$的黑块，$1\times k$的黑块，方块放置时，必须是黑白交替的，矩阵不用填满，但要求最下面的块和最上面的块必须是黑色的，问有多少种放置方法。
​


---

### 输入描述



输入两个整数$n,k$代表矩阵的高度和黑块的高度

#### 数据范围

$2≤k≤10,1≤n≤100$

---


### 输出描述

输出一个整数代表放置方法



---


### 样例一

#### 输入

```
5 3
```

#### 输出

```
6
```

# 题目大意

**为了便于理解题意，我画了一张图来解释：**

![示例](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/291c41e010444833ad335c2b9d9bac30.jpeg#pic_center)

# 题目分析

用两个数组：

```cpp
int Bai[111] = {0};  // Bai[i]：只考虑下面的i块，{最下面一块是黑块前提下，最上面一块是**白**块}的方案数
int Hei[111] = {0};  // Hei[i]：只考虑下面的i块，{最下面一块是黑块前提下，最上面一块是**黑**块}的方案数
```

初始值：

```cpp
Hei[1] = 1;  // 最下面一块是黑色，最上面一块是黑色，并且最有一块被填色，只有一种方法，就是只放置一个1x1的黑块
Bai[0] = 1;  // 因为黑白是交替放置的，因此可以理解为第0块（必须为黑）的下面有一个虚拟的白块
```

之后，从第二块儿开始模拟：

+ 如果第$i$块是1x1的白块，那么下面一块必定是黑块。
   ```cpp
   Bai[i] = Hei[i - 1];
   ```
+ 如果第$i$块是1x1的黑块，那么下面一块必定是白块。
   ```cpp
   Hei[i] = Bai[i - 1];
   ```
+ 如果第$i$块是1xk的黑块（**前提是i≥k**），那么下面一块(i - k)必定是白块
   ```cpp
   if (i - k >= 0) {
       Hei[i] += Bai[i - k];
   }
   ```


最后再把所有的最上面是黑块的情况累加起来即可。

```cpp
ll ans = 0;
for (int i = 1; i <= n; i++) {
    ans += Hei[i];
}
cout << ans << endl;
```

# AC代码

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2022-07-21 10:10:16
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-21 10:22:45
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

ll n, k;
ll Bai[111] = {0};  // Bai[i]：只考虑下面的i块，{最下面一块是黑块前提下，最上面一块是白块}的方案数
ll Hei[111] = {0};

int main() {
    Hei[1] = 1, Bai[0] = 1;
    cin >> n >> k;
    for (int i = 2; i <= n; i++) {
        // 第i块是白块的顶部
        Bai[i] = Hei[i - 1];
        // 第i块是黑块的顶部
        Hei[i] = Bai[i - 1];  // 1x1
        if (i - k >= 0) {
            Hei[i] += Bai[i - k];
        }
    }
    
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += Hei[i];
    }
    cout << ans << endl;
    return 0;
}
```

<font color="black" face="楷体" size="5px">虽然代码可以复制，但最好还是自己理解后再敲哦</font>

<!-- <font color="black" face="楷体" size="5px">每周提前更新菁英班周赛题解，点关注，不迷路</font> -->

>原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/07/21/MaTiJi%20-%20MT3182%20-%20%E5%A1%AB%E7%9F%A9%E9%98%B5/)哦~
>Tisfy：[https://letmefly.blog.csdn.net/article/details/125918304](https://letmefly.blog.csdn.net/article/details/125918304)