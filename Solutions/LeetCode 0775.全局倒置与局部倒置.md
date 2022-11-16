---
title: 775.全局倒置与局部倒置
date: 2022-11-16 08:16:54
tags: [题解, LeetCode, 中等, 数组, 数学]
---

# 【LetMeFly】775.全局倒置与局部倒置

力扣题目链接：[https://leetcode.cn/problems/global-and-local-inversions/](https://leetcode.cn/problems/global-and-local-inversions/)

<p>给你一个长度为 <code>n</code> 的整数数组 <code>nums</code> ，表示由范围 <code>[0, n - 1]</code> 内所有整数组成的一个排列。</p>

<p><strong>全局倒置</strong> 的数目等于满足下述条件不同下标对 <code>(i, j)</code> 的数目：</p>

<ul>
	<li><code>0 <= i < j < n</code></li>
	<li><code>nums[i] > nums[j]</code></li>
</ul>

<p><strong>局部倒置</strong> 的数目等于满足下述条件的下标 <code>i</code> 的数目：</p>

<ul>
	<li><code>0 <= i < n - 1</code></li>
	<li><code>nums[i] > nums[i + 1]</code></li>
</ul>

<p>当数组 <code>nums</code> 中 <strong>全局倒置</strong> 的数量等于 <strong>局部倒置</strong> 的数量时，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,0,2]
<strong>输出：</strong>true
<strong>解释：</strong>有 1 个全局倒置，和 1 个局部倒置。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,0]
<strong>输出：</strong>false
<strong>解释：</strong>有 2 个全局倒置，和 1 个局部倒置。
</pre>
 

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 <= n <= 5000</code></li>
	<li><code>0 <= nums[i] < n</code></li>
	<li><code>nums</code> 中的所有整数 <strong>互不相同</strong></li>
	<li><code>nums</code> 是范围 <code>[0, n - 1]</code> 内所有数字组成的一个排列</li>
</ul>


    
## 方法一：一个变量记录上上一个元素及之前的最大值

“局部倒置”的数量 是 “前一个元素大于后一个元素的**相邻元素对**” 的数量

“全局倒置”的数量 是 “前面元素大于后面元素的**元素对**” 的数量

要想让“局部倒置”数量 等于 “全局倒置”数量，就不能存在“前面元素大于后面元素 且 这两个元素不相邻”的情况（~反之亦然~）

因此，我们只需要看“是否有上上一个元素及其之前的元素 大于 当前元素”即可

遍历数组，用一个变量$M$记录“上上一个元素及其之前的元素”的最大值，若$M$大于当前元素，则返回$false$

+ 时间复杂度$O(n)$，其中$n$是数组中元素个数
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int M = nums[0];
        int n = nums.size();
        for (int i = 2; i < n; i++) {
            if (M > nums[i])
                return false;
            M = max(M, nums[i - 1]);
        }
        return true;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/11/16/LeetCode%200775.%E5%85%A8%E5%B1%80%E5%80%92%E7%BD%AE%E4%B8%8E%E5%B1%80%E9%83%A8%E5%80%92%E7%BD%AE/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127877435](https://letmefly.blog.csdn.net/article/details/127877435)
