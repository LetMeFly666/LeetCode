---
title: 剑指 Offer II 085.生成匹配的括号
date: 2022-06-02 20-17-10
tags: [题解, LeetCode, 中等, 字符串, 动态规划, 回溯]
---

# 【LetMeFly】剑指 Offer II 085.生成匹配的括号

力扣题目链接：[https://leetcode.cn/problems/IDBivT/](https://leetcode.cn/problems/IDBivT/)

<p>正整数&nbsp;<code>n</code>&nbsp;代表生成括号的对数，请设计一个函数，用于能够生成所有可能的并且 <strong>有效的 </strong>括号组合。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 3
<strong>输出：</strong>[&quot;((()))&quot;,&quot;(()())&quot;,&quot;(())()&quot;,&quot;()(())&quot;,&quot;()()()&quot;]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>[&quot;()&quot;]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 8</code></li>
</ul>

<p>&nbsp;</p>

<p><meta charset="UTF-8" />注意：本题与主站 22&nbsp;题相同：&nbsp;<a href="https://leetcode-cn.com/problems/generate-parentheses/">https://leetcode-cn.com/problems/generate-parentheses/</a></p>


    