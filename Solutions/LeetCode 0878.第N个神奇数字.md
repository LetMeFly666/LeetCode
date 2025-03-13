---
title: 878.第 N 个神奇数字
date: 2022-11-22 10:43:26
tags: [题解, LeetCode, 困难, 数学, 二分查找, 二分, 最小公倍数, lcm]
categories: [题解, LeetCode]
---

# 【LetMeFly】878.第 N 个神奇数字

力扣题目链接：[https://leetcode.cn/problems/nth-magical-number/](https://leetcode.cn/problems/nth-magical-number/)

<p>一个正整数如果能被 <code>a</code> 或 <code>b</code> 整除，那么它是神奇的。</p>

<p>给定三个整数 <code>n</code> ,&nbsp;<code>a</code> , <code>b</code> ，返回第 <code>n</code> 个神奇的数字。因为答案可能很大，所以返回答案&nbsp;<strong>对&nbsp;</strong><code>10<sup>9</sup>&nbsp;+ 7</code> <strong>取模&nbsp;</strong>后的值。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 1, a = 2, b = 3
<strong>输出：</strong>2
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入：</strong>n = 4, a = 2, b = 3
<strong>输出：</strong>6
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
	<li><code>2 &lt;= a, b &lt;= 4 * 10<sup>4</sup></code></li>
</ul>

<p>&nbsp;</p>


    
## 方法一：二分查找

根据鸽巢原理，在$1\sim x$中，有$\lfloor\frac{x}{a}\rfloor+\lfloor\frac{x}{b}\rfloor-\lfloor\frac{x}{c}\rfloor$个“神奇数”，其中$c$是$a$和$b$的最小公倍数。

因此，我们可以直接二分$x$找到第$n$个“神奇数”即可。

+ 时间复杂度$O(\log(n\times\min(a, b)))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
typedef long long ll;
class Solution {
public:
    int nthMagicalNumber(int n, ll a, ll b) {
        ll c = lcm(a, b);
        ll l = min(a, b), r = n * min(a, b);
        while (l <= r) {
            ll mid = (l + r) >> 1;
            if (mid / a + mid / b - mid / c >= n)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return (r + 1) % 1000000007;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/11/22/LeetCode%200878.%E7%AC%ACN%E4%B8%AA%E7%A5%9E%E5%A5%87%E6%95%B0%E5%AD%97/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127978493](https://letmefly.blog.csdn.net/article/details/127978493)
