---
title: 561.数组拆分 I
date: 2023-03-15 10:44:59
tags: [题解, LeetCode, 简单, 贪心, 数组, 计数排序, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】561.数组拆分 I

力扣题目链接：[https://leetcode.cn/problems/array-partition-i/](https://leetcode.cn/problems/array-partition-i/)

<p>给定长度为 <code>2n</code><strong> </strong>的整数数组 <code>nums</code> ，你的任务是将这些数分成 <code>n</code><strong> </strong>对, 例如 <code>(a<sub>1</sub>, b<sub>1</sub>), (a<sub>2</sub>, b<sub>2</sub>), ..., (a<sub>n</sub>, b<sub>n</sub>)</code> ，使得从 <code>1</code> 到 <code>n</code> 的 <code>min(a<sub>i</sub>, b<sub>i</sub>)</code> 总和最大。</p>

<p>返回该 <strong>最大总和</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,4,3,2]
<strong>输出：</strong>4
<strong>解释：</strong>所有可能的分法（忽略元素顺序）为：
1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
所以最大总和为 4</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [6,2,6,5,1,2]
<strong>输出：</strong>9
<strong>解释：</strong>最优的分法为 (2, 1), (2, 5), (6, 6). min(2, 1) + min(2, 5) + min(6, 6) = 1 + 2 + 6 = 9
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 10<sup>4</sup></code></li>
	<li><code>nums.length == 2 * n</code></li>
	<li><code>-10<sup>4</sup> <= nums[i] <= 10<sup>4</sup></code></li>
</ul>


    
## 方法一：排序

我们先研究一个整数队$(a, b)$，假设里面较小的是$a$，那么无论$b$多大，累加到答案中的就只是$a$

因此，我们构造$(a, b)$时，使这两个元素之差尽可能地小，才能尽可能地“不浪费”较大的$b$

那么方法就出来了，直接对原始数组排个序，相邻元素两两成对即可。

+ 时间复杂度$O(len(nums)\times \log len(nums))$
+ 空间复杂度$O(\log len(nums))$

时空复杂度的来源主要是排序

### AC代码

#### C++

```cpp
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            ans += nums[i];
        }
        return ans;
    }
};
```

#### Python

```python
class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        ans = 0
        for i in range(0, len(nums), 2):
            ans += nums[i]
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/03/15/LeetCode%200561.%E6%95%B0%E7%BB%84%E6%8B%86%E5%88%86I/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129548105](https://letmefly.blog.csdn.net/article/details/129548105)
