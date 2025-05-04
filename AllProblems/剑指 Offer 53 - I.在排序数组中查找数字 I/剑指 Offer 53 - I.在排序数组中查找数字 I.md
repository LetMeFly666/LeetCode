---
title: 剑指 Offer 53 - I.在排序数组中查找数字 I
date: 2022-06-02 20-16-17
tags: [题解, LeetCode, 简单, 数组, 二分查找]
---

# 【LetMeFly】剑指 Offer 53 - I.在排序数组中查找数字 I

力扣题目链接：[https://leetcode.cn/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/](https://leetcode.cn/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/)

<p>统计一个数字在排序数组中出现的次数。</p>

<p> </p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [<code>5,7,7,8,8,10]</code>, target = 8
<strong>输出:</strong> 2</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = [<code>5,7,7,8,8,10]</code>, target = 6
<strong>输出:</strong> 0</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> <= nums[i] <= 10<sup>9</sup></code></li>
	<li><code>nums</code> 是一个非递减数组</li>
	<li><code>-10<sup>9</sup> <= target <= 10<sup>9</sup></code></li>
</ul>

<p> </p>

<p><strong>注意：</strong>本题与主站 34 题相同（仅返回值不同）：<a href="https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/">https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/</a></p>


    