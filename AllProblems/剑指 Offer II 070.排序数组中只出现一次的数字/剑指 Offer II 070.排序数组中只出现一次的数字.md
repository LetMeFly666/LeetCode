---
title: 剑指 Offer II 070.排序数组中只出现一次的数字
date: 2023-01-03 18-56-05
tags: [题解, LeetCode, 中等, 数组, 二分查找]
---

# 【LetMeFly】剑指 Offer II 070.排序数组中只出现一次的数字

力扣题目链接：[https://leetcode.cn/problems/skFtm2/](https://leetcode.cn/problems/skFtm2/)

<p>给定一个只包含整数的有序数组 <code>nums</code>&nbsp;，每个元素都会出现两次，唯有一个数只会出现一次，请找出这个唯一的数字。</p>

<p>你设计的解决方案必须满足 <code>O(log n)</code> 时间复杂度和 <code>O(1)</code> 空间复杂度。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,1,2,3,3,4,4,8,8]
<strong>输出:</strong> 2
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums =  [3,3,7,7,10,11,11]
<strong>输出:</strong> 10
</pre>

<p>&nbsp;</p>

<p><meta charset="UTF-8" /></p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i]&nbsp;&lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>

<p><meta charset="UTF-8" />注意：本题与主站 540&nbsp;题相同：<a href="https://leetcode-cn.com/problems/single-element-in-a-sorted-array/">https://leetcode-cn.com/problems/single-element-in-a-sorted-array/</a></p>


    