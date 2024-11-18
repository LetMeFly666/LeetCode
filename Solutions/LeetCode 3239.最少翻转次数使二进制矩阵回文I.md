---
title: 3239.最少翻转次数使二进制矩阵回文 I
date: 2024-11-15 12:59:24
tags: [题解, LeetCode, 中等, 数组, 双指针, 矩阵, 回文]
---

# 【LetMeFly】3239.最少翻转次数使二进制矩阵回文 I：遍历（行和列两种情况分别讨论）

力扣题目链接：[https://leetcode.cn/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-i/](https://leetcode.cn/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-i/)

<p>给你一个&nbsp;<code>m x n</code>&nbsp;的二进制矩阵&nbsp;<code>grid</code>&nbsp;。</p>

<p>如果矩阵中一行或者一列从前往后与从后往前读是一样的，那么我们称这一行或者这一列是 <strong>回文</strong> 的。</p>

<p>你可以将 <code>grid</code>&nbsp;中任意格子的值 <strong>翻转</strong>&nbsp;，也就是将格子里的值从 <code>0</code>&nbsp;变成 <code>1</code>&nbsp;，或者从 <code>1</code>&nbsp;变成 <code>0</code>&nbsp;。</p>

<p>请你返回 <strong>最少</strong>&nbsp;翻转次数，使得矩阵 <strong>要么</strong>&nbsp;所有行是 <strong>回文的</strong>&nbsp;，要么所有列是 <strong>回文的</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [[1,0,0],[0,0,0],[0,0,1]]</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><b>解释：</b></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/07/07/screenshot-from-2024-07-08-00-20-10.png" style="width: 420px; height: 108px;" /></p>

<p>将高亮的格子翻转，得到所有行都是回文的。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = </span>[[0,1],[0,1],[0,0]]</p>

<p><span class="example-io"><b>输出：</b>1</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/07/07/screenshot-from-2024-07-08-00-31-23.png" style="width: 300px; height: 100px;" /></p>

<p>将高亮的格子翻转，得到所有列都是回文的。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [[1],[0]]</span></p>

<p><span class="example-io"><b>输出：</b>0</span></p>

<p><strong>解释：</strong></p>

<p>所有行已经是回文的。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m * n &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 1</code></li>
</ul>


    
## 解题方法：行列分别计算

如何判断某一行成为回文行至少要翻转几次？

> 从这一行第一个元素遍历到中间的元素，如果与之相对的那个“回文元素”和这个元素不同，则需要进行一次翻转。

这样就能求出所有行全部成为回文行至少要翻转几次。

同理就能求出所有列全部成为回文列至少要翻转几次。

二者中的最小值即为所求。

+ 时间复杂度$O(nm)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
private:
    int forLine(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m / 2; j++) {
                ans += grid[i][j] != grid[i][m - j - 1];
            }
        }
        return ans;
    }

    int forCol(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n / 2; i++) {
                ans += grid[i][j] != grid[n - i - 1][j];
            }
        }
        return ans;
    }
public:
    int minFlips(vector<vector<int>>& grid) {
        return min(forLine(grid), forCol(grid));
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def forLine(self, grid: List[List[int]]) -> int:
        ans = 0
        n, m = len(grid), len(grid[0])
        for i in range(n):
            for j in range(m // 2):
                ans += grid[i][j] != grid[i][m - j - 1]
        return ans

    def forCol(self, grid: List[List[int]]) -> int:
        ans = 0
        n, m = len(grid), len(grid[0])
        for j in range(m):
            for i in range(n // 2):
                ans += grid[i][j] != grid[n - i - 1][j]
        return ans

    def minFlips(self, grid: List[List[int]]) -> int:
        return min(self.forLine(grid), self.forCol(grid))
```

#### Java

```java
class Solution {
    private int forLine(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m / 2; j++) {
                if (grid[i][j] != grid[i][m - j - 1]) {
                    ans++;
                }
            }
        }
        return ans;
    }

    private int forCol(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int ans = 0;
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n / 2; i++) {
                if (grid[i][j] != grid[n - i - 1][j]) {
                    ans++;
                }
            }
        }
        return ans;
    }

    public int minFlips(int[][] grid) {
        return Math.min(forLine(grid), forCol(grid));
    }
}
```

#### Go

```go
package main

func forLine(grid [][]int) (ans int) {
    n, m := len(grid), len(grid[0])
    for i := 0; i < n; i++ {
        for j := 0; j < m / 2; j++ {
            if grid[i][j] != grid[i][m - j - 1] {
                ans++
            }
        }
    }
    return
}

func forCol(grid [][]int) (ans int) {
    n, m := len(grid), len(grid[0])
    for j := 0; j < m; j++ {
        for i := 0; i < n / 2; i++ {
            if grid[i][j] != grid[n - i - 1][j] {
                ans++
            }
        }
    }
    return
}

func minFlips(grid [][]int) int {
    return min(forLine(grid), forCol(grid))
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/11/15/LeetCode%203239.%E6%9C%80%E5%B0%91%E7%BF%BB%E8%BD%AC%E6%AC%A1%E6%95%B0%E4%BD%BF%E4%BA%8C%E8%BF%9B%E5%88%B6%E7%9F%A9%E9%98%B5%E5%9B%9E%E6%96%87I/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/143796015](https://letmefly.blog.csdn.net/article/details/143796015)

<small>为什么我这次题解写地这么慢，因为我在并行处理行政工作。</small>
