---
title: 983.最低票价
date: 2024-10-01 17:00:26
tags: [题解, LeetCode, 中等, 数组, 动态规划, 记忆化搜索, 哈希表, 哈希, map, set]
---

# 【LetMeFly】983.最低票价：记忆化搜索

力扣题目链接：[https://leetcode.cn/problems/minimum-cost-for-tickets/](https://leetcode.cn/problems/minimum-cost-for-tickets/)

<p>在一个火车旅行很受欢迎的国度，你提前一年计划了一些火车旅行。在接下来的一年里，你要旅行的日子将以一个名为&nbsp;<code>days</code>&nbsp;的数组给出。每一项是一个从&nbsp;<code>1</code>&nbsp;到&nbsp;<code>365</code>&nbsp;的整数。</p>

<p>火车票有 <strong>三种不同的销售方式</strong> ：</p>

<ul>
	<li>一张 <strong>为期一天</strong> 的通行证售价为&nbsp;<code>costs[0]</code> 美元；</li>
	<li>一张 <strong>为期七天</strong> 的通行证售价为&nbsp;<code>costs[1]</code> 美元；</li>
	<li>一张 <strong>为期三十天</strong> 的通行证售价为&nbsp;<code>costs[2]</code> 美元。</li>
</ul>

<p>通行证允许数天无限制的旅行。 例如，如果我们在第 <code>2</code> 天获得一张 <strong>为期 7 天</strong> 的通行证，那么我们可以连着旅行 7 天：第 <code>2</code> 天、第 <code>3</code> 天、第 <code>4</code> 天、第 <code>5</code> 天、第 <code>6</code> 天、第 <code>7</code> 天和第 <code>8</code> 天。</p>

<p>返回 <em>你想要完成在给定的列表&nbsp;<code>days</code>&nbsp;中列出的每一天的旅行所需要的最低消费&nbsp;</em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>days = [1,4,6,7,8,20], costs = [2,7,15]
<strong>输出：</strong>11
<strong>解释： </strong>
例如，这里有一种购买通行证的方法，可以让你完成你的旅行计划：
在第 1 天，你花了 costs[0] = $2 买了一张为期 1 天的通行证，它将在第 1 天生效。
在第 3 天，你花了 costs[1] = $7 买了一张为期 7 天的通行证，它将在第 3, 4, ..., 9 天生效。
在第 20 天，你花了 costs[0] = $2 买了一张为期 1 天的通行证，它将在第 20 天生效。
你总共花了 $11，并完成了你计划的每一天旅行。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
<strong>输出：</strong>17
<strong>解释：
</strong>例如，这里有一种购买通行证的方法，可以让你完成你的旅行计划： 
在第 1 天，你花了 costs[2] = $15 买了一张为期 30 天的通行证，它将在第 1, 2, ..., 30 天生效。
在第 31 天，你花了 costs[0] = $2 买了一张为期 1 天的通行证，它将在第 31 天生效。 
你总共花了 $17，并完成了你计划的每一天旅行。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= days.length &lt;= 365</code></li>
	<li><code>1 &lt;= days[i] &lt;= 365</code></li>
	<li><code>days</code>&nbsp;按顺序严格递增</li>
	<li><code>costs.length == 3</code></li>
	<li><code>1 &lt;= costs[i] &lt;= 1000</code></li>
</ul>


    
## 解题方法：记忆化搜索

使用一个函数`dfs(day)`来记录一年开始到第`day`天所需的最小花费。并使用一个哈希表缓存函数返回的结果，若计算过则不再次计算。

+ 如果`day < 0`，则直接返回`0`；
+ 如果`day`不在要出行的天数中，则这天无需买票，返回`dfs(day - 1)`；
+ 否则，返回三种买票方案中最便宜的那个（假设我要买一天的票，则金额为`dfs(day - 1) + costs[0]`）

最终返回`dfs(365)`或`dfs(要出行的最后一天)`即可。

+ 时间复杂度$O(D)$，其中$D=365$
+ 空间复杂度$O(D)$

### AC代码

#### C++

```cpp
class Solution {
private:
    unordered_map<int, int> cache;
    unordered_set<int> se;
    vector<int> costs;
    int dfs(int day) {
        if (day <= 0) {
            return 0;
        }
        if (cache.count(day)) {
            return cache[day];
        }
        if (!se.count(day)) {
            return cache[day] = dfs(day - 1);
        }
        return cache[day] = min(dfs(day - 1) + costs[0], min(dfs(day - 7) + costs[1], dfs(day - 30) + costs[2]));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        this->costs = costs;
        se.insert(days.begin(), days.end());
        return dfs(days.back());
    }
};
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/10/01/LeetCode%200983.%E6%9C%80%E4%BD%8E%E7%A5%A8%E4%BB%B7/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/142672522](https://letmefly.blog.csdn.net/article/details/142672522)
