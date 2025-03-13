---
title: 50.Pow(x, n)
date: 2022-05-25 19:48:49
tags: [题解, LeetCode, 中等, 快速幂]
categories: [题解, LeetCode]
---

# 【LetMeFly】50.Pow(x, n)

实现 [pow(x, n)](https://www.cplusplus.com/reference/valarray/pow/) ，即计算```x```的```n```次幂函数（即，```xⁿ``` ）。

**示例 1:**

```
输入：x = 2.00000, n = 10
输出：1024.00000
```

**示例 2:**

```
输入：x = 2.10000, n = 3
输出：9.26100
```

**示例 3:**

```
输入：x = 2.00000, n = -2
输出：0.25000
解释：2-2 = 1/22 = 1/4 = 0.25
```

**提示:**

+ $-100.0 < x < 100.0$
+ $-2^{31} \leq n \leq 2^{31}-1$
+ $-10^4 \leq x^n \leq 10^4$

# 题目大意

给你一个浮点数$x$和一个整数$n$，让你计算$x^n$。

# 思路

$-10^4 \leq x^n \leq 10^4$，也就是说答案不会异常大。因此直接使用修改版的**快速幂**即可。

## 快速幂

快速幂的介绍有很多，比如可以参考 [https://letmefly.xyz/Notes/ACM/Problems/快速幂    /](https://letmefly.xyz/Notes/ACM/Problems/%E5%BF%AB%E9%80%9F%E5%B9%82/)

但是一般的快速幂都是计算整数的整数次幂的，并且会取模。

因此我们只需要做出一些特殊修改即可：

> 如果$n$是负数，就计算$1 / Pow(x, -n)$

**注意：**

一些编程语言中，$n$一定要记得转为```long long```，因为```-INT_MIN > INT_MAX```

## 方法一：快速幂

直接套用快速幂模板并稍作修改即可。

+ 时间复杂度$O(\log n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
private:
    double Pow(double x, long long n) {  // -INT_MIN > INT_MAX，因此此处需要使用long long
        double ans = 1;
        while (n) {
            if (n & 1) {
                ans *= x;
            }
            x = x * x;
            n >>= 1;
        }
        return ans;
    }
public:
    double myPow(double x, long long n) {  // 这里LeetCode中原本是int n，修改为long long可以避免-(-2147483648) = 2147483648超出INT_MAX
        return n > 0 ? Pow(x, n) : 1 / Pow(x, -n);
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/05/25/LeetCode%200050.Pow(x,%20n)/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/124972517](https://letmefly.blog.csdn.net/article/details/124972517)
