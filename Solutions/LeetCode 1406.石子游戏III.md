---
title: 1406.石子游戏 III：递归(DFS+记忆化) / 递推(DP+原地滚动)
date: 2026-08-03 19:02:40
tags: [题解, LeetCode, 困难, 数组, 数学, 动态规划, 博弈, DP, DFS, 深度优先搜索, 记忆化搜索]
categories: [题解, LeetCode]
---

# 【LetMeFly】1406.石子游戏 III：递归(DFS+记忆化) / 递推(DP+原地滚动)

力扣题目链接：[https://leetcode.cn/problems/stone-game-iii/](https://leetcode.cn/problems/stone-game-iii/)

<p>Alice 和 Bob 继续他们的石子游戏。几堆石子 <strong>排成一行</strong> ，每堆石子都对应一个得分，由数组 <code>stoneValue</code> 给出。</p>

<p>Alice 和 Bob 轮流取石子，<strong>Alice</strong> 总是先开始。在每个玩家的回合中，该玩家可以拿走剩下石子中的的前 <strong>1、2 或 3 堆石子</strong> 。比赛一直持续到所有石头都被拿走。</p>

<p>每个玩家的最终得分为他所拿到的每堆石子的对应得分之和。每个玩家的初始分数都是 <strong>0</strong> 。</p>

<p>比赛的目标是决出最高分，得分最高的选手将会赢得比赛，比赛也可能会出现平局。</p>

<p>假设 Alice 和 Bob 都采取 <strong>最优策略</strong> 。</p>

<p>如果 Alice 赢了就返回 <code>"Alice"</code> <em>，</em>Bob 赢了就返回<em> </em><code>"Bob"</code><em>，</em>分数相同返回 <code>"Tie"</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>values = [1,2,3,7]
<strong>输出：</strong>"Bob"
<strong>解释：</strong>Alice 总是会输，她的最佳选择是拿走前三堆，得分变成 6 。但是 Bob 的得分为 7，Bob 获胜。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>values = [1,2,3,-9]
<strong>输出：</strong>"Alice"
<strong>解释：</strong>Alice 要想获胜就必须在第一个回合拿走前三堆石子，给 Bob 留下负分。
如果 Alice 只拿走第一堆，那么她的得分为 1，接下来 Bob 拿走第二、三堆，得分为 5 。之后 Alice 只能拿到分数 -9 的石子堆，输掉比赛。
如果 Alice 拿走前两堆，那么她的得分为 3，接下来 Bob 拿走第三堆，得分为 3 。之后 Alice 只能拿到分数 -9 的石子堆，同样会输掉比赛。
注意，他们都应该采取 <strong>最优策略 </strong>，所以在这里 Alice 将选择能够使她获胜的方案。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>values = [1,2,3,6]
<strong>输出：</strong>"Tie"
<strong>解释：</strong>Alice 无法赢得比赛。如果她决定选择前三堆，她可以以平局结束比赛，否则她就会输。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= stoneValue.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>-1000&nbsp;&lt;= stoneValue[i] &lt;= 1000</code></li>
</ul>



## 解题方法一：深度优先搜索

写一个函数计算 从$stoneValue[idx]$开始拿到最后的子游戏 中，先手最多比后手领先多少分。

> 怎么计算？如果已经拿空，则返回$0$；否则返回三种选法中结果最好的那个(如有)

+ 时间复杂度$O(len(stoneValue))$
+ 空间复杂度$O(len(stoneValue))$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-08-03 18:36:37
 */
class Solution {
private:
    int n;
    vector<int> mem;

    int play(vector<int>& v, int idx=0) {
        if (mem[idx] != INT_MIN) {
            return mem[idx];
        }
        if (idx == n) {
            return mem[idx] = 0;
        }
        int ans = INT_MIN;
        for (int i = 0, cnt = 0; i < 3; i++) {
            if (idx + i >= n) {
                break;
            }
            cnt += v[idx + i];
            ans = max(ans, cnt - play(v, idx + i + 1));
        }
        return mem[idx] = ans;
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        mem.resize(n + 1, INT_MIN);
        int score = play(stoneValue);
        return score > 0 ? "Alice" : score ? "Bob" : "Tie";
    }
};
```

## 解题方法二.1：动态规划

令$dp[i]$代表当前先手从下标$i$选到最后的最大得分，$suffix[i]$代表从下标$i$选到最后的总分。

> 则当前先手在下标$i$选择$j$个的话，相当于其对手从下标$i+j$开始到最后作为先手，当前先手的得分为后面总分减去对手得分即$suffix[i]-dp[i+j]$。

+ 时间复杂度$O(len(stoneValue))$
+ 空间复杂度$O(len(stoneValue))$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-08-03 18:55:21
 */
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(stoneValue.size() + 3);
        int suffix = 0;
        for (int i = stoneValue.size() - 1; i >= 0; i--) {
            dp[i] = INT_MIN;
            suffix += stoneValue[i];
            for (int j = 1; j <= 3; j++) {
                dp[i] = max(dp[i], suffix - dp[i + j]);
            }
        }
        
        int diff = dp[0] - (suffix - dp[0]);
        return diff > 0 ? "Alice" : diff ? "Bob" : "Tie";
    }
};
```

## 解题方法二.2：动态规划+原地滚动

不难发现$j$的取值范围是$1\leq j\leq 3$，所以我们使用三个变量来存放后面三个$dp$值就好了。

+ 时间复杂度$O(len(stoneValue))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-08-03 19:01:21
 */
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int dp3[3] = {0};
        int suffix = 0;
        for (int i = stoneValue.size() - 1; i >= 0; i--) {
            int dp = INT_MIN;
            suffix += stoneValue[i];
            for (int j = 0; j < 3; j++) {
                dp = max(dp, suffix - dp3[j]);
            }
            dp3[2] = dp3[1], dp3[1] = dp3[0], dp3[0] = dp;
        }
        
        int diff = dp3[0] - (suffix - dp3[0]);
        return diff > 0 ? "Alice" : diff ? "Bob" : "Tie";
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/163451093)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/08/03/LeetCode%201406.%E7%9F%B3%E5%AD%90%E6%B8%B8%E6%88%8FIII/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
