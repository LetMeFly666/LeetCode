---
title: 190.颠倒二进制位
date: 2022-08-14 13:11:10
tags: [题解, LeetCode, 简单, 位运算, 分治]
categories: [题解, LeetCode]
---

# 【LetMeFly】190.颠倒二进制位

力扣题目链接：[https://leetcode.cn/problems/reverse-bits/](https://leetcode.cn/problems/reverse-bits/)

<p>颠倒给定的 32 位无符号整数的二进制位。</p>

<p><strong>提示：</strong></p>

<ul>
	<li>请注意，在某些语言（如 Java）中，没有无符号整数类型。在这种情况下，输入和输出都将被指定为有符号整数类型，并且不应影响您的实现，因为无论整数是有符号的还是无符号的，其内部的二进制表示形式都是相同的。</li>
	<li>在 Java 中，编译器使用<a href="https://baike.baidu.com/item/二进制补码/5295284" target="_blank">二进制补码</a>记法来表示有符号整数。因此，在 <strong>示例 2</strong>&nbsp;中，输入表示有符号整数 <code>-3</code>，输出表示有符号整数 <code>-1073741825</code>。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 00000010100101000001111010011100
<strong>输出：</strong>964176192 (00111001011110000010100101000000)
<strong>解释：</strong>输入的二进制串 <strong>00000010100101000001111010011100 </strong>表示无符号整数<strong> 43261596</strong><strong>，
    </strong> 因此返回 964176192，其二进制表示形式为 <strong>00111001011110000010100101000000</strong>。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 11111111111111111111111111111101
<strong>输出：</strong>3221225471 (10111111111111111111111111111111)
<strong>解释：</strong>输入的二进制串 <strong>11111111111111111111111111111101</strong> 表示无符号整数 4294967293，
   &nbsp; 因此返回 3221225471 其二进制表示形式为 <strong>10111111111111111111111111111111 。</strong></pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>输入是一个长度为 <code>32</code> 的二进制字符串</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶</strong>: 如果多次调用这个函数，你将如何优化你的算法？</p>


    
## 方法一：位运算

直接从$0$到$31$枚举答案的第$i$位，如果原数$n$的这一位是$1$，就把答案的这一位置为$1$

+ 时间复杂度$O(C)$，其中$C$是$32$位无符号整数的二进制位数（$32$）
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2022-08-14 13:10:21
 */
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << (31 - i)))
                ans |= (1 << i);
        }
        return ans;
    }
};
```

#### C++

```cpp
/*
 * @LastEditTime: 2026-02-16 15:26:10
 */
class Solution {
public:
    int reverseBits(int n) {
        unsigned ans = 0;
        for (int i = 0; i < 32; i++, n >>= 1) {
            if (n & 1) {
                ans |= 1 << (31 - i);
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/08/14/LeetCode%200190.%E9%A2%A0%E5%80%92%E4%BA%8C%E8%BF%9B%E5%88%B6%E4%BD%8D/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126330708](https://letmefly.blog.csdn.net/article/details/126330708)
