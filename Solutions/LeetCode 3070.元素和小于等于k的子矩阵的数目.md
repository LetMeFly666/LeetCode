---
title: 3070.元素和小于等于 k 的子矩阵的数目：原地修改(前缀和思想)
date: 2026-03-18 22:20:44
tags: [题解, LeetCode, 中等, 数组, 矩阵, 前缀和]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.com/uploads/2024/01/01/example1.png
---

# 【LetMeFly】3070.元素和小于等于 k 的子矩阵的数目：原地修改(前缀和思想)

力扣题目链接：[https://leetcode.cn/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/](https://leetcode.cn/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/)

<p>给你一个下标从 <strong>0</strong> 开始的整数矩阵 <code>grid</code> 和一个整数 <code>k</code>。</p>

<p>返回包含 <code>grid</code> 左上角元素、元素和小于或等于 <code>k</code> 的 <strong><span data-keyword="submatrix">子矩阵</span></strong>的数目。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2024/01/01/example1.png" style="padding: 10px; background: #fff; border-radius: .5rem;" />
<pre>
<strong>输入：</strong>grid = [[7,6,3],[6,6,1]], k = 18
<strong>输出：</strong>4
<strong>解释：</strong>如上图所示，只有 4 个子矩阵满足：包含 grid 的左上角元素，并且元素和小于或等于 18 。</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2024/01/01/example21.png" style="padding: 10px; background: #fff; border-radius: .5rem;" />
<pre>
<strong>输入：</strong>grid = [[7,2,9],[1,5,0],[2,6,6]], k = 20
<strong>输出：</strong>6
<strong>解释：</strong>如上图所示，只有 6 个子矩阵满足：包含 grid 的左上角元素，并且元素和小于或等于 20 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length </code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= n, m &lt;= 1000 </code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 1000</code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：前缀和原地修改

第一层循环从上到下第二层循环从左到右遍历一遍$grid$数组，在遍历过程中把$grid[i][j]$的值修改为从左上角到这个元素的子矩阵元素之和。

怎么$O(1)$时间得到右下角为$(i,j)$的子矩阵之和？借助前面的遍历结果即可：

+ 如果$i$和$j$都大于$0$，则$grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1]$：

    ```
    1 2
    3 4
    ```

    如图矩阵在计算左上角到右下角的$4$的时候，可以借助左上角到$4$上面$2$的元素和 + 左上角到$4$左边$3$的元素和 - 计算重复的左上角到$4$左上角$1$的元素和。

+ 如果$i$大于$0$而$j$等于$0$，则直接加上这个元素上一行的结果即可；
+ 如果$j$大于$0$而$i$等于$0$同理。

优化：如果到$grid[i][j]$的子矩阵元素和已经大于$k$，那么再往右和往下的更大子矩阵的和一定更大，可跳过。

+ 时间复杂度$O(mn)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-03-18 22:19:52
 */
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i && j) {
                    grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
                } else if (i) {
                    grid[i][j] += grid[i - 1][j];
                } else if (j) {
                    grid[i][j] += grid[i][j - 1];
                }
                ans += grid[i][j] <= k;
            }
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/159214883)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/03/18/LeetCode%203070.%E5%85%83%E7%B4%A0%E5%92%8C%E5%B0%8F%E4%BA%8E%E7%AD%89%E4%BA%8Ek%E7%9A%84%E5%AD%90%E7%9F%A9%E9%98%B5%E7%9A%84%E6%95%B0%E7%9B%AE/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
