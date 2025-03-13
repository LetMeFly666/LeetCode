---
title: 2520.统计能整除数字的位数
date: 2023-10-26 10:24:09
tags: [题解, LeetCode, 简单, 数学, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】2520.统计能整除数字的位数：模拟

力扣题目链接：[https://leetcode.cn/problems/count-the-digits-that-divide-a-number/](https://leetcode.cn/problems/count-the-digits-that-divide-a-number/)

<p>给你一个整数 <code>num</code> ，返回 <code>num</code> 中能整除 <code>num</code> 的数位的数目。</p>

<p>如果满足&nbsp;<code>nums % val == 0</code> ，则认为整数 <code>val</code> 可以整除 <code>nums</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>num = 7
<strong>输出：</strong>1
<strong>解释：</strong>7 被自己整除，因此答案是 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>num = 121
<strong>输出：</strong>2
<strong>解释：</strong>121 可以被 1 整除，但无法被 2 整除。由于 1 出现两次，所以返回 2 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>num = 1248
<strong>输出：</strong>4
<strong>解释：</strong>1248 可以被它每一位上的数字整除，因此答案是 4 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num &lt;= 10<sup>9</sup></code></li>
	<li><code>num</code> 的数位中不含 <code>0</code></li>
</ul>


    
## 方法一：模拟

我们不断取出$num$在十进制下的最低位，并判断这个最低位能否被$num$整除。直到取完每一位为止。

+ 时间复杂度$O(\log_{10} n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int countDigits(int num) {
        int n = num;
        int ans = 0;
        while (n) {
            ans += (num % (n % 10)) == 0;
            n /= 10;
        }
        return ans;
    }
};
```

#### Python

```python
class Solution:
    def countDigits(self, num: int) -> int:
        n = num
        ans = 0
        while n:
            ans += (num % (n % 10)) == 0
            n //= 10
        return ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/10/26/LeetCode%202520.%E7%BB%9F%E8%AE%A1%E8%83%BD%E6%95%B4%E9%99%A4%E6%95%B0%E5%AD%97%E7%9A%84%E4%BD%8D%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/134050300](https://letmefly.blog.csdn.net/article/details/134050300)
