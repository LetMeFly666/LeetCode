---
title: 1621.大小为 K 的不重叠线段的数目：组合数学(快速幂+模逆元)
date: 2026-09-17 08:33:53
tags: [题解, LeetCode, 中等, 数学, 动态规划, 组合数学, 前缀和, 快速幂, 模逆元]
categories: [题解, LeetCode]
---

# 【LetMeFly】1621.大小为 K 的不重叠线段的数目：组合数学(快速幂+模逆元)

力扣题目链接：[https://leetcode.cn/problems/number-of-sets-of-k-non-overlapping-line-segments/](https://leetcode.cn/problems/number-of-sets-of-k-non-overlapping-line-segments/)

<p>给你一维空间的 <code>n</code> 个点，其中第 <code>i</code> 个点（编号从 <code>0</code> 到 <code>n-1</code>）位于 <code>x = i</code> 处，请你找到 <strong>恰好</strong> <code>k</code> <strong>个不重叠</strong> 线段且每个线段至少覆盖两个点的方案数。线段的两个端点必须都是 <strong>整数坐标</strong> 。这 <code>k</code> 个线段不需要全部覆盖全部 <code>n</code> 个点，且它们的端点 <strong>可以 </strong>重合。</p>

<p>请你返回 <code>k</code> 个不重叠线段的方案数。由于答案可能很大，请将结果对 <code>10<sup>9</sup> + 7</code> <strong>取余</strong> 后返回。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.cn/aliyun-lc-upload/uploads/2020/10/17/ex1.png" style="width: 179px; height: 222px;" />
<pre>
<b>输入：</b>n = 4, k = 2
<b>输出：</b>5
<strong>解释：
</strong>如图所示，两个线段分别用红色和蓝色标出。
上图展示了 5 种不同的方案 {(0,2),(2,3)}，{(0,1),(1,3)}，{(0,1),(2,3)}，{(1,2),(2,3)}，{(0,1),(1,2)} 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>n = 3, k = 1
<b>输出：</b>3
<strong>解释：</strong>总共有 3 种不同的方案 {(0,1)}, {(0,2)}, {(1,2)} 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>n = 30, k = 7
<b>输出：</b>796297179
<strong>解释：</strong>画 7 条线段的总方案数为 3796297200 种。将这个数对 10<sup>9</sup> + 7 取余得到 796297179 。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<b>输入：</b>n = 5, k = 3
<b>输出：</b>7
</pre>

<p><strong>示例 5：</strong></p>

<pre>
<b>输入：</b>n = 3, k = 2
<b>输出：</b>1</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= n <= 1000</code></li>
	<li><code>1 <= k <= n-1</code></li>
</ul>


    
## 解题方法：组合数学

咱们站在资源分配的视角。

$n$个点共有$n-1$个长度可以分配，其中$k$个线段占据了$k$个长度，剩下的$n-1-k$个长度怎么分？

1. 可以分配到任何一个线段上（共有$k$个线段）
2. 可以分配到任何线段两边的空白位置上（共有$k+1$个空白位置）

问题变成了把$n-1-k$个东西放到$2k+1$个位置，有多少种放法。

把$a$个东西放到$b$个位置有多少种方法呢？相当于$a$个东西中间插入$b-1$个隔板，相当于东西加隔板共$a+b-1$个位置，其中选$b-1$个作为隔板，即$C_{a+b-1}^{b-1}$。

也就是说，本题的$C_{n+k-1}^{2k}$即为答案。

现在还有一个问题就是在大数对质数取模的情况下，怎么计算组合数$C_a^b$。

$$C_a^b = \frac{a!}{(a-b)!b!} = a! \times ((a-b)!)^{-1} \times (b!)^{-1}$$

而模运算下，$a^-1 \equiv a^{MOD-2} \mod MOD$，所以我们可以用快速幂来计算模逆元。

### 预处理优化

由于本题数据量$n$和$k$都是$10^3$量级，所以我们可以预处理出$0\sim 2000$范围内每个数的阶乘和模逆元。

阶乘$Jie[i]=Jie[i-1] \times i$，我们可以从$Jie[0]=1$开始处理到$Jie[2000]$。

而$2000!$的模逆元 $Rev[2000] = (2000!)^{-1} \equiv (2000!)^{MOD-2} \mod MOD$，前面计算出$2000!$的结果$Jie[2000]$后，可以用快速幂在$\log MOD$的时间内计算出$Rev[2000]$。

由于$Rev[i]=Jie[i]^{-1}=(Jie[i-1] \times i)^{-1}=Rev[i-1] \times i^{-1}$，所以$Rev[i-1] = Rev[i] \times i$，我们可以从$Rev[2000]$开始倒序处理到$Rev[0]$。

### 时空复杂度分析

+ 时间复杂度：预处理$O(n+k)$，单次运行$O(1)$
+ 空间复杂度：总计$O(n+k)$，单次运行额外空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-09-17 08:33:08
 */
typedef long long ll;
const ll MOD = 1e9 + 7;
ll Jie[2001];
ll Rev[2001];

ll myPow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

// J[i] = J[i-1] * i
// R[i] = (J[i-1] * i)^-1 = J[i-1]^-1 * i^-1 = R[i-1] * i^-1
// R[i-1] = R[i] * i
int _ = []{
    Jie[0] = 1;
    for (int i = 1; i <= 2000; i++) {
        Jie[i] = Jie[i - 1] * i % MOD;
    }
    Rev[2000] = myPow(Jie[2000], MOD - 2);
    for (int i = 2000; i; i--) {
        Rev[i - 1] = Rev[i] * i % MOD;
    }
    return 0;
} ();


class Solution {
private:
    int C(ll a, ll b) {
        return (Jie[a] * Rev[a - b] % MOD) * Rev[b] % MOD;
    }
public:
    int numberOfSets(int n, int k) {
        // 长n-1，k条线，还有n-1-k长度可供使用
        // 这些长度可以放到k条线段上，也可以放到k条线段两边的k+1个空白位置
        // 问题变成了把n-1-k个东西放到2k+1个位置
        //
        // a个东西放b个位置有多少种方法？相当于a个东西插入b-1个隔板
        // 相当于a+b-1个位置其中选b-1个作为隔板，即C_{a+b-1}^{b-1}
        // 回到本题则是C_{n+k-1}^{2k}
        //
        // C_a^b = a(a-1)(a-2)...(a-b+1) / b(b-1)(b-2)...1
        //       = a/1 * (a-1)/2 * (a-2)/3 * ... * (a-b+1)/b
        // a/t相当于a*rev(t)相当于a*t^{MOD-2}
        //
        // 换种思路，C_a^b= a! / (a-b)!b!
        return C(n + k - 1, 2 * k);
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/--------------------------)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/09/16/LeetCode%201621.%E5%A4%A7%E5%B0%8F%E4%B8%BAK%E7%9A%84%E4%B8%8D%E9%87%8D%E5%8F%A0%E7%BA%BF%E6%AE%B5%E7%9A%84%E6%95%B0%E7%9B%AE/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
