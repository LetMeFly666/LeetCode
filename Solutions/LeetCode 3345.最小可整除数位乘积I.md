---
title: 3345.最小可整除数位乘积 I：暴力枚举（从n开始尝试）
date: 2026-08-06 15:25:28
tags: [题解, LeetCode, 简单, 数学, 枚举, 暴力]
categories: [题解, LeetCode]
---

# 【LetMeFly】3345.最小可整除数位乘积 I：暴力枚举（从n开始尝试）

力扣题目链接：[https://leetcode.cn/problems/smallest-divisible-digit-product-i/](https://leetcode.cn/problems/smallest-divisible-digit-product-i/)

<p>给你两个整数&nbsp;<code>n</code> 和&nbsp;<code>t</code>&nbsp;。请你返回大于等于&nbsp;<code>n</code>&nbsp;的&nbsp;<strong>最小</strong>&nbsp;整数，且该整数的&nbsp;<strong>各数位之积</strong>&nbsp;能被&nbsp;<code>t</code>&nbsp;整除。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>n = 10, t = 2</span></p>

<p><span class="example-io"><b>输出：</b>10</span></p>

<p><strong>解释：</strong></p>

<p>10 的数位乘积为 0 ，可以被 2 整除，所以它是大于等于 10 且满足题目要求的最小整数。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>n = 15, t = 3</span></p>

<p><span class="example-io"><b>输出：</b>16</span></p>

<p><strong>解释：</strong></p>

<p>16 的数位乘积为 6 ，可以被 3 整除，所以它是大于等于 15 且满足题目要求的最小整数。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= t &lt;= 10</code></li>
</ul>


    
## 解题方法：从n开始尝试

从$n$开始递增枚举，如果当前数字每一位只积是$t$的倍数，则返回。

最多枚举$10$个数一定会出现一个$0$，$0$一定是$t$的倍数。

+ 时间复杂度$O(\log n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-08-06 15:21:51
 */
class Solution {
private:
    bool ok(int n, int t) {
        int mul = 1;
        while (n) {
            mul *= n % 10;
            n /= 10;
        }
        return mul % t == 0;
    }
public:
    int smallestNumber(int n, int t) {
        while (!ok(n, t)) {
            n++;
        }
        return n;
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-08-06 15:24:33
'''
class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        while True:
            mul = 1
            for i in str(n):
                mul *= ord(i) - ord('0')
            if mul % t == 0:
                return n
            n += 1
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/163537421)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/08/06/LeetCode%203345.%E6%9C%80%E5%B0%8F%E5%8F%AF%E6%95%B4%E9%99%A4%E6%95%B0%E4%BD%8D%E4%B9%98%E7%A7%AFI/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
