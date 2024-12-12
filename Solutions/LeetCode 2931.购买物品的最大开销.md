---
title: 2931.购买物品的最大开销
date: 2024-12-12 14:51:52
tags: [题解, LeetCode, 困难, 贪心, 数组, 矩阵, 排序, 堆（优先队列）, 多指针]
---

# 【LetMeFly】2931.购买物品的最大开销：多指针（平均优于排序）

力扣题目链接：[https://leetcode.cn/problems/maximum-spending-after-buying-items/](https://leetcode.cn/problems/maximum-spending-after-buying-items/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始大小为&nbsp;<code>m * n</code>&nbsp;的整数矩阵&nbsp;<code>values</code>&nbsp;，表示&nbsp;<code>m</code>&nbsp;个不同商店里&nbsp;<code>m * n</code>&nbsp;件不同的物品。每个商店有 <code>n</code>&nbsp;件物品，第&nbsp;<code>i</code>&nbsp;个商店的第 <code>j</code>&nbsp;件物品的价值为&nbsp;<code>values[i][j]</code>&nbsp;。除此以外，第&nbsp;<code>i</code>&nbsp;个商店的物品已经按照价值非递增排好序了，也就是说对于所有&nbsp;<code>0 &lt;= j &lt; n - 1</code>&nbsp;都有&nbsp;<code>values[i][j] &gt;= values[i][j + 1]</code>&nbsp;。</p>

<p>每一天，你可以在一个商店里购买一件物品。具体来说，在第&nbsp;<code>d</code>&nbsp;天，你可以：</p>

<ul>
	<li>选择商店&nbsp;<code>i</code>&nbsp;。</li>
	<li>购买数组中最右边的物品&nbsp;<code>j</code>&nbsp;，开销为&nbsp;<code>values[i][j] * d</code>&nbsp;。换句话说，选择该商店中还没购买过的物品中最大的下标&nbsp;<code>j</code>&nbsp;，并且花费&nbsp;<code>values[i][j] * d</code>&nbsp;去购买。</li>
</ul>

<p><strong>注意</strong>，所有物品都视为不同的物品。比方说如果你已经从商店 <code>1</code>&nbsp;购买了物品&nbsp;<code>0</code>&nbsp;，你还可以在别的商店里购买其他商店的物品&nbsp;<code>0</code>&nbsp;。</p>

<p>请你返回购买所有 <code>m * n</code>&nbsp;件物品需要的 <strong>最大开销</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>values = [[8,5,2],[6,4,1],[9,7,3]]
<b>输出：</b>285
<b>解释：</b>第一天，从商店 1 购买物品 2 ，开销为 values[1][2] * 1 = 1 。
第二天，从商店 0 购买物品 2 ，开销为 values[0][2] * 2 = 4 。
第三天，从商店 2 购买物品 2 ，开销为 values[2][2] * 3 = 9 。
第四天，从商店 1 购买物品 1 ，开销为 values[1][1] * 4 = 16 。
第五天，从商店 0 购买物品 1 ，开销为 values[0][1] * 5 = 25 。
第六天，从商店 1 购买物品 0 ，开销为 values[1][0] * 6 = 36 。
第七天，从商店 2 购买物品 1 ，开销为 values[2][1] * 7 = 49 。
第八天，从商店 0 购买物品 0 ，开销为 values[0][0] * 8 = 64 。
第九天，从商店 2 购买物品 0 ，开销为 values[2][0] * 9 = 81 。
所以总开销为 285 。
285 是购买所有 m * n 件物品的最大总开销。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>values = [[10,8,6,4,2],[9,7,5,3,2]]
<b>输出：</b>386
<b>解释：</b>第一天，从商店 0 购买物品 4 ，开销为 values[0][4] * 1 = 2 。
第二天，从商店 1 购买物品 4 ，开销为 values[1][4] * 2 = 4 。
第三天，从商店 1 购买物品 3 ，开销为 values[1][3] * 3 = 9 。
第四天，从商店 0 购买物品 3 ，开销为 values[0][3] * 4 = 16 。
第五天，从商店 1 购买物品 2 ，开销为 values[1][2] * 5 = 25 。
第六天，从商店 0 购买物品 2 ，开销为 values[0][2] * 6 = 36 。
第七天，从商店 1 购买物品 1 ，开销为 values[1][1] * 7 = 49 。
第八天，从商店 0 购买物品 1 ，开销为 values[0][1] * 8 = 64 。
第九天，从商店 1 购买物品 0 ，开销为 values[1][0] * 9 = 81 。
第十天，从商店 0 购买物品 0 ，开销为 values[0][0] * 10 = 100 。
所以总开销为 386 。
386 是购买所有 m * n 件物品的最大总开销。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= m == values.length &lt;= 10</code></li>
	<li><code>1 &lt;= n == values[i].length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= values[i][j] &lt;= 10<sup>6</sup></code></li>
	<li><code>values[i]</code>&nbsp;按照非递增顺序排序。</li>
</ul>


    
## 解题方法：多指针

首先需要明确，最佳购买顺序是：将所有商店的所有商品从小到大排序，之后依次购买。

> 首先购买越晚系数越大，所以贵的应该尽可能晚购买；
>
> 其次，一定可以做到按所有商品价值从小到大购买，因为越靠后的商品越便宜，当前最便宜的商品一定在最后面。

直接调用库函数排序就没有利用“每个商家的商品非递增”这一特性，且排序复杂度$mn\log (mn)$ 平均大于 $mn\times m$。

> | $ m $ | $mn\log (mn)\gt mn\times m$ |
> |:-------:|:144428274:|
> |    1    | $$ n \geq 3 $$  |
> |    2    | $$ n \geq 5 $$  |
> |    3    | $$ n \geq 9 $$  |
> |    4    | $$ n \geq 17 $$ |
> |    5    | $$ n \geq 33 $$ |
> |    6    | $$ n \geq 65 $$ |
> |    7    | $$ n \geq 129 $$|
> |    8    | $$ n \geq 257 $$|
> |    9    | $$ n \geq 513 $$|
> |   10    | $$ n \geq 1025 $$ |

因此，我们可以使用$m$个指针，每个指针指向这家商店购买到了哪件商品，每次从$m$家里选择最便宜的那件就好。

+ 时间复杂度$O(m^2n)$：单次选择复杂度$O(m)$，共选择$mn$次。$m$的最大范围比较小，最多为$10$。
+ 空间复杂度$O(m)$

### AC代码

#### C++

```cpp
typedef long long ll;
class Solution {
public:
    ll maxSpending(vector<vector<int>>& values) {
        vector<int> loc(values.size(), values[0].size() - 1);
        ll ans = 0;
        int cnt = values.size() * values[0].size();
        ll th = 1;
        while (cnt--) {
            int m = 1e7, mLoc;
            for (int i = 0; i < values.size(); i++) {
                if (loc[i] >= 0 && values[i][loc[i]] < m) {
                    m = values[i][loc[i]];
                    mLoc = i;
                }
            }
            ans += values[mLoc][loc[mLoc]] * th;
            th++, loc[mLoc]--;
        }
        return ans;
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def maxSpending(self, values: List[List[int]]) -> int:
        loc = [len(values[0]) - 1] * len(values)
        ans, cnt, th = 0, len(values) * len(values[0]), 1
        while th <= cnt:
            m, mLoc = 10000000, 0
            for i in range(len(values)):
                if loc[i] >= 0 and values[i][loc[i]] < m:
                    m, mLoc = values[i][loc[i]], i
            ans += th * values[mLoc][loc[mLoc]]
            th += 1
            loc[mLoc] -= 1
        return ans
```

#### Java

```java
import java.util.Arrays;

class Solution {
    public long maxSpending(int[][] values) {
        int[] loc = new int[values.length];
        Arrays.fill(loc, values[0].length - 1);
        long ans = 0, th = 1;
        int cnt = values.length * values[0].length;
        while (th <= cnt) {
            int m = 100000000, mLoc = 0;
            for (int i = 0; i < values.length; i++) {
                if (loc[i] >= 0 && values[i][loc[i]] < m) {
                    m = values[i][loc[i]];
                    mLoc = i;
                }
            }
            ans += values[mLoc][loc[mLoc]] * th;
            th++;
            loc[mLoc]--;
        }
        return ans;
    }
}
```

#### Go

```go
package main

func maxSpending(values [][]int) (ans int64) {
    loc := make([]int, len(values))
    for i := range loc {
        loc[i] = len(values[0]) - 1
    }
    cnt, th := (int64)(len(values) * len(values[0])), (int64)(1)
    for th <= cnt {
        m, mLoc := 10000000, 0
        for i := range values {
            if loc[i] >= 0 && values[i][loc[i]] < m {
                m, mLoc = values[i][loc[i]], i
            }
        }
        ans += (int64)(values[mLoc][loc[mLoc]]) * th
        th++
        loc[mLoc]--
    }
    return
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/12/12/LeetCode%202931.%E8%B4%AD%E4%B9%B0%E7%89%A9%E5%93%81%E7%9A%84%E6%9C%80%E5%A4%A7%E5%BC%80%E9%94%80/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/144428274](https://letmefly.blog.csdn.net/article/details/144428274)
