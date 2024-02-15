---
title: 2397.被列覆盖的最多行数
date: 2024-01-04 21:19:10
tags: [题解, LeetCode, 中等, 位运算, 数组, 回溯, 二进制, 二进制枚举, 枚举, 矩阵]
---

# 【LetMeFly】2397.被列覆盖的最多行数：二进制枚举

力扣题目链接：[https://leetcode.cn/problems/maximum-rows-covered-by-columns/](https://leetcode.cn/problems/maximum-rows-covered-by-columns/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的&nbsp;<code>m x n</code>&nbsp;二进制矩阵&nbsp;<code>mat</code>&nbsp;和一个整数&nbsp;<code>cols</code>&nbsp;，表示你需要选出的列数。</p>

<p>如果一行中，所有的 <code>1</code> 都被你选中的列所覆盖，那么我们称这一行 <strong>被覆盖</strong>&nbsp;了。</p>

<p>请你返回在选择 <code>cols</code>&nbsp;列的情况下，<strong>被覆盖</strong>&nbsp;的行数 <strong>最大</strong>&nbsp;为多少。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2022/07/14/rowscovered.png" style="width: 250px; height: 417px;"></strong></p>

<pre><b>输入：</b>mat = [[0,0,0],[1,0,1],[0,1,1],[0,0,1]], cols = 2
<b>输出：</b>3
<strong>解释：</strong>
如上图所示，覆盖 3 行的一种可行办法是选择第 0 和第 2 列。
可以看出，不存在大于 3 行被覆盖的方案，所以我们返回 3 。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2022/07/14/rowscovered2.png" style="width: 83px; height: 247px;"></strong></p>

<pre><b>输入：</b>mat = [[1],[0]], cols = 1
<b>输出：</b>2
<strong>解释：</strong>
选择唯一的一列，两行都被覆盖了，原因是整个矩阵都被覆盖了。
所以我们返回 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 12</code></li>
	<li><code>mat[i][j]</code>&nbsp;要么是&nbsp;<code>0</code>&nbsp;要么是&nbsp;<code>1</code>&nbsp;。</li>
	<li><code>1 &lt;= cols &lt;= n</code></li>
</ul>


    
## 方法一：二进制枚举

使用二进制枚举每一列“选中与不选”的情况。对于某种选择情况：

> 首先选择的列的要总数为numSelect。接下来开始遍历每一行。对于某一行：
>
> > 遍历这一行的每一个元素。如果矩阵中这个元素为1但是没有选择这一行，则此行无效。否则遍历完成时此行累加。
>
> 累加合法的行，即为“选择”下的结果。

所有合法选择中的最大结果即为答案。

+ 时间复杂度$O(2^n\times mn)$，其中$matrix$有$m$行$n$列
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int ans = 0;
        int m = matrix.size(), n = matrix[0].size();
        for (int state = 0; state < (1 << n); state++) {
            if (__builtin_popcount(state) != numSelect) {
                continue;
            }
            int thisAns = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][j] && !(state & (1 << j))) {
                        goto loop;
                    }
                }
                thisAns++;
                loop:;
            }
            ans = max(ans, thisAns);
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def maximumRows(self, matrix: List[List[int]], numSelect: int) -> int:
        ans = 0
        m, n = len(matrix), len(matrix[0])
        for state in range(1 << n):
            if bin(state).count('1') != numSelect:
                continue
            thisAns = 0
            for i in range(m):
                can = True
                for j in range(n):
                    if matrix[i][j] and not state & (1 << j):
                        can = False
                        break
                thisAns += can
            ans = max(ans, thisAns)
        return ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/01/04/LeetCode%202397.%E8%A2%AB%E5%88%97%E8%A6%86%E7%9B%96%E7%9A%84%E6%9C%80%E5%A4%9A%E8%A1%8C%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135396524](https://letmefly.blog.csdn.net/article/details/135396524)
