---
title: 剑指 Offer 44.数字序列中某一位的数字
date: 2022-06-02 20-16-13
tags: [题解, LeetCode, 中等, 数学, 二分查找]
---

# 【LetMeFly】剑指 Offer 44.数字序列中某一位的数字

力扣题目链接：[https://leetcode.cn/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof/](https://leetcode.cn/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof/)

<p>数字以0123456789101112131415&hellip;的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。</p>

<p>请写一个函数，求任意第n位对应的数字。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 3
<strong>输出：</strong>3
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 11
<strong>输出：</strong>0</pre>

<p>&nbsp;</p>

<p><strong>限制：</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;&nbsp;2^31</code></li>
</ul>

<p>注意：本题与主站 400 题相同：<a href="https://leetcode-cn.com/problems/nth-digit/">https://leetcode-cn.com/problems/nth-digit/</a></p>


    