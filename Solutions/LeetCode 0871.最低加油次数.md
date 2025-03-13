---
title: 871.最低加油次数
date: 2022-07-02 17:34:26
tags: [题解, LeetCode, 困难, 贪心, 数组, 动态规划, 堆（优先队列）, 优先队列]
categories: [题解, LeetCode]
---

# 【LetMeFly】871.最低加油次数 - 类似于POJ2431丛林探险

力扣题目链接：[https://leetcode.cn/problems/minimum-number-of-refueling-stops/](https://leetcode.cn/problems/minimum-number-of-refueling-stops/)

<p>汽车从起点出发驶向目的地，该目的地位于出发位置东面 <code>target</code>&nbsp;英里处。</p>

<p>沿途有加油站，每个&nbsp;<code>station[i]</code>&nbsp;代表一个加油站，它位于出发位置东面&nbsp;<code>station[i][0]</code>&nbsp;英里处，并且有&nbsp;<code>station[i][1]</code>&nbsp;升汽油。</p>

<p>假设汽车油箱的容量是无限的，其中最初有&nbsp;<code>startFuel</code>&nbsp;升燃料。它每行驶 1 英里就会用掉 1 升汽油。</p>

<p>当汽车到达加油站时，它可能停下来加油，将所有汽油从加油站转移到汽车中。</p>

<p>为了到达目的地，汽车所必要的最低加油次数是多少？如果无法到达目的地，则返回 <code>-1</code> 。</p>

<p>注意：如果汽车到达加油站时剩余燃料为 0，它仍然可以在那里加油。如果汽车到达目的地时剩余燃料为 0，仍然认为它已经到达目的地。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>target = 1, startFuel = 1, stations = []
<strong>输出：</strong>0
<strong>解释：</strong>我们可以在不加油的情况下到达目的地。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>target = 100, startFuel = 1, stations = [[10,100]]
<strong>输出：</strong>-1
<strong>解释：</strong>我们无法抵达目的地，甚至无法到达第一个加油站。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
<strong>输出：</strong>2
<strong>解释：</strong>
我们出发时有 10 升燃料。
我们开车来到距起点 10 英里处的加油站，消耗 10 升燃料。将汽油从 0 升加到 60 升。
然后，我们从 10 英里处的加油站开到 60 英里处的加油站（消耗 50 升燃料），
并将汽油从 10 升加到 50 升。然后我们开车抵达目的地。
我们沿途在1两个加油站停靠，所以返回 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 &lt;= target, startFuel, stations[i][1] &lt;= 10^9</code></li>
	<li><code>0 &lt;= stations.length &lt;= 500</code></li>
	<li><code>0 &lt; stations[0][0] &lt; stations[1][0] &lt; ... &lt; stations[stations.length-1][0] &lt; target</code></li>
</ol>

## 方法一：贪心 + 优先队列

这道题让人很容易想到递归。

这道题可参考题解[丛林探险](https://blog.csdn.net/Tisfy/article/details/122611633)

方法也很简单:

若在可用到达的距离范围内有多个加油站，则将这些加油站点的加油量入队（优先队列）。

若走到下一个加油站之前油会耗尽，则需要加油（优先队列中最大的加油量）后继续走。

当油量大于等于卡车到城镇的距离L时结束。

+ 时间复杂度$O(n\log n)$，其中$n$是加油站个数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        sort(stations.begin(), stations.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        int ans = 0;
        int canGo = startFuel;
        int loc = 0;
        priority_queue<int> pq;
        while (canGo < target) {
            while (loc < stations.size() && stations[loc][0] <= canGo) {
                pq.push(stations[loc][1]);
                loc++;
            }
            if (pq.empty())
                return -1;
            canGo += pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};
```


> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/07/02/LeetCode%200871.%E6%9C%80%E4%BD%8E%E5%8A%A0%E6%B2%B9%E6%AC%A1%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125575683](https://letmefly.blog.csdn.net/article/details/125575683)

