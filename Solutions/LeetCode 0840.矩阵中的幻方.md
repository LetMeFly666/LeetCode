---
title: 840.矩阵中的幻方：模拟（+小小位运算）
date: 2025-12-30 13:40:02
tags: [题解, LeetCode, 中等, 数组, 哈希表, 数学, 矩阵, 模拟, 位运算]
categories: [题解, LeetCode]
---

# 【LetMeFly】840.矩阵中的幻方：模拟（+小小位运算）

力扣题目链接：[https://leetcode.cn/problems/magic-squares-in-grid/](https://leetcode.cn/problems/magic-squares-in-grid/)

<p><code>3 x 3</code> 的幻方是一个填充有&nbsp;<strong>从 <code>1</code> 到 <code>9</code>&nbsp;</strong> 的不同数字的 <code>3 x 3</code> 矩阵，其中每行，每列以及两条对角线上的各数之和都相等。</p>

<p>给定一个由整数组成的<code>row x col</code>&nbsp;的 <code>grid</code>，其中有多少个&nbsp;<code>3 × 3</code> 的 “幻方” 子矩阵？</p>

<p>注意：虽然幻方只能包含 1 到 9 的数字，但&nbsp;<code>grid</code> 可以包含最多15的数字。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2020/09/11/magic_main.jpg" /></p>

<pre>
<strong>输入: </strong>grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]
<strong>输出: </strong>1
<strong>解释: </strong>
下面的子矩阵是一个 3 x 3 的幻方：
<img src="https://assets.leetcode.com/uploads/2020/09/11/magic_valid.jpg" />
而这一个不是：
<img src="https://assets.leetcode.com/uploads/2020/09/11/magic_invalid.jpg" />
总的来说，在本示例所给定的矩阵中只有一个 3 x 3 的幻方子矩阵。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> grid = [[8]]
<strong>输出:</strong> 0
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>row == grid.length</code></li>
	<li><code>col == grid[i].length</code></li>
	<li><code>1 &lt;= row, col &lt;= 10</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 15</code></li>
</ul>


    
## 解题方法：模拟

主函数中枚举每个`3x3`矩阵的右下角下表，写一个辅助函数计算右下角坐标为`(i, j)`的矩阵是否是`幻方`。

这个函数怎么写呢？

对于是否由1-9组成，可以使用位运算，将所有数与初始值为0的mask按位或，如出现3则$mask |= 1 << 3$，最终看$mask$是否为$1<<10-2$。

我们还可以使用两个大小为3的数组分别记录每一行和每一列的和，看他们是否相等、以及是否和主对角线和副对角线的和相等。

+ 时间复杂度$O(col\times row)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2025-12-30 13:25:00
 */
class Solution {
private:
    inline bool is(vector<vector<int>>& grid, int i, int j) {
        int mask = 0;
        int rowCnt[3] = {0}, colCnt[3] = {0};
        for (int di = 0; di < 3; di++) {
            for (int dj = 0; dj < 3; dj++) {
                int v = grid[i - di][j - dj];
                mask |= 1 << v;
                rowCnt[di] += v;
                colCnt[dj] += v;
            }
        }
        if (mask != (1 << 10) - 2) {  // (1<<10)-1：1111111111（10个1）而mask没有或上1<<0所以再-1
            return false;
        }

        int cnt = rowCnt[0];
        for (int d = 0; d < 3; d++) {
            if (rowCnt[d] != cnt || colCnt[d] != cnt) {
                return false;
            }
        }
        if (grid[i][j] + grid[i - 1][j - 1] + grid[i - 2][j - 2] != cnt) {
            return false;
        }
        if (grid[i - 2][j] + grid[i - 1][j - 1] + grid[i][j - 2] != cnt) {
            return false;
        }
        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 2; i < n; i++) {
            for (int j = 2; j < m; j++) {
                ans += is(grid, i, j);
            }
        }
        return ans;
    }
};
```

#### Python

```python
'''
LastEditTime: 2025-12-30 13:38:58
'''
from typing import List

class Solution:
    def ok(self, grid: List[List[int]], i: int, j: int) -> bool:
        mask = 0
        colCnt = [0] * 3
        rowCnt = [0] * 3
        for di in range(3):
            for dj in range(3):
                v = grid[i - di][j - dj]
                mask |= 1 << v
                rowCnt[di] += v
                colCnt[dj] += v
        if mask != (1 << 10) - 2:
            return False
        cnt = grid[i][j] + grid[i - 1][j - 1] + grid[i - 2][j - 2]
        if grid[i - 2][j] + grid[i - 1][j - 1] + grid[i][j - 2] != cnt:
            return False
        if any(c != cnt for c in colCnt):
            return False
        if any(r != cnt for r in rowCnt):
            return False
        return True
    
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        return sum(self.ok(grid, i, j) for j in range(2, len(grid[0])) for i in range(2, len(grid)))
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/156429151)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/12/30/LeetCode%200840.%E7%9F%A9%E9%98%B5%E4%B8%AD%E7%9A%84%E5%B9%BB%E6%96%B9/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
