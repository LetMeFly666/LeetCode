---
title: 3392.统计符合条件长度为 3 的子数组数目：一次遍历模拟
date: 2025-04-29 10:24:45
tags: [题解, LeetCode, 简单, 数组]
categories: [题解, LeetCode]
---

# 【LetMeFly】3392.统计符合条件长度为 3 的子数组数目：一次遍历模拟

力扣题目链接：[https://leetcode.cn/problems/count-subarrays-of-length-three-with-a-condition/](https://leetcode.cn/problems/count-subarrays-of-length-three-with-a-condition/)

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;，请你返回长度为 3 的 <span data-keyword="subarray-nonempty">子数组</span>，满足第一个数和第三个数的和恰好为第二个数的一半。</p>

<p><strong>子数组</strong>&nbsp;指的是一个数组中连续 <strong>非空</strong>&nbsp;的元素序列。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,1,4,1]</span></p>

<p><span class="example-io"><b>输出：</b>1</span></p>

<p><b>解释：</b></p>

<p>只有子数组&nbsp;<code>[1,4,1]</code>&nbsp;包含 3 个元素且第一个和第三个数字之和是中间数字的一半。number.</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,1,1]</span></p>

<p><span class="example-io"><b>输出：</b>0</span></p>

<p><b>解释：</b></p>

<p><code>[1,1,1]</code>&nbsp;是唯一长度为 3 的子数组，但第一个数和第三个数的和不是第二个数的一半。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 100</code></li>
	<li><code><font face="monospace">-100 &lt;= nums[i] &lt;= 100</font></code></li>
</ul>


    
## 解题方法：一次遍历模拟

用变量$i$从第三个元素开始向后遍历数组，若$(nums[i] + nums[i - 2]) * 2 == nums[i - 1]$，则答案数量加一。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-04-27 23:47:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-27 23:48:38
 */
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans = 0;
        for (int i = 2; i < nums.size(); i++) {
            ans += (nums[i] + nums[i - 2]) * 2 == nums[i - 1];
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-04-27 23:49:08
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-27 23:49:26
'''
from typing import List

class Solution:
    def countSubarrays(self, nums: List[int]) -> int:
        return sum((nums[i - 2] + nums[i]) * 2 == nums[i - 1] for i in range(2, len(nums)))
```

#### Golang

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-04-27 23:49:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-27 23:52:54
 * @Description: AC,100.00%,95.45%
 */
package main

func countSubarrays(nums []int) (ans int) {
    for i := 2; i < len(nums); i++ {
        if (nums[i] + nums[i - 2]) * 2 == nums[i - 1] {
            ans++
        }
    }
    return
}
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-04-27 23:49:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-27 23:50:25
 */
class Solution {
    public int countSubarrays(int[] nums) {
        int ans = 0;
        for (int i = 2; i < nums.length; i++) {
            if ((nums[i - 2] + nums[i]) * 2 == nums[i - 1]) {
                ans++;
            }
        }
        return ans;
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/147603015)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/04/29/LeetCode%203392.%E7%BB%9F%E8%AE%A1%E7%AC%A6%E5%90%88%E6%9D%A1%E4%BB%B6%E9%95%BF%E5%BA%A6%E4%B8%BA3%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84%E6%95%B0%E7%9B%AE/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
