---
title: 1289.下降路径最小和 II：通俗易懂地讲解O(n^2) + O(1)的做法
date: 2023-08-10 08:30:33
tags: [题解, LeetCode, 困难, 数组, 动态规划, DP, 矩阵]
categories: [题解, LeetCode]
---

# 【LetMeFly】1289.下降路径最小和 II：通俗易懂地讲解O(n^2) + O(1)的做法

力扣题目链接：[https://leetcode.cn/problems/minimum-falling-path-sum-ii/](https://leetcode.cn/problems/minimum-falling-path-sum-ii/)

<p>给你一个&nbsp;<code>n x n</code> 整数矩阵&nbsp;<code>arr</code>&nbsp;，请你返回 <strong>非零偏移下降路径</strong> 数字和的最小值。</p>

<p><strong>非零偏移下降路径</strong> 定义为：从&nbsp;<code>arr</code> 数组中的每一行选择一个数字，且按顺序选出来的数字中，相邻数字不在原数组的同一列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/08/10/falling-grid.jpg" style="width: 244px; height: 245px;" /></p>

<pre>
<strong>输入：</strong>arr = [[1,2,3],[4,5,6],[7,8,9]]
<strong>输出：</strong>13
<strong>解释：</strong>
所有非零偏移下降路径包括：
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
下降路径中数字和最小的是&nbsp;[1,5,7] ，所以答案是&nbsp;13 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>grid = [[7]]
<strong>输出：</strong>7
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == grid.length == grid[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 200</code></li>
	<li><code>-99 &lt;= grid[i][j] &lt;= 99</code></li>
</ul>


    
## 方法一：动态规划

这道题其实**思路**很简单：

1. gird[i][j]来自gird[i - 1]的哪一个？当然是gird[i - 1]中最小的那一个。
2. 如果grid[i - 1]中最小的那个元素恰好是j怎么办？那么gird[i][j]就来自gird[i - 1]中第二小的那一个。

不难发现，我们只关注上一行最小的两个元素（的位置）

**具体实现**

写一个函数```findMin2(v)```，用来寻找数组v中最小的两个元素的位置。

用$i$从第2行开始遍历地图grid：
   + 用$j$遍历$gird[i]$：
      + 如果$j$等于上一行最小元素的下标：$grid[i][j] += grid[i - 1][第二小元素的下标]$
	  + 否则$grid[i][j] += grid[i - 1][最小元素的下标]$

最终返回最后一行的最小元素即可。

+ 时间复杂度$O(n^2)$，其中$size(gird) = n\times n$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
private:
    pair<int, int> findMin2(vector<int>& v) {  // 只接收长度大于等于2的v
        pair<int, int> ans;
        int m = v[0], loc = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] < m) {
                m = v[i], loc = i;
            }
        }
        ans.first = loc;
        loc = ans.first ? 0 : 1, m = v[loc];  // 如果第一个元素是最小的，那么找第二个最小元素的时候就从上一行的第二个元素开始
        for (int i = 0; i < v.size(); i++) {
            if (v[i] < m && i != ans.first) {
                m = v[i], loc = i;
            }
        }
        ans.second = loc;
        return ans;
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 1; i < n; i++) {
            pair<int, int> last2min = findMin2(grid[i - 1]);  // i >= 1说明grid[i - 1].size() >= 2
            for (int j = 0; j < n; j++) {
                grid[i][j] += (j == last2min.first ? grid[i - 1][last2min.second] : grid[i - 1][last2min.first]);
            }
        }
        return *min_element(grid.back().begin(), grid.back().end());
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def findMin2(self, v: List[int]) -> List[int]:
        ans = [0, 0]
        m, loc = v[0], 0
        for i in range(len(v)):
            if v[i] < m:
                m, loc = v[i], i
        ans[0] = loc
        loc = 0 if ans[0] else 1
        m = v[loc]
        for i in range(len(v)):
            if v[i] < m and i != ans[0]:
                m, loc = v[i], i
        ans[1] = loc
        return ans
    
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        n = len(grid)
        for i in range(1, n):
            last2min = self.findMin2(grid[i - 1])
            for j in range(n):
                grid[i][j] += grid[i - 1][last2min[0]] if j != last2min[0] else grid[i - 1][last2min[1]]
        return min(grid[-1])
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/08/10/LeetCode%201289.%E4%B8%8B%E9%99%8D%E8%B7%AF%E5%BE%84%E6%9C%80%E5%B0%8F%E5%92%8CII/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/132201281](https://letmefly.blog.csdn.net/article/details/132201281)
