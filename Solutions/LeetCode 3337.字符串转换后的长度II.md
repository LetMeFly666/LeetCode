---
title: 3337.字符串转换后的长度 II
date: 2025-05-15 10:07:46
tags: [题解, LeetCode, 困难, 哈希表, 数学, 字符串, 动态规划, 计数]
categories: [题解, LeetCode]
---

> 鸣谢[灵茶山艾府](https://leetcode.cn/u/endlesscheng/)的题解[矩阵快速幂优化 DP](https://leetcode.cn/problems/total-characters-in-string-after-transformations-ii/solutions/2967037/ju-zhen-kuai-su-mi-you-hua-dppythonjavac-cd2j)

先计算一个字符`a`进行$t$次替换后的长度、一个`b`进行$t$次替换后的长度、...、一个`z`进行$t$次替换后的长度。每个字母进行$t$次替换后字符串长度计算出来后，只需要统计一下原始字符串中每种字符分别有多少个，乘一下就好了。

如何计算`a`进行$t$次替换后的长度？

> 假设`a`进行一次替换得到`b`和`c`，那么问题就变成了`b`进行$t-1$次替换 和 `c`进行$t-1$次替换之后的长度之和。

定义$f[i][j]$表示字母$j$替换$i$次后的长度（上述举例即为$f[t][0] = f[t-1][1]+f[t-1][2]$），则有：

$$f[i][j] = \sum_{k=1}^{nums[j]} f[i-1][(j+k)\mod 26]$$

初始值$f[0][j]=1$，答案为$\sum_{j=0}^{25}f[t][j]\cdot cnt[j]$，其中$cnt[j]$是$j$出现的次数。

但是直接计算时间复杂度为$O(t\cdot C)$（其中$C=26$），肯定超时。

**矩阵快速幂优化**

以样例一为例（其实也就是[3335. 字符串转换后的长度 I](https://leetcode.cn/problems/total-characters-in-string-after-transformations-i)）：$nums = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2]$

于是有：

$$
\begin{aligned}
f[i][0] & =f[i-1][1] \\
f[i][1] & =f[i-1][2] \\
f[i][2] & =f[i-1][3] \\
\vdots & \\
f[i][23] & =f[i-1][24] \\
f[i][24] & =f[i-1][25] \\
f[i][25] & =f[i-1][0]+f[i-1][1]
\end{aligned}\\
$$

使用矩阵表示，有：

$$
\left[\begin{array}{c}
f[i][0] \\
f[i][1] \\
f[i][2] \\
\vdots \\
f[i][23] \\
f[i][24] \\
f[i][25]
\end{array}\right]=\left[\begin{array}{ccccccc}
0 & 1 & 0 & 0 & \cdots & 0 & 0 \\
0 & 0 & 1 & 0 & \cdots & 0 & 0 \\
0 & 0 & 0 & 1 & \cdots & 0 & 0 \\
\vdots & \vdots & \vdots & \vdots & \ddots & \vdots & \vdots \\
0 & 0 & 0 & 0 & \cdots & 1 & 0 \\
0 & 0 & 0 & 0 & \cdots & 0 & 1 \\
1 & 1 & 0 & 0 & \cdots & 0 & 0
\end{array}\right]\left[\begin{array}{c}
f[i-1][0] \\
f[i-1][1] \\
f[i-1][2] \\
\vdots \\
f[i-1][23] \\
f[i-1][24] \\
f[i-1][25]
\end{array}\right]
$$

把上式中的三个矩阵分别记作$F[i],M,F[i−1]$，即

$$
F[i]=M \times F[i-1]
$$

则有：

$$

\begin{aligned}
F[t] & =M \times F[t-1] \\
& =M \times M \times F[t-2] \\
& =M \times M \times M \times F[t-3] \\
& \vdots \\
& =M^{t} \times F[0]
\end{aligned}
$$

也就是说，我们只需要在$\log t\times C^3$的时间内算出$M^t$，问题就解决了。

使用矩阵快速幂即可完美解决。

听到矩阵快速幂不要怕，它和[快速幂](https://blog.letmefly.xyz/tags/%E5%BF%AB%E9%80%9F%E5%B9%82/)的原理是一模一样的，只是把快速幂中的整数乘法换成了矩阵乘法而已。
