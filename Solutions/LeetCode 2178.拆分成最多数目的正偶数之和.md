---
title: 2178.拆分成最多数目的正偶数之和
date: 2023-07-06 07:47:08
tags: [题解, LeetCode, 中等, 贪心, 数学, 回溯, 思维]
---

# 【LetMeFly】2178.拆分成最多数目的正偶数之和

力扣题目链接：[https://leetcode.cn/problems/maximum-split-of-positive-even-integers/](https://leetcode.cn/problems/maximum-split-of-positive-even-integers/)

<p>给你一个整数&nbsp;<code>finalSum</code>&nbsp;。请你将它拆分成若干个&nbsp;<strong>互不相同</strong> 的正偶数之和，且拆分出来的正偶数数目&nbsp;<strong>最多</strong>&nbsp;。</p>

<ul>
	<li>比方说，给你&nbsp;<code>finalSum = 12</code>&nbsp;，那么这些拆分是&nbsp;<strong>符合要求</strong> 的（互不相同的正偶数且和为&nbsp;<code>finalSum</code>）：<code>(2 + 10)</code>&nbsp;，<code>(2 + 4 + 6)</code>&nbsp;和&nbsp;<code>(4 + 8)</code>&nbsp;。它们中，<code>(2 + 4 + 6)</code>&nbsp;包含最多数目的整数。注意&nbsp;<code>finalSum</code>&nbsp;不能拆分成&nbsp;<code>(2 + 2 + 4 + 4)</code>&nbsp;，因为拆分出来的整数必须互不相同。</li>
</ul>

<p>请你返回一个整数数组，表示将整数拆分成 <strong>最多</strong> 数目的正偶数数组。如果没有办法将&nbsp;<code>finalSum</code>&nbsp;进行拆分，请你返回一个&nbsp;<strong>空</strong>&nbsp;数组。你可以按 <b>任意</b>&nbsp;顺序返回这些整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>finalSum = 12
<b>输出：</b>[2,4,6]
<b>解释：</b>以下是一些符合要求的拆分：<code>(2 + 10)<span style="">，</span></code><code>(2 + 4 + 6) </code>和 <code>(4 + 8) 。</code>
(2 + 4 + 6) 为最多数目的整数，数目为 3 ，所以我们返回 [2,4,6] 。
[2,6,4] ，[6,2,4] 等等也都是可行的解。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>finalSum = 7
<b>输出：</b>[]
<b>解释：</b>没有办法将 finalSum 进行拆分。
所以返回空数组。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>finalSum = 28
<b>输出：</b>[6,8,2,12]
<b>解释：</b>以下是一些符合要求的拆分：<code>(2 + 26)<span style="">，</span></code><code>(6 + 8 + 2 + 12)</code> 和 <code>(4 + 24) 。</code>
<code>(6 + 8 + 2 + 12)</code> 有最多数目的整数，数目为 4 ，所以我们返回 [6,8,2,12] 。
[10,2,4,12] ，[6,2,4,16] 等等也都是可行的解。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= finalSum &lt;= 10<sup>10</sup></code></li>
</ul>


    
## 方法一：贪心（数学）

+ 如果finalNum为奇数，那么一定不能被拆成偶数之和
+ 否则，一定能够被分为数个不同的偶数

贪心，从最小的正偶数$2$开始尝试，如果$finalNum - 2 > 2$，就说明finalNum里面能够划分出一个$2$，并且划分出2之后剩余的偶数大于2；

之后尝试能否在剩下的数中划分出来一个4、6、...，直到不可划分为止。

+ 时间复杂度$O(\sqrt(finalNum))$，$2+4+6+\cdots + 2n = n(n+1)\approx n^2\approx finalNum$，因此$n\approx \sqrt{finalNum}$
+ 空间复杂度$O(1)$，力扣算法返回的结果不计入算法的空间复杂度

### AC代码

#### C++

```cpp
typedef long long ll;

class Solution {
public:
    vector<ll> maximumEvenSplit(ll finalSum) {
        if (finalSum % 2) {
            return {};
        }
        vector<ll> ans;
        ll now = 2;
        while (finalSum - now > now) {
            ans.push_back(now);
            finalSum -= now;
            now += 2;
        }
        ans.push_back(finalSum);
        return ans;
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def maximumEvenSplit(self, finalSum: int) -> List[int]:
        if finalSum % 2:
            return []
        ans = []
        now = 2
        while finalSum - now > now:
            ans.append(now)
            finalSum -= now
            now += 2
        ans.append(finalSum)
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/07/06/LeetCode%202178.%E6%8B%86%E5%88%86%E6%88%90%E6%9C%80%E5%A4%9A%E6%95%B0%E7%9B%AE%E7%9A%84%E6%AD%A3%E5%81%B6%E6%95%B0%E4%B9%8B%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131567568](https://letmefly.blog.csdn.net/article/details/131567568)
