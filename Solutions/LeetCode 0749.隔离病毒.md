---
title: 749.隔离病毒
date: 2022-07-18 11:11:24
tags: [题解, LeetCode, 困难, 深度优先搜索, 广度优先搜索, 数组, 矩阵, 模拟, 大模拟, BFS, 多重BFS, 哈希, set]
---

# 【LetMeFly】749.隔离病毒 - 大模拟

力扣题目链接：[https://leetcode.cn/problems/contain-virus/](https://leetcode.cn/problems/contain-virus/)

<p>病毒扩散得很快，现在你的任务是尽可能地通过安装防火墙来隔离病毒。</p>

<p>假设世界由&nbsp;<code>m x n</code>&nbsp;的二维矩阵&nbsp;<code>isInfected</code>&nbsp;组成，&nbsp;<code>isInfected[i][j] == 0</code>&nbsp;表示该区域未感染病毒，而 &nbsp;<code>isInfected[i][j] == 1</code>&nbsp;表示该区域已感染病毒。可以在任意 2 个相邻单元之间的共享边界上安装一个防火墙（并且只有一个防火墙）。</p>

<p>每天晚上，病毒会从被感染区域向相邻未感染区域扩散，除非被防火墙隔离。现由于资源有限，每天你只能安装一系列防火墙来隔离其中一个被病毒感染的区域（一个区域或连续的一片区域），且该感染区域对未感染区域的威胁最大且 <strong>保证唯一&nbsp;</strong>。</p>

<p>你需要努力使得最后有部分区域不被病毒感染，如果可以成功，那么返回需要使用的防火墙个数; 如果无法实现，则返回在世界被病毒全部感染时已安装的防火墙个数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2021/06/01/virus11-grid.jpg" style="height: 255px; width: 500px;" /></p>

<pre>
<strong>输入:</strong> isInfected = [[0,1,0,0,0,0,0,1],[0,1,0,0,0,0,0,1],[0,0,0,0,0,0,0,1],[0,0,0,0,0,0,0,0]]
<strong>输出:</strong> 10
<strong>解释:</strong>一共有两块被病毒感染的区域。
在第一天，添加 5 墙隔离病毒区域的左侧。病毒传播后的状态是:
<img src="653" />
第二天，在右侧添加 5 个墙来隔离病毒区域。此时病毒已经被完全控制住了。
<img src="https://assets.leetcode.com/uploads/2021/06/01/virus13edited-grid.jpg" style="height: 261px; width: 500px;" />
</pre>

<p><strong>示例 2：</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2021/06/01/virus2-grid.jpg" style="height: 253px; width: 653px;" /></p>

<pre>
<strong>输入:</strong> isInfected = [[1,1,1],[1,0,1],[1,1,1]]
<strong>输出:</strong> 4
<strong>解释:</strong> 虽然只保存了一个小区域，但却有四面墙。
注意，防火墙只建立在两个不同区域的共享边界上。
</pre>

<p><strong>示例&nbsp;3:</strong></p>

<pre>
<strong>输入:</strong> isInfected = [[1,1,1,0,0,0,0,0,0],[1,0,1,0,1,1,1,1,1],[1,1,1,0,0,0,0,0,0]]
<strong>输出:</strong> 13
<strong>解释:</strong> 在隔离右边感染区域后，隔离左边病毒区域只需要 2 个防火墙。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>m ==&nbsp;isInfected.length</code></li>
	<li><code>n ==&nbsp;isInfected[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>isInfected[i][j]</code>&nbsp;is either&nbsp;<code>0</code>&nbsp;or&nbsp;<code>1</code></li>
	<li>在整个描述的过程中，总有一个相邻的病毒区域，它将在下一轮 <strong>严格地感染更多未受污染的方块</strong>&nbsp;</li>
</ul>

<p>&nbsp;</p>


    
## 方法一：多重DFS

### 大致思路

不断重复下面循环，直到没有待隔离的病毒为止

+ 广搜确定不同区域的：待感染区域的面积、隔离此区域所需要的隔离墙的数量
+ 隔离这个病毒区

### 具体实现

用不同的数字代表地图中不同的状态：

```
0: 空地
1: 活の病毒
2: 被控制の病毒
```

然后一个死循环，每次控制一个病毒区域。如果已经没有活病毒了，就推出循环。

```cpp
while (true) {
    bool has1 = false;
    
	// 这里进行病毒隔离操作，同时如果还有活病毒(1)，就把has1标记为true

    if (!has1)
        break;
}
```

至于控制活病毒的部分，需要几个变量：

```cpp
int max1adjacent = 0;  // 活病毒的最大相邻待感染区域的大小
map<int, pair<int, int>> area2loc;  // [<待感染区域的面积, 其中一个活病毒的坐标>]
map<pair<int, int>, int> loc2wallNum;  // [<活病毒的坐标, 需要添加的墙的数量>]
vector<vector<bool>> visited(n, vector<bool>(m, false));  // 哪个区域被遍历过了
```

这样就可以在遍历完成之时，立刻得到这次要控制的位置，以及这次控制需要安装多少隔离墙。

遍历的方法为：

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        if (isInfected[i][j] == 1 && !visited[i][j]) {  // 这是一个活病毒的位置 && 这个区域还没有被遍历过
            has1 = true;
            visited[i][j] = true;
            pair<int, int> oneOfThisArea = {i, j};
            int thisAdjacent = 0;  // 这个待感染区域的大小
            int thisWallNum = 0;  // 控制这个区域的话，需要安装隔离墙的数量
            set<pair<int, int>> counted;  // 已经统计过的待感染区域  // 注意不能通过将visited标记为true的方式来判断某个待感染区域是否被统计过，因为待感染区域对于不同的病毒块互不影响
			
			// 这里进行BFS，同时记录这片区域的待感染区域的大小、需要安装隔离墙的数量

            max1adjacent = max(max1adjacent, thisAdjacent);
            area2loc[thisAdjacent] = oneOfThisArea;
            loc2wallNum[oneOfThisArea] = thisWallNum;
        }
    }
}
```

具体BFS方法为：

```cpp
queue<pair<int, int>> q;
q.push({i, j});
while (q.size()) {
    auto[x, y] = q.front();
    q.pop();
    for (int d = 0; d < 4; d++) {
        int tx = x + direction[d][0];
        int ty = y + direction[d][1];
        if (tx >= 0 && tx < n && ty > 0 && ty < m) {  // 下一个单元在合法范围内
            if (isInfected[tx][ty] == 1 && !visited[tx][ty]) {  // 下一个单元是未被标记的病毒
                visited[tx][ty] = true;
                q.push({tx, ty});
            }
            else if (isInfected[tx][ty] == 0) {  // 下一个单元格是待感染区域
                thisWallNum++;  // 不论这个待感染区域是否被统计过，都要安装隔离墙（区域只统计一次，但隔离墙最多要安装4面）
                if (!visited[tx][ty]) {  // 这个区域还未被统计过
                    visited[tx][ty] = true;
                    thisAdjacent++;
                }                                        
            }
        }
    }
}
```

这样，遍历完成后，我们就知道了最大的待感染面积 及其 对应的感染区域的某个病毒的位置，然后就把它们标记为2（隔离过了）

```cpp
if (!max1adjacent) {  // 待感染区域面积为0，说明没有活病毒了或者全部被病毒感染了（其实似乎不用has1
变量即可）
    break;
}

pair<int, int> oneOfThisArea = area2loc[max1adjacent];
ans += loc2wallNum[oneOfThisArea];

// 再次BFS标记此区域病毒为已隔离
// 其他区域扩散
```

具体BFS方法为：

```cpp
queue<pair<int, int>> q;
q.push(oneOfThisArea);
isInfected[oneOfThisArea.first][oneOfThisArea.second] = 2;
while (q.size()) {
    auto[x, y] = q.front();
    q.pop();
    for (int d = 0; d < 4; d++) {
        int tx = x + direction[d][0];
        int ty = y + direction[d][1];
        if (tx >= 0 && tx < n && ty > 0 && ty < m) {
            if (isInfected[tx][ty] == 1) {
                isInfected[tx][ty] = 2;
                q.push({tx, ty});
            }
        }
    }
}
```

其他区域扩散的具体实现为：

#### 方法一

```cpp
visited = vector<vector<bool>>(n, vector<bool>(m, false));
for (int x = 0; x < n; x++) {
    for (int y = 0; y < m; y++) {
        if (isInfected[x][y] == 1 && !visited[x][y]) {
            visited[x][y] = true;
            q.push({x, y})                        ;
            while (q.size()) {
                auto[x, y] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int tx = x + direction[d][0];
                    int ty = y + direction[d][1];
                    if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
                        if (isInfected[tx][ty] == 0) {  // 空地
                            isInfected[tx][ty] = 1;
                            visited[tx][ty] = true;  // 防止继续感染拓展
                        }
                        else if (isInfected[tx][ty] == 1 && !visited[tx][ty]) {  // 还是病毒 && 还未被处理过
                            visited[tx][ty] = true;
                            q.push({tx, ty});
                        }
                    }
                }
            }
        }
    }
}
```

#### 方法二

其实这次就没必要再搜索了

```cpp
visited = vector<vector<bool>>(n, vector<bool>(m, false));
for (int x = 0; x < n; x++) {
    for (int y = 0; y < m; y++) {
        if (isInfected[x][y] == 1 && !visited[x][y]) {
            visited[x][y] = true;
            for (int d = 0; d < 4; d++) {
                int tx = x + direction[d][0];
                int ty = y + direction[d][1];
                if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
                    if (isInfected[tx][ty] == 0) {
                        isInfected[tx][ty] = 1;
                        visited[tx][ty] = true;
                    }
                }
            }
        }
    }
}
```

+ 时间复杂度$O(nm)$
+ 空间复杂度$O(nm)$

### AC代码

#### C++

```cpp
/*
    0: 空地
    1: 活の病毒
    2: 被控制の病毒
*/
const int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
private:
    int ans = 0;
public:
    int containVirus(vector<vector<int>>& isInfected) {
        int n = isInfected.size();
        int m = isInfected[0].size();
        while (true) {
            bool has1 = false;

            int max1adjacent = 0;  // 活病毒的最大相邻待感染区域的大小
            map<int, pair<int, int>> area2loc;  // [<待感染区域的面积, 其中一个活病毒的坐标>]
            map<pair<int, int>, int> loc2wallNum;  // [<活病毒的坐标, 需要添加的墙的数量>]
            vector<vector<bool>> visited(n, vector<bool>(m, false));  // 哪个区域被遍历过了
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (isInfected[i][j] == 1 && !visited[i][j]) {  // 这是一个活病毒的位置 && 这个区域还没有被遍历过
                        has1 = true;
                        visited[i][j] = true;
                        pair<int, int> oneOfThisArea = {i, j};
                        int thisAdjacent = 0;  // 这个待感染区域的大小
                        int thisWallNum = 0;  // 控制这个区域的话，需要安装隔离墙的数量
                        set<pair<int, int>> counted;  // 已经统计过的待感染区域  // 注意不能通过将visited标记为true的方式来判断某个待感染区域是否被统计过，因为待感染区域对于不同的病毒块互不影响

                        queue<pair<int, int>> q;
                        q.push({i, j});
                        while (q.size()) {
                            auto[x, y] = q.front();
                            q.pop();
                            for (int d = 0; d < 4; d++) {
                                int tx = x + direction[d][0];
                                int ty = y + direction[d][1];
                                if (tx >= 0 && tx < n && ty >= 0 && ty < m) {  // 下一个单元在合法范围内
                                    if (isInfected[tx][ty] == 1 && !visited[tx][ty]) {  // 下一个单元是未被标记的病毒
                                        visited[tx][ty] = true;
                                        q.push({tx, ty});
                                    }
                                    else if (isInfected[tx][ty] == 0) {  // 下一个单元格是待感染区域
                                        thisWallNum++;  // 不论这个待感染区域是否被统计过，都要安装隔离墙（区域只统计一次，但隔离墙最多要安装4面）
                                        if (!counted.count({tx, ty})) {  // 这个区域还未被统计过
                                            counted.insert({tx, ty});
                                            thisAdjacent++;
                                        }                                        
                                    }
                                }
                            }
                        }

                        max1adjacent = max(max1adjacent, thisAdjacent);
                        area2loc[thisAdjacent] = oneOfThisArea;
                        loc2wallNum[oneOfThisArea] = thisWallNum;
                    }
                }
            }
            if (!max1adjacent) {  // 待感染区域面积为0，说明没有活病毒了或者全部被病毒感染了（其实似乎不用has1变量即可）
                break;
            }
            pair<int, int> oneOfThisArea = area2loc[max1adjacent];
            ans += loc2wallNum[oneOfThisArea];

            queue<pair<int, int>> q;
            q.push(oneOfThisArea);
            isInfected[oneOfThisArea.first][oneOfThisArea.second] = 2;
            while (q.size()) {
                auto[x, y] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int tx = x + direction[d][0];
                    int ty = y + direction[d][1];
                    if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
                        if (isInfected[tx][ty] == 1) {
                            isInfected[tx][ty] = 2;
                            q.push({tx, ty});
                        }
                    }
                }
            }

            visited = vector<vector<bool>>(n, vector<bool>(m, false));
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    if (isInfected[x][y] == 1 && !visited[x][y]) {
                        visited[x][y] = true;
                        for (int d = 0; d < 4; d++) {
                            int tx = x + direction[d][0];
                            int ty = y + direction[d][1];
                            if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
                                if (isInfected[tx][ty] == 0) {
                                    isInfected[tx][ty] = 1;
                                    visited[tx][ty] = true;
                                }
                            }
                        }
                    }
                }
            }

            if (!has1)
                break;
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/07/18/LeetCode%200749.%E9%9A%94%E7%A6%BB%E7%97%85%E6%AF%92/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125846470](https://letmefly.blog.csdn.net/article/details/125846470)
