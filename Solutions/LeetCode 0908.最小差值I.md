---
title: 908.最小差值 I
date: 2024-10-21 14:48:02
tags: [题解, LeetCode, 简单, 数组, 数学]
categories: [题解, LeetCode]
---

# 【LetMeFly】908.最小差值 I：思维（遍历）

力扣题目链接：[https://leetcode.cn/problems/smallest-range-i/](https://leetcode.cn/problems/smallest-range-i/)

<p>给你一个整数数组 <code>nums</code>，和一个整数 <code>k</code> 。</p>

<p>在一个操作中，您可以选择 <code>0 &lt;= i &lt; nums.length</code> 的任何索引 <code>i</code> 。将 <code>nums[i]</code> 改为 <code>nums[i] + x</code> ，其中 <code>x</code> 是一个范围为 <code>[-k, k]</code> 的整数。对于每个索引 <code>i</code> ，最多 <strong>只能 </strong>应用 <strong>一次</strong> 此操作。</p>

<p><code>nums</code>&nbsp;的&nbsp;<strong>分数&nbsp;</strong>是&nbsp;<code>nums</code>&nbsp;中最大和最小元素的差值。&nbsp;</p>

<p><em>在对&nbsp; <code>nums</code> 中的每个索引最多应用一次上述操作后，返回&nbsp;<code>nums</code> 的最低 <strong>分数</strong></em> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1], k = 0
<strong>输出：</strong>0
<strong>解释：</strong>分数是 max(nums) - min(nums) = 1 - 1 = 0。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,10], k = 2
<strong>输出：</strong>6
<strong>解释：</strong>将 nums 改为 [2,8]。分数是 max(nums) - min(nums) = 8 - 2 = 6。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,3,6], k = 3
<strong>输出：</strong>0
<strong>解释：</strong>将 nums 改为 [4,4,4]。分数是 max(nums) - min(nums) = 4 - 4 = 0。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>4</sup></code></li>
</ul>


    
## 解题方法：遍历

这道题应该如何思考呢？如何将变化后数组中最大值和最小值之差尽可能地小？当然是“大的数尽可能往小的变”、“小的数尽可能往大的变”。

+ 如果$k$很小，那么最大的数$M$最多减小到$M-k$，最小的数$m$最多增加到$m+k$，最终的最小差值为$M-m-2*k$；
+ 如果$k$足够大$2k\geq M-m$，那么所有的数都可以变成相同的数，最终最小差值为$0$。

因此答案为$\max\{0, \max(nums)-\min(nums)-2k\}$

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int M = *max_element(nums.begin(), nums.end());
        int m = * min_element(nums.begin(), nums.end());
        return max(0, M - m - 2 * k);
    }
};
```

#### Go

```go
package main

import "slices"

func smallestRangeI(nums []int, k int) int {
    return max(0, slices.Max(nums) - slices.Min(nums) - 2 * k)
}
```

#### Java

```java
class Solution {
    public int smallestRangeI(int[] nums, int k) {
        int M = nums[0], m = nums[0];
        for (int t : nums) {
            M = Math.max(M, t);
            m = Math.min(m, t);
        }
        return Math.max(0, M - m  - 2 * k);
    }
}
```

#### Python

```python
from typing import List

class Solution:
    def smallestRangeI(self, nums: List[int], k: int) -> int:
        return max(0, max(nums) - min(nums) - 2 * k)
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/10/21/LeetCode%200908.%E6%9C%80%E5%B0%8F%E5%B7%AE%E5%80%BCI/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/143112464](https://letmefly.blog.csdn.net/article/details/143112464)
