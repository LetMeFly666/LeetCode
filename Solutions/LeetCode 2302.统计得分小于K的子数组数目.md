---
title: 2302.统计得分小于 K 的子数组数目：滑动窗口（不需要前缀和）
date: 2025-04-30 17:01:00
tags: [题解, LeetCode, 困难, 数组, 二分查找, 前缀和, 滑动窗口]
categories: [题解, LeetCode]
---

# 【LetMeFly】2302.统计得分小于 K 的子数组数目：滑动窗口（不需要前缀和）

力扣题目链接：[https://leetcode.cn/problems/count-subarrays-with-score-less-than-k/](https://leetcode.cn/problems/count-subarrays-with-score-less-than-k/)

<p>一个数组的 <strong>分数</strong>&nbsp;定义为数组之和 <strong>乘以</strong>&nbsp;数组的长度。</p>

<ul>
	<li>比方说，<code>[1, 2, 3, 4, 5]</code>&nbsp;的分数为&nbsp;<code>(1 + 2 + 3 + 4 + 5) * 5 = 75</code>&nbsp;。</li>
</ul>

<p>给你一个正整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;，请你返回&nbsp;<code>nums</code>&nbsp;中分数&nbsp;<strong>严格小于&nbsp;</strong><code>k</code>&nbsp;的&nbsp;<strong>非空整数子数组数目</strong>。</p>

<p><strong>子数组</strong> 是数组中的一个连续元素序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [2,1,4,3,5], k = 10
<b>输出：</b>6
<strong>解释：</strong>
有 6 个子数组的分数小于 10 ：
- [2] 分数为 2 * 1 = 2 。
- [1] 分数为 1 * 1 = 1 。
- [4] 分数为 4 * 1 = 4 。
- [3] 分数为 3 * 1 = 3 。 
- [5] 分数为 5 * 1 = 5 。
- [2,1] 分数为 (2 + 1) * 2 = 6 。
注意，子数组 [1,4] 和 [4,3,5] 不符合要求，因为它们的分数分别为 10 和 36，但我们要求子数组的分数严格小于 10 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,1,1], k = 5
<b>输出：</b>5
<strong>解释：</strong>
除了 [1,1,1] 以外每个子数组分数都小于 5 。
[1,1,1] 分数为 (1 + 1 + 1) * 3 = 9 ，大于 5 。
所以总共有 5 个子数组得分小于 5 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>15</sup></code></li>
</ul>

Hard里面的简单题。

## 解题方法：滑动窗口

本题计算的是字数组和乘以数组长度，由于数组元素为正，所以数组中元素越多计算得到的值越大，**具有单调性**，可以使用滑动窗口。

使用$cnt$记录窗口中元素总和，右指针依次遍历数组中每个元素作为窗口终点（遍历时将指向元素加入窗口）。

对于每个右指针的位置：

> 如果$cnt*len(subArray)\geq k$，则不断右移左指针。
>
> 左指针移动结束后所在位置就是第一个窗口“分数”小于“k”的位置，从左指针到右指针任一元素**开始**到右指针所指元素**结束**的子数组“分数”都小于“k”，都是合法子数组。总个数为$r-l+1$，累加到答案中即可。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-04-30 10:29:37
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-30 10:34:24
 */
typedef long long ll;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        ll ans = 0, cnt = 0;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            cnt += nums[r];
            while (cnt * (r - l + 1) >= k) {
                cnt -= nums[l++];
            }
            ans += (r - l + 1);
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-04-29 23:46:38
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-30 10:39:13
'''
from typing import List

class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        ans = cnt = l = 0
        for r in range(len(nums)):
            cnt += nums[r]
            while cnt * (r - l + 1) >= k:
                cnt -= nums[l]
                l += 1
            ans += (r - l + 1)
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-04-29 23:46:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-30 10:41:19
 */
class Solution {
    public long countSubarrays(int[] nums, long k) {
        long ans = 0, cnt = 0;
        for (int l = 0, r = 0; r < nums.length; r++) {
            cnt += nums[r];
            while (cnt * (r - l + 1) >= k) {
                cnt -= nums[l++];
            }
            ans += (r - l + 1);
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-04-29 23:46:45
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-30 10:55:53
 */
package main

func countSubarrays(nums []int, k int64) (ans int64) {
    cnt := int64(0)
    l := 0
    for r, t := range nums {
        cnt += int64(t)
        for cnt * int64(r - l + 1) >= k {
            cnt -= int64(nums[l])
            l++
        }
        ans += int64(r - l + 1)
    }
    return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/147637062)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/04/30/LeetCode%202302.%E7%BB%9F%E8%AE%A1%E5%BE%97%E5%88%86%E5%B0%8F%E4%BA%8EK%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84%E6%95%B0%E7%9B%AE/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
