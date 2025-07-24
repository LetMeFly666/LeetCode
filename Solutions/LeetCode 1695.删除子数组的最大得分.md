---
title: 1695.删除子数组的最大得分：滑动窗口(哈希表)
date: 2025-07-24 13:24:09
tags: [题解, LeetCode, 中等, 数组, 哈希表, set, 滑动窗口, 双指针]
categories: [题解, LeetCode]
---

# 【LetMeFly】1695.删除子数组的最大得分：滑动窗口(哈希表)

力扣题目链接：[https://leetcode.cn/problems/maximum-erasure-value/](https://leetcode.cn/problems/maximum-erasure-value/)

<p>给你一个正整数数组 <code>nums</code> ，请你从中删除一个含有 <strong>若干不同元素</strong> 的子数组<strong>。</strong>删除子数组的 <strong>得分</strong> 就是子数组各元素之 <strong>和</strong> 。</p>

<p>返回 <strong>只删除一个</strong> 子数组可获得的 <strong>最大得分</strong><em> 。</em></p>

<p>如果数组 <code>b</code> 是数组 <code>a</code> 的一个连续子序列，即如果它等于 <code>a[l],a[l+1],...,a[r]</code> ，那么它就是 <code>a</code> 的一个子数组。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,2,4,5,6]
<strong>输出：</strong>17
<strong>解释：</strong>最优子数组是 [2,4,5,6]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,2,1,2,5,2,1,2,5]
<strong>输出：</strong>8
<strong>解释：</strong>最优子数组是 [5,2,1] 或 [1,2,5]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>1 <= nums[i] <= 10<sup>4</sup></code></li>
</ul>


    
## 解题方法：滑动窗口

这道题翻译一下就是：找和最大的不包含相同元素的子数组。

怎么找？滑动窗口即可。

使用两个指针指向窗口的两个端点，窗口范围内的数组为以右指针r为终点的最长的子数组。

每次右指针右移一位，如果窗口中已经包含了要新加入的元素，就将左指针不断左移，直到窗口中不包含右指针指向的新元素为止。

如何快速判断窗口中一个元素是否已经存在？使用一个哈希表统计即可。

+ 时间复杂度$O(len(nums))$，左右指针每个元素各自最多遍历一次。
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-07-23 10:31:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-23 13:26:19
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> had;
        int ans = 0, cnt = 0;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            while (had.count(nums[r])) {
                had.erase(nums[l]);
                cnt -= nums[l++];
            }
            had.insert(nums[r]);
            cnt += nums[r];
            // printf("l = %d, r = %d, cnt = %d\n", l, r, cnt);
            ans = max(ans, cnt);
        }
        return ans;
    }
};

/*
[187,470,25,436,538,809,441,167,477,110,275,133,666,345,411,459,490,266,987,965,429,166,809,340,467,318,125,165,809,610,31,585,970,306,42,189,169,743,78,810,70,382,367,490,787,670,476,278,775,673,299,19,893,817,971,458,409,886,434]
9252
16911
*/
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-07-23 10:31:42
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-23 13:29:36
'''
from typing import List

class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        had = set()
        ans = l = cnt = 0
        for v in nums:
            while v in had:
                had.remove(nums[l])
                cnt -= nums[l]
                l += 1
            had.add(v)
            cnt += v
            ans = max(ans, cnt)
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-07-23 10:31:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-24 13:22:02
 */
import java.util.HashSet;
import java.util.Set;

class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        int ans = 0;
        Set<Integer> had = new HashSet<>();
        for (int l = 0, r = 0, cnt = 0; r < nums.length; r++) {
            while (had.contains(nums[r])) {
                had.remove(nums[l]);
                cnt -= nums[l++];
            }
            had.add(nums[r]);
            cnt += nums[r];
            ans = Math.max(ans, cnt);
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-07-23 10:31:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-24 13:16:17
 */
package main

// import "fmt"

func maximumUniqueSubarray(nums []int) (ans int) {
    had := map[int]struct{}{}
    l, cnt := 0, 0
    for _, t := range nums {
        for _, ok := had[t]; ok; _, ok = had[t] {
            delete(had, nums[l])
            cnt -= nums[l]
            l++
        }
        cnt += t
        had[t] = struct{}{}
        ans = max(ans, cnt)
    }
    return
}

// func main() {
//     nums := []int{4, 2, 4, 5, 6}
//     ans := maximumUniqueSubarray(nums)
//     fmt.Println(ans)
// }
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/149602144)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/07/23/LeetCode%201695.%E5%88%A0%E9%99%A4%E5%AD%90%E6%95%B0%E7%BB%84%E7%9A%84%E6%9C%80%E5%A4%A7%E5%BE%97%E5%88%86/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
