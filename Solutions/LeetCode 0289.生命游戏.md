---
title: 289.生命游戏
date: 2022-09-16 08:16:56
tags: [题解, LeetCode, 中等, 数组, 矩阵, 模拟, 原地]
categories: [题解, LeetCode]
---

# 【LetMeFly】289.生命游戏

力扣题目链接：[https://leetcode.cn/problems/game-of-life/](https://leetcode.cn/problems/game-of-life/)

<p>根据&nbsp;<a href="https://baike.baidu.com/item/%E7%94%9F%E5%91%BD%E6%B8%B8%E6%88%8F/2926434?fr=aladdin" target="_blank">百度百科</a>&nbsp;，&nbsp;<strong>生命游戏</strong>&nbsp;，简称为 <strong>生命</strong> ，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。</p>

<p>给定一个包含 <code>m × n</code>&nbsp;个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态： <code>1</code> 即为 <strong>活细胞</strong> （live），或 <code>0</code> 即为 <strong>死细胞</strong> （dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：</p>

<ol>
	<li>如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；</li>
	<li>如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；</li>
	<li>如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；</li>
	<li>如果死细胞周围正好有三个活细胞，则该位置死细胞复活；</li>
</ol>

<p>下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。给你 <code>m x n</code> 网格面板 <code>board</code> 的当前状态，返回下一个状态。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/26/grid1.jpg" />
<pre>
<strong>输入：</strong>board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
<strong>输出：</strong>[[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/26/grid2.jpg" />
<pre>
<strong>输入：</strong>board = [[1,1],[1,0]]
<strong>输出：</strong>[[1,1],[1,1]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == board.length</code></li>
	<li><code>n == board[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 25</code></li>
	<li><code>board[i][j]</code> 为 <code>0</code> 或 <code>1</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<ul>
	<li>你可以使用原地算法解决本题吗？请注意，面板上所有格子需要同时被更新：你不能先更新某些格子，然后使用它们的更新后的值再更新其他格子。</li>
	<li>本题中，我们使用二维数组来表示面板。原则上，面板是无限的，但当活细胞侵占了面板边界时会造成问题。你将如何解决这些问题？</li>
</ul>


    
## 方法一：额外空间

复制一份原始数组，然后按照题意进行模拟，统计一周的活细胞个数，并改变中间细胞的状态。

+ 时间复杂度$O(mn)$，其中地图的size为$m\times n$
+ 空间复杂度$O(mn)$

### AC代码

#### C++

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> a(board);
        int n = a.size(), m = a[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cnt = 0;
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        if (x || y) {
                            if (i + x >= 0 && i + x < n && j + y >= 0 && j + y < m) {
                                cnt += a[i + x][j + y];
                            }
                        }
                    }
                }
                if (a[i][j]) {
                    if (cnt < 2 || cnt > 3) {
                        board[i][j] = 0;
                    }
                }
                else {
                    if (cnt == 3) {
                        board[i][j] = 1;
                    }
                }
            }
        }
    }
};
```

## 方法二：原地修改

思路是充分利用原始空间。一个$int$是32位，但表示$0$和$1$只需要1位。

因此可以用$2$表示原本是$0$，现在是$1$；用$3$表示原本是$1$，现在是$0$。

这样，在统计过程中，就不会丢失原始数组中的信息。

最后，再遍历一遍数组，将$2$修改回$1$、$3$修改回$0$即可。

+ 时间复杂度$O(mn)$，其中地图的size为$m\times n$
+ 空间复杂度$O(1)$

就不放代码展示了。

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/09/16/LeetCode%200289.%E7%94%9F%E5%91%BD%E6%B8%B8%E6%88%8F/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126883144](https://letmefly.blog.csdn.net/article/details/126883144)
