---
title: 3249.统计好节点的数目
date: 2024-11-14 13:26:33
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, DFS]
---

# 【LetMeFly】3249.统计好节点的数目：深度优先搜索(DFS)

力扣题目链接：[https://leetcode.cn/problems/count-the-number-of-good-nodes/](https://leetcode.cn/problems/count-the-number-of-good-nodes/)

<p>现有一棵 <strong>无向</strong> 树，树中包含 <code>n</code> 个节点，按从 <code>0</code> 到 <code>n - 1</code> 标记。树的根节点是节点 <code>0</code> 。给你一个长度为 <code>n - 1</code> 的二维整数数组 <code>edges</code>，其中 <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> 表示树中节点 <code>a<sub>i</sub></code> 与节点 <code>b<sub>i</sub></code> 之间存在一条边。</p>

<p>如果一个节点的所有子节点为根的&nbsp;<span data-keyword="subtree">子树</span>&nbsp;包含的节点数相同，则认为该节点是一个 <strong>好节点</strong>。</p>

<p>返回给定树中<strong> 好节点 </strong>的数量。</p>

<p><strong>子树</strong>&nbsp;指的是一个节点以及它所有后代节点构成的一棵树。</p>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]</span></p>

<p><strong>输出：</strong><span class="example-io">7</span></p>

<p><strong>说明：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2024/05/26/tree1.png" style="width: 360px; height: 158px;" />
<p>树的所有节点都是好节点。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">edges = [[0,1],[1,2],[2,3],[3,4],[0,5],[1,6],[2,7],[3,8]]</span></p>

<p><strong>输出：</strong><span class="example-io">6</span></p>

<p><strong>说明：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2024/06/03/screenshot-2024-06-03-193552.png" style="width: 360px; height: 303px;" />
<p>树中有 6 个好节点。上图中已将这些节点着色。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>edges = [[0,1],[1,2],[1,3],[1,4],[0,5],[5,6],[6,7],[7,8],[0,9],[9,10],[9,12],[10,11]]</span></p>

<p><span class="example-io"><b>输出：</b>12</span></p>

<p><strong>解释：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2024/08/08/rob.jpg" style="width: 450px; height: 277px;" />
<p>除了节点 9 以外其他所有节点都是好节点。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li>输入确保 <code>edges</code> 总表示一棵有效的树。</li>
</ul>


    
## 解题方法：深度优先搜索

首先通过“边”建“树”，创建一个`graph`二维数组，其中`graph[x]`为所有与`x`相邻的节点。

接着写一个函数`dfs(当前节点, 父节点)`，如果`当前节点`的所有子树大小`dfs(子节点)`相同，就将全局答案加一。最终返回`当前节点`为根的子树的大小。

+ 时间复杂度$O(n)$，每个节点之后被`dfs`一次
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
private:
    int ans;
    vector<vector<int>> graph;

    int dfs(int root, int parent=-1) {
        int cnt = 1;
        int oneChild = 0;
        bool thisNodeOk = true;
        for (int nextNode : graph[root]) {
            if (nextNode == parent) {
                continue;
            }
            int nextCnt = dfs(nextNode, root);
            cnt += nextCnt;
            if (oneChild && nextCnt != oneChild) {
                thisNodeOk = false;
            }
            oneChild = nextCnt;
        }
        if (thisNodeOk) {
            ans++;
        }
        return cnt;
    }
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        ans = 0;
        graph.resize(edges.size() + 1);
        for (vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        dfs(0);
        return ans;
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def dfs(self, thisNode: int, parentNode: int=-1) -> int:
        cnt, oneChild, ok = 1, 0, True
        for nextNode in self.graph[thisNode]:
            if nextNode == parentNode:
                continue
            nextChild = self.dfs(nextNode, thisNode)
            cnt += nextChild
            if not oneChild:
                oneChild = nextChild
            elif oneChild != nextChild:
                ok = False
        if ok:
            self.ans += 1
        return cnt
    
    def countGoodNodes(self, edges: List[List[int]]) -> int:
        self.graph = [[] for _ in range(len(edges) + 1)]
        for x, y in edges:
            self.graph[x].append(y)
            self.graph[y].append(x)
        self.ans = 0
        self.dfs(0)
        return self.ans
```

#### Java

```java
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    private List<Integer>[] graph;
    private int ans;

    private int dfs(int thisNode, int lastNode) {
        int cnt = 1;
        int oneChild = 0;
        boolean ok = true;
        for (int nextChilld : graph[thisNode]) {
            if (nextChilld == lastNode) {
                continue;
            }
            int thisChild = dfs(nextChilld, thisNode);
            cnt += thisChild;
            if (oneChild == 0) {
                oneChild = thisChild;
            } else if (oneChild != thisChild) {
                ok = false;
            }
        }
        if (ok) {
            ans++;
        }
        return cnt;
    }

    public int countGoodNodes(int[][] edges) {
        ans = 0;
        graph = new ArrayList[edges.length + 1];
        Arrays.setAll(graph, i -> new ArrayList<>());
        for (int[] edge : edges) {
            graph[edge[0]].add(edge[1]);
            graph[edge[1]].add(edge[0]);
        }
        dfs(0, -1);
        return ans;
    }
}
```

#### Go

```go
package main

// import "fmt"

func countGoodNodes(edges [][]int) (ans int) {
    graph := make([][]int, len(edges) + 1)
    for _, edge := range edges {
        graph[edge[0]] = append(graph[edge[0]], edge[1])
        graph[edge[1]] = append(graph[edge[1]], edge[0])
    }
    var dfs func(int, int) int
    dfs = func(thisNode, lastNode int) int {
        // fmt.Println(thisNode, lastNode)
        cnt, oneChild, ok := 1, 0, true
        for _, nextNode := range graph[thisNode] {
            if nextNode == lastNode {
                continue
            }
            thisChild := dfs(nextNode, thisNode)
            cnt += thisChild
            if oneChild == 0 {
                oneChild = thisChild
            } else if oneChild != thisChild {
                ok = false
            }
        }
        if ok {
            ans++
        }
        return cnt
    }
    dfs(0, -1)
    return ans
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/11/14/LeetCode%203249.%E7%BB%9F%E8%AE%A1%E5%A5%BD%E8%8A%82%E7%82%B9%E7%9A%84%E6%95%B0%E7%9B%AE/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/143768804](https://letmefly.blog.csdn.net/article/details/143768804)
