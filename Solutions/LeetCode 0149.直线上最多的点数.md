---
title: 149.直线上最多的点数
date: 2022-07-31 12:13:14
tags: [题解, LeetCode, 困难, 几何, 数组, 哈希表, 数学, 共线, 坐标]
---

# 【LetMeFly】149.直线上最多的点数

力扣题目链接：[https://leetcode.cn/problems/max-points-on-a-line/](https://leetcode.cn/problems/max-points-on-a-line/)

<p>给你一个数组 <code>points</code> ，其中 <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> 表示 <strong>X-Y</strong> 平面上的一个点。求最多有多少个点在同一条直线上。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<!-- <img alt="" src="https://assets.leetcode.com/uploads/2021/02/25/plane1.jpg" style="width: 300px; height: 294px;" /> -->
<img alt="" src="https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/476420f4dbf24b7e9c20087039369fe1.jpeg" style="width: 300px; height: 294px;" />
<pre>
<strong>输入：</strong>points = [[1,1],[2,2],[3,3]]
<strong>输出：</strong>3
</pre>

<p><strong>示例 2：</strong></p>
<!-- <img alt="" src="https://assets.leetcode.com/uploads/2021/02/25/plane2.jpg" style="width: 300px; height: 294px;" /> -->
<img alt="" src="https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/69c247626123430f976fa1e5a51cafc6.jpeg" style="width: 300px; height: 294px;" />
<pre>
<strong>输入：</strong>points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
<strong>输出：</strong>4
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= points.length <= 300</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>-10<sup>4</sup> <= x<sub>i</sub>, y<sub>i</sub> <= 10<sup>4</sup></code></li>
	<li><code>points</code> 中的所有点 <strong>互不相同</strong></li>
</ul>


    
## 方法一：看所有其他点与这个点的斜率

第一层遍历每一个点。

然后，第二层遍历再次遍历每一个点，求出两个点之间的斜率，并用哈希表计数。

因为都经过第一个点，所以斜率相同的点都在一条直线上。

取最大的斜率相同的点的个数，就是经过第一个点的直线中，经过点最多的直线所经过的点。

关于精度问题，C++中使用```long double```可以通过。

+ 时间复杂度$O(n^2)$，其中$n$是点的个数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
long double ONE = 1;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        
        for (int i = 0; i < n; i++) {
            unordered_map<long double, int> ma;
            int thisAns = 0;
            for (int j = 0 ; j < n; j++) {
                if (i == j)
                    continue;
                long double k = ONE * (points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                ma[k]++;
                thisAns = max(thisAns, ma[k]);
            }
            ans = max(ans, thisAns + 1);
        }

        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/07/31/LeetCode%200149.%E7%9B%B4%E7%BA%BF%E4%B8%8A%E6%9C%80%E5%A4%9A%E7%9A%84%E7%82%B9%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126084170](https://letmefly.blog.csdn.net/article/details/126084170)
