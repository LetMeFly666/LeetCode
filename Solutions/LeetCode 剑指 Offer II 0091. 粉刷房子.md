---
title: 剑指 Offer II 091.粉刷房子
date: 2022-06-25 10:51:08
tags: [题解, LeetCode, 中等, 数组, 动态规划, DP]
categories: [题解, LeetCode]
---

# 【LetMeFly】剑指 Offer II 091.粉刷房子 - 原地修改

力扣题目链接：[https://leetcode.cn/problems/JEj789/](https://leetcode.cn/problems/JEj789/)

<p>假如有一排房子，共 <code>n</code> 个，每个房子可以被粉刷成红色、蓝色或者绿色这三种颜色中的一种，你需要粉刷所有的房子并且使其相邻的两个房子颜色不能相同。</p>

<p>当然，因为市场上不同颜色油漆的价格不同，所以房子粉刷成不同颜色的花费成本也是不同的。每个房子粉刷成不同颜色的花费是以一个&nbsp;<code>n x 3</code><em>&nbsp;</em>的正整数矩阵 <code>costs</code> 来表示的。</p>

<p>例如，<code>costs[0][0]</code> 表示第 0 号房子粉刷成红色的成本花费；<code>costs[1][2]</code>&nbsp;表示第 1 号房子粉刷成绿色的花费，以此类推。</p>

<p>请计算出粉刷完所有房子最少的花费成本。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入: </strong>costs = [[17,2,17],[16,16,5],[14,3,19]]
<strong>输出: </strong>10
<strong>解释: </strong>将 0 号房子粉刷成蓝色，1 号房子粉刷成绿色，2 号房子粉刷成蓝色<strong>。</strong>
&nbsp;    最少花费: 2 + 5 + 3 = 10。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入: </strong>costs = [[7,6,2]]
<strong>输出: 2</strong>
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>costs.length == n</code></li>
	<li><code>costs[i].length == 3</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= costs[i][j] &lt;= 20</code></li>
</ul>

<p>&nbsp;</p>

<p><meta charset="UTF-8" />注意：本题与主站 256&nbsp;题相同：<a href="https://leetcode-cn.com/problems/paint-house/">https://leetcode-cn.com/problems/paint-house/</a></p>

## 方法一：动态规划

这是一道比较容易想出来的动态规划，我们用$dp[i][j]$表示第$i + 1$个方块粉刷第$j$个颜色时，前$i + 1$个方块儿的最小花费。

那么，$min{dp[n - 1][0, 1, 2]}$就是答案（把第$n$个方块粉刷成$3$种颜色中的一个，前$n$个方块的最小花费）

但是，相邻两个方块颜色不能相同。因此**递推公式：**

+ $dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0]$
+ $dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1]$
+ $dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2]$

如果允许修改$costs$数组，那么我们可以直接用$costs$数组来代替$dp$数组，$costs[i][j] += min(costs[i - 1][xx])$即可。

+ 时间复杂度$O(n)$，其中$n$是房子个数
+ 空间复杂度：
   + 如果能修改$costs$数组，就不需要额外开辟数组空间，只需要使用常数个变量即可，此时空间复杂度为$O(1)$；
   + 如果不能修改$costs$数组，那么 如果额外开辟一个$dp$数组，空间复杂度为$O(n)$；如果使用$3$个变量代替$dp$数组，空间复杂度$O(1)$（因为dp数组第$i-1$之前内容不会再用到）

### AC代码

#### C++

```cpp
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        for (int i = 1; i < costs.size(); i++) {
            costs[i][0] += min(costs[i - 1][1], costs[i - 1][2]);
            costs[i][1] += min(costs[i - 1][0], costs[i - 1][2]);
            costs[i][2] += min(costs[i - 1][0], costs[i - 1][1]);
        }
        return min(costs[costs.size() - 1][0], min(costs[costs.size() - 1][1], costs[costs.size() - 1][2]));
    }
};
```


> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/06/25/LeetCode%20%E5%89%91%E6%8C%87%20Offer%20II%200091.%20%E7%B2%89%E5%88%B7%E6%88%BF%E5%AD%90/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125456885](https://letmefly.blog.csdn.net/article/details/125456885)