---
title: 3067.在带权树网络中统计可连接服务器对数目
date: 2024-06-04 22:55:48
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, 数组]
---

# 【LetMeFly】3067.在带权树网络中统计可连接服务器对数目：枚举根

力扣题目链接：[https://leetcode.cn/problems/count-pairs-of-connectable-servers-in-a-weighted-tree-network/](https://leetcode.cn/problems/count-pairs-of-connectable-servers-in-a-weighted-tree-network/)

<p>给你一棵无根带权树，树中总共有 <code>n</code>&nbsp;个节点，分别表示 <code>n</code>&nbsp;个服务器，服务器从 <code>0</code>&nbsp;到 <code>n - 1</code>&nbsp;编号。同时给你一个数组&nbsp;<code>edges</code>&nbsp;，其中&nbsp;<code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>, weight<sub>i</sub>]</code>&nbsp;表示节点&nbsp;<code>a<sub>i</sub></code> 和&nbsp;<code>b<sub>i</sub></code>&nbsp;之间有一条双向边，边的权值为&nbsp;<code>weight<sub>i</sub></code>&nbsp;。再给你一个整数&nbsp;<code>signalSpeed</code>&nbsp;。</p>

<p>如果两个服务器 <code>a</code>&nbsp;，<code>b</code>&nbsp;和 <code>c</code>&nbsp;满足以下条件，那么我们称服务器 <code>a</code>&nbsp;和 <code>b</code>&nbsp;是通过服务器 <code>c</code>&nbsp;<strong>可连接的</strong>&nbsp;：</p>

<ul>
	<li><code>a &lt; b</code>&nbsp;，<code>a != c</code> 且&nbsp;<code>b != c</code>&nbsp;。</li>
	<li>从&nbsp;<code>c</code>&nbsp;到&nbsp;<code>a</code>&nbsp;的距离是可以被&nbsp;<code>signalSpeed</code>&nbsp;整除的。</li>
	<li>从&nbsp;<code>c</code>&nbsp;到&nbsp;<code>b</code>&nbsp;的距离是可以被&nbsp;<code>signalSpeed</code>&nbsp;整除的。</li>
	<li>从&nbsp;<code>c</code>&nbsp;到&nbsp;<code>b</code>&nbsp;的路径与从&nbsp;<code>c</code>&nbsp;到&nbsp;<code>a</code>&nbsp;的路径没有任何公共边。</li>
</ul>

<p>请你返回一个长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>count</code>&nbsp;，其中&nbsp;<code>count[i]</code> 表示通过服务器&nbsp;<code>i</code>&nbsp;<strong>可连接</strong>&nbsp;的服务器对的&nbsp;<strong>数目</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/01/21/example22.png" style="width: 438px; height: 243px; padding: 10px; background: #fff; border-radius: .5rem;" /></p>

<pre>
<b>输入：</b>edges = [[0,1,1],[1,2,5],[2,3,13],[3,4,9],[4,5,2]], signalSpeed = 1
<b>输出：</b>[0,4,6,6,4,0]
<b>解释：</b>由于 signalSpeed 等于 1 ，count[c] 等于所有从 c 开始且没有公共边的路径对数目。
在输入图中，count[c] 等于服务器 c 左边服务器数目乘以右边服务器数目。
</pre>

<p><strong class="example">示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/01/21/example11.png" style="width: 495px; height: 484px; padding: 10px; background: #fff; border-radius: .5rem;" /></p>

<pre>
<b>输入：</b>edges = [[0,6,3],[6,5,3],[0,3,1],[3,2,7],[3,1,6],[3,4,2]], signalSpeed = 3
<b>输出：</b>[2,0,0,0,0,0,2]
<b>解释：</b>通过服务器 0 ，有 2 个可连接服务器对(4, 5) 和 (4, 6) 。
通过服务器 6 ，有 2 个可连接服务器对 (4, 5) 和 (0, 5) 。
所有服务器对都必须通过服务器 0 或 6 才可连接，所以其他服务器对应的可连接服务器对数目都为 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 3</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>, weight<sub>i</sub>]</code><!-- notionvc: a2623897-1bb1-4c07-84b6-917ffdcd83ec --></li>
	<li><code>1 &lt;= weight<sub>i</sub> &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= signalSpeed &lt;= 10<sup>6</sup></code></li>
	<li>输入保证&nbsp;<code>edges</code>&nbsp;构成一棵合法的树。</li>
</ul>


    
## 解题方法：枚举根

枚举每个节点作为```c```，以```c```为根，求每个“子树”中有多少节点离```c```的距离是```signalSpeed```的总个数（可以通过DFS求出）。

```
    c
   / \
   *  ***
  **
```

假设所有子树中符合要求的节点数分别为```[4, 5, 8]```，则以```c```为根的总对数为```4 * 5 + 4 * 8 + 5 * 8```（两两相乘）。

+ 时间复杂度$O(n^2)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
private:
    vector<vector<pair<int, int>>> graph;
    int signalSpeed;

    int dfs(int from, int to, int cntDistance) {
        int ans = cntDistance % signalSpeed == 0;
        for (auto [nextNode, nextDistance] : graph[to]) {
            if (nextNode == from) {
                continue;
            }
            ans += dfs(to, nextNode, cntDistance + nextDistance);
        }
        return ans;
    }
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        // init
        graph.resize(edges.size() + 1);
        this->signalSpeed = signalSpeed;
        for (vector<int>& edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        // calculate
        vector<int> ans(edges.size() + 1);
        for (int c = 0; c < ans.size(); c++) {
            vector<int> ab;  // c为根的每个边上有多少ab节点
            for (auto [to, distance] : graph[c]) {
                ab.push_back(dfs(c, to, distance));
            }
            for (int i = 0; i < ab.size(); i++) {
                for (int j = i + 1; j < ab.size(); j++) {
                    ans[c] += ab[i] * ab[j];
                }
            }
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def dfs(self, from_: int, to: int, cntDistance: int) -> int:
        ans = 0 if cntDistance % self.signalSpeed else 1
        for nextNode, nextDistance in self.graph[to]:
            if nextNode == from_:
                continue
            ans += self.dfs(to, nextNode, cntDistance + nextDistance)
        return ans

    def countPairsOfConnectableServers(self, edges: List[List[int]], signalSpeed: int) -> List[int]:
        # init
        self.signalSpeed = signalSpeed
        graph = [[] for _ in range(len(edges) + 1)]
        for x, y, d in edges:
            graph[x].append((y, d))
            graph[y].append((x, d))
        self.graph = graph
        # calculate
        ans = [0] * (len(edges) + 1)
        for c in range(len(ans)):
            ab = []
            for to, distance in graph[c]:
                ab.append(self.dfs(c, to, distance))
            for i in range(len(ab)):
                for j in range(i + 1, len(ab)):
                    ans[c] += ab[i] * ab[j]
        return ans

```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/06/04/LeetCode%203067.%E5%9C%A8%E5%B8%A6%E6%9D%83%E6%A0%91%E7%BD%91%E7%BB%9C%E4%B8%AD%E7%BB%9F%E8%AE%A1%E5%8F%AF%E8%BF%9E%E6%8E%A5%E6%9C%8D%E5%8A%A1%E5%99%A8%E5%AF%B9%E6%95%B0%E7%9B%AE/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/139456087](https://letmefly.blog.csdn.net/article/details/139456087)
