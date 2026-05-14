---
title: 2784.检查数组是否是好的：排序 或 O(1)空间原地
date: 2026-05-14 05:57:28
tags: [题解, LeetCode, 简单, 数组, 哈希表, 排序, 原地, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】2784.检查数组是否是好的：排序 或 O(1)空间原地

力扣题目链接：[https://leetcode.cn/problems/check-if-array-is-good/](https://leetcode.cn/problems/check-if-array-is-good/)

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;，如果它是数组&nbsp;<code>base[n]</code>&nbsp;的一个排列，我们称它是个&nbsp;<strong>好</strong>&nbsp;数组。</p>

<p><code>base[n] = [1, 2, ..., n - 1, n, n]</code>&nbsp;（换句话说，它是一个长度为 <code>n + 1</code>&nbsp;且包含&nbsp;<code>1</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;恰好各一次，包含 <code>n</code>&nbsp; 两次的一个数组）。比方说，<code>base[1] = [1, 1]</code>&nbsp;，<code>base[3] = [1, 2, 3, 3]</code>&nbsp;。</p>

<p>如果数组是一个好数组，请你返回&nbsp;<code>true</code>&nbsp;，否则返回&nbsp;<code>false</code>&nbsp;。</p>

<p><strong>注意：</strong>数组的排列是这些数字按任意顺序排布后重新得到的数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [2, 1, 3]
<b>输出：</b>false
<b>解释：</b>因为数组的最大元素是 3 ，唯一可以构成这个数组的 base[n] 对应的 n = 3 。但是 base[3] 有 4 个元素，但数组 nums 只有 3 个元素，所以无法得到 base[3] = [1, 2, 3, 3] 的排列，所以答案为 false 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1, 3, 3, 2]
<b>输出：</b>true
<b>解释：因为</b>数组的最大元素是 3 ，唯一可以构成这个数组的 base[n] 对应的 n = 3 ，可以看出数组是 base[3] = [1, 2, 3, 3] 的一个排列（交换 nums 中第二个和第四个元素）。所以答案为 true 。</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = [1, 1]
<b>输出：</b>true
<b>解释：</b>因为数组的最大元素是 1 ，唯一可以构成这个数组的 base[n] 对应的 n = 1，可以看出数组是 base[1] = [1, 1] 的一个排列。所以答案为 true 。</pre>

<p><strong>示例 4：</strong></p>

<pre><b>输入：</b>nums = [3, 4, 4, 1, 2, 1]
<b>输出：</b>false
<b>解释：</b>因为数组的最大元素是 4 ，唯一可以构成这个数组的 base[n] 对应的 n = 4 。但是 base[n] 有 5 个元素而 nums 有 6 个元素。所以答案为 false 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= num[i] &lt;= 200</code></li>
</ul>


    
## 解题方法一：排序

将原始数组中的元素按从小到大的顺序排序，看前$n$个元素是否是$1$到$n$，并且看最后一个元素是否是$n$。

+ 时间复杂度$O(n\log n)$，其中$n=len(nums)$
+ 空间复杂度$O(\log n)$

```cpp
/*
 * @LastEditTime: 2026-05-14 05:40:27
 */
class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0, n = nums.size(); i < n - 1; i++) {
            if (nums[i] != i + 1) {
                return false;
            }
        }
        if (nums.back() != nums.size() - 1) {
            return false;
        }
        return true;
    }
};
```

## 解题方法二：原地修改

先去掉“$n$需要出现两次”这一特性，假如这道题是$1$到$n$分别各自出现一次，有没有办法使用原始数组统计每个数出现了几次？

有。假设$nums$数组中一个数为$t$，那么我们将$nums[t-1]$变成负数（取反），用来标记$t$这个值已经出现过；如果$nums[t-1]$已经为负数，说明$t$出现了两次。

否则，由于$n$个数会将$n$个数变成负数，且每个数变成负数之前都是正数，所以说明每个数都恰好出现了一次。

```cpp
/*
 * @LastEditTime: 2026-05-14 05:42:41
 */
// THIS CANNOT BE ACCEPTED
// THIS IS FOR n只出现1次的全排列
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        for (int t : nums) {
            t = t < 0 ? -t : t;
            if (t > n || t == 0) {
                return false;
            }
            if (nums[t - 1] < 0) {
                return false;
            }
            nums[t - 1] = -nums[t - 1];
        }
        return true;
    }
};
```

好，现在题目说是$1$到$n-1$都出现一次，唯独$n$出现了两次。怎么特殊处理？

使用一个变量记录$n$出现了几次就好了。

```cpp
/*
 * @LastEditTime: 2026-05-14 05:56:40
 */
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;  // 注意，n是数组长度-1
        int cntN = 0;
        for (int t : nums) {
            t = t < 0 ? -t : t;
            if (t > n || t == 0) {
                return false;
            }
            if (t == n) {
                cntN++;
                continue;
            }
            if (nums[t - 1] < 0) {
                return false;
            }
            nums[t - 1] = -nums[t - 1];
        }
        return cntN == 2;
    }
};
```

+ 时间复杂度$O(n)$，其中$n=len(nums)$
+ 空间复杂度$O(1)$

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/161081207)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/05/14/LeetCode%202784.%E6%A3%80%E6%9F%A5%E6%95%B0%E7%BB%84%E6%98%AF%E5%90%A6%E6%98%AF%E5%A5%BD%E7%9A%84/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
