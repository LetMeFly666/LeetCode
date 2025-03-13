---
title: 3242.设计相邻元素求和服务
date: 2024-11-11 23:54:29
tags: [题解, LeetCode, 简单, 设计, 数组, 哈希表, 哈希, map, 矩阵, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】3242.设计相邻元素求和服务：哈希表

力扣题目链接：[https://leetcode.cn/problems/design-neighbor-sum-service/](https://leetcode.cn/problems/design-neighbor-sum-service/)

<p>给你一个 <code>n x n</code> 的二维数组 <code>grid</code>，它包含范围 <code>[0, n<sup>2</sup> - 1]</code> 内的<strong>不重复</strong>元素。</p>

<p>实现 <code>neighborSum</code> 类：</p>

<ul>
	<li><code>neighborSum(int [][]grid)</code> 初始化对象。</li>
	<li><code>int adjacentSum(int value)</code> 返回在 <code>grid</code> 中与 <code>value</code> 相邻的元素之<strong>和</strong>，相邻指的是与 <code>value</code> 在上、左、右或下的元素。</li>
	<li><code>int diagonalSum(int value)</code> 返回在 <code>grid</code> 中与 <code>value</code> 对角线相邻的元素之<strong>和</strong>，对角线相邻指的是与 <code>value</code> 在左上、右上、左下或右下的元素。</li>
</ul>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/06/24/design.png" style="width: 400px; height: 248px;" /></p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong></p>

<p>["neighborSum", "adjacentSum", "adjacentSum", "diagonalSum", "diagonalSum"]</p>

<p>[[[[0, 1, 2], [3, 4, 5], [6, 7, 8]]], [1], [4], [4], [8]]</p>

<p><strong>输出：</strong> [null, 6, 16, 16, 4]</p>

<p><strong>解释：</strong></p>

<p><strong class="example"><img alt="" src="https://assets.leetcode.com/uploads/2024/06/24/designexample0.png" style="width: 250px; height: 249px;" /></strong></p>

<ul>
	<li>1 的相邻元素是 0、2 和 4。</li>
	<li>4 的相邻元素是 1、3、5 和 7。</li>
	<li>4 的对角线相邻元素是 0、2、6 和 8。</li>
	<li>8 的对角线相邻元素是 4。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong></p>

<p>["neighborSum", "adjacentSum", "diagonalSum"]</p>

<p>[[[[1, 2, 0, 3], [4, 7, 15, 6], [8, 9, 10, 11], [12, 13, 14, 5]]], [15], [9]]</p>

<p><strong>输出：</strong> [null, 23, 45]</p>

<p><strong>解释：</strong></p>

<p><strong class="example"><img alt="" src="https://assets.leetcode.com/uploads/2024/06/24/designexample2.png" style="width: 300px; height: 300px;" /></strong></p>

<ul>
	<li>15 的相邻元素是 0、10、7 和 6。</li>
	<li>9 的对角线相邻元素是 4、12、14 和 15。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= n == grid.length == grid[0].length &lt;= 10</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= n<sup>2</sup> - 1</code></li>
	<li>所有 <code>grid[i][j]</code> 值均不重复。</li>
	<li><code>adjacentSum</code> 和 <code>diagonalSum</code> 中的 <code>value</code> 均在范围 <code>[0, n<sup>2</sup> - 1]</code> 内。</li>
	<li>最多会调用 <code>adjacentSum</code> 和 <code>diagonalSum</code> 总共 <code>2 * n<sup>2</sup></code> 次。</li>
</ul>


    
## 解题方法：哈希表

使用哈希表记录每个值的adjacentSum和diagonalSum，查询操作的时候直接去哈希表里查询就可以了。

+ 时间复杂度：初始化$O(n^2)$单次查询$O(1)$
+ 空间复杂度：初始化$O(n^2)$单次查询$O(1)$

### AC代码

#### C++

```cpp
const int adj[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const int dia[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

class NeighborSum {
private:
    vector<pair<int, int>> cache;
public:
    NeighborSum(vector<vector<int>>& grid) {
        int n = grid.size();
        cache.resize(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int cntAdj = 0, cntDia = 0;
                for (int k = 0; k < 4; k++) {
                    int x = i + adj[k][0], y = j + adj[k][1];
                    if (x >= 0 && x < n && y >= 0 && y < n) {
                        cntAdj += grid[x][y];
                    }
                    x = i + dia[k][0], y = j + dia[k][1];
                    if (x >= 0 && x < n && y >= 0 && y < n) {
                        cntDia += grid[x][y];
                    }
                }
                cache[grid[i][j]] = {cntAdj, cntDia};
            }
        }
    }
    
    int adjacentSum(int value) {
        return cache[value].first;
    }
    
    int diagonalSum(int value) {
        return cache[value].second;
    }
};
```

#### Python

```python
from typing import List

direction = [[-1, 0], [1, 0], [0, -1], [0, 1], [-1, -1], [1, 1], [-1, 1], [1, -1]]

class NeighborSum:
    def __init__(self, grid: List[List[int]]):
        n = len(grid)
        self.cache = [[0, 0] for _ in range(n * n)]
        for i in range(n):
            for j in range(n):
                for th, (x, y) in enumerate(direction):
                    if 0 <= x + i < n and 0 <= y + j < n:
                        self.cache[grid[i][j]][th // 4] += grid[x + i][y + j]

    def adjacentSum(self, value: int) -> int:
        return self.cache[value][0]

    def diagonalSum(self, value: int) -> int:
        return self.cache[value][1]
```

#### Java

```java
class NeighborSum {
    private static final int[][] direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    private int[][] cache;

    public NeighborSum(int[][] grid) {
        int n = grid.length;
        cache = new int[n * n][2];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 8; k++) {
                    int x = i + direction[k][0], y = j + direction[k][1];
                    if (x >= 0 && x < n && y >= 0 && y < n) {
                        cache[grid[i][j]][k / 4] += grid[x][y];
                    }
                }
            }
        }
    }
    
    public int adjacentSum(int value) {
        return cache[value][0];
    }
    
    public int diagonalSum(int value) {
        return cache[value][1];
    }
}
```

#### Go

```go
package main

var direction = []struct{x, y int}{{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}}
type Value [][2]int

type NeighborSum struct {
    cache Value
}


func Constructor(grid [][]int) NeighborSum {
    n := len(grid)
    var neighborSum NeighborSum
    neighborSum.cache = make(Value, n * n)
    for i, row := range grid {
        for j, v := range row {
            for k, d := range direction {
                x, y := i + d.x, j + d.y
                if x >= 0 && x < n && y >= 0 && y < n {
                    neighborSum.cache[v][k / 4] += grid[x][y]
                }
            }
        }
    }
    return neighborSum
}


func (this *NeighborSum) AdjacentSum(value int) int {
    return this.cache[value][0]
}


func (this *NeighborSum) DiagonalSum(value int) int {
    return this.cache[value][1]
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/11/11/LeetCode%203242.%E8%AE%BE%E8%AE%A1%E7%9B%B8%E9%82%BB%E5%85%83%E7%B4%A0%E6%B1%82%E5%92%8C%E6%9C%8D%E5%8A%A1/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/143698347](https://letmefly.blog.csdn.net/article/details/143698347)
