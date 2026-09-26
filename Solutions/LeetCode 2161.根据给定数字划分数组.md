---
title: 2161.根据给定数字划分数组：双指针（O(1)但非源地操作）
date: 2026-06-08 20:36:51
tags: [题解, LeetCode, 中等, 数组, 双指针, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】2161.根据给定数字划分数组：双指针（O(1)但非源地操作）

力扣题目链接：[https://leetcode.cn/problems/partition-array-according-to-given-pivot/](https://leetcode.cn/problems/partition-array-according-to-given-pivot/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>pivot</code>&nbsp;。请你将&nbsp;<code>nums</code>&nbsp;重新排列，使得以下条件均成立：</p>

<ul>
	<li>所有小于&nbsp;<code>pivot</code>&nbsp;的元素都出现在所有大于&nbsp;<code>pivot</code>&nbsp;的元素&nbsp;<strong>之前</strong>&nbsp;。</li>
	<li>所有等于&nbsp;<code>pivot</code>&nbsp;的元素都出现在小于和大于 <code>pivot</code>&nbsp;的元素 <strong>中间</strong>&nbsp;。</li>
	<li>小于 <code>pivot</code>&nbsp;的元素之间和大于 <code>pivot</code>&nbsp;的元素之间的 <strong>相对顺序</strong>&nbsp;不发生改变。
	<ul>
		<li>更正式的，考虑每一对&nbsp;<code>p<sub>i</sub></code>，<code>p<sub>j</sub></code>&nbsp;，<code>p<sub>i</sub></code>&nbsp;是初始时位置 <code>i</code>&nbsp;元素的新位置，<code>p<sub>j</sub></code>&nbsp;是初始时位置&nbsp;<code>j</code>&nbsp;元素的新位置。如果&nbsp;<code>i &lt; j</code> 且两个元素&nbsp;<strong>都</strong>&nbsp;小于（或大于）<code>pivot</code>，那么&nbsp;<code>p<sub>i</sub> &lt; p<sub>j</sub></code>&nbsp;。</li>
	</ul>
	</li>
</ul>

<p>请你返回重新排列 <code>nums</code>&nbsp;数组后的结果数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [9,12,5,10,14,3,10], pivot = 10
<b>输出：</b>[9,5,3,10,10,12,14]
<b>解释：</b>
元素 9 ，5 和 3 小于 pivot ，所以它们在数组的最左边。
元素 12 和 14 大于 pivot ，所以它们在数组的最右边。
小于 pivot 的元素的相对位置和大于 pivot 的元素的相对位置分别为 [9, 5, 3] 和 [12, 14] ，它们在结果数组中的相对顺序需要保留。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [-3,4,3,2], pivot = 2
<b>输出：</b>[-3,2,4,3]
<b>解释：</b>
元素 -3 小于 pivot ，所以在数组的最左边。
元素 4 和 3 大于 pivot ，所以它们在数组的最右边。
小于 pivot 的元素的相对位置和大于 pivot 的元素的相对位置分别为 [-3] 和 [4, 3] ，它们在结果数组中的相对顺序需要保留。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>6</sup> &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>pivot</code>&nbsp;等于&nbsp;<code>nums</code>&nbsp;中的一个元素。</li>
</ul>


    
## 解题方法：双指针

> 首先需要明确的是，这道题暂时没有找到合适的原地操作的方法。所谓空间复杂度$O(1)$，实则是因为力扣返回值不计入算法空间复杂度。

开辟一个和原始数组等长的答案数组，使用两个指针分别从左往右存放比$pivot$小的值和从右往左存放比$pivot$大的值。

最后记得把比$pivot$大的部分reverse一下（因为我们是优先把比$pivot$大的值放到最后面了所以需要翻转一下），中间没有填的位置默认赋值为$pivot$。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-06-08 20:34:51
 */
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n, pivot);
        int l = 0, r = n - 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                ans[l++] = nums[i];
            } else if (nums[i] > pivot) {
                ans[r--] = nums[i];
            }
        }
        reverse(ans.begin() + r + 1, ans.end());
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/161806767)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/06/08/LeetCode%202161.%E6%A0%B9%E6%8D%AE%E7%BB%99%E5%AE%9A%E6%95%B0%E5%AD%97%E5%88%92%E5%88%86%E6%95%B0%E7%BB%84/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
