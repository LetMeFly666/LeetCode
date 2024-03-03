---
title: 509.斐波那契数
date: 2022-11-06 08:55:29
tags: [题解, LeetCode, 简单, 困难, 递归, 记忆化搜索, 记忆化, 数学, 动态规划, DP, 原地滚动, 斐波那契, 哈希, 矩阵快速幂, 通项公式]
---

# 【LetMeFly】尝试以四种方式吃透：509.斐波那契数（四种大方法+两种小优化）

先说明本题解法：

1. 动态规划（及 原地滚动的优化）
2. 递归（及 记忆化的优化）
3. 矩阵快速幂
4. 通项公式

---

力扣题目链接：[https://leetcode.cn/problems/fibonacci-number/](https://leetcode.cn/problems/fibonacci-number/)

<p><strong>斐波那契数</strong>&nbsp;（通常用&nbsp;<code>F(n)</code> 表示）形成的序列称为 <strong>斐波那契数列</strong> 。该数列由&nbsp;<code>0</code> 和 <code>1</code> 开始，后面的每一项数字都是前面两项数字的和。也就是：</p>

<pre>
F(0) = 0，F(1)&nbsp;= 1
F(n) = F(n - 1) + F(n - 2)，其中 n &gt; 1
</pre>

<p>给定&nbsp;<code>n</code> ，请计算 <code>F(n)</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>1
<strong>解释：</strong>F(2) = F(1) + F(0) = 1 + 0 = 1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 3
<strong>输出：</strong>2
<strong>解释：</strong>F(3) = F(2) + F(1) = 1 + 1 = 2
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 4
<strong>输出：</strong>3
<strong>解释：</strong>F(4) = F(3) + F(2) = 2 + 1 = 3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 30</code></li>
</ul>


    
## 方法一：动态规划

开辟一个大小为$30$的数组$a$（或开辟大小为$n+1$的数组也可）

初始值$a[0] = 0, a[1] = 1$

之后从下标$2$开始到$n$为止，使用转移方程$a[n] = a[n - 1] + a[n - 2]$求解

最终返回```a[n]```即可

+ 时间复杂度$O(n)$
+ 空间复杂度$O(C)$，这里$C$是数据中$n$的最大值$30$（也可以只开辟$n+1$的数组，则空间复杂度为$O(n)$）

### AC代码

#### C++

```cpp
class Solution {  // 开辟一整个数组
public:
    int fib(int n) {
        int a[31] = {0, 1};
        for (int i = 2; i <= n; i++)
            a[i] = a[i - 1] + a[i - 2];
        return a[n];
    }
};
```

## 方法一.2：动态规划 + 原地滚动

不难发现，在计算$a[n]$时，我们只用到了$a[n-1]$和$a[n-2]$，再往前的数据就再也用不到了

因此，我们只需要使用两个额外的空间$_0$和$_1$来分别记录$a[n-1]$和a[n-2]$的值，在计算过程中，不断更新$_0$和$_1$的值即可

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {  // 两个额外变量模拟
public:
    int fib(int n) {
        if (n < 2)
            return n;
        int _0 = 0, _1 = 1;  // 分别代表a[n - 2]和a[n - 1]
        int ans;
        for (int i = 2; i <= n; i++) {
            ans = _0 + _1;
            _0 = _1, _1 = ans;  // Update
        }
        return ans;
    }
};
```

## 方法二：递归

斐波那契数列很容易看出“递归”

题目都说明了，$F(n) = F(n - 1) + F(n - 2)$，终止条件是$n = 0$或$n = 1$

那么，我们只需要在非终止条件下无脑递归即可。

+ 时间复杂度$O(n^2)$，**这个时间复杂度待会儿分析**
+ 空间复杂度$O(n)$，不论总递归次数为多少，总递归深度为$n$

### AC代码

#### C++

```cpp
class Solution {  // 递归
public:
    int fib(int n) {
        if (n < 2)
            return n;
        return fib(n - 1) + fib(n - 2);
    }
};
```

## 方法二.2：递归 + 记忆化

方法二在数据量小的前提下能很轻松地计算出结果。

但是为什么方法二的时间复杂度是$O(n^2)$呢？

不难发现，计算$F(5)$时，会调用$F(4)$和$F(3)$，但在计算$F(4)$时，会再调用一次$F(3)$，也就是说$F(3)$不只被调用了一次

例如计算$F(6)$时：

![demo](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/016d3e18ed4e4c0fb50cdf99c2cc489a.png)

$F(4)$计算了两次，$F(3)$计算了三次，$F(2)$更是计算了五次。

$n$越大，这种重复计算就越明显。

那么，既然算过一遍$F(3)$了，为什么要再算一次呢？

**记忆化**出现了

我们使用一个哈希表，将计算过的结果记录下来，那么再次调用这个函数时，直接返回之前计算过的结果不就可以了吗？

![demo2](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/4973f2d70be24f3ca12d6ed09ecc63ea.png)

这样就避免了没必要的重复计算。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {  // 递归 + 记忆化
private:
    unordered_map<int, int> ma;
public:
    int fib(int n) {
        if (n < 2)
            return n;
        if (ma.count(n))
            return ma[n];
        return ma[n] = fib(n - 1) + fib(n - 2);
    }
};
```

## 方法三：矩阵快速幂

$$\left[\begin{array}{ll}
1 & 1 \\
1 & 0
\end{array}\right]\left[\begin{array}{c}
a_n \\
a_{n-1}
\end{array}\right]=\left[\begin{array}{c}
a_n+a_{n-1} \\
a_n
\end{array}\right]=\left[\begin{array}{c}
a_{n+1} \\
a_n
\end{array}\right]$$

因此

$$\left[\begin{array}{c}
a_{n+1} \\
a_n
\end{array}\right]=\left[\begin{array}{ll}
1 & 1 \\
1 & 0
\end{array}\right]^{n}\left[\begin{array}{l}
a_1 \\
a_0
\end{array}\right]$$

因此可以使用矩阵快速幂求出

$$\left[\begin{array}{ll}
1 & 1 \\
1 & 0
\end{array}\right]^{n-1}$$

再将其右乘$\left[\begin{array}{c}a_{1} \\ a_0\end{array}\right]$即得到$\left[\begin{array}{c}a_{n} \\ a_{n-1}\end{array}\right]$

假设：

$$\left[\begin{array}{ll}1 & 1 \\ 1 & 0\end{array}\right]^{n-1}=\left[\begin{array}{ll}x & y \\ m & n\end{array}\right]$$

那么：

$$\left[\begin{array}{c}a_{n} \\ a_{n-1}\end{array}\right]=\left[\begin{array}{ll}1 & 1 \\ 1 & 0\end{array}\right]^{n-1}\left[\begin{array}{c}a_{1} \\ a_0\end{array}\right]=\left[\begin{array}{ll}x & y \\ m & n\end{array}\right]\left[\begin{array}{ll}1\\ 0\end{array}\right]=\left[\begin{array}{ll}x\\ m\end{array}\right]$$

因此$a_n=x$，也就是$\left[\begin{array}{ll}1 & 1 \\ 1 & 0\end{array}\right]^{n-1}$的左上角的值

+ 时间复杂度$O(\log n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
struct Matrix {
    int a[2][2];

    Matrix(int x, int y, int m, int n) {
        a[0][0] = x, a[0][1] = y;
        a[1][0] = m, a[1][1] = n;
    }

    Matrix() {
        a[0][0] = 0, a[0][1] = 0;
        a[1][0] = 0, a[1][1] = 0;
    }
};

Matrix operator* (const Matrix& a, const Matrix& b) {
    Matrix result;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result.a[i][j] = a.a[i][0] * b.a[0][j] + a.a[i][1] * b.a[1][j];
        }
    }
    return result;
}

class Solution {
private:
    Matrix Pow(Matrix a, int n) {  // 这里只接受>0的n
        Matrix result(1, 0, 0, 1);
        while (n) {
            if (n & 1)
                result = result * a;
            n >>= 1;
            a = a * a;
        }
        return result;
    }
public:
    int fib(int n) {
        if (n < 2)
            return n;
        return Pow(Matrix(1, 1, 1, 0), n - 1).a[0][0];
    }
};
```

## 方法四：通项公式

使用生成函数求斐波那契的通项公式

设$\ \ \ \ F(x)=F_1x+F_2x^2+F_3x^3+F_4x^4+\cdots$

则$\ \ xF(x)=\ \ \ \ \ \ \ \ \ \ \ F_1x^2+F_2x^3+F_3x^4+\cdots$

且$x^2F(x)=\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ F_1x^3+F_2x^4+\cdots$

因此，$(x^2+x)F(x)=F_1x^2+(F_2+F_1)x^3+(F_3+F_4)x^4+\cdots=F_1x^2+F_3x^3+F_4x^4+\cdots$

因此，$(1-(x^2+x))F(x)=F_1x+(F_2-F_1)x^2$

即$(1-x-x^2)F(x)=x$

所以$F(x)=\frac{x}{1-x-x^2}=-\frac{x}{\left(x-\frac{\sqrt{5}-1}{2}\right)\left(x+\frac{\sqrt{5}+1}{2}\right)}=-\frac{1}{\sqrt{5}}(\frac{1}{\frac{\sqrt{5}-1}{2} x+1}+\frac{1}{\frac{\sqrt{5}+1}{2} x-1})$

我们求出了斐波那契数列的生成函数

**接下来通过生成函数求原始数列**

设$G(x)=\frac{1}{ax+b}$，其对应的原始数列是$\{g_i\}$

则有$\frac{1}{ax+b}=\sum_{i=1}^\infty g_ix^i$

已知$n\to \infty$时$1+x+x^2+\cdots+x^n=\frac{1}{1-x}$

用$-x$替换$x$得$\frac{1}{1+x}=1-x+x^2-x^3+\cdots$

所以$\frac{1}{bx+b}=\frac1b-\frac1bx+\frac1bx^2-\frac1bx^3+\cdots$

用$\frac{a}bx$替换$x$得$\frac1{ax+b}=\frac{1}{b}-\frac{a}{b^{2}} x+\frac{a^{2}}{b^{3}} x^{2}-\frac{a^{3}}{b^{4}} x^{3}+\cdots$

所以$x^n$的系数$g_n=(-1)^na^nb^{-(n+1)}$

之前我们求出$F(x)=-\frac{1}{\sqrt{5}}(\frac{1}{\frac{\sqrt{5}-1}{2} x+1}+\frac{1}{\frac{\sqrt{5}+1}{2} x-1})$

对于$\frac{1}{\frac{\sqrt{5}-1}{2} x+1}$，令$a=\frac{\sqrt{5}-1}{2},b=1$得$g_n=(\frac{1-\sqrt5}{2})^n$，因此$G(x)=\{(\frac{1-\sqrt5}{2})^x\}$

对于$\frac{1}{\frac{\sqrt{5}+1}{2} x-1}$，令$a=\frac{\sqrt{5}+1}{2},b=-1$得$g_n=-(\frac{1+\sqrt5}{2})^n$，因此$G(x)=\{-(\frac{1+\sqrt5}{2})^x\}$

所以$a_n=-\frac{1}{\sqrt{5}}[(\frac{1-\sqrt5}{2})^x-(\frac{1+\sqrt5}{2})^x]=\frac{1}{\sqrt{5}}\left[\left(\frac{1+\sqrt{5}}{2}\right)^{n}-\left(\frac{1-\sqrt{5}}{2}\right)^{n}\right]$ 即为所求

+ 时间复杂度不好衡量（也不能说O(1)吧，但是肯定比矩阵快速幂快，毕竟CPU有专门的求幂指令）
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int fib(int n) {
        return 1. / sqrt(5) * (pow((1 + sqrt(5)) / 2, n) - pow((1 - sqrt(5)) / 2, n));
    }
};
```

有同学说，比赛的时候忘记了通项公式怎么办，总不能现场手推一遍吧

其实我们只需要记得通项公式的大概形势：$a_n=\frac{1}{\sqrt{5}}\left[\left(\frac{1+\sqrt{5}}{2}\right)^{n}-\left(\frac{1-\sqrt{5}}{2}\right)^{n}\right]=x_1y_1^n+x_2y_2^n$

因此代入几个$a$就把$x_1,y_1,x_2,y_2$解出来了（$a_0=0,a_1=1,\cdots$）

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/11/06/LeetCode%200509.%E6%96%90%E6%B3%A2%E9%82%A3%E5%A5%91%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127712505](https://letmefly.blog.csdn.net/article/details/127712505)
