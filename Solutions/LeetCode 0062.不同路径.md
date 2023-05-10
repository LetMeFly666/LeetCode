---
title: 62.不同路径
date: 2022-11-26 23:12:32
tags: [题解, LeetCode, 中等, 数学, 动态规划, 组合数学]
---

# 【LetMeFly】62.不同路径：两种方法解决

力扣题目链接：[https://leetcode.cn/problems/unique-paths/](https://leetcode.cn/problems/unique-paths/)

<p>一个机器人位于一个 <code>m x n</code><em> </em>网格的左上角 （起始点在下图中标记为 “Start” ）。</p>

<p>机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。</p>

<p>问总共有多少条不同的路径？</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img src="https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png" />
<pre>
<strong>输入：</strong>m = 3, n = 7
<strong>输出：</strong>28</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>m = 3, n = 2
<strong>输出：</strong>3
<strong>解释：</strong>
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右
3. 向下 -> 向右 -> 向下
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>m = 7, n = 3
<strong>输出：</strong>28
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>m = 3, n = 3
<strong>输出：</strong>6</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= m, n <= 100</code></li>
	<li>题目数据保证答案小于等于 <code>2 * 10<sup>9</sup></code></li>
</ul>


    
## 方法一：动态规划

这题比较容易处理的是，只能向下或者向右走。

那么反过来，到达某点的前一步，一定是左边或者上边。

所以，到达某点的方案数就是“到达某点上方一格”的方案数 + “到达某点左边一格”的方案数（当然，上方没有方格的话，从上方到来的方案数就是0）

这道题直接不用考虑取模的问题，因为数据保证了答案小于等于$2\times10^9$

因此开辟一个二维的DP数组即可。

+ 时间复杂度$O(n\times m)$
+ 空间复杂度$O(n\times m)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0)
                    dp[i][j] += dp[i - 1][j];
                if (j > 0)
                    dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
```

其实我们处理下一行的时候只用到了上一行的数据，因此我们可以将二维数组压缩为一维，这样空间复杂度就降低为了$O(n)$

## 方法二：排列组合

不如直接用数学的方法来做。

从左上角到右下角，一共向右了$n - 1$次，向下了$m - 1$次

那么不就是在$(n-1)+(m-1)$次移动中，选出$m-1$次向下么

因此方案数为$C_{n + m - 2}^{n-1}$

```
                            (m + n - 2)(m + n - 3)···n
   C(n + m - 2, m - 1)  =   128059055
                                     (m - 1)!
   
   (m + n - 2) - n + 1 = m - 1
```

+ 时间复杂度$O(m)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        ll ans = 1;
        for (int x = n, y = 1; y < m; x++, y++) {
            ans = ans * x / y;
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/11/26/LeetCode%200062.%E4%B8%8D%E5%90%8C%E8%B7%AF%E5%BE%84/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128059055](https://letmefly.blog.csdn.net/article/details/128059055)
