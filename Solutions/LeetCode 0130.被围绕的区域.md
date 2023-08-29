---
title: 130.被围绕的区域
date: 2022-07-22 11:43:53
tags: [题解, LeetCode, 中等, 深度优先搜索, 广度优先搜索, 并查集, 数组, 矩阵, BFS]
---

# 【LetMeFly】130.被围绕的区域 - BFS：标记没有被围绕的区域

力扣题目链接：[https://leetcode.cn/problems/surrounded-regions/](https://leetcode.cn/problems/surrounded-regions/)

给你一个 <code>m x n</code> 的矩阵 <code>board</code> ，由若干字符 <code>'X'</code> 和 <code>'O'</code> ，找到所有被 <code>'X'</code> 围绕的区域，并将这些区域里所有的 <code>'O'</code> 用 <code>'X'</code> 填充。
<div class="original__bRMd">
<div>
<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/bb5e87df3a6844b2bc0edd142ac65d90.jpeg" style="width: 550px; height: 237px;" />
<pre>
<strong>输入：</strong>board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
<strong>输出：</strong>[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
<strong>解释：</strong>被围绕的区间不会存在于边界上，换句话说，任何边界上的 <code>'O'</code> 都不会被填充为 <code>'X'</code>。 任何不在边界上，或不与边界上的 <code>'O'</code> 相连的 <code>'O'</code> 最终都会被填充为 <code>'X'</code>。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>board = [["X"]]
<strong>输出：</strong>[["X"]]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == board.length</code></li>
	<li><code>n == board[i].length</code></li>
	<li><code>1 <= m, n <= 200</code></li>
	<li><code>board[i][j]</code> 为 <code>'X'</code> 或 <code>'O'</code></li>
</ul>
</div>
</div>


    
## 方法一：BFS：标记没有被围绕的区域

这道题是让“被```X```包围的```O```”变成```X```。

不如换个思考角度：

我们可以很容易地求出“没有被```X```包围的```O```”（从四条边开始搜素即可）

然后把“没有被```X```包围的```O```”标记一下，之后再遍历一遍原始矩阵，把所有没有被标记过的```O```变成```X```即可

+ 时间复杂度$O(nm)$，其中$board$的```size```为$n\times m$
+ 空间复杂度$O(nm)$

### AC代码

#### C++

```cpp
typedef pair<int, int> pii;
const int directions[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

class Solution {
private:
    vector<vector<bool>> isnot;  // true：不是被包围的O   false：(还)未被认定为“不是被包围的O”
    int n, m;

    void extend(int x, int y, vector<vector<char>>& a) {
        if (a[x][y] == 'O' && !isnot[x][y]) {
            queue<pii> q;
            isnot[x][y] = true;
            q.push({x, y});
            while (q.size()) {
                auto[x, y] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int tx = x + directions[d][0];
                    int ty = y + directions[d][1];
                    if (tx >=0 && tx < n && ty >= 0 && ty < m) {
                        if (a[tx][ty] == 'O' && !isnot[tx][ty]) {
                            isnot[tx][ty] = true;
                            q.push({tx, ty});
                        }
                    }
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        n = board.size(), m = board[0].size();
        isnot = vector<vector<bool>>(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            extend(i, 0, board);
            extend(i, m - 1, board);
        }
        for (int j = 0; j < m; j++) {
            extend(0, j, board);
            extend(n - 1, j, board);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !isnot[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/07/22/LeetCode%200130.%E8%A2%AB%E5%9B%B4%E7%BB%95%E7%9A%84%E5%8C%BA%E5%9F%9F/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125929415](https://letmefly.blog.csdn.net/article/details/125929415)
