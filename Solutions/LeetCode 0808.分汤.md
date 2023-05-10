---
title: 808.分汤
date: 2022-11-21 21:36:18
tags: [题解, LeetCode, 中等, 数学, 动态规划, 概率与统计, DP]
---

# 【LetMeFly】808.分汤：好题！

力扣题目链接：[https://leetcode.cn/problems/soup-servings/](https://leetcode.cn/problems/soup-servings/)

<p>有&nbsp;<strong>A&nbsp;和&nbsp;B 两种类型&nbsp;</strong>的汤。一开始每种类型的汤有&nbsp;<code>n</code>&nbsp;毫升。有四种分配操作：</p>

<ol>
	<li>提供 <code>100ml</code> 的 <strong>汤A</strong> 和 <code>0ml</code> 的 <strong>汤B</strong> 。</li>
	<li>提供 <code>75ml</code> 的 <strong>汤A</strong> 和 <code>25ml</code> 的 <strong>汤B</strong> 。</li>
	<li>提供 <code>50ml</code> 的 <strong>汤A</strong> 和 <code>50ml</code> 的 <strong>汤B</strong> 。</li>
	<li>提供 <code>25ml</code> 的 <strong>汤A</strong> 和 <code>75ml</code> 的 <strong>汤B</strong> 。</li>
</ol>

<p>当我们把汤分配给某人之后，汤就没有了。每个回合，我们将从四种概率同为 <code>0.25</code> 的操作中进行分配选择。如果汤的剩余量不足以完成某次操作，我们将尽可能分配。当两种类型的汤都分配完时，停止操作。</p>

<p><strong>注意&nbsp;</strong>不存在先分配 <code>100</code> ml <strong>汤B</strong> 的操作。</p>

<p>需要返回的值：&nbsp;<strong>汤A&nbsp;</strong>先分配完的概率 +&nbsp;&nbsp;<strong>汤A和汤B&nbsp;</strong>同时分配完的概率 / 2。返回值在正确答案&nbsp;<code>10<sup>-5</sup></code>&nbsp;的范围内将被认为是正确的。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> n = 50
<strong>输出:</strong> 0.62500
<strong>解释:</strong>如果我们选择前两个操作<strong>，</strong>A 首先将变为空。
对于第三个操作，A 和 B 会同时变为空。
对于第四个操作，B 首先将变为空。<strong>
</strong>所以 A 变为空的总概率加上 A 和 B 同时变为空的概率的一半是 0.25 *(1 + 1 + 0.5 + 0)= 0.625。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> n = 100
<strong>输出:</strong> 0.71875
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 10<sup>9</sup></code>​​​​​​​</li>
</ul>


    
## 方法一：特判 + 动态规划

我们将“一份”汤水视为```25ml```

因“不足时尽可能分配”，故```n ml```汤水相当于$\lceil\frac{25}{n}\rceil$份

令$dp[i][j]$为“分配前A有i ml，B有j ml”的情况下“要求的概率”（这里要求的概率就是“汤A先分配完的概率 + 汤A和汤B同时分配完的概率 / 2”）

那么我们就能得到状态转移方程：

$dp[i][j] = \frac14\times(dp[i - 4][j] + dp[i - 3][j - 1] + dp[i - 2][j - 2] + dp[i - 1][j - 3])$

这是因为初始值是$[i][j]$的时候，一次操作会**等概率**得到$[i - 4][j]$、$[i - 3][j - 1]$、$[i - 2][j - 2]$、$[i - 1][j - 3]$这四种情况。

注意，假如A汤不足$3$份，那么$[i - 3]$就由$0$替换。还是因为那句“不足时尽可能分配”，想取$3$份A但A不足三份的话，就把A取完（变成0）

最后考虑一下初始值：

+ 若初始的时候A和B的量都为0，那么“汤A和汤B同时分配完的概率”为1，“汤A先分配完的概率”为0，“汤A先分配完的概率 + 汤A和汤B同时分配完的概率 / 2”为$0+1/2=0.5$
+ 若初始的时候A为0但B的量不为0，那么“汤A先分配完的概率”为1，“汤A和汤B同时分配完的概率”为0，“汤A先分配完的概率 + 汤A和汤B同时分配完的概率 / 2”为$1+0/2=1$

复杂度分析：

完了，这DP的复杂度为$O(n^2)$咋办？

不用怕，注意“4种方案中”，“不存在先分配 100 ml 汤B 的操作”也就是说A被分配更多的概率更大。当$n$足够大时，$A$先分配完的概率接近于$1$

我们可以手动尝试一下

```cpp
int main() {
    int n;
    while (cin >> n) {
        Solution sol;
        cout << sol.soupServings(n) << endl;
    }
    return 0;
}
```

当$n\geq5000$时（甚至更小），得到概率为$0.99999.xx$

满足题目“返回值在正确答案$10^{-5}$的范围内将被认为是正确的”

因此，当$n$足够大时，直接返回$1$即可。

+ 时间复杂度$O(n^2)$或$O(1)$。当$n\geq 5000$时时间复杂度为$O(1)$，否则为$O(n^2)$
+ 空间复杂度：同时间复杂度

看似$O(n^2)$的做法，通过了数据量$10^9$的题目。所以说这题很妙。

### AC代码

#### C++

```cpp
class Solution {
public:
    double soupServings(int n) {
        if (n >= 5000)
            return 1;
        n = n / 25 + (n % 25 != 0);
        vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0));
        for (int j = 1; j <= n; j++) {
            dp[0][j] = 1;
        }
        dp[0][0] = 0.5;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = 0.25 * (dp[max(0, i - 4)][j] + dp[max(0, i - 3)][max(0, j - 1)] + dp[max(0, i - 2)][max(0, j - 2)] + dp[max(0, i - 1)][max(0, j - 3)]);
            }
        }
        return dp[n][n];
    }
};
```

![result](https://img-blog.csdnimg.cn/2bff54f8c1a14ba18c4534e04387bd5c.jpeg#pic_center)

<!-- ![result.jpg](https://pic.leetcode.cn/1669038960-JGQGVK-result.jpg) -->

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/11/21/LeetCode%200808.%E5%88%86%E6%B1%A4/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127973526](https://letmefly.blog.csdn.net/article/details/127973526)
