---
title: 290.单词规律
date: 2022-09-16 09:41:48
tags: [题解, LeetCode, 简单, 哈希表, 字符串]
categories: [题解, LeetCode]
---

# 【LetMeFly】290.单词规律

力扣题目链接：[https://leetcode.cn/problems/word-pattern/](https://leetcode.cn/problems/word-pattern/)

<p>给定一种规律 <code>pattern</code>&nbsp;和一个字符串&nbsp;<code>s</code>&nbsp;，判断 <code>s</code>&nbsp;是否遵循相同的规律。</p>

<p>这里的&nbsp;<strong>遵循&nbsp;</strong>指完全匹配，例如，&nbsp;<code>pattern</code>&nbsp;里的每个字母和字符串&nbsp;<code>str</code><strong>&nbsp;</strong>中的每个非空单词之间存在着双向连接的对应规律。</p>

<p>&nbsp;</p>

<p><strong>示例1:</strong></p>

<pre>
<strong>输入:</strong> pattern = <code>"abba"</code>, str = <code>"dog cat cat dog"</code>
<strong>输出:</strong> true</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong>pattern = <code>"abba"</code>, str = <code>"dog cat cat fish"</code>
<strong>输出:</strong> false</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> pattern = <code>"aaaa"</code>, str = <code>"dog cat cat dog"</code>
<strong>输出:</strong> false</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= pattern.length &lt;= 300</code></li>
	<li><code>pattern</code>&nbsp;只包含小写英文字母</li>
	<li><code>1 &lt;= s.length &lt;= 3000</code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母和&nbsp;<code>' '</code></li>
	<li><code>s</code>&nbsp;<strong>不包含</strong> 任何前导或尾随对空格</li>
	<li><code>s</code>&nbsp;中每个单词都被 <strong>单个空格 </strong>分隔</li>
</ul>


    
## 方法一：哈希表

这道题题目描述挺含糊的。

大概意思就是$pattern$中的一个字母**唯一对应**$s$中的一个单词。

但是DT的是C++里没有split。

因此C++选手需要手动模拟拆分字符串。

用一个记录上一个单词的起始位置的前一个位置，用一个变量记录遍历到了第几个单词，用两个哈希表分别存放单词和字母的对应关系。

每遍历到一个单词，就看是否和字母一一对应。

+ 时间复杂度$O(n)$，其中$n$是字符串长度
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool wordPattern(string& pattern, string& s) {
        unordered_map<char, string> c2s;
        unordered_map<string, char> s2c;
        int th = 0;
        int lastBegin = -1;
        s += ' ';
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                string thisWord = s.substr(lastBegin + 1, i - lastBegin - 1);
                lastBegin = i;
                if (c2s.count(pattern[th])) {
                    if (c2s[pattern[th]] != thisWord) {
                        return false;
                    }
                }
                else {
                    c2s[pattern[th]] = thisWord;
                }
                if (s2c.count(thisWord)) {
                    if (s2c[thisWord] != pattern[th]) {
                        return false;
                    }
                }
                else {
                    s2c[thisWord] = pattern[th];
                }
                th++;
            }
        }
        return th == pattern.size();
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/09/16/LeetCode%200290.%E5%8D%95%E8%AF%8D%E8%A7%84%E5%BE%8B/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126884583](https://letmefly.blog.csdn.net/article/details/126884583)
