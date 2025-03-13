---
title: 2828.判别首字母缩略词
date: 2023-12-20 14:05:28
tags: [题解, LeetCode, 简单, 数组, 字符串, 模拟, 遍历]
categories: [题解, LeetCode]
---

# 【LetMeFly】2828.判别首字母缩略词

力扣题目链接：[https://leetcode.cn/problems/check-if-a-string-is-an-acronym-of-words/](https://leetcode.cn/problems/check-if-a-string-is-an-acronym-of-words/)

<p>给你一个字符串数组&nbsp;<code>words</code> 和一个字符串 <code>s</code> ，请你判断 <code>s</code> 是不是 <code>words</code> 的 <strong>首字母缩略词</strong> 。</p>

<p>如果可以按顺序串联 <code>words</code> 中每个字符串的第一个字符形成字符串 <code>s</code> ，则认为 <code>s</code> 是 <code>words</code> 的首字母缩略词。例如，<code>"ab"</code> 可以由 <code>["apple", "banana"]</code> 形成，但是无法从 <code>["bear", "aardvark"]</code> 形成。</p>

<p>如果 <code>s</code> 是 <code>words</code> 的首字母缩略词，返回 <code>true</code><em> </em>；否则，返回<em> </em><code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>words = ["alice","bob","charlie"], s = "abc"
<strong>输出：</strong>true
<strong>解释：</strong>words 中 "alice"、"bob" 和 "charlie" 的第一个字符分别是 'a'、'b' 和 'c'。因此，s = "abc" 是首字母缩略词。 
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>words = ["an","apple"], s = "a"
<strong>输出：</strong>false
<strong>解释：</strong>words 中 "an" 和 "apple" 的第一个字符分别是 'a' 和 'a'。
串联这些字符形成的首字母缩略词是 "aa" 。
因此，s = "a" 不是首字母缩略词。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>words = ["never","gonna","give","up","on","you"], s = "ngguoy"
<strong>输出：</strong>true
<strong>解释：</strong>串联数组 words 中每个字符串的第一个字符，得到字符串 "ngguoy" 。
因此，s = "ngguoy" 是首字母缩略词。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 10</code></li>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>words[i]</code> 和 <code>s</code> 由小写英文字母组成</li>
</ul>


    
## 方法一：模拟（遍历）

首先看字符串和单词数组是否等长，若不等长直接返回```false```。

接着枚举字符串的每一位，如果这个字符与对应单词的首字母不同，则返回```false```。

遍历完成后，返回```true```。

+ 时间复杂度$O(len(words) + len(s))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if (s.size() != words.size()) {
            return false;
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != words[i][0]) {
                return false;
            }
        }
        return true;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def isAcronym(self, words: List[str], s: str) -> bool:
        if len(s) != len(words):
            return False
        for i in range(len(s)):
            if s[i] != words[i][0]:
                return False
        return True
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/12/20/LeetCode%202828.%E5%88%A4%E5%88%AB%E9%A6%96%E5%AD%97%E6%AF%8D%E7%BC%A9%E7%95%A5%E8%AF%8D/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135106811](https://letmefly.blog.csdn.net/article/details/135106811)
