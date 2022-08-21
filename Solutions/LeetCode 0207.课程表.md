---
title: 207.课程表
date: 2022-08-21 10:49:40
tags: [题解, LeetCode, 中等, 深度优先搜索, 广度优先搜索, 图, 拓扑排序]
---

# 【LetMeFly】207.课程表

力扣题目链接：[https://leetcode.cn/problems/course-schedule/](https://leetcode.cn/problems/course-schedule/)

<p>你这个学期必须选修 <code>numCourses</code> 门课程，记为 <code>0</code> 到 <code>numCourses - 1</code> 。</p>

<p>在选修某些课程之前需要一些先修课程。 先修课程按数组 <code>prerequisites</code> 给出，其中 <code>prerequisites[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> ，表示如果要学习课程 <code>a<sub>i</sub></code> 则 <strong>必须</strong> 先学习课程  <code>b<sub>i</sub></code><sub> </sub>。</p>

<ul>
	<li>例如，先修课程对 <code>[0, 1]</code> 表示：想要学习课程 <code>0</code> ，你需要先完成课程 <code>1</code> 。</li>
</ul>

<p>请你判断是否可能完成所有课程的学习？如果可以，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>numCourses = 2, prerequisites = [[1,0]]
<strong>输出：</strong>true
<strong>解释：</strong>总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>numCourses = 2, prerequisites = [[1,0],[0,1]]
<strong>输出：</strong>false
<strong>解释：</strong>总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0 ；并且学习课程 0 之前，你还应先完成课程 1 。这是不可能的。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= numCourses <= 10<sup>5</sup></code></li>
	<li><code>0 <= prerequisites.length <= 5000</code></li>
	<li><code>prerequisites[i].length == 2</code></li>
	<li><code>0 <= a<sub>i</sub>, b<sub>i</sub> < numCourses</code></li>
	<li><code>prerequisites[i]</code> 中的所有课程对 <strong>互不相同</strong></li>
</ul>


    
## 方法一：拓扑排序

这道题类似于[LeetCode 剑指 Offer II 115.重建序列](https://leetcode.letmefly.xyz/2022/07/23/LeetCode%20%E5%89%91%E6%8C%87%20Offer%20II%200115.%20%E9%87%8D%E5%BB%BA%E5%BA%8F%E5%88%97/)，使用[拓扑排序](https://leetcode.letmefly.xyz/tags/%E6%8B%93%E6%89%91%E6%8E%92%E5%BA%8F/)进行解决即可。

遍历每一个“先修课关系”，如果学习```a```前必须先学习```b```，那么就构建一条```b→a```的边（```b```指向的节点中添加```a```，```a```的入度```+1```）

之后开始拓扑排序，使用一个队列，入队所有入度为$0$的节点

不断从队列中取出节点，将这个节点所指向的每个元素的入度都减一

一旦某个节点入度变为$0$，就入队

拓扑排序完成后，若没有剩余节点，就返回```true```

否则说明“先修课关系图”中有环，返回```false```

+ 时间复杂度$O(n + numCourses)$，其中$n$是先修课关系数
+ 空间复杂度$O(n + numCourses)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);
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
                }
            }
        }

        return !remainNode;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/08/21/LeetCode%200207.%E8%AF%BE%E7%A8%8B%E8%A1%A8/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126448507](https://letmefly.blog.csdn.net/article/details/126448507)
