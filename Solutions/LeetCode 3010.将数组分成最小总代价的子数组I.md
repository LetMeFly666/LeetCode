---
title: 3010.将数组分成最小总代价的子数组 I：排序 OR 维护最小次小
date: 2026-02-01 10:08:40
tags: [题解, LeetCode, 简单, 数组, 枚举, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】3010.将数组分成最小总代价的子数组 I：排序 OR 维护最小次小

力扣题目链接：[https://leetcode.cn/problems/divide-an-array-into-subarrays-with-minimum-cost-i/](https://leetcode.cn/problems/divide-an-array-into-subarrays-with-minimum-cost-i/)

<p>给你一个长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>一个数组的 <strong>代价</strong>&nbsp;是它的 <strong>第一个</strong>&nbsp;元素。比方说，<code>[1,2,3]</code>&nbsp;的代价是&nbsp;<code>1</code>&nbsp;，<code>[3,4,1]</code>&nbsp;的代价是&nbsp;<code>3</code>&nbsp;。</p>

<p>你需要将&nbsp;<code>nums</code>&nbsp;分成&nbsp;<code>3</code>&nbsp;个&nbsp;<strong>连续且没有交集</strong>&nbsp;的子数组。</p>

<p>请你返回这些<span data-keyword="subarray">子数组</span>的 <strong>最小</strong>&nbsp;代价&nbsp;<b>总和</b>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,3,12]
<b>输出：</b>6
<b>解释：</b>最佳分割成 3 个子数组的方案是：[1] ，[2] 和 [3,12] ，总代价为 1 + 2 + 3 = 6 。
其他得到 3 个子数组的方案是：
- [1] ，[2,3] 和 [12] ，总代价是 1 + 2 + 12 = 15 。
- [1,2] ，[3] 和 [12] ，总代价是 1 + 3 + 12 = 16 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [5,4,3]
<b>输出：</b>12
<b>解释：</b>最佳分割成 3 个子数组的方案是：[5] ，[4] 和 [3] ，总代价为 5 + 4 + 3 = 12 。
12 是所有分割方案里的最小总代价。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [10,3,1,1]
<b>输出：</b>12
<b>解释：</b>最佳分割成 3 个子数组的方案是：[10,3] ，[1] 和 [1] ，总代价为 10 + 1 + 1 = 12 。
12 是所有分割方案里的最小总代价。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= n &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 50</code></li>
</ul>


    
## 解题方法：排序 OR 维护最小次小

不难发现，$nums[0]$必被第一个子数组选中，后续数组中可以分别将最小值和次小值作为后面两个数组的起始元素。

### 排序法

对$nums$除第一个元素外的其他部分排序，返回数组前三个元素就好了。

### 维护最小次小

两个变量$min1$和$min2$分别维护除第一个元素外其他部分的最小值和次小值，遍历过程中：

+ 若元素小于等于最小值则令次小值等于最小值，最小值等于该元素
+ 否则，若元素小于次小值，则令次小值等于该元素

### 时空复杂度分析

+ 时间复杂度：排序$O(n\log n)$、最小次小$O(n)$
+ 空间复杂度：排序$O(\log n)$、最小次小$O(1)$

### AC代码

#### C++ - 排序

```cpp
/*
 * @LastEditTime: 2026-02-01 09:51:34
 */
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        sort(nums.begin() + 1, nums.end());
        return nums[0] + nums[1] + nums[2];
    }
};
```

#### C++ - 最小次小

```cpp
/*
 * @LastEditTime: 2026-02-01 09:56:48
 */
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int min1 = 100, min2 = 100;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= min1) {
                min2 = min1;
                min1 = nums[i];
            } else if (nums[i] < min2) {
                min2 = nums[i];
            }
        }
        return nums[0] + min1 + min2;
    }
};
```

#### Python - 排序一行版

```python
'''
LastEditTime: 2026-02-01 10:06:51
'''
from typing import List

class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        return nums[0] + sum(sorted(nums[1:])[:2])
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/157612251)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/02/01/LeetCode%203010.%E5%B0%86%E6%95%B0%E7%BB%84%E5%88%86%E6%88%90%E6%9C%80%E5%B0%8F%E6%80%BB%E4%BB%A3%E4%BB%B7%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84I/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
