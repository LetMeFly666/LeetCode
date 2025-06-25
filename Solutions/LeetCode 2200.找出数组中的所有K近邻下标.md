---
title: 2200.找出数组中的所有 K 近邻下标：O(n)解法 - 比灵神代码简洁了一回
date: 2025-06-25 22:44:38
tags: [题解, LeetCode, 简单, 数组, 双指针, 模拟, 暴力]
categories: [题解, LeetCode]
---

# 【LetMeFly】2200.找出数组中的所有 K 近邻下标：O(n)解法 - 比灵神代码简洁了一回

力扣题目链接：[https://leetcode.cn/problems/find-all-k-distant-indices-in-an-array/](https://leetcode.cn/problems/find-all-k-distant-indices-in-an-array/)

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 和两个整数 <code>key</code> 和 <code>k</code> 。<strong>K 近邻下标</strong> 是 <code>nums</code> 中的一个下标 <code>i</code> ，并满足至少存在一个下标 <code>j</code> 使得 <code>|i - j| &lt;= k</code> 且 <code>nums[j] == key</code> 。</p>

<p>以列表形式返回按 <strong>递增顺序</strong> 排序的所有 K 近邻下标。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,4,9,1,3,9,5], key = 9, k = 1
<strong>输出：</strong>[1,2,3,4,5,6]
<strong>解释：</strong>因此，<code>nums[2] == key</code> 且 <code>nums[5] == key 。
- 对下标 0 ，|0 - 2| &gt; k 且 |0 - 5| &gt; k ，所以不存在 j</code> 使得 <code>|0 - j| &lt;= k</code> 且 <code>nums[j] == key 。所以 0 不是一个 K 近邻下标。
- 对下标 1 ，|1 - 2| &lt;= k 且 nums[2] == key ，所以 1 是一个 K 近邻下标。
- 对下标 2 ，|2 - 2| &lt;= k 且 nums[2] == key ，所以 2 是一个 K 近邻下标。
- 对下标 3 ，|3 - 2| &lt;= k 且 nums[2] == key ，所以 3 是一个 K 近邻下标。
- 对下标 4 ，|4 - 5| &lt;= k 且 nums[5] == key ，所以 4 是一个 K 近邻下标。
- 对下标 5 ，|5 - 5| &lt;= k 且 nums[5] == key ，所以 5 是一个 K 近邻下标。
- 对下标 6 ，|6 - 5| &lt;= k 且 nums[5] == key ，所以 6 是一个 K 近邻下标。
</code>因此，按递增顺序返回 [1,2,3,4,5,6] 。 
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,2,2,2,2], key = 2, k = 2
<strong>输出：</strong>[0,1,2,3,4]
<strong>解释：</strong>对 nums 的所有下标 i ，总存在某个下标 j 使得 |i - j| &lt;= k 且 nums[j] == key ，所以每个下标都是一个 <code>K 近邻下标。</code> 
因此，返回 [0,1,2,3,4] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code>key</code> 是数组 <code>nums</code> 中的一个整数</li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>
</ul>


    
## 解题方法一：暴力模拟

用$i$从$0$到$len(nums)-1$遍历$nums$中的每个数并分别判断他们是否是“K近邻下标”，用$j$从$max(0, i-k)$到$min(len(nums)-1, i+k)$判断$i$的“K临近”是否有值为key的元素，如果有就将i添加到答案数组中。

+ 时间复杂度$O(len(nums)\times k)$
+ 空间复杂度$O(1)$，力扣返回值不计入算法空间复杂度

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-06-25 22:24:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-25 22:29:22
 */
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = max(0, i - k); j <= min(int(nums.size()) - 1, i + k); j++) {
                if (nums[j] == key) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};
```

## 解题方法二：双指针

我们不妨换个思路，遍历数组并将值为key的附近元素下标添加到答案数组中。

一个指针$i$遍历$nums$数组，一个指针$j$指向“未判断过的元素”。所谓“未判断过的元素”是指还不知道这个元素是否可以被加入答案数组。

如果$i$遍历到了值为$key$的元素了如何做？就将$[j, min(len(nums)-1, i+k)]$全部添加到答案数组中。

也就是说，$i$指针遍历了数组一次，$j$指针最多遍历每个元素各一次，总时间复杂度降低至了$O(n)$

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$，力扣返回值不计入算法空间复杂度

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-06-25 22:30:38
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-25 22:34:30
 */
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        for (int i = 0, j = 0; i < nums.size(); i++) {
            if (nums[i] == key) {
                int l = max(j, i - k), r = min(i + k, (int)nums.size() - 1);
                for (j = l; j <= r; j++) {
                    ans.push_back(j);
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
Date: 2025-06-25 22:24:22
LastEditors: LetMeFly.xyz
LastEditTime: 2025-06-25 22:38:19
'''
from typing import List

class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        ans = []
        last = 0
        for i in range(len(nums)):
            if nums[i] == key:
                for j in range(max(last, i - k), min(len(nums), i + k + 1)):
                    ans.append(j)
                last = i + k + 1
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-06-25 22:24:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-25 22:41:09
 */
import java.util.List;
import java.util.ArrayList;

class Solution {
    public List<Integer> findKDistantIndices(int[] nums, int key, int k) {
        List<Integer> ans = new ArrayList<>();
        for (int i = 0, j = 0; i < nums.length; i++) {
            if (nums[i] == key) {
                for (j = Math.max(j, i - k); j <= Math.min(nums.length - 1, i + k); j++) {
                    ans.add(j);
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
 * @Date: 2025-06-25 22:24:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-25 22:43:42
 */
package main

func findKDistantIndices(nums []int, key int, k int) (ans []int) {
    for i, j := 0, 0; i < len(nums); i++ {
        if nums[i] == key {
            for j = max(j, i - k); j <= min(len(nums) - 1, i + k); j++ {
                ans = append(ans, j)
            }
        }
    }
    return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/148909624)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/06/25/LeetCode%202200.%E6%89%BE%E5%87%BA%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E6%89%80%E6%9C%89K%E8%BF%91%E9%82%BB%E4%B8%8B%E6%A0%87/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
