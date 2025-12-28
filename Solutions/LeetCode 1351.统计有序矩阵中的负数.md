---
title: 1351.统计有序矩阵中的负数：O(m+n)时间复杂度——抽象题解
date: 2025-12-28 15:20:45
tags: [题解, LeetCode, 简单, 数组, 矩阵, 遍历]
categories: [题解, LeetCode]
---

# 【LetMeFly】1351.统计有序矩阵中的负数：O(m+n)时间复杂度——抽象题解

力扣题目链接：[https://leetcode.cn/problems/count-negative-numbers-in-a-sorted-matrix/](https://leetcode.cn/problems/count-negative-numbers-in-a-sorted-matrix/)

<p>给你一个&nbsp;<code>m&nbsp;* n</code>&nbsp;的矩阵&nbsp;<code>grid</code>，矩阵中的元素无论是按行还是按列，都以非严格递减顺序排列。&nbsp;请你统计并返回&nbsp;<code>grid</code>&nbsp;中 <strong>负数</strong> 的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
<strong>输出：</strong>8
<strong>解释：</strong>矩阵中共有 8 个负数。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>grid = [[3,2],[1,0]]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>-100 &lt;= grid[i][j] &lt;= 100</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你可以设计一个时间复杂度为 <code>O(n + m)</code> 的解决方案吗？</p>


    
## 解题方法：遍历

例如样例数组：

```
 4  3  2 -1
 3  2  1 -1
 1  1 -1 -2
-1 -1 -2 -3
```

不难发现其实是这样的：

```
 4  3  2  |  -1
 3  2  1 /  -1
 1  1   / -1 -2
-------+
-1 -1 -2 -3
```

看到中间那条**分隔线**了吗？我们按照中间那条线遍历就好了。

使用一个纵坐标变量，默认值为最后一列。接着从第一行开始往下遍历：

> 对于当前行，让纵坐标移动到第一个非负数的位置（或移出数组）。具体而言：
> 
> 对于当前行，在纵坐标没有越界且当前所指元素为负数时，纵坐标不断左移。

+ 时间复杂度$O(m+n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2025-12-28 14:45:14
 */
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0, j = m - 1; i < n; i++) {
            while (j >= 0 && grid[i][j] < 0) {
                j--;
            }
            ans += m - j - 1;
        }
        return ans;
    }
};

/*
[[4,3,2,-1],
 [3,2,1,-1],
 [1,1,-1,-2],
 [-1,-1,-2,-3]]
*/
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/156361831)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/12/28/LeetCode%201351.%E7%BB%9F%E8%AE%A1%E6%9C%89%E5%BA%8F%E7%9F%A9%E9%98%B5%E4%B8%AD%E7%9A%84%E8%B4%9F%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
