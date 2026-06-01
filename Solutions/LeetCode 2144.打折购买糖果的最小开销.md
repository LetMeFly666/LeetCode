---
title: 2144.打折购买糖果的最小开销：贪心
date: 2026-06-01 22:25:22
tags: [题解, LeetCode, 简单, 贪心, 数组, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】2144.打折购买糖果的最小开销：贪心

力扣题目链接：[https://leetcode.cn/problems/minimum-cost-of-buying-candies-with-discount/](https://leetcode.cn/problems/minimum-cost-of-buying-candies-with-discount/)

<p>一家商店正在打折销售糖果。每购买 <strong>两个</strong>&nbsp;糖果，商店会 <strong>免费</strong>&nbsp;送一个糖果。</p>

<p>免费送的糖果唯一的限制是：它的价格需要小于等于购买的两个糖果价格的 <strong>较小值</strong>&nbsp;。</p>

<ul>
	<li>比方说，总共有 <code>4</code>&nbsp;个糖果，价格分别为&nbsp;<code>1</code>&nbsp;，<code>2</code>&nbsp;，<code>3</code>&nbsp;和&nbsp;<code>4</code>&nbsp;，一位顾客买了价格为&nbsp;<code>2</code> 和&nbsp;<code>3</code>&nbsp;的糖果，那么他可以免费获得价格为 <code>1</code>&nbsp;的糖果，但不能获得价格为&nbsp;<code>4</code>&nbsp;的糖果。</li>
</ul>

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>cost</code>&nbsp;，其中&nbsp;<code>cost[i]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;个糖果的价格，请你返回获得 <strong>所有</strong>&nbsp;糖果的 <strong>最小</strong>&nbsp;总开销。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>cost = [1,2,3]
<b>输出：</b>5
<b>解释：</b>我们购买价格为 2 和 3 的糖果，然后免费获得价格为 1 的糖果。
总开销为 2 + 3 = 5 。这是开销最小的 <strong>唯一</strong>&nbsp;方案。
注意，我们不能购买价格为 1 和 3 的糖果，并免费获得价格为 2 的糖果。
这是因为免费糖果的价格必须小于等于购买的 2 个糖果价格的较小值。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>cost = [6,5,7,9,2,2]
<b>输出：</b>23
<b>解释：</b>最小总开销购买糖果方案为：
- 购买价格为 9 和 7 的糖果
- 免费获得价格为 6 的糖果
- 购买价格为 5 和 2 的糖果
- 免费获得价格为 2 的最后一个糖果
因此，最小总开销为 9 + 7 + 5 + 2 = 23 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>cost = [5,5]
<b>输出：</b>10
<b>解释：</b>由于只有 2 个糖果，我们需要将它们都购买，而且没有免费糖果。
所以总最小开销为 5 + 5 = 10 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= cost.length &lt;= 100</code></li>
	<li><code>1 &lt;= cost[i] &lt;= 100</code></li>
</ul>


    
## 解题方法：贪心

想省钱，那就尽可能免费领大的。但是免费领的不能比买的两个贵，所以为了免费领尽可能贵的，就要尽可能买更贵的。

所以我们从最贵的往便宜的开始买就好了，每买两个就免费领取一个。

+ 时间复杂度$O(n\log n)$，其中$n=len(cost)$
+ 空间复杂度$O(\log n)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-06-01 22:07:10
 */
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int ans = 0;
        sort(cost.begin(), cost.end(), greater<>());
        for (int i = 0, n = cost.size(), cnt = 0; i < n; i++) {
            if (cnt == 2) {
                cnt = 0;
            } else {
                ans += cost[i];
                cnt++;
            }
        }
        return ans;
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-06-01 22:13:03
'''
from typing import List

class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        cost.sort(reverse=True)
        return sum(cost) - sum(cost[2::3])
```

#### Java

```java
/*
 * @LastEditTime: 2026-06-01 22:11:38
 */
import java.util.Arrays;

class Solution {
    public int minimumCost(int[] cost) {
        int ans = 0;
        Arrays.sort(cost);
        for (int i = cost.length - 1; i >= 0; i -= 3) {
            ans += cost[i];
            if (i > 0) {
                ans += cost[i - 1];
            }
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2026-06-01 22:10:30
 */
package main

import "sort"

func minimumCost(cost []int) (ans int) {
    sort.Ints(cost);
    for i, cnt := len(cost) - 1, 0; i >= 0; i-- {
        if cnt == 2 {
            cnt = 0
        } else {
            ans += cost[i];
            cnt++
        }
    }
    return
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-06-01 22:24:39
 */
impl Solution {
    pub fn minimum_cost(mut cost: Vec<i32>) -> i32 {
        let mut ans = 0;
        cost.sort_unstable();
        let mut cnt = 0;
        for i in (0..cost.len()).rev() {
            if cnt == 2 {
                cnt = 0;
            } else {
                ans += cost[i];
                cnt += 1;
            }
        }
        ans
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/161602222)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/06/01/LeetCode%202144.%E6%89%93%E6%8A%98%E8%B4%AD%E4%B9%B0%E7%B3%96%E6%9E%9C%E7%9A%84%E6%9C%80%E5%B0%8F%E5%BC%80%E9%94%80/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
