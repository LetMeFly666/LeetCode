---
title: 1878.矩阵中最大的三个菱形和：斜向前缀和
date: 2026-03-17 13:31:48
tags: [题解, LeetCode, 中等, 数组, 数学, 矩阵, 前缀和, 排序, 堆（优先队列）]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.com/uploads/2021/04/23/pc73-q4-desc-2.png
---

# 【LetMeFly】1878.矩阵中最大的三个菱形和：斜向前缀和

力扣题目链接：[https://leetcode.cn/problems/get-biggest-three-rhombus-sums-in-a-grid/](https://leetcode.cn/problems/get-biggest-three-rhombus-sums-in-a-grid/)

<p>给你一个 <code>m x n</code> 的整数矩阵 <code>grid</code> 。</p>

<p><strong>菱形和</strong> 指的是 <code>grid</code> 中一个正菱形 <strong>边界</strong> 上的元素之和。本题中的菱形必须为正方形旋转45度，且四个角都在一个格子当中。下图是四个可行的菱形，每个菱形和应该包含的格子都用了相应颜色标注在图中。</p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/23/pc73-q4-desc-2.png" style="width: 385px; height: 385px;" />
<p> </p>

<p>注意，菱形可以是一个面积为 0 的区域，如上图中右下角的紫色菱形所示。</p>

<p>请你按照 <strong>降序</strong> 返回 <code>grid</code> 中三个最大的 <strong>互不相同的菱形和</strong> 。如果不同的和少于三个，则将它们全部返回。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/23/pc73-q4-ex1.png" style="width: 360px; height: 361px;" />
<pre>
<b>输入：</b>grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]
<b>输出：</b>[228,216,211]
<b>解释：</b>最大的三个菱形和如上图所示。
- 蓝色：20 + 3 + 200 + 5 = 228
- 红色：200 + 2 + 10 + 4 = 216
- 绿色：5 + 200 + 4 + 2 = 211
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/23/pc73-q4-ex2.png" style="width: 217px; height: 217px;" />
<pre>
<b>输入：</b>grid = [[1,2,3],[4,5,6],[7,8,9]]
<b>输出：</b>[20,9,8]
<b>解释：</b>最大的三个菱形和如上图所示。
- 蓝色：4 + 2 + 6 + 8 = 20
- 红色：9 （右下角红色的面积为 0 的菱形）
- 绿色：8 （下方中央面积为 0 的菱形）
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>grid = [[7,7,7]]
<b>输出：</b>[7]
<b>解释：</b>所有三个可能的菱形和都相同，所以返回 [7] 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 <= m, n <= 100</code></li>
	<li><code>1 <= grid[i][j] <= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法：斜向前缀和

严格按照以下约定计算和使用前缀和：

+ ↘ `(i, j) -> (x, y)`: $diag[x+1][y+1] - diag[i][j]$
+ ↗ `(i, j) -> (x, y)`: $anti[i+1][j] - anti[x][y+1]$

遍历一遍原始数组我们即可得到前缀和数组。

然后枚举每个菱形的中心和菱形的二分之一对角线长度$k$，依据前缀和计算4条边的长度，三个变量维护三个最大的不同周长。

+ 时间复杂度$O(nm\min(m,n))$
+ 空间复杂度$O(mn)$

主要是很多边界值加一减一的要细心。

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-03-17 00:04:02
 */
/*
↘ (i, j) -> (x, y): diag[x+1][y+1] - diag[i][j]
↗ (i, j) -> (x, y): anti[i+1][j] - anti[x][y+1]
*/
class Solution {
private:
    int x = 0, y = 0, z = 0;  // 三大
    vector<vector<int>> diag, anti;

    void update(int v) {
        if (v > x) {
            z = y, y = x, x = v;
        } else if (v < x && v > y) {
            z = y, y = v;
        } else if (v < y && v > z) {
            z = v;
        }
    }

    void calc(int i, int j, int k) {
        if (!k) {
            return update(diag[i + 1][j + 1] - diag[i][j]);
        }
        // 上：i - k, j
        // 下：i + k, j
        // 左：i, j - k
        // 右：i, j + k
        int val = 0
            + diag[i][j + k] - diag[i - k][j]                  // ↘ [上, 右)：(i-k, j)->(i, j+k) | (i-k,j)->(i-1, j+k-1)
            + diag[i + k + 1][j + 1] - diag[i + 1][j - k + 1]  // ↘ (左, 下]：(i,j-k)->(i+k,j) | (i+1,j-k+1)->(i+k,j)
            + anti[i + 1][j - k] - anti[i - k + 1][j]          // ↗ [左, 上)：(i,j-k)->(i-k,j) | (i,j-k)->(i-k+1,j-1)
            + anti[i + k][j + 1] - anti[i][j + k + 1];         // ↗ (下, 右]：(i+k,j)->(i,j+k) | (i+k-1,j+1)->(i,j+k)
        update(val);
    }
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        diag = vector<vector<int>>(n + 1, vector<int>(m + 1));  // ↘
        anti = vector<vector<int>>(n + 1, vector<int>(m + 1));  // ↖
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                diag[i + 1][j + 1] = diag[i][j] + grid[i][j];
                anti[i + 1][j] = anti[i][j + 1] + grid[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0, max_k = min(i, min(j, min(n - i - 1, m - j - 1))); k <= max_k; k++) {
                    calc(i, j, k);
                }
            }
        }

        vector<int> ans;
        if (x) {
            ans.push_back(x);
        }
        if (y) {
            ans.push_back(y);
        }
        if (z) {
            ans.push_back(z);
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/159162029)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/03/17/LeetCode%201878.%E7%9F%A9%E9%98%B5%E4%B8%AD%E6%9C%80%E5%A4%A7%E7%9A%84%E4%B8%89%E4%B8%AA%E8%8F%B1%E5%BD%A2%E5%92%8C/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
