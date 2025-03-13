---
title: 2549.统计桌面上的不同数字
date: 2024-03-23 11:17:45
tags: [题解, LeetCode, 简单, 数组, 哈希表, 数学, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】2549.统计桌面上的不同数字：数学O(1) / 模拟O(n^3)

力扣题目链接：[https://leetcode.cn/problems/count-distinct-numbers-on-board/](https://leetcode.cn/problems/count-distinct-numbers-on-board/)

<p>给你一个正整数 <code>n</code> ，开始时，它放在桌面上。在 <code>10<sup>9</sup></code> 天内，每天都要执行下述步骤：</p>

<ul>
	<li>对于出现在桌面上的每个数字 <code>x</code> ，找出符合 <code>1 &lt;= i &lt;= n</code> 且满足 <code>x % i == 1</code> 的所有数字 <code>i</code> 。</li>
	<li>然后，将这些数字放在桌面上。</li>
</ul>

<p>返回在 <code>10<sup>9</sup></code> 天之后，出现在桌面上的 <strong>不同</strong> 整数的数目。</p>

<p><strong>注意：</strong></p>

<ul>
	<li>一旦数字放在桌面上，则会一直保留直到结束。</li>
	<li><code>%</code> 表示取余运算。例如，<code>14 % 3</code> 等于 <code>2</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 5
<strong>输出：</strong>4
<strong>解释：</strong>最开始，5 在桌面上。 
第二天，2 和 4 也出现在桌面上，因为 5 % 2 == 1 且 5 % 4 == 1 。 
再过一天 3 也出现在桌面上，因为 4 % 3 == 1 。 
在十亿天结束时，桌面上的不同数字有 2 、3 、4 、5 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 3 
<strong>输出：</strong>2
<strong>解释：</strong> 
因为 3 % 2 == 1 ，2 也出现在桌面上。 
在十亿天结束时，桌面上的不同数字只有两个：2 和 3 。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
</ul>


    
## 方法一：模拟

> 每次用$i$从$1$枚举到$n-1$：
>
> > 每次用$j$从$1$枚举到$n$：
> >
> > 如果$j\mod i == 1$并且$i$还没有在桌面上，就把$i$放到桌面上。
>
> 直到本次枚举没有新数字被放到桌面上。

+ 时间复杂度$O(n^3)$，最多可能枚举$n$轮
+ 空间复杂度$O(n)$

## 方法二：数学

对于$x\geq2$，一定有$x\mod (x-1)=1$。

如果操作足够都次，$n$、$n-1$、$n-2$、$\cdots$、$2$一定会全部出现在桌子上。

不难发现$n\leq 100$而枚举次数为$10^9$，每次枚举至少出现一个新数字，因此$10^9$足够$2$到$n$的所有数字出现在桌子上。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int distinctIntegers(int n) {
        return n == 1 ? 1 : n - 1;
    }
};
```

#### Python

```python
class Solution:
    def distinctIntegers(self, n: int) -> int:
        return 1 if n == 1 else n - 1
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/03/23/LeetCode%202549.%E7%BB%9F%E8%AE%A1%E6%A1%8C%E9%9D%A2%E4%B8%8A%E7%9A%84%E4%B8%8D%E5%90%8C%E6%95%B0%E5%AD%97/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136963667](https://letmefly.blog.csdn.net/article/details/136963667)
