---
title: 931.下降路径最小和：通俗思路讲解
date: 2023-07-13 08:20:17
tags: [题解, LeetCode, 中等, 数组, 动态规划, 矩阵, DP]
---

# 【LetMeFly】931.下降路径最小和：通俗思路讲解

力扣题目链接：[https://leetcode.cn/problems/minimum-falling-path-sum/](https://leetcode.cn/problems/minimum-falling-path-sum/)

<p>给你一个 <code>n x n</code> 的<strong> 方形 </strong>整数数组&nbsp;<code>matrix</code> ，请你找出并返回通过 <code>matrix</code> 的<strong>下降路径</strong><em> </em>的<strong> </strong><strong>最小和</strong> 。</p>

<p><strong>下降路径</strong> 可以从第一行中的任何元素开始，并从每一行中选择一个元素。在下一行选择的元素和当前行所选元素最多相隔一列（即位于正下方或者沿对角线向左或者向右的第一个元素）。具体来说，位置 <code>(row, col)</code> 的下一个元素应当是 <code>(row + 1, col - 1)</code>、<code>(row + 1, col)</code> 或者 <code>(row + 1, col + 1)</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/11/03/failing1-grid.jpg" style="height: 500px; width: 499px;" /></p>

<pre>
<strong>输入：</strong>matrix = [[2,1,3],[6,5,4],[7,8,9]]
<strong>输出：</strong>13
<strong>解释：</strong>如图所示，为和最小的两条下降路径
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/11/03/failing2-grid.jpg" style="height: 365px; width: 164px;" /></p>

<pre>
<strong>输入：</strong>matrix = [[-19,57],[-40,-5]]
<strong>输出：</strong>-59
<strong>解释：</strong>如图所示，为和最小的下降路径
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == matrix.length == matrix[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>-100 &lt;= matrix[i][j] &lt;= 100</code></li>
</ul>


    
## 方法一：动态规划

换个思维：$matrix[i][j]$只能由$matrix[i - 1][j - 1]$或$matrix[i - 1][j]$或$matrix[i - 1][j + 1]$走到。

那么从这三个的哪一个过来呢？当然是这三个中最小的那个。

于是我们就直到怎么做了。

+ 时间复杂度$O(n^2)$，其中$size(matrix) = n\times n$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int m = 1e8;
                for (int k = -1; k <= 1; k++) {
                    if (j + k >= 0 && j + k < n) {
                        m = min(m, matrix[i - 1][j + k]);
                    }
                }
                matrix[i][j] += m;
            }
        }
        int ans = 1e8;
        for (int j = 0; j < n; j++) {
            ans = min(ans, matrix[n - 1][j]);
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        for i in range(1, n):
            for j in range(n):
                m = 1e8
                for k in range(-1, 2):
                    if 0 <= j + k < n:
                        m = min(m, matrix[i - 1][j + k])
                matrix[i][j] += m
        return min(matrix[-1])
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/07/13/LeetCode%200931.%E4%B8%8B%E9%99%8D%E8%B7%AF%E5%BE%84%E6%9C%80%E5%B0%8F%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131694030](https://letmefly.blog.csdn.net/article/details/131694030)
