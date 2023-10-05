---
title: 309.最佳买卖股票时机含冷冻期
date: 2022-09-18 09:10:32
tags: [题解, LeetCode, 中等, 数组, 动态规划, dp]
---

# 【LetMeFly】309.最佳买卖股票时机含冷冻期

力扣题目链接：[https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/)

<p>给定一个整数数组<meta charset="UTF-8" /><code>prices</code>，其中第&nbsp;<em>&nbsp;</em><code>prices[i]</code>&nbsp;表示第&nbsp;<code><em>i</em></code>&nbsp;天的股票价格 。​</p>

<p>设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:</p>

<ul>
	<li>卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。</li>
</ul>

<p><strong>注意：</strong>你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> prices = [1,2,3,0,2]
<strong>输出: </strong>3 
<strong>解释:</strong> 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> prices = [1]
<strong>输出:</strong> 0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= prices.length &lt;= 5000</code></li>
	<li><code>0 &lt;= prices[i] &lt;= 1000</code></li>
</ul>


    
## 方法一：动态规划

力扣上之前关于股票买卖的类似的题目：

+ [0121.买卖股票的最佳时机](https://blog.tisfy.eu.org/2022/07/19/LeetCode%200121.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BA/)
+ [0122.买卖股票的最佳时机II](https://blog.tisfy.eu.org/2022/07/19/LeetCode%200122.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BAII/)
+ [0123.买卖股票的最佳时机III](https://blog.tisfy.eu.org/2022/07/20/LeetCode%200123.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BAIII/)
+ [0188.买卖股票的最佳时机IV](https://blog.tisfy.eu.org/2022/08/12/LeetCode%200188.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BAIV/)


本题中，我们使用三个变量：

+ ```buy```：手里有一支买了的股票的最大收益
+ ```sell```：**今天**卖了一只股票的最大收益
+ ```none```：今天什么都不干的最大收益

第一天，三者的初始值分别为：

+ ```buy```：第一天就买入了股票，收益为```- 第一天的股票价格```
+ ```sell```：第一天就卖出了股票（买入的当天卖出），收益为```0```
+ ```none```：第一天什么也不干，收益为```0```

之后从第二天开始遍历每一天，并计算三者的新值：
+ ```newBuy```：今天买入了股票（前提是昨天什么都没干）```none - prices[i]```，或者之前就买入了股票并且还没卖```buy```
+ ```newSell```：**今天**卖出了股票（前提是之前有买入股票）```buy + prices[i]```
+ ```newNone```：今天什么都没干并且昨天什么都没干```none```，或者今天什么都没干并且昨天卖出了一支股票```sell```

不断更新三者的值，最终返回三者的最大值即可。


+ 时间复杂度$O(n)$，其中$n$是股市开放天数
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = -prices[0];
        int sell = 0;
        int none = 0;
        int n = prices.size();
        for (int i = 1; i < n; i++) {
            int newBuy = max(buy, none - prices[i]);
            int newSell = buy + prices[i];
            int newNone = max(none, sell);
            buy = newBuy;
            sell = newSell;
            none = newNone;
        }
        return max(sell, none);
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        buy, sell, sellBefore = -prices[0], 0, 0
        for i in range(1, len(prices)):
            buy, sell, sellBefore = max(buy, sellBefore - prices[i]), max(sell, buy + prices[i]), sell
        return sell
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/09/18/LeetCode%200309.%E6%9C%80%E4%BD%B3%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E6%97%B6%E6%9C%BA%E5%90%AB%E5%86%B7%E5%86%BB%E6%9C%9F/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126913940](https://letmefly.blog.csdn.net/article/details/126913940)
