---
title: 2398.预算内的最多机器人数目
date: 2024-09-13 18:20:50
tags: [题解, LeetCode, 困难, 队列, 数组, 二分查找, 前缀和, 滑动窗口, 堆（优先队列）, 单调队列]
categories: [题解, LeetCode]
---

# 【LetMeFly】2398.预算内的最多机器人数目：滑动窗口+单调队列——思路清晰的一篇题解

力扣题目链接：[https://leetcode.cn/problems/maximum-number-of-robots-within-budget/](https://leetcode.cn/problems/maximum-number-of-robots-within-budget/)

<p>你有&nbsp;<code>n</code>&nbsp;个机器人，给你两个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>chargeTimes</code> 和&nbsp;<code>runningCosts</code>&nbsp;，两者长度都为&nbsp;<code>n</code>&nbsp;。第&nbsp;<code>i</code>&nbsp;个机器人充电时间为&nbsp;<code>chargeTimes[i]</code>&nbsp;单位时间，花费&nbsp;<code>runningCosts[i]</code>&nbsp;单位时间运行。再给你一个整数&nbsp;<code>budget</code>&nbsp;。</p>

<p>运行&nbsp;<code>k</code>&nbsp;个机器人 <strong>总开销</strong>&nbsp;是&nbsp;<code>max(chargeTimes) + k * sum(runningCosts)</code>&nbsp;，其中&nbsp;<code>max(chargeTimes)</code>&nbsp;是这&nbsp;<code>k</code>&nbsp;个机器人中最大充电时间，<code>sum(runningCosts)</code>&nbsp;是这 <code>k</code>&nbsp;个机器人的运行时间之和。</p>

<p>请你返回在 <strong>不超过</strong>&nbsp;<code>budget</code>&nbsp;的前提下，你 <strong>最多</strong>&nbsp;可以 <strong>连续</strong>&nbsp;运行的机器人数目为多少。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>chargeTimes = [3,6,1,3,4], runningCosts = [2,1,3,4,5], budget = 25
<b>输出：</b>3
<b>解释：</b>
可以在 budget 以内运行所有单个机器人或者连续运行 2 个机器人。
选择前 3 个机器人，可以得到答案最大值 3 。总开销是 max(3,6,1) + 3 * sum(2,1,3) = 6 + 3 * 6 = 24 ，小于 25 。
可以看出无法在 budget 以内连续运行超过 3 个机器人，所以我们返回 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>chargeTimes = [11,12,19], runningCosts = [10,8,7], budget = 19
<b>输出：</b>0
<b>解释：</b>即使运行任何一个单个机器人，还是会超出 budget，所以我们返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>chargeTimes.length == runningCosts.length == n</code></li>
	<li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= chargeTimes[i], runningCosts[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= budget &lt;= 10<sup>15</sup></code></li>
</ul>


    
## 解题方法：滑动窗口+单调队列

如果题目要求是`k * sum(runningCosts) ≤ budget`应该怎么做呢？很简单，一个滑动窗口即可。

> 使用两个指针`l`和`r`分别指向所选区间的左端点和右端点，每次右指针`r`向右移动一位，若窗口中所选元素的`k * sum(runningCosts) > budget`，则不断往后移动左指针，直到`k * sum(runningCosts) ≤ budget`为止，就得到了以`r`为右端点时，最大的可选机器人数。
> 
> 从`l`到`r`的元素是被选中的元素，被称为“窗口”。这得益于窗口中元素数量越多，`k * sum(runningCosts)`就越大。
> 
> 由于左指针和右指针都至多遍历一次数组，所以总时间复杂度为$O(n)$。

但是这道题的总开销是`max(chargeTimes) + k * sum(runningCosts)`，而不是`k * sum(runningCosts)`。`k = r - l + 1`，而`sum(runningCosts)`只需要在移动左右指针的时候使用一个变量来维护即可在$O(1)$的时间内得到。对于一个窗口，`max(chargeTimes)`如何在$O(1)$的时间内得到呢？这就需要引入单调队列。

> 使用一个单调递减队列，保持越靠近队首的元素严格靠近越靠近队尾的元素。
> 
> 具体来说，当`r`加入窗口时，若`chargeTimes[r] > 队尾元素`，则队尾元素不断出栈。之后再将`r`入栈。这样，栈中的元素就保持了单调递减。而当`l`退出窗口时，如果队首元素就是`l`，则`l`出队。
> 
> 这样做有一个好处，由于队列是单调递减的，所以队首元素就是窗口中`chargeTimes`最大的那个元素。诶，`max(chargeTimes)`也能在$O(1)$时间复杂度内得到了，问题解决。
> 
> 注意，队列的作用只是为了计算窗口中的`max(chargeTimes)`。若队列中一个元素被`chargeTimes`更大的`r`“顶”出队列，则并不代表其不在窗口中了，而只是说明其`chargeTimes`值比较小。

+ 时间复杂度$O(len(chargeTimes))$
+ 空间复杂度$O(len(chargeTimes))$

### AC代码

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/09/13/LeetCode%202398.%E9%A2%84%E7%AE%97%E5%86%85%E7%9A%84%E6%9C%80%E5%A4%9A%E6%9C%BA%E5%99%A8%E4%BA%BA%E6%95%B0%E7%9B%AE/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/142218259](https://letmefly.blog.csdn.net/article/details/142218259)
