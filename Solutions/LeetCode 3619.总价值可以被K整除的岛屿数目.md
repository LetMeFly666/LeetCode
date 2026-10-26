---
title: 3619.总价值可以被 K 整除的岛屿数目：广度优先搜索BFS
date: 2026-10-26 22:06:27
tags: [题解, LeetCode, 中等, 深度优先搜索, 广度优先搜索, BFS, 并查集, 数组, 矩阵]
categories: [题解, LeetCode]
index_img: https://files.letmefly.xyz/d/n/leetcode/3619-example1griddrawio-1.png
---

# 【LetMeFly】3619.总价值可以被 K 整除的岛屿数目：广度优先搜索BFS

力扣题目链接：[https://leetcode.cn/problems/count-islands-with-total-value-divisible-by-k/](https://leetcode.cn/problems/count-islands-with-total-value-divisible-by-k/)

<p>给你一个 <code>m x n</code> 的矩阵 <code>grid</code> 和一个正整数 <code>k</code>。一个&nbsp;<strong>岛屿&nbsp;</strong>是由&nbsp;<strong>正&nbsp;</strong>整数（表示陆地）组成的，并且陆地间&nbsp;<strong>四周&nbsp;</strong>连通（水平或垂直）。</p>

<p>一个岛屿的总价值是该岛屿中所有单元格的值之和。</p>

<p>返回总价值可以被 <code>k</code> <strong>整除&nbsp;</strong>的岛屿数量。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>
<img alt="" src="https://files.letmefly.xyz/d/n/leetcode/3619-example1griddrawio-1.png" style="width: 200px; height: 200px;" />
<div class="example-block">
<p><strong>输入:</strong> <span class="example-io">grid = [[0,2,1,0,0],[0,5,0,0,5],[0,0,1,0,0],[0,1,4,7,0],[0,2,0,0,8]], k = 5</span></p>

<p><strong>输出:</strong> <span class="example-io">2</span></p>

<p><strong>解释:</strong></p>

<p>网格中包含四个岛屿。蓝色高亮显示的岛屿的总价值可以被 5 整除，而红色高亮显示的岛屿则不能。</p>
</div>

<p><strong class="example">示例 2:</strong></p>
<img alt="" src="https://files.letmefly.xyz/d/n/leetcode/3619-example2griddrawio.png" style="width: 200px; height: 150px;" />
<div class="example-block">
<p><strong>输入:</strong> <span class="example-io">grid = [[3,0,3,0], [0,3,0,3], [3,0,3,0]], k = 3</span></p>

<p><strong>输出:</strong> <span class="example-io">6</span></p>

<p><strong>解释:</strong></p>

<p>网格中包含六个岛屿，每个岛屿的总价值都可以被 3 整除。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 1000</code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>6</sup></code></li>
</ul>


    
## 解题方法：广度优先搜索

遍历一遍矩阵，遇到非零单位则开始BFS。BFS的作用是：找出所有上下左右相邻非零单元格求和并将单元格置为0，最后返回总和是否能被k整除。

+ 时间复杂度$O(mn)$
+ 空间复杂度$O(mn)$

注意一个岛屿的总价值可能会超过32位int范围，所以某些编程语言可能需要使用如long long等的64位类型。

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-10-26 22:05:14
 */
typedef long long ll;
class Solution {
private:
    int n, m;
    static constexpr int dirs[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    bool inGrid(int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < m;
    }

    bool bfs(vector<vector<int>>& grid, int x, int y, int k) {
        ll cnt = grid[x][y];
        grid[x][y] = 0;
        queue<pair<int, int>> q;
        q.push({x, y});
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (inGrid(nx, ny) && grid[nx][ny]) {
                    cnt += grid[nx][ny];
                    grid[nx][ny] = 0;
                    q.push({nx, ny});
                }
            }
        }
        return cnt % k == 0;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    ans += bfs(grid, i, j, k);
                }
            }
        }
        return ans;
    }
};
```

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/169170261)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/10/26/LeetCode%203619.%E6%80%BB%E4%BB%B7%E5%80%BC%E5%8F%AF%E4%BB%A5%E8%A2%ABK%E6%95%B4%E9%99%A4%E7%9A%84%E5%B2%9B%E5%B1%BF%E6%95%B0%E7%9B%AE/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
