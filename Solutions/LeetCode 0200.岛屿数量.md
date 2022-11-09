---
title: 200.岛屿数量
date: 2022-08-18 09:58:08
tags: [题解, LeetCode, 中等, 深度优先搜索, 广度优先搜索, 并查集, 数组, 矩阵, BFS, 连通块]
---

# 【LetMeFly】200.岛屿数量

力扣题目链接：[https://leetcode.cn/problems/number-of-islands/](https://leetcode.cn/problems/number-of-islands/)

<p>给你一个由 <code>'1'</code>（陆地）和 <code>'0'</code>（水）组成的的二维网格，请你计算网格中岛屿的数量。</p>

<p>岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。</p>

<p>此外，你可以假设该网格的四条边均被水包围。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
<strong>输出：</strong>1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
<strong>输出：</strong>3
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 <= m, n <= 300</code></li>
	<li><code>grid[i][j]</code> 的值为 <code>'0'</code> 或 <code>'1'</code></li>
</ul>


    
## 方法一：BFS

用广度优先搜索遍历一遍地图，遇到为```'1'```的方块就从开始广搜，并把答案的“岛屿数量”+1

广搜过程中，把遍历到的岛屿标记为```'2'```

一些广搜题列表可参考[广度优先搜索题解专题](https://leetcode.letmefly.xyz/tags/%E5%B9%BF%E5%BA%A6%E4%BC%98%E5%85%88%E6%90%9C%E7%B4%A2/)，该专题主要包括图的广搜和二叉树的广搜。

+ 时间复杂度$O(nm)$，其中地图的大小为$n\times m$
+ 空间复杂度$O(M)$，其中$M$是最大的岛屿面积

### AC代码

#### C++

```cpp
int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
private:
public:
    int numIslands(vector<vector<char>>& grid) {  // '2'表示遍历过的岛屿
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    grid[i][j] = '2';
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (q.size()) {
                        auto[x, y] = q.front();
                        q.pop();
                        for (int d = 0; d < 4; d++) {
                            int tx = x + direction[d][0];
                            int ty = y + direction[d][1];
                            if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
                                if (grid[tx][ty] == '1') {
                                    grid[tx][ty] = '2';
                                    q.push({tx, ty});
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/08/18/LeetCode%200200.%E5%B2%9B%E5%B1%BF%E6%95%B0%E9%87%8F/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126400354](https://letmefly.blog.csdn.net/article/details/126400354)
