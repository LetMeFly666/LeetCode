---
title: 1349.参加考试的最大学生数
date: 2023-12-26 10:43:51
tags: [题解, LeetCode, 困难, 位运算, 数组, 动态规划, 状态压缩, 矩阵, 深度优先搜索, DFS, 记忆化搜索]
categories: [题解, LeetCode]
---

# 【LetMeFly】1349.参加考试的最大学生数：状态压缩 + 记忆化搜索

力扣题目链接：[https://leetcode.cn/problems/maximum-students-taking-exam/](https://leetcode.cn/problems/maximum-students-taking-exam/)

<p>给你一个&nbsp;<code>m&nbsp;* n</code>&nbsp;的矩阵 <code>seats</code>&nbsp;表示教室中的座位分布。如果座位是坏的（不可用），就用&nbsp;<code>&#39;#&#39;</code>&nbsp;表示；否则，用&nbsp;<code>&#39;.&#39;</code>&nbsp;表示。</p>

<p>学生可以看到左侧、右侧、左上、右上这四个方向上紧邻他的学生的答卷，但是看不到直接坐在他前面或者后面的学生的答卷。请你计算并返回该考场可以容纳的一起参加考试且无法作弊的最大学生人数。</p>

<p>学生必须坐在状况良好的座位上。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/02/09/image.png" style="height: 197px; width: 339px;"></p>

<pre><strong>输入：</strong>seats = [[&quot;#&quot;,&quot;.&quot;,&quot;#&quot;,&quot;#&quot;,&quot;.&quot;,&quot;#&quot;],
&nbsp;             [&quot;.&quot;,&quot;#&quot;,&quot;#&quot;,&quot;#&quot;,&quot;#&quot;,&quot;.&quot;],
&nbsp;             [&quot;#&quot;,&quot;.&quot;,&quot;#&quot;,&quot;#&quot;,&quot;.&quot;,&quot;#&quot;]]
<strong>输出：</strong>4
<strong>解释：</strong>教师可以让 4 个学生坐在可用的座位上，这样他们就无法在考试中作弊。 
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>seats = [[&quot;.&quot;,&quot;#&quot;],
&nbsp;             [&quot;#&quot;,&quot;#&quot;],
&nbsp;             [&quot;#&quot;,&quot;.&quot;],
&nbsp;             [&quot;#&quot;,&quot;#&quot;],
&nbsp;             [&quot;.&quot;,&quot;#&quot;]]
<strong>输出：</strong>3
<strong>解释：</strong>让所有学生坐在可用的座位上。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>seats = [[&quot;#&quot;,&quot;.&quot;,&quot;<strong>.</strong>&quot;,&quot;.&quot;,&quot;#&quot;],
&nbsp;             [&quot;<strong>.</strong>&quot;,&quot;#&quot;,&quot;<strong>.</strong>&quot;,&quot;#&quot;,&quot;<strong>.</strong>&quot;],
&nbsp;             [&quot;<strong>.</strong>&quot;,&quot;.&quot;,&quot;#&quot;,&quot;.&quot;,&quot;<strong>.</strong>&quot;],
&nbsp;             [&quot;<strong>.</strong>&quot;,&quot;#&quot;,&quot;<strong>.</strong>&quot;,&quot;#&quot;,&quot;<strong>.</strong>&quot;],
&nbsp;             [&quot;#&quot;,&quot;.&quot;,&quot;<strong>.</strong>&quot;,&quot;.&quot;,&quot;#&quot;]]
<strong>输出：</strong>10
<strong>解释：</strong>让学生坐在第 1、3 和 5 列的可用座位上。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>seats</code>&nbsp;只包含字符&nbsp;<code>&#39;.&#39;&nbsp;和</code><code>&#39;#&#39;</code></li>
	<li><code>m ==&nbsp;seats.length</code></li>
	<li><code>n ==&nbsp;seats[i].length</code></li>
	<li><code>1 &lt;= m &lt;= 8</code></li>
	<li><code>1 &lt;= n &lt;= 8</code></li>
</ul>


    
## 方法一：状态压缩 + 记忆化搜索

写一个函数```dfs(row, status)```，用来计算第row行的“坐人情况的二进制串”为status的情况下，前row行最多坐多少人。

如果我们实现了这个函数，那么直接返回最后一行 ```1 << n```个状态的```dfs```最大值即为答案。所以这个函数怎么实现呢？

1. 首先判断status的合法性：不能坐在坏座位上、不能两个人挨着坐。
2. 当前状态下的最大值，等于上一行所有状态（不用特别考虑上一行是否是合法状态，因为若不合法则dfs会返回极小值）下的最大值，加上这一行当前状态下的人数
3. 在第2步的“上一行状态”中，需要满足：上一行和这一行没有“斜对面”关系

+ 时间复杂度$O(mn\times 2^{2n})$，其中$seats$为$m$行$n$列。状态数共有$m\times 2^n$种（dfs的参数），计算一个状态复杂度$n\times 2^n$
+ 空间复杂度$O(m\times 2^n)$

### AC代码

#### C++

```cpp
class Solution {
private:
    int m, n;
    vector<vector<char>> seats;
    unordered_map<int, int> visited;

    bool isOkState(int row, int status) {
        // return true;
        for (int j = 0; j < n; j++) {
            if (!(status & (1 << j))) {
                continue;
            }
            // 二进制状态下这一位为1
            if (seats[row][j] == '#') {
                return false;
            }
            if (j > 0 && (status & (1 << (j - 1)))) {  // 相邻两个1
                return false;
            }
        }
        return true;
    }

    int dfs(int row, int status) {
        if (visited.count((row << n) + status)) {
            return visited[(row << n) + status];
        }
        if (!isOkState(row, status)) {
            return -1000;
        }
        int cnt1 = __builtin_popcount(status);
        if (!row) {
            return cnt1;
        }
        int ans = 0;
        for (int lastStatus = 0; lastStatus < (1 << n); lastStatus++) {
            for (int j = 0; j < n; j++) {
                if (j > 0 && (status & (1 << j)) && (lastStatus & (1 << (j - 1)))) {
                    goto loop;
                }
                if (j + 1 < n && (status & (1 << j)) && (lastStatus & (1 << (j + 1)))) {
                    goto loop;
                }
            }
            ans = max(ans, dfs(row - 1, lastStatus));
            loop:;
        }
        ans += cnt1;
        return visited[(row << n) + status] = ans;
    }
public:
    int maxStudents(vector<vector<char>>& seats) {
        this->seats = move(seats);
        m = this->seats.size(), n = this->seats[0].size();
        int ans = 0;
        for (int j = 0; j < (1 << n); j++) {
            ans = max(ans, dfs(m - 1, j));
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List
# from functools import cache

class Solution:
    @cache
    def dfs(self, row: int, status: int) -> int:
        for j in range(self.n):
            if not status & (1 << j):
                continue
            if self.seats[row][j] == '#':  # 坏椅子坐人
                return -1000
            if j > 0 and status & (1 << (j - 1)):  # 连续两人
                return -1000
        cnt1 = bin(status).count('1')
        if not row:
            return cnt1
        lastRowMax = 0
        for lastStatus in range(1 << self.n):
            ok = True
            for j in range(self.n):
                if j > 0 and status & (1 << j) and lastStatus & (1 << (j - 1)):
                    ok = False
                    break
                if j + 1 < self.n and status & (1 << j) and lastStatus & (1 << (j + 1)):
                    ok = False
                    break
            if ok:
                lastRowMax = max(lastRowMax, self.dfs(row - 1, lastStatus))
        return cnt1 + lastRowMax
    
    def maxStudents(self, seats: List[List[str]]) -> int:
        self.seats = seats
        self.m, self.n = len(seats), len(seats[0])
        ans = 0
        for status in range(1 << self.n):
            ans = max(ans, self.dfs(self.m - 1, status))
        return ans

```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/12/26/LeetCode%201349.%E5%8F%82%E5%8A%A0%E8%80%83%E8%AF%95%E7%9A%84%E6%9C%80%E5%A4%A7%E5%AD%A6%E7%94%9F%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135217045](https://letmefly.blog.csdn.net/article/details/135217045)
