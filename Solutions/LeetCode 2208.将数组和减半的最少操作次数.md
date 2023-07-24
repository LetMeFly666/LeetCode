---
title: 2208.将数组和减半的最少操作次数：贪心（优先队列）
date: 2023-07-25 06:34:51
tags: [题解, LeetCode, 中等, 贪心, 数组, 堆（优先队列）, 堆, 大根堆, 优先队列]
---

# 【LetMeFly】2208.将数组和减半的最少操作次数：贪心（优先队列）

力扣题目链接：[https://leetcode.cn/problems/minimum-operations-to-halve-array-sum/](https://leetcode.cn/problems/minimum-operations-to-halve-array-sum/)

<p>给你一个正整数数组&nbsp;<code>nums</code>&nbsp;。每一次操作中，你可以从&nbsp;<code>nums</code>&nbsp;中选择 <strong>任意</strong>&nbsp;一个数并将它减小到 <strong>恰好</strong>&nbsp;一半。（注意，在后续操作中你可以对减半过的数继续执行操作）</p>

<p>请你返回将 <code>nums</code>&nbsp;数组和 <strong>至少</strong>&nbsp;减少一半的 <strong>最少</strong>&nbsp;操作数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [5,19,8,1]
<b>输出：</b>3
<b>解释：</b>初始 nums 的和为 5 + 19 + 8 + 1 = 33 。
以下是将数组和减少至少一半的一种方法：
选择数字 19 并减小为 9.5 。
选择数字 9.5 并减小为 4.75 。
选择数字 8 并减小为 4 。
最终数组为 [5, 4.75, 4, 1] ，和为 5 + 4.75 + 4 + 1 = 14.75 。
nums 的和减小了 33 - 14.75 = 18.25 ，减小的部分超过了初始数组和的一半，18.25 &gt;= 33/2 = 16.5 。
我们需要 3 个操作实现题目要求，所以返回 3 。
可以证明，无法通过少于 3 个操作使数组和减少至少一半。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [3,8,20]
<b>输出：</b>3
<strong>解释：</strong>初始 nums 的和为 3 + 8 + 20 = 31 。
以下是将数组和减少至少一半的一种方法：
选择数字 20 并减小为 10 。
选择数字 10 并减小为 5 。
选择数字 3 并减小为 1.5 。
最终数组为 [1.5, 8, 5] ，和为 1.5 + 8 + 5 = 14.5 。
nums 的和减小了 31 - 14.5 = 16.5 ，减小的部分超过了初始数组和的一半， 16.5 &gt;= 31/2 = 16.5 。
我们需要 3 个操作实现题目要求，所以返回 3 。
可以证明，无法通过少于 3 个操作使数组和减少至少一半。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>7</sup></code></li>
</ul>


    
## 方法一：贪心（优先队列）

思路很简单，每次将数组中最大的元素减半即可。

具体怎么实现呢？很多编程语言都有“优先队列”。因此我们只需要使用一个```大根堆```（出队时大元素优先的优先队列），每次将队首元素取出减半并放回即可。

+ 时间复杂度$O(len(nums)\times \log len(nums))$，操作次数不超过数组长度。
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double s = 0;
        for (int t : nums) {
            pq.push(t);
            s += t;
        }
        double need = s / 2;
        int ans = 0;
        while (need > 0) {
            double thisValue = pq.top();
            pq.pop();
            thisValue /= 2;
            need -= thisValue;
            pq.push(thisValue);
            ans++;
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List
# import heapq

class Solution:
    def halveArray(self, nums: List[int]) -> int:
        pq = []
        s = 0
        for t in nums:
            heapq.heappush(pq, -t)
            s += t
        need = s / 2
        ans = 0
        while need > 0:
            thisValue = -heapq.heappop(pq)
            thisValue /= 2
            need -= thisValue
            ans += 1
            heapq.heappush(pq, -thisValue)
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/07/25/LeetCode%202208.%E5%B0%86%E6%95%B0%E7%BB%84%E5%92%8C%E5%87%8F%E5%8D%8A%E7%9A%84%E6%9C%80%E5%B0%91%E6%93%8D%E4%BD%9C%E6%AC%A1%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131908685](https://letmefly.blog.csdn.net/article/details/131908685)
