---
title: 剑指 Offer 66.构建乘积数组
date: 2022-06-02 20-16-26
tags: [题解, LeetCode, 中等, 数组, 前缀和]
---

# 【LetMeFly】剑指 Offer 66.构建乘积数组

力扣题目链接：[https://leetcode.cn/problems/gou-jian-cheng-ji-shu-zu-lcof/](https://leetcode.cn/problems/gou-jian-cheng-ji-shu-zu-lcof/)

<p>给定一个数组 <code>A[0,1,…,n-1]</code>，请构建一个数组 <code>B[0,1,…,n-1]</code>，其中 <code>B[i]</code> 的值是数组 <code>A</code> 中除了下标 <code>i</code> 以外的元素的积, 即 <code>B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]</code>。不能使用除法。</p>

<p> </p>

<p><strong>示例:</strong></p>

<pre>
<strong>输入:</strong> [1,2,3,4,5]
<strong>输出:</strong> [120,60,40,30,24]</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>所有元素乘积之和不会溢出 32 位整数</li>
	<li><code>a.length <= 100000</code></li>
</ul>


    