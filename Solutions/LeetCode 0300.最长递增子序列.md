---
title: 300.最长递增子序列
date: 2022-12-10 11:44:00
tags: [题解, LeetCode, 中等, 数组, 二分查找, 动态规划, dp, 最x子xx, 最长子序列]
---

# 【LetMeFly】300.最长递增子序列

力扣题目链接：[https://leetcode.cn/problems/longest-increasing-subsequence/](https://leetcode.cn/problems/longest-increasing-subsequence/)

<p>给你一个整数数组 <code>nums</code> ，找到其中最长严格递增子序列的长度。</p>

<p><strong>子序列&nbsp;</strong>是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，<code>[3,6,2,7]</code> 是数组 <code>[0,3,1,6,2,2,7]</code> 的子序列。</p>
&nbsp;

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [10,9,2,5,3,7,101,18]
<strong>输出：</strong>4
<strong>解释：</strong>最长递增子序列是 [2,3,7,101]，因此长度为 4 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,1,0,3,2,3]
<strong>输出：</strong>4
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [7,7,7,7,7,7,7]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2500</code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<p>&nbsp;</p>

<p><b>进阶：</b></p>

<ul>
	<li>你能将算法的时间复杂度降低到&nbsp;<code>O(n log(n))</code> 吗?</li>
</ul>


    
## 方法一：动态规划

开辟一个大小为$n+1$的数组（其中$n=len(nums)$）$dp$

其中$dp[i]$代表$nums$中，以$nums[i]$结尾的最长子序列的长度。

那么，对于$dp[i]$，我们很容易给出状态转移方程：

$dp[i] = \max_{j<i}(dp[j] + 1, dp[i])$

也就是说，$nums[j]<nums[i]$的话，以$nums[i]$结尾的最长子序列，可由“以$nums[j]$结尾的最长子序列”加上$nums[j]$得到

最终返回$dp$数组中的最大值，即为以$nums$中某个元素结尾的 最长子序列 的长度。

+ 时间复杂度$O(len(nums)^2)$
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/12/10/LeetCode%200300.%E6%9C%80%E9%95%BF%E9%80%92%E5%A2%9E%E5%AD%90%E5%BA%8F%E5%88%97/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128263490](https://letmefly.blog.csdn.net/article/details/128263490)
