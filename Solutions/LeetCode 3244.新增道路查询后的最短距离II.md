---
title: 3244.新增道路查询后的最短距离 II
date: 2024-11-20 13:07:37
tags: [题解, LeetCode, 困难, 贪心, 图, 数组, 有序集合, 思维]
---

# 【LetMeFly】3244.新增道路查询后的最短距离 II：贪心（跃迁合并）-9行py（O(n)）

力扣题目链接：[https://leetcode.cn/problems/shortest-distance-after-road-addition-queries-ii/](https://leetcode.cn/problems/shortest-distance-after-road-addition-queries-ii/)

<p>给你一个整数 <code>n</code> 和一个二维整数数组 <code>queries</code>。</p>

<p>有 <code>n</code> 个城市，编号从 <code>0</code> 到 <code>n - 1</code>。初始时，每个城市 <code>i</code> 都有一条<strong>单向</strong>道路通往城市 <code>i + 1</code>（ <code>0 &lt;= i &lt; n - 1</code>）。</p>

<p><code>queries[i] = [u<sub>i</sub>, v<sub>i</sub>]</code> 表示新建一条从城市 <code>u<sub>i</sub></code> 到城市 <code>v<sub>i</sub></code> 的<strong>单向</strong>道路。每次查询后，你需要找到从城市 <code>0</code> 到城市 <code>n - 1</code> 的<strong>最短路径</strong>的<strong>长度</strong>。</p>

<p>所有查询中不会存在两个查询都满足 <code>queries[i][0] &lt; queries[j][0] &lt; queries[i][1] &lt; queries[j][1]</code>。</p>

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

<p><strong>提示:</strong></p>

<ul>
	<li><code>3 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>0 &lt;= queries[i][0] &lt; queries[i][1] &lt; n</code></li>
	<li><code>1 &lt; queries[i][1] - queries[i][0]</code></li>
	<li>查询中不存在重复的道路。</li>
	<li>不存在两个查询都满足 <code>i != j</code> 且 <code>queries[i][0] &lt; queries[j][0] &lt; queries[i][1] &lt; queries[j][1]</code>。</li>
</ul>


> 挺有意思的一道题。

## 解题方法：跃迁合并

把每一条路径视为一条跃迁通道，每个点记录“自己最多能跃迁到的点”，初始值每个点能跃迁到的点都是自己的下一个节点。

新来一条“跃迁通道”有两种可能：

+ 被一条更长(或等长)的跃迁通道覆盖
+ 覆盖n条跃迁通道

反正不可能和其他跃迁通道有交叉。

两种情况的判断方式是“跃迁起点”指向的“能跃迁到的点”是否大于(等于)自己的“跃迁终点”

> 例如新加一条`[1, 3]`的跃迁路径，结果发现`1`已经能跃迁到`5`了，那么就说明这是一条被其他“跃迁通道”覆盖的通道

+ 对于第一种情况：直接continue
+ 对于第二种情况：修改所有“最大被覆盖子跃迁通道”的起点的“能跃迁到的点”

    > 例如原本有“跃迁通道”`[1, 3]`，`[3, 4]`，`[4, 7]`，新增“跃迁通道”`[1, 7]`，
    >
    > 那么就将`1`、`3`、`4`的“能跃迁到的点”修改为`7`。
    >
    > 跃迁次数减少$3-1=2$次

### 时空复杂度分析

+ 时间复杂度$O(n+q)$：每次修改一个点“能跃迁到的点”，总跃迁次数就会减少一；总跃迁次数最多减少到1，说明“跃迁合并”最多$n-1$次。
+ 空间复杂度$O(n)$，返回值不计入。

### AC代码

#### C++

```cpp
/*
每个点记录“自己跃迁到的点”
初始值每个点能跃迁到的点都是自己的下一个节点

新来一条“跃迁通道”有两种可能：
    + 被一条更长(或等长)的跃迁通道覆盖
    + 覆盖n条跃迁通道
反正不可能和其他跃迁通道有交叉
两种情况的判断方式是“跃迁起点”指向的“能跃迁到的点”是否大于(等于)自己的“跃迁终点”
    + 对于第一种情况：直接continue
    + 对于第二种情况：修改所有“最大被覆盖子跃迁通道”的起点的“能跃迁到的点”
*/
// FourthTry  // 简化版  // 执行用时分布:2ms,击败98.51%;消耗内存分布:108.84MB,击败83.86%.
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> transitionTo(n), ans(queries.size());
        for (int i = 0; i < n; i++) {
            transitionTo[i] = i + 1;
        }
        int transitionToEndTimes = n - 1;
        for (int i = 0; i < queries.size(); i++) {
            int from = queries[i][0], to = queries[i][1], now = from;
            while (transitionTo[now] < to) {
                transitionToEndTimes--;
                int originalTo = transitionTo[now];
                transitionTo[now] = to;
                now = originalTo;
            }
            ans[i] = transitionToEndTimes;
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
        transitionTo = [i + 1 for i in range(n)]
        ans = []
        shortestTimes = n - 1
        for from_, to in queries:
            while transitionTo[from_] < to:
                shortestTimes -= 1
                transitionTo[from_], from_ = to, transitionTo[from_]
            ans.append(shortestTimes)
        return ans
```

#### Java

```java
class Solution {
    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        int[] transitionTo = new int[n];
        for (int i = 0; i < n; i++) {
            transitionTo[i] = i + 1;
        }
        int[] ans = new int[queries.length];
        int minTimes = n - 1;
        for (int i = 0; i < queries.length; i++) {
            int from = queries[i][0], to =  queries[i][1];
            while (transitionTo[from] < to) {
                minTimes--;
                int originalTo = transitionTo[from];
                transitionTo[from] = to;
                from = originalTo;
            }
            ans[i] = minTimes;
        }
        return ans;
    }
}  // AC,100.00%,79.09%
```

#### Go

```go
package main

func shortestDistanceAfterQueries(n int, queries [][]int) (ans []int) {
    transitionTo := make([]int, n)
    for i := range transitionTo {
        transitionTo[i] = i + 1
    }
    minTimes := n - 1
    for _, query := range queries {
        from, to := query[0], query[1]
        for transitionTo[from] < to {
            minTimes--
            transitionTo[from], from = to, transitionTo[from]
        }
        ans = append(ans, minTimes)
    }
    return
}  // AC,81.82%,29.41%
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/11/20/LeetCode%203244.%E6%96%B0%E5%A2%9E%E9%81%93%E8%B7%AF%E6%9F%A5%E8%AF%A2%E5%90%8E%E7%9A%84%E6%9C%80%E7%9F%AD%E8%B7%9D%E7%A6%BBII/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/143908539](https://letmefly.blog.csdn.net/article/details/143908539)
