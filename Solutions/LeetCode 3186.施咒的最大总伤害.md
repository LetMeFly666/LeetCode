---
title: 3186.施咒的最大总伤害：动态规划+双指针——O(1)空间（暂未发现其他O(1)空间的题解）
date: 2025-10-11 19:05:05
tags: [题解, LeetCode, 中等, 数组, 哈希表, map, 双指针, 二分查找, 动态规划, DP, 计数, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】3186.施咒的最大总伤害：动态规划+双指针——O(1)空间（暂未发现其他O(1)空间的题解）

力扣题目链接：[https://leetcode.cn/problems/maximum-total-damage-with-spell-casting/](https://leetcode.cn/problems/maximum-total-damage-with-spell-casting/)

<p>一个魔法师有许多不同的咒语。</p>

<p>给你一个数组&nbsp;<code>power</code>&nbsp;，其中每个元素表示一个咒语的伤害值，可能会有多个咒语有相同的伤害值。</p>

<p>已知魔法师使用伤害值为&nbsp;<code>power[i]</code>&nbsp;的咒语时，他们就&nbsp;<strong>不能</strong>&nbsp;使用伤害为&nbsp;<code>power[i] - 2</code>&nbsp;，<code>power[i] - 1</code>&nbsp;，<code>power[i] + 1</code>&nbsp;或者&nbsp;<code>power[i] + 2</code>&nbsp;的咒语。</p>

<p>每个咒语最多只能被使用 <strong>一次</strong>&nbsp;。</p>

<p>请你返回这个魔法师可以达到的伤害值之和的 <strong>最大值</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>power = [1,1,3,4]</span></p>

<p><span class="example-io"><b>输出：</b>6</span></p>

<p><strong>解释：</strong></p>

<p>可以使用咒语 0，1，3，伤害值分别为 1，1，4，总伤害值为 6 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>power = [7,1,6,6]</span></p>

<p><span class="example-io"><b>输出：</b>13</span></p>

<p><strong>解释：</strong></p>

<p>可以使用咒语 1，2，3，伤害值分别为 1，6，6，总伤害值为 13 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= power.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= power[i] &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法一：动态规划（O(n)空间）

首先二话不说对power数组来个哈希表统计和排序，得到这样的数组：`[<1出现2次>, <3出现1次>, ...]`。排序依据是power小的优先。

创建动态规划数组，dp[i+1]表示power[0]到power[i]所能达到的最大总伤害（dp[0]=0，此处power[i]代表排序后）。

这样就有状态转移方程：

$dp[i+1]=\max(dp[i], dp[j]+thisVal)$

其中$dp[i]$代表不使用当前power，$dp[j]$是最后一个满足$\lt power[i]-2$的power，$thisVal$代表使用这个power产生的总能量（$thisVal=power[i]\times times[i]$）。

现在就剩下最后一个问题了，如何快速得到小于$power[i]-2$的最大power是谁，也就是如何得到j的大小。

双指针即可。每当处理一个新$power[i]$时，当$power[j]\lt power[i]-2$时不断另$j+=1$即可。

+ 时间复杂度$O(n\log n)$，其中$n=len(power)$，时间复杂度的来源主要是排序
+ 空间复杂度$O(n)$，空间复杂度的来源主要是动态规划数组

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2025-10-11 18:38:56
 */
typedef long long ll;
class Solution {
public:
    ll maximumTotalDamage(vector<int>& power) {
        unordered_map<int, int> cnt;
        for (int t : power) {
            cnt[t]++;
        }
        vector<pair<int, int>> values(cnt.begin(), cnt.end());
        sort(values.begin(), values.end());
        vector<ll> dp(values.size() + 1);
        for (int i = 0, j = 0; i < values.size(); i++) {
            auto& [value, times] = values[i];
            while (values[j].first < value - 2) {
                j++;
            }
            dp[i + 1] = max(dp[i], dp[j] + (ll) value * times);
        }
        return dp.back();
    }
};

```



#### Python

```python
'''
Author: LetMeFly
Date: 2025-10-11 18:10:29
LastEditors: LetMeFly.xyz
LastEditTime: 2025-10-11 18:46:52
'''
from typing import List
from collections import Counter

class Solution:
    def maximumTotalDamage(self, power: List[int]) -> int:
        cnt = Counter(power)
        values = sorted(cnt)
        dp = [0] * (len(values) + 1)
        j = 0
        for i, val in enumerate(values):
            while values[j] < val - 2:
                j += 1
            dp[i + 1] = max(dp[i], dp[j] + val * cnt[val])
        return dp[-1]
```

## 解题方法二：动态规划（O(1)空间）

不难发现方法一中空间复杂度的来源主要是动态规划数组，并且不难发现动态规划数组只需要利用到最近几个。

这是因为和power[i]冲突的power范围向前看也就有个$power[i]-1$和$power[i]-2$，假设power中有这两个值，那么至多也就会用到两个前面的dp值。

所以可以使用数个变量来完成dp数组的原地滚动。

+ 时间复杂度$O(n\log n)$，其中$n=len(power)$，时间复杂度的来源主要是排序
+ 空间复杂度$O(1)$，相比于方法一，原地滚动大大简化了动态规划数组所需的空间

### AC代码

#### Python

```python
'''
Author: LetMeFly
Date: 2025-10-11 18:10:29
LastEditors: LetMeFly.xyz
LastEditTime: 2025-10-11 19:04:17
'''
from typing import List
from collections import Counter

class Solution:
    def maximumTotalDamage(self, power: List[int]) -> int:
        cnt = Counter(power)
        values = sorted(cnt)
        dp0 = dp1 = dp2 = 0
        val1 = val2 = -10
        for val in values:
            valSum = val * cnt[val]
            if val - val2 > 2:  # 无冲突
                useThis = valSum + dp2
            elif val - val1 > 2:  # 和val2相差小于2，但和val1不冲突
                useThis = valSum + dp1
            else:  # 和val1、val2都冲突(一定不会再和前面的冲突了)
                useThis = valSum + dp0
            dp = max(useThis, dp2)
            dp0, dp1, dp2 = dp1, dp2, dp
            val1, val2 = val2, val
        return dp2
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/153067130)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/10/11/LeetCode%203186.%E6%96%BD%E5%92%92%E7%9A%84%E6%9C%80%E5%A4%A7%E6%80%BB%E4%BC%A4%E5%AE%B3/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
