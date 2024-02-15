---
title: 51.N皇后
date: 2022-05-27 10:25:01
tags: [题解, LeetCode, 困难, N皇后, 回溯]
---

# 【LetMeFly】51.N皇后

力扣题目链接：[https://leetcode.cn/problems/n-queens/](https://leetcode.cn/problems/n-queens/)

**n 皇后问题** 研究的是如何将```n```个皇后放置在```n×n```的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数```n```，返回所有不同的 **n 皇后问题**的解决方案。

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

给你一张```n×n```的棋盘，让你往上放置```n```个```皇后```。这些```皇后```满足：任意两皇后不在同一行、不在同一列、不在同一斜线上。

# 思路

我们可以定义一个函数```goon(int line)```，来在当前棋盘状态下，继续往第```line```行落子。

```cpp
void goon(int line) {  // 该放第line行了
    如果已经放满了：
        说明当前状态是一个可行的最终状态
        当前棋盘加入答案、结束递归

    否则：
        遍历这一行所有位置，看每个位置是否能放
        对于某个位置：
            如果能放：
                就放一个“皇后”
                继续递归模拟下一行
                模拟结束后撤销这个皇后，判断下一个位置是否可行
            否则：
                不做操作，继续判断下一个位置
}
```

至于上文中的“判断一个位置是否能放”，实现方法为：

```cpp
bool ifOk(int x, int y) {  // 往(x, y)放置一个皇后是否可行
    遍历这一行，如果已有皇后，就返回false
    
    遍历这一列，如果已有皇后，就返回false

    接下来是对角线上的位置。同一正对角线上的元素满足“横坐标-纵坐标值相等”，同一负对角线上的元素满足“横坐标+纵坐标值相等”。
    遍历每一行，求出这一行中和(x, y)位于同一对角线上的位置，如果已有皇后，就返回false
    
    如果前面都没有返回false，说明这是一个合法的位置，就return true;
}
```

## 方法一：回溯

思路中已经描述地差不多了，接下来就是具体实现可参考代码注释

+ 时间复杂度$O(n!)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
private:
    vector<string> a;
    vector<vector<string>> ans;
    int n;
    bool ifOk(int x, int y) {  // 往(x, y)放置一个皇后是否可行
        for (int j = 0; j < n; j++) {
            if (a[x][j] == 'Q') {
                return false;
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[i][y] == 'Q') {
                return false;
            }
        }
        for (int i = 0; i < n; i++) {
            // i + j = x + y
            int j = x + y - i;
            if (j >= 0 && j < n && a[i][j] == 'Q') {
                return false;
            }
            // i - j = x - y
            j = i - x + y;
            if (j >= 0 && j < n && a[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    void goon(int line) {  // 该放第line行了
        if (line >= n) {
            ans.push_back(a);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (ifOk(line, j)) {
                a[line][j] = 'Q';
                goon(line + 1);
                a[line][j] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        string oneLine(n, '.');
        // a = vector<string>(oneLine, n);
        for (int i = 0; i < n; i++) {
            a.push_back(oneLine);
        }
        goon(0);
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/05/27/LeetCode%200051.N%E7%9A%87%E5%90%8E/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/124999635](https://letmefly.blog.csdn.net/article/details/124999635)
