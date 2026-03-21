---
title: 3643.垂直翻转子矩阵：原地修改(模拟)
date: 2026-03-21 14:08:58
tags: [题解, LeetCode, 简单, 数组, 双指针, 矩阵, 模拟]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.com/uploads/2025/07/20/gridexmdrawio.png
---

# 【LetMeFly】3643.垂直翻转子矩阵：原地修改(模拟)

力扣题目链接：[https://leetcode.cn/problems/flip-square-submatrix-vertically/](https://leetcode.cn/problems/flip-square-submatrix-vertically/)

<p>给你一个 <code>m x n</code> 的整数矩阵 <code>grid</code>，以及三个整数 <code>x</code>、<code>y</code> 和 <code>k</code>。</p>

<p>整数 <code>x</code> 和 <code>y</code> 表示一个&nbsp;<strong>正方形子矩阵&nbsp;</strong>的左上角下标，整数 <code>k</code> 表示该正方形子矩阵的边长。</p>

<p>你的任务是垂直翻转子矩阵的行顺序。</p>

<p>返回更新后的矩阵。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2025/07/20/gridexmdrawio.png" style="width: 300px; height: 116px;" />
<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">grid = </span>[[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]<span class="example-io">, x = 1, y = 0, k = 3</span></p>

<p><strong>输出：</strong> <span class="example-io">[[1,2,3,4],[13,14,15,8],[9,10,11,12],[5,6,7,16]]</span></p>

<p><strong>解释：</strong></p>

<p>上图展示了矩阵在变换前后的样子。</p>
</div>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2025/07/20/gridexm2drawio.png" style="width: 350px; height: 68px;" />
<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">grid = [[3,4,2,3],[2,3,4,2]], x = 0, y = 2, k = 2</span></p>

<p><strong>输出：</strong> <span class="example-io">[[3,4,4,2],[2,3,2,3]]</span></p>

<p><strong>解释：</strong></p>

<p>上图展示了矩阵在变换前后的样子。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 100</code></li>
	<li><code>0 &lt;= x &lt; m</code></li>
	<li><code>0 &lt;= y &lt; n</code></li>
	<li><code>1 &lt;= k &lt;= min(m - x, n - y)</code></li>
</ul>


    
## 解题方法：原地修改

令$i$从$0$到$\lfloor\frac{k}2\rfloor$枚举，交换$x+i$行和$x+k-i-1$行的列数为从$y$到$y+k-1$的对应元素。

+ 时间复杂度$O(k^2)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-03-21 14:07:46
 */
class Solution {
public:
    vector<vector<int>> &reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int i = 0; i < k / 2; i++) {
            for (int j = 0; j < k; j++) {
                swap(grid[x + i][y + j], grid[x + k - i - 1][y + j]);
            }
        }
        return grid;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/159318064)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/03/21/LeetCode%203643.%E5%9E%82%E7%9B%B4%E7%BF%BB%E8%BD%AC%E5%AD%90%E7%9F%A9%E9%98%B5/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
