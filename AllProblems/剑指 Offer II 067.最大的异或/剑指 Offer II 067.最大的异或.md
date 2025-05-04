---
title: 剑指 Offer II 067.最大的异或
date: 2023-01-03 18-56-04
tags: [题解, LeetCode, 中等, 位运算, 字典树, 数组, 哈希表]
---

# 【LetMeFly】剑指 Offer II 067.最大的异或

力扣题目链接：[https://leetcode.cn/problems/ms70jA/](https://leetcode.cn/problems/ms70jA/)

<p>给你一个整数数组 <code>nums</code> ，返回<em> </em><code>nums[i] XOR nums[j]</code> 的最大运算结果，其中 <code>0 ≤ i ≤ j &lt; n</code> 。</p>

<p>&nbsp;</p>

<div class="original__bRMd">
<div>
<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,10,5,25,2,8]
<strong>输出：</strong>28
<strong>解释：</strong>最大运算结果是 5 XOR 25 = 28.</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [14,70,53,83,49,91,36,80,92,51,66,70]
<strong>输出：</strong>127
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
</ul>
</div>
</div>

<p>&nbsp;</p>

<p><meta charset="UTF-8" />注意：本题与主站 421&nbsp;题相同：&nbsp;<a href="https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array/">https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array/</a></p>


    