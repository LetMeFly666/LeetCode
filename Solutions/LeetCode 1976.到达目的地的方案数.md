---
title: 1976.到达目的地的方案数
date: 2024-03-05 15:05:03
tags: [题解, LeetCode, 中等, 图, 拓扑排序, 动态规划, 最短路]
categories: [题解, LeetCode]
---

# 【LetMeFly】1976.到达目的地的方案数：单源最短路的Dijkstra算法

力扣题目链接：[https://leetcode.cn/problems/number-of-ways-to-arrive-at-destination/](https://leetcode.cn/problems/number-of-ways-to-arrive-at-destination/)

<p>你在一个城市里，城市由 <code>n</code>&nbsp;个路口组成，路口编号为&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;，某些路口之间有 <strong>双向</strong>&nbsp;道路。输入保证你可以从任意路口出发到达其他任意路口，且任意两个路口之间最多有一条路。</p>

<p>给你一个整数&nbsp;<code>n</code>&nbsp;和二维整数数组&nbsp;<code>roads</code>&nbsp;，其中&nbsp;<code>roads[i] = [u<sub>i</sub>, v<sub>i</sub>, time<sub>i</sub>]</code>&nbsp;表示在路口&nbsp;<code>u<sub>i</sub></code>&nbsp;和&nbsp;<code>v<sub>i</sub></code>&nbsp;之间有一条需要花费&nbsp;<code>time<sub>i</sub></code>&nbsp;时间才能通过的道路。你想知道花费 <strong>最少时间</strong>&nbsp;从路口&nbsp;<code>0</code>&nbsp;出发到达路口&nbsp;<code>n - 1</code>&nbsp;的方案数。</p>

<p>请返回花费 <strong>最少时间</strong>&nbsp;到达目的地的 <strong>路径数目</strong>&nbsp;。由于答案可能很大，将结果对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;后返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/17/graph2.png" style="width: 235px; height: 381px;">
<pre><b>输入：</b>n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
<b>输出：</b>4
<b>解释：</b>从路口 0 出发到路口 6 花费的最少时间是 7 分钟。
四条花费 7 分钟的路径分别为：
- 0 ➝ 6
- 0 ➝ 4 ➝ 6
- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>n = 2, roads = [[1,0,10]]
<b>输出：</b>1
<b>解释：</b>只有一条从路口 0 到路口 1 的路，花费 10 分钟。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 200</code></li>
	<li><code>n - 1 &lt;= roads.length &lt;= n * (n - 1) / 2</code></li>
	<li><code>roads[i].length == 3</code></li>
	<li><code>0 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>1 &lt;= time<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>u<sub>i </sub>!= v<sub>i</sub></code></li>
	<li>任意两个路口之间至多有一条路。</li>
	<li>从任意路口出发，你能够到达其他任意路口。</li>
</ul>


    
## 方法一：单源最短路的Dijkstra算法

“单源最短路”意思是从一个点出发到其他点的最短路径。单源最短路的Dijkstra算法也可以看[我之前做的视频](https://www.bilibili.com/video/BV1Y84y1N7Lm/)。

> 总之Dijkstra算法就是，我们从起点开始:
>
> > 计算所有能*一步到达*的点中，哪个点距离起点最近。
> >
> > 下一步就走到这个点，然后能*一步到达*的点就更新了。
>
> 直到走完所有的点为止。

对于这道题，我们在“往前走”的同时，记录一下走到这一步的“方案数”：

+ 若从当前点走到点```a```的距离 **小于** ```a```原本到起点的距离，则说明发现了*新大“路”*（更近的路）。舍弃掉之前的方案数，将点```a```的方案数**变为**当前点的方案数，并更新最短距离，可以从点```a```开始往深处继续探索。
+ 若从当前点走到点```a```的距离 **等于** ```a```原本到起点的距离，则说明又发现了一条*同为最近路*的路。将点```a```的方案数**加上**当前点的方案数。
+ 否则，已有更短路，不做考虑。

最终返回终点的路径数即为答案。

+ 时间复杂度$O(m\log m)$
+ 空间复杂度$O(n+m)$

### AC代码

#### C++

```cpp
typedef long long ll;
const ll MOD = 1e9 + 7;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n);
        for (vector<int>& road : roads) {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }
        vector<ll> way(n);
        way[0] = 1;
        vector<ll> dis(n, 1e18);
        dis[0] = 0;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        pq.push({0, 0});
        while (pq.size()) {
            auto [thisDistance, thisNode] = pq.top();
            pq.pop();
            if (thisDistance > dis[thisNode]) {  // 有更优解了
                continue;
            }
            for (auto [nextNode, nextDistance] : graph[thisNode]) {
                if (thisDistance + nextDistance < dis[nextNode]) {
                    dis[nextNode] = thisDistance + nextDistance;
                    way[nextNode] = way[thisNode];
                    pq.push({dis[nextNode], nextNode});
                }
                else if (thisDistance + nextDistance == dis[nextNode]) {
                    way[nextNode] = (way[nextNode] + way[thisNode]) % MOD;
                }
            }
        }
        return way.back();
    }
};
```

#### Python

```python
# from typing import List
# import heapq

MOD = int(1e9) + 7

class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        graph = [[] for _ in range(n)]
        for x, y, d in roads:
            graph[x].append((y, d))
            graph[y].append((x, d))
        way = [0] * n
        way[0] = 1
        dis = [int(1e18)] * n
        dis[0] = 0
        pq = [(0, 0)]
        while pq:
            thisDistance, thisNode = heapq.heappop(pq)
            if thisDistance > dis[thisNode]:
                continue
            for nextNode, nextDistance in graph[thisNode]:
                if nextDistance + thisDistance < dis[nextNode]:
                    dis[nextNode] = nextDistance + thisDistance
                    way[nextNode] = way[thisNode]
                    heapq.heappush(pq, (dis[nextNode], nextNode))
                elif nextDistance + thisDistance == dis[nextNode]:
                    way[nextNode] = (way[nextNode] + way[thisNode]) % MOD
        return way[-1]
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/03/05/LeetCode%201976.%E5%88%B0%E8%BE%BE%E7%9B%AE%E7%9A%84%E5%9C%B0%E7%9A%84%E6%96%B9%E6%A1%88%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136481215](https://letmefly.blog.csdn.net/article/details/136481215)
