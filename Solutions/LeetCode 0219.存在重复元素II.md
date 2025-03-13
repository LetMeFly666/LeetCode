---
title: 219.存在重复元素 II：哈希表
date: 2025-01-29 11:59:01
tags: [题解, LeetCode, 简单, 数组, 哈希表, map]
categories: [题解, LeetCode]
---

# 【LetMeFly】219.存在重复元素 II：哈希表

力扣题目链接：[https://leetcode.cn/problems/contains-duplicate-ii/](https://leetcode.cn/problems/contains-duplicate-ii/)

<p>给你一个整数数组&nbsp;<code>nums</code> 和一个整数&nbsp;<code>k</code> ，判断数组中是否存在两个 <strong>不同的索引</strong><em>&nbsp;</em><code>i</code>&nbsp;和<em>&nbsp;</em><code>j</code> ，满足 <code>nums[i] == nums[j]</code> 且 <code>abs(i - j) &lt;= k</code> 。如果存在，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,1], k<em> </em>= 3
<strong>输出：</strong>true</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,0,1,1], k<em> </em>=<em> </em>1
<strong>输出：</strong>true</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,1,2,3], k<em> </em>=<em> </em>2
<strong>输出：</strong>false</pre>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法：哈希表

使用哈希表记录每个元素最后一次出现的位置。

遍历`nums`数组，如果当前元素在哈希表中出现过并且这次和上次出现位置只差不超过$k$，则返回`true`。

每次遍历完一个数组，更新哈希表中这个数字的“最后出现位置”。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-01-29 11:48:29
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-29 11:49:49
 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> ma;
        for (int i = 0; i < nums.size(); i++) {
            if (ma.count(nums[i]) && i - ma[nums[i]] <= k) {
                return true;
            }
            ma[nums[i]] = i;
        }
        return false;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-01-29 11:51:06
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-29 11:51:09
'''
from typing import List

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        ma = dict()
        for i, t in enumerate(nums):
            if t in ma and i - ma[t] <= k:
                return True
            ma[t] = i
        return False
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-01-29 11:53:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-29 11:55:24
 */
import java.util.HashMap;

class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        HashMap<Integer, Integer> ma = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (i - ma.getOrDefault(nums[i], -1000000) <= k) {
                return true;
            }
            ma.put(nums[i], i);
        }
        return false;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-01-29 11:56:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-29 11:57:59
 */
package main

func containsNearbyDuplicate(nums []int, k int) bool {
    ma := map[int]int{}
    for i, t := range nums {
        if p, ok := ma[t]; ok && i - p <= k {
            return true
        }
        ma[t] = i
    }
    return false
}
```

Happy New Year! 健康第一。

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/01/29/LeetCode%200219.%E5%AD%98%E5%9C%A8%E9%87%8D%E5%A4%8D%E5%85%83%E7%B4%A0II/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/145392757](https://letmefly.blog.csdn.net/article/details/145392757)
