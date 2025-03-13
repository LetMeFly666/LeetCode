---
title: 码蹄集 - MT2142 - 万民堂大厨
date: 2022-08-04 09:09:09
tags: [题解, 码蹄集, 中等, 模拟, 动态规划, DP]
categories: [题解, 马蹄集]
---

@[TOC](传送门)


---


## 万民堂大厨

+ <a href="https://matiji.net/exam/brushquestion/142/3181/1DC60EA6DF83A333301CFFE1407FBA59"> 万民堂大厨 </a> <a href="https://matiji.net/exam/dohomework/1405/2">.</a>

<small>时间限制：1秒</small>
<small>空间限制：128M</small>



---



### 题目描述

万民堂大厨要做一道菜，这道菜需要烹饪数个小时，达到一定的火力值。可以选择小火烹饪一次加n点火力值，中火烹饪加m点火力值，大火烹饪加k点火力值，烹饪次数不限制。这道菜总共要达到x点火力值，不多不少，才能显现出万民堂大厨的实力。但万民堂大厨觉得这还是太简单了。所以他想考考你，这道菜有多少种不同的烹饪方式？（火力烹饪的顺序不同也算不同的情况，毕竟璃月厨艺博大精深，先小火后大火和先大火后小火烹饪的菜品会有很大不同）由于数据很大，请输出答案mod 1e9+7之后的值
​


---

### 输入描述



四个整数x,n,m,k


#### 数据范围

所有数据均在long long范围内
0 < x < 1000, 0 < n < m < k < 30

---


### 输出描述


一个整数，表示不同的方案数

若无法烹饪则输出“impossible”



---


### 样例一

#### 输入

```
5 1 2 3
```

#### 输出

```
13
```




# 题目分析

<small>其实这道题的题目描述让我比较疑惑的是，数据范围为什么要加上个“```long long范围内```”，我寻思1000连```INT_MAX```都不到诶。</small>

这道题说白了，就是**给你三个不同的数，每个数可以使用任意次。问你有多少种方案使得三个数之和是x，三个数顺序不同视为不同的方案**

好了，既然我们知道了题意，那么就可以开始愉快地dp了。

建立一个长度至少为$x + 1$的```dp```数组，初始值除$dp[0]=1$外全为$0$。

$dp[i]$表示三个数之和为$i$的方案数。

那么，我们就可以用$i$从$1$到$x$循环一遍，和为$i$的方案有$3$种，就是分别由$i-a_0$、$i-a_1$、$i-a_2$得到。

因此$dp[i] = \sum_{j=0}^{2} dp[i - a[j]]$，其中$i \geq a[j]$


# AC代码

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2022-08-03 18:50:58
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-03 18:57:14
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

ll dp[1010] = {1, 0};
const ll mod = 1e9 + 7;

int main() {
    int x;
    int val[3];
    cin >> x;
    for (int i = 0; i < 3; i++) {
        cin >> val[i];
    }
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < 3; j++) {
            if (i - val[j] >= 0) {
                dp[i] += dp[i - val[j]];
                dp[i] %= mod;
            }
        }
    }
    if (dp[x]) {
        cout << dp[x] << endl;
    }
    else {
        puts("impossible");
    }
    return 0;
}
```

<font color="black" face="楷体" size="5px">虽然代码可以复制，但最好还是自己理解后再敲哦</font>

<!-- <font color="black" face="楷体" size="5px">每周提前更新菁英班周赛题解，点关注，不迷路</font> -->

>原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/08/04/MaTiJi%20-%20MT2142%20-%20%E4%B8%87%E6%B0%91%E5%A0%82%E5%A4%A7%E5%8E%A8/)哦~
>Tisfy：[https://letmefly.blog.csdn.net/article/details/126152888](https://letmefly.blog.csdn.net/article/details/126152888)