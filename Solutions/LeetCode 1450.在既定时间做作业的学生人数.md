---
title: 1450.在既定时间做作业的学生人数
date: 2022-08-19 08:30:46
tags: [题解, LeetCode, 简单, 数组, 遍历]
---

# 【LetMeFly】1450.在既定时间做作业的学生人数

力扣题目链接：[https://leetcode.cn/problems/number-of-students-doing-homework-at-a-given-time/](https://leetcode.cn/problems/number-of-students-doing-homework-at-a-given-time/)

<p>给你两个整数数组 <code>startTime</code>（开始时间）和 <code>endTime</code>（结束时间），并指定一个整数 <code>queryTime</code> 作为查询时间。</p>

<p>已知，第 <code>i</code> 名学生在 <code>startTime[i]</code> 时开始写作业并于 <code>endTime[i]</code> 时完成作业。</p>

<p>请返回在查询时间 <code>queryTime</code> 时正在做作业的学生人数。形式上，返回能够使 <code>queryTime</code> 处于区间 <code>[startTime[i], endTime[i]]</code>（含）的学生人数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>startTime = [1,2,3], endTime = [3,2,7], queryTime = 4
<strong>输出：</strong>1
<strong>解释：</strong>一共有 3 名学生。
第一名学生在时间 1 开始写作业，并于时间 3 完成作业，在时间 4 没有处于做作业的状态。
第二名学生在时间 2 开始写作业，并于时间 2 完成作业，在时间 4 没有处于做作业的状态。
第三名学生在时间 3 开始写作业，预计于时间 7 完成作业，这是是唯一一名在时间 4 时正在做作业的学生。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>startTime = [4], endTime = [4], queryTime = 4
<strong>输出：</strong>1
<strong>解释：</strong>在查询时间只有一名学生在做作业。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>startTime = [4], endTime = [4], queryTime = 5
<strong>输出：</strong>0
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>startTime = [1,1,1,1], endTime = [1,3,2,4], queryTime = 7
<strong>输出：</strong>0
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>startTime = [9,8,7,6,5,4,3,2,1], endTime = [10,10,10,10,10,10,10,10,10], queryTime = 5
<strong>输出：</strong>5
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>startTime.length == endTime.length</code></li>
	<li><code>1 &lt;= startTime.length &lt;= 100</code></li>
	<li><code>1 &lt;= startTime[i] &lt;= endTime[i] &lt;= 1000</code></li>
	<li><code>1 &lt;=&nbsp;queryTime &lt;= 1000</code></li>
</ul>


    
## 方法一：遍历

遍历一遍学生，如果某个学生学习的开始时间不晚于查询时间，并且结束时间不早于查询时间，那么答案数量加一。

+ 时间复杂度$O(n)$，其中$n$是学生人数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int ans = 0;
        for (int i = startTime.size() - 1; i >= 0; i--) {
            if (startTime[i] <= queryTime && endTime[i] >= queryTime)
                ans++;
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/08/19/LeetCode%201450.%E5%9C%A8%E6%97%A2%E5%AE%9A%E6%97%B6%E9%97%B4%E5%81%9A%E4%BD%9C%E4%B8%9A%E7%9A%84%E5%AD%A6%E7%94%9F%E4%BA%BA%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126417256](https://letmefly.blog.csdn.net/article/details/126417256)
