---
title: 码蹄集 - MT3251 - 多重回文
date: 2022-08-22 09:34:50
tags: [题解, 码蹄集, 中等, 思维]
categories: [题解, 马蹄集]
---

@[TOC](传送门)


---


## 多重回文：我觉得这道题“子串”不合适

+ <a href="https://matiji.net/exam/brushquestion/251/3846/4C6668FEB8CFD6520DE73B365B31D1A4"> 多重回文</a> <a href="https://matiji.net/exam/dohomework/1500/6">.</a>

<small>时间限制：1秒</small>
<small>空间限制：128M</small>



---



### 题目描述

小码哥最近在研究字符串，如果一个字符串可以被划分为同时满足以下条件的若干个连续的字串，他就称该串为“多重回文串”：

1.每个字符都被划分进恰好一个子串中
2.每个子串都是长度不小于 22 的回文串

现在给出一个字符串 ss，请问能否通过对 ss 中的字符重新排列，使其成为一个“多重回文串”？

---

### 输入描述

输入一行，一个字符串 $s$，满足 $|s|\in[1,2\times 10^5]$，保证所有字符均为小写字母。

#### 数据范围

无



---


### 输出描述


输出一行，YES 或 NO。



---


### 样例一

#### 输入

```
aeoooamlml
```

#### 输出

```
YES
```

样例中的字符串可以重新排列为 aoooa mem ll，满足“多重回文串”的定义。


# 题目分析

“子串”应该是连续的，并且顺序也不能改变。

这道题字母就完全重组了，只要求每个字母恰好使用一次。

既然题目不要求顺序，那么就好说了，直接所有的字母拿出来，想怎么用就怎么用。

如果要组成回文串，那么前后必须对称。

相同的字母好处理，直接自己就能前后对称。

但是“落单”的字母就需要被“相同”的字母前后夹着（因为题目要求回文串的长度至少为$2$）

因此，问题就转化为了：是否有足够的“相同字母对”，能把“落单的字母”夹在中间。

只需要遍历一遍字符串，统计每个字母出现的次数。

之后遍历$26$个字母，把能成对的全部成对，落单的单着。

然后比较“成对”的对数和“落单”的单数哪个大 就可以了。

# AC代码

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2022-08-21 13:11:13
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-21 13:42:28
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

int bin[26] = {0};

int main() {
    string s;
    cin >> s;
    for (char& c : s) {  // 遍历字符串统计每个字母出现的次数
        bin[c - 'a']++;
    }
    int cntOdd = 0, cntEven = 0;
    for (int i = 0; i < 26; i++) {  // 遍历26个字母，统计“成对”、“落单”的字母(对)的个数
        if (bin[i]) {
            if (bin[i] % 2) {  // 这个字母总共出现了奇数次，有一个落单的前提下其他的字母都能成对
                bin[i]--;
                cntOdd++;
            }
            cntEven += bin[i] / 2;  // 两个字母是一对
        }
    }
    puts(cntEven >= cntOdd ? "YES" : "NO");  // 成对的夹着落单的
    return 0;
}
```

<font color="black" face="楷体" size="5px">虽然代码可以复制，但最好还是自己理解后再敲哦</font>

<!-- <font color="black" face="楷体" size="5px">每周提前更新菁英班周赛题解，点关注，不迷路</font> -->

>原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/08/22/MaTiJi%20-%20MT3251%20-%20%E5%A4%9A%E9%87%8D%E5%9B%9E%E6%96%87/)哦~
>Tisfy：[https://letmefly.blog.csdn.net/article/details/126459839](https://letmefly.blog.csdn.net/article/details/126459839)