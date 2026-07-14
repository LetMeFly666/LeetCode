---
title: 3286.穿越网格图的安全路径：“优先”队列
date: 2026-07-14 11:26:35
tags: [题解, LeetCode, 中等, 广度优先搜索, 图, 数组, 矩阵, 最短路, 堆（优先队列）, 优先队列]
categories: [题解, LeetCode]
---

# 【LetMeFly】3286.穿越网格图的安全路径：“优先”队列

力扣题目链接：[https://leetcode.cn/problems/find-a-safe-walk-through-a-grid/](https://leetcode.cn/problems/find-a-safe-walk-through-a-grid/)

<p>给你一个&nbsp;<code>m x n</code>&nbsp;的二进制矩形&nbsp;<code>grid</code>&nbsp;和一个整数&nbsp;<code>health</code>&nbsp;表示你的健康值。</p>

<p>你开始于矩形的左上角&nbsp;<code>(0, 0)</code>&nbsp;，你的目标是矩形的右下角&nbsp;<code>(m - 1, n - 1)</code>&nbsp;。</p>

<p>你可以在矩形中往上下左右相邻格子移动，但前提是你的健康值始终是 <b>正数</b>&nbsp;。</p>

<p>对于格子&nbsp;<code>(i, j)</code>&nbsp;，如果&nbsp;<code>grid[i][j] = 1</code>&nbsp;，那么这个格子视为 <strong>不安全</strong>&nbsp;的，会使你的健康值减少 1 。</p>

<p>如果你可以到达最终的格子，请你返回&nbsp;<code>true</code>&nbsp;，否则返回 <code>false</code>&nbsp;。</p>

<p><b>注意</b>&nbsp;，当你在最终格子的时候，你的健康值也必须为<strong>&nbsp;正数</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]], health = 1</span></p>

<p><span class="example-io"><b>输出：</b>true</span></p>

<p><b>解释：</b></p>

<p>沿着下图中灰色格子走，可以安全到达最终的格子。</p>
<img alt="" src="https://assets.leetcode.com/uploads/2024/08/04/3868_examples_1drawio.png" style="width: 301px; height: 121px;" /></div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [[0,1,1,0,0,0],[1,0,1,0,0,0],[0,1,1,1,0,1],[0,0,1,0,1,0]], health = 3</span></p>

<p><span class="example-io"><b>输出：</b>false</span></p>

<p><b>解释：</b></p>

<p>健康值最少为 4 才能安全到达最后的格子。</p>
<img alt="" src="https://assets.leetcode.com/uploads/2024/08/04/3868_examples_2drawio.png" style="width: 361px; height: 161px;" /></div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [[1,1,1],[1,0,1],[1,1,1]], health = 5</span></p>

<p><span class="example-io"><b>输出：</b>true</span></p>

<p><b>解释：</b></p>

<p>沿着下图中灰色格子走，可以安全到达最终的格子。</p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/08/04/3868_examples_3drawio.png" style="width: 181px; height: 121px;" /></p>

<p>任何不经过格子&nbsp;<code>(1, 1)</code>&nbsp;的路径都是不安全的，因为你的健康值到达最终格子时，都会小于等于 0 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
<li><code>2 <= m * n</code></li>
	<li><code>1 &lt;= health &lt;= m + n</code></li>
	<li><code>grid[i][j]</code>&nbsp;要么是 0 ，要么是 1 。</li>
</ul>


    
## 解题方法：优先队列

从起点开始，不论上下左右怎么走，走到为$0$的格子都不掉血，走到为$1$的格子则代价$+1$。

我们可以换个思路，从起点到终点最小的代价是多少？如果最小的代价小于初始健康值则返回`true`。

因此，可以使用一个优先队列，每次队列中代价最小的位置出队，更新其上下左右相邻格子的到达代价。如果上下左右四个格子到达的代价更小则入队。

**优化**

由于新入队格子的代价最多是当前格子+1，所以其实队列中最多只有两个值，我们也可以使用双端队列，如果新入队格子代价和现在相等则对到队首，否则入队到队尾。

+ 时间复杂度$O(size(grid))$，优先队列优化后无需排序。
+ 空间复杂度$O(size(grid))$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-07-14 11:26:09
 */
typedef pair<int, int> pii;
class Solution {
private:
    constexpr static int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> costs(n, vector<int>(m, 100000000));
        deque<pii> q;
        q.push_back({0, 0});
        costs[0][0] = grid[0][0];  // 注意起点可能直接掉血
        while (q.size()) {
            auto [x, y] = q.front();
            q.pop_front();
            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                    int next_cost = costs[x][y] + grid[nx][ny];
                    if (next_cost >= costs[nx][ny]) {
                        continue;
                    }
                    costs[nx][ny] = next_cost;
                    if (grid[nx][ny]) {
                        q.push_back({nx, ny});
                    } else {
                        q.push_front({nx, ny});
                    }
                }
            }
        }
        return costs[n - 1][m - 1] < health;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/162868510)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/07/14/LeetCode%203286.%E7%A9%BF%E8%B6%8A%E7%BD%91%E6%A0%BC%E5%9B%BE%E7%9A%84%E5%AE%89%E5%85%A8%E8%B7%AF%E5%BE%84/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
