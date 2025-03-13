---
title: 3112.访问消失节点的最少时间
date: 2024-07-18 18:27:51
tags: [题解, LeetCode, 中等, 图, 数组, 最短路, 堆（优先队列）]
categories: [题解, LeetCode]
---

# 【LetMeFly】3112.访问消失节点的最少时间：单源最短路的Dijkstra算法

力扣题目链接：[https://leetcode.cn/problems/minimum-time-to-visit-disappearing-nodes/](https://leetcode.cn/problems/minimum-time-to-visit-disappearing-nodes/)

<p>给你一个二维数组 <code>edges</code>&nbsp;表示一个 <code>n</code>&nbsp;个点的无向图，其中&nbsp;<code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>, length<sub>i</sub>]</code>&nbsp;表示节点&nbsp;<code>u<sub>i</sub></code> 和节点&nbsp;<code>v<sub>i</sub></code>&nbsp;之间有一条需要&nbsp;<code>length<sub>i</sub></code>&nbsp;单位时间通过的无向边。</p>

<p>同时给你一个数组&nbsp;<code>disappear</code>&nbsp;，其中&nbsp;<code>disappear[i]</code>&nbsp;表示节点 <code>i</code>&nbsp;从图中消失的时间点，在那一刻及以后，你无法再访问这个节点。</p>

<p><strong>注意</strong>，图有可能一开始是不连通的，两个节点之间也可能有多条边。</p>

<p>请你返回数组&nbsp;<code>answer</code>&nbsp;，<code>answer[i]</code>&nbsp;表示从节点 <code>0</code>&nbsp;到节点 <code>i</code>&nbsp;需要的 <strong>最少</strong>&nbsp;单位时间。如果从节点 <code>0</code>&nbsp;出发 <strong>无法</strong> 到达节点 <code>i</code>&nbsp;，那么 <code>answer[i]</code>&nbsp;为 <code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img 10px="" alt="" padding:="" src="https://assets.leetcode.com/uploads/2024/03/09/example1.png" style="width: 350px; height: 210px;" /></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p style=""><span class="example-io" style="font-size: 8.75px;"><b>输入：</b></span><span class="example-io" style="font-size: 0.85rem; font-family: Menlo, sans-serif;">n = 3, edges = [[0,1,2],[1,2,1],[0,2,4]], disappear = [1,1,5]</span></p>

<p style=""><span class="example-io" style="font-size: 8.75px;"><b>输出：</b></span><span class="example-io" style="font-size: 0.85rem; font-family: Menlo, sans-serif;">[0,-1,4]</span></p>

<p style="font-size: 0.875rem;"><strong>解释：</strong></p>

<p style="font-size: 0.875rem;">我们从节点 0 出发，目的是用最少的时间在其他节点消失之前到达它们。</p>

<ul style="font-size: 0.875rem;">
	<li>对于节点 0 ，我们不需要任何时间，因为它就是我们的起点。</li>
	<li>对于节点 1 ，我们需要至少 2 单位时间，通过&nbsp;<code>edges[0]</code>&nbsp;到达。但当我们到达的时候，它已经消失了，所以我们无法到达它。</li>
	<li>对于节点 2 ，我们需要至少 4 单位时间，通过&nbsp;<code>edges[2]</code>&nbsp;到达。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<p><img 10px="" alt="" padding:="" src="https://assets.leetcode.com/uploads/2024/03/09/example2.png" style="width: 350px; height: 210px;" /></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p style=""><span class="example-io" style="font-size: 8.75px;"><b>输入：</b></span><span class="example-io" style="font-size: 0.85rem; font-family: Menlo, sans-serif;">n = 3, edges = [[0,1,2],[1,2,1],[0,2,4]], disappear = [1,3,5]</span></p>

<p style=""><span class="example-io" style="font-size: 8.75px;"><b>输出：</b></span><span class="example-io" style="font-size: 0.85rem; font-family: Menlo, sans-serif;">[0,2,3]</span></p>

<p style="font-size: 0.875rem;"><strong>解释：</strong></p>

<p style="font-size: 0.875rem;">我们从节点 0 出发，目的是用最少的时间在其他节点消失之前到达它们。</p>

<ul style="font-size: 0.875rem;">
	<li>对于节点 0 ，我们不需要任何时间，因为它就是我们的起点。</li>
	<li>对于节点 1 ，我们需要至少 2 单位时间，通过&nbsp;<code>edges[0]</code>&nbsp;到达。</li>
	<li>对于节点 2&nbsp;，我们需要至少 3&nbsp;单位时间，通过&nbsp;<code>edges[0]</code>&nbsp;和 <code>edges[1]</code>&nbsp;到达。</li>
</ul>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><span class="example-io"><b>输入：</b>n = 2, edges = [[0,1,1]], disappear = [1,1]</span></p>

<p><span class="example-io"><b>输出：</b>[0,-1]</span></p>

<p><strong>解释：</strong></p>

<p>当我们到达节点 1 的时候，它恰好消失，所以我们无法到达节点 1 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= edges.length &lt;= 10<sup>5</sup></code></li>
	<li><code>edges[i] == [u<sub>i</sub>, v<sub>i</sub>, length<sub>i</sub>]</code></li>
	<li><code>0 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>1 &lt;= length<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li><code>disappear.length == n</code></li>
	<li><code>1 &lt;= disappear[i] &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法：单源最短路的Dijkstra算法

关于`单源最短路的Dijkstra算法`的视频讲解，可以查看[这个视频](https://www.bilibili.com/video/BV1Y84y1N7Lm/)。

大致思路是：从起点开始，每次将所有的能一部到达的节点放入优先队列中。优先队列中存放的是每个节点的首次能到达的时间以及节点编号，能最先到达的最先出队。

每次从优先队列中取出一个元素，这样就得到了这个元素的最快到达时间。以此节点开始将所有相邻的没有确定过最短时间的节点入队。直到队列为空为止，就得到了从起点到其他任意一点的最短耗时。

关于本题，有个额外条件就是节点消失时间。很简单，在每次遍历当前节点的相邻节点时，若无法在某相邻节点消失之前到达，则不将其入队。

+ 时间复杂度$O(n+m\log m)$，其中$n$是节点数量，$m$是边的数量。
+ 空间复杂度$O(n+m)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int, int>>> graph(n);
        for (vector<int>& edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        vector<int> ans(n, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;  // [<time, toNode>, ...
        pq.push({0, 0});
        while (pq.size()) {
            auto [thisTime, thisNode] = pq.top();
            pq.pop();
            if (ans[thisNode] != -1) {
                continue;
            }
            ans[thisNode] = thisTime;
            for (auto [nextNode, length] : graph[thisNode]) {
                if (ans[nextNode] != -1 || thisTime + length >= disappear[nextNode]) {
                    continue;
                }
                pq.push({thisTime + length, nextNode});
            }
        }
        return ans;
    }
};
```

#### Java

```java
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;

class Solution {
    public int[] minimumTime(int n, int[][] edges, int[] disappear) {
        List<int[]>[] graph = new ArrayList[n];
        Arrays.setAll(graph, i -> new ArrayList<>());
        for (int[] edge : edges) {
            graph[edge[0]].add(new int[]{edge[1], edge[2]});
            graph[edge[1]].add(new int[]{edge[0], edge[2]});
        }
        int[] ans = new int[n];
        Arrays.fill(ans, -1);
        Queue<int[]> pq = new PriorityQueue<>((a, b) -> (a[0] - b[0]));
        pq.add(new int[]{0, 0});
        while (!pq.isEmpty()) {
            int[] temp = pq.poll();
            int thisTime = temp[0];
            int thisNode = temp[1];
            if (ans[thisNode] != -1) {
                continue;
            }
            ans[thisNode] = thisTime;
            for (int[] temp2 : graph[thisNode]) {
                int nextNode = temp2[0];
                int length = temp2[1];
                if (ans[nextNode] == -1 && thisTime + length < disappear[nextNode]) {
                    pq.add(new int[]{thisTime + length, nextNode});
                }
            }
        }
        return ans;
    }
}
```

#### Python

```python
from typing import List
import heapq

class Solution:
    def minimumTime(self, n: int, edges: List[List[int]], disappear: List[int]) -> List[int]:
        graph = [[] for _ in range(n)]
        for x, y, d in edges:
            graph[x].append((y, d))
            graph[y].append((x, d))
        ans = [-1] * n
        pq = [(0, 0)]
        while pq:
            thisTime, thisNode = heapq.heappop(pq)
            if ans[thisNode] != -1:
                continue
            ans[thisNode] = thisTime
            for nextNode, length in graph[thisNode]:
                # print(nextNode, length, ans[nextNode], thisTime + length, disappear[nextNode])  #------------------
                # print(ans[nextNode] != -1)
                # print(thisTime + length < disappear[nextNode])
                if ans[nextNode] == -1 and thisTime + length < disappear[nextNode]:
                    heapq.heappush(pq, (thisTime + length, nextNode))
        return ans


if __name__ == '__main__':
    sol = Solution()
    print(sol.minimumTime(3, [[0, 1, 2], [1, 2, 1], [0, 2, 4]], [1, 1, 5]))
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/07/18/LeetCode%203112.%E8%AE%BF%E9%97%AE%E6%B6%88%E5%A4%B1%E8%8A%82%E7%82%B9%E7%9A%84%E6%9C%80%E5%B0%91%E6%97%B6%E9%97%B4/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/140530368](https://letmefly.blog.csdn.net/article/details/140530368)
