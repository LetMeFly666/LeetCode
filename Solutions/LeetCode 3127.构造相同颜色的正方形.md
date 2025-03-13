---
title: 3127.构造相同颜色的正方形
date: 2024-08-31 18:31:25
tags: [题解, LeetCode, 简单, 数组, 枚举, 矩阵, 打表]
categories: [题解, LeetCode]
---

# 【LetMeFly】3127.构造相同颜色的正方形：打表瘾犯了

力扣题目链接：[https://leetcode.cn/problems/make-a-square-with-the-same-color/](https://leetcode.cn/problems/make-a-square-with-the-same-color/)

<p>给你一个二维 <code>3 x 3</code>&nbsp;的矩阵&nbsp;<code>grid</code>&nbsp;，每个格子都是一个字符，要么是&nbsp;<code>'B'</code>&nbsp;，要么是&nbsp;<code>'W'</code>&nbsp;。字符&nbsp;<code>'W'</code>&nbsp;表示白色，字符&nbsp;<code>'B'</code>&nbsp;表示黑色。</p>

<p>你的任务是改变 <strong>至多一个</strong>&nbsp;格子的颜色，使得矩阵中存在一个 <code>2 x 2</code>&nbsp;颜色完全相同的正方形。<!-- notionvc: adf957e1-fa0f-40e5-9a2e-933b95e276a7 --></p>

<p>如果可以得到一个相同颜色的 <code>2 x 2</code>&nbsp;正方形，那么返回 <code>true</code>&nbsp;，否则返回 <code>false</code>&nbsp;。</p>

<p>&nbsp;</p>
<style type="text/css">.grid-container {
  display: grid;
  grid-template-columns: 30px 30px 30px;
  padding: 10px;
}
.grid-item {
  background-color: black;
  border: 1px solid gray;
  height: 30px;
  font-size: 30px;
  text-align: center;
}
.grid-item-white {
  background-color: white;
}
</style>
<style class="darkreader darkreader--sync" media="screen" type="text/css">
</style>
<p><strong class="example">示例 1：</strong></p>

<div class="grid-container">
<div class="grid-item">&nbsp;</div>

<div class="grid-item grid-item-white">&nbsp;</div>

<div class="grid-item">&nbsp;</div>

<div class="grid-item">&nbsp;</div>

<div class="grid-item grid-item-white">&nbsp;</div>

<div class="grid-item grid-item-white">&nbsp;</div>

<div class="grid-item">&nbsp;</div>

<div class="grid-item grid-item-white">&nbsp;</div>

<div class="grid-item">&nbsp;</div>
</div>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [["B","W","B"],["B","W","W"],["B","W","B"]]</span></p>

<p><span class="example-io"><b>输出：</b>true</span></p>

<p><strong>解释：</strong></p>

<p>修改&nbsp;<code>grid[0][2]</code> 的颜色，可以满足要求。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="grid-container">
<div class="grid-item">&nbsp;</div>

<div class="grid-item grid-item-white">&nbsp;</div>

<div class="grid-item">&nbsp;</div>

<div class="grid-item grid-item-white">&nbsp;</div>

<div class="grid-item">&nbsp;</div>

<div class="grid-item grid-item-white">&nbsp;</div>

<div class="grid-item">&nbsp;</div>

<div class="grid-item grid-item-white">&nbsp;</div>

<div class="grid-item">&nbsp;</div>
</div>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [["B","W","B"],["W","B","W"],["B","W","B"]]</span></p>

<p><span class="example-io"><b>输出：</b>false</span></p>

<p><strong>解释：</strong></p>

<p>只改变一个格子颜色无法满足要求。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="grid-container">
<div class="grid-item">&nbsp;</div>

<div class="grid-item grid-item-white">&nbsp;</div>

<div class="grid-item">&nbsp;</div>

<div class="grid-item">&nbsp;</div>

<div class="grid-item grid-item-white">&nbsp;</div>

<div class="grid-item grid-item-white">&nbsp;</div>

<div class="grid-item">&nbsp;</div>

<div class="grid-item grid-item-white">&nbsp;</div>

<div class="grid-item grid-item-white">&nbsp;</div>
</div>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [["B","W","B"],["B","W","W"],["B","W","W"]]</span></p>

<p><span class="example-io"><b>输出：</b>true</span></p>

<p><strong>解释：</strong></p>

<p><code>grid</code>&nbsp;已经包含一个&nbsp;<code>2 x 2</code>&nbsp;颜色相同的正方形了。<!-- notionvc: 9a8b2d3d-1e73-457a-abe0-c16af51ad5c2 --></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>grid.length == 3</code></li>
	<li><code>grid[i].length == 3</code></li>
	<li><code>grid[i][j]</code>&nbsp;要么是&nbsp;<code>'W'</code>&nbsp;，要么是&nbsp;<code>'B'</code> 。</li>
</ul>


    
## 解题方法一：正常枚举

枚举每一个四方块的右下角，统计这个四方块中有多少个`W`。只要`W`的个数不是`2`，就能直接返回`true`。原因如下：

> + 若`W = 0`，则全黑
> + 若`W = 1`，则1白，1次修改可变成全黑
> + 若`W = 3`，则1黑，1次修改可变成全白
> + 若`W = 4`，则全白

如果枚举完了所有的四方块，则返回`false`。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

写代码的时候忘记看数据范围了，写完了才发现一定是3x3。

#### C++

```cpp
class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for (int i = 1; i < grid.size(); i++) {
            for (int j = 1; j < grid.size(); j++) {
                if ((grid[i][j] == 'W') + (grid[i - 1][j] == 'W') + (grid[i][j - 1] == 'W') + (grid[i - 1][j - 1] == 'W') != 2) {
                    return true;
                }
            }
        }
        return false;
    }
};
```

#### Go

```go
package main

func canMakeSquare(grid [][]byte) bool {
    for i := 1; i < len(grid); i++ {
        for j := 1; j < len(grid[0]); j++ {
            cntW := 0
            for x := -1; x < 1; x++ {
                for y := -1; y < 1; y++ {
                    if grid[i + x][j + y] == 'W' {
                        cntW++
                    }
                }
            }
            if cntW != 2 {
                return true
            }
        }
    }
    return false
}
```

#### Java

```java
class Solution {
    public boolean canMakeSquare(char[][] grid) {
        for (int i = 1; i < grid.length; i++) {
            for (int j = 1; j < grid[0].length; j++) {
                int cntW = 0;
                for (int x = -1; x < 1; x++) {
                    for (int y = -1; y < 1; y++) {
                        if (grid[i + x][j + y] == 'W') {
                            cntW++;
                        }
                    }
                }
                if (cntW != 2) {
                    return true;
                }
            }
        }
        return false;
    }
}
```

#### Python

```python
from typing import List

class Solution:
    def canMakeSquare(self, grid: List[List[str]]) -> bool:
        for i in range(1, len(grid)):
            for j in range(1, len(grid[0])):
                if (grid[i][j] == 'W') + (grid[i - 1][j] == 'W') + (grid[i][j - 1] == 'W') + (grid[i - 1][j - 1] == 'W') != 2:
                    return True
        return False
```

## 解题方法二：打表

做完后发现表格大小固定为3x3，然而方法一写成了mxn。怎么办？只把len(grid)和len(grid[0])改成3然后再提交一次？好像意义不大。

既然3x3的表格最多有$2^{3\times3}=512$种情况，因此来个痛快的打表吧。

由于方法一中，`W`（范围`0-4`）只有为`2`这一种情况时不可行，因此不可行的情况比较少。所以决定打表枚举不可行的情况。

如何将表格和整数互相转换？`grid[i][j]`对应整数二进制下的低`i * 3 + j`位即可。`W`代表`1`，`B`代表`0`，完美。

+ 时间复杂度$O(1)$，一共有14种返回false的情况，可视为常数1
+ 空间复杂度$O(1)$

### AC代码

#### Python：打表求不可行的有哪些

```python
from typing import List

class Solution:
    def canMakeSquare(self, grid: List[List[str]]) -> bool:
        for i in range(1, len(grid)):
            for j in range(1, len(grid[0])):
                if (grid[i][j] == 'W') + (grid[i - 1][j] == 'W') + (grid[i][j - 1] == 'W') + (grid[i - 1][j - 1] == 'W') != 2:
                    return True
        return False

cannot = []
sol = Solution()
for code in range(1 << 9):
    grid = [['W' if (code & (1 << (i * 3 + j))) else 'B' for j in range(3)] for i in range(3)]
    if grid == [['B', 'W', 'B'], ['W', 'B', 'W'], ['B', 'W', 'B']]:
        print(code)
    # print(grid)
    if not sol.canMakeSquare(grid):
        cannot.append(code)
print(cannot)

# [56, 113, 146, 149, 170, 173, 227, 284, 338, 341, 362, 365, 398, 455]
```

#### Python：由表差答案

```python
from typing import List

cannot = [56, 113, 146, 149, 170, 173, 227, 284, 338, 341, 362, 365, 398, 455]

class Solution:
    def grid2code(self, grid: List[List[str]]) -> int:
        ans = 0
        for i in range(3):
            for j in range(3):
                if grid[i][j] == 'W':
                    ans |= (1 << (i * 3 + j))
        return ans

    def canMakeSquare(self, grid: List[List[str]]) -> bool:
        return self.grid2code(grid) not in cannot
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/08/31/LeetCode%203127.%E6%9E%84%E9%80%A0%E7%9B%B8%E5%90%8C%E9%A2%9C%E8%89%B2%E7%9A%84%E6%AD%A3%E6%96%B9%E5%BD%A2/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/141756605](https://letmefly.blog.csdn.net/article/details/141756605)
