---
title: 2485.找出中枢整数
date: 2023-06-26 09:43:37
tags: [题解, LeetCode, 简单, 数学, 前缀和]
---

# 【LetMeFly】2485.找出中枢整数

力扣题目链接：[https://leetcode.cn/problems/find-the-pivot-integer/](https://leetcode.cn/problems/find-the-pivot-integer/)

<p>给你一个正整数 <code>n</code> ，找出满足下述条件的<strong> 中枢整数</strong> <code>x</code> ：</p>

<ul>
	<li><code>1</code> 和 <code>x</code> 之间的所有元素之和等于 <code>x</code> 和 <code>n</code> 之间所有元素之和。</li>
</ul>

<p>返回中枢整数<em> </em><code>x</code> 。如果不存在中枢整数，则返回 <code>-1</code> 。题目保证对于给定的输入，至多存在一个中枢整数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 8
<strong>输出：</strong>6
<strong>解释：</strong>6 是中枢整数，因为 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>1
<strong>解释：</strong>1 是中枢整数，因为 1 = 1 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 4
<strong>输出：</strong>-1
<strong>解释：</strong>可以证明不存在满足题目要求的整数。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>


    
## 方法一：数学

如果“1 和 x 之间的所有元素之和等于 x 和 n 之间所有元素之和”，

那么有：

$$1 + 2 + 3 + ... + x = x + (x + 1) + ... + n$$

于是有：

$$\frac{x * (x + 1)}{2} = \frac{(n - x + 1) * (x + n)}{2}$$

解得：

$$x = \sqrt{\frac{n^2 + n}{2}}$$

因为$n^2 + n=n(n+1)$一定是偶数，所以其一定能整除$2$。

我们只需要判断一下$\frac{n^2 + n}{2}$是否是平方数就好了

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
1 + 2 + 3 + ... + x = x + (x + 1) + ... + n

x * (x + 1) / 2 = (n - x + 1) * (x + n) / 2

x * (x + 1) = (n - x + 1) * (x + n)

x^2 + x = nx - x^2 + x + n^2 - nx + n

2x^2 = n^2 + n

x = sqrt((n^2 + n) / 2)

n^2 + n = n(n + 1)一定是偶数，能整除2

就看n^2 + n是不是平方数了
*/

class Solution {
public:
    int pivotInteger(int n) {
        int ans = sqrt((n * n + n) / 2);
        return ans * ans == (n * n + n) / 2 ? ans : -1;
    }
};
```

#### Python

```python
# from math import sqrt

class Solution:
    def pivotInteger(self, n: int) -> int:
        ans = int(sqrt((n * n + n) / 2))
        return ans if ans * ans == (n * n + n) / 2 else -1
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/06/26/LeetCode%202485.%E6%89%BE%E5%87%BA%E4%B8%AD%E6%9E%A2%E6%95%B4%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131391141](https://letmefly.blog.csdn.net/article/details/131391141)
