---
title: 剑指 Offer 09.用两个栈实现队列
date: 2023-01-03 18-55-01
tags: [题解, LeetCode, 简单, 栈, 设计, 队列]
---

# 【LetMeFly】剑指 Offer 09.用两个栈实现队列

力扣题目链接：[https://leetcode.cn/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/](https://leetcode.cn/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/)

<p>用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 <code>appendTail</code> 和 <code>deleteHead</code> ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，<code>deleteHead</code>&nbsp;操作返回 -1 )</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
["CQueue","appendTail","deleteHead","deleteHead","deleteHead"]
[[],[3],[],[],[]]
<strong>输出：</strong>[null,null,3,-1,-1]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
<strong>输出：</strong>[null,-1,null,null,5,2]
</pre>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= values &lt;= 10000</code></li>
	<li>最多会对<code>&nbsp;appendTail、deleteHead </code>进行<code>&nbsp;10000</code>&nbsp;次调用</li>
</ul>


    