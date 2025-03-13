---
title: 714.买卖股票的最佳时机含手续费
date: 2023-10-06 12:14:44
tags: [题解, LeetCode, 中等, 贪心, 数组, 动态规划, DP]
categories: [题解, LeetCode]
---

# 【LetMeFly】714.买卖股票的最佳时机含手续费

力扣题目链接：[https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)

<p>给定一个整数数组&nbsp;<code>prices</code>，其中 <code>prices[i]</code>表示第&nbsp;<code>i</code>&nbsp;天的股票价格 ；整数&nbsp;<code>fee</code> 代表了交易股票的手续费用。</p>

<p>你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。</p>

<p>返回获得利润的最大值。</p>

<p><strong>注意：</strong>这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>prices = [1, 3, 2, 8, 4, 9], fee = 2
<strong>输出：</strong>8
<strong>解释：</strong>能够达到的最大利润:  
在此处买入&nbsp;prices[0] = 1
在此处卖出 prices[3] = 8
在此处买入 prices[4] = 4
在此处卖出 prices[5] = 9
总利润:&nbsp;((8 - 1) - 2) + ((9 - 4) - 2) = 8</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>prices = [1,3,7,5,10,3], fee = 3
<strong>输出：</strong>6
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= prices.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= prices[i] &lt; 5 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= fee &lt; 5 * 10<sup>4</sup></code></li>
</ul>


    
## 方法一：动态规划

使用两个变量：```buy```代表当前处于持仓状态下的最大收益、```sell```代表当前处于“空手”状态下的最大收益。

在第一天：
   + 若处于持仓状态，则说明购买了第一天的股票，当前总收益$buy = -prices[0]$
   + 若处于空手状态，则说明第一天没有进行股票交易（因为有手续费所以不会当天购买当天卖出），当前总收益$sell = 0$

之后从第二天开始遍历到最后一天，遍历过程中：
   + $buy = \max(buy, sell - prices[i])$
   + $sell = \max(sell, buy + prices[i] - fee)$

最终返回$sell$即可。

+ 时间复杂度$O(len(prices))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = -prices[0], sell = 0;
        for (int i = 1; i < prices.size(); i++) {
            buy = max(buy, sell - prices[i]);
            sell = max(sell, buy + prices[i] - fee);
        }
        return sell;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        buy, sell = -prices[0], 0
        for i in range(1, len(prices)):
            buy = max(buy, sell - prices[i])
            sell = max(sell, buy + prices[i] - fee)
        return sell
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/10/06/LeetCode%200714.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BA%E5%90%AB%E6%89%8B%E7%BB%AD%E8%B4%B9/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/133609633](https://letmefly.blog.csdn.net/article/details/133609633)
