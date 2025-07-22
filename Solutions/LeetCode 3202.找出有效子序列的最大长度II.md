---
title: 3202.找出有效子序列的最大长度 II：取模性质(动态规划) - O(k)空间
date: 2025-07-20 22:28:56
tags: [题解, LeetCode, 中等, 数组, 动态规划, DP, 取模, 模运算]
categories: [题解, LeetCode]
---

# 【LetMeFly】3202.找出有效子序列的最大长度 II：取模性质(动态规划) - O(k)空间

力扣题目链接：[https://leetcode.cn/problems/find-the-maximum-length-of-valid-subsequence-ii/](https://leetcode.cn/problems/find-the-maximum-length-of-valid-subsequence-ii/)

给你一个整数数组&nbsp;<code>nums</code>&nbsp;和一个 <strong>正</strong>&nbsp;整数&nbsp;<code>k</code>&nbsp;。
<p><code>nums</code>&nbsp;的一个&nbsp;<span data-keyword="subsequence-array">子序列</span> <code>sub</code>&nbsp;的长度为 <code>x</code>&nbsp;，如果其满足以下条件，则称其为 <strong>有效子序列</strong>&nbsp;：</p>

<ul>
	<li><code>(sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k</code></li>
</ul>
返回 <code>nums</code>&nbsp;的 <strong>最长</strong><strong>有效子序列</strong>&nbsp;的长度。

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,3,4,5], k = 2</span></p>

<p><span class="example-io"><b>输出：</b>5</span></p>

<p><b>解释：</b></p>

<p>最长有效子序列是&nbsp;<code>[1, 2, 3, 4, 5]</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,4,2,3,1,4], k = 3</span></p>

<p><span class="example-io"><b>输出：</b>4</span></p>

<p><strong>解释：</strong></p>

<p>最长有效子序列是&nbsp;<code>[1, 4, 1, 4]</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>3</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>7</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>3</sup></code></li>
</ul>

深度思考的题解。

## 解题方法一：动态规划(DP)

一个序列$[a_1,b_1,a_2,b_2,a_3,\dots]$满足$(a_1+b_1)\% k == (b_1+a_2)\%k == (a_2+b2)\%k==\dots$的话，则有：

> $a_1, a_2,\dots$对$k$同余，$b_1,b_2,\dots$对$k$同余。

所谓同余，就是模$k$后的结果相等。

使用一个动态规划数组$dp[i][j]$代表$a_*$模$k$等于$i$而$b_*$模$k$等于$j$的$[a_1,b_1,a_2,b_2\dots]$序列的最大长度，则可以：

> 遍历$nums$数组，若当前元素（对$k$取模后）为$x$，则任何$yxyx$序列的长度都可以在$xyxy$序列的基础上再加一个$x$从而变成$yxyx$序列。
>
> $dp[y][x]=dp[x][y]+1$

注意，$dp[a][b]$代表的$abab$序列，结尾一定是$b$，但开头不一定是$a$（可以是$abab$也可以是$babab$）。

### 时空复杂度分析

+ 时间复杂度$O(k^2 + nk)$
+ 空间复杂度$O(k^2)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-07-18 22:33:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-20 19:32:05
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k, vector<int>(k));
        int ans = 0;
        for (int x : nums) {
            x %= k;
            for (int y = 0; y < k; y++) {
                dp[y][x] = dp[x][y] + 1;
                ans = max(ans, dp[y][x]);
            }
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-07-18 22:33:22
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-20 22:23:43
'''
from typing import List

class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        dp = [[0] * k for _ in range(k)]
        for x in nums:
            x %= k
            for y in range(k):
                dp[y][x] = dp[x][y] + 1
        return max(map(max, dp))
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-07-18 22:33:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-20 22:28:07
 */
package main

func maximumLength(nums []int, k int) (ans int) {
    dp := make([][]int, k)
    for i := range dp {
        dp[i] = make([]int, k)
    }
    for _, x := range nums {
        x %= k
        for y := range dp {
            dp[y][x] = dp[x][y] + 1
            ans = max(ans, dp[y][x])
        }
    }
    return
}
```

## 解题方法二：动态规划(DP) - 枚举取模结果反推配对元素

方法一中我们遍历数组中的每个元素(作为abab序列中的a)，接着从$0$到$k-1$遍历abab序列中的b。

其实不难发现，假设$abab$序列模$k$的结果是$res$，并且$a$已经确定了，那么$b$为多少呢？由于$(a+b)\%k=res$，所以b=(res-a+k)\%k$(之所以要加$k$是为了防止$b$小于$0$)。

方法二中，我们可以先枚举abab序列取模的结果$0$到$k-1$。对于abab序列取模结果为$res$的前提下，我们遍历数组中的每个元素(作为a)，那么$b$的值就能计算出来了。

令$dp[i]$代表模为$res$且以$i$结尾的abab序列的长度，则有：$dp[a]=dp[b]+1$。这样，时间复杂度不变，我们就把空间复杂度由$O(k^2)$降低为$O(k)$了（相当于这$O(k)$的空间重复使用了$k$次）。

### 时空复杂度分析

+ 时间复杂度$O(k(n+k))$
+ 空间复杂度$O(k)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-07-21 22:55:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-21 22:55:40
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans = 0;
        for (int res = 0; res < k; res++) {
            vector<int> dp(k);
            for (int x : nums) {
                x %= k;
                int y = (res - x + k) % k;
                dp[y] = dp[x] + 1;  // 不需要max(dp[y], dp[x] + 1)，因为dp[y]一定拼接自dp[x]，x和y互为一对儿
                ans = max(ans, dp[y]);
            }
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-07-21 22:50:12
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-21 22:57:04
'''
from typing import List

class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        ans = 0
        for res in range(k):
            dp = [0] * k
            for x in nums:
                x %= k
                # (1+2) % 5 = 3 | (4 + (3 - 4 + 5)) % 5 = 3 | 3 - 4 + 5 = 4 | 3 - 4 = -1 | [0, 1, 2, 3, 4][-1] = [0, 1, 2, 3, 4][4]
                dp[res - x] = dp[x] + 1
            ans = max(ans, max(dp))
        return ans
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-07-23 00:10:50
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-23 00:13:19
 */
package main

func maximumLength(nums []int, k int) (ans int) {
    for res := 0; res < k; res++ {
        dp := make([]int, k)
        for _, a := range nums {
            a %= k
            dp[a] = dp[(res - a + k) % k] + 1
            ans = max(ans, dp[a])
        }
    }
    return
}
```

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/149491839)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/07/18/LeetCode%203202.%E6%89%BE%E5%87%BA%E6%9C%89%E6%95%88%E5%AD%90%E5%BA%8F%E5%88%97%E7%9A%84%E6%9C%80%E5%A4%A7%E9%95%BF%E5%BA%A6II/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
