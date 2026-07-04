---
title: 2492.两个城市间路径的最小分数：找1所在连通图的最小边(BFS / DFS)
date: 2026-07-04 11:03:17
tags: [题解, LeetCode, 中等, 深度优先搜索, DFS, BFS, 广度优先搜索, 并查集, 图]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.com/uploads/2022/10/12/graph11.png
---

# 【LetMeFly】2492.两个城市间路径的最小分数：找1所在连通图的最小边(BFS / DFS)

力扣题目链接：[https://leetcode.cn/problems/minimum-score-of-a-path-between-two-cities/](https://leetcode.cn/problems/minimum-score-of-a-path-between-two-cities/)

<p>给你一个正整数&nbsp;<code>n</code>&nbsp;，表示总共有&nbsp;<code>n</code>&nbsp;个城市，城市从&nbsp;<code>1</code>&nbsp;到&nbsp;<code>n</code>&nbsp;编号。给你一个二维数组&nbsp;<code>roads</code>&nbsp;，其中&nbsp;<code>roads[i] = [a<sub>i</sub>, b<sub>i</sub>, distance<sub>i</sub>]</code>&nbsp;表示城市&nbsp;<code>a<sub>i</sub></code> 和&nbsp;<code>b<sub>i</sub></code>&nbsp;之间有一条 <strong>双向</strong>&nbsp;道路，道路距离为&nbsp;<code>distance<sub>i</sub></code>&nbsp;。城市构成的图不一定是连通的。</p>

<p>两个城市之间一条路径的 <strong>分数</strong>&nbsp;定义为这条路径中道路的 <strong>最小</strong>&nbsp;距离。</p>

<p><span class="text-only" data-eleid="20" style="white-space: pre;">返回城市</span><span class="text-only text-font-italic" data-eleid="21" style="white-space: pre;"> </span><code><span class="text-only" data-eleid="22" style="white-space: pre;">1</span></code><span class="text-only text-font-italic" data-eleid="23" style="white-space: pre;"> </span><span class="text-only" data-eleid="24" style="white-space: pre;">和城市</span><span class="text-only text-font-italic" data-eleid="25" style="white-space: pre;"> </span><span class="text-only" data-eleid="26" style="white-space: pre;"><code>n</code> 之间的所有路径的 </span><strong><span class="text-only" data-eleid="27" style="white-space: pre;">最小</span></strong><span class="text-only" data-eleid="28" style="white-space: pre;"> 分数。</span></p>

<p><b>注意：</b></p>

<ul>
	<li>一条路径指的是两个城市之间的道路序列。</li>
	<li>一条路径可以 <strong>多次</strong> 包含同一条道路，你也可以沿着路径多次到达城市 <code>1</code>&nbsp;和城市 <code>n</code>&nbsp;。</li>
	<li>测试数据保证城市 <code>1</code>&nbsp;和城市<code>n</code>&nbsp;之间 <strong>至少</strong>&nbsp;有一条路径。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/10/12/graph11.png" style="width: 190px; height: 231px;" /></p>

<pre>
<b>输入：</b>n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
<b>输出：</b>5
<b>解释：</b>城市 1 到城市 4 的路径中，分数最小的一条为：1 -&gt; 2 -&gt; 4 。这条路径的分数是 min(9,5) = 5 。
不存在分数更小的路径。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/10/12/graph22.png" style="width: 190px; height: 231px;" /></p>

<pre>
<b>输入：</b>n = 4, roads = [[1,2,2],[1,3,4],[3,4,7]]
<b>输出：</b>2
<b>解释：</b>城市 1 到城市 4 分数最小的路径是：1 -&gt; 2 -&gt; 1 -&gt; 3 -&gt; 4 。这条路径的分数是 min(2,2,4,7) = 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= roads.length &lt;= 10<sup>5</sup></code></li>
	<li><code>roads[i].length == 3</code></li>
	<li><code>1 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li><code>1 &lt;= distance<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
	<li>不会有重复的边。</li>
	<li>城市 <code>1</code>&nbsp;和城市 <code>n</code>&nbsp;之间至少有一条路径。</li>
</ul>


    
## 解题方法：找1所在连通图的最小边

由于路径可以无限往返，所以其实只要和`1`联通的路径都可以走。由于`1`一定和`n`联通，所以实际上是找和`1`联通的节点的所有边中，值最小的那条边。

### 解题方法一：广度优先搜索(BFS)

遍历一遍roads得到邻接表`graph`，其中`graph[i]`是所有和节点`i`相邻的`节点`；同时得到节点相邻最小路长`m`，其中`m[i]`是所有和节点`i`相邻的路的最短距离。

使用一个队列进行广度优先搜索，初始时把`i`入队，每出队一个节点就更新答案最小值，并把其相邻未入队过的节点入队。

### 解题方法二：深度优先搜索(DFS)

遍历一遍roads得到邻接表`graph`，其中`graph[i]`是所有和节点`i`相邻的`(节点, 路的距离)`。

从节点`i`开始深度优先搜索，遍历每一条与`i`相邻的路并更新答案最小值，若某条路上与`i`相邻的节点还未遍历过则递归。

### 时空复杂度分析

+ 时间复杂度$O(n)$
+ 空间复杂度$O(n)$

### AC代码

#### C++ —— BFS

```cpp
/*
 * @LastEditTime: 2026-07-04 10:58:26
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<int>> graph(n + 1);
        vector<int> m(n + 1, 100000);

        for (vector<int>& road : roads) {
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
            m[road[0]] = min(m[road[0]], road[2]);
            m[road[1]] = min(m[road[1]], road[2]);
        }
        
        int ans = 100000;
        vector<bool> visited(n + 1);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        while (q.size()) {
            int a = q.front();
            q.pop();
            for (int b: graph[a]) {
                if (!visited[b]) {
                    visited[b] = true;
                    q.push(b);
                    ans = min(ans, m[b]);
                }
            }
        }
        return ans;
    }
};
```

#### C++ —— DFS

```cpp
/*
 * @LastEditTime: 2026-07-04 11:02:17
 */
class Solution {
private:
    int ans;
    vector<bool> visited;
    vector<vector<pair<int, int>>> graph;

    void dfs(int from) {
        visited[from] = true;
        for (auto [to, dis] : graph[from]) {
            ans = min(ans, dis);
            if (!visited[to]) {
                dfs(to);
            }
        }
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        visited = vector<bool> (n + 1);
        graph = vector<vector<pair<int, int>>>(n + 1);
        for (vector<int>& road : roads) {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }

        ans = 100000;
        dfs(1);
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/162575812)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/07/04/LeetCode%202492.%E4%B8%A4%E4%B8%AA%E5%9F%8E%E5%B8%82%E9%97%B4%E8%B7%AF%E5%BE%84%E7%9A%84%E6%9C%80%E5%B0%8F%E5%88%86%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
