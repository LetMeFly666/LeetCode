---
title: 3243.新增道路查询后的最短距离 I
date: 2024-11-19 23:02:57
tags: [题解, LeetCode, 中等, 广度优先搜索, 图, 数组, 动态规划, DP, 最短路]
categories: [题解, LeetCode]
---

# 【LetMeFly】3243.新增道路查询后的最短距离 I：动态规划(DP)

力扣题目链接：[https://leetcode.cn/problems/shortest-distance-after-road-addition-queries-i/](https://leetcode.cn/problems/shortest-distance-after-road-addition-queries-i/)

<p>给你一个整数 <code>n</code> 和一个二维整数数组 <code>queries</code>。</p>

<p>有 <code>n</code> 个城市，编号从 <code>0</code> 到 <code>n - 1</code>。初始时，每个城市 <code>i</code> 都有一条<strong>单向</strong>道路通往城市 <code>i + 1</code>（ <code>0 &lt;= i &lt; n - 1</code>）。</p>

<p><code>queries[i] = [u<sub>i</sub>, v<sub>i</sub>]</code> 表示新建一条从城市 <code>u<sub>i</sub></code> 到城市 <code>v<sub>i</sub></code> 的<strong>单向</strong>道路。每次查询后，你需要找到从城市 <code>0</code> 到城市 <code>n - 1</code> 的<strong>最短路径</strong>的<strong>长度</strong>。</p>

<p>返回一个数组 <code>answer</code>，对于范围 <code>[0, queries.length - 1]</code> 中的每个 <code>i</code>，<code>answer[i]</code> 是处理完<strong>前</strong> <code>i + 1</code> 个查询后，从城市 <code>0</code> 到城市 <code>n - 1</code> 的最短路径的<em>长度</em>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 5, queries = [[2, 4], [0, 2], [0, 4]]</span></p>

<p><strong>输出：</strong> <span class="example-io">[3, 2, 1]</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/06/28/image8.jpg" style="width: 350px; height: 60px;" /></p>

<p>新增一条从 2 到 4 的道路后，从 0 到 4 的最短路径长度为 3。</p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/06/28/image9.jpg" style="width: 350px; height: 60px;" /></p>

<p>新增一条从 0 到 2 的道路后，从 0 到 4 的最短路径长度为 2。</p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/06/28/image10.jpg" style="width: 350px; height: 96px;" /></p>

<p>新增一条从 0 到 4 的道路后，从 0 到 4 的最短路径长度为 1。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 4, queries = [[0, 3], [0, 2]]</span></p>

<p><strong>输出：</strong> <span class="example-io">[1, 1]</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/06/28/image11.jpg" style="width: 300px; height: 70px;" /></p>

<p>新增一条从 0 到 3 的道路后，从 0 到 3 的最短路径长度为 1。</p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/06/28/image12.jpg" style="width: 300px; height: 70px;" /></p>

<p>新增一条从 0 到 2 的道路后，从 0 到 3 的最短路径长度仍为 1。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= n &lt;= 500</code></li>
	<li><code>1 &lt;= queries.length &lt;= 500</code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>0 &lt;= queries[i][0] &lt; queries[i][1] &lt; n</code></li>
	<li><code>1 &lt; queries[i][1] - queries[i][0]</code></li>
	<li>查询中没有重复的道路。</li>
</ul>


    
## 解题方法：动态规划

这道题有点意思，只有小编号城市指向大编号城市这一说。

因此我们可以使用：dp数组，dp[i]代表0到i的最短距离；fromList数组，fromList[i]代表所有能通向i的节点。

每次新增一条边（假设从from到to），就从to开始遍历到n - 1。对于遍历到的节点i，$dp[i]=\min dp[i], dp[j] + 1$（其中$j\in fromList[i]$）。

+ 时间复杂度$O(q(n+q))$
+ 空间复杂度$O(n+q)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> shortest(n);
        vector<vector<int>> fromList(n);
        for (int i = 1; i < n; i++) {
            fromList[i].push_back(i - 1);
            shortest[i] = i;
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int from = queries[i][0], to = queries[i][1];
            fromList[to].push_back(from);
            for (int j = to; j < n; j++) {
                for (int from : fromList[j]) {
                    shortest[j] = min(shortest[j], shortest[from] + 1);
                }
            }
            ans[i] = shortest.back();
        }
        return ans;
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        shortest = [i for i in range(n)]
        fromList = [[i - 1] for i in range(n)]
        ans = []
        for from_, to in queries:
            fromList[to].append(from_)
            for i in range(to, n):
                shortest[i] = min(shortest[i], min(shortest[j] + 1 for j in fromList[i]))
            ans.append(shortest[-1])
        return ans

```

#### Java

```java
import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        int[] shortest = new int[n];
        List<Integer>[] fromList = new List[n];
        for (int i = 0; i < n; i++) {
            shortest[i] = i;
            fromList[i] = new ArrayList<Integer>();
            fromList[i].add(i - 1);
        }
        int[] ans = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int from = queries[i][0], to = queries[i][1];
            fromList[to].add(from);
            for (int j = to; j < n; j++) {
                for (int from_ : fromList[j]) {
                    shortest[j] = Math.min(shortest[j], shortest[from_] + 1);
                }
            }
            ans[i] = shortest[n - 1];
        }
        return ans;
    }
}
```

#### Go

```go
package main

func shortestDistanceAfterQueries(n int, queries [][]int) (ans []int) {
    shortest := make([]int, n)
    fromList := make([][]int, n)
    for i := range shortest {
        shortest[i] = i
        fromList[i] = make([]int, 0)
        fromList[i] = append(fromList[i], i - 1)
    }
    ans = make([]int, len(queries))
    for i, query := range queries {
        fromList[query[1]] = append(fromList[query[1]], query[0])
        for j := query[1]; j < n; j++ {
            for _, from := range fromList[j] {
                shortest[j] = min(shortest[j], shortest[from] + 1)
            }
        }
        ans[i] = shortest[n - 1]
    }
    return
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/11/19/LeetCode%203243.%E6%96%B0%E5%A2%9E%E9%81%93%E8%B7%AF%E6%9F%A5%E8%AF%A2%E5%90%8E%E7%9A%84%E6%9C%80%E7%9F%AD%E8%B7%9D%E7%A6%BBI/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/143897977](https://letmefly.blog.csdn.net/article/details/143897977)
