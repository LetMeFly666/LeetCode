---
title: 1886.判断矩阵经轮转后是否一致：模拟
date: 2026-03-22 23:47:38
tags: [题解, LeetCode, 简单, 数组, 矩阵, 矩阵旋转]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.com/uploads/2021/05/20/grid3.png
---

# 【LetMeFly】1886.判断矩阵经轮转后是否一致：模拟

力扣题目链接：[https://leetcode.cn/problems/determine-whether-matrix-can-be-obtained-by-rotation/](https://leetcode.cn/problems/determine-whether-matrix-can-be-obtained-by-rotation/)

<p>给你两个大小为 <code>n x n</code> 的二进制矩阵 <code>mat</code> 和 <code>target</code> 。现<strong> 以 90 度顺时针轮转 </strong>矩阵 <code>mat</code> 中的元素 <strong>若干次</strong> ，如果能够使 <code>mat</code> 与 <code>target</code> 一致，返回 <code>true</code> ；否则，返回<em> </em><code>false</code><em> 。</em></p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/20/grid3.png" style="width: 301px; height: 121px;" />
<pre>
<strong>输入：</strong>mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
<strong>输出：</strong>true
<strong>解释：</strong>顺时针轮转 90 度一次可以使 mat 和 target 一致。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/20/grid4.png" style="width: 301px; height: 121px;" />
<pre>
<strong>输入：</strong>mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
<strong>输出：</strong>false
<strong>解释：</strong>无法通过轮转矩阵中的元素使 equal 与 target 一致。
</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/26/grid4.png" style="width: 661px; height: 184px;" />
<pre>
<strong>输入：</strong>mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
<strong>输出：</strong>true
<strong>解释：</strong>顺时针轮转 90 度两次可以使 mat 和 target 一致。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == mat.length == target.length</code></li>
	<li><code>n == mat[i].length == target[i].length</code></li>
	<li><code>1 <= n <= 10</code></li>
	<li><code>mat[i][j]</code> 和 <code>target[i][j]</code> 不是 <code>0</code> 就是 <code>1</code></li>
</ul>


    
## 解题方法：模拟

如何将矩阵顺时针旋转90度？

> 使用一个新矩阵，令新矩阵的`(i, j)`等于旧矩阵的`(j, n-i-1)`就好了。

旋转$3$次判断$4$次，本题结束。

+ 时间复杂度$O(n^2)$
+ 空间复杂度$O(n^2)$

当然也有原地旋转矩阵的办法，如[48. 旋转图像](https://leetcode.cn/problems/rotate-image/)。

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-03-22 23:45:34
 */
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for (int t = 0; t < 4; t++) {
            if (mat == target) {
                return true;
            }
            if (t == 3) {
                break;
            }
            vector<vector<int>> tmp(n, vector<int>(n));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    tmp[i][j] = mat[j][n - i - 1];
                }
            }
            mat.swap(tmp);
        }
        return false;
    }
};

```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/159357841)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/03/22/LeetCode%201886.%E5%88%A4%E6%96%AD%E7%9F%A9%E9%98%B5%E7%BB%8F%E8%BD%AE%E8%BD%AC%E5%90%8E%E6%98%AF%E5%90%A6%E4%B8%80%E8%87%B4/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
