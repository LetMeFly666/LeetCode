---
title: 263.丑数
date: 2022-09-13 08:37:19
tags: [题解, LeetCode, 简单, 数学]
---

# 【LetMeFly】263.丑数

力扣题目链接：[https://leetcode.cn/problems/ugly-number/](https://leetcode.cn/problems/ugly-number/)

<p><strong>丑数 </strong>就是只包含质因数&nbsp;<code>2</code>、<code>3</code> 和 <code>5</code>&nbsp;的正整数。</p>

<p>给你一个整数 <code>n</code> ，请你判断 <code>n</code> 是否为 <strong>丑数</strong> 。如果是，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 6
<strong>输出：</strong>true
<strong>解释：</strong>6 = 2 × 3</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>true
<strong>解释：</strong>1 没有质因数，因此它的全部质因数是 {2, 3, 5} 的空集。习惯上将其视作第一个丑数。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 14
<strong>输出：</strong>false
<strong>解释：</strong>14 不是丑数，因为它包含了另外一个质因数&nbsp;<code>7 </code>。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-2<sup>31</sup> &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


    
## 方法一：模拟

如果原数小于等于0，那么它一定不是“丑数”。

在它不为“一”时，判断它是否能被“2”、“3”或“5”整除，

能除则除一次，若都不能，则不是“丑数”。

若最终它变成了“1”，则是“丑数”。

+ 时间复杂度$O(\log n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0)
            return false;
        while (n != 1) {
            if (n % 2 == 0)
                n /= 2;
            else if (n % 3 == 0)
                n /= 3;
            else if (n % 5 == 0)
                n /= 5;
            else
                return false;
        }
        return true;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/09/13/LeetCode%200263.%E4%B8%91%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126826353](https://letmefly.blog.csdn.net/article/details/126826353)
