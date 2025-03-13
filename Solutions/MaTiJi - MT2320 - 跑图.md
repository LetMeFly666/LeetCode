---
title: 码蹄集 - MT2320 - 跑图
date: 2022-09-28 21:12:32
tags: [题解, 码蹄集, 简单, 图]
categories: [题解, 马蹄集]
---

@[TOC](传送门)


---


## 跑图：简单图问题

+ <a href="https://matiji.net/exam/brushquestion/320/3181/1DC60EA6DF83A333301CFFE1407FBA59"> 跑图</a> <a href="https://matiji.net/exam/dohomework/1956/1">.</a>

<small>时间限制：1秒</small>
<small>空间限制：128M</small>



---



### 题目描述

给出一张有向图，你需要返回图中每个节点所连接的最长的边的指向节点和长度

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



输出n行，每行输出2个数为
从i出发的最长的边的指向节点 和 长度
如果该节点没有出边，输出0



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
2 3
4 5
5 2
0
0
```




# 题目分析

这道题就是个简单的图问题，考察点是**图的输入与存储**

我们可以用```vector<pair<int, int>> graph[1010];```来存储图

假如 ```graph[2] = {<1, 3>, <2, 5>}```，那么就说明有两条从节点2出发的边，分别指向了1（长度为3）和2（长度为5）

因此，输入完成后，我们只需要将每个节点的边都按“长度最长优先”的规则排个序，并输出排序后的第一条边即可。

# AC代码

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2022-09-28 20:58:04
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-28 21:02:15
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

typedef pair<int, int> pii;  // <toNode, 长度>

bool cmp(const pii& a, const pii& b) {
    return a.second > b.second;
}

vector<pii> graph[1010];

int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int a, b, l;
        cin >> a >> b >> l;
        graph[a].push_back({b, l});
        // graph[b].push_back({a, l});
    }
    for (int i = 1; i <= n; i++) {
        if (graph[i].size()) {
            sort(graph[i].begin(), graph[i].end(), cmp);
            cout << graph[i][0].first << ' ' << graph[i][0].second << endl;
        }
        else {
            puts("0");
        }
    }
    return 0;
}
```

<font color="black" face="楷体" size="5px">虽然代码可以复制，但最好还是自己理解后再敲哦</font>

<!-- <font color="black" face="楷体" size="5px">每周提前更新菁英班周赛题解，点关注，不迷路</font> -->

>原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/09/28/MaTiJi%20-%20MT2320%20-%20%E8%B7%91%E5%9B%BE/)哦~
>Tisfy：[https://letmefly.blog.csdn.net/article/details/127097261](https://letmefly.blog.csdn.net/article/details/127097261)