---
title: 3567.子矩阵的最小绝对差：暴力模拟
date: 2026-03-20 23:25:20
tags: [题解, LeetCode, 中等, 数组, 矩阵, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】3567.子矩阵的最小绝对差：暴力模拟

力扣题目链接：[https://leetcode.cn/problems/minimum-absolute-difference-in-sliding-submatrix/](https://leetcode.cn/problems/minimum-absolute-difference-in-sliding-submatrix/)

<p>给你一个 <code>m x n</code> 的整数矩阵 <code>grid</code> 和一个整数 <code>k</code>。</p>

<p>对于矩阵 <code>grid</code> 中的每个连续的 <code>k x k</code> <strong>子矩阵</strong>，计算其中任意两个&nbsp;<strong>不同</strong>值 之间的&nbsp;<strong>最小绝对差&nbsp;</strong>。</p>

<p>返回一个大小为 <code>(m - k + 1) x (n - k + 1)</code> 的二维数组 <code>ans</code>，其中 <code>ans[i][j]</code> 表示以 <code>grid</code> 中坐标 <code>(i, j)</code> 为左上角的子矩阵的最小绝对差。</p>

<p><strong>注意</strong>：如果子矩阵中的所有元素都相同，则答案为 0。</p>

<p>子矩阵 <code>(x1, y1, x2, y2)</code> 是一个由选择矩阵中所有满足 <code>x1 &lt;= x &lt;= x2</code> 且 <code>y1 &lt;= y &lt;= y2</code> 的单元格 <code>matrix[x][y]</code> 组成的矩阵。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">grid = [[1,8],[3,-2]], k = 2</span></p>

<p><strong>输出：</strong> <span class="example-io">[[2]]</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>只有一个可能的 <code>k x k</code> 子矩阵：<code><span class="example-io">[[1, 8], [3, -2]]</span></code>。</li>
	<li>子矩阵中的不同值为 <code>[1, 8, 3, -2]</code>。</li>
	<li>子矩阵中的最小绝对差为 <code>|1 - 3| = 2</code>。因此，答案为 <code>[[2]]</code>。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">grid = [[3,-1]], k = 1</span></p>

<p><strong>输出：</strong> <span class="example-io">[[0,0]]</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>每个 <code>k x k</code> 子矩阵中只有一个不同的元素。</li>
	<li>因此，答案为 <code>[[0, 0]]</code>。</li>
</ul>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">grid = [[1,-2,3],[2,3,5]], k = 2</span></p>

<p><strong>输出：</strong> <span class="example-io">[[1,2]]</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>有两个可能的 <code>k × k</code> 子矩阵：

	<ul>
		<li>以 <code>(0, 0)</code> 为起点的子矩阵：<code>[[1, -2], [2, 3]]</code>。

		<ul>
			<li>子矩阵中的不同值为 <code>[1, -2, 2, 3]</code>。</li>
			<li>子矩阵中的最小绝对差为 <code>|1 - 2| = 1</code>。</li>
		</ul>
		</li>
		<li>以 <code>(0, 1)</code> 为起点的子矩阵：<code>[[-2, 3], [3, 5]]</code>。
		<ul>
			<li>子矩阵中的不同值为 <code>[-2, 3, 5]</code>。</li>
			<li>子矩阵中的最小绝对差为 <code>|3 - 5| = 2</code>。</li>
		</ul>
		</li>
	</ul>
	</li>
	<li>因此，答案为 <code>[[1, 2]]</code>。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= m == grid.length &lt;= 30</code></li>
	<li><code>1 &lt;= n == grid[i].length &lt;= 30</code></li>
	<li><code>-10<sup>5</sup> &lt;= grid[i][j] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= min(m, n)</code></li>
</ul>


    
## 解题方法：暴力模拟

大小为$n\times m$的矩阵共有$(n-k+1)\times(m-k+1)$个$k\times k$大小的子矩阵，枚举每个子矩阵并将子矩阵所有元素放入一个临时数组，对这个数组排序看相邻且不同元素的最小diff。

+ 时间复杂度$O((n-k)(m-k)k^2\log k)$
+ 空间复杂度$O(k^2)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-03-20 23:24:53
 */
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1));
        for (int i = 0; i < n - k + 1; i++) {
            for (int j = 0; j < m - k + 1; j++) {
                vector<int> vals;
                vals.reserve(k * k);
                for (int di = 0; di < k; di++) {
                    for (int dj = 0; dj < k; dj++) {
                        vals.push_back(grid[i + di][j + dj]);
                    }
                }
                sort(vals.begin(), vals.end());
                int diff = 1000000;
                for (int i = 1; i < k * k; i++) {
                    int this_diff = vals[i] - vals[i - 1];
                    if (this_diff) {
                        diff = min(diff, abs(this_diff));
                    }
                }
                ans[i][j] = diff == 1000000 ? 0 : diff;
            }
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/159291000)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/03/20/LeetCode%203567.%E5%AD%90%E7%9F%A9%E9%98%B5%E7%9A%84%E6%9C%80%E5%B0%8F%E7%BB%9D%E5%AF%B9%E5%B7%AE/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
