---
title: 3095.或值至少 K 的最短子数组 I：因为是I所以先暴力枚举（枚举+小优化）
date: 2025-01-16 12:32:35
tags: [题解, LeetCode, 简单, 位运算, 数组, 枚举]
categories: [题解, LeetCode]
---

# 【LetMeFly】3095.或值至少 K 的最短子数组 I：因为是I所以先暴力枚举（枚举+小优化）

力扣题目链接：[https://leetcode.cn/problems/shortest-subarray-with-or-at-least-k-i/](https://leetcode.cn/problems/shortest-subarray-with-or-at-least-k-i/)

<p>给你一个 <strong>非负</strong>&nbsp;整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;。</p>

<p>如果一个数组中所有元素的按位或运算 <code>OR</code>&nbsp;的值 <strong>至少</strong>&nbsp;为 <code>k</code>&nbsp;，那么我们称这个数组是 <strong>特别的</strong>&nbsp;。</p>

<p>请你返回&nbsp;<code>nums</code>&nbsp;中&nbsp;<strong>最短特别非空</strong>&nbsp;<span data-keyword="subarray-nonempty">子数组</span>的长度，如果特别子数组不存在，那么返回 <code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,3], k = 2</span></p>

<p><span class="example-io"><b>输出：</b>1</span></p>

<p><strong>解释：</strong></p>

<p>子数组&nbsp;<code>[3]</code>&nbsp;的按位&nbsp;<code>OR</code> 值为&nbsp;<code>3</code>&nbsp;，所以我们返回 <code>1</code>&nbsp;。</p>

<p>注意，<code>[2]</code> 也是一个特别子数组。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [2,1,8], k = 10</span></p>

<p><span class="example-io"><b>输出：</b>3</span></p>

<p><strong>解释：</strong></p>

<p>子数组&nbsp;<code>[2,1,8]</code> 的按位&nbsp;<code>OR</code>&nbsp;值为 <code>11</code>&nbsp;，所以我们返回 <code>3</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2], k = 0</span></p>

<p><span class="example-io"><b>输出：</b>1</span></p>

<p><b>解释：</b></p>

<p>子数组&nbsp;<code>[1]</code>&nbsp;的按位&nbsp;<code>OR</code>&nbsp;值为&nbsp;<code>1</code>&nbsp;，所以我们返回&nbsp;<code>1</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 50</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 50</code></li>
	<li><code>0 &lt;= k &lt; 64</code></li>
</ul>


    
## 解题方法：枚举（小优化）

**枚举：**

子数组左右端点，计算子数组中元素按位或后的结果，若$\geq k$则更新答案最小值。

**小优化：**

1. 以`l`为起点的子数组中：`[l, r + 1]`子数组的或结果可以由`[l, r]`子数组的或结果或上一个`nums[r + 1]`快速得到。
2. 若`[l, r]`子数组的或结果已经$\geq k$了，则无需再枚举`[l, r + 1]`等以`l`为起点的更长的子数组。

+ 时间复杂度$O(len(nums)^2)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-01-16 12:22:16
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-16 12:25:45
 */

// 开始读题
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = 100;
        for (int l = 0; l < nums.size(); l++) {
            int val = nums[l];
            for (int r = l; r < nums.size(); r++) {
                val |= nums[r];
                if (val >= k) {
                    ans = min(ans, r - l + 1);
                    break;
                }
            }
        }
        return ans == 100 ? -1 : ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-01-16 12:25:24
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-16 12:27:03
'''
from typing import List

class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        ans = 100
        for l in range(len(nums)):
            val = nums[l]
            for r in range(l, len(nums)):
                val |= nums[r]
                if val >= k:
                    ans = min(ans, r - l + 1)
                    break
        return -1 if ans == 100 else ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-01-16 12:27:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-16 12:29:04
 */
class Solution {
    public int minimumSubarrayLength(int[] nums, int k) {
        int ans = 100;
        for (int l = 0; l < nums.length; l++) {
            int val = nums[l];
            for (int r = l; r < nums.length; r++) {
                val |= nums[r];
                if (val >= k) {
                    ans = Math.min(ans, r - l + 1);
                    break;
                }
            }
        }
        return ans == 100 ? -1 : ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-01-16 12:29:34
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-16 12:31:29
 */
package main

func minimumSubarrayLength(nums []int, k int) int {
    ans := 100
    for l, val := range nums {
        for r := l; r < len(nums); r++ {
            val |= nums[r]
            if val >= k {
                ans = min(ans, r - l + 1)
                break
            }
        }
    }
    if ans == 100 {
        return -1
    }
    return ans
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/01/16/LeetCode%203095.%E6%88%96%E5%80%BC%E8%87%B3%E5%B0%91K%E7%9A%84%E6%9C%80%E7%9F%AD%E5%AD%90%E6%95%B0%E7%BB%84I/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/145180094](https://letmefly.blog.csdn.net/article/details/145180094)
