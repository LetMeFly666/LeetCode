---
title: 1984.学生分数的最小差值：排序(类似滑动窗口)
date: 2026-01-25 10:55:40
tags: [题解, LeetCode, 简单, 数组, 排序, 滑动窗口]
categories: [题解, LeetCode]
---

# 【LetMeFly】1984.学生分数的最小差值：排序(类似滑动窗口)

力扣题目链接：[https://leetcode.cn/problems/minimum-difference-between-highest-and-lowest-of-k-scores/](https://leetcode.cn/problems/minimum-difference-between-highest-and-lowest-of-k-scores/)

<p>给你一个 <strong>下标从 0 开始</strong> 的整数数组 <code>nums</code> ，其中 <code>nums[i]</code> 表示第 <code>i</code> 名学生的分数。另给你一个整数 <code>k</code> 。</p>

<p>从数组中选出任意 <code>k</code> 名学生的分数，使这 <code>k</code> 个分数间 <strong>最高分</strong> 和 <strong>最低分</strong> 的 <strong>差值</strong> 达到<strong> 最小化</strong> 。</p>

<p>返回可能的 <strong>最小差值</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [90], k = 1
<strong>输出：</strong>0
<strong>解释：</strong>选出 1 名学生的分数，仅有 1 种方法：
- [<em><strong>90</strong></em>] 最高分和最低分之间的差值是 90 - 90 = 0
可能的最小差值是 0
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [9,4,1,7], k = 2
<strong>输出：</strong>2
<strong>解释：</strong>选出 2 名学生的分数，有 6 种方法：
- [<em><strong>9</strong></em>,<em><strong>4</strong></em>,1,7] 最高分和最低分之间的差值是 9 - 4 = 5
- [<em><strong>9</strong></em>,4,<em><strong>1</strong></em>,7] 最高分和最低分之间的差值是 9 - 1 = 8
- [<em><strong>9</strong></em>,4,1,<em><strong>7</strong></em>] 最高分和最低分之间的差值是 9 - 7 = 2
- [9,<em><strong>4</strong></em>,<em><strong>1</strong></em>,7] 最高分和最低分之间的差值是 4 - 1 = 3
- [9,<em><strong>4</strong></em>,1,<em><strong>7</strong></em>] 最高分和最低分之间的差值是 7 - 4 = 3
- [9,4,<em><strong>1</strong></em>,<em><strong>7</strong></em>] 最高分和最低分之间的差值是 7 - 1 = 6
可能的最小差值是 2</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= nums.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法：排序

将$nums$排序，返回所有长度为$k$的子数组中$diff(last, first)$的最小值即可。

+ 时间复杂度$O(N^2)$
+ 空间复杂度$O(N\log N)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-01-25 10:33:04
 */
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 100000;
        for (int i = 0; i + k - 1 < nums.size(); i++) {
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }
        return ans;
    }
};
```


#### Python

```python
'''
LastEditTime: 2026-01-25 10:37:04
'''
from typing import List

class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        nums.sort()
        return min(nums[i + k - 1] - nums[i] for i in range(len(nums) - k + 1))
```

#### Java

```java
/*
 * @LastEditTime: 2026-01-25 10:40:30
 */
import java.util.Arrays;

class Solution {
    public int minimumDifference(int[] nums, int k) {
        int ans = 100000;
        Arrays.sort(nums);
        for (int i = 0; i + k - 1 < nums.length; i++) {
            ans = Math.min(ans, nums[i + k - 1] - nums[i]);
        }
        return ans;
    }
}
```


#### Go

```go
/*
 * @LastEditTime: 2026-01-25 10:39:56
 */
package main

import "sort"

func minimumDifference(nums []int, k int) int {
	ans := 100000
    sort.Ints(nums)
	for i := 0; i < len(nums) - k + 1; i++ {
		ans = min(ans, nums[i + k - 1] - nums[i])
	}
	return ans
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-01-25 10:43:39
 */
impl Solution {
    pub fn minimum_difference(mut nums: Vec<i32>, k: i32) -> i32 {
        let k = k as usize;
        let mut ans = 100000;
        nums.sort();
        for i in 0..nums.len() - k + 1 {
            ans = ans.min(nums[i + k - 1] - nums[i]);
        }
        ans
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/157362645)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/01/25/LeetCode%201984.%E5%AD%A6%E7%94%9F%E5%88%86%E6%95%B0%E7%9A%84%E6%9C%80%E5%B0%8F%E5%B7%AE%E5%80%BC/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
