---
title: 154.寻找旋转排序数组中的最小值 II：比I多个if(二分查找?)
date: 2026-05-16 20:46:47
tags: [题解, LeetCode, 困难, 数组, 二分查找]
categories: [题解, LeetCode]
---

# 【LetMeFly】154.寻找旋转排序数组中的最小值 II：比I多个if(二分查找?)

力扣题目链接：[https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array-ii/](https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array-ii/)

已知一个长度为 <code>n</code> 的数组，预先按照升序排列，经由 <code>1</code> 到 <code>n</code> 次 <strong>旋转</strong> 后，得到输入数组。例如，原数组 <code>nums = [0,1,4,4,5,6,7]</code> 在变化后可能得到：
<ul>
	<li>若旋转 <code>4</code> 次，则可以得到 <code>[4,5,6,7,0,1,4]</code></li>
	<li>若旋转 <code>7</code> 次，则可以得到 <code>[0,1,4,4,5,6,7]</code></li>
</ul>

<p>注意，数组 <code>[a[0], a[1], a[2], ..., a[n-1]]</code> <strong>旋转一次</strong> 的结果为数组 <code>[a[n-1], a[0], a[1], a[2], ..., a[n-2]]</code> 。</p>

<p>给你一个可能存在 <strong>重复</strong> 元素值的数组 <code>nums</code> ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 <strong>最小元素</strong> 。</p>

<p>你必须尽可能减少整个过程的操作步骤。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,3,5]
<strong>输出：</strong>1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,2,2,0,1]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 5000</code></li>
	<li><code>-5000 &lt;= nums[i] &lt;= 5000</code></li>
	<li><code>nums</code> 原来是一个升序排序的数组，并进行了 <code>1</code> 至 <code>n</code> 次旋转</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>这道题与 <a href="https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/description/">寻找旋转排序数组中的最小值</a> 类似，但 <code>nums</code> 可能包含重复元素。允许重复会影响算法的时间复杂度吗？会如何影响，为什么？</p>


    
## 解题方法：二分查找?

在[153.寻找旋转排序数组中的最小值：二分查找(左闭右开写法)](https://blog.letmefly.xyz/2026/05/15/LeetCode%200153.%E5%AF%BB%E6%89%BE%E6%97%8B%E8%BD%AC%E6%8E%92%E5%BA%8F%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E6%9C%80%E5%B0%8F%E5%80%BC/)中，我们使用二分查找解决了nums中元素不重复前提下的最小值查找问题。

在本题，nums中可能会出现重复元素，也就是当$nums[m]==nums.back()$的时候我们不知道最小值在左边还是在右边。那么不妨当这个时候，我们删掉最后一个元素（反正最后一个元素一定不是唯一最小值），变成在前面$n-1$个元素中继续求解的问题好了。

+ 时间复杂度$O(n)$。虽然看似在二分查找，但极端情况所有元素均相等，似乎没有算法可以躲过$O(n)$的命运
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-05-16 20:44:41
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;  // 左右闭区间吧还是
        while (l < r) {
            int m = (l + r) >> 1;
            if (nums[m] == nums[r]) {
                r--;
            } else if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return nums[l];
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/161146809)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/05/16/LeetCode%200154.%E5%AF%BB%E6%89%BE%E6%97%8B%E8%BD%AC%E6%8E%92%E5%BA%8F%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E6%9C%80%E5%B0%8F%E5%80%BCII/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
