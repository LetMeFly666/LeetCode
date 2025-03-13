---
title: 2316.统计无向图中无法互相到达点对数
date: 2023-10-21 15:31:02
tags: [题解, LeetCode, 中等, 深度优先搜索, 广度优先搜索, BFS, 并查集, 图]
categories: [题解, LeetCode]
---

# 【LetMeFly】2316.统计无向图中无法互相到达点对数：广度优先搜索（BFS）

力扣题目链接：[https://leetcode.cn/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/](https://leetcode.cn/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/)

<p>给你一个整数&nbsp;<code>n</code>&nbsp;，表示一张<strong>&nbsp;无向图</strong>&nbsp;中有 <code>n</code>&nbsp;个节点，编号为&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;。同时给你一个二维整数数组&nbsp;<code>edges</code>&nbsp;，其中&nbsp;<code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code>&nbsp;表示节点&nbsp;<code>a<sub>i</sub></code> 和&nbsp;<code>b<sub>i</sub></code>&nbsp;之间有一条&nbsp;<strong>无向</strong>&nbsp;边。</p>

<p>请你返回 <strong>无法互相到达</strong>&nbsp;的不同 <strong>点对数目</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/05/05/tc-3.png" style="width: 267px; height: 169px;"></p>

<pre><b>输入：</b>n = 3, edges = [[0,1],[0,2],[1,2]]
<b>输出：</b>0
<b>解释：</b>所有点都能互相到达，意味着没有点对无法互相到达，所以我们返回 0 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/05/05/tc-2.png" style="width: 295px; height: 269px;"></p>

<pre><b>输入：</b>n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
<b>输出：</b>14
<b>解释：</b>总共有 14 个点对互相无法到达：
[[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]]
所以我们返回 14 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= edges.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>不会有重复边。</li>
</ul>


    
## 方法一：广度优先搜索BFS

这道题的关键就是统计出每个子图的大小。假设原图是由大小为```a```、```b```、```c```的三个子图构成的，那么答案$ans = a\times(b + c) + b\times(a+c)+c\times(a+b) = a\times (n-a)+b\times(n-b)+c\times(n-c)$。

怎么统计出每个子图有多少个节点呢？广搜一遍就行了。使用```visited```数组来记录哪个节点被遍历过，从$0$到$n-1$枚举，遇到没遍历过的节点就开始广搜，统计这个子图的节点个数并标记处理过的节点。

+ 时间复杂度$O(n + len(edges))$
+ 空间复杂度$O(n + len(edges))$

### AC代码

#### C++

```cpp
typedef long long ll;
class Solution {
public:
    ll countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& v : edges) {
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        vector<ll> sizes;
        vector<bool> visited(n);
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }
            int cntNode = 0;
            visited[i] = true;
            queue<int> q;
            q.push(i);
            while (q.size()) {
                int thisNode = q.front();
                cntNode++;
                q.pop();
                for (int t : graph[thisNode]) {
                    if (!visited[t]) {
                        visited[t] = true;
                        q.push(t);
                    }
                }
            }
            sizes.push_back(cntNode);
        }
        ll ans = 0;
        for (ll t : sizes) {
            ans += t * (n - t);
        }
        return ans / 2;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        graph = [[] for _ in range(n)]
        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)
        visited = [False] * n
        sizes = []
        for i in range(n):
            if visited[i]:
                continue
            cntNode = 0
            visited[i] = True
            q = [i]
            while q:
                thisNode = q.pop()
                cntNode += 1
                for t in graph[thisNode]:
                    if not visited[t]:
                        visited[t] = True
                        q.append(t)
            sizes.append(cntNode)
        ans = 0
        for t in sizes:
            ans += t * (n - t)
        return ans // 2

```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/10/21/LeetCode%202316.%E7%BB%9F%E8%AE%A1%E6%97%A0%E5%90%91%E5%9B%BE%E4%B8%AD%E6%97%A0%E6%B3%95%E4%BA%92%E7%9B%B8%E5%88%B0%E8%BE%BE%E7%82%B9%E5%AF%B9%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/133962709](https://letmefly.blog.csdn.net/article/details/133962709)
