---
title: 剑指 Offer 63.股票的最大利润
date: 2022-06-02 20-16-25
tags: [题解, LeetCode, 中等, 数组, 动态规划]
---

# 【LetMeFly】剑指 Offer 63.股票的最大利润

力扣题目链接：[https://leetcode.cn/problems/gu-piao-de-zui-da-li-run-lcof/](https://leetcode.cn/problems/gu-piao-de-zui-da-li-run-lcof/)

<p>假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> [7,1,5,3,6,4]
<strong>输出:</strong> 5
<strong>解释: </strong>在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> [7,6,4,3,1]
<strong>输出:</strong> 0
<strong>解释: </strong>在这种情况下, 没有交易完成, 所以最大利润为 0。</pre>

<p>&nbsp;</p>

<p><strong>限制：</strong></p>

<p><code>0 &lt;= 数组长度 &lt;= 10^5</code></p>

<p>&nbsp;</p>

<p><strong>注意：</strong>本题与主站 121 题相同：<a href="https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/">https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/</a></p>


    