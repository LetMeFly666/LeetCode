---
title: 1680.连接连续二进制数字：O(n)左移位运算
date: 2026-03-01 09:21:44
tags: [题解, LeetCode, 中等, 位运算, 数学, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】1680.连接连续二进制数字：O(n)左移位运算

力扣题目链接：[https://leetcode.cn/problems/concatenation-of-consecutive-binary-numbers/](https://leetcode.cn/problems/concatenation-of-consecutive-binary-numbers/)

<p>给你一个整数 <code>n</code> ，请你将 <code>1</code> 到 <code>n</code> 的二进制表示连接起来，并返回连接结果对应的 <strong>十进制</strong> 数字对 <code>10<sup>9</sup> + 7</code> 取余的结果。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>n = 1
<b>输出：</b>1
<strong>解释：</strong>二进制的 "1" 对应着十进制的 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>n = 3
<b>输出：</b>27
<strong>解释：</strong>二进制下，1，2 和 3 分别对应 "1" ，"10" 和 "11" 。
将它们依次连接，我们得到 "11011" ，对应着十进制的 27 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>n = 12
<b>输出：</b>505379714
<b>解释：</b>连接结果为 "1101110010111011110001001101010111100" 。
对应的十进制数字为 118505380540 。
对 10<sup>9</sup> + 7 取余后，结果为 505379714 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法：位运算

将$a$和$b$的二进制拼接，结果等于$a\times 10^{bit\_len(b)} + b$，而乘法和加法均满足模运算的<span title="(a + b) mod m = ((a mod m) + (b mod m)) mod m">分配律</span>，所以从$1$到$n$一次遍历不断拼接相邻两个整数并不断取模即可。

如何求得一个整数的二进制长度？

> 很多编程语言都有库函数，例如C++可以使用`__builtin_clz`求得一个整数二进制下前导零的个数，32位整数的位数$32$减去前导零的个数就是这个数二进制的长度。

+ 时间复杂度$O(n)$。大多数现代架构会把`__builtin_clz`直接映射为单条硬件指令，单次执行时间复杂度是$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-02-28 10:15:41
 */
typedef long long ll;
const ll MOD = 1e9 + 7;

class Solution {
public:
    int concatenatedBinary(int n) {
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = ((ans << (32 - __builtin_clz(i))) + i) % MOD;
        }
        return ans;
    }
};

```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/158535683)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/03/01/LeetCode%201680.%E8%BF%9E%E6%8E%A5%E8%BF%9E%E7%BB%AD%E4%BA%8C%E8%BF%9B%E5%88%B6%E6%95%B0%E5%AD%97/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
