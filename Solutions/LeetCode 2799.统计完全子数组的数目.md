---
title: 2799.统计完全子数组的数目：滑动窗口（哈希表）
date: 2025-04-24 23:24:12
tags: [题解, LeetCode, 中等, 数组, 哈希表, set, map, 滑动窗口]
categories: [题解, LeetCode]
---

# 【LetMeFly】2799.统计完全子数组的数目：滑动窗口（哈希表）

力扣题目链接：[https://leetcode.cn/problems/count-complete-subarrays-in-an-array/](https://leetcode.cn/problems/count-complete-subarrays-in-an-array/)

<p>给你一个由 <strong>正</strong> 整数组成的数组 <code>nums</code> 。</p>

<p>如果数组中的某个子数组满足下述条件，则称之为 <strong>完全子数组</strong> ：</p>

<ul>
	<li>子数组中 <strong>不同</strong> 元素的数目等于整个数组不同元素的数目。</li>
</ul>

<p>返回数组中 <strong>完全子数组</strong> 的数目。</p>

<p><strong>子数组</strong> 是数组中的一个连续非空序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,3,1,2,2]
<strong>输出：</strong>4
<strong>解释：</strong>完全子数组有：[1,3,1,2]、[1,3,1,2,2]、[3,1,2] 和 [3,1,2,2] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [5,5,5,5]
<strong>输出：</strong>10
<strong>解释：</strong>数组仅由整数 5 组成，所以任意子数组都满足完全子数组的条件。子数组的总数为 10 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 2000</code></li>
</ul>


    
## 解题方法：滑动窗口

首先使用一个哈希表统计数组中出现了多少种的元素（记为`allType`）。

接着再使用一个哈希表，统计窗口中每个元素出现多少次。

数组中的元素依次加入窗口中，当`窗口中元素种类数为allType`并且`窗口中第一个元素出现次数不为1`时，左移窗口左指针。

这样，就保证了每次窗口右指针确定时，左指针指向位置为最后一个“窗口合法”的位置（或0）。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-04-24 22:47:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-24 23:05:27
 * @Description: AC,36.08%,63.38%
 */
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> visited;
        for (int t : nums) {
            visited.insert(t);
        }
        int allType = visited.size();
        unordered_map<int, int> times;
        int ans = 0;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            times[nums[r]]++;
            while (times.size() == allType && times[nums[l]] > 1) {
                times[nums[l++]]--;
            }
            if (times.size() == allType) {
                ans += l + 1;
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
Date: 2025-04-24 22:47:44
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-24 23:10:14
Description: AC,60.65%,29.08%
'''
from typing import List
from collections import defaultdict

class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        allType = len(set(nums))
        times = defaultdict(int)
        l = ans = 0
        for r in range(len(nums)):
            times[nums[r]] += 1
            while len(times) == allType and times[nums[l]] > 1:
                times[nums[l]] -= 1
                l += 1
            if len(times) == allType:
                ans += l + 1
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-04-24 22:47:48
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-24 23:18:36
 * @Description: AC,65.83%,85.83%
 */
import java.util.Set;
import java.util.Map;
import java.util.HashSet;
import java.util.HashMap;

class Solution {
    public int countCompleteSubarrays(int[] nums) {
        Set<Integer> se = new HashSet<>();
        for (int t : nums) {
            se.add(t);
        }
        int allType = se.size();
        Map<Integer, Integer> times = new HashMap<>();
        int ans = 0;
        int l = 0;
        for (int t : nums) {
            times.merge(t, 1, Integer::sum);
            while (times.size() == allType && times.get(nums[l]) > 1) {
                times.merge(nums[l++], -1, Integer::sum);
            }
            if (times.size() == allType) {
                ans += l + 1;
            }
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-04-24 22:47:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-24 23:23:21
 * @Description: AC,32.53%,40.96%
 */
package main

func countCompleteSubarrays(nums []int) (ans int) {
	visited := map[int]bool{}
	for _, t := range nums {
		visited[t] = true
	}
	allType := len(visited)
	times := map[int]int{}
	l := 0
	for _, t := range nums {
		times[t]++
		for len(times) == allType && times[nums[l]] > 1 {
			times[nums[l]]--
			l++
		}
		if len(times) == allType {
			ans += l + 1
		}
	}
	return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/147494871)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/04/24/LeetCode%202799.%E7%BB%9F%E8%AE%A1%E5%AE%8C%E5%85%A8%E5%AD%90%E6%95%B0%E7%BB%84%E7%9A%84%E6%95%B0%E7%9B%AE/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
