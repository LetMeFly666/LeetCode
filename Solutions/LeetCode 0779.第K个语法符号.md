---
title: 779.第K个语法符号
date: 2022-10-20 08:11:30
tags: [题解, LeetCode, 中等, 位运算, 递归, 数学]
categories: [题解, LeetCode]
---

# 【LetMeFly】779.第K个语法符号：递归，追根溯源

力扣题目链接：[https://leetcode.cn/problems/k-th-symbol-in-grammar/](https://leetcode.cn/problems/k-th-symbol-in-grammar/)

<p>我们构建了一个包含 <code>n</code> 行(&nbsp;<strong>索引从 1&nbsp; 开始&nbsp;</strong>)的表。首先在第一行我们写上一个 <code>0</code>。接下来的每一行，将前一行中的<code>0</code>替换为<code>01</code>，<code>1</code>替换为<code>10</code>。</p>

<ul>
	<li>例如，对于 <code>n = 3</code> ，第 <code>1</code> 行是 <code>0</code> ，第 <code>2</code> 行是 <code>01</code> ，第3行是 <code>0110</code> 。</li>
</ul>

<p>给定行数&nbsp;<code>n</code>&nbsp;和序数 <code>k</code>，返回第 <code>n</code> 行中第 <code>k</code>&nbsp;个字符。（&nbsp;<code>k</code>&nbsp;<strong>从索引 1 开始</strong>）</p>

<p><br />
<strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> n = 1, k = 1
<strong>输出:</strong> 0
<strong>解释: </strong>第一行：<u>0</u>
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> n = 2, k = 1
<strong>输出:</strong> 0
<strong>解释:</strong> 
第一行: 0 
第二行: 0<u>1</u>
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> n = 2, k = 2
<strong>输出:</strong> 1
<strong>解释:</strong>
第一行: 0
第二行: 0<u>1</u>
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 30</code></li>
	<li><code>1 &lt;= k &lt;= 2<sup>n - 1</sup></code></li>
</ul>


    
## 方法一：递归，追根溯源

要求第$n$行的第$k$个数，那么这个数是哪儿来的呢？

第$n$行的第$k$个数是由第$n-1$行的第$\lfloor\frac{k+1}{2}\rfloor$个数来的。

我们将第$n-1$行的第$\lfloor\frac{k+1}{2}\rfloor$个数即为$from$，那么当$from = 0并且k \% 2 \neq 0$ 或者 $from \neq 0 并且 k \% 2 = 0$时，第$n$行第$k$个数为$0$

反之则为$1$

递归终止条件就是递归到了最原始的“数字之父”，即第1行的第1个数，这样就直接返回0

+ 时间复杂度$O(\log_2 k)$
+ 空间复杂度$O(\log_2 k)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1 && k == 1)
            return 0;
        int from = kthGrammar(n - 1, (k + 1) / 2);
        return (from != k % 2) ? 0 : 1;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/10/20/LeetCode%200779.%E7%AC%ACK%E4%B8%AA%E8%AF%AD%E6%B3%95%E7%AC%A6%E5%8F%B7/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127419515](https://letmefly.blog.csdn.net/article/details/127419515)
