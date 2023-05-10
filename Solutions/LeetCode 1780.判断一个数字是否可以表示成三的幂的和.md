---
title: 1780.判断一个数字是否可以表示成三的幂的和
date: 2022-12-09 09:52:16
tags: [题解, LeetCode, 中等, 数学, 进制转换, 二进制枚举]
---

# 【LetMeFly】1780.判断一个数字是否可以表示成三的幂的和

力扣题目链接：[https://leetcode.cn/problems/check-if-number-is-a-sum-of-powers-of-three/](https://leetcode.cn/problems/check-if-number-is-a-sum-of-powers-of-three/)

<p>给你一个整数 <code>n</code> ，如果你可以将 <code>n</code> 表示成若干个不同的三的幂之和，请你返回 <code>true</code> ，否则请返回 <code>false</code> 。</p>

<p>对于一个整数 <code>y</code> ，如果存在整数 <code>x</code> 满足 <code>y == 3<sup>x</sup></code> ，我们称这个整数 <code>y</code> 是三的幂。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>n = 12
<b>输出：</b>true
<b>解释：</b>12 = 3<sup>1</sup> + 3<sup>2</sup>
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>n = 91
<b>输出：</b>true
<b>解释：</b>91 = 3<sup>0</sup> + 3<sup>2</sup> + 3<sup>4</sup>
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>n = 21
<b>输出：</b>false
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>7</sup></code></li>
</ul>



也可直接看效率更高的方法二

## 方法一：二进制枚举

### 题目分析

$3^{14}=4782969<10^7, 3^{15}=14348907>10^7$

因此，想要数个不同的$3$的$n$次幂组成$n$（$n\leq 10^7$），那么最多使用$3^0\~3^{14}$这$15$个数

每个数有“选”与“不选”两种选择，因此最多有$2^{15}=32768$种方案，可以枚举解决。

### 解题思路

那么，我们直接开辟一个数组，把所有的小于等于$n$的“3的幂”放入数组

```cpp
vector<int> three(1, 1);  // 初始值是1个1
while (three.back() < n) {
    three.push_back(three.back() * 3);
}
```

接下来，用一个整数$state$从$0$到$2^{len(three)}$枚举，$state$的第$i$位为$0$则代表使用$three$数组中的第$i$个数，否则代表不使用。

每个$state$代表一种方案，计算所有的方案中，是否有和为$n$的

```cpp
int num = three.size(), to = 1 << num;
for (int state = 0; state < to; state++) {
    int s = 0;
    for (int j = 0; j < num; j++) {
        if (state & (1 << j)) {
            s += three[j];
        }
    }
    if (s == n)
        return true;
}
return false;
```

### 复杂度分析

+ 时间复杂度$O(2^{\log_3 n})$
+ 空间复杂度$O(\log_3 n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> three(1, 1);
        while (three.back() < n) {
            three.push_back(three.back() * 3);
        }
        int num = three.size(), to = 1 << num;
        for (int state = 0; state < to; state++) {
            int s = 0;
            for (int j = 0; j < num; j++) {
                if (state & (1 << j)) {
                    s += three[j];
                }
            }
            if (s == n)
                return true;
        }
        return false;
    }
};
```

## 方法二：进制转换

我们只需要将$n$转化为三进制，然后判断$n$在三进制下是否有$2$

例如$10=(101)_3$，那就说明$10=3^0+3^2$；$15=(120)_3$，那就说明$15=3^2+2\times3^1$，需要两个$3^1$

+ 时间复杂度$O(\log_3 n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n) {
            if (n % 3 == 2)
                return false;
            n /= 3;
        }
        return true;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/12/09/LeetCode%201780.%E5%88%A4%E6%96%AD%E4%B8%80%E4%B8%AA%E6%95%B0%E5%AD%97%E6%98%AF%E5%90%A6%E5%8F%AF%E4%BB%A5%E8%A1%A8%E7%A4%BA%E6%88%90%E4%B8%89%E7%9A%84%E5%B9%82%E7%9A%84%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128248159](https://letmefly.blog.csdn.net/article/details/128248159)
