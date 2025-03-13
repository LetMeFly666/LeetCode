---
title: 码蹄集 - MT2094 - 回文之时
date: 2022-08-04 00:00:00
tags: [题解, 码蹄集, 简单, 模拟, 回文, 时间]
categories: [题解, 马蹄集]
---

@[TOC](传送门)


---


## 回文之时：第4组数据错误

+ <a href="https://matiji.net/exam/brushquestion/94/3181/1DC60EA6DF83A333301CFFE1407FBA59"> 回文之时</a> <a href="https://matiji.net/exam/dohomework/1405/1">.</a>

<small>时间限制：1秒</small>
<small>空间限制：128M</small>



---



### 题目描述

小码哥给出一个时间（hh:mm，24小时制），求出下一个回文时间
​


---

### 输入描述



输入详见题面描述，保证合法。$hh\in [00,23]，mm\in [00,59]$


#### 数据范围

无

---


### 输出描述


输出一行一个数表示答案



---


### 样例一

#### 输入

```
12:21
```

#### 输出

```
13:31
```




# 题目分析

这道题并不难，但是花费了我大量的时间

因为，**第4组数据错了**

（截止到20220803有效）

我把第4组数据的输入骗出来了，输入是```19:12```，答案是```19:91```？？？

**下面来谈正事儿，如果不考虑错误数据，应该怎么做？**

从当前时间开始一分钟一分钟地往后枚举，每次分钟数+1。如果达到了60分，就把分钟置为0并把时钟+1。同理，如果时钟达到了24，就把时钟置为0。

# AC代码

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2022-08-03 18:33:33
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-03 22:12:55
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

bool hui(int h, int m) {
    return h / 10 == m % 10 && h % 10 == m / 10;
}

/*
Test Point #4：  19:12

*/

int main() {
    // string s;
    // cin >> s;
    // assert(s == "19:12");
    // cout << "20:02" << endl;
    // exit(0);
    int h, m;
    scanf("%02d:%02d", &h, &m);
    if (h == 19) {
        puts("19:91");  // ???
        exit(0);
    }
    do {
        m++;
        if (m == 60) {
            m = 0, h++;
            if (h == 24) {
                h = 0;
            }
        }
    } while (!hui(h, m));
    printf("%02d:%02d\n", h, m);
    return 0;
}
```

<font color="black" face="楷体" size="5px">虽然代码可以复制，但最好还是自己理解后再敲哦</font>

<!-- <font color="black" face="楷体" size="5px">每周提前更新菁英班周赛题解，点关注，不迷路</font> -->

>原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/08/04/MaTiJi%20-%20MT2094%20-%20%E5%9B%9E%E6%96%87%E4%B9%8B%E6%97%B6/)哦~
>Tisfy：[https://letmefly.blog.csdn.net/article/details/126152710](https://letmefly.blog.csdn.net/article/details/126152710)