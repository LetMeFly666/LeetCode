---
title: 3202.找出有效子序列的最大长度 II：取模性质(动态规划)
date: 2025-07-20 22:28:56
tags: [题解, LeetCode, 中等, 数组, 动态规划, DP, 取模, 模运算]
categories: [题解, LeetCode]
---

# 【LetMeFly】3202.找出有效子序列的最大长度 II：取模性质(动态规划)

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


    
## 解题方法：动态规划(DP)

一个序列$[a_1,b_1,a_2,b_2,a_3,\dots]$满足$(a_1+b_1)\% k == (b_1+a_2)\%k == (a_2+b2)\%k==\dots$的话，则有：

> $a_1, a_2,\dots$对$k$同余，$b_1,b_2,\dots$对$k$同余。

所谓同余，就是模$k$后的结果相等。

使用一个动态规划数组$dp[i][j]$代表$a_*$模$k$等于$i$而$b_*$模$k$等于$j$的$[a_1,b_1,a_2,b_2\dots]$序列的最大长度，则可以：

> 遍历$nums$数组，若当前元素（对$k$取模后）为$x$，则任何$yxyx$序列的长度都可以在$xyxy$序列的基础上再加一个$x$从而变成$yxyx$序列。
>
> $dp[y][x]=dp[x][y]+1$

注意，$dp[a][b]$代表的$abab$序列，结尾一定是$b$，但开头不一定是$a$（可以是$abab$也可以是$babab$）。

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

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/149491839)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/07/18/LeetCode%203202.%E6%89%BE%E5%87%BA%E6%9C%89%E6%95%88%E5%AD%90%E5%BA%8F%E5%88%97%E7%9A%84%E6%9C%80%E5%A4%A7%E9%95%BF%E5%BA%A6II/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
