---
title: 1155.掷骰子等于目标和的方法数：动态规划
date: 2023-10-24 14:29:25
tags: [题解, LeetCode, 中等, 动态规划, DP]
categories: [题解, LeetCode]
---

# 【LetMeFly】1155.掷骰子等于目标和的方法数：动态规划

力扣题目链接：[https://leetcode.cn/problems/number-of-dice-rolls-with-target-sum/](https://leetcode.cn/problems/number-of-dice-rolls-with-target-sum/)

<p>这里有&nbsp;<code>n</code>&nbsp;个一样的骰子，每个骰子上都有&nbsp;<code>k</code>&nbsp;个面，分别标号为&nbsp;<code>1</code>&nbsp;到 <code>k</code> 。</p>

<p>给定三个整数 <code>n</code> ,&nbsp; <code>k</code> 和&nbsp;<code>target</code>&nbsp;，返回可能的方式(从总共<em>&nbsp;</em><code>k<sup>n</sup></code><em>&nbsp;</em>种方式中)滚动骰子的数量，使正面朝上的数字之和等于<em>&nbsp;</em><code>target</code>&nbsp;。</p>

<p>答案可能很大，你需要对&nbsp;<code>10<sup>9</sup>&nbsp;+ 7</code> <strong>取模</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 1, k = 6, target = 3
<strong>输出：</strong>1
<strong>解释：</strong>你扔一个有 6 个面的骰子。
得到 3 的和只有一种方法。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 2, k = 6, target = 7
<strong>输出：</strong>6
<strong>解释：</strong>你扔两个骰子，每个骰子有 6 个面。
得到 7 的和有 6 种方法：1+6 2+5 3+4 4+3 5+2 6+1。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 30, k = 30, target = 500
<strong>输出：</strong>222616187
<strong>解释：</strong>返回的结果必须是对 10<sup>9</sup> + 7 取模。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n, k &lt;= 30</code></li>
	<li><code>1 &lt;= target &lt;= 1000</code></li>
</ul>


    
## 方法一：动态规划(DP)

开辟一个动态规划数组$dp$，其中$dp[i][j]$代表$i$个骰子的和为$j$的方案数。

初始值$dp[i][j]=0$，而$dp[1][1-k]=1$。

这样，我们就可以从第二天开始枚举：

```python
for i from 2 to n:  # i个骰子
   for j from 1 to target:  # 和为j
       for _k from 1 to min(k, target):  # i个骰子和为j，可以由 i-1个骰子和为j-_k 加上 一个值为_k的骰子 得到
	       dp[i][j] = (dp[i][j] + dp[i - 1][j - _k]) % MOD
```

**优化：**

1. 不难发现$i$个骰子的状态只和$i-1$个骰子的状态有关，因此可以将二维数组压缩为一维。
2. 我们初始化了1个骰子从1到k的方案数为1，其实我们也可以只领$dp[0][0]=1$（0个骰子和为0的方案数为1）

复杂的分析

+ 时间复杂度$O(n\times k\times target)$
+ 空间复杂度$O(n\times target)$或$O(target)$

### AC代码

#### C++

没有进行空间优化：

```cpp
typedef long long ll;
const ll MOD = 1e9 + 7;
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<ll>> dp(n + 1, vector<ll>(target + 1, 0));
        for (int j = 1; j <= min(k, target); j++) {
            dp[1][j] = 1;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                for (int _k = 1; _k <= min(k, j); _k++) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - _k]) % MOD;
                }
            }
        }
        return dp[n][target];
    }
};
```

#### Python

进行了空间优化：

```python
MOD = int(1e9 + 7)
class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        dp = [1] + [0] * target
        for i in range(1, n + 1):
            for j in range(target, -1, -1):
                dp[j] = 0
                for _k in range(1, min(k + 1, j + 1)):
                    dp[j] = (dp[j] + dp[j - _k]) % MOD
        return dp[-1]
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/10/24/LeetCode%201155.%E6%8E%B7%E9%AA%B0%E5%AD%90%E7%AD%89%E4%BA%8E%E7%9B%AE%E6%A0%87%E5%92%8C%E7%9A%84%E6%96%B9%E6%B3%95%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/134023955](https://letmefly.blog.csdn.net/article/details/134023955)
