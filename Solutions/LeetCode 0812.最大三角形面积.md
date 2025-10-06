---
title: 812.最大三角形面积：三角形面积公式考察（附三种公式）
date: 2025-09-27 15:19:16
tags: [题解, LeetCode, 简单, 几何, 数组, 数学]
categories: [题解, LeetCode]
index_img: https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/04/1027.png
---

# 【LetMeFly】812.最大三角形面积：三角形面积公式考察（附三种公式）

力扣题目链接：[https://leetcode.cn/problems/largest-triangle-area/](https://leetcode.cn/problems/largest-triangle-area/)

<p>给你一个由 <strong>X-Y</strong> 平面上的点组成的数组 <code>points</code> ，其中 <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> 。从其中取任意三个不同的点组成三角形，返回能组成的最大三角形的面积。与真实值误差在 <code>10<sup>-5</sup></code> 内的答案将会视为正确答案<strong>。</strong></p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/04/1027.png" style="height: 369px; width: 450px;" />
<pre>
<strong>输入：</strong>points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
<strong>输出：</strong>2.00000
<strong>解释：</strong>输入中的 5 个点如上图所示，红色的三角形面积最大。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>points = [[1,0],[0,0],[0,1]]
<strong>输出：</strong>0.50000
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= points.length &lt;= 50</code></li>
	<li><code>-50 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 50</code></li>
	<li>给出的所有点 <strong>互不相同</strong></li>
</ul>


    
## 解题方法：暴力

三角形面积公式怎么算，有这些方法：

假设二维平面三角形三个顶点的坐标 $A(x_1, y_1), B(x_2, y_2), C(x_3, y_3)$，

1. 行列式公式（Shoelace公式）：$S = \frac{1}{2} | x_1(y_2 - y_3) + x_2(y_3 - y_1) + x_3(y_1 - y_2) |$

2. 向量叉积公式：设 $\vec{AB} = (x_2-x_1, y_2-y_1), \vec{AC} = (x_3-x_1, y_3-y_1)$，则  
   $S = \frac{1}{2} | \vec{AB} \times \vec{AC} | = \frac{1}{2} | (x_2-x_1)(y_3-y_1) - (x_3-x_1)(y_2-y_1) |$

3. 海伦公式（已知三边长 $a,b,c$）：$a = \sqrt{(x_2-x_3)^2 + (y_2-y_3)^2},\ b = \sqrt{(x_1-x_3)^2 + (y_1-y_3)^2},\ c = \sqrt{(x_1-x_2)^2 + (y_1-y_2)^2}$  
   $s = \frac{a+b+c}{2},\ S = \sqrt{s(s-a)(s-b)(s-c)}$


+ 时间复杂度$O(len(points)^3)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-09-27 12:53:08
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-27 15:10:05
 */
class Solution {
private:
    inline int calc(vector<vector<int>>& points, int i, int j, int k) {
        int x1 = points[i][0], y1 = points[i][1];
        int x2 = points[j][0], y2 = points[j][1];
        int x3 = points[k][0], y3 = points[k][1];
        return abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
    }
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int ans = 0;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                for (int k = j + 1; k < points.size(); k++) {
                    ans = max(ans, calc(points, i, j, k));
                }
            }
        }
        return double(ans) / 2;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-09-27 12:53:08
LastEditors: LetMeFly.xyz
LastEditTime: 2025-09-27 15:15:55
'''
from typing import List
from itertools import combinations

class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        ans = 0
        for p1, p2, p3 in combinations(points, 3):
            x1, y1 = p2[0] - p1[0], p2[1] - p1[1]
            x2, y2 = p3[0] - p1[0], p3[1] - p1[1]
            ans = max(ans, abs(x1 * y2 - y1 * x2))  # 记得abs
        return ans / 2
```

#### Python一行版

```python
'''
Author: LetMeFly
Date: 2025-09-27 12:53:08
LastEditors: LetMeFly.xyz
LastEditTime: 2025-09-27 15:17:57
'''
from typing import List
from itertools import combinations

class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        return max(abs((p2[0] - p1[0]) * (p3[1] - p1[1]) - (p2[1] - p1[1]) * (p3[0] - p1[0])) for p1, p2, p3 in combinations(points, 3)) / 2
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/152167745)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/09/27/LeetCode%200812.%E6%9C%80%E5%A4%A7%E4%B8%89%E8%A7%92%E5%BD%A2%E9%9D%A2%E7%A7%AF/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
