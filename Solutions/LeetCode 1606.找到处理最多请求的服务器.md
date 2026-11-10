---
title: 1606.找到处理最多请求的服务器：有序集合+优先队列（模拟）
date: 2026-11-09 21:44:02
tags: [题解, LeetCode, 困难, 数组, 有序集合, 优先队列, 模拟, 大模拟, 堆（优先队列）, 计数]
categories: [题解, LeetCode]
---

# 【LetMeFly】1606.找到处理最多请求的服务器：有序集合+优先队列（模拟）

力扣题目链接：[https://leetcode.cn/problems/find-servers-that-handled-most-number-of-requests/](https://leetcode.cn/problems/find-servers-that-handled-most-number-of-requests/)

<p>你有 <code>k</code>&nbsp;个服务器，编号为 <code>0</code>&nbsp;到 <code>k-1</code>&nbsp;，它们可以同时处理多个请求组。每个服务器有无穷的计算能力但是 <strong>不能同时处理超过一个请求</strong>&nbsp;。请求分配到服务器的规则如下：</p>

<ul>
	<li>第&nbsp;<code>i</code>&nbsp;（序号从 0 开始）个请求到达。</li>
	<li>如果所有服务器都已被占据，那么该请求被舍弃（完全不处理）。</li>
	<li>如果第&nbsp;<code>(i % k)</code>&nbsp;个服务器空闲，那么对应服务器会处理该请求。</li>
	<li>否则，将请求安排给下一个空闲的服务器（服务器构成一个环，必要的话可能从第 0 个服务器开始继续找下一个空闲的服务器）。比方说，如果第 <code>i</code>&nbsp;个服务器在忙，那么会查看第 <code>(i+1)</code>&nbsp;个服务器，第 <code>(i+2)</code>&nbsp;个服务器等等。</li>
</ul>

<p>给你一个 <strong>严格递增</strong>&nbsp;的正整数数组&nbsp;<code>arrival</code>&nbsp;，表示第&nbsp;<code>i</code>&nbsp;个任务的到达时间，和另一个数组&nbsp;<code>load</code>&nbsp;，其中&nbsp;<code>load[i]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;个请求的工作量（也就是服务器完成它所需要的时间）。你的任务是找到 <strong>最繁忙的服务器</strong>&nbsp;。最繁忙定义为一个服务器处理的请求数是所有服务器里最多的。</p>

<p>请你返回包含所有&nbsp;<strong>最繁忙服务器</strong>&nbsp;序号的列表，你可以以任意顺序返回这个列表。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.cn/aliyun-lc-upload/uploads/2020/10/03/load-1.png" style="height: 221px; width: 389px;" /></p>

<pre>
<strong>输入：</strong>k = 3, arrival = [1,2,3,4,5], load = [5,2,3,3,3] 
<strong>输出：</strong>[1] 
<strong>解释：</strong>
所有服务器一开始都是空闲的。
前 3 个请求分别由前 3 台服务器依次处理。
请求 3 进来的时候，服务器 0 被占据，所以它被安排到下一台空闲的服务器，也就是服务器 1 。
请求 4 进来的时候，由于所有服务器都被占据，该请求被舍弃。
服务器 0 和 2 分别都处理了一个请求，服务器 1 处理了两个请求。所以服务器 1 是最忙的服务器。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>k = 3, arrival = [1,2,3,4], load = [1,2,1,2]
<strong>输出：</strong>[0]
<strong>解释：</strong>
前 3 个请求分别被前 3 个服务器处理。
请求 3 进来，由于服务器 0 空闲，它被服务器 0 处理。
服务器 0 处理了两个请求，服务器 1 和 2 分别处理了一个请求。所以服务器 0 是最忙的服务器。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>k = 3, arrival = [1,2,3], load = [10,12,11]
<strong>输出：</strong>[0,1,2]
<strong>解释：</strong>每个服务器分别处理了一个请求，所以它们都是最忙的服务器。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>k = 3, arrival = [1,2,3,4,8,9,10], load = [5,2,10,3,1,2,2]
<strong>输出：</strong>[1]
</pre>

<p><strong>示例 5：</strong></p>

<pre>
<strong>输入：</strong>k = 1, arrival = [1], load = [1]
<strong>输出：</strong>[0]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= arrival.length, load.length &lt;= 10<sup>5</sup></code></li>
	<li><code>arrival.length == load.length</code></li>
	<li><code>1 &lt;= arrival[i], load[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>arrival</code>&nbsp;保证 <strong>严格递增</strong>&nbsp;。</li>
</ul>


    
## 解题方法：有序集合+优先队列（模拟）

1. 使用一个有序集合$available$来维护当前空闲的服务器（初始值是$0$到$k-1$）。使用有序集合的原因是方便在$O(\log k)$的时间内找到最小的$\geq i\%k$的服务器编号。
2. 使用一个优先队列$working$来维护当前正在工作的服务器，排序依据是服务器工作完成的时间，存储内容除了服务器工作完成时间外还有服务器编号。
3. 使用一个数组$cnt$记录每个服务器处理的请求数。

遍历每一个请求，对于到达时间是$arrive$且工作时长是$cost$的请求：

1. 当$working$非空且$队首元素\leq arrive$时，不断将这些在此刻（$arrive$时刻）已经完成任务的服务器出队并加入到$available$中。
2. 如果$available$为空，说明所有服务器都在工作，当前请求被舍。
3. 否则，二分查找$available$中最小的$\geq i\%k$的服务器编号，如果找不到则循环取到$available$的最小编号。这个编号的服务器处理当前请求（从$available$中删除、服务次数加一、将该任务完成时间$arrive+cost$和服务器编号加入到$working$中）。

遍历一次计数数组找到最大服务次数，再遍历一次计数数组将服务次数等于最大服务次数的所有服务器加入答案数组中。

+ 时间复杂度$O(k+\len(arrival)\log k)$
+ 空间复杂度$O(k)$，力扣返回值不计入算法空间复杂度

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-11-09 21:43:36
 */
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available(views::iota(0, k).begin(), views::iota(0, k).end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> working;  // [<time_available, id>, ...
        int n = arrival.size();
        vector<int> cnt(k);
        for (int i = 0; i < n; i++) {
            int arrive = arrival[i];
            while (!working.empty()) {
                auto &&[time_available, id] = working.top();
                if (time_available > arrive) {
                    break;
                }
                available.insert(id);
                working.pop();
            }
            if (available.empty()) {
                continue;
            }
            set<int>::iterator it = available.lower_bound(i % k);
            if (it == available.end()) {
                it = available.begin();
            }
            int id = *it;
            available.erase(it);
            cnt[id]++;
            int cost = load[i];
            working.push({arrive + cost, id});
        }
        int max_times = *ranges::max_element(cnt);
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            if (cnt[i] == max_times) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/170369089)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/11/09/LeetCode%201606.%E6%89%BE%E5%88%B0%E5%A4%84%E7%90%86%E6%9C%80%E5%A4%9A%E8%AF%B7%E6%B1%82%E7%9A%84%E6%9C%8D%E5%8A%A1%E5%99%A8/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
