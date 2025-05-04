---
title: 剑指 Offer II 083.没有重复元素集合的全排列
date: 2022-06-02 20-17-10
tags: [题解, LeetCode, 中等, 数组, 回溯]
---

# 【LetMeFly】剑指 Offer II 083.没有重复元素集合的全排列

力扣题目链接：[https://leetcode.cn/problems/VvJkup/](https://leetcode.cn/problems/VvJkup/)

<p>给定一个不含重复数字的整数数组 <code>nums</code> ，返回其 <strong>所有可能的全排列</strong> 。可以 <strong>按任意顺序</strong> 返回答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3]
<strong>输出：</strong>[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,1]
<strong>输出：</strong>[[0,1],[1,0]]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1]
<strong>输出：</strong>[[1]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 6</code></li>
	<li><code>-10 &lt;= nums[i] &lt;= 10</code></li>
	<li><code>nums</code> 中的所有整数 <strong>互不相同</strong></li>
</ul>

<p>&nbsp;</p>

<p><meta charset="UTF-8" />注意：本题与主站 46&nbsp;题相同：<a href="https://leetcode-cn.com/problems/permutations/">https://leetcode-cn.com/problems/permutations/</a>&nbsp;</p>


    