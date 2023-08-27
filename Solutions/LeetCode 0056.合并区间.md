---
title: 56.合并区间
date: 2023-08-27 09:15:41
tags: [题解, LeetCode, 中等, 数组, 排序]
---

# 【LetMeFly】56.合并区间

力扣题目链接：[https://leetcode.cn/problems/merge-intervals/](https://leetcode.cn/problems/merge-intervals/)

<p>以数组 <code>intervals</code> 表示若干个区间的集合，其中单个区间为 <code>intervals[i] = [start<sub>i</sub>, end<sub>i</sub>]</code> 。请你合并所有重叠的区间，并返回&nbsp;<em>一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间</em>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>intervals = [[1,3],[2,6],[8,10],[15,18]]
<strong>输出：</strong>[[1,6],[8,10],[15,18]]
<strong>解释：</strong>区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入：</strong>intervals = [[1,4],[4,5]]
<strong>输出：</strong>[[1,5]]
<strong>解释：</strong>区间 [1,4] 和 [4,5] 可被视为重叠区间。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= intervals.length &lt;= 10<sup>4</sup></code></li>
	<li><code>intervals[i].length == 2</code></li>
	<li><code>0 &lt;= start<sub>i</sub> &lt;= end<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
</ul>


    
## 方法一：排序

直接对intervals数组进行一个sort，使用两个变量from和to分别指向当前区间的起点和终点。

遍历区间：
+ 如果当前区间不能和[from, to]合并，则将[from, to]放入答案中，并开始计新的区间
+ 否则，更新[from, to]的结尾to的覆盖范围

即可。

+ 时间复杂度$O(n\log n)$，其中$n = len(intervals)$
+ 空间复杂度$O(\log n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),  intervals.end());
        intervals.push_back({100000, 100000});  // 哨兵思想
        vector<vector<int>> ans;
        int from = intervals[0][0], to = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= to) {
                to = max(to, intervals[i][1]);
            }
            else {
                ans.push_back({from, to});
                from = intervals[i][0], to = intervals[i][1];
            }
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        intervals.append([100000, 100000])
        ans = []
        from_, to = intervals[0]
        for i in range(1, len(intervals)):
            if intervals[i][0] <= to:
                to = max(to, intervals[i][1])
            else:
                ans.append([from_, to])
                from_, to = intervals[i]
        return ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2023/08/27/LeetCode%200056.%E5%90%88%E5%B9%B6%E5%8C%BA%E9%97%B4/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/132520291](https://letmefly.blog.csdn.net/article/details/132520291)
