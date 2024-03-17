---
title: 310.最小高度树
date: 2024-03-17 21:04:25
tags: [题解, LeetCode, 中等, 深度优先搜索, 广度优先搜索, 图, 树, 拓扑排序]
---

# 【LetMeFly】310.最小高度树：拓扑排序秒了

力扣题目链接：[https://leetcode.cn/problems/minimum-height-trees/](https://leetcode.cn/problems/minimum-height-trees/)

<p>树是一个无向图，其中任何两个顶点只通过一条路径连接。 换句话说，一个任何没有简单环路的连通图都是一棵树。</p>

<p>给你一棵包含&nbsp;<code>n</code>&nbsp;个节点的树，标记为&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code> 。给定数字&nbsp;<code>n</code>&nbsp;和一个有 <code>n - 1</code> 条无向边的 <code>edges</code>&nbsp;列表（每一个边都是一对标签），其中 <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> 表示树中节点 <code>a<sub>i</sub></code> 和 <code>b<sub>i</sub></code> 之间存在一条无向边。</p>

<p>可选择树中任何一个节点作为根。当选择节点 <code>x</code> 作为根节点时，设结果树的高度为 <code>h</code> 。在所有可能的树中，具有最小高度的树（即，<code>min(h)</code>）被称为 <strong>最小高度树</strong> 。</p>

<p>请你找到所有的 <strong>最小高度树</strong> 并按 <strong>任意顺序</strong> 返回它们的根节点标签列表。</p>
树的 <strong>高度</strong> 是指根节点和叶子节点之间最长向下路径上边的数量。

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/01/e1.jpg" style="height: 213px; width: 800px;" />
<pre>
<strong>输入：</strong>n = 4, edges = [[1,0],[1,2],[1,3]]
<strong>输出：</strong>[1]
<strong>解释：</strong>如图所示，当根是标签为 1 的节点时，树的高度是 1 ，这是唯一的最小高度树。</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/01/e2.jpg" style="height: 321px; width: 800px;" />
<pre>
<strong>输入：</strong>n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
<strong>输出：</strong>[3,4]
</pre>

<p>&nbsp;</p>

<ul>
</ul>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>所有 <code>(a<sub>i</sub>, b<sub>i</sub>)</code> 互不相同</li>
	<li>给定的输入 <strong>保证</strong> 是一棵树，并且 <strong>不会有重复的边</strong></li>
</ul>


    
## 方法一：拓扑排序

根据图论我们知道，（非空）树的中心有一个或两个。

<details><summary>原因小提示：</summary>

树中最长路的中心有一个或两个。

</details>

那么，我们来个拓扑排序不就好了？

从叶节点开始“扔”，每次扔掉所有的叶节点节点。这样就会出现新的叶节点，再扔掉。......。一层一层，直到某层扔完时剩下一个或两个节点即为答案。

<details><summary>拓扑排序怎么实现：</summary>

使用一个数组```degree```，```degree[i]```表示与节点```i```相邻的边有几条，图论中称其为```度```。

初始时将所有度为```1```的节点入队。

每次将这一层的所有节点出队，对于出队的节点```thisNode```，它的所有相邻的节点的度减一。若度变成了```1```，则入队（新的叶节点get）。

</details>

+ 时间复杂度$O(n)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {  // 这里不要忘了！要不然degree不为1
            return {0};
        }
        vector<int> degree(n);
        vector<vector<int>> graph(n);
        for (vector<int>& v : edges) {
            degree[v[0]]++;
            degree[v[1]]++;
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        int remainNode = n;
        while (remainNode > 2) {
            for (int _ = q.size(); _ > 0; _--) {
                remainNode--;
                int thisNode = q.front();
                q.pop();
                for (int nextNode : graph[thisNode]) {
                    degree[nextNode]--;
                    if (degree[nextNode] == 1) {
                        q.push(nextNode);
                    }
                }
            }
        }
        vector<int> ans = {q.front()};
        q.pop();
        if (q.size()) {
            ans.push_back(q.front());
        }
        return ans;
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n == 1:
            return [0]
        degree = [0] * n
        graph = [[] for _ in range(n)]
        for x, y in edges:
            degree[x] += 1
            degree[y] += 1
            graph[x].append(y)
            graph[y].append(x)
        q = [i for i, d in enumerate(degree) if d == 1]
        remainNode = n
        while remainNode > 2:
            tempQ = []
            for thisNode in q:
                remainNode -= 1
                for nextNode in graph[thisNode]:
                    degree[nextNode] -= 1
                    if degree[nextNode] == 1:
                        tempQ.append(nextNode)
            q = tempQ
        return q
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/03/17/LeetCode%200310.%E6%9C%80%E5%B0%8F%E9%AB%98%E5%BA%A6%E6%A0%91/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136790299](https://letmefly.blog.csdn.net/article/details/136790299)
