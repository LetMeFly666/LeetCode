---
title: 188.买卖股票的最佳时机 IV
date: 2022-08-12 10:26:36
tags: [题解, LeetCode, 困难, 数组, 动态规划]
---

# 【LetMeFly】188.买卖股票的最佳时机 IV

力扣题目链接：[https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/)

<p>给定一个整数数组 <code>prices</code> ，它的第<em> </em><code>i</code> 个元素 <code>prices[i]</code> 是一支给定的股票在第 <code>i</code><em> </em>天的价格。</p>

<p>设计一个算法来计算你所能获取的最大利润。你最多可以完成 <strong>k</strong> 笔交易。</p>

<p><strong>注意：</strong>你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>k = 2, prices = [2,4,1]
<strong>输出：</strong>2
<strong>解释：</strong>在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>k = 2, prices = [3,2,6,5,0,3]
<strong>输出：</strong>7
<strong>解释：</strong>在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 <= k <= 100</code></li>
	<li><code>0 <= prices.length <= 1000</code></li>
	<li><code>0 <= prices[i] <= 1000</code></li>
</ul>


    
## 方法一：动态规划

这道题类似[LeetCode 0123.买卖股票的最佳时机 III](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/)，不同之处在于```0123```只能购买并出售两次，而```0188```能购买并出售$k$次。

与```0123```同理（解决方案请参考[https://blog.tisfy.eu.org/2022/07/20/LeetCode%200123.买卖股票的最佳时机 III](https://blog.tisfy.eu.org/2022/07/20/LeetCode%200123.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BAIII/)），我们用$buy[i]$严格代表进行了$i$次买入和$i-1$次卖出的最大收益，用$sell[i]$严格表示进行了$i$次买卖的最大收益。

初始值$buy[0] = sell[0] = 0$，而第一天$buy[i] = -prices[0],sell[i] = 0(i \neq 0)$

我们从第二天开始模拟，这一天可以在$sell[k - 1]$的基础上进行买入，也可以在$buy[k]$的基础上进行卖出

最后，返回$sell[k]$（进行了$k$次买卖）即为最终答案

+ 时间复杂度$O(n\times k)$，其中$n$是股票天数
+ 空间复杂度$O(k)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty())
            return 0;
        vector<int> buy(k + 1, -prices[0]);
        vector<int> sell(k + 1, 0);
        buy[0] = 0, sell[0] = 0;
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 1; j <= k; j++) {
                buy[j] = max(buy[j], sell[j - 1] + (-prices[i]));
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k];
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        if not prices:
            return 0
        buy = [-prices[0]] * (k + 1)
        sell = [0] * (k + 1)
        buy[0] = 0
        for i in range(1, len(prices)):
            for j in range(1, k + 1):
                buy[j] = max(buy[j], sell[j - 1] - prices[i])
                sell[j] = max(sell[j], buy[j] + prices[i])
        return sell[k]
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/08/12/LeetCode%200188.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BAIV/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126299307](https://letmefly.blog.csdn.net/article/details/126299307)
