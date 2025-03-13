---
title: 529.扫雷游戏
date: 2022-11-23 11:17:50
tags: [题解, LeetCode, 中等, 深度优先搜索, 广度优先搜索, BFS, 数组, 矩阵, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】529.扫雷游戏

力扣题目链接：[https://leetcode.cn/problems/minesweeper/](https://leetcode.cn/problems/minesweeper/)

<p>让我们一起来玩扫雷游戏！</p>

<p>给你一个大小为 <code>m x n</code> 二维字符矩阵&nbsp;<code>board</code> ，表示扫雷游戏的盘面，其中：</p>

<ul>
	<li><code>'M'</code>&nbsp;代表一个 <strong>未挖出的</strong> 地雷，</li>
	<li><code>'E'</code>&nbsp;代表一个<strong> 未挖出的 </strong>空方块，</li>
	<li><code>'B'</code><strong>&nbsp;</strong>代表没有相邻（上，下，左，右，和所有4个对角线）地雷的<strong> 已挖出的 </strong>空白方块，</li>
	<li><strong>数字</strong>（<code>'1'</code> 到 <code>'8'</code>）表示有多少地雷与这块<strong> 已挖出的</strong> 方块相邻，</li>
	<li><code>'X'</code>&nbsp;则表示一个<strong> 已挖出的</strong> 地雷。</li>
</ul>

<p>给你一个整数数组 <code>click</code> ，其中 <code>click = [click<sub>r</sub>, click<sub>c</sub>]</code> 表示在所有<strong> 未挖出的 </strong>方块（<code>'M'</code> 或者 <code>'E'</code>）中的下一个点击位置（<code>click<sub>r</sub></code> 是行下标，<code>click<sub>c</sub></code> 是列下标）。</p>

<p>根据以下规则，返回相应位置被点击后对应的盘面：</p>

<ol>
	<li>如果一个地雷（<code>'M'</code>）被挖出，游戏就结束了- 把它改为&nbsp;<code>'X'</code> 。</li>
	<li>如果一个<strong> 没有相邻地雷 </strong>的空方块（<code>'E'</code>）被挖出，修改它为（<code>'B'</code>），并且所有和其相邻的<strong> 未挖出 </strong>方块都应该被递归地揭露。</li>
	<li>如果一个<strong> 至少与一个地雷相邻</strong> 的空方块（<code>'E'</code>）被挖出，修改它为数字（<code>'1'</code> 到 <code>'8'</code> ），表示相邻地雷的数量。</li>
	<li>如果在此次点击中，若无更多方块可被揭露，则返回盘面。</li>
</ol>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img src="https://assets.leetcode.com/uploads/2018/10/12/minesweeper_example_1.png" style="width: 500px; max-width: 400px; height: 269px;" />
<pre>
<strong>输入：</strong>board = [["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]], click = [3,0]
<strong>输出：</strong>[["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]
</pre>

<p><strong>示例 2：</strong></p>
<img src="https://assets.leetcode.com/uploads/2018/10/12/minesweeper_example_2.png" style="width: 500px; max-width: 400px; height: 275px;" />
<pre>
<strong>输入：</strong>board = [["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]], click = [1,2]
<strong>输出：</strong>[["B","1","E","1","B"],["B","1","X","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == board.length</code></li>
	<li><code>n == board[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>board[i][j]</code> 为 <code>'M'</code>、<code>'E'</code>、<code>'B'</code> 或数字 <code>'1'</code> 到 <code>'8'</code> 中的一个</li>
	<li><code>click.length == 2</code></li>
	<li><code>0 &lt;= click<sub>r</sub> &lt; m</code></li>
	<li><code>0 &lt;= click<sub>c</sub> &lt; n</code></li>
	<li><code>board[click<sub>r</sub>][click<sub>c</sub>]</code> 为 <code>'M'</code> 或 <code>'E'</code></li>
</ul>


    
## 方法一：模拟 + 广搜

点击一个未点击过的地方，会有以下两大种情况：

1. 这个地方是地雷，直接将这个地方修改为```X```并返回
2. 这个地方不是地雷。那么就构建一个队列并将这个点入队。在队列不为空时不断取出队首的点：
   + 如果该点四周地雷数量为0，那么就将这个点标记为```B```，并将四周没有处理过的点入队
   + 如果该点四周地雷数量不为0，那么就将这个点标记为四周地雷的数量

然后问题就解决了。

**细节问题：**

关于上文中“四周没有处理过的点”，我们可以用哈希表解决。因为棋盘的大小最大为$50\times50$，因此我们可以将横纵坐标压缩为一个数：$横坐标\times100+纵坐标$。这样，我们就可以使用哈希表```unordered_set<int>```来记录某个点是否已经处理过。

+ 时间复杂度$O(nm)$，其中$size(borad) = n\times m$
+ 空间复杂度$O(nm)$，这实际上取决于点击位置相连的“四周地雷总数为0”的方块数量

### AC代码

#### C++

```cpp
class Solution {
private:
    int nearby(vector<vector<char>>& board, vector<int>& click) {
        int ans = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int ti = click[0] + i;
                int tj = click[1] + j;
                if (ti >= 0 && ti < board.size() && tj >= 0 && tj < board[0].size()) {
                    ans += board[ti][tj] == 'M';
                }
            }
        }
        return ans;
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board[click[0]][click[1]] == 'M')
            board[click[0]][click[1]] = 'X';
        else {
            queue<vector<int>> q;
            q.push(click);
            unordered_set<int> already;
            already.insert(click[0] * 100 + click[1]);
            while (q.size()) {
                vector<int> thisPoint = q.front();
                q.pop();
                int aroundMine = nearby(board, thisPoint);
                if (aroundMine)
                    board[thisPoint[0]][thisPoint[1]] = '0' + aroundMine;
                else {
                    board[thisPoint[0]][thisPoint[1]] = 'B';
                    for (int i = -1; i <= 1; i++) {
                        for (int j = -1; j <= 1; j++) {
                            int ti = thisPoint[0] + i;
                            int tj = thisPoint[1] + j;
                            if (ti >= 0 && ti < board.size() && tj >= 0 && tj < board[0].size()) {
                                if (!already.count(ti * 100 + tj)) {
                                    already.insert(ti * 100 + tj);
                                    q.push({ti, tj});
                                }
                            }
                        }
                    }
                }
            }
        }
        return board;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/11/23/LeetCode%200529.%E6%89%AB%E9%9B%B7%E6%B8%B8%E6%88%8F/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127997191](https://letmefly.blog.csdn.net/article/details/127997191)
