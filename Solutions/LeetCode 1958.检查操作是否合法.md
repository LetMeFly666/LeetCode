---
title: 1958.检查操作是否合法
date: 2024-07-07 17:19:36
tags: [题解, LeetCode, 中等, 数组, 枚举, 矩阵]
---

# 【LetMeFly】1958.检查操作是否合法：8个方向分别遍历

力扣题目链接：[https://leetcode.cn/problems/check-if-move-is-legal/](https://leetcode.cn/problems/check-if-move-is-legal/)

<p>给你一个下标从&nbsp;<strong>0</strong>&nbsp;开始的&nbsp;<code>8 x 8</code> 网格&nbsp;<code>board</code>&nbsp;，其中&nbsp;<code>board[r][c]</code>&nbsp;表示游戏棋盘上的格子&nbsp;<code>(r, c)</code>&nbsp;。棋盘上空格用&nbsp;<code>'.'</code>&nbsp;表示，白色格子用&nbsp;<code>'W'</code>&nbsp;表示，黑色格子用&nbsp;<code>'B'</code>&nbsp;表示。</p>

<p>游戏中每次操作步骤为：选择一个空格子，将它变成你正在执行的颜色（要么白色，要么黑色）。但是，<strong>合法 </strong>操作必须满足：涂色后这个格子是 <strong>好线段的一个端点</strong>&nbsp;（好线段可以是水平的，竖直的或者是对角线）。</p>

<p><strong>好线段</strong>&nbsp;指的是一个包含 <strong>三个或者更多格子（包含端点格子）</strong>的线段，线段两个端点格子为 <strong>同一种颜色</strong>&nbsp;，且中间剩余格子的颜色都为 <strong>另一种颜色</strong>&nbsp;（线段上不能有任何空格子）。你可以在下图找到好线段的例子：</p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/22/goodlines5.png" style="width: 500px; height: 312px;" />
<p>给你两个整数&nbsp;<code>rMove</code> 和&nbsp;<code>cMove</code>&nbsp;以及一个字符&nbsp;<code>color</code>&nbsp;，表示你正在执行操作的颜色（白或者黑），如果将格子&nbsp;<code>(rMove, cMove)</code>&nbsp;变成颜色&nbsp;<code>color</code>&nbsp;后，是一个&nbsp;<strong>合法</strong>&nbsp;操作，那么返回&nbsp;<code>true</code>&nbsp;，如果不是合法操作返回&nbsp;<code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/07/10/grid11.png" style="width: 350px; height: 350px;" /></p>

<pre>
<b>输入：</b>board = [[".",".",".","B",".",".",".","."],[".",".",".","W",".",".",".","."],[".",".",".","W",".",".",".","."],[".",".",".","W",".",".",".","."],["W","B","B",".","W","W","W","B"],[".",".",".","B",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","W",".",".",".","."]], rMove = 4, cMove = 3, color = "B"
<b>输出：</b>true
<b>解释：</b>'.'，'W' 和 'B' 分别用颜色蓝色，白色和黑色表示。格子 (rMove, cMove) 用 'X' 标记。
以选中格子为端点的两个好线段在上图中用红色矩形标注出来了。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/07/10/grid2.png" style="width: 350px; height: 351px;" /></p>

<pre>
<b>输入：</b>board = [[".",".",".",".",".",".",".","."],[".","B",".",".","W",".",".","."],[".",".","W",".",".",".",".","."],[".",".",".","W","B",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".","B","W",".","."],[".",".",".",".",".",".","W","."],[".",".",".",".",".",".",".","B"]], rMove = 4, cMove = 4, color = "W"
<b>输出：</b>false
<b>解释：</b>虽然选中格子涂色后，棋盘上产生了好线段，但选中格子是作为中间格子，没有产生以选中格子为端点的好线段。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>board.length == board[r].length == 8</code></li>
	<li><code>0 &lt;= rMove, cMove &lt; 8</code></li>
	<li><code>board[rMove][cMove] == '.'</code></li>
	<li><code>color</code>&nbsp;要么是&nbsp;<code>'B'</code> 要么是&nbsp;<code>'W'</code>&nbsp;。</li>
</ul>


    
## 解题方法：8个方向分别模拟

本题编号<span title="BUCT建校">1958</span>。

### 思路

从修改位置开始向8个方向分别模拟，一旦某个方向符合“好线段”则返回true，全部模拟完未返回则返回false。

对于某个方向，要确保：

1. 下一个格子是反色
2. 之后的格子中，在遇到空格之前，遇到同色

### 具体细节

1. 颜色的反色：`color ^ 'W' ^ 'B'`（这是因为两个相同值异或结果为0，0异或一个数结果为这个数）；
2. 其实可以不用真的修改`rMove, cMove`这个格子的颜色。

### 时空复杂度

+ 时间复杂度$O(CD)$。其中格子大小是$C\times C$，$C=8$；方向个数是$D$，$D=8$。
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
const int directions[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
class Solution {
private:
    inline bool inBorad(int x, int y) {
        return x >= 0 && x < 8 && y >= 0 && y < 8;
    }
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        board[rMove][cMove] = color;
        for (int d = 0; d < 8; d++) {
            int x = rMove, y = cMove;
            int dx = directions[d][0], dy = directions[d][1];
            x += dx, y += dy;
            if (!inBorad(x, y)) {
                continue;
            }
            if (board[x][y] != (color ^ 'B' ^ 'W')) {
                continue;
            }
            while (inBorad(x + dx, y + dy)) {
                x = x + dx, y = y + dy;
                if (board[x][y] == color) {
                    return true;
                }
                if (board[x][y] == '.') {
                    break;
                }
            }
        }
        return false;
    }
};

/*
..W.BWWB
BW.W.WBB
.WBWW.WW
WW.W..BB
BWBBWWB.
W.W..BWW
B.BB..BB
.W.W.W.W

5 4 W
*/
```

#### Go

```go
package main

func inBoard(x int, y int) bool {
    return 0 <= x && x < 8 && 0 <= y && y < 8
}

func checkMove(board [][]byte, rMove int, cMove int, color byte) bool {
    directions := []struct{x, y int}{{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}
    for _, thisDirection := range directions {
        dx, dy := thisDirection.x, thisDirection.y
        x, y := rMove + dx, cMove + dy
        if !inBoard(x, y) || board[x][y] == '.' || board[x][y] == color {
            continue
        }
        for inBoard(x + dx, y + dy) {
            x, y = x + dx, y + dy
            if board[x][y] == color {
                return true
            }
            if board[x][y] == '.' {
                break
            }
        }
    }
    return false
}
```

#### Java

```java
class Solution {
    private static final int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    private boolean inBoard(int x, int y) {
        return x >= 0 && x < 8 && y >= 0 && y < 8;
    }

    public boolean checkMove(char[][] board, int rMove, int cMove, char color) {
        for (int d = 0; d < 8; d++) {
            int dx = directions[d][0], dy = directions[d][1];
            int x = rMove + dx, y = cMove + dy;
            if (!inBoard(x, y) || board[x][y] == '.' || board[x][y] == color) {
                continue;
            }
            while (inBoard(x + dx, y + dy)) {
                x = x + dx;
                y = y + dy;
                if (board[x][y] == color) {
                    return true;
                }
                if (board[x][y] == '.') {
                    break;
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

DIRECTIONS = [[0, 1], [0, -1], [1, 0], [-1, 0], [1, 1], [1, -1], [-1, 1], [-1, -1]]

class Solution:
    def inBoard(self, x: int, y: int) -> bool:
        return 0 <= x < 8 and 0 <= y < 8
    
    def checkMove(self, board: List[List[str]], rMove: int, cMove: int, color: str) -> bool:
        board[rMove][cMove] = color  # 其实不真的修改也没问题
        for tx, ty in DIRECTIONS:
            x, y = rMove + tx, cMove + ty
            if not self.inBoard(x, y):
                continue
            if board[x][y] == color or board[x][y] == '.':
                continue
            while self.inBoard(x + tx, y + ty):
                x, y = x + tx, y + ty
                if board[x][y] == color:
                    return True
                if board[x][y] == '.':
                    break
        return False

```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/07/07/LeetCode%201958.%E6%A3%80%E6%9F%A5%E6%93%8D%E4%BD%9C%E6%98%AF%E5%90%A6%E5%90%88%E6%B3%95/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/140249215](https://letmefly.blog.csdn.net/article/details/140249215)
