---
title: 3350.检测相邻递增子数组 II：将数组分成多段递增
date: 2025-10-15 22:33:56
tags: [题解, LeetCode, 中等, 数组, 遍历]
categories: [题解, LeetCode]
---

# 【LetMeFly】3350.检测相邻递增子数组 II：将数组分成多段递增

力扣题目链接：[https://leetcode.cn/problems/adjacent-increasing-subarrays-detection-ii/](https://leetcode.cn/problems/adjacent-increasing-subarrays-detection-ii/)

<p>给你一个由 <code>n</code> 个整数组成的数组 <code>nums</code> ，请你找出 <code>k</code> 的 <strong>最大值</strong>，使得存在 <strong>两个</strong> <strong>相邻</strong> 且长度为 <code>k</code> 的 <strong>严格递增</strong> <span data-keyword="subarray-nonempty">子数组</span>。具体来说，需要检查是否存在从下标 <code>a</code> 和 <code>b</code> (<code>a &lt; b</code>) 开始的 <strong>两个</strong> 子数组，并满足下述全部条件：</p>

<ul>
	<li>这两个子数组 <code>nums[a..a + k - 1]</code> 和 <code>nums[b..b + k - 1]</code> 都是 <strong>严格递增</strong> 的。</li>
	<li>这两个子数组必须是 <strong>相邻的</strong>，即 <code>b = a + k</code>。</li>
</ul>

<p>返回 <code>k</code> 的 <strong>最大可能 </strong>值。</p>

<p><strong>子数组</strong> 是数组中的一个连续<b> 非空</b> 的元素序列。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [2,5,7,8,9,2,3,4,3,1]</span></p>

<p><strong>输出：</strong><span class="example-io">3</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>从下标 2 开始的子数组是 <code>[7, 8, 9]</code>，它是严格递增的。</li>
	<li>从下标 5 开始的子数组是 <code>[2, 3, 4]</code>，它也是严格递增的。</li>
	<li>这两个子数组是相邻的，因此 3 是满足题目条件的 <strong>最大</strong> <code>k</code> 值。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [1,2,3,4,4,4,4,5,6,7]</span></p>

<p><strong>输出：</strong><span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>从下标 0 开始的子数组是 <code>[1, 2]</code>，它是严格递增的。</li>
	<li>从下标 2 开始的子数组是 <code>[3, 4]</code>，它也是严格递增的。</li>
	<li>这两个子数组是相邻的，因此 2 是满足题目条件的 <strong>最大</strong> <code>k</code> 值。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：一次遍历

数组`[2,5,7,8,9,2,3,4,3,1]`由四个递增数组组成：`[2,5,7,8,9]`、`[2,3,4]`、`[3]`、`[1]`，他们的长度分别是5、3、1、1。

1. 对于相邻的长度为5、3的递增数组，可以设置$k=min(5,3)=3$
2. 对于单个长度为5的递增数组，可以设置$k=\lfloor\frac52\rfloor$

一遍遍历更新并计算上述两个值中最大的那个作为答案。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2025-10-15 22:20:57
 */
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int ans = 0;
        for (int lastCnt = 0, nowCnt = 0, i = 0; i < nums.size(); i++) {
            nowCnt++;
            if (i == nums.size() - 1 || nums[i] >= nums[i + 1]) {  // 递增数组之尾
                ans = max({ans, min(lastCnt, nowCnt), nowCnt / 2});
                lastCnt = nowCnt, nowCnt = 0;
            }
        }
        return ans;
    }
};
```

#### C++ - 写法2

```cpp
/*
 * @LastEditTime: 2025-10-15 22:16:10
 */
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int ans = 1;
        int lastVal = 1000000001, lastCnt = 0, nowCnt = 0;
        for (int t : nums) {
            if (t <= lastVal) {
                ans = max(ans, min(lastCnt, nowCnt));
                ans = max(ans, nowCnt / 2);
                printf("ans = %d, t = %d, lastCnt = %d, nowCnt = %d\n", ans, t, lastCnt, nowCnt);
                lastCnt = nowCnt, nowCnt = 1;
            } else {
                nowCnt++;
            }
            lastVal = t;
        }
        return max({ans, min(lastCnt, nowCnt), nowCnt / 2});
    }
};
```

#### Python

```python
'''
LastEditTime: 2025-10-15 22:23:10
'''
from typing import List

class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        ans = lastCnt = nowCnt = 0
        for i in range(len(nums)):
            nowCnt += 1
            if i == len(nums) - 1 or nums[i] >= nums[i + 1]:
                ans = max(ans, min(lastCnt, nowCnt), nowCnt // 2)
                lastCnt = nowCnt
                nowCnt = 0
        return ans
```

#### Java

```java
/*
 * @LastEditTime: 2025-10-15 22:28:53
 */
class Solution {
    public int maxIncreasingSubarrays(List<Integer> nums) {
        int ans = 0;
        for (int i = 0, lastCnt = 0, nowCnt = 0; i < nums.size(); i++) {
            nowCnt++;
            if (i == nums.size() - 1 || nums.get(i) >= nums.get(i + 1)) {  // 昨天踩过的bug今天不会再踩一次
                ans = Math.max(ans, Math.max(Math.min(lastCnt, nowCnt), nowCnt / 2));
                lastCnt = nowCnt;
                nowCnt = 0;
            }
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2025-10-15 22:25:04
 */
package main

// 我发现nowCnt特别容易打成nowCNt
func maxIncreasingSubarrays(nums []int) int {
    ans, lastCnt, nowCnt := 0, 0, 0
    for i, t := range nums {
        nowCnt++
        if i == len(nums) - 1 || t >= nums[i + 1] {
            ans = max(ans, max(min(lastCnt, nowCnt), nowCnt / 2))
            lastCnt, nowCnt = nowCnt, 0
        }
    }
    return ans
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2025-10-15 22:32:24
 */
impl Solution {
    pub fn max_increasing_subarrays(nums: Vec<i32>) -> i32 {
        let mut ans: i32 = 0;
        let mut last_cnt: i32 = 0;
        let mut now_cnt: i32 = 0;
        for i in 0..nums.len() {
            now_cnt += 1;
            if i == nums.len() - 1 || nums[i] >= nums[i + 1] {
                ans = ans.max(last_cnt.min(now_cnt)).max(now_cnt / 2);
                // (last_cnt, now_cnt) = (now_cnt, 0);
                last_cnt = now_cnt;
                now_cnt = 0;
            }
        }
        ans
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/153350590)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/10/15/LeetCode%203350.%E6%A3%80%E6%B5%8B%E7%9B%B8%E9%82%BB%E9%80%92%E5%A2%9E%E5%AD%90%E6%95%B0%E7%BB%84II/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)

今天(2025.10.15)是我在CSDN的[2048天纪念日](https://app-blog.csdn.net/incentive?utm_medium=notify.im.blog_action.20251015.a&username=Tisfy)诶。