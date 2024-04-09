---
title: 2529.正整数和负整数的最大计数
date: 2024-04-09 12:07:21
tags: [题解, LeetCode, 简单, 数组, 二分查找, 计数]
---

# 【LetMeFly】2529.正整数和负整数的最大计数：遍历计数 OR 二分查找

力扣题目链接：[https://leetcode.cn/problems/maximum-count-of-positive-integer-and-negative-integer/](https://leetcode.cn/problems/maximum-count-of-positive-integer-and-negative-integer/)

<p>给你一个按 <strong>非递减顺序</strong> 排列的数组 <code>nums</code> ，返回正整数数目和负整数数目中的最大值。</p>

<ul>
	<li>换句话讲，如果 <code>nums</code> 中正整数的数目是 <code>pos</code> ，而负整数的数目是 <code>neg</code> ，返回 <code>pos</code> 和 <code>neg</code>二者中的最大值。</li>
</ul>

<p><strong>注意：</strong><code>0</code> 既不是正整数也不是负整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [-2,-1,-1,1,2,3]
<strong>输出：</strong>3
<strong>解释：</strong>共有 3 个正整数和 3 个负整数。计数得到的最大值是 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [-3,-2,-1,0,0,1,2]
<strong>输出：</strong>3
<strong>解释：</strong>共有 2 个正整数和 3 个负整数。计数得到的最大值是 3 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,20,66,1314]
<strong>输出：</strong>4
<strong>解释：</strong>共有 4 个正整数和 0 个负整数。计数得到的最大值是 4 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2000</code></li>
	<li><code>-2000 &lt;= nums[i] &lt;= 2000</code></li>
	<li><code>nums</code> 按 <strong>非递减顺序</strong> 排列。</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你可以设计并实现时间复杂度为 <code>O(log(n))</code> 的算法解决此问题吗？</p>


    
## 方法一：遍历计数

使用两个变量分别统计正数和负数的个数，遍历一遍原始数组即可得到。最终返回这两个数的最大值即可。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int cntPos = 0, cntNeg = 0;
        for (int t : nums) {
            cntPos += t > 0;
            cntNeg += t < 0;
        }
        return max(cntPos, cntNeg);
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        return max(sum(1 if t > 0 else 0 for t in nums), sum(1 if t < 0 else 0 for t in nums))
```

## 方法二：二分查找

注意到题目中说“数组非递减”，那不是很明确地让我们使用二分查找吗。

二分查找找到第一个$\geq 0$的下标$i$，则负数个数为$i$个；

二分查找找到第一个$\gt 0$的下标$j$，则正数个数为$n - j$个。

+ 时间复杂度$O(\log len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int pos = nums.end() - upper_bound(nums.begin(), nums.end(), 0);
        return max(neg, pos);
    }
};
```

#### Python

```python
# from typing import List
# from bisect import bisect_left, bisect_right

class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        return max(bisect_left(nums, 0), len(nums) - bisect_right(nums, 0))
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/04/09/LeetCode%202529.%E6%AD%A3%E6%95%B4%E6%95%B0%E5%92%8C%E8%B4%9F%E6%95%B4%E6%95%B0%E7%9A%84%E6%9C%80%E5%A4%A7%E8%AE%A1%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/137554489](https://letmefly.blog.csdn.net/article/details/137554489)
