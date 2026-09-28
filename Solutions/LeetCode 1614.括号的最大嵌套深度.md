---
title: 1614.括号的最大嵌套深度：一次遍历（只看括号）
date: 2026-09-28 10:10:25
tags: [题解, LeetCode, 简单, 字符串, 字符串解析]
categories: [题解, LeetCode]
---

# 【LetMeFly】1614.括号的最大嵌套深度：一次遍历（只看括号）

力扣题目链接：[https://leetcode.cn/problems/maximum-nesting-depth-of-the-parentheses/](https://leetcode.cn/problems/maximum-nesting-depth-of-the-parentheses/)

<p>给定 <strong>有效括号字符串</strong> <code>s</code>，返回 <code>s</code> 的 <strong>嵌套深度</strong>。嵌套深度是嵌套括号的 <strong>最大</strong> 数量。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong>s = "(1+(2*3)+((<strong>8</strong>)/4))+1"</p>

<p><strong>输出：</strong>3</p>

<p><strong>解释：</strong>数字 8 在嵌套的 3 层括号中。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong>s = "(1)+((2))+(((<strong>3</strong>)))"</p>

<p><strong>输出：</strong>3</p>

<p><strong>解释：</strong>数字 3 在嵌套的 3 层括号中。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "()(())((()()))"</span></p>

<p><strong>输出：</strong><span class="example-io">3</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> 由数字 <code>0-9</code> 和字符 <code>'+'</code>、<code>'-'</code>、<code>'*'</code>、<code>'/'</code>、<code>'('</code>、<code>')'</code> 组成</li>
	<li>题目数据保证括号字符串&nbsp;<code>s</code> 是 <strong>有效的括号字符串</strong></li>
</ul>


    
## 解题方法：遍历

> 数字加减运算符什么的，我才不关注呢！

使用一个变量`layer`记录当前括号的层数，遇到`(`则层数加一，遇到`)`则层数减一。其中最大的层数即为答案。

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-09-28 08:11:07
 */
class Solution {
public:
    int maxDepth(const string& s) {
        int ans = 0;
        for (int i = 0, n = s.size(), layer = 0; i < n; i++) {
            if (s[i] == '(') {
                layer++;
                ans = max(ans, layer);
            } else if (s[i] == ')') {
                layer--;
            }
        }
        return ans;
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-09-28 08:19:18
'''
class Solution:
    def maxDepth(self, s: str) -> int:
        layer = ans = 0
        for i, c in enumerate(s):
            if c == '(':
                layer += 1
                ans = max(ans, layer)
            elif c == ')':
                layer -= 1
        return ans
```

#### Java

```java
/*
 * @LastEditTime: 2026-09-28 08:20:54
 */
class Solution {
    public int maxDepth(String s) {
        int ans = 0;
        for (int i = 0, n = s.length(), layer = 0; i < n; i++) {
            if (s.charAt(i) == '(') {
                ans = Math.max(ans, ++layer);
            } else if (s.charAt(i) == ')') {
                layer--;
            }
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2026-09-28 10:00:29
 */
package main

func maxDepth(s string) (ans int) {
    layer := 0
    for _, c := range s {
        if c == '(' {
            layer++
            ans = max(ans, layer)
        } else if c == ')' {
            layer--
        }
    }
    return
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-09-28 10:09:31
 */
impl Solution {
    pub fn max_depth(s: String) -> i32 {
        let mut ans = 0;
        let mut layer = 0;
        for c in s.chars() {
            if c == '(' {
                layer += 1;
                ans = ans.max(layer);
            } else if c == ')' {
                layer -= 1;
            }
        }
        ans
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/166778903)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/09/28/LeetCode%201614.%E6%8B%AC%E5%8F%B7%E7%9A%84%E6%9C%80%E5%A4%A7%E5%B5%8C%E5%A5%97%E6%B7%B1%E5%BA%A6/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
