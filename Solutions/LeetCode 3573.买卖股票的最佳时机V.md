---
title: 3573.买卖股票的最佳时机 V：深度优先搜索 / 动态规划：通俗讲解
date: 2025-12-17 23:19:51
tags: [题解, LeetCode, 中等, 数组, 动态规划, DP, 深度优先搜索, DFS]
categories: [题解, LeetCode]
---

# 【LetMeFly】3573.买卖股票的最佳时机 V：深度优先搜索 / 动态规划：通俗讲解

力扣题目链接：[https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-v/](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-v/)

<p>给你一个整数数组 <code>prices</code>，其中 <code>prices[i]</code> 是第 <code>i</code> 天股票的价格（美元），以及一个整数 <code>k</code>。</p>

<p>你最多可以进行 <code>k</code> 笔交易，每笔交易可以是以下任一类型：</p>

<ul>
	<li>
	<p><strong>普通交易</strong>：在第 <code>i</code> 天买入，然后在之后的第 <code>j</code> 天卖出，其中 <code>i &lt; j</code>。你的利润是 <code>prices[j] - prices[i]</code>。</p>
	</li>
	<li>
	<p><strong>做空交易</strong>：在第 <code>i</code> 天卖出，然后在之后的第 <code>j</code> 天买回，其中 <code>i &lt; j</code>。你的利润是 <code>prices[i] - prices[j]</code>。</p>
	</li>
</ul>

<p><strong>注意</strong>：你必须在开始下一笔交易之前完成当前交易。此外，你不能在已经进行买入或卖出操作的同一天再次进行买入或卖出操作。</p>

<p>通过进行&nbsp;<strong>最多</strong> <code>k</code> 笔交易，返回你可以获得的最大总利润。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<div class="example-block">
<p><strong>输入:</strong> <span class="example-io">prices = [1,7,9,8,2], k = 2</span></p>

<p><strong>输出:</strong> <span class="example-io">14</span></p>

<p><strong>解释:</strong></p>
我们可以通过 2 笔交易获得 14 美元的利润：

<ul>
	<li>一笔普通交易：第 0 天以 1 美元买入，第 2 天以 9 美元卖出。</li>
	<li>一笔做空交易：第 3 天以 8 美元卖出，第 4 天以 2 美元买回。</li>
</ul>
</div>

<p><strong class="example">示例 2:</strong></p>

<div class="example-block">
<p><strong>输入:</strong> <span class="example-io">prices = [12,16,19,19,8,1,19,13,9], k = 3</span></p>

<p><strong>输出:</strong> <span class="example-io">36</span></p>

<p><strong>解释:</strong></p>
我们可以通过 3 笔交易获得 36 美元的利润：

<ul>
	<li>一笔普通交易：第 0 天以 12 美元买入，第 2 天以 19 美元卖出。</li>
	<li>一笔做空交易：第 3 天以 19 美元卖出，第 4 天以 8 美元买回。</li>
	<li>一笔普通交易：第 5 天以 1 美元买入，第 6 天以 19 美元卖出。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>2 &lt;= prices.length &lt;= 10<sup>3</sup></code></li>
	<li><code>1 &lt;= prices[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= prices.length / 2</code></li>
</ul>

自我评价：好文x1(bushi)

## 解题方法一：深度优先搜索

定义`dfs(i, j, status)`含义为：

* 0到$i$天，共进行了$j$次买入或做空操作
* status：0代表第$i$天要到没持有股票状态；1代表第$i$天要到手持股票的状态；2代表第$i$天要到做空的状态

假设买入或做空时立刻消耗交易次数(卖出或还上时交易完成不二次消耗次数)，那么有：

1. 如果status为0（这天结束后两清）：可昨天本就两清今天什么都没干(`dfs(i-1, j, 0)`)，可昨天是手持股票状态今天卖了(`dfs(i-1, j, 1) + prices[i]`)，可昨天是空头状态今天买回来补上了(`dfs(i-1, j, 2) - prices[i]`)。
2. 如果status为1（这天结束后手持股票）：可昨天本就持有股票今天什么都没干(`dfs(i-1, j, 1)`)，可昨天两清今天刚买入(`dfs(i-1, j-1, 0) - prices[i]`)。
3. 如果status为2（这天结束后欠还股票）：可昨天就是欠股票状态今天什么都没干(`dfs(i-1, j, 2)`)，可昨天两清今天做空提前卖了股票(`dfs(i-1, j-1, 0) + prices[i]`)。

边界条件：

1. 可用操作次数始终不能为负，如果为负返回“负无穷”
2. 天数为-1时（交易开始前）只能处于两清状态，如果交易开始前（$i=-1$）状态已经处在持股或空头则说明状态不合法，返回“负无穷”。

时空复杂度：

+ 时间复杂度$O(len(prices)\times k)$
+ 空间复杂度$O(len(prices)\times k)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2025-12-17 23:09:09
 */
typedef long long ll;
class Solution {
private:
    vector<int> prices;
    unordered_map<int, ll> cache;

    inline int getKey(int i, int j, int status) {
        return i * 3000 + j * 3 + status;
    }

    ll dfs(int i, int j, int status) {
        // 0~i天 最多交易j次
        // status: 0无1买2空头
        
        int key = getKey(i, j, status);
        if (cache.count(key)) {
            return cache[key];
        }

        if (j < 0) {
            return -1'000'000'000'000'000;
        }
        if (i < 0) {
            return status ? -1'000'000'000'000'000 : 0;
        }

        if (status == 0) {
            return cache[key] = max({dfs(i - 1, j, 0), dfs(i - 1, j, 1) + prices[i], dfs(i - 1, j, 2) - prices[i]});
        } else if (status == 1) {
            return cache[key] = max(dfs(i - 1, j - 1, 0) - prices[i], dfs(i - 1, j, 1));
        } else {
            return cache[key] = max(dfs(i - 1, j - 1, 0) + prices[i], dfs(i - 1, j, 2));
        }
    }
public:
    ll maximumProfit(vector<int>& prices, int k) {
        this->prices = move(prices);
        return dfs(this->prices.size() - 1, k, 0);
    }
};
```

#### Python

python记得最终返回结果前强制清空下缓存，虽然python也有gc机制但可能gc不及时导致MLE。

```python
'''
LastEditTime: 2025-12-17 23:18:54
'''
from typing import List
from functools import cache
from math import inf

class Solution:
    def maximumProfit(self, prices: List[int], k: int) -> int:
        n = len(prices)

        @cache
        def dfs(i: int, j: int, status: int) -> int:
            """0无1有2空头"""

            if j < 0:
                return -inf
            if i < 0:
                return -inf if status else 0
            
            if status == 0:
                return max(dfs(i - 1, j, 0), dfs(i - 1, j, 1) + prices[i], dfs(i - 1, j, 2) - prices[i])
            elif status == 1:
                return max(dfs(i - 1, j, 1), dfs(i - 1, j - 1, 0) - prices[i])
            else:
                return max(dfs(i - 1, j, 2), dfs(i - 1, j - 1, 0) + prices[i])

        ans = dfs(n - 1, k, 0)
        dfs.cache_clear()
        return ans
```

## 解题方法二：动态规划

将深度优先搜索翻译成递推：

```python
if status == 0:
    return max(dfs(i - 1, j, 0), dfs(i - 1, j, 1) + prices[i], dfs(i - 1, j, 2) - prices[i])
elif status == 1:
    return max(dfs(i - 1, j, 1), dfs(i - 1, j - 1, 0) - prices[i])
else:
    return max(dfs(i - 1, j, 2), dfs(i - 1, j - 1, 0) + prices[i])
```

翻译为：

```python
dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + price, dp[i-1][j][2] - price)
dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - price)
dp[i][j][2] = max(dp[i-1][j][2], dp[i-1][j-1][0] + price)
```

注意为了防止下标出现-1可以令所有i在作dp下标时加上1：

```python
dp[i+1][j][0] = max(dp[i][j][0], dp[i][j][1] + price, dp[i][j][2] - price)
dp[i+1][j][1] = max(dp[i][j][1], dp[i][j-1][0] - price)
dp[i+1][j][2] = max(dp[i][j][2], dp[i][j-1][0] + price)
```

时空复杂度：

+ 时间复杂度$O(len(prices)\times k)$
+ 空间复杂度$O(len(prices)\times k)$

### AC代码

#### Python

```python
'''
LastEditTime: 2025-12-17 23:51:56
'''
from typing import List
from math import inf

class Solution:
    def maximumProfit(self, prices: List[int], k: int) -> int:
        n = len(prices)

        # dp[i][j][status]: i有效范围0~n-1，j有效范围0~k，这俩都多开一个无效状态的空间
        dp = [[[-inf] * 3 for _ in range(k + 2)] for _ in range(n + 1)]
        for j in range(1, k + 2):
            dp[0][j][0] = 0

        for i, price in enumerate(prices):
            for j in range(1, k + 2):
                dp[i+1][j][0] = max(dp[i][j][0], dp[i][j][1] + price, dp[i][j][2] - price)
                dp[i+1][j][1] = max(dp[i][j][1], dp[i][j-1][0] - price)
                dp[i+1][j][2] = max(dp[i][j][2], dp[i][j-1][0] + price)
        return dp[-1][-1][0]
```

## 解题方法三：动态规划+空间优化

不难发现第$i$天（dp[i+1][xx][x]）数据仅和第$i-1$天有关（dp[i][xx][x]），因此可以优化掉数组第一维。

注意j要倒序遍历，因为j依赖的是上一天的j-1，如果先更新j-1再更新j则会重复计算。

时空复杂度：

+ 时间复杂度$O(len(prices)\times k)$
+ 空间复杂度$O(k)$

### AC代码

#### Python

```python

```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/156029259)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/12/17/LeetCode%203573.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BAV/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
