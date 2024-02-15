---
title: 码蹄集 - MT2073 - 上传头像
date: 2022-08-21 21:14:11
tags: [题解, 码蹄集, 简单, 模拟]
---

@[TOC](传送门)


---


## 上传头像
+ <a href="https://matiji.net/exam/brushquestion/73/3181/1DC60EA6DF83A333301CFFE1407FBA59"> 上传头像</a> <a href="https://matiji.net/exam/dohomework/1500/3">.</a>

<small>时间限制：1秒</small>
<small>空间限制：128M</small>



---



### 题目描述

有一天无聊的你在注册一个无聊的网站，注册完的第一步自然是上传头像。

你发现这个网站总共可以上传 n个头像，每个头像必须是正方形，并且长宽至少为L×L

在图片上传前，系统会对图片进行如下处理：如果图片的任何一边长度超过了 G，那么系统会不断地对图片的长宽同时减半（向下取整），直至两边长度 ≤G 为止。

你现在找到了 n张可供上传的图片，第 ii 张的尺寸是 W_i *H_i。

如果图片有任何一边小于 L，请输出 “Too Young”

如果图片满足大小条件但不为正方形，请输出”Too Simple”

如果图片满足大小条件并且是正方形，请输出”Sometimes Naive”

以上所有字符串输出时均不包含引号。


---

### 输入描述



一行三个整数 n,L,G ，意义如题目所述。

接下来每行两个整数 W_i,H_i，表示图片长宽。

#### 数据范围

n≤2000，0<Wi,Hi,G,L≤10000

---


### 输出描述


共 n行，每行一个字符串，意义如题目所述。



---


### 样例一

#### 输入

```
3 5 10
12 3
7 8
5 5
```

#### 输出

```
Too Young
Too Simple
Sometimes Naive
```




# 题目分析

这道题我也不知道为啥要输出这玩意儿。

既然让这么输出，那就这么输出吧。

1. 首先判断是否有边长度大于G。如果有，就长和宽分别除以2。直到没有为止
2. 接着判断是否有长度边小于L。如果有，就输出Too Young
3. 如果没有输出Too Young，就判断长和宽是否相同。如果相同，就输出Sometimes Naive
4. 否则就输出Too Simple

# AC代码

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2022-08-21 11:05:12
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-21 11:09:10
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
int main() {
    int n, l, g;
    cin >> n >> l >> g;
    while (n--) {
        int a, b;
        cin >> a >> b;
        while (a > g || b > g) {
            a /= 2, b /= 2;
        }
        if (a < l || b < l) {
            puts("Too Young");
        }
        else if (a == b) {
            puts("Sometimes Naive");
        }
        else {
            puts("Too Simple");
        }
    }
    return 0;
}
```

<font color="black" face="楷体" size="5px">虽然代码可以复制，但最好还是自己理解后再敲哦</font>

<!-- <font color="black" face="楷体" size="5px">每周提前更新菁英班周赛题解，点关注，不迷路</font> -->

>原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/08/21/MaTiJi%20-%20MT2073%20-%20%E4%B8%8A%E4%BC%A0%E5%A4%B4%E5%83%8F/)哦~
>Tisfy：[https://letmefly.blog.csdn.net/article/details/126455567](https://letmefly.blog.csdn.net/article/details/126455567)