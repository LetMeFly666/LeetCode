---
title: 1847.最近的房间
date: 2024-12-17 09:07:38
tags: [题解, LeetCode, 困难, 数组, 二分查找, 排序, 有序集合]
---

# 【LetMeFly】1847.最近的房间：有序集合

力扣题目链接：[https://leetcode.cn/problems/closest-room/](https://leetcode.cn/problems/closest-room/)

<p>一个酒店里有 <code>n</code> 个房间，这些房间用二维整数数组 <code>rooms</code> 表示，其中 <code>rooms[i] = [roomId<sub>i</sub>, size<sub>i</sub>]</code> 表示有一个房间号为 <code>roomId<sub>i</sub></code> 的房间且它的面积为 <code>size<sub>i</sub></code> 。每一个房间号 <code>roomId<sub>i</sub></code> 保证是 <strong>独一无二</strong> 的。</p>

<p>同时给你 <code>k</code> 个查询，用二维数组 <code>queries</code> 表示，其中 <code>queries[j] = [preferred<sub>j</sub>, minSize<sub>j</sub>]</code> 。第 <code>j</code> 个查询的答案是满足如下条件的房间 <code>id</code> ：</p>

<ul>
	<li>房间的面积 <b>至少</b> 为 <code>minSize<sub>j</sub></code> ，且</li>
	<li><code>abs(id - preferred<sub>j</sub>)</code> 的值 <strong>最小</strong> ，其中 <code>abs(x)</code> 是 <code>x</code> 的绝对值。</li>
</ul>

<p>如果差的绝对值有 <strong>相等</strong> 的，选择 <strong>最小</strong> 的 <code>id</code> 。如果 <strong>没有满足条件的房间</strong> ，答案为 <code>-1</code> 。</p>

<p>请你返回长度为 <code>k</code> 的数组 <code>answer</code> ，其中<em> </em><code>answer[j]</code> 为第 <code>j</code> 个查询的结果。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>rooms = [[2,2],[1,2],[3,2]], queries = [[3,1],[3,3],[5,2]]
<b>输出：</b>[3,-1,3]
<strong>解释：</strong>查询的答案如下：
查询 [3,1] ：房间 3 的面积为 2 ，大于等于 1 ，且号码是最接近 3 的，为 abs(3 - 3) = 0 ，所以答案为 3 。
查询 [3,3] ：没有房间的面积至少为 3 ，所以答案为 -1 。
查询 [5,2] ：房间 3 的面积为 2 ，大于等于 2 ，且号码是最接近 5 的，为 abs(3 - 5) = 2 ，所以答案为 3 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>rooms = [[1,4],[2,3],[3,5],[4,1],[5,2]], queries = [[2,3],[2,4],[2,5]]
<b>输出：</b>[2,1,3]
<strong>解释：</strong>查询的答案如下：
查询 [2,3] ：房间 2 的面积为 3 ，大于等于 3 ，且号码是最接近的，为 abs(2 - 2) = 0 ，所以答案为 2 。
查询 [2,4] ：房间 1 和 3 的面积都至少为 4 ，答案为 1 因为它房间编号更小。
查询 [2,5] ：房间 3 是唯一面积大于等于 5 的，所以答案为 3 。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == rooms.length</code></li>
	<li><code>1 <= n <= 10<sup>5</sup></code></li>
	<li><code>k == queries.length</code></li>
	<li><code>1 <= k <= 10<sup>4</sup></code></li>
	<li><code>1 <= roomId<sub>i</sub>, preferred<sub>j</sub> <= 10<sup>7</sup></code></li>
	<li><code>1 <= size<sub>i</sub>, minSize<sub>j</sub> <= 10<sup>7</sup></code></li>
</ul>


    
## 解题方法：有序集合

我们可以首先对所有的查询按照“size从大到小”的顺序排序，同时保留原本的顺序信息(得知道一个查询是原来的第几个查询)。

> 这样做有什么好处呢？排序后满足前一个查询的size的房间一定能满足后一个查询。

因此我们可以对房间依据size从大到小的顺序排序，使用一个指针指向所有已经满足size条件的room，并将所有满足size条件的roomId添加到有序集合roomIds中。

> 也就是说，对于一个查询，roomIds中的房间都可以住。问题就变成了如何在一个有序集合里查询与queryId最接近的值，直接使用二分查找即可。

+ 时间复杂度$O((n+k)\log n+k\log k)$。排序$O(n\log n+k\log k)$，单次添加到有序集合$O(\log n)$一共添加最多$n$次，单次查询$O(\log n)$一共查询$k$次。
+ 空间复杂度$O(n+ k)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        vector<int> queryIdx(queries.size());
        iota(queryIdx.begin(), queryIdx.end(), 0);
        sort(queryIdx.begin(), queryIdx.end(), [&](int i, int j) {
            return queries[i][1] > queries[j][1];
        });
        sort(rooms.begin(), rooms.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] > b[1];
        });
        set<int> canIds;
        vector<int> ans(queries.size());
        for (int locR = 0, locQ = 0; locQ < queryIdx.size(); locQ++) {
            int queryId = queries[queryIdx[locQ]][0], size = queries[queryIdx[locQ]][1];
            while (locR < rooms.size() && rooms[locR][1] >= size) {
                canIds.insert(rooms[locR++][0]);
            }
            if (canIds.empty()) {
                ans[queryIdx[locQ]] = -1;
                continue;
            }
            set<int>::iterator it = canIds.lower_bound(queryId);
            int idDiff = abs(queryId - *it);
            if (it != canIds.begin() && abs(queryId - *prev(it)) <= idDiff) {
                it--;
            }
            ans[queryIdx[locQ]] = *it;
        }
        return ans;
    }
};
```

#### Python

```python
from typing import List
from sortedcontainers import SortedList
from bisect import bisect_left

class Solution:
    def closestRoom(self, rooms: List[List[int]], queries: List[List[int]]) -> List[int]:
        queryIdx = [i for i in range(len(queries))]
        queryIdx.sort(key=lambda x: -queries[x][1])
        rooms.sort(key=lambda x: -x[1])
        canIds = SortedList()
        ans = [-1] * len(queries)
        locR = 0
        for locQI in range(len(queries)):
            queryId, querySize = queries[queryIdx[locQI]]
            while locR < len(rooms) and rooms[locR][1] >= querySize:
                canIds.add(rooms[locR][0])
                locR += 1
            if not canIds:
                continue
            it = bisect_left(canIds, queryId)
            # print(f'bisect_left({canIds, queryId}) = {it}')  # bisect_left((SortedList([1, 2, 3]), 5)) = 3
            if it == len(canIds) or (it and abs(canIds[it - 1] - queryId) <= abs(canIds[it] - queryId)):
                it -= 1
            ans[queryIdx[locQI]] = canIds[it]
        return ans
```

#### Java

```java
import java.util.TreeSet;
import java.util.Arrays;

class Solution {
    public int[] closestRoom(int[][] rooms, int[][] queries) {
        Integer[] queryIdx = new Integer[queries.length];  // int的话不支持sort的Comparator
        Arrays.setAll(queryIdx, i -> i);
        Arrays.sort(queryIdx, (i, j) -> queries[j][1] - queries[i][1]);
        Arrays.sort(rooms, (a, b) -> b[1] - a[1]);
        TreeSet<Integer> canIds = new TreeSet<>();
        int[] ans = new int[queries.length];
        int locR = 0;
        for (int locQI = 0; locQI < queryIdx.length; locQI++) {
            int queryId = queries[queryIdx[locQI]][0], querySize = queries[queryIdx[locQI]][1];
            while (locR < rooms.length && rooms[locR][1] >= querySize) {
                canIds.add(rooms[locR++][0]);
            }
            if (canIds.isEmpty()) {
                ans[queryIdx[locQI]] = -1;
                continue;
            }
            Integer floor = canIds.floor(queryId);
            Integer ceil = canIds.ceiling(queryId);
            if (floor == null) {
                ans[queryIdx[locQI]] = ceil;
            } else if (ceil == null) {
                ans[queryIdx[locQI]] = floor;
            } else {
                if (Math.abs(floor - queryId) <= Math.abs(ceil - queryId)) {
                    ans[queryIdx[locQI]] = floor;
                } else {
                    ans[queryIdx[locQI]] = ceil;
                }
            }
        }
        return ans;
    }
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/12/17/LeetCode%201847.%E6%9C%80%E8%BF%91%E7%9A%84%E6%88%BF%E9%97%B4/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/144524587](https://letmefly.blog.csdn.net/article/details/144524587)
