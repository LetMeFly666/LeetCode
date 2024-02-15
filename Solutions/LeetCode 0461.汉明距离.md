---
title: 461.汉明距离
date: 2022-10-25 11:03:19
tags: [题解, LeetCode, 简单, 位运算]
---

# 【LetMeFly】461.汉明距离

力扣题目链接：[https://leetcode.cn/problems/hamming-distance/](https://leetcode.cn/problems/hamming-distance/)

<p>两个整数之间的 <a href="https://baike.baidu.com/item/%E6%B1%89%E6%98%8E%E8%B7%9D%E7%A6%BB">汉明距离</a> 指的是这两个数字对应二进制位不同的位置的数目。</p>

<p>给你两个整数 <code>x</code> 和 <code>y</code>，计算并返回它们之间的汉明距离。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>x = 1, y = 4
<strong>输出：</strong>2
<strong>解释：</strong>
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
上面的箭头指出了对应二进制位不同的位置。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>x = 3, y = 1
<strong>输出：</strong>1
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 <= x, y <= 2<sup>31</sup> - 1</code></li>
</ul>


    
## 方法一：位运算

我们只需要按照题意，分别提取出$x$和$y$的每一位，看看它们是否相等。

如果不相等，答案数量+1

怎么“提取”出$x$在二进制下的某一位呢？

假设我们要提取$x$的二进制下从低到高的第$i + 1$位，那么我们可以构造一个用来进行与运算的数

```cpp
int mask = 1 << i;
```

这样$mask$在二进制下就是$1000...0$

我们用$x$与$mask$进行与运算，得到的就是$x$的这一位以及后面的数个$0$

+ 时间复杂度$O(C)$，其中$C=31$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        for (int i = 0; i < 31; i++) {
            int mask = 1 << i;
            ans += ((x & mask) != (y & mask));
        }
        return ans;
    }
};
```

## 方法二：还是位运算

方法二类似方法一，不同之处是“取出某一位”的方式

方法二中，我们将$x$右移$i$位，再与$1$进行与运算，就得到了$x$的第$i+1$位

```cpp
(x >> i) & 1;
```

+ 时间复杂度$O(C)$，其中$C=31$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        for (int i = 0; i < 31; i++) {
            ans += (((x >> i) & 1) != ((y >> i) & 1));
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/10/25/LeetCode%200461.%E6%B1%89%E6%98%8E%E8%B7%9D%E7%A6%BB/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127510681](https://letmefly.blog.csdn.net/article/details/127510681)
