---
title: 剑指 Offer II 081.允许重复选择元素的组合
date: 2022-06-02 20-17-08
tags: [题解, LeetCode, 中等, 数组, 回溯]
---

# 【LetMeFly】剑指 Offer II 081.允许重复选择元素的组合

力扣题目链接：[https://leetcode.cn/problems/Ygoe9J/](https://leetcode.cn/problems/Ygoe9J/)

<p>给定一个<strong>无重复元素</strong>的正整数数组&nbsp;<code>candidates</code>&nbsp;和一个正整数&nbsp;<code>target</code>&nbsp;，找出&nbsp;<code>candidates</code>&nbsp;中所有可以使数字和为目标数&nbsp;<code>target</code>&nbsp;的唯一组合。</p>

<p><code>candidates</code>&nbsp;中的数字可以无限制重复被选取。如果至少一个所选数字数量不同，则两种组合是不同的。&nbsp;</p>

<p>对于给定的输入，保证和为&nbsp;<code>target</code> 的唯一组合数少于 <code>150</code> 个。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<pre>
<strong>输入: </strong>candidates = <code>[2,3,6,7], </code>target = <code>7</code>
<strong>输出: </strong>[[7],[2,2,3]]
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入: </strong>candidates = [2,3,5]<code>, </code>target = 8
<strong>输出: </strong>[[2,2,2,2],[2,3,3],[3,5]]</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入: </strong>candidates = <code>[2], </code>target = <span style="white-space: pre-wrap;">1</span>
<strong>输出: </strong>[]
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入: </strong>candidates = <code>[1], </code>target = <code>1</code>
<strong>输出: </strong>[[1]]
</pre>

<p><strong>示例 5：</strong></p>

<pre>
<strong>输入: </strong>candidates = <code>[1], </code>target = <code>2</code>
<strong>输出: </strong>[[1,1]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= candidates.length &lt;= 30</code></li>
	<li><code>1 &lt;= candidates[i] &lt;= 200</code></li>
	<li><code>candidate</code> 中的每个元素都是独一无二的。</li>
	<li><code>1 &lt;= target &lt;= 500</code></li>
</ul>

<p>&nbsp;</p>

<p><meta charset="UTF-8" />注意：本题与主站 39&nbsp;题相同：&nbsp;<a href="https://leetcode-cn.com/problems/combination-sum/">https://leetcode-cn.com/problems/combination-sum/</a></p>


    