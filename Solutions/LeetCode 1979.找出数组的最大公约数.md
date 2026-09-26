---
title: 1979.找出数组的最大公约数：模拟（附手动gcd）
date: 2026-07-18 07:16:16
tags: [题解, LeetCode, 简单, 数组, 数学, 数论]
categories: [题解, LeetCode]
---

# 【LetMeFly】1979.找出数组的最大公约数：模拟（附手动gcd）

力扣题目链接：[https://leetcode.cn/problems/find-greatest-common-divisor-of-array/](https://leetcode.cn/problems/find-greatest-common-divisor-of-array/)

<p>给你一个整数数组 <code>nums</code> ，返回数组中最大数和最小数的 <strong>最大公约数</strong> 。</p>

<p>两个数的&nbsp;<strong>最大公约数</strong> 是能够被两个数整除的最大正整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [2,5,6,9,10]
<strong>输出：</strong>2
<strong>解释：</strong>
nums 中最小的数是 2
nums 中最大的数是 10
2 和 10 的最大公约数是 2
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [7,5,6,8,3]
<strong>输出：</strong>1
<strong>解释：</strong>
nums 中最小的数是 3
nums 中最大的数是 8
3 和 8 的最大公约数是 1
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [3,3]
<strong>输出：</strong>3
<strong>解释：</strong>
nums 中最小的数是 3
nums 中最大的数是 3
3 和 3 的最大公约数是 3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
</ul>


    
## 解题方法：遍历 + 库函数/手动gcd

遍历一遍原始数组求出最小值和最大值，使用库函数或手写函数计算最大值和最小值的最大公约数。

怎么手动计算两个数的最大公约数（gcd）？使用欧几里得算法（辗转相除法）可以在$\log nums[i]$的时间复杂度内求出。

所谓辗转相除法，即`两个数的最大公约数，等于较小的数和两数相除余数的最大公约数`，即$gcd(a,b)=gcd(b,a\mod b)$。

递归写法比较清晰易懂但是会有一个$\log$级别的递归栈：

```cpp
int gcd(int a, int b) {  // 要保证a>=b
    return b ? gcd(b, a % b) : a;
}
```

而遍历写法不那么清晰但空间复杂度为$O(1)$：

```cpp
int gcd(int a, int b) {
    if (a > b) {
        swap(a, b);
    }
    while (b) {
        // (a, b) = (b, a % b);
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}
```

+ 时间复杂度$O(len(nums)\times\log nums[i])$
+ 空间复杂度$O(\log nums[i])$或$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-07-18 07:01:47
 */
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int m = nums[0], M = m;
        for (int t : nums) {
            m = min(m, t);
            M = max(M, t);
        }
        return gcd(m, M);
    }
};
```

#### C++ —— 迭代gcd

```cpp
/*
 * @LastEditTime: 2026-07-18 07:23:34
 */
class Solution {
private:
    int gcd1979(int a, int b) {
        if (a > b) {
            swap(a, b);
        }
        while (b) {
            // (a, b) = (b, a % b);
            int tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }
public:
    int findGCD(vector<int>& nums) {
        int m = nums[0], M = m;
        for (int t : nums) {
            m = min(m, t);
            M = max(M, t);
        }
        return gcd1979(m, M);
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-07-18 07:04:07
'''
from typing import List
from math import gcd

class Solution:
    def findGCD(self, nums: List[int]) -> int:
        return gcd(min(nums), max(nums))
```

#### Java

```java
/*
 * @LastEditTime: 2026-07-18 07:06:24
 */
class Solution {
    public int findGCD(int[] nums) {
        int m = nums[0], M = m;
        for (int t : nums) {
            m = Math.min(m, t);
            M = Math.max(M, t);
        }
        return gcd(M, m);
    }

    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2026-07-18 07:10:26
 */
package main

func gcd1979(a, b int) int {
    if b == 0 {
        return a
    }
    return gcd1979(b, a % b)
}

func findGCD(nums []int) int {
    m := nums[0]
    M := m
    for _, t := range nums {
        m = min(m, t)
        M = max(M, t)
    }
    return gcd1979(M, m)
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-07-18 07:15:10
 */
impl Solution {
    pub fn find_gcd(nums: Vec<i32>) -> i32 {
        let mut m: i32 = nums[0];
        let mut M: i32 = m;
        for &t in nums.iter() {  // 记得&t解引用
            m = m.min(t);
            M = M.max(t);
        }
        Self::gcd(M, m)
    }

    fn gcd(a: i32, b: i32) -> i32 {
        if b == 0 {
            a
        } else {
            Self::gcd(b, a % b)
        }
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/162985944)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/07/18/LeetCode%201979.%E6%89%BE%E5%87%BA%E6%95%B0%E7%BB%84%E7%9A%84%E6%9C%80%E5%A4%A7%E5%85%AC%E7%BA%A6%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
