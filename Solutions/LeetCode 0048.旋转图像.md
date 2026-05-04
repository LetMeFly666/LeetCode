---
title: 48.旋转图像：两次对称操作
date: 2026-05-04 11:53:57
tags: [题解, LeetCode, 中等, 数组, 数学, 矩阵, 原地, 原地修改]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.com/uploads/2020/08/28/mat1.jpg
---

# 【LetMeFly】48.旋转图像：两次对称操作

力扣题目链接：[https://leetcode.cn/problems/rotate-image/](https://leetcode.cn/problems/rotate-image/)

<p>给定一个 <em>n&nbsp;</em>×&nbsp;<em>n</em> 的二维矩阵&nbsp;<code>matrix</code> 表示一个图像。请你将图像顺时针旋转 90 度。</p>

<p>你必须在<strong><a href="https://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95" target="_blank"> 原地</a></strong> 旋转图像，这意味着你需要直接修改输入的二维矩阵。<strong>请不要 </strong>使用另一个矩阵来旋转图像。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/28/mat1.jpg" style="height: 188px; width: 500px;" />
<pre>
<strong>输入：</strong>matrix = [[1,2,3],[4,5,6],[7,8,9]]
<strong>输出：</strong>[[7,4,1],[8,5,2],[9,6,3]]
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/28/mat2.jpg" style="height: 201px; width: 500px;" />
<pre>
<strong>输入：</strong>matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
<strong>输出：</strong>[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == matrix.length == matrix[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 20</code></li>
	<li><code>-1000 &lt;= matrix[i][j] &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>


    
## 解题方法：两次对称

先将矩阵按对角线做一次对称操作，再将矩阵按竖直中线做一次对称操作即可。

```
\                   |
 1 2 3            1 4 7            7 4 1
  \                 |
 4 5 6    ===>    2 5 8    ===>    8 5 2
    \               |
 7 8 9            3 6 9            9 6 3
      \             |
    对角线        竖直中线       顺时针旋转完成
```

+ 时间复杂度$O(n^2)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-05-04 11:52:40
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/160763354)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/05/04/LeetCode%200048.%E6%97%8B%E8%BD%AC%E5%9B%BE%E5%83%8F/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
