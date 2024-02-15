---
title: 1954.收集足够苹果的最小花园周长
date: 2023-12-24 16:41:52
tags: [题解, LeetCode, 中等, 数学, 二分查找]
---

# 【LetMeFly】1954.收集足够苹果的最小花园周长：数学O(1)的做法

力扣题目链接：[https://leetcode.cn/problems/minimum-garden-perimeter-to-collect-enough-apples/](https://leetcode.cn/problems/minimum-garden-perimeter-to-collect-enough-apples/)

<p>给你一个用无限二维网格表示的花园，<strong>每一个</strong>&nbsp;整数坐标处都有一棵苹果树。整数坐标&nbsp;<code>(i, j)</code>&nbsp;处的苹果树有 <code>|i| + |j|</code>&nbsp;个苹果。</p>

<p>你将会买下正中心坐标是 <code>(0, 0)</code>&nbsp;的一块 <strong>正方形土地</strong>&nbsp;，且每条边都与两条坐标轴之一平行。</p>

<p>给你一个整数&nbsp;<code>neededApples</code>&nbsp;，请你返回土地的&nbsp;<strong>最小周长</strong>&nbsp;，使得&nbsp;<strong>至少</strong>&nbsp;有<strong>&nbsp;</strong><code>neededApples</code>&nbsp;个苹果在土地&nbsp;<strong>里面或者边缘上</strong>。</p>

<p><code>|x|</code>&nbsp;的值定义为：</p>

<ul>
	<li>如果&nbsp;<code>x &gt;= 0</code>&nbsp;，那么值为&nbsp;<code>x</code></li>
	<li>如果&nbsp;<code>x &lt;&nbsp;0</code>&nbsp;，那么值为&nbsp;<code>-x</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://pic.leetcode-cn.com/1627790803-qcBKFw-image.png" style="width: 442px; height: 449px;" />
<pre>
<b>输入：</b>neededApples = 1
<b>输出：</b>8
<b>解释：</b>边长长度为 1 的正方形不包含任何苹果。
但是边长为 2 的正方形包含 12 个苹果（如上图所示）。
周长为 2 * 4 = 8 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>neededApples = 13
<b>输出：</b>16
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>neededApples = 1000000000
<b>输出：</b>5040
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= neededApples &lt;= 10<sup>15</sup></code></li>
</ul>


    
## 方法一：求公式

**边长为$2n$的正方形，苹果数量为多少呢？**

由于X和Y是相互独立的，因此二者可以分开来看。对于X：

> 边长为$2n$的正方形一共有$2n+1$行，每行有Y轴左右共$2$部分。只考虑其中一行Y轴右侧的部分：
>
> > 对苹果的总贡献数为$0+1+2+\cdots+n=\frac{n(n+1)}{2}$
>
> 因此所有的X的贡献为$(2n+1)\times2\times\frac{n(n+1)}{2}=n(n+1)(2n+1)$

由于Y与X类似，所以Y的贡献与X相同，因此边长为2n的正方形的苹果数为$2n(n+1)(2n+1)$

**$n$为多少才能至少有neededApples个苹果呢？**

将上式处理一下：$2n(n+1)(2n+1)=4n(n+1)(n+0.5)\approx 4n^3$并且大于$4n^3$

也就是说要求的$n$就在$\sqrt[3]{\frac14neededApples}$附近。令$m=\sqrt[3]{\frac14neededApples}$，其实从$\lfloor m\rfloor - 10$到$\lfloor m\rfloor+10$算一遍就直到答案了。

**有没有更靠谱/可信一点的证明？** （此部分可跳过）

令$n=\lfloor m\rfloor$，令$f(n)=n(n+1)(n+0.5)$，则是在求最小的$n$使得$f(n)\geq \frac14neededApples$。因为有：

1. $f(n-1)=(n-1)n(n-0.5)\lt n^3\leq m^3=\frac14neededApples$，因此$n-1$必定偏小
2. $f(n+1)=(n+1)(n+2)(n+1.5)\gt (n+1)^3=\lceil m\rceil^3\gt \frac14neededApples$，因此$n+1$必定满足要求

所以答案$ans$的范围是：$[n, n+1]$，其中$n=\lfloor m\rfloor=\lfloor \sqrt[3]{\frac14neededApples}\rfloor$。

因此只需要先计算出$\lfloor \sqrt[3]{\frac14neededApples}\rfloor$，并在不满足要求（苹果数偏少）时不断加加一，直到满足要求即可。（最多会加1次一）

+ 时间复杂度$O(1)$，开立方根有内置库，可视为$O(1)$时间复杂度
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
x: 2(2n+1)(1+2+...+n)=n(n+1)(2n+1)
y = x
x + y: 2n(n+1)(2n+1) = 4n(n+1)(n+0.5)≈4n^3
*/
class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long ans = cbrt((double)0.25 * neededApples);
        while (2 * ans * (ans + 1) * (2 * ans + 1) <  neededApples) {
            ans++;
        }
        return ans * 8;
    }
};
```

#### Python

```python
# from numpy import cbrt

class Solution:
    def minimumPerimeter(self, neededApples: int) -> int:
        ans = int(cbrt(0.25 * neededApples))
        while 2 * ans * (ans + 1) * (2 * ans + 1) < neededApples:
            ans += 1
        return ans * 8
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/12/24/LeetCode%201954.%E6%94%B6%E9%9B%86%E8%B6%B3%E5%A4%9F%E8%8B%B9%E6%9E%9C%E7%9A%84%E6%9C%80%E5%B0%8F%E8%8A%B1%E5%9B%AD%E5%91%A8%E9%95%BF/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135183907](https://letmefly.blog.csdn.net/article/details/135183907)
