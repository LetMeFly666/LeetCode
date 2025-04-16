---
title: 2537.统计好子数组的数目：滑动窗口(双指针)
date: 2025-04-16 21:01:12
tags: [题解, LeetCode, 中等, 数组, 哈希表, 滑动窗口, 双指针]
categories: [题解, LeetCode]
---

# 【LetMeFly】2537.统计好子数组的数目：滑动窗口(双指针)

力扣题目链接：[https://leetcode.cn/problems/count-the-number-of-good-subarrays/](https://leetcode.cn/problems/count-the-number-of-good-subarrays/)

<p>给你一个整数数组 <code>nums</code>&nbsp;和一个整数 <code>k</code>&nbsp;，请你返回 <code>nums</code>&nbsp;中 <strong>好</strong>&nbsp;子数组的数目。</p>

<p>一个子数组 <code>arr</code>&nbsp;如果有 <strong>至少</strong>&nbsp;<code>k</code>&nbsp;对下标 <code>(i, j)</code>&nbsp;满足 <code>i &lt; j</code>&nbsp;且 <code>arr[i] == arr[j]</code>&nbsp;，那么称它是一个 <strong>好</strong>&nbsp;子数组。</p>

<p><strong>子数组</strong>&nbsp;是原数组中一段连续 <strong>非空</strong>&nbsp;的元素序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [1,1,1,1,1], k = 10
<b>输出：</b>1
<b>解释：</b>唯一的好子数组是这个数组本身。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [3,1,4,3,2,2,4], k = 2
<b>输出：</b>4
<b>解释：</b>总共有 4 个不同的好子数组：
- [3,1,4,3,2,2] 有 2 对。
- [3,1,4,3,2,2,4] 有 3 对。
- [1,4,3,2,2,4] 有 2 对。
- [4,3,2,2,4] 有 2 对。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i], k &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：滑动窗口(双指针)

### 解题思路

使用一个哈希表记录窗口(两个指针之间)中每个元素出现的次数。

右指针从第一个元素到最后一个元素遍历数组，在移动的过程中，将指向的元素添加到“窗口”中并更新窗口中的“相等对数”；

在窗口中的“相等对数”大于等于$k$时，不断右移左指针（将左指针指向元素移出窗口）并更新窗口中的“相等对数”；

这样，右指针每次移动一个位置，左指针指向的就是第一个“窗口中相等对数小于$k$”的位置。

### 具体方法

假设右移**右**指针新**加入**窗口中了一个元素$x$，那么如何更新“窗口中的相等对数”呢？

> **新加入**的$x$与之前窗口中的每个**已有**$x$都能配对，所以新增“对数”为新元素**加入前**哈希表中$x$的个数。

假设右移**左**指针新**移除**了窗口中一个元素$x$，那么如何更新“窗口中的相等对数”呢？

> **被移除**的$x$与窗口中的每个**其他**$x$都配过对，所以减少的“对数”为新元素**移除后**哈希表中$x$的个数。

假设第一个“使窗口中相等对数小于$k$”的左指针下标为$l$，那么答案应该增加几？

> $l$下标左边的任何一个元素开始，到右指针$r$的字数组都满足“相等对数大于等于$k$”，都是“好字数组”。
>
> 以$r$结尾的好字数组的个数为$l$左边的元素个数，对答案的贡献为$l$。

### 时空复杂度

+ 时间复杂度$O(len(nums))$。左右指针最多各自遍历数组一次
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-04-16 19:45:53
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-16 20:25:23
 */
typedef long long ll;

class Solution {
public:
    ll countGood(vector<int>& nums, int k) {
        ll ans = 0;
        unordered_map<int, int> ma;
        ll now = 0;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            now += ma[nums[r]]++;
            while (now >= k) {
                now -= --ma[nums[l++]];
            }
            ans += l;
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-04-16 20:23:21
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-16 20:26:37
'''
from typing import List
from collections import defaultdict


class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        times = defaultdict(int)
        ans = l = now = 0
        for t in nums:
            now += times[t]
            times[t] += 1
            while now >= k:
                times[nums[l]] -= 1
                now -= times[nums[l]]
                l += 1
            ans += l
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-04-16 20:27:13
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-16 20:49:27
 */
import java.util.Map;
import java.util.HashMap;

class Solution {
    public long countGood(int[] nums, int k) {
        long ans = 0, now = 0;
        Map<Integer, Integer> ma = new HashMap<>();
        for (int l = 0, r = 0; r < nums.length; r++) {
            now += ma.merge(nums[r], 1, Integer::sum) - 1;
            while (now >= k) {
                now -= ma.merge(nums[l++], -1, Integer::sum);
            }
            ans += l;
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-04-16 20:50:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-16 20:56:36
 */
package main

func countGood(nums []int, k int) (ans int64) {
    times := map[int]int64{}
    now := int64(0)
    for l, r := 0, 0; r < len(nums); r++ {
        now += times[nums[r]]
        times[nums[r]]++
        for now >= int64(k) {
            times[nums[l]]--
            now -= times[nums[l]]
            l++
        }
        ans += int64(l)
    }
    return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/147288778)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/04/16/LeetCode%202537.%E7%BB%9F%E8%AE%A1%E5%A5%BD%E5%AD%90%E6%95%B0%E7%BB%84%E7%9A%84%E6%95%B0%E7%9B%AE/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
