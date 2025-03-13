---
title: 3065.超过阈值的最少操作数 I
date: 2025-01-14 12:34:16
tags: [题解, LeetCode, 简单, 数组, 遍历]
categories: [题解, LeetCode]
---

# 【LetMeFly】3065.超过阈值的最少操作数 I：遍历统计

力扣题目链接：[https://leetcode.cn/problems/minimum-operations-to-exceed-threshold-value-i/](https://leetcode.cn/problems/minimum-operations-to-exceed-threshold-value-i/)

<p>给你一个下标从 <b>0</b>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;。</p>

<p>一次操作中，你可以删除 <code>nums</code>&nbsp;中的最小元素。</p>

<p>你需要使数组中的所有元素都大于或等于 <code>k</code>&nbsp;，请你返回需要的 <strong>最少</strong>&nbsp;操作次数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [2,11,10,1,3], k = 10
<b>输出：</b>3
<b>解释：</b>第一次操作后，nums 变为 [2, 11, 10, 3] 。
第二次操作后，nums 变为 [11, 10, 3] 。
第三次操作后，nums 变为 [11, 10] 。
此时，数组中的所有元素都大于等于 10 ，所以我们停止操作。
使数组中所有元素都大于等于 10 需要的最少操作次数为 3 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,1,2,4,9], k = 1
<b>输出：</b>0
<b>解释：</b>数组中的所有元素都大于等于 1 ，所以不需要对 nums 做任何操作。</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [1,1,2,4,9], k = 9
<b>输出：</b>4
<b>解释：</b>nums 中只有一个元素大于等于 9 ，所以需要执行 4 次操作。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
	<li>输入保证至少有一个满足&nbsp;<code>nums[i] &gt;= k</code>&nbsp;的下标&nbsp;<code>i</code>&nbsp;存在。</li>
</ul>


    
## 解题方法：遍历统计

遍历数组，若当前元素小于`k`，则答案数量加一。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for (int t : nums) {
            ans += t < k;
        }
        return ans;
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        return sum(t < k for t in nums)
```

#### Java

```java
class Solution {
    public int minOperations(int[] nums, int k) {
        int ans = 0;
        for (int t : nums) {
            if (t < k) {
                ans++;
            }
        }
        return ans;
    }
}
```

#### Go

```go
package main

func minOperations(nums []int, k int) (ans int) {
    for _, t := range nums {
        if t < k {
            ans++
        }
    }
    return
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/01/14/LeetCode%203065.%E8%B6%85%E8%BF%87%E9%98%88%E5%80%BC%E7%9A%84%E6%9C%80%E5%B0%91%E6%93%8D%E4%BD%9C%E6%95%B0I/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/145136167](https://letmefly.blog.csdn.net/article/details/145136167)
