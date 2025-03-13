---
title: 189.轮转数组
date: 2022-08-12 10:53:30
tags: [题解, LeetCode, 中等, 数组, 数学, 双指针, 思维]
categories: [题解, LeetCode]
---

# 【LetMeFly】189.轮转数组：额外空间 / 原地反转

力扣题目链接：[https://leetcode.cn/problems/rotate-array/](https://leetcode.cn/problems/rotate-array/)

<p>给你一个数组，将数组中的元素向右轮转 <code>k</code><em>&nbsp;</em>个位置，其中&nbsp;<code>k</code><em>&nbsp;</em>是非负数。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,2,3,4,5,6,7], k = 3
<strong>输出:</strong> <code>[5,6,7,1,2,3,4]</code>
<strong>解释:</strong>
向右轮转 1 步: <code>[7,1,2,3,4,5,6]</code>
向右轮转 2 步: <code>[6,7,1,2,3,4,5]
</code>向右轮转 3 步: <code>[5,6,7,1,2,3,4]</code>
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入：</strong>nums = [-1,-100,3,99], k = 2
<strong>输出：</strong>[3,99,-1,-100]
<strong>解释:</strong> 
向右轮转 1 步: [99,-1,-100,3]
向右轮转 2 步: [3,99,-1,-100]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<ul>
	<li>尽可能想出更多的解决方案，至少有 <strong>三种</strong> 不同的方法可以解决这个问题。</li>
	<li>你可以使用空间复杂度为&nbsp;<code>O(1)</code> 的&nbsp;<strong>原地&nbsp;</strong>算法解决这个问题吗？</li>
</ul>

<ul>
</ul>

<ul>
</ul>


    
## 方法一：额外空间

如果不考虑空间消耗，那么这道题将会十分容易。

先将原始数组Copy一份到临时数组中，然后变换后的数组中的第$i$个元素就是原始数组中的第$(i - k) \% n$个元素（只取正值）

但是注意C++中负数对整数取模还是负数，因此$i - k$后需要加上“数个n”以使取模结果为正数。那么加上多少个$n$呢？可以加上$\lfloor \frac{k}{n} \rfloor + 1$个$n$（大于$k$）

+ 时间复杂度$O(n)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int add = k / n * n + n;  // >= k
        vector<int> original(nums);
        for (int i = 0; i < n; i++) {
            nums[i] = original[(i - k + add) % n];
        }
    }
};
```

## 方法二：数组翻转

“向右轮转k个位置”，也就是说将数组的后$k$个元素调到数组前

如```1, 2, 3, 4, 5, 6, 7```轮转3次就是将后三个元素```5, 6, 7```调到数组前：```5, 6, 7, 1, 2, 3, 4```

那么，直接将数组前后反转一次，原本的后$k$个元素不就变成前$k$个元素了吗？

```1, 2, 3, 4, 5, 6, 7 -> 7, 6, 5, 4, 3, 2, 1```

但是这样元素的前后位置颠倒了，前$3$个元素应是```5, 6, 7```而不是```7, 6, 5```，后$7 - 3$个元素应该是```1, 2, 3, 4```而不是```4, 3, 2, 1```

所以我们再分别对前后两部分做一次反转操作即可（```7, 6, 5 -> 5, 6, 7```、```4, 3, 2, 1 -> 1, 2, 3, 4```）

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

是不是很巧妙

### AC代码

#### C++

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/08/12/LeetCode%200189.%E8%BD%AE%E8%BD%AC%E6%95%B0%E7%BB%84/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126300212](https://letmefly.blog.csdn.net/article/details/126300212)
