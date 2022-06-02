---
title: 剑指 Offer 14- II.剪绳子 II
date: 2022-06-02 20-15-57
tags: [题解, LeetCode, 中等, 数学, 动态规划]
---

# 【LetMeFly】剑指 Offer 14- II.剪绳子 II

力扣题目链接：[https://leetcode.cn/problems/jian-sheng-zi-ii-lcof/](https://leetcode.cn/problems/jian-sheng-zi-ii-lcof/)

<p>给你一根长度为 <code>n</code> 的绳子，请把绳子剪成整数长度的 <code>m</code>&nbsp;段（m、n都是整数，n&gt;1并且m&gt;1），每段绳子的长度记为 <code>k[0],k[1]...k[m - 1]</code> 。请问 <code>k[0]*k[1]*...*k[m - 1]</code> 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。</p>

<p>答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入: </strong>2
<strong>输出: </strong>1
<strong>解释: </strong>2 = 1 + 1, 1 &times; 1 = 1</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入: </strong>10
<strong>输出: </strong>36
<strong>解释: </strong>10 = 3 + 3 + 4, 3 &times;&nbsp;3 &times;&nbsp;4 = 36</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
</ul>

<p>注意：本题与主站 343 题相同：<a href="https://leetcode-cn.com/problems/integer-break/">https://leetcode-cn.com/problems/integer-break/</a></p>


    