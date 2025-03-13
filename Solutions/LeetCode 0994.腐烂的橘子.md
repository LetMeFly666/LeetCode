---
title: 994.腐烂的橘子
date: 2024-05-13 14:26:46
tags: [题解, LeetCode, 中等, 广度优先搜索, 数组, 矩阵]
categories: [题解, LeetCode]
---

# 【LetMeFly】994.腐烂的橘子：广度优先搜索(BFS)

力扣题目链接：[https://leetcode.cn/problems/rotting-oranges/](https://leetcode.cn/problems/rotting-oranges/)

<p>在给定的&nbsp;<code>m x n</code>&nbsp;网格<meta charset="UTF-8" />&nbsp;<code>grid</code>&nbsp;中，每个单元格可以有以下三个值之一：</p>

<ul>
	<li>值&nbsp;<code>0</code>&nbsp;代表空单元格；</li>
	<li>值&nbsp;<code>1</code>&nbsp;代表新鲜橘子；</li>
	<li>值&nbsp;<code>2</code>&nbsp;代表腐烂的橘子。</li>
</ul>

<p>每分钟，腐烂的橘子&nbsp;<strong>周围&nbsp;4 个方向上相邻</strong> 的新鲜橘子都会腐烂。</p>

<p>返回 <em>直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回&nbsp;<code>-1</code></em>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/02/16/oranges.png" style="height: 137px; width: 650px;" /></strong></p>

<pre>
<strong>输入：</strong>grid = [[2,1,1],[1,1,0],[0,1,1]]
<strong>输出：</strong>4
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>grid = [[2,1,1],[0,1,1],[1,0,1]]
<strong>输出：</strong>-1
<strong>解释：</strong>左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个方向上。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>grid = [[0,2]]
<strong>输出：</strong>0
<strong>解释：</strong>因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10</code></li>
	<li><code>grid[i][j]</code> 仅为&nbsp;<code>0</code>、<code>1</code>&nbsp;或&nbsp;<code>2</code></li>
</ul>


    
## 解题方法：BFS

首先将腐烂的橘子入队。（每个入队的橘子都被标记为0，假设坏掉消失了，反正它最多“往外感染一次”）

接着当队列非空时：

> 每次将队列中当前元素全部出队，并尝试向上下左右四个方向腐蚀一个橘子。
>
> 若腐蚀成功则新橘子入队（并标记为消失）

每轮腐蚀若成功则“腐蚀时间加一”，直至队列为空，判断是否还有完好的橘子。

+ 时间复杂度$O(mn)$
+ 空间复杂度$O(mn)$

不知本题数据范围为何这么小。

### AC代码

#### C++

```cpp
const int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        int cntNormal = 0;
        queue<int> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    cntNormal++;
                }
                else if (grid[i][j] == 2) {
                    q.push(i * 10 + j);
                    grid[i][j] = 0;
                }
            }
        }
        while (q.size()) {
            bool hasNew = false;
            for (int i = q.size(); i > 0; i--) {
                int x = q.front() / 10, y = q.front() % 10;
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int tx = x + directions[d][0], ty = y + directions[d][1];
                    if (tx >= 0 && tx < grid.size() && ty >= 0 && ty < grid[0].size() && grid[tx][ty] == 1) {
                        grid[tx][ty] = 0;
                        q.push(tx * 10 + ty);
                        cntNormal--;
                        hasNew = true;
                    }
                }
            }
            ans += hasNew;
        }
        return cntNormal ? -1 : ans;
    }
};
```

#### Python

```python
# from typing import List


DIRECTIONS = [[0, -1], [0, 1], [-1, 0], [1, 0]]

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        ans = 0
        cntNormal = 0
        q = []
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    cntNormal += 1
                elif grid[i][j] == 2:
                    q.append((i, j))
                    grid[i][j] = 0
        while q:
            hasNew = False
            newQ = []
            for x, y in q:
                for dx, dy in DIRECTIONS:
                    newX, newY = x + dx, y + dy
                    if newX >= 0 and newX < len(grid) and newY >= 0 and newY < len(grid[0]) and grid[newX][newY] == 1:
                        newQ.append((newX, newY))
                        grid[newX][newY] = 0
                        cntNormal -= 1
                        hasNew = True
            q = newQ
            ans += hasNew
        return -1 if cntNormal else ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/05/13/LeetCode%200994.%E8%85%90%E7%83%82%E7%9A%84%E6%A9%98%E5%AD%90/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/138802167](https://letmefly.blog.csdn.net/article/details/138802167)
