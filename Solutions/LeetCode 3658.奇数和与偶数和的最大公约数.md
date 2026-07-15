---
title: 3658.奇数和与偶数和的最大公约数：数论 / 数学O(1)
date: 2026-07-15 16:33:21
tags: [题解, LeetCode, 简单, 数学, 数论]
categories: [题解, LeetCode]
---

# 【LetMeFly】3658.奇数和与偶数和的最大公约数：数论 / 数学O(1)

力扣题目链接：[https://leetcode.cn/problems/gcd-of-odd-and-even-sums/](https://leetcode.cn/problems/gcd-of-odd-and-even-sums/)

<p>给你一个整数 <code>n</code>。请你计算以下两个值的&nbsp;<strong>最大公约数</strong>（GCD）：</p>

<ul>
	<li>
	<p><code>sumOdd</code>：最小的&nbsp;<code>n</code> 个正奇数的总和。</p>
	</li>
	<li>
	<p><code>sumEven</code>：最小的&nbsp;<code>n</code> 个正偶数的总和。</p>
	</li>
</ul>

<p>返回 <code>sumOdd</code> 和 <code>sumEven</code> 的 GCD。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 4</span></p>

<p><strong>输出：</strong> <span class="example-io">4</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>前 4 个奇数的总和 <code>sumOdd = 1 + 3 + 5 + 7 = 16</code></li>
	<li>前 4 个偶数的总和 <code>sumEven = 2 + 4 + 6 + 8 = 20</code></li>
</ul>

<p>因此，<code>GCD(sumOdd, sumEven) = GCD(16, 20) = 4</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 5</span></p>

<p><strong>输出：</strong> <span class="example-io">5</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>前 5 个奇数的总和 <code>sumOdd = 1 + 3 + 5 + 7 + 9 = 25</code></li>
	<li>前 5 个偶数的总和 <code>sumEven = 2 + 4 + 6 + 8 + 10 = 30</code></li>
</ul>

<p>因此，<code>GCD(sumOdd, sumEven) = GCD(25, 30) = 5</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>


    
## 解题方法：数论 / 数学O(1)

首先计算`sumOdd`和`sumEven`：

+ $sumOdd = 1 + 3 + 5 + \dots + 2n-1 = \frac{(1+2n-1)\times n}{2}=n\times n$
+ $sumEven = 2 + 4 + 6 + \dots + 2n = \frac{(2+2n)\times n}2=n\times (n+1)$

### 解题方法一：数论算gcd

两个数的最大公约数 = 小数 和「大数 ÷ 小数的余数」的最大公约数。

算出$n^2$和$n\times (n+1)$的最大公约数(gcd)即可。

+ 时间复杂度$O(\log n)$
+ 空间复杂度$O(\log n)$

#### C++

```cpp
/*
 * @LastEditTime: 2026-07-15 16:29:54
 */
/*
odd:  1 3 5 .. 2n-1 -> 2n * n / 2 = n^2
even: 2 4 6 ... 2n  -> (2n+2)*n/2 = n(n+1)
*/
class Solution {
private:
    int gcd(int a, int b) {
        return !b ? a : gcd(b, a % b);
    }
public:
    int gcdOfOddEvenSums(int n) {
        return gcd(n * n, n * (n + 1));
    }
};
```

### 解题方法二：一眼看出来结果（O(1)）

$n\times n$和$n\times(n+1)$的最大公约数是多少？首先不难看出它们有个公约数$n$，接着就是求$n$和$n+1$的最大公约数：

> $n$和$n+1$的最大公约数一定是$1$，因为它们只相差了$1$。$a$和$b$的差值一定是其最大公约数的倍数。

所以我们直接返回$n$即可。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-07-15 16:31:21
 */
/*
odd:  1 3 5 .. 2n-1 -> 2n * n / 2 = n^2
even: 2 4 6 ... 2n  -> (2n+2)*n/2 = n(n+1)
*/
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return n;
    }
};
```



#### Python

```python
'''
LastEditTime: 2026-07-15 16:32:26
'''
class Solution:
    def gcdOfOddEvenSums(self, n: int) -> int:
        return n
```

#### Java

```java
/*
 * @LastEditTime: 2026-07-15 16:32:05
 */
class Solution {
    public int gcdOfOddEvenSums(int n) {
        return n;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2026-07-15 16:31:45
 */
package main

func gcdOfOddEvenSums(n int) int {
    return n
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-07-15 16:32:48
 */
impl Solution {
    pub fn gcd_of_odd_even_sums(n: i32) -> i32 {
        n
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/162909396)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/07/15/LeetCode%203658.%E5%A5%87%E6%95%B0%E5%92%8C%E4%B8%8E%E5%81%B6%E6%95%B0%E5%92%8C%E7%9A%84%E6%9C%80%E5%A4%A7%E5%85%AC%E7%BA%A6%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
