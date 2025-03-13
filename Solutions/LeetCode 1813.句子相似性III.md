---
title: 1813.句子相似性 III
date: 2023-01-16 23:10:39
tags: [题解, LeetCode, 中等, 数组, 双指针, 字符串]
categories: [题解, LeetCode]
---

# 【LetMeFly】：“图解”1813.句子相似性 III

力扣题目链接：[https://leetcode.cn/problems/sentence-similarity-iii/](https://leetcode.cn/problems/sentence-similarity-iii/)

<p>一个句子是由一些单词与它们之间的单个空格组成，且句子的开头和结尾没有多余空格。比方说，<code>"Hello World"</code> ，<code>"HELLO"</code> ，<code>"hello world hello world"</code> 都是句子。每个单词都 <strong>只</strong> 包含大写和小写英文字母。</p>

<p>如果两个句子 <code>sentence1</code> 和 <code>sentence2</code> ，可以通过往其中一个句子插入一个任意的句子（<strong>可以是空句子</strong>）而得到另一个句子，那么我们称这两个句子是 <strong>相似的</strong> 。比方说，<code>sentence1 = "Hello my name is Jane"</code> 且 <code>sentence2 = "Hello Jane"</code> ，我们可以往 <code>sentence2</code> 中 <code>"Hello"</code> 和 <code>"Jane"</code> 之间插入 <code>"my name is"</code> 得到 <code>sentence1</code> 。</p>

<p>给你两个句子 <code>sentence1</code> 和 <code>sentence2</code> ，如果<em> </em><code>sentence1</code> 和<em> </em><code>sentence2</code> 是相似的，请你返回 <code>true</code> ，否则返回 <code>false</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>sentence1 = "My name is Haley", sentence2 = "My Haley"
<b>输出：</b>true
<b>解释：</b>可以往 sentence2 中 "My" 和 "Haley" 之间插入 "name is" ，得到 sentence1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>sentence1 = "of", sentence2 = "A lot of words"
<b>输出：</b>false
<strong>解释：</strong>没法往这两个句子中的一个句子只插入一个句子就得到另一个句子。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>sentence1 = "Eating right now", sentence2 = "Eating"
<b>输出：</b>true
<b>解释：</b>可以往 sentence2 的结尾插入 "right now" 得到 sentence1 。
</pre>

<p><strong>示例 4：</strong></p>

<pre><b>输入：</b>sentence1 = "Luky", sentence2 = "Lucccky"
<b>输出：</b>false
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= sentence1.length, sentence2.length &lt;= 100</code></li>
	<li><code>sentence1</code> 和 <code>sentence2</code> 都只包含大小写英文字母和空格。</li>
	<li><code>sentence1</code> 和 <code>sentence2</code> 中的单词都只由单个空格隔开。</li>
</ul>


    
## 方法一：双指针

为了方便处理，我们首先将句子拆分为单词。例如将```Hello World```拆分为```[Hello, World]```

接着对于单词列表1和单词列表2，分别使用首尾两个指针，指针指向两个单词列表中已经匹配上的部分。

为了方便理解，假设句子1为```A E B C```，句子2为```A E C```，那么：

```
单词1首指针                       单词1尾指针
     ↓                                ↓
           A      E      B        C         👈单词1
           A      E               C         👈单词2
     ↑                                ↑
单词2首指针                       单词2尾指针
```

接着在单词1和单词2的首指针的下一个单词匹配时，不断后移两个指针

```
    单词1首指针          单词1尾指针
         ↓                   ↓
A        E      B        C         👈单词1
A        E               C         👈单词2
         ↑                   ↑
    单词2首指针          单词2尾指针
```

不难发现两个单词列表的第一个单词```A```是匹配的，第二个单词```B```也是匹配的，但是第三个单词开始不匹配了。首指针的移动**到此为止**

接着开始移动尾指针

```
    单词1首指针      单词1尾指针
         ↓               ↓
A        E      B        C         👈单词1
A        E               C         👈单词2
         ↑               ↑
    单词2首指针      单词2尾指针
```

不难发现两个单词列表的最后一个单词```C```是匹配的，但是倒数第二个单词开始不匹配了。尾指针的移动**到此为止**

指针移动完毕，诶，单词列表2的首位指针相邻了！！！

这说明什么？这说明单词列表2的首指针所指过的单词，全都是单词列表1的“前缀”；而单词列表2的尾指针所指过的单词，全都是单词列表1的“后缀”

那不就说明单词列表1可以由单词列表2在中间添加数个连续的单词而得到么？

因此返回true即可

+ 时间复杂度$O(len(sentence1) + len(sentence2))$
+ 空间复杂度$O(len(sentence1) + len(sentence2))$

注意事项：

1. 比较指针的下一个单词之前，记得检测指针的下一个单词是否在单词列表的合法范围内，以防止越界
2. 在比较尾指针时，不但要保证指针的下一个所指下标大于等于0，还要保证下一个所指位置大于首指针（与首指针不重合，以防止某个单词匹配两次）

### AC代码

#### C++

```cpp
class Solution {
private:
    vector<string> sentence2words(string& s) {
        vector<string> ans;
        int start = 0;
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                ans.push_back(s.substr(start, i - start));
                start = i + 1;
            }
        }
        return ans;
    }
public:
    bool areSentencesSimilar(string& sentence1, string& sentence2) {
        vector<string> words1 = sentence2words(sentence1), words2 = sentence2words(sentence2);
        int front1 = -1, front2 = -1, back1 = words1.size(), back2 = words2.size();
        while (front1 + 1 < words1.size() && front2 + 1 < words2.size() && words1[front1 + 1] == words2[front2 + 1]) {
            front1++, front2++;
        }
        while (back1 - 1 > front1 && back2 - 1 > front2 && words1[back1 - 1] == words2[back2 - 1]) {
            back1--, back2--;
        }
        return front1 + 1  == back1|| front2 + 1 == back2;
    }
};
```

#### Python

```python
class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        words1 = sentence1.split()
        words2 = sentence2.split()
        front1, front2, back1, back2 = -1, -1, len(words1), len(words2)
        while front1 + 1 < len(words1) and front2 + 1 < len(words2) and words1[front1 + 1] == words2[front2 + 1]:
            front1 += 1
            front2 += 1
        while back1 - 1 > front1 and back2 - 1 > front2 and words1[back1 - 1] == words2[back2 - 1]:
            back1 -= 1
            back2 -= 1
        return front1 + 1 == back1 or front2 + 1 == back2
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/01/16/LeetCode%201813.%E5%8F%A5%E5%AD%90%E7%9B%B8%E4%BC%BC%E6%80%A7III/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128710464](https://letmefly.blog.csdn.net/article/details/128710464)
