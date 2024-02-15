---
title: 1779.找到最近的有相同 X 或 Y 坐标的点
date: 2022-12-01 14:06:42
tags: [题解, LeetCode, 简单, 数组, 最值, 遍历, 曼哈顿距离]
---

# 【LetMeFly】1779.找到最近的有相同 X 或 Y 坐标的点

力扣题目链接：[https://leetcode.cn/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/](https://leetcode.cn/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/)

<p>给你两个整数&nbsp;<code>x</code> 和&nbsp;<code>y</code>&nbsp;，表示你在一个笛卡尔坐标系下的&nbsp;<code>(x, y)</code>&nbsp;处。同时，在同一个坐标系下给你一个数组&nbsp;<code>points</code>&nbsp;，其中&nbsp;<code>points[i] = [a<sub>i</sub>, b<sub>i</sub>]</code>&nbsp;表示在&nbsp;<code>(a<sub>i</sub>, b<sub>i</sub>)</code>&nbsp;处有一个点。当一个点与你所在的位置有相同的 <code>x</code> 坐标或者相同的 <code>y</code> 坐标时，我们称这个点是 <b>有效的</b>&nbsp;。</p>

<p>请返回距离你当前位置&nbsp;<strong>曼哈顿距离</strong>&nbsp;最近的&nbsp;<strong>有效</strong>&nbsp;点的下标（下标从 <strong>0</strong> 开始）。如果有多个最近的有效点，请返回下标&nbsp;<strong>最小</strong>&nbsp;的一个。如果没有有效点，请返回&nbsp;<code>-1</code>&nbsp;。</p>

<p>两个点 <code>(x<sub>1</sub>, y<sub>1</sub>)</code>&nbsp;和 <code>(x<sub>2</sub>, y<sub>2</sub>)</code>&nbsp;之间的 <strong>曼哈顿距离</strong>&nbsp;为&nbsp;<code>abs(x<sub>1</sub> - x<sub>2</sub>) + abs(y<sub>1</sub> - y<sub>2</sub>)</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>x = 3, y = 4, points = [[1,2],[3,1],[2,4],[2,3],[4,4]]
<b>输出：</b>2
<b>解释：</b>所有点中，[3,1]，[2,4] 和 [4,4] 是有效点。有效点中，[2,4] 和 [4,4] 距离你当前位置的曼哈顿距离最小，都为 1 。[2,4] 的下标最小，所以返回 2 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>x = 3, y = 4, points = [[3,4]]
<b>输出：</b>0
<b>提示：</b>答案可以与你当前所在位置坐标相同。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>x = 3, y = 4, points = [[2,3]]
<b>输出：</b>-1
<b>解释：</b>没有 有效点。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= points.length &lt;= 10<sup>4</sup></code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>1 &lt;= x, y, a<sub>i</sub>, b<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
</ul>


    
## 方法一：遍历

我们使用一个变量```m```来记录“有效”点中的最小曼哈顿距离，初始值是“无穷大”$10^5$

我们再使用一个变量```ans```来记录当前的答案。

变量数组，如果某个“有效”点的曼哈顿距离**小于**```m```，那么就更新```m```和```ans```，最终返回```ans```即可

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int m = 1e5, ans = -1;
        for (int i = 0; i < points.size(); i++) {
            if (points[i][0] == x || points[i][1] == y) {
                int d = abs(points[i][0] - x) + abs(points[i][1] - y);
                if (d < m) {
                    m = d, ans = i;
                }
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/12/01/LeetCode%201779.%E6%89%BE%E5%88%B0%E6%9C%80%E8%BF%91%E7%9A%84%E6%9C%89%E7%9B%B8%E5%90%8CX%E6%88%96Y%E5%9D%90%E6%A0%87%E7%9A%84%E7%82%B9/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128131353](https://letmefly.blog.csdn.net/article/details/128131353)
