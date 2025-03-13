---
title: 1267.统计参与通信的服务器
date: 2023-08-24 09:16:53
tags: [题解, LeetCode, 中等, 深度优先搜索, 广度优先搜索, 并查集, 数组, 计数, 矩阵, 哈希表, 哈希]
categories: [题解, LeetCode]
---

# 【LetMeFly】1267.统计参与通信的服务器

力扣题目链接：[https://leetcode.cn/problems/count-servers-that-communicate/](https://leetcode.cn/problems/count-servers-that-communicate/)

<p>这里有一幅服务器分布图，服务器的位置标识在&nbsp;<code>m * n</code>&nbsp;的整数矩阵网格&nbsp;<code>grid</code>&nbsp;中，1 表示单元格上有服务器，0 表示没有。</p>

<p>如果两台服务器位于同一行或者同一列，我们就认为它们之间可以进行通信。</p>

<p>请你统计并返回能够与至少一台其他服务器进行通信的服务器的数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/11/24/untitled-diagram-6.jpg" style="height: 203px; width: 202px;"></p>

<pre><strong>输入：</strong>grid = [[1,0],[0,1]]
<strong>输出：</strong>0
<strong>解释：</strong>没有一台服务器能与其他服务器进行通信。</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/11/24/untitled-diagram-4-1.jpg" style="height: 203px; width: 203px;"></strong></p>

<pre><strong>输入：</strong>grid = [[1,0],[1,1]]
<strong>输出：</strong>3
<strong>解释：</strong>所有这些服务器都至少可以与一台别的服务器进行通信。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/11/24/untitled-diagram-1-3.jpg" style="height: 443px; width: 443px;"></p>

<pre><strong>输入：</strong>grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
<strong>输出：</strong>4
<strong>解释：</strong>第一行的两台服务器互相通信，第三列的两台服务器互相通信，但右下角的服务器无法与其他服务器通信。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m &lt;= 250</code></li>
	<li><code>1 &lt;= n &lt;= 250</code></li>
	<li><code>grid[i][j] == 0 or 1</code></li>
</ul>


    
## 方法一：计数

假设$gird$的$size$为$n\times m$，开辟两个数组$row[n]$和$col[m]$，分别记录某行服务器个数 和 某列的服务器个数。

遍历一遍地图矩阵$grid$，若此处有服务器(server) 且 此行或此列不只一台服务器，则$ans++$

+ 时间复杂度$O(n\times m)$
+ 空间复杂度$O(n + m)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> row(n), col(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                row[i] += grid[i][j], col[j] += grid[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans += grid[i][j] * (row[i] > 1 || col[j] > 1);
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
    def countServers(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        col, row = [0] * n, [0] * m
        for i in range(n):
            for j in range(m):
                col[i] += grid[i][j]
                row[j] += grid[i][j]
        ans = 0
        for i in range(n):
            for j in range(m):
                ans += grid[i][j] * (col[i] > 1 or row[j] > 1)
        return ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/08/24/LeetCode%201267.%E7%BB%9F%E8%AE%A1%E5%8F%82%E4%B8%8E%E9%80%9A%E4%BF%A1%E7%9A%84%E6%9C%8D%E5%8A%A1%E5%99%A8/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/132466649](https://letmefly.blog.csdn.net/article/details/132466649)
