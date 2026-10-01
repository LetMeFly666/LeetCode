---
title: 20.有效的括号：栈匹配
date: 2026-10-01 09:23:29
tags: [题解, LeetCode, 简单, 栈, 字符串, 括号匹配, 字符串匹配]
categories: [题解, LeetCode]
---

# 【LetMeFly】20.有效的括号：栈匹配

力扣题目链接：[https://leetcode.cn/problems/valid-parentheses/](https://leetcode.cn/problems/valid-parentheses/)

<p>给定一个只包括 <code>'('</code>，<code>')'</code>，<code>'{'</code>，<code>'}'</code>，<code>'['</code>，<code>']'</code>&nbsp;的字符串 <code>s</code> ，判断字符串是否有效。</p>

<p>有效字符串需满足：</p>

<ol>
	<li>左括号必须用相同类型的右括号闭合。</li>
	<li>左括号必须以正确的顺序闭合。</li>
	<li>每个右括号都有一个对应的相同类型的左括号。</li>
</ol>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "()"</span></p>

<p><span class="example-io"><b>输出：</b>true</span></p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "()[]{}"</span></p>

<p><span class="example-io"><b>输出：</b>true</span></p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "(]"</span></p>

<p><span class="example-io"><b>输出：</b>false</span></p>
</div>

<p><strong class="example">示例 4：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "([])"</span></p>

<p><span class="example-io"><b>输出：</b>true</span></p>
</div>

<p><strong class="example">示例 5：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "([)]"</span></p>

<p><span class="example-io"><b>输出：</b>false</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> 仅由括号 <code>'()[]{}'</code> 组成</li>
</ul>


    
## 解题方法：栈

遍历字符串，遇到左括号则入栈，遇到右括号则看栈顶元素与之是否匹配（匹配则出栈不匹配直接返回`False`），若遍历完栈为空才返回`True`。

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(len(s))$

也可以给栈中插入一个非括号哨兵字符来避免判断栈中是否有元素。

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-10-01 09:22:00
 */
class Solution {
public:
    bool isValid(const string& s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else if (st.empty()) {
                return false;
            } else {
                char a = st.top();
                st.pop();
                if (!(a == '(' && c == ')' || a == '[' && c == ']' || a == '{' && c == '}')) {
                    return false;
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
        st = ['']
        pair = {
            '{': '}',
            '(': ')',
            '[': ']'
        }
        for c in s:
            if c in pair: st.append(c)
            elif pair.get(st.pop(), '') != c: return False
        return len(st) == 1
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/166937873)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/10/01/LeetCode%200020.%E6%9C%89%E6%95%88%E7%9A%84%E6%8B%AC%E5%8F%B7/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
