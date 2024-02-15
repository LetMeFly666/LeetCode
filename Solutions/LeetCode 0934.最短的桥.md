---
title: 934.最短的桥
date: 2022-10-25 10:50:25
tags: [题解, LeetCode, 中等, 深度优先搜索, 广度优先搜索, BFS, 数组, 矩阵, 图]
---

# 【LetMeFly】934.最短的桥

力扣题目链接：[https://leetcode.cn/problems/shortest-bridge/](https://leetcode.cn/problems/shortest-bridge/)

<p>在给定的二维二进制数组 <code>A</code> 中，存在两座岛。（岛是由四面相连的 <code>1</code> 形成的一个最大组。）</p>

<p>现在，我们可以将 <code>0</code> 变为 <code>1</code>，以使两座岛连接起来，变成一座岛。</p>

<p>返回必须翻转的 <code>0</code> 的最小数目。（可以保证答案至少是 <code>1</code> 。）</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>A = [[0,1],[1,0]]
<strong>输出：</strong>1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>A = [[0,1,0],[0,0,0],[0,0,1]]
<strong>输出：</strong>2
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>A = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
<strong>输出：</strong>1</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= A.length == A[0].length <= 100</code></li>
	<li><code>A[i][j] == 0</code> 或 <code>A[i][j] == 1</code></li>
</ul>


    
## 方法一：广搜

在熟练掌握了图的搜索后，这道题也不难，两次搜索就可以了。

第一次搜索的时候，我们从任意一个“1”开始，当四联通（上下左右）还是1时，继续搜索，直到把一个“岛”搜完。

这样，我们就得到了一个完整的“岛”

第二次搜索的时候，我们从第一次得到的“岛”开始，一圈一圈地往外拓展。每走一步，答案加一。直到遇到新的“岛”为止

+ 时间复杂度$O(n^2)$，一共进行了两次搜索
+ 空间复杂度$O(n^2)$，空间复杂度主要来自队列

### AC代码

#### C++

```cpp
typedef pair<int, int> pii;
const static int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
class Solution {
private:
    // vector<vector<int>> distance;
    int n;

    queue<pii> getIslandBy1Node(int x, int y, vector<vector<int>>& grid) {
        grid[x][y] = -1;
        queue<pii> q, ans;
        q.push({x, y});
        ans.push({x, y});
        while (q.size()) {
            pii thisNode = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int tx = thisNode.first + directions[d][0];
                int ty = thisNode.second + directions[d][1];
                if (tx >= 0 && tx < n && ty >= 0 && ty < n) {
                    if (grid[tx][ty] == 1) {
                        grid[tx][ty] = -1;
                        q.push({tx, ty});
                        ans.push({tx, ty});
                    }
                }
            }
        }
        return ans;
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        // distance = vector<vector<int>>(n, vector<int>(n));
        queue<pii> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    q = getIslandBy1Node(i, j, grid);
                    goto loop;
                }
            }
        }
        loop:;
        int ans = 0;
        while (true) {
            for (int i = q.size(); i > 0; i--) {
                pii thisNode = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int tx = thisNode.first + directions[d][0];
                    int ty = thisNode.second + directions[d][1];
                    if (tx >= 0 && tx < n && ty >= 0 && ty < n) {
                        if (grid[tx][ty] == 1) {
                            return ans;
                        }
                        if (grid[tx][ty] == 0) {
                            grid[tx][ty] = -1;
                            q.push({tx, ty});
                        }
                    }
                }
            }
            ans++;
        }
        // return -1;  // FakeReturn
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/10/25/LeetCode%200934.%E6%9C%80%E7%9F%AD%E7%9A%84%E6%A1%A5/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127509391](https://letmefly.blog.csdn.net/article/details/127509391)
