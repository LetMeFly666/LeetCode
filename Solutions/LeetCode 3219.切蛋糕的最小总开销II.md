---
title: 3219.切蛋糕的最小总开销 II
date: 2024-12-31 14:21:50
tags: [题解, LeetCode, 困难, 贪心, 数组, 排序]
---

# 【LetMeFly】3219.切蛋糕的最小总开销 II：贪心——先切贵的

力扣题目链接：[https://leetcode.cn/problems/minimum-cost-for-cutting-cake-ii/](https://leetcode.cn/problems/minimum-cost-for-cutting-cake-ii/)

<p>有一个&nbsp;<code>m x n</code>&nbsp;大小的矩形蛋糕，需要切成&nbsp;<code>1 x 1</code>&nbsp;的小块。</p>

<p>给你整数&nbsp;<code>m</code>&nbsp;，<code>n</code>&nbsp;和两个数组：</p>

<ul>
	<li><code>horizontalCut</code> 的大小为&nbsp;<code>m - 1</code>&nbsp;，其中&nbsp;<code>horizontalCut[i]</code>&nbsp;表示沿着水平线 <code>i</code>&nbsp;切蛋糕的开销。</li>
	<li><code>verticalCut</code> 的大小为&nbsp;<code>n - 1</code>&nbsp;，其中&nbsp;<code>verticalCut[j]</code>&nbsp;表示沿着垂直线&nbsp;<code>j</code>&nbsp;切蛋糕的开销。</li>
</ul>

<p>一次操作中，你可以选择任意不是&nbsp;<code>1 x 1</code>&nbsp;大小的矩形蛋糕并执行以下操作之一：</p>

<ol>
	<li>沿着水平线&nbsp;<code>i</code>&nbsp;切开蛋糕，开销为&nbsp;<code>horizontalCut[i]</code>&nbsp;。</li>
	<li>沿着垂直线&nbsp;<code>j</code>&nbsp;切开蛋糕，开销为&nbsp;<code>verticalCut[j]</code>&nbsp;。</li>
</ol>

<p>每次操作后，这块蛋糕都被切成两个独立的小蛋糕。</p>

<p>每次操作的开销都为最开始对应切割线的开销，并且不会改变。</p>

<p>请你返回将蛋糕全部切成&nbsp;<code>1 x 1</code>&nbsp;的蛋糕块的&nbsp;<strong>最小</strong>&nbsp;总开销。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>m = 3, n = 2, horizontalCut = [1,3], verticalCut = [5]</span></p>

<p><span class="example-io"><b>输出：</b>13</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/06/04/ezgifcom-animated-gif-maker-1.gif" style="width: 280px; height: 320px;" /></p>

<ul>
	<li>沿着垂直线 0 切开蛋糕，开销为 5 。</li>
	<li>沿着水平线 0 切开&nbsp;<code>3 x 1</code>&nbsp;的蛋糕块，开销为 1 。</li>
	<li>沿着水平线 0 切开 <code>3 x 1</code>&nbsp;的蛋糕块，开销为 1 。</li>
	<li>沿着水平线 1 切开 <code>2 x 1</code>&nbsp;的蛋糕块，开销为 3 。</li>
	<li>沿着水平线 1 切开 <code>2 x 1</code>&nbsp;的蛋糕块，开销为 3 。</li>
</ul>

<p>总开销为&nbsp;<code>5 + 1 + 1 + 3 + 3 = 13</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>m = 2, n = 2, horizontalCut = [7], verticalCut = [4]</span></p>

<p><span class="example-io"><b>输出：</b>15</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>沿着水平线 0 切开蛋糕，开销为 7 。</li>
	<li>沿着垂直线 0 切开&nbsp;<code>1 x 2</code>&nbsp;的蛋糕块，开销为 4 。</li>
	<li>沿着垂直线 0 切开&nbsp;<code>1 x 2</code>&nbsp;的蛋糕块，开销为 4 。</li>
</ul>

<p>总开销为&nbsp;<code>7 + 4 + 4 = 15</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>horizontalCut.length == m - 1</code></li>
	<li><code>verticalCut.length == n - 1</code></li>
	<li><code>1 &lt;= horizontalCut[i], verticalCut[i] &lt;= 10<sup>3</sup></code></li>
</ul>


    
## 解题方法：贪心（双指针）

从头到尾贯穿整个蛋糕的一刀切的越早，所需的切割次数越少。

> 例如假如一个2x2的蛋糕：
>
> 1. 先竖着切，就是竖着一刀横着两刀
> 2. 先横着切，就是竖着两刀横着一刀

所以，将切割代价按照从大到小的顺序排序，然后在横竖切法里挑最贵的先切就好了。

切的时候从头切到尾：

> 假如这是竖着的一刀，就看横向一共切了几次。
>
> 如果横向一共切了$hCutTime$次，那么这一刀就要切$hCutTime + 1$次。

+ 时间复杂度$O(m\log m + n\log n)$
+ 空间复杂度$O(\log m + \log n)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2024-12-31 13:04:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-31 13:10:03
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    ll minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(), horizontalCut.end(), greater<>());
        sort(verticalCut.begin(), verticalCut.end(), greater<>());
        int hCutTime = 0, vCutTime = 0;
        ll ans = 0;
        while (hCutTime < horizontalCut.size() || vCutTime < verticalCut.size()) {
            if (vCutTime == verticalCut.size() || hCutTime < horizontalCut.size() && horizontalCut[hCutTime] > verticalCut[vCutTime]) {
                ans += horizontalCut[hCutTime++] * (vCutTime + 1);
            } else {
                ans += verticalCut[vCutTime++] * (hCutTime + 1);
            }
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2024-12-31 13:10:50
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-31 13:14:10
'''
from typing import List

class Solution:
    def minimumCost(self, m: int, n: int, horizontalCut: List[int], verticalCut: List[int]) -> int:
        horizontalCut.sort(key=lambda a: -a)
        verticalCut.sort(key=lambda a: -a)
        ans = hCutTime = vCutTime = 0
        m, n = m - 1, n - 1
        while hCutTime < m or vCutTime < n:
            if vCutTime == n or hCutTime < m and horizontalCut[hCutTime] > verticalCut[vCutTime]:
                ans += horizontalCut[hCutTime] * (vCutTime + 1)
                hCutTime += 1
            else:
                ans += verticalCut[vCutTime] * (hCutTime + 1)
                vCutTime += 1
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2024-12-31 13:14:31
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-31 13:22:22
 */
import java.util.Arrays;

class Solution {
    public long minimumCost(int m, int n, int[] horizontalCut, int[] verticalCut) {
        // Arrays.sort(horizontalCut, (a, b) -> b - a);  // 不可，Arrays.sort(int[])时不支持自定义排序
        Arrays.sort(horizontalCut);  // 那就从小到大排序然后下面反着遍历吧
        Arrays.sort(verticalCut);
        int hCutTime = m - 2, vCutTime = n - 2;
        long ans = 0;
        while (hCutTime >= 0 || vCutTime >= 0) {
            if (vCutTime < 0 || hCutTime >= 0 && horizontalCut[hCutTime] > verticalCut[vCutTime]) {
                ans += horizontalCut[hCutTime--] * (n - vCutTime - 1);
            } else {
                ans += verticalCut[vCutTime--] * (m - hCutTime - 1);
            }
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2024-12-31 13:23:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-31 13:37:03
 */
package main

import "slices"

func minimumCost(m int, n int, horizontalCut []int, verticalCut []int) (ans int64) {
    slices.SortFunc(horizontalCut, func(i, j int) int { return j - i; });
    slices.SortFunc(verticalCut, func(i, j int) int { return j - i; });
    var hCutTime, vCutTime int
    m, n = m - 1, n - 1
    for hCutTime < m || vCutTime < n {
        if vCutTime == n || hCutTime < m && horizontalCut[hCutTime] > verticalCut[vCutTime] {
            ans += int64(horizontalCut[hCutTime] * (vCutTime + 1))
            hCutTime++
        } else {
            ans += int64(verticalCut[vCutTime] * (hCutTime + 1))
            vCutTime++
        }
    }
    return
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/12/31/LeetCode%203219.%E5%88%87%E8%9B%8B%E7%B3%95%E7%9A%84%E6%9C%80%E5%B0%8F%E6%80%BB%E5%BC%80%E9%94%80II/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/144849684](https://letmefly.blog.csdn.net/article/details/144849684)
