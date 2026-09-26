---
title: 3020.子集中元素的最大数量：哈希表枚举
date: 2026-06-27 13:08:59
tags: [题解, LeetCode, 中等, 数组, 哈希表, map, 枚举]
categories: [题解, LeetCode]
---

# 【LetMeFly】3020.子集中元素的最大数量：哈希表枚举

力扣题目链接：[https://leetcode.cn/problems/find-the-maximum-number-of-elements-in-subset/](https://leetcode.cn/problems/find-the-maximum-number-of-elements-in-subset/)

<p>给你一个<strong> 正整数 </strong>数组 <code>nums</code> 。</p>

<p>你需要从数组中选出一个满足下述条件的<span data-keyword="subset">子集</span>：</p>

<ul>
	<li>你可以将选中的元素放置在一个下标从 <strong>0</strong> 开始的数组中，并使其遵循以下模式：<code>[x, x<sup>2</sup>, x<sup>4</sup>, ..., x<sup>k/2</sup>, x<sup>k</sup>, x<sup>k/2</sup>, ..., x<sup>4</sup>, x<sup>2</sup>, x]</code>（<strong>注意</strong>，<code>k</code> 可以是任何 <strong>非负</strong> 的 2 的幂）。例如，<code>[2, 4, 16, 4, 2]</code> 和 <code>[3, 9, 3]</code> 都符合这一模式，而 <code>[2, 4, 8, 4, 2]</code> 则不符合。</li>
</ul>

<p>返回满足这些条件的子集中，元素数量的 <strong>最大值 </strong><em>。</em></p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,4,1,2,2]
<strong>输出：</strong>3
<strong>解释：</strong>选择子集 {4,2,2} ，将其放在数组 [2,4,2] 中，它遵循该模式，且 2<sup>2</sup> == 4 。因此答案是 3 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,3,2,4]
<strong>输出：</strong>1
<strong>解释：</strong>选择子集 {1}，将其放在数组 [1] 中，它遵循该模式。因此答案是 1 。注意我们也可以选择子集 {2} 、{4} 或 {3} ，可能存在多个子集都能得到相同的答案。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：哈希表枚举

首先使用哈希表统计每个元素分别出现了多少次。接着枚举哈希表中的每一个值x，看看以x为起点的“幂数组”最大能有多长：

> 当$x$在哈希表中的次数最少为$2$时，答案加$2$，$x$平方。
>
> + 若最终$x$在哈希表中只出现了一次，则答案数量加一
> + 否则(由于“幂数组”长度一定为奇数)相当于多加了一次$x$，答案数量减一

会超时吗？不会。每个数每次都在平方，以“最小”的$2$为例，数组长度最多也不超过$5$：

> ```python
> x = 2
> a = []
> while x <= 1e9:
>     a.append(x)
>     x = x * x
> print(a)
> ```

特别的，如果$x=1$，再怎么平方结果都是$1$，只需要看下$1$出现了几次就好。假设$1$出现了$n$次，则不超过$n$的最大奇数即为$1$组成的最长“幂数组”的长度。

+ 时间复杂度$O(len(nums)\times \log \log M)$，其中$M=\max nums[i]$，单个值$x$时间复杂度$\log\log M$的计算方式为$x^{2^k}\leq M$得$k=\mathrm{O}\log\log M$。时间复杂度也可以认为是$O(len(nums))$。
+ 空间复杂度$O(len(nums))$

### AC代码

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/162367911)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/06/27/LeetCode%203020.%E5%AD%90%E9%9B%86%E4%B8%AD%E5%85%83%E7%B4%A0%E7%9A%84%E6%9C%80%E5%A4%A7%E6%95%B0%E9%87%8F/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
