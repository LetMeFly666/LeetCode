---
title: 630.课程表 III
date: 2023-09-11 14:26:28
tags: [题解, LeetCode, 困难, 贪心, 数组, 堆（优先队列）, 优先队列]
---

# 【LetMeFly】630.课程表 III：贪心 + 优先队列

力扣题目链接：[https://leetcode.cn/problems/course-schedule-iii/](https://leetcode.cn/problems/course-schedule-iii/)

<p>这里有 <code>n</code> 门不同的在线课程，按从 <code>1</code> 到 <code>n</code>&nbsp;编号。给你一个数组 <code>courses</code> ，其中 <code>courses[i] = [duration<sub>i</sub>, lastDay<sub>i</sub>]</code> 表示第 <code>i</code> 门课将会 <strong>持续</strong> 上 <code>duration<sub>i</sub></code> 天课，并且必须在不晚于 <code>lastDay<sub>i</sub></code> 的时候完成。</p>

<p>你的学期从第 <code>1</code> 天开始。且不能同时修读两门及两门以上的课程。</p>

<p>返回你最多可以修读的课程数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>courses = [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
<strong>输出：</strong>3
<strong>解释：</strong>
这里一共有 4 门课程，但是你最多可以修 3 门：
首先，修第 1 门课，耗费 100 天，在第 100 天完成，在第 101 天开始下门课。
第二，修第 3 门课，耗费 1000 天，在第 1100 天完成，在第 1101 天开始下门课程。
第三，修第 2 门课，耗时 200 天，在第 1300 天完成。
第 4 门课现在不能修，因为将会在第 3300 天完成它，这已经超出了关闭日期。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>courses = [[1,2]]
<strong>输出：</strong>1
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>courses = [[3,2],[4,3]]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= courses.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= duration<sub>i</sub>, lastDay<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
</ul>


    
## 方法一：贪心 + 优先队列

**贪心是因为：两门课相比，能完成截止时间早的就完成截止时间早的**

就像期末考试优先复习先考的一样。

但是如果截止时间早的课特别长呢（复习这门课的时间够学其他课两门了）？那么就「反悔」吧！

先按照截止时间从小到大排序，遍历courses。如果上完了duration=10的课导致无法按时完成duration=4的课，那么就“撤回”时长为10的课转上时长为4的课（没有少上课，但完成时间提前了，多空出来了6天）。

怎么实现呢？**用优先队列（大根堆）来记录所有已选择的课的时长**即可。

也可以参考[LeetCode@灵茶山艾府](https://leetcode.cn/problems/course-schedule-iii/solutions/2436667/tan-xin-huan-neng-fan-hui-pythonjavacgoj-lcwp/)的题解

+ 时间复杂度$O(n\times \log n)$，其中$n = len(courses)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        priority_queue<int> pq;
        int totalTime = 0;
        for (vector<int>& c : courses) {
            if (c[1] - c[0] >= totalTime) {
                totalTime += c[0];
                pq.push(c[0]);
            }
            else if (pq.size() && pq.top() > c[0]) {
                totalTime = totalTime + c[0] - pq.top();
                pq.pop();
                pq.push(c[0]);
            }
        }
        return pq.size();
    }
};
```

#### Python

```python
from typing import List
import heapq

class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        courses.sort(key=lambda a : a[1])
        pq = []
        totalTime = 0
        for duration, lastday in courses:
            if lastday - duration >= totalTime:
                totalTime += duration
                heapq.heappush(pq, -duration)
            elif pq and -pq[0] > duration:
                totalTime = totalTime + duration -(-pq[0])
                heapq.heapreplace(pq, -duration)
        return len(pq)
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2023/09/11/LeetCode%200630.%E8%AF%BE%E7%A8%8B%E8%A1%A8III/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/132806660](https://letmefly.blog.csdn.net/article/details/132806660)
