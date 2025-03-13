---
title: 3133.数组最后一个元素的最小值
date: 2024-08-22 23:24:43
tags: [题解, LeetCode, 中等, 位运算, 二进制]
categories: [题解, LeetCode]
---

# 【LetMeFly】3133.数组最后一个元素的最小值：位运算+双指针

力扣题目链接：[https://leetcode.cn/problems/minimum-array-end/](https://leetcode.cn/problems/minimum-array-end/)

<p>给你两个整数 <code>n</code> 和 <code>x</code> 。你需要构造一个长度为 <code>n</code> 的 <strong>正整数 </strong>数组 <code>nums</code> ，对于所有 <code>0 &lt;= i &lt; n - 1</code> ，满足 <code>nums[i + 1]</code><strong> 大于 </strong><code>nums[i]</code> ，并且数组 <code>nums</code> 中所有元素的按位 <code>AND</code> 运算结果为 <code>x</code> 。</p>

<p>返回 <code>nums[n - 1]</code> 可能的<strong> 最小 </strong>值。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">n = 3, x = 4</span></p>

<p><strong>输出：</strong><span class="example-io">6</span></p>

<p><strong>解释：</strong></p>

<p>数组 <code>nums</code> 可以是 <code>[4,5,6]</code> ，最后一个元素为 <code>6</code> 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">n = 2, x = 7</span></p>

<p><strong>输出：</strong><span class="example-io">15</span></p>

<p><strong>解释：</strong></p>

<p>数组 <code>nums</code> 可以是 <code>[7,15]</code> ，最后一个元素为 <code>15</code> 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n, x &lt;= 10<sup>8</sup></code></li>
</ul>


    
## 解题方法：位运算+双指针

### 解题思路

所有num与运算的结果为x，说明x二进制下为1的位置在所有num中也全部为1。

那其他位置呢？x二进制下为0的位置呢？当然是可1可0。

因为想要nums数组中最大的那个数尽可能小，所以在填充x非零位置的时候，用从0到$n-1$的二进制填充就好了。这样得到的nums数组即为最优。

**总之：将$n-1$的二进制插入到$x$中为0的位置即可。**

> 假如$x=5(101)$，那么x中为0的位有：第2位、第4位、第5位、第6位、...。
> 
> 假设$n=3$，那么$0$到$n-1$的2进制为$00$、$01$、$10$。
> 
> 将这些数填充到x中为0的位置，即可得到nums数组：**0**1**0**1、**0**1**1**1、**1**1**0**1（加粗的位置是x中为0的位置，填入了0到2这3个数）。
> 
> 因此$nums$中最大的数为：将$n-1$的二进制填入$x$二进制下为$0$的位置。

### 具体做法

由于$1\leq n\leq 10^8 \le 2^{27}$，所以只需要考虑$n-1$的低$27$位即可。

使用两个指针，ix指向x的每一位，in指向n的每一位。

主循环令in从0到26（指向n的每一位），每次ix找到一个x为0的位（当ix指向的那一位为1时，ix增加1移动到下一位），将这一位赋值为in所指的位的值。

+ 取出x的第ix位：```(x >> ix) & 1```
+ 取出n的第in位：```(n >> in) & 1```
+ 构造第in位为n的第in位，其余位为0的数：```(n >> in) & 1) << ix```
+ 将x的第ix位赋值为n的第in位：``` x |= (((n >> in) & 1) << ix)```

### 时空复杂度分析

+ 时间复杂度$O(C)$，其中$C=\log(\max\{n, x\})=27$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
将x每个0的位置设置为n-1的二进制
*/
typedef long long ll;

class Solution {
public:
    ll minEnd(ll n, ll x) {
        n--;
        for (int in = 0, ix = 0; in < 27; in++, ix++) {
            while ((x >> ix) & 1) {  // 找到下一个为0的位置
                ix++;
            }
            x |= (((n >> in) & 1) << ix);
        }
        return x;
    }
};
```

#### Go

```go
package main

func minEnd(n int, x int) int64 {
    n64, ans := (int64)(n - 1), (int64)(x)
    for in, ix := 0, 0; in < 27; in, ix = in + 1, ix + 1 {
        for ((ans >> ix) & 1) != 0 {
            ix++
        }
        ans |= (((n64 >> in) & 1) << ix)
    }
    return ans
}
```

#### Java

```java
class Solution {
    public long minEnd(long n, long x) {
        n--;
        for (int in = 0, ix = 0; in < 27; in++, ix++) {
            while (((x >> ix) & 1) != 0) {
                ix++;
            }
            x |= (((n >> in) & 1) << ix);
        }
        return x;
    }
}
```

#### Python

```python
class Solution:
    def minEnd(self, n: int, x: int) -> int:
        n -= 1
        ix = 0
        for in_ in range(27):
            while (x >> ix) & 1:
                ix += 1
            x |= (((n >> in_) & 1) << ix)
            ix += 1
        return x
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/08/22/LeetCode%203133.%E6%95%B0%E7%BB%84%E6%9C%80%E5%90%8E%E4%B8%80%E4%B8%AA%E5%85%83%E7%B4%A0%E7%9A%84%E6%9C%80%E5%B0%8F%E5%80%BC/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/141440484](https://letmefly.blog.csdn.net/article/details/141440484)
