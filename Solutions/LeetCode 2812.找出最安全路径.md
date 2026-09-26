---
title: 2812.找出最安全路径：两次BFS(先进先出队列+优先队列)
date: 2026-07-03 11:00:37
tags: [题解, LeetCode, 中等, 广度优先搜索, BFS, 并查集, 数组, 二分查找, 矩阵, 堆（优先队列）]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.com/uploads/2023/07/02/example3.png
---

# 【LetMeFly】2812.找出最安全路径：两次BFS(先进先出队列+优先队列)

力扣题目链接：[https://leetcode.cn/problems/find-the-safest-path-in-a-grid/](https://leetcode.cn/problems/find-the-safest-path-in-a-grid/)

<p>给你一个下标从 <strong>0</strong> 开始、大小为 <code>n x n</code> 的二维矩阵 <code>grid</code> ，其中 <code>(r, c)</code> 表示：</p>

<ul>
	<li>如果 <code>grid[r][c] = 1</code> ，则表示一个存在小偷的单元格</li>
	<li>如果 <code>grid[r][c] = 0</code> ，则表示一个空单元格</li>
</ul>

<p>你最开始位于单元格 <code>(0, 0)</code> 。在一步移动中，你可以移动到矩阵中的任一相邻单元格，包括存在小偷的单元格。</p>

<p>矩阵中路径的 <strong>安全系数</strong> 定义为：从路径中任一单元格到矩阵中任一小偷所在单元格的 <strong>最小</strong> 曼哈顿距离。</p>

<p>返回所有通向单元格<em> </em><code>(n - 1, n - 1)</code> 的路径中的 <strong>最大安全系数</strong> 。</p>

<p>单元格 <code>(r, c)</code> 的某个 <strong>相邻</strong> 单元格，是指在矩阵中存在的 <code>(r, c + 1)</code>、<code>(r, c - 1)</code>、<code>(r + 1, c)</code> 和 <code>(r - 1, c)</code> 之一。</p>

<p>两个单元格 <code>(a, b)</code> 和 <code>(x, y)</code> 之间的 <strong>曼哈顿距离</strong> 等于 <code>| a - x | + | b - y |</code> ，其中 <code>|val|</code> 表示 <code>val</code> 的绝对值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/07/02/example1.png" style="width: 362px; height: 242px;" />
<pre>
<strong>输入：</strong>grid = [[1,0,0],[0,0,0],[0,0,1]]
<strong>输出：</strong>0
<strong>解释：</strong>从 (0, 0) 到 (n - 1, n - 1) 的每条路径都经过存在小偷的单元格 (0, 0) 和 (n - 1, n - 1) 。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/07/02/example2.png" style="width: 362px; height: 242px;" />
<pre>
<strong>输入：</strong>grid = [[0,0,1],[0,0,0],[0,0,0]]
<strong>输出：</strong>2
<strong>解释：</strong>
上图所示路径的安全系数为 2：
- 该路径上距离小偷所在单元格（0，2）最近的单元格是（0，0）。它们之间的曼哈顿距离为 | 0 - 0 | + | 0 - 2 | = 2 。
可以证明，不存在安全系数更高的其他路径。
</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/07/02/example3.png" style="width: 362px; height: 242px;" />
<pre>
<strong>输入：</strong>grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
<strong>输出：</strong>2
<strong>解释：</strong>
上图所示路径的安全系数为 2：
- 该路径上距离小偷所在单元格（0，3）最近的单元格是（1，2）。它们之间的曼哈顿距离为 | 0 - 1 | + | 3 - 2 | = 2 。
- 该路径上距离小偷所在单元格（3，0）最近的单元格是（3，2）。它们之间的曼哈顿距离为 | 3 - 3 | + | 0 - 2 | = 2 。
可以证明，不存在安全系数更高的其他路径。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= grid.length == n &lt;= 400</code></li>
	<li><code>grid[i].length == n</code></li>
	<li><code>grid[i][j]</code> 为 <code>0</code> 或 <code>1</code></li>
	<li><code>grid</code> 至少存在一个小偷</li>
</ul>


    
## 解题方法：两次广度优先搜索

初始时候我们只知道哪里有小偷，但不知道每个单元格的*安全系数*。我们可以通过一次广度优先搜索得到每个单元格的*安全系数*：

> 使用一个先入先出队列，初始时将所有小偷单元格入队，接着在队列非空时不断出队。
> 
> 对于出队的单元格，若其上下左右四个相邻单元格还没有入队过，则入队，并更新相邻单元格的*安全系数*为当前出队单元格的$安全系数+1$。
> 
> 队列为空则说明已经求得所有单元格的*安全系数*

知道了每个单元格的*安全系数*，剩下的就是求从起点(左上角)到终点(右下角)的**尽可能走大安全系数**的路径中的最小单元格是多少：

> 由于路径可以上下左右到出走，所以我们不能简单地DP遍历。一旦在到达终点前我们*不得不*走了某小安全系数的单元格，那么以后大于等于这个最小安全系数的单元格就能肆无忌惮地走了。
> 
> 因此可以使用一个优先队列再从起点开始进行一次广度优先搜索，每次出队时更新答案(所经过单元格的最小值)，若出队单元格是终点则直接返回。否则上下左右四个相邻单元格中未遍历过的单元格入队，并按*安全系数*大的优先为依据优先出队。

+ 时间复杂度$O(n^2\log n)$，因为$O(\log n^2)=O(2\log n)=O(\log n)$
+ 空间复杂度$O(n^2)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-07-01 22:58:28
 */
#define debug_(x) {cout << #x << ":" << endl; debug(x);}

typedef pair<int, int> pii;
class Solution {
private:
    vector<vector<int>> dis;
    static constexpr int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void genDis(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pii> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        dis = vector<vector<int>>(n, vector<int>(m));
        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + directions[d][0];
                int ny = y + directions[d][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny <m && !visited[nx][ny]) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                    dis[nx][ny] = dis[x][y] + 1;
                }
            }
        }
    }

    int dfs() {
        int n = dis.size(), m = dis[0].size();
        auto cmp = [this](const pii& a, const pii& b) {
            return dis[a.first][a.second] < dis[b.first][b.second];
        };
        priority_queue<pii, vector<pii>, decltype(cmp)> q(cmp);
        vector<vector<bool>> visited(n, vector<bool>(m));
        int ans = min(dis[0][0], dis[n - 1][m - 1]);
        q.push({0, 0});
        visited[0][0] = true;
        if (n == 1 && m == 1) {
            return ans;
        }
        
        while (q.size()) {
            auto [x, y] = q.top();
            q.pop();
            ans = min(ans, dis[x][y]);
            for (int d = 0; d < 4; d++) {
                int nx = x + directions[d][0];
                int ny = y + directions[d][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                    if (nx == n - 1 && ny == m - 1) {
                        return ans;
                    }
                }
            }
        }
        return ans;
    }
    
    void debug(vector<vector<int>>& v) {
        int n = v.size(), m = v[0].size();
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                cout << "[[";
            } else {
                cout << " [";
            }

            for (int j = 0; j < m; j++) {
                if (j) {
                    cout << ", ";
                }
                cout << v[i][j];
            }

            if (i == n - 1) {
                cout << "]]";
            } else {
                cout << "],";
            }
            puts("");
        }
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        genDis(grid);
        return dfs();
    }
};

// 忽然发现其实m=n
```

#### Python

```python
'''
LastEditTime: 2026-07-03 10:59:07
'''
from typing import List
from collections import deque
import heapq

class Solution:
    def __init__(self) -> None:
        self.directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]
    
    def genDis(self, grid: List[List[int]]):
        n, m = len(grid), len(grid[0])
        dis = [[-1] * m for _ in range(n)]
        q = deque()
        for i, row in enumerate(grid):
            for j, v in enumerate(row):
                if v:
                    q.append((i, j))
                    dis[i][j] = 0
        
        while q:
            x, y = q.popleft()
            for dx, dy in self.directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < n and 0 <= ny < m and dis[nx][ny] == -1:
                    q.append((nx, ny))
                    dis[nx][ny] = dis[x][y] + 1
        self.dis = dis

    def dfs(self) -> int:
        n, m = len(self.dis), len(self.dis[0])
        visited = [[False] * m for _ in range(n)]
        pq = [(-self.dis[0][0], 0, 0)]
        visited[0][0] = True
        ans = self.dis[0][0]
        
        while pq:
            dis, x, y = heapq.heappop(pq)
            dis = -dis
            ans = min(ans, dis)
            if x == n - 1 and y == m - 1:
                return ans
            for dx, dy in self.directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < n and 0 <= ny < m and not visited[nx][ny]:
                    visited[nx][ny] = True
                    heapq.heappush(pq, (-self.dis[nx][ny], nx, ny))

    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        self.genDis(grid)
        return self.dfs()
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/162545627)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/07/03/LeetCode%202812.%E6%89%BE%E5%87%BA%E6%9C%80%E5%AE%89%E5%85%A8%E8%B7%AF%E5%BE%84/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
