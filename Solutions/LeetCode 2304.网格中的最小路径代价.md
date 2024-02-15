---
title: 2304.网格中的最小路径代价
date: 2023-11-22 19:55:00
tags: [题解, LeetCode, 中等, 数组, 动态规划, DP, 矩阵]
---

# 【LetMeFly】2304.网格中的最小路径代价：DP

力扣题目链接：[https://leetcode.cn/problems/minimum-path-cost-in-a-grid/](https://leetcode.cn/problems/minimum-path-cost-in-a-grid/)

<p>给你一个下标从 <strong>0</strong> 开始的整数矩阵&nbsp;<code>grid</code> ，矩阵大小为 <code>m x n</code> ，由从 <code>0</code> 到 <code>m * n - 1</code> 的不同整数组成。你可以在此矩阵中，从一个单元格移动到 <strong>下一行</strong> 的任何其他单元格。如果你位于单元格 <code>(x, y)</code> ，且满足 <code>x &lt; m - 1</code> ，你可以移动到 <code>(x + 1, 0)</code>, <code>(x + 1, 1)</code>, ..., <code>(x + 1, n - 1)</code><strong> </strong>中的任何一个单元格。<strong>注意：</strong>&nbsp;在最后一行中的单元格不能触发移动。</p>

<p>每次可能的移动都需要付出对应的代价，代价用一个下标从 <strong>0</strong> 开始的二维数组 <code>moveCost</code> 表示，该数组大小为 <code>(m * n) x n</code> ，其中 <code>moveCost[i][j]</code> 是从值为 <code>i</code> 的单元格移动到下一行第 <code>j</code> 列单元格的代价。从&nbsp;<code>grid</code> 最后一行的单元格移动的代价可以忽略。</p>

<p><code>grid</code> 一条路径的代价是：所有路径经过的单元格的 <strong>值之和</strong> 加上 所有移动的 <strong>代价之和 </strong>。从 <strong>第一行</strong> 任意单元格出发，返回到达 <strong>最后一行</strong> 任意单元格的最小路径代价<em>。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/04/28/griddrawio-2.png" style="width: 301px; height: 281px;" /></p>

<pre>
<strong>输入：</strong>grid = [[5,3],[4,0],[2,1]], moveCost = [[9,8],[1,5],[10,12],[18,6],[2,4],[14,3]]
<strong>输出：</strong>17
<strong>解释：</strong>最小代价的路径是 5 -&gt; 0 -&gt; 1 。
- 路径途经单元格值之和 5 + 0 + 1 = 6 。
- 从 5 移动到 0 的代价为 3 。
- 从 0 移动到 1 的代价为 8 。
路径总代价为 6 + 3 + 8 = 17 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>grid = [[5,1,2],[4,0,3]], moveCost = [[12,10,15],[20,23,8],[21,7,1],[8,1,13],[9,10,25],[5,3,2]]
<strong>输出：</strong>6
<strong>解释：</strong>
最小代价的路径是 2 -&gt; 3 。 
- 路径途经单元格值之和 2 + 3 = 5 。 
- 从 2 移动到 3 的代价为 1 。 
路径总代价为 5 + 1 = 6 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>2 &lt;= m, n &lt;= 50</code></li>
	<li><code>grid</code> 由从 <code>0</code> 到 <code>m * n - 1</code> 的不同整数组成</li>
	<li><code>moveCost.length == m * n</code></li>
	<li><code>moveCost[i].length == n</code></li>
	<li><code>1 &lt;= moveCost[i][j] &lt;= 100</code></li>
</ul>


    
## 方法一：DP

从倒数第二行开始往第一行遍历：
   + 对于这一行的每一个元素：
       + 计算出 从下一行的所有元素中来到这一行，增加值最小的那个
   + 这个元素加上下一行来的最小增加量

最终返回第一行中的最小元素即为答案。

+ 时间复杂度$O(nm^2)$，其中$size(grid)=n\times m$（$n$行$m$列）
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size(), m = grid[0].size();
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                int m_ = 100000000;
                for (int k = 0; k < m; k++) {
                    m_ = min(m_, grid[i + 1][k] + moveCost[grid[i][j]][k]);
                }
                grid[i][j] += m_;
            }
        }
        return *min_element(grid[0].begin(), grid[0].end());
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def minPathCost(self, grid: List[List[int]], moveCost: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        for i in range(n - 2, -1, -1):
            for j in range(m):
                m_ = 100000000
                for k in range(m):
                    m_ = min(m_, grid[i + 1][k] + moveCost[grid[i][j]][k])
                grid[i][j] += m_
        return min(grid[0])

```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/11/22/LeetCode%202304.%E7%BD%91%E6%A0%BC%E4%B8%AD%E7%9A%84%E6%9C%80%E5%B0%8F%E8%B7%AF%E5%BE%84%E4%BB%A3%E4%BB%B7/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/134563145](https://letmefly.blog.csdn.net/article/details/134563145)
