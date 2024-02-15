---
title: 231.2 的幂
date: 2022-09-08 15:46:16
tags: [题解, LeetCode, 简单, 位运算, 递归, 数学, 补码]
---

# 【LetMeFly】231.2 的幂

力扣题目链接：[https://leetcode.cn/problems/power-of-two/](https://leetcode.cn/problems/power-of-two/)

<p>给你一个整数 <code>n</code>，请你判断该整数是否是 2 的幂次方。如果是，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>如果存在一个整数 <code>x</code> 使得 <code>n == 2<sup>x</sup></code> ，则认为 <code>n</code> 是 2 的幂次方。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>true
<strong>解释：</strong>2<sup>0</sup> = 1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 16
<strong>输出：</strong>true
<strong>解释：</strong>2<sup>4</sup> = 16
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 3
<strong>输出：</strong>false
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>n = 4
<strong>输出：</strong>true
</pre>

<p><strong>示例 5：</strong></p>

<pre>
<strong>输入：</strong>n = 5
<strong>输出：</strong>false
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-2<sup>31</sup> <= n <= 2<sup>31</sup> - 1</code></li>
</ul>

<p> </p>

<p><strong>进阶：</strong>你能够不使用循环/递归解决此问题吗？</p>


    
## 方法一：位运算 + 负数特判

如果一个数是2的幂，那么这个数的二进制表示中只有一个1，其余全是0。

因此，我们只需要统计$n$在二进制下的$1$的个数即可。

**注意：** 当$n$是负数的时候，C++中算术右移，什么时候都不会变成0（最终会变成-1（每一位都是1））。

如果想要逻辑右移，那么需要把int转为unsigned int。

+ 时间复杂度$O(\log n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 0)
            return false;
        int cnt1 = 0;
        while (n) {
            if (n & 1)
                cnt1++;
            n >>= 1;
        }
        return cnt1 == 1;
    }
};
```

# 方法二：转为unsigned int + INT_MIN特判

32位整数的最小数为$-2^{31}-1$，其二进制（补码表示）为```1000 0000 0000 0000 0000 0000 0000 0000```

原因是：$2^{31}$为```1000 0000 0000 0000 0000 0000 0000 0000```

**补码 = 原码最高位为1，其余位取反再加一**

最高位不变，其余位取反：```1111 1111 1111 1111 1111 1111 1111 1111```

其余位加一：```111 1111 1111 1111 1111 1111 1111 1111 + 1``` = ```1000 0000 0000 0000 0000 0000 0000 0000```

首位的1溢出了，最终补码为```1000 0000 0000 0000 0000 0000 0000 0000```

也就是说，有且仅有这一个32位负整数，二进制下只有1个1。

因此，转为```unsigned int```的话，需要特判一下是否为```IINT_MIN```

### AC代码

#### C++

```cpp
class Solution {
public:
    bool isPowerOfTwo(unsigned int n) {
        if (n == INT_MIN)
            return false;
        int cnt1 = 0;
        while (n) {
            if (n & 1)
                cnt1++;
            n >>= 1;
        }
        return cnt1 == 1;
    }
};
```

如果觉得修改参数类型不好，也可：

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
		unsigned int un = n;
        if (un == INT_MIN)
            return false;
        int cnt1 = 0;
        while (un) {
            if (un & 1)
                cnt1++;
            un >>= 1;
        }
        return cnt1 == 1;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/09/08/LeetCode%200231.2%E7%9A%84%E5%B9%82/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126766929](https://letmefly.blog.csdn.net/article/details/126766929)
