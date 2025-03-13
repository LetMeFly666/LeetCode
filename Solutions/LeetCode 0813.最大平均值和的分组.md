---
title: 813.最大平均值和的分组
date: 2022-11-28 20:57:56
tags: [题解, LeetCode, 中等, 数组, 动态规划, DP, 前缀和]
categories: [题解, LeetCode]
---

# 【LetMeFly】813.最大平均值和的分组

力扣题目链接：[https://leetcode.cn/problems/largest-sum-of-averages/](https://leetcode.cn/problems/largest-sum-of-averages/)

<p>给定数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;。我们将给定的数组&nbsp;<code>nums</code>&nbsp;分成 <strong>最多</strong>&nbsp;<code>k</code>&nbsp;个相邻的非空子数组 。&nbsp;<strong>分数</strong> 由每个子数组内的平均值的总和构成。</p>

<p>注意我们必须使用 <code>nums</code> 数组中的每一个数进行分组，并且分数不一定需要是整数。</p>

<p>返回我们所能得到的最大 <strong>分数</strong> 是多少。答案误差在&nbsp;<code>10<sup>-6</sup></code>&nbsp;内被视为是正确的。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [9,1,2,3,9], k = 3
<strong>输出:</strong> 20.00000
<strong>解释:</strong> 
nums 的最优分组是[9], [1, 2, 3], [9]. 得到的分数是 9 + (1 + 2 + 3) / 3 + 9 = 20. 
我们也可以把 nums 分成[9, 1], [2], [3, 9]. 
这样的分组得到的分数为 5 + 2 + 6 = 13, 但不是最大值.
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,2,3,4,5,6,7], k = 4
<strong>输出:</strong> 20.50000
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>
</ul>


    
## 方法一：DP + 前缀和

首先需要明白的是，虽然题目说的是“最多$k$组”，但其实等价于“分为$k$组”。因为能分成$k$组的话，绝对不分成$k-1$组。毕竟分组越少，除得越多。如果明白这个道理，下面的 证明 可以跳过。

> 证明：假设我们把数组分成了$k-1$组，那么我们可以将其中的某组一分为二（一定存在元素个数大于$1$的分组），这样，分母就会变小。（假设这组为$[a_1, a_2, \cdots, a_n, b]$，那么这组的平均数为$\frac{a_1+a_2+\cdots+a_n+b}{n+1}$，**不失一般性**，我们把其中的$b$分出来，这样平均数之和就变成了$\frac{a_1+a_2+\cdots+a_n}{n}+b>\frac{a_1+a_2+\cdots+a_n+b}{n+1}$

目的明确，确定分为$k$组。因此我们就可以使用数组$dp[n+1][k+1]$（其中$n$是数组中元素的个数），其中$dp[i][j]$代表将原始数组中的前$i$个元素分为$j$组的最大“平均数之和”

我们预处理求出一个前缀和数组$prefix[n+1]$，其中$prefix[i]$代表数组中前$i$个元素的和

+ 当$j=1$时，$dp[i][j] = dp[i][1] = prefix[i] / i$（前$i$个元素的平均数）
+ 否则，我们在$[j-1, i-1]$中挑选一个$l$，将$[0, i]$分为$[0, l-1]$和$[l,i-1]$两部分，因此$dp[i][j]=\max_{l\geq j-1}\{dp[l][j-1]+\frac{\sum_{r=l}^{i-1}nums[r]}{i-l}\}$

最终$dp[n][k]$即为答案

+ 时间复杂度$O(n^2\times k)$
+ 空间复杂度$O(n\times k)$

### AC代码

#### C++

```cpp
class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> prefix(n + 1);
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        vector<vector<double>> dp(n + 1, vector<double>(k + 1));
        for (int i = 1; i <= n; i++) {
            dp[i][1] = prefix[i] / i;
        }
        for (int j = 2; j <= k; j++) {
            for (int i = j; i <= n; i++) {
                for (int l = j - 1; l < i; l++) {
                    dp[i][j] = max(dp[i][j], dp[l][j - 1] + (prefix[i] - prefix[l]) / (i - l));
                }
            }
        }
        return dp[n][k];
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/11/28/LeetCode%200813.%E6%9C%80%E5%A4%A7%E5%B9%B3%E5%9D%87%E5%80%BC%E5%92%8C%E7%9A%84%E5%88%86%E7%BB%84/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128087654](https://letmefly.blog.csdn.net/article/details/128087654)
