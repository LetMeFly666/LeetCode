---
title: 3011.判断一个数组是否可以变为有序
date: 2024-07-13 00:33:50
tags: [题解, LeetCode, 中等, 位运算, 数组, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】3011.判断一个数组是否可以变为有序：分组循环

力扣题目链接：[https://leetcode.cn/problems/find-if-array-can-be-sorted/](https://leetcode.cn/problems/find-if-array-can-be-sorted/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始且全是 <strong>正</strong>&nbsp;整数的数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>一次 <b>操作</b>&nbsp;中，如果两个 <strong>相邻</strong>&nbsp;元素在二进制下数位为 <strong>1</strong>&nbsp;的数目 <strong>相同</strong>&nbsp;，那么你可以将这两个元素交换。你可以执行这个操作 <strong>任意次</strong>&nbsp;（<strong>也可以 0 次</strong>）。</p>

<p>如果你可以使数组变有序，请你返回&nbsp;<code>true</code> ，否则返回&nbsp;<code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [8,4,2,30,15]
<b>输出：</b>true
<b>解释：</b>我们先观察每个元素的二进制表示。 2 ，4 和 8 分别都只有一个数位为 1 ，分别为 "10" ，"100" 和 "1000" 。15 和 30 分别有 4 个数位为 1 ："1111" 和 "11110" 。
我们可以通过 4 个操作使数组有序：
- 交换 nums[0] 和 nums[1] 。8 和 4 分别只有 1 个数位为 1 。数组变为 [4,8,2,30,15] 。
- 交换 nums[1] 和 nums[2] 。8 和 2 分别只有 1 个数位为 1 。数组变为 [4,2,8,30,15] 。
- 交换 nums[0] 和 nums[1] 。4 和 2 分别只有 1 个数位为 1 。数组变为 [2,4,8,30,15] 。
- 交换 nums[3] 和 nums[4] 。30 和 15 分别有 4 个数位为 1 ，数组变为 [2,4,8,15,30] 。
数组变成有序的，所以我们返回 true 。
注意我们还可以通过其他的操作序列使数组变得有序。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,3,4,5]
<b>输出：</b>true
<b>解释：</b>数组已经是有序的，所以我们返回 true 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [3,16,8,4,2]
<b>输出：</b>false
<b>解释：</b>无法通过操作使数组变为有序。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 2<sup>8</sup></code></li>
</ul>


    
## 解题方法：分组

从前到后遍历数组，将二进制下1相同的数划分为一组。则有：

> + 同组直接元素可任意交换位置
> + 不同组元素不可交换位置

也就是说，我们不考虑同组直接的顺序是什么样子的，我们只考虑这一组中：

> 1. 最大元素是多少
> 2. 有没有元素小于上一组的最大元素（若小于则无法完成最终的排序）

一旦有不符合上述情况的直接返回false，否则返回true。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int lastMax = 0, last1 = 0, thisMax = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (__builtin_popcount(nums[i]) != last1) {
                lastMax = thisMax, last1 = __builtin_popcount(nums[i]);
                thisMax = nums[i];
            } else {
                thisMax = max(thisMax, nums[i]);
            }
            if (nums[i] < lastMax) {
                return false;
            }
        }
        return true;
    }
};
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/07/13/LeetCode%203011.%E5%88%A4%E6%96%AD%E4%B8%80%E4%B8%AA%E6%95%B0%E7%BB%84%E6%98%AF%E5%90%A6%E5%8F%AF%E4%BB%A5%E5%8F%98%E4%B8%BA%E6%9C%89%E5%BA%8F/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/140391465](https://letmefly.blog.csdn.net/article/details/140391465)
