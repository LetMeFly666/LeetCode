---
title: 3046.分割数组
date: 2024-12-28 14:59:34
tags: [题解, LeetCode, 简单, 数组, 哈希表, map, 计数]
categories: [题解, LeetCode]
---

# 【LetMeFly】3046.分割数组：计数

力扣题目链接：[https://leetcode.cn/problems/split-the-array/](https://leetcode.cn/problems/split-the-array/)

<p>给你一个长度为 <strong>偶数 </strong>的整数数组 <code>nums</code> 。你需要将这个数组分割成 <code>nums1</code> 和 <code>nums2</code> 两部分，要求：</p>

<ul>
	<li><code>nums1.length == nums2.length == nums.length / 2</code> 。</li>
	<li><code>nums1</code> 应包含 <strong>互不相同</strong><strong> </strong>的元素。</li>
	<li><code>nums2</code>也应包含<strong> 互不相同</strong> 的元素。</li>
</ul>

<p>如果能够分割数组就返回 <code>true</code> ，否则返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,2,2,3,4]
<strong>输出：</strong>true
<strong>解释：</strong>分割 nums 的可行方案之一是 nums1 = [1,2,3] 和 nums2 = [1,2,4] 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,1,1]
<strong>输出：</strong>false
<strong>解释：</strong>分割 nums 的唯一可行方案是 nums1 = [1,1] 和 nums2 = [1,1] 。但 nums1 和 nums2 都不是由互不相同的元素构成。因此，返回 false 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>nums.length % 2 == 0</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>


    
## 解题方法：哈希表计数

使用哈希表统计每个数出现的次数，一旦有数字出现3次及以上就直接返回`false`。

所有数字都出现2次及一下则返回`true`。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2024-12-28 14:38:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-28 14:40:14
 */
class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        int times[101] = {0};
        for (int t : nums) {
            times[t]++;
            if (times[t] > 2) {
                return false;
            }
        }
        return true;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2024-12-28 14:40:34
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-28 14:41:10
'''
from typing import List
from collections import Counter

class Solution:
    def isPossibleToSplit(self, nums: List[int]) -> bool:
        return max(Counter(nums).values()) <= 2
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2024-12-28 14:43:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-28 14:45:25
 */
import java.util.HashMap;

class Solution {
    public boolean isPossibleToSplit(int[] nums) {
        HashMap<Integer, Integer> times = new HashMap<>();
        for (int t : nums) {
            if (times.merge(t, 1, Integer::sum) > 2) {
                return false;
            }
        }
        return true;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2024-12-28 14:48:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-28 14:57:51
 */
package main

func isPossibleToSplit(nums []int) bool {
    times := map[int]int{}
    for _, n := range nums {
        times[n]++
        if (times[n] > 2) {
            return false
        }
    }
    return true
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/12/28/LeetCode%203046.%E5%88%86%E5%89%B2%E6%95%B0%E7%BB%84/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/144789679](https://letmefly.blog.csdn.net/article/details/144789679)
