---
title: 2596.检查骑士巡视方案
date: 2023-09-13 10:27:36
tags: [题解, LeetCode, 中等, 深度优先搜索, 广度优先搜索, 数组, 矩阵, 模拟, 排序]
---

# 【LetMeFly】2596.检查骑士巡视方案

力扣题目链接：[https://leetcode.cn/problems/check-knight-tour-configuration/](https://leetcode.cn/problems/check-knight-tour-configuration/)

<p>骑士在一张 <code>n x n</code> 的棋盘上巡视。在有效的巡视方案中，骑士会从棋盘的 <strong>左上角</strong> 出发，并且访问棋盘上的每个格子 <strong>恰好一次</strong> 。</p>

<p>给你一个 <code>n x n</code> 的整数矩阵 <code>grid</code> ，由范围 <code>[0, n * n - 1]</code> 内的不同整数组成，其中 <code>grid[row][col]</code> 表示单元格 <code>(row, col)</code> 是骑士访问的第 <code>grid[row][col]</code> 个单元格。骑士的行动是从下标 <strong>0</strong> 开始的。</p>

<p>如果 <code>grid</code> 表示了骑士的有效巡视方案，返回 <code>true</code>；否则返回 <code>false</code>。</p>

<p><strong>注意</strong>，骑士行动时可以垂直移动两个格子且水平移动一个格子，或水平移动两个格子且垂直移动一个格子。下图展示了骑士从某个格子出发可能的八种行动路线。<br>
<img alt="" src="https://assets.leetcode.com/uploads/2018/10/12/knight.png" style="width: 300px; height: 300px;"></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/12/28/yetgriddrawio-5.png" style="width: 251px; height: 251px;">
<pre><strong>输入：</strong>grid = [[0,11,16,5,20],[17,4,19,10,15],[12,1,8,21,6],[3,18,23,14,9],[24,13,2,7,22]]
<strong>输出：</strong>true
<strong>解释：</strong>grid 如上图所示，可以证明这是一个有效的巡视方案。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/12/28/yetgriddrawio-6.png" style="width: 151px; height: 151px;">
<pre><strong>输入：</strong>grid = [[0,3,6],[5,8,1],[2,7,4]]
<strong>输出：</strong>false
<strong>解释：</strong>grid 如上图所示，考虑到骑士第 7 次行动后的位置，第 8 次行动是无效的。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == grid.length == grid[i].length</code></li>
	<li><code>3 &lt;= n &lt;= 7</code></li>
	<li><code>0 &lt;= grid[row][col] &lt; n * n</code></li>
	<li><code>grid</code> 中的所有整数 <strong>互不相同</strong></li>
</ul>


    
## 方法一：排序 + 模拟

创建一个indices数组，indices[i]代表第i步要跳到的位置（只需要遍历一遍grid数组即可完成indices数组）。

使用两个变量$nowX$和$nowY$，代表当前的位置。

遍历indices数组，如果下一个位置 和 当前位置不是“日”字型，则返回false。

最终返回true。

**细节描述：**

Q1: 如何确定相邻两个位置是否是日字型？

A1: 看“横坐标之差×纵坐标之差”是否等于2。

Q2: 如何优雅地判断骑士是否由“左上角”出发？特判grid[0][0]是否为0不够优雅。

A2: 初始位置可以设置为(-2, -1)，这样首个位置必须是(0, 0)才满足日字型。

+ 时间复杂度$O(n^2)$，其中$size(gird) = n\times n$
+ 空间复杂度$O(n^2)$

### AC代码

#### C++

```cpp
typedef pair<int, int> pii;
class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pii> indices(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                indices[grid[i][j]] = {i, j};
            }
        }
        int nowX = -2, nowY = -1;
        for (int i = 0; i < n * n; i++) {
            int nextX =indices[i].first, nextY = indices[i].second;
            if (abs(nowX - nextX) * abs(nowY - nextY) != 2) {
                return false;
            }
            nowX = nextX, nowY = nextY;
        }
        return true;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def checkValidGrid(self, grid: List[List[int]]) -> bool:
        n = len(grid)
        indices = [0] * n ** 2
        for i in range(n):
            for j in range(n):
                indices[grid[i][j]] = [i, j]
        nowX, nowY = -2, -1
        for i in range(n * n):
            nextX, nextY = indices[i]
            if abs(nextX - nowX) * abs(nextY - nowY) != 2:
                return False
            nowX, nowY = indices[i]
        return True
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/09/13/LeetCode%202596.%E6%A3%80%E6%9F%A5%E9%AA%91%E5%A3%AB%E5%B7%A1%E8%A7%86%E6%96%B9%E6%A1%88/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/132847346](https://letmefly.blog.csdn.net/article/details/132847346)
