---
title: 976.三角形的最大周长：贪心(排序)
date: 2025-09-28 13:31:12
tags: [题解, LeetCode, 简单, 贪心, 数组, 数学, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】976.三角形的最大周长：贪心(排序)

力扣题目链接：[https://leetcode.cn/problems/largest-perimeter-triangle/](https://leetcode.cn/problems/largest-perimeter-triangle/)

<p>给定由一些正数（代表长度）组成的数组 <code>nums</code>&nbsp;，返回 <em>由其中三个长度组成的、<strong>面积不为零</strong>的三角形的最大周长</em>&nbsp;。如果不能形成任何面积不为零的三角形，返回&nbsp;<code>0</code>。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,1,2]
<strong>输出：</strong>5
<strong>解释：</strong>你可以用三个边长组成一个三角形:1 2 2。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,1,10]
<strong>输出：</strong>0
<strong>解释：</strong>
你不能用边长 1,1,2 来组成三角形。
不能用边长 1,1,10 来构成三角形。
不能用边长 1、2 和 10 来构成三角形。
因为我们不能用任何三条边长来构成一个非零面积的三角形，所以我们返回 0。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>


    
## 解题方法：排序

将边长排序，采用贪心思维，先看最长边能不能用上：

> 选中所有边中的最长边，在此前提下，另外两边之和需要大于最长边。并且我们希望三角形周长最长，我们应该怎么选另外两条边？
>
> 很简单，不用动脑子就知道，另外两条边就选剩下的边中最长的两条。
>
> + 如果另外两边之和大于最长边，则完美，最长的三条边可以组成三角形，那么选这三条边所组成的三角形周长一定最长；
>
> + 否则，很遗憾，没有任何剩下的两条边之和可以大于第一条选中的最长边，可以说明最长的那条边一定不会被选中，直接扔掉最长边。

如果发现最长边不能被用上，扔掉最长边，剩下的所有边仍然按照这个思路去挑选就好。

+ 时间复杂度$O(n\log n)$，其中$n=len(nums)$
+ 空间复杂度$O(\log n)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-09-28 13:21:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-28 13:22:32
 */
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 3; i >= 0; i--) {
            if (nums[i] + nums[i + 1] > nums[i + 2]) {
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }
        return 0;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-09-28 13:21:46
LastEditors: LetMeFly.xyz
LastEditTime: 2025-09-28 13:30:31
'''
from typing import List

class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort()
        for i in range(len(nums) - 3, -1, -1):
            if nums[i] + nums[i + 1] > nums[i + 2]:
                return nums[i] + nums[i + 1] + nums[i + 2]
        return 0
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-09-28 13:21:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-28 13:27:11
 */
import java.util.Arrays;

class Solution {
    public int largestPerimeter(int[] nums) {
        Arrays.sort(nums);
        for (int i = nums.length - 3; i >= 0; i--) {
            if (nums[i] + nums[i + 1] > nums[i + 2]) {
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }
        return 0;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-09-28 13:21:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-28 13:29:34
 */
package main

import "sort"

func largestPerimeter(nums []int) int {
    sort.Ints(nums)
    for i := len(nums) - 3; i >= 0; i-- {
        if nums[i] + nums[i + 1] > nums[i + 2] {
            return nums[i] + nums[i + 1] + nums[i + 2]
        }
    }
    return 0
}
```

#### Rust

```rust
/*
 * @Author: LetMeFly
 * @Date: 2025-09-28 13:21:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-28 13:25:57
 */
impl Solution {
    pub fn largest_perimeter(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        for i in (0..nums.len()-2).rev() {
            if nums[i] + nums[i + 1] > nums[i + 2] {
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }
        0
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/152215094)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/09/28/LeetCode%200976.%E4%B8%89%E8%A7%92%E5%BD%A2%E7%9A%84%E6%9C%80%E5%A4%A7%E5%91%A8%E9%95%BF/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
