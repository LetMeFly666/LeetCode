---
title: 419.甲板上的战舰
date: 2024-06-11 12:27:23
tags: [题解, LeetCode, 中等, 深度优先搜索, 数组, 矩阵]
---

# 【LetMeFly】419.甲板上的战舰：统计战舰头（左上角）——附Py一行版

力扣题目链接：[https://leetcode.cn/problems/battleships-in-a-board/](https://leetcode.cn/problems/battleships-in-a-board/)

<p>给你一个大小为 <code>m x n</code> 的矩阵 <code>board</code> 表示甲板，其中，每个单元格可以是一艘战舰 <code>'X'</code> 或者是一个空位 <code>'.'</code> ，返回在甲板 <code>board</code> 上放置的 <strong>战舰</strong> 的数量。</p>

<p><strong>战舰</strong> 只能水平或者垂直放置在 <code>board</code> 上。换句话说，战舰只能按 <code>1 x k</code>（<code>1</code> 行，<code>k</code> 列）或 <code>k x 1</code>（<code>k</code> 行，<code>1</code> 列）的形状建造，其中 <code>k</code> 可以是任意大小。两艘战舰之间至少有一个水平或垂直的空位分隔 （即没有相邻的战舰）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/10/battelship-grid.jpg" style="width: 333px; height: 333px;" />
<pre>
<strong>输入：</strong>board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
<strong>输出：</strong>2
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>board = [["."]]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == board.length</code></li>
	<li><code>n == board[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>board[i][j]</code> 是 <code>'.'</code> 或 <code>'X'</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你可以实现一次扫描算法，并只使用<strong> </strong><code>O(1)</code><strong> </strong>额外空间，并且不修改 <code>board</code> 的值来解决这个问题吗？</p>


    
## 解题方法：统计战舰左上角

这题的意思是，若出现战舰```X```，则战舰```X```的形状必定是“一行或一列连着几个”。

因此我们直接统计有多少个“战舰头”不就可以了吗。

遍历每个方格，若当前方格为战舰```X```，则满足以下条件时该方格为“战舰头”：

> + 该方格左边是边界或空地
> + 该方格上边是边界或空地

+ 时间复杂度$O(size(board))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'X' && (i == 0 || board[i - 1][j] == '.') && (j == 0 || board[i][j - 1] == '.')) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
// package main

func countBattleships(board [][]byte) int {
    ans := 0
    for i := 0; i < len(board); i++ {
        for j := 0; j < len(board[0]); j++ {
            if board[i][j] == 'X' && (i == 0 || board[i - 1][j] == '.') && (j == 0 || board[i][j - 1] == '.') {
                ans++
            }
        }
    }
    return ans
}
```

#### Java

```java
class Solution {
    public int countBattleships(char[][] board) {
        int ans = 0;
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == 'X' && (i == 0 || board[i - 1][j] == '.') && (j == 0 || board[i][j - 1] == '.')) {
                    ans++;
                }
            }
        }
        return ans;
    }
}
```

#### Python

```python
# from typing import List

class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        return sum(board[i][j] == 'X' and (i == 0 or board[i - 1][j] == '.') and (j == 0 or board[i][j - 1] == '.') for j in range(len(board[0])) for i in range(len(board)))
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/06/11/LeetCode%200419.%E7%94%B2%E6%9D%BF%E4%B8%8A%E7%9A%84%E6%88%98%E8%88%B0/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/139595909](https://letmefly.blog.csdn.net/article/details/139595909)
