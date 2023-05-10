---
title: 1799.N 次操作后的最大分数和
date: 2022-12-22 15:34:21
tags: [题解, LeetCode, 困难, 位运算, 数组, 数学, 动态规划, 回溯, 状态压缩, 数论, 二进制枚举, DP]
---

# 【LetMeFly】1799.N 次操作后的最大分数和

力扣题目链接：[https://leetcode.cn/problems/maximize-score-after-n-operations/](https://leetcode.cn/problems/maximize-score-after-n-operations/)

<p>给你 <code>nums</code> ，它是一个大小为 <code>2 * n</code> 的正整数数组。你必须对这个数组执行 <code>n</code> 次操作。</p>

<p>在第 <code>i</code> 次操作时（操作编号从 <strong>1</strong> 开始），你需要：</p>

<ul>
	<li>选择两个元素 <code>x</code> 和 <code>y</code> 。</li>
	<li>获得分数 <code>i * gcd(x, y)</code> 。</li>
	<li>将 <code>x</code> 和 <code>y</code> 从 <code>nums</code> 中删除。</li>
</ul>

<p>请你返回 <code>n</code> 次操作后你能获得的分数和最大为多少。</p>

<p>函数 <code>gcd(x, y)</code> 是 <code>x</code> 和 <code>y</code> 的最大公约数。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [1,2]
<b>输出：</b>1
<b>解释：</b>最优操作是：
(1 * gcd(1, 2)) = 1
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [3,4,6,8]
<b>输出：</b>11
<b>解释：</b>最优操作是：
(1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = [1,2,3,4,5,6]
<b>输出：</b>14
<b>解释：</b>最优操作是：
(1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 7</code></li>
	<li><code>nums.length == 2 * n</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>


    
## 方法一：状压DP（状态压缩 + 动态规划）

首先预处理将$nums[i]$和$nums[j]$的最大公因数计算出来存入$gcd[i][j]$中（其中$0\leq i<j<n$）

```cpp
int n = nums.size();
int gcd[n][n];
for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
        gcd[i][j] = __gcd(nums[i], nums[j]);
```

然后开辟一个大小为$2^n$的数组$dp[1<<n]$，其中$dp[i]$代表状态为$i$时或获得的最大分数。

从小到大枚举所有的状态（最大$1<<n$）

```cpp
int mask = 1 << n;
vector<int> dp(mask, 0);
for (int state = 0; state < mask; state++) {
	...
}
```

对于每个状态$state$，首先计算$state$在二进制下有多少个$1$

如果$state$在二进制下有偶数个$1$，那么就枚举其中$1$的位置，让其中的$1$两两配对，同时更新$dp[state]$的最大值

> 假设我们让其中的第$i$位和第$j$位配对了，那么$dp[state]$就可以由（$ij$配对）和（剩下的元素配对$dp[state - (1 << i) - (1 << j)]$）加起来得到。

+ 时间复杂度$O(2^n\times n^2)$
+ 空间复杂度$O(2^n+n^2)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        int gcd[n][n];
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                gcd[i][j] = __gcd(nums[i], nums[j]);
        int mask = 1 << n;
        vector<int> dp(mask, 0);
        for (int state = 0; state < mask; state++) {
            int one = __builtin_popcount(state);
            if (one % 2)
                continue;
            for (int i = 0; i < n; i++) {
                if (state & (1 << i)) {
                    for (int j = i + 1; j < n; j++) {
                        if (state & (1 << j)) {
                            dp[state] = max(dp[state], dp[state - (1 << i) - (1 << j)] + one / 2 * gcd[i][j]);
                        }
                    }
                }
            }
        }
        return dp[mask - 1];
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/12/22/LeetCode%201799.N%E6%AC%A1%E6%93%8D%E4%BD%9C%E5%90%8E%E7%9A%84%E6%9C%80%E5%A4%A7%E5%88%86%E6%95%B0%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128409728](https://letmefly.blog.csdn.net/article/details/128409728)
