---
title: 3142.判断矩阵是否满足条件
date: 2024-08-29 23:54:40
tags: [题解, LeetCode, 简单, 数组, 矩阵, 遍历]
categories: [题解, LeetCode]
---

# 【LetMeFly】3142.判断矩阵是否满足条件：模拟(遍历)

力扣题目链接：[https://leetcode.cn/problems/check-if-grid-satisfies-conditions/](https://leetcode.cn/problems/check-if-grid-satisfies-conditions/)

<p>给你一个大小为 <code>m x n</code>&nbsp;的二维矩阵&nbsp;<code>grid</code>&nbsp;。你需要判断每一个格子&nbsp;<code>grid[i][j]</code>&nbsp;是否满足：</p>

<ul>
	<li>如果它下面的格子存在，那么它需要等于它下面的格子，也就是&nbsp;<code>grid[i][j] == grid[i + 1][j]</code>&nbsp;。</li>
	<li>如果它右边的格子存在，那么它需要不等于它右边的格子，也就是&nbsp;<code>grid[i][j] != grid[i][j + 1]</code>&nbsp;。</li>
</ul>

<p>如果 <strong>所有</strong>&nbsp;格子都满足以上条件，那么返回 <code>true</code>&nbsp;，否则返回 <code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [[1,0,2],[1,0,2]]</span></p>

<p><span class="example-io"><b>输出：</b>true</span></p>

<p><strong>解释：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2024/04/15/examplechanged.png" style="width: 254px; height: 186px;padding: 10px; background: #fff; border-radius: .5rem;" /></strong></p>

<p>网格图中所有格子都符合条件。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [[1,1,1],[0,0,0]]</span></p>

<p><span class="example-io"><b>输出：</b>false</span></p>

<p><b>解释：</b></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2024/03/27/example21.png" style="width: 254px; height: 186px;padding: 10px; background: #fff; border-radius: .5rem;" /></strong></p>

<p>同一行中的格子值都相等。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [[1],[2],[3]]</span></p>

<p><span class="example-io"><b>输出：</b>false</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/03/31/changed.png" style="width: 86px; height: 277px;padding: 10px; background: #fff; border-radius: .5rem;" /></p>

<p>同一列中的格子值不相等。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n, m &lt;= 10</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 9</code></li>
</ul>


    
## 解题方法：模拟

使用j从第一列循环到最后一列。

> 对于当前列j，如果当前列不是第一列，则判断这个元素是否和左边那一列元素相等。若相等则返回false。
> 
> 使用i从第二行循环到最后一行。
>
> > 如果当前元素和上一行对应元素不同，则返回false。

最终返回true。

+ 时间复杂度$O(mn)$
+ 空间复杂度$O(1)$

相当于只判断了一次左边一列和右边一列是否不同，也可以每行判断一次，写法更简单，运算量几乎翻倍，但不增加时间复杂度，小数据可忽略。

### AC代码

#### C++

```cpp
class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (j && grid[0][j] == grid[0][j - 1]) {
                return false;
            }
            for (int i = 1; i < grid.size(); i++) {
                if (grid[i][j] != grid[i - 1][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};
```

#### Go

```go
package main

func satisfiesConditions(grid [][]int) bool {
    for j := range grid[0] {
        if j > 0 && grid[0][j] == grid[0][j - 1] {
            return false
        }
        for i := 1; i < len(grid); i++ {
            if grid[i][j] != grid[i - 1][j] {
                return false
            }
        }
    }
    return true
}
```

#### Java

```java
class Solution {
    public boolean satisfiesConditions(int[][] grid) {
        for (int j = 0; j < grid[0].length; j++) {
            if (j > 0 && grid[0][j] == grid[0][j - 1]) {
                return false;
            }
            for (int i = 1; i < grid.length; i++) {
                if (grid[i][j] != grid[i - 1][j]) {
                    return false;
                }
            }
        }
        return true;
    }
}
```

#### Python

```python
from typing import List

class Solution:
    def satisfiesConditions(self, grid: List[List[int]]) -> bool:
        for j in range(len(grid[0])):
            if j and grid[0][j] == grid[0][j - 1]:
                return False
            for i in range(1, len(grid)):
                if grid[i][j] != grid[i - 1][j]:
                    return False
        return True
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/08/29/LeetCode%203142.%E5%88%A4%E6%96%AD%E7%9F%A9%E9%98%B5%E6%98%AF%E5%90%A6%E6%BB%A1%E8%B6%B3%E6%9D%A1%E4%BB%B6/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/141691365](https://letmefly.blog.csdn.net/article/details/141691365)
