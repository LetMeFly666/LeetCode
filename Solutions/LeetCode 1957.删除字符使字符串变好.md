---
title: 1957.删除字符使字符串变好：计数
date: 2025-07-21 18:57:39
tags: [题解, LeetCode, 简单, 字符串, 计数]
categories: [题解, LeetCode]
---

# 【LetMeFly】1957.删除字符使字符串变好：计数

力扣题目链接：[https://leetcode.cn/problems/delete-characters-to-make-fancy-string/](https://leetcode.cn/problems/delete-characters-to-make-fancy-string/)

<p>一个字符串如果没有 <strong>三个连续</strong>&nbsp;相同字符，那么它就是一个 <strong>好字符串</strong>&nbsp;。</p>

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;，请你从 <code>s</code>&nbsp;删除&nbsp;<strong>最少</strong>&nbsp;的字符，使它变成一个 <strong>好字符串</strong> 。</p>

<p>请你返回删除后的字符串。题目数据保证答案总是 <strong>唯一的 </strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>s = "le<strong>e</strong>etcode"
<b>输出：</b>"leetcode"
<strong>解释：</strong>
从第一组 'e' 里面删除一个 'e' ，得到 "leetcode" 。
没有连续三个相同字符，所以返回 "leetcode" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>s = "<strong>a</strong>aab<strong>aa</strong>aa"
<b>输出：</b>"aabaa"
<strong>解释：</strong>
从第一组 'a' 里面删除一个 'a' ，得到 "aabaaaa" 。
从第二组 'a' 里面删除两个 'a' ，得到 "aabaa" 。
没有连续三个相同字符，所以返回 "aabaa" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>s = "aab"
<b>输出：</b>"aab"
<b>解释：</b>没有连续三个相同字符，所以返回 "aab" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
</ul>


    
## 解题方法：计数

统计当前字符连续出现了多少个，如果连续出现小于3个则添加到答案字符串中。

+ 时间复杂度$O(len(s))$
+ 空间复杂度：对于可变字符串的编程语言如C++，$O(1)$；对于不可变字符串的编程语言如Python、Golang，$O(len(s))$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-07-21 18:48:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-21 18:51:15
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        char last = '0';
        int cnt = 0;
        for (char c : s) {
            if (c == last) {
                if (cnt == 2) {
                    continue;
                }
                ans += c;
                cnt++;
            } else {
                last = c;
                cnt = 1;
                ans += c;
            }
        }
        return ans;
    }
};
```

#### C++ (Version 2)

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-07-21 18:48:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-21 18:52:52
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        char last = '0';
        int cnt = 0;
        for (char c : s) {
            if (c != last) {
                last = c;
                cnt = 0;
            }
            cnt++;
            if (cnt < 3) {
                ans += c;
            }
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-07-21 18:48:15
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-21 18:54:53
'''
class Solution:
    def makeFancyString(self, s: str) -> str:
        ans = []
        last = '0'
        cnt = 0
        for c in s:
            if c != last:
                last = c
                cnt = 0
            cnt += 1
            if cnt < 3:
                ans.append(c)
        return ''.join(ans)
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-07-21 18:48:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-21 18:57:03
 */
package main

func makeFancyString(s string) string {
    ans := []byte{}
    last := byte(0)
    cnt := 0
    for _, c := range s {
        if byte(c) != last {
            last = byte(c)
            cnt = 0
        }
        cnt++
        if cnt < 3 {
            ans = append(ans, byte(c))
        }
    }
    return string(ans)
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/149512809)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/07/21/LeetCode%201957.%E5%88%A0%E9%99%A4%E5%AD%97%E7%AC%A6%E4%BD%BF%E5%AD%97%E7%AC%A6%E4%B8%B2%E5%8F%98%E5%A5%BD/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
