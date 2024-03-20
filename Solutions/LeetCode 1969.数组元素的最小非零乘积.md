---
title: 1969.数组元素的最小非零乘积
date: 2024-03-20 11:06:08
tags: [题解, LeetCode, 中等, 贪心, 递归, 数学, 快速幂, 二进制]
---

# 【LetMeFly】1969.数组元素的最小非零乘积：贪心(快速幂)

力扣题目链接：[https://leetcode.cn/problems/minimum-non-zero-product-of-the-array-elements/](https://leetcode.cn/problems/minimum-non-zero-product-of-the-array-elements/)

<p>给你一个正整数&nbsp;<code>p</code>&nbsp;。你有一个下标从 <strong>1</strong>&nbsp;开始的数组&nbsp;<code>nums</code>&nbsp;，这个数组包含范围&nbsp;<code>[1, 2<sup>p</sup> - 1]</code>&nbsp;内所有整数的二进制形式（两端都 <strong>包含</strong>）。你可以进行以下操作 <strong>任意</strong>&nbsp;次：</p>

<ul>
	<li>从 <code>nums</code>&nbsp;中选择两个元素&nbsp;<code>x</code>&nbsp;和&nbsp;<code>y</code>&nbsp; 。</li>
	<li>选择 <code>x</code>&nbsp;中的一位与 <code>y</code>&nbsp;对应位置的位交换。对应位置指的是两个整数 <strong>相同位置</strong>&nbsp;的二进制位。</li>
</ul>

<p>比方说，如果&nbsp;<code>x = 11<em><strong>0</strong></em>1</code>&nbsp;且&nbsp;<code>y = 00<em><strong>1</strong></em>1</code>&nbsp;，交换右边数起第 <code>2</code>&nbsp;位后，我们得到&nbsp;<code>x = 11<em><strong>1</strong></em>1</code> 和&nbsp;<code>y = 00<em><strong>0</strong></em>1</code>&nbsp;。</p>

<p>请你算出进行以上操作 <strong>任意次</strong>&nbsp;以后，<code>nums</code>&nbsp;能得到的 <strong>最小非零</strong>&nbsp;乘积。将乘积对<em>&nbsp;</em><code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong> 后返回。</p>

<p><strong>注意：</strong>答案应为取余 <strong>之前</strong>&nbsp;的最小值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>p = 1
<b>输出：</b>1
<b>解释：</b>nums = [1] 。
只有一个元素，所以乘积为该元素。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>p = 2
<b>输出：</b>6
<b>解释：</b>nums = [01, 10, 11] 。
所有交换要么使乘积变为 0 ，要么乘积与初始乘积相同。
所以，数组乘积 1 * 2 * 3 = 6 已经是最小值。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>p = 3
<b>输出：</b>1512
<b>解释：</b>nums = [001, 010, 011, 100, 101, 110, 111]
- 第一次操作中，我们交换第二个和第五个元素最左边的数位。
    - 结果数组为 [001, <em><strong>1</strong></em>10, 011, 100, <em><strong>0</strong></em>01, 110, 111] 。
- 第二次操作中，我们交换第三个和第四个元素中间的数位。
    - 结果数组为 [001, 110, 0<em><strong>0</strong></em>1, 1<em><strong>1</strong></em>0, 001, 110, 111] 。
数组乘积 1 * 6 * 1 * 6 * 1 * 6 * 7 = 1512 是最小乘积。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= p &lt;= 60</code></li>
</ul>


    
## 方法一：贪心(快速幂)

### 方法

解决这道题需要明白两点：

1. 尽量把所有数变成```111...10```和```000...01```的形式；
2. 如何使用```快速幂```快速计算。

### 原因

为什么要尽量变成```111...10```和```000...01```的形式？

> 题目中的两个数```x = 1100```和```y = 0011```，```x * y = 1100 * 0010 + 1100 * 0001```。
>
> 我们看从左往右的第三个```1```，它的“贡献”是```1100 * 0010```。
>
> 而如果交换第三个```1```的位置使得```x = 1110```且```y = 0001```（```x * y = 1000 * 0001 + 0100 * 0001 + 0010 * 0001```），
>
> 则第三个```1```的“贡献”是```0010 * 0001```。
>
> 有没有发现，第三个```1```不论在```x```中还是在```y```中，其对```x * y```的贡献中总有“```0010```乘以```另一个数```”这一部分。
>
> 那么能不能让另一个数尽可能小？可以。因最终结果要“非零”，因此另一个数最小为```1```。

能变成多少个```111...10```和```000...01```的形式？

> 从```1```到```2^p-1```的二进制数中，除了```2^p-1```（二进制下全部为```1```）外，其余数（偶数个）正好可以两两配对（使得每一位上总计1个```1```和1个```0```）。
>
> 因此最终可以变成$2^p-1$乘以：$\frac{2^p-2}{2}$个$2^p-2$

快速幂是什么？

> 快速幂用于快速计算$a^b\mod p$的结果，其原理是将```b```看成二进制数。
>
> 例如$a^6=a^{110_{(2)}}=a^{100_{(2)}}\times a^{10_{(2)}}$，而$a^{100_{(2)}}$又可以通过$a^{10_{(2)}}\times a$得到。
>
> 这样便将$O(b)$的时间复杂度将为了$b$二进制长度的复杂度$O(\log b)$
>
> 具体可参考[快速幂小解](https://web.letmefly.xyz/Notes/ACM/Problems/%E5%BF%AB%E9%80%9F%E5%B9%82/)。

### 时空复杂度

+ 时间复杂度$O(p)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
typedef long long ll;
const ll MOD = 1e9 + 7;
class Solution {
private:
    ll Pow(ll a, ll b) {
        a %= MOD;
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
public:
    // (2 ^ p - 1) * ((2 ^ p - 2) ^ ((2 ^ p - 2) / 2))
    int minNonZeroProduct(int p) {
        return (((1LL << p) - 1) % MOD) * Pow((1LL << p) - 2, ((1LL << p) - 2) / 2) % MOD;
    }
};
```

#### Python

```python
MOD = int(1e9) + 7

class Solution:
    def minNonZeroProduct(self, p: int) -> int:
        return ((1 << p) - 1) * pow((1 << p) - 2, ((1 << p) - 2) // 2, MOD) % MOD  # 记得是//而不是/
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/03/20/LeetCode%201969.%E6%95%B0%E7%BB%84%E5%85%83%E7%B4%A0%E7%9A%84%E6%9C%80%E5%B0%8F%E9%9D%9E%E9%9B%B6%E4%B9%98%E7%A7%AF/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136872322](https://letmefly.blog.csdn.net/article/details/136872322)
