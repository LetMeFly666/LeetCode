---
title: 342.4的幂
date: 2022-09-29 12:47:26
tags: [题解, LeetCode, 简单, 位运算, 递归, 数学]
categories: [题解, LeetCode]
---

# 【LetMeFly】342.4的幂

力扣题目链接：[https://leetcode.cn/problems/power-of-four/](https://leetcode.cn/problems/power-of-four/)

<p>给定一个整数，写一个函数来判断它是否是 4 的幂次方。如果是，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>整数 <code>n</code> 是 4 的幂次方需满足：存在整数 <code>x</code> 使得 <code>n == 4<sup>x</sup></code></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 16
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 5
<strong>输出：</strong>false
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-2<sup>31</sup> &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你能不使用循环或者递归来完成本题吗？</p>


    
## 方法一：“消4得1法”

所谓“消4得1法”，就是要在原数不为1的时候，每次判断这个数是否为4的倍数，如果是就让这个数÷4，否则就返回false，直到这个数变成1为止，就返回true

注意，$1=4^0$，而$4$的任何次幂都不会为负数。

+ 时间复杂度$O(log_4n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) {
            return false;
        }
        while (n != 1) {
            if (n % 4) {
                return false;
            }
            n /= 4;
        }
        return true;
    }
};
```

## 方法二：判断是否 是2的幂且是平方数

如何判断一个数是否是2的幂？这里有5种方法判断：[【LetMeFly】231.2 的幂：五种小方法判断](http://blog.letmefly.xyz/2022/09/08/LeetCode%200231.2%E7%9A%84%E5%B9%82/)

如果一个数是2的幂，那么它是4的幂吗？只需要看这个数是否是平方数即可（$\lfloor\sqrt{n}\rfloor^2==n$）。

这是因为$4^t=(2^{\frac{t}{2}})^2$。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) {
            return false;
        }
        int k = sqrt(n);
        return k * k == n && (n & (n - 1)) == 0;
    }
};
```

## 方法三：判断是否 是2的幂且模3得1

如果一个数是2的幂，那么它是4的幂等价于它模3得1。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && n % 3 == 1;
    }
};
```

#### Python

```python
class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        return n > 0 and n & (n - 1) == 0 and n % 3 == 1
```

#### Java

```java
class Solution {
    public boolean isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && n % 3 == 1;
    }
}
```

#### Go

```go
package main

func isPowerOfFour(n int) bool {
    return n > 0 && n & (n - 1) == 0 && n % 3 == 1
}
```

#### Rust

```rust
impl Solution {
    pub fn is_power_of_four(n: i32) -> bool {
        n > 0 && n & (n - 1) == 0 && n % 3 == 1
    }
}
```

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/127104821)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2022/09/29/LeetCode%200342.4%E7%9A%84%E5%B9%82/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)