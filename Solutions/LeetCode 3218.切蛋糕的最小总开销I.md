---
title: 3218.切蛋糕的最小总开销 I
date: 2024-12-25 20:58:03
tags: [题解, LeetCode, 中等, 贪心, 数组, 动态规划, 排序, 深度优先搜索, DFS, 记忆化搜索]
---

# 【LetMeFly】3218.切蛋糕的最小总开销 I：记忆化搜索(深度优先搜索DFS)

力扣题目链接：[https://leetcode.cn/problems/minimum-cost-for-cutting-cake-i/](https://leetcode.cn/problems/minimum-cost-for-cutting-cake-i/)

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
	<li><code>1 &lt;= m, n &lt;= 20</code></li>
	<li><code>horizontalCut.length == m - 1</code></li>
	<li><code>verticalCut.length == n - 1</code></li>
	<li><code>1 &lt;= horizontalCut[i], verticalCut[i] &lt;= 10<sup>3</sup></code></li>
</ul>


    
## 解题方法：深度优先搜索（记忆化）

写一个函数`dfs`计算：切割竖直方向`[ia, ib)`水平方向`[ja, jb)`这个子蛋糕所需的最小花费。

每次计算很简单，若已经是`1x1`大小则直接返回`0`，若是水平切割：

> 枚举所有水平切割的下刀位置。其中，递归计算上下两块新蛋糕所需的最小花费并加上这一刀的花费作为这种切割方法的最小花费。

若是竖直切割则同理。

直接使用整块大蛋糕的大小调用`dfs`函数即可求得答案。

+ 时间复杂度$O(m^2n^2(m+n))$。共有$m^2n^2$种子蛋糕方案，每种方案首次计算平均耗时$O(m+n)$。
+ 空间复杂度$O(m^2n^2)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2024-12-25 18:08:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-25 18:40:56
 */
class Solution {
private:
    unordered_map<int, int> ma;

    int dfs(int ia, int ib, int ja, int jb, vector<int>& h, vector<int>& v) {
        int code = ia + ib * 20 + ja * 400 + jb * 8000;
        if (ma.count(code)) {
            return ma[code];
        }
        int ans = 1000000000;
        if (ib - ia == 1 && jb - ja == 1) {
            ans = 0;
        }
        for (int ic = ia + 1; ic < ib; ic++) {
            ans = min(ans, h[ic - 1] + dfs(ia, ic, ja, jb, h, v) + dfs(ic, ib, ja, jb, h, v));
        }
        for (int jc = ja + 1; jc < jb; jc++) {
            ans = min(ans, v[jc - 1] + dfs(ia, ib, ja, jc, h, v) + dfs(ia, ib, jc, jb, h, v));
        }
        return ma[code] = ans;
    }
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        return dfs(0, m, 0, n, horizontalCut, verticalCut);
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2024-12-25 20:27:10
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-25 20:34:17
'''
from typing import List
from functools import cache

class Solution:
    @cache
    def dfs(self, ia: int, ib: int, ja: int, jb: int) -> int:
        if ib - ia == 1 and jb - ja == 1:
            return 0
        ans = 1000000000
        for ic in range(ia + 1, ib):
            ans = min(ans, self.h[ic - 1] + self.dfs(ia, ic, ja, jb) + self.dfs(ic, ib, ja, jb))
        for jc in range(ja + 1, jb):
            ans = min(ans, self.v[jc - 1] + self.dfs(ia, ib, ja, jc) + self.dfs(ia, ib, jc, jb))
        return ans

    def minimumCost(self, m: int, n: int, horizontalCut: List[int], verticalCut: List[int]) -> int:
        self.h, self.v = horizontalCut, verticalCut
        return self.dfs(0, m, 0, n)
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2024-12-25 20:36:16
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-25 20:42:05
 */
class Solution {
    int[][][][] cache;
    int[] h, v;

    private int dfs(int ia, int ib, int ja, int jb) {
        if (cache[ia][ib][ja][jb] > 0 || (ib == ia + 1 && jb == ja + 1)) {
            return cache[ia][ib][ja][jb];
        }
        int ans = 1000000000;
        for (int ic = ia + 1; ic < ib; ic++) {
            ans = Math.min(ans, h[ic - 1] + dfs(ia, ic, ja, jb) + dfs(ic, ib, ja, jb));
        }
        for (int jc = ja + 1; jc < jb; jc++) {
            ans = Math.min(ans, v[jc - 1] + dfs(ia, ib, ja, jc) + dfs(ia, ib, jc, jb));
        }
        cache[ia][ib][ja][jb] = ans;
        return ans;
    }

    public int minimumCost(int m, int n, int[] horizontalCut, int[] verticalCut) {
        cache = new int[m][m + 1][n][n + 1];
        h = horizontalCut;
        v = verticalCut;
        return dfs(0, m, 0, n);
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2024-12-25 20:44:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-25 20:56:44
 */
package main

func min_CFCC(a, b int) int {
    if a <= b {
        return a
    }
    return b
}

func minimumCost(m int, n int, horizontalCut []int, verticalCut []int) int {
    cache := make([][][][]int, m)  // [m][m + 1][n][n + 1]
    for i := range cache {
        cache[i] = make([][][]int, m + 1)
        for j := range cache[i] {
            cache[i][j] = make([][]int, n)
            for k := range cache[i][j] {
                cache[i][j][k] = make([]int, n + 1)
            }
        }
    }
    var dfs func(int, int, int, int) int
    dfs = func(ia, ib, ja, jb int) int {
        if cache[ia][ib][ja][jb] > 0 || (ia == ib - 1 && ja == jb - 1) {
            return cache[ia][ib][ja][jb]
        }
        ans := 1000000000
        for ic := ia + 1; ic < ib; ic++ {
            ans = min_CFCC(ans, horizontalCut[ic - 1] + dfs(ia, ic, ja, jb) + dfs(ic, ib, ja, jb))
        }
        for jc := ja + 1; jc < jb; jc++ {
            ans = min_CFCC(ans, verticalCut[jc - 1] + dfs(ia, ib, ja, jc) + dfs(ia, ib, jc, jb))
        }
        cache[ia][ib][ja][jb] = ans
        return ans
    }
    return dfs(0, m, 0, n)
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/12/25/LeetCode%203218.%E5%88%87%E8%9B%8B%E7%B3%95%E7%9A%84%E6%9C%80%E5%B0%8F%E6%80%BB%E5%BC%80%E9%94%80I/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/144728332](https://letmefly.blog.csdn.net/article/details/144728332)
