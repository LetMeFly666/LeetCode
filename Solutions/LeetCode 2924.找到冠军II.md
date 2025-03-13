---
title: 2924.找到冠军 II
date: 2024-04-13 09:34:56
tags: [题解, LeetCode, 中等, 图, 遍历, 拓扑排序, 脑筋急转弯]
categories: [题解, LeetCode]
---

# 【LetMeFly】2924.找到冠军 II：脑筋急转弯——只关心入度

力扣题目链接：[https://leetcode.cn/problems/find-champion-ii/](https://leetcode.cn/problems/find-champion-ii/)

<p>一场比赛中共有 <code>n</code> 支队伍，按从 <code>0</code> 到&nbsp; <code>n - 1</code> 编号。每支队伍也是 <strong>有向无环图（DAG）</strong> 上的一个节点。</p>

<p>给你一个整数 <code>n</code> 和一个下标从 <strong>0</strong> 开始、长度为 <code>m</code> 的二维整数数组 <code>edges</code> 表示这个有向无环图，其中 <code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>]</code> 表示图中存在一条从 <code>u<sub>i</sub></code> 队到 <code>v<sub>i</sub></code> 队的有向边。</p>

<p>从 <code>a</code> 队到 <code>b</code> 队的有向边意味着 <code>a</code> 队比 <code>b</code> 队 <strong>强</strong> ，也就是 <code>b</code> 队比 <code>a</code> 队 <strong>弱</strong> 。</p>

<p>在这场比赛中，如果不存在某支强于 <code>a</code> 队的队伍，则认为 <code>a</code> 队将会是 <strong>冠军</strong> 。</p>

<p>如果这场比赛存在 <strong>唯一</strong> 一个冠军，则返回将会成为冠军的队伍。否则，返回<em> </em><code>-1</code><em> 。</em></p>

<p><strong>注意</strong></p>

<ul>
	<li><strong>环</strong> 是形如 <code>a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub>, a<sub>n+1</sub></code> 的一个序列，且满足：节点 <code>a<sub>1</sub></code> 与节点 <code>a<sub>n+1</sub></code> 是同一个节点；节点 <code>a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub></code> 互不相同；对于范围&nbsp;<code>[1, n]</code> 中的每个 <code>i</code> ，均存在一条从节点 <code>a<sub>i</sub></code> 到节点 <code>a<sub>i+1</sub></code> 的有向边。</li>
	<li><strong>有向无环图</strong> 是不存在任何环的有向图。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img height="300" src="https://assets.leetcode.com/uploads/2023/10/19/graph-3.png" width="300" /></p>

<pre>
<strong>输入：</strong>n = 3, edges = [[0,1],[1,2]]
<strong>输出：</strong>0
<strong>解释：</strong>1 队比 0 队弱。2 队比 1 队弱。所以冠军是 0 队。
</pre>

<p><strong class="example">示例 2：</strong></p>

<p><img height="300" src="https://assets.leetcode.com/uploads/2023/10/19/graph-4.png" width="300" /></p>

<pre>
<strong>输入：</strong>n = 4, edges = [[0,2],[1,3],[1,2]]
<strong>输出：</strong>-1
<strong>解释：</strong>2 队比 0 队和 1 队弱。3 队比 1 队弱。但是 1 队和 0 队之间不存在强弱对比。所以答案是 -1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>m == edges.length</code></li>
	<li><code>0 &lt;= m &lt;= n * (n - 1) / 2</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= edge[i][j] &lt;= n - 1</code></li>
	<li><code>edges[i][0] != edges[i][1]</code></li>
	<li>生成的输入满足：如果 <code>a</code> 队比 <code>b</code> 队强，就不存在 <code>b</code> 队比 <code>a</code> 队强</li>
	<li>生成的输入满足：如果 <code>a</code> 队比 <code>b</code> 队强，<code>b</code> 队比 <code>c</code> 队强，那么 <code>a</code> 队比 <code>c</code> 队强</li>
</ul>


    
## 解题方法：脑筋急转弯——统计入度为0的节点

![脑筋急转弯](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/direct/6fd8ee0451db4cd0815a7f09eca75304.jpeg)

<!-- ![脑筋急转弯](https://pic.leetcode.cn/1712972814-vYpZzf-%E6%97%A0%E6%A0%87%E9%A2%98.jpg) -->

这题和[2923.找到冠军 I](https://blog.letmefly.xyz/2024/04/12/LeetCode%202923.%E6%89%BE%E5%88%B0%E5%86%A0%E5%86%9BI/)的区别有二：输入不同（给定获胜关系的描述方式不同）、不确保只有唯一一个冠军。

那就和上一题的方法一一样，统计“不输于”任何队伍的队伍不就可以了吗？

对于边$edge = \{x, y\}$，说明$y$输于了队伍$x$，因此令$indegree[y] += 1$（图论中称为“入度”）。

处理完所有的边后，统计“入度”为$0$的队伍的个数。若只有一个队伍入度为$0$，则其为唯一的冠军！否则返回```-1```。

+ 时间复杂度$O(n + len(edges))$
+ 空间复杂度$O(n)$

也可以使用布尔类型的$indegree$数组来统计某个队伍是否失败过，也可以使用哈希表更高效地统计有哪些队伍失败过。

### AC代码

#### C++

```cpp
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n);
        for (vector<int>& edge : edges)  {
            indegree[edge[1]]++;
        }
        int cntWinner = 0, winner;
        for (int i = 0; i < n; i++) {
            if (!indegree[i]) {
                cntWinner++;
                winner = i;
            }
        }
        return cntWinner == 1 ? winner : -1;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        indegree = [0] * n
        for x, y in edges:
            indegree[y] += 1
        cntWinner, winner = 0, 0
        for i in range(n):
            if not indegree[i]:
                cntWinner += 1
                winner = i
        return winner if cntWinner == 1 else -1
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/04/13/LeetCode%202924.%E6%89%BE%E5%88%B0%E5%86%A0%E5%86%9BII/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/137707389](https://letmefly.blog.csdn.net/article/details/137707389)
