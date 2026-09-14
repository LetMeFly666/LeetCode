---
title: 836.矩形重叠：xy两方向分别看
date: 2026-09-14 10:53:43
tags: [题解, LeetCode, 简单, 几何, 数学]
categories: [题解, LeetCode]
---

# 【LetMeFly】836.矩形重叠：xy两方向分别看

力扣题目链接：[https://leetcode.cn/problems/rectangle-overlap/](https://leetcode.cn/problems/rectangle-overlap/)

<p>矩形以列表 <code>[x1, y1, x2, y2]</code> 的形式表示，其中 <code>(x1, y1)</code> 为左下角的坐标，<code>(x2, y2)</code> 是右上角的坐标。矩形的上下边平行于 x 轴，左右边平行于 y 轴。</p>

<p>如果相交的面积为 <strong>正</strong> ，则称两矩形重叠。需要明确的是，只在角或边接触的两个矩形不构成重叠。</p>

<p>给出两个矩形 <code>rec1</code> 和 <code>rec2</code> 。如果它们重叠，返回 <code>true</code>；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>rec1 = [0,0,2,2], rec2 = [1,1,3,3]
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>rec1 = [0,0,1,1], rec2 = [1,0,2,1]
<strong>输出：</strong>false
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>rec1 = [0,0,1,1], rec2 = [2,2,3,3]
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>rect1.length == 4</code></li>
	<li><code>rect2.length == 4</code></li>
	<li><code>-10<sup>9</sup> &lt;= rec1[i], rec2[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>rec1</code> 和 <code>rec2</code> 表示一个面积不为零的有效矩形</li>
</ul>


    
## 解题方法：线段相交

一维坐标系中一条线段从`la`到`ra`，另一条线段从`lb`到`rb`。假设`la <= ra`，那么什么情况下两条线段相交呢？答案是`lb < ra`。

二维空间中，如果两个正方形在x轴方向上和y轴方向上线段都相交，则两正方形有重叠。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-09-14 10:52:55
 */
class Solution {
private:
    bool ok(int la, int ra, int lb, int rb) {
        if (la > lb) {
            swap(la, lb);
            swap(ra, rb);
        }
        return lb < ra;
    }
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return ok(rec1[0], rec1[2], rec2[0], rec2[2]) && ok(rec1[1], rec1[3], rec2[1], rec2[3]);
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/165307839)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/09/14/LeetCode%200836.%E7%9F%A9%E5%BD%A2%E9%87%8D%E5%8F%A0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
archive