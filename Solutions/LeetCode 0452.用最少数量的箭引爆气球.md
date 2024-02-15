---
title: 452.用最少数量的箭引爆气球
date: 2022-10-21 21:23:54
tags: [题解, LeetCode, 中等, 贪心, 数组, 排序]
---

# 【LetMeFly】452.用最少数量的箭引爆气球

力扣题目链接：[https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/](https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/)

<p>有一些球形气球贴在一堵用 XY 平面表示的墙面上。墙面上的气球记录在整数数组&nbsp;<code>points</code>&nbsp;，其中<code>points[i] = [x<sub>start</sub>, x<sub>end</sub>]</code>&nbsp;表示水平直径在&nbsp;<code>x<sub>start</sub></code>&nbsp;和&nbsp;<code>x<sub>end</sub></code>之间的气球。你不知道气球的确切 y 坐标。</p>

<p>一支弓箭可以沿着 x 轴从不同点 <strong>完全垂直</strong> 地射出。在坐标 <code>x</code> 处射出一支箭，若有一个气球的直径的开始和结束坐标为 <code>x</code><sub><code>start</code>，</sub><code>x</code><sub><code>end</code>，</sub> 且满足 &nbsp;<code>x<sub>start</sub>&nbsp;≤ x ≤ x</code><sub><code>end</code>，</sub>则该气球会被 <strong>引爆</strong>&nbsp;<sub>。</sub>可以射出的弓箭的数量 <strong>没有限制</strong> 。 弓箭一旦被射出之后，可以无限地前进。</p>

<p>给你一个数组 <code>points</code> ，<em>返回引爆所有气球所必须射出的 <strong>最小</strong> 弓箭数&nbsp;</em>。</p>
&nbsp;

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>points = [[10,16],[2,8],[1,6],[7,12]]
<strong>输出：</strong>2
<strong>解释：</strong>气球可以用2支箭来爆破:
-在x = 6处射出箭，击破气球[2,8]和[1,6]。
-在x = 11处发射箭，击破气球[10,16]和[7,12]。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>points = [[1,2],[3,4],[5,6],[7,8]]
<strong>输出：</strong>4
<strong>解释：</strong>每个气球需要射出一支箭，总共需要4支箭。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>points = [[1,2],[2,3],[3,4],[4,5]]
<strong>输出：</strong>2
解释：气球可以用2支箭来爆破:
- 在x = 2处发射箭，击破气球[1,2]和[2,3]。
- 在x = 4处射出箭，击破气球[3,4]和[4,5]。</pre>

<p>&nbsp;</p>

<p><meta charset="UTF-8" /></p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= points.length &lt;= 10<sup>5</sup></code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>-2<sup>31</sup>&nbsp;&lt;= x<sub>start</sub>&nbsp;&lt; x<sub>end</sub>&nbsp;&lt;= 2<sup>31</sup>&nbsp;- 1</code></li>
</ul>


    
## 方法一：排序 + 贪心

以“起始位置最小最优先，结束位置最小次优先”排序

接着遍历所有气球，记录射穿这个（这些）气球的话，箭的最右位置能有多右

当下一个气球的起始位置不超过“最右位置”时，就顺带把下一个气球也射穿

因此需要更新“最右位置”

注意每射一箭，答案数量加一

+ 时间复杂度$O(n\log n)$，其中$n$是气球个数
+ 空间复杂度$O(\log n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [&](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });
        int ans = 0;
        for (int i = 0; i < points.size(); i++) {
            int rightMost = points[i][1];
            while (i + 1 < points.size() && points[i + 1][0] <= rightMost) {
                rightMost = min(rightMost, points[++i][1]);
            }
            ans++;
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/10/21/LeetCode%200452.%E7%94%A8%E6%9C%80%E5%B0%91%E6%95%B0%E9%87%8F%E7%9A%84%E7%AE%AD%E5%BC%95%E7%88%86%E6%B0%94%E7%90%83/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127454292](https://letmefly.blog.csdn.net/article/details/127454292)
