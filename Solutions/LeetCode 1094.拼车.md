---
title: 1094.拼车
date: 2023-12-02 14:22:27
tags: [题解, LeetCode, 中等, 数组, 前缀和, 排序, 模拟, 堆（优先队列）, 优先队列]
---

# 【LetMeFly】1094.拼车：优先队列

力扣题目链接：[https://leetcode.cn/problems/car-pooling/](https://leetcode.cn/problems/car-pooling/)

<p>车上最初有&nbsp;<code>capacity</code>&nbsp;个空座位。车&nbsp;<strong>只能&nbsp;</strong>向一个方向行驶（也就是说，<strong>不允许掉头或改变方向</strong>）</p>

<p>给定整数&nbsp;<code>capacity</code>&nbsp;和一个数组 <code>trips</code> , &nbsp;<code>trip[i] = [numPassengers<sub>i</sub>, from<sub>i</sub>, to<sub>i</sub>]</code>&nbsp;表示第 <code>i</code> 次旅行有&nbsp;<code>numPassengers<sub>i</sub></code>&nbsp;乘客，接他们和放他们的位置分别是&nbsp;<code>from<sub>i</sub></code>&nbsp;和&nbsp;<code>to<sub>i</sub></code>&nbsp;。这些位置是从汽车的初始位置向东的公里数。</p>

<p>当且仅当你可以在所有给定的行程中接送所有乘客时，返回&nbsp;<code>true</code>，否则请返回 <code>false</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>trips = [[2,1,5],[3,3,7]], capacity = 4
<strong>输出：</strong>false
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>trips = [[2,1,5],[3,3,7]], capacity = 5
<strong>输出：</strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= trips.length &lt;= 1000</code></li>
	<li><code>trips[i].length == 3</code></li>
	<li><code>1 &lt;= numPassengers<sub>i</sub>&nbsp;&lt;= 100</code></li>
	<li><code>0 &lt;= from<sub>i</sub>&nbsp;&lt; to<sub>i</sub>&nbsp;&lt;= 1000</code></li>
	<li><code>1 &lt;= capacity &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 方法一：优先队列

首先二话不说对trips按“上车地点”为依据从小到大排个序。

接着创建一个优先队列，用于存放“已上车的人”。优先队列的排序依据是“先下车的人优先”。

使用一个变量记录当前车上的人数，遍历trips数组：

> 让优先队列中，不晚于此位置的人下车；
>
> 让这批人上车。

期间若出现超载的情况则返回```false```，否则返回```true```。

+ 时间复杂度$O(n\log n)$，其中$n=len(trips)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int nowPeopleCnt = 0;
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> nowPeople(cmp);
        for (vector<int>& trip : trips) {
            int num = trip[0], from = trip[1], to = trip[2];
            while (nowPeople.size() && nowPeople.top().second <= from) {
                nowPeopleCnt -= nowPeople.top().first;
                nowPeople.pop();
            }
            nowPeopleCnt += num;
            if (nowPeopleCnt > capacity) {
                return false;
            }
            nowPeople.push({num, to});
        }
        return true;
    }
};
```

#### Python

```python
# from typing import List
# import heapq

class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        trips.sort(key=lambda x: x[1])
        nowPeopleCnt = 0
        nowPeople = []
        for num, from_, to in trips:
            while nowPeople and nowPeople[0][0] <= from_:
                nowPeopleCnt -= nowPeople[0][1]
                heapq.heappop(nowPeople)
            nowPeopleCnt += num
            if nowPeopleCnt > capacity:
                return False
            heapq.heappush(nowPeople, (to, num))
        return True
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2023/12/02/LeetCode%201094.%E6%8B%BC%E8%BD%A6/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/134751973](https://letmefly.blog.csdn.net/article/details/134751973)
