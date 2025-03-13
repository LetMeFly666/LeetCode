---
title: 2389.和有限的最长子序列
date: 2023-03-17 13:06:47
tags: [题解, LeetCode, 简单, 贪心, 数组, 二分查找, 二分, 前缀和, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】2389.和有限的最长子序列

力扣题目链接：[https://leetcode.cn/problems/longest-subsequence-with-limited-sum/](https://leetcode.cn/problems/longest-subsequence-with-limited-sum/)

<p>给你一个长度为 <code>n</code>&nbsp;的整数数组 <code>nums</code> ，和一个长度为 <code>m</code> 的整数数组 <code>queries</code> 。</p>

<p>返回一个长度为 <code>m</code> 的数组<em> </em><code>answer</code><em> </em>，其中<em> </em><code>answer[i]</code><em> </em>是 <code>nums</code> 中<span style=""> </span>元素之和小于等于 <code>queries[i]</code> 的 <strong>子序列</strong> 的 <strong>最大</strong> 长度<span style="">&nbsp;</span><span style=""> </span>。</p>

<p><strong>子序列</strong> 是由一个数组删除某些元素（也可以不删除）但不改变剩余元素顺序得到的一个数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,5,2,1], queries = [3,10,21]
<strong>输出：</strong>[2,3,4]
<strong>解释：</strong>queries 对应的 answer 如下：
- 子序列 [2,1] 的和小于或等于 3 。可以证明满足题目要求的子序列的最大长度是 2 ，所以 answer[0] = 2 。
- 子序列 [4,5,1] 的和小于或等于 10 。可以证明满足题目要求的子序列的最大长度是 3 ，所以 answer[1] = 3 。
- 子序列 [4,5,2,1] 的和小于或等于 21 。可以证明满足题目要求的子序列的最大长度是 4 ，所以 answer[2] = 4 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,3,4,5], queries = [1]
<strong>输出：</strong>[0]
<strong>解释：</strong>空子序列是唯一一个满足元素和小于或等于 1 的子序列，所以 answer[0] = 0 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>m == queries.length</code></li>
	<li><code>1 &lt;= n, m &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i], queries[i] &lt;= 10<sup>6</sup></code></li>
</ul>


    
## 方法一：前缀和 + 二分

这道题要的是“子序列”。什么意思？意思就是随便删除数组中的元素，不必保证连续。

那么想要尽可能多的数字的和不超过```q```，当然是要这些数字尽可能地小。

因此我们给原数组中的元素从小到大排序，再使用前缀和的方法令```nums[i]```为“nums[0]到nums[i]的元素和”。

这样，我们在寻找“和不超过```q```”的最长序列时，只需要二分找到```nums```中最后一个不大于```q```的元素的**位置**，这就说明排过序的nums数组中这个元素及其之前的所有元素的和不超过```q```，且这是最后一个满足上述条件的位置。

这个位置即为所求。

+ 时间复杂度$O(len(nums)\times \log len(nums) + len(queries)\times\log len(nums))$，排序的时间复杂度是$O(len(nums)\times \log len(nums)$，每次查找的时间复杂度是$O(\log len(nums))$
+ 空间复杂度$O(\log len(nums))$，这里我们修改了$nums$数组和$queries$数组，只是排序时用到了$O(\log len(nums))$的空间

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }
        for (int& q : queries) {
            q = upper_bound(nums.begin(), nums.end(), q) - nums.begin();
        }
        return queries;
    }
};
```

#### Python

```python
# from typing import List
# import bisect


class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        nums.sort()
        for i in range(1, len(nums)):
            nums[i] += nums[i - 1]
        for i, q in enumerate(queries):  # 这里for q in queries的话，修改q是不会修改queries中的值的
            queries[i] = bisect.bisect_right(nums, q)
        return queries
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/03/17/LeetCode%202389.%E5%92%8C%E6%9C%89%E9%99%90%E7%9A%84%E6%9C%80%E9%95%BF%E5%AD%90%E5%BA%8F%E5%88%97/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129618747](https://letmefly.blog.csdn.net/article/details/129618747)
