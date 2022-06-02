---
title: 剑指 Offer 41.数据流中的中位数
date: 2022-06-02 20-16-12
tags: [题解, LeetCode, 困难, 设计, 双指针, 数据流, 排序, 堆（优先队列）]
---

# 【LetMeFly】剑指 Offer 41.数据流中的中位数

力扣题目链接：[https://leetcode.cn/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof/](https://leetcode.cn/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof/)

<p>如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。</p>

<p>例如，</p>

<p>[2,3,4]&nbsp;的中位数是 3</p>

<p>[2,3] 的中位数是 (2 + 3) / 2 = 2.5</p>

<p>设计一个支持以下两种操作的数据结构：</p>

<ul>
	<li>void addNum(int num) - 从数据流中添加一个整数到数据结构中。</li>
	<li>double findMedian() - 返回目前所有元素的中位数。</li>
</ul>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：
</strong>[&quot;MedianFinder&quot;,&quot;addNum&quot;,&quot;addNum&quot;,&quot;findMedian&quot;,&quot;addNum&quot;,&quot;findMedian&quot;]
[[],[1],[2],[],[3],[]]
<strong>输出：</strong>[null,null,null,1.50000,null,2.00000]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：
</strong>[&quot;MedianFinder&quot;,&quot;addNum&quot;,&quot;findMedian&quot;,&quot;addNum&quot;,&quot;findMedian&quot;]
[[],[2],[],[3],[]]
<strong>输出：</strong>[null,null,2.00000,null,2.50000]</pre>

<p>&nbsp;</p>

<p><strong>限制：</strong></p>

<ul>
	<li>最多会对&nbsp;<code>addNum、findMedian</code> 进行&nbsp;<code>50000</code>&nbsp;次调用。</li>
</ul>

<p>注意：本题与主站 295 题相同：<a href="https://leetcode-cn.com/problems/find-median-from-data-stream/">https://leetcode-cn.com/problems/find-median-from-data-stream/</a></p>


    