---
title: 837.新 21 点：动态规划+滑动窗口
date: 2025-08-17 22:32:41
tags: [题解, LeetCode, 中等, 数学, 动态规划, DP, 滑动窗口, 概率与统计, 数学, 概率论]
categories: [题解, LeetCode]
---

# 【LetMeFly】837.新 21 点：动态规划+滑动窗口

力扣题目链接：[https://leetcode.cn/problems/new-21-game/](https://leetcode.cn/problems/new-21-game/)

<p>爱丽丝参与一个大致基于纸牌游戏 <strong>“21点”</strong> 规则的游戏，描述如下：</p>

<p>爱丽丝以 <code>0</code> 分开始，并在她的得分少于 <code>k</code> 分时抽取数字。 抽取时，她从 <code>[1, maxPts]</code> 的范围中随机获得一个整数作为分数进行累计，其中 <code>maxPts</code> 是一个整数。 每次抽取都是独立的，其结果具有相同的概率。</p>

<p>当爱丽丝获得 <code>k</code> 分 <strong>或更多分</strong> 时，她就停止抽取数字。</p>

<p>爱丽丝的分数不超过 <code>n</code> 的概率是多少？</p>

<p>与实际答案误差不超过&nbsp;<code>10<sup>-5</sup></code> 的答案将被视为正确答案。</p>
&nbsp;

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 10, k = 1, maxPts = 10
<strong>输出：</strong>1.00000
<strong>解释：</strong>爱丽丝得到一张牌，然后停止。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 6, k = 1, maxPts = 10
<strong>输出：</strong>0.60000
<strong>解释：</strong>爱丽丝得到一张牌，然后停止。 在 10 种可能性中的 6 种情况下，她的得分不超过 6 分。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 21, k = 17, maxPts = 10
<strong>输出：</strong>0.73278
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= k &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= maxPts &lt;= 10<sup>4</sup></code></li>
</ul>


    
## 解题方法：动态规划

这道题有点“反向dp”。令$dp[i]$表示当爱丽丝获得$i$分时，最终获胜的概率。

其中“获胜”是指最终分数$\geq k$且$\leq n$，那么初始状态0分时$dp[0]$即位所求。

一旦爱丽丝分数$\geq k$她就立即停止抽牌，由于最后一张牌的分数范围是$1$到$maxPts$，所以最终分数的可能范围是从$k$到$k+maxPts-1$，可得dp数组的初始状态：

{% raw %}

$$
dp[i]=\begin{cases}
  1 \text{ if } i\leq n \\
  0 \text{ else } 
\end{cases}\ \ \  ,\ k\leq i\lt k+maxPts
$$

{% endraw %}

那么在她手中的分数还未达到游戏终止时（假设当前为$i$分），由于再抽一张牌可以**等概率**达到$i+1, i+2, \cdots, i+maxPts$，所以可得状态转移方程：

{% raw %}

$$dp[i] = \frac{dp[i+1]+dp[i+2]+\dots+dp[i+maxPts]}{maxPts}$$

{% endraw %}

由于每次计算$dp[i+1]+dp[i+2]+\dots+dp[i+maxPts]$太过于机械和重复，所以可以参考“滑动窗口”的思想，使用一个变量$s$记录“窗口”中$maxPts$个元素的和，并随着窗口的前移不断更新$s$即可。

+ 时间复杂度$O(k+maxPts)$
+ 空间复杂度$O(k+maxPts)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-08-17 19:33:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-17 19:38:09
 */
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(k + maxPts);
        double s = 0;
        for (int i = k; i < k + maxPts; i++) {
            dp[i] = i <= n;
            s += dp[i];
        }
        for (int i = k - 1; i >= 0; i--) {
            dp[i] = s / maxPts;
            s = s - dp[i + maxPts] + dp[i];
        }
        return dp[0];
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-08-17 19:33:11
LastEditors: LetMeFly.xyz
LastEditTime: 2025-08-17 19:40:07
'''
class Solution:
    def new21Game(self, n: int, k: int, maxPts: int) -> float:
        dp = [0.] * (k + maxPts)
        s = 0.
        for i in range(k, k + maxPts):
            dp[i] = 1. if i <= n else 0.
            s += dp[i]
        for i in range(k - 1, -1, -1):
            dp[i] = s / maxPts
            s = s + dp[i] - dp[i + maxPts]
        return dp[0]
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-08-17 19:33:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-17 19:43:15
 */
class Solution {
    public double new21Game(int n, int k, int maxPts) {
        double[] dp = new double[k + maxPts];
        double s = 0;
        for (int i = k; i < k + maxPts; i++) {
            dp[i] = i <= n ? 1. : 0.;
            s += dp[i];
        }
        for (int i = k - 1; i >= 0; i--) {
            dp[i] = s / maxPts;
            s = s + dp[i] - dp[i + maxPts];
        }
        return dp[0];
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-08-17 19:33:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-17 22:20:30
 */
package main

func new21Game(n int, k int, maxPts int) float64 {
    dp := make([]float64, k + maxPts)
    s := 0.
    for i := k; i < k + maxPts; i++ {
        if i <= n {
            dp[i] = 1.
        } else {
            dp[i] = 0.
        }
        s += dp[i]  // 别忘了
    }
    for i := k - 1; i >= 0; i-- {
        dp[i] = s / float64(maxPts)
        s = s + dp[i] - dp[i + maxPts]
    }
    return dp[0]
}
```

#### Rust

```rust
/*
 * @Author: LetMeFly
 * @Date: 2025-08-17 19:33:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-17 22:31:00
 */
impl Solution {
    pub fn new21_game(n: i32, k: i32, max_pts: i32) -> f64 {
        let k: usize = k as usize;
        let max_pts: usize = max_pts as usize;
        let n: usize = n as usize;

        let mut dp: Vec<f64> = vec![0.; k + max_pts];
        let mut s: f64 = 0.;
        for i in k..(k+max_pts) {
            if i <= n {
                dp[i] = 1.;
            } else {
                dp[i] = 0.;
            }
            s += dp[i];
        }
        for i in (0..k).rev() {
            dp[i] = s / max_pts as f64;
            s = s + dp[i] - dp[i + max_pts];
        }
        dp[0]
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/150474266)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/08/17/LeetCode%200837.%E6%96%B021%E7%82%B9/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
