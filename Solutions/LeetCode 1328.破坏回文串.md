---
title: 1328.破坏回文串：贪心
date: 2025-03-05 16:11:50
tags: [题解, LeetCode, 中等, 贪心, 字符串, 回文, 回文串]
---

# 【LetMeFly】1328.破坏回文串：贪心

力扣题目链接：[https://leetcode.cn/problems/break-a-palindrome/](https://leetcode.cn/problems/break-a-palindrome/)

<p>给你一个由小写英文字母组成的回文字符串&nbsp;<code>palindrome</code> ，请你将其中&nbsp;<strong>一个</strong> 字符用任意小写英文字母替换，使得结果字符串的 <strong>字典序最小</strong> ，且&nbsp;<strong>不是</strong>&nbsp;回文串。</p>

<p>请你返回结果字符串。如果无法做到，则返回一个 <strong>空串</strong> 。</p>

<p>如果两个字符串长度相同，那么字符串 <code>a</code> 字典序比字符串 <code>b</code> 小可以这样定义：在 <code>a</code> 和 <code>b</code> 出现不同的第一个位置上，字符串 <code>a</code> 中的字符严格小于 <code>b</code> 中的对应字符。例如，<code>"abcc”</code> 字典序比 <code>"abcd"</code> 小，因为不同的第一个位置是在第四个字符，显然 <code>'c'</code> 比 <code>'d'</code> 小。</p>
&nbsp;

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>palindrome = "abccba"
<strong>输出：</strong>"aaccba"
<strong>解释：</strong>存在多种方法可以使 "abccba" 不是回文，例如 "<em><strong>z</strong></em>bccba", "a<em><strong>a</strong></em>ccba", 和 "ab<em><strong>a</strong></em>cba" 。
在所有方法中，"aaccba" 的字典序最小。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>palindrome = "a"
<strong>输出：</strong>""
<strong>解释：</strong>不存在替换一个字符使 "a" 变成非回文的方法，所以返回空字符串。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= palindrome.length &lt;= 1000</code></li>
	<li><code>palindrome</code>&nbsp;只包含小写英文字母。</li>
</ul>


    
## 解题方法：贪心

如果字符串只有一个字符，那么改成什么都是回文，直接返回空字符串。

如果字符串的长度为奇数，那么修改正中间的字符是没有意义的，修改后仍是回文串。

为了让修改后的字符串前面字符尽可能小，对于一个长度不只为1的字符串：

+ 遍历字符串的前一半（不遍历到字符串正中间元素或后半字符串），一旦出现非`a`字符，就将这个字符修改为`a`并返回
+ 否则（前半字符串(不包含正中间字符)全是`a`）说明后半字符串也全是`a`，将最后一个字符修改为`b`并返回

+ 时间复杂度$O(len(palindrome))$
+ 空间复杂度$O(1)$。C++可变字符串可直接修改原字符串并返回；其他不可变字符串的编程语言返回值不计入算法空间复杂度。

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-05 12:55:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-05 12:56:14
 */
class Solution {
public:
    string breakPalindrome(string palindrome) {
        if (palindrome.size() == 1) {
            return "";
        }
        for (int i = 0; i < palindrome.size() / 2; i++) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome.back() = 'b';
        return palindrome;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-03-05 15:57:15
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-05 15:59:07
'''
class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        if len(palindrome) == 1:
            return ''
        
        s = list(palindrome)
        for i in range(len(palindrome) // 2):
            if palindrome[i] != 'a':
                s[i] = 'a'
                return ''.join(s)
        
        s[-1] = 'b'
        return ''.join(s)

```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-03-05 16:00:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-05 16:02:39
 */
class Solution {
    public String breakPalindrome(String palindrome) {
        if (palindrome.length() == 1) {
            return new String();
        }
        char[] s = palindrome.toCharArray();
        for (int i = 0; i < s.length / 2; i++) {
            if (s[i] != 'a') {
                s[i] = 'a';
                return new String(s);
            }
        }
        s[s.length - 1] = 'b';
        return new String(s);
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-03-05 16:05:35
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-05 16:07:53
 */
package main

func breakPalindrome(palindrome string) string {
    if len(palindrome) == 1 {
        return ""
    }
    for i := 0; i < len(palindrome) / 2; i++ {
        if palindrome[i] != 'a' {
            return palindrome[:i] + "a" + palindrome[i + 1:]
        }
    }
    return palindrome[:len(palindrome) - 1] + "b"
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/146046025)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/03/05/LeetCode%201328.%E7%A0%B4%E5%9D%8F%E5%9B%9E%E6%96%87%E4%B8%B2/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
