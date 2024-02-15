---
title: 886.可能的二分法
date: 2022-10-16 10:12:17
tags: [题解, LeetCode, 中等, 深度优先搜索, 广度优先搜索, BFS, 并查集, 图, 哈希表, 哈希, 二分图]
---

# 【LetMeFly】886.可能的二分法：图搜索

力扣题目链接：[https://leetcode.cn/problems/possible-bipartition/](https://leetcode.cn/problems/possible-bipartition/)

<p>给定一组&nbsp;<code>n</code>&nbsp;人（编号为&nbsp;<code>1, 2, ..., n</code>），&nbsp;我们想把每个人分进<strong>任意</strong>大小的两组。每个人都可能不喜欢其他人，那么他们不应该属于同一组。</p>

<p>给定整数 <code>n</code>&nbsp;和数组 <code>dislikes</code>&nbsp;，其中&nbsp;<code>dislikes[i] = [a<sub>i</sub>, b<sub>i</sub>]</code>&nbsp;，表示不允许将编号为 <code>a<sub>i</sub></code>&nbsp;和&nbsp;&nbsp;<code>b<sub>i</sub></code>的人归入同一组。当可以用这种方法将所有人分进两组时，返回 <code>true</code>；否则返回 <code>false</code>。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 4, dislikes = [[1,2],[1,3],[2,4]]
<strong>输出：</strong>true
<strong>解释：</strong>group1 [1,4], group2 [2,3]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 3, dislikes = [[1,2],[1,3],[2,3]]
<strong>输出：</strong>false
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2000</code></li>
	<li><code>0 &lt;= dislikes.length &lt;= 10<sup>4</sup></code></li>
	<li><code>dislikes[i].length == 2</code></li>
	<li><code>1 &lt;= dislikes[i][j] &lt;= n</code></li>
	<li><code>a<sub>i</sub>&nbsp;&lt; b<sub>i</sub></code></li>
	<li><code>dislikes</code>&nbsp;中每一组都 <strong>不同</strong></li>
</ul>

<p>&nbsp;</p>


    
## 方法一：广度优先搜索

可以把题目理解为：$n$个节点的无向图，其中$dislikes$为边

这样，我们就能很容易地把图构建出来：

```cpp
vector<vector<int>> graph(n + 1);
for (auto& v : dislikes) {
    graph[v[0]].push_back(v[1]);
    graph[v[1]].push_back(v[0]);
}
```

图构建完毕后，对图进行搜索。

因为图可能不连通，因此当发现一个新的图的节点时，用哈希表记录下这个连通子图中的节点。

这样，在图遍历过程中，我们就可以很容易地知道是否出现了“环”

遍历过程中，我们给节点编号（分组），编号只有“1”和“2”

如果某个节点的相邻节点已有编号，就看这两个节点的编号是否相同。

若相邻两个节点编号相同，则分组失败，返回```false```

若图成功遍历完毕，则返回```true```

+ 时间复杂度$O(n + m)$，其中$n$是节点个数，$m$是边的个数
+ 空间复杂度$O(n + m)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
		// 建图
        vector<vector<int>> graph(n + 1);
        for (auto& v : dislikes) {
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
		// 遍历
        vector<bool> visited(n + 1, false);  // visited[i]表示节点i是否被遍历过
        vector<int> node(n + 1);  // node[i]表示节点i的编号
        for (int i = 1; i <= n; i++) {  // 查看每一个节点
            if (!visited[i]) {  // 若是一个未遍历过的新节点，则说明这是一个新的“子图”的节点
                visited[i] = true;  // 标记为遍历过
                node[i] = 1;  // 赋编号
                unordered_set<int> appeared;  // 用来记录这个子图中都有哪些节点
                appeared.insert(i);
                queue<int> q;  // 广搜队列
                q.push(i);
                while (q.size()) {
                    int thisNode = q.front();  // 取出节点
                    q.pop();
                    for (int toNode : graph[thisNode]) {  // 节点临边
                        if (!visited[toNode]) {  // 第一次遍历到
                            visited[toNode] = true;
                            node[toNode] = node[thisNode] == 1 ? 0 : 1;
                            appeared.insert(toNode);
                            q.push(toNode);
                        }
                        else {
                            if (appeared.count(toNode)) {  // 这俩点相连
                                if (node[thisNode] == node[toNode])
                                    return false;  // !!!!!!!!
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/10/16/LeetCode%200886.%E5%8F%AF%E8%83%BD%E7%9A%84%E4%BA%8C%E5%88%86%E6%B3%95/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127344544](https://letmefly.blog.csdn.net/article/details/127344544)
