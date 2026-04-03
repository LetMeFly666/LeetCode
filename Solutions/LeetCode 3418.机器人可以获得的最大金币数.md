---
title: 3418.机器人可以获得的最大金币数：动态规划
date: 2026-04-03 08:30:31
tags: [题解, LeetCode, 中等, 数组, 动态规划, 矩阵]
categories: [题解, LeetCode]
---

# 【LetMeFly】3418.机器人可以获得的最大金币数：动态规划

力扣题目链接：[https://leetcode.cn/problems/maximum-amount-of-money-robot-can-earn/](https://leetcode.cn/problems/maximum-amount-of-money-robot-can-earn/)

<p>给你一个 <code>m x n</code> 的网格。一个机器人从网格的左上角 <code>(0, 0)</code> 出发，目标是到达网格的右下角 <code>(m - 1, n - 1)</code>。在任意时刻，机器人只能向右或向下移动。</p>

<p>网格中的每个单元格包含一个值 <code>coins[i][j]</code>：</p>

<ul>
	<li>如果 <code>coins[i][j] &gt;= 0</code>，机器人可以获得该单元格的金币。</li>
	<li>如果 <code>coins[i][j] &lt; 0</code>，机器人会遇到一个强盗，强盗会抢走该单元格数值的&nbsp;<strong>绝对值</strong> 的金币。</li>
</ul>

<p>机器人有一项特殊能力，可以在行程中&nbsp;<strong>最多感化&nbsp;</strong>2个单元格的强盗，从而防止这些单元格的金币被抢走。</p>

<p><strong>注意：</strong>机器人的总金币数可以是负数。</p>

<p>返回机器人在路径上可以获得的&nbsp;<strong>最大金币数&nbsp;</strong>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">coins = [[0,1,-1],[1,-2,3],[2,-3,4]]</span></p>

<p><strong>输出：</strong> <span class="example-io">8</span></p>

<p><strong>解释：</strong></p>

<p>一个获得最多金币的最优路径如下：</p>

<ol>
	<li>从 <code>(0, 0)</code> 出发，初始金币为 <code>0</code>（总金币 = <code>0</code>）。</li>
	<li>移动到 <code>(0, 1)</code>，获得 <code>1</code> 枚金币（总金币 = <code>0 + 1 = 1</code>）。</li>
	<li>移动到 <code>(1, 1)</code>，遇到强盗抢走 <code>2</code> 枚金币。机器人在此处使用一次感化能力，避免被抢（总金币 = <code>1</code>）。</li>
	<li>移动到 <code>(1, 2)</code>，获得 <code>3</code> 枚金币（总金币 = <code>1 + 3 = 4</code>）。</li>
	<li>移动到 <code>(2, 2)</code>，获得 <code>4</code> 枚金币（总金币 = <code>4 + 4 = 8</code>）。</li>
</ol>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">coins = [[10,10,10],[10,10,10]]</span></p>

<p><strong>输出：</strong> <span class="example-io">40</span></p>

<p><strong>解释：</strong></p>

<p>一个获得最多金币的最优路径如下：</p>

<ol>
	<li>从 <code>(0, 0)</code> 出发，初始金币为 <code>10</code>（总金币 = <code>10</code>）。</li>
	<li>移动到 <code>(0, 1)</code>，获得 <code>10</code> 枚金币（总金币 = <code>10 + 10 = 20</code>）。</li>
	<li>移动到 <code>(0, 2)</code>，再获得 <code>10</code> 枚金币（总金币 = <code>20 + 10 = 30</code>）。</li>
	<li>移动到 <code>(1, 2)</code>，获得 <code>10</code> 枚金币（总金币 = <code>30 + 10 = 40</code>）。</li>
</ol>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == coins.length</code></li>
	<li><code>n == coins[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 500</code></li>
	<li><code>-1000 &lt;= coins[i][j] &lt;= 1000</code></li>
</ul>


    
## 解题方法：动态规划

令$dp[th][i][j]$代表到达$(i, j)$时感化强盗最多$th$次的最大收益。

+ 如果不感化：$dp[th][i][j]=coins[i][j] + \max(dp[th][i-1][j], dp[th][i][j-1])$（上左最大的那个 + 本格子）
+ 如果感化：$dp[th][i][j] = \max(dp[th-1][i-1][j], dp[th-1][i][j-1])$ （上左$th-1$次感化中最大的那个）

注意判断下边界条件$th$、$i$、$j$大于或等于$0$就好。

+ 时间复杂度$O(nm)$
+ 空间复杂度$O(nm)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-04-03 08:29:08
 */
const int INF = 1e9;
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();
        array<vector<vector<int>>, 3> dp;
        dp.fill(vector<vector<int>>(n, vector<int>(m)));
        dp[0][0][0] = coins[0][0];
        dp[1][0][0] = dp[2][0][0] = max(coins[0][0], 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!i && !j) {
                    continue;
                }
                for (int th = 0; th < 3; th++) {
                    dp[th][i][j] = coins[i][j] + max(i ? dp[th][i - 1][j] : -INF, j ? dp[th][i][j - 1] : -INF);
                    // printf("dp[%d][%d][%d] = %d\n", th, i, j, dp[th][i][j]);
                }
                for (int th = 1; th < 3; th++) {
                    // int a = dp[th][i][j], b = max(i ? dp[th - 1][i - 1][j] : -INF, j ? dp[th - 1][i][j - 1] : -INF);
                    // if (b > a) {
                    //     printf("dp[%d][%d][%d]: %d -> ", th, i, j, a);
                    //     if (i && dp[th - 1][i - 1][j] > (j ? dp[th - 1][i][j - 1] : 0)) {
                    //         printf
                    //     } else {
                    //         printf
                    //     }
                    // }
                    dp[th][i][j] = max(dp[th][i][j], max(i ? dp[th - 1][i - 1][j] : -INF, j ? dp[th - 1][i][j - 1] : -INF));
                }
            }
        }

        return dp[2][n - 1][m - 1];
    }
};

```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/--------------------------)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/04/02/LeetCode%203418.%E6%9C%BA%E5%99%A8%E4%BA%BA%E5%8F%AF%E4%BB%A5%E8%8E%B7%E5%BE%97%E7%9A%84%E6%9C%80%E5%A4%A7%E9%87%91%E5%B8%81%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
