---
title: 999.可以被一步捕获的棋子数
date: 2024-12-07 00:25:18
tags: [题解, LeetCode, 简单, 数组, 矩阵, 模拟]
---

# 【LetMeFly】999.可以被一步捕获的棋子数：模拟

力扣题目链接：[https://leetcode.cn/problems/available-captures-for-rook/](https://leetcode.cn/problems/available-captures-for-rook/)

<p>给定一个&nbsp;<code>8 x 8</code> 的棋盘，<strong>只有一个</strong> 白色的车，用字符 <code>'R'</code> 表示。棋盘上还可能存在白色的象&nbsp;<code>'B'</code>&nbsp;以及黑色的卒&nbsp;<code>'p'</code>。空方块用字符 <code>'.'</code>&nbsp;表示。</p>

<p>车可以按水平或竖直方向（上，下，左，右）移动任意个方格直到它遇到另一个棋子或棋盘的边界。如果它能够在一次移动中移动到棋子的方格，则能够 <strong>吃掉</strong> 棋子。</p>

<p>注意：车不能穿过其它棋子，比如象和卒。这意味着如果有其它棋子挡住了路径，车就不能够吃掉棋子。</p>

<p>返回白车将能 <strong>吃掉</strong> 的 <strong>卒的数量</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/02/23/1253_example_1_improved.PNG" style="height: 305px; width: 300px;" /></p>

<pre>
<strong>输入：</strong>[[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","R",".",".",".","p"],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
<strong>输出：</strong>3
<strong>解释：
</strong>在本例中，车能够吃掉所有的卒。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/02/23/1253_example_2_improved.PNG" style="height: 306px; width: 300px;" /></p>

<pre>
<strong>输入：</strong>[[".",".",".",".",".",".",".","."],[".","p","p","p","p","p",".","."],[".","p","p","B","p","p",".","."],[".","p","B","R","B","p",".","."],[".","p","p","B","p","p",".","."],[".","p","p","p","p","p",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
<strong>输出：</strong>0
<strong>解释：
</strong>象阻止了车吃掉任何卒。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/02/23/1253_example_3_improved.PNG" style="height: 305px; width: 300px;" /></p>

<pre>
<strong>输入：</strong>[[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","p",".",".",".","."],["p","p",".","R",".","p","B","."],[".",".",".",".",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."]]
<strong>输出：</strong>3
<strong>解释： </strong>
车可以吃掉位置 b5，d6 和 f5 的卒。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>board.length == 8</code></li>
	<li><code>board[i].length == 8</code></li>
	<li><code>board[i][j]</code> 可以是&nbsp;<code>'R'</code>，<code>'.'</code>，<code>'B'</code>&nbsp;或&nbsp;<code>'p'</code></li>
	<li>只有一个格子上存在&nbsp;<code>board[i][j] == 'R'</code></li>
</ol>


    
## 解题方法：模拟

一共分为两步：

1. 遍历棋盘，遇到字符`R`时停下，并记录下起点下标
2. 从起点开始分别向上下左右四个方向遍历，遇到边界或者遇到`B`停止。同时，遍历时若遇到`p`，则答案数量加一并停止。

+ 时间复杂度$O(mn)$，其中棋盘大小为$m\times n$
+ 空间复杂度$O(1)$

[我的一个评论](https://leetcode.cn/problems/available-captures-for-rook/solutions/170099/che-de-ke-yong-bu-huo-liang-by-leetcode-solution/comments/2438607)

### AC代码

#### C++

```cpp
const int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x, y;
        for (x = 0; x < board.size(); x++) {
            for (y = 0; y < board[0].size(); y++) {
                if (board[x][y] == 'R') {
                    goto loop;
                }
            }
        }
        loop:;
        int ans = 0;
        for (int d = 0; d < 4; d++) {
            for (int step = 1; ; step++) {
                int nx = x + directions[d][0] * step;
                int ny = y + directions[d][1] * step;
                if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || board[nx][ny] == 'B') {
                    break;
                }
                if (board[nx][ny] == 'p') {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/12/07/LeetCode%200999.%E5%8F%AF%E4%BB%A5%E8%A2%AB%E4%B8%80%E6%AD%A5%E6%8D%95%E8%8E%B7%E7%9A%84%E6%A3%8B%E5%AD%90%E6%95%B0/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/144303138](https://letmefly.blog.csdn.net/article/details/144303138)
