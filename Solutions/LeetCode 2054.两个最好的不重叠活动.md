---
title: 2054.两个最好的不重叠活动：二分查找
date: 2025-12-23 23:45:19
tags: [题解, LeetCode, 中等, 数组, 二分查找, 动态规划, 排序]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.com/uploads/2021/09/21/picture5.png
---

# 【LetMeFly】2054.两个最好的不重叠活动：二分查找

力扣题目链接：[https://leetcode.cn/problems/two-best-non-overlapping-events/](https://leetcode.cn/problems/two-best-non-overlapping-events/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的二维整数数组&nbsp;<code>events</code>&nbsp;，其中&nbsp;<code>events[i] = [startTime<sub>i</sub>, endTime<sub>i</sub>, value<sub>i</sub>]</code>&nbsp;。第&nbsp;<code>i</code>&nbsp;个活动开始于&nbsp;<code>startTime<sub>i</sub></code>&nbsp;，结束于&nbsp;<code>endTime<sub>i</sub></code>&nbsp;，如果你参加这个活动，那么你可以得到价值&nbsp;<code>value<sub>i</sub></code>&nbsp;。你 <strong>最多</strong>&nbsp;可以参加&nbsp;<strong>两个时间不重叠</strong>&nbsp;活动，使得它们的价值之和 <strong>最大</strong>&nbsp;。</p>

<p>请你返回价值之和的 <strong>最大值</strong>&nbsp;。</p>

<p>注意，活动的开始时间和结束时间是 <strong>包括</strong>&nbsp;在活动时间内的，也就是说，你不能参加两个活动且它们之一的开始时间等于另一个活动的结束时间。更具体的，如果你参加一个活动，且结束时间为 <code>t</code>&nbsp;，那么下一个活动必须在&nbsp;<code>t + 1</code>&nbsp;或之后的时间开始。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/09/21/picture5.png" style="width: 400px; height: 75px;"></p>

<pre><b>输入：</b>events = [[1,3,2],[4,5,2],[2,4,3]]
<b>输出：</b>4
<strong>解释：</strong>选择绿色的活动 0 和 1 ，价值之和为 2 + 2 = 4 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="Example 1 Diagram" src="https://assets.leetcode.com/uploads/2021/09/21/picture1.png" style="width: 400px; height: 77px;"></p>

<pre><b>输入：</b>events = [[1,3,2],[4,5,2],[1,5,5]]
<b>输出：</b>5
<strong>解释：</strong>选择活动 2 ，价值和为 5 。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/09/21/picture3.png" style="width: 400px; height: 66px;"></p>

<pre><b>输入：</b>events = [[1,5,3],[1,5,1],[6,6,5]]
<b>输出：</b>8
<strong>解释：</strong>选择活动 0 和 2 ，价值之和为 3 + 5 = 8 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= events.length &lt;= 10<sup>5</sup></code></li>
	<li><code>events[i].length == 3</code></li>
	<li><code>1 &lt;= startTime<sub>i</sub> &lt;= endTime<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= value<sub>i</sub> &lt;= 10<sup>6</sup></code></li>
</ul>


    
## 解题方法：二分查找

如果只能选一个event，那么好说，哪个价值大选哪个；如果一定要选两个event，假设第二个event选事件e，那么第一个event一定要选结束时间早于e开始时间的所有事件中价值最大的那个。

很显然，为了枚举第一个event的可选范围，可以以结束时间为依据对所有event按从小到大排个序。

接着使用一个（有序）数组maxValue，数组中存放的内容是：到xx时刻为止，单个event的最大价值是多少。排序依据是结束时间。

遍历所有事件，对于某事件e，二分查找maxValue中小于e开始时间中最大的那个，其值加上e的价值即为第二个event选e情况下的最优解。之后更新e结束时间的单个事件最大值。

+ 时间复杂度$O(n\log n)$，其中$n=len(events)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2025-12-23 18:58:01
 */
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        vector<pair<int, int>> maxValue;
        int singleMax = 0, pairMax = 0;
        for (vector<int>& e : events) {
            vector<pair<int, int>>::iterator it = lower_bound(maxValue.begin(), maxValue.end(), e[0], [](const pair<int, int>& p, int value) {
                return p.first < value;
            });
            if (it != maxValue.begin()) {
                pairMax = max(pairMax, (--it)->second + e[2]);
            }
            singleMax = max(singleMax, e[2]);
            maxValue.push_back({e[1], singleMax});
        }
        return max(pairMax, singleMax);
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/156207232)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/12/23/LeetCode%202054.%E4%B8%A4%E4%B8%AA%E6%9C%80%E5%A5%BD%E7%9A%84%E4%B8%8D%E9%87%8D%E5%8F%A0%E6%B4%BB%E5%8A%A8/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
