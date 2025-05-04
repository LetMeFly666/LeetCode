---
title: 剑指 Offer 62.圆圈中最后剩下的数字
date: 2022-06-02 20-16-24
tags: [题解, LeetCode, 简单, 递归, 数学]
---

# 【LetMeFly】剑指 Offer 62.圆圈中最后剩下的数字

力扣题目链接：[https://leetcode.cn/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/](https://leetcode.cn/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/)

<p>0,1,···,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字（删除后从下一个数字开始计数）。求出这个圆圈里剩下的最后一个数字。</p>

<p>例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> n = 5, m = 3
<strong>输出: </strong>3
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入:</strong> n = 10, m = 17
<strong>输出: </strong>2
</pre>

<p> </p>

<p><strong>限制：</strong></p>

<ul>
	<li><code>1 <= n <= 10^5</code></li>
	<li><code>1 <= m <= 10^6</code></li>
</ul>


    