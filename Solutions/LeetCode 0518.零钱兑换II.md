---
title: 518.零钱兑换 II
date: 2022-11-19 14:44:48
tags: [题解, LeetCode, 中等, 数组, 动态规划, DP]
---

# 【LetMeFly】518.零钱兑换 II

力扣题目链接：[https://leetcode.cn/problems/coin-change-2/](https://leetcode.cn/problems/coin-change-2/)

<p>给你一个整数数组 <code>coins</code> 表示不同面额的硬币，另给一个整数 <code>amount</code> 表示总金额。</p>

<p>请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 <code>0</code> 。</p>

<p>假设每一种面额的硬币有无限个。 </p>

<p>题目数据保证结果符合 32 位带符号整数。</p>

<p> </p>

<ul>
</ul>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>amount = 5, coins = [1, 2, 5]
<strong>输出：</strong>4
<strong>解释：</strong>有四种方式可以凑成总金额：
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>amount = 3, coins = [2]
<strong>输出：</strong>0
<strong>解释：</strong>只用面额 2 的硬币不能凑成总金额 3 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>amount = 10, coins = [10] 
<strong>输出：</strong>1
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= coins.length <= 300</code></li>
	<li><code>1 <= coins[i] <= 5000</code></li>
	<li><code>coins</code> 中的所有值 <strong>互不相同</strong></li>
	<li><code>0 <= amount <= 5000</code></li>
</ul>


    
## 方法一：动态规划

用$dp[i]$表示硬币总金额为$i$的方案数

初始值$dp[0] = 1$（硬币总和为0的方案只有一种：0枚硬币）

转移方程$dp[i] = \sum dp[i - coin_j]$

注意，$[1, 2]$和$[2, 1]$是一种方案。因此为了避免硬币顺序不同导致方案数重复计算的情况，我们应该按照硬币顺序进行模拟。即：先全用$1$元硬币，再尝试用$2$元硬币替换数个$1$元硬币，再考虑$3$元（如果有的话）...

+ 时间复杂度$O(len(coins) \times amount)$
+ 空间复杂度$O(amount)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int& t : coins) {
            for (int i = t; i <= amount; i++)
                dp[i] += dp[i - t];
        }
        return dp.back();
    }
};
```

#### Pythonn

```python
from typing import List

class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        dp = [0] * (amount + 1)
        dp[0] = 1
        for coin in coins:
            for i in range(coin, amount + 1):
                dp[i] += dp[i - coin]
        return dp[-1]
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/11/19/LeetCode%200518.%E9%9B%B6%E9%92%B1%E5%85%91%E6%8D%A2II/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127936876](https://letmefly.blog.csdn.net/article/details/127936876)
