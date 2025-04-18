---
title: 2364.统计坏数对的数目：反向统计
date: 2025-04-18 13:47:04
tags: [题解, LeetCode, 中等, 数组, 哈希表, map, 数学, 计数]
categories: [题解, LeetCode]
---

# 【LetMeFly】2364.统计坏数对的数目：反向统计

力扣题目链接：[https://leetcode.cn/problems/count-number-of-bad-pairs/](https://leetcode.cn/problems/count-number-of-bad-pairs/)

<p>给你一个下标从<strong>&nbsp;0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;。如果 <code>i &lt; j</code>&nbsp;且&nbsp;<code>j - i != nums[j] - nums[i]</code>&nbsp;，那么我们称&nbsp;<code>(i, j)</code>&nbsp;是一个 <strong>坏</strong><strong>数对</strong>&nbsp;。</p>

<p>请你返回 <code>nums</code>&nbsp;中 <strong>坏数对</strong>&nbsp;的总数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [4,1,3,3]
<b>输出：</b>5
<b>解释：</b>数对 (0, 1) 是坏数对，因为 1 - 0 != 1 - 4 。
数对 (0, 2) 是坏数对，因为 2 - 0 != 3 - 4, 2 != -1 。
数对 (0, 3) 是坏数对，因为 3 - 0 != 3 - 4, 3 != -1 。
数对 (1, 2) 是坏数对，因为 2 - 1 != 3 - 1, 1 != 2 。
数对 (2, 3) 是坏数对，因为 3 - 2 != 3 - 3, 1 != 0 。
总共有 5 个坏数对，所以我们返回 5 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1,2,3,4,5]
<b>输出：</b>0
<strong>解释：</strong>没有坏数对。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

很不错的一道题。

## 解题方法：哈希表反向计数

长度为$n$的数组一共有多少个数对？

> 一共有$n(n-1)/2$个。

其中有多少个坏数对？

> 总数对个数减去好数对个数即为坏数对个数。

如何统计有多少个好数对个数？

> $nums[j] - nums[i] == j - i$等价于$nums[j] - j == nums[i] - i$，
>
> 我们可以将数组中的每个数减去它的下标，问题就变成了“数组中相同的数组成的数对有多少个”。

数组中相同的数组成的数对有多少个？

> 可以使用一个哈希表统计每种元素出现的次数。假设遍历处理过的数组时遍历到了$x$，那么当前$x$可以与已出现过的所有$x$配对。

问题解决。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-04-18 10:23:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-18 10:25:58
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> times;
        ll ans = nums.size() * (nums.size() - 1) / 2;
        for (int i = 0; i < nums.size(); i++) {
            ans -= times[nums[i] - i]++;
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-04-18 10:26:49
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-18 10:28:15
'''
from typing import List
from collections import defaultdict

class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        times = defaultdict(int)
        ans = len(nums) * (len(nums) - 1) // 2
        for i, v in enumerate(nums):
            ans -= times[v - i]
            times[v - i] += 1
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-04-18 10:29:32
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-18 10:34:19
 */
import java.util.Map;
import java.util.HashMap;

class Solution {
    public long countBadPairs(int[] nums) {
        long ans = (long)nums.length * (nums.length - 1) / 2;
        Map<Integer, Integer> times = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            ans -= times.merge(nums[i] - i, 1, Integer::sum) - 1;
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-04-18 10:35:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-18 10:38:47
 */
package main

func countBadPairs(nums []int) int64 {
    ans := len(nums) * (len(nums) - 1) / 2
    times := map[int]int{}
    for i, v := range nums {
        ans -= times[v - i]
        times[v - i]++
    }
    return int64(ans)
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/147327624)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/04/18/LeetCode%202364.%E7%BB%9F%E8%AE%A1%E5%9D%8F%E6%95%B0%E5%AF%B9%E7%9A%84%E6%95%B0%E7%9B%AE/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
