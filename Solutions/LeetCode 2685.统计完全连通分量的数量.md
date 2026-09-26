---
title: 2685.统计完全连通分量的数量：DFS求每个连通块的边点数
date: 2026-07-11 08:46:04
tags: [题解, LeetCode, 中等, 深度优先搜索, DFS, 广度优先搜索, 并查集, 图, 连通图, 图的连通分量]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.com/uploads/2023/04/11/screenshot-from-2023-04-11-23-32-00.png
---

# 【LetMeFly】2685.统计完全连通分量的数量：DFS求每个连通块的边点数

力扣题目链接：[https://leetcode.cn/problems/count-the-number-of-complete-components/](https://leetcode.cn/problems/count-the-number-of-complete-components/)

<p>给你一个整数 <code>n</code> 。现有一个包含 <code>n</code> 个顶点的 <strong>无向</strong> 图，顶点按从 <code>0</code> 到 <code>n - 1</code> 编号。给你一个二维整数数组 <code>edges</code> 其中 <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> 表示顶点 <code>a<sub>i</sub></code> 和 <code>b<sub>i</sub></code> 之间存在一条 <strong>无向</strong> 边。</p>

<p>返回图中 <strong>完全连通分量</strong> 的数量。</p>

<p>如果在子图中任意两个顶点之间都存在路径，并且子图中没有任何一个顶点与子图外部的顶点共享边，则称其为 <strong>连通分量</strong> 。</p>

<p>如果连通分量中每对节点之间都存在一条边，则称其为 <strong>完全连通分量</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2023/04/11/screenshot-from-2023-04-11-23-31-23.png" style="width: 671px; height: 270px;" /></strong></p>

<pre>
<strong>输入：</strong>n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
<strong>输出：</strong>3
<strong>解释：</strong>如上图所示，可以看到此图所有分量都是完全连通分量。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2023/04/11/screenshot-from-2023-04-11-23-32-00.png" style="width: 671px; height: 270px;" /></strong></p>

<pre>
<strong>输入：</strong>n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
<strong>输出：</strong>1
<strong>解释：</strong>包含节点 0、1 和 2 的分量是完全连通分量，因为每对节点之间都存在一条边。
包含节点 3 、4 和 5 的分量不是完全连通分量，因为节点 4 和 5 之间不存在边。
因此，在图中完全连接分量的数量是 1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 50</code></li>
	<li><code>0 &lt;= edges.length &lt;= n * (n - 1) / 2</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>不存在重复的边</li>
</ul>


    
## 解题方法：深度优先搜索DFS

从$0$到$n-1$遍历每一个节点，如果当前节点还没有被遍历过，则说明又找到了一个新的联通块，从这个节点开始DFS。

DFS要遍历与这个节点相连的所有节点和所有边并求出共有多少个。如果$边=\frac{点\times(点-1)}{2}$，则说明这个连通分量是完全连通分量。（注意，实际代码实现过程中每条边可能被其相连的两个节点共计遍历两次）

+ 时间复杂度$O(len(edges)+n)$，时间复杂度是边数+点数;
+ 空间复杂度$O(len(edges)+n)$，边的空间复杂度来自图的邻接表，点点空间复杂度来自DFS最大深度。

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-07-11 08:40:46
 */
typedef pair<int, int> pii;
class Solution {
private:
    vector<bool> visited;
    vector<vector<int>> graph;

    pii dfs(int from) {
        visited[from] = true;
        int edge = 0, node = 1;
        for (int to : graph[from]) {
            edge++;
            if (!visited[to]) {
                auto [next_edge, next_node] = dfs(to);
                edge += next_edge;
                node += next_node;
            }
        }
        return {edge, node};
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        for (vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        visited.resize(n);
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                auto [edge, node] = dfs(i);
                ans += edge == node * (node - 1);  // no need to /2
            }
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/162781132)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/07/11/LeetCode%202685.%E7%BB%9F%E8%AE%A1%E5%AE%8C%E5%85%A8%E8%BF%9E%E9%80%9A%E5%88%86%E9%87%8F%E7%9A%84%E6%95%B0%E9%87%8F/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
