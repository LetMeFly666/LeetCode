---
title: 剑指 Offer 57.和为s的两个数字
date: 2022-06-02 20-16-21
tags: [题解, LeetCode, 简单, 数组, 双指针, 二分查找]
---

# 【LetMeFly】剑指 Offer 57.和为s的两个数字

力扣题目链接：[https://leetcode.cn/problems/he-wei-sde-liang-ge-shu-zi-lcof/](https://leetcode.cn/problems/he-wei-sde-liang-ge-shu-zi-lcof/)

<p>输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [2,7,11,15], target = 9
<strong>输出：</strong>[2,7] 或者 [7,2]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [10,26,30,31,47,60], target = 40
<strong>输出：</strong>[10,30] 或者 [30,10]
</pre>

<p>&nbsp;</p>

<p><strong>限制：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= nums[i]&nbsp;&lt;= 10^6</code></li>
</ul>


    