---
title: 1401.圆和矩形是否有重叠：找最近点（三种可能）
date: 2026-09-19 08:50:32
tags: [题解, LeetCode, 中等, 几何, 数学]
categories: [题解, LeetCode]
index_img: https://files.letmefly.xyz/d/n/leetcode/1401-sample_4_1728.png
---

# 【LetMeFly】1401.圆和矩形是否有重叠：找最近点（三种可能）

力扣题目链接：[https://leetcode.cn/problems/circle-and-rectangle-overlapping/](https://leetcode.cn/problems/circle-and-rectangle-overlapping/)

<p>给你一个以 <code>(radius, xCenter, yCenter)</code> 表示的圆和一个与坐标轴平行的矩形 <code>(x1, y1, x2, y2)</code> ，其中 <code>(x1, y1)</code> 是矩形左下角的坐标，而 <code>(x2, y2)</code> 是右上角的坐标。</p>

<p>如果圆和矩形有重叠的部分，请你返回 <code>true</code> ，否则返回 <code>false</code>&nbsp;。</p>

<p>换句话说，请你检测是否 <strong>存在</strong> 点 <code>(x<sub>i</sub>, y<sub>i</sub>)</code> ，它既在圆上也在矩形上（两者都包括点落在边界上的情况）。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1 ：</strong></p>
<img alt="" src="https://files.letmefly.xyz/d/n/leetcode/1401-sample_4_1728.png" style="width: 258px; height: 167px;" />
<pre>
<strong>输入：</strong>radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
<strong>输出：</strong>true
<strong>解释：</strong>圆和矩形存在公共点 (1,0) 。
</pre>

<p><strong class="example">示例 2 ：</strong></p>

<pre>
<strong>输入：</strong>radius = 1, xCenter = 1, yCenter = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1
<strong>输出：</strong>false
</pre>

<p><strong class="example">示例 3 ：</strong></p>
<img alt="" src="https://files.letmefly.xyz/d/n/leetcode/1401-sample_2_1728.png" style="width: 150px; height: 135px;" />
<pre>
<strong>输入：</strong>radius = 1, xCenter = 0, yCenter = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1
<strong>输出：</strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= radius &lt;= 2000</code></li>
	<li><code>-10<sup>4</sup> &lt;= xCenter, yCenter &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= x1 &lt; x2 &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= y1 &lt; y2 &lt;= 10<sup>4</sup></code></li>
</ul>


    
## 解题方法：找最近点

矩形是横平竖直的（不是歪的），所以我们可以分别寻找矩形在$x$方向上和在$y$方向上距离圆心最近的最近点。

x方向上，圆心在$xCenter$，矩形在$x$方向上的范围（投影）是线段$[x1, x2]$，所以离圆心最近的点$x$坐标有三种可能：

1. 线段在圆心右边（$x1 > xCenter$），最近点是$x1$；
2. 线段在圆心左边（$x2 < xCenter$），最近点是$x2$；
3. 线段覆盖圆心（$x1 \le xCenter \le x2$），最近点是$xCenter$。

y方向上同理。

知道了矩形距离圆心的最近坐标$(x, y)$后，我们只需要判断这个点是否在圆内，即该点到圆心的距离的平方$(x - xCenter)^2 + (y - yCenter)^2$是否$\leq$圆半径的平方$radius^2$即可。

## 时空复杂度

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

## 归纳

这三种情况也可以通过一个最大值和最小值的判断得到：

+ $x = \max(x1, \min(xCenter, x2))$
+ $y = \max(y1, \min(yCenter, y2))$

## AC代码

### C++

```cpp
/*
 * @LastEditTime: 2026-09-19 08:27:16
 */
class Solution {
private:
    inline int getClosest(int center, int x1, int x2) {
        if (x1 > center) {
            return x1;
        } else if (x2 < center) {
            return x2;
        } else {
            return center;
        }
    }
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x = getClosest(xCenter, x1, x2);
        int y = getClosest(yCenter, y1, y2);
        return (x - xCenter) * (x - xCenter) + (y - yCenter) * (y - yCenter) <= radius * radius;
    }
};
```

### Python

```python
'''
LastEditTime: 2026-09-19 08:43:25
'''
class Solution:
    def checkOverlap(self, radius: int, xCenter: int, yCenter: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        x = max(x1, min(xCenter, x2))
        y = max(y1, min(yCenter, y2))
        return (x - xCenter) ** 2 + (y - yCenter) ** 2 <= radius ** 2
```

### Java

```java
/*
 * @LastEditTime: 2026-09-19 08:39:53
 */
class Solution {
    private int getClosest(int c, int a, int b) {
        if (a > c) {
            return a;
        } else if (b < c) {
            return b;
        } else {
            return c;
        }
    }

    private int p(int a) {
        return a * a;
    }

    public boolean checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x = getClosest(xCenter, x1, x2);
        int y = getClosest(yCenter, y1, y2);
        return p(x - xCenter) + p(y - yCenter) <= p(radius);
    }
}
```

### Go

```go
/*
 * @LastEditTime: 2026-09-19 08:38:52
 */
package main

func getClosest(center, x1, x2 int) int {
    if x1 > center {
        return x1
    } else if x2 < center {
        return x2
    } else {
        return center
    }
}

func getPow(x int) int {
    return x * x
}

func checkOverlap(radius int, xCenter int, yCenter int, x1 int, y1 int, x2 int, y2 int) bool {
    x := getClosest(xCenter, x1, x2)
    y := getClosest(yCenter, y1, y2)
    return getPow(x - xCenter) + getPow(y - yCenter) <= getPow(radius)
}
```

### Rust

```rust
/*
 * @LastEditTime: 2026-09-19 08:46:21
 */
impl Solution {
    fn get_closest(c: i32, a: i32, b: i32) -> i32 {
        if a > c {
            a
        } else if b < c {
            b
        } else {
            c
        }
    }

    fn p(a: i32) -> i32 {
        a * a
    }

    pub fn check_overlap(radius: i32, x_center: i32, y_center: i32, x1: i32, y1: i32, x2: i32, y2: i32) -> bool {
        let x = Self::get_closest(x_center, x1, x2);
        let y = Self::get_closest(y_center, y1, y2);
        Self::p(x - x_center) + Self::p(y - y_center) <= Self::p(radius)
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/165969901)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/09/19/LeetCode%201401.%E5%9C%86%E5%92%8C%E7%9F%A9%E5%BD%A2%E6%98%AF%E5%90%A6%E6%9C%89%E9%87%8D%E5%8F%A0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
