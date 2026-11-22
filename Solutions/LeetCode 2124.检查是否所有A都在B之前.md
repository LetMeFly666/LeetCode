---
title: 2124.检查是否所有 A 都在 B 之前：看字符串中有没有`ba`
date: 2026-11-22 10:05:09
tags: [题解, LeetCode, 简单, 字符串, 遍历]
categories: [题解, LeetCode]
---

# 【LetMeFly】2124.检查是否所有 A 都在 B 之前：看字符串中有没有`ba`

力扣题目链接：[https://leetcode.cn/problems/check-if-all-as-appears-before-all-bs/](https://leetcode.cn/problems/check-if-all-as-appears-before-all-bs/)

<p>给你一个 <strong>仅</strong> 由字符 <code>'a'</code> 和 <code>'b'</code> 组成的字符串&nbsp; <code>s</code> 。如果字符串中 <strong>每个</strong> <em> </em><code>'a'</code> 都出现在 <strong>每个</strong><em> </em><code>'b'</code><em> </em>之前，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "aaabbb"
<strong>输出：</strong>true
<strong>解释：</strong>
'a' 位于下标 0、1 和 2 ；而 'b' 位于下标 3、4 和 5 。
因此，每个 'a' 都出现在每个 'b' 之前，所以返回 true 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "abab"
<strong>输出：</strong>false
<strong>解释：</strong>
存在一个 'a' 位于下标 2 ，而一个 'b' 位于下标 1 。
因此，不能满足每个 'a' 都出现在每个 'b' 之前，所以返回 false 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "bbb"
<strong>输出：</strong>true
<strong>解释：</strong>
不存在 'a' ，因此可以视作每个 'a' 都出现在每个 'b' 之前，所以返回 true 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s[i]</code> 为 <code>'a'</code> 或 <code>'b'</code></li>
</ul>


    
## 解题方法：遍历

如果存在`a`在`b`之后的情况，就说明字符串中存在`ba`。只需要遍历一遍字符串看下有没有`ba`就好了。

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-11-22 09:57:56
 */
class Solution {
public:
    bool checkString(const string& s) {
        for (int i = 1, n = s.size(); i < n; i++) {
            if (s[i - 1] == 'b' && s[i] == 'a') {
                return false;
            }
        }
        return true;
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-11-22 10:01:07
'''
class Solution:
    def checkString(self, s: str) -> bool:
        return 'ba' not in s
```

#### Java

```java
/*
 * @LastEditTime: 2026-11-22 10:00:56
 */
class Solution {
    public boolean checkString(String s) {
        for (int i = 1, n = s.length(); i < n; i++) {
            if (s.charAt(i - 1) == 'b' && s.charAt(i) == 'a') {
                return false;
            }
        }
        return true;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2026-11-22 09:59:59
 */
package main

func checkString(s string) bool {
    n := len(s)
    for i := 1; i < n; i++ {
        if s[i - 1] == 'b' && s[i] == 'a' {
            return false
        }
    }
    return true
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-11-22 10:04:09
 */
impl Solution {
    pub fn check_string(s: String) -> bool {
        let n = s.len();
        let s = s.as_bytes();
        for i in 1..n {
            if s[i - 1] == b'b' && s[i] == b'a' {
                return false
            }
        }
        true
    }
}
```

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/171181757)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/11/22/LeetCode%202124.%E6%A3%80%E6%9F%A5%E6%98%AF%E5%90%A6%E6%89%80%E6%9C%89A%E9%83%BD%E5%9C%A8B%E4%B9%8B%E5%89%8D/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
