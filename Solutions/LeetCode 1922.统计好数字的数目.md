---
title: 1922.统计好数字的数目：乘法原理+快速幂
date: 2025-04-14 00:31:36
tags: [题解, LeetCode, 中等, 数学, 乘法原理, 快速幂]
categories: [题解, LeetCode]
---

# 【LetMeFly】1922.统计好数字的数目：乘法原理+快速幂

力扣题目链接：[https://leetcode.cn/problems/count-good-numbers/](https://leetcode.cn/problems/count-good-numbers/)

<p>我们称一个数字字符串是 <strong>好数字</strong> 当它满足（下标从 <strong>0</strong> 开始）<strong>偶数</strong> 下标处的数字为 <strong>偶数</strong> 且 <strong>奇数</strong> 下标处的数字为 <strong>质数</strong> （<code>2</code>，<code>3</code>，<code>5</code> 或 <code>7</code>）。</p>

<ul>
	<li>比方说，<code>"2582"</code> 是好数字，因为偶数下标处的数字（<code>2</code> 和 <code>8</code>）是偶数且奇数下标处的数字（<code>5</code> 和 <code>2</code>）为质数。但 <code>"3245"</code> <strong>不是</strong> 好数字，因为 <code>3</code> 在偶数下标处但不是偶数。</li>
</ul>

<p>给你一个整数 <code>n</code> ，请你返回长度为 <code>n</code> 且为好数字的数字字符串 <strong>总数</strong> 。由于答案可能会很大，请你将它对<strong> </strong><code>10<sup>9</sup> + 7</code> <strong>取余后返回</strong> 。</p>

<p>一个 <strong>数字字符串</strong> 是每一位都由 <code>0</code> 到 <code>9</code> 组成的字符串，且可能包含前导 0 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>n = 1
<b>输出：</b>5
<b>解释：</b>长度为 1 的好数字包括 "0"，"2"，"4"，"6"，"8" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>n = 4
<b>输出：</b>400
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>n = 50
<b>输出：</b>564908303
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 10<sup>15</sup></code></li>
</ul>


    
## 解题方法：乘法原理+快速幂

每个偶数下标有5种选择，每个奇数下标有4种选择，每个元素之间的选择互补干扰冲突。

由于共有$a=\lfloor\frac{n+1}{2}\rfloor$个偶数位和$b=\lfloor\frac{n}{2}\rfloor$个奇数位，所以一共有$5^a4^b$种答案。

如何快速计算$m^n$？使用[快速幂](https://blog.letmefly.xyz/tags/%E5%BF%AB%E9%80%9F%E5%B9%82/)可在$\log n$的时间复杂度内求出。

快速幂原理方法请见：[这里](https://web.letmefly.xyz/Notes/ACM/Problems/%E5%BF%AB%E9%80%9F%E5%B9%82/)。

+ 时间复杂度$O(\log n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-04-13 17:00:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-13 17:06:07
 * @Description: AC,100.00%,51.97%
 */
typedef long long ll;
const ll MOD = 1e9 + 7;

class Solution {
private:
    ll pow(ll a, ll b) {
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
    int countGoodNumbers(long long n) {
        return pow(5, (n + 1) / 2) * pow(4, n / 2) % MOD;
    }
};
```

#### Python

Python用户可以无视手动实现快速幂。

```python
'''
Author: LetMeFly
Date: 2025-04-13 17:06:16
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-13 17:06:17
'''
MOD = 1000000007

class Solution:
    def countGoodNumbers(self, n: int) -> int:
        return pow(5, (n + 1) // 2, MOD) * pow(4, n // 2, MOD) % MOD
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-04-13 17:07:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-14 00:07:21
 * @Description: AC,100.00%,87.23%
 */
class Solution {
    private final long mod = 1000000007;

    private long pow(long a, long b) {
        long ans = 1;
        while (b > 0) {
            if ((b & 1) == 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
            b >>= 1;
        }
        return ans;
    }

    public int countGoodNumbers(long n) {
        return (int)(pow(5, (n + 1) / 2) * pow(4, n / 2) % mod);
    }
}
```

#### Golang

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-04-13 17:54:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-14 00:05:17
 * @Description: continue on subway，太晃了还是先算了
 * @Description: AC,100.00%,63.16%
 */
package main

var MOD1922 = int64(1000000007)

func pow1922(a int64, b int64) int64 {
	ans := int64(1)
	for ; b > 0; b >>= 1 {
		if b & 1 == 1 {
			ans = ans * a % MOD1922
		}
		a = a * a % MOD1922
	}
	return ans
}

func countGoodNumbers(n int64) int {
    return int(pow1922(5, (n + 1) / 2) * pow1922(4, n / 2) % MOD1922)
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/147200001)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/04/14/LeetCode%201922.%E7%BB%9F%E8%AE%A1%E5%A5%BD%E6%95%B0%E5%AD%97%E7%9A%84%E6%95%B0%E7%9B%AE/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
