---
title: 1292.元素和小于等于阈值的正方形的最大边长：二维前缀和（无需二分）+抽象速懂的描述
date: 2026-01-19 23:27:08
tags: [题解, LeetCode, 中等, 数组, 矩阵, 前缀和]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.cn/aliyun-lc-upload/uploads/2019/12/15/e1.png
---

# 【LetMeFly】1292.元素和小于等于阈值的正方形的最大边长：二维前缀和（无需二分）+抽象速懂的描述

力扣题目链接：[https://leetcode.cn/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/](https://leetcode.cn/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/)

<p>给你一个大小为&nbsp;<code>m x n</code>&nbsp;的矩阵&nbsp;<code>mat</code>&nbsp;和一个整数阈值&nbsp;<code>threshold</code>。</p>

<p>请你返回元素总和小于或等于阈值的正方形区域的最大边长；如果没有这样的正方形区域，则返回 <strong>0&nbsp;</strong>。<br />
&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.cn/aliyun-lc-upload/uploads/2019/12/15/e1.png" style="height: 186px; width: 335px;" /></p>

<pre>
<strong>输入：</strong>mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
<strong>输出：</strong>2
<strong>解释：</strong>总和小于或等于 4 的正方形的最大边长为 2，如图所示。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 300</code></li>
	<li><code>0 &lt;= mat[i][j] &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= threshold &lt;= 10<sup>5</sup></code><sup>&nbsp;</sup></li>
</ul>


    
## 解题方法：前缀和

二维矩阵的二维前缀和可以快速计算出某个子矩阵的元素和。

```
AB
CD
```

其中`prefix[D]`代表从左上角到`D`这个矩阵的元素和，计算方法为`D+B+C-A`。

```
ABC
DEF
GHI
```

那么想计算`EFHI`这个子矩阵的元素和就只需要`prefix[I]-prefix[C]-prefix[G]+prefix[A]`。

二层循环枚举矩阵左上角顶点，使用一个变量`ans`作为答案合法边长并且**只增不减**，那么二层循环时间复杂度$O(mn)$，内层`ans`总时间复杂度不会超过$O\min(m,n)$。

+ 时间复杂度$O(mn)$
+ 空间复杂度$O(N\log N)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-01-19 21:55:16
 */
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> prefix(n + 1, vector<int>(m + 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefix[i + 1][j + 1] = mat[i][j] - prefix[i][j] + prefix[i][j + 1] + prefix[i + 1][j];
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                while (i + ans < n && j + ans < m && prefix[i + ans + 1][j + ans + 1] - prefix[i + ans + 1][j] - prefix[i][j + ans + 1] + prefix[i][j] <= threshold) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/157145833)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/01/19/LeetCode%201292.%E5%85%83%E7%B4%A0%E5%92%8C%E5%B0%8F%E4%BA%8E%E7%AD%89%E4%BA%8E%E9%98%88%E5%80%BC%E7%9A%84%E6%AD%A3%E6%96%B9%E5%BD%A2%E7%9A%84%E6%9C%80%E5%A4%A7%E8%BE%B9%E9%95%BF/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
