---
title: 209.长度最小的子数组
date: 2022-08-22 10:39:02
tags: [题解, LeetCode, 中等, 数组, 二分查找, 前缀和, 滑动窗口, 双指针, 子问题]
---

# 【LetMeFly】209.长度最小的子数组

力扣题目链接：[https://leetcode.cn/problems/minimum-size-subarray-sum/](https://leetcode.cn/problems/minimum-size-subarray-sum/)

<p>给定一个含有 <code>n</code><strong> </strong>个正整数的数组和一个正整数 <code>target</code><strong> 。</strong></p>

<p>找出该数组中满足其和<strong> </strong><code>≥ target</code><strong> </strong>的长度最小的 <strong>连续子数组</strong> <code>[nums<sub>l</sub>, nums<sub>l+1</sub>, ..., nums<sub>r-1</sub>, nums<sub>r</sub>]</code> ，并返回其长度<strong>。</strong>如果不存在符合条件的子数组，返回 <code>0</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>target = 7, nums = [2,3,1,2,4,3]
<strong>输出：</strong>2
<strong>解释：</strong>子数组 <code>[4,3]</code> 是该条件下的长度最小的子数组。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>target = 4, nums = [1,4,4]
<strong>输出：</strong>1
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>target = 11, nums = [1,1,1,1,1,1,1,1]
<strong>输出：</strong>0
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= target <= 10<sup>9</sup></code></li>
	<li><code>1 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>1 <= nums[i] <= 10<sup>5</sup></code></li>
</ul>

<p> </p>

<p><strong>进阶：</strong></p>

<ul>
	<li>如果你已经实现<em> </em><code>O(n)</code> 时间复杂度的解法, 请尝试设计一个 <code>O(n log(n))</code> 时间复杂度的解法。</li>
</ul>


    
## 方法一：滑动窗口

使用两个指针$l$和$r$，其中$l$指向“符合答案的子数组的第一个元素的前一个元素”，$r$指向“符合答案的子数组的最后一个元素”

初始时，没有任何一个元素处于“滑动窗口”中，因此$l$为$-1$，然后$r$从下标$0$开始遍历数组。

每次$r$遍历到一个新的元素，就把这个元素加到“窗口总和”中。

当左指针和右指针之间有间距时，不断尝试去掉左指针的下一个元素，如果去掉后窗口中元素总和小于$target$了，就取消这次“移除尝试”

这样，$r$每次遍历一个数组中的元素，就能得到以$r$结尾的满足$和\geq target$的最小窗口（或前$r$个元素的和仍不足$target$）

如果窗口中的元素的和不小于$target$，就更新答案最小值。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int l = -1;  // (l, r]
        int s = 0;
        for (int r = 0; r < nums.size(); r++) {
            s += nums[r];
            while (l + 1 < r && s - nums[l + 1] >= target) {
                s -= nums[l + 1];
                l++;
            }
            if (s >= target) {
                ans = min(ans, r - l);
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/08/22/LeetCode%200209.%E9%95%BF%E5%BA%A6%E6%9C%80%E5%B0%8F%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126461543](https://letmefly.blog.csdn.net/article/details/126461543)
