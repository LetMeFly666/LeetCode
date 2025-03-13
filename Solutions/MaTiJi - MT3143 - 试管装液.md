---
title: 码蹄集 - MT3143 - 试管装液
date: 2022-08-21 21:22:54
tags: [题解, 码蹄集, 困难, 划分, 生成函数, 组合数, 递归, 记忆化]
categories: [题解, 马蹄集]
---

@[TOC](传送门)


---


## 试管装液
+ <a href="https://matiji.net/exam/brushquestion/143/3846/4C6668FEB8CFD6520DE73B365B31D1A4"> 试管装液</a> <a href="https://matiji.net/exam/dohomework/1500/4">.</a>

<small>时间限制：1秒</small>
<small>空间限制：128M</small>



---



### 题目描述

炼金术士小码哥最近学到了新的炼金方法，将炼金材料制成液料加入试管中再混合进行炼金能提高炼金品质。现在小码哥想要将一批基础的炼金原料全部制成液料存储在试管中。

小码哥现在有n个试管（试管被编号为1，2，···，n），并且她将炼金原料制成液料后一共得到了m单位质量的液料。每个试管最多能装k单位质量的液料。小码哥为了方便，每个试管中只会被装入整数个单位质量的液料，并且所有液料都会被装入试管

小码哥想知道，一共有多少种方案装入液料，方案对1e8+7取模

不同方案的定义为两组不同方案中至少有一个同号试管的液料的质量不同（例如2个试管中1 2跟2 1为不同方案）


---

### 输入描述



第一行一个正整数k。

第二行一个正整数T，表示数据组数

接下来T行，每行两个整数n，m。

#### 数据范围

1≤T≤10000，1≤n，k≤100，0≤m≤n*k

---


### 输出描述


输出T行，每行一个整数，表示对应行的方案数



---


### 样例一

#### 输入

```
9
5
3 12
9 67
5 27
4 1
3 6
```

#### 输出

```
73
315315
4840
4
28
```




# 题目分析

我觉得这道题不简单。

如果数据量再小一些，可以尝试递归。但是这道题递归会超时，记忆化的前提下也只能通过7组。

如果使用动态规划，那么这道题麻烦的一点就是“每根试管是不同的”，也就是说方案```1 2```和方案```2 1```是两种方案。并且每个试管最大容量位```k```。

于是不得不让我们想到**生成函数**。

**首先介绍比较容易理解的递归**，数据量小的时候可以使用：

写一个递归函数```getAns(long long n, long long m)```，返回“n个试管里放m单位体积”的方案数。

递归终止条件为```m = 0```（$n$个试管都空着的方案数为$1$）或```n = 0```（$0$个试管放$m$($m>0$)体积的方案数为$0$）

之后就模拟这$n$根试管的第一根试管盛放的液体量```thisV: 0 -> min(k, m)```，并继续递归```getAns(n - 1, m - thisV)```（剩下的$n-1$根试管盛放$m - thisV$）

```cpp
ll getAns(int n, int m) {  // n个试管里放m体积
    if (m == 0) {
        return 1;
    }
    if (n == 0) {
        return 0;
    }
    ll ans = 0;
    for (int thisV = 0; thisV <= k && thisV <= m; thisV++) {
        ans = (ans + getAns(n - 1, m - thisV)) % MOD;
    }
    return ans;
}
```

接下来进行**记忆化**操作：

使用```unordered_map<int, int>```来记录已经计算过的值。

这就需要把```n```和```m```映射到一个数字中。

因为```m ≤ n * k ≤ 10000```，所以我们可以令```m```乘以```100000```再和```n```相加，这样就能“把$m$和$n$糅合到一个数中”了

糅合函数：

```cpp
inline int two2one(int n, int m) {
    return n * 100000 + m;
}
```

分解函数：

```cpp
inline void one2two(int a, int& n, int& m) {
    m = a % 100000;
    n = a / 100000;
}
```

+ 这里为什么不使用```unordered_map<pair<int, int>, int>```来更方便地存放```n```和```m```？先不说效率问题，如果使用```unordered_map<pair<int, int>, int>```，你就得自定义一个```pair<int, int>```的哈希函数，这其实已经和上述糅合操作差不多了，甚至更麻烦。感兴趣的可以 [点我参考](https://blog.csdn.net/lr_shadow/article/details/115864228)
+ 这里为什么不使用```map<pair<int, int>, int>```来避免自定义哈希函数？因为递归的解法本来就超时，```map```存放的键值是有序的，这也就导致了存取的复杂度增加（unordered_map的O(1)变成了map的O(log n)）

进入函数，如果已经计算过了$getAns(n, m)$，就直接返回```MAP[two2one(n, m)]```

否则进行递归计算，在返回结果之前，把结果存放在map中。

```cpp
unordered_map<int, ll> ma;

inline int two2one(int n, int m) {
    return n * 100000 + m;
}

inline void one2two(int a, int& n, int& m) {
    m = a % 100000;
    n = a / 100000;
}

ll getAns(int n, int m) {  // n个试管里放m体积
    if (m == 0) {
        return 1;
    }
    if (n == 0) {
        return 0;
    }
    int a = two2one(n, m);
    if (ma.count(a)) {
        return ma[a];
    }
    ll ans = 0;
    for (int thisV = 0; thisV <= k && thisV <= m; thisV++) {
        ans = (ans + getAns(n - 1, m - thisV)) % MOD;
    }
    return ma[a] = ans;
}
```

好了，到此为止，我们只需要愉快地调用```getAns```这个函数就可以了

```cpp
int main() {
    cin >> k;
    int N;
    cin >> N;
    while (N--) {
        int n, m;
        scanf("%d%d",&n, &m);
        printf("%lld\n", getAns(n, m));
    }
    return 0;
}
```

**更小的数据时才能使用的代码**：

```cpp
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

const ll MOD = 1e8 + 7;  // ???

int k;

unordered_map<int, ll> ma;

inline int two2one(int n, int m) {
    return n * 100000 + m;
}

inline void one2two(int a, int& n, int& m) {
    m = a % 100000;
    n = a / 100000;
}

ll getAns(int n, int m) {  // n个试管里放m体积
    if (m == 0) {
        return 1;
    }
    if (n == 0) {
        return 0;
    }
    int a = two2one(n, m);
    if (ma.count(a)) {
        return ma[a];
    }
    ll ans = 0;
    for (int thisV = 0; thisV <= k && thisV <= m; thisV++) {
        ans = (ans + getAns(n - 1, m - thisV)) % MOD;
    }
    return ma[a] = ans;
}

int main() {
    cin >> k;
    int N;
    cin >> N;
    while (N--) {
        int n, m;
        scanf("%d%d",&n, &m);
        printf("%lld\n", getAns(n, m));
    }
    return 0;
}
```

**接下来言归正传，使用生成函数正确解决此题**：

<!-- https://www.zhihu.com/question/21342185/answer/95768619 -->

一个试管最多装$k$体积的液体（$x^k$），最少装$0$体积的液体（$x^0 = 1$），因此一个试管可以表示为：$1 + x + x^2 + \cdots + x^k$

所以$m$个试管可表示为：$F(x) = (1 + x + x^2 + \cdots + x^k) ^ m$

因为一共要装$n$体积的液体，所以$F(x)$中$x^n$的系数即为答案。

接下来求$x^n$的系数：

$F(x) = (1 + x + x^2 + \cdots + x^k) ^ m\\\ \ \ \ \ \ \ \ \ \  = (\frac{1 - x^{k + 1}}{1 - x})^m\\\ \ \ \ \ \ \ \ \ \  = (1 - x^{k + 1})^m(1-x)^{-m}\\\ \ \ \ \ \ \ \ \ \  = \sum_{r=0}^{m}C_m^r(-1)^{r}x^{(k+1)r}\sum_{s=0}^{+\infin}C_{m+s-1}^sx^s$

所以$x^n$的系数为：

$\sum_{r=0}^{\lfloor \frac{n}{k + 1}\rfloor}(-1)^rC_m^rC_{m+n-(k+1)r-1}^{n-(k+1)r}$

好了，公式都有了，剩下的就是“C++求组合数的问题了”

同样使用记忆化操作：

```cpp
ll C[20000][10002] = {0};

ll getC(ll n, ll m) {
    if (m == 0 || m == n)
        return 1;
    if (C[n][m] != 0)
        return C[n][m];
    return C[n][m] = ((getC(n - 1, m) + getC(n - 1, m - 1)) % MOD);
}
```

所以主函数为：

```cpp
int main() {
    ll k;
    cin >> k;
    int N;
    cin >> N;
    while (N--) {
        ll n, m;  // n单位的液体，放到m个试管中
        cin >> m >> n;
        ll to = n / (k + 1);
        ll ans = 0;
        for (ll r = 0; r <= to; r++) {
            ll thisVal = r % 2 ? -1 : 1;
            thisVal = (thisVal * getC(m, r)) % MOD;
            thisVal = (thisVal * getC(m + n - (k + 1) * r - 1, n - (k + 1) * r)) % MOD;
            ans = (ans + thisVal + 3 * MOD) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}
```

# AC代码

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2022-08-21 11:14:32
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-21 18:30:30
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

const ll MOD = 1e8 + 7;

ll C[20000][10002] = {0};

ll getC(ll n, ll m) {
    if (m == 0 || m == n)
        return 1;
    if (C[n][m] != 0)
        return C[n][m];
    return C[n][m] = ((getC(n - 1, m) + getC(n - 1, m - 1)) % MOD);
}

int main() {
    ll k;
    cin >> k;
    int N;
    cin >> N;
    while (N--) {
        ll n, m;  // n单位的液体，放到m个试管中
        cin >> m >> n;
        ll to = n / (k + 1);
        ll ans = 0;
        for (ll r = 0; r <= to; r++) {
            ll thisVal = r % 2 ? -1 : 1;
            thisVal = (thisVal * getC(m, r)) % MOD;
            thisVal = (thisVal * getC(m + n - (k + 1) * r - 1, n - (k + 1) * r)) % MOD;
            ans = (ans + thisVal + 3 * MOD) % MOD;  // 这里记得多加几个MOD，否则结果可能是负数
        }
        cout << ans << endl;
    }
    return 0;
}
```

刚开始我一看$10^8+1$以为不是素数，没用卢卡斯定理。提供一种使用卢卡斯定理的解法（From [CSDN@指间理想](https://blog.csdn.net/newbie_dqt)）：

```cpp
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

const int MOD = 1e8 + 7;

ll fact[15000];
ll Pow(ll a, ll b, ll p) {
    ll res = 1;
    while (b) {
        if (b & 1)
            res = (res * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return res;
}

inline ll C(ll m, ll n, ll p) {
    return m < n ? 0 : fact[m] * Pow(fact[n], p - 2, p) % p * Pow(fact[m - n], p - 2, p) % p;
}

inline ll lucas(ll m, ll n, ll p) {
    return n == 0 ? 1 % p : lucas(m / p, n / p, p) * C(m % p, n % p, p) % p;
}

void initFact() {
    fact[0] = 1;
    for (ll i = 1; i < 15000; i++)
        fact[i] = (i * fact[i - 1]) % MOD;
}

int main() {
    ll n, m, k;
    initFact();
    cin >> k;
    int N;
    cin >> N;
    while (N--) {
        cin >> m >> n;
        ll res = 0;
        ll to = n / (k + 1);
        for (ll r = 0; r <= to; r++) {
            ll tp = lucas(m, r, MOD) * lucas(m + n - k * r - r - 1, n - k * r - r, MOD) % MOD;
            if (r % 2 == 0)
                res = (res + tp) % MOD;
            else
                res = (res - tp + MOD * 3) % MOD;
        }
        puts("");
    }
    return 0;
}
```

<font color="black" face="楷体" size="5px">虽然代码可以复制，但最好还是自己理解后再敲哦</font>

<!-- <font color="black" face="楷体" size="5px">每周提前更新菁英班周赛题解，点关注，不迷路</font> -->

>原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/08/21/MaTiJi%20-%20MT3143%20-%20%E8%AF%95%E7%AE%A1%E8%A3%85%E6%B6%B2/)哦~
>Tisfy：[https://letmefly.blog.csdn.net/article/details/126455717](https://letmefly.blog.csdn.net/article/details/126455717)