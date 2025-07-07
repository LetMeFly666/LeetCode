---
title: 2099.找到和最大的长度为 K 的子序列
date: 2025-07-07 23:40:45
tags: [题解, LeetCode, 简单, 数组, 哈希表, 排序, 堆（优先队列）]
categories: [题解, LeetCode]
---

# 【LetMeFly】2099.找到和最大的长度为 K 的子序列

力扣题目链接：[https://leetcode.cn/problems/find-subsequence-of-length-k-with-the-largest-sum/](https://leetcode.cn/problems/find-subsequence-of-length-k-with-the-largest-sum/)

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;。你需要找到&nbsp;<code>nums</code>&nbsp;中长度为 <code>k</code>&nbsp;的 <strong>子序列</strong>&nbsp;，且这个子序列的&nbsp;<strong>和最大&nbsp;</strong>。</p>

<p>请你返回 <strong>任意</strong> 一个长度为&nbsp;<code>k</code>&nbsp;的整数子序列。</p>

<p><strong>子序列</strong>&nbsp;定义为从一个数组里删除一些元素后，不改变剩下元素的顺序得到的数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [2,1,3,3], k = 2
<b>输出：</b>[3,3]
<strong>解释：</strong>
子序列有最大和：3 + 3 = 6 。</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [-1,-2,3,4], k = 3
<b>输出：</b>[-1,3,4]
<b>解释：</b>
子序列有最大和：-1 + 3 + 4 = 6 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = [3,4,3,3], k = 2
<b>输出：</b>[3,4]
<strong>解释：</strong>
子序列有最大和：3 + 4 = 7 。
另一个可行的子序列为 [4, 3] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>-10<sup>5</sup>&nbsp;&lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>
</ul>


    
## 解题方法：xx

11111

+ 时间复杂度$O(N^2)$
+ 空间复杂度$O(N\log N)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-07-03 21:31:48
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-06 00:06:51
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> idx(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            idx[i] = i;
        }
        sort(idx.begin(), idx.end(), [&nums](int i, int j) {
            return nums[i] > nums[j];
        });
        idx.resize(k);
        sort(idx.begin(), idx.end());
        for (int &t : idx) {
            t = nums[t];
        }
        return idx;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-07-03 21:31:48
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-06 00:09:39
'''
from typing import List

class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        idx = [i for i in range(len(nums))]
        idx.sort(key=lambda i : -nums[i])
        idx = idx[:k]
        idx.sort()
        return [nums[i] for i in idx]
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-07-03 21:31:48
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-06 22:03:44
 */
import java.util.Arrays;

class Solution {
    public int[] maxSubsequence(int[] nums, int k) {
        Integer[] idx = new Integer[nums.length];
        for (int i = 0; i < nums.length; i++) {
            idx[i] = i;
        }
        Arrays.sort(idx, (i, j) -> nums[j] - nums[i]);
        int[] ans = new int[k];
        for (int i = 0; i < k; i++) {
            ans[i] = idx[i];
        }
        Arrays.sort(ans);
        for (int i = 0; i < k; i++) {
            ans[i] = nums[ans[i]];
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-07-03 21:31:48
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-06 22:16:49
 */
package main

import "sort"

func maxSubsequence(nums []int, k int) []int {
    idx := make([]int, len(nums))
    for i := range idx {
        idx[i] = i
    }
    sort.Slice(idx, func(i, j int) bool {
        return nums[idx[i]] > nums[idx[j]]  // 不可以nums[i] > nums[j]，因为排序过程中idx[i]可能不再是i 
    })
    idx = idx[:k]
    sort.Ints(idx)
    for th, i := range idx {
        idx[th] = nums[i]
    }
    return idx
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/--------------------------)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/07/07/LeetCode%202099.%E6%89%BE%E5%88%B0%E5%92%8C%E6%9C%80%E5%A4%A7%E7%9A%84%E9%95%BF%E5%BA%A6%E4%B8%BAK%E7%9A%84%E5%AD%90%E5%BA%8F%E5%88%97/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
