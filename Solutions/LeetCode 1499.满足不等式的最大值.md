---
title: 1499.满足不等式的最大值：双端队列（一步步讲解）
date: 2023-07-21 08:28:23
tags: [题解, LeetCode, 困难, 队列, 数组, 滑动窗口, 单调队列, 堆（优先队列）, 双端队列]
---

# 【LetMeFly】1499.满足不等式的最大值：双端队列（一步步讲解）

力扣题目链接：[https://leetcode.cn/problems/max-value-of-equation/](https://leetcode.cn/problems/max-value-of-equation/)

<p>给你一个数组 <code>points</code> 和一个整数 <code>k</code> 。数组中每个元素都表示二维平面上的点的坐标，并按照横坐标 x 的值从小到大排序。也就是说 <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> ，并且在 <code>1 &lt;= i &lt; j &lt;= points.length</code> 的前提下， <code>x<sub>i</sub> &lt; x<sub>j</sub></code> 总成立。</p>

<p>请你找出<em> </em><code>y<sub>i</sub>&nbsp;+ y<sub>j</sub>&nbsp;+ |x<sub>i</sub>&nbsp;- x<sub>j</sub>|</code> 的 <strong>最大值</strong>，其中 <code>|x<sub>i</sub>&nbsp;- x<sub>j</sub>|&nbsp;&lt;= k</code> 且 <code>1 &lt;= i &lt; j &lt;= points.length</code>。</p>

<p>题目测试数据保证至少存在一对能够满足 <code>|x<sub>i</sub>&nbsp;- x<sub>j</sub>|&nbsp;&lt;= k</code> 的点。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>points = [[1,3],[2,0],[5,10],[6,-10]], k = 1
<strong>输出：</strong>4
<strong>解释：</strong>前两个点满足 |x<sub>i</sub>&nbsp;- x<sub>j</sub>| &lt;= 1 ，代入方程计算，则得到值 3 + 0 + |1 - 2| = 4 。第三个和第四个点也满足条件，得到值 10 + -10 + |5 - 6| = 1 。
没有其他满足条件的点，所以返回 4 和 1 中最大的那个。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>points = [[0,0],[3,0],[9,2]], k = 3
<strong>输出：</strong>3
<strong>解释：</strong>只有前两个点满足 |x<sub>i</sub>&nbsp;- x<sub>j</sub>| &lt;= 3 ，代入方程后得到值 0 + 0 + |0 - 3| = 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= points.length &lt;= 10^5</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>-10^8&nbsp;&lt;= points[i][0], points[i][1] &lt;= 10^8</code></li>
	<li><code>0 &lt;= k &lt;= 2 * 10^8</code></li>
	<li>对于所有的<code>1 &lt;= i &lt; j &lt;= points.length</code> ，<code>points[i][0] &lt; points[j][0]</code> 都成立。也就是说，<code>x<sub>i</sub></code> 是严格递增的。</li>
</ul>


    
## 方法一：双端队列

**先不考虑“必须|xi - xj| <= k”：**

要求的是$y_i + y_j + |x_i - x_j| = y_i + y_j + (x_j - x_i) = (y_i - x_i) + (x_j + y_j)$的最大值，

我们可以遍历所有点，将已经遍历过的点视为$(x_i, y_i)$，当前正被遍历到的点视为$(x_j, y_j)$。

使用一个[双端队列](https://blog.tisfy.eu.org/tags/%E5%8F%8C%E7%AB%AF%E9%98%9F%E5%88%97/)存放```递减```的$(y_i - x_i)$，那么对于当前的$(x_j, y_j)$，使用$x_j + y_j$加上最大的（队首的）$(y_i - x_i)$即为最优选择。

我们要做的，就是维护双端队列的递减特性：

```cpp
q = deque(int);
for (xj, yj in points) {
    ans = max(ans, (xj + yj) + q[0]);  // q[0]为最大的(yi - xi)
    while (q非空 && yj - xj >= q.back) {  // 当队尾不大于当前时弹出队尾，使得当前元素入队后队列仍递减
        q.pop_back();
    }
    q.push_back({yj - xj});
}
```

**接下来加上限制“必须|xi - xj| <= k”：**

原理不变，在入队时加上当前点的```横坐标```这一信息，遍历到点$(x_j, y_j)$时，当队首元素与当前元素横坐标之差大于$k$时，不断弹出队首元素 即可。

```cpp
q = deque(pair<int, int>);  // 队列中的每个点变成：[yi - xi, x]
for (xj, yj in points) {
	while (q非空 && xj - q[0][0] > k) {  // 加上这一行，满足横坐标之差不大于k
		q.pop_front();
	}
    ans = max(ans, (xj + yj) + q[0][0]);  // q[0]变为q[0][0]
    while (q非空 && yj - xj >= q.back[0]) {  // 这里back变成back[0]
        q.pop_back();
    }
    q.push_back({yj - xj, xj});  // 这里节点中多存入一个“xj”
}
```

+ 时间复杂度$O(len(points))$，每个节点最多入队一次出队一次。
+ 空间复杂度$O(len(points))$，空间复杂度取决于同时在队列中的最大元素数。

### AC代码

#### C++

```cpp
/*
yi + yj + |xi - xj| = (yi - xi) + (xj + yj)
队列中放从大到小的(yi - xi)
*/
typedef pair<int, int> pii;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int ans = INT_MIN;
        deque<pii> q;
        for (vector<int>& point : points) {
            int x = point[0], y = point[1];
            while (q.size() && x - q.front().second > k) {
                q.pop_front();
            }
            if (q.size()) {
                ans = max(ans, x + y + q.front().first);
            }
            while (q.size() && y - x >= q.back().first) {
                q.pop_back();
            }
            q.push_back({y - x, x});
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List
# from collections import deque

class Solution:
    def findMaxValueOfEquation(self, points: List[List[int]], k: int) -> int:
        ans = -1e9
        q = deque()
        for x, y in points:
            while q and x - q[0][1] > k:
                q.popleft()
            if q:
                ans = max(ans, x + y + q[0][0])
            while q and q[-1][0] <= y - x:
                q.pop()
            q.append([y - x, x])
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/07/21/LeetCode%201499.%E6%BB%A1%E8%B6%B3%E4%B8%8D%E7%AD%89%E5%BC%8F%E7%9A%84%E6%9C%80%E5%A4%A7%E5%80%BC/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131844105](https://letmefly.blog.csdn.net/article/details/131844105)
