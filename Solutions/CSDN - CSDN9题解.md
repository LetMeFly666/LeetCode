---
title: CSDN - CSDN9题解
date: 2022-11-17 18:28:57
tags: [题解, CSDN]
---

[TOC]

>  CSDN编程竞赛报名地址：https://edu.csdn.net/contest/detail/22

## 小艺读书

### 题目描述

书是人类进步的阶梯。 小艺每周因为工作的原因会选择性的每天多读几页或者少读几页。 小艺想知道一本n页的书她会在
周几读完。

### 解题思路

这题数据量不大，直接模拟就好

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[7];
    int n;
    cin >> n;
    for (int i = 0; i< 7; i++) {
        cin >> a[i];
    }
    int th = 0;
    while (n > 0) {
        n -= a[th];
        if (n <= 0) {
            cout<< th + 1 << endl;
            return 0;
        }
        th = (th + 1) % 7;
    }
    return 0;
}
```

## 鬼画符门之宗门大比

### 题目描述

给定整数序列A。求在整数序列A中连续权值最大的子序列的权值。

### 解题思路

说白了就是最大子串，板子题

用两个遍历，分别记录当前的和 和 历史最大值即可。

遍历过程中，如果当前和为负数，就丢弃前面的子串，将和化为0

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int s = 0;
    int ans = INT_MIN;
    for (int t : a) {
        if (s <= 0)
            s = t;
        else
            s += t;
        ans = max(ans, s);
    }
    cout << ans << endl;
    return 0;
}
```

## 硬币划分

### 题目描述

有1分，2分，5分，10分四种硬币，每种硬币数量无限，给定n分钱(n<=100000)，有多少中组合可以组成n分钱？

### 解题思路

动态规划，dp[i]表示总金额为i的方案数

转移方程$dp[i] = \sum dp[i - coin_j]$，其中coin的取值范围为1、2、5、10

注意，要一种硬币一种硬币地算，因为“先1后2”和“先2后1”是一种情况。

一种硬币一种硬币地算相当于 先“全部用1元硬币”，然后尝试用“2元”替换“1元”的，再用“5元”替换，最后“10”

因此不会“先2后1”

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
int main() {
    const int coins[4] = {1, 2, 5, 10};
    int n;
    cin >> n;
    vector<ll>dp (n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = coins[i]; j <= n; j++) {
            dp[j] = (dp[j] + dp[j - coins[i]]) % MOD;
        }
    }
    cout << dp.back();
    return 0;
}
```

## 饿龙咆哮-逃离城堡

### 题目描述

小艺酱误入龙族结界，被恶龙带回城堡，小艺酱决定逃离城堡，逃离龙族结界.。

总路程为c， 小艺酱的速度是vp，饿龙速度为vd。饿龙会在t小时后发现小艺酱出逃。

小艺酱担心自己跑不出去，准备了好多珍宝。 每当饿龙追上自己的时候小艺酱就会丢下一个珍宝，饿龙捡到珍宝会返回自己的城堡进行研究，研究f小时后，再出城堡追赶小艺。

小艺想知道自己至少需要丢多少珍宝才能让自己安全逃出结界。


### 解题思路

这题注意精度，进行模拟就好

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int main() {
    ld vp, vd, c, t, f;
    cin >> vp >> vd >> t >> f >> c;
    if (vp >= vd) {
        cout << 0 << endl;
        return 0;
    }
    ld total = vp * t;
    int ans = 0;
    while (total < c) {
        ld x = (vp * total) / (vd - vp);
        total += x;
        if (total >= c)
            break;
        ans++;
        ld newT = total / vd + f;
        total += newT * vp;
    }
    cout << ans << endl;
    return 0;
}
```

