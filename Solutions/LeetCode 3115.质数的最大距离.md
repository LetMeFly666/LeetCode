---
title: 3115.质数的最大距离
date: 2024-07-02 10:57:52
tags: [题解, LeetCode, 中等, 数组, 数学, 数论]
---

# 【LetMeFly】3115.质数的最大距离：质数判断

力扣题目链接：[https://leetcode.cn/problems/maximum-prime-difference/](https://leetcode.cn/problems/maximum-prime-difference/)

<p>给你一个整数数组 <code>nums</code>。</p>

<p>返回两个（不一定不同的）质数在 <code>nums</code> 中&nbsp;<strong>下标</strong> 的 <strong>最大距离</strong>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [4,2,9,5,3]</span></p>

<p><strong>输出：</strong> <span class="example-io">3</span></p>

<p><strong>解释：</strong> <code>nums[1]</code>、<code>nums[3]</code> 和 <code>nums[4]</code> 是质数。因此答案是 <code>|4 - 1| = 3</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [4,8,2,8]</span></p>

<p><strong>输出：</strong> <span class="example-io">0</span></p>

<p><strong>解释：</strong> <code>nums[2]</code> 是质数。因为只有一个质数，所以答案是 <code>|2 - 2| = 0</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 3 * 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
	<li>输入保证 <code>nums</code> 中至少有一个质数。</li>
</ul>


    
## 解题方法：质数判断

如何判断一个整数是否为质数？

> 对于一个整数$n$，如果$n\lt 2$，则$n$不是质数。
>
> 使用变量$i$从$2$到$\sqrt{n}$遍历，若对于某个$i$有$n\% i==0$，则$n$不是质数。
>
> 否则，$n$为质数。

接着遍历整数数组，使用两个变量即可确定出第一个质数和最后一个质数。二者相减即为答案。

+ 时间复杂度$O(len(nums)\times\sqrt{\max(nums)})$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
private:
    inline bool isPrime(int n) {
        if (n == 1) {
            return false;
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int m = 10000000, M = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (isPrime(nums[i])) {
                m = min(m, i);
                M = max(M, i);
            }
        }
        return M - m;
    }
};
```

#### Go

```go
package main

func max(a int, b int) int {
    if a > b {
        return a
    }
    return b
}

func min(a int, b int) int {
    if a < b {
        return a
    }
    return b
}

func isPrime(n int) bool {
    if n == 1 {
        return false
    }
    for i := 2; i * i <= n; i++ {
        if n % i == 0 {
            return false
        }
    }
    return true
}

func maximumPrimeDifference(nums []int) int {
    M, m := -1, 10000000
    for i := 0; i < len(nums); i++ {
        if isPrime(nums[i]) {
            M = max(M, i)
            m = min(m, i)
        }
    }
    return M - m
}
```

#### Java

```java
class Solution {
    private boolean isPrime(int n) {
        if (n == 1) {
            return false;
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    public int maximumPrimeDifference(int[] nums) {
        int m = 10000000, M = -1;
        for (int i = 0; i < nums.length; i++) {
            if (isPrime(nums[i])) {
                m = Math.min(m, i);
                M = Math.max(M, i);
            }
        }
        return M - m;
    }
}
```

#### Python

```python
from typing import List
from math import sqrt

class Solution:
    def isPrime(self, n: int) -> bool:
        if n == 1:
            return False
        for i in range(2, int(sqrt(n)) + 1):
            if n % i == 0:
                return False
        return True
    
    def maximumPrimeDifference(self, nums: List[int]) -> int:
        m, M = 10000000, -1
        for i in range(len(nums)):
            if self.isPrime(nums[i]):
                m, M = min(m, i), max(M, i)
        return M - m
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/07/02/LeetCode%203115.%E8%B4%A8%E6%95%B0%E7%9A%84%E6%9C%80%E5%A4%A7%E8%B7%9D%E7%A6%BB/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/140121329](https://letmefly.blog.csdn.net/article/details/140121329)
