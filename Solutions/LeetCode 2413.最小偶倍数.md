---
title: 2413.最小偶倍数
date: 2023-04-21 12:44:21
tags: [题解, LeetCode, 简单, 数学, 数论]
categories: [题解, LeetCode]
---

# 【LetMeFly】2413.最小偶倍数

力扣题目链接：[https://leetcode.cn/problems/smallest-even-multiple/](https://leetcode.cn/problems/smallest-even-multiple/)

给你一个正整数 <code>n</code> ，返回 <code>2</code><em> </em>和<em> </em><code>n</code> 的最小公倍数（正整数）。
<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 5
<strong>输出：</strong>10
<strong>解释：</strong>5 和 2 的最小公倍数是 10 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 6
<strong>输出：</strong>6
<strong>解释：</strong>6 和 2 的最小公倍数是 6 。注意数字会是它自身的倍数。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 150</code></li>
</ul>


    
## 方法一：数学

这道题是问一个数$n$和$2$的最小公倍数。

emm，如果$n$是偶数，那么它和$2$的最小公倍数就是$n$；反之，如果$n$是奇数，那么它和$2$的最小公倍数就是$n\times 2$

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int smallestEvenMultiple(int n) {
        return n % 2 ? n * 2 : n;
    }
};
```

#### Python

```python
class Solution:
    def smallestEvenMultiple(self, n: int) -> int:
        return n * 2 if n % 2 else n
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/04/21/LeetCode%202413.%E6%9C%80%E5%B0%8F%E5%81%B6%E5%80%8D%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130285901](https://letmefly.blog.csdn.net/article/details/130285901)
