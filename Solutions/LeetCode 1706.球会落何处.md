---
title: 1706.球会落何处：模拟 - 很有意思的一道题
date: 2025-02-15 11:31:41
tags: [题解, LeetCode, 中等, 数组, 矩阵, 模拟]
---

# 【LetMeFly】1706.球会落何处：模拟 - 很有意思的一道题

力扣题目链接：[https://leetcode.cn/problems/where-will-the-ball-fall/](https://leetcode.cn/problems/where-will-the-ball-fall/)

<p>用一个大小为 <code>m x n</code> 的二维网格 <code>grid</code> 表示一个箱子。你有 <code>n</code> 颗球。箱子的顶部和底部都是开着的。</p>

<p>箱子中的每个单元格都有一个对角线挡板，跨过单元格的两个角，可以将球导向左侧或者右侧。</p>

<ul>
	<li>将球导向右侧的挡板跨过左上角和右下角，在网格中用 <code>1</code> 表示。</li>
	<li>将球导向左侧的挡板跨过右上角和左下角，在网格中用 <code>-1</code> 表示。</li>
</ul>

<p>在箱子每一列的顶端各放一颗球。每颗球都可能卡在箱子里或从底部掉出来。如果球恰好卡在两块挡板之间的 "V" 形图案，或者被一块挡导向到箱子的任意一侧边上，就会卡住。</p>

<p>返回一个大小为 <code>n</code> 的数组 <code>answer</code> ，其中 <code>answer[i]</code> 是球放在顶部的第 <code>i</code> 列后从底部掉出来的那一列对应的下标，如果球卡在盒子里，则返回 <code>-1</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<!-- <p><strong><img alt="" src="https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/img_convert/3a42336477eff34f6b5fd4d5c563a488.jpeg" style="width: 500px; height: 385px;" /></strong></p> -->
<p><strong><img alt="" src="https://cors.letmefly.xyz/https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/12/26/ball.jpg" style="width: 500px; height: 385px;" /></strong></p>

<pre>
<strong>输入：</strong>grid = [[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]
<strong>输出：</strong>[1,-1,-1,-1,-1]
<strong>解释：</strong>示例如图：
b0 球开始放在第 0 列上，最终从箱子底部第 1 列掉出。
b1 球开始放在第 1 列上，会卡在第 2、3 列和第 1 行之间的 "V" 形里。
b2 球开始放在第 2 列上，会卡在第 2、3 列和第 0 行之间的 "V" 形里。
b3 球开始放在第 3 列上，会卡在第 2、3 列和第 0 行之间的 "V" 形里。
b4 球开始放在第 4 列上，会卡在第 2、3 列和第 1 行之间的 "V" 形里。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>grid = [[-1]]
<strong>输出：</strong>[-1]
<strong>解释：</strong>球被卡在箱子左侧边上。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>grid = [[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1],[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1]]
<strong>输出：</strong>[0,1,2,3,4,-1]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 <= m, n <= 100</code></li>
	<li><code>grid[i][j]</code> 为 <code>1</code> 或 <code>-1</code></li>
</ul>


    
## 解题方法：模拟

球斜着落对于某些人的人脑来说可能有点复杂，因此可以把球斜着落拆成“先水平移动后数值下降”两个部分。

对于一个小球`(x, y)`，它水平移动的下一个坐标是`(x, y + grid[x][y])`。

如果下一个坐标**没越界**且**隔板方向和当前相同**，则说明可以完成一次“水平移动并下坠”。

对于一个小球，模拟最多`m`次，就会从底部掉出或被中途卡住。

+ 时间复杂度$O(mn)$
+ 空间复杂度$O(1)$，答案不计入力扣算法空间复杂度

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly  // 中间中断了
 * @Date: 2025-02-15 11:04:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-15 11:19:25
 */
class Solution {
private:
    void drop(vector<vector<int>>& grid, vector<int>& ans, int j) {
        int x = 0, y = j;
        while (x < grid.size()) {
            int nextY = y + grid[x][y];
            if (nextY < 0 || nextY >= grid[0].size() || grid[x][y] != grid[x][nextY]) {
                return;
            }
            x++, y = nextY;
        }
        ans[j] = y;
    } 
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size(), -1);
        for (int j = 0; j < grid[0].size(); j++) {
            drop(grid, ans, j);
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-02-15 11:20:53
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-15 11:24:22
Description: AC,67.31%,26.92%
'''
from typing import List

class Solution:
    def drop(self, j: int) -> None:
        y = j
        for x in range(len(self.grid)):
            nextY = self.grid[x][y] + y
            if nextY < 0 or nextY >= len(self.grid[0]) or self.grid[x][y] != self.grid[x][nextY]:
                return
            y = nextY
        self.ans[j] = y        

    def findBall(self, grid: List[List[int]]) -> List[int]:
        self.grid = grid
        self.ans = [-1] * len(grid[0])
        for j in range(len(grid[0])):
            self.drop(j)
        return self.ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-02-15 11:20:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-15 11:30:31
 */
class Solution {
    private int[][] grid;

    private int drop(int y) {
        for (int x = 0; x < grid.length; x++) {
            int nextY = grid[x][y] + y;
            if (nextY < 0 || nextY >= grid[0].length || grid[x][y] != grid[x][nextY]) {
                return -1;
            }
            y = nextY;
        }
        return y;
    }

    public int[] findBall(int[][] grid) {
        this.grid = grid;
        int[] ans = new int[grid[0].length];
        for (int j = 0; j < grid[0].length; j++) {
            ans[j] = drop(j);
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-02-15 11:21:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-15 11:27:19
 */
package main

func drop_WWTBF(grid [][]int, y int) int {
    for x := range grid {
        nextY := y + grid[x][y]
        if nextY < 0 || nextY >= len(grid[0]) || grid[x][y] != grid[x][nextY] {
            return -1
        }
        y = nextY
    }
    return y
}

func findBall(grid [][]int) []int {
    ans := make([]int, len(grid[0]))
    for j := range grid[0] {
        ans[j] = drop_WWTBF(grid, j)
    }
    return ans
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/145648365)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/02/15/LeetCode%201706.%E7%90%83%E4%BC%9A%E8%90%BD%E4%BD%95%E5%A4%84/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
>
> Tisfy：[https://blog.letmefly.xyz/2025/02/15/LeetCode 1706.球会落何处/](https://blog.letmefly.xyz/2025/02/15/LeetCode%201706.%E7%90%83%E4%BC%9A%E8%90%BD%E4%BD%95%E5%A4%84/)
