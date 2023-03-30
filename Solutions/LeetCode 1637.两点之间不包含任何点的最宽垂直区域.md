---
title: 1637.两点之间不包含任何点的最宽垂直面积
date: 2023-03-30 09:20:49
tags: [题解, LeetCode, 中等, 数组, 排序, Set]
---

# 【LetMeFly】1637.两点之间不包含任何点的最宽垂直面积

力扣题目链接：[https://leetcode.cn/problems/widest-vertical-area-between-two-points-containing-no-points/](https://leetcode.cn/problems/widest-vertical-area-between-two-points-containing-no-points/)

<p>给你 <code>n</code> 个二维平面上的点 <code>points</code> ，其中 <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> ，请你返回两点之间内部不包含任何点的 <strong>最宽垂直面积</strong> 的宽度。</p>

<p><strong>垂直面积</strong> 的定义是固定宽度，而 y 轴上无限延伸的一块区域（也就是高度为无穷大）。 <strong>最宽垂直面积</strong> 为宽度最大的一个垂直面积。</p>

<p>请注意，垂直区域 <strong>边上</strong> 的点 <strong>不在</strong> 区域内。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/10/31/points3.png" style="width: 276px; height: 371px;" />​
<pre>
<b>输入：</b>points = [[8,7],[9,9],[7,4],[9,7]]
<b>输出：</b>1
<b>解释：</b>红色区域和蓝色区域都是最优区域。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>points = [[3,1],[9,0],[1,0],[1,4],[5,3],[8,8]]
<b>输出：</b>3
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == points.length</code></li>
	<li><code>2 <= n <= 10<sup>5</sup></code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>0 <= x<sub>i</sub>, y<sub>i</sub> <= 10<sup>9</sup></code></li>
</ul>


    
## 方法一：排序 / Set

这道题只需要考虑横坐标。

将所有的横坐标排序后，间隔最远的横坐标就是答案。

（当然，也可以使用有序集合（底层是红黑树）来实现）

emm，总觉得这中文版题目描述不太完美，“最宽区域”，我选$[1000000000, +\infty)$不行么

+ 时间复杂度$O(n\log n)$
+ 空间复杂度$O(\log n)$或$O(diff(points[0]))$（不同的横坐标的个数，也可以理解为$O(n)$）

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> se;
        for (vector<int>& point : points) {
            se.insert(point[0]);
        }
        int ans = 0;
        int last = *se.begin();
        for (int t : se) {
            ans = max(ans, t - last);
            last = t;
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List
"""Python的set是无序的"""

class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        x = [p[0] for p in points]
        x.sort()
        return max(x[i] - x[i - 1] for i in range(1, len(x)))
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2023/03/30/LeetCode%201637.%E4%B8%A4%E7%82%B9%E4%B9%8B%E9%97%B4%E4%B8%8D%E5%8C%85%E5%90%AB%E4%BB%BB%E4%BD%95%E7%82%B9%E7%9A%84%E6%9C%80%E5%AE%BD%E5%9E%82%E7%9B%B4%E5%8C%BA%E5%9F%9F/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129851128](https://letmefly.blog.csdn.net/article/details/129851128)
