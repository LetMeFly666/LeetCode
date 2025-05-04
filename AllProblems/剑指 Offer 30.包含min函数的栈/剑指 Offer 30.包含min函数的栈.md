---
title: 剑指 Offer 30.包含min函数的栈
date: 2022-06-02 20-16-06
tags: [题解, LeetCode, 简单, 栈, 设计]
---

# 【LetMeFly】剑指 Offer 30.包含min函数的栈

力扣题目链接：[https://leetcode.cn/problems/bao-han-minhan-shu-de-zhan-lcof/](https://leetcode.cn/problems/bao-han-minhan-shu-de-zhan-lcof/)

<p>定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。</p>

<p>&nbsp;</p>

<p><strong>示例:</strong></p>

<pre>MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --&gt; 返回 -3.
minStack.pop();
minStack.top();      --&gt; 返回 0.
minStack.min();   --&gt; 返回 -2.
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li>各函数的调用总次数不超过 20000 次</li>
</ol>

<p>&nbsp;</p>

<p>注意：本题与主站 155 题相同：<a href="https://leetcode-cn.com/problems/min-stack/">https://leetcode-cn.com/problems/min-stack/</a></p>


    