---
title: 剑指 Offer II 073.狒狒吃香蕉
date: 2022-06-02 20-17-04
tags: [题解, LeetCode, 中等, 数组, 二分查找]
---

# 【LetMeFly】剑指 Offer II 073.狒狒吃香蕉

力扣题目链接：[https://leetcode.cn/problems/nZZqjQ/](https://leetcode.cn/problems/nZZqjQ/)

<p>狒狒喜欢吃香蕉。这里有 <code>n</code> 堆香蕉，第 <code>i</code> 堆中有&nbsp;<code>piles[i]</code>&nbsp;根香蕉。警卫已经离开了，将在 <code>h</code> 小时后回来。</p>

<p>狒狒可以决定她吃香蕉的速度 <code>k</code> （单位：根/小时）。每个小时，她将会选择一堆香蕉，从中吃掉 <code>k</code> 根。如果这堆香蕉少于 <code>k</code> 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉，下一个小时才会开始吃另一堆的香蕉。&nbsp;&nbsp;</p>

<p>狒狒喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。</p>

<p>返回她可以在 <code>h</code> 小时内吃掉所有香蕉的最小速度 <code>k</code>（<code>k</code> 为整数）。</p>

<p>&nbsp;</p>

<ul>
</ul>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>piles = [3,6,7,11], h = 8
<strong>输出：</strong>4
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>piles = [30,11,23,4,20], h = 5
<strong>输出：</strong>30
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>piles = [30,11,23,4,20], h = 6
<strong>输出：</strong>23
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= piles.length &lt;= 10<sup>4</sup></code></li>
	<li><code>piles.length &lt;= h &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= piles[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<p>&nbsp;</p>

<p><meta charset="UTF-8" /><strong>注意：</strong>本题与主站 875&nbsp;题相同：&nbsp;<a href="https://leetcode-cn.com/problems/koko-eating-bananas/">https://leetcode-cn.com/problems/koko-eating-bananas/</a></p>


    