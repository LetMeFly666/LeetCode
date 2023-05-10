---
title: 827.最大人工岛
date: 2022-09-18 08:39:20
tags: [题解, LeetCode, 困难, 深度优先搜索, 广度优先搜索, 并查集, 数组, 矩阵, BFS, 图, 连通块, 哈希]
---

# 【LetMeFly】827.最大人工岛

力扣题目链接：[https://leetcode.cn/problems/making-a-large-island/](https://leetcode.cn/problems/making-a-large-island/)

<p>给你一个大小为 <code>n x n</code> 二进制矩阵 <code>grid</code> 。<strong>最多</strong> 只能将一格 <code>0</code> 变成 <code>1</code> 。</p>

<p>返回执行此操作后，<code>grid</code> 中最大的岛屿面积是多少？</p>

<p><strong>岛屿</strong> 由一组上、下、左、右四个方向相连的 <code>1</code> 形成。</p>

<p> </p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入: </strong>grid = [[1, 0], [0, 1]]
<strong>输出:</strong> 3
<strong>解释:</strong> 将一格0变成1，最终连通两个小岛得到面积为 3 的岛屿。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入: </strong>grid =<strong> </strong>[[1, 1], [1, 0]]
<strong>输出:</strong> 4
<strong>解释:</strong> 将一格0变成1，岛屿的面积扩大为 4。</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入: </strong>grid = [[1, 1], [1, 1]]
<strong>输出:</strong> 4
<strong>解释:</strong> 没有0可以让我们变成1，面积依然为 4。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 <= n <= 500</code></li>
	<li><code>grid[i][j]</code> 为 <code>0</code> 或 <code>1</code></li>
</ul>


    
## 方法一：深搜 + 哈希

对原始地图进行一次深搜，将不同的“岛屿”（连通块）标记为不同的编号。

同时，用哈希表记录每个编号对应的“岛屿”的面积。

之后再遍历一遍地图，如果某个小方格为0，就尝试把这个方格填平。

若填平，则其及其连通岛屿的面积和为：自己的面积（1） + 四周相连岛屿的面积（去重后，根据编号，通过哈希表快速求出某块的面积）

更新答案最大值。

具体细节请参考代码注释。

+ 时间复杂度$O(n^2)$
+ 空间复杂度$O(n^2)$

### AC代码

#### C++

```cpp
typedef pair<int, int> point;
const int directions[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int numTo = 2;  // 将不同岛屿进行编号（从2号开始编）
        unordered_map<int, int> num2area;  // 岛屿编号 -> 此岛面积
        num2area[0] = 0;  // “0号编号”的岛屿面积为0（其实0号就是水）
        int n = grid.size();
        for (int i = 0; i < n; i++) {  // 广搜开始
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {  // 新岛屿
                    int thisNum = numTo;  // 新岛屿的编号
                    numTo++;
                    int thisArea = 1;  // 新岛屿的面积
                    queue<point> points;  // 队列
                    points.push({i, j});
                    grid[i][j] = thisNum;
                    while (points.size()) {  // 不空时
                        point thisPoint = points.front();
                        points.pop();
                        for (int d = 0; d < 4; d++) {
                            int tx = thisPoint.first + directions[d][0];
                            int ty = thisPoint.second + directions[d][1];
                            if (tx >= 0 && tx < n && ty >= 0 && ty < n) {
                                if (grid[tx][ty] == 1) {
                                    grid[tx][ty] = thisNum;  // 同样编号
                                    points.push({tx, ty});  // 入队
                                    thisArea++;  // 面积+1
                                }
                            }
                        }
                    }
                    num2area[thisNum] = thisArea;  // 存入哈希表
                }
            }
        }
        if (numTo == 2)  // 没有岛屿被编号，也就是说全都是水
            return 1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> nearby;  // 哈希表去重
                    for (int d = 0; d < 4; d++) {  // 上下左右四周
                        int tx = i + directions[d][0];
                        int ty = j + directions[d][1];
                        if (tx >= 0 && tx < n && ty >= 0 && ty < n) {
                            nearby.insert(grid[tx][ty]);
                        }
                    }
                    int cnt = 1;
                    for (int num : nearby) {
                        cnt += num2area[num];
                    }
                    ans = max(ans, cnt);
                }
            }
        }
        return ans ? ans : n * n;  // 如果ans = 0，就说明本来就没有水。也就是说本来就全是陆地，因此岛屿面积为n^2
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/09/18/LeetCode%200827.%E6%9C%80%E5%A4%A7%E4%BA%BA%E5%B7%A5%E5%B2%9B/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126913736](https://letmefly.blog.csdn.net/article/details/126913736)
