---
title: 680.验证回文串 II：两侧向中间，不同就试删
date: 2025-02-03 09:06:49
tags: [题解, LeetCode, 简单, 双指针, 字符串, 回文, 回文串]
---

# 【LetMeFly】680.验证回文串 II：两侧向中间，不同就试删

力扣题目链接：[https://leetcode.cn/problems/valid-palindrome-ii/](https://leetcode.cn/problems/valid-palindrome-ii/)

<p>给你一个字符串&nbsp;<code>s</code>，<strong>最多</strong> 可以从中删除一个字符。</p>

<p>请你判断 <code>s</code> 是否能成为回文字符串：如果能，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "aba"
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abca"
<strong>输出：</strong>true
<strong>解释：</strong>你可以删除字符 'c' 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "abc"
<strong>输出：</strong>false</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> 由小写英文字母组成</li>
</ul>


    
## 解题方法：遍历

从两边到中间遍历字符串，如果当前两个字符不相同，就尝试删除其中的一个（并判断删除后中间剩下的字符串是否是回文字符串）。

如果删除一个或零个能成为回文字符串，则返回`true`。

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-02-03 08:52:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-03 08:57:47
 */
class Solution {
private:
    bool isOk(string& s, int l, int r) {
        for (; l < r; l++, r--) {
            if (s[l] != s[r]) {
                return false;
            }
        }
        return true;
    }
public:
    bool validPalindrome(string& s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return isOk(s, i, j - 1) || isOk(s, i + 1, j);
            }
        }
        return true;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-02-03 08:57:31
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-03 08:59:26
'''
class Solution:
    def isOk(self, s: str, l: int, r: int) -> bool:
        while l < r:
            if s[l] != s[r]:
                return False
            l += 1
            r -= 1
        return True
    
    def validPalindrome(self, s: str) -> bool:
        l, r = 0, len(s) - 1
        while l < r:
            if s[l] != s[r]:
                return self.isOk(s, l, r - 1) or self.isOk(s, l + 1, r)
            l += 1
            r -= 1
        return True
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-02-03 08:57:34
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-03 09:01:29
 */
class Solution {
    private boolean isOk(String s, int l, int r) {
        for (; l < r; l++, r--) {
            if (s.charAt(l) != s.charAt(r)) {
                return false;
            }
        }
        return true;
    }

    public boolean validPalindrome(String s) {
        for (int l = 0, r = s.length() - 1; l < r; l++, r--) {
            if (s.charAt(l) != s.charAt(r)) {
                return isOk(s, l, r - 1) || isOk(s, l + 1, r);
            }
        }
        return true;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-02-03 08:57:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-03 09:05:54
 */
package main

func isOk_VP(s string, l, r int) bool {
    for ; l < r; l, r = l + 1, r - 1 {
        if s[l] != s[r] {
            return false
        }
    }
    return true
}

func validPalindrome(s string) bool {
    for l, r := 0, len(s) - 1; l < r; l, r = l + 1, r - 1 {
        if s[l] != s[r] {
            return isOk_VP(s, l, r - 1) || isOk_VP(s, l + 1, r)
        }
    }
    return true
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/02/03/LeetCode%200680.%E9%AA%8C%E8%AF%81%E5%9B%9E%E6%96%87%E4%B8%B2II/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/145427404](https://letmefly.blog.csdn.net/article/details/145427404)

从昨天(2025.2.2)大概晚上五六点开始，又能明显感觉到great wall对github的强力封锁了。。。

6LCi6LCi5aKZ5aKZ5bim5p2l55qE4oCc6auY5pWI5byA5Y+R4oCdCg==