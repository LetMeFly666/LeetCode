---
title: 2490.回环句：判断空格前后字母是否相同
date: 2023-06-30 07:28:55
tags: [题解, LeetCode, 简单, 字符串]
---

# 【LetMeFly】2490.回环句：判断空格前后字母是否相同

力扣题目链接：[https://leetcode.cn/problems/circular-sentence/](https://leetcode.cn/problems/circular-sentence/)

<p><strong>句子</strong> 是由单个空格分隔的一组单词，且不含前导或尾随空格。</p>

<ul>
	<li>例如，<code>"Hello World"</code>、<code>"HELLO"</code>、<code>"hello world hello world"</code> 都是符合要求的句子。</li>
</ul>

<p>单词 <strong>仅</strong> 由大写和小写英文字母组成。且大写和小写字母会视作不同字符。</p>

<p>如果句子满足下述全部条件，则认为它是一个 <strong>回环句</strong> ：</p>

<ul>
	<li>单词的最后一个字符和下一个单词的第一个字符相等。</li>
	<li>最后一个单词的最后一个字符和第一个单词的第一个字符相等。</li>
</ul>

<p>例如，<code>"leetcode exercises sound delightful"</code>、<code>"eetcode"</code>、<code>"leetcode eats soul"</code> 都是回环句。然而，<code>"Leetcode is cool"</code>、<code>"happy Leetcode"</code>、<code>"Leetcode"</code> 和 <code>"I like Leetcode"</code> 都 <strong>不</strong> 是回环句。</p>

<p>给你一个字符串 <code>sentence</code> ，请你判断它是不是一个回环句。如果是，返回 <code>true</code><em> </em>；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>sentence = "leetcode exercises sound delightful"
<strong>输出：</strong>true
<strong>解释：</strong>句子中的单词是 ["leetcode", "exercises", "sound", "delightful"] 。
- leetcod<strong><em>e</em></strong> 的最后一个字符和 <strong><em>e</em></strong>xercises 的第一个字符相等。
- exercise<em><strong>s</strong></em> 的最后一个字符和 <em><strong>s</strong></em>ound 的第一个字符相等。
- <em><strong>s</strong></em>ound 的最后一个字符和 delightfu<em><strong>l</strong></em> 的第一个字符相等。
- delightfu<em><strong>l</strong></em> 的最后一个字符和 <em><strong>l</strong></em>eetcode 的第一个字符相等。
这个句子是回环句。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>sentence = "eetcode"
<strong>输出：</strong>true
<strong>解释：</strong>句子中的单词是 ["eetcode"] 。
- eetcod<em><strong>e</strong></em> 的最后一个字符和 eetcod<em><strong>e</strong></em> 的第一个字符相等。
这个句子是回环句。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>sentence = "Leetcode is cool"
<strong>输出：</strong>false
<strong>解释：</strong>句子中的单词是 ["Leetcode", "is", "cool"] 。
- Leetcod<em><strong>e</strong></em>&nbsp;的最后一个字符和 i<strong><em>s</em></strong> 的第一个字符 <strong>不</strong> 相等。 
这个句子 <strong>不</strong> 是回环句。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= sentence.length &lt;= 500</code></li>
	<li><code>sentence</code> 仅由大小写英文字母和空格组成</li>
	<li><code>sentence</code> 中的单词由单个空格进行分隔</li>
	<li>不含任何前导或尾随空格</li>
</ul>


    
## 方法一：判断空格前后字母是否相同

题目说明了“句子”的格式：以单个空格分隔的数个单词组成句子。

因此，我们只需要遍历一遍字符串，遍历到空格时，判断这个空格的前后字符是否相同即可。

最终，还需要特判一下句子的第一个字母和最后一个字母是否相同。

+ 时间复杂度$O(len(sentence))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool isCircularSentence(string sentence) {
        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] == ' ') {
                if (sentence[i - 1] != sentence[i + 1]) {
                    return false;
                }
            }
        }
        return sentence.back() == sentence[0];
    }
};
```

#### Python

```python
class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        for i in range(len(sentence)):
            if sentence[i] == ' ':
                if sentence[i - 1] != sentence[i + 1]:
                    return False
        return sentence[-1] == sentence[0]
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/06/30/LeetCode%202490.%E5%9B%9E%E7%8E%AF%E5%8F%A5/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131468453](https://letmefly.blog.csdn.net/article/details/131468453)
