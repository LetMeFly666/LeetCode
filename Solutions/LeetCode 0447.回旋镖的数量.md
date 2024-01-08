---
title: 447.回旋镖的数量
date: 2024-01-08 19:17:35
tags: [题解, LeetCode, 中等, 数组, 哈希表, 哈希, map, 数学]
---

# 【LetMeFly】447.回旋镖的数量：哈希表

力扣题目链接：[https://leetcode.cn/problems/number-of-boomerangs/](https://leetcode.cn/problems/number-of-boomerangs/)

<p>给定平面上<em>&nbsp;</em><code>n</code><em> </em>对 <strong>互不相同</strong> 的点&nbsp;<code>points</code> ，其中 <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> 。<strong>回旋镖</strong> 是由点&nbsp;<code>(i, j, k)</code> 表示的元组 ，其中&nbsp;<code>i</code>&nbsp;和&nbsp;<code>j</code>&nbsp;之间的距离和&nbsp;<code>i</code>&nbsp;和&nbsp;<code>k</code>&nbsp;之间的欧式距离相等（<strong>需要考虑元组的顺序</strong>）。</p>

<p>返回平面上所有回旋镖的数量。</p>
&nbsp;

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>points = [[0,0],[1,0],[2,0]]
<strong>输出：</strong>2
<strong>解释：</strong>两个回旋镖为 <strong>[[1,0],[0,0],[2,0]]</strong> 和 <strong>[[1,0],[2,0],[0,0]]</strong>
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>points = [[1,1],[2,2],[3,3]]
<strong>输出：</strong>2
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>points = [[1,1]]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n ==&nbsp;points.length</code></li>
	<li><code>1 &lt;= n &lt;= 500</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>-10<sup>4</sup> &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
	<li>所有点都 <strong>互不相同</strong></li>
</ul>


    
## 方法一：哈希表

第一重循环枚举每个$j$点。对于points[j]，使用一个哈希表，记录所有的点到j点的距离的出现次数。然后遍历哈希表，假设某距离出现了cnt次，那么就将$cnt\times(cnt-1)$累加到答案中。

+ 时间复杂度$O(len(points)^2)$
+ 空间复杂度$O(len(points))$

### AC代码

#### C++

```cpp
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        for (vector<int>& p : points) {
            unordered_map<int, int> ma;
            for (vector<int>& q : points) {
                ma[(p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1])]++;
            }
            for (auto [_, cnt] : ma) {
                ans += cnt * (cnt - 1);
            }
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List
# from collections import defaultdict

class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        ans = 0
        for p in points:
            ma = defaultdict(int)
            for q in points:
                ma[(p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1])] += 1
            for _, cnt in ma.items():
                ans += cnt * (cnt - 1)
        return ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2024/01/08/LeetCode%200447.%E5%9B%9E%E6%97%8B%E9%95%96%E7%9A%84%E6%95%B0%E9%87%8F/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135464460](https://letmefly.blog.csdn.net/article/details/135464460)
