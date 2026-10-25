---
title: 1254.统计封闭岛屿的数目：广度优先搜索BFS
date: 2023-06-18 13:53:56
tags: [题解, LeetCode, 中等, 深度优先搜索, 广度优先搜索, BFS, 并查集, 数组, 矩阵, 图]
categories: [题解, LeetCode]
---

# 【LetMeFly】1254.统计封闭岛屿的数目：广度优先搜索BFS

力扣题目链接：[https://leetcode.cn/problems/number-of-closed-islands/](https://leetcode.cn/problems/number-of-closed-islands/)

<p>二维矩阵 <code>grid</code>&nbsp;由 <code>0</code>&nbsp;（土地）和 <code>1</code>&nbsp;（水）组成。岛是由最大的4个方向连通的 <code>0</code>&nbsp;组成的群，封闭岛是一个&nbsp;<code>完全</code> 由1包围（左、上、右、下）的岛。</p>

<p>请返回 <em>封闭岛屿</em> 的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/10/31/sample_3_1610.png" style="height: 151px; width: 240px;" /></p>

<pre>
<strong>输入：</strong>grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
<strong>输出：</strong>2
<strong>解释：</strong>
灰色区域的岛屿是封闭岛屿，因为这座岛屿完全被水域包围（即被 1 区域包围）。</pre>

<p><strong>示例 2：</strong></p>

<p><img src="https://assets.leetcode.cn/aliyun-lc-upload/uploads/2019/11/07/sample_4_1610.png" style="height: 98px; width: 160px;" /></p>

<pre>
<strong>输入：</strong>grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
<strong>输出：</strong>1
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>grid = [[1,1,1,1,1,1,1],
&nbsp;            [1,0,0,0,0,0,1],
&nbsp;            [1,0,1,1,1,0,1],
&nbsp;            [1,0,1,0,1,0,1],
&nbsp;            [1,0,1,1,1,0,1],
&nbsp;            [1,0,0,0,0,0,1],
             [1,1,1,1,1,1,1]]
<strong>输出：</strong>2
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= grid.length, grid[0].length &lt;= 100</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;=1</code></li>
</ul>


    
## 方法一：BFS，先四周后中间

首先我们写一个BFS函数，从一个“0”开始广搜，将与之相连的所有“0”全部标记为“1”。

这样，我们只需要首先遍历给定地图的四周，将与四周相连的“0”送入BFS函数并标记为“1”，

接着遍历中间的“0”，将中间相邻的“0”标记为“1”的同时，记录下标记次数即为“封闭岛屿”的个数。

+ 时间复杂度$O(n\times m)$，其中$size(grid)=n\times m$
+ 空间复杂度$O(n\times m)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2023-06-18 13:32:17
 */
typedef pair<int, int> pii;

const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
private:
    void mark(vector<vector<int>>& grid, int x, int y) {
        queue<pii> q;
        q.push({x, y});
        grid[x][y] = 1;
        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int tx = x + directions[d][0];
                int ty = y + directions[d][1];
                if (tx >= 0 && tx < grid.size() && ty >= 0 && ty < grid[0].size() && grid[tx][ty] == 0) {
                    q.push({tx, ty});
                    grid[tx][ty] = 1;
                }
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        // 四周的0视为1
        for (int i = 0; i < grid.size(); i++) {
            if (grid[i][0] == 0) {
                mark(grid, i, 0);
            }
            if (grid[i][grid[0].size() - 1] == 0) {
                mark(grid, i, grid[0].size() - 1);
            }
        }
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[0][j] == 0) {
                mark(grid, 0, j);
            }
            if (grid[grid.size() - 1][j] == 0) {
                mark(grid, grid.size() - 1, j);
            }
        }
        // 统计中间岛屿数量
        int ans = 0;
        for (int i = 1; i < grid.size() - 1; i++) {
            for (int j = 1; j < grid[0].size() - 1; j++) {
                if (grid[i][j] == 0) {
                    mark(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
```

#### Python

```python
'''
LastEditTime: 2023-06-18 13:52:12
'''
# from typing import List


directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]

class Solution:
    def mark(self, grid: List[List[int]], x, y) -> None:
        q = []
        grid[x][y] = 1
        q.append((x, y))
        while q:
            x, y = q.pop()
            for dx, dy in directions:
                tx = dx + x
                ty = dy + y
                if 0 <= tx < len(grid) and 0 <= ty < len(grid[0]) and grid[tx][ty] == 0:
                    grid[tx][ty] = 1
                    q.append((tx, ty))
        
    def closedIsland(self, grid: List[List[int]]) -> int:
        for i in range(len(grid)):
            if grid[i][0] == 0:
                self.mark(grid, i, 0)
            if grid[i][-1] == 0:
                self.mark(grid, i, len(grid[0]) - 1)
        for j in range(len(grid[0])):
            if grid[0][j] == 0:
                self.mark(grid, 0, j)
            if grid[-1][j] == 0:
                self.mark(grid, len(grid) - 1, j)
        
        ans = 0
        for i in range(1, len(grid) - 1):
            for j in range(1, len(grid[0]) - 1):
                if grid[i][j] == 0:
                    self.mark(grid, i, j)
                    ans += 1
        return ans
```

#### C++

```cpp
/*
 * @LastEditTime: 2026-10-25 09:17:30
 */
class Solution {
private:
    int n, m;
    static constexpr int dirs[][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

    bool isCenter(int i, int j) {  // 是否不是四周这一圈
        return i && i != n - 1 && j && j != m - 1;
    }

    bool inGrid(int i, int j) {
        return i >= 0 && i < n && j >=0 && j < m;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    continue;
                }
                // 新土地
                grid[i][j] = 1;
                bool ok = isCenter(i, j);
                queue<pair<int, int>> q;
                q.push({i, j});
                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    for (auto[dx, dy] : dirs) {
                        int nx = x + dx, ny = y + dy;
                        if (!inGrid(nx, ny) || grid[nx][ny]) {
                            continue;
                        }
                        grid[nx][ny] = 1;
                        ok &= isCenter(nx, ny);
                        q.push({nx, ny});
                    }
                }
                ans += ok;
            }
        }
        return ans;
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-10-25 09:24:54
'''
from typing import List

dirs = [[0, 1], [0, -1], [1, 0], [-1, 0]]

class Solution:
    def isCenter(self, i: int, j: int) -> bool:
        return 0 < i < self.n - 1 and 0 < j < self.m - 1
    
    def inGrid(self, i: int, j: int) -> bool:
        return 0 <= i < self.n and 0 <= j < self.m
    
    def closedIsland(self, grid: List[List[int]]) -> int:
        self.n = len(grid)
        self.m = len(grid[0])
        ans = 0
        for i, line in enumerate(grid):
            for j, v in enumerate(line):
                if v:
                    continue
                grid[i][j] = 1
                ok = self.isCenter(i, j)
                q = [(i, j)]
                while q:
                    x, y = q.pop()
                    for dx, dy in dirs:
                        nx, ny = x + dx, y + dy
                        if not self.inGrid(nx, ny) or grid[nx][ny]:
                            continue
                        grid[nx][ny] = 1
                        ok &= self.isCenter(nx, ny)
                        q.append((nx, ny))
                ans += ok
        return ans
```

#### Java

```java
/*
 * @LastEditTime: 2026-10-25 12:56:37
 */
import java.util.Queue;
import java.util.LinkedList;

class Solution {
    private int n, m;
    private final int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    private boolean isCenter(int i, int j) {
        return 0 < i && i < n - 1 && 0 < j && j < m - 1;
    }

    private boolean inGrid(int i, int j) {
        return 0 <= i && i < n && 0 <= j && j < m;
    }

    public int closedIsland(int[][] grid) {
        n = grid.length;
        m = grid[0].length;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    continue;
                }
                grid[i][j] = 1;
                boolean ok = isCenter(i, j);
                Queue<int[]> q = new LinkedList<>();
                q.offer(new int[]{i, j});
                while (!q.isEmpty()) {
                    int[] top = q.poll();
                    int x = top[0], y = top[1];
                    for (int[] d : dirs) {
                        int nx = x + d[0], ny = y + d[1];
                        if (!inGrid(nx, ny) || grid[nx][ny] == 1) {
                            continue;
                        }
                        grid[nx][ny] = 1;
                        ok &= isCenter(nx, ny);
                        q.offer(new int[]{nx, ny});
                    }
                }
                if (ok) {
                    ans++;
                }
            }
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2026-10-25 12:16:55
 */
package main

func isCenter1254(i, j, n, m int) bool {
    return 0 < i && i < n - 1 && 0 < j && j < m - 1
}

func inGrid1254(i, j, n, m int) bool {
    return 0 <= i && i < n && 0 <= j && j < m
}

var dirs1254 = [4][2]int{{0, -1}, {0, 1}, {1, 0}, {-1, 0}}

func closedIsland(grid [][]int) (ans int) {
    n, m := len(grid), len(grid[0])
    for i, line := range grid {
        for j, v := range line {
            if v == 1 {
                continue
            }
            ok := isCenter1254(i, j, n, m)
            grid[i][j] = 1
            q := [][2]int{{i, j}}
            for len(q) > 0 {
                top := q[len(q) - 1]
                q = q[:len(q) - 1]
                x, y := top[0], top[1]
                for _, d := range dirs1254 {
                    nx, ny := x + d[0], y + d[1]
                    if !inGrid1254(nx, ny, n, m) || grid[nx][ny] == 1 {
                        continue
                    }
                    grid[nx][ny] = 1
                    ok = ok && isCenter1254(nx, ny, n, m)  // go没有bool的&
                    q = append(q, [2]int{nx, ny})
                }
            }
            if ok {
                ans++
            }
        }
    }
    return
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-10-25 16:19:59
 */
use std::collections::VecDeque;

impl Solution {
    const DIRS: [(isize, isize); 4] = [(-1, 0), (1, 0), (0, 1), (0, -1)];  // 注意防止usize到-1

    fn is_center(i: usize, j: usize, n: usize, m: usize) -> bool {
        0 < i && i < n - 1 && 0 < j && j < m - 1
    }

    fn in_grid(i: isize, j: isize, n: usize, m: usize) -> bool {
        0 <= i && i < n as isize && 0 <= j && j < m as isize
    }

    pub fn closed_island(mut grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let m = grid[0].len();
        let mut ans = 0;
        for i in 0..n {
            for j in 0..m {
                if grid[i][j] == 1 {
                    continue;
                }
                grid[i][j] = 1;
                let mut ok = Self::is_center(i, j, n, m);
                let mut q = VecDeque::new();
                q.push_back((i, j));
                while let Some((x, y)) = q.pop_front() {
                    for &(dx, dy) in &Self::DIRS {
                        let nx = x as isize + dx;
                        let ny = y as isize + dy;
                        if !Self::in_grid(nx, ny, n, m){
                            continue;
                        }
                        let (nx, ny) = (nx as usize, ny as usize);
                        if grid[nx][ny] == 1 {
                            continue;
                        }
                        grid[nx][ny] = 1;
                        ok &= Self::is_center(nx, ny, n, m);
                        q.push_back((nx, ny));
                    }
                }
                ans += if ok {
                    1
                } else {
                    0
                }
            }
        }
        ans
    }
}
```

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/--------------------------)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/10/25/LeetCode%201254.%E7%BB%9F%E8%AE%A1%E5%B0%81%E9%97%AD%E5%B2%9B%E5%B1%BF%E7%9A%84%E6%95%B0%E7%9B%AE/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)


> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/06/18/LeetCode%201254.%E7%BB%9F%E8%AE%A1%E5%B0%81%E9%97%AD%E5%B2%9B%E5%B1%BF%E7%9A%84%E6%95%B0%E7%9B%AE/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131270866](https://letmefly.blog.csdn.net/article/details/131270866)
