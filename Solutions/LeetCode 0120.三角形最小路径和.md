---
title: 120.三角形最小路径和
date: 2022-07-18 16:23:53
tags: [题解, LeetCode, 中等, 数组, 动态规划]
---

# 【LetMeFly】120.三角形最小路径和

力扣题目链接：[https://leetcode.cn/problems/triangle/](https://leetcode.cn/problems/triangle/)

<p>给定一个三角形 <code>triangle</code> ，找出自顶向下的最小路径和。</p>

<p>每一步只能移动到下一行中相邻的结点上。<strong>相邻的结点 </strong>在这里指的是 <strong>下标</strong> 与 <strong>上一层结点下标</strong> 相同或者等于 <strong>上一层结点下标 + 1</strong> 的两个结点。也就是说，如果正位于当前行的下标 <code>i</code> ，那么下一步可以移动到下一行的下标 <code>i</code> 或 <code>i + 1</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
<strong>输出：</strong>11
<strong>解释：</strong>如下面简图所示：
   <strong>2</strong>
  <strong>3</strong> 4
 6 <strong>5</strong> 7
4 <strong>1</strong> 8 3
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>triangle = [[-10]]
<strong>输出：</strong>-10
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= triangle.length <= 200</code></li>
	<li><code>triangle[0].length == 1</code></li>
	<li><code>triangle[i].length == triangle[i - 1].length + 1</code></li>
	<li><code>-10<sup>4</sup> <= triangle[i][j] <= 10<sup>4</sup></code></li>
</ul>

<p> </p>

<p><strong>进阶：</strong></p>

<ul>
	<li>你可以只使用 <code>O(n)</code> 的额外空间（<code>n</code> 为三角形的总行数）来解决这个问题吗？</li>
</ul>


    
## 方法一：原地修改

第$i$行的第$j$个元素可由第$i-1$行的第$j-1$ or 第$j$个元素走来。

那么具体由哪个走来呢？当然取决于上一行第$j-1$ 和 第$j$个的最小的那个。

直接在原三角形上进行修改即可。

+ 时间复杂度$O(N^2)$，其中$N$为三角形的边长
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for (int i = 1; i < n; i++) {
            triangle[i][0] += triangle[i - 1][0];
            for (int j = 1; j < i; j++) {
                triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
            triangle[i][i] += triangle[i - 1][i - 1];
        }
		// 返回最后一行的最小元素
        int ans = triangle[n - 1][0];
        for (int i = 1; i < n; i++) {
            ans = min(ans, triangle[n - 1][i]);
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/07/18/LeetCode%200120.%E4%B8%89%E8%A7%92%E5%BD%A2%E6%9C%80%E5%B0%8F%E8%B7%AF%E5%BE%84%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125854342](https://letmefly.blog.csdn.net/article/details/125854342)
