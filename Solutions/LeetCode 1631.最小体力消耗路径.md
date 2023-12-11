---
title: 1631.最小体力消耗路径
date: 2023-12-11 18:57:55
tags: [题解, LeetCode, 中等, 深度优先搜索, 广度优先搜索, BFS, 并查集, 数组, 二分查找, 矩阵, 堆（优先队列）]
---

# 【LetMeFly】1631.最小体力消耗路径：广度优先搜索BFS

力扣题目链接：[https://leetcode.cn/problems/path-with-minimum-effort/](https://leetcode.cn/problems/path-with-minimum-effort/)

<p>你准备参加一场远足活动。给你一个二维 <code>rows x columns</code> 的地图 <code>heights</code> ，其中 <code>heights[row][col]</code> 表示格子 <code>(row, col)</code> 的高度。一开始你在最左上角的格子 <code>(0, 0)</code> ，且你希望去最右下角的格子 <code>(rows-1, columns-1)</code> （注意下标从 <strong>0</strong> 开始编号）。你每次可以往 <strong>上</strong>，<strong>下</strong>，<strong>左</strong>，<strong>右</strong> 四个方向之一移动，你想要找到耗费 <strong>体力</strong> 最小的一条路径。</p>

<p>一条路径耗费的 <strong>体力值</strong> 是路径上相邻格子之间 <strong>高度差绝对值</strong> 的 <strong>最大值</strong> 决定的。</p>

<p>请你返回从左上角走到右下角的最小<strong> 体力消耗值</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/10/25/ex1.png" style="width: 300px; height: 300px;" /></p>

<pre>
<b>输入：</b>heights = [[1,2,2],[3,8,2],[5,3,5]]
<b>输出：</b>2
<b>解释：</b>路径 [1,3,5,3,5] 连续格子的差值绝对值最大为 2 。
这条路径比路径 [1,2,2,2,5] 更优，因为另一条路径差值最大值为 3 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/10/25/ex2.png" style="width: 300px; height: 300px;" /></p>

<pre>
<b>输入：</b>heights = [[1,2,3],[3,8,4],[5,3,5]]
<b>输出：</b>1
<b>解释：</b>路径 [1,2,3,4,5] 的相邻格子差值绝对值最大为 1 ，比路径 [1,3,5,3,5] 更优。
</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/10/25/ex3.png" style="width: 300px; height: 300px;" />
<pre>
<b>输入：</b>heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
<b>输出：</b>0
<b>解释：</b>上图所示路径不需要消耗任何体力。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>rows == heights.length</code></li>
	<li><code>columns == heights[i].length</code></li>
	<li><code>1 <= rows, columns <= 100</code></li>
	<li><code>1 <= heights[i][j] <= 10<sup>6</sup></code></li>
</ul>


    
## 方法一：广度优先搜索BFS

首先我们可以构造一个图，图中顶点是矩阵中的点，图中的边是矩阵中相邻点的绝对值之差。

这样，我们只需要从起点0开始，使用一个优先队列进行广度优先搜索。每次找出未遍历的点中与已遍历的点中绝对值之差最小的点。入队时将“点的位置”和“从起点到该点的最大绝对值之差”入队。

最终返回最后一个位置距离起点的最大绝对值之差即为答案。

+ 时间复杂度$O(nm\log nm)$，其中$size(graph)=n\times m$
+ 空间复杂度$O(nm)$

### AC代码

#### C++

```cpp
const int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<pair<int, int>>> graph(n * m);  // graph[i]: [[j, 5], [k, 3]]
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int d = 0; d < 4; d++) {
                    int ti = i + directions[d][0], tj = j + directions[d][1];
                    if (ti < 0 || ti >= n || tj < 0 || tj >= m) {
                        continue;
                    }
                    int diff = abs(heights[i][j] - heights[ti][tj]);
                    int x = i * m + j, y = ti * m + tj;
                    graph[x].push_back({y, diff});
                }
            }
        }
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        pq.push({0, 0});
        vector<int> ans(n * m, 1e9);  // 从0到i的最大绝对值之差
        ans[0] = 0;
        while (pq.size()) {
            auto [index, diff] = pq.top();
            pq.pop();
            for (auto [toIndex, toDiff] : graph[index]) {
                int nextDiff = max(diff, toDiff);
                if (ans[toIndex] > nextDiff) {
                    ans[toIndex] = nextDiff;
                    pq.push({toIndex, nextDiff});
                }
            }
        }
        return ans.back();
    }
};
```

#### Python

```python
# from typing import List
# import heapq


directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]

class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        n, m = len(heights), len(heights[0])
        graph = [[] for _ in range(n * m)]
        for i in range(n):
            for j in range(m):
                for di, dj in directions:
                    ti, tj = i + di, j + dj
                    if ti < 0 or ti >= n or tj < 0 or tj >= m:
                        continue
                    graph[i * m + j].append((ti * m + tj, abs(heights[ti][tj] - heights[i][j])))
        pq = [(0, 0)]
        ans = [1000000000] * (n * m)
        ans[0] = 0
        while pq:
            thisDiff, thisNode = heapq.heappop(pq)
            for toNode, toDiff in graph[thisNode]:
                newDiff = max(thisDiff, toDiff)
                if ans[toNode] > newDiff:
                    ans[toNode] = newDiff
                    heapq.heappush(pq, (newDiff, toNode))
                    # print(thisNode, toNode, newDiff)
        return ans[-1]
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2023/12/11/LeetCode%201631.%E6%9C%80%E5%B0%8F%E4%BD%93%E5%8A%9B%E6%B6%88%E8%80%97%E8%B7%AF%E5%BE%84/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/134934684](https://letmefly.blog.csdn.net/article/details/134934684)
