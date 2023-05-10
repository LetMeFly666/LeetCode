---
title: 1971.寻找图中是否存在路径
date: 2022-12-19 20:12:54
tags: [题解, LeetCode, 简单, 深度优先搜索, 广度优先搜索, 图, BFS, 连通图]
---

# 【LetMeFly】1971.寻找图中是否存在路径

力扣题目链接：[https://leetcode.cn/problems/find-if-path-exists-in-graph/](https://leetcode.cn/problems/find-if-path-exists-in-graph/)

<p>有一个具有 <code>n</code>个顶点的 <strong>双向</strong> 图，其中每个顶点标记从 <code>0</code> 到 <code>n - 1</code>（包含 <code>0</code> 和 <code>n - 1</code>）。图中的边用一个二维整数数组 <code>edges</code> 表示，其中 <code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>]</code> 表示顶点 <code>ui</code> 和顶点 <code>vi</code> 之间的双向边。 每个顶点对由 <strong>最多一条</strong> 边连接，并且没有顶点存在与自身相连的边。</p>

<p>请你确定是否存在从顶点 <code>start</code> 开始，到顶点 <code>end</code> 结束的 <strong>有效路径</strong> 。</p>

<p>给你数组 <code>edges</code> 和整数 <code>n</code>、<code>start</code>和<code>end</code>，如果从 <code>start</code> 到 <code>end</code> 存在 <strong>有效路径</strong> ，则返回 <code>true</code>，否则返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/14/validpath-ex1.png" style="width: 141px; height: 121px;" />
<pre>
<strong>输入：</strong>n = 3, edges = [[0,1],[1,2],[2,0]], start = 0, end = 2
<strong>输出：</strong>true
<strong>解释：</strong>存在由顶点 0 到顶点 2 的路径:
- 0 → 1 → 2 
- 0 → 2
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/14/validpath-ex2.png" style="width: 281px; height: 141px;" />
<pre>
<strong>输入：</strong>n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], start = 0, end = 5
<strong>输出：</strong>false
<strong>解释：</strong>不存在由顶点 0 到顶点 5 的路径.
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>0 &lt;= edges.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>u<sub>i</sub> != v<sub>i</sub></code></li>
	<li><code>0 &lt;= start, end &lt;= n - 1</code></li>
	<li>不存在双向边</li>
	<li>不存在指向顶点自身的边</li>
</ul>


    
## 方法一：广度优先搜索

首先我们把题目中给的图，以邻接表的形式存储下来（C++中可使用vector<vector<int>>）

接着，再开辟一个大小未$n$的布尔类型的数组$visited$，其中$visited[n]$代表节点$n$是否被访问过，初始值全为$false$

然后建立一个队列，将起点入队。注意每入队一个节点，都需要将这个节点在$visited$中标记为$true$

当队列不为空时，将节点不断出队。对于出队的每个节点，遍历其相邻的所有节点。若有相邻节点未访问过，则入队。直到队列为空，我们就将与起点相联通的所有节点遍历完了。

最终$visited[destination]$即为答案

+ 时间复杂度$O(n)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n);
        visited[source] = true;
        queue<int> q;
        q.push(source);
        while (q.size()) {
            int thisNode = q.front();
            q.pop();
            for (int toNode : graph[thisNode]) {
                if (!visited[toNode]) {
                    visited[toNode] = true;
                    q.push(toNode);
                }
            }
        }
        return visited[destination];
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/12/19/LeetCode%201971.%E5%AF%BB%E6%89%BE%E5%9B%BE%E4%B8%AD%E6%98%AF%E5%90%A6%E5%AD%98%E5%9C%A8%E8%B7%AF%E5%BE%84/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128377260](https://letmefly.blog.csdn.net/article/details/128377260)
