---
title: 1935.可以输入的最大单词数：哈希表
date: 2025-09-15 22:13:53
tags: [题解, LeetCode, 简单, 哈希表, set, 字符串]
categories: [题解, LeetCode]
---

# 【LetMeFly】1935.可以输入的最大单词数：哈希表

力扣题目链接：[https://leetcode.cn/problems/maximum-number-of-words-you-can-type/](https://leetcode.cn/problems/maximum-number-of-words-you-can-type/)

<p>键盘出现了一些故障，有些字母键无法正常工作。而键盘上所有其他键都能够正常工作。</p>

<p>给你一个由若干单词组成的字符串 <code>text</code> ，单词间由单个空格组成（不含前导和尾随空格）；另有一个字符串 <code>brokenLetters</code> ，由所有已损坏的不同字母键组成，返回你可以使用此键盘完全输入的 <code>text</code> 中单词的数目。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>text = "hello world", brokenLetters = "ad"
<strong>输出：</strong>1
<strong>解释：</strong>无法输入 "world" ，因为字母键 'd' 已损坏。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>text = "leet code", brokenLetters = "lt"
<strong>输出：</strong>1
<strong>解释：</strong>无法输入 "leet" ，因为字母键 'l' 和 't' 已损坏。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>text = "leet code", brokenLetters = "e"
<strong>输出：</strong>0
<strong>解释：</strong>无法输入任何单词，因为字母键 'e' 已损坏。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= brokenLetters.length &lt;= 26</code></li>
	<li><code>text</code> 由若干用单个空格分隔的单词组成，且不含任何前导和尾随空格</li>
	<li>每个单词仅由小写英文字母组成</li>
	<li><code>brokenLetters</code> 由 <strong>互不相同</strong> 的小写英文字母组成</li>
</ul>


    
## 解题方法：哈希表

首先把brokenLetters变成一个哈希表用来快速查询一个字符是否已经broken。

接着使用一个变量`can`表示当前单词中是否有不可用字符，默认值为`true`。

遍历字符串`text`，如果遇到空格，就说明遍历完了一个单词，若单词中没有不可用字符则答案累加；之后将`can`重置为`true`。

否则，如果遇到的字符在broken列表中，就将`can`置为`false`。

+ 时间复杂度$O(len(text) + len(brokenLetters))$
+ 空间复杂度$O(len(brokenLetters))$

也可以手动实现哈希表，如使用一个整数的不同位代表不同字符是否在哈希表中。

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-09-15 21:48:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-15 21:50:18
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> cannot(brokenLetters.begin(), brokenLetters.end());
        int ans = 0;
        bool can = true;
        for (char c : text) {
            if (c == ' ') {
                ans += can;
                can = true;
                continue;
            }
            if (cannot.count(c)) {
                can = false;
            }
        }
        return ans + can;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-09-15 21:48:47
LastEditors: LetMeFly.xyz
LastEditTime: 2025-09-15 21:56:54
'''
class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        ans = 0
        cannot = set(brokenLetters)
        for word in text.split():
            ans += all(c not in cannot for c in word)
        return ans
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-09-15 21:58:43
LastEditors: LetMeFly.xyz
LastEditTime: 2025-09-15 21:58:57
'''
class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        cannot = set(brokenLetters)
        return sum(all(c not in cannot for c in word) for word in text.split())
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-09-15 21:48:47
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-15 22:00:30
 */
import java.util.Set;
import java.util.HashSet;

class Solution {
    public int canBeTypedWords(String text, String brokenLetters) {
        Set<Character> cannot = new HashSet<>();
        for (char c : brokenLetters.toCharArray()) {
            cannot.add(c);
        }
        int ans = 0;
        boolean can = true;
        for (char c : text.toCharArray()) {
            if (c == ' ') {
                ans += can ? 1 : 0;
                can = true;
                continue;
            }
            if (cannot.contains(c)) {
                can = false;
            }
        }
        return ans + (can ? 1 : 0);
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-09-15 21:48:47
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-15 22:06:31
 */
package main

func canBeTypedWords(text string, brokenLetters string) (ans int) {
    cannot := map[byte]struct{}{}
    for i := range brokenLetters {
        cannot[brokenLetters[i]] = struct{}{}
    }
    can := true
    for i := range text {
        if text[i] == ' ' {
            if can {
                ans++
            } else {
                can = true
            }
            continue
        }
        if _, in := cannot[text[i]]; in {
            can = false
        }
    }
    if can {
        ans++
    }
    return
}
```

#### Rust

```rust
/*
 * @Author: LetMeFly
 * @Date: 2025-09-15 21:48:47
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-15 22:11:40
 */
use std::collections::HashSet;

impl Solution {
    pub fn can_be_typed_words(text: String, broken_letters: String) -> i32 {
        let cannot: HashSet<char> = broken_letters.chars().collect();
        let mut ans: i32 = 0;
        let mut can: bool = true;
        for c in text.chars() {
            if c == ' ' {
                ans += if can { 1 } else { 0 };
                can = true;
            } else if cannot.contains(&c) {
                can = false;
            }
        }
        ans + if can { 1 } else { 0 }
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/151727471)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/09/15/LeetCode%201935.%E5%8F%AF%E4%BB%A5%E8%BE%93%E5%85%A5%E7%9A%84%E6%9C%80%E5%A4%A7%E5%8D%95%E8%AF%8D%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
