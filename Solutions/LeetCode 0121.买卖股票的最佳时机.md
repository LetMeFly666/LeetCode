---
title: 121.买卖股票的最佳时机
date: 2022-07-19 11:03:37
tags: [题解, LeetCode, 简单, 数组, 动态规划, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】121.买卖股票的最佳时机 - 从后往前模拟

力扣题目链接：[https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/)

<p>给定一个数组 <code>prices</code> ，它的第 <code>i</code> 个元素 <code>prices[i]</code> 表示一支给定股票第 <code>i</code> 天的价格。</p>

<p>你只能选择 <strong>某一天</strong> 买入这只股票，并选择在 <strong>未来的某一个不同的日子</strong> 卖出该股票。设计一个算法来计算你所能获取的最大利润。</p>

<p>返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 <code>0</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>[7,1,5,3,6,4]
<strong>输出：</strong>5
<strong>解释：</strong>在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>prices = [7,6,4,3,1]
<strong>输出：</strong>0
<strong>解释：</strong>在这种情况下, 没有交易完成, 所以最大利润为 0。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= prices.length <= 10<sup>5</sup></code></li>
	<li><code>0 <= prices[i] <= 10<sup>4</sup></code></li>
</ul>


    
## 方法一：从后往前模拟

使用两个变量：

```cpp
int M = 0;  // 代表今天及之后的某一天中的股票最高价格
int ans = 0;  // 代表最大收益
```

从后往前遍历，不断更新最大值$M$。

因为我们是从后往前遍历的，因此从今天买入股票的话，一定能够在股票价格为$M$的时候卖出。

这样，就判断今天买入股票的话，能够赚取多少钱即可。

+ 时间复杂度$O(N)$，其中$N$为已知股票金额的天数($prices.size()$)。
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int M = 0;
        for (int i = prices.size() - 1; i >= 0; i--) {
            M = max(M, prices[i]);
            ans = max(ans, M - prices[i]);  // 今天买入股票的话，最大收益是 M - prices[i]
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ans, m = 0, prices[0]
        for t in prices:
            m = min(m, t)
            ans = max(ans, t - m)
        return
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/07/19/LeetCode%200121.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BA/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125867999](https://letmefly.blog.csdn.net/article/details/125867999)
