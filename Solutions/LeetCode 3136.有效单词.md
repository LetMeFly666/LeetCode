---
title: 3136.有效单词：遍历模拟
date: 2025-07-15 23:43:04
tags: [题解, LeetCode, 简单, 字符串, 遍历, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】3136.有效单词：遍历模拟

力扣题目链接：[https://leetcode.cn/problems/valid-word/](https://leetcode.cn/problems/valid-word/)

<p><strong>有效单词</strong> 需要满足以下几个条件：</p>

<ul>
	<li><strong>至少 </strong>包含 3 个字符。</li>
	<li>由数字 0-9 和英文大小写字母组成。（不必包含所有这类字符。）</li>
	<li><strong>至少</strong> 包含一个 <strong>元音字母 </strong>。</li>
	<li><strong>至少</strong> 包含一个 <strong>辅音字母 </strong>。</li>
</ul>

<p>给你一个字符串 <code>word</code> 。如果 <code>word</code> 是一个有效单词，则返回 <code>true</code> ，否则返回 <code>false</code> 。</p>

<p><strong>注意：</strong></p>

<ul>
	<li><code>'a'</code>、<code>'e'</code>、<code>'i'</code>、<code>'o'</code>、<code>'u'</code> 及其大写形式都属于<strong> 元音字母 </strong>。</li>
	<li>英文中的 <strong>辅音字母 </strong>是指那些除元音字母之外的字母。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">word = "234Adas"</span></p>

<p><strong>输出：</strong><span class="example-io">true</span></p>

<p><strong>解释：</strong></p>

<p>这个单词满足所有条件。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">word = "b3"</span></p>

<p><strong>输出：</strong><span class="example-io">false</span></p>

<p><strong>解释：</strong></p>

<p>这个单词的长度少于 3 且没有包含元音字母。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">word = "a3$e"</span></p>

<p><strong>输出：</strong><span class="example-io">false</span></p>

<p><strong>解释：</strong></p>

<p>这个单词包含了 <code>'$'</code> 字符且没有包含辅音字母。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 20</code></li>
	<li><code>word</code> 由英文大写和小写字母、数字、<code>'@'</code>、<code>'#'</code> 和 <code>'$'</code> 组成。</li>
</ul>


    
## 解题方法：遍历

如果word长度小于3，则直接返回false。

使用两个布尔类型的变量hasYuan和hasFu统计是否有元音字符和辅音字符。

遍历字符串：

+ 如果当前字符是大写字母，将大写字母转为小写字母（加上32）
+ 如果当前字符是小写字母（转后也算），则判断当前字符是否是元音字符

    + 如果是，则将hasYuan设置为true
    + 否则，将hasFu设置为true

+ 否则（不是字母），如果当前字符不是数字，则直接返回false

最终若hasYuan和hasFu都为true则返回true。

+ 时间复杂度$O(len(word))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-07-15 23:15:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-15 23:22:47
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool isYuan(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    bool isValid(string word) {
        if (word.size() < 3) {
            return false;
        }
        bool hasYuan = false, hasFu = false;
        for (char c : word) {
            if ('A' <= c && c <= 'Z') {
                // python -c "print(ord('a') - ord('A'))"
                c += 32;
            }
            if ('a' <= c && c <= 'z') {
                if (isYuan(c)) {
                    hasYuan = true;
                } else {
                    hasFu = true;
                }
            } else if (c < '0' || c > '9') {
                return false;
            }
        }
        return hasYuan && hasFu;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-07-15 23:15:03
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-15 23:30:52
'''
class Solution:
    def isValid(self, word: str) -> bool:
        if len(word) < 3:
            return False
        ok = [False, False]
        for c in word:
            if c.isalpha():
                ok[c.lower() in 'aeiou'] = True
            elif not c.isdigit():
                return False
        return all(ok)
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-07-15 23:15:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-15 23:35:42
 */
class Solution {
    private boolean isYuan(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    public boolean isValid(String word) {
        if (word.length() < 3) {
            return false;
        }
        boolean hasYuan = false, hasFu = false;
        for (char c : word.toCharArray()) {
            if ('A' <= c && c <= 'Z') {
                c += 32;
            }
            if ('a' <= c && c <= 'z') {
                if (isYuan(c)) {
                    hasYuan = true;
                } else {
                    hasFu = true;
                }
            } else if (c < '0' || c > '9') {
                return false;
            }
        }
        return hasYuan && hasFu;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-07-15 23:15:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-15 23:40:26
 */
package main

func isYuan3136(c byte) bool {
    return c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u'
}

func isValid(word string) bool {
    if len(word) < 3 {
        return false
    }
    hasYuan, hasFu := false, false
    for _, c := range word {
        if 'A' <= c && c <= 'Z' {
            c += 32
        }
        if 'a' <= c && c <= 'z' {
            if isYuan3136(byte(c)) {
                hasYuan = true
            } else {
                hasFu = true
            }
        } else if c < '0' || c > '9' {
            return false
        }
    }
    return hasYuan && hasFu
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/149373884)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/07/15/LeetCode%203136.%E6%9C%89%E6%95%88%E5%8D%95%E8%AF%8D/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
