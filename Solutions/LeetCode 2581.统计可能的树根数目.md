---
title: 2581.统计可能的树根数目
date: 2024-02-29 14:48:27
tags: [题解, LeetCode, 困难, 树, 深度优先搜索, DFS, 哈希表, 动态规划, DP, 树形DP]
---

# 【LetMeFly】2581.统计可能的树根数目：换根DP(树形DP)

力扣题目链接：[https://leetcode.cn/problems/count-number-of-possible-root-nodes/](https://leetcode.cn/problems/count-number-of-possible-root-nodes/)

<p>Alice 有一棵 <code>n</code> 个节点的树，节点编号为 <code>0</code> 到 <code>n - 1</code> 。树用一个长度为 <code>n - 1</code> 的二维整数数组 <code>edges</code> 表示，其中 <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> ，表示树中节点 <code>a<sub>i</sub></code> 和 <code>b<sub>i</sub></code> 之间有一条边。</p>

<p>Alice 想要 Bob 找到这棵树的根。她允许 Bob 对这棵树进行若干次 <strong>猜测</strong> 。每一次猜测，Bob 做如下事情：</p>

<ul>
	<li>选择两个 <strong>不相等</strong>&nbsp;的整数&nbsp;<code>u</code> 和&nbsp;<code>v</code>&nbsp;，且树中必须存在边&nbsp;<code>[u, v]</code>&nbsp;。</li>
	<li>Bob 猜测树中&nbsp;<code>u</code>&nbsp;是&nbsp;<code>v</code>&nbsp;的 <strong>父节点</strong>&nbsp;。</li>
</ul>

<p>Bob 的猜测用二维整数数组&nbsp;<code>guesses</code> 表示，其中&nbsp;<code>guesses[j] = [u<sub>j</sub>, v<sub>j</sub>]</code>&nbsp;表示 Bob 猜&nbsp;<code>u<sub>j</sub></code> 是&nbsp;<code>v<sub>j</sub></code>&nbsp;的父节点。</p>

<p>Alice 非常懒，她不想逐个回答&nbsp;Bob 的猜测，只告诉 Bob 这些猜测里面 <strong>至少</strong>&nbsp;有&nbsp;<code>k</code>&nbsp;个猜测的结果为&nbsp;<code>true</code>&nbsp;。</p>

<p>给你二维整数数组 <code>edges</code>&nbsp;，Bob 的所有猜测和整数&nbsp;<code>k</code>&nbsp;，请你返回可能成为树根的&nbsp;<strong>节点数目</strong>&nbsp;。如果没有这样的树，则返回 <code>0</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/12/19/ex-1.png" style="width: 727px; height: 250px;" /></p>

<pre>
<b>输入：</b>edges = [[0,1],[1,2],[1,3],[4,2]], guesses = [[1,3],[0,1],[1,0],[2,4]], k = 3
<b>输出：</b>3
<b>解释：</b>
根为节点 0 ，正确的猜测为 [1,3], [0,1], [2,4]
根为节点 1 ，正确的猜测为 [1,3], [1,0], [2,4]
根为节点 2 ，正确的猜测为 [1,3], [1,0], [2,4]
根为节点 3 ，正确的猜测为 [1,0], [2,4]
根为节点 4 ，正确的猜测为 [1,3], [1,0]
节点 0 ，1 或 2 为根时，可以得到 3 个正确的猜测。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/12/19/ex-2.png" style="width: 600px; height: 303px;" /></p>

<pre>
<b>输入：</b>edges = [[0,1],[1,2],[2,3],[3,4]], guesses = [[1,0],[3,4],[2,1],[3,2]], k = 1
<b>输出：</b>5
<b>解释：</b>
根为节点 0 ，正确的猜测为 [3,4]
根为节点 1 ，正确的猜测为 [1,0], [3,4]
根为节点 2 ，正确的猜测为 [1,0], [2,1], [3,4]
根为节点 3 ，正确的猜测为 [1,0], [2,1], [3,2], [3,4]
根为节点 4 ，正确的猜测为 [1,0], [2,1], [3,2]
任何节点为根，都至少有 1 个正确的猜测。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>edges.length == n - 1</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= guesses.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub>, u<sub>j</sub>, v<sub>j</sub> &lt;= n - 1</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li><code>u<sub>j</sub> != v<sub>j</sub></code></li>
	<li><code>edges</code>&nbsp;表示一棵有效的树。</li>
	<li><code>guesses[j]</code>&nbsp;是树中的一条边。</li>
	<li><code>guesses</code>&nbsp;是唯一的。</li>
	<li><code>0 &lt;= k &lt;= guesses.length</code></li>
</ul>


    
## 方法一：换根DP(树形DP)

首先我们可以把所有的猜想都存入哈希表中，以便对于某条边，能快速知道其是否有被猜过。

> 由于节点范围是$10^5$，因此可以将$父节点 \times 10^6 + 子节点$作为哈希表的键值。（注意可能会超32位整数）

假如只问“```0```”为根的话猜中次数是否$\geq k$，那么我们只需要从$0$开始对树进行深度优先搜索：

> 搜索过程中统计边被猜中的次数（借助哈希表可以在$O(1)$时间内完成一次查询），搜索结束后判断是否$\geq k$。

现在要问“各个节点”为根的话猜中次数。怎么办？在原有结果的基础上再DP一次即可：

> 假设在现有的基础上，```x```是```y```的父节点。此时有```cnt```个猜中的边。若把```y```变成```x```的父节点呢？
>
> ![来自LeetCode官方题解的“树换根图”](https://assets.leetcode.cn/solution-static/2581/2581.png)
>
> 变化的只有```x```与```y```之间的一条边。
>
> 若有猜```(x, y)```，则猜中次数$cnt-1$；若有猜```(y, x)```，则猜中次数$cnt+1$。
>
> DP过程中（其实就是沿边走的过程）不断将父子关系对调，并统计$cnt\geq k$的个数即为答案。

+ 时间复杂度$O(N + M)$，其中$N$是树的节点个数，$M=len(guesses)$
+ 空间复杂度$O(N+M)$

### AC代码

#### C++

```cpp
typedef long long ll;
class Solution {
private:
    int cnt;  // 以0为根时答对的数目
    int ans;
    int k;
    vector<vector<int>> graph;
    unordered_set<ll> se;


    void dfs(int thisNode, int lastNode=-1) {
        for (int nextNode : graph[thisNode]) {
            if (nextNode == lastNode) {
                continue;
            }
            if (se.count((ll)thisNode * 1000000 + nextNode)) {
                cnt++;
            }
            dfs(nextNode, thisNode);
        }
    }

    void change(int thisNode, int lastNode, int cnt) {
        int cnt_bak = cnt;
        for (int nextNode : graph[thisNode]) {
            if (nextNode == lastNode) {
                continue;
            }
            if (se.count((ll)thisNode * 1000000 + nextNode)) {
                cnt--;
            }
            if (se.count((ll)nextNode * 1000000 + thisNode)) {
                cnt++;
            }
            ans += cnt >= k;
            change(nextNode, thisNode, cnt);
            cnt = cnt_bak;
        }
    }
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        graph.resize(edges.size() + 1);
        for (vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        for (vector<int>& guess : guesses) {
            se.insert((ll)guess[0] * 1000000 + guess[1]);
        }
        cnt = 0;
        this->k = k;
        dfs(0);
        ans = cnt >= k;
        change(0, -1, cnt);
        return ans;
    }
};
```

#### Python

```python
from typing import List

class Solution:  # AC,100.00%,92.59%
    def dfs(self, thisNode: int, lastNode: int) -> None:
        for nextNode in self.graph[thisNode]:
            if nextNode == lastNode:
                continue
            if (thisNode * 1000000 + nextNode) in self.se:
                self.cnt += 1
            self.dfs(nextNode, thisNode)
    
    def change(self, thisNode: int, lastNode: int, cnt: int) -> None:
        cnt_bak = cnt
        for nextNode in self.graph[thisNode]:
            if nextNode == lastNode:
                continue
            if (thisNode * 1000000 + nextNode) in self.se:
                cnt -= 1
            if (nextNode * 1000000 + thisNode) in self.se:
                cnt += 1
            self.ans += cnt >= self.k
            self.change(nextNode, thisNode, cnt)
            cnt = cnt_bak            

    def rootCount(self, edges: List[List[int]], guesses: List[List[int]], k: int) -> int:
        self.graph = [[] for _ in range(len(edges) + 1)]
        for x, y in edges:
            self.graph[x].append(y)
            self.graph[y].append(x)
        self.se = set()
        for x, y in guesses:
            self.se.add(x * 1000000 + y)
        self.cnt = 0
        self.dfs(0, -1)
        self.k = k
        self.ans = 1 if self.cnt >= k else 0
        self.change(0, -1, self.cnt)
        return self.ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/02/29/LeetCode%202581.%E7%BB%9F%E8%AE%A1%E5%8F%AF%E8%83%BD%E7%9A%84%E6%A0%91%E6%A0%B9%E6%95%B0%E7%9B%AE/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136372137](https://letmefly.blog.csdn.net/article/details/136372137)
