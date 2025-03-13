---
title: 1334.阈值距离内邻居最少的城市
date: 2023-11-14 23:01:16
tags: [题解, LeetCode, 中等, 图, 动态规划, 最短路, 迪杰斯特拉算法]
categories: [题解, LeetCode]
---

# 【LetMeFly】1334.阈值距离内邻居最少的城市：多次运用单源最短路的迪杰斯特拉算法

力扣题目链接：[https://leetcode.cn/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/](https://leetcode.cn/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/)

<p>有 <code>n</code> 个城市，按从 <code>0</code> 到 <code>n-1</code> 编号。给你一个边数组 <code>edges</code>，其中 <code>edges[i] = [from<sub>i</sub>, to<sub>i</sub>, weight<sub>i</sub>]</code> 代表 <code>from<sub>i</sub></code> 和 <code>to<sub>i</sub></code><sub> </sub>两个城市之间的双向加权边，距离阈值是一个整数 <code>distanceThreshold</code>。</p>

<p>返回能通过某些路径到达其他城市数目最少、且路径距离 <strong>最大</strong> 为 <code>distanceThreshold</code> 的城市。如果有多个这样的城市，则返回编号最大的城市。</p>

<p>注意，连接城市 <em><strong>i</strong></em> 和 <em><strong>j</strong></em> 的路径的距离等于沿该路径的所有边的权重之和。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/01/26/find_the_city_01.png" style="height: 225px; width: 300px;" /></p>

<pre>
<strong>输入：</strong>n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
<strong>输出：</strong>3
<strong>解释：</strong>城市分布图如上。
每个城市阈值距离 distanceThreshold = 4 内的邻居城市分别是：
城市 0 -> [城市 1, 城市 2] 
城市 1 -> [城市 0, 城市 2, 城市 3] 
城市 2 -> [城市 0, 城市 1, 城市 3] 
城市 3 -> [城市 1, 城市 2] 
城市 0 和 3 在阈值距离 4 以内都有 2 个邻居城市，但是我们必须返回城市 3，因为它的编号最大。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/01/26/find_the_city_02.png" style="height: 225px; width: 300px;" /></strong></p>

<pre>
<strong>输入：</strong>n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
<strong>输出：</strong>0
<strong>解释：</strong>城市分布图如上。 
每个城市阈值距离 distanceThreshold = 2 内的邻居城市分别是：
城市 0 -> [城市 1] 
城市 1 -> [城市 0, 城市 4] 
城市 2 -> [城市 3, 城市 4] 
城市 3 -> [城市 2, 城市 4]
城市 4 -> [城市 1, 城市 2, 城市 3] 
城市 0 在阈值距离 2 以内只有 1 个邻居城市。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= n <= 100</code></li>
	<li><code>1 <= edges.length <= n * (n - 1) / 2</code></li>
	<li><code>edges[i].length == 3</code></li>
	<li><code>0 <= from<sub>i</sub> < to<sub>i</sub> < n</code></li>
	<li><code>1 <= weight<sub>i</sub>, distanceThreshold <= 10^4</code></li>
	<li>所有 <code>(from<sub>i</sub>, to<sub>i</sub>)</code> 都是不同的。</li>
</ul>


    
## 方法一：多次运用单源最短路的迪杰斯特拉算法

迪杰斯特拉算法可以让我们在$O(n^2)$的时间复杂度内求出图中某点到其他所有点的最短路径。

关于单源最短路的迪杰斯特拉算法，推荐查看[某人](https://letmefly.xyz/)的[视频讲解及配套代码](https://letmefly.xyz/Links/Redirect/id?13)。（算法本质是在所有能走的路中选一个最短的能到新节点的路来走）

这样，我们可以写一个函数来获取某个点不超过“distanceThreshold”的“邻居城市”的个数。

使用两个变量分别记录“最少的近邻个数”和“当前答案”，遍历一遍每个节点，计算并更新这两个变量即可得到答案。

+ 时间复杂度$O(n^3)$
+ 空间复杂度$O(size(graph) + n)$

### AC代码

#### C++

```cpp
class Solution {
private:
    int find1City(vector<vector<pair<int, int>>> &graph, int start, int Md) {
        vector<bool> visited(graph.size(), false);
        vector<int> minDistance(graph.size(), 1e9);
        minDistance[start] = 0;
        for (int i = 0; i < graph.size(); i++) {
            int thisMinDistance = 1e9;
            int thisShortestPoint = -1;
            for (int j = 0; j < graph.size(); j++) {
                if (!visited[j] && minDistance[j] < thisMinDistance) {
                    thisMinDistance = minDistance[j];
                    thisShortestPoint = j;
                }
            }
            if (thisMinDistance == 1e9) {
                break;
            }
            visited[thisShortestPoint] = true;
            for (auto& [toPoint, thisDistance] : graph[thisShortestPoint]) {
                if (minDistance[thisShortestPoint] + thisDistance < minDistance[toPoint]) {
                    minDistance[toPoint] = minDistance[thisShortestPoint] + thisDistance;
                }
            }
        }
        int ans = -1;
        for (int i = 0; i < graph.size(); i++) {
            if (minDistance[i] <= Md) {
                ans++;
            }
        }
        return ans;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& v : edges) {
            graph[v[0]].push_back({v[1], v[2]});
            graph[v[1]].push_back({v[0], v[2]});
        }
        int mCan = n, Mnum = 0;
        for (int i = 0; i < n; i++) {
            int thisCity = find1City(graph, i, distanceThreshold);
            if (thisCity <= mCan) {
                mCan = thisCity;
                Mnum = i;
            }
        }
        return Mnum;
    }
};
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/11/14/LeetCode%201334.%E9%98%88%E5%80%BC%E8%B7%9D%E7%A6%BB%E5%86%85%E9%82%BB%E5%B1%85%E6%9C%80%E5%B0%91%E7%9A%84%E5%9F%8E%E5%B8%82/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/134410277](https://letmefly.blog.csdn.net/article/details/134410277)
