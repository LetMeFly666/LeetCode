---
title: 1021.删除最外层的括号：一次遍历
date: 2022-05-28 10:38:16
tags: [题解, LeetCode, 简单, 括号匹配, 模拟, 字符串, 栈, 字符串解析]
categories: [题解, LeetCode]
---

# 【LetMeFly】1021.删除最外层的括号：一次遍历

力扣题目链接：[https://leetcode.cn/problems/remove-outermost-parentheses/](https://leetcode.cn/problems/remove-outermost-parentheses/)

<p>有效括号字符串为空 <code>""</code>、<code>"(" + A + ")"</code> 或 <code>A + B</code> ，其中 <code>A</code> 和 <code>B</code> 都是有效的括号字符串，<code>+</code> 代表字符串的连接。</p>

<ul>
	<li>例如，<code>""</code>，<code>"()"</code>，<code>"(())()"</code> 和 <code>"(()(()))"</code> 都是有效的括号字符串。</li>
</ul>

<p>如果有效字符串 <code>s</code> 非空，且不存在将其拆分为 <code>s = A + B</code> 的方法，我们称其为<strong>原语（primitive）</strong>，其中 <code>A</code> 和 <code>B</code> 都是非空有效括号字符串。</p>

<p>给出一个非空有效字符串 <code>s</code>，考虑将其进行原语化分解，使得：<code>s = P_1 + P_2 + ... + P_k</code>，其中 <code>P_i</code> 是有效括号字符串原语。</p>

<p>对 <code>s</code> 进行原语化分解，删除分解中每个原语字符串的最外层括号，返回 <code>s</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "(()())(())"
<strong>输出：</strong>"()()()"
<strong>解释：
</strong>输入字符串为 "(()())(())"，原语化分解得到 "(()())" + "(())"，
删除每个部分中的最外层括号后得到 "()()" + "()" = "()()()"。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "(()())(())(()(()))"
<strong>输出：</strong>"()()()()(())"
<strong>解释：</strong>
输入字符串为 "(()())(())(()(()))"，原语化分解得到 "(()())" + "(())" + "(()(()))"，
删除每个部分中的最外层括号后得到 "()()" + "()" + "()(())" = "()()()()(())"。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "()()"
<strong>输出：</strong>""
<strong>解释：</strong>
输入字符串为 "()()"，原语化分解得到 "()" + "()"，
删除每个部分中的最外层括号后得到 "" + "" = ""。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> 为 <code>'('</code> 或 <code>')'</code></li>
	<li><code>s</code> 是一个有效括号字符串</li>
</ul>

## 题目大意

题目大概意思就是要把原字符串拆分成`(...)(...)(...)`的样子。

例如某个字符串可以拆分成`(a)(b)(c)(d)`，那么就返回`abcd`。

其中，我们把`(a)`、`(b)`、`(c)`、`(d)`记为**原语**。

<small>也就是说要把由原语组成的字符串拆分成每个原语，然后把每个原语去掉两边的括号并按顺序拼接后返回。</small>

## 解题思路

用变量$left$来记录未配对的左括号的数量。

从左到右遍历字符串，遇到左括号$left$就$+1$，遇到右括号就$-1$。

也就是用计数来模拟栈。

## 具体方法：模拟

遇到**左**括号，如果计数**之前**$left$为$0$，那么就说明这是一个`原语`的****开始。原语的最**左**括号是不用作为答案返回的，因此只有当$left$不为$0$的时候才返回当前字符。

遇到**右**括号，如果计数**之后**$left$为$0$，那么就说明这是一个`原语`的**结束**。原语的最**右**括号是不用作为答案返回的，因此只有当$left$不为$0$的时候才返回当前字符。

## 时空复杂度

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

## AC代码

### C++

```cpp
/*
 * @LastEditTime: 2022-05-28 10:36:45
 */
// 原语（primitive）
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int left = 0;  // 当前有几个未配对的左括号
        for (char& c : s) {
            if (c == '(') {
                if (left) {
                    ans += '(';
                }
                left++;
            }
            else {
                left--;
                if (left) {
                    ans += ')';
                }
            }
        }
        return ans;
    }
};
```

### C++ - 写法二

```cpp
/*
 * @LastEditTime: 2026-10-08 08:58:16
 */
#define IFSKIP if (!layer) skip = true

class Solution {
public:
    string removeOuterParentheses(const string& s) {
        string ans;
        for (int i = 0, n = s.size(), layer = 0; i < n; i++) {
            bool skip = false;
            if (s[i] == '(') {
                IFSKIP;
                layer++;
            } else {
                layer--;
                IFSKIP;
            }

            if (!skip) {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
```

### Python

```python
'''
LastEditTime: 2026-10-08 09:26:04
'''
class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        ans = []
        layer = 0
        for c in s:
            if c == '(':
                if layer:
                    ans.append(c)
                layer += 1
            else:
                layer -= 1
                if layer:
                    ans.append(c)
        return ''.join(ans)
                
```

### Java

```java
/*
 * @LastEditTime: 2026-10-08 09:24:07
 */
class Solution {
    public String removeOuterParentheses(String s) {
        StringBuilder ans = new StringBuilder();
        for (int i = 0, n = s.length(), layer = 0; i < n; i++) {
            boolean skip = false;
            if (s.charAt(i) == '(') {
                if (layer++ == 0) {
                    skip = true;
                }
            } else {
                if (--layer == 0) {
                    skip = true;
                }
            }
            if (!skip) {
                ans.append(s.charAt(i));
            }
        }
        return ans.toString();
    }
}
```

### Go

```go
/*
 * @LastEditTime: 2026-10-08 09:15:54
 */
package main

import "strings"

func removeOuterParentheses(s string) string {
    var ans strings.Builder
    layer := 0
    for _, c := range s {
        skip := false
        if c == '(' {
            if layer == 0 {
                skip = true
            }
            layer++
        } else {
            layer--
            if layer == 0 {
                skip = true
            }
        }
        if !skip {
            ans.WriteRune(c)
        }
    }
    return ans.String()
}
```

### Rust

```rust
/*
 * @LastEditTime: 2026-10-08 09:32:53
 */
impl Solution {
    pub fn remove_outer_parentheses(s: String) -> String {
        let mut ans = String::new();
        let mut layer = 0;
        for c in s.bytes() {
            if c == b'(' {
                if layer != 0 {
                    ans.push(c as char);
                }
                layer += 1;
            } else {
                layer -= 1;
                if layer != 0 {
                    ans.push(c as char);
                }
            }
        }
        ans
    }
}
```


## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/125015777)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2022/05/28/LeetCode%201021.%E5%88%A0%E9%99%A4%E6%9C%80%E5%A4%96%E5%B1%82%E7%9A%84%E6%8B%AC%E5%8F%B7/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
