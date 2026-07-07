---
title: 3754.连接非零数字并乘以其数字和 I：O(1)非字符串写法
date: 2026-07-07 11:54:42
tags: [题解, LeetCode, 简单, 数学]
categories: [题解, LeetCode]
---

# 【LetMeFly】3754.连接非零数字并乘以其数字和 I：O(1)非字符串写法

力扣题目链接：[https://leetcode.cn/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/](https://leetcode.cn/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/)

<p>给你一个整数 <code>n</code>。</p>

<p>将 <code>n</code> 中所有的&nbsp;<strong>非零数字&nbsp;</strong>按照它们的原始顺序连接起来，形成一个新的整数 <code>x</code>。如果不存在&nbsp;<strong>非零数字&nbsp;</strong>，则 <code>x = 0</code>。</p>

<p><code>sum</code> 为 <code>x</code> 中所有数字的&nbsp;<strong>数字和&nbsp;</strong>。</p>

<p>返回一个整数，表示 <code>x * sum</code> 的值。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 10203004</span></p>

<p><strong>输出：</strong> <span class="example-io">12340</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>非零数字是 1、2、3 和 4。因此，<code>x = 1234</code>。</li>
	<li>数字和为 <code>sum = 1 + 2 + 3 + 4 = 10</code>。</li>
	<li>因此，答案是 <code>x * sum = 1234 * 10 = 12340</code>。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 1000</span></p>

<p><strong>输出：</strong> <span class="example-io">1</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>非零数字是 1，因此 <code>x = 1</code> 且 <code>sum = 1</code>。</li>
	<li>因此，答案是 <code>x * sum = 1 * 1 = 1</code>。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：不断处以10

当$n$非零时，不断取出$n$在十进制下的个位$t$，并将$n$除以$10$并想下取整。如果个位$t$非零，则进行处理：

1. 求和：使用一个变量$cnt$记录所有非零$t$的和；
2. 拼接：使用一个变量$con$记录所有非零$t$十进制下的拼接结果。

    假设当前$con$为$234$且$t$为$1$，怎么把$1$拼接到$234$的前面呢？令$con+=t\times 10^3$即可。这个$10^3$可以使用一个变量$pow$来记录，每次拼接完成后$pow=pow\times 10$。

最终$cnt\times con$即为答案。

+ 时间复杂度$O(\log n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-07-07 11:50:28
 */
typedef long long ll;
class Solution {
public:
    ll sumAndMultiply(int n) {
        ll cnt = 0, con = 0, pow = 1;
        while (n) {
            ll t = n % 10;
            n /= 10;
            if (!t) {
                continue;
            }
            con += pow * t;
            pow *= 10;
            cnt += t;
        }
        return cnt * con;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/162661145)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/07/07/LeetCode%203754.%E8%BF%9E%E6%8E%A5%E9%9D%9E%E9%9B%B6%E6%95%B0%E5%AD%97%E5%B9%B6%E4%B9%98%E4%BB%A5%E5%85%B6%E6%95%B0%E5%AD%97%E5%92%8CI/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
