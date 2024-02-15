---
title: 码蹄集 - MT2201 - 各位之和
date: 2022-07-21 18:01:12
tags: [题解, 码蹄集, 简单, 模拟, 各位和]
---

@[TOC](传送门)


---


## 各位之和
+ <a href="https://matiji.net/exam/brushquestion/201/3181/1DC60EA6DF83A333301CFFE1407FBA59"> 各位之和</a> <a href="https://matiji.net/exam/dohomework/1284/3">.</a>

<small>时间限制：1秒</small>
<small>空间限制：128M</small>



---



### 题目描述

小码哥超厉害，可以把任意的数通过一次操作变成它的各个数位上的数字之和。

现在小码哥找来了一个数n，请问操作几次之后可以变成一个一位数。
​


---

### 输入描述


输入包含一个整数 $n$

#### 数据范围

$1 <= n <= 10^{100000}$

---


### 输出描述

输出一行一个数表示答案



---


### 样例一

#### 输入

```
991
```

#### 输出

```
3
```



# 题目分析

直接按照要求，进行模拟即可。

其实看到$10^{100000}$不用害怕，直接把输入的数字当作字符串来处理即可。

$10^{100000}$也就是说输入的字符串的长度最大为$100000$，而$100000$个数求和最大不到$10^6$（最多$6$位）

因此很快就会收敛为一位数。完全不用担心时间问题。

## 字符串の各位和

字符串的各位和比较容易，直接遍历字符串，并累加每一位即可。

```cpp
ll getS(string s) {
    ll ans = 0;
    for (char& c : s)
        ans += c - '0';
    return ans;
}
```

## 数字の各位和

数字的各位和也不难。在数字不为零的时候，每次取出数字的个位数，然后让数字除以$10$即可。

```cpp
ll getS(ll n) {
    ll ans = 0;
    while (n) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}
```

# AC代码

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2022-07-21 09:46:18
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-21 09:48:26
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

ll getS(string s) {
    ll ans = 0;
    for (char& c : s)
        ans += c - '0';
    return ans;
}

ll getS(ll n) {
    ll ans = 0;
    while (n) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    if (s.size() == 1) {
        puts("0");
        return 0;
    }
    ll n = getS(s);
    int ans = 1;
    while (true) {
        if (n < 10)
            break;
        ans++;
        n = getS(n);
    }
    cout << ans << endl;
    return 0;
}
```

<font color="black" face="楷体" size="5px">虽然代码可以复制，但最好还是自己理解后再敲哦</font>

<!-- <font color="black" face="楷体" size="5px">每周提前更新菁英班周赛题解，点关注，不迷路</font> -->

>原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/07/21/MaTiJi%20-%20MT2201%20-%20%E5%90%84%E4%BD%8D%E4%B9%8B%E5%92%8C/)哦~
>Tisfy：[https://letmefly.blog.csdn.net/article/details/125918169](https://letmefly.blog.csdn.net/article/details/125918169)