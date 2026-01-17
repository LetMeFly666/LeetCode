---
title: 3047.求交集区域内的最大正方形面积：2层循环暴力枚举
date: 2026-01-17 20:05:07
tags: [题解, LeetCode, 中等, 几何, 数组, 数学]
categories: [题解, LeetCode]
---

# 【LetMeFly】3047.求交集区域内的最大正方形面积：2层循环暴力枚举

力扣题目链接：[https://leetcode.cn/problems/find-the-largest-area-of-square-inside-two-rectangles/](https://leetcode.cn/problems/find-the-largest-area-of-square-inside-two-rectangles/)

<p>在二维平面上存在 <code>n</code> 个矩形。给你两个下标从 <strong>0</strong> 开始的二维整数数组 <code>bottomLeft</code> 和 <code>topRight</code>，两个数组的大小都是 <code>n x 2</code> ，其中 <code>bottomLeft[i]</code> 和 <code>topRight[i]</code> 分别代表第 <code>i</code> 个矩形的<strong> 左下角 </strong>和 <strong>右上角 </strong>坐标。</p>

<p>我们定义 <strong>向右 </strong>的方向为 x 轴正半轴（<strong>x 坐标增加</strong>），<strong>向左 </strong>的方向为 x 轴负半轴（<strong>x 坐标减少</strong>）。同样地，定义 <strong>向上 </strong>的方向为 y 轴正半轴（<strong>y 坐标增加</strong>）<strong>，向下 </strong>的方向为 y 轴负半轴（<strong>y 坐标减少</strong>）。</p>

<p>你可以选择一个区域，该区域由两个矩形的 <strong>交集</strong>&nbsp;形成。你需要找出能够放入该区域 <strong>内 </strong>的<strong> 最大 </strong>正方形面积，并选择最优解。</p>

<p>返回能够放入交集区域的正方形的 <strong>最大 </strong>可能面积，如果矩形之间不存在任何交集区域，则返回 <code>0</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2024/01/05/example12.png" style="width: 443px; height: 364px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem;" />
<pre>
<strong>输入：</strong>bottomLeft = [[1,1],[2,2],[3,1]], topRight = [[3,3],[4,4],[6,6]]
<strong>输出：</strong>1
<strong>解释：</strong>边长为 1 的正方形可以放入矩形 0 和矩形 1 的交集区域，或矩形 1 和矩形 2 的交集区域。因此最大面积是边长 * 边长，即 1 * 1 = 1。
可以证明，边长更大的正方形无法放入任何交集区域。
</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2024/01/04/rectanglesexample2.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 445px; height: 365px;" />
<pre>
<strong>输入：</strong>bottomLeft = [[1,1],[2,2],[1,2]], topRight = [[3,3],[4,4],[3,4]]
<strong>输出：</strong>1
<strong>解释：</strong>边长为 1 的正方形可以放入矩形 0 和矩形 1，矩形 1 和矩形 2，或所有三个矩形的交集区域。因此最大面积是边长 * 边长，即 1 * 1 = 1。
可以证明，边长更大的正方形无法放入任何交集区域。
请注意，区域可以由多于两个矩形的交集构成。
</pre>

<p><strong class="example">示例 3：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2024/01/04/rectanglesexample3.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 444px; height: 364px;" />
<pre>
<strong>输入：</strong>bottomLeft = [[1,1],[3,3],[3,1]], topRight = [[2,2],[4,4],[4,2]]
<strong>输出：</strong>0
<strong>解释：</strong>不存在相交的矩形，因此，返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == bottomLeft.length == topRight.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>3</sup></code></li>
	<li><code>bottomLeft[i].length == topRight[i].length == 2</code></li>
	<li><code>1 &lt;= bottomLeft[i][0], bottomLeft[i][1] &lt;= 10<sup>7</sup></code></li>
	<li><code>1 &lt;= topRight[i][0], topRight[i][1] &lt;= 10<sup>7</sup></code></li>
	<li><code>bottomLeft[i][0] &lt; topRight[i][0]</code></li>
	<li><code>bottomLeft[i][1] &lt; topRight[i][1]</code></li>
</ul>


    
## 解题方法：暴力模拟

一维坐标上，一个线段坐标从$a$到$b$，一个线段坐标从$c$到$d$，它们的相交部分有多长？

> $\min(b, d) - \max(a, c)$，再与$0$取一个最大值就好了（右端点最小值减去左端点最大值）

依次判断两个正方形在横纵坐标轴上的相交长度，最小值的平方即为最大正方形的面积。

+ 时间复杂度$O(n^2)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-01-17 20:02:05
 */
typedef long long ll;

class Solution {
private:
    // a->b VS c->d
    ll getDiff(int a, int b, int c, int d) {
        return max(0, min(b, d) - max(a, c));
    }
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        ll ans = 0;
        for (int i = 0; i < bottomLeft.size(); i++) {
            for (int j = i + 1; j < bottomLeft.size(); j++) {
                ll dx = getDiff(bottomLeft[i][0], topRight[i][0], bottomLeft[j][0], topRight[j][0]);
                ll dy = getDiff(bottomLeft[i][1], topRight[i][1], bottomLeft[j][1], topRight[j][1]);
                ans = max(ans, min(dx, dy) * min(dx, dy));
            }
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/157067926)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/01/17/LeetCode%203047.%E6%B1%82%E4%BA%A4%E9%9B%86%E5%8C%BA%E5%9F%9F%E5%86%85%E7%9A%84%E6%9C%80%E5%A4%A7%E6%AD%A3%E6%96%B9%E5%BD%A2%E9%9D%A2%E7%A7%AF/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
