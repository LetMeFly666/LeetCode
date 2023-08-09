---
title: 1281.整数的各位积和之差
date: 2023-08-09 08:12:03
tags: [题解, LeetCode, 简单, 数学, 各位和]
---

# 【LetMeFly】1281.整数的各位积和之差

力扣题目链接：[https://leetcode.cn/problems/subtract-the-product-and-sum-of-digits-of-an-integer/](https://leetcode.cn/problems/subtract-the-product-and-sum-of-digits-of-an-integer/)

<p>给你一个整数&nbsp;<code>n</code>，请你帮忙计算并返回该整数「各位数字之积」与「各位数字之和」的差。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 234
<strong>输出：</strong>15 
<strong>解释：</strong>
各位数之积 = 2 * 3 * 4 = 24 
各位数之和 = 2 + 3 + 4 = 9 
结果 = 24 - 9 = 15
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 4421
<strong>输出：</strong>21
<strong>解释： 
</strong>各位数之积 = 4 * 4 * 2 * 1 = 32 
各位数之和 = 4 + 4 + 2 + 1 = 11 
结果 = 32 - 11 = 21
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10^5</code></li>
</ul>


    
## 方法一：取出每一位

这道题主要在考察如何取出一个整数的每一位。当然，可以使用内置函数将整数转为字符串，再遍历字符串的每一位。但是还可以：

在整数$n$不为零时：
   1. 取出$n \% 10$来做运算
   2. $n /= 10$

这样就取出整数的每一位了。

+ 时间复杂度$O(\log_{10}n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int subtractProductAndSum(int n) {
        int mul = 1, cnt = 0;
        while (n) {
            mul *= n % 10;
            cnt += n % 10;
            n /= 10;
        }
        return mul - cnt;
    }
};
```

#### Python

```python
class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        mul, cnt = 1, 0
        while n:
            mul *= n % 10
            cnt += n % 10
            n //= 10
        return mul - cnt
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/08/09/LeetCode%201281.%E6%95%B4%E6%95%B0%E7%9A%84%E5%90%84%E4%BD%8D%E7%A7%AF%E5%92%8C%E4%B9%8B%E5%B7%AE/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/132179859](https://letmefly.blog.csdn.net/article/details/132179859)
