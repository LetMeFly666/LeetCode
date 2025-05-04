---
title: LCP 04.覆盖
date: 2022-06-02 20-15-15
tags: [题解, LeetCode, 困难, 位运算, 图, 数组, 动态规划, 状态压缩]
---

# 【LetMeFly】LCP 04.覆盖

力扣题目链接：[https://leetcode.cn/problems/broken-board-dominoes/](https://leetcode.cn/problems/broken-board-dominoes/)

<p>你有一块棋盘，棋盘上有一些格子已经坏掉了。你还有无穷块大小为<code>1 * 2</code>的多米诺骨牌，你想把这些骨牌<strong>不重叠</strong>地覆盖在<strong>完好</strong>的格子上，请找出你最多能在棋盘上放多少块骨牌？这些骨牌可以横着或者竖着放。</p>

<p>&nbsp;</p>

<p>输入：<code>n, m</code>代表棋盘的大小；<code>broken</code>是一个<code>b * 2</code>的二维数组，其中每个元素代表棋盘上每一个坏掉的格子的位置。</p>

<p>输出：一个整数，代表最多能在棋盘上放的骨牌数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 2, m = 3, broken = [[1, 0], [1, 1]]
<strong>输出：</strong>2
<strong>解释：</strong>我们最多可以放两块骨牌：[[0, 0], [0, 1]]以及[[0, 2], [1, 2]]。（见下图）</pre>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/09/09/domino_example_1.jpg" style="height: 204px; width: 304px;"></p>

<p>&nbsp;</p>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 3, m = 3, broken = []
<strong>输出：</strong>4
<strong>解释：</strong>下图是其中一种可行的摆放方式
</pre>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/09/09/domino_example_2.jpg" style="height: 304px; width: 304px;"></p>

<p>&nbsp;</p>

<p><strong>限制：</strong></p>

<ol>
	<li><code>1 &lt;= n &lt;= 8</code></li>
	<li><code>1 &lt;= m &lt;= 8</code></li>
	<li><code>0 &lt;= b &lt;= n * m</code></li>
</ol>


    