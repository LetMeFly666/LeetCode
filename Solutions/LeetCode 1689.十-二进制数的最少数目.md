---
title: 1689.十-二进制数的最少数目：一次遍历比大小（脑筋急转弯）
date: 2026-03-01 20:28:01
tags: [题解, LeetCode, 中等, 贪心, 字符串, 脑筋急转弯]
categories: [题解, LeetCode]
---

# 【LetMeFly】1689.十-二进制数的最少数目：一次遍历比大小（脑筋急转弯）

力扣题目链接：[https://leetcode.cn/problems/partitioning-into-minimum-number-of-deci-binary-numbers/](https://leetcode.cn/problems/partitioning-into-minimum-number-of-deci-binary-numbers/)

<p>如果一个十进制数字不含任何前导零，且每一位上的数字不是 <code>0</code> 就是 <code>1</code> ，那么该数字就是一个 <strong>十-二进制数</strong> 。例如，<code>101</code> 和 <code>1100</code> 都是 <strong>十-二进制数</strong>，而 <code>112</code> 和 <code>3001</code> 不是。</p>

<p>给你一个表示十进制整数的字符串 <code>n</code> ，返回和为 <code>n</code> 的 <strong>十-二进制数 </strong>的最少数目。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = "32"
<strong>输出：</strong>3
<strong>解释：</strong>10 + 11 + 11 = 32
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = "82734"
<strong>输出：</strong>8
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = "27346209830709182346"
<strong>输出：</strong>9
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n.length &lt;= 10<sup>5</sup></code></li>
	<li><code>n</code> 仅由数字组成</li>
	<li><code>n</code> 不含任何前导零并总是表示正整数</li>
</ul>


    
## 解题方法：遍历

> `123`变成了`000`的时候，$123$就变成了$0$。

每次每个字符可以减`0`或`1`，最多几次可以将字符串减为全`0`？

答案是字符串中最大的那个字符对应的数字次。

+ 时间复杂度$O(len(n))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-03-01 19:51:09
 */
class Solution {
public:
    int minPartitions(string n) {
        char M = '0';
        for (char c : n) {
            M = max(M, c);
        }
        return M - '0';
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-03-01 19:52:13
'''
class Solution:
    def minPartitions(self, n: str) -> int:
        return ord(max(n)) - ord('0')  # 记得python str不能直接相减
```

#### Java

```java
/*
 * @LastEditTime: 2026-03-01 20:20:21
 */
class Solution {
    public int minPartitions(String n) {
        return n.chars().max().getAsInt() - '0';
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2026-03-01 20:10:52
 */
package main

// 要的是max不是min别搞错了
func max1689(a, b rune) rune {
    if a < b {
        return b
    }
    return a
}

func minPartitions(n string) int {
    m := rune('0')
    for _, c := range n {
        m = max1689(m, c)
    }
    return int(byte(m) - '0')
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-03-01 20:23:19
 */
impl Solution {
    pub fn min_partitions(n: String) -> i32 {
        let mut m = '0';
        for c in n.chars() {
            if c > m {
                m = c;
            }
        }
        (m as i32) - ('0' as i32)
    }
}
```

#### Rust - one line

```rust
/*
 * @LastEditTime: 2026-03-01 20:26:52
 */
impl Solution {
    pub fn min_partitions(n: String) -> i32 {
        (*n.as_bytes().iter().max().unwrap() - b'0') as i32
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/158543334)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/03/01/LeetCode%201689.%E5%8D%81-%E4%BA%8C%E8%BF%9B%E5%88%B6%E6%95%B0%E7%9A%84%E6%9C%80%E5%B0%91%E6%95%B0%E7%9B%AE/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
