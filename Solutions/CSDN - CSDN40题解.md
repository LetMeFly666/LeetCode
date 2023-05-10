---
title: CSDN - CSDN40题解
date: 2023-03-29 15:16:11
tags: [题解, CSDN]
---

[TOC]

# 【CSDN线上竞赛40】小结

>  CSDN编程竞赛报名地址：[https://edu.csdn.net/contest/detail/54](https://edu.csdn.net/contest/detail/54)

## 小鱼的航程(改进版)

### 题目描述

有一只小鱼，它上午游泳150公里，下午游泳100公里，晚上和周末都休息（实行双休日)，假设从周x(1<=x<=7)开始算起，请问这样过了n天以后，小鱼一共累计游泳了多少公里呢？


### 解题思路

首先这道题数据量较大，不能完全模拟。

但是比较容易想到的是，我们可以先计算出这n天等于**几周余几天**

a周的话，就能游$a\times (150 + 100) \times 5$公里

剩下的小于7的几天，模拟一下就好了

### AC代码

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long ans = 0, x, n;
    cin >> x >> n;
    ans += (n / 7) * (250 * 5);
    n %= 7;
    while (n--) {
        if (x != 6 && x != 7) {
            ans += 250;
        }
        x = (x + 1);
    }
    cout << ans << endl;
    return 0;
}
```

## 编码

### 题目描述

编码工作常被运用于密文或压缩传输。这里我们用一种最简单的编码方式进行编码：把一些有规律的单词编成数字。 字母表中共有26个字母{a，b，…，z}，这些特殊的单词长度不超过6且字母按升序排列。把所有这样的长度相同的单词放在一起，按字典顺序排列，一个单词的编码就对应着它在整个序列中的位置。 你的任务就是对于所给的单词，求出它的编码

### 解题思路

排列组合问题，需要注意的是：

1. 需要判断给定字符串是否合法（貌似只有一组样例不是“长度不大于6的递增字符串”）
2. 题目好像并没有说明数据范围，因此C++等语言记得开long long

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll C(ll n, ll m) {
    if (m == n || (!m) || (!n)) {
        return 1;
    }
    if (n == 1) {
        return m;
    }
    return C(n - 1, m - 1) + C(n - 1, m);
}

int main() {
    string s;
    cin >> s;
    // 判断是否合法字符串
    if (s.size() > 6) {
        puts("0");
        return 0;
    }
    for (int i = 1; i < s.size(); i++) {
        if (s[i] <= s[i - 1]) {
            puts("0");
            return 0;
        }
    }
    // 开始计算
    ll ans = C(26, s.size()) - C(26 - (s[0] - 'a'), s.size());
    for (int i = 1; i < s.size(); i++) {
        ans += C(26, i) + C(26 - (s[i - 1] - 'a' + 1), s.size() - i) - C(26 - (s[i] - 'a'), s.size() - i);
    }
    cout << ans + 1 << endl;
    return 0;
}
```

## 一维数组的最大子数组和

### 题目描述

给定一个整数数组 nums ，找到一个具有最大和的连续子数组，输出该子数组在原数组中的开始下标和结束下标。原数组下标从0开始

### 解题思路

动态规划，dp[i]代表数组下标0到下标i的最优解。

遍历原始数组，如果$dp[i - 1] \geq 0$，那么就有使用前面数组的价值；否则就从当前位置开始作为子数组的起点。

**注：** 上述为比赛时的思路，其实不需要开辟dp数组，直接使用一个变量即可。毕竟dp数组中，dp[i]也只会用到dp[i - 1]

对于这道题是否有多个“最大和的连续子数组”的情况，暂时存疑，因为我比赛的时候刚开始忘记开long long了，存在数据溢出的话，$dp[i - 1] \geq 0$和$dp[i - 1] \gt 0$对结果的影响可能不准。

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100010], dp[100010];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp[0] = a[0];
    ll ans = a[0];
    int from = 0, to = 0;
    int ansFrom = from, ansTo = to;
    for (int i = 1; i < n; i++) {
        if (dp[i - 1] >= 0) {
            dp[i] = dp[i - 1] + a[i];
        }
        else {
            dp[i] = a[i];
            from = i;
        }
        if (dp[i] > ans) {
            ans = dp[i];
            ansFrom = from, ansTo = i;
        }
        // dp[i] = max(dp[i - 1] + a[i], a[i]);
        // ans = max(ans, dp[i]);
    }
    cout << ansFrom << ' ' << ansTo << endl;
    return 0;
}
```

## 喜水青蛙

### 题目描述

总是喜欢在水里嬉戏的青蛙，某天要过河拜访一位朋友。
已知河道中长满了带刺的不知名生物，能通过的路只有一条直线，长度为L。
直线上随机分布着m块石头。青蛙的最小跳跃距离是s，最大跳跃距离是t。
青蛙想要尽可能的少踩石头，那么它通过河道最少会踩到多少石头？

### 解题思路

这道题的原题是[NOIP2005的青蛙过河](https://ac.nowcoder.com/acm/contest/253/B)

当时做这道题觉得比较坑的一点是：青蛙过河不一定非要踩着石子。

可以理解为：青蛙可以在水面上轻功跳，它不想踩到石头上，但由于其跳跃距离有限，因此有时不得不踩中一些石子。青蛙不求最小的跳跃次数，只想尽可能少地踩中石子。

本题中河的长度很长（$10^9$），但是石头的数量很少（$100$），因此两个石头之间可能有很长的间隙，我们可以离散化存储石头的位置，计算到达石头$i$处，至少要踩到多少的石头。

注意：

1. 本题有多组样例
2. 石头不一定有序，保险起见输入后对石头位置进行排序

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
int shiTou[111], Sum[10010];
bool visited[100010];

int main() {
    int l, s, t, m;
    while (cin >> l >> s >> t >> m) {
        memset(Sum, 0x3f, sizeof(Sum));
        for (int i = 1; i <= m; i++) {
            scanf("%d", &shiTou[i]);
        }
        sort(shiTou, shiTou + m + 2);
        int x = 0;
        for (int i = 0; i <= m + 1; i++) {
            if (shiTou[i] - shiTou[i - 1] <= t * s) {
                x += shiTou[i] - shiTou[i - 1];
            }
            else {
                x += (shiTou[i] - shiTou[i - 1]) % t + t;
            }
            visited[x] = true;
        }
        Sum[0] = 0;
        for (int i = 0; i <= x + t; i++) {
            for (int j = s; j <= t; j++) {
                if (i >= j) {
                    Sum[i] = min(Sum[i], Sum[i - j] + visited[i]);
                }
            }
        }
        int ans = INT_MAX;
        for (int i = x; i <= x + t; i++) {
            ans = min(ans, Sum[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/03/29/CSDN%20-%20CSDN40%E9%A2%98%E8%A7%A3/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129837755](https://letmefly.blog.csdn.net/article/details/129837755)