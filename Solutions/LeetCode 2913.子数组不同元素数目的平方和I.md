---
title: 2913.子数组不同元素数目的平方和 I：第一题先常数很大的O(n^2)
date: 2026-10-15 22:23:12
tags: [题解, LeetCode, 简单, 线段树, 数组, 哈希表, set, 模拟, 暴力]
categories: [题解, LeetCode]
---

# 【LetMeFly】2913.子数组不同元素数目的平方和 I：第一题先常数很大的O(n^2)

力扣题目链接：[https://leetcode.cn/problems/subarrays-distinct-element-sum-of-squares-i/](https://leetcode.cn/problems/subarrays-distinct-element-sum-of-squares-i/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>定义 <code>nums</code>&nbsp;一个子数组的 <strong>不同计数</strong>&nbsp;值如下：</p>

<ul>
	<li>令&nbsp;<code>nums[i..j]</code>&nbsp;表示 <code>nums</code> 中所有下标在 <code>i</code> 到 <code>j</code> 范围内的元素构成的子数组（满足 <code>0 &lt;= i &lt;= j &lt; nums.length</code> ），那么我们称子数组&nbsp;<code>nums[i..j]</code>&nbsp;中不同值的数目为&nbsp;<code>nums[i..j]</code>&nbsp;的不同计数。</li>
</ul>

<p>请你返回 <code>nums</code>&nbsp;中所有子数组的 <strong>不同计数</strong>&nbsp;的 <strong>平方</strong>&nbsp;和。</p>

<p>由于答案可能会很大，请你将它对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;后返回。</p>

<p>子数组指的是一个数组里面一段连续 <strong>非空</strong>&nbsp;的元素序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,1]
<b>输出：</b>15
<b>解释：</b>六个子数组分别为：
[1]: 1 个互不相同的元素。
[2]: 1 个互不相同的元素。
[1]: 1 个互不相同的元素。
[1,2]: 2 个互不相同的元素。
[2,1]: 2 个互不相同的元素。
[1,2,1]: 2 个互不相同的元素。
所有不同计数的平方和为 1<sup>2</sup> + 1<sup>2</sup> + 1<sup>2</sup> + 2<sup>2</sup> + 2<sup>2</sup> + 2<sup>2</sup> = 15 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [2,2]
<b>输出：3</b>
<strong>解释：</strong>三个子数组分别为：
[2]: 1 个互不相同的元素。
[2]: 1 个互不相同的元素。
[2,2]: 1 个互不相同的元素。
所有不同计数的平方和为 1<sup>2</sup> + 1<sup>2</sup> + 1<sup>2</sup> = 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>


    
## 解题方法：二重循环模拟

第一重循环用变量$i$枚举子数组起点，第二重循环用变量$j$枚举子数组终点，使用一个set来统计子数组中不同元素的个数，并将哈希表大小的平方累加到答案中。在第二重循环的过程中直接将$j$对应的元素加入到哈希表中。

+ 时间复杂度$O(len(nums)^2)$
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-10-15 22:22:31
 */
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        for (int i = 0, n = nums.size(); i < n; i++) {
            unordered_set<int> se;
            for (int j = i; j < n; j++) {
                se.insert(nums[j]);
                ans += se.size() * se.size();
            }
        }
        return ans;
    }
};
```

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/168030918)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/10/15/LeetCode%202913.%E5%AD%90%E6%95%B0%E7%BB%84%E4%B8%8D%E5%90%8C%E5%85%83%E7%B4%A0%E6%95%B0%E7%9B%AE%E7%9A%84%E5%B9%B3%E6%96%B9%E5%92%8CI/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
