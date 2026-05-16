---
title: 153.寻找旋转排序数组中的最小值：二分查找(左闭右开写法)
date: 2026-05-15 22:02:06
tags: [题解, LeetCode, 中等, 数组, 二分查找, 二分]
categories: [题解, LeetCode]
---

# 【LetMeFly】153.寻找旋转排序数组中的最小值：二分查找(左闭右开写法)

力扣题目链接：[https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/](https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/)

已知一个长度为 <code>n</code> 的数组，预先按照升序排列，经由 <code>1</code> 到 <code>n</code> 次 <strong>旋转</strong> 后，得到输入数组。例如，原数组 <code>nums = [0,1,2,4,5,6,7]</code> 在变化后可能得到：
<ul>
	<li>若旋转 <code>4</code> 次，则可以得到 <code>[4,5,6,7,0,1,2]</code></li>
	<li>若旋转 <code>7</code> 次，则可以得到 <code>[0,1,2,4,5,6,7]</code></li>
</ul>

<p>注意，数组 <code>[a[0], a[1], a[2], ..., a[n-1]]</code> <strong>旋转一次</strong> 的结果为数组 <code>[a[n-1], a[0], a[1], a[2], ..., a[n-2]]</code> 。</p>

<p>给你一个元素值 <strong>互不相同</strong> 的数组 <code>nums</code> ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 <strong>最小元素</strong> 。</p>

<p>你必须设计一个时间复杂度为&nbsp;<code>O(log n)</code> 的算法解决此问题。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,4,5,1,2]
<strong>输出：</strong>1
<strong>解释：</strong>原数组为 [1,2,3,4,5] ，旋转 3 次得到输入数组。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,5,6,7,0,1,2]
<strong>输出：</strong>0
<strong>解释：</strong>原数组为 [0,1,2,4,5,6,7] ，旋转 4 次得到输入数组。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [11,13,15,17]
<strong>输出：</strong>11
<strong>解释：</strong>原数组为 [11,13,15,17] ，旋转 4 次得到输入数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 5000</code></li>
	<li><code>-5000 &lt;= nums[i] &lt;= 5000</code></li>
	<li><code>nums</code> 中的所有整数 <strong>互不相同</strong></li>
	<li><code>nums</code> 原来是一个升序排序的数组，并进行了 <code>1</code> 至 <code>n</code> 次旋转</li>
</ul>


    
## 解题方法：二分查找

有序+要求`log n`，很容易想到二分。

二分$mid$和谁比？如果和左右两个元素比，当$mid-1$、$mid$、$mid+1$递增时候，不好判断最小值在左边还是在右边。

其实也可以让$nums[mid]$和$nums[-1]$比。如果$nums[mid]\gt nums[-1]$，说明最小值在$mid$右边(一旦出现“下降折点”,后边所有元素将永远小于左边)；否则(说明从$mid$到最后都处于递增状态)，说明最小值在$mid$及其右边。

```
       *
     *  |
   *    |
  *     |
*       |
        |   * 一旦遇到“轮转分割线”，右侧所有值都将小于左侧
        | *
        *
```

这很适合二分。直接二分查找**第一个小于等于nums[-1]的元素**就好了。

+ 时间复杂度$O(\log n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-05-15 22:01:34
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size();  // 左闭右开
        while (l < r) {
            int m = (l + r) >> 1;
            if (nums[m] > nums.back()) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return nums[l];
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/161146404)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/05/15/LeetCode%200153.%E5%AF%BB%E6%89%BE%E6%97%8B%E8%BD%AC%E6%8E%92%E5%BA%8F%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E6%9C%80%E5%B0%8F%E5%80%BC/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
