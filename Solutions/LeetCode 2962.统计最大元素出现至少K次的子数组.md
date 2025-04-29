---
title: 2962.统计最大元素出现至少 K 次的子数组：滑动窗口
date: 2025-04-29 21:28:38
tags: [题解, LeetCode, 中等, 数组, 滑动窗口]
categories: [题解, LeetCode]
---

# 【LetMeFly】2962.统计最大元素出现至少 K 次的子数组：滑动窗口

力扣题目链接：[https://leetcode.cn/problems/count-subarrays-where-max-element-appears-at-least-k-times/](https://leetcode.cn/problems/count-subarrays-where-max-element-appears-at-least-k-times/)

<p>给你一个整数数组 <code>nums</code> 和一个 <strong>正整数</strong> <code>k</code> 。</p>

<p>请你统计有多少满足 「&nbsp;<code>nums</code> 中的 <strong>最大</strong> 元素」至少出现 <code>k</code> 次的子数组，并返回满足这一条件的子数组的数目。</p>

<p>子数组是数组中的一个连续元素序列。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,3,2,3,3], k = 2
<strong>输出：</strong>6
<strong>解释：</strong>包含元素 3 至少 2 次的子数组为：[1,3,2,3]、[1,3,2,3,3]、[3,2,3]、[3,2,3,3]、[2,3,3] 和 [3,3] 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,4,2,1], k = 3
<strong>输出：</strong>0
<strong>解释：</strong>没有子数组包含元素 4 至少 3 次。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法：滑动窗口

首先遍历一遍数组得到数组中最大的元素。

之后使用两个指针分别指向窗口中的第一个和最后一个元素的下标，不断右移右指针，并将新元素加入窗口。

当窗口中“最大数个数”等于k时，不断右移左窗口并将左边元素移出窗口。此时左指针左边(不含左指针)的任何一个元素开始到右指针所组成的子数组都合法。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-04-29 13:19:27
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-29 21:19:24
 */
typedef long long ll;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = nums[0];
        for (int t : nums) {
            mx = max(mx, t);
        }
        ll ans = 0;
        for (int l = 0, r = 0, cnt = 0; r < nums.size(); r++) {
            cnt += nums[r] == mx;
            while (cnt == k) {
                cnt -= nums[l++] == mx;
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
Date: 2025-04-29 13:19:47
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-29 21:21:03
'''
from typing import List

class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        mx = max(nums)
        l = cnt = ans = 0
        for t in nums:
            cnt += t == mx
            while cnt == k:
                cnt -= nums[l] == mx
                l += 1
            ans += l
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-04-29 13:19:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-29 21:23:01
 */
class Solution {
    public long countSubarrays(int[] nums, int k) {
        int mx = nums[0];
        for (int t : nums) {
            mx = Math.max(mx, t);
        }
        long ans = 0;
        for (int l = 0, cnt = 0, r = 0; r < nums.length; r++) {
            if (nums[r] == mx) {
                cnt++;
            }
            while (cnt == k) {
                if (nums[l++] == mx) {
                    cnt--;
                }
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
 * @Date: 2025-04-29 13:20:02
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-29 13:23:23
 */
package main

func countSubarrays(nums []int, k int) (ans int64) {
    M := nums[0]
	for _, t := range nums {
		M = max(M, t)
	}
	for l, r, cnt := 0, 0, 0; r < len(nums); r++ {
		if nums[r] == M {
			cnt++
		}
		for cnt >= k {
			if nums[l] == M {
				cnt -= 1
			}
			l++
		}
		ans += int64(l)
	}
	return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/147620212)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/04/29/LeetCode%202962.%E7%BB%9F%E8%AE%A1%E6%9C%80%E5%A4%A7%E5%85%83%E7%B4%A0%E5%87%BA%E7%8E%B0%E8%87%B3%E5%B0%91K%E6%AC%A1%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
