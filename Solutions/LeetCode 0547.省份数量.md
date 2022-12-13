---
title: 547.省份数量
date: 2022-12-13 16:55:44
tags: [题解, LeetCode, 中等, 深度优先搜索, 广度优先搜索, 并查集, 图, 图的连通分量, BFS]
---

# 【LetMeFly】547.省份数量

力扣题目链接：[https://leetcode.cn/problems/number-of-provinces/](https://leetcode.cn/problems/number-of-provinces/)

<div class="original__bRMd">
<div>
<p>有 <code>n</code> 个城市，其中一些彼此相连，另一些没有相连。如果城市 <code>a</code> 与城市 <code>b</code> 直接相连，且城市 <code>b</code> 与城市 <code>c</code> 直接相连，那么城市 <code>a</code> 与城市 <code>c</code> 间接相连。</p>

<p><strong>省份</strong> 是一组直接或间接相连的城市，组内不含其他没有相连的城市。</p>

<p>给你一个 <code>n x n</code> 的矩阵 <code>isConnected</code> ，其中 <code>isConnected[i][j] = 1</code> 表示第 <code>i</code> 个城市和第 <code>j</code> 个城市直接相连，而 <code>isConnected[i][j] = 0</code> 表示二者不直接相连。</p>

<p>返回矩阵中 <strong>省份</strong> 的数量。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/24/graph1.jpg" style="width: 222px; height: 142px;" />
<pre>
<strong>输入：</strong>isConnected = [[1,1,0],[1,1,0],[0,0,1]]
<strong>输出：</strong>2
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/24/graph2.jpg" style="width: 222px; height: 142px;" />
<pre>
<strong>输入：</strong>isConnected = [[1,0,0],[0,1,0],[0,0,1]]
<strong>输出：</strong>3
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 200</code></li>
	<li><code>n == isConnected.length</code></li>
	<li><code>n == isConnected[i].length</code></li>
	<li><code>isConnected[i][j]</code> 为 <code>1</code> 或 <code>0</code></li>
	<li><code>isConnected[i][i] == 1</code></li>
	<li><code>isConnected[i][j] == isConnected[j][i]</code></li>
</ul>
</div>
</div>


    
## 方法一：BFS求图的连通分量

这道题其实挺裸的，就是让求一个图的连通分量。

题目中，已经给了图的邻接矩阵，我们直接对图开始搜索就好。

初始时，建立一个布尔类型的数组，数组长度为节点个数（$len(isConnected)$），初始值全为$false$

然后使用一个整数类型的变量$ans$来记录找到的联通分量的个数，初始值为$0$

**具体思路**是：我们遍历这$n$个节点，一旦遍历到某个节点，就把与这个节点相联通的所有的节点遍历一遍，并把答案数量加一。

遍历过程中，一个节点不论是怎么怎么遍历到的，都需要把布尔数组中这个节点对应的布尔值标记为$true$（表示该点已遍历）

+ 时间复杂度$O(len(isConnected)^2)$。每个节点都会被遍历一次，这个节点与其他节点的所有“连接情况”也会被遍历一次
+ 空间复杂度$O(len(isConnected))$

### AC代码

#### C++

```cpp
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                queue<int> q;
                q.push(i);
                ans++;
                while (q.size()) {
                    int thisNode = q.front();
                    q.pop();
                    for (int to = 0; to < n; to++) {
                        if (isConnected[thisNode][to] && !visited[to]) {
                            visited[to] = true;
                            q.push(to);
                        }
                    }
                }
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/12/13/LeetCode%200547.%E7%9C%81%E4%BB%BD%E6%95%B0%E9%87%8F/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128304781](https://letmefly.blog.csdn.net/article/details/128304781)
