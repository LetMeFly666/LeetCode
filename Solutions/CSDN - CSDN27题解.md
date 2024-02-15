---
title: CSDN - CSDN27题解
date: 2023-02-10 18:29:31
tags: [题解, CSDN]
---

[TOC]

>  CSDN编程竞赛报名地址：[https://edu.csdn.net/contest/detail/41](https://edu.csdn.net/contest/detail/41)

这次题目描述刚开始好像有些问题，之后被修正了

## 幸运数字

### 题目描述

小艺定义一个幸运数字的标准包含3条: 1、仅包含4或7。 2、幸运数字的前半部分数字之和等于后半部分数字之和。 3、
数字的长度是偶数。


### 解题思路

把输入当作字符串来处理即可

1. 判断字符串长度是否为偶数
2. 判断字符串中是否只包含4和7
3. 判断字符串前半部分之和是否等于后半部分之和（其实直接用ASCII码进行计算，不必换算成整数再计算也可，因为前后两半字符串的长度是相同的）

### AC代码

```cpp
#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    if (s.size() % 2) {
        puts("No");
        return 0;
    }
    for (char c : s) {
        if (c != '4' && c != '7') {
            puts("No");
            return 0;
        }
    }
    int cnt = 0;
    for (int i = 0; i < s.size() / 2; i++) {
        cnt += s[i] - '0';
    }
    for (int i = s.size() / 2; i < s.size(); i++) {
        cnt -= s[i] - '0';
    }
    puts(cnt ? "No" : "YES");
    return 0;
}
```

## 投篮

### 题目描述

小明投篮，罚球线投球可得1分，在三分线内投篮得分可以得到2分，在三分线以外的地方投篮得分可以得到3分，连续投
进得分累计，一旦有一个球没投进则得分清零，重新计算。现给出所有得分记录（清零不计入得分），请你计算一下小明
最多连续投进多少个球？

### 解题思路

遍历每次的得分，如果当前得分**不大于**上次得分，则视为“头球中断”

否则视为“连续进球”

统计一下最大的连续进球次数即可

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int ans = 0;
    int thisCnt = 0;
    int lastScore = 0;
    int n;
    cin >> n;
    while (n--) {
        int t;
        cin >> t;
        if (t <= lastScore) {
            lastScore = 0;
            thisCnt = 0;
        }
        thisCnt++;
        ans = max(ans, thisCnt);
        lastScore = t;
    }
    cout << ans << endl;
    return 0;
}
```

## 通货膨胀-x国货币

### 题目描述

X国发行货币最高面额为n。 次高面额为n的因子。 以此类推。 X国最多发行多少种货币。

### 解题思路

只需要按照题目的意思，在n不为质数的时候，不断除以“大于1的最小因子”即可

首先，判断一个数$n$是否为质数，只需要从2枚举到$\sqrt(n)$，看其中某个数能否被$n$整除。如果都不能，则$n$是质数。

否则，我们就找到了$n$的“大于1的最小因子”，让$n$除以这个因子，得到的即为“下一个货币面值”

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    if (n == 1) {
        puts("1");
        return 0;
    }
    int ans = 2;
    while (n > 1) {
        int k = sqrt(n);
        bool has = false;
        for (int i = 2; i <= k; i++) {
            if (n % i == 0) {
                n /= i;
                ans++;
                has = true;
                break;
            }
        }
        if (!has) {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
```

## 最后一位

### 题目描述

小明选择了一个正整数X,然后把它写在黑板上。然后每一天他会擦掉当前数字的最后一位,直到他擦掉所有数位。 在整个过
程中,小明会把所有在黑板上出现过的数字记录下来,然后求出他们的总和sum. 例如X = 509, 在黑板上出现过的数字依次
是509, 50, 5, 他们的和就是564. 小明现在给出一个sum,小明想让你求出一个正整数X经过上述过程的结果是sum.

### 解题思路

509能按照题目描述得到564，但是给你564怎么反推出来509呢？

我们来看一下564的构成。

$564 = 509 + 50 + 5 = (500 + 50 + 5) + (00 + 0) + (9) = 5\times111+0\times11+9\times1$

既然$564 = 5\times 111 + 0\times 11 + 9 \times 1$，那么为什么不反向地求出余数呢？

$564÷111=5\cdots9$

$9÷11=0\cdots9$

$9÷1=9\cdots0$

看到每次计算的**商**了吗？

也就是说，我们用计算出的$564$，每次除以$1111...1$、$111...1$、$...$、$1$，每次的商组合起来就是原数。

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;
    ll k = 111111111111111111;
    ll ans = 0;
    while (k) {
        ll yu = n / k;
        // printf("n = %lld, k = %lld, yu = %lld, ans = %lld\n", n, k, yu, ans); //*********
        ans = ans * 10 + yu;
        n -= yu * k;
        k /= 10;
    }
    cout << ans << endl;
    return 0;
}
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/02/10/CSDN%20-%20CSDN27%E9%A2%98%E8%A7%A3/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128975414](https://letmefly.blog.csdn.net/article/details/128975414)