---
title: 541.反转字符串 II：模拟
date: 2025-01-31 12:41:05
tags: [题解, LeetCode, 简单, 双指针, 字符串, 字符串翻转]
---

# 【LetMeFly】541.反转字符串 II：模拟

力扣题目链接：[https://leetcode.cn/problems/reverse-string-ii/](https://leetcode.cn/problems/reverse-string-ii/)

<p>给定一个字符串 <code>s</code> 和一个整数 <code>k</code>，从字符串开头算起，每计数至 <code>2k</code> 个字符，就反转这 <code>2k</code> 字符中的前 <code>k</code> 个字符。</p>

<ul>
	<li>如果剩余字符少于 <code>k</code> 个，则将剩余字符全部反转。</li>
	<li>如果剩余字符小于 <code>2k</code> 但大于或等于 <code>k</code> 个，则反转前 <code>k</code> 个字符，其余字符保持原样。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "abcdefg", k = 2
<strong>输出：</strong>"bacdfeg"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abcd", k = 2
<strong>输出：</strong>"bacd"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> 仅由小写英文组成</li>
	<li><code>1 &lt;= k &lt;= 10<sup>4</sup></code></li>
</ul>


    
## 解题方法：模拟

使用`l`从`0`到`len(s) - 1`遍历要翻转字符串的左端点，那么要翻转字符串的右端点就是`min(l + r, len(s)) - 1`。每次`l += 2*k`。

对于字符串`s[l, r]`，如何翻转？若不能调用编程语言内置函数，可在`l ＜ r`时交换`s[l]`和`s[r]`并右移`l`和左移`r`各一次。

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-01-31 11:58:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-31 12:02:00
 */
class Solution {
private:
    inline void reverse_(string& s, int l, int r) {
        reverse(s.begin() + l, s.begin() + r);
    }
public:
    string reverseStr(string& s, int k) {
        for (int l = 0; l < s.size(); l += k * 2) {
            reverse_(s, l, min(l + k, (int)s.size()));
        }
        return s;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-01-31 12:02:40
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-31 12:08:02
'''
class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        s = list(s)
        for l in range(0, len(s), k * 2):
            s[l:l + k] = s[l:l + k][::-1]
        return ''.join(s)
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-01-31 12:11:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-31 12:16:13
 */
class Solution {
    private void reverse(char[] s, int l, int r) {  // [l, r]
        while (l < r) {
            char temp = s[l];
            s[l++] = s[r];
            s[r--] = temp;
        }
    }

    public String reverseStr(String s1, int k) {
        char[] s = s1.toCharArray();
        for (int l = 0; l < s.length; l += k * 2) {
            reverse(s, l, Math.min(l + k, s.length) - 1);
        }
        // return s.toString();  // 不可！
        return new String(s);
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-01-31 12:17:35
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-31 12:18:54
 */
package main

import "slices"

func reverseStr(s1 string, k int) string {
    s := []byte(s1)
    for i := 0; i < len(s); i += k * 2 {
        slices.Reverse(s[i:min(i + k, len(s))])
    }
    return string(s)
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/01/31/LeetCode%200541.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2II/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/145404901](https://letmefly.blog.csdn.net/article/details/145404901)
