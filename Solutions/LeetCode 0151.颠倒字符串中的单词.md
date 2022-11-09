---
title: 151.颠倒字符串中的单词
date: 2022-08-01 08:36:03
tags: [题解, LeetCode, 中等, 双指针, 字符串, 栈, 字符串反转, 字符串变换]
---

# 【LetMeFly】151.颠倒字符串中的单词

力扣题目链接：[https://leetcode.cn/problems/reverse-words-in-a-string/](https://leetcode.cn/problems/reverse-words-in-a-string/)

<p>给你一个字符串 <code>s</code> ，颠倒字符串中 <strong>单词</strong> 的顺序。</p>

<p><strong>单词</strong> 是由非空格字符组成的字符串。<code>s</code> 中使用至少一个空格将字符串中的 <strong>单词</strong> 分隔开。</p>

<p>返回 <strong>单词</strong> 顺序颠倒且 <strong>单词</strong> 之间用单个空格连接的结果字符串。</p>

<p><strong>注意：</strong>输入字符串 <code>s</code>中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "<code>the sky is blue</code>"
<strong>输出：</strong>"<code>blue is sky the</code>"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = " &nbsp;hello world &nbsp;"
<strong>输出：</strong>"world hello"
<strong>解释：</strong>颠倒后的字符串中不能存在前导空格和尾随空格。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "a good &nbsp; example"
<strong>输出：</strong>"example good a"
<strong>解释：</strong>如果两个单词间有多余的空格，颠倒后的字符串需要将单词间的空格减少到仅有一个。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> 包含英文大小写字母、数字和空格 <code>' '</code></li>
	<li><code>s</code> 中 <strong>至少存在一个</strong> 单词</li>
</ul>

<ul>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>如果字符串在你使用的编程语言中是一种可变数据类型，请尝试使用&nbsp;<code>O(1)</code> 额外空间复杂度的 <strong>原地</strong> 解法。</p>


    
## 方法一：栈

从后往前遍历每一个字符，遇到```非空格字符```就入栈，遇到空格/遍历到字符串首 就看栈是否为空

如果栈不空，就在答案字符串后添加栈中的新单词

添加方式为：(如果这个单词不是答案字符串的第一个单词，就加上空格。)逐个出栈并添加到答案字符串尾部

+ 时间复杂度$O(n)$，其中$n$为原始字符串的长度
+ 空间复杂度$O(m)$，其中$m$为最大单词长度

### AC代码

#### C++

```cpp
class Solution {
public:
    string reverseWords(string s) {
        string ans;
        stack<char> st;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ' ')
                st.push(s[i]);
            if (s[i] == ' ' || !i) {
                if (st.size()) {
                    if (ans.size())
                        ans += ' ';
                    while (st.size()) {
                        ans += st.top();
                        st.pop();
                    }
                }
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/08/01/LeetCode%200151.%E9%A2%A0%E5%80%92%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E7%9A%84%E5%8D%95%E8%AF%8D/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126093751](https://letmefly.blog.csdn.net/article/details/126093751)
