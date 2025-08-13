---
title: 326.3 的幂：大幂整除
date: 2025-08-13 13:26:49
tags: [题解, LeetCode, 简单, 递归, 数学]
categories: [题解, LeetCode]
---

# 【LetMeFly】326.3 的幂：大幂整除

力扣题目链接：[https://leetcode.cn/problems/power-of-three/](https://leetcode.cn/problems/power-of-three/)

<p>给定一个整数，写一个函数来判断它是否是 3&nbsp;的幂次方。如果是，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>整数 <code>n</code> 是 3 的幂次方需满足：存在整数 <code>x</code> 使得 <code>n == 3<sup>x</sup></code></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 27
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 0
<strong>输出：</strong>false
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 9
<strong>输出：</strong>true
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>n = 45
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-2<sup>31</sup> &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你能不使用循环或者递归来完成本题吗？</p>


    
## 解题方法：看n能否被“最大的”3的幂整除

题目有一行进阶小字说“你能不使用循环或者递归来完成本题吗？”，好一个挑衅(provocation，bushi)，那就不递归或者循环了吧。

类似[【LetMeFly】231.2 的幂：五种小方法判断](https://blog.letmefly.xyz/2022/09/08/LeetCode%200231.2%E7%9A%84%E5%B9%82/)的方法五，我们直接使用题目数据范围内最大的3的幂对n取模，看余数是否为0就好了。

如何求题目数据范围内最大的3的幂？打开python有：

```python
>>> 3**20 > 2**31-1
True
>>> 3**19 > 2**31-1
False
>>> 3**19
1162261467
```

可知如果不大于$2^{31}-1$的正整数$n$是$3$的幂那么它一定能够被$1162261467$整除。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-08-13 13:17:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-13 13:25:31
 */
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && !(1162261467 % n);
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-08-13 13:17:09
LastEditors: LetMeFly.xyz
LastEditTime: 2025-08-13 13:24:54
'''
class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        return n > 0 and not 1162261467 % n
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-08-13 13:17:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-13 13:23:25
 */
class Solution {
    public boolean isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-08-13 13:17:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-13 13:23:55
 */
package main

func isPowerOfThree(n int) bool {
    return n > 0 && 1162261467 % n == 0
}
```

#### Rust

```rust
/*
 * @Author: LetMeFly
 * @Date: 2025-08-13 13:17:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-13 13:21:37
 */
impl Solution {
    pub fn is_power_of_three(n: i32) -> bool {
        n > 0 && 1162261467 % n == 0
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/150343626)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/08/13/LeetCode%200326.3%E7%9A%84%E5%B9%82/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
