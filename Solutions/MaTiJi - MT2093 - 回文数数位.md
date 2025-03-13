---
title: 码蹄集 - MT2093 - 回文数数位
date: 2022-07-21 12:12:06
tags: [题解, 码蹄集, 简单, 模拟, 回文, 各位和]
categories: [题解, 马蹄集]
---

@[TOC](传送门)


---


## 回文数数位
+ <a href="https://matiji.net/exam/brushquestion/93/3181/1DC60EA6DF83A333301CFFE1407FBA59"> 回文数数位</a> <a href="https://matiji.net/exam/dohomework/1284/1">.</a>

<small>时间限制：1秒</small>
<small>空间限制：128M</small>



---



### 题目描述

给出一个非负整数，如果他是回文数，输出他的各位和，否则输出impossible
​


---

### 输入描述



一个非负整数

#### 数据范围

数据范围

保证所有数在1000000以内

---


### 输出描述


若是回文数，则输出各位和，否则输出impossible



---


### 样例一

#### 输入

```
12321
```

#### 输出

```
9
```




# 题目分析

这道题直接模拟即可。

为了方便处理，我们可以把输入视为字符串。那么，只要掌握以下两点：

1. 如何判断一个字符串是否为回文数
2. 如何将数字字符串的每一位求和

## 1. 如何判断一个字符串是否为回文数

很简单，**回文串**满足第$i$个字符和倒数第$i$个字符相同（$1\leq i\leq 回文串.size()$）

那么，我们从前往后遍历回文串，发现不同时直接返回```false```即可。

其实只需要遍历到$\lfloor \frac{字符串.size()}{2}\rfloor$即可。（如果不理解遍历到字符串末尾也可以）

```cpp
bool HuiWen(string s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1])
            return false;
    }
    return true;
}
```

## 2. 如何将数字字符串的每一位求和

这就很简单了，直接遍历字符串并累加即可

```cpp
int cnt = 0;
for (char& c : s) {
    cnt += c - '0';
}
cout << cnt << endl;
```

# AC代码

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2022-07-21 09:43:27
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-21 09:44:32
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

bool HuiWen(string s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1])
            return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    if (HuiWen(s)) {
        int cnt = 0;
        for (char& c : s) {
            cnt += c - '0';
        }
        cout << cnt << endl;
    }
    else
        puts("impossible");
    return 0;
}
```

<font color="black" face="楷体" size="5px">虽然代码可以复制，但最好还是自己理解后再敲哦</font>

<!-- <font color="black" face="楷体" size="5px">每周提前更新菁英班周赛题解，点关注，不迷路</font> -->

>原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/07/21/MaTiJi%20-%20MT2093%20-%20%E5%9B%9E%E6%96%87%E6%95%B0%E6%95%B0%E4%BD%8D/)哦~
>Tisfy：[https://letmefly.blog.csdn.net/article/details/125909744](https://letmefly.blog.csdn.net/article/details/125909744)