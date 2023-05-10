---
title: 2299.强密码检验器 II
date: 2023-01-19 22:42:37
tags: [题解, LeetCode, 简单, 字符串, 模拟]
---

# 【LetMeFly】2299.强密码检验器 II

力扣题目链接：[https://leetcode.cn/problems/strong-password-checker-ii/](https://leetcode.cn/problems/strong-password-checker-ii/)

<p>如果一个密码满足以下所有条件，我们称它是一个 <strong>强</strong>&nbsp;密码：</p>

<ul>
	<li>它有至少 <code>8</code>&nbsp;个字符。</li>
	<li>至少包含 <strong>一个小写英文</strong>&nbsp;字母。</li>
	<li>至少包含 <strong>一个大写英文</strong>&nbsp;字母。</li>
	<li>至少包含 <strong>一个数字</strong>&nbsp;。</li>
	<li>至少包含 <strong>一个特殊字符</strong>&nbsp;。特殊字符为：<code>"!@#$%^&amp;*()-+"</code>&nbsp;中的一个。</li>
	<li>它 <strong>不</strong>&nbsp;包含&nbsp;<code>2</code>&nbsp;个连续相同的字符（比方说&nbsp;<code>"aab"</code>&nbsp;不符合该条件，但是&nbsp;<code>"aba"</code>&nbsp;符合该条件）。</li>
</ul>

<p>给你一个字符串&nbsp;<code>password</code>&nbsp;，如果它是一个&nbsp;<strong>强</strong>&nbsp;密码，返回&nbsp;<code>true</code>，否则返回&nbsp;<code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>password = "IloveLe3tcode!"
<b>输出：</b>true
<b>解释：</b>密码满足所有的要求，所以我们返回 true 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>password = "Me+You--IsMyDream"
<b>输出：</b>false
<b>解释：</b>密码不包含数字，且包含 2 个连续相同的字符。所以我们返回 false 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>password = "1aB!"
<b>输出：</b>false
<b>解释：</b>密码不符合长度要求。所以我们返回 false 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= password.length &lt;= 100</code></li>
	<li><code>password</code>&nbsp;包含字母，数字和&nbsp;<code>"!@#$%^&amp;*()-+"</code>&nbsp;这些特殊字符。</li>
</ul>


    
## 方法一：模拟

对于“是否有两个连续的相同字符”，我们可以开辟一个变量来记录上一个字符是什么，如果这个字符和上一个字符相同则直接返回false

对于“是否含有大写字母”、“是否含有小写字母”、“是否含有数字”，则很容易判断

如果既不是大小写字母，又不是数字，**则就是**特殊字符（因为题目中说了只包含这些字符，所以在不满足前三种的情况下就不用再特判是否为特殊字符了）

+ 时间复杂度$O(len(password))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool strongPasswordCheckerII(string& password) {
        if (password.size() < 8)
            return false;
        char lastChar = 0;
        bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;
        for (char c : password) {
            if (c == lastChar)
                return false;
            lastChar = c;
            if (c >= '0' && c <= '9')
                hasDigit = true;
            else if (c >= 'a' && c <= 'z')
                hasLower = true;
            else if (c >= 'A' && c <= 'Z')
                hasUpper = true;
            else
                hasSpecial = true;
        }
        return hasLower && hasUpper && hasDigit && hasSpecial;
    }
};
```

#### Python

```python
# 参考了官方题解的简洁的判断大小写数字的方法，其他全部是自己的思路，竟然和官方题解的命名都一样。
# 不同的是特殊字符的判断方法，题目中说过了只包含字母数字和特殊字符，因此不少字母数字就是特殊字符
# 不同的还有是否两个连续字符相同的判断方法，我个人觉得我的更简洁一些
class Solution:
    def strongPasswordCheckerII(self, password: str) -> bool:
        if len(password) < 8:
            return False
        lastChar = ''
        hasLower, hasUpper, hasDigit, hasSpecial = False, False, False, False
        for c in password:
            if c == lastChar:
                return False
            lastChar = c
            if c.islower():
                hasLower = True
            elif c.isupper():
                hasUpper = True
            elif c.isdigit():
                hasDigit = True
            else:
                hasSpecial = True
        return hasLower and hasUpper and hasDigit and hasSpecial
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/01/19/LeetCode%202299.%E5%BC%BA%E5%AF%86%E7%A0%81%E6%A3%80%E9%AA%8C%E5%99%A8II/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128738747](https://letmefly.blog.csdn.net/article/details/128738747)
