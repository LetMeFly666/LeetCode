---
title: 1003.检查替换后的词是否有效
date: 2023-05-03 09:48:23
tags: [题解, LeetCode, 中等, 栈, 字符串]
---

# 【LetMeFly】1003.检查替换后的词是否有效

力扣题目链接：[https://leetcode.cn/problems/check-if-word-is-valid-after-substitutions/](https://leetcode.cn/problems/check-if-word-is-valid-after-substitutions/)

给你一个字符串 <code>s</code> ，请你判断它是否 <strong>有效</strong> 。
<p>字符串 <code>s</code> <strong>有效</strong> 需要满足：假设开始有一个空字符串 <code>t = ""</code> ，你可以执行 <strong>任意次</strong> 下述操作将<strong> </strong><code>t</code><strong> 转换为 </strong><code>s</code> ：</p>

<ul>
	<li>将字符串 <code>"abc"</code> 插入到 <code>t</code> 中的任意位置。形式上，<code>t</code> 变为 <code>t<sub>left</sub> + "abc" + t<sub>right</sub></code>，其中 <code>t == t<sub>left</sub> + t<sub>right</sub></code> 。注意，<code>t<sub>left</sub></code> 和 <code>t<sub>right</sub></code> 可能为 <strong>空</strong> 。</li>
</ul>

<p>如果字符串 <code>s</code> 有效，则返回 <code>true</code>；否则，返回 <code>false</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "aabcbc"
<strong>输出：</strong>true
<strong>解释：</strong>
"" -&gt; "<strong>abc</strong>" -&gt; "a<strong>abc</strong>bc"
因此，"aabcbc" 有效。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abcabcababcc"
<strong>输出：</strong>true
<strong>解释：</strong>
"" -&gt; "<strong>abc</strong>" -&gt; "abc<strong>abc</strong>" -&gt; "abcabc<strong>abc</strong>" -&gt; "abcabcab<strong>abc</strong>c"
因此，"abcabcababcc" 有效。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "abccba"
<strong>输出：</strong>false
<strong>解释：</strong>执行操作无法得到 "abccba" 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>s</code> 由字母 <code>'a'</code>、<code>'b'</code> 和 <code>'c'</code> 组成</li>
</ul>


    
## 方法一：栈

开辟一个字符栈，遍历字符串：

+ 如果当前字符是```a```就入栈
+ 如果当前字符是```b```就看栈顶是否是```a```，是```a```就将```a```换成```b```，不是```a```就返回```false```
+ 如果当前字符是```c```就看栈顶是否是```b```，是```b```就让```b```出栈，不是```b```就返回```false```

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(len(s))$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool isValid(string& s) {
        stack<char> st;
        for (char c : s) {
            if (c == 'a') {
                st.push('a');
            }
            else if (c == 'b') {
                if (st.empty() || st.top() != 'a') {
                    return false;
                }
                else {
                    st.pop();
                    st.push('b');
                }
            }
            else {
                if (st.empty() || st.top() != 'b') {
                    return false;
                }
                else {
                    st.pop();
                }
            }
        }
        return st.empty();
    }
};
```

#### Python

```python
class Solution:
    def isValid(self, s: str) -> bool:
        st = []
        for c in s:
            if c == 'a':
                st.append('a')
            elif c == 'b':
                if not len(st) or st[-1] != 'a':
                    return False
                else:
                    st[-1] = 'b'
            else:
                if not len(st) or st[-1] != 'b':
                    return False
                else:
                    st.pop()
        return not len(st)
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2023/05/03/LeetCode%201003.%E6%A3%80%E6%9F%A5%E6%9B%BF%E6%8D%A2%E5%90%8E%E7%9A%84%E8%AF%8D%E6%98%AF%E5%90%A6%E6%9C%89%E6%95%88/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130470201](https://letmefly.blog.csdn.net/article/details/130470201)
