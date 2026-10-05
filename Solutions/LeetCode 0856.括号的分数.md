---
title: 856.括号的分数：栈模拟 / 一次遍历（O(n)+O(1)）
date: 2022-10-09 09:36:56
tags: [题解, LeetCode, 中等, 栈, 字符串]
categories: [题解, LeetCode]
---

# 【LetMeFly】856.括号的分数：栈模拟 / 一次遍历（O(n)+O(1)）

力扣题目链接：[https://leetcode.cn/problems/score-of-parentheses/](https://leetcode.cn/problems/score-of-parentheses/)

<p>给定一个平衡括号字符串&nbsp;<code>S</code>，按下述规则计算该字符串的分数：</p>

<ul>
	<li><code>()</code> 得 1 分。</li>
	<li><code>AB</code> 得&nbsp;<code>A + B</code>&nbsp;分，其中 A 和 B 是平衡括号字符串。</li>
	<li><code>(A)</code> 得&nbsp;<code>2 * A</code>&nbsp;分，其中 A 是平衡括号字符串。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入： </strong>&quot;()&quot;
<strong>输出： </strong>1
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入： </strong>&quot;(())&quot;
<strong>输出： </strong>2
</pre>

<p><strong>示例&nbsp;3：</strong></p>

<pre><strong>输入： </strong>&quot;()()&quot;
<strong>输出： </strong>2
</pre>

<p><strong>示例&nbsp;4：</strong></p>

<pre><strong>输入： </strong>&quot;(()(()))&quot;
<strong>输出： </strong>6
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>S</code>&nbsp;是平衡括号字符串，且只含有&nbsp;<code>(</code>&nbsp;和&nbsp;<code>)</code>&nbsp;。</li>
	<li><code>2 &lt;= S.length &lt;= 50</code></li>
</ol>


    
## 方法一：特殊栈模拟

### 解题思路

假设我们有一个海纳百川的栈，各种类型的数据都能入栈。

那么我们就可以开始遍历字符串，遇到左括号就入栈，遇到右括号时：如果栈顶是左括号，那么就将左括号出栈，并且入栈“1”；如果栈顶是数值，那么在遇到左括号之前，将栈顶元素逐个出栈并累加，将左括号出栈后，将里面的元素乘二后入栈。

最终，我们将栈中的数值累加即为答案。

### 具体方法

分析上述思路不难发现，一共只有两类要入栈出栈的数据：“数值”和“左括号”

因此，对于C++，我们可以自定义一个结构体：

```cpp
struct SpecialChar {  // 左括号 / 数值
    bool isLeft;  // 左括号？
    int val;  // 若不是左括号，则此val有效
};
```

这样，只需要一个能存放这种结构体的栈，就实现了“数值”和“左括号”的入栈和出栈。

上述思路中，遇到右括号时，先看栈顶是否为左括号，“若为左括号则出栈并入栈```1```”、“若不为左括号则将所有数值出栈并求和，将左括号出栈，数值二倍后入栈”这两种情况也可以合并一下：

遇到右括号时，使用一个遍历```s = 0```来求和，在栈顶元素不为左括号时，不断出栈并将该数值累加到```s```中。若最终```s```值为0，则说明根本没有出栈数值，也就是说栈顶就是左括号，那么入栈“1”。否则就将```s × 2```后入栈。

### 时空复杂度

+ 时间复杂度$O(n)$，其中$n$是字符串长度。
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
struct SpecialChar {  // 左括号 / 数值
    bool isLeft;  // 左括号？
    int val;  // 若不是左括号，则此val有效

    SpecialChar(bool isLeft, int val = 0): isLeft(isLeft), val(val) {};
};

class Solution {
public:
    int scoreOfParentheses(string& s) {
        stack<SpecialChar> st;
        for (char& c : s) {
            if (c == '(') {
                st.push(SpecialChar(true));
            }
            else {  // 必有左括号
                int s = 0;
                while (!st.top().isLeft) {
                    s += st.top().val;
                    st.pop();
                }
                st.pop();  // 对应左括号出栈
                st.push(SpecialChar(false, s ? s * 2 : 1));
            }
        }
        int ans = 0;
        while (st.size()) {
            ans += st.top().val;
            st.pop();
        }
        return ans;
    }
};
```

## 方法二：一次遍历

### 解题思路

我们只关注相邻且闭合的括号。不难发现`()`得1分，`(())`得2分，`((()))`得4分...，似乎得分只与括号深度有关。

而`(()())`中有两个深度为2的括号对，得分为`2 + 2 = 4`分。

所以我们遍历一次字符串，并记录当前括号深度就好了。

### 具体方法

遍历字符串，遇到`(`深度加一，遇到`)`深度减一。如果当前括号是`)`并且前一个括号是`(`，那么就说明我们遇到了一个相邻且闭合的括号对`()`，得分增加$2^layer$。

### 时空复杂度

+ 时间复杂度$O(n)$，其中$n$是字符串长度。
+ 空间复杂度$O(1)$

#### C++

```cpp
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

/*
 * @Author: LetMeFly
 * @Date: 2026-10-05 16:38:39
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-05 16:39:47
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int scoreOfParentheses(const string& s) {
        int ans = 0;
        for (int i = 0, n = s.size(), layer = 0; i < n; i++) {
            if (s[i] == '(') {
                layer++;
            } else {
                layer--;
                if (s[i - 1] == '(') {
                    ans += 1 << layer;
                }
            }
        }
        return ans;
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-10-05 16:45:23
'''
class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        ans = layer = 0
        for i, c in enumerate(s):
            if c == '(':
                layer += 1
            else:
                layer -= 1
                if s[i - 1] == '(':
                    ans += 1 << layer
        return ans
```

#### Java

```java
/*
 * @LastEditTime: 2026-10-05 16:44:16
 */
class Solution {
    public int scoreOfParentheses(String s) {
        int ans = 0;
        for (int i = 0, n = s.length(), layer = 0; i < n; i++) {
            if (s.charAt(i) == '(') {
                layer++;
            } else {
                layer--;
                if (s.charAt(i - 1) == '(') {
                    ans += 1 << layer;
                }
            }
        }
        return ans;
    }
}
```

#### Go

```go
package main

/*
 * @Author: LetMeFly
 * @Date: 2026-10-05 16:38:39
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-05 16:42:41
 */
package main

func scoreOfParentheses(s string) (ans int) {
    layer := 0
    for i, c := range s {
        if c == '(' {
            layer++
        } else {
            layer--
            if s[i - 1] == '(' {
                ans += 1 << layer
            }
        }
    }
    return
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-10-05 16:47:57
 */
impl Solution {
    pub fn score_of_parentheses(s: String) -> i32 {
        let s = s.as_bytes();
        let mut ans = 0;
        let mut layer = 0;
        for i in 0..s.len() {
            if s[i] == b'(' {
                layer += 1;
            } else {
                layer -= 1;
                if s[i - 1] == b'(' {
                    ans += 1 << layer;
                }
            }
        }
        ans
    }
}
```

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/127221656)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2022/10/09/LeetCode%200856.%E6%8B%AC%E5%8F%B7%E7%9A%84%E5%88%86%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)

1 to rm