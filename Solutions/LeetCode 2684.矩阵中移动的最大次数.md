---
title: 2684.矩阵中移动的最大次数
date: 2024-03-16 09:51:19
tags: [题解, LeetCode, 中等, 数组, 动态规划, 矩阵, 广度优先搜索, BFS, 哈希表, 哈希, set]
categories: [题解, LeetCode]
---

# 【LetMeFly】2684.矩阵中移动的最大次数：一列一列处理，只记能到哪行(BFS)

力扣题目链接：[https://leetcode.cn/problems/maximum-number-of-moves-in-a-grid/](https://leetcode.cn/problems/maximum-number-of-moves-in-a-grid/)

<p>给你一个下标从 <strong>0</strong> 开始、大小为 <code>m x n</code> 的矩阵 <code>grid</code> ，矩阵由若干 <strong>正</strong> 整数组成。</p>

<p>你可以从矩阵第一列中的 <strong>任一</strong> 单元格出发，按以下方式遍历&nbsp;<code>grid</code> ：</p>

<ul>
	<li>从单元格 <code>(row, col)</code> 可以移动到&nbsp;<code>(row - 1, col + 1)</code>、<code>(row, col + 1)</code> 和 <code>(row + 1, col + 1)</code> 三个单元格中任一满足值 <strong>严格</strong> 大于当前单元格的单元格。</li>
</ul>

<p>返回你在矩阵中能够 <strong>移动</strong> 的 <strong>最大</strong> 次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/04/11/yetgriddrawio-10.png" style="width: 201px; height: 201px;">
<pre><strong>输入：</strong>grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]
<strong>输出：</strong>3
<strong>解释：</strong>可以从单元格 (0, 0) 开始并且按下面的路径移动：
- (0, 0) -&gt; (0, 1).
- (0, 1) -&gt; (1, 2).
- (1, 2) -&gt; (2, 3).
可以证明这是能够移动的最大次数。</pre>

<p><strong>示例 2：</strong></p>

<pre><img alt="" src="https://assets.leetcode.com/uploads/2023/04/12/yetgrid4drawio.png">
<strong>输入：</strong>grid = [[3,2,4],[2,1,9],[1,1,7]]
<strong>输出：</strong>0
<strong>解释：</strong>从第一列的任一单元格开始都无法移动。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>2 &lt;= m, n &lt;= 1000</code></li>
	<li><code>4 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 10<sup>6</sup></code></li>
</ul>


    
## 方法一：一列一列处理，只记能到哪行(BFS + 哈希表set)

不难发现移动的方法有三：↗→↘。不论是哪种移动方式，每移动一步就要往右一列。

因此我们使用一个哈希表记录当前列都能到达哪些位置，由当前列能到达的所有位置获得下一列能到达的所有位置，直到到达最右边一列或无位置可达。

所达到的最远列数即为答案（下标从0开始的话）。

+ 时间复杂度$O(nm)$，其中$grid$有$n$行$m$列。
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        unordered_set<int> can;
        for (int i = 0; i < grid.size(); i++) {
            can.insert(i);
        }
        int ans = 0;
        while (can.size()) {
            ans++;
            if (ans == grid[0].size()) {
                break;
            }
            unordered_set<int> nextCan;
            for (int row : can) {
                for (int j = -1; j <= 1; j++) {
                    if (row + j >= 0 && row + j < grid.size() && grid[row + j][ans] > grid[row][ans - 1]) {
                        nextCan.insert(row + j);
                    }
                }
            }
            swap(can, nextCan);
        }
        return --ans;
    }
};
```

#### Python

```python
from typing import List

class Solution:  # AC,80.00%,92.59%
    def maxMoves(self, grid: List[List[int]]) -> int:
        can = set(i for i in range(len(grid)))
        ans = 0
        while can:
            ans += 1
            if ans == len(grid[0]):
                break
            nextCan = set()
            for row in can:
                for j in range(-1, 2):
                    if row + j >= 0 and row + j < len(grid) and grid[row + j][ans] > grid[row][ans - 1]:
                        nextCan.add(row + j)
            can = nextCan
        return ans - 1
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/03/16/LeetCode%202684.%E7%9F%A9%E9%98%B5%E4%B8%AD%E7%A7%BB%E5%8A%A8%E7%9A%84%E6%9C%80%E5%A4%A7%E6%AC%A1%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136757373](https://letmefly.blog.csdn.net/article/details/136757373)
