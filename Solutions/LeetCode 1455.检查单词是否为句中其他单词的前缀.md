---
title: 1455.检查单词是否为句中其他单词的前缀
date: 2022-08-21 10:22:33
tags: [题解, LeetCode, 简单, 字符串, 字符串匹配, 双指针]
---

# 【LetMeFly】1455.检查单词是否为句中其他单词的前缀

力扣题目链接：[https://leetcode.cn/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/](https://leetcode.cn/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/)

<p>给你一个字符串 <code>sentence</code> 作为句子并指定检索词为 <code>searchWord</code> ，其中句子由若干用 <strong>单个空格</strong> 分隔的单词组成。请你检查检索词 <code>searchWord</code> 是否为句子 <code>sentence</code> 中任意单词的前缀。</p>

<p>如果&nbsp;<code>searchWord</code> 是某一个单词的前缀，则返回句子&nbsp;<code>sentence</code> 中该单词所对应的下标（<strong>下标从 1 开始</strong>）。如果 <code>searchWord</code> 是多个单词的前缀，则返回匹配的第一个单词的下标（<strong>最小下标</strong>）。如果 <code>searchWord</code> 不是任何单词的前缀，则返回 <code>-1</code><strong> </strong>。</p>

<p>字符串 <code>s</code> 的 <strong>前缀</strong> 是 <code>s</code> 的任何前导连续子字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>sentence = "i love eating burger", searchWord = "burg"
<strong>输出：</strong>4
<strong>解释：</strong>"burg" 是 "burger" 的前缀，而 "burger" 是句子中第 4 个单词。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>sentence = "this problem is an easy problem", searchWord = "pro"
<strong>输出：</strong>2
<strong>解释：</strong>"pro" 是 "problem" 的前缀，而 "problem" 是句子中第 2 个也是第 6 个单词，但是应该返回最小下标 2 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>sentence = "i am tired", searchWord = "you"
<strong>输出：</strong>-1
<strong>解释：</strong>"you" 不是句子中任何单词的前缀。

</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= sentence.length &lt;= 100</code></li>
	<li><code>1 &lt;= searchWord.length &lt;= 10</code></li>
	<li><code>sentence</code> 由小写英文字母和空格组成。</li>
	<li><code>searchWord</code> 由小写英文字母组成。</li>
</ul>


    
## 方法一：双指针

用两个指针，初始值分别指向句子的第一个字母和单词的第一个字母。

在两个指针**都未指完**对应字符串时：

+ 如果句子中的当前字母和单词的当前字母相同，就两个指针都向后移动一位
+ 否则就把单词指针指向单词的第一个字母，句子指针不断向后寻找，找到下一个单词为止

如果中途某一刻单词指针超过了单词尾部，就说明找到了相同前缀，返回当前单词是第几个单词。

否则，循环退出且未匹配成功，返回-1。

+ 时间复杂度$O(n)$，其中$n$是句子的长度
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int isPrefixOfWord(string& sentence, string& searchWord) {
        int locLong = 0, locShort = 0;
        int th = 1;  // 第几个单词
        while (locLong < sentence.size() && locShort < searchWord.size()) {
            if (sentence[locLong] == searchWord[locShort]) {
                locLong++, locShort++;
            }
            else {
                locShort = 0;
                while (locLong < sentence.size() && sentence[locLong] != ' ') {
                    locLong++;
                }
                locLong++;  // 空格后
                th++;
            }
            if (locShort == searchWord.size())
                return th;
        }
        return -1;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/08/21/LeetCode%201455.%E6%A3%80%E6%9F%A5%E5%8D%95%E8%AF%8D%E6%98%AF%E5%90%A6%E4%B8%BA%E5%8F%A5%E4%B8%AD%E5%85%B6%E4%BB%96%E5%8D%95%E8%AF%8D%E7%9A%84%E5%89%8D%E7%BC%80/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126448124](https://letmefly.blog.csdn.net/article/details/126448124)
