---
title: 2240.买钢笔和铅笔的方案数
date: 2023-09-01 09:37:06
tags: [题解, LeetCode, 中等, 数学, 枚举]
---

# 【LetMeFly】2240.买钢笔和铅笔的方案数

力扣题目链接：[https://leetcode.cn/problems/number-of-ways-to-buy-pens-and-pencils/](https://leetcode.cn/problems/number-of-ways-to-buy-pens-and-pencils/)

<p>给你一个整数&nbsp;<code>total</code>&nbsp;，表示你拥有的总钱数。同时给你两个整数&nbsp;<code>cost1</code> 和&nbsp;<code>cost2</code>&nbsp;，分别表示一支钢笔和一支铅笔的价格。你可以花费你部分或者全部的钱，去买任意数目的两种笔。</p>

<p>请你返回购买钢笔和铅笔的&nbsp;<strong>不同方案数目</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>total = 20, cost1 = 10, cost2 = 5
<b>输出：</b>9
<b>解释：</b>一支钢笔的价格为 10 ，一支铅笔的价格为 5 。
- 如果你买 0 支钢笔，那么你可以买 0 ，1 ，2 ，3 或者 4 支铅笔。
- 如果你买 1 支钢笔，那么你可以买 0 ，1 或者 2 支铅笔。
- 如果你买 2 支钢笔，那么你没法买任何铅笔。
所以买钢笔和铅笔的总方案数为 5 + 3 + 1 = 9 种。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>total = 5, cost1 = 10, cost2 = 10
<b>输出：</b>1
<b>解释：</b>钢笔和铅笔的价格都为 10 ，都比拥有的钱数多，所以你没法购买任何文具。所以只有 1 种方案：买 0 支钢笔和 0 支铅笔。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= total, cost1, cost2 &lt;= 10<sup>6</sup></code></li>
</ul>


    
## 方法一：单方枚举

首先令$cost1 \leq cost2$（如果不，就swap(cost1, cost2)）。

我们可以算出最多买多少根钢笔2（$M2 = \lfloor \frac{total}{cost2} \rfloor$）。

这样，我们就可以从$0$到$M2$枚举钢笔2的个数。

购买了$i$个钢笔2时，购买钢笔1的方案数为$\lceil \frac{total - i \times cost2}{cost1} \rceil$。

+ 时间复杂度$O($\lfloor \frac{total}{cost2} \rfloor$)$（如果cost1不大于cost2就交换二者）
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
typedef long long ll;
class Solution {
public:
    ll waysToBuyPensPencils(int total, int cost1, int cost2) {
        ll ans = 0;
        if (cost1 > cost2) {  // let cost1 <= cost2
            swap(cost1, cost2);
        }
        int M2 = total / cost2;  // max2
        for (int i = 0; i <= M2; i++) {
            ans += (total - cost2 * i) / cost1 + 1;
        }
        return ans;
    }
};
```

#### Python

```python
class Solution:
    def waysToBuyPensPencils(self, total: int, cost1: int, cost2: int) -> int:
        if cost1 > cost2:
            cost1, cost2 = cost2, cost1
        ans = 0
        M2 = total // cost2
        for i in range(M2 + 1):
            ans += (total - i * cost2) // cost1 + 1
        return ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2023/09/01/LeetCode%202240.%E4%B9%B0%E9%92%A2%E7%AC%94%E5%92%8C%E9%93%85%E7%AC%94%E7%9A%84%E6%96%B9%E6%A1%88%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/132617507](https://letmefly.blog.csdn.net/article/details/132617507)
