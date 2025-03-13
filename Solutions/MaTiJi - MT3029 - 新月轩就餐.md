---
title: 码蹄集 - MT3029 - 新月轩就餐
date: 2022-08-04 10:03:10
tags: [题解, 码蹄集, 困难, 最小全部, 优先队列]
categories: [题解, 马蹄集]
---

@[TOC](传送门)


---


## 新月轩就餐

+ <a href="https://matiji.net/exam/brushquestion/29/3846/4C6668FEB8CFD6520DE73B365B31D1A4"> 新月轩就餐 </a> <a href="https://matiji.net/exam/dohomework/1405/5">.</a>

<small>时间限制：1秒</small>
<small>空间限制：128M</small>



---



### 题目描述

新月轩是璃月最高档的餐厅，这里有m位顶级厨师的手艺。但是餐厅有个奇怪的规定，顾客需要给出两个数字a和b，代表品尝菜单的第a到第b道佳肴，每道佳肴的价钱相同。你的小伙伴小码哥现在希望品尝到所有名厨的手艺，但是又想最小化付的钱。

​ 请你为小码哥出谋划策，想想怎样给定a和b能满足他的要求。保证数据有解。

​ 如有多组解，输出a最小的那组。


---

### 输入描述

第一行两个整数 n，m，分别表示佳肴总数和这些佳肴一共由多少厨师所做

第二行包含n个整数ai，代表每道佳肴对应厨师的编号


#### 数据范围

1<=n<=1e6

1<=ai<=m<=2000

---


### 输出描述


一行两个整数 a，b



---


### 样例一

#### 输入

```
15 5
1 5 1 2 5 4 3 4 2 1 2 5 5 2 4
```

#### 输出

```
3 7 
```




# 题目分析

用```vector<int> a[i]```记录大厨```i```做的所有菜分别为第几道

用```int originalData[i];```记录第```i```道菜的大厨是谁

用```int thInA[i];```记录第```i```道菜是这个做菜大厨做的第几道菜

之后，我们可以使用一个“小数先出队”的优先队列，初始时入队每个大厨的第一道菜。

每次出队一道菜（编号记为```x```），由```originalData```可以得到这道菜是大厨```originalData[x]```做的，由```thInA```可以得到这道菜是这个大厨的第```thInA[x]```道菜。

既然这个菜出队了，那么想要品尝所有大厨的菜，就必须把这个大厨的下一道菜入队。

这样，队列中始终有$m$道菜，分别来自$m$个大厨。

每次操作，队列中的最大值（入队时可以记录下来）和队列中的最小值（队首元素）之差就是当前方案的```a b跨度```。

如果当前方案优于历史最佳方案，就更新答案。

直到某个大厨没有下一道菜了，退出循环。


# AC代码

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2022-08-03 21:48:32
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-03 22:44:41
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

vector<int> a[2001];
int originalData[1000010];
int thInA[1000010];
// int loc[2001];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cd(originalData[i]);
        thInA[i] = a[originalData[i]].size();
        a[originalData[i]].push_back(i);
    }
    int ans = INT_MAX;
    int ansA, ansB;
    int maxValInQueue = 0;
    for (int i = 1; i <= m; i++) {
        pq.push(a[i][0]);
        maxValInQueue = max(maxValInQueue, a[i][0]);
    }
    while (true) {
        int minValInQueue = pq.top();
        pq.pop();
        if (maxValInQueue - minValInQueue < ans) {
            ans = maxValInQueue - minValInQueue;
            ansA = minValInQueue, ansB = maxValInQueue;
        }
        int removedWhose = originalData[minValInQueue];
        int thOfHim = thInA[minValInQueue];
        thOfHim++;
        if (thOfHim == a[removedWhose].size()) {
            break;
        }
        int newVal = a[removedWhose][thOfHim];
        maxValInQueue = max(maxValInQueue, newVal);
        pq.push(newVal);
    }
    cout << ansA << " " << ansB << endl;
    return 0;
}
```


<font color="black" face="楷体" size="5px">虽然代码可以复制，但最好还是自己理解后再敲哦</font>

<!-- <font color="black" face="楷体" size="5px">每周提前更新菁英班周赛题解，点关注，不迷路</font> -->

> 原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/08/04/MaTiJi%20-%20MT3029%20-%20%E6%96%B0%E6%9C%88%E8%BD%A9%E5%B0%B1%E9%A4%90/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126154056](https://letmefly.blog.csdn.net/article/details/126154056)