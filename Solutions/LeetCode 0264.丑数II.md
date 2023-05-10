---
title: 264.丑数 II
date: 2022-09-13 19:18:53
tags: [题解, LeetCode, 中等, 哈希表, 数学, 动态规划, 堆（优先队列）]
---

# 【LetMeFly】264.丑数 II

力扣题目链接：[https://leetcode.cn/problems/ugly-number-ii/](https://leetcode.cn/problems/ugly-number-ii/)

<p>给你一个整数 <code>n</code> ，请你找出并返回第 <code>n</code> 个 <strong>丑数</strong> 。</p>

<p><strong>丑数 </strong>就是只包含质因数 <code>2</code>、<code>3</code> 和/或 <code>5</code> 的正整数。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 10
<strong>输出：</strong>12
<strong>解释：</strong>[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 是由前 10 个丑数组成的序列。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>1
<strong>解释：</strong>1 通常被视为丑数。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 1690</code></li>
</ul>


    
## 方法一：取最小

开辟一个大小为$n$的数组，第$i$个元素代表第$i$个“丑数”

初始值为：第一个元素是“1”

因为“丑数”的因数中只能包含“2”、“3”、“5”，因此每次分别拿“2”、“3”、“5”去乘某一个“丑数”，最小结果就是下一个“丑数”

乘“丑数”的顺序为：“2”、“3”、“5”相互独立。对于“2”来说，从第一个丑数开始逐渐往后尝试，若为最小则后移。

```
丑数
1
↑↑↑
235

2 * 1 = 2  ----+
3 * 1 = 3      +---> 最小的是2 * 1 = 2
5 * 1 = 5  ----+
```

👇

```
丑数
1      2
↑↑     ↑
35     2

2 * 2 = 4  ----+
3 * 1 = 3      +---> 最小的是3 * 1 = 3
5 * 1 = 5  ----+
```

👇

```
丑数
1      2        3
↑      ↑↑
5      23

2 * 2 = 4  ----+
3 * 2 = 6      +---> 最小的是2 * 2 = 4
5 * 1 = 5  ----+
```

👇

```
丑数
1      2       3      4
↑      ↑       ↑
5      3       2

2 * 3 = 6  ----+
3 * 2 = 6      +---> 最小的是5 * 1 = 5
5 * 1 = 5  ----+
```

👇

```
丑数
1     2      3      4     5
      ↑↑     ↑
      35     2

2 * 3 = 6  ----+
3 * 2 = 6      +---> 最小的是2 * 3 = 6和3 * 2 = 6
5 * 2 = 10 ----+
```

👇

```
丑数
1     2      3      4     5     6
      ↑      ↑      ↑
      5      3      2

2 * 4 = 8  ----+
3 * 3 = 9      +---> 最小的是2 * 4 = 8
5 * 2 = 10 ----+
```

👇

```
丑数
1     2     3     4     5     6    8
      ↑     ↑           ↑
      5     3           2
```

每次都会新生成一个丑数。在“2”、“3”、“5”中，哪个数的运算结果等于最小丑数，哪个数的指针就后移一位。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> a(n);
        a[0] = 1;
        int _2 = 0, _3 = 0, _5 = 0;
        int toLoc = 1;
        for (int i = 1; i < n; i++) {
            int ans2 = a[_2] * 2;
            int ans3 = a[_3] * 3;
            int ans5 = a[_5] * 5;
            int m = min(ans2, min(ans3, ans5));
            a[toLoc++] = m;
            if (ans2 == m) {
                _2++;
            }
            if (ans3 == m) {
                _3++;
            }
            if (ans5 == m) {
                _5++;
            }
        }
        return a[n - 1];
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/09/13/LeetCode%200264.%E4%B8%91%E6%95%B0II/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126840084](https://letmefly.blog.csdn.net/article/details/126840084)
