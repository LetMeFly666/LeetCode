---
title: 1928.规定时间内到达终点的最小花费
date: 2024-10-03 13:17:58
tags: [题解, LeetCode, 困难, 图, 数组, 动态规划, DP]
categories: [题解, LeetCode]
---

# 【LetMeFly】1928.规定时间内到达终点的最小花费：动态规划

力扣题目链接：[https://leetcode.cn/problems/minimum-cost-to-reach-destination-in-time/](https://leetcode.cn/problems/minimum-cost-to-reach-destination-in-time/)

<p>一个国家有 <code>n</code> 个城市，城市编号为 <code>0</code> 到 <code>n - 1</code> ，题目保证 <strong>所有城市</strong> 都由双向道路 <b>连接在一起</b> 。道路由二维整数数组 <code>edges</code> 表示，其中 <code>edges[i] = [x<sub>i</sub>, y<sub>i</sub>, time<sub>i</sub>]</code> 表示城市 <code>x<sub>i</sub></code> 和 <code>y<sub>i</sub></code> 之间有一条双向道路，耗费时间为 <code>time<sub>i</sub></code> 分钟。两个城市之间可能会有多条耗费时间不同的道路，但是不会有道路两头连接着同一座城市。</p>

<p>每次经过一个城市时，你需要付通行费。通行费用一个长度为 <code>n</code> 且下标从 <strong>0</strong> 开始的整数数组 <code>passingFees</code> 表示，其中 <code>passingFees[j]</code> 是你经过城市 <code>j</code> 需要支付的费用。</p>

<p>一开始，你在城市 <code>0</code> ，你想要在 <code>maxTime</code> <strong>分钟以内</strong> （包含 <code>maxTime</code> 分钟）到达城市 <code>n - 1</code> 。旅行的 <strong>费用</strong> 为你经过的所有城市 <strong>通行费之和</strong> （<strong>包括</strong> 起点和终点城市的通行费）。</p>

<p>给你 <code>maxTime</code>，<code>edges</code> 和 <code>passingFees</code> ，请你返回完成旅行的 <strong>最小费用</strong> ，如果无法在 <code>maxTime</code> 分钟以内完成旅行，请你返回 <code>-1</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/06/04/leetgraph1-1.png" style="width: 371px; height: 171px;" /></p>

<pre>
<b>输入：</b>maxTime = 30, edges = [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees = [5,1,2,20,20,3]
<b>输出：</b>11
<b>解释：</b>最优路径为 0 -> 1 -> 2 -> 5 ，总共需要耗费 30 分钟，需要支付 11 的通行费。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2021/06/04/copy-of-leetgraph1-1.png" style="width: 371px; height: 171px;" /></strong></p>

<pre>
<b>输入：</b>maxTime = 29, edges = [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees = [5,1,2,20,20,3]
<b>输出：</b>48
<b>解释：</b>最优路径为 0 -> 3 -> 4 -> 5 ，总共需要耗费 26 分钟，需要支付 48 的通行费。
你不能选择路径 0 -> 1 -> 2 -> 5 ，因为这条路径耗费的时间太长。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>maxTime = 25, edges = [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees = [5,1,2,20,20,3]
<b>输出：</b>-1
<b>解释：</b>无法在 25 分钟以内从城市 0 到达城市 5 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= maxTime <= 1000</code></li>
	<li><code>n == passingFees.length</code></li>
	<li><code>2 <= n <= 1000</code></li>
	<li><code>n - 1 <= edges.length <= 1000</code></li>
	<li><code>0 <= x<sub>i</sub>, y<sub>i</sub> <= n - 1</code></li>
	<li><code>1 <= time<sub>i</sub> <= 1000</code></li>
	<li><code>1 <= passingFees[j] <= 1000</code> </li>
	<li>图中两个节点之间可能有多条路径。</li>
	<li>图中不含有自环。</li>
</ul>


    
## 解题方法：动态规划

使用`dp[t][i]`表示在时间`t`到达城市`i`所需最小花费。初始值除了`dp[0][0] = passingFees[0]`外其余`dp[t][i]`全为“无穷大”`10^7`。

对于当前时间`t`，枚举每一条边（假设这条边连接`i`和`j`而花费是`cost`），若`cost <= t`，则能更新`dp[t][j] = min(dp[t][j], dp[t - cost][i] + passingFees)`，`dp[t][i]`同理。

最终，对于所有的`t`，`dp[t][n - 1]`最小的那个即为最小耗时（若为“无穷大”则返回`-1`）。

+ 时间复杂度$O((n+m)\times maxTime)$。其中$n$是节点数，$m$是边数；构建`dp`数组耗时$O(n\times maxTime)$，动态规划耗时$O(m\times maxTime)$
+ 空间复杂度$O(n\times maxTime)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        // vector<vector<pair<int, int>>> graph(passingFees.size());
        // for (vector<int>& edge : edges) {
        //     graph[edge[0]].push_back({edge[1], edge[2]});
        //     graph[edge[1]].push_back({edge[0], edge[2]});
        // }
        vector<vector<int>> dp(maxTime + 1, vector<int>(passingFees.size(), 10000000));
        dp[0][0] = passingFees[0];
        for (int t = 1; t <= maxTime; t++) {
            for (vector<int>& edge : edges) {
                int i = edge[0], j = edge[1], thisTime = edge[2];
                if (thisTime <= t) {
                    dp[t][j] = min(dp[t][j], dp[t - thisTime][i] + passingFees[j]);
                    dp[t][i] = min(dp[t][i], dp[t - thisTime][j] + passingFees[i]);
                }
            }
        }
        int ans = 10000000;
        for (int t = 0; t <= maxTime; t++) {
            ans = min(ans, dp[t].back());
        }
        return ans == 10000000 ? -1 : ans;
    }
};
```

#### Go

```go
package main

func min(a int, b int) int {
    if a <= b {
        return a
    }
    return b
}

func minCost(maxTime int, edges [][]int, passingFees []int) int {
    dp := make([][]int, maxTime + 1)
    // for _, d := range dp {
    //     d = make([]int, len(passingFees))
    //     for i := range d {
    //         d[i] = 10000000
    //     }
    // }
    for th := range dp {
        dp[th] = make([]int, len(passingFees))
        for i := range dp[th] {
            dp[th][i] = 10000000
        }
    }
    dp[0][0] = passingFees[0]
    
    for t := 1; t <= maxTime; t++ {
        for _, edge := range edges {
            i, j, cost := edge[0], edge[1], edge[2]
            if cost <= t {
                dp[t][j] = min(dp[t][j], dp[t - cost][i] + passingFees[j])
                dp[t][i] = min(dp[t][i], dp[t - cost][j] + passingFees[i])
            }
        }
    }

    ans := 10000000
    for _, d := range dp {
        ans = min(ans, d[len(passingFees) - 1])
    }
    if ans == 10000000 {
        return -1
    }
    return ans
}
```

#### Java

```java
import java.util.Arrays;
class Solution {
    public int minCost(int maxTime, int[][] edges, int[] passingFees) {
        int[][] dp = new int[maxTime + 1][passingFees.length];
        for (int i = 0; i <= maxTime; i++) {
            Arrays.fill(dp[i], 10000000);
        }
        dp[0][0] = passingFees[0];
        for (int t = 1; t <= maxTime; t++) {
            for (int[] edge : edges) {
                int i = edge[0], j = edge[1], cost = edge[2];
                if (cost <= t) {
                    dp[t][j] = Math.min(dp[t][j], dp[t - cost][i] + passingFees[j]);
                    dp[t][i] = Math.min(dp[t][i], dp[t - cost][j] + passingFees[i]);
                }
            }
        }
        int ans = 10000000;
        for (int[] d : dp) {
            ans = Math.min(ans, d[passingFees.length - 1]);
        }
        return ans == 10000000 ? -1 : ans;
    }
}
```

#### Python

```python
from typing import List

class Solution:
    def minCost(self, maxTime: int, edges: List[List[int]], passingFees: List[int]) -> int:
        dp = [[10000000] * len(passingFees) for _ in range(maxTime + 1)]
        dp[0][0] = passingFees[0]
        for t in range(1, maxTime + 1):
            for i, j, thisTime in edges:
                if thisTime <= t:
                    dp[t][j] = min(dp[t][j], dp[t - thisTime][i] + passingFees[j])
                    dp[t][i] = min(dp[t][i], dp[t - thisTime][j] + passingFees[i])
        ans = min(d[-1] for d in dp)
        return -1 if ans == 10000000 else ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/10/03/LeetCode%201928.%E8%A7%84%E5%AE%9A%E6%97%B6%E9%97%B4%E5%86%85%E5%88%B0%E8%BE%BE%E7%BB%88%E7%82%B9%E7%9A%84%E6%9C%80%E5%B0%8F%E8%8A%B1%E8%B4%B9/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/142691241](https://letmefly.blog.csdn.net/article/details/142691241)
