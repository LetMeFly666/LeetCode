---
title: 2373.矩阵中的局部最大值
date: 2023-03-01 09:27:30
tags: [题解, LeetCode, 简单, 数组, 矩阵, 模拟]
---

# 【LetMeFly】2373.矩阵中的局部最大值

力扣题目链接：[https://leetcode.cn/problems/largest-local-values-in-a-matrix/](https://leetcode.cn/problems/largest-local-values-in-a-matrix/)

<p>给你一个大小为 <code>n x n</code> 的整数矩阵 <code>grid</code> 。</p>

<p>生成一个大小为&nbsp;<code>(n - 2) x (n - 2)</code> 的整数矩阵&nbsp; <code>maxLocal</code> ，并满足：</p>

<ul>
	<li><code>maxLocal[i][j]</code> 等于 <code>grid</code> 中以 <code>i + 1</code> 行和 <code>j + 1</code> 列为中心的 <code>3 x 3</code> 矩阵中的 <strong>最大值</strong> 。</li>
</ul>

<p>换句话说，我们希望找出 <code>grid</code> 中每个&nbsp;<code>3 x 3</code> 矩阵中的最大值。</p>

<p>返回生成的矩阵。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/06/21/ex1.png" style="width: 371px; height: 210px;" /></p>

<pre>
<strong>输入：</strong>grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
<strong>输出：</strong>[[9,9],[8,6]]
<strong>解释：</strong>原矩阵和生成的矩阵如上图所示。
注意，生成的矩阵中，每个值都对应 grid 中一个相接的 3 x 3 矩阵的最大值。</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/07/02/ex2new2.png" style="width: 436px; height: 240px;" /></p>

<pre>
<strong>输入：</strong>grid = [[1,1,1,1,1],[1,1,1,1,1],[1,1,2,1,1],[1,1,1,1,1],[1,1,1,1,1]]
<strong>输出：</strong>[[2,2,2],[2,2,2],[2,2,2]]
<strong>解释：</strong>注意，2 包含在 grid 中每个 3 x 3 的矩阵中。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == grid.length == grid[i].length</code></li>
	<li><code>3 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 100</code></li>
</ul>


    
## 方法一：模拟

假设grid的size为$n\times n$，那么答案的size就为$(n - 2)\times(n-2)$

先生成这么大的空数组，然后遍历答案数组的每一个位置在原始数组中对应的$3\times3$矩阵的中心，对于每个位置，求出其$3\times3$矩阵的最大值即可

+ 时间复杂度$O(len(grid)^2)$
+ 空间复杂度$O(1)$，力扣算法返回值不计入算法的空间复杂度

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2));
        for (int i = 1; i + 1 < n; i++) {
            for (int j = 1; j + 1 < n; j++) {
                int M = 1;
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        M = max(M, grid[i + k][j + l]);
                    }
                }
                ans[i - 1][j - 1] = M;
            }
        }
        return ans;
    }
};
```

#### Python

```python
class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        n = len(grid)
        ans = [[0 for _ in range(n - 2)] for __ in range(n - 2)]
        for i in range(1, n - 1):
            for j in range(1, n - 1):
                M = 1
                for k in range(-1, 2):
                    for l in range(-1, 2):
                        M = max(M, grid[i + k][j + l])
                ans[i - 1][j - 1] = M        
        return ans
```

语法糖简化：

```python
class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        n = len(grid)
        ans = [[0 for _ in range(n - 2)] for __ in range(n - 2)]
        for i in range(1, n - 1):
            for j in range(1, n - 1):
                ans[i - 1][j - 1] = max(grid[x][y] for x in range(i - 1, i + 2) for y in range(j - 1, j + 2))
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/03/01/LeetCode%202373.%E7%9F%A9%E9%98%B5%E4%B8%AD%E7%9A%84%E5%B1%80%E9%83%A8%E6%9C%80%E5%A4%A7%E5%80%BC/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129274862](https://letmefly.blog.csdn.net/article/details/129274862)
