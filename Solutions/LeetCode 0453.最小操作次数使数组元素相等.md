---
title: 453.最小操作次数使数组元素相等：两次遍历（反向思维）
date: 2026-11-01 11:02:44
tags: [题解, LeetCode, 中等, 数组, 数学, 遍历]
categories: [题解, LeetCode]
---

# 【LetMeFly】453.最小操作次数使数组元素相等：两次遍历（反向思维）

力扣题目链接：[https://leetcode.cn/problems/minimum-moves-to-equal-array-elements/](https://leetcode.cn/problems/minimum-moves-to-equal-array-elements/)

<p>给你一个长度为 <code>n</code> 的整数数组，每次操作将会使 <code>n - 1</code> 个元素增加 <code>1</code> 。返回让数组所有元素相等的最小操作次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3]
<strong>输出：</strong>3
<strong>解释：</strong>
只需要3次操作（注意每次操作会增加两个元素的值）：
[1,2,3]  =&gt;  [2,3,3]  =&gt;  [3,4,3]  =&gt;  [4,4,4]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,1]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li>答案保证符合 <strong>32-bit</strong> 整数</li>
</ul>


    
## 解题方法：遍历

想要使所有数相等，每次操作会使$n-1$个数$+1$，等价于每次操作会使得$1$个数$-1$。

首先遍历一遍数组得到最小元素，再遍历一遍数组将每个元素与最小元素的差值累加即为答案。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-11-01 10:58:17
 */
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int m = nums[0];
        for (int t : nums) {
            m = min(m, t);
        }
        int ans = 0;
        for (int t : nums) {
            ans += t - m;
        }
        return ans;
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-11-01 11:00:17
'''
from typing import List

class Solution:
    def minMoves(self, nums: List[int]) -> int:
        m = min(nums)
        return sum(t - m for t in nums)
```

#### Java

```java
/*
 * @LastEditTime: 2026-11-01 11:01:07
 */
class Solution {
    public int minMoves(int[] nums) {
        int m = nums[0];
        for (int t : nums) {
            m = Math.min(m, t);
        }
        int ans = 0;
        for (int t : nums) {
            ans += t - m;
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2026-11-01 10:59:44
 */
package main

func minMoves(nums []int) (ans int) {
    m := nums[0]
    for _, t := range nums {
        m = min(t, m)
    }
    for _, t := range nums {
        ans += t - m
    }
    return
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-11-01 11:01:46
 */
impl Solution {
    pub fn min_moves(nums: Vec<i32>) -> i32 {
        let mut m = nums[0];
        for &t in nums.iter() {
            m = m.min(t);
        }
        let mut ans = 0;
        for &t in nums.iter() {
            ans += t - m;
        }
        ans
    }
}
```

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/169734689)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/11/01/LeetCode%200453.%E6%9C%80%E5%B0%8F%E6%93%8D%E4%BD%9C%E6%AC%A1%E6%95%B0%E4%BD%BF%E6%95%B0%E7%BB%84%E5%85%83%E7%B4%A0%E7%9B%B8%E7%AD%89/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
