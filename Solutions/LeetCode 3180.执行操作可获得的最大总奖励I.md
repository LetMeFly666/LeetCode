---
title: 3180.执行操作可获得的最大总奖励 I
date: 2024-10-28 21:39:26
tags: [题解, LeetCode, 中等, 数组, 动态规划, DP]
categories: [题解, LeetCode]
---

# 【LetMeFly】3180.执行操作可获得的最大总奖励 I：动态规划

力扣题目链接：[https://leetcode.cn/problems/maximum-total-reward-using-operations-i/](https://leetcode.cn/problems/maximum-total-reward-using-operations-i/)

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
	<li><code>1 &lt;= rewardValues.length &lt;= 2000</code></li>
	<li><code>1 &lt;= rewardValues[i] &lt;= 2000</code></li>
</ul>


    
## 解题方法：动态规划

使用一个布尔类型的数组$dp$，其中$dp[i]$代表总奖励$i$是否有办法达到。初始值除了$dp[0]$为$true$外其余值全部为$false$。假设$rewardValues$中的最大元素为$M$，则总奖励一定不会超过$M - 1 + M$，因此数组大小为$2 * M$。

不失一般性，我们先对给定数组排个序。遍历数值中的每个元素，假设当前元素为$x$，那么$[0, x - 1]$范围内的任意一个“奖励都能加上$x$”。也就是说，如果$dp[i]$为$true$，那么$dp[i + x]$也将为$true$，其中$0\leq i\leq x - 1$。

因此有状态转移方程$dp[i + x] |= dp[i]$，其中$0\leq i\leq x - 1$。

+ 时间复杂度$O(n\log n + nm)$，其中$n=len(rewardValues), m = \max(rewardValues)$
+ 空间复杂度$O(\log n + m)$

时空复杂度上如果想除以一个系统位数，可以考虑[【LetMeFly】3181.执行操作可获得的最大总奖励 II：动态规划+位运算优化](https://blog.letmefly.xyz/2024/10/30/LeetCode%203181.%E6%89%A7%E8%A1%8C%E6%93%8D%E4%BD%9C%E5%8F%AF%E8%8E%B7%E5%BE%97%E7%9A%84%E6%9C%80%E5%A4%A7%E6%80%BB%E5%A5%96%E5%8A%B1II/)的位运算优化

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        vector<bool> dp(rewardValues.back() * 2);
        dp[0] = true;
        for (int t : rewardValues) {  // [t + 0, t + t - 1]
            for (int x = t * 2 - 1; x >= t; x--) {
                dp[x] = dp[x] | dp[x - t];  // dp[x] |= dp[x - t];
            }
        }
        int ans = dp.size() - 1;
        while (!dp[ans]) {
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
        dp = [False] * (rewardValues[-1] * 2)
        dp[0] = True
        for x in rewardValues:  # [0, x - 1] + x -> [x, 2x - 1]
            for i in range(x, 2 * x):  # 这里面任意一个i加上一次x后就会>2x，因此x不会被计算两次
                dp[i] |= dp[i - x]
        ans = len(dp) - 1
        while not dp[ans]:
            ans -= 1
        return ans
```

#### Go

```go
package main

import "sort"

func maxTotalReward(rewardValues []int) int {
    sort.Ints(rewardValues)
    dp := make([]bool, 2 * rewardValues[len(rewardValues) - 1])
    dp[0] = true
    for _, x := range rewardValues {
        for i := x; i < 2 * x; i++ {
            // dp[i] = dp[i] | dp[i - x]
            // var a, b bool = true, false
            // a |= b
            // a = a | b
            if dp[i - x] {
                dp[i] = true
            }
        }
    }
    ans := len(dp) - 1
    for !dp[ans] {
        ans--
    }
    return ans
}
```

#### Java

```java
import java.util.Arrays;

class Solution {
    public int maxTotalReward(int[] rewardValues) {
        Arrays.sort(rewardValues);
        boolean[] dp = new boolean[2 * rewardValues[rewardValues.length - 1]];
        dp[0] = true;
        for (int x : rewardValues) {
            for (int i = x; i < 2 * x; i++) {
                dp[i] |= dp[i - x];
            }
        }
        int ans = dp.length - 1;
        while (!dp[ans]) {
            ans--;
        }
        return ans;
    }
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/10/28/LeetCode%203180.%E6%89%A7%E8%A1%8C%E6%93%8D%E4%BD%9C%E5%8F%AF%E8%8E%B7%E5%BE%97%E7%9A%84%E6%9C%80%E5%A4%A7%E6%80%BB%E5%A5%96%E5%8A%B1I/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/143314587](https://letmefly.blog.csdn.net/article/details/143314587)
