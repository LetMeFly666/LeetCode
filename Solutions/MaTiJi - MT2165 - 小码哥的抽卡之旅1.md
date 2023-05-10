---
title: 码蹄集 - MT2165 - 小码哥的抽卡之旅1
date: 2022-08-04 09:28:01
tags: [题解, 码蹄集, 中等, 模拟, 数学, 概率论]
---

@[TOC](传送门)


---


## 小码哥的抽卡之旅1

+ <a href="https://matiji.net/exam/brushquestion/165/3181/1DC60EA6DF83A333301CFFE1407FBA59"> 小码哥的抽卡之旅1 </a> <a href="https://matiji.net/exam/dohomework/1405/3">.</a>

<small>时间限制：1秒</small>
<small>空间限制：128M</small>



---



### 题目描述

小码哥最近迷上了一款抽卡游戏。单抽出金的概率是0.6%，如果前89发都不出金，则90发必出金。小天目前存了一些抽数，想要你帮他算算他出金的概率。
​


---

### 输入描述



一个整数n，表示小码哥的抽数


#### 数据范围

1<=n<=90

---


### 输出描述


一个百分数p，表示出金的概率，保留六位小数(按所给样例)



---


### 样例一

#### 输入

```
1
```

#### 输出

```
0.600000%
```




# 题目分析

<small>好像和原神的抽卡一模一样</small>

+ 抽$0$次中奖的概率是$0$，不中奖的概率是$1$

+ 抽$1$次中奖的概率是$1\times 0.006 = 0.006$，不中的概率是$1 - 0.006 = 0.994$

+ $2$次抽奖机会能中奖的概率是$0.006 + 0.994\times 0.006 = 0.011964$

+ $\cdots$

注意，我描述$2$次抽奖的时候，说的不是```抽2次中奖的概率```。

```两次抽奖机会```不等于```抽2次中奖```

```两次抽奖机会```是指最多抽两次，哪一次中奖都可以

```抽2次中奖```是指前$1$次没中奖，第$2$次中奖了


# AC代码

其实做题的时候我忘特判$90$发必中了，$90$次机会能中奖的概率是$41.819882\%$，但是AC了。**AC代码不等于正确代码**

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2022-08-03 18:30:18
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-03 18:33:03
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
int main() {
    int n;
    double get = 0, notget = 1 - get;
    cin >> n;
    for (int i = 0; i < n; i++) {
        get += notget * 0.006;
        notget = 1 - get;
    }
    printf("%.6lf%\n", get * 100);
    return 0;
}
```

# 正确代码

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2022-08-04 09:43:00
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-04 09:43:02
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
int main() {
    int n;
    double get = 0, notget = 1 - get;
    cin >> n;
    for (int i = 0; i < n; i++) {
        get += notget * 0.006;
        notget = 1 - get;
    }
    printf("%.6lf%\n", n == 90 ? double(1) : get * 100);
    return 0;
}
```

# 方法二

其实也可以不用这么麻烦，直接枚举每一次不中奖的概率，代码更简短

$n$次都不中的概率是$(1-0.006)^n$，因此答案为$1 - (1 - 0.006) ^ n$

```cpp
int n;
cin >> n;
printf("%.6lf%\n", n == 90 ? double(1) : 1 - pow(1 - 0.006, n));
```

<font color="black" face="楷体" size="5px">虽然代码可以复制，但最好还是自己理解后再敲哦</font>

<!-- <font color="black" face="楷体" size="5px">每周提前更新菁英班周赛题解，点关注，不迷路</font> -->

> 原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/08/04/MaTiJi%20-%20MT2165%20-%20%E5%B0%8F%E7%A0%81%E5%93%A5%E7%9A%84%E6%8A%BD%E5%8D%A1%E4%B9%8B%E6%97%851/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126153308](https://letmefly.blog.csdn.net/article/details/126153308)