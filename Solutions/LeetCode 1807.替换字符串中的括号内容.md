---
title: 1807.替换字符串中的括号内容
date: 2023-01-12 22:22:24
tags: [题解, LeetCode, 中等, 数组, 哈希表, 字符串, 字符串解析]
---

# 【LetMeFly】1807.替换字符串中的括号内容

力扣题目链接：[https://leetcode.cn/problems/evaluate-the-bracket-pairs-of-a-string/](https://leetcode.cn/problems/evaluate-the-bracket-pairs-of-a-string/)

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;，它包含一些括号对，每个括号中包含一个 <strong>非空</strong>&nbsp;的键。</p>

<ul>
	<li>比方说，字符串&nbsp;<code>"(name)is(age)yearsold"</code>&nbsp;中，有&nbsp;<strong>两个</strong>&nbsp;括号对，分别包含键&nbsp;<code>"name"</code> 和&nbsp;<code>"age"</code>&nbsp;。</li>
</ul>

<p>你知道许多键对应的值，这些关系由二维字符串数组&nbsp;<code>knowledge</code>&nbsp;表示，其中&nbsp;<code>knowledge[i] = [key<sub>i</sub>, value<sub>i</sub>]</code>&nbsp;，表示键&nbsp;<code>key<sub>i</sub></code>&nbsp;对应的值为&nbsp;<code>value<sub>i</sub></code><sub>&nbsp;</sub>。</p>

<p>你需要替换 <strong>所有</strong>&nbsp;的括号对。当你替换一个括号对，且它包含的键为&nbsp;<code>key<sub>i</sub></code>&nbsp;时，你需要：</p>

<ul>
	<li>将&nbsp;<code>key<sub>i</sub></code>&nbsp;和括号用对应的值&nbsp;<code>value<sub>i</sub></code>&nbsp;替换。</li>
	<li>如果从 <code>knowledge</code>&nbsp;中无法得知某个键对应的值，你需要将&nbsp;<code>key<sub>i</sub></code>&nbsp;和括号用问号&nbsp;<code>"?"</code>&nbsp;替换（不需要引号）。</li>
</ul>

<p><code>knowledge</code>&nbsp;中每个键最多只会出现一次。<code>s</code>&nbsp;中不会有嵌套的括号。</p>

<p>请你返回替换 <strong>所有</strong>&nbsp;括号对后的结果字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>s = "(name)is(age)yearsold", knowledge = [["name","bob"],["age","two"]]
<b>输出：</b>"bobistwoyearsold"
<strong>解释：</strong>
键 "name" 对应的值为 "bob" ，所以将 "(name)" 替换为 "bob" 。
键 "age" 对应的值为 "two" ，所以将 "(age)" 替换为 "two" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>s = "hi(name)", knowledge = [["a","b"]]
<b>输出：</b>"hi?"
<b>解释：</b>由于不知道键 "name" 对应的值，所以用 "?" 替换 "(name)" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>s = "(a)(a)(a)aaa", knowledge = [["a","yes"]]
<b>输出：</b>"yesyesyesaaa"
<b>解释：</b>相同的键在 s 中可能会出现多次。
键 "a" 对应的值为 "yes" ，所以将所有的 "(a)" 替换为 "yes" 。
注意，不在括号里的 "a" 不需要被替换。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= knowledge.length &lt;= 10<sup>5</sup></code></li>
	<li><code>knowledge[i].length == 2</code></li>
	<li><code>1 &lt;= key<sub>i</sub>.length, value<sub>i</sub>.length &lt;= 10</code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母和圆括号&nbsp;<code>'('</code>&nbsp;和&nbsp;<code>')'</code>&nbsp;。</li>
	<li><code>s</code>&nbsp;中每一个左圆括号&nbsp;<code>'('</code>&nbsp;都有对应的右圆括号&nbsp;<code>')'</code>&nbsp;。</li>
	<li><code>s</code>&nbsp;中每对括号内的键都不会为空。</li>
	<li><code>s</code>&nbsp;中不会有嵌套括号对。</li>
	<li><code>key<sub>i</sub></code>&nbsp;和&nbsp;<code>value<sub>i</sub></code>&nbsp;只包含小写英文字母。</li>
	<li><code>knowledge</code>&nbsp;中的&nbsp;<code>key<sub>i</sub></code>&nbsp;不会重复。</li>
</ul>


    
## 方法一：哈希表 + 字符串解析

这道题的关键就是字符串的解析，将字符串解析出来，然后将括号中的$key$替换成$value$，并且去掉括号即可。

这就包含两个问题

1. 如何将括号中的$key$解析出来
2. 如何将括号中的$key$替换为对应的$value$

**首先来解决问题一**：何将括号中的$key$解析出来

我们用i遍历字符串$s$的下标，$i$的初始值是$0$，到$s.length$为止。

期间，如果$s[i]$不为```'('```，那么我们就不断地将$s[i]$添加到答案字符串中去（这些都是不用解析的部分）

一旦遇到了```'('```，我们就用另外一个变量$to$，从$i + 1$开始往后累加，直到$s[to]$为```')'```为止。

这样，我们就提取出了这对括号中间的$key$

**接着来解决问题二**：如何将括号中的$key$替换为对应的$value$

这个很简单，开辟一个哈希表，首先遍历一遍$knowledge$数组，将$knowledge$中每一个“二元对”的第一个字符串当作$key$，第二个字符串当作$value$存入哈希表中。

这样就能很方便地直到$key$是否在哈希表中，以及其在哈希表中的话，对应的$value$是什么

+ 时间复杂度$O(len(s) + knowledge中字符数目之和)$
+ 空间复杂度$O(knowledge中字符数目之和)$

### AC代码

#### C++

```cpp
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans;
        unordered_map<string, string> ma;
        for (auto& v : knowledge) {
            ma[v[0]] = v[1];
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                int to = i + 1;
                while (s[to] != ')') {
                    to++;
                }
                string key = s.substr(i + 1, to - i - 1);
                ans += ma.count(key) ? ma[key] : "?";
                i = to;  // 循环结束后会有i++
            }
            else {
                ans += s[i];
            }
        }
        return ans;
    }
};
```

#### Python

```python
class Solution:
    def evaluate(self, s: str, knowledge: List[List[str]]) -> str:
        ma = {}
        for v in knowledge:
            ma[v[0]] = v[1]
        ans = ""
        i = 0
        while i < len(s):  # 使用for i in range(s)的话，不易在下方修改i的值
            if (s[i] == '('):
                to = i + 1
                while s[to] != ')':
                    to += 1
                ans += ma.get(s[i + 1 : to], "?")
                i = to
            else:
                ans += s[i]
            i += 1
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2023/01/12/LeetCode%201807.%E6%9B%BF%E6%8D%A2%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E7%9A%84%E6%8B%AC%E5%8F%B7%E5%86%85%E5%AE%B9/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128667712](https://letmefly.blog.csdn.net/article/details/128667712)
