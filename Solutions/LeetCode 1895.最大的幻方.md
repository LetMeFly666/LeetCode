---
title: 1895.最大的幻方：暴力中来点前缀和优化
date: 2026-01-18 23:19:46
tags: [题解, LeetCode, 中等, 数组, 矩阵, 前缀和]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.com/uploads/2021/05/29/magicsquare-grid.jpg
---

# 【LetMeFly】1895.最大的幻方：暴力中来点前缀和优化

力扣题目链接：[https://leetcode.cn/problems/largest-magic-square/](https://leetcode.cn/problems/largest-magic-square/)

<p>一个 <code>k x k</code> 的<strong> 幻方</strong> 指的是一个 <code>k x k</code> 填满整数的方格阵，且每一行、每一列以及两条对角线的和 <strong>全部</strong><strong>相等</strong> 。幻方中的整数 <strong>不需要互不相同</strong> 。显然，每个 <code>1 x 1</code> 的方格都是一个幻方。</p>

<p>给你一个 <code>m x n</code> 的整数矩阵 <code>grid</code> ，请你返回矩阵中 <strong>最大幻方</strong> 的 <strong>尺寸</strong> （即边长 <code>k</code>）。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/29/magicsquare-grid.jpg" style="width: 413px; height: 335px;">
<pre><b>输入：</b>grid = [[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]
<b>输出：</b>3
<b>解释：</b>最大幻方尺寸为 3 。
每一行，每一列以及两条对角线的和都等于 12 。
- 每一行的和：5+1+6 = 5+4+3 = 2+7+3 = 12
- 每一列的和：5+5+2 = 1+4+7 = 6+3+3 = 12
- 对角线的和：5+4+3 = 6+4+2 = 12
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/29/magicsquare2-grid.jpg" style="width: 333px; height: 255px;">
<pre><b>输入：</b>grid = [[5,1,3,1],[9,3,3,1],[1,3,3,8]]
<b>输出：</b>2
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 10<sup>6</sup></code></li>
</ul>


    
## 解题方法：暴力中来点前缀和优化

最为暴力的做法是什么？

1. 枚举边长$k$（可从大到小枚举），复杂度$O(\min(m, n))$
2. 枚举幻方左上角，复杂度$O(mn)$
3. 对于一个方块，判断其是否为幻方，复杂度$O(k^2)$

总计复杂度$O(n^5)$，而$50^5=312,500,000=3.12e8$会超时，所以需要想办法优化一层循环。

不难发现，我们在判断一个方块是否为幻方时要暴力计算每一行之和，而一行的元素和使用前缀和即可$O(1)$算出，所以我们可以预处理计算出一个横向上的前缀和以及一个纵向上的前缀和（斜向由于只有两条所以无需前缀和加速）。

这样，时间复杂度就降低为了$O(n^4)$，而$50^4=6,250,000=6.25e6$可以接受。

+ 时间复杂度$O(mn\cdot\min(m,n))$
+ 空间复杂度$O(mn)$

这道题要细心考虑边界问题。

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-01-18 23:17:50
 */
class Solution {
private:
    vector<vector<int>> rowSum, colSum;

    bool ok(vector<vector<int>>& grid, int x, int y, int l) {
        int cnt = 0, cntRev = 0;
        for (int i = 0; i < l; i++) {
            cnt += grid[x + i][y + i];
            cntRev += grid[x + i][y + l - i - 1];  // 易错
        }
        if (cnt != cntRev) {
            return false;
        }
        for (int i = 0; i < l; i++) {
            if (rowSum[x + i][y + l] - rowSum[x + i][y] != cnt) {
                return false;
            }
            if (colSum[x + l][y + i] - colSum[x][y + i] != cnt) {
                return false;
            }
        }
        return true;
    }
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        rowSum.resize(n, vector<int>(m + 1));
        colSum.resize(n + 1, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rowSum[i][j + 1] = rowSum[i][j] + grid[i][j];
                colSum[i + 1][j] = colSum[i][j] + grid[i][j];
            }
        }

        for (int k = n; k > 1; k--) {
            for (int i = 0; i + k <= n; i++) {
                for (int j = 0; j + k <= m; j++) {
                    if (ok(grid, i, j, k)) {
                        return k;
                    }
                }
            }
        }
        return 1;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/157104818)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/01/18/LeetCode%201895.%E6%9C%80%E5%A4%A7%E7%9A%84%E5%B9%BB%E6%96%B9/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
