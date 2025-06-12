---
title: 3423.循环数组中相邻元素的最大差值：遍历(模拟)
date: 2025-06-12 23:03:23
tags: [题解, LeetCode, 简单, 数组, 遍历, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】3423.循环数组中相邻元素的最大差值：遍历(模拟)

力扣题目链接：[https://leetcode.cn/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/](https://leetcode.cn/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/)

<p>给你一个 <strong>循环</strong>&nbsp;数组&nbsp;<code>nums</code>&nbsp;，请你找出相邻元素之间的&nbsp;<strong>最大</strong>&nbsp;绝对差值。</p>

<p><b>注意：</b>一个循环数组中，第一个元素和最后一个元素是相邻的。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,4]</span></p>

<p><span class="example-io"><b>输出：</b>3</span></p>

<p><strong>解释：</strong></p>

<p>由于&nbsp;<code>nums</code>&nbsp;是循环的，<code>nums[0]</code> 和&nbsp;<code>nums[2]</code>&nbsp;是相邻的，它们之间的绝对差值是最大值&nbsp;<code>|4 - 1| = 3</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [-5,-10,-5]</span></p>

<p><span class="example-io"><b>输出：</b>5</span></p>

<p><b>解释：</b></p>

<p>相邻元素&nbsp;<code>nums[0]</code> 和&nbsp;<code>nums[1]</code>&nbsp;之间的绝对差值为最大值&nbsp;<code>|-5 - (-10)| = 5</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 100</code></li>
	<li><code>-100 &lt;= nums[i] &lt;= 100</code></li>
</ul>


    
## 解题方法：遍历

答案(ans)的默认值是$abs(nums[0] - nums[-1])$，接着使用$i$从$1$到$len(nums) - 1$遍历，更新ans为$max(ans, abs(nums[i] - nums[i - 1]))$

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-06-12 22:49:40
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-12 22:52:31
 */
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int ans = abs(nums[0] - nums[nums.size() - 1]);
        for (int i = 1; i < nums.size(); i++) {
            ans = max(ans, abs(nums[i] - nums[i - 1]));
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-06-12 22:49:40
LastEditors: LetMeFly.xyz
LastEditTime: 2025-06-12 22:53:39
'''
from typing import List

class Solution:
    def maxAdjacentDistance(self, nums: List[int]) -> int:
        ans = abs(nums[0] - nums[-1])
        for i in range(1, len(nums)):
            ans = max(ans, abs(nums[i] - nums[i - 1]))
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-06-12 22:49:40
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-12 23:01:46
 */
class Solution {
    public int maxAdjacentDistance(int[] nums) {
        int ans = Math.abs(nums[0] - nums[nums.length - 1]);
        for (int i = 1; i < nums.length; i++) {
            ans = Math.max(ans, Math.abs(nums[i] - nums[i - 1]));
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-06-12 22:49:40
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-12 22:58:57
 * @Descriptions: AC,100.00%,93.33%
 */
package main

// abs3423 是因为golang没有内置abs函数
func abs3423(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

func maxAdjacentDistance(nums []int) int {
    ans := abs3423(nums[0] - nums[len(nums)-1])
    for i := 1; i < len(nums); i++ {
        ans = max(ans, abs3423(nums[i] - nums[i - 1]))
    }
    return ans
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/148620597)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/06/12/LeetCode%203423.%E5%BE%AA%E7%8E%AF%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9B%B8%E9%82%BB%E5%85%83%E7%B4%A0%E7%9A%84%E6%9C%80%E5%A4%A7%E5%B7%AE%E5%80%BC/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
