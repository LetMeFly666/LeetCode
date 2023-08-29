---
title: 1037.有效的回旋镖
date: 2022-07-14 21:56:29
tags: [题解, LeetCode, 简单, 几何, 数组, 数学, 共线, 斜率, 坐标]
---

# 【LetMeFly】1037.有效的回旋镖：斜率 - 一行解决

力扣题目链接：[https://leetcode.cn/problems/valid-boomerang/](https://leetcode.cn/problems/valid-boomerang/)

<p>给定一个数组<meta charset="UTF-8" />&nbsp;<code>points</code>&nbsp;，其中<meta charset="UTF-8" />&nbsp;<code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>&nbsp;表示 <strong>X-Y</strong> 平面上的一个点，<em>如果这些点构成一个&nbsp;</em><strong>回旋镖</strong>&nbsp;则返回&nbsp;<code>true</code>&nbsp;。</p>

<p><strong>回旋镖</strong>&nbsp;定义为一组三个点，这些点&nbsp;<strong>各不相同</strong>&nbsp;且&nbsp;<strong>不在一条直线上</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>points = [[1,1],[2,3],[3,2]]
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>points = [[1,1],[2,2],[3,3]]
<strong>输出：</strong>false</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>
<meta charset="UTF-8" />

<ul>
	<li><code>points.length == 3</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>0 &lt;= x<sub>i</sub>, y<sub>i</sub>&nbsp;&lt;= 100</code></li>
</ul>


    
## 方法一：斜率 - 一行解决

假设第一个点和第二个点的连线的斜率是$k_1$，第二个点和第三个点的连线的斜率是$k_2$，那么当$k_1\neq k_2$时，三点不共线，能构成“回旋镖”

斜率的求法：$k=\frac{\Delta y}{\Delta x}$

但是出现除法的话，一是会有精度问题，而是还要特判分母是否为0。

因此要判断$\frac{\Delta y1}{\Delta x1}$是否等于$\frac{\Delta y2}{\Delta x2}$，只需要判断$\Delta y1 \times \Delta x2$是否等于$\Delta y2 \times \Delta x1$即可。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

![result](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/962004024ef649b18454e35de5b80331.jpeg#pic_center)

### AC代码

#### C++

```cpp
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        return (points[0][0] - points[1][0]) * (points[1][1] - points[2][1]) != (points[1][0] - points[2][0]) * (points[0][1] - points[1][1]);
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/07/14/LeetCode%201037.%E6%9C%89%E6%95%88%E7%9A%84%E5%9B%9E%E6%97%8B%E9%95%96/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125793916](https://letmefly.blog.csdn.net/article/details/125793916)
