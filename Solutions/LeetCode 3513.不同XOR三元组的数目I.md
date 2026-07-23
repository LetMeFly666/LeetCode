---
title: 3513.不同 XOR 三元组的数目 I： 1 << bit_width（数学）
date: 2026-07-23 16:02:15
tags: [题解, LeetCode, 中等, 位运算, 数组, 数学]
categories: [题解, LeetCode]
---

# 【LetMeFly】3513.不同 XOR 三元组的数目 I： 1 << bit_width（数学）

力扣题目链接：[https://leetcode.cn/problems/number-of-unique-xor-triplets-i/](https://leetcode.cn/problems/number-of-unique-xor-triplets-i/)

<p>给你一个长度为 <code>n</code> 的整数数组 <code>nums</code>，其中 <code>nums</code> 是范围 <code>[1, n]</code> 内所有数的&nbsp;<strong>排列&nbsp;</strong>。</p>

<p><strong>XOR 三元组</strong> 定义为三个元素的异或值 <code>nums[i] XOR nums[j] XOR nums[k]</code>，其中 <code>i &lt;= j &lt;= k</code>。</p>

<p>返回所有可能三元组 <code>(i, j, k)</code> 中&nbsp;<strong>不同&nbsp;</strong>的 XOR 值的数量。</p>

<p><strong>排列</strong> 是一个集合中所有元素的重新排列。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [1,2]</span></p>

<p><strong>输出：</strong> <span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p>所有可能的 XOR 三元组值为：</p>

<ul>
	<li><code>(0, 0, 0) → 1 XOR 1 XOR 1 = 1</code></li>
	<li><code>(0, 0, 1) → 1 XOR 1 XOR 2 = 2</code></li>
	<li><code>(0, 1, 1) → 1 XOR 2 XOR 2 = 1</code></li>
	<li><code>(1, 1, 1) → 2 XOR 2 XOR 2 = 2</code></li>
</ul>

<p>不同的 XOR 值为 <code>{1, 2}</code>，因此输出为 2。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [3,1,2]</span></p>

<p><strong>输出：</strong> <span class="example-io">4</span></p>

<p><strong>解释：</strong></p>

<p>可能的 XOR 三元组值包括：</p>

<ul>
	<li><code>(0, 0, 0) → 3 XOR 3 XOR 3 = 3</code></li>
	<li><code>(0, 0, 1) → 3 XOR 3 XOR 1 = 1</code></li>
	<li><code>(0, 0, 2) → 3 XOR 3 XOR 2 = 2</code></li>
	<li><code>(0, 1, 2) → 3 XOR 1 XOR 2 = 0</code></li>
</ul>

<p>不同的 XOR 值为 <code>{0, 1, 2, 3}</code>，因此输出为 4。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= n</code></li>
	<li><code>nums</code> 是从 <code>1</code> 到 <code>n</code> 的整数的一个排列。</li>
</ul>


    
## 解题方法：数学

先考虑$n$比较大的情况（$n\geq 3$）：

如果$n=2$，那么只有


+ 时间复杂度$O(N^2)$
+ 空间复杂度$O(N\log N)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-07-23 15:00:59
 */
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unsigned n = nums.size();
        if (n < 3) {
            return n;
        }
        
        return 1 << bit_width(n);
    }
};
```

#### C++

```cpp
/*
 * @LastEditTime: 2026-07-23 14:55:02
 */
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return n;
        }
        
        int cnt = 0;
        while (n) {
            n >>= 1;
            cnt++;
        }
        return 1 << cnt;
    }
};
```

#### C++

```cpp
/*
 * @LastEditTime: 2026-07-23 15:59:42
 */
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unsigned n = nums.size();
        return n < 3 ? n : 1 << bit_width(n);
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/--------------------------)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/07/23/LeetCode%203513.%E4%B8%8D%E5%90%8CXOR%E4%B8%89%E5%85%83%E7%BB%84%E7%9A%84%E6%95%B0%E7%9B%AEI/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
