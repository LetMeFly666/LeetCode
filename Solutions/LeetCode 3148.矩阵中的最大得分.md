---
title: 3148.矩阵中的最大得分
date: 2024-08-16 00:13:02
tags: [题解, LeetCode, 中等, 数组, 动态规划, DP, 矩阵]
categories: [题解, LeetCode]
---

# 【LetMeFly】3148.矩阵中的最大得分：每个元素与其左或上元素之差的最大值（原地修改O(1)空间）

力扣题目链接：[https://leetcode.cn/problems/maximum-difference-score-in-a-grid/](https://leetcode.cn/problems/maximum-difference-score-in-a-grid/)

<p>给你一个由 <strong>正整数</strong> 组成、大小为 <code>m x n</code> 的矩阵 <code>grid</code>。你可以从矩阵中的任一单元格移动到另一个位于正下方或正右侧的任意单元格（不必相邻）。从值为 <code>c1</code> 的单元格移动到值为 <code>c2</code> 的单元格的得分为 <code>c2 - c1</code> 。</p>

<p>你可以从<strong> 任一</strong> 单元格开始，并且必须至少移动一次。</p>

<p>返回你能得到的 <strong>最大 </strong>总得分。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2024/03/14/grid1.png" style="width: 240px; height: 240px;" />
<div class="example-block">
<p><strong>输入：</strong><span class="example-io">grid = [[9,5,7,3],[8,9,6,1],[6,7,14,3],[2,5,3,1]]</span></p>

<p><strong>输出：</strong><span class="example-io">9</span></p>

<p><strong>解释：</strong>从单元格 <code>(0, 1)</code> 开始，并执行以下移动：<br />
- 从单元格 <code>(0, 1)</code> 移动到 <code>(2, 1)</code>，得分为 <code>7 - 5 = 2</code> 。<br />
- 从单元格 <code>(2, 1)</code> 移动到 <code>(2, 2)</code>，得分为 <code>14 - 7 = 7</code> 。<br />
总得分为 <code>2 + 7 = 9</code> 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/04/08/moregridsdrawio-1.png" style="width: 180px; height: 116px;" /></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">grid = [[4,3,2],[3,2,1]]</span></p>

<p><strong>输出：</strong><span class="example-io">-1</span></p>

<p><strong>解释：</strong>从单元格 <code>(0, 0)</code> 开始，执行一次移动：从 <code>(0, 0)</code> 到 <code>(0, 1)</code> 。得分为 <code>3 - 4 = -1</code> 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>2 &lt;= m, n &lt;= 1000</code></li>
	<li><code>4 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法：动态规划

从a移动到b，再从b移动到c，等价于直接从a移动到c。

因此要求的，就是对所有的a到c中，c-a的最大值。

怎么求？很简单，在遍历原始数组的时候将每个值修改为*这个元素、这个元素左上方(包含)所有元素的最小值*。

这样，对应下标为(i, j)的元素，其左上方的最小值就是min(grid[i - 1][j], grid[i][j - 1])。

使用grid[i][j]减去这个“最小值”，即为从任意一点移动到(i, j)所得的最大得分（只能往右或下移动）。

所有的最大得分中，最大的那个即为所求。

+ 时间复杂度$O(size(grid))$
+ 空间复杂度$O(1)$：可以直接修改grid数组的话，空间复杂度就是O(1)

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int ans = grid[0][1] - grid[0][0];
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                int original = grid[i][j];
                if (i > 0) {
                    grid[i][j] = min(grid[i][j], grid[i - 1][j]);
                    ans = max(ans, original - grid[i - 1][j]);
                }
                if (j > 0) {
                    grid[i][j] = min(grid[i][j], grid[i][j - 1]);
                    ans = max(ans, original - grid[i][j - 1]);
                }
            }
        }
        return ans;
    }
};
```

执行用时分布119ms击败99.11%；消耗内存分布55.80MB击败87.46%。

#### Python

```python
from typing import List

class Solution:
    def maxScore(self, grid: List[List[int]]) -> int:
        ans = grid[0][1] - grid[0][0]
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                original = grid[i][j]
                if i > 0:
                    grid[i][j] = min(grid[i][j], grid[i - 1][j])
                    ans = max(ans, original - grid[i - 1][j])
                if j > 0:
                    grid[i][j] = min(grid[i][j], grid[i][j - 1])
                    ans = max(ans, original - grid[i][j - 1])
        return ans
```

#### Java

```java
import java.util.List;

class Solution {
    public int maxScore(List<List<Integer>> grid) {
        int ans = -100000000;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.get(0).size(); j++) {
                int original = grid.get(i).get(j);
                if (i > 0) {
                    grid.get(i).set(j, Math.min(grid.get(i).get(j), grid.get(i - 1).get(j)));
                    ans = Math.max(ans, original - grid.get(i - 1).get(j));
                }
                if (j > 0) {
                    grid.get(i).set(j, Math.min(grid.get(i).get(j), grid.get(i).get(j - 1)));
                    ans = Math.max(ans, original - grid.get(i).get(j - 1));
                }
            }
        }
        return ans;
    }
}
```

#### Go

```go
package main


func min(a int, b int) int {
    if a < b {
        return a
    }
    return b
}

func max(a int, b int) int {
    if a > b {
        return a
    }
    return b
}

func maxScore(grid [][]int) int {
    ans := -12345678
    for i, line := range grid {
        for j, item := range line {
            original := item
            if i > 0 {
                grid[i][j] = min(grid[i][j], grid[i - 1][j])  // 这里修改item的值不会改变grid[i][j]的值
                ans = max(ans, original - grid[i - 1][j])
            }
            if j > 0 {
                grid[i][j] = min(grid[i][j], grid[i][j - 1])
                ans = max(ans, original - grid[i][j - 1])
            }
        }
    }
    return ans
}
```

## End

[44CC44Gt44GZ44Gn44Kr44OQ44Gr5b2T5pysCg==](https://github.com/LetMeFly666/SecFFT/blob/62c3890e1be5ac87912c17e3e90c0bef5d0e40a0/README.md?plain=1#L438C67-L438C107)

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/08/16/LeetCode%203148.%E7%9F%A9%E9%98%B5%E4%B8%AD%E7%9A%84%E6%9C%80%E5%A4%A7%E5%BE%97%E5%88%86/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/141234633](https://letmefly.blog.csdn.net/article/details/141234633)
