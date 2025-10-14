---
title: 3349.检测相邻递增子数组 I：既然是I，那就先暴力模拟吧
date: 2025-10-14 20:38:31
tags: [题解, LeetCode, 简单, 数组, 模拟, 暴力, 枚举]
categories: [题解, LeetCode]
---

# 【LetMeFly】3349.检测相邻递增子数组 I：既然是I，那就先暴力模拟吧

力扣题目链接：[https://leetcode.cn/problems/adjacent-increasing-subarrays-detection-i/](https://leetcode.cn/problems/adjacent-increasing-subarrays-detection-i/)

<p>给你一个由 <code>n</code> 个整数组成的数组 <code>nums</code> 和一个整数 <code>k</code>，请你确定是否存在 <strong>两个</strong> <strong>相邻</strong> 且长度为 <code>k</code> 的 <strong>严格递增</strong> 子数组。具体来说，需要检查是否存在从下标 <code>a</code> 和 <code>b</code> (<code>a &lt; b</code>) 开始的 <strong>两个</strong> 子数组，并满足下述全部条件：</p>

<ul>
	<li>这两个子数组 <code>nums[a..a + k - 1]</code> 和 <code>nums[b..b + k - 1]</code> 都是 <strong>严格递增</strong> 的。</li>
	<li>这两个子数组必须是 <strong>相邻的</strong>，即 <code>b = a + k</code>。</li>
</ul>

<p>如果可以找到这样的 <strong>两个</strong> 子数组，请返回 <code>true</code>；否则返回 <code>false</code>。</p>

<p><strong>子数组</strong> 是数组中的一个连续<b> 非空</b> 的元素序列。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [2,5,7,8,9,2,3,4,3,1], k = 3</span></p>

<p><strong>输出：</strong><span class="example-io">true</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>从下标 <code>2</code> 开始的子数组为 <code>[7, 8, 9]</code>，它是严格递增的。</li>
	<li>从下标 <code>5</code> 开始的子数组为 <code>[2, 3, 4]</code>，它也是严格递增的。</li>
	<li>两个子数组是相邻的，因此结果为 <code>true</code>。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [1,2,3,4,4,4,4,5,6,7], k = 5</span></p>

<p><strong>输出：</strong><span class="example-io">false</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= 2 * k &lt;= nums.length</code></li>
	<li><code>-1000 &lt;= nums[i] &lt;= 1000</code></li>
</ul>


    
## 解题方法：模拟

写一个函数`isOk`判断`nums`数组从下标`i`开始是否为`k`个连续递增的。

接着枚举每一个“两连续递增数组的起点下标”，判断这个下标开始是否为两个连续的`k`个递增数组。

+ 时间复杂度$O(nk)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2025-10-14 20:18:02
 */
class Solution {
private:
    inline bool isOk(vector<int>& nums, int i, int k) {
        while (--k) {
            if (nums[i] >= nums[++i]) {
                return false;
            } 
        }
        return true;
    }
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i + 2 * k <= n; i++) {
            if (isOk(nums, i, k) && isOk(nums, i + k, k)) {
                return true;
            }
        }
        return false;
    }
};
```

#### Python

```python
'''
LastEditTime: 2025-10-14 20:21:32
'''
from typing import List

# THIS IS NOT RIGHT
class Solution:
    def hasIncreasingSubarrays(self, nums: List[int], k: int) -> bool:
        for i in range(len(nums) - 2 * k + 1):
            if all(nums[j + 1] > nums[j] for j in range(i, i + k)) and all(nums[j + 1] > nums[j] for j in range(i + k, i + k * 2)):
                return True
        return False
```

#### Java

```java
/*
 * @LastEditTime: 2025-10-14 20:31:34
 */
class Solution {
    private boolean isOk(List<Integer> nums, int i, int k) {
        while (--k > 0) {
            if (nums.get(i) >= nums.get(++i)) {
                return false;
            }
        }
        return true;
    }

    public boolean hasIncreasingSubarrays(List<Integer> nums, int k) {
        for (int i = 0; i + 2 * k <= nums.size(); i++) {  // List没有length方法
            if (isOk(nums, i, k) && isOk(nums, i + k, k)) {
                return true;
            }
        }
        return false;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2025-10-14 20:26:58
 */
package main


func isOk3349(nums []int, i, k int) bool {
    for j := 0; j + 1 < k; j++ {
        if nums[i + j] >= nums[i + j + 1] {
            return false
        }
    }
    return true
}

func hasIncreasingSubarrays(nums []int, k int) bool {
    for i := 0; i + 2 * k <= len(nums); i++ {
        if isOk3349(nums, i, k) && isOk3349(nums, i + k, k) {
            return true
        }
    }
    return false
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2025-10-14 20:37:25
 */
impl Solution {
    fn is_ok(nums: &[i32], i: i32, k: i32) -> bool {
        for i in i..i+k-1 {
            if nums[i as usize] >= nums[(i + 1) as usize] {
                return false
            }
        }
        true
    }

    pub fn has_increasing_subarrays(nums: Vec<i32>, k: i32) -> bool {
        for i in 0..nums.len()+1-(2*k) as usize {
            if Self::is_ok(&nums, i as i32, k) && Self::is_ok(&nums, i as i32 + k, k) {
                return true
            }
        }
        false
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/153273993)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/10/14/LeetCode%203349.%E6%A3%80%E6%B5%8B%E7%9B%B8%E9%82%BB%E9%80%92%E5%A2%9E%E5%AD%90%E6%95%B0%E7%BB%84I/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
