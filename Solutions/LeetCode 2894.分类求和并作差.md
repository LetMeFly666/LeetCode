---
title: 2894.分类求和并作差：数学O(1)一行解决
date: 2025-05-27 22:01:09
tags: [题解, LeetCode, 简单, 数学]
categories: [题解, LeetCode]
---

# 【LetMeFly】2894.分类求和并作差：数学O(1)一行解决

力扣题目链接：[https://leetcode.cn/problems/divisible-and-non-divisible-sums-difference/](https://leetcode.cn/problems/divisible-and-non-divisible-sums-difference/)

<p>给你两个正整数 <code>n</code> 和 <code>m</code> 。</p>

<p>现定义两个整数 <code>num1</code> 和 <code>num2</code> ，如下所示：</p>

<ul>
	<li><code>num1</code>：范围 <code>[1, n]</code> 内所有 <strong>无法被 </strong><code>m</code><strong> 整除</strong> 的整数之和。</li>
	<li><code>num2</code>：范围 <code>[1, n]</code> 内所有 <strong>能够被 </strong><code>m</code><strong> 整除</strong> 的整数之和。</li>
</ul>

<p>返回整数 <code>num1 - num2</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 10, m = 3
<strong>输出：</strong>19
<strong>解释：</strong>在这个示例中：
- 范围 [1, 10] 内无法被 3 整除的整数为 [1,2,4,5,7,8,10] ，num1 = 这些整数之和 = 37 。
- 范围 [1, 10] 内能够被 3 整除的整数为 [3,6,9] ，num2 = 这些整数之和 = 18 。
返回 37 - 18 = 19 作为答案。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 5, m = 6
<strong>输出：</strong>15
<strong>解释：</strong>在这个示例中：
- 范围 [1, 5] 内无法被 6 整除的整数为 [1,2,3,4,5] ，num1 = 这些整数之和 =  15 。
- 范围 [1, 5] 内能够被 6 整除的整数为 [] ，num2 = 这些整数之和 = 0 。
返回 15 - 0 = 15 作为答案。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 5, m = 1
<strong>输出：</strong>-15
<strong>解释：</strong>在这个示例中：
- 范围 [1, 5] 内无法被 1 整除的整数为 [] ，num1 = 这些整数之和 = 0 。 
- 范围 [1, 5] 内能够被 1 整除的整数为 [1,2,3,4,5] ，num2 = 这些整数之和 = 15 。
返回 0 - 15 = -15 作为答案。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n, m &lt;= 1000</code></li>
</ul>


    
## 解题方法：数学

这就需要拿出我们小学二年级就学过的**等差数列求和公式** $\lfloor\frac{(首项+尾项)\times 项数}{2}\rfloor$

另外有$num1-num2=(num1+num2)-num2$，而$num1+num2$就是整个数列$1$到$n$的和，$num2$就是首项为$m$尾项为$\lfloor\frac{n}m\rfloor\times m$项数为$\lfloor\frac{n}m\rfloor$的等差数列。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-05-27 21:42:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-27 21:53:29
 */
class Solution {
public:
    int differenceOfSums(int n, int m) {
        return (1 + n) * n / 2 - (m + n / m * m) * (n / m);
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-05-27 21:42:21
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-27 21:54:46
'''
class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        return (1 + n) * n // 2 - (m + n // m * m) * (n // m)
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-05-27 21:42:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-27 21:57:48
 */
class Solution {
    public int differenceOfSums(int n, int m) {
        return (1 + n) * n / 2 - (m + n / m * m) * (n / m);
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-05-27 21:42:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-27 21:58:33
 */
package main

func differenceOfSums(n int, m int) int {
    return (1 + n) * n / 2 - (m + n / m * m) * (n / m)
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/148266123)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/05/27/LeetCode%202894.%E5%88%86%E7%B1%BB%E6%B1%82%E5%92%8C%E5%B9%B6%E4%BD%9C%E5%B7%AE/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
