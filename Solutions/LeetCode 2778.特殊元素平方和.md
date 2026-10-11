---
title: 2778.特殊元素平方和：遍历O(n) / 枚举因子O(√n)
date: 2026-10-11 09:38:39
tags: [题解, LeetCode, 简单, 数组, 枚举, 数学]
categories: [题解, LeetCode]
---

# 【LetMeFly】2778.特殊元素平方和：遍历O(n) / 枚举因子O(√n)

力扣题目链接：[https://leetcode.cn/problems/sum-of-squares-of-special-elements/](https://leetcode.cn/problems/sum-of-squares-of-special-elements/)

<p>给你一个下标从 <strong>1</strong> 开始、长度为 <code>n</code> 的整数数组 <code>nums</code> 。</p>

<p>对 <code>nums</code> 中的元素 <code>nums[i]</code> 而言，如果 <code>n</code>&nbsp;能够被 <code>i</code> 整除，即 <code>n % i == 0</code> ，则认为 <code>nums[i]</code> 是一个 <strong>特殊元素</strong> 。</p>

<p>返回 <code>nums</code> 中所有 <strong>特殊元素</strong> 的 <strong>平方和</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4]
<strong>输出：</strong>21
<strong>解释：</strong>nums 中共有 3 个特殊元素：nums[1]，因为 4 被 1 整除；nums[2]，因为 4 被 2 整除；以及 nums[4]，因为 4 被 4 整除。 
因此，nums 中所有特殊元素的平方和等于 nums[1] * nums[1] + nums[2] * nums[2] + nums[4] * nums[4] = 1 * 1 + 2 * 2 + 4 * 4 = 21 。  
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,7,1,19,18,3]
<strong>输出：</strong>63
<strong>解释：</strong>nums 中共有 4 个特殊元素：nums[1]，因为 6 被 1 整除；nums[2] ，因为 6 被 2 整除；nums[3]，因为 6 被 3 整除；以及 nums[6]，因为 6 被 6 整除。 
因此，nums 中所有特殊元素的平方和等于 nums[1] * nums[1] + nums[2] * nums[2] + nums[3] * nums[3] + nums[6] * nums[6] = 2 * 2 + 7 * 7 + 1 * 1 + 3 * 3 = 63 。 </pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length == n &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 50</code></li>
</ul>


    
## 解题方法一：遍历

从$i$到$n$遍历，如果$n$能被$i$整除，则将$nums[i]$的平方加入答案。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-10-11 09:03:46
 */
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans = 0;
        for (int i = 0, n = nums.size(); i < n; i++) {
            if (n % (i + 1) == 0) {
                ans += nums[i] * nums[i];
            }
        }
        return ans;
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-10-11 09:07:21
'''
from typing import List

class Solution:
    def sumOfSquares(self, nums: List[int]) -> int:
        ans = 0
        for i, t in enumerate(nums):
            if not len(nums) % (i + 1):
                ans += t * t
        return ans
```

#### Java

```java
/*
 * @LastEditTime: 2026-10-11 09:06:29
 */
class Solution {
    public int sumOfSquares(int[] nums) {
        int ans = 0;
        for (int i = 0, n = nums.length; i < n; i++) {
            if (n % (i + 1) == 0) {
                ans += nums[i] * nums[i];
            }
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2026-10-11 09:05:38
 */
package main

func sumOfSquares(nums []int) (ans int) {
    for i, t := range nums {
        if len(nums) % (i + 1) == 0 {
            ans += t * t
        }
    }
    return
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-10-11 09:08:39
 */
impl Solution {
    pub fn sum_of_squares(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        let n = nums.len();
        for i in 0..n {
            if n % (i + 1) == 0 {
                ans += nums[i] * nums[i];
            }
        }
        ans
    }
}
```

## 解题方法二：枚举因子

从$1$到$\sqrt{n}$遍历，如果$n$能被$i$整除，则将$nums[i]$的平方加入答案；在此前提下，如果$i^2 \neq n$，则将$nums[n/i]$的平方也加入答案。

+ 时间复杂度$O(\sqrt{n})$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-10-11 09:21:22
 */
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans = 0;
        size_t n = nums.size();
        size_t root = sqrt(n);
        for (int i = 1; i <= root; i++) {
            if (n % i == 0) {
                ans += nums[i - 1] * nums[i - 1] + nums[n / i - 1] * nums[n / i - 1];
            }
        }
        if (root * root == n) {
            ans -= nums[root - 1] * nums[root - 1];
        }
        return ans;
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-10-11 09:32:05
'''
from typing import List
from math import isqrt

class Solution:
    def sumOfSquares(self, nums: List[int]) -> int:
        ans = 0
        for i in range(1, isqrt(len(nums)) + 1):
            if len(nums) % i == 0:
                ans += nums[i - 1] * nums[i - 1]
                if i * i != len(nums):
                    ans += nums[len(nums) // i - 1] * nums[len(nums) // i - 1]
        return ans
```

#### Java

```java
/*
 * @LastEditTime: 2026-10-11 09:27:59
 */
class Solution {
    public int sumOfSquares(int[] nums) {
        int ans = 0;
        for (int i = 1, n = nums.length, root = (int)Math.sqrt(n); i <= root; i++) {
            if (n % i == 0) {
                ans += nums[i - 1] * nums[i - 1];
                if (i * i != n) {
                    ans += nums[n / i - 1] * nums[n / i - 1];
                }
            }
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2026-10-11 09:23:09
 */
package main

func sumOfSquares(nums []int) (ans int) {
    n := len(nums)
    for i := 1; i * i <= n; i++ {
        if n % i == 0 {
            ans += nums[i - 1] * nums[i - 1];
            if i * i != n {
                ans += nums[n / i - 1] * nums[n / i - 1];
            }
        }
    }
    return
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-10-11 09:37:56
 */
impl Solution {
    pub fn sum_of_squares(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        let n = nums.len();
        let root = (n as f64).sqrt() as usize;
        for i in 1..=root {
            if n % i == 0 {
                ans += nums[i - 1] * nums[i - 1];
                if i * i != n {
                    ans += nums[n / i - 1] * nums[n / i - 1];
                }
            }
        }
        ans
    }
}
```

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/167566113)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/10/11/LeetCode%202778.%E7%89%B9%E6%AE%8A%E5%85%83%E7%B4%A0%E5%B9%B3%E6%96%B9%E5%92%8C/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
