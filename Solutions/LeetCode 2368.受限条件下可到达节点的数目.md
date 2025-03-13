---
title: 2368.受限条件下可到达节点的数目
date: 2024-03-02 16:24:01
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, DFS, 广度优先搜索, 图, 数组, 哈希表, 哈希, set]
categories: [题解, LeetCode]
---

# 【LetMeFly】2368.受限条件下可到达节点的数目：搜索 + 哈希表

力扣题目链接：[https://leetcode.cn/problems/reachable-nodes-with-restrictions/](https://leetcode.cn/problems/reachable-nodes-with-restrictions/)

<p>现有一棵由 <code>n</code> 个节点组成的无向树，节点编号从 <code>0</code> 到 <code>n - 1</code> ，共有 <code>n - 1</code> 条边。</p>

<p>给你一个二维整数数组 <code>edges</code> ，长度为 <code>n - 1</code> ，其中 <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> 表示树中节点 <code>a<sub>i</sub></code> 和 <code>b<sub>i</sub></code> 之间存在一条边。另给你一个整数数组 <code>restricted</code> 表示 <strong>受限</strong> 节点。</p>

<p>在不访问受限节点的前提下，返回你可以从节点<em> </em><code>0</code><em> </em>到达的 <strong>最多</strong> 节点数目<em>。</em></p>

<p>注意，节点 <code>0</code> <strong>不</strong> 会标记为受限节点。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/06/15/ex1drawio.png" style="width: 402px; height: 322px;">
<pre><strong>输入：</strong>n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], restricted = [4,5]
<strong>输出：</strong>4
<strong>解释：</strong>上图所示正是这棵树。
在不访问受限节点的前提下，只有节点 [0,1,2,3] 可以从节点 0 到达。</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/06/15/ex2drawio.png" style="width: 412px; height: 312px;">
<pre><strong>输入：</strong>n = 7, edges = [[0,1],[0,2],[0,5],[0,4],[3,2],[6,5]], restricted = [4,2,1]
<strong>输出：</strong>3
<strong>解释：</strong>上图所示正是这棵树。
在不访问受限节点的前提下，只有节点 [0,5,6] 可以从节点 0 到达。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li><code>edges</code> 表示一棵有效的树</li>
	<li><code>1 &lt;= restricted.length &lt; n</code></li>
	<li><code>1 &lt;= restricted[i] &lt; n</code></li>
	<li><code>restricted</code> 中的所有值 <strong>互不相同</strong></li>
</ul>


    
## 方法一：深度优先搜索(DFS)

首先开辟一个大小为$n\times 0$的二维数组```graph```，```graph[i]```表示所有与节点```i```相邻的边（遍历```edges```数组即可完成建图）。

接着使用一个哈希表用来记录不可达节点（遍历```restricted```数组可以完成哈希表的初始值）。若一个节点被遍历过后，也可将其标记为不可达。

之后就能从节点```0```开始愉快地搜索了（每次搜索时先将该节点标记并将答案数量加一，再递归所有未被标记过的邻居节点）。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
private:
    int ans;
    unordered_set<int> unachieveable;
    vector<vector<int>> graph;

    void dfs(int n) {
        unachieveable.insert(n);
        ans++;
        for (int next : graph[n]) {
            if (!unachieveable.count(next)) {
                dfs(next);
            }
        }
    }
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        ans = 0;
        graph.resize(n);
        for (vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        for (int t : restricted) {
            unachieveable.insert(t);
        }
        dfs(0);
        return ans;
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def dfs(self, n: int) -> None:
        self.unachieveable.add(n)
        self.ans += 1
        for next in self.graph[n]:
            if next not in self.unachieveable:
                self.dfs(next)
    
    def reachableNodes(self, n: int, edges: List[List[int]], restricted: List[int]) -> int:
        self.ans = 0
        self.graph = [[] for _ in range(n)]
        for x, y in edges:
            self.graph[x].append(y)
            self.graph[y].append(x)
        self.unachieveable = set(restricted)
        self.dfs(0)
        return self.ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/03/02/LeetCode%202368.%E5%8F%97%E9%99%90%E6%9D%A1%E4%BB%B6%E4%B8%8B%E5%8F%AF%E5%88%B0%E8%BE%BE%E8%8A%82%E7%82%B9%E7%9A%84%E6%95%B0%E7%9B%AE/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136418048](https://letmefly.blog.csdn.net/article/details/136418048)
