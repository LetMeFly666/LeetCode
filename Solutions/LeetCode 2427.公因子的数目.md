---
title: 2427.公因子的数目
date: 2023-04-05 12:55:40
tags: [题解, LeetCode, 简单, 数学, 枚举, 数论, 枚举, 最大公约数, gcd, 遍历]
---

# 【LetMeFly】2427.公因子的数目

力扣题目链接：[https://leetcode.cn/problems/number-of-common-factors/](https://leetcode.cn/problems/number-of-common-factors/)

<p>给你两个正整数 <code>a</code> 和 <code>b</code> ，返回 <code>a</code> 和 <code>b</code> 的 <strong>公</strong> 因子的数目。</p>

<p>如果 <code>x</code> 可以同时整除 <code>a</code> 和 <code>b</code> ，则认为 <code>x</code> 是 <code>a</code> 和 <code>b</code> 的一个 <strong>公因子</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>a = 12, b = 6
<strong>输出：</strong>4
<strong>解释：</strong>12 和 6 的公因子是 1、2、3、6 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>a = 25, b = 30
<strong>输出：</strong>2
<strong>解释：</strong>25 和 30 的公因子是 1、5 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= a, b &lt;= 1000</code></li>
</ul>


    
## 方法一：从1枚举到min(a, b)，看是否可以同时被整除

a和b的最大值都是1000，因此我们可以直接从1枚举到min(a, b)，如果当前枚举值能同时被a和b整除，那么答案数量就加一。

+ 时间复杂度$O(\min(a, b))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int commonFactors(int a, int b) {
        int ans = 0;
        for (int i = 1; i <= min(a, b); i++) {
            if (a % i == 0 && b % i == 0) {
                ans++;
            }
        }
        return ans;
    }
};
```

#### Python

```python
class Solution:
    def commonFactors(self, a: int, b: int) -> int:
        return sum(a % i == 0 and b % i == 0 for i in range(1, min(a, b) + 1))
```

## 方法二：计算a和b的最大公约数有多少个因子

如果一个数能同时被a和b整除，那么这个数一定能被a和b的最大公约数整除。

计算出a和b的最大公约数（记为c），我们只需要计算c的因子有多少个。

因此我们可以使用$i$从$1$到$\sqrt c$枚举，如果$c \% i == 0$，就$ans++$。记得看$\frac{c}{i}$是否等于$i$，如果不等，则$\frac{c}{i}$也是$c$的一个因数

+ 时间复杂度$O(\sqrt{\gcd(a, b)}$，求最大公约数的时间可以忽略不计
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int commonFactors(int a, int b) {
        int ans = 0;
        int c = gcd(a, b);
        int to = sqrt(c);
        for (int i = 1; i <= to; i++) {
            if (c % i == 0) {
                ans++;
                if (c / i != i) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
```

#### Python

```python
from math import gcd, sqrt
class Solution:
    def commonFactors(self, a: int, b: int) -> int:
        ans = 0
        c = gcd(a, b)
        for i in range(1, int(sqrt(c)) + 1):
            if c % i == 0:
                ans += 1
                if c // i != i:
                    ans += 1
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/04/05/LeetCode%202427.%E5%85%AC%E5%9B%A0%E5%AD%90%E7%9A%84%E6%95%B0%E7%9B%AE/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129969312](https://letmefly.blog.csdn.net/article/details/129969312)
