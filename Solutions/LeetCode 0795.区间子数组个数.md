---
title: 795.区间子数组个数
date: 2022-11-24 16:42:55
tags: [题解, LeetCode, 中等, 数组, 双指针]
---

# 【LetMeFly】795.区间子数组个数

力扣题目链接：[https://leetcode.cn/problems/number-of-subarrays-with-bounded-maximum/](https://leetcode.cn/problems/number-of-subarrays-with-bounded-maximum/)

<p>给你一个整数数组 <code>nums</code> 和两个整数：<code>left</code> 及 <code>right</code> 。找出 <code>nums</code> 中连续、非空且其中最大元素在范围&nbsp;<code>[left, right]</code> 内的子数组，并返回满足条件的子数组的个数。</p>

<p>生成的测试用例保证结果符合 <strong>32-bit</strong> 整数范围。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,1,4,3], left = 2, right = 3
<strong>输出：</strong>3
<strong>解释：</strong>满足条件的三个子数组：[2], [2, 1], [3]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,9,2,5,6], left = 2, right = 8
<strong>输出：</strong>7
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= left &lt;= right &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 方法一：统计

题目中要找的是“最大元素在[left, right]范围内的子数组”

已知$right \geq left$，因此“最大元素在[left, right]范围内的子数组”的数量，等于“最大元素不超过right的子数组数量” - “最大元素不超过left - 1的子数组数量”

因此，我们只需要实现一个函数，这个函数能够计算出“数组a中最大元素不超过b的子数组的数量”

怎么实现呢？

我们用一个变量来记录“上一个大于b的元素的位置”，当再次遇到“大于b的元素”时，二者之间的数组的所有非空子数组都是要找的数组。

假设两个“大于b的元素”之间有$k$个元素，那么这$k$个元素组成的非空子数组的个数就是$k \times (k + 1) / 2$

问题解决。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
private:
    int noMoreThan(vector<int>& a, int b) {  // a中的 “所有元素都不大于b 的子数组的个数”
        int ans = 0;
        int lastLoc = -1;
        int n = a.size();
        for (int i = 0; i <= n; i++) {
            if (i == n || a[i] > b) {
                ans += (long long)(i - lastLoc - 1) * (i - lastLoc) / 2;
                lastLoc = i;
            }
        }
        return ans;
    }
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return noMoreThan(nums, right) - noMoreThan(nums, left - 1);
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/11/24/LeetCode%200795.%E5%8C%BA%E9%97%B4%E5%AD%90%E6%95%B0%E7%BB%84%E4%B8%AA%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128021990](https://letmefly.blog.csdn.net/article/details/128021990)
