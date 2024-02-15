---
title: 377.组合总和 Ⅳ
date: 2022-10-10 20:18:40
tags: [题解, LeetCode, 中等, 数组, 动态规划, dp]
---

# 【LetMeFly】377.组合总和 Ⅳ

力扣题目链接：[https://leetcode.cn/problems/combination-sum-iv/](https://leetcode.cn/problems/combination-sum-iv/)

<p>给你一个由 <strong>不同</strong> 整数组成的数组 <code>nums</code> ，和一个目标整数 <code>target</code> 。请你从 <code>nums</code> 中找出并返回总和为 <code>target</code> 的元素组合的个数。</p>

<p>题目数据保证答案符合 32 位整数范围。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3], target = 4
<strong>输出：</strong>7
<strong>解释：</strong>
所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
请注意，顺序不同的序列被视作不同的组合。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [9], target = 3
<strong>输出：</strong>0
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 200</code></li>
	<li><code>1 <= nums[i] <= 1000</code></li>
	<li><code>nums</code> 中的所有元素 <strong>互不相同</strong></li>
	<li><code>1 <= target <= 1000</code></li>
</ul>

<p> </p>

<p><strong>进阶：</strong>如果给定的数组中含有负数会发生什么？问题会产生何种变化？如果允许负数出现，需要向题目中添加哪些限制条件？</p>


    
## 方法一：动态规划

令$dp[i]$表示总和为$i$的方案数。

那么初始值$dp[0] = 1$

转移方程$dp[i] += dp[i - num]$，其中$num <= i\&\& num \in nums$

需要注意的是，本题中题目说明了“答案不会超过INT_MAX”，但是中间运算过程可能会溢出。因此需要在进行加法运算前判断一下相加后是否溢出，若会溢出则什么都不干即可。

+ 时间复杂度$O(n\times target)$，其中$n$是数组中元素个数
+ 空间复杂度$O(target)$

### AC代码

#### C++

```cpp
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int& num : nums) {
                if (num <= i && ((long long)dp[i] + dp[i - num] <= INT_MAX)) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/10/10/LeetCode%200377.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8C%E2%85%A3/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127251669](https://letmefly.blog.csdn.net/article/details/127251669)
