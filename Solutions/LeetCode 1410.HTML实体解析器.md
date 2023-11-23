---
title: 1410.HTML 实体解析器
date: 2023-11-23 10:07:56
tags: [题解, LeetCode, 中等, 哈希表, 字符串]
---

# 【LetMeFly】1410.HTML 实体解析器：字符串匹配

力扣题目链接：[https://leetcode.cn/problems/html-entity-parser/](https://leetcode.cn/problems/html-entity-parser/)

<p>「HTML&nbsp;实体解析器」 是一种特殊的解析器，它将 HTML 代码作为输入，并用字符本身替换掉所有这些特殊的字符实体。</p>

<p>HTML 里这些特殊字符和它们对应的字符实体包括：</p>

<ul>
	<li><strong>双引号：</strong>字符实体为&nbsp;<code>&amp;quot;</code>&nbsp;，对应的字符是&nbsp;<code>&quot;</code>&nbsp;。</li>
	<li><strong>单引号：</strong>字符实体为&nbsp;<code>&amp;apos;</code>&nbsp;，对应的字符是&nbsp;<code>&#39;</code>&nbsp;。</li>
	<li><strong>与符号：</strong>字符实体为&nbsp;<code>&amp;amp;</code>&nbsp;，对应对的字符是&nbsp;<code>&amp;</code>&nbsp;。</li>
	<li><strong>大于号：</strong>字符实体为&nbsp;<code>&amp;gt;</code>&nbsp;，对应的字符是&nbsp;<code>&gt;</code>&nbsp;。</li>
	<li><strong>小于号：</strong>字符实体为&nbsp;<code>&amp;lt;</code>&nbsp;，对应的字符是&nbsp;<code>&lt;</code>&nbsp;。</li>
	<li><strong>斜线号：</strong>字符实体为&nbsp;<code>&amp;frasl;</code>&nbsp;，对应的字符是&nbsp;<code>/</code>&nbsp;。</li>
</ul>

<p>给你输入字符串&nbsp;<code>text</code>&nbsp;，请你实现一个 HTML&nbsp;实体解析器，返回解析器解析后的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>text = &quot;&amp;amp; is an HTML entity but &amp;ambassador; is not.&quot;
<strong>输出：</strong>&quot;&amp; is an HTML entity but &amp;ambassador; is not.&quot;
<strong>解释：</strong>解析器把字符实体 &amp;amp; 用 &amp; 替换
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入：</strong>text = &quot;and I quote: &amp;quot;...&amp;quot;&quot;
<strong>输出：</strong>&quot;and I quote: \&quot;...\&quot;&quot;
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>text = &quot;Stay home! Practice on Leetcode :)&quot;
<strong>输出：</strong>&quot;Stay home! Practice on Leetcode :)&quot;
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>text = &quot;x &amp;gt; y &amp;amp;&amp;amp; x &amp;lt; y is always false&quot;
<strong>输出：</strong>&quot;x &gt; y &amp;&amp; x &lt; y is always false&quot;
</pre>

<p><strong>示例 5：</strong></p>

<pre>
<strong>输入：</strong>text = &quot;leetcode.com&amp;frasl;problemset&amp;frasl;all&quot;
<strong>输出：</strong>&quot;leetcode.com/problemset/all&quot;
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 10^5</code></li>
	<li>字符串可能包含 256 个ASCII 字符中的任意字符。</li>
</ul>


    
## 方法一：字符串匹配

一共就6种要替换的情况，我们可以先把6种要替换的情况都存下来到一个数组中（理解为哈希表也可以）。

接着就开始愉快地遍历```text```字符串了：

+ 如果当前字符为```&```：
   + 遍历替换数组，如果能匹配则将答案字符串加上要替换的结果
   + 如果全部匹配不上就加上当前字符
+ 否则：答案字符串加上当前字符

最终返回答案字符串即可。

+ 时间复杂度$O(len(text)\times k)$，其中$k$是要替换字符串的评价长度
+ 空间复杂度$O(C)$，只有“替换数组”占据了常数大小的空间

### AC代码

#### C++

```cpp
const static vector<pair<string, char>> dic = {
    {"&quot;", '"'},
    {"&apos;", '\''},
    {"&amp;", '&'},
    {"&gt;", '>'},
    {"&lt;", '<'},
    {"&frasl;", '/'}
};

class Solution {
public:
    string entityParser(string& text) {
        string ans;
        for (int i = 0; i < text.size(); i++) {
            if (text[i] == '&') {
                for (auto&& [from, to] : dic) {
                    if (text.substr(i, from.size()) == from) {
                        ans += to;
                        i += from.size() - 1;
                        goto loop;
                    }
                }
            }
            ans += text[i];
            loop:;
        }
        return ans;
    }
};
```

#### Python

```python
dic = [
    ('&quot;', '"'),
    ('&apos;', "'"),
    ('&gt;', '>'),
    ('&lt;', '<'),
    ('&frasl;', '/'),
    ('&amp;', '&')
]

class Solution:
    def entityParser(self, text: str) -> str:
        ans = ''
        i = 0
        while i < len(text):
            matched = False
            if text[i] == '&':
                for from_, to in dic:
                    if text[i: len(from_) + i] == from_:
                        matched = True
                        ans += to
                        i += len(from_)
                        break
            if not matched:
                ans += text[i]
                i += 1
        return ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2023/11/23/LeetCode%201410.HTML%E5%AE%9E%E4%BD%93%E8%A7%A3%E6%9E%90%E5%99%A8/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/134571778](https://letmefly.blog.csdn.net/article/details/134571778)
