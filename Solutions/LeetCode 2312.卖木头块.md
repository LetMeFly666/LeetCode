---
title: 2312.卖木头块
date: 2024-03-15 18:17:58
tags: [题解, LeetCode, 困难, 记忆化搜索, 数组, 动态规划, DP]
categories: [题解, LeetCode]
---

# 【LetMeFly】2312.卖木头块：动态规划(DP)

力扣题目链接：[https://leetcode.cn/problems/selling-pieces-of-wood/](https://leetcode.cn/problems/selling-pieces-of-wood/)

<p>给你两个整数&nbsp;<code>m</code> 和&nbsp;<code>n</code>&nbsp;，分别表示一块矩形木块的高和宽。同时给你一个二维整数数组&nbsp;<code>prices</code>&nbsp;，其中&nbsp;<code>prices[i] = [h<sub>i</sub>, w<sub>i</sub>, price<sub>i</sub>]</code>&nbsp;表示你可以以&nbsp;<code>price<sub>i</sub></code>&nbsp;元的价格卖一块高为&nbsp;<code>h<sub>i</sub></code>&nbsp;宽为&nbsp;<code>w<sub>i</sub></code>&nbsp;的矩形木块。</p>

<p>每一次操作中，你必须按下述方式之一执行切割操作，以得到两块更小的矩形木块：</p>

<ul>
	<li>沿垂直方向按高度 <strong>完全</strong> 切割木块，或</li>
	<li>沿水平方向按宽度 <strong>完全</strong> 切割木块</li>
</ul>

<p>在将一块木块切成若干小木块后，你可以根据 <code>prices</code>&nbsp;卖木块。你可以卖多块同样尺寸的木块。你不需要将所有小木块都卖出去。你 <strong>不能</strong>&nbsp;旋转切好后木块的高和宽。</p>

<p>请你返回切割一块大小为<em>&nbsp;</em><code>m x n</code><em> </em>的木块后，能得到的&nbsp;<strong>最多</strong>&nbsp;钱数。</p>

<p>注意你可以切割木块任意次。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/04/27/ex1.png" style="width: 239px; height: 150px;" /></p>

<pre>
<b>输入：</b>m = 3, n = 5, prices = [[1,4,2],[2,2,7],[2,1,3]]
<b>输出：</b>19
<b>解释：</b>上图展示了一个可行的方案。包括：
- 2 块 2 x 2 的小木块，售出 2 * 7 = 14 元。
- 1 块 2 x 1 的小木块，售出 1 * 3 = 3 元。
- 1 块 1 x 4 的小木块，售出 1 * 2 = 2 元。
总共售出 14 + 3 + 2 = 19 元。
19 元是最多能得到的钱数。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/04/27/ex2new.png" style="width: 250px; height: 175px;" /></p>

<pre>
<b>输入：</b>m = 4, n = 6, prices = [[3,2,10],[1,4,2],[4,1,3]]
<b>输出：</b>32
<b>解释：</b>上图展示了一个可行的方案。包括：
- 3 块 3 x 2 的小木块，售出 3 * 10 = 30 元。
- 1 块 1 x 4 的小木块，售出 1 * 2 = 2 元。
总共售出 30 + 2 = 32 元。
32 元是最多能得到的钱数。
注意我们不能旋转 1 x 4 的木块来得到 4 x 1 的木块。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>1 &lt;= prices.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>prices[i].length == 3</code></li>
	<li><code>1 &lt;= h<sub>i</sub> &lt;= m</code></li>
	<li><code>1 &lt;= w<sub>i</sub> &lt;= n</code></li>
	<li><code>1 &lt;= price<sub>i</sub> &lt;= 10<sup>6</sup></code></li>
	<li>所有&nbsp;<code>(h<sub>i</sub>, w<sub>i</sub>)</code> <strong>互不相同</strong>&nbsp;。</li>
</ul>


    
## 方法一：动态规划(DP)

令```dp[i][j]```代表大小为```i × j```的木块的最大价值。

初始值：若给定的大小为```m × n```的木块的售卖价格为```p```则令```dp[m][n] = p```；否则```dp[i][j] = 0```。

转移方程：

> + 对于横着切的方法：```dp[i][j] = max(dp[i][j], dp[i - k][j] + dp[k][j])```（其中$1\leq k\leq \lfloor \frac{i}{2} \rfloor$）
> + 对于竖着切的方法：```dp[i][j] = max(dp[i][j], dp[i][j - k] + dp[i][k]);```（其中$1\leq k\leq \lfloor \frac{j}{2} \rfloor$）

最终返回```dp[m][n]```即为答案。

+ 时间复杂度$O(mn(m+n))$
+ 空间复杂度$O(mn)$

### AC代码

#### C++

```cpp
typedef long long ll;
class Solution {
public:
    ll sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<ll>> dp(m + 1, vector<ll>(n + 1));
        for (vector<int>& price : prices) {
            dp[price[0]][price[1]] = price[2];
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= i / 2; k++) {
                    dp[i][j] = max(dp[i][j], dp[i - k][j] + dp[k][j]);
                }
                for (int k = 1; k <= j / 2; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][j - k] + dp[i][k]);
                }
            }
        }
        return dp[m][n];
    }
};
```

#### Python

```python
from typing import List

class Solution:  # AC,96.77%,100.00%
    def sellingWood(self, m: int, n: int, prices: List[List[int]]) -> int:
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for x, y, p in prices:
            dp[x][y] = p
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                dp[i][j] = max(
                    dp[i][j],
                    max((dp[i - k][j] + dp[k][j] for k in range(1, i // 2 + 1)), default=0),  # 这里必须加上default，否则可能会变成max(())
                    max((dp[i][j - k] + dp[i][k] for k in range(1, j // 2 + 1)), default=0)
                )
        return dp[m][n]
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/03/15/LeetCode%202312.%E5%8D%96%E6%9C%A8%E5%A4%B4%E5%9D%97/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136747100](https://letmefly.blog.csdn.net/article/details/136747100)
