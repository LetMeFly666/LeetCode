---
title: 2357.使数组中所有元素都等于零
date: 2023-02-24 08:51:23
tags: [题解, LeetCode, 简单, 数组, 模拟, 哈希表, 哈希, 排序, 模拟, 堆（优先队列）]
---

# 【LetMeFly】2357.使数组中所有元素都等于零

力扣题目链接：[https://leetcode.cn/problems/make-array-zero-by-subtracting-equal-amounts/](https://leetcode.cn/problems/make-array-zero-by-subtracting-equal-amounts/)

<p>给你一个非负整数数组 <code>nums</code> 。在一步操作中，你必须：</p>

<ul>
	<li>选出一个正整数 <code>x</code> ，<code>x</code> 需要小于或等于 <code>nums</code> 中 <strong>最小</strong> 的 <strong>非零</strong> 元素。</li>
	<li><code>nums</code> 中的每个正整数都减去 <code>x</code>。</li>
</ul>

<p>返回使 <code>nums</code> 中所有元素都等于<em> </em><code>0</code> 需要的 <strong>最少</strong> 操作数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,5,0,3,5]
<strong>输出：</strong>3
<strong>解释：</strong>
第一步操作：选出 x = 1 ，之后 nums = [0,4,0,2,4] 。
第二步操作：选出 x = 2 ，之后 nums = [0,2,0,0,2] 。
第三步操作：选出 x = 2 ，之后 nums = [0,0,0,0,0] 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0]
<strong>输出：</strong>0
<strong>解释：</strong>nums 中的每个元素都已经是 0 ，所以不需要执行任何操作。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 100</code></li>
</ul>


    
## 方法一：模拟

其实不难想象，每次选取一个“不超过数值中最小元素的正整数x”，然后数组中的每个正数都减去x，想要得到最小操作次数，那当然是每次的x越大越好。x最大为多大呢？最大为当前数组中的最小的正整数。

也就是说，最佳方案是：每次令x等于当前数组中最小的正整数，然后让每个正整数减去这个x，直到所有的数都变成0。

+ 时间复杂度$O(len(nums)^2)$
+ 空间复杂度$O(1)$

## 方法二：统计/哈希计数

方法一中我们直到了x选取的最佳方案，那么能否更快速地计算出需要操作多少次呢？

当然可以！每次操作我们减去了数组中最小的正整数，也就是说比“x”大的整数都会被剩下，从而需要再次“减x操作”；而所有值为x的整数在这次操作后都会变为0。

那么，我们统计一共有**多少种**正整数不就行了么？

每次操作消去当前最小的正整数，有多少种整数就好操作多少次。

因此，我们建立一个哈希表（或者使用数组也可以），遍历数组并统计出数组中一共有多少种正整数即为答案。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> se;
        for (int& t : nums) {
            if (t) {
                se.insert(t);
            }
        }
        return se.size();
    }
};
```

#### Python

```python
class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        se = set()
        for t in nums:
            if t:
                se.add(t)
        return len(se)
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/02/24/LeetCode%202357.%E4%BD%BF%E6%95%B0%E7%BB%84%E4%B8%AD%E6%89%80%E6%9C%89%E5%85%83%E7%B4%A0%E9%83%BD%E7%AD%89%E4%BA%8E%E9%9B%B6/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129193781](https://letmefly.blog.csdn.net/article/details/129193781)
