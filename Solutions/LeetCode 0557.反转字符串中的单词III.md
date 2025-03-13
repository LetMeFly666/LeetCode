---
title: 557.反转字符串中的单词 III
date: 2023-03-14 13:55:09
tags: [题解, LeetCode, 简单, 双指针, 字符串, 字符串翻转, 字符串变换]
categories: [题解, LeetCode]
---

# 【LetMeFly】557.反转字符串中的单词 III

力扣题目链接：[https://leetcode.cn/problems/reverse-words-in-a-string-iii/](https://leetcode.cn/problems/reverse-words-in-a-string-iii/)

<p>给定一个字符串<meta charset="UTF-8" />&nbsp;<code>s</code>&nbsp;，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "Let's take LeetCode contest"
<strong>输出：</strong>"s'teL ekat edoCteeL tsetnoc"
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入：</strong> s = "God Ding"
<strong>输出：</strong>"doG gniD"
</pre>

<p>&nbsp;</p>

<p><strong><strong><strong><strong>提示：</strong></strong></strong></strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><meta charset="UTF-8" /><code>s</code>&nbsp;包含可打印的 <strong>ASCII</strong> 字符。</li>
	<li><meta charset="UTF-8" /><code>s</code>&nbsp;不包含任何开头或结尾空格。</li>
	<li><meta charset="UTF-8" /><code>s</code>&nbsp;里 <strong>至少</strong> 有一个词。</li>
	<li><meta charset="UTF-8" /><code>s</code>&nbsp;中的所有单词都用一个空格隔开。</li>
</ul>


    
## 方法一：模拟

首先，遍历并找到字符串中的所有的空格

接着，翻转两个空格之间的字符串即可。

### C++

使用一个变量begin记录这个“子字符串”开始的下标

接着遍历原始字符串，如果遍历到了原始字符串的末尾或者空格，就翻转这个子字符串，并更新begin的值

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(1)$

### Python

首先将原始字符串以空格分隔

```python
s.split()
```

接着，使用```join```函数，以空格为间隔按顺序添加“分隔后字符列表中的每一个字符 的 反向形式”


```python
' '.join(i[::-1] for i in s.split())
```

其中$i$是“分隔后字符列表中的每一个字符”，$i[::-1]$是其翻转后的形式。

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(len(s))$

### AC代码

#### C++

```cpp
class Solution {
public:
    string reverseWords(string& s) {
        int begin = 0;
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                reverse(s.begin() + begin, s.begin() + i);
                begin = i + 1;
            }
        }
        return s;
    }
};
```

#### Python

```python
class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(i[::-1] for i in s.split())
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/03/14/LeetCode%200557.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E7%9A%84%E5%8D%95%E8%AF%8DIII/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129526011](https://letmefly.blog.csdn.net/article/details/129526011)
