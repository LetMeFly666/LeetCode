---
title: 2706.购买两块巧克力
date: 2023-12-29 16:58:52
tags: [题解, LeetCode, 简单, 数组, 排序, 遍历]
---

# 【LetMeFly】2706.购买两块巧克力：一次遍历（O(n) + O(1)）

力扣题目链接：[https://leetcode.cn/problems/buy-two-chocolates/](https://leetcode.cn/problems/buy-two-chocolates/)

<p>给你一个整数数组&nbsp;<code>prices</code>&nbsp;，它表示一个商店里若干巧克力的价格。同时给你一个整数&nbsp;<code>money</code>&nbsp;，表示你一开始拥有的钱数。</p>

<p>你必须购买 <strong>恰好&nbsp;</strong>两块巧克力，而且剩余的钱数必须是 <strong>非负数</strong>&nbsp;。同时你想最小化购买两块巧克力的总花费。</p>

<p>请你返回在购买两块巧克力后，最多能剩下多少钱。如果购买任意两块巧克力都超过了你拥有的钱，请你返回 <code>money</code>&nbsp;。注意剩余钱数必须是非负数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>prices = [1,2,2], money = 3
<b>输出：</b>0
<b>解释：</b>分别购买价格为 1 和 2 的巧克力。你剩下 3 - 3 = 0 块钱。所以我们返回 0 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>prices = [3,2,3], money = 3
<b>输出：</b>3
<b>解释：</b>购买任意 2 块巧克力都会超过你拥有的钱数，所以我们返回 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= prices.length &lt;= 50</code></li>
	<li><code>1 &lt;= prices[i] &lt;= 100</code></li>
	<li><code>1 &lt;= money &lt;= 100</code></li>
</ul>


    
## 方法一：一次遍历

使用两个变量$m1$和$m2$来维护“最便宜的两块巧克力的价格”，并且保证，在每次操作结束后满足$m1\leq m2$。

这样，我们只需要遍历价格数组，如果当前价格$p\lt m2$，则说明这个价格具有“利用价值”，令$m2=p$。如果$m1\gt m2$，则交换二者。

遍历结束后我们便得到了价格最低的两块巧克力。

+ 时间复杂度$O(len(prices))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int m1 = 1000, m2 = 1000;  // 令m1 <= m2
        for (int p : prices) {
            if (p < m2) {
                m2 = p;
                if (m1 > m2) {
                    swap(m1, m2);
                }
            }
        }
        return m1 + m2 > money ? money : money - m1 - m2;
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        m1, m2 = 1000, 1000
        for p in prices:
            if p < m2:
                m2 = p
                if m1 > m2:
                    m1, m2 = m2, m1
        return money if m1 + m2 > money else money - m1 - m2
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/12/29/LeetCode%202706.%E8%B4%AD%E4%B9%B0%E4%B8%A4%E5%9D%97%E5%B7%A7%E5%85%8B%E5%8A%9B/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135295305](https://letmefly.blog.csdn.net/article/details/135295305)
