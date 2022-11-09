---
title: 1403.非递增顺序的最小子序列
date: 2022-08-04 10:47:16
tags: [题解, LeetCode, 简单, 贪心, 数组, 排序, 子问题, 最x子xx]
---

# 【LetMeFly】1403.非递增顺序的最小子序列

力扣题目链接：[https://leetcode.cn/problems/minimum-subsequence-in-non-increasing-order/](https://leetcode.cn/problems/minimum-subsequence-in-non-increasing-order/)

<p>给你一个数组 <code>nums</code>，请你从中抽取一个子序列，满足该子序列的元素之和 <strong>严格</strong> 大于未包含在该子序列中的各元素之和。</p>

<p>如果存在多个解决方案，只需返回 <strong>长度最小</strong> 的子序列。如果仍然有多个解决方案，则返回 <strong>元素之和最大</strong> 的子序列。</p>

<p>与子数组不同的地方在于，「数组的子序列」不强调元素在原数组中的连续性，也就是说，它可以通过从数组中分离一些（也可能不分离）元素得到。</p>

<p><strong>注意</strong>，题目数据保证满足所有约束条件的解决方案是 <strong>唯一</strong> 的。同时，返回的答案应当按 <strong>非递增顺序</strong> 排列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [4,3,10,9,8]
<strong>输出：</strong>[10,9] 
<strong>解释：</strong>子序列 [10,9] 和 [10,8] 是最小的、满足元素之和大于其他各元素之和的子序列。但是 [10,9] 的元素之和最大。&nbsp;
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [4,4,7,6,7]
<strong>输出：</strong>[7,7,6] 
<strong>解释：</strong>子序列 [7,7] 的和为 14 ，不严格大于剩下的其他元素之和（14 = 4 + 4 + 6）。因此，[7,6,7] 是满足题意的最小子序列。注意，元素按非递增顺序返回。  
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [6]
<strong>输出：</strong>[6]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 500</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>


    
## 方法一：排序取大

既然让子序列长度尽可能短，那么就要子序列中每个数取值尽可能大。

因此对原数组排序，大的在前。

预处理时，原数组求和并记录。

从前到后取出原数组中的元素，累加到子序列的和中。

如果子序列的和 ＞ 了剩余元素的和，就退出循环

返回子序列即可。

这样，满足题目要求的所有条件：严格大于、长度最小、元素和最大、非递增 等

+ 时间复杂度$O(n\log n)$，其中$n$是原数组的长度
+ 空间复杂度$O(log n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int s = 0;
        for (int i = 0; i < nums.size(); i++) {
            s += nums[i];
        }
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> ans;
        int nowSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans.push_back(nums[i]);
            nowSum += nums[i];
            if (nowSum > s - nowSum)
                break;
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/08/04/LeetCode%201403.%E9%9D%9E%E9%80%92%E5%A2%9E%E9%A1%BA%E5%BA%8F%E7%9A%84%E6%9C%80%E5%B0%8F%E5%AD%90%E5%BA%8F%E5%88%97/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126155397](https://letmefly.blog.csdn.net/article/details/126155397)
