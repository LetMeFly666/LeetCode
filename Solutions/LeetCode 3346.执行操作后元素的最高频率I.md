---
title: 3346.执行操作后元素的最高频率 I：滑动窗口（正好适合本题数据，II再另谋他法）
date: 2025-10-30 23:23:25
tags: [题解, LeetCode, 中等, 数组, 排序, 滑动窗口, 哈希表, map, 计数]
categories: [题解, LeetCode]
---

# 【LetMeFly】3346.执行操作后元素的最高频率 I：滑动窗口（正好适合本题数据，II再另某他法）

力扣题目链接：[https://leetcode.cn/problems/maximum-frequency-of-an-element-after-performing-operations-i/](https://leetcode.cn/problems/maximum-frequency-of-an-element-after-performing-operations-i/)

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;和两个整数&nbsp;<code>k</code> 和&nbsp;<code>numOperations</code>&nbsp;。</p>

<p>你必须对 <code>nums</code>&nbsp;执行 <strong>操作</strong>&nbsp; <code>numOperations</code>&nbsp;次。每次操作中，你可以：</p>

<ul>
	<li>选择一个下标&nbsp;<code>i</code>&nbsp;，它在之前的操作中 <strong>没有</strong>&nbsp;被选择过。</li>
	<li>将 <code>nums[i]</code>&nbsp;增加范围&nbsp;<code>[-k, k]</code>&nbsp;中的一个整数。</li>
</ul>

<p>在执行完所有操作以后，请你返回 <code>nums</code>&nbsp;中出现 <strong>频率最高</strong>&nbsp;元素的出现次数。</p>

<p>一个元素 <code>x</code>&nbsp;的 <strong>频率</strong>&nbsp;指的是它在数组中出现的次数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,4,5], k = 1, numOperations = 2</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><strong>解释：</strong></p>

<p>通过以下操作得到最高频率 2 ：</p>

<ul>
	<li>将&nbsp;<code>nums[1]</code>&nbsp;增加 0 ，<code>nums</code> 变为&nbsp;<code>[1, 4, 5]</code>&nbsp;。</li>
	<li>将&nbsp;<code>nums[2]</code>&nbsp;增加 -1 ，<code>nums</code> 变为&nbsp;<code>[1, 4, 4]</code>&nbsp;。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [5,11,20,20], k = 5, numOperations = 1</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><strong>解释：</strong></p>

<p>通过以下操作得到最高频率 2 ：</p>

<ul>
	<li>将 <code>nums[1]</code> 增加 0 。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= numOperations &lt;= nums.length</code></li>
</ul>


    
## 解题方法：滑动窗口

数组中元素顺序不影响结果，所以可以先对数组排个序。

统计每个数出现了多少次，然后从$nums$中最小值到最大值枚举$target$。对于一个$target$，计算将尽可能多的数变成$target$的话最终最多出现多少个$target$。

使用两个指针$l$和$r$，$l$指向数组中第一个可以变成$target$的元素，$r$指向第一个<span title="不是由于太大的话可能时由于太小">由于太大</span>而不可以变成$target$的元素。

$target$变化时，如有需要则不断右移$l$和$r$指针直到严格满足指针定义为止。

好了，我们得到了$nums[l, l + 1, l + 2, \dots, r - 1]$的共$r-l$个元素都能通过一次操作变成$target$，而题目限制最多进行$numOperations$次操作，前面哈希表的作用这不就来了吗。

通过哈希表可以快速得知已有$already$个$target$，相当于有$already$个元素不需要操作。所以最终最多能有$\min(r-l, numOperations+already)$个元素变成$target$。

+ 时间复杂度$O(len(nums)+\max(nums))$，而[最高频率I](https://leetcode.cn/problems/maximum-frequency-of-an-element-after-performing-operations-i)和[II](https://leetcode.cn/problems/maximum-frequency-of-an-element-after-performing-operations-ii/)的区别就在于$nums$的范围，本解法无法通过[最高频率II](https://leetcode.cn/problems/maximum-frequency-of-an-element-after-performing-operations-ii/)。
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2025-10-30 22:53:20
 */
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> frequency;
        for (int t : nums) {
            frequency[t]++;
        }
        int ans = 0;
        for (int l = 0, r = 0, target = nums[0]; target <= nums.back(); target++) {
            while (target - nums[l] > k) {
                l++;
            }
            while (r < nums.size() && nums[r] - target <= k) {
                r++;
            }
            ans = max(ans, min(r - l, numOperations + frequency[target]));
        }
        return ans;
    }
};
```

#### Python

```python
'''
LastEditTime: 2025-10-30 22:57:07
'''
from typing import List
from collections import Counter

class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        nums.sort()
        frequency = Counter(nums)
        l = r = 0
        ans = 0
        for target in range(nums[0], nums[-1] + 1):
            while target - nums[l] > k:
                l += 1
            while r < len(nums) and nums[r] - target <= k:
                r += 1
            ans = max(ans, min(r - l, numOperations + frequency[target]))
        return ans  # 刚刚差点忘记return
```

#### Java

```java
/*
 * @LastEditTime: 2025-10-30 23:07:34
 */
import java.util.Map;
import java.util.HashMap;
import java.util.Arrays;

class Solution {
    public int maxFrequency(int[] nums, int k, int numOperations) {
        Arrays.sort(nums);
        Map<Integer, Integer> frequency = new HashMap<>();
        for (int t : nums) {
            frequency.merge(t, 1, Integer::sum);  // 这个api挺容易忘的
        }
        int ans = 0, n = nums.length;
        for (int l = 0, r = 0, target = nums[0]; target <= nums[n - 1]; target++) {
            while (target - nums[l] > k) {
                l++;
            }
            while (r < n && nums[r] - target <= k) {
                r++;
            }
            ans = Math.max(ans, Math.min(r - l, numOperations + frequency.getOrDefault(target, 0)));
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2025-10-30 23:00:59
 */
package main

import "sort"

func maxFrequency(nums []int, k int, numOperations int) (ans int) {
    sort.Ints(nums)
    frequency := map[int]int{}
    for _, t := range nums {
        frequency[t]++
    }
    n := len(nums)
    for l, r, target := 0, 0, nums[0]; target <= nums[n - 1]; target++ {
        for target - nums[l] > k {
            l++
        }
        for r < n && nums[r] - target <= k {
            r++
        }
        ans = max(ans, min(r - l, numOperations + frequency[target]))
    }
    return
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2025-10-30 23:19:32
 */
use std::collections::HashMap;
// 这台机器上没有安装过rust，故无IDE语法检查了
impl Solution {
    pub fn max_frequency(mut nums: Vec<i32>, k: i32, num_operations: i32) -> i32 {
        nums.sort();
        let mut frequency = HashMap::new();
        for &t in &nums {
            *frequency.entry(t).or_insert(0) += 1;  // 不存在时默认值为0
        }
        
        let mut ans: i32 = 0;
        let mut l: usize = 0;
        let mut r: usize = 0;
        for target in nums[0]..=nums[nums.len()-1] {
            while target - nums[l] > k {
                l += 1;
            }
            while r < nums.len() && nums[r] - target <= k {
                r += 1;
            }
            ans = ans.max(((r - l) as i32).min(num_operations + *frequency.get(&target).unwrap_or(&0)));
        }
        ans
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/154155843)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/10/30/LeetCode%203346.%E6%89%A7%E8%A1%8C%E6%93%8D%E4%BD%9C%E5%90%8E%E5%85%83%E7%B4%A0%E7%9A%84%E6%9C%80%E9%AB%98%E9%A2%91%E7%8E%87I/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
