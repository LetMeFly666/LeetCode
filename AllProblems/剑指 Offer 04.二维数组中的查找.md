---
title: 剑指 Offer 04.二维数组中的查找
date: 2023-01-03 18-54-59
tags: [题解, LeetCode, 中等, 数组, 二分查找, 分治, 矩阵]
---

# 【LetMeFly】剑指 Offer 04.二维数组中的查找

力扣题目链接：[https://leetcode.cn/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/](https://leetcode.cn/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/)

<p>在一个 n * m 的二维数组中，每一行都按照从左到右&nbsp;<strong>非递减&nbsp;</strong>的顺序排序，每一列都按照从上到下&nbsp;<strong>非递减&nbsp;</strong>的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。</p>

<p>&nbsp;</p>

<p><strong>示例:</strong></p>

<p>现有矩阵 matrix 如下：</p>

<pre>
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
</pre>

<p>给定 target&nbsp;=&nbsp;<code>5</code>，返回&nbsp;<code>true</code>。</p>

<p>给定&nbsp;target&nbsp;=&nbsp;<code>20</code>，返回&nbsp;<code>false</code>。</p>

<p>&nbsp;</p>

<p><strong>限制：</strong></p>

<p><code>0 &lt;= n &lt;= 1000</code></p>

<p><code>0 &lt;= m &lt;= 1000</code></p>

<p>&nbsp;</p>

<p><strong>注意：</strong>本题与主站 240 题相同：<a href="https://leetcode-cn.com/problems/search-a-2d-matrix-ii/">https://leetcode-cn.com/problems/search-a-2d-matrix-ii/</a></p>


    