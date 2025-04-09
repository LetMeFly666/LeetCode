---
title: 3375.使数组的值全部为 K 的最少操作次数：O(1)空间——排序+一次遍历
date: 2025-04-09 22:20:52
tags: [题解, LeetCode, 简单, 数组, 排序, 遍历, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】3375.使数组的值全部为 K 的最少操作次数：O(1)空间——排序+一次遍历

力扣题目链接：[https://leetcode.cn/problems/minimum-operations-to-make-array-values-equal-to-k/](https://leetcode.cn/problems/minimum-operations-to-make-array-values-equal-to-k/)

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;。</p>

<p>如果一个数组中所有 <strong>严格大于</strong>&nbsp;<code>h</code>&nbsp;的整数值都 <strong>相等</strong>&nbsp;，那么我们称整数&nbsp;<code>h</code>&nbsp;是 <strong>合法的</strong>&nbsp;。</p>

<p>比方说，如果&nbsp;<code>nums = [10, 8, 10, 8]</code>&nbsp;，那么&nbsp;<code>h = 9</code>&nbsp;是一个 <strong>合法</strong>&nbsp;整数，因为所有满足&nbsp;<code>nums[i] &gt; 9</code>&nbsp;的数都等于 10 ，但是 5 不是 <strong>合法</strong>&nbsp;整数。</p>

<p>你可以对 <code>nums</code>&nbsp;执行以下操作：</p>

<ul>
	<li>选择一个整数&nbsp;<code>h</code>&nbsp;，它对于 <strong>当前</strong>&nbsp;<code>nums</code>&nbsp;中的值是合法的。</li>
	<li>对于每个下标 <code>i</code>&nbsp;，如果它满足&nbsp;<code>nums[i] &gt; h</code>&nbsp;，那么将&nbsp;<code>nums[i]</code>&nbsp;变为&nbsp;<code>h</code>&nbsp;。</li>
</ul>

<p>你的目标是将 <code>nums</code>&nbsp;中的所有元素都变为 <code>k</code>&nbsp;，请你返回 <strong>最少</strong>&nbsp;操作次数。如果无法将所有元素都变&nbsp;<code>k</code>&nbsp;，那么返回 -1 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [5,2,5,4,5], k = 2</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><b>解释：</b></p>

<p>依次选择合法整数 4 和 2 ，将数组全部变为 2 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [2,1,2], k = 2</span></p>

<p><span class="example-io"><b>输出：</b>-1</span></p>

<p><strong>解释：</strong></p>

<p>没法将所有值变为 2 。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [9,7,5,3], k = 1</span></p>

<p><span class="example-io"><b>输出：</b>4</span></p>

<p><strong>解释：</strong></p>

<p>依次选择合法整数 7 ，5 ，3 和 1 ，将数组全部变为 1 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100 </code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
	<li><code>1 &lt;= k &lt;= 100</code></li>
</ul>


    
## 解题方法：排序+遍历

这是一道阅读理解题。

先将数组从大到小排个序，若最小值小于$k$则直接返回$-1$，否则继续。

从(第二个元素开始)前到后遍历数组，若当前元素与上一个元素不同，则需要将上一个元素(和所有与之相等的元素)经过一次操作变成当前元素，操作次数加一。

最终(遍历完成后)，数组中所有值都会变成$k$。如果最小值不是$k$，则还需要额外的一次变换将所有值都变成$k$。

+ 时间复杂度$O(n\log n)$，其中$n=len(nums)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-04-09 21:58:45
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-09 22:08:39
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        if (nums.back() < k) {
            return -1;
        }
        int ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                printf("nums[%d] = %d, nums[%d] = %d, ans = %d, ans++\n", i, nums[i], i - 1, nums[i - 1], ans);  // ****
                ans++;
            }
        }
        return ans + (nums.back() != k);
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-04-09 22:09:48
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-09 22:10:06
'''
from typing import List

class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        nums.sort(reverse=True)
        if nums[-1] < k:
            return -1
        ans = 0
        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1]:
                ans += 1
        return ans + (nums[-1] != k)
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-04-09 22:12:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-09 22:15:42
 */
import java.util.Arrays;

class Solution {
    public int minOperations(int[] nums, int k) {
        Arrays.sort(nums);
        if (nums[0] < k) {
            return -1;
        }
        int ans = 0;
        for (int i = nums.length - 1; i > 0; i--) {
            if (nums[i] != nums[i - 1]) {
                ans++;
            }
        }
        if (nums[0] != k) {
            ans++;
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-04-09 22:16:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-09 22:18:14
 */
package main

import "slices"

func minOperations(nums []int, k int) (ans int) {
    slices.Sort(nums)
    if nums[0] < k {
        return -1
    }
    for i := len(nums) - 1; i > 0; i-- {
        if nums[i] != nums[i - 1] {
            ans++
        }
    }
    if nums[0] != k {
        ans++
    }
    return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/147104288)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/04/09/LeetCode%203375.%E4%BD%BF%E6%95%B0%E7%BB%84%E7%9A%84%E5%80%BC%E5%85%A8%E9%83%A8%E4%B8%BAK%E7%9A%84%E6%9C%80%E5%B0%91%E6%93%8D%E4%BD%9C%E6%AC%A1%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
