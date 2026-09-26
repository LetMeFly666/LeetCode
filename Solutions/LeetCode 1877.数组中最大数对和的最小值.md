---
title: 1877.数组中最大数对和的最小值：排序
date: 2026-01-24 09:43:45
tags: [题解, LeetCode, 中等, 贪心, 数组, 双指针, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】1877.数组中最大数对和的最小值：排序

力扣题目链接：[https://leetcode.cn/problems/minimize-maximum-pair-sum-in-array/](https://leetcode.cn/problems/minimize-maximum-pair-sum-in-array/)

<p>一个数对 <code>(a,b)</code> 的 <strong>数对和</strong> 等于 <code>a + b</code> 。<strong>最大数对和</strong> 是一个数对数组中最大的 <strong>数对和</strong> 。</p>

<ul>
	<li>比方说，如果我们有数对 <code>(1,5)</code> ，<code>(2,3)</code> 和 <code>(4,4)</code>，<strong>最大数对和</strong> 为 <code>max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8</code> 。</li>
</ul>

<p>给你一个长度为 <strong>偶数</strong> <code>n</code> 的数组 <code>nums</code> ，请你将 <code>nums</code> 中的元素分成 <code>n / 2</code> 个数对，使得：</p>

<ul>
	<li><code>nums</code> 中每个元素 <strong>恰好</strong> 在 <strong>一个</strong> 数对中，且</li>
	<li><strong>最大数对和</strong> 的值 <strong>最小</strong> 。</li>
</ul>

<p>请你在最优数对划分的方案下，返回最小的 <strong>最大数对和</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [3,5,2,3]
<b>输出：</b>7
<b>解释：</b>数组中的元素可以分为数对 (3,3) 和 (5,2) 。
最大数对和为 max(3+3, 5+2) = max(6, 7) = 7 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [3,5,4,2,4,6]
<b>输出：</b>8
<b>解释：</b>数组中的元素可以分为数对 (3,5)，(4,4) 和 (6,2) 。
最大数对和为 max(3+5, 4+4, 6+2) = max(8, 8, 8) = 8 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>n</code> 是 <strong>偶数</strong> 。</li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法：排序

试想，对于最小的元素$a$，要和哪个元素组成一对呢？当然是要和最大的元素$b$组成一对。

> 否则，最大的元素$b$就要和比$a$可能更大的$c$组成一对，和肯定要更大（或持平）。

处理完最小元素$a$和最大元素$b$，剩下元素也同理，每次将剩下的最小元素和最大元素配对即可。

> 这种不限制远近任意组合成对的题目，排序是不会影响顺序的。我们可以对`nums`排个序。

+ 时间复杂度$O(n\log n)$
+ 空间复杂度$O(\log n)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-01-24 09:30:46
 */
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() / 2; i++) {
            ans = max(ans, nums[i] + nums[nums.size() - i - 1]);
        }
        return ans;
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-01-24 09:36:17
'''
from typing import List

class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        nums.sort()
        return max(nums[i] + nums[~i] for i in range(len(nums) // 2))
```

#### Java

```java
/*
 * @LastEditTime: 2026-01-24 09:39:41
 */
import java.util.Arrays;

class Solution {
    public int minPairSum(int[] nums) {
        Arrays.sort(nums);
        int ans = 0;
        for (int i = 0; i < nums.length / 2; i++) {
            ans = Math.max(ans, nums[i] + nums[nums.length - i - 1]);
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2026-01-24 09:34:40
 */
package main

import "sort"

func minPairSum(nums []int) (ans int) {
    sort.Ints(nums)
    for i := 0; i < len(nums) / 2; i++ {
        ans = max(ans, nums[i] + nums[len(nums) - i - 1])
    }
    return
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-01-24 09:37:33
 */
impl Solution {
    pub fn min_pair_sum(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        let mut ans = 0;
        for i in 0..nums.len() / 2 {
            ans = ans.max(nums[i] + nums[nums.len() - i - 1]);
        }
        ans
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/157333871)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/01/24/LeetCode%201877.%E6%95%B0%E7%BB%84%E4%B8%AD%E6%9C%80%E5%A4%A7%E6%95%B0%E5%AF%B9%E5%92%8C%E7%9A%84%E6%9C%80%E5%B0%8F%E5%80%BC/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
