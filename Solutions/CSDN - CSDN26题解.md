---
title: CSDN - CSDN26题解
date: 2023-02-07 22:29:02
tags: [题解, CSDN]
---

[TOC]

>  CSDN编程竞赛报名地址：[https://edu.csdn.net/contest/detail/40](https://edu.csdn.net/contest/detail/40)

## 等差数列

### 题目描述

一个等差数列是一个能表示成a, a+b, a+2b,..., a+nb (n=0,1,2,3,...)的数列。在这个问题中a是一个非负的整数，b是
正整数。 现给出三个整数，分别表示等差数列的第一项a、最后一项、公差b，求该数列的和。


### 解题思路

PS：解题的时候变量名看混了，以下代码中，a代表首项，b代表末项，c代表公差

首先判断首项末项的差值是否为公差的整数倍，如果不是直接返回-1

否则$\frac{末项-首项}{公差}$就是项数，而$\frac{(首项+末项)\times 公差}{2}$即为等差数列的和。

**注意32位整数无法存下1e10的数据**

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long a, c, b;
    cin >> a >> b >> c;
    if ((b - a) % c) {
        puts("-1");
        return 0;
    }
    long long n = (b - a) / c + 1;
    cout << (n * (a + b) / 2) << endl;
    return 0;
}
```

## 阿波罗的魔力宝石

### 题目描述

在希腊神话中，有一个神祗阿波罗。阿波罗拥有一枚能够使人变得更加聪明的神奇宝石。但是，这枚宝石的魔力被封印在
了一个混乱的顺序中，你需要通过排序的方法才能拥有这枚宝石的魔力。 给定一个长度为 N 的整数数组 A，请你将数组
A中的元素进行冒泡排序。（该题目由CSDN用户【[生产队的刘同学](https://blog.csdn.net/weixin_41102528)】提供）

### 解题思路

emmm，真的会有人冒泡排序来超时么？直接Sort以下多好

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    cin >> n;
    vector<ll> v;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    for (auto& t : v) {
        cout << t << endl;
    }
    return 0;
}
```

## 任务分配问题

### 题目描述

小明手头上有n个问题，每个问题都有一个数值，表示这个问题的难度；正好小明团队有n个人，每个人都有一个数值，表
示这个人的能力 现在小明要把这n个问题分配给每个人，要求能力更高的人分配到更高难度的问题

### 解题思路

这道题说白了就是个自定义排序的问题。

能力高的排前面，能力相同的话id小的排前面。然后把题目难度大的排前面，人人和题目一一分配即可。

可以使用结构体来打包记录必要的数据。

### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct PER {
    int nengli;
    int th;
};

bool cmp(PER a, PER b) {
    if (a.nengli != b.nengli) {
        return a.nengli > b.nengli;
    }
    return a.th < b.th;
}

int main() {
    int n;
    cin >> n;
    vector<int> nandu;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        nandu.push_back(t);
    }
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        PER per;
        per.th = i;
        per.nengli = t;
        ren.push_back(per);
    }
    sort(nandu.begin(), nandu.end(), greater<int>());
    sort(ren.begin(), ren.end(), cmp);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int th = ren[i].th;
        int nd = nandu[i];
        ans[th] = nd;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
```

## 单词逆序

### 题目描述

对于一个字符串，请设计一个算法，只在字符串的单词间做逆序调整，也就是说，字符串由一些由空格分隔的部分组成，
你需要将这些部分逆序。 给定一个原字符串A，请返回逆序后的字符串。例，输入”It’s a dog!“输出”dog! a It’s“



### 解题思路

Split函数真香！

### AC代码

```python
a = input()
b = a.split()
b.reverse()
print(" ".join(b))
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/02/07/CSDN%20-%20CSDN26%E9%A2%98%E8%A7%A3/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128927254](https://letmefly.blog.csdn.net/article/details/128927254)