---
title: 1523.在区间范围内统计奇数数目：两种方法O(1)算
date: 2026-02-19 18:19:46
tags: [题解, LeetCode, 简单, 数学]
categories: [题解, LeetCode]
---

# 【LetMeFly】1523.在区间范围内统计奇数数目：两种方法O(1)算

力扣题目链接：[https://leetcode.cn/problems/count-odd-numbers-in-an-interval-range/](https://leetcode.cn/problems/count-odd-numbers-in-an-interval-range/)

<p>给你两个非负整数&nbsp;<code>low</code> 和&nbsp;<code>high</code>&nbsp;。请你返回<em>&nbsp;</em><code>low</code><em> </em>和<em>&nbsp;</em><code>high</code><em>&nbsp;</em>之间（包括二者）奇数的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>low = 3, high = 7
<strong>输出：</strong>3
<strong>解释：</strong>3 到 7 之间奇数数字为 [3,5,7] 。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>low = 8, high = 10
<strong>输出：</strong>1
<strong>解释：</strong>8 到 10 之间奇数数字为 [9] 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= low &lt;= high&nbsp;&lt;= 10^9</code></li>
</ul>


    
## 解题方法一：思考容易写着麻烦点

low和high都是偶数的示例 2：low = 8, high = 10，中间共有几个奇数？

答案是$\frac{10-8}2$个。

如果low是奇数，那么我们令low-1；如果high是奇数，那么我们就令high+1就好了。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-02-19 17:39:31
 */
class Solution {
public:
    int countOdds(int low, int high) {
        if (low % 2) {
            low--;
        }
        if (high % 2) {
            high++;
        }
        return (high - low) >> 1;
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-02-19 18:00:11
'''
class Solution:
    def countOdds(self, low: int, high: int) -> int:
        if low % 2:
            low -= 1
        if high % 2:
            high += 1
        return (high - low) // 2
```

#### Go

```go
/*
 * @LastEditTime: 2026-02-19 18:02:40
 */
package main

func countOdds(low int, high int) int {
    if low % 2 == 1 {
        low--
    }
    if high % 2 == 1 {
        high++
    }
    return (high - low) / 2
}
```

## 解题方法二：思考麻烦点写着容易

不论一个数的奇偶性：

* $[1, low)$ 共有几个奇数？答案是$\lfloor\frac{low}2\rfloor$个；
* $[1, high]$ 共有几个奇数？答案是$\lfloor\frac{high+1}2\rfloor$个。

那么 $[low, high]$ 共有几个奇数？ $[1, high] - [1, low)$ 即为所得。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### Java

```java
/*
 * @LastEditTime: 2026-02-19 18:04:04
 */
class Solution {
    public int countOdds(int low, int high) {
        return (high + 1) / 2 - low / 2;
    }
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-02-19 18:06:07
 */
impl Solution {
    pub fn count_odds(low: i32, high: i32) -> i32 {
        (high + 1) / 2 - low / 2
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/158209747)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/02/19/LeetCode%201523.%E5%9C%A8%E5%8C%BA%E9%97%B4%E8%8C%83%E5%9B%B4%E5%86%85%E7%BB%9F%E8%AE%A1%E5%A5%87%E6%95%B0%E6%95%B0%E7%9B%AE/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
