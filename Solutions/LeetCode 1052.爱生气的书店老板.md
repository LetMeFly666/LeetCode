---
title: 1052.爱生气的书店老板
date: 2024-04-23 21:15:30
tags: [题解, LeetCode, 中等, 数组, 滑动窗口]
categories: [题解, LeetCode]
---

# 【LetMeFly】1052.爱生气的书店老板：滑动窗口

力扣题目链接：[https://leetcode.cn/problems/grumpy-bookstore-owner/](https://leetcode.cn/problems/grumpy-bookstore-owner/)

<p>有一个书店老板，他的书店开了&nbsp;<code>n</code>&nbsp;分钟。每分钟都有一些顾客进入这家商店。给定一个长度为 <code>n</code> 的整数数组 <code>customers</code> ，其中 <code>customers[i]</code> 是在第 <code>i</code> 分钟开始时进入商店的顾客数量，所有这些顾客在第 <code>i</code> 分钟结束后离开。</p>

<p>在某些时候，书店老板会生气。 如果书店老板在第 <code>i</code> 分钟生气，那么 <code>grumpy[i] = 1</code>，否则 <code>grumpy[i] = 0</code>。</p>

<p>当书店老板生气时，那一分钟的顾客就会不满意，若老板不生气则顾客是满意的。</p>

<p>书店老板知道一个秘密技巧，能抑制自己的情绪，可以让自己连续&nbsp;<code>minutes</code>&nbsp;分钟不生气，但却只能使用一次。</p>

<p>请你返回 <em>这一天营业下来，最多有多少客户能够感到满意</em> 。<br />
&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3
<strong>输出：</strong>16
<strong>解释：</strong>书店老板在最后 3 分钟保持冷静。
感到满意的最大客户数量 = 1 + 1 + 1 + 1 + 7 + 5 = 16.
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>customers = [1], grumpy = [0], minutes = 1
<strong>输出：</strong>1</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == customers.length == grumpy.length</code></li>
	<li><code>1 &lt;= minutes &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= customers[i] &lt;= 1000</code></li>
	<li><code>grumpy[i] == 0 or 1</code></li>
</ul>


    
## 解题方法：滑动窗口

首先计算出$0$到$minutes - 1$分钟不生气的结果。之后从此基础上开始一分钟一分钟地往右移（滑动）：

> 不生气的起始时间加一，不生气的结束时间同时加一。（这样不生气的时间长度```窗口大小```就不会变化）
>
> 计算这两个更改所导致的满意顾客数量的变化。

直到“窗口”的右边界到达数组的末尾，这样我们就计算了所有可能的“不生气区间”。

将所有结果中最优的那个做为答案即可。

+ 时间复杂度$O(len(customers))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int thisAns = 0;
        for (int i = 0; i < minutes; i++) {
            thisAns += customers[i];
        }
        for (int i = minutes; i < customers.size(); i++) {
            if (!grumpy[i]) {
                thisAns += customers[i];
            }
        }
        int ans = thisAns;
        for (int r = minutes; r < customers.size(); r++) {
            if (grumpy[r]) {  // 1 -> 0
                thisAns += customers[r];
            }
            if (grumpy[r - minutes]) {  // 0 -> 1
                thisAns -= customers[r - minutes];
            }
            ans = max(ans, thisAns);
            // printf("[%d -> %d] -> %d\n", r - minutes + 1, r, thisAns);  //*************
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        thisAns = sum(customers[i] for i in range(minutes)) + sum(customers[i] if not grumpy[i] else 0 for i in range(minutes, len(customers)))
        ans = thisAns
        for r in range(minutes, len(customers)):
            thisAns += customers[r] * grumpy[r] - customers[r - minutes] * grumpy[r - minutes]
            ans = max(ans, thisAns)
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/04/23/LeetCode%201052.%E7%88%B1%E7%94%9F%E6%B0%94%E7%9A%84%E4%B9%A6%E5%BA%97%E8%80%81%E6%9D%BF/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/138139013](https://letmefly.blog.csdn.net/article/details/138139013)
