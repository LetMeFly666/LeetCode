---
title: 463.岛屿的周长
date: 2022-10-25 12:13:17
tags: [题解, LeetCode, 简单, 深度优先搜索, 广度优先搜索, BFS, 数组, 矩阵]
---

# 【LetMeFly】463.岛屿的周长

力扣题目链接：[https://leetcode.cn/problems/island-perimeter/](https://leetcode.cn/problems/island-perimeter/)

<p>给定一个 <code>row x col</code> 的二维网格地图 <code>grid</code> ，其中：<code>grid[i][j] = 1</code> 表示陆地， <code>grid[i][j] = 0</code> 表示水域。</p>

<p>网格中的格子 <strong>水平和垂直</strong> 方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。</p>

<p>岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<!-- <p><img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/island.png" /></p> -->
<!-- <p><img src="https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/f66f804f1ab649d1a26cbc44e44aeee3~tplv-k3u1fbpfcp-zoom-1.image" alt="掘金图源"/></p> -->
<p><img src="https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/eb11a3cbad234923a14025b3e03f838d.png" /></p>


<pre>
<strong>输入：</strong>grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
<strong>输出：</strong>16
<strong>解释：</strong>它的周长是上面图片中的 16 个黄色的边</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>grid = [[1]]
<strong>输出：</strong>4
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>grid = [[1,0]]
<strong>输出：</strong>4
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
    <li><code>row == grid.length</code></li>
    <li><code>col == grid[i].length</code></li>
    <li><code>1 <= row, col <= 100</code></li>
    <li><code>grid[i][j]</code> 为 <code>0</code> 或 <code>1</code></li>
</ul>


    
## 方法一：广搜

要知道：

> 每个“1”能提供$4$条边，如果其相邻有个“1”，那么其提供的边数就要少一条。

因此，我们只需要从任意一个“1”开始进行广搜，搜到一个**新**的“1”答案边数就加4

同时，搜到一个“1”（不管是否被搜到过）就将答案边数减1

**框架：**

```cpp
int islandPerimeter(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j]) {
                /*
                    找到一个1，决定从这个1开始进行广搜
                    // 这里是广搜部分
                */
                goto loop;
            }
        }
    }
    loop:;
    return ans;
}
```

**广搜部分：**

```cpp
queue<pii> q;
grid[i][j] = -1;
q.push({i, j});
ans += 4;
while (q.size()) {
    pii thisNode = q.front();
    q.pop();
    for (int d = 0; d < 4; d++) {
        int tx = thisNode.first + directions[d][0];
        int ty = thisNode.second + directions[d][1];
        if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
            if (grid[tx][ty]) {
                ans--;
                // dbg(ans);  //********
                if (grid[tx][ty] == 1) {
                    grid[tx][ty] = -1;
                    q.push({tx, ty});
                    ans += 4;
                }
            }
        }
    }
}
```

+ 时间复杂度$O(n\times m)$，其中地图大小为$n\times m$
+ 空间复杂度$O(n\times m)$

### AC代码

#### C++

```cpp
typedef pair<int, int> pii;
const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    queue<pii> q;
                    grid[i][j] = -1;
                    q.push({i, j});
                    ans += 4;
                    while (q.size()) {
                        pii thisNode = q.front();
                        q.pop();
                        for (int d = 0; d < 4; d++) {
                            int tx = thisNode.first + directions[d][0];
                            int ty = thisNode.second + directions[d][1];
                            if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
                                if (grid[tx][ty]) {
                                    ans--;
                                    // dbg(ans);  //********
                                    if (grid[tx][ty] == 1) {
                                        grid[tx][ty] = -1;
                                        q.push({tx, ty});
                                        ans += 4;
                                    }
                                }
                            }
                        }
                    }

                    goto loop;
                }
            }
        }
        loop:;
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/10/25/LeetCode%200463.%E5%B2%9B%E5%B1%BF%E7%9A%84%E5%91%A8%E9%95%BF/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127510967](https://letmefly.blog.csdn.net/article/details/127510967)
