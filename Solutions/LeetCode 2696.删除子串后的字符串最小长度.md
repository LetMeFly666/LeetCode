---
title: 2696.删除子串后的字符串最小长度
date: 2024-01-10 19:13:56
tags: [题解, LeetCode, 简单, 栈, 字符串, 模拟]
---

# 【LetMeFly】2696.删除子串后的字符串最小长度：栈

力扣题目链接：[https://leetcode.cn/problems/minimum-string-length-after-removing-substrings/](https://leetcode.cn/problems/minimum-string-length-after-removing-substrings/)

<p>给你一个仅由 <strong>大写</strong> 英文字符组成的字符串 <code>s</code> 。</p>

<p>你可以对此字符串执行一些操作，在每一步操作中，你可以从 <code>s</code> 中删除 <strong>任一个</strong> <code>"AB"</code> 或 <code>"CD"</code> 子字符串。</p>

<p>通过执行操作，删除所有&nbsp;<code>"AB"</code> 和 <code>"CD"</code> 子串，返回可获得的最终字符串的 <strong>最小</strong> 可能长度。</p>

<p><strong>注意</strong>，删除子串后，重新连接出的字符串可能会产生新的&nbsp;<code>"AB"</code> 或 <code>"CD"</code> 子串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "ABFCACDB"
<strong>输出：</strong>2
<strong>解释：</strong>你可以执行下述操作：
- 从 "<em><strong>AB</strong></em>FCACDB" 中删除子串 "AB"，得到 s = "FCACDB" 。
- 从 "FCA<em><strong>CD</strong></em>B" 中删除子串 "CD"，得到 s = "FCAB" 。
- 从 "FC<strong><em>AB</em></strong>" 中删除子串 "AB"，得到 s = "FC" 。
最终字符串的长度为 2 。
可以证明 2 是可获得的最小长度。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "ACBBD"
<strong>输出：</strong>5
<strong>解释：</strong>无法执行操作，字符串长度不变。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> 仅由大写英文字母组成</li>
</ul>


    
## 方法一：栈

使用一个栈存放字符串剩下的元素，遍历字符串：

+ 如果当前字符是```B```并且栈顶元素是```A```则```A```出栈
+ 否则如果当前字符是```D```并且栈顶元素是```C```则```C```出栈
+ 否则当前字符入栈

最终返回栈中元素的个数即可。

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(len(s))$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == 'B' && st.size() && st.top() == 'A') {
                st.pop();
            }
            else if (c == 'D' && st.size() && st.top() == 'C') {
                st.pop();
            }
            else {
                st.push(c);
            }
        }
        return st.size();
    }
};
```

#### Python

```python
class Solution:
    def minLength(self, s: str) -> int:
        st = []
        for c in s:
            if (c == 'B' and st and st[-1] == 'A') or (c == 'D' and st and st[-1] == 'C'):
                st.pop()
            else:
                st.append(c)
        return len(st)
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2024/01/10/LeetCode%202696.%E5%88%A0%E9%99%A4%E5%AD%90%E4%B8%B2%E5%90%8E%E7%9A%84%E5%AD%97%E7%AC%A6%E4%B8%B2%E6%9C%80%E5%B0%8F%E9%95%BF%E5%BA%A6/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135511159](https://letmefly.blog.csdn.net/article/details/135511159)
