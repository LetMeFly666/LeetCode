---
title: 2192.有向无环图中一个节点的所有祖先
date: 2024-04-04 15:28:58
tags: [题解, LeetCode, 中等, 深度优先搜索, 广度优先搜索, 图, 拓扑排序]
---

# 【LetMeFly】2192.有向无环图中一个节点的所有祖先：拓扑排序

力扣题目链接：[https://leetcode.cn/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/](https://leetcode.cn/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/)

<p>给你一个正整数&nbsp;<code>n</code>&nbsp;，它表示一个 <strong>有向无环图</strong>&nbsp;中节点的数目，节点编号为&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;（包括两者）。</p>

<p>给你一个二维整数数组&nbsp;<code>edges</code>&nbsp;，其中&nbsp;<code>edges[i] = [from<sub>i</sub>, to<sub>i</sub>]</code>&nbsp;表示图中一条从&nbsp;<code>from<sub>i</sub></code>&nbsp;到&nbsp;<code>to<sub>i</sub></code>&nbsp;的单向边。</p>

<p>请你返回一个数组&nbsp;<code>answer</code>，其中<em>&nbsp;</em><code>answer[i]</code>是第&nbsp;<code>i</code>&nbsp;个节点的所有&nbsp;<strong>祖先</strong>&nbsp;，这些祖先节点&nbsp;<strong>升序</strong>&nbsp;排序。</p>

<p>如果 <code>u</code>&nbsp;通过一系列边，能够到达 <code>v</code>&nbsp;，那么我们称节点 <code>u</code>&nbsp;是节点 <code>v</code>&nbsp;的 <strong>祖先</strong>&nbsp;节点。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/12/12/e1.png" style="width: 322px; height: 265px;"></p>

<pre><b>输入：</b>n = 8, edgeList = [[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]
<b>输出：</b>[[],[],[],[0,1],[0,2],[0,1,3],[0,1,2,3,4],[0,1,2,3]]
<strong>解释：</strong>
上图为输入所对应的图。
- 节点 0 ，1 和 2 没有任何祖先。
- 节点 3 有 2 个祖先 0 和 1 。
- 节点 4 有 2 个祖先 0 和 2 。
- 节点 5 有 3 个祖先 0 ，1 和 3 。
- 节点 6 有 5 个祖先 0 ，1 ，2 ，3 和 4 。
- 节点 7 有 4 个祖先 0 ，1 ，2 和 3 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/12/12/e2.png" style="width: 343px; height: 299px;"></p>

<pre><b>输入：</b>n = 5, edgeList = [[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
<b>输出：</b>[[],[0],[0,1],[0,1,2],[0,1,2,3]]
<strong>解释：</strong>
上图为输入所对应的图。
- 节点 0 没有任何祖先。
- 节点 1 有 1 个祖先 0 。
- 节点 2 有 2 个祖先 0 和 1 。
- 节点 3 有 3 个祖先 0 ，1 和 2 。
- 节点 4 有 4 个祖先 0 ，1 ，2 和 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>0 &lt;= edges.length &lt;= min(2000, n * (n - 1) / 2)</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= from<sub>i</sub>, to<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>from<sub>i</sub> != to<sub>i</sub></code></li>
	<li>图中不会有重边。</li>
	<li>图是 <strong>有向</strong> 且 <strong>无环</strong> 的。</li>
</ul>


    
## 解题方法：拓扑排序

遍历所有边，记录下：每个节点的```入度```（有多少条边指向这个节点）、每个节点都指向哪些节点。

使用一个队列，将所有入度为0的点入队。当队列非空时，不断从队首取出节点。遍历这个节点的所有子节点，子节点入度减一（若减为0则入队），子节点的祖先节点加上这个节点以及这个节点的祖先节点。

最终返回每个节点的祖先节点。（可以使用哈希表来存放一个节点的祖先节点，这样便于在$O(1)$的时间复杂度内完成新祖先节点的插入与去重，最终再转为数组并排序）

+ 时间复杂度$O(n\times len(edges) + n^2\log n)$：拓扑排序$n\times len(edges)$，后序对每个节点的祖先节点排序(最多)都是$n\log n$
+ 空间复杂度$O(n^2)$：等于答案的空间复杂度（我们使用哈希表辅助中间过程的运算消耗空间相同）

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> father(n);
        vector<int> degree(n);
        vector<vector<int>> graph(n);
        for (vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            degree[edge[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (!degree[i]) {
                q.push(i);
            }
        }
        while (q.size()) {
            int thisNode = q.front();
            q.pop();
            for (int nextNode : graph[thisNode]) {
                father[nextNode].insert(thisNode);
                for (int thisFather : father[thisNode]) {
                    father[nextNode].insert(thisFather);
                }
                degree[nextNode]--;
                if (!degree[nextNode]) {
                    q.push(nextNode);
                }
            }
        }
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; i++) {
            for (int t : father[i]) {
                ans[i].push_back(t);
            }
            sort(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List
# from collections import deque


class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        father = [set() for _ in range(n)]
        degree = [0] * n
        graph = [[] for _ in range(n)]
        for x, y in edges:
            degree[y] += 1
            graph[x].append(y)
        q = deque()
        for i in range(n):
            if not degree[i]:
                q.append(i)
        while q:
            thisNode = q.popleft()
            for nextNode in graph[thisNode]:
                father[nextNode].add(thisNode)
                father[nextNode].update(father[thisNode])
                degree[nextNode] -= 1
                if not degree[nextNode]:
                    q.append(nextNode)
        return [sorted(list(i)) for i in father]
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/04/04/LeetCode%202192.%E6%9C%89%E5%90%91%E6%97%A0%E7%8E%AF%E5%9B%BE%E4%B8%AD%E4%B8%80%E4%B8%AA%E8%8A%82%E7%82%B9%E7%9A%84%E6%89%80%E6%9C%89%E7%A5%96%E5%85%88/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/137376368](https://letmefly.blog.csdn.net/article/details/137376368)
