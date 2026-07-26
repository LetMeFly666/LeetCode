---
title: 628.三个数的最大乘积：三个最大 / 两个最小+一个最大（排序+数学/贪心）
date: 2026-07-26 22:00:18
tags: [题解, LeetCode, 简单, 数组, 数学, 排序, 贪心]
categories: [题解, LeetCode]
---

# 【LetMeFly】628.三个数的最大乘积：三个最大 / 两个最小+一个最大（排序+数学/贪心）

力扣题目链接：[https://leetcode.cn/problems/maximum-product-of-three-numbers/](https://leetcode.cn/problems/maximum-product-of-three-numbers/)

<p>给你一个整型数组 <code>nums</code> ，在数组中找出由三个数组成的最大乘积，并输出这个乘积。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3]
<strong>输出：</strong>6
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4]
<strong>输出：</strong>24
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [-1,-2,-3]
<strong>输出：</strong>-6
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 <= nums.length <= 10<sup>4</sup></code></li>
	<li><code>-1000 <= nums[i] <= 1000</code></li>
</ul>


    
## 思考方法：分类讨论

不是迫不得已不选奇数个负数。那么如果迫不得已呢？

+ 必须选三个负数的时候？说明只有三个负数，没得挑。
+ 必须选且只选一个负数的时候？说明只有一个负数和两个非负数，也只有三个数没得挑。

此外的情况我们肯定选偶数个负数：

+ 要么不选负数，此时我们选$nums$中三个最大的数
+ 要么选两个负数和一个非负数，此时我们选负数中绝对值最大的两个数（也就是$nums$中最小的两个数）和$nums$中最大的数

不论是迫不得已还是非迫不得已的情况，我们的最佳方案都包含在以下两种情况之内：

+ 选$nums$中三个最大的数
+ 选$nums$中两个最小的数和一个最大的数

给定数据满足最少有三个数，以上。

### 时空复杂度

时空复杂度主要来自排序。

+ 时间复杂度$O(n\log n)$
+ 空间复杂度$O(\log n)$

### AC代码

#### C++

注释不用看：

```cpp
/*
 * @LastEditTime: 2026-07-26 21:59:32
 */
/*
全正 / 1负 / 2负 / 全负

+ 全正: 最大3+
+ 1负： 最大1-、最小2+
+ 2负： 最小2-、最大1+
+ 全负: 最大3-

不对，没考虑还有0的情况

---

假设全是负数： 只能选三个最大的
没正数但有0：  选0

算了，这样想有点麻烦

---

选法：不是迫不得已不选三个负数 / 尽量不选0

假设正负数都很充足： 三个最大 / 两个最小负数+一最大正数
没有负数： 三个最大
必须选且只选一个负数：只有一个负数和另外两个数，就三个数没得选
有至少两个负数并且能选非负数：两个最小负数+一最大数
只能全选负数：三个最大负数

要么三个最大，要么两个最小+一最大
*/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        ranges::sort(nums);
        int n = nums.size();
        return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[0] * nums[1] * nums[n - 1]);
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/163221219)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/07/26/LeetCode%200628.%E4%B8%89%E4%B8%AA%E6%95%B0%E7%9A%84%E6%9C%80%E5%A4%A7%E4%B9%98%E7%A7%AF/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
