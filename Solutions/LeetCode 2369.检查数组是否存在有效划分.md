---
title: 2369.检查数组是否存在有效划分
date: 2024-03-01 20:07:17
tags: [题解, LeetCode, 中等, 数组, 动态规划, DP]
categories: [题解, LeetCode]
---

# 【LetMeFly】2369.检查数组是否存在有效划分：动态规划(DP)

力扣题目链接：[https://leetcode.cn/problems/check-if-there-is-a-valid-partition-for-the-array/](https://leetcode.cn/problems/check-if-there-is-a-valid-partition-for-the-array/)

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> ，你必须将数组划分为一个或多个 <strong>连续</strong> 子数组。</p>

<p>如果获得的这些子数组中每个都能满足下述条件<strong> 之一</strong> ，则可以称其为数组的一种 <strong>有效</strong> 划分：</p>

<ol>
	<li>子数组 <strong>恰</strong> 由 <code>2</code> 个相等元素组成，例如，子数组 <code>[2,2]</code> 。</li>
	<li>子数组 <strong>恰</strong> 由 <code>3</code> 个相等元素组成，例如，子数组 <code>[4,4,4]</code> 。</li>
	<li>子数组 <strong>恰</strong> 由 <code>3</code> 个连续递增元素组成，并且相邻元素之间的差值为 <code>1</code> 。例如，子数组 <code>[3,4,5]</code> ，但是子数组 <code>[1,3,5]</code> 不符合要求。</li>
</ol>

<p>如果数组 <strong>至少</strong> 存在一种有效划分，返回 <code>true</code><em> </em>，否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,4,4,5,6]
<strong>输出：</strong>true
<strong>解释：</strong>数组可以划分成子数组 [4,4] 和 [4,5,6] 。
这是一种有效划分，所以返回 true 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,1,2]
<strong>输出：</strong>false
<strong>解释：</strong>该数组不存在有效划分。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>


    
## 方法一：动态规划(DP)

使用一个布尔类型的```dp```数组，其中```dp[i + 1]```表示“数组```nums```的从```0```到```i```子数组”是否能被划分。

初始值```dp[0] = True```，其余```dp[i] = False```。

我们只需要遍历```nums```数组：

> + 若```dp[(i + 1) - 2]```为```True```且```nums[i] = nums[i - 1]```，则```nums```可在```[0, 1, ..., i - 2]```的基础上拼接一个```[i - 1, i]```，因此```dp[i + 1] = True```。
> + 若```dp[(i + 1) - 3]```为```True```且```nums[i] = nums[i - 1] = nums[i - 2]```或```nums[i] = nums[i - 1] + 1 = nums[i - 2] + 2```，则则```nums```可在```[0, 1, ..., i - 3]```的基础上拼接一个```[i - 2, i - 1, i]```，因此```dp[i + 1] = True```。

最终返回```dp```的最后一个元素即为答案。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(len(nums))$

优化空间：

1. 可以发现我们至多用到DP数组中的最近3个元素，因此我们可以使用三个变量来“滚动”，这样空间复杂度能变为$O(1)$。
2. 当最近三个DP元素均为```False```时，该数组将“永无重见天日之时”，可直接返回```False```。

### AC代码

#### C++

```cpp
class Solution {
public:
    bool validPartition(vector<int>& nums) {
        vector<bool> dp(nums.size() + 1);
        dp[0] = true;
        for (int i = 0; i < nums.size(); i++) {
            if (i + 1 - 2 >= 0 && dp[i + 1 - 2] && nums[i] == nums[i - 1]) {
                dp[i + 1] = true;
            }
            if (i + 1 - 3 >= 0 && dp[i + 1 - 3] && ((nums[i] == nums[i - 1] && nums[i] == nums[i - 2] || nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2))) {
                dp[i + 1] = true;
            }
        }
        return dp.back();
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def validPartition(self, nums: List[int]) -> bool:
        dp = [False] * (len(nums) + 1)
        dp[0] = True
        for i in range(len(nums)):
            if i + 1 - 2 >= 0 and dp[i + 1 - 2] and nums[i] == nums[i - 1]:
                dp[i + 1] = True
            if i + 1 - 3 >= 0 and dp[i + 1 - 3] and (nums[i] == nums[i - 1] == nums[i - 2] or nums[i] == nums[i - 1] + 1 == nums[i - 2] + 2):
                dp[i + 1] = True
        return dp[-1]
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/03/01/LeetCode%202369.%E6%A3%80%E6%9F%A5%E6%95%B0%E7%BB%84%E6%98%AF%E5%90%A6%E5%AD%98%E5%9C%A8%E6%9C%89%E6%95%88%E5%88%92%E5%88%86/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136405114](https://letmefly.blog.csdn.net/article/details/136405114)
