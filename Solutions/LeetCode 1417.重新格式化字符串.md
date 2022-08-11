---
title: 1417.重新格式化字符串
date: 2022-08-11 09:58:00
tags: [题解, LeetCode, 简单, 字符串, 构造]
---

# 【LetMeFly】1417.重新格式化字符串

力扣题目链接：[https://leetcode.cn/problems/reformat-the-string/](https://leetcode.cn/problems/reformat-the-string/)

<p>给你一个混合了数字和字母的字符串 <code>s</code>，其中的字母均为小写英文字母。</p>

<p>请你将该字符串重新格式化，使得任意两个相邻字符的类型都不同。也就是说，字母后面应该跟着数字，而数字后面应该跟着字母。</p>

<p>请你返回 <strong>重新格式化后</strong> 的字符串；如果无法按要求重新格式化，则返回一个 <strong>空字符串</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = &quot;a0b1c2&quot;
<strong>输出：</strong>&quot;0a1b2c&quot;
<strong>解释：</strong>&quot;0a1b2c&quot; 中任意两个相邻字符的类型都不同。 &quot;a0b1c2&quot;, &quot;0a1b2c&quot;, &quot;0c2a1b&quot; 也是满足题目要求的答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = &quot;leetcode&quot;
<strong>输出：</strong>&quot;&quot;
<strong>解释：</strong>&quot;leetcode&quot; 中只有字母，所以无法满足重新格式化的条件。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = &quot;1229857369&quot;
<strong>输出：</strong>&quot;&quot;
<strong>解释：</strong>&quot;1229857369&quot; 中只有数字，所以无法满足重新格式化的条件。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>s = &quot;covid2019&quot;
<strong>输出：</strong>&quot;c2o0v1i9d&quot;
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>s = &quot;ab123&quot;
<strong>输出：</strong>&quot;1a2b3&quot;
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 500</code></li>
	<li><code>s</code> 仅由小写英文字母和/或数字组成。</li>
</ul>


    
## 方法一：模拟

不考虑优化空间复杂度的情况下：

首先预处理一遍原始字符串，将字母和数字分别存放在两个新的字符串中。

如果两个字符串长度只差大于1，那么就不能构造出合法“交替字符串”，就返回空。

否则：用一个变量记录下一个字符应该是字母还是数字，在两个字符串有任意一个没有使用完时，按照变量指示取出对应字符串中的字符，并将变量置反（字母->数字|数字->字母）

+ 时间复杂度$O(n)$，其中$n$是原始字符串的长度
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    string reformat(string& s) {
        string C, N;
        for (char& c : s) {
            if (c >= 'a' && c <= 'z')
                C += c;
            else
                N += c;
        }
        if (abs(int(C.size() - N.size())) > 1)
            return "";
        bool shouldC = C.size() >= N.size();
        string ans;
        int locC = 0, locN = 0;
        while (locC < C.size() || locN < N.size()) {
            if (shouldC) {
                shouldC = false;
                ans += C[locC++];
            }
            else {
                shouldC = true;
                ans += N[locN++];
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/08/11/LeetCode%201417.%E9%87%8D%E6%96%B0%E6%A0%BC%E5%BC%8F%E5%8C%96%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126279589](https://letmefly.blog.csdn.net/article/details/126279589)
