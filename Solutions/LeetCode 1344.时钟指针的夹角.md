---
title: 1344.时钟指针的夹角：分别计算时针分针与0的夹角(模拟)
date: 2026-06-18 10:09:34
tags: [题解, LeetCode, 中等, 数学]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.cn/aliyun-lc-upload/uploads/2020/02/08/sample_1_1673.png
---

# 【LetMeFly】1344.时钟指针的夹角：分别计算时针分针与0的夹角(模拟)

力扣题目链接：[https://leetcode.cn/problems/angle-between-hands-of-a-clock/](https://leetcode.cn/problems/angle-between-hands-of-a-clock/)

<p>给你两个数&nbsp;<code>hour</code>&nbsp;和&nbsp;<code>minutes</code>&nbsp;。请你返回在时钟上，由给定时间的时针和分针组成的较小角的角度（60 单位制）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.cn/aliyun-lc-upload/uploads/2020/02/08/sample_1_1673.png" style="height: 225px; width: 230px;"></p>

<pre><strong>输入：</strong>hour = 12, minutes = 30
<strong>输出：</strong>165
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.cn/aliyun-lc-upload/uploads/2020/02/08/sample_2_1673.png" style="height: 225px; width: 230px;"></p>

<pre><strong>输入：</strong>hour = 3, minutes = 30
<strong>输出；</strong>75
</pre>

<p><strong>示例 3：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.cn/aliyun-lc-upload/uploads/2020/02/08/sample_3_1673.png" style="height: 231px; width: 230px;"></strong></p>

<pre><strong>输入：</strong>hour = 3, minutes = 15
<strong>输出：</strong>7.5
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>hour = 4, minutes = 50
<strong>输出：</strong>155
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>hour = 12, minutes = 0
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= hour &lt;= 12</code></li>
	<li><code>0 &lt;= minutes &lt;= 59</code></li>
	<li>与标准答案误差在&nbsp;<code>10^-5</code>&nbsp;以内的结果都被视为正确结果。</li>
</ul>


    
## 解题方法：分别计算时针分针与0的夹角

**时针与0的夹角怎么算？**

按一圈12个刻度，每个刻度30°，时针走了$hour+\frac{minutes}{60}$个刻度。

（特别的，我们可以把12点等价为0点）

**分针与0的夹角怎么算？**

按一圈60个刻度，每个刻度6°，分针走了$minutes$个刻度。

**时针分针最小夹角怎么算**

$\min (夹角, 360-夹角)$，其中$夹角=|分针角度-时针角度|$。

**时空复杂度分析**

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-06-18 10:08:12
 */
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = (hour % 12 + (double)minutes / 60) * 30;
        double m = minutes * 6;
        double diff = abs(h - m);
        return min(diff, 360 - diff);
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/162089766)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/06/18/LeetCode%201344.%E6%97%B6%E9%92%9F%E6%8C%87%E9%92%88%E7%9A%84%E5%A4%B9%E8%A7%92/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
