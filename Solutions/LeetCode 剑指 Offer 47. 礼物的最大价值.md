---
title: 剑指 Offer 47.礼物的最大价值
date: 2023-03-08 17:51:04
tags: [题解, LeetCode, 中等, 数组, 动态规划, 矩阵, DP]
---

# 【LetMeFly】剑指 Offer 47.礼物的最大价值

力扣题目链接：[https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/](https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/)

<p>在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> 
<code>[
&nbsp; [1,3,1],
&nbsp; [1,5,1],
&nbsp; [4,2,1]
]</code>
<strong>输出:</strong> <code>12
</code><strong>解释:</strong> 路径 1&rarr;3&rarr;5&rarr;2&rarr;1 可以拿到最多价值的礼物</pre>

<p>&nbsp;</p>

<p>提示：</p>

<ul>
	<li><code>0 &lt; grid.length &lt;= 200</code></li>
	<li><code>0 &lt; grid[0].length &lt;= 200</code></li>
</ul>


## 方法一：动态规划DP

这道题移动规则很简单，只能下移或者右移。

那么对于地图中的某点，其要么是从左边来，要么是从上边来。

我们从头到尾遍历数组（第一行从左到右、第二行从左到右、......）

遍历过程中，将当前位置的值修改为“从左边来的话的最大值”和“从上边来的话的最大值”的最大值，最终返回右下角的值即为答案。

+ 时间复杂度$O(len(grid)\times len(grid[0]))$
+ 空间复杂度$1$，若不允许修改原始数组，则空间复杂度为$O(len(grid)\times len(grid[0]))$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                else if (i == 0 && j != 0) {
                    grid[i][j] += grid[i][j - 1];
                }
                else if (i != 0 && j == 0) {
                    grid[i][j] += grid[i - 1][j];
                }
                else {
                    grid[i][j] += max(grid[i - 1][j], grid[i][j - 1]);
                }
            }
        }
        return grid.back().back();
    }
};
```

#### Python

```python
# from typing import List


class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        for i in range(n):
            for j in range(m):
                if i == 0 and j == 0:
                    continue
                elif i == 0 and j!= 0:
                    grid[i][j] += grid[i][j - 1]
                elif i != 0 and j == 0:
                    grid[i][j] += grid[i - 1][j]
                else:
                    grid[i][j] += max(grid[i - 1][j], grid[i][j - 1])
        return grid[n - 1][m - 1]
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2023/03/08/LeetCode%20%E5%89%91%E6%8C%87%20Offer%2047.%20%E7%A4%BC%E7%89%A9%E7%9A%84%E6%9C%80%E5%A4%A7%E4%BB%B7%E5%80%BC/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129408765](https://letmefly.blog.csdn.net/article/details/129408765)
