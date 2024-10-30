---
title: 3181.执行操作可获得的最大总奖励 II
date: 2024-10-30 10:35:36
tags: [题解, LeetCode, 困难, 位运算, 数组, 动态规划, DP, bitset]
---

# 【LetMeFly】3181.执行操作可获得的最大总奖励 II：动态规划+位运算优化

力扣题目链接：[https://leetcode.cn/problems/maximum-total-reward-using-operations-ii/](https://leetcode.cn/problems/maximum-total-reward-using-operations-ii/)

<p>给你一个整数数组 <code>rewardValues</code>，长度为 <code>n</code>，代表奖励的值。</p>

<p>最初，你的总奖励 <code>x</code> 为 0，所有下标都是<strong> 未标记 </strong>的。你可以执行以下操作 <strong>任意次 </strong>：</p>

<ul>
	<li>从区间 <code>[0, n - 1]</code> 中选择一个 <strong>未标记 </strong>的下标 <code>i</code>。</li>
	<li>如果 <code>rewardValues[i]</code> <strong>大于</strong> 你当前的总奖励 <code>x</code>，则将 <code>rewardValues[i]</code> 加到 <code>x</code> 上（即 <code>x = x + rewardValues[i]</code>），并<strong> 标记</strong> 下标 <code>i</code>。</li>
</ul>

<p>以整数形式返回执行最优操作能够获得的<strong> 最大</strong><em> </em>总奖励。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">rewardValues = [1,1,3,3]</span></p>

<p><strong>输出：</strong><span class="example-io">4</span></p>

<p><strong>解释：</strong></p>

<p>依次标记下标 0 和 2，总奖励为 4，这是可获得的最大值。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">rewardValues = [1,6,4,3,2]</span></p>

<p><strong>输出：</strong><span class="example-io">11</span></p>

<p><strong>解释：</strong></p>

<p>依次标记下标 0、2 和 1。总奖励为 11，这是可获得的最大值。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= rewardValues.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= rewardValues[i] &lt;= 5 * 10<sup>4</sup></code></li>
</ul>


    
## 解题方法：动态规划

在[【LetMeFly】3180.执行操作可获得的最大总奖励 I：动态规划](https://blog.letmefly.xyz/2024/10/28/LeetCode%203180.%E6%89%A7%E8%A1%8C%E6%93%8D%E4%BD%9C%E5%8F%AF%E8%8E%B7%E5%BE%97%E7%9A%84%E6%9C%80%E5%A4%A7%E6%80%BB%E5%A5%96%E5%8A%B1I/)中，我们已经知道了$O(mn)$时间复杂度的算法：

> 使用$dp[i]$代表奖励$i$能否获得，对于奖励数组中的一个奖励$x$有转移公式$dp[i] |= dp[i - x]$，其中$0\leq i - x \lt x$。

本题增加了数据量，$\max(mn)=50000\times 50000=2500000000=2.5e9$，难以在$1$秒内完成计算，因此需要一些“并行计算”来降低一些时间复杂度：

> 不难发现，对于一个奖励$x$我们需要从$0$遍历到$x-1$，导致了$O(m)$的时间复杂度。
>
> 但实际上，$dp$数组的每一个元素都是一个布尔类型的数据，我要是把这些数据拼接起来（比如原来的一个bool类型的数据变成一个整数的某一位）是不是时空复杂度直接能除以一个整数位数/计算机字长呢？
>
> 现在我们将$dp$由布尔类型的数组变成一个很多位的大整数或[bitset](https://github.com/LetMeFly666/LeetCode/blob/07c3776fc5e2cb33a4b27b19ebb2b519d464e9ac/Codes/3181-maximum-total-reward-using-operations-ii-tryBitset.cpp)，对于$0\leq i\lt x$，$dp[i + x] |= dp[i]$就变成了$dp |= (dp低x位左移x位后的结果)$，因此问题就变成了如何获取$dp$这个大整数的低$x$位左移$x$位的结果。常见方法如：
>
> 1. 方法一（对于大整数）：首先获得一个低$x$位全为$1$的掩码$mask$（$mask = (1 << x) - 1$），然后取出$dp$的低$x$位（$dp \& mask$），将这个结果左移$x$位（$(dp \& mask) << x$）
> 2. 方法二（对于bitset）：先将$dp$左移$len(dp)-x$位再右移$len(dp)-x$位，则除了低$x$位以外都变成了$0$，再将其左移$x$位即可（$dp<<(len(dp)-x)>>(len(dp)-x)<<x$，等价于$dp<<(len(dp)-x)>>(len(dp)-2x)$）

+ 时间复杂度$O(n\log n+nm/w)$，其中$w$是整数位数或计算机字长，一般为$64$（或$32$），$\max(mn)=50000\times 50000/64=39,062,500\approx 3.9e7$
+ 空间复杂度$O(\log n+m/w)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        bitset<100000> dp = 1;  // 2 * (50000)
        for (int x : rewardValues) {
            // [0, x - 1]
            // dp |= dp << (100000 - x) >> (100000 - x) << x;
            dp |= dp << (100000 - x) >> (100000- 2 * x);
        }
        int ans = rewardValues.back() * 2 - 1;
        while (!dp.test(ans)) {
            ans--;
        }
        return ans;
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def maxTotalReward(self, rewardValues: List[int]) -> int:
        rewardValues.sort()
        dp = 1
        for x in rewardValues:
            dp |= (dp & ((1 << x) - 1)) << x
        return dp.bit_length() - 1
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/10/30/LeetCode%203181.%E6%89%A7%E8%A1%8C%E6%93%8D%E4%BD%9C%E5%8F%AF%E8%8E%B7%E5%BE%97%E7%9A%84%E6%9C%80%E5%A4%A7%E6%80%BB%E5%A5%96%E5%8A%B1II/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/143360617](https://letmefly.blog.csdn.net/article/details/143360617)
