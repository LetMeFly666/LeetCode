---
title: 693.交替位二进制数：位运算（O(1)非O(log n)）
date: 2026-02-18 15:02:58
tags: [题解, LeetCode, 简单, 位运算]
categories: [题解, LeetCode]
---

# 【LetMeFly】693.交替位二进制数：位运算（O(1)非O(log n)）

力扣题目链接：[https://leetcode.cn/problems/binary-number-with-alternating-bits/](https://leetcode.cn/problems/binary-number-with-alternating-bits/)

<p>给定一个正整数，检查它的二进制表示是否总是 0、1 交替出现：换句话说，就是二进制表示中相邻两位的数字永不相同。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 5
<strong>输出：</strong>true
<strong>解释：</strong>5 的二进制表示是：101
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 7
<strong>输出：</strong>false
<strong>解释：</strong>7 的二进制表示是：111.</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 11
<strong>输出：</strong>false
<strong>解释：</strong>11 的二进制表示是：1011.</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


    
## 解题方法：位运算

假设原来数字是`101010`，那么右移一位后变成`010101`，异或变成`111111`。

当且仅当原数字$n$是`01`交替时有$n\ \hat{}\ (n>>1)$全是`1`。

假设$x=n\ \hat{}\ (n>>1)$，如何判断$x$中是否全是$1$呢？令`111111`+`1`=`1000000`，`1000000`&`111111`=`0`。

当且仅当$x$二进制下全是`1`时有$x\&(x+1)=0$。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

注意计算过程中不要超过有符号型`int32`。

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-02-18 14:54:30
 */
class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned x = (n >> 1) ^ n;
        return ((x + 1) & x) == 0;
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-02-18 15:02:19
'''
class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        x = (n >> 1) ^ n
        return (x + 1) & x == 0
```

#### Java

```java
/*
 * @LastEditTime: 2026-02-18 15:00:15
 */
class Solution {
    public boolean hasAlternatingBits(int n) {
        int x = (n >> 1) ^ n;
        return (x & (x + 1)) == 0;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2026-02-18 15:01:13
 */
package main

func hasAlternatingBits(n int) bool {
    x := (n >> 1) ^ n
    return (x & (x + 1)) == 0
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-02-18 14:59:11
 */
impl Solution {
    pub fn has_alternating_bits(n: i32) -> bool {
        let x: usize = ((n >> 1) ^ n )as usize;
        (x & (x + 1)) == 0
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/158180666)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/02/18/LeetCode%200693.%E4%BA%A4%E6%9B%BF%E4%BD%8D%E4%BA%8C%E8%BF%9B%E5%88%B6%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
