---
title: 码蹄集 - MT3521 - X/Y
date: 2022-09-28 21:53:32
tags: [题解, 码蹄集, 中等, 数学, 同余]
---

@[TOC](传送门)


---


## X/Y

+ <a href="https://matiji.net/exam/brushquestion/521/3846/4C6668FEB8CFD6520DE73B365B31D1A4"> X/Y</a> <a href="https://matiji.net/exam/dohomework/1956/5">.</a>

<small>时间限制：1秒</small>
<small>空间限制：128M</small>



---



### 题目描述

有一个特别大的整数$X$，保证它一定可以被$Y$整除，现在给定整数$n(n=Xmod9973)$，数据保证$gcd(Y,9973)=1$。

---

### 输入描述


一行包含两个整数n,Yn,Y

#### 数据范围

其中：$0<=n<99730$,$1<=Y<=10^9$,$gcd(Y,9973)=1$



---


### 输出描述

一行输出 (X/Y)(X/Y)%9973



---


### 样例一

#### 输入

```
87 123456789
```

#### 输出

```
6060
```



# 题目分析

这道题看懂之后也不难。

既然是对9973取模，那么答案只有9973种。

因此，我们可以直接从0到9972模拟，X/Y并取模后的值ans

如果ans * Y 和 n 关于9973同余，那么ans就是答案

# AC代码

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2022-09-28 20:42:02
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-28 20:46:11
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

const ll MOD = 9973;

int main() {
    ll n, y;
    cin >> n >> y;
    for (ll ans = 0; ans < MOD; ans++) {
        if ((ans * y) % MOD == n) {
            cout << ans << endl;
        }
    }
    return 0;
}
```

<font color="black" face="楷体" size="5px">虽然代码可以复制，但最好还是自己理解后再敲哦</font>

<!-- <font color="black" face="楷体" size="5px">每周提前更新菁英班周赛题解，点关注，不迷路</font> -->

>原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/09/28/MaTiJi%20-%20MT3521%20-%20X%E6%AF%94Y/)哦~
>Tisfy：[https://letmefly.blog.csdn.net/article/details/127097898](https://letmefly.blog.csdn.net/article/details/127097898)