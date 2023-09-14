---
title: 1222.可以攻击国王的皇后
date: 2023-09-14 10:11:35
tags: [题解, LeetCode, 中等, 数组, 矩阵, 模拟, 哈希表, 哈希, set]
---

# 【LetMeFly】1222.可以攻击国王的皇后

力扣题目链接：[https://leetcode.cn/problems/queens-that-can-attack-the-king/](https://leetcode.cn/problems/queens-that-can-attack-the-king/)

<p>在一个&nbsp;<strong>8x8</strong>&nbsp;的棋盘上，放置着若干「黑皇后」和一个「白国王」。</p>

<p>给定一个由整数坐标组成的数组&nbsp;<code>queens</code>&nbsp;，表示黑皇后的位置；以及一对坐标&nbsp;<code>king</code> ，表示白国王的位置，返回所有可以攻击国王的皇后的坐标(任意顺序)。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/10/13/untitled-diagram.jpg" /></p>

<pre>
<strong>输入：</strong>queens = [[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]], king = [0,0]
<strong>输出：</strong>[[0,1],[1,0],[3,3]]
<strong>解释：</strong> 
[0,1] 的皇后可以攻击到国王，因为他们在同一行上。 
[1,0] 的皇后可以攻击到国王，因为他们在同一列上。 
[3,3] 的皇后可以攻击到国王，因为他们在同一条对角线上。 
[0,4] 的皇后无法攻击到国王，因为她被位于 [0,1] 的皇后挡住了。 
[4,0] 的皇后无法攻击到国王，因为她被位于 [1,0] 的皇后挡住了。 
[2,4] 的皇后无法攻击到国王，因为她和国王不在同一行/列/对角线上。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/10/13/untitled-diagram-1.jpg" /></strong></p>

<pre>
<strong>输入：</strong>queens = [[0,0],[1,1],[2,2],[3,4],[3,5],[4,4],[4,5]], king = [3,3]
<strong>输出：</strong>[[2,2],[3,4],[4,4]]
</pre>

<p><strong>示例 3：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/10/13/untitled-diagram-2.jpg" /></strong></p>

<pre>
<strong>输入：</strong>queens = [[5,6],[7,7],[2,1],[0,7],[1,6],[5,1],[3,7],[0,3],[4,0],[1,2],[6,3],[5,0],[0,4],[2,2],[1,1],[6,4],[5,4],[0,0],[2,6],[4,5],[5,2],[1,4],[7,5],[2,3],[0,5],[4,2],[1,0],[2,7],[0,1],[4,6],[6,1],[0,6],[4,3],[1,7]], king = [3,4]
<strong>输出：</strong>[[2,3],[1,4],[1,6],[3,7],[4,3],[5,4],[4,5]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= queens.length&nbsp;&lt;= 63</code></li>
	<li><code>queens[i].length == 2</code></li>
	<li><code>0 &lt;= queens[i][j] &lt;&nbsp;8</code></li>
	<li><code>king.length == 2</code></li>
	<li><code>0 &lt;= king[0], king[1] &lt; 8</code></li>
	<li>一个棋盘格上最多只能放置一枚棋子。</li>
</ul>


    
## 方法一：哈希 + 模拟

> 皇后可以八个方向移动（↑↓←→↖↙↗↘），不能跳过其他棋子。

首先将所有的“皇后”的位置放入哈希表中，以便$O(1)$的时间复杂度查询某个位置是否有皇后。

接着从国王位置开始往8个方向遍历，遍历到皇后或超出棋盘边界为止。若遇到皇后，则加入到答案中。

+ 时间复杂度$O(C^2)$，其中$C=8$
+ 空间复杂度$O(len(queen))$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        unordered_set<int> se;
        for (auto& q : queens) {
            se.insert(q[0] * 100 + q[1]);
        }

        vector<vector<int>> ans;
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (!dx && !dy) {
                    continue;
                }
                int nowX = king[0], nowY = king[1];
                while (nowX + dx >= 0 && nowX + dx < 8 && nowY + dy >= 0 && nowY + dy < 8) {
                    nowX += dx, nowY += dy;
                    if (se.count(nowX * 100 + nowY)) {
                        ans.push_back({nowX, nowY});
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def queensAttacktheKing(self, queens: List[List[int]], king: List[int]) -> List[List[int]]:
        se = set(map(tuple, queens))
        ans = []
        for dx in range(-1, 2):
            for dy in range(-1, 2):
                if not dx and not dy:
                    continue
                nowX, nowY = king
                while 0 <= nowX + dx < 8 and 0 <= nowY + dy < 8:
                    nowX, nowY = nowX + dx, nowY + dy
                    if (nowX, nowY) in se:
                        ans.append([nowX, nowY])
                        break
        return ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2023/09/14/LeetCode%201222.%E5%8F%AF%E4%BB%A5%E6%94%BB%E5%87%BB%E5%9B%BD%E7%8E%8B%E7%9A%84%E7%9A%87%E5%90%8E/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/132870626](https://letmefly.blog.csdn.net/article/details/132870626)
