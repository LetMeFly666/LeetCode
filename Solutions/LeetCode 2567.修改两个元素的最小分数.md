---
title: 2567.修改两个元素的最小分数：三种情况（也可O(n)）
date: 2026-11-20 12:46:22
tags: [题解, LeetCode, 中等, 贪心, 数组, 排序, 分类讨论]
categories: [题解, LeetCode]
---

# 【LetMeFly】2567.修改两个元素的最小分数：三种情况（也可O(n)）

力扣题目链接：[https://leetcode.cn/problems/minimum-score-by-changing-two-elements/](https://leetcode.cn/problems/minimum-score-by-changing-two-elements/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<ul>
	<li><code>nums</code> 的 <strong>最小</strong>&nbsp;得分是满足 <code>0 &lt;= i &lt; j &lt; nums.length</code>&nbsp;的&nbsp;<code>|nums[i]&nbsp;- nums[j]|</code>&nbsp;的最小值。</li>
	<li><code>nums</code>的 <strong>最大 </strong>得分是满足 <code>0 &lt;= i &lt; j &lt; nums.length</code>&nbsp;的&nbsp;<code>|nums[i]&nbsp;- nums[j]|</code>&nbsp;的最大值。</li>
	<li><code>nums</code>&nbsp;的分数是 <strong>最大</strong>&nbsp;得分与 <strong>最小</strong>&nbsp;得分的和。</li>
</ul>

<p>我们的目标是最小化&nbsp;<code>nums</code>&nbsp;的分数。你 <strong>最多</strong> 可以修改&nbsp;<code>nums</code>&nbsp;中&nbsp;<strong>2</strong>&nbsp;个元素的值。</p>

<p>请你返回修改&nbsp;<code>nums</code>&nbsp;中&nbsp;<strong>至多两个</strong>&nbsp;元素的值后，可以得到的 <strong>最小分数</strong>&nbsp;。</p>

<p><code>|x|</code>&nbsp;表示 <code>x</code>&nbsp;的绝对值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,4,3]
<b>输出：</b>0
<b>解释：</b>将 nums[1] 和 nums[2] 的值改为 1 ，nums 变为 [1,1,1] 。<code>|nums[i] - nums[j]|</code> 的值永远为 0 ，所以我们返回 0 + 0 = 0 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,4,7,8,5]
<b>输出：</b>3
<b>解释：
</b>将 nums[0] 和 nums[1] 的值变为 6 ，nums 变为 [6,6,7,8,5] 。
最小得分是 i = 0 且 j = 1 时得到的 |<code>nums[i] - nums[j]</code>| = |6 - 6| = 0 。
最大得分是 i = 3 且 j = 4 时得到的 |<code>nums[i] - nums[j]</code>| = |8 - 5| = 3 。
最大得分与最小得分之和为 3 。这是最优答案。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：三种情况分类讨论

排序不影响结果，先对$nums$数组排个序。

之后就不难发现，其实我们关注的最多也就 最大值、第二大值、第三大值、最小值、第二小值、第三小值 这六个数。其他数在这些范围内改变没有意义，变动到这些范围之外只会让最**大**的绝对值之差更大。

关于最**小**的绝对值之差，都修改两个数了，直接让这两个数相等，或其中任意一个数和别的数相等，即可使得最小绝对值之差为$0$。

其实也就三种改法：

1. 修改最大的两个数：把这两个数变小，最大的数变成原本第三大的数，最小的数还是原本最小的数
2. 修改最小的两个数：把这两个数变大，最大的数还是原本最大的数，最小的数变成原本第三小的数
3. 修改最大和最小的两个数：最大数变小最小数变大，最大的数是原本第二大的数，最小的数是原本第二小的数

返回以上三种修改方法得到的*最大数和最小数之差*中最小的那个。

## 时空复杂度

+ 时间复杂度$O(n\log n)$
+ 空间复杂度$O(\log n)$

由于只需要确定最大值、第二大值、第三大值、最小值、第二小值、第三小值，所以其实也可以使用几个变量一次遍历得出，这样则有：

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

## AC代码

### C++

```cpp
/*
 * @LastEditTime: 2026-11-19 22:29:22
 */
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        ranges::sort(nums);
        int n = nums.size();
        return min(
            nums[n - 3] - nums[0], min(  // 改最大的两个
                nums[n - 1] - nums[2],     // 改最小的两个
                nums[n - 2] - nums[1]      // 改最小和最大的那两个
            )
        );
    }
};
```

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/171100682)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/11/19/LeetCode%202567.%E4%BF%AE%E6%94%B9%E4%B8%A4%E4%B8%AA%E5%85%83%E7%B4%A0%E7%9A%84%E6%9C%80%E5%B0%8F%E5%88%86%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
