---
title: 542.01 矩阵
date: 2022-12-04 17:52:36
tags: [题解, LeetCode, 中等, 广度优先搜索, 数组, 动态规划, 矩阵, BFS]
categories: [题解, LeetCode]
---

# 【LetMeFly】542.01 矩阵

力扣题目链接：[https://leetcode.cn/problems/01-matrix/](https://leetcode.cn/problems/01-matrix/)

<p>给定一个由 <code>0</code> 和 <code>1</code> 组成的矩阵 <code>mat</code> ，请输出一个大小相同的矩阵，其中每一个格子是 <code>mat</code> 中对应位置元素到最近的 <code>0</code> 的距离。</p>

<p>两个相邻元素间的距离为 <code>1</code> 。</p>

<p> </p>

<p><b>示例 1：</b></p>

<p><img alt="" src="https://pic.leetcode-cn.com/1626667201-NCWmuP-image.png" style="width: 150px; " /></p>

<pre>
<strong>输入：</strong>mat =<strong> </strong>[[0,0,0],[0,1,0],[0,0,0]]
<strong>输出：</strong>[[0,0,0],[0,1,0],[0,0,0]]
</pre>

<p><b>示例 2：</b></p>

<p><img alt="" src="https://pic.leetcode-cn.com/1626667205-xFxIeK-image.png" style="width: 150px; " /></p>

<pre>
<b>输入：</b>mat =<b> </b>[[0,0,0],[0,1,0],[1,1,1]]
<strong>输出：</strong>[[0,0,0],[0,1,0],[1,2,1]]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 <= m, n <= 10<sup>4</sup></code></li>
	<li><code>1 <= m * n <= 10<sup>4</sup></code></li>
	<li><code>mat[i][j] is either 0 or 1.</code></li>
	<li><code>mat</code> 中至少有一个 <code>0 </code></li>
</ul>


    
## 方法一：广度优先搜索

首先遍历原始矩阵，找到所有的0，将其位置入队。

接着在队列不为空时，不断出队一个位置，并判断这个位置的上下左右是否被遍历过。

如果还没有被遍历过，那么就将新的位置入队。并将地图中新的位置的值修改为“出队位置的值 + 1”

**原理：**

所有的原始的0最终结果都是0。广度优先搜索就是在所有的“0”的位置中，走一步。这一步所到的位置就是“1”步能到达的位置。同理，“1”经过一步到达的位置就是“2”。最先到达的就是步数最少的。

+ 时间复杂度$O(nm)$
+ 空间复杂度$O(nm)$

### AC代码

#### C++

```cpp
typedef pair<int, int> pii;
const int direcitons[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pii> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!mat[i][j]) {
                    visited[i][j] = true;
                    q.push({i, j});
                }
            }
        }
        while (q.size()) {
            pii thisNode = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int tx = thisNode.first + direcitons[d][0];
                int ty = thisNode.second + direcitons[d][1];
                if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
                    if (!visited[tx][ty]) {
                        visited[tx][ty] = true;
                        mat[tx][ty] = mat[thisNode.first][thisNode.second] + 1;
                        q.push({tx, ty});
                    }
                }
            }
        }
        return mat;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/12/04/LeetCode%200542.01%E7%9F%A9%E9%98%B5/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128175163](https://letmefly.blog.csdn.net/article/details/128175163)
