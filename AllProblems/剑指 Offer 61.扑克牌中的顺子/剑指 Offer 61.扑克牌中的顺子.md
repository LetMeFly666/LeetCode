---
title: 剑指 Offer 61.扑克牌中的顺子
date: 2022-06-02 20-16-24
tags: [题解, LeetCode, 简单, 数组, 排序]
---

# 【LetMeFly】剑指 Offer 61.扑克牌中的顺子

力扣题目链接：[https://leetcode.cn/problems/bu-ke-pai-zhong-de-shun-zi-lcof/](https://leetcode.cn/problems/bu-ke-pai-zhong-de-shun-zi-lcof/)

<p>从<strong>若干副扑克牌</strong>中随机抽 <code>5</code> 张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre>
<strong>输入:</strong> [1,2,3,4,5]
<strong>输出:</strong> True</pre>

<p>&nbsp;</p>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入:</strong> [0,0,1,2,5]
<strong>输出:</strong> True</pre>

<p>&nbsp;</p>

<p><strong>限制：</strong></p>

<p>数组长度为 5&nbsp;</p>

<p>数组的数取值为 [0, 13] .</p>


    