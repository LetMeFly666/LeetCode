---
title: 1592.重新排列单词间的空格
date: 2022-09-07 20:03:41
tags: [题解, LeetCode, 简单, 字符串, 构造, 计算, 分配]
---

# 【LetMeFly】1592.重新排列单词间的空格

力扣题目链接：[https://leetcode.cn/problems/rearrange-spaces-between-words/](https://leetcode.cn/problems/rearrange-spaces-between-words/)

<p>给你一个字符串 <code>text</code> ，该字符串由若干被空格包围的单词组成。每个单词由一个或者多个小写英文字母组成，并且两个单词之间至少存在一个空格。题目测试用例保证 <code>text</code> <strong>至少包含一个单词</strong> 。</p>

<p>请你重新排列空格，使每对相邻单词之间的空格数目都 <strong>相等</strong> ，并尽可能 <strong>最大化</strong> 该数目。如果不能重新平均分配所有空格，请 <strong>将多余的空格放置在字符串末尾</strong> ，这也意味着返回的字符串应当与原 <code>text</code> 字符串的长度相等。</p>

<p>返回 <strong>重新排列空格后的字符串</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>text = &quot;  this   is  a sentence &quot;
<strong>输出：</strong>&quot;this   is   a   sentence&quot;
<strong>解释：</strong>总共有 9 个空格和 4 个单词。可以将 9 个空格平均分配到相邻单词之间，相邻单词间空格数为：9 / (4-1) = 3 个。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>text = &quot; practice   makes   perfect&quot;
<strong>输出：</strong>&quot;practice   makes   perfect &quot;
<strong>解释：</strong>总共有 7 个空格和 3 个单词。7 / (3-1) = 3 个空格加上 1 个多余的空格。多余的空格需要放在字符串的末尾。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>text = &quot;hello   world&quot;
<strong>输出：</strong>&quot;hello   world&quot;
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>text = &quot;  walks  udp package   into  bar a&quot;
<strong>输出：</strong>&quot;walks  udp  package  into  bar  a &quot;
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>text = &quot;a&quot;
<strong>输出：</strong>&quot;a&quot;
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 100</code></li>
	<li><code>text</code> 由小写英文字母和 <code>&#39; &#39;</code> 组成</li>
	<li><code>text</code> 中至少包含一个单词</li>
</ul>


    
## 方法一：计算 + 模拟

**思路**

两次遍历

第一次遍历统计出单词的个数、空格的个数

然后就能计算出两个单词之间应该有多少个空格、最后一个单词后有多少个空格

第二次遍历，遇到空格就跳过，遇到字母就输出。如果遇到的是某个单词的最后一个字母，就输出应有数量的空格。

**具体方法**

统计空格的个数很简单，遍历的时候如果这个字符是空格就累加即可。

统计单词的个数的时候，记录一下上一个字符是字母还是空格。如果上一个字符是空格并且当前又遇到了字母，那么单词数量+1。

判断第二次遍历时是否为某个单词的最后一个字母的方法为：如果这个**字母**不是字符串的最后一个字符，并且下一个字符是空格，那么这个字母就是某个单词的最后一个字母。

确定空格数量的方式为：单词之间的空格数量为$\lfloor\frac{空格数量}{单词数量 - 1}\rfloor$；所有单词后的空格的数量为$空格数量 \mod (单词数量 - 1)$

+ 时间复杂度$O(n)$，其中$n$是文本长度
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    string reorderSpaces(string& text) {
        // count spaces
        int spaces = 0;
        int numOfWords = 0;
        bool lastIsSpace = true;
        for (char& c : text) {
            if (c == ' ') {
                spaces++;
                lastIsSpace = true;
            }
            else {
                if (lastIsSpace) {
                    lastIsSpace = false;
                    numOfWords++;
                }
            }

        }

        // calculate
        int perSpace, lastSpace;
        if (numOfWords == 1) {
            perSpace = 0;
            lastSpace = spaces;
        }
        else {
            perSpace = spaces / (numOfWords - 1);
            lastSpace = spaces % (numOfWords - 1);
        }

        // construct
        string ans;
        int nowWords = 0;
        for (int i = 0; i < text.size(); i++) {
            if (text[i] == ' ')
                continue;
            ans += text[i];
            if (i + 1 < text.size() && text[i + 1] == ' ') {  // 单词的最后一个字母
                nowWords++;
                if (nowWords != numOfWords) {
                    for (int j = 0; j < perSpace; j++) {
                        ans += ' ';
                    }
                }
            }
        }
        for (int i = 0; i < lastSpace; i++) {
            ans += ' ';
        }
        return ans;
    }
};
```

附上一个LeetCode官解的Python代码（好简洁）

```python
class Solution:
    def reorderSpaces(self, text: str) -> str:
        words = text.split()
        space = text.count(' ')
        if len(words) == 1:
            return words[0] + ' ' * space
        per_space, rest_space = divmod(space, len(words) - 1)
        return (' ' * per_space).join(words) + ' ' * rest_space
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/09/07/LeetCode%201592.%E9%87%8D%E6%96%B0%E6%8E%92%E5%88%97%E5%8D%95%E8%AF%8D%E9%97%B4%E7%9A%84%E7%A9%BA%E6%A0%BC/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126752968](https://letmefly.blog.csdn.net/article/details/126752968)
