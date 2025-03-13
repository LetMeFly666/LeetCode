---
title: 1027.最长等差数列
date: 2023-04-22 09:50:37
tags: [题解, LeetCode, 中等, 数组, 哈希表, 哈希, map, 二分查找, 动态规划, 等差数列]
categories: [题解, LeetCode]
---

# 【LetMeFly】1027.最长等差数列

力扣题目链接：[https://leetcode.cn/problems/longest-arithmetic-subsequence/](https://leetcode.cn/problems/longest-arithmetic-subsequence/)

<p>给你一个整数数组&nbsp;<code>nums</code>，返回 <code>nums</code>&nbsp;中最长等差子序列的<strong>长度</strong>。</p>

<p>回想一下，<code>nums</code> 的子序列是一个列表&nbsp;<code>nums[i<sub>1</sub>], nums[i<sub>2</sub>], ..., nums[i<sub>k</sub>]</code> ，且&nbsp;<code>0 &lt;= i<sub>1</sub> &lt; i<sub>2</sub> &lt; ... &lt; i<sub>k</sub> &lt;= nums.length - 1</code>。并且如果&nbsp;<code>seq[i+1] - seq[i]</code>(&nbsp;<code>0 &lt;= i &lt; seq.length - 1</code>) 的值都相同，那么序列&nbsp;<code>seq</code>&nbsp;是等差的。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,6,9,12]
<strong>输出：</strong>4
<strong>解释： </strong>
整个数组是公差为 3 的等差数列。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [9,4,7,2,10]
<strong>输出：</strong>3
<strong>解释：</strong>
最长的等差子序列是 [4,7,10]。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [20,1,15,3,10,5,8]
<strong>输出：</strong>4
<strong>解释：</strong>
最长的等差子序列是 [20,15,10,5]。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 500</code></li>
</ul>


    
## 方法一：枚举公差（哈希表）

首先预处理遍历一遍数组，找到数组中的最大值和最小值，最大值和最小值之差记为$diff$。那么，等差数列的公差一定在$[-diff, diff]$之间。

枚举每一个可能的$diff$。当公差枚举到$d$时：

使用一个哈希表$ma$，其中$ma[n]$代表公差为$d$时，以$n$结尾的等差数组的**现有长度**。

这样，我们只需要遍历原始数组，当我们遍历到$n$时，如果$n-d$已经在哈希表中，那么$n$就可以添加到$n-d$结尾的哈希表的末尾（长度为原有长度加一）；反之，$n$必须自己打头开始作为一个等差数列的首项（长度为1）

+ 时间复杂度$O(len(nums)\times (\max(nums)+\min(nums)))$（时间复杂度中max(nums)-min(nums)的复杂度取决于二者较大的一个）
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int ans = 2;
        auto minmax = minmax_element(nums.begin(), nums.end());
        int diff = *minmax.second - *minmax.first;
        for (int d = -diff; d <= diff; d++) {  // 要从-diff开始
            unordered_map<int, int> ma;
            for (int num : nums) {
                int thisAns;  // 其实可以直接 int thisAns = ma[num - d] + 1
                if (ma.count(num - d)) {
                    thisAns = ma[num - d] + 1;
                }
                else {
                    thisAns = 1;
                }
                ma[num] = thisAns;
                ans = max(ans, thisAns);
            }
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def longestArithSeqLength(self, nums: List[int]) -> int:
        ans = 2
        diff = max(nums) - min(nums)
        for d in range(-diff, diff + 1):
            mp = dict()
            for num in nums:
                if num - d in mp:
                    thisAns = mp[num - d] + 1
                else:
                    thisAns = 1
                mp[num] = thisAns
                ans = max(ans, thisAns)
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/04/22/LeetCode%201027.%E6%9C%80%E9%95%BF%E7%AD%89%E5%B7%AE%E6%95%B0%E5%88%97/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130301122](https://letmefly.blog.csdn.net/article/details/130301122)
