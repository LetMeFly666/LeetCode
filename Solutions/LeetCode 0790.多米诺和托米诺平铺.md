---
title: 790.多米诺和托米诺平铺：难想条件的简单动态规划
date: 2025-05-05 22:40:03
tags: [题解, LeetCode, 中等, 动态规划, DP]
categories: [题解, LeetCode]
---

# 【LetMeFly】790.多米诺和托米诺平铺：难想条件的简单动态规划

力扣题目链接：[https://leetcode.cn/problems/domino-and-tromino-tiling/](https://leetcode.cn/problems/domino-and-tromino-tiling/)

<p>有两种形状的瓷砖：一种是&nbsp;<code>2 x 1</code> 的多米诺形，另一种是形如&nbsp;"L" 的托米诺形。两种形状都可以旋转。</p>

<p><img src="https://assets.leetcode.com/uploads/2021/07/15/lc-domino.jpg" style="height: 195px; width: 362px;" /></p>

<p>给定整数 n ，返回可以平铺&nbsp;<code>2 x n</code> 的面板的方法的数量。<strong>返回对</strong>&nbsp;<code>10<sup>9</sup>&nbsp;+ 7</code>&nbsp;<strong>取模&nbsp;</strong>的值。</p>

<p>平铺指的是每个正方形都必须有瓷砖覆盖。两个平铺不同，当且仅当面板上有四个方向上的相邻单元中的两个，使得恰好有一个平铺有一个瓷砖占据两个正方形。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2021/07/15/lc-domino1.jpg" style="height: 226px; width: 500px;" /></p>

<pre>
<strong>输入:</strong> n = 3
<strong>输出:</strong> 5
<strong>解释:</strong> 五种不同的方法如上所示。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> n = 1
<strong>输出:</strong> 1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>


    
## 解题方法：动态规划

力扣的[@灵茶山艾府](https://leetcode.cn/u/endlesscheng/)有张不错的图(来自[这个](https://leetcode.cn/problems/domino-and-tromino-tiling/solutions/1968516/by-endlesscheng-umpp/)题解)：

![理解图](https://pic.leetcode.cn/1668157188-nBzesC-790-5.png)

可以使用$f[i]$代表铺满$i$列的方案数，那么对于**最右边的可以独立切割出来的矩形**（也就是图上蓝色部分）有三种情况。

> 什么叫“最右边的可以独立切割出来的矩”？就是说“最右边蓝色部分无法被竖着一刀分成左右两个部分”。
>
> 因为若能竖着一刀将右边蓝色部分分成左右两个部分，那么左边部分的方案数一定已经被$f[j]$计算过了。
>
> 三种情况如下：
>
> 1. 最右边的蓝色独立矩形是一个竖着的$1\times 2$，可以在$f[i-1]$的基础上得到
> 2.  最右边的蓝色独立矩形是两个横着的$2\times 1$，可以在$f[i-2]$的基础上得到
> 3. 最右边的蓝色独立矩形完全交错排列，无法被竖着一刀分割，可以分别在$f[i-3]$、$f[i-4]$、$\cdots$、$f[0]$的基础上得到，并且每种都有上下两种摆放方式。

也就是说：$f[i]=f[i-1]+f[i-2]+2\times\sum_{j=0}^{i-3}f[j]$

但是这样的时间复杂度是$O(n^2)$，有没有一种更快的求法？有：

$f[i]-f[i-1]$是多少呢？

$$f[i]-f[i-1]=f[i-1]+f[i-2]+2\times\sum_{j=0}^{i-3}f[j]\\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ -f[i-2]+f[i-3]+2\times\sum_{j=0}^{i-4}f[j]\\ \ =f[i-1]+f[i-3]$$

所以有$f[i]=2\times f[i-1]+f[i-3]$。

实现容易推导难。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(n)$

不难发现，求$f[i]$时只会用到$f[i-1]$和$f[i-3]$两个变量，因此实际上我们使用$4$个变量滚动式地循环使用即可将空间复杂度降低到$O(1)$。

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-05-05 21:58:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-05 22:23:11
 */
const int MOD = 1e9 + 7;

class Solution {
public:
    int numTilings(int n) {
        if (n == 1) {
            return 1;
        }
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = ((dp[i - 1] * 2) % MOD + dp[i - 3]) % MOD;
        }
        return dp.back();
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-05-05 21:58:06
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-05 22:25:56
'''
MOD = 1000000007

class Solution:
    def numTilings(self, n: int) -> int:
        if n == 1:
            return 1
        dp = [0] * (n + 1)
        dp[0] = dp[1] = 1
        dp[2] = 2
        for i in range(3, n + 1):
            dp[i] = (dp[i - 1] * 2 + dp[i - 3]) % MOD
        return dp[-1]
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-05-05 21:58:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-05 22:28:23
 */
class Solution {
    private static int MOD = 1000000007;

    public int numTilings(int n) {
        if (n == 1) {
            return 1;
        }
        int[] dp = new int[n + 1];
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = ((dp[i - 1] * 2) % MOD + dp[i - 3]) % MOD;
        }
        return dp[n];
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-05-05 21:58:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-05 22:38:29
 */
package main

var MOD int = 1000000007

func numTilings(n int) int {
    if n == 1 {
        return 1
    }
    dp := make([]int, n + 1)
    dp[0] = 1
    dp[1] = 1
    dp[2] = 2
    for i := 3; i <= n; i++ {
        dp[i] = (dp[i - 1] * 2 % MOD + dp[i - 3]) % MOD
    }
    return dp[n]
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/147724251)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/05/05/LeetCode%200790.%E5%A4%9A%E7%B1%B3%E8%AF%BA%E5%92%8C%E6%89%98%E7%B1%B3%E8%AF%BA%E5%B9%B3%E9%93%BA/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
