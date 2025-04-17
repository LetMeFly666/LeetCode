---
title: 2176.统计数组中相等且可以被整除的数对：两层遍历模拟
date: 2025-04-17 20:23:19
tags: [题解, LeetCode, 简单, 数组, 遍历, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】2176.统计数组中相等且可以被整除的数对：两层遍历模拟

力扣题目链接：[https://leetcode.cn/problems/count-equal-and-divisible-pairs-in-an-array/](https://leetcode.cn/problems/count-equal-and-divisible-pairs-in-an-array/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;，请你返回满足&nbsp;<code>0 &lt;= i &lt; j &lt; n</code>&nbsp;，<code>nums[i] == nums[j]</code> 且&nbsp;<code>(i * j)</code>&nbsp;能被&nbsp;<code>k</code>&nbsp;整除的数对&nbsp;<code>(i, j)</code>&nbsp;的&nbsp;<strong>数目</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [3,1,2,2,2,1,3], k = 2
<b>输出：</b>4
<strong>解释：</strong>
总共有 4 对数符合所有要求：
- nums[0] == nums[6] 且 0 * 6 == 0 ，能被 2 整除。
- nums[2] == nums[3] 且 2 * 3 == 6 ，能被 2 整除。
- nums[2] == nums[4] 且 2 * 4 == 8 ，能被 2 整除。
- nums[3] == nums[4] 且 3 * 4 == 12 ，能被 2 整除。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1,2,3,4], k = 1
<b>输出：</b>0
<b>解释：</b>由于数组中没有重复数值，所以没有数对 (i,j) 符合所有要求。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i], k &lt;= 100</code></li>
</ul>


    
## 解题方法：模拟

第一层使用变量$i$从$0$到$n-1$遍历，第二层使用变量$j$从$i+1$到$n-1$遍历。

如果$nums[i]==nums[j]$相等且$i\times j \% k==0$，则答案数量加一。

+ 时间复杂度$O(len(nums)^2)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-04-17 20:13:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-17 20:28:40
 */
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j] && i * j % k == 0) {
                    ans++;
                }
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
Date: 2025-04-17 20:15:46
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-17 20:15:58
'''
from typing import List


class Solution:
    def countPairs(self, nums: List[int], k: int) -> int:
        return sum(nums[i] == nums[j] and i * j % k == 0 for i in range(len(nums)) for j in range(i + 1, len(nums)))
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-04-17 20:17:48
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-17 20:18:12
 */
class Solution {
    public int countPairs(int[] nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] == nums[j] && i * j % k == 0) {
                    ans++;
                }
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
 * @Date: 2025-04-17 20:19:13
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-17 20:21:29
 */
package main

func countPairs(nums []int, k int) (ans int) {
    for i := range nums {
		for j := i + 1; j < len(nums); j++ {
			if nums[i] == nums[j] && i * j % k == 0 {
				ans++
			}
		}
	}
	return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/147315213)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/04/17/LeetCode%202176.%E7%BB%9F%E8%AE%A1%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9B%B8%E7%AD%89%E4%B8%94%E5%8F%AF%E4%BB%A5%E8%A2%AB%E6%95%B4%E9%99%A4%E7%9A%84%E6%95%B0%E5%AF%B9/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
