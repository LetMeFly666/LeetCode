---
title: 2540.最小公共值：双指针（O(m+n)）
date: 2026-05-19 18:00:57
tags: [题解, LeetCode, 简单, 数组, 哈希表, 双指针, 二分查找]
categories: [题解, LeetCode]
---

# 【LetMeFly】2540.最小公共值：双指针（O(m+n)）

力扣题目链接：[https://leetcode.cn/problems/minimum-common-value/](https://leetcode.cn/problems/minimum-common-value/)

<p>给你两个整数数组&nbsp;<code>nums1</code> 和&nbsp;<code>nums2</code>&nbsp;，它们已经按非降序排序，请你返回两个数组的 <strong>最小公共整数</strong>&nbsp;。如果两个数组&nbsp;<code>nums1</code> 和&nbsp;<code>nums2</code>&nbsp;没有公共整数，请你返回&nbsp;<code>-1</code>&nbsp;。</p>

<p>如果一个整数在两个数组中都 <strong>至少出现一次</strong>&nbsp;，那么这个整数是数组&nbsp;<code>nums1</code> 和&nbsp;<code>nums2</code>&nbsp;<strong>公共</strong>&nbsp;的。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums1 = [1,2,3], nums2 = [2,4]
<b>输出：</b>2
<b>解释：</b>两个数组的最小公共元素是 2 ，所以我们返回 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums1 = [1,2,3,6], nums2 = [2,3,4,5]
<b>输出：</b>2
<b>解释：</b>两个数组中的公共元素是 2 和 3 ，2 是较小值，所以返回 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums1[i], nums2[j] &lt;= 10<sup>9</sup></code></li>
	<li><code>nums1</code> 和&nbsp;<code>nums2</code>&nbsp;都是 <strong>非降序</strong>&nbsp;的。</li>
</ul>


    
## 解题方法：双指针

两个指针分别指向两个数组，若所指两元素相等则直接返回，否则哪个元素小就把哪个指针右移。

+ 时间复杂度$O(len(nums1)+len(nums2))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-05-19 18:00:07
 */
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0, j = 0; i < nums1.size() && j < nums2.size();) {
            if (nums1[i] == nums2[j]) {
                return nums1[i];
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return -1;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/161230404)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/05/19/LeetCode%202540.%E6%9C%80%E5%B0%8F%E5%85%AC%E5%85%B1%E5%80%BC/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
