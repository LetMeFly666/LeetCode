---
title: 2639.查询网格图中每一列的宽度
date: 2024-04-27 11:10:24
tags: [题解, LeetCode, 简单, 数组, 矩阵, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】2639.查询网格图中每一列的宽度：模拟（遍历）

力扣题目链接：[https://leetcode.cn/problems/find-the-width-of-columns-of-a-grid/](https://leetcode.cn/problems/find-the-width-of-columns-of-a-grid/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的&nbsp;<code>m x n</code>&nbsp;整数矩阵&nbsp;<code>grid</code>&nbsp;。矩阵中某一列的宽度是这一列数字的最大 <strong>字符串长度</strong>&nbsp;。</p>

<ul>
	<li>比方说，如果&nbsp;<code>grid = [[-10], [3], [12]]</code>&nbsp;，那么唯一一列的宽度是&nbsp;<code>3</code>&nbsp;，因为&nbsp;<code>-10</code>&nbsp;的字符串长度为&nbsp;<code>3</code>&nbsp;。</li>
</ul>

<p>请你返回一个大小为 <code>n</code>&nbsp;的整数数组&nbsp;<code>ans</code>&nbsp;，其中&nbsp;<code>ans[i]</code>&nbsp;是第&nbsp;<code>i</code>&nbsp;列的宽度。</p>

<p>一个有 <code>len</code>&nbsp;个数位的整数 <code>x</code>&nbsp;，如果是非负数，那么&nbsp;<strong>字符串</strong><strong>长度</strong>&nbsp;为&nbsp;<code>len</code>&nbsp;，否则为&nbsp;<code>len + 1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>grid = [[1],[22],[333]]
<b>输出：</b>[3]
<b>解释：</b>第 0 列中，333 字符串长度为 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>grid = [[-15,1,3],[15,7,12],[5,6,-2]]
<b>输出：</b>[3,1,2]
<b>解释：</b>
第 0 列中，只有 -15 字符串长度为 3 。
第 1 列中，所有整数的字符串长度都是 1 。
第 2 列中，12 和 -2 的字符串长度都为 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100 </code></li>
	<li><code>-10<sup>9</sup> &lt;= grid[r][c] &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：遍历（模拟）

两层循环，外层循环遍历数组的每一列：

内层循环中，对于这一列，遍历这一列的每一行，使用一个变量记录这一列每个数的最大宽度。

如何求数字的“宽度”？（可使用内置函数）将数字转为字符串，字符串的长度即为数字的宽度。

+ 时间复杂度$O(Size(grid))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size());
        for (int j = 0; j < grid[0].size(); j++) {
            int thisAns = 1;
            for (int i = 0; i < grid.size(); i++) {
                thisAns = max(thisAns, (int)to_string(grid[i][j]).size());
            }
            ans[j] = thisAns;
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def findColumnWidth(self, grid: List[List[int]]) -> List[int]:
        ans = [1] * len(grid[0])
        for j in range(len(grid[0])):
            thisAns = 1
            for i in range(len(grid)):
                thisAns = max(thisAns, len(str(grid[i][j])))
            ans[j] = thisAns
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/04/27/LeetCode%202639.%E6%9F%A5%E8%AF%A2%E7%BD%91%E6%A0%BC%E5%9B%BE%E4%B8%AD%E6%AF%8F%E4%B8%80%E5%88%97%E7%9A%84%E5%AE%BD%E5%BA%A6/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/138244991](https://letmefly.blog.csdn.net/article/details/138244991)
