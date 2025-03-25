---
title: 2711.对角线上不同值的数量差：O(mn)时间O(1)空间 - 位运算优化 - C++/Go双百版本 - 三种方法(一步步优化)
date: 2025-03-25 21:38:46
tags: [题解, LeetCode, 中等, 数组, 哈希表, set, 矩阵, 前缀和, 位运算]
categories: [题解, LeetCode]
---

# 【LetMeFly】2711.对角线上不同值的数量差：O(mn)时间O(1)空间 - 位运算优化 - C++/Go双百版本 - 三种方法(一步步优化)

力扣题目链接：[https://leetcode.cn/problems/difference-of-number-of-distinct-values-on-diagonals/](https://leetcode.cn/problems/difference-of-number-of-distinct-values-on-diagonals/)

<p>给你一个下标从 <code>0</code> 开始、大小为 <code>m x n</code> 的二维矩阵 <code>grid</code> ，请你求解大小同样为 <code>m x n</code> 的答案矩阵 <code>answer</code> 。</p>

<p>矩阵 <code>answer</code> 中每个单元格 <code>(r, c)</code> 的值可以按下述方式进行计算：</p>

<ul>
	<li>令 <code>topLeft[r][c]</code> 为矩阵 <code>grid</code> 中单元格 <code>(r, c)</code> 左上角对角线上 <strong>不同值</strong> 的数量。</li>
	<li>令 <code>bottomRight[r][c]</code> 为矩阵 <code>grid</code> 中单元格 <code>(r, c)</code> 右下角对角线上 <strong>不同值</strong> 的数量。</li>
</ul>

<p>然后 <code>answer[r][c] = |topLeft[r][c] - bottomRight[r][c]|</code> 。</p>

<p>返回矩阵 <code>answer</code> 。</p>

<p><strong>矩阵对角线</strong> 是从最顶行或最左列的某个单元格开始，向右下方向走到矩阵末尾的对角线。</p>

<p>如果单元格 <code>(r1, c1)</code> 和单元格 <code>(r, c) </code>属于同一条对角线且 <code>r1 &lt; r</code> ，则单元格 <code>(r1, c1)</code> 属于单元格 <code>(r, c)</code> 的左上对角线。类似地，可以定义右下对角线。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/04/19/ex2.png" style="width: 786px; height: 121px;" />
<pre>
<strong>输入：</strong>grid = [[1,2,3],[3,1,5],[3,2,1]]
<strong>输出：</strong>[[1,1,0],[1,0,1],[0,1,1]]
<strong>解释：</strong>第 1 个图表示最初的矩阵 grid 。&nbsp;
第 2 个图表示对单元格 (0,0) 计算，其中蓝色单元格是位于右下对角线的单元格。
第 3 个图表示对单元格 (1,2) 计算，其中红色单元格是位于左上对角线的单元格。
第 4 个图表示对单元格 (1,1) 计算，其中蓝色单元格是位于右下对角线的单元格，红色单元格是位于左上对角线的单元格。
- 单元格 (0,0) 的右下对角线包含 [1,1] ，而左上对角线包含 [] 。对应答案是 |1 - 0| = 1 。
- 单元格 (1,2) 的右下对角线包含 [] ，而左上对角线包含 [2] 。对应答案是 |0 - 1| = 1 。
- 单元格 (1,1) 的右下对角线包含 [1] ，而左上对角线包含 [1] 。对应答案是 |1 - 1| = 0 。
其他单元格的对应答案也可以按照这样的流程进行计算。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>grid = [[1]]
<strong>输出：</strong>[[0]]
<strong>解释：</strong>- 单元格 (0,0) 的右下对角线包含 [] ，左上对角线包含 [] 。对应答案是 |0 - 0| = 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n, grid[i][j] &lt;= 50</code></li>
</ul>

挺不错的一道题。

## 解题方法一：暴力模拟

使用$O(mn)$的时间复杂度枚举每个起点，对于每个起点：

> 使用两个哈希表（集合），分别统计这个起点左上角和右下角有多少个不同的元素。
>
> 怎么统计呢？从$k=1$开始，到$i + d$或$j + d$超出合法边界为止，直接将$grid[i + d][j + d]$插入到哈希表中。

知道了每个起点左上角和右下角分别有多少个不同的元素，就知道答案了。

+ 时间复杂度$O(mn\times \min(m, n))$
+ 空间复杂度$O(\min(m, n))$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-25 16:52:02
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-25 17:42:27
 */
class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        vector<vector<int>> ans(grid.size(), vector<int>(grid[0].size()));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                unordered_set<int> l, r;
                for (int k = 1; i - k >= 0 && j - k >= 0; k++) {
                    l.insert(grid[i - k][j - k]);
                }
                for (int k = 1; i + k < grid.size() && j + k < grid[0].size(); k++) {
                    r.insert(grid[i + k][j + k]);
                }
                ans[i][j] = abs(int(l.size() - r.size()));
            }
        }
        return ans;
    }
};
```

## 解题方法二：前缀和优化

方法一中我们需要从每个起点开始往两个方向遍历，但其实很多数被统计了很多次。

怎么优化呢？前缀和呗。从第一行或第一列的共$m + n - 1$个元素开始向右下角遍历，遍历过程中使用哈希表统计当前一共遍历到了多少个元素，并直接将结果写入$ans[i][j]$中。

也就是说，当前$ans[i][j]$代表$grid[i][j]$左上角的那条线一共有多少种不同的元素。

当从左上角遍历到右下角后，清空哈希表，再次向左上角折回，并在折回过程中统计右下角一共有多少种元素。

左上角元素的种类数减去右下角元素的种类数即为当前位置对应的答案。

+ 时间复杂度$O(mn)$
+ 空间复杂度$O(\min(m, n))$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-25 19:44:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-25 21:04:00
 */
class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for (int k = 0; k < m + n - 1; k++) {
            int i = k < m ? 0 : k - m + 1, j = k < m ? k : 0;
            unordered_set<int> se;
            int d = 0;
            for (; i + d < n && j + d < m; d++) {
                ans[i + d][j + d] = se.size();
                se.insert(grid[i + d][j + d]);
            }
            se.clear();
            for (d--; d >= 0; d--) {
                ans[i + d][j + d] = abs(int(ans[i + d][j + d] - se.size()));
                se.insert(grid[i + d][j + d]);
            }
        }
        return ans;
    }
};
```

## 解题方法三：位运算优化

很容易注意到，$grid[i][j]$的范围是$1$到$50$，因此我们可以直接**使用64位整数的每一位表示每个数值是否出现过**。

这样，加上将临时结果存放在答案数组中，我们就做到了$O(1)$额外空间得出答案了。

+ 时间复杂度$O(mn)$
+ 空间复杂度$O(1)$，力扣返回值不记入算法空间复杂度

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-25 21:06:53
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-25 21:17:48
 * @Description: AC,100.00%,100.00%
 */
typedef long long ll;


class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for (int k = 0; k < m + n - 1; k++) {
            int i = k < m ? 0 : k - m + 1, j = k < m ? k : 0;
            ll se = 0;
            int d = 0;
            for (; i + d < n && j + d < m; d++) {
                ans[i + d][j + d] = __builtin_popcountll(se);
                se |= 1LL << grid[i + d][j + d];
            }
            se = 0;
            for (d--; d >= 0; d--) {
                ans[i + d][j + d] = abs(ans[i + d][j + d] - __builtin_popcountll(se));
                se |= 1LL << grid[i + d][j + d];
            }
        }
        return ans;
    }
};
```

+ 执行用时分布3ms，击败100.00%
+ 消耗内存分布28.95MB，击败100.00%

#### Python

```python
'''
Author: LetMeFly
Date: 2025-03-25 21:18:16
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-25 21:23:09
'''
from typing import List

class Solution:
    def differenceOfDistinctValues(self, grid: List[List[int]]) -> List[List[int]]:
        n, m = len(grid), len(grid[0])
        ans = [[0] * m for _ in range(n)]
        for k in range(m + n - 1):
            i = 0 if k < m else k - m + 1
            j = k if k < m else 0
            se = d = 0
            while i + d < n and j + d < m:
                ans[i + d][j + d] = se.bit_count()  # python10才有
                se |= 1 << grid[i + d][j + d]
                d += 1
            se = 0
            d -= 1
            while d >= 0:
                ans[i + d][j + d] = abs(ans[i + d][j + d] - se.bit_count())
                se |= 1 << grid[i + d][j + d]
                d -= 1
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-03-25 21:23:51
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-25 21:28:30
 */
class Solution {
    public int[][] differenceOfDistinctValues(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int[][] ans = new int[n][m];
        for (int k = 0; k < m + n - 1; k++) {
            int i = k < m ? 0 : k - m + 1;
            int j = k < m ? k : 0;
            long se = 0;
            int d = 0;
            for (; i + d < n && j + d < m; d++) {
                ans[i + d][j + d] = Long.bitCount(se);
                se |= 1L << grid[i + d][j + d];
            }
            se = 0;
            for (d--; d >= 0; d--) {
                ans[i + d][j + d] = Math.abs(ans[i + d][j + d] - Long.bitCount(se));
                se |= 1L << grid[i + d][j + d];
            }
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-03-25 21:29:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-25 21:37:43
 */
package main

import "math/bits"

func abs2711(a int) int {
    if a < 0 {
        return -a
    }
    return a
}

func differenceOfDistinctValues(grid [][]int) [][]int {
    n, m := len(grid), len(grid[0])
    ans := make([][]int, n)
    for i := range ans {
        ans[i] = make([]int, m)
    }
    for k := 0; k < m + n - 1; k++ {
        var i, j int
        if k < m {
            i, j = 0, k
        } else {
            i, j = k - m + 1, 0
        }
        se := uint64(0)
        d := 0
        for ; i + d < n && j + d < m; d++ {
            ans[i + d][j + d] = bits.OnesCount64(se)
            se |= uint64(1) << grid[i + d][j + d]
        }
        se = 0
        for d--; d >= 0; d-- {
            ans[i + d][j + d] = abs2711(ans[i + d][j + d] - bits.OnesCount64(se))
            se |= uint64(1) << grid[i + d][j + d]
        }
    }
    return ans
}
```

+ 执行用时分布0ms，击败100.00%
+ 消耗内存分布8.31MB，击败100.00%

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/146514119)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/03/25/LeetCode%202711.%E5%AF%B9%E8%A7%92%E7%BA%BF%E4%B8%8A%E4%B8%8D%E5%90%8C%E5%80%BC%E7%9A%84%E6%95%B0%E9%87%8F%E5%B7%AE/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
