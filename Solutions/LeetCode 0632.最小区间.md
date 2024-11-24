---
title: 632.最小区间
date: 2024-11-24 18:36:13
tags: [题解, LeetCode, 困难, 贪心, 数组, 哈希表, 排序, 滑动窗口, 堆（优先队列）]
---

# 【LetMeFly】632.最小区间：优先队列

力扣题目链接：[https://leetcode.cn/problems/smallest-range-covering-elements-from-k-lists/](https://leetcode.cn/problems/smallest-range-covering-elements-from-k-lists/)

<p>你有&nbsp;<code>k</code>&nbsp;个 <strong>非递减排列</strong> 的整数列表。找到一个 <strong>最小 </strong>区间，使得&nbsp;<code>k</code>&nbsp;个列表中的每个列表至少有一个数包含在其中。</p>

<p>我们定义如果&nbsp;<code>b-a &lt; d-c</code>&nbsp;或者在&nbsp;<code>b-a == d-c</code>&nbsp;时&nbsp;<code>a &lt; c</code>，则区间 <code>[a,b]</code> 比 <code>[c,d]</code> 小。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
<strong>输出：</strong>[20,24]
<strong>解释：</strong> 
列表 1：[4, 10, 15, 24, 26]，24 在区间 [20,24] 中。
列表 2：[0, 9, 12, 20]，20 在区间 [20,24] 中。
列表 3：[5, 18, 22, 30]，22 在区间 [20,24] 中。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [[1,2,3],[1,2,3],[1,2,3]]
<strong>输出：</strong>[1,1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>nums.length == k</code></li>
	<li><code>1 &lt;= k &lt;= 3500</code></li>
	<li><code>1 &lt;= nums[i].length &lt;= 50</code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i][j] &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code> 按非递减顺序排列</li>
</ul>

<p>&nbsp;</p>


    
## 解题方法：优先队列

使用一个优先队列，每个“整数列表”放一个元素到优先队列中，优先队列以“列表元素最小”为最优先。

优先队列中存放的，是每个列表本次要覆盖的元素。

每次从优先队列中取出一个元素：

> 那么这次方案(取出之前)的最小值就是取出的这个元素，最大值我们使用一个值记录并在入队时候更新。
>
> 更新最佳方案：如果当前方案优于之前的最佳方案，就更新最佳方案为这个方案。
>
> 新元素入队：如果出队元素所在列表还有新元素，则下一个元素入队，并记得更新“最大值”；否则结束循环。

+ 时间复杂度$O(nk\log k)$
+ 空间复杂度$O(k)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> loc(nums.size());
        auto cmp = [&nums, &loc](const int& x, const int& y) {
            return nums[x][loc[x]] > nums[y][loc[y]];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        int m = -1e8, M = -1e6;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(i);
            M = max(M, nums[i][0]);
        }
        int nowm, nowM = M;
        while (pq.size()) {
            int index = pq.top();
            pq.pop();
            nowm = nums[index][loc[index]];
            loc[index]++;
            if (nowM - nowm < M - m) {
                M = nowM;
                m = nowm;
            }
            if (loc[index] == nums[index].size()) {
                break;
            }
            nowM = max(nowM, nums[index][loc[index]]);
            pq.push(index);
        }
        return {m, M};
    }
};
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/11/24/LeetCode%200632.%E6%9C%80%E5%B0%8F%E5%8C%BA%E9%97%B4/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/144011635](https://letmefly.blog.csdn.net/article/details/144011635)
