---
title: 1785.构成特定和需要添加的最少元素
date: 2022-12-16 19:13:43
tags: [题解, LeetCode, 中等, 贪心, 数组]
---

# 【LetMeFly】1785.构成特定和需要添加的最少元素

力扣题目链接：[https://leetcode.cn/problems/minimum-elements-to-add-to-form-a-given-sum/](https://leetcode.cn/problems/minimum-elements-to-add-to-form-a-given-sum/)

<p>给你一个整数数组 <code>nums</code> ，和两个整数 <code>limit</code> 与 <code>goal</code> 。数组 <code>nums</code> 有一条重要属性：<code>abs(nums[i]) <= limit</code> 。</p>

<p>返回使数组元素总和等于 <code>goal</code> 所需要向数组中添加的 <strong>最少元素数量</strong> ，添加元素 <strong>不应改变</strong> 数组中 <code>abs(nums[i]) <= limit</code> 这一属性。</p>

<p>注意，如果 <code>x >= 0</code> ，那么 <code>abs(x)</code> 等于 <code>x</code> ；否则，等于 <code>-x</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,-1,1], limit = 3, goal = -4
<strong>输出：</strong>2
<strong>解释：</strong>可以将 -2 和 -3 添加到数组中，数组的元素总和变为 1 - 1 + 1 - 2 - 3 = -4 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,-10,9,1], limit = 100, goal = 0
<strong>输出：</strong>1
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>1 <= limit <= 10<sup>6</sup></code></li>
	<li><code>-limit <= nums[i] <= limit</code></li>
	<li><code>-10<sup>9</sup> <= goal <= 10<sup>9</sup></code></li>
</ul>


    
## 方法一：计算

我们可以很容易地求出，数组中当前元素的和 与 目标值goal 的差值。

方法很简单：直接使用目标值减去数组中的每一个元素即可。

这里**需要注意的是**，数组中每个元素的范围是$10^5$级别，数组中元素的个数是$10^6$级别，数组中元素之和可能会超出$32$位整数，因此C++中我们需要把$goal$转为$long long$类型

计算出了上述二者的差值，每次往数组中添加的元素的绝对值又必须不超过$limit$，因此我们尽可能地多添加值为$limit$的元素，最终差值用一个元素补上即可。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minElements(vector<int>& nums, int limit, long long goal) {  // 偷懒小技巧：直接把这里改成long long
        for (int t : nums)
            goal -= t;
        goal = abs(goal);
        return goal / limit + (goal % limit != 0);
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/12/16/LeetCode%201785.%E6%9E%84%E6%88%90%E7%89%B9%E5%AE%9A%E5%92%8C%E9%9C%80%E8%A6%81%E6%B7%BB%E5%8A%A0%E7%9A%84%E6%9C%80%E5%B0%91%E5%85%83%E7%B4%A0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128346870](https://letmefly.blog.csdn.net/article/details/128346870)
