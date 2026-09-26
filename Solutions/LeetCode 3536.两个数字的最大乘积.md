---
title: 3536.两个数字的最大乘积：O(1)空间维护max2
date: 2026-07-25 22:13:44
tags: [题解, LeetCode, 简单, 数学, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】3536.两个数字的最大乘积：O(1)空间维护max2

力扣题目链接：[https://leetcode.cn/problems/maximum-product-of-two-digits/](https://leetcode.cn/problems/maximum-product-of-two-digits/)

<p>给定一个正整数 <code>n</code>。</p>

<p>返回 <strong>任意两位数字&nbsp;</strong>相乘所得的&nbsp;<strong>最大&nbsp;</strong>乘积。</p>

<p><strong>注意：</strong>如果某个数字在 <code>n</code> 中出现多次，你可以多次使用该数字。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 31</span></p>

<p><strong>输出：</strong> <span class="example-io">3</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li><code>n</code> 的数字是 <code>[3, 1]</code>。</li>
	<li>任意两位数字相乘的结果为：<code>3 * 1 = 3</code>。</li>
	<li>最大乘积为 3。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 22</span></p>

<p><strong>输出：</strong> <span class="example-io">4</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li><code>n</code> 的数字是 <code>[2, 2]</code>。</li>
	<li>任意两位数字相乘的结果为：<code>2 * 2 = 4</code>。</li>
	<li>最大乘积为 4。</li>
</ul>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 124</span></p>

<p><strong>输出：</strong> <span class="example-io">8</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li><code>n</code> 的数字是 <code>[1, 2, 4]</code>。</li>
	<li>任意两位数字相乘的结果为：<code>1 * 2 = 2</code>, <code>1 * 4 = 4</code>, <code>2 * 4 = 8</code>。</li>
	<li>最大乘积为 8。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>10 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：求n每一位 + 维护最大两值

怎么求出$n$在十进制下的每一位？

> 当$n\neq 0$时候，取出$n\ \%\ 10$，并令$n=\lfloor\frac{n}{10}\rfloor$。

如何维护最大两个值？

> 初始时候最大值$mx2$和第二大值$mx1$都为$0$。
> 
> + 如果$n$的某一位$t$比最大值$mx2$还大，则令$mx1=mx2$并令$mx2=t$；
> + 否则如果$t$比次大值$mx1$大，则令$mx1=t$。

最终返回最大值和次大值之积。

+ 时间复杂度$O(\log n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-07-25 22:11:39
 */
class Solution {
public:
    int maxProduct(int n) {
        int mx1 = 0, mx2 = 0;
        while (n) {
            int t = n % 10;
            n /= 10;
            if (t > mx2) {
                mx1 = mx2;
                mx2 = t;
            } else if (t > mx1) {
                mx1 = t;
            }
        }
        return mx1 * mx2;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/163198871)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/07/25/LeetCode%203536.%E4%B8%A4%E4%B8%AA%E6%95%B0%E5%AD%97%E7%9A%84%E6%9C%80%E5%A4%A7%E4%B9%98%E7%A7%AF/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
