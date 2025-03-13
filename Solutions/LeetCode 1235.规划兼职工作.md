---
title: 1235.规划兼职工作
date: 2022-10-22 10:00:11
tags: [题解, LeetCode, 困难, 数组, 二分查找, 动态规划, 排序, 哈希表, 哈希, 离散化]
categories: [题解, LeetCode]
---

# 【LetMeFly】1235.规划兼职工作：[离散化：多次哈希 + DPx1] | [二分查找 + DP]

力扣题目链接：[https://leetcode.cn/problems/maximum-profit-in-job-scheduling/](https://leetcode.cn/problems/maximum-profit-in-job-scheduling/)

<p>你打算利用空闲时间来做兼职工作赚些零花钱。</p>

<p>这里有&nbsp;<code>n</code>&nbsp;份兼职工作，每份工作预计从&nbsp;<code>startTime[i]</code>&nbsp;开始到&nbsp;<code>endTime[i]</code>&nbsp;结束，报酬为&nbsp;<code>profit[i]</code>。</p>

<p>给你一份兼职工作表，包含开始时间&nbsp;<code>startTime</code>，结束时间&nbsp;<code>endTime</code>&nbsp;和预计报酬&nbsp;<code>profit</code>&nbsp;三个数组，请你计算并返回可以获得的最大报酬。</p>

<p>注意，时间上出现重叠的 2 份工作不能同时进行。</p>

<p>如果你选择的工作在时间&nbsp;<code>X</code>&nbsp;结束，那么你可以立刻进行在时间&nbsp;<code>X</code>&nbsp;开始的下一份工作。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/10/19/sample1_1584.png" style="width: 300px;"></strong></p>

<pre><strong>输入：</strong>startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
<strong>输出：</strong>120
<strong>解释：
</strong>我们选出第 1 份和第 4 份工作， 
时间范围是 [1-3]+[3-6]，共获得报酬 120 = 50 + 70。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/10/19/sample22_1584.png" style="height: 112px; width: 600px;"> </strong></p>

<pre><strong>输入：</strong>startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
<strong>输出：</strong>150
<strong>解释：
</strong>我们选择第 1，4，5 份工作。 
共获得报酬 150 = 20 + 70 + 60。
</pre>

<p><strong>示例 3：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/10/19/sample3_1584.png" style="height: 112px; width: 400px;"></strong></p>

<pre><strong>输入：</strong>startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
<strong>输出：</strong>6
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= startTime.length == endTime.length ==&nbsp;profit.length&nbsp;&lt;= 5 * 10^4</code></li>
	<li><code>1 &lt;=&nbsp;startTime[i] &lt;&nbsp;endTime[i] &lt;= 10^9</code></li>
	<li><code>1 &lt;=&nbsp;profit[i] &lt;= 10^4</code></li>
</ul>


    
## 方法一：离散化：多次哈希 + DPx1

我们将所有出现过的时间记录下来并排序，那么我们就只需要考虑“出现过的时间”这些特殊节点，最多一共$2n$个节点。

假设一共有$n$个节点（$appearedTime.size() = n$），我们建立一个长度为$n$的$dp$数组，其中$dp[i]$代表到时间$appearedTime[i]$为止的最大获利。

$dp[i] = \max\{dp[i - 1], dp[第t份工作的开始时间在appearedTime中的下标] + profit[t]\}$，其中$endTime[t] = appearedTime[i]$

什么意思呢？就是假如有一份工作在$appearedTime[i]$时刻结束，那么选择这份工作的话获利为$这份工作开始时的最大获利 + 这份工作的工资 = dp[这份工作开始时间对应的index] + profit[这份工作]$

以上所有需要用到的东西，均由哈希表映射即可。

### 如何处理出现过的时间节点

首先将所有出现过的时间放入哈希表中，然后将哈希表中的所有时间取出来，再排个序

```cpp
int n = startTime.size();
// 插入哈希表
unordered_set<int> appearedTimeSet;  // 所有的出现过的时间
for (int i = 0; i < n; i++) {
    appearedTimeSet.insert(startTime[i]);
    appearedTimeSet.insert(endTime[i]);
}
// 存入数组并排序
vector<int> appearedTime;
for (const int& t : appearedTimeSet) {
    appearedTime.push_back(t);
}
sort(appearedTime.begin(), appearedTime.end());
```

### 如何由结束时间映射到这是第几份工作

将```<工作结束时间, 这是第几份工作>```插入哈希表，就可以通过```工作结束时间```获取所有的```在这个时间结束的工作```

```cpp
int n = startTime.size();

unordered_multimap<int, int> endBy;  // <在这个时间结束, 这个任务对应的编号>
for (int i = 0; i < n; i++) {
    endBy.insert({endTime[i], i});
}
```

### 如何由工作的开始时间映射到其在appearedTime中的index

遍历appearedTime中的时间，将```<时间, 这个时间的index>```插入哈希表

```cpp
int nTime = appearedTime.size();
unordered_map<int, int> time2loc;
for (int i = 0; i < nTime; i++) {
    time2loc[appearedTime[i]] = i;
}
```

### 动态规划部分怎么实现

```cpp
vector<int> dp(nTime);
for (int i = 1; i < nTime; i++) {
    dp[i] = dp[i - 1];  // 继承上一时刻的最大获利
    auto range = endBy.equal_range(appearedTime[i]);  // 结束时间等于appearedTime[i]的所有的工作 在哈希表中存在的范围
    for_each(range.first, range.second, [&](unordered_multimap<int, int>::value_type& x) {  // 对于在appearedTime[i]结束的每一份工作
        // x.second是这份工作的编号
        // startTime[x.second]是这份工作的开始时间
        // time2loc[startTime[x.second]]是这份工作的开始时间在appearedTime中对应的下标
        // dp[time2loc[startTime[x.second]]是这份工作开始时间的最大获利
        // profit[x.second]是这份工作的获利
        dp[i] = max(dp[i], dp[time2loc[startTime[x.second]]] + profit[x.second]);
    });
}
// dp中的最后一个元素（所有出现过的时刻中的最后一个时刻）即为答案
return dp.back();
```

+ 时间复杂度$O(\n log n)$，其中$n$是工作数量，时间复杂度主要来自排序
+ 空间复杂度$O(n)$，使用了数次哈希表，每次的空间复杂度都是$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        unordered_set<int> appearedTimeSet;  // 所有的出现过的时间
        unordered_multimap<int, int> endBy;  // <在这个时间结束, 这个任务对应的编号>
        int n = startTime.size();
        for (int i = 0; i < n; i++) {
            appearedTimeSet.insert(startTime[i]);
            appearedTimeSet.insert(endTime[i]);
            endBy.insert({endTime[i], i});
        }
        vector<int> appearedTime;
        for (const int& t : appearedTimeSet) {
            appearedTime.push_back(t);
        }
        sort(appearedTime.begin(), appearedTime.end());
        int nTime = appearedTime.size();
        unordered_map<int, int> time2loc;
        for (int i = 0; i < nTime; i++) {
            time2loc[appearedTime[i]] = i;
        }
        vector<int> dp(nTime);
        for (int i = 1; i < nTime; i++) {
            dp[i] = dp[i - 1];
            auto range = endBy.equal_range(appearedTime[i]);
            for_each(range.first, range.second, [&](unordered_multimap<int, int>::value_type& x) {
                dp[i] = max(dp[i], dp[time2loc[startTime[x.second]]] + profit[x.second]);
            });
            printf("i = %d, appearedTime[%d] = %d, dp[%d] = %d\n", i, i, appearedTime[i], i, dp[i]);  //************
        }
        return dp.back();
    }
};
```

## 方法二：二分查找 + DP

方法一中我们使用了数个哈希表将时间和工作映射了起来

方法二学习自力扣官解：[https://leetcode.cn/problems/maximum-profit-in-job-scheduling/solution/gui-hua-jian-zhi-gong-zuo-by-leetcode-so-gu0e/](https://leetcode.cn/problems/maximum-profit-in-job-scheduling/solution/gui-hua-jian-zhi-gong-zuo-by-leetcode-so-gu0e/)

这种方法中，$dp[i]$代表前$i$份兼职工作可以获得的最大报酬。

因此，$dp[i] = \max\{dp[i-1], dp[k] + profit[i - 1]\}$，其中$k$表示结束时间不超过第$i-1$份工作的开始时间的工作数量

这个$k$怎么来呢？当然是二分查找

因此我们还需要对工作按照“结束时间”从小到大排个序。

+ 时间复杂度$O(\n log n)$，其中$n$是工作数量，时间复杂度主要来自排序
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        for (int i = 0; i < n; i++) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end(), [&](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            int k = upper_bound(jobs.begin(), jobs.begin() + i - 1, jobs[i - 1][0], [&](int st, vector<int>& job) {
                return st < job[1];
            }) - jobs.begin();
            dp[i] = max(dp[i - 1], dp[k] + jobs[i - 1][2]);
        }
        return dp[n];
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/10/22/LeetCode%201235.%E8%A7%84%E5%88%92%E5%85%BC%E8%81%8C%E5%B7%A5%E4%BD%9C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127458533](https://letmefly.blog.csdn.net/article/details/127458533)
