---
title: 码蹄集 - MT2005 - 玉璋
date: 2022-08-21 20:55:55
tags: [题解, 码蹄集, 简单, 模拟, 分数]
---

@[TOC](传送门)


---


## 玉璋
+ <a href="https://matiji.net/exam/brushquestion/5/3181/1DC60EA6DF83A333301CFFE1407FBA59"> 玉璋</a> <a href="https://matiji.net/exam/dohomework/1500/1">.</a>

<small>时间限制：1秒</small>
<small>空间限制：128M</small>



---



### 题目描述

山脉中、大地上、磐石间，都遍布着岩之力。能自如驱动这股力量的人却少之又少。

钟离便是这样一位角色。他的玉璋护盾可谓是安如磐石，不动如山。

由于钟离的护盾太强，从来没有被打破，所以需要你计算玉璋护盾的理论值。

钟离的基础生命值为a，各种加持下生命会提高b%，即最大生命值为 a*(1+b%)，玉璋护盾存在一个基础吸收量c，附加吸收量d%的最大生命值，总吸收量为 (c+d%*最大生命值)。

对所有元素的吸收效果存在e%的护盾强效（护盾的强度最后要乘（1+e%））。

保留两位小数


---

### 输入描述

第一行五个正实数a b c d e

#### 数据范围

所有数在double范围内

---


### 输出描述



输出护盾的值



---


### 样例一

#### 输入

```
14488 248 2712 23.0 50.0
```

#### 输出

```
21462.29
```




# 题目分析

这道题就是纯模拟题，按照题目意思计算。

1. 先计算最大生命：a * (1 + b / 100)
2. 再计算总吸收量：c + d / 100 * 最大生命 = c + d / 100 * (a * (1 + b / 100))
3. 最后计算总互盾：(1 + e / 100) * 总吸收量 = (1 + e / 100) * (c + d / 100 * (a * (1 + b / 100)))

# AC代码

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2022-08-21 11:11:27
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-21 11:13:02
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
int main() {
    double a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    double ans = (1 + e / 100) * (c + d / 100 * (a * (1 + b / 100)));
    printf("%.2lf\n", ans);
    return 0;
}
```

<font color="black" face="楷体" size="5px">虽然代码可以复制，但最好还是自己理解后再敲哦</font>

<!-- <font color="black" face="楷体" size="5px">每周提前更新菁英班周赛题解，点关注，不迷路</font> -->

>原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/08/21/MaTiJi%20-%20MT2005%20-%20%E7%8E%89%E7%92%8B/)哦~
>Tisfy：[https://letmefly.blog.csdn.net/article/details/126455355](https://letmefly.blog.csdn.net/article/details/126455355)