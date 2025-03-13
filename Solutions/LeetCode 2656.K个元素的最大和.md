---
title: 2656.K 个元素的最大和
date: 2023-11-15 20:30:04
tags: [题解, LeetCode, 简单, 贪心, 数组]
categories: [题解, LeetCode]
---

# 【LetMeFly】2656.K 个元素的最大和：一次遍历（附Python一行版代码）

力扣题目链接：[https://leetcode.cn/problems/maximum-sum-with-exactly-k-elements/](https://leetcode.cn/problems/maximum-sum-with-exactly-k-elements/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code> 和一个整数&nbsp;<code>k</code>&nbsp;。你需要执行以下操作<strong>&nbsp;恰好</strong> <code>k</code>&nbsp;次，最大化你的得分：</p>

<ol>
	<li>从 <code>nums</code>&nbsp;中选择一个元素&nbsp;<code>m</code>&nbsp;。</li>
	<li>将选中的元素&nbsp;<code>m</code>&nbsp;从数组中删除。</li>
	<li>将新元素&nbsp;<code>m + 1</code>&nbsp;添加到数组中。</li>
	<li>你的得分增加&nbsp;<code>m</code>&nbsp;。</li>
</ol>

<p>请你返回执行以上操作恰好 <code>k</code>&nbsp;次后的最大得分。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,3,4,5], k = 3
<b>输出：</b>18
<b>解释：</b>我们需要从 nums 中恰好选择 3 个元素并最大化得分。
第一次选择 5 。和为 5 ，nums = [1,2,3,4,6] 。
第二次选择 6 。和为 6 ，nums = [1,2,3,4,7] 。
第三次选择 7 。和为 5 + 6 + 7 = 18 ，nums = [1,2,3,4,8] 。
所以我们返回 18 。
18 是可以得到的最大答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [5,5,5], k = 2
<b>输出：</b>11
<b>解释：</b>我们需要从 nums 中恰好选择 2 个元素并最大化得分。
第一次选择 5 。和为 5 ，nums = [5,5,6] 。
第二次选择 6 。和为 6 ，nums = [5,5,7] 。
所以我们返回 11 。
11 是可以得到的最大答案。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
	<li><code>1 &lt;= k &lt;= 100</code></li>
</ul>


    
## 方法一：一次遍历

1. 想要使和最大，每次操作肯定选**最大值**
2. 每次操作后最大值都会更大

因此，我们只需要遍历一遍数组找到数组中元素的最大值，假设为$M$，则返回等差数列$M, M + 1, M + 2, \cdots, M + k - 1$（共$k$项）之和$k\frac{M + (M + k - 1)}{2}$即为答案。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int M = nums[0];
        for (int t : nums) {
            M = max(M, t);
        }
        return k * (M + M + k - 1) / 2;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def maximizeSum(self, nums: List[int], k: int) -> int:
        return k * (max(nums) * 2 + k - 1) // 2
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/11/15/LeetCode%202656.K%E4%B8%AA%E5%85%83%E7%B4%A0%E7%9A%84%E6%9C%80%E5%A4%A7%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/134429024](https://letmefly.blog.csdn.net/article/details/134429024)
