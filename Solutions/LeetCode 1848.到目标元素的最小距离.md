---
title: 1848.到目标元素的最小距离：数组遍历(附python一行版)
date: 2026-04-13 22:00:02
tags: [题解, LeetCode, 简单, 数组]
categories: [题解, LeetCode]
---

# 【LetMeFly】1848.到目标元素的最小距离：数组遍历(附python一行版)

力扣题目链接：[https://leetcode.cn/problems/minimum-distance-to-the-target-element/](https://leetcode.cn/problems/minimum-distance-to-the-target-element/)

<p>给你一个整数数组 <code>nums</code> （下标 <strong>从 0 开始</strong> 计数）以及两个整数 <code>target</code> 和 <code>start</code> ，请你找出一个下标 <code>i</code> ，满足 <code>nums[i] == target</code> 且 <code>abs(i - start)</code> <strong>最小化</strong> 。注意：<code>abs(x)</code> 表示 <code>x</code> 的绝对值。</p>

<p>返回 <code>abs(i - start)</code> 。</p>

<p>题目数据保证 <code>target</code> 存在于 <code>nums</code> 中。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4,5], target = 5, start = 3
<strong>输出：</strong>1
<strong>解释：</strong>nums[4] = 5 是唯一一个等于 target 的值，所以答案是 abs(4 - 3) = 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1], target = 1, start = 0
<strong>输出：</strong>0
<strong>解释：</strong>nums[0] = 1 是唯一一个等于 target 的值，所以答案是 abs(0 - 0) = 0 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,1,1,1,1,1,1,1,1], target = 1, start = 0
<strong>输出：</strong>0
<strong>解释：</strong>nums 中的每个值都是 1 ，但 nums[0] 使 abs(i - start) 的结果得以最小化，所以答案是 abs(0 - 0) = 0 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 1000</code></li>
	<li><code>1 <= nums[i] <= 10<sup>4</sup></code></li>
	<li><code>0 <= start < nums.length</code></li>
	<li><code>target</code> 存在于 <code>nums</code> 中</li>
</ul>


    
## 解题方法：遍历

遍历一遍数组，如果当前元素和`target`相等，就更新`ans`关于`abs(i - start)`的最小值。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

也可从$start$开始往左右遍历，遍历到一个就停止（需注意边界case）。

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-04-13 21:40:13
 */
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = nums.size();
        for (int i = 0, n = nums.size(); i < n; i++) {
            if (nums[i] == target) {
                ans = min(ans, abs(i - start));
            }
        }
        return ans;
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-04-13 21:41:57
'''
from typing import List

class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        return min(abs(i - start) for i, v in enumerate(nums) if v == target)
```

#### Java

```java
/*
 * @LastEditTime: 2026-04-13 21:44:45
 */
class Solution {
    public int getMinDistance(int[] nums, int target, int start) {
        int ans = nums.length;
        for (int i = 0, n = nums.length; i < n; i++) {
            if (nums[i] == target) {
                ans = Math.min(ans, Math.abs(i - start));
            }
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2026-04-13 21:44:01
 */
package main

func abs1848(a int) int {
    if a >= 0 {
        return a
    }
    return -a
}

func getMinDistance(nums []int, target int, start int) int {
    ans := len(nums)
    for i, v := range nums {
        if v == target {
            ans = min(ans, abs1848(i - start))
        }
    }
    return ans
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-04-13 21:46:02
 */
impl Solution {
    pub fn get_min_distance(nums: Vec<i32>, target: i32, start: i32) -> i32 {
        let mut ans = nums.len() as i32;
        for i in 0..nums.len() {
            if nums[i] == target {
                ans = ans.min((i as i32 - start).abs());
            }
        }
        ans
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/160123059)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/04/13/LeetCode%201848.%E5%88%B0%E7%9B%AE%E6%A0%87%E5%85%83%E7%B4%A0%E7%9A%84%E6%9C%80%E5%B0%8F%E8%B7%9D%E7%A6%BB/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
