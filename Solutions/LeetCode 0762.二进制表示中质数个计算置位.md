---
title: 762.二进制表示中质数个计算置位：位运算（mask O(1)判断）
date: 2026-02-21 12:30:01
tags: [题解, LeetCode, 简单, 位运算, 数学, 质数]
categories: [题解, LeetCode]
---

# 【LetMeFly】762.二进制表示中质数个计算置位：位运算（mask O(1)判断）

力扣题目链接：[https://leetcode.cn/problems/prime-number-of-set-bits-in-binary-representation/](https://leetcode.cn/problems/prime-number-of-set-bits-in-binary-representation/)

<p>给你两个整数&nbsp;<code>left</code>&nbsp;和&nbsp;<code>right</code> ，在闭区间 <code>[left, right]</code>&nbsp;范围内，统计并返回 <strong>计算置位位数为质数</strong> 的整数个数。</p>

<p><strong>计算置位位数</strong> 就是二进制表示中 <code>1</code> 的个数。</p>

<ul>
	<li>例如， <code>21</code>&nbsp;的二进制表示&nbsp;<code>10101</code>&nbsp;有 <code>3</code> 个计算置位。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>left = 6, right = 10
<strong>输出：</strong>4
<strong>解释：</strong>
6 -&gt; 110 (2 个计算置位，2 是质数)
7 -&gt; 111 (3 个计算置位，3 是质数)
9 -&gt; 1001 (2 个计算置位，2 是质数)
10-&gt; 1010 (2 个计算置位，2 是质数)
共计 4 个计算置位为质数的数字。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>left = 10, right = 15
<strong>输出：</strong>5
<strong>解释：</strong>
10 -&gt; 1010 (2 个计算置位, 2 是质数)
11 -&gt; 1011 (3 个计算置位, 3 是质数)
12 -&gt; 1100 (2 个计算置位, 2 是质数)
13 -&gt; 1101 (3 个计算置位, 3 是质数)
14 -&gt; 1110 (3 个计算置位, 3 是质数)
15 -&gt; 1111 (4 个计算置位, 4 不是质数)
共计 5 个计算置位为质数的数字。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= left &lt;= right &lt;= 10<sup>6</sup></code></li>
	<li><code>0 &lt;= right - left &lt;= 10<sup>4</sup></code></li>
</ul>


    
## 解题方法：预处理

写个脚本，计算$10^6$范围内二进制下最多有多少个1：$1^{20}=1048576$

再算出来其中都有哪些是质数：$[2, 3, 5, 7, 11, 13, 17, 19]$

再使用一个整数二进制下的每一位代表一个数是否是质数。

```python
'''
LastEditTime: 2026-02-21 12:22:44
'''
max_length = 0
while 1 << max_length < 1000000:
    max_length += 1
print(f'max_length: {max_length}, 1 << {max_length} = {1 << max_length}')

primes = []
for i in range(2, max_length + 1):
    isnot = False
    for j in range(2, i):
        if i % j == 0:
            isnot = True
            break
    if not isnot:
        primes.append(i)
print(f'primes: {primes}')

mask = 0
for p in primes:
    mask |= 1 << p
print(f'mask: {mask}')

"""
max_length: 20, 1 << 20 = 1048576
primes: [2, 3, 5, 7, 11, 13, 17, 19]
mask: 665772
"""
```

+ 时间复杂度$O(right - left)$
+ 空间复杂度$O(N\log N)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-02-21 12:28:09
 */
class Solution {
private:
    constexpr static int mask = 665772;
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i++) {
            if (mask & (1 << __builtin_popcount(i))) {
                // printf("i = %d, cnt1 = %d\n", i, __builtin_popcount(i));
                ans++;
            }
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/158262877)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/02/21/LeetCode%200762.%E4%BA%8C%E8%BF%9B%E5%88%B6%E8%A1%A8%E7%A4%BA%E4%B8%AD%E8%B4%A8%E6%95%B0%E4%B8%AA%E8%AE%A1%E7%AE%97%E7%BD%AE%E4%BD%8D/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
