---
title: 210.课程表 II
date: 2022-08-22 10:54:15
tags: [题解, LeetCode, 中等, 深度优先搜索, 广度优先搜索, 图, 拓扑排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】210.课程表 II

力扣题目链接：[https://leetcode.cn/problems/course-schedule-ii/](https://leetcode.cn/problems/course-schedule-ii/)

<p>现在你总共有 <code>numCourses</code> 门课需要选，记为&nbsp;<code>0</code>&nbsp;到&nbsp;<code>numCourses - 1</code>。给你一个数组&nbsp;<code>prerequisites</code> ，其中 <code>prerequisites[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> ，表示在选修课程 <code>a<sub>i</sub></code> 前 <strong>必须</strong> 先选修&nbsp;<code>b<sub>i</sub></code> 。</p>

<ul>
	<li>例如，想要学习课程 <code>0</code> ，你需要先完成课程&nbsp;<code>1</code> ，我们用一个匹配来表示：<code>[0,1]</code> 。</li>
</ul>

<p>返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序，你只要返回 <strong>任意一种</strong> 就可以了。如果不可能完成所有课程，返回 <strong>一个空数组</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>numCourses = 2, prerequisites = [[1,0]]
<strong>输出：</strong>[0,1]
<strong>解释：</strong>总共有 2 门课程。要学习课程 1，你需要先完成课程 0。因此，正确的课程顺序为 <code>[0,1] 。</code>
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
<strong>输出：</strong>[0,2,1,3]
<strong>解释：</strong>总共有 4 门课程。要学习课程 3，你应该先完成课程 1 和课程 2。并且课程 1 和课程 2 都应该排在课程 0 之后。
因此，一个正确的课程顺序是&nbsp;<code>[0,1,2,3]</code> 。另一个正确的排序是&nbsp;<code>[0,2,1,3]</code> 。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>numCourses = 1, prerequisites = []
<strong>输出：</strong>[0]
</pre>

<p>&nbsp;</p>
<strong>提示：</strong>

<ul>
	<li><code>1 &lt;= numCourses &lt;= 2000</code></li>
	<li><code>0 &lt;= prerequisites.length &lt;= numCourses * (numCourses - 1)</code></li>
	<li><code>prerequisites[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; numCourses</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>所有<code>[a<sub>i</sub>, b<sub>i</sub>]</code> <strong>互不相同</strong></li>
</ul>


    
## 方法一：拓扑排序

这道题和[LeetCode 0207.课程表](https://blog.letmefly.xyz/2022/08/21/LeetCode%200207.%E8%AF%BE%E7%A8%8B%E8%A1%A8/) 非常类似，不同的是这道题需要返回选课的顺序。

我们直接把上一题的代码搬过来，稍加修改即可。

在拓扑排序过程中，如果某个节点的入度为$0$，那么就说明这门课的先修课已经全部“学完”了，下一门课就可以学习这一门，因此把这门课添加到答案中即可。

+ 时间复杂度$O(n + numCourses)$，其中$n$是先修课关系数
+ 空间复杂度$O(n + numCourses)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);
        vector<int> ans;
        // 建图
        for (int i = prerequisites.size() - 1; i >= 0; i--) {
            // v[1] -> v[0]
            indegree[prerequisites[i][0]]++;
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        // 拓扑排序
        int remainNode = numCourses;
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (!indegree[i]) {
                remainNode--;
                q.push(i);
                ans.push_back(i);
            }
        }
        while (q.size()) {
            int thisNode = q.front();
            q.pop();
            for (int& toNode : graph[thisNode]) {
                indegree[toNode]--;
                if (!indegree[toNode]) {
                    remainNode--;
                    q.push(toNode);
                    ans.push_back(toNode);
                }
            }
        }

        if (remainNode) {
            return {};
        }
        else {
            return ans;
        }
    }
};
```

#### Python

```python
# from collections import deque
# from typing import List

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = [[] for _ in range(numCourses)]
        indegree = [0] * numCourses
        for a, b in prerequisites:
            graph[b].append(a)
            indegree[a] += 1
        q = deque()
        for i in range(numCourses):
            if not indegree[i]:
                q.append(i)
        ans = []
        while q:
            thisCourse = q.popleft()
            ans.append(thisCourse)
            for to in graph[thisCourse]:
                indegree[to] -= 1
                if not indegree[to]:
                    q.append(to)
        return ans if len(ans) == numCourses else []
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/08/22/LeetCode%200210.%E8%AF%BE%E7%A8%8B%E8%A1%A8II/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126461788](https://letmefly.blog.csdn.net/article/details/126461788)
