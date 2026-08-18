---
title: 3471.找出最大的几近缺失整数：三种情况判断
date: 2026-08-18 16:48:27
tags: [题解, LeetCode, 简单, 数组, 脑筋急转弯, 分类讨论]
categories: [题解, LeetCode]
---

# 【LetMeFly】3471.找出最大的几近缺失整数：三种情况判断

力扣题目链接：[https://leetcode.cn/problems/find-the-largest-almost-missing-integer/](https://leetcode.cn/problems/find-the-largest-almost-missing-integer/)

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>k</code> 。</p>

<p>如果整数 <code>x</code>&nbsp;恰好仅出现在&nbsp;<code>nums</code>&nbsp;中的一个大小为 <code>k</code>&nbsp;的子数组中，则认为&nbsp;<code>x</code>&nbsp;是 <code>nums</code>&nbsp;中的几近缺失（<strong>almost missing</strong>）整数。</p>

<p>返回 <code>nums</code> 中 <strong>最大的几近缺失</strong> 整数，如果不存在这样的整数，返回&nbsp;<code>-1</code>&nbsp;。</p>
<strong>子数组</strong> 是数组中的一个连续元素序列。

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [3,9,2,1,7], k = 3</span></p>

<p><span class="example-io"><b>输出：</b>7</span></p>

<p><b>解释：</b></p>

<ul>
	<li>1 出现在两个大小为 3 的子数组中：<code>[9, 2, 1]</code>、<code>[2, 1, 7]</code></li>
	<li>2 出现在三个大小为&nbsp;3 的子数组中：<code>[3, 9, 2]</code>、<code>[9, 2, 1]</code>、<code>[2, 1, 7]</code></li>
	<li index="2">3 出现在一个大小为 3 的子数组中：<code>[3, 9, 2]</code></li>
	<li index="3">7 出现在一个大小为 3 的子数组中：<code>[2, 1, 7]</code></li>
	<li index="4">9 出现在两个大小为 3 的子数组中：<code>[3, 9, 2]</code>、<code>[9, 2, 1]</code></li>
</ul>

<p>返回 7 ，因为它满足题意的所有整数中最大的那个。</p>
</div>

<p><b>示例 2：</b></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [3,9,7,2,1,7], k = 4</span></p>

<p><span class="example-io"><b>输出：</b>3</span></p>

<p><b>解释：</b></p>

<ul>
	<li>1 出现在两个大小为 4 的子数组中：<code>[9, 7, 2, 1]</code>、<code>[7, 2, 1, 7]</code></li>
	<li>2 出现在三个大小为 4 的子数组中：<code>[3, 9, 7, 2]</code>、<code>[9, 7, 2, 1]</code>、<code>[7, 2, 1, 7]</code></li>
	<li>3 出现在一个大小为 4 的子数组中：<code>[3, 9, 7, 2]</code></li>
	<li>7 出现在三个大小为 4 的子数组中：<code>[3, 9, 7, 2]</code>、<code>[9, 7, 2, 1]</code>、<code>[7, 2, 1, 7]</code></li>
	<li>9 出现在两个大小为 4 的子数组中：<code>[3, 9, 7, 2]</code>、<code>[9, 7, 2, 1]</code></li>
</ul>

<p>返回 3&nbsp;，因为它满足题意的所有整数中最大的那个。</p>
</div>

<p><b>示例 3：</b></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [0,0], k = 1</span></p>

<p><span class="example-io"><b>输出：</b>-1</span></p>

<p><b>解释：</b></p>

<p>不存在满足题意的整数。</p>
</div>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 50</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 50</code></li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>
</ul>


    
## 解题方法：三种情况分类讨论

+ 如果$n=k$，则真个数组只有一个子数组，返回数组最大值
+ 如果$k=1$，则每个元素都是一个子数组，返回数组中出现次数为1的最大值
+ **否则** $1\lt k\lt n$，则除了第一个数和最后一个数外，每个数都至少被包含到两个子数组中，必定不可能是*最大的几近缺失整数*。所以我们只需看首尾两数中有没有只出现一次的数，若有则返回大的那个

时空复杂度：

+ 时间复杂度$O(n^2)$，其中$n=len(nums)$
+ 空间复杂度$O(\log n)$，最大数据量是$50$不使用哈希表也很快

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-08-18 16:46:31
 */
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == k) {
            return *max_element(nums.begin(), nums.end());
        }

        if (k == 1) {
            ranges::sort(nums);
            for (int i = n - 1; i >= 0; i--) {
                if (i - 1 >= 0 && nums[i - 1] == nums[i]) {
                    continue;
                }
                if (i + 1 < n && nums[i + 1] == nums[i]) {
                    continue;
                }
                return nums[i];
            }
            return -1;
        }
        
        int first = nums[0], last = nums.back();
        if (first == last) {
            return -1;
        }
        bool another1 = false, another2 = false;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] == first) {
                another1 = true;
            }
            if (nums[i] == last) {
                another2 = true;
            }
        }
        if (another1 && another2) {
            return -1;
        }
        if (!another1 && !another2) {
            return max(first, last);
        }
        return another1 ? last : first;
    }
};
```

+ 执行用时分布 0 ms 击败 100.00%
+ 消耗内存分布 28.13 MB 击败 92.86%

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/163860139)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/08/18/LeetCode%203471.%E6%89%BE%E5%87%BA%E6%9C%80%E5%A4%A7%E7%9A%84%E5%87%A0%E8%BF%91%E7%BC%BA%E5%A4%B1%E6%95%B4%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
