---
title: 2652.倍数求和
date: 2023-10-17 09:29:53
tags: [题解, LeetCode, 简单, 数学]
---

# 【LetMeFly】2652.倍数求和：O(1)做法 - 容斥原理

力扣题目链接：[https://leetcode.cn/problems/sum-multiples/](https://leetcode.cn/problems/sum-multiples/)

<p>给你一个正整数 <code>n</code> ，请你计算在 <code>[1，n]</code> 范围内能被 <code>3</code>、<code>5</code>、<code>7</code> 整除的所有整数之和。</p>

<p>返回一个整数，用于表示给定范围内所有满足约束条件的数字之和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 7
<strong>输出：</strong>21
<strong>解释：</strong>在 <code>[1, 7]</code> 范围内能被 3、<code>5、</code><code>7 整除的所有整数分别是</code><code> 3、5、6、7</code> 。数字之和为 <code>21</code> 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 10
<strong>输出：</strong>40
<strong>解释：</strong>在 <code>[1, 10]</code> 范围内能被 3、<code>5、</code><code>7 整除的所有整数分别是</code><code> 3、5、6、7、9、10</code> 。数字之和为 <code>40</code> 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 9
<strong>输出：</strong>30
<strong>解释：</strong>在 <code>[1, 9]</code> 范围内能被 3、<code>5、</code><code>7 整除的所有整数分别是</code><code> 3、5、6、7、9</code> 。数字之和为 <code>30</code> 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>3</sup></code></li>
</ul>


    
## 方法一：O(1)做法 - 容斥原理

从$1$到$n$的数中，是$k$的倍数的数有哪些呢？当然是$k$、$2k$、$\cdots$、$\lfloor\frac{n}{k}\rfloor\times k$。

他们的和为多少呢？等差数列求和公式为$\frac{(首项+尾项)\times 项数}{2}$，因此他们的和为$\frac{(k + \lfloor\frac{n}{k}\rfloor\times k)\times \lfloor\frac{n}{k}\rfloor}{2}$。

根据容斥原理，一个集合中，是$3$的倍数或是$5$的倍数或是$7$的倍数的数，等于$f(3) + f(5) + f(7) - f(3\times5) - f(3\times 7) - f(5\times 7) + f(3\times 5\times 7)$，其中$f(k)$代表是$k$的倍数的数。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
private:
    int n;

    inline int f(int k) {
        return (k + n / k * k) * (n / k) / 2;  // (首项 + 尾项) * 项数 / 2
    }
public:
    int sumOfMultiples(int n) {
        this->n = n;
        return f(3) + f(5) + f(7) - f(15) - f(21) - f(35) + f(105);
    }
};
```

#### Python

```python
class Solution:
    def sumOfMultiples(self, n: int) -> int:
        def f(k: int) -> int:
            return (k + n // k * k) * (n // k) // 2
        return f(3) + f(5) + f(7) - f(15) - f(21) - f(35) + f(105)
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/10/17/LeetCode%202652.%E5%80%8D%E6%95%B0%E6%B1%82%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/133876939](https://letmefly.blog.csdn.net/article/details/133876939)
