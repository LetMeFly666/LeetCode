---
title: 2065.最大化一张图中的路径价值
date: 2024-07-01 14:46:01
tags: [题解, LeetCode, 困难, 图, 数组, 回溯, 递归, DFS, 深度优先搜索]
categories: [题解, LeetCode]
---

# 【LetMeFly】2065.最大化一张图中的路径价值：回溯

力扣题目链接：[https://leetcode.cn/problems/maximum-path-quality-of-a-graph/](https://leetcode.cn/problems/maximum-path-quality-of-a-graph/)

<p>给你一张 <strong>无向</strong>&nbsp;图，图中有 <code>n</code>&nbsp;个节点，节点编号从 <code>0</code>&nbsp;到 <code>n - 1</code>&nbsp;（<strong>都包括</strong>）。同时给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>values</code>&nbsp;，其中&nbsp;<code>values[i]</code>&nbsp;是第 <code>i</code>&nbsp;个节点的 <strong>价值</strong>&nbsp;。同时给你一个下标从 <strong>0</strong>&nbsp;开始的二维整数数组&nbsp;<code>edges</code>&nbsp;，其中&nbsp;<code>edges[j] = [u<sub>j</sub>, v<sub>j</sub>, time<sub>j</sub>]</code>&nbsp;表示节点&nbsp;<code>u<sub>j</sub></code> 和&nbsp;<code>v<sub>j</sub></code>&nbsp;之间有一条需要&nbsp;<code>time<sub>j</sub></code>&nbsp;秒才能通过的无向边。最后，给你一个整数&nbsp;<code>maxTime</code>&nbsp;。</p>

<p><strong>合法路径</strong>&nbsp;指的是图中任意一条从节点&nbsp;<code>0</code>&nbsp;开始，最终回到节点 <code>0</code>&nbsp;，且花费的总时间 <strong>不超过</strong>&nbsp;<code>maxTime</code> 秒的一条路径。你可以访问一个节点任意次。一条合法路径的 <b>价值</b>&nbsp;定义为路径中 <strong>不同节点</strong>&nbsp;的价值 <strong>之和</strong>&nbsp;（每个节点的价值 <strong>至多</strong>&nbsp;算入价值总和中一次）。</p>

<p>请你返回一条合法路径的 <strong>最大</strong>&nbsp;价值。</p>

<p><strong>注意：</strong>每个节点 <strong>至多</strong>&nbsp;有 <strong>四条</strong>&nbsp;边与之相连。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/10/19/ex1drawio.png" style="width: 269px; height: 170px;" /></p>

<pre>
<b>输入：</b>values = [0,32,10,43], edges = [[0,1,10],[1,2,15],[0,3,10]], maxTime = 49
<b>输出：</b>75
<strong>解释：</strong>
一条可能的路径为：0 -&gt; 1 -&gt; 0 -&gt; 3 -&gt; 0 。总花费时间为 10 + 10 + 10 + 10 = 40 &lt;= 49 。
访问过的节点为 0 ，1 和 3 ，最大路径价值为 0 + 32 + 43 = 75 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/10/19/ex2drawio.png" style="width: 269px; height: 170px;" /></p>

<pre>
<b>输入：</b>values = [5,10,15,20], edges = [[0,1,10],[1,2,10],[0,3,10]], maxTime = 30
<b>输出：</b>25
<strong>解释：</strong>
一条可能的路径为：0 -&gt; 3 -&gt; 0 。总花费时间为 10 + 10 = 20 &lt;= 30 。
访问过的节点为 0 和 3 ，最大路径价值为 5 + 20 = 25 。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/10/19/ex31drawio.png" style="width: 236px; height: 170px;" /></p>

<pre>
<b>输入：</b>values = [1,2,3,4], edges = [[0,1,10],[1,2,11],[2,3,12],[1,3,13]], maxTime = 50
<b>输出：</b>7
<strong>解释：</strong>
一条可能的路径为：0 -&gt; 1 -&gt; 3 -&gt; 1 -&gt; 0 。总花费时间为 10 + 13 + 13 + 10 = 46 &lt;= 50 。
访问过的节点为 0 ，1 和 3 ，最大路径价值为 1 + 2 + 4 = 7 。</pre>

<p><strong>示例 4：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2021/10/21/ex4drawio.png" style="width: 270px; height: 71px;" /></strong></p>

<pre>
<b>输入：</b>values = [0,1,2], edges = [[1,2,10]], maxTime = 10
<b>输出：</b>0
<b>解释：</b>
唯一一条路径为 0 。总花费时间为 0 。
唯一访问过的节点为 0 ，最大路径价值为 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == values.length</code></li>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>0 &lt;= values[i] &lt;= 10<sup>8</sup></code></li>
	<li><code>0 &lt;= edges.length &lt;= 2000</code></li>
	<li><code>edges[j].length == 3 </code></li>
	<li><code>0 &lt;= u<sub>j </sub>&lt; v<sub>j</sub> &lt;= n - 1</code></li>
	<li><code>10 &lt;= time<sub>j</sub>, maxTime &lt;= 100</code></li>
	<li><code>[u<sub>j</sub>, v<sub>j</sub>]</code>&nbsp;所有节点对 <strong>互不相同</strong>&nbsp;。</li>
	<li>每个节点 <strong>至多有四条&nbsp;</strong>边。</li>
	<li>图可能不连通。</li>
</ul>


    
## 解题方法：回溯

不难发现最大总耗时为100，而单次耗时最少为10。因此最多经过10条边。每个节点最多有4条边相连（说明每走一条边最多有4种选择），因此最多有4^10种行走路线。

写一个函数```dfs(int root, int time, int value)```用来判断“走到root节点总耗时为time且总价值为value”时的结果：

> 如果root为0则立刻更新答案；
>
> 对于所有与root相邻的节点next，如果“当前时间+路径长度”不超过最大耗时，则：
>
> > + 如果走到过next，则递归```dfs(next, time + distance, value)```（无法再次获得价值）
> > + 否则，则将next标记为走到过，然后递归```dfs(next, time + distance, value + values[next])```（无法再次获得价值），递归结束后再将next标记为未走到过（回溯）

+ 时间复杂度$O(m+n+d^k)$，其中$n=len(values)$，$m=len(edges)$，$d=4$，$k=10$。（建立邻接表耗时$O(m+n)$，递归耗时$O(d^k)$）
+ 空间复杂度$O(m+n+k)$。（邻接表消耗空间$O(m+n)$，递归最大深度$O(k)$）

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2024-07-01 14:19:06
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-01 14:32:31
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int ans, maxTime;
    vector<bool> visited;
    vector<int> values;
    vector<vector<pair<int, int>>> graph;  // graph[i]: [<neighbor, distance>, ...]

    void dfs(int root, int time, int value) {
        if (!root) {
            ans = max(ans, value);
        }
        for (auto [next, distance] : graph[root]) {
            if (time + distance > maxTime) {
                continue;
            }
            if (!visited[next]) {
                visited[next] = true;
                dfs(next, time + distance, value + values[next]);
                visited[next] = false;
            }
            else {
                dfs(next, time + distance, value);
            }
        }
    }
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        ans = 0;
        this->maxTime = maxTime;
        visited.resize(values.size(), false);
        this->values = values;
        graph.resize(values.size());
        for (vector<int>& edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        visited[0] = true;  // 别忘了
        dfs(0, 0, values[0]);
        return ans;
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def dfs(self, root, time, value) -> None:
        if not root:
            self.ans = max(self.ans, value)
        for next, distance in self.graph[root]:
            if time + distance > self.maxTime:
                continue
            if self.visited[next]:
                self.dfs(next, time + distance, value)
            else:
                self.visited[next] = True
                self.dfs(next, time + distance, value + self.values[next])
                self.visited[next] = False
    
    def maximalPathQuality(self, values: List[int], edges: List[List[int]], maxTime: int) -> int:
        self.ans = 0
        self.maxTime = maxTime
        self.values = values
        self.graph = [[] for _ in range(len(values))]
        for x, y, d in edges:
            self.graph[x].append((y, d))
            self.graph[y].append((x, d))
        self.visited = [False] * len(values)
        self.visited[0] = True
        self.dfs(0, 0, values[0])
        return self.ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/07/01/LeetCode%202065.%E6%9C%80%E5%A4%A7%E5%8C%96%E4%B8%80%E5%BC%A0%E5%9B%BE%E4%B8%AD%E7%9A%84%E8%B7%AF%E5%BE%84%E4%BB%B7%E5%80%BC/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/140101479](https://letmefly.blog.csdn.net/article/details/140101479)
