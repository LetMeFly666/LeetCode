---
title: 2944.购买水果需要的最少金币数：动态规划（O(n^2)复杂度，非最优算法）
date: 2025-01-24 14:22:52
tags: [题解, LeetCode, 中等, 队列, 数组, 动态规划, DP, 单调队列, 堆（优先队列）]
---

# 【LetMeFly】2944.购买水果需要的最少金币数：动态规划（O(n^2)复杂度，非最优算法）

力扣题目链接：[https://leetcode.cn/problems/minimum-number-of-coins-for-fruits/](https://leetcode.cn/problems/minimum-number-of-coins-for-fruits/)

<p>给你一个 <strong>下标从 1 开始的</strong> 整数数组&nbsp;<code>prices</code>&nbsp;，其中&nbsp;<code>prices[i]</code>&nbsp;表示你购买第 <code>i</code>&nbsp;个水果需要花费的金币数目。</p>

<p>水果超市有如下促销活动：</p>

<ul>
	<li>如果你花费 <code>prices[i]</code>&nbsp;购买了下标为&nbsp;<code>i</code>&nbsp;的水果，那么你可以免费获得下标范围在&nbsp;<code>[i + 1, i + i]</code>&nbsp;的水果。</li>
</ul>

<p><strong>注意</strong>&nbsp;，即使你&nbsp;<strong>可以</strong>&nbsp;免费获得水果&nbsp;<code>j</code>&nbsp;，你仍然可以花费&nbsp;<code>prices[j]</code>&nbsp;个金币去购买它以获得它的奖励。</p>

<p>请你返回获得所有水果所需要的 <strong>最少</strong>&nbsp;金币数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">prices = [3,1,2]</span></p>

<p><strong>输出：</strong><span class="example-io">4</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>用&nbsp;<code>prices[0] = 3</code>&nbsp;个金币购买第 1 个水果，你可以免费获得第 2 个水果。</li>
	<li>用&nbsp;<code>prices[1] = 1</code>&nbsp;个金币购买第 2 个水果，你可以免费获得第 3 个水果。</li>
	<li>免费获得第 3 个水果。</li>
</ul>

<p>请注意，即使您可以免费获得第 2 个水果作为购买第 1 个水果的奖励，但您购买它是为了获得其奖励，这是更优化的。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">prices = [1,10,1,1]</span></p>

<p><strong>输出：</strong><span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>用&nbsp;<code>prices[0] = 1</code> 个金币购买第 1 个水果，你可以免费获得第 2 个水果。</li>
	<li>免费获得第 2 个水果。</li>
	<li>用&nbsp;<code>prices[2] = 1</code> 个金币购买第 3 个水果，你可以免费获得第 4 个水果。</li>
	<li>免费获得第 4 个水果。</li>
</ul>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">prices = [26,18,6,12,49,7,45,45]</span></p>

<p><strong>输出：</strong><span class="example-io">39</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>用&nbsp;<code>prices[0] = 26</code> 个金币购买第 1 个水果，你可以免费获得第 2 个水果。</li>
	<li>免费获得第 2 个水果。</li>
	<li>用&nbsp;<code>prices[2] = 6</code> 个金币购买第 3 个水果，你可以免费获得第 4，5，6（接下来的三个）水果。</li>
	<li>免费获得第 4 个水果。</li>
	<li>免费获得第 5&nbsp;个水果。</li>
	<li>用&nbsp;<code>prices[5] = 7</code>&nbsp;个金币购买第 6 个水果，你可以免费获得第 7 和 第 8 个水果。</li>
	<li>免费获得第 7&nbsp;个水果。</li>
	<li>免费获得第 8&nbsp;个水果。</li>
</ul>

<p>请注意，即使您可以免费获得第 6 个水果作为购买第 3 个水果的奖励，但您购买它是为了获得其奖励，这是更优化的。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= prices.length &lt;= 1000</code></li>
	<li><code>1 &lt;= prices[i] &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法：动态规划

创建`buy`数组和`notBuy`数组，其中：

1. `buy[i]`代表**购买**下标为`i`的水果话，获得`[0, i]`的水果所需的最小花费
1. `notBuy[i]`代表**不购买**下标为`i`的水果话，获得`[0, i]`的水果所需的最小花费

因此很容易想到状态转移方程：

1. 购买下标为`i`的水果的话，可以在购买和不购买`i - 1`这两种方案中，选择最优的那个：$buy[i] = \min(buy[i - 1], notBuy[i - 1]) + prices[i]$
1. 不购买下标为`i`的水果的话，可以在购买了下标为$[ \lfloor\frac{i}2\rfloor, i)$的水果的基础上，免费获得下标为`i`的水果：$notBuy[i]=\min\limits_{j=\lfloor\frac{i}2\rfloor}^{i-1}\{buy[j]\}$

最终，`buy[n - 1]`和`notBuy[n - 1]`中最小的那个即为所求。

## 疑难解答

**初始值怎么确定？**

> 初始值`buy[0] = notBuy[0] = prices[0]`，因为第一个水果无法通过购买其他水果获赠得到，所以第一个水果必须购买。

**为什么$buy[i] = \min(buy[i - 1], notBuy[i - 1]) + prices[i]$，而不是$buy[i] = notBuy[i - 1] + prices[i]$？**

> 读者问题的核心在于是否有必要使用`min`操作判断`buy[i - 1]`和`notBuy[i - 1]`二者中的最小值。
>
> 直觉告诉我们，似乎不买`i - 1`会比买`i - 1`省钱，似乎`notBuy[i - 1]`一定会小于`buy[i - 1]`。
>
> 其实不然，因为我们要获得所有的水果，所以不买水果`3`的话，就一定要买水果`2`从而获赠水果`3`。但是水果`2`可能十分贵，不如购买水果`1`和`3`而令水果`2`作为赠品。

## 时空复杂度分析

+ 时间复杂度$O(n^2)$，其中$n=len(prices)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-01-24 13:02:37
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-24 14:05:03
 */
class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        vector<int> buy(prices.size()), notBuy(prices.size());
        buy[0] = notBuy[0] = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            buy[i] = min(notBuy[i - 1], buy[i - 1]) + prices[i];  // 不买3的话必须买2，因此buy[2]不一定大于notBuy[2]
            notBuy[i] = 1000000000;
            for (int j = i / 2; j < i; j++) {
                notBuy[i] = min(notBuy[i], buy[j]);
            }
        }
        return min(buy.back(), notBuy.back());
    }
};
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/01/24/LeetCode%202944.%E8%B4%AD%E4%B9%B0%E6%B0%B4%E6%9E%9C%E9%9C%80%E8%A6%81%E7%9A%84%E6%9C%80%E5%B0%91%E9%87%91%E5%B8%81%E6%95%B0/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/145340613](https://letmefly.blog.csdn.net/article/details/145340613)
