---
title: 9.回文数
date: 2022-10-31 09:33:09
tags: [题解, LeetCode, 简单, 数学, 回文]
---

# 【LetMeFly】9.回文数

力扣题目链接：[https://leetcode.cn/problems/palindrome-number/](https://leetcode.cn/problems/palindrome-number/)

<p>给你一个整数 <code>x</code> ，如果 <code>x</code> 是一个回文整数，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。</p>

<ul>
	<li>例如，<code>121</code> 是回文，而 <code>123</code> 不是。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>x = 121
<strong>输出：</strong>true
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入：</strong>x = -121
<strong>输出：</strong>false
<strong>解释：</strong>从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>x = 10
<strong>输出：</strong>false
<strong>解释：</strong>从右向左读, 为 01 。因此它不是一个回文数。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-2<sup>31</sup>&nbsp;&lt;= x &lt;= 2<sup>31</sup>&nbsp;- 1</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你能不将整数转为字符串来解决这个问题吗？</p>


    
## 方法一：按字符串处理

管他三七二十一，直接把原数当作字符串处理就好。

将原数转为字符串，再将字符串翻转，看看翻转前后是否相同。

所有操作都有现成函数（对于很多编程语言来说都是这样子的）

+ 时间复杂度$O(\log x)$
+ 空间复杂度$O(\log x)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        string s1 = to_string(x);
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        return s1 == s2;
    }
};
```

## 方法二：进阶，对于小数意义不大，但是面试可用：通过十进制下的每一位计算翻转后的值

我们不断取出（并移除）原数十进制下的最后一位，并将这一位“拼接”到新数后面

这样就计算出了新数，比较新数原数是否相等即可。

### Example

```
x = 1235
```

step1.

```
x = 1235
reversed = 0
original = x = 1235
```

step2.

```
x = 123
reversed = 5
```

step3

```
x = 12
reversed = 53
```

step4

```
x = 1
reversed = 532
```

step5

```
x = 0
reversed = 5321
```

step6.

```
reversed != original
return false;
```

### 注意

1. 负数一定不回文
2. 当心计算过程中超过INT_MAX

对于“2.”

假如原数是```2147483647```，那么翻转后就是```7463847412```，超出了```INT_MAX```，导致溢出，在力扣上无法通过

因此，我们令$reversed$乘以$10$并加上新的一位之前，要先判断$\frac{INT_MAX}{10}$是否小于$reversed$

这里不用判断$\frac{INT_MAX - 新一位}{10}$是否小于等于$reversed$

因为$7>2$，如果原数是$10$位数，那么原数的最高位一定不超过$2$，也就是说翻转后的最低位一定不超过$2$，更不会超过$7$

+ 时间复杂度$O(\log x)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int reversed = 0, original = x;
        while (x) {
            if (INT_MAX / 10 < reversed)
                return false;
            reversed = reversed * 10 + (x % 10);
            x /= 10;
        }
        return reversed == original;
    }
};
```

执行效率果然有所提升

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/10/31/LeetCode%200009.%E5%9B%9E%E6%96%87%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127609755](https://letmefly.blog.csdn.net/article/details/127609755)
