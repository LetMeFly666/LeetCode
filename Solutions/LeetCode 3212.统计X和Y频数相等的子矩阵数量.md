---
title: 3212.统计 X 和 Y 频数相等的子矩阵数量：前缀和
date: 2026-03-19 22:20:10
tags: [题解, LeetCode, 中等, 数组, 矩阵, 前缀和]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.com/uploads/2024/06/07/examplems.png
---

# 【LetMeFly】3212.统计 X 和 Y 频数相等的子矩阵数量：前缀和

力扣题目链接：[https://leetcode.cn/problems/count-submatrices-with-equal-frequency-of-x-and-y/](https://leetcode.cn/problems/count-submatrices-with-equal-frequency-of-x-and-y/)

<p>给你一个二维字符矩阵 <code>grid</code>，其中 <code>grid[i][j]</code> 可能是 <code>'X'</code>、<code>'Y'</code> 或 <code>'.'</code>，返回满足以下条件的<span data-keyword="submatrix">子矩阵</span>数量：</p>

<ul>
	<li>包含 <code>grid[0][0]</code></li>
	<li><code>'X'</code> 和 <code>'Y'</code> 的频数相等。</li>
	<li>至少包含一个 <code>'X'</code>。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">grid = [["X","Y","."],["Y",".","."]]</span></p>

<p><strong>输出：</strong> <span class="example-io">3</span></p>

<p><strong>解释：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2024/06/07/examplems.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 175px; height: 350px;" /></strong></p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">grid = [["X","X"],["X","Y"]]</span></p>

<p><strong>输出：</strong> <span class="example-io">0</span></p>

<p><strong>解释：</strong></p>

<p>不存在满足 <code>'X'</code> 和 <code>'Y'</code> 频数相等的子矩阵。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">grid = [[".","."],[".","."]]</span></p>

<p><strong>输出：</strong> <span class="example-io">0</span></p>

<p><strong>解释：</strong></p>

<p>不存在满足至少包含一个 <code>'X'</code> 的子矩阵。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= grid.length, grid[i].length &lt;= 1000</code></li>
	<li><code>grid[i][j]</code> 可能是 <code>'X'</code>、<code>'Y'</code> 或 <code>'.'</code>.</li>
</ul>


> 前置注意事项：本题的子矩阵是必须包含左上角的矩阵。

## 解题方法：前缀和

类似昨天的每日一题[3070.元素和小于等于 k 的子矩阵的数目](https://blog.letmefly.xyz/2026/03/18/LeetCode%203070.%E5%85%83%E7%B4%A0%E5%92%8C%E5%B0%8F%E4%BA%8E%E7%AD%89%E4%BA%8Ek%E7%9A%84%E5%AD%90%E7%9F%A9%E9%98%B5%E7%9A%84%E6%95%B0%E7%9B%AE/)，使用一个$diff$数组存储从$(0,0)$到$(i,j)$的`X - Y`的数量，再额外使用一个数组存储从$(0,0)$到$(i,j)$是否存在`X`(或`Y`)。

遍历过程中维护并更新这两个数组即可。

+ 时间复杂度$O(mn)$
+ 空间复杂度$O(mn)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-03-19 22:19:31
 */
class Solution {
private:
    inline int v(int x) {
        return x == 'X' ? 1 : x == 'Y' ? -1 : 0;
    }
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> hasX(n, vector<bool>(m));  // has x or y
        vector<vector<int>> diff(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i && j) {
                    hasX[i][j] = hasX[i - 1][j] | hasX[i][j - 1] | (grid[i][j] != '.');
                    diff[i][j] = diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1] + v(grid[i][j]);
                } else if (i) {
                    hasX[i][j] = hasX[i - 1][j] | (grid[i][j] != '.');
                    diff[i][j] = diff[i - 1][j] + v(grid[i][j]);
                } else if (j) {
                    hasX[i][j] = hasX[i][j - 1] | (grid[i][j] != '.');
                    diff[i][j] = diff[i][j - 1] + v(grid[i][j]);
                } else {
                    hasX[i][j] = grid[i][j] != '.';
                    diff[i][j] = v(grid[i][j]);
                }
                ans += (!diff[i][j] && hasX[i][j]);
            }
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/159253457)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/03/19/LeetCode%203212.%E7%BB%9F%E8%AE%A1X%E5%92%8CY%E9%A2%91%E6%95%B0%E7%9B%B8%E7%AD%89%E7%9A%84%E5%AD%90%E7%9F%A9%E9%98%B5%E6%95%B0%E9%87%8F/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
