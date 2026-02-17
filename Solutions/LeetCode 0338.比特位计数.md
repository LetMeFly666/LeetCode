---
title: 338.比特位计数
date: 2022-09-28 12:54:20
tags: [题解, LeetCode, 简单, 位运算, 动态规划]
categories: [题解, LeetCode]
---

# 【LetMeFly】338.比特位计数：三种方法求一个数二进制下有多少个1

力扣题目链接：[https://leetcode.cn/problems/counting-bits/](https://leetcode.cn/problems/counting-bits/)

<p>给你一个整数 <code>n</code> ，对于&nbsp;<code>0 &lt;= i &lt;= n</code> 中的每个 <code>i</code> ，计算其二进制表示中 <strong><code>1</code> 的个数</strong> ，返回一个长度为 <code>n + 1</code> 的数组 <code>ans</code> 作为答案。</p>

<p>&nbsp;</p>

<div class="original__bRMd">
<div>
<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>[0,1,1]
<strong>解释：</strong>
0 --&gt; 0
1 --&gt; 1
2 --&gt; 10
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 5
<strong>输出：</strong>[0,1,1,2,1,2]
<strong>解释：</strong>
0 --&gt; 0
1 --&gt; 1
2 --&gt; 10
3 --&gt; 11
4 --&gt; 100
5 --&gt; 101
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<ul>
	<li>很容易就能实现时间复杂度为 <code>O(n log n)</code> 的解决方案，你可以在线性时间复杂度 <code>O(n)</code> 内用一趟扫描解决此问题吗？</li>
	<li>你能不使用任何内置函数解决此问题吗？（如，C++ 中的&nbsp;<code>__builtin_popcount</code> ）</li>
</ul>
</div>
</div>


    
## 写在前面

本篇题解的三种方法不论哪一种，大致思路就是对于某个数，单独求出其二进制下有多少个1。

每个数的求解是相互独立的，求这一个数的时候没有用到上一个数的结果。

## 方法一：每次取最低位

对于一个数$n$，在$n\neq0$时，不断取出当前$n$的最低位，判断是否为1（$n\&1$）

之后，将$n$的最低位丢弃（右移即可，$n>>1$）

这样就统计出了$n$在二进制下有多少个1。

+ 时间复杂度$O(n\log_2 n)$
+ 空间复杂度$O(1)$，力扣算法答案不计入空间复杂度

### AC代码

#### C++

不为0时取最低位,时间/空间超越：7.24%,55.59%

```cpp
class Solution {
private:
    int __LetMeFly_popcount(int n) {
        int ans = 0;
        while (n) {
            if (n & 1)
                ans++;
            n >>= 1;
        }
        return ans;
    }
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; i++) {
            ans[i] = __LetMeFly_popcount(i);
        }
        return ans;
    }
};
```

## 方法二：借助内置函数__builtin_popcount

对于一个数$n$，我们可以直接使用内置函数__builtin_popcount(n)来求出n在二进制下有多少个1

有些编译器不支持上述操作，但是力扣是支持的

+ 时间复杂度$O(n\log_2 n)$
+ 空间复杂度$O(1)$，力扣算法答案不计入空间复杂度

### AC代码

#### C++

内置__builtin_popcount,时间/空间超越：83.71%,56.81%

```cpp
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; i++) {
            ans[i] = __builtin_popcount(i);
        }
        return ans;
    }
};
```

## 方法三：借助lowbit

对于一个数$n$，我们可以巧妙借助$lowbit$来快速取出$n$中的1

$lowbit$可以在$O(1)$的复杂度内求出：一个数二进制下第一个1开始到二进制下最后一位 所组成的数。

说人话就是：

假如$n=6(110_2)$，那么$lowbit(6)$就等于$10_2$，也就是十进制下的$2$

这样，每次求得$lowbit$后再减去之，就能每次消灭一个$1$

二进制下有$k$个$1$的一个数$n$只需要进行$k$次运算就能求得答案。

具体原理可参考我之前的笔记：[https://letmefly.xyz/Notes/ACM/Template/lowbit.html](https://letmefly.xyz/Notes/ACM/Template/lowbit.html)

喜欢了可以给个[Star](https://github.com/LetMeFly666/various)

+ 时间复杂度$O(n K)$，其中$K$是$n$个数平均的“二进制下1的个数”
+ 空间复杂度$O(1)$，力扣算法答案不计入空间复杂度

### AC代码

#### C++

借助lowbit,时间/空间超越：83.71%,96.33%

```cpp
class Solution {
private:
    int __LetMeFly_popcount_byLowbit(int n) {
        int ans = 0;
        while (n) {
            n -= (n & -n);
            ans++;
        }
        return ans;
    }
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; i++) {
            ans[i] = __LetMeFly_popcount_byLowbit(i);
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/09/28/LeetCode%200338.%E6%AF%94%E7%89%B9%E4%BD%8D%E8%AE%A1%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127087581](https://letmefly.blog.csdn.net/article/details/127087581)
