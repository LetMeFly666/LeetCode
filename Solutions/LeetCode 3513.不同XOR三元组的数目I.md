---
title: 3513.不同 XOR 三元组的数目 I： 1 << bit_width（数学）
date: 2026-07-23 16:02:15
tags: [题解, LeetCode, 中等, 位运算, 数组, 数学, 构造, 异或]
categories: [题解, LeetCode]
---

# 【LetMeFly】3513.不同 XOR 三元组的数目 I： 1 << bit_width（数学）

力扣题目链接：[https://leetcode.cn/problems/number-of-unique-xor-triplets-i/](https://leetcode.cn/problems/number-of-unique-xor-triplets-i/)

<p>给你一个长度为 <code>n</code> 的整数数组 <code>nums</code>，其中 <code>nums</code> 是范围 <code>[1, n]</code> 内所有数的&nbsp;<strong>排列&nbsp;</strong>。</p>

<p><strong>XOR 三元组</strong> 定义为三个元素的异或值 <code>nums[i] XOR nums[j] XOR nums[k]</code>，其中 <code>i &lt;= j &lt;= k</code>。</p>

<p>返回所有可能三元组 <code>(i, j, k)</code> 中&nbsp;<strong>不同&nbsp;</strong>的 XOR 值的数量。</p>

<p><strong>排列</strong> 是一个集合中所有元素的重新排列。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [1,2]</span></p>

<p><strong>输出：</strong> <span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p>所有可能的 XOR 三元组值为：</p>

<ul>
	<li><code>(0, 0, 0) → 1 XOR 1 XOR 1 = 1</code></li>
	<li><code>(0, 0, 1) → 1 XOR 1 XOR 2 = 2</code></li>
	<li><code>(0, 1, 1) → 1 XOR 2 XOR 2 = 1</code></li>
	<li><code>(1, 1, 1) → 2 XOR 2 XOR 2 = 2</code></li>
</ul>

<p>不同的 XOR 值为 <code>{1, 2}</code>，因此输出为 2。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [3,1,2]</span></p>

<p><strong>输出：</strong> <span class="example-io">4</span></p>

<p><strong>解释：</strong></p>

<p>可能的 XOR 三元组值包括：</p>

<ul>
	<li><code>(0, 0, 0) → 3 XOR 3 XOR 3 = 3</code></li>
	<li><code>(0, 0, 1) → 3 XOR 3 XOR 1 = 1</code></li>
	<li><code>(0, 0, 2) → 3 XOR 3 XOR 2 = 2</code></li>
	<li><code>(0, 1, 2) → 3 XOR 1 XOR 2 = 0</code></li>
</ul>

<p>不同的 XOR 值为 <code>{0, 1, 2, 3}</code>，因此输出为 4。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= n</code></li>
	<li><code>nums</code> 是从 <code>1</code> 到 <code>n</code> 的整数的一个排列。</li>
</ul>


    
## 解题方法：数学

> 背景：$n\oplus n=0$，$0\oplus n=n$，$a\oplus b=b\oplus a$。

由于需要从数组中选择三个下标$i$、$j$、$k$，所以先考虑$n\geq3$时的情况：

+ $n\geq3$时：$0$可以得到、$[1, n]$可以得到、二进制下最高位和$n$相同的任意整数都能得到：

    + $0$：$1\oplus2\oplus3=0$
    + $[1,n]$：$1\oplus1\oplus [1,n]\rightarrow [1,n]$
    + 最高位和$n$相同的其他数$t$：假设$n$二进制下有$l$位，则$2^l\leq n$，

        $2^l$最高位为$1$其余位全是$0$，剩下两个数的异或结果可以是$t$除最高位以外的任何值，可以这样构造：

        $t$中为$0$的位两个数这一位相同，$t$中不为$0$的位两个数这一位不同。（由于$n\geq 3$所以剩下至少有两位，不会出现只剩下一位还需要两个数不等的情况。只剩下一位还需要两个数不等的话，就必须要一个$0$一个$1$了，而所有数都需要$\geq 1$）

    由于$[0,n]$包含除去最高位剩下的$l-1$位中所有的$2^{l-1}$种情况，所以$n\geq3$时有从$0$到$2^l-1$这共计$2^l$种异或结果，其中$l$是$n$二进制下的位数。

+ 如果$n==2$，那么数组中只有$1$和$2$，三个下标至少有两个相同（相同数字异或结果为$0$），和另一个下标的异或结果只能是$1$或$2$，共有$2$种结果。
+ 如果$n==1$，数组中只有$1$，三个$1$的异或结果是$1$，共有$1$种结果。

所以我们看数组中共有几个元素（记为$n$），如果$n\lt3$则返回$n$，否则返回$2^{bit\_width(n)}$。

### 时空复杂度分析

使用库函数调用CPU计算32位或64位无符号整数的二进制长度的时空复杂度可以做到$O(1)$:

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++ —— 库函数算二进制长度

```cpp
/*
 * @LastEditTime: 2026-07-23 15:00:59
 */
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unsigned n = nums.size();
        if (n < 3) {
            return n;
        }
        
        return 1 << bit_width(n);
    }
};
```

#### C++ —— 手算二进制长度

```cpp
/*
 * @LastEditTime: 2026-07-23 14:55:02
 */
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return n;
        }
        
        int cnt = 0;
        while (n) {
            n >>= 1;
            cnt++;
        }
        return 1 << cnt;
    }
};
```

#### C++ —— 库函数算二进制长度（2行版）

```cpp
/*
 * @LastEditTime: 2026-07-23 15:59:42
 */
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unsigned n = nums.size();
        return n < 3 ? n : 1 << bit_width(n);
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/163143087)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/07/23/LeetCode%203513.%E4%B8%8D%E5%90%8CXOR%E4%B8%89%E5%85%83%E7%BB%84%E7%9A%84%E6%95%B0%E7%9B%AEI/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
