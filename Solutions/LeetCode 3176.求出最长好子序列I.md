---
title: 3176.求出最长好子序列 I
date: 2024-09-07 09:26:20
tags: [题解, LeetCode, 中等, 数组, 哈希表, 动态规划, DP]
---

# 【LetMeFly】3176.求出最长好子序列 I：动态规划（DP）

力扣题目链接：[https://leetcode.cn/problems/find-the-maximum-length-of-a-good-subsequence-i/](https://leetcode.cn/problems/find-the-maximum-length-of-a-good-subsequence-i/)

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;和一个 <strong>非负</strong>&nbsp;整数&nbsp;<code>k</code>&nbsp;。如果一个整数序列&nbsp;<code>seq</code>&nbsp;满足在范围下标范围&nbsp;<code>[0, seq.length - 2]</code>&nbsp;中存在 <strong>不超过</strong>&nbsp;<code>k</code>&nbsp;个下标 <code>i</code>&nbsp;满足&nbsp;<code>seq[i] != seq[i + 1]</code>&nbsp;，那么我们称这个整数序列为&nbsp;<strong>好</strong>&nbsp;序列。</p>

<p>请你返回 <code>nums</code>&nbsp;中&nbsp;<strong>好</strong> <span data-keyword="subsequence-array">子序列</span>&nbsp;的最长长度</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,1,1,3], k = 2</span></p>

<p><span class="example-io"><b>输出：</b>4</span></p>

<p><strong>解释：</strong></p>

<p>最长好子序列为&nbsp;<code>[<em><strong>1</strong></em>,<em><strong>2</strong></em>,<strong><em>1</em></strong>,<em><strong>1</strong></em>,3]</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,3,4,5,1], k = 0</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><strong>解释：</strong></p>

<p>最长好子序列为&nbsp;<code>[<strong><em>1</em></strong>,2,3,4,5,<strong><em>1</em></strong>]</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 500</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= k &lt;= min(nums.length, 25)</code></li>
</ul>


    
## 解题方法：动态规划

使用一个动态规划数组$dp$，其中$dp[i][l]$代表数组前$i$个元素的不超过$l$个相邻不同的好子序列的最大长度。

初始值$dp[i][0]=1$，其余值默认为$-1$就行，转移方程：

$$dp[i][l] = \min \begin{cases}
dp[i][l] & \\
dp[j][l] + 1 & \text{ if } nums[i]=nums[j]\\
dp[j][l - 1] + 1 & \text{ if } nums[i] \neq nums[j] \text{ and } l \gt 0
\end{cases}$$

三层循环，第一层用$i$从$0$到$len(nums)-1$，第二层用$l$从$0$到$k$，第三层用$j$从$0$到$i-1$。

+ 时间复杂度$O(len(nums)^2\times k)$
+ 空间复杂度$O(len(nums)\times k)$

更低复杂度请见下一题：[求出最长好子序列 II](https://blog.letmefly.xyz/2024/09/07/LeetCode%203177.%E6%B1%82%E5%87%BA%E6%9C%80%E9%95%BF%E5%A5%BD%E5%AD%90%E5%BA%8F%E5%88%97II/)

### AC代码

#### C++

```cpp
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(nums.size(), vector<int>(k + 1, -1));
        for (int i = 0; i < nums.size(); i++) {
            dp[i][0] = 1;
            for (int l = 0; l <= k; l++) {
                for (int j = 0; j < i; j++) {
                    int diff = nums[i] != nums[j];
                    if (l - diff >= 0) {
                        dp[i][l] = max(dp[i][l], dp[j][l - diff] + 1);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int l = 0; l <= k; l++) {
                ans = max(ans, dp[i][l]);
            }
        }
        return ans;
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        dp = [[-1] * (k + 1) for _ in range(len(nums))]
        for i in range(len(nums)):
            dp[i][0] = 1
            for l in range(k + 1):
                for j in range(i):
                    diff = int(nums[i] != nums[j])
                    if l - diff >= 0:
                        dp[i][l] = max(dp[i][l], dp[j][l - diff] + 1)
        return max(max(dp[i]) for i in range(len(nums)))
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/09/07/LeetCode%203176.%E6%B1%82%E5%87%BA%E6%9C%80%E9%95%BF%E5%A5%BD%E5%AD%90%E5%BA%8F%E5%88%97I/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/141992543](https://letmefly.blog.csdn.net/article/details/141992543)
