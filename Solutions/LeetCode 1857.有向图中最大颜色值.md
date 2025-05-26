---
title: 1857.有向图中最大颜色值：拓扑排序+动态规划
date: 2025-05-27 00:04:19
tags: [题解, LeetCode, 困难, 图, 拓扑排序, 哈希表, 动态规划, DP, 计数]
categories: [题解, LeetCode]
---

# 【LetMeFly】1857.有向图中最大颜色值：拓扑排序+动态规划

力扣题目链接：[https://leetcode.cn/problems/largest-color-value-in-a-directed-graph/](https://leetcode.cn/problems/largest-color-value-in-a-directed-graph/)

<p>给你一个 <strong>有向图</strong> ，它含有 <code>n</code> 个节点和 <code>m</code> 条边。节点编号从 <code>0</code> 到 <code>n - 1</code> 。</p>

<p>给你一个字符串 <code>colors</code> ，其中 <code>colors[i]</code> 是小写英文字母，表示图中第 <code>i</code> 个节点的 <b>颜色</b> （下标从 <strong>0</strong> 开始）。同时给你一个二维数组 <code>edges</code> ，其中 <code>edges[j] = [a<sub>j</sub>, b<sub>j</sub>]</code> 表示从节点 <code>a<sub>j</sub></code> 到节点 <code>b<sub>j</sub></code><sub> </sub>有一条 <strong>有向边</strong> 。</p>

<p>图中一条有效 <strong>路径</strong> 是一个点序列 <code>x<sub>1</sub> -&gt; x<sub>2</sub> -&gt; x<sub>3</sub> -&gt; ... -&gt; x<sub>k</sub></code> ，对于所有 <code>1 &lt;= i &lt; k</code> ，从 <code>x<sub>i</sub></code> 到 <code>x<sub>i+1</sub></code> 在图中有一条有向边。路径的 <strong>颜色值</strong> 是路径中 <strong>出现次数最多</strong> 颜色的节点数目。</p>

<p>请你返回给定图中有效路径里面的 <strong>最大颜色值</strong><strong> 。</strong>如果图中含有环，请返回 <code>-1</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/04/21/leet1.png" style="width: 400px; height: 182px;"></p>

<pre><b>输入：</b>colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
<b>输出：</b>3
<b>解释：</b>路径 0 -&gt; 2 -&gt; 3 -&gt; 4 含有 3 个颜色为 <code>"a" 的节点（上图中的红色节点）。</code>
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/04/21/leet2.png" style="width: 85px; height: 85px;"></p>

<pre><b>输入：</b>colors = "a", edges = [[0,0]]
<b>输出：</b>-1
<b>解释：</b>从 0 到 0 有一个环。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == colors.length</code></li>
	<li><code>m == edges.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= m &lt;= 10<sup>5</sup></code></li>
	<li><code>colors</code> 只含有小写英文字母。</li>
	<li><code>0 &lt;= a<sub>j</sub>, b<sub>j</sub> &lt; n</code></li>
</ul>


    
## 解题方法：拓扑排序+动态规划

记录每个节点的入度(入度为指向这个节点的边的个数)，记录每个节点指向哪些节点。

创建一个队列，一旦有节点入度为0则入队（拓扑排序）。

创建一个DP数组，DP[i][j]表示从路径起点到节点i颜色j的最大个数。

队列非空时：

> 每次从队列中取出一个节点(thisNode)，DP数组中这个节点自身的颜色值加一。
>
> 遍历这个节点指向的所有节点(nextNode)，被指向节点入度减一，更新被指向节点的每种颜色最大值dp[nextNode][j]为max(dp[nextNode][j], dp[thisNode][j])。

最终，若仍有节点入度非零，则代表有环，返回-1；否则，返回dp[i][j]中最大的一个。

+ 时间复杂度$O((m+n)C)$，其中$C=26$
+ 空间复杂度$O(nC+m)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-05-26 10:24:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-26 23:26:40
 */
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        vector<vector<int>> out(colors.size());
        vector<int> indegree(colors.size());
        for (vector<int>& edge: edges) {
            out[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < colors.size(); i++) {
            if (!indegree[i]) {
                q.push(i);
            }
        }
        vector<array<int, 26>> dp(colors.size());
        int ans = 0;
        while (q.size()) {
            int thisNode = q.front();
            q.pop();
            ans = max(ans, ++dp[thisNode][colors[thisNode] - 'a']);
            for (int nextNode : out[thisNode]) {
                indegree[nextNode]--;
                if (!indegree[nextNode]) {
                    q.push(nextNode);
                }
                for (int i = 0; i < 26; i++) {
                    dp[nextNode][i] = max(dp[nextNode][i], dp[thisNode][i]);
                }
            }
        }
        for (int i = 0; i < colors.size(); i++) {
            if (indegree[i]) {
                return -1;
            }
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-05-26 22:02:44
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-26 23:34:26
'''
from typing import List

class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        out = [[] for _ in range(len(colors))]
        indegree = [0] * len(colors)
        for x, y in edges:
            out[x].append(y)
            indegree[y] += 1
        q = []
        for i in range(len(colors)):
            if indegree[i] == 0:
                q.append(i)
        dp = [[0] * 26 for _ in range(len(colors))]
        ans = 0
        while q:
            thisNode = q.pop()
            dp[thisNode][ord(colors[thisNode]) - ord('a')] += 1
            ans = max(ans, dp[thisNode][ord(colors[thisNode]) - ord('a')])
            for nextNode in out[thisNode]:
                indegree[nextNode] -= 1
                if not indegree[nextNode]:
                    q.append(nextNode)
                for i in range(26):
                    dp[nextNode][i] = max(dp[nextNode][i], dp[thisNode][i])
        if any(indegree):
            return -1
        return ans

```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-05-26 22:02:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-27 00:02:40
 */
import java.util.List;
import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;

class Solution {
    public int largestPathValue(String colors, int[][] edges) {
        List<Integer>[] out = new ArrayList[colors.length()];
        for (int i = 0; i < colors.length(); i++) {
            out[i] = new ArrayList<>();
        }
        int[] indegree = new int[colors.length()];
        for (int[] edge : edges) {
            out[edge[0]].add(edge[1]);
            indegree[edge[1]]++;
        }
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < colors.length(); i++) {
            if (indegree[i] == 0) {
                q.offer(i);
            }
        }
        int[][]dp = new int[colors.length()][26];
        int ans = 0;
        while (!q.isEmpty()) {
            int thisNode = q.poll();
            ans = Math.max(ans, ++dp[thisNode][colors.charAt(thisNode) - 'a']);
            for (int nextNode : out[thisNode]) {
                indegree[nextNode]--;
                if (indegree[nextNode] == 0) {
                    q.offer(nextNode);
                }
                for (int i = 0; i < 26; i++) {
                    dp[nextNode][i] = Math.max(dp[nextNode][i], dp[thisNode][i]);
                }
            }
        }
        for (int i = 0; i < colors.length(); i++) {
            if (indegree[i] != 0) {
                return -1;
            }
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-05-26 22:02:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-26 23:59:12
 */
package main

func largestPathValue(colors string, edges [][]int) (ans int) {
    out := make([][]int, len(colors))
    for i := range out {
        out[i] = make([]int, 0)
    }
    indegree := make([]int, len(colors))
    for _, edge := range edges {
        out[edge[0]] = append(out[edge[0]], edge[1])
        indegree[edge[1]]++
    }
    q := []int{}
    for i, v := range indegree {
        if v == 0 {
            q = append(q, i)
        }
    }
    dp := make([][]int, len(colors))
    for i := range dp {
        dp[i] = make([]int, 26)
    }
    for len(q) > 0 {
        thisNode := q[len(q) - 1]
        q = q[:len(q) - 1]
        dp[thisNode][colors[thisNode] - 'a']++
        ans = max(ans, dp[thisNode][colors[thisNode] - 'a'])
        for _, nextNode := range out[thisNode] {
            indegree[nextNode]--
            if indegree[nextNode] == 0 {
                q = append(q, nextNode)
            }
            for i := 0; i < 26; i++ {
                dp[nextNode][i] = max(dp[nextNode][i], dp[thisNode][i])
            }
        }
    }
    for _, v := range indegree {
        if v != 0 {
            return -1
        }
    }
    return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/148242411)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/05/26/LeetCode%201857.%E6%9C%89%E5%90%91%E5%9B%BE%E4%B8%AD%E6%9C%80%E5%A4%A7%E9%A2%9C%E8%89%B2%E5%80%BC/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
