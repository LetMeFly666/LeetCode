---
title: 码蹄集 - MT2322 - 还是跑图
date: 2022-09-28 21:22:06
tags: [题解, 码蹄集, 简单, 图]
---

@[TOC](传送门)


---


## 还是跑图：还是简单图问题

+ <a href="https://matiji.net/exam/brushquestion/322/3181/1DC60EA6DF83A333301CFFE1407FBA59"> 还是跑图</a> <a href="https://matiji.net/exam/dohomework/1956/2">.</a>

<small>时间限制：1秒</small>
<small>空间限制：128M</small>



---



### 题目描述

给出一张有向图，你需要返回

图中出边最多的节点，如果有多个出边最多的节点，输出编号最小的

---

### 输入描述

第一行n,m，表示有n个节点，m条边
第二行开始m行
每行有三个数x y z,表示有一条从x到y的边,长度为z

#### 数据范围

1<=n<=1000,1<=m<=100000
1<=x,y<=n, x≠y
1<=z<=m
可能有重边，每条边长度不同



---


### 输出描述



输出1行，为出边最多的节点
接下来若干行，每行输出该节点的边的去向节点和边长，按去向节点编号从小到大输出，如有重边按边长从小到大输出



---


### 样例一

#### 输入

```
5 5
1 2 3
2 3 4
2 4 5
3 1 1
3 5 2
```

#### 输出

```
2
3 4
4 5
```




# 题目分析

这道题和[2320-跑图](https://leetcode.letmefly.xyz/2022/09/28/MaTiJi%20-%20MT2320%20-%20%E8%B7%91%E5%9B%BE/)差不多

我们仍然可以用```vector<pair<int, int>> graph[1010];```来存储图

具体方法可参考：[https://leetcode.letmefly.xyz/2022/09/28/MaTiJi - MT2320 - 跑图/](https://leetcode.letmefly.xyz/2022/09/28/MaTiJi%20-%20MT2320%20-%20%E8%B7%91%E5%9B%BE/)

因此，输入完成后，先统计一遍“最大出度”为多少，并统计出“出度为最大出度”且“编号尽可能小”的节点的编号。

然后输出这个节点的出度，对这个节点出发的所有边，按照“指向编号尽可能小，长度尽可能小”的顺序排序并输出即可。

# AC代码

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2022-09-28 21:03:17
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-28 21:05:53
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

typedef pair<int, int> pii;  // <to, l>

// bool cmp(const pii& a, const pii& b) {
//     if (a.first == b.first) {
//         return a.second < b.second;
//     }
//     return a.first < b.first;
// }

vector<pii> graph[1010];

int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int a, b, l;
        cin >> a >> b >> l;
        graph[a].push_back({b, l});
    }
    int M = 0;
    int maxOf;
    for (int i = 1; i <= n; i++) {
        if (graph[i].size() > M) {
            M = graph[i].size();
            maxOf = i;
        }
    }
    cout << maxOf << endl;
    sort(graph[maxOf].begin(), graph[maxOf].end());
    for (auto[a, b] : graph[maxOf]) {
        cout << a << ' ' << b << endl;
    }
    return 0;
}
```

<font color="black" face="楷体" size="5px">虽然代码可以复制，但最好还是自己理解后再敲哦</font>

<!-- <font color="black" face="楷体" size="5px">每周提前更新菁英班周赛题解，点关注，不迷路</font> -->

>原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/09/28/MaTiJi%20-%20MT2322%20-%20%E8%BF%98%E6%98%AF%E8%B7%91%E5%9B%BE/)哦~
>Tisfy：[https://letmefly.blog.csdn.net/article/details/127097400](https://letmefly.blog.csdn.net/article/details/127097400)