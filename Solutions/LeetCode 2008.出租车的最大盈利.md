---
title: 2008.出租车的最大盈利
date: 2023-12-08 22:50:48
tags: [题解, LeetCode, 中等, 数组, 二分查找, 动态规划, DP, 排序, 哈希表, 哈希, map]
categories: [题解, LeetCode]
---

# 【LetMeFly】2008.出租车的最大盈利：动态规划 + 哈希表

力扣题目链接：[https://leetcode.cn/problems/maximum-earnings-from-taxi/](https://leetcode.cn/problems/maximum-earnings-from-taxi/)

<p>你驾驶出租车行驶在一条有 <code>n</code>&nbsp;个地点的路上。这 <code>n</code>&nbsp;个地点从近到远编号为&nbsp;<code>1</code>&nbsp;到&nbsp;<code>n</code>&nbsp;，你想要从 <code>1</code>&nbsp;开到 <code>n</code>&nbsp;，通过接乘客订单盈利。你只能沿着编号递增的方向前进，不能改变方向。</p>

<p>乘客信息用一个下标从 <strong>0</strong>&nbsp;开始的二维数组&nbsp;<code>rides</code>&nbsp;表示，其中&nbsp;<code>rides[i] = [start<sub>i</sub>, end<sub>i</sub>, tip<sub>i</sub>]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;位乘客需要从地点&nbsp;<code>start<sub>i</sub></code>&nbsp;前往&nbsp;<code>end<sub>i</sub></code>&nbsp;，愿意支付&nbsp;<code>tip<sub>i</sub></code>&nbsp;元的小费。</p>

<p><strong>每一位</strong> 你选择接单的乘客&nbsp;<code>i</code>&nbsp;，你可以 <strong>盈利</strong>&nbsp;<code>end<sub>i</sub> - start<sub>i</sub> + tip<sub>i</sub></code>&nbsp;元。你同时&nbsp;<strong>最多</strong>&nbsp;只能接一个订单。</p>

<p>给你 <code>n</code>&nbsp;和 <code>rides</code>&nbsp;，请你返回在最优接单方案下，你能盈利&nbsp;<strong>最多</strong>&nbsp;多少元。</p>

<p><strong>注意：</strong>你可以在一个地点放下一位乘客，并在同一个地点接上另一位乘客。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>n = 5, rides = [<em><strong>[2,5,4]</strong></em>,[1,5,1]]
<b>输出：</b>7
<b>解释：</b>我们可以接乘客 0 的订单，获得 5 - 2 + 4 = 7 元。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>n = 20, rides = [[1,6,1],<strong><em>[3,10,2]</em></strong>,<em><strong>[10,12,3]</strong></em>,[11,12,2],[12,15,2],<strong><em>[13,18,1]</em></strong>]
<b>输出：</b>20
<b>解释：</b>我们可以接以下乘客的订单：
- 将乘客 1 从地点 3 送往地点 10 ，获得 10 - 3 + 2 = 9 元。
- 将乘客 2 从地点 10 送往地点 12 ，获得 12 - 10 + 3 = 5 元。
- 将乘客 5 从地点 13 送往地点 18 ，获得 18 - 13 + 1 = 6 元。
我们总共获得 9 + 5 + 6 = 20 元。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= rides.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>rides[i].length == 3</code></li>
	<li><code>1 &lt;= start<sub>i</sub> &lt; end<sub>i</sub> &lt;= n</code></li>
	<li><code>1 &lt;= tip<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 方法一：动态规划 + 哈希表

使用dp[i]表示从地点到距离$i$的最大收益。

关于位置$i$，可以选择接“i为终点的乘客”，也可以选择不接。

因此可以预处理，使用哈希表ma，ma[i]存放所有以i为终点的乘客。因此对于dp[i]：

+ 若接终点为i的乘客，则遍历所有终点为i的乘客。假设这个乘客```起点 终点 小费```分别为```start end tip```，则有$dp[i] = max(dp[i], dp[start] + (end - start + tip))$
+ 若不接，则$dp[i] = dp[i - 1]$

最终返回$dp.end()$即可。

+ 时间复杂度$O(m + n)$，其中$m=len(rides)$
+ 空间复杂度$O(m + n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        unordered_map<int, vector<vector<int>>> ma;
        for (vector<int>& ride : rides) {
            ma[ride[1]].push_back(ride);
        }
        vector<long long> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            for (vector<int>& ride : ma[i]) {
                int start = ride[0], end = ride[1], tip = ride[2];
                dp[i] = max(dp[i], dp[start] + end - start + tip);
            }
        }
        return dp.back();
    }
};
```

#### Python

```python
# from typing import List
# from collections import defaultdict

class Solution:
    def maxTaxiEarnings(self, n: int, rides: List[List[int]]) -> int:
        ma =  defaultdict(list)
        for ride in rides:
            ma[ride[1]].append(ride)
        dp = [0] * (n + 1)
        for i in range(1, n + 1):
            dp[i] = dp[i - 1]
            for start, end, tip in ma[i]:
                dp[i] = max(dp[i], dp[start] + end - start + tip)
        return dp[-1]

```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/12/08/LeetCode%202008.%E5%87%BA%E7%A7%9F%E8%BD%A6%E7%9A%84%E6%9C%80%E5%A4%A7%E7%9B%88%E5%88%A9/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/134889043](https://letmefly.blog.csdn.net/article/details/134889043)
