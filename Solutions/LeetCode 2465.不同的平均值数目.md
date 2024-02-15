---
title: 2465.不同的平均值数目：排序 + 双指针 + 哈希
date: 2023-06-04 22:18:11
tags: [题解, LeetCode, 简单, 数组, 哈希表, 哈希, set, 双指针, 排序]
---

# 【LetMeFly】2465.不同的平均值数目：排序 + 双指针 + 哈希

力扣题目链接：[https://leetcode.cn/problems/number-of-distinct-averages/](https://leetcode.cn/problems/number-of-distinct-averages/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始长度为 <strong>偶数</strong>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>只要&nbsp;<code>nums</code> <strong>不是</strong>&nbsp;空数组，你就重复执行以下步骤：</p>

<ul>
	<li>找到&nbsp;<code>nums</code>&nbsp;中的最小值，并删除它。</li>
	<li>找到&nbsp;<code>nums</code>&nbsp;中的最大值，并删除它。</li>
	<li>计算删除两数的平均值。</li>
</ul>

<p>两数 <code>a</code>&nbsp;和 <code>b</code>&nbsp;的 <strong>平均值</strong>&nbsp;为&nbsp;<code>(a + b) / 2</code>&nbsp;。</p>

<ul>
	<li>比方说，<code>2</code>&nbsp;和&nbsp;<code>3</code>&nbsp;的平均值是&nbsp;<code>(2 + 3) / 2 = 2.5</code>&nbsp;。</li>
</ul>

<p>返回上述过程能得到的 <strong>不同</strong>&nbsp;平均值的数目。</p>

<p><strong>注意</strong>&nbsp;，如果最小值或者最大值有重复元素，可以删除任意一个。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [4,1,4,0,3,5]
<b>输出：</b>2
<strong>解释：</strong>
1. 删除 0 和 5 ，平均值是 (0 + 5) / 2 = 2.5 ，现在 nums = [4,1,4,3] 。
2. 删除 1 和 4 ，平均值是 (1 + 4) / 2 = 2.5 ，现在 nums = [4,3] 。
3. 删除 3 和 4 ，平均值是 (3 + 4) / 2 = 3.5 。
2.5 ，2.5 和 3.5 之中总共有 2 个不同的数，我们返回 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1,100]
<b>输出：</b>1
<strong>解释：</strong>
删除 1 和 100 后只有一个平均值，所以我们返回 1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 100</code></li>
	<li><code>nums.length</code>&nbsp;是偶数。</li>
	<li><code>0 &lt;= nums[i] &lt;= 100</code></li>
</ul>


    
## 方法一：排序 + 双指针 + 哈希

首先对原始数组排序，接着使用双指针分别指向数组的头和尾。

使用一个哈希表存放最大数和最小数之和（因为问的是不同的平均数的**数量**，因此没必要除以2）

最终返回哈希表中原始的个数即可。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> se;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            se.insert(nums[l++] + nums[r--]);
        }
        return se.size();
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def distinctAverages(self, nums: List[int]) -> int:
        nums.sort()
        se = set()
        l, r = 0, len(nums) - 1
        while l < r:
            se.add(nums[l] + nums[r])
            l += 1
            r -= 1
        return len(se)
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/06/04/LeetCode%202465.%E4%B8%8D%E5%90%8C%E7%9A%84%E5%B9%B3%E5%9D%87%E5%80%BC%E6%95%B0%E7%9B%AE/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131038154](https://letmefly.blog.csdn.net/article/details/131038154)
