---
title: 剑指 Offer 60.n个骰子的点数
date: 2022-06-02 20-16-24
tags: [题解, LeetCode, 中等, 数学, 动态规划, 概率与统计]
---

# 【LetMeFly】剑指 Offer 60.n个骰子的点数

力扣题目链接：[https://leetcode.cn/problems/nge-tou-zi-de-dian-shu-lcof/](https://leetcode.cn/problems/nge-tou-zi-de-dian-shu-lcof/)

<p>把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。</p>

<p>&nbsp;</p>

<p>你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> 1
<strong>输出:</strong> [0.16667,0.16667,0.16667,0.16667,0.16667,0.16667]
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> 2
<strong>输出:</strong> [0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0.05556,0.02778]</pre>

<p>&nbsp;</p>

<p><strong>限制：</strong></p>

<p><code>1 &lt;= n &lt;= 11</code></p>


    