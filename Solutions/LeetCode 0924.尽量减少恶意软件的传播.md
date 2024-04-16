---
title: 924.尽量减少恶意软件的传播
date: 2024-04-16 10:19:36
tags: [题解, LeetCode, 困难, 深度优先搜索, 广度优先搜索, BFS, 并查集, 图, 哈希表, 连通块, 染色]
---

# 【LetMeFly】924.尽量减少恶意软件的传播：连通块染色（以BFS为例）

力扣题目链接：[https://leetcode.cn/problems/minimize-malware-spread/](https://leetcode.cn/problems/minimize-malware-spread/)

<p>给出了一个由 <code>n</code> 个节点组成的网络，用 <code>n × n</code> 个邻接矩阵图<meta charset="UTF-8" />&nbsp;<code>graph</code>&nbsp;表示。在节点网络中，当 <code>graph[i][j] = 1</code>&nbsp;时，表示节点&nbsp;<code>i</code>&nbsp;能够直接连接到另一个节点 <code>j</code>。&nbsp;</p>

<p>一些节点&nbsp;<code>initial</code>&nbsp;最初被恶意软件感染。只要两个节点直接连接，且其中至少一个节点受到恶意软件的感染，那么两个节点都将被恶意软件感染。这种恶意软件的传播将继续，直到没有更多的节点可以被这种方式感染。</p>

<p>假设 <code>M(initial)</code> 是在恶意软件停止传播之后，整个网络中感染恶意软件的最终节点数。</p>

<p>如果从&nbsp;<code>initial</code>&nbsp;中<strong>移除某一节点</strong>能够最小化 <code>M(initial)</code>， 返回该节点。如果有多个节点满足条件，就返回<strong>索引最小</strong>的节点。</p>

<p>请注意，如果某个节点已从受感染节点的列表 <code>initial</code> 中删除，它以后仍有可能因恶意软件传播而受到感染。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>graph = [[1,1,0],[1,1,0],[0,0,1]], initial = [0,1]
<strong>输出：</strong>0
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>graph = [[1,0,0],[0,1,0],[0,0,1]], initial = [0,2]
<strong>输出：</strong>0
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>graph = [[1,1,1],[1,1,1],[1,1,1]], initial = [1,2]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>
<meta charset="UTF-8" />

<ul>
	<li><code>n == graph.length</code></li>
	<li><code>n == graph[i].length</code></li>
	<li><code>2 &lt;= n &lt;= 300</code></li>
	<li><code>graph[i][j]&nbsp;==&nbsp;0</code>&nbsp;或&nbsp;<code>1</code>.</li>
	<li><code>graph[i][j] == graph[j][i]</code></li>
	<li><code>graph[i][i] == 1</code></li>
	<li><code>1 &lt;= initial.length &lt;= n</code></li>
	<li><code>0 &lt;= initial[i] &lt;= n - 1</code></li>
	<li><code>initial</code>&nbsp;中所有整数均<strong>不重复</strong></li>
</ul>


    
## 解题方法：连通块染色（以BFS为例）

### 解题思路

我们将所有相互连通的节点（称为连通块）染成相同的颜色，不同连通块染成不同的颜色，并记录下每个连通块的大小。

这样，对于```intial```中的节点```t```：

+ 如果存在另一节点```i```和```t```同色，则初始时移除该节点无意义；
+ 否则，初始时移除节点```t```的话，和```t```同色的节点都将幸免。

### 具体方法

对于连通块染色：

> + 使用数组```color[i]```代表节点```i```的颜色，初始值全为```0```（代表无色）；
> + 使用数组```color2size[i]```代表颜色为```i```的节点的个数。
>
> 遍历每个节点，若该节点未被染色，则发现新的连通块：
>
> > 将该节点染成一个新的颜色，创建一个队列并将该节点入队。
> >
> > 队列非空时，出队一个节点，并遍历这个节点的所有相邻节点。
> >
> > 若某相邻节点未被染色，则将其染成相同的颜色，并更新```color2size```的大小。

### 时空复杂度

+ 时间复杂度$O(len(graph)^2)$
+ 空间复杂度$O(len(graph))$

### AC代码

#### C++

```cpp
class Solution {
private:
    int canDesc(int t, vector<int>& initial, vector<int>& color, vector<int>& color2size) {
        for (int i : initial) {
            if (color[i] == color[t] && i != t) {
                return 0;
            }
        }
        return color2size[color[t]];
    }
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int cntColor = 0;
        vector<int> color(graph.size());
        vector<int> color2size(graph.size() + 1);
        for (int i = 0; i < graph.size(); i++) {  // begin from each node
            if (color[i]) {
                continue;
            }
            cntColor++;
            queue<int> q;
            q.push(i);
            color[i] = cntColor;
            color2size[cntColor]++;
            while (q.size()) {
                int thisNode = q.front();
                q.pop();
                for (int j = 0; j < graph.size(); j++) {
                    if (graph[thisNode][j] && !color[j]) {
                        q.push(j);
                        color[j] = cntColor;
                        color2size[cntColor]++;
                    }
                }
            }
        }
        int ans, maxDesc = -1;
        sort(initial.begin(), initial.end());
        for (int t : initial) {
            int thisDesc = canDesc(t, initial, color, color2size);
            if (thisDesc > maxDesc) {
                maxDesc = thisDesc;
                ans = t;
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
    def canDesc(self, t, initial, color, color2cnt) -> int:
        for i in initial:
            if color[i] == color[t] and i != t:
                return 0
        return color2cnt[color[t]]
    
    def minMalwareSpread(self, graph: List[List[int]], initial: List[int]) -> int:
        color = [0] * len(graph)
        color2cnt = [0] * (len(graph) + 1)
        cntColor = 0
        for i in range(len(graph)):
            if color[i]:
                continue
            cntColor += 1
            color[i] = cntColor
            color2cnt[cntColor] = 1
            q = [i]
            while q:
                thisNode = q.pop()
                for j in range(len(graph)):
                    if graph[thisNode][j] and not color[j]:
                        color[j] = cntColor
                        color2cnt[cntColor] += 1
                        q.append(j)
        ans, maxDesc = 0, -1
        initial.sort()
        for t in initial:
            thisDesc = self.canDesc(t, initial, color, color2cnt)
            if thisDesc > maxDesc:
                maxDesc = thisDesc
                ans = t
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/04/16/LeetCode%200924.%E5%B0%BD%E9%87%8F%E5%87%8F%E5%B0%91%E6%81%B6%E6%84%8F%E8%BD%AF%E4%BB%B6%E7%9A%84%E4%BC%A0%E6%92%AD/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/137815658](https://letmefly.blog.csdn.net/article/details/137815658)
