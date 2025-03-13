---
title: 322.零钱兑换
date: 2024-03-24 12:04:57
tags: [题解, LeetCode, 中等, 广度优先搜索, 数组, 动态规划, DP]
categories: [题解, LeetCode]
---

# 【LetMeFly】322.零钱兑换：动态规划(DP)

力扣题目链接：[https://leetcode.cn/problems/coin-change/](https://leetcode.cn/problems/coin-change/)

<p>给你一个整数数组 <code>coins</code> ，表示不同面额的硬币；以及一个整数 <code>amount</code> ，表示总金额。</p>

<p>计算并返回可以凑成总金额所需的 <strong>最少的硬币个数</strong> 。如果没有任何一种硬币组合能组成总金额，返回&nbsp;<code>-1</code> 。</p>

<p>你可以认为每种硬币的数量是无限的。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<pre>
<strong>输入：</strong>coins = <code>[1, 2, 5]</code>, amount = <code>11</code>
<strong>输出：</strong><code>3</code> 
<strong>解释：</strong>11 = 5 + 5 + 1</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>coins = <code>[2]</code>, amount = <code>3</code>
<strong>输出：</strong>-1</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>coins = [1], amount = 0
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= coins.length &lt;= 12</code></li>
	<li><code>1 &lt;= coins[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>0 &lt;= amount &lt;= 10<sup>4</sup></code></li>
</ul>


    
## 方法一：动态规划

使用一个$dp$数组，$dp[i]$代表组成金额$i$至少需要多少枚硬币。

初始值除了$dp[0]=0$外其余值全为“无穷大”。

状态转移方程：$dp[i]=\min (dp[i], dp[i - coin] + 1), \forall coin \in cins$。

最终$dp[amount]$的值即为答案（若为“无穷大”则需返回```-1```）

+ 时间复杂度$O(amount\times len(coins))$
+ 空间复杂度$O(amount)

### AC代码

#### C++

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 1e5);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int t : coins) {
                if (i - t >= 0) {
                    dp[i] = min(dp[i], dp[i - t] + 1);
                }
            }
        }
        return dp.back() > amount ? -1 : dp.back();
    }
};
```

其实也可以对coins按从小到大的顺序排序，一旦$i-coin\le 0$就break。

#### Python

```python
from typing import List

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [int(1e5)] * (amount + 1)
        dp[0] = 0
        for i in range(1, amount + 1):
            for coin in coins:
                if i - coin >= 0:
                    dp[i] = min(dp[i], dp[i - coin] + 1)
        return -1 if dp[-1] > amount else dp[-1]
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/03/24/LeetCode%200322.%E9%9B%B6%E9%92%B1%E5%85%91%E6%8D%A2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136985285](https://letmefly.blog.csdn.net/article/details/136985285)
