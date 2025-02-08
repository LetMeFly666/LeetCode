---
title: 63.不同路径 II：动态规划 - 原地使用地图数组，几乎无额外空间开销
date: 2025-02-08 10:07:06
tags: [题解, LeetCode, 中等, 数组, 动态规划, DP, 矩阵]
---

# 【LetMeFly】63.不同路径 II：动态规划 - 原地使用地图数组，几乎无额外空间开销

力扣题目链接：[https://leetcode.cn/problems/unique-paths-ii/](https://leetcode.cn/problems/unique-paths-ii/)

<p>给定一个&nbsp;<code>m x n</code>&nbsp;的整数数组&nbsp;<code>grid</code>。一个机器人初始位于 <strong>左上角</strong>（即 <code>grid[0][0]</code>）。机器人尝试移动到 <strong>右下角</strong>（即 <code>grid[m - 1][n - 1]</code>）。机器人每次只能向下或者向右移动一步。</p>

<p>网格中的障碍物和空位置分别用 <code>1</code> 和 <code>0</code> 来表示。机器人的移动路径中不能包含 <strong>任何</strong>&nbsp;有障碍物的方格。</p>

<p>返回机器人能够到达右下角的不同路径数量。</p>

<p>测试用例保证答案小于等于 <code>2 * 10<sup>9</sup></code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/robot1.jpg" />
<pre>
<strong>输入：</strong>obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
<strong>输出：</strong>2
<strong>解释：</strong>3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 <code>2</code> 条不同的路径：
1. 向右 -&gt; 向右 -&gt; 向下 -&gt; 向下
2. 向下 -&gt; 向下 -&gt; 向右 -&gt; 向右
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/robot2.jpg" />
<pre>
<strong>输入：</strong>obstacleGrid = [[0,1],[0,0]]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m ==&nbsp;obstacleGrid.length</code></li>
	<li><code>n ==&nbsp;obstacleGrid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>obstacleGrid[i][j]</code> 为 <code>0</code> 或 <code>1</code></li>
</ul>


    
## 解题方法：动态规划

直接使用原来的obstacleGrid数组，令`obstacleGrid[i][j]`代表走到`(i, j)`为止的总方案数。

因为是原地修改，所以就要求我们从左到右从上到下按顺序遍历。

遍历到一个元素时：

+ 如果这个元素为`1`，就说明这里是障碍，走这里的方案数为`0`；
+ 否则，走这里的方案数为“由上面来”和“由左边来”的方案数之和（若不可由上而来则将“由上面来”的方案数记为1）。

特别的，对于起始位置`obstacleGrid[0][0]`：

+ 若初始值为`1`说明不可从这里出发，总方案数为`0`；
+ 若初始值为`0`说明可以从这里出发，令`obstacleGrid[0][0] = 1`。

### 时空复杂度分析

+ 时间复杂度$O(size(obstacleGrid))$
+ 空间复杂度$O(1)$

### AC代码

#### Python

```python
'''
Author: LetMeFly
Date: 2025-02-08 09:55:16
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-08 09:58:42
'''
from typing import List

class Solution:
    def uniquePathsWithObstacles(self, a: List[List[int]]) -> int:
        a[0][0] = 0 if a[0][0] else 1
        for i in range(len(a)):
            for j in range(len(a[0])):
                if a[i][j] != 0 and (i or j):
                    a[i][j] = 0
                    continue
                if i > 0:
                    a[i][j] += a[i - 1][j]
                if j > 0:
                    a[i][j] += a[i][j - 1]
        return a[-1][-1]
```

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-02-08 09:36:16
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-08 09:53:50
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        for (int i = 0; i < obstacleGrid.size(); i++) {
            for (int j = 0; j < obstacleGrid[0].size(); j++) {
                if (i == 0 && j == 0) {
                    obstacleGrid[i][j] = obstacleGrid[i][j] ? 0 : 1;
                    continue;
                } else if (obstacleGrid[i][j]) {
                    obstacleGrid[i][j] = -1;
                    continue;
                }
                if (i > 0 && obstacleGrid[i - 1][j] != -1) {
                    obstacleGrid[i][j] += obstacleGrid[i - 1][j];
                }
                if (j > 0 && obstacleGrid[i][j - 1] != -1) {
                    obstacleGrid[i][j] += obstacleGrid[i][j - 1];
                }
            }
        }
        return max(obstacleGrid.back().back(), 0);
    }
};
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-02-08 09:55:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-08 10:02:07
 */
class Solution {
    public int uniquePathsWithObstacles(int[][] a) {
        if (a[0][0] == 1) {
            return 0;
        }
        a[0][0] = 1;
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                if (a[i][j] == 1 && i + j > 0) {
                    a[i][j] = 0;
                    continue;
                }
                if (i > 0) {
                    a[i][j] += a[i - 1][j];
                }
                if (j > 0) {
                    a[i][j] += a[i][j - 1];
                }
            }
        }
        return a[a.length - 1][a[0].length - 1];
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-02-08 09:55:29
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-08 10:04:49
 */
package main

func uniquePathsWithObstacles(a [][]int) int {
    if a[0][0] == 1 {
        return 0
    }
    a[0][0] = 1
    for i := range a {
        for j := range a[0] {
            if a[i][j] == 1 && i + j > 0 {
                a[i][j] = 0
                continue
            }
            if i > 0 {
                a[i][j] += a[i - 1][j]
            }
            if j > 0 {
                a[i][j] += a[i][j - 1]
            }
        }
    }
    return a[len(a) - 1][len(a[0]) - 1]
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/02/08/LeetCode%200063.%E4%B8%8D%E5%90%8C%E8%B7%AF%E5%BE%84II/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/145509662](https://letmefly.blog.csdn.net/article/details/145509662)
