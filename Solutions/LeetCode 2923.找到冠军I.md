---
title: 2923.找到冠军 I
date: 2024-04-12 13:53:33
tags: [题解, LeetCode, 简单, 数组, 矩阵, 模拟, 遍历]
categories: [题解, LeetCode]
---

# 【LetMeFly】2923.找到冠军 I：O(n^2)和O(n)的做法

力扣题目链接：[https://leetcode.cn/problems/find-champion-i/](https://leetcode.cn/problems/find-champion-i/)

<p>一场比赛中共有 <code>n</code> 支队伍，按从 <code>0</code> 到&nbsp; <code>n - 1</code> 编号。</p>

<p>给你一个下标从 <strong>0</strong> 开始、大小为 <code>n * n</code> 的二维布尔矩阵 <code>grid</code> 。对于满足&nbsp;<code>0 &lt;= i, j &lt;= n - 1</code> 且 <code>i != j</code> 的所有 <code>i, j</code> ：如果 <code>grid[i][j] == 1</code>，那么 <code>i</code> 队比 <code>j</code> 队 <strong>强</strong> ；否则，<code>j</code> 队比 <code>i</code> 队 <strong>强</strong> 。</p>

<p>在这场比赛中，如果不存在某支强于 <code>a</code> 队的队伍，则认为 <code>a</code> 队将会是 <strong>冠军</strong> 。</p>

<p>返回这场比赛中将会成为冠军的队伍。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>grid = [[0,1],[0,0]]
<strong>输出：</strong>0
<strong>解释：</strong>比赛中有两支队伍。
grid[0][1] == 1 表示 0 队比 1 队强。所以 0 队是冠军。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>grid = [[0,0,1],[1,0,1],[0,0,0]]
<strong>输出：</strong>1
<strong>解释：</strong>比赛中有三支队伍。
grid[1][0] == 1 表示 1 队比 0 队强。
grid[1][2] == 1 表示 1 队比 2 队强。
所以 1 队是冠军。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>2 &lt;= n &lt;= 100</code></li>
	<li><code>grid[i][j]</code> 的值为 <code>0</code> 或 <code>1</code><meta charset="UTF-8" /></li>
	<li>对于所有&nbsp;<code>i</code>，<code> grid[i][i]</code>&nbsp;等于&nbsp;<code>0.</code></li>
	<li>对于满足&nbsp;<code>i != j</code> 的所有 <code>i, j</code> ，<code>grid[i][j] != grid[j][i]</code> 均成立</li>
	<li>生成的输入满足：如果 <code>a</code> 队比 <code>b</code> 队强，<code>b</code> 队比 <code>c</code> 队强，那么 <code>a</code> 队比 <code>c</code> 队强</li>
</ul>


    
## 方法一：O(n^2)的做法

冠军队伍```⇔```没有能胜过它的队伍。

因此我们只需要遍历每一列，如果哪一列全是$0$，那么这一对就是冠军。

+ 时间复杂度$O(n^2)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int j = 0; j < n; j++) {
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (grid[i][j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                return j;
            }
        }
        return -1;  // Fake Return
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def findChampion(self, grid: List[List[int]]) -> int:
        n = len(grid)
        for j in range(n):
            ok = True
            for i in range(n):
                if grid[i][j]:
                    ok = False
                    break
            if ok:
                return j
        return -1  # Fake Return
```

## 方法二：O(n)的做法

这题需要明白的是：所有队伍之间的能力值是“绝对的”，比的就是数值，不存在a克制b而b克制c而c克制a的情况。并且可以认为每个队伍的“能力值”各不相同。

这样，不妨假设冠军队伍是$ans=0$，接着我们只需要用变量$i$从$1$遍历到$n-1$，如果$i$剩余$ans$（$grid[i][ans]=1$），则将$ans$替换为$i$。

这样，遍历结束后的$ans$即为唯一全胜的队伍，也就是冠军。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 1; i < grid.size(); i++) {
            if (grid[i][ans]) {
                ans = i;
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
    def findChampion(self, grid: List[List[int]]) -> int:
        ans = 0
        for i in range(len(grid)):
            if grid[i][ans]:
                ans = i
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/04/12/LeetCode%202923.%E6%89%BE%E5%88%B0%E5%86%A0%E5%86%9BI/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/137678593](https://letmefly.blog.csdn.net/article/details/137678593)
