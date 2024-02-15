---
title: 52.N皇后II
date: 2022-05-27 10:50:29
tags: [题解, LeetCode, 困难, N皇后, 回溯]
---

# 【LetMeFly】52.N皇后II

力扣题目链接：[https://leetcode.cn/problems/n-queens-ii/](https://leetcode.cn/problems/n-queens-ii/)

**n 皇后问题** 研究的是如何将```n```个皇后放置在```n×n```的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数```n```，返回所有不同的 **n 皇后问题**的解决方案的数量。

每一种解法包含一个不同的 **n 皇后问题**的棋子放置方案，该方案中```'Q'```和```'.'```分别代表了皇后和空位。

<a href="https://letmefly.xyz" title="LetMeFly">笔者</a>注：

> 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子

这个可能一些中国小朋友不知道，因此已经在Github提交[issue](https://github.com/LeetCode-Feedback/LeetCode-Feedback/issues/7434)啦

**示例 1:**

<img src="https://assets.leetcode.com/uploads/2020/11/13/queens.jpg">

```
输入：n = 4
输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
解释：如上图所示，4 皇后问题存在两个不同的解法。
```

**示例 2:**

```
输入：n = 1
输出：[["Q"]]
```

**提示:**

+ $1\leq n\leq 9$

# 题目大意

这题与“[LeetCode 51.N皇后](https://leetcode.cn/problems/n-queens/)”不同之处在于，此题不需要返回具体答案状态是什么，只需要返回答案数量即可。

# 思路

具体思路方法请见 [https://blog.letmefly.xyz/2022/05/27/LeetCode 0051.N皇后/](https://blog.letmefly.xyz/2022/05/27/LeetCode%200051.N%E7%9A%87%E5%90%8E/)

我们可以小修改[LeetCode 51.N皇后](https://blog.letmefly.xyz/2022/05/27/LeetCode%200051.N%E7%9A%87%E5%90%8E/)的代码:

首先不需要用字符表示棋盘了，我们可以使用布尔类型的数据来表示棋盘。true代表皇后，false代表空。

其次，我们不需要返回具体状态是什么了，因此只需要计数即可。

## 方法一：回溯

下面是具体实现，可多关注与[LeetCode 51.N皇后](https://blog.letmefly.xyz/2022/05/27/LeetCode%200051.N%E7%9A%87%E5%90%8E/)的不同之处。

+ 时间复杂度$O(n!)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
private:
    bool a[9][9] = {false};
    int ans = 0;
    int n;
    bool ifOk(int x, int y) {  // 往(x, y)放置一个皇后是否可行
        for (int j = 0; j < n; j++) {
            if (a[x][j]) {
                return false;
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[i][y]) {
                return false;
            }
        }
        for (int i = 0; i < n; i++) {
            // i + j = x + y
            int j = x + y - i;
            if (j >= 0 && j < n && a[i][j]) {
                return false;
            }
            // i - j = x - y
            j = i - x + y;
            if (j >= 0 && j < n && a[i][j]) {
                return false;
            }
        }
        return true;
    }
    void goon(int line) {  // 该放第line行了
        if (line >= n) {
            ans++;
            return;
        }
        for (int j = 0; j < n; j++) {
            if (ifOk(line, j)) {
                a[line][j] = true;
                goon(line + 1);
                a[line][j] = false;
            }
        }
    }
public:
    int totalNQueens(int n) {
        this->n = n;
        goon(0);
        return ans;
    }
};
```

#### Java

🔥 感谢 [@Fomalhaut🥝](https://leetcode.cn/u/Fomalhaut1998/)大佬 提供Java版本的代码~

```java
class Solution {
    char[][] board;
    int n;
    int res = 0;

    public int totalNQueens(int _n) {
        /*
        与51.N皇后十分类似:这题相比更简单
         */
        n = _n;
        board = new char[n][n];
        for (int i = 0; i < n; i++) {
            // '.'表示没有放置国王
            Arrays.fill(board[i], '.');
        }
        // 按照行的顺序进行遍历
        dfs(0);
        return res;
    }

    private void dfs(int r) {
        // 遍历到n,说明[0,n-1]行已经全部遍历完毕,合法结果+1
        if (r == n) res++;
        // 遍历第r行的所有列
        for (int c = 0; c < n; c++) {
            // 无效的直接跳过
            if (!valid(r, c)) continue;
            // 可以放置的在该处放置国王
            board[r][c] = 'Q';
            // 继续判断下一行(因为一行只能放一个)
            dfs(r + 1);
            // 撤回(回到原来这行肯定要删除掉刚刚标记的'Q')
            board[r][c] = '.';
        }
    }

    // 判定在[r,c]坐标放置国王是否合法(排除法)
    private boolean valid(int r, int c) {
        // 同一行必定不会重复放置(递归逻辑决定)
        // 因此只要判断列与两条斜边即可
        // 列[0,r-1]
        for (int i = 0; i < r; i++) {
            if (board[i][c] != '.') return false;
        }
        // 斜边:左上->右下
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] != '.') return false;
        }
        // 斜边:右上->左下
        for (int i = r - 1, j = c + 1; i >= 0 && j <= n - 1; i--, j++) {
            if (board[i][j] != '.') return false;
        }
        // 排除后的情形就是合法的
        return true;
    }
}
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/05/27/LeetCode%200051.N%E7%9A%87%E5%90%8E/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125000091](https://letmefly.blog.csdn.net/article/details/125000091)
