---
title: 2500.删除每行中的最大值
date: 2023-07-27 08:33:17
tags: [题解, LeetCode, 简单, 数组, 矩阵, 排序]
---

# 【LetMeFly】2500.删除每行中的最大值

力扣题目链接：[https://leetcode.cn/problems/delete-greatest-value-in-each-row/](https://leetcode.cn/problems/delete-greatest-value-in-each-row/)

<p>给你一个 <code>m x n</code> 大小的矩阵 <code>grid</code> ，由若干正整数组成。</p>

<p>执行下述操作，直到 <code>grid</code> 变为空矩阵：</p>

<ul>
	<li>从每一行删除值最大的元素。如果存在多个这样的值，删除其中任何一个。</li>
	<li>将删除元素中的最大值与答案相加。</li>
</ul>

<p><strong>注意</strong> 每执行一次操作，矩阵中列的数据就会减 1 。</p>

<p>返回执行上述操作后的答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/10/19/q1ex1.jpg" style="width: 600px; height: 135px;" /></p>

<pre>
<strong>输入：</strong>grid = [[1,2,4],[3,3,1]]
<strong>输出：</strong>8
<strong>解释：</strong>上图展示在每一步中需要移除的值。
- 在第一步操作中，从第一行删除 4 ，从第二行删除 3（注意，有两个单元格中的值为 3 ，我们可以删除任一）。在答案上加 4 。
- 在第二步操作中，从第一行删除 2 ，从第二行删除 3 。在答案上加 3 。
- 在第三步操作中，从第一行删除 1 ，从第二行删除 1 。在答案上加 1 。
最终，答案 = 4 + 3 + 1 = 8 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/10/19/q1ex2.jpg" style="width: 83px; height: 83px;" /></p>

<pre>
<strong>输入：</strong>grid = [[10]]
<strong>输出：</strong>10
<strong>解释：</strong>上图展示在每一步中需要移除的值。
- 在第一步操作中，从第一行删除 10 。在答案上加 10 。
最终，答案 = 10 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 100</code></li>
</ul>


    
## 方法一：排序

将每一行从小到大排序。

之后依次遍历每一列，并将这一列的最大值累加到答案中即可。

+ 时间复杂度$O(nm\log m)$，其中$size(grid) = n\times m$（每行有m个元素）
+ 空间复杂度$O(\log m)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for (vector<int>& v : grid) {
            sort(v.begin(), v.end());
        }
        int ans = 0;
        for (int j = 0; j < grid[0].size(); j++) {
            int thisValue = grid[0][j];
            for (int i = 1; i < grid.size(); i++) {
                thisValue = max(thisValue, grid[i][j]);
            }
            ans += thisValue;
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/07/27/LeetCode%202500.%E5%88%A0%E9%99%A4%E6%AF%8F%E8%A1%8C%E4%B8%AD%E7%9A%84%E6%9C%80%E5%A4%A7%E5%80%BC/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131951838](https://letmefly.blog.csdn.net/article/details/131951838)
