---
title: 2477.到达首都的最少油耗
date: 2023-12-05 19:44:50
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, DFS, 广度优先搜索, 图]
categories: [题解, LeetCode]
---

# 【LetMeFly】2477.到达首都的最少油耗：深度优先搜索(DFS)

力扣题目链接：[https://leetcode.cn/problems/minimum-fuel-cost-to-report-to-the-capital/](https://leetcode.cn/problems/minimum-fuel-cost-to-report-to-the-capital/)

<p>给你一棵 <code>n</code>&nbsp;个节点的树（一个无向、连通、无环图），每个节点表示一个城市，编号从&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;，且恰好有&nbsp;<code>n - 1</code>&nbsp;条路。<code>0</code>&nbsp;是首都。给你一个二维整数数组&nbsp;<code>roads</code>&nbsp;，其中&nbsp;<code>roads[i] = [a<sub>i</sub>, b<sub>i</sub>]</code>&nbsp;，表示城市&nbsp;<code>a<sub>i</sub></code> 和&nbsp;<code>b<sub>i</sub></code>&nbsp;之间有一条&nbsp;<strong>双向路</strong>&nbsp;。</p>

<p>每个城市里有一个代表，他们都要去首都参加一个会议。</p>

<p>每座城市里有一辆车。给你一个整数&nbsp;<code>seats</code>&nbsp;表示每辆车里面座位的数目。</p>

<p>城市里的代表可以选择乘坐所在城市的车，或者乘坐其他城市的车。相邻城市之间一辆车的油耗是一升汽油。</p>

<p>请你返回到达首都最少需要多少升汽油。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/09/22/a4c380025e3ff0c379525e96a7d63a3.png" style="width: 303px; height: 332px;"></p>

<pre><b>输入：</b>roads = [[0,1],[0,2],[0,3]], seats = 5
<b>输出：</b>3
<b>解释：</b>
- 代表 1 直接到达首都，消耗 1 升汽油。
- 代表 2 直接到达首都，消耗 1 升汽油。
- 代表 3 直接到达首都，消耗 1 升汽油。
最少消耗 3 升汽油。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/11/16/2.png" style="width: 274px; height: 340px;"></p>

<pre><b>输入：</b>roads = [[3,1],[3,2],[1,0],[0,4],[0,5],[4,6]], seats = 2
<b>输出：</b>7
<b>解释：</b>
- 代表 2 到达城市 3 ，消耗 1 升汽油。
- 代表 2 和代表 3 一起到达城市 1 ，消耗 1 升汽油。
- 代表 2 和代表 3 一起到达首都，消耗 1 升汽油。
- 代表 1 直接到达首都，消耗 1 升汽油。
- 代表 5 直接到达首都，消耗 1 升汽油。
- 代表 6 到达城市 4 ，消耗 1 升汽油。
- 代表 4 和代表 6 一起到达首都，消耗 1 升汽油。
最少消耗 7 升汽油。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/09/27/efcf7f7be6830b8763639cfd01b690a.png" style="width: 108px; height: 86px;"></p>

<pre><b>输入：</b>roads = [], seats = 1
<b>输出：</b>0
<b>解释：</b>没有代表需要从别的城市到达首都。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>roads.length == n - 1</code></li>
	<li><code>roads[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li><code>roads</code>&nbsp;表示一棵合法的树。</li>
	<li><code>1 &lt;= seats &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 方法一：深度优先搜索(DFS)

车是可以随时“丢弃”与“重选”的，因此我们只需要知道“每一步”有多少人即可。

从“根节点”```0```开始深搜，深搜过程中，对于节点```node```：

> 假设```node```有数个子节点，各个子节点为根的子树的大小分别为$a_1$，$a_2$，...，
>
> 那么从这些节点到达节点```node```分别需要耗油$\lceil\frac{a_1}{seats}\rceil$，$\lceil\frac{a_2}{seats}\rceil$，...
>
> 将这些耗油累加到答案中，同时也得到了以节点```node```为根的子树的大小。

上述过程中，所有人一同往根节点的方向走一步，就将耗油累加到了答案中，因此最终返回答案即可。

+ 时间复杂度$O(N^2)$
+ 空间复杂度$O(N\log N)$

### AC代码

#### C++

```cpp
class Solution {
private:
    long long ans;
    vector<vector<int>> graph;
    vector<bool> visited;

    long long dfs(int node, int seats){
        visited[node] = true;
        int cnt = 1;
        for (int toNode  : graph[node]) {
            if (!visited[toNode]) {
                long long peopleFromThatNode = dfs(toNode, seats);
                cnt += peopleFromThatNode;
                ans += (peopleFromThatNode + seats - 1) / seats;
            }
        }
        return cnt;
    }

public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        ans = 0;
        graph = vector<vector<int>>(roads.size() + 1);
        visited = vector<bool>(roads.size() + 1);
        for (auto& road : roads) {
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
        }
        dfs(0, seats);
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def dfs(self, node: int) -> int:
        self.visited[node] = True
        cnt = 1
        for nextNode in self.graph[node]:
            if not self.visited[nextNode]:
                peopleFromThatNode = self.dfs(nextNode)
                cnt += peopleFromThatNode
                self.ans += (peopleFromThatNode + self.seats - 1) // self.seats
        return cnt
    
    def minimumFuelCost(self, roads: List[List[int]], seats: int) -> int:
        self.ans = 0
        self.graph = [[] for _ in range(len(roads) + 1)]
        for from_, to in roads:
            self.graph[from_].append(to)
            self.graph[to].append(from_)
        self.visited = [False] * (len(roads) + 1)
        self.seats = seats
        self.dfs(0)
        return self.ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/12/05/LeetCode%202477.%E5%88%B0%E8%BE%BE%E9%A6%96%E9%83%BD%E7%9A%84%E6%9C%80%E5%B0%91%E6%B2%B9%E8%80%97/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/134816086](https://letmefly.blog.csdn.net/article/details/134816086)
