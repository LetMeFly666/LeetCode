---
title: 3314.构造最小位运算数组 I：今日先简单题简单做-到II再优化
date: 2026-01-20 23:10:58
tags: [题解, LeetCode, 简单, 位运算, 数组, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】3314.构造最小位运算数组 I：今日先简单题简单做-到II再优化

力扣题目链接：[https://leetcode.cn/problems/construct-the-minimum-bitwise-array-i/](https://leetcode.cn/problems/construct-the-minimum-bitwise-array-i/)

<p>给你一个长度为 <code>n</code>&nbsp;的<span data-keyword="prime">质数</span>数组&nbsp;<code>nums</code>&nbsp;。你的任务是返回一个长度为 <code>n</code>&nbsp;的数组 <code>ans</code>&nbsp;，对于每个下标 <code>i</code>&nbsp;，以下<strong>&nbsp;条件</strong>&nbsp;均成立：</p>

<ul>
	<li><code>ans[i] OR (ans[i] + 1) == nums[i]</code></li>
</ul>

<p>除此以外，你需要 <strong>最小化</strong>&nbsp;结果数组里每一个&nbsp;<code>ans[i]</code>&nbsp;。</p>

<p>如果没法找到符合 <strong>条件</strong>&nbsp;的&nbsp;<code>ans[i]</code>&nbsp;，那么&nbsp;<code>ans[i] = -1</code>&nbsp;。</p>

<p><strong>质数</strong>&nbsp;指的是一个大于 1 的自然数，且它只有 1 和自己两个因数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [2,3,5,7]</span></p>

<p><span class="example-io"><b>输出：</b>[-1,1,4,3]</span></p>

<p><b>解释：</b></p>

<ul>
	<li>对于&nbsp;<code>i = 0</code>&nbsp;，不存在&nbsp;<code>ans[0]</code>&nbsp;满足&nbsp;<code>ans[0] OR (ans[0] + 1) = 2</code>&nbsp;，所以&nbsp;<code>ans[0] = -1</code>&nbsp;。</li>
	<li>对于&nbsp;<code>i = 1</code>&nbsp;，满足 <code>ans[1] OR (ans[1] + 1) = 3</code>&nbsp;的最小&nbsp;<code>ans[1]</code>&nbsp;为&nbsp;<code>1</code>&nbsp;，因为&nbsp;<code>1 OR (1 + 1) = 3</code>&nbsp;。</li>
	<li>对于&nbsp;<code>i = 2</code>&nbsp;，满足 <code>ans[2] OR (ans[2] + 1) = 5</code>&nbsp;的最小 <code>ans[2]</code>&nbsp;为&nbsp;<code>4</code>&nbsp;，因为&nbsp;<code>4 OR (4 + 1) = 5</code>&nbsp;。</li>
	<li>对于&nbsp;<code>i = 3</code>&nbsp;，满足&nbsp;<code>ans[3] OR (ans[3] + 1) = 7</code>&nbsp;的最小&nbsp;<code>ans[3]</code>&nbsp;为&nbsp;<code>3</code>&nbsp;，因为&nbsp;<code>3 OR (3 + 1) = 7</code>&nbsp;。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [11,13,31]</span></p>

<p><span class="example-io"><b>输出：</b>[9,12,15]</span></p>

<p><b>解释：</b></p>

<ul>
	<li>对于&nbsp;<code>i = 0</code>&nbsp;，满足&nbsp;<code>ans[0] OR (ans[0] + 1) = 11</code> 的最小&nbsp;<code>ans[0]</code>&nbsp;为&nbsp;<code>9</code>&nbsp;，因为&nbsp;<code>9 OR (9 + 1) = 11</code>&nbsp;。</li>
	<li>对于&nbsp;<code>i = 1</code>&nbsp;，满足&nbsp;<code>ans[1] OR (ans[1] + 1) = 13</code>&nbsp;的最小&nbsp;<code>ans[1]</code>&nbsp;为&nbsp;<code>12</code>&nbsp;，因为&nbsp;<code>12 OR (12 + 1) = 13</code>&nbsp;。</li>
	<li>对于&nbsp;<code>i = 2</code>&nbsp;，满足&nbsp;<code>ans[2] OR (ans[2] + 1) = 31</code>&nbsp;的最小&nbsp;<code>ans[2]</code>&nbsp;为&nbsp;<code>15</code>&nbsp;，因为&nbsp;<code>15 OR (15 + 1) = 31</code>&nbsp;。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>2 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code>nums[i]</code>&nbsp;是一个质数。</li>
</ul>


    
## 解题方法：模拟

> 今天就每个数$O(1)$的话，[明天的](https://blog.letmefly.xyz/2026/01/21/LeetCode%203315.%E6%9E%84%E9%80%A0%E6%9C%80%E5%B0%8F%E4%BD%8D%E8%BF%90%E7%AE%97%E6%95%B0%E7%BB%84II/)每日一题就没得做了。

对于一个数$n$，如何求得其对应的最小$ans$？

使用一个变量从$0$试到$n-1$就好了。

每个数都这样试试，也不用优化，今日的每日一题就这样结束了。

+ 时间复杂度$O(len(nums)\times\max(nums))$
+ 空间复杂度$O(1)$，力扣返回值不计入算法空间复杂度

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-01-20 22:52:17
 */
class Solution {
private:
    int get(int n) {
        for (int i = 0; i <= n; i++) {
            if ((i | (i + 1)) == n) {
                return i;
            }
        }
        return -1;
    }
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = get(nums[i]);
        }
        return ans;
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-01-20 22:55:49
'''
from typing import List

class Solution:
    def get(self, n: int) -> int:
        for i in range(n):
            if (i | (i + 1)) == n:  # 不是(i or (i + 1))
                return i
        return -1
    
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        return [self.get(t) for t in nums]
```

#### Java

```java
/*
 * @LastEditTime: 2026-01-20 23:04:56
 */
import java.util.List;

class Solution {
    private int get(int n) {
        for (int i = 0; i < n; i++) {
            if ((i | (i + 1)) == n) {
                return i;
            }
        }
        return -1;
    }

    public int[] minBitwiseArray(List<Integer> nums) {
        int[] ans = new int[nums.size()];  // 是size不是length
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = get(nums.get(i));
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2026-01-20 22:58:16
 */
package main

func minBitwiseArray(nums []int) []int {
    get := func(n int) int {
        for i := 0; i < n; i++ {
            if (i | (i + 1)) == n {
                return i
            }
        }
        return -1
    }
    ans := make([]int, len(nums))
    for i, n := range nums {
        ans[i] = get(n)
    }
    return ans
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-01-20 23:07:14
 */
impl Solution {
    fn get(n: i32) -> i32 {
        for i in 0..n {
            if (i | (i + 1)) == n {
                return i;
            }
        }
        -1
    }

    pub fn min_bitwise_array(nums: Vec<i32>) -> Vec<i32> {
        nums.iter().map(|&num| Self::get(num)).collect()
    }
}
```

#### Rust - 压缩版(bushi)

```rust
/*
 * @LastEditTime: 2026-01-20 23:09:46
 */
impl Solution {
    pub fn min_bitwise_array(nums: Vec<i32>) -> Vec<i32> {
        nums.iter()
            .map(|&n| {
                for i in 0..n {
                    if (i | (i + 1)) == n {
                        return i;
                    }
                }
                -1
            })
            .collect()
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/157185873)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/01/20/LeetCode%203314.%E6%9E%84%E9%80%A0%E6%9C%80%E5%B0%8F%E4%BD%8D%E8%BF%90%E7%AE%97%E6%95%B0%E7%BB%84I/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
