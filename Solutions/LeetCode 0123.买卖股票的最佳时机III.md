---
title: 123.买卖股票的最佳时机 III
date: 2022-07-20 12:04:32
tags: [题解, LeetCode, 困难, 数组, 动态规划, dp, 模拟]
---

# 【LetMeFly】123.买卖股票的最佳时机 III：常数空间下的动态规划+模拟

力扣题目链接：[https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/)

<p>给定一个数组，它的第<em> </em><code>i</code> 个元素是一支给定的股票在第 <code>i</code><em> </em>天的价格。</p>

<p>设计一个算法来计算你所能获取的最大利润。你最多可以完成 <strong>两笔 </strong>交易。</p>

<p><strong>注意：</strong>你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。</p>

<p> </p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>prices = [3,3,5,0,0,3,1,4]
<strong>输出：</strong>6
<strong>解释：</strong>在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>prices = [1,2,3,4,5]
<strong>输出：</strong>4
<strong>解释：</strong>在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。   
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。   
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>prices = [7,6,4,3,1] 
<strong>输出：</strong>0 
<strong>解释：</strong>在这个情况下, 没有交易完成, 所以最大利润为 0。</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>prices = [1]
<strong>输出：</strong>0
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= prices.length <= 10<sup>5</sup></code></li>
	<li><code>0 <= prices[i] <= 10<sup>5</sup></code></li>
</ul>


    
## 方法一：常数空间下的动态规划

这道题说白了最多有$5$个状态：

+ 未进行过任何交易
+ 进行了一次买入
+ 进行了一次买卖
+ 进行了一次买卖 + 一次买入
+ 进行了两次买卖

未进行任何交易时，所获利为$0$，因此无需特别关注。

用四个变量$buy1, sell1, buy2, sell2$分别代表交易进行到剩下的四种状态时，当前获利的最大值。（这里变量名尽量与[官方题解](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/solution/mai-mai-gu-piao-de-zui-jia-shi-ji-iii-by-wrnt/)保持一致）

**接下来我们严格遵守上述四个变量的含义**

将四个变量的初始值赋值为第一天过后的最大获利值：

+ $buy1$：第一天进行了一次买入。那么当前最大获利为 $负的第一天的股价$（说是最大获利，其实第一天进行到这种状态的话别无选择，只有这一种获利结果）
+ $sell1$：第一天进行了一次买卖。那么买入和卖出的价格相同，当前最大获利为$0$
+ $buy2$：第一天进行了一次买卖 + 一次买入。也就是说第一天买了一次立刻卖了，然后又买了一次，总(最大)获利为$负的第一天的股价$
+ $sell2$：第一天进行了两次买卖。总收益为$0$

```cpp
int buy1 = -prices[0]
int sell1 = 0;
int buy2 = -prices[0]
int sell2 = 0;
```

接下来，从第$2$天开始，模拟前$i$天，每种状态下的最大获利。

+ $buy1$：前$i$天只进行过一次买入的最大获利。$buy=\max(buy', -prices[i])$。也就是说，可以是前$i-1$天股价较低的时候进行一次买入($buy'$)，也可以不在前$i-1$天买而是在第$i$天买入($-prices[i]$)。（这里用$buy'$代表第$i-1$天时$buy$的值）
+ $sell1$：前$i$天进行过一次买卖。$sell1=\max(sell1', buy1' + prices[i])$。也就是说，可以是在前$i-1$天进行了一次买卖而今天不进行任何操作($sell1'$)，也可以是前$i-1$天只进行了买入而在第$i$天卖出($buy1'+prices[i]$)（卖出会获利$prices[i]$）
+ $buy2$：前$i$天进行过一次买卖+一次买入。$buy2=\max(buy2', sell1'-prices[i])$。也就是说，可以是在前$i-1$天进行了一次买卖+一次买入而今天不进行任何操作($buy2'$)，也可以是前$i-1$天进行了一次买卖而在第$i$天又买入了一次($sell1' + (-prices[i])$)（买入会支出$prices[i]$）
+ $sell2$：前$i$天进行了两次买卖。$sell2=\max(sell2',buy2'+prices[i])$。可以是在前$i-1$天进行了两次买卖而今天不进行任何操作($sell2'$)，也可以是前$i-1$天只进行了一次买卖+一次买入而在第$i$天卖出了第二次买入($buy2'+prices[i]$)（卖出会获利$prices[i]$）

因此，模拟完$n$天后，返回$sell2$即可（进行了两次买卖）

注意，题目中是最多进行两次买卖，也就是说可以只进行一次买卖或不进行任何买卖。不进行买卖和买入的当天卖出是等价的，因此可以理解为必须进行了两次买卖但可能买入的同一天卖出过。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$，只使用了常数个额外空间

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = -prices[0], sell1 = 0;
        int buy2 = -prices[0], sell2 = 0;
        for (int i = 1; i < prices.size(); i++) {
            buy1 = max(buy1, 0 + (-prices[i]));
            sell1 = max(sell1, buy1 + (prices[i]));
            buy2 = max(buy2, sell1 + (-prices[i]));
            sell2 = max(sell2, buy2 + (prices[i]));
        }
        return sell2;
    }
};
```

代码很短，关键在于严格遵守变量的定义并理解。

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/07/20/LeetCode%200123.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BAIII/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125889831](https://letmefly.blog.csdn.net/article/details/125889831)
