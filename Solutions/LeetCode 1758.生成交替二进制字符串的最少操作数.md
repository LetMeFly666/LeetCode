---
title: 1758.生成交替二进制字符串的最少操作数
date: 2022-11-29 23:00:13
tags: [题解, LeetCode, 简单, 字符串, 模拟, 遍历]
---

# 【LetMeFly】1758.生成交替二进制字符串的最少操作数

力扣题目链接：[https://leetcode.cn/problems/minimum-changes-to-make-alternating-binary-string/](https://leetcode.cn/problems/minimum-changes-to-make-alternating-binary-string/)

<p>给你一个仅由字符 <code>'0'</code> 和 <code>'1'</code> 组成的字符串 <code>s</code> 。一步操作中，你可以将任一 <code>'0'</code> 变成 <code>'1'</code> ，或者将 <code>'1'</code> 变成 <code>'0'</code> 。</p>

<p><strong>交替字符串</strong> 定义为：如果字符串中不存在相邻两个字符相等的情况，那么该字符串就是交替字符串。例如，字符串 <code>"010"</code> 是交替字符串，而字符串 <code>"0100"</code> 不是。</p>

<p>返回使 <code>s</code> 变成 <strong>交替字符串</strong> 所需的 <strong>最少</strong> 操作数。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "0100"
<strong>输出：</strong>1
<strong>解释：</strong>如果将最后一个字符变为 '1' ，s 就变成 "0101" ，即符合交替字符串定义。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "10"
<strong>输出：</strong>0
<strong>解释：</strong>s 已经是交替字符串。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "1111"
<strong>输出：</strong>2
<strong>解释：</strong>需要 2 步操作得到 "0101" 或 "1010" 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s[i]</code> 是 <code>'0'</code> 或 <code>'1'</code></li>
</ul>


    
## 方法一：模拟

要变成的字符串最多有两种，一种是```010101...```，一种是```101010...```

假如我们要把字符串全部变成```010101...```需要$oneZero$步，那么我们将这个字符串变成```101010...```就需要$s.size() - oneZero$步。

因此，我们只需要计算出字符串变成```010101...```需要的步数即可。

我们遍历字符串，如果字符串不等于的下标$i \% 2$，那么“变更数量+1”

最终返回“变成```010101...```”和“变成```101010...```”所需步数中最小的一个即可。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minOperations(string& s) {
        int oneZero = 0;  // 101010...
        int n = s.size();
        for (int i = 0; i < n; i++) {
            oneZero += (s[i] != '0' + i % 2);
        }
        return min(oneZero, n - oneZero);
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/11/29/LeetCode%201758.%E7%94%9F%E6%88%90%E4%BA%A4%E6%9B%BF%E4%BA%8C%E8%BF%9B%E5%88%B6%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9A%84%E6%9C%80%E5%B0%91%E6%93%8D%E4%BD%9C%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128107132](https://letmefly.blog.csdn.net/article/details/128107132)
