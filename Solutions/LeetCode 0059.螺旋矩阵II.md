---
title: 59.螺旋矩阵 II：优质代码无多层嵌套，Python主程序11行解决
date: 2025-02-07 20:59:41
tags: [题解, LeetCode, 中等, 数组, 矩阵, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】59.螺旋矩阵 II：优质代码无多层嵌套，Python主程序11行解决

力扣题目链接：[https://leetcode.cn/problems/spiral-matrix-ii/](https://leetcode.cn/problems/spiral-matrix-ii/)

<p>给你一个正整数 <code>n</code> ，生成一个包含 <code>1</code> 到 <code>n<sup>2</sup></code> 所有元素，且元素按顺时针顺序螺旋排列的 <code>n x n</code> 正方形矩阵 <code>matrix</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/spiraln.jpg" style="width: 242px; height: 242px;" />
<pre>
<strong>输入：</strong>n = 3
<strong>输出：</strong>[[1,2,3],[8,9,4],[7,6,5]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>[[1]]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 20</code></li>
</ul>


    
## 解题方法：模拟（定义方向数组）

定义一个方向数组`directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}`，代表当前前进方向下，下一个元素的下标相对这一个元素的下标的横纵坐标`diff`。

四个方向分别代表👉👇👈👆，初始方向为👉（令`d`代表方向，初始值为`0`）。

前进过程中，如果前方元素是边界，或者前方元素已经被填充过，则换向（`d = (d + 1) % 4`）。

+ 时间复杂度$O(n^2)$
+ 空间复杂度$O(1)$，返回值不计入

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-02-07 20:37:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-07 20:42:22
 */

class Solution {
private:
    const int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int d = 0, x = 0, y = 0;
        for (int i = 1; i <= n * n; i++) {
            ans[x][y] = i;
            int nx = x + directions[d][0];
            int ny = y + directions[d][1];
            if (nx < 0 || nx == n || ny < 0 || ny == n || ans[nx][ny]) {
                d = (d + 1) % 4;
                nx = x + directions[d][0];
                ny = y + directions[d][1];
            }
            x = nx, y = ny;
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-02-07 20:38:00
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-07 20:49:54
'''
from typing import List


class Solution:
    def __init__(self):
        self.directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]
    
    def generateMatrix(self, n: int) -> List[List[int]]:
        ans = [[0] * n for _ in range(n)]
        d = x = y = 0
        for i in range(n * n):
            ans[x][y] = i + 1
            nx, ny = x + self.directions[d][0], y + self.directions[d][1]
            if nx == n or nx < 0 or ny == n or ny < 0 or ans[nx][ny]:
                d = (d + 1) % 4
                nx, ny = x + self.directions[d][0], y + self.directions[d][1]
            x, y = nx, ny
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-02-07 20:38:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-07 20:52:38
 */
class Solution {
    private int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    public int[][] generateMatrix(int n) {
        int[][] ans = new int[n][n];
        int d = 0, x = 0, y = 0;
        for (int i = 1; i <= n * n; i++) {
            ans[x][y] = i;
            int nx = x + directions[d][0];
            int ny = y + directions[d][1];
            if (nx == n || nx < 0 || ny == n || ny < 0 || ans[nx][ny] > 0) {
                d = (d + 1) % 4;
                nx = x + directions[d][0];
                ny = y + directions[d][1];
            }
            x = nx;
            y = ny;
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-02-07 20:38:08
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-07 20:57:00
 */
package main

var directions [][]int = [][]int{
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
}

func generateMatrix(n int) [][]int {
    ans := make([][]int, n)
    for i := range ans {
        ans[i] = make([]int, n)
    }
    d, x, y := 0, 0, 0
    for i := 1; i <= n * n; i++ {
        ans[x][y] = i
        nx, ny := x + directions[d][0], y + directions[d][1]
        if nx == n || nx < 0 || ny == n || ny < 0 || ans[nx][ny] > 0 {
            d = (d + 1) % 4
            nx, ny = x + directions[d][0], y + directions[d][1]
        }
        x, y = nx, ny
    }
    return ans
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/02/07/LeetCode%200059.%E8%9E%BA%E6%97%8B%E7%9F%A9%E9%98%B5II/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/145502589](https://letmefly.blog.csdn.net/article/details/145502589)
