---
title: 152.乘积最大子数组
date: 2022-08-01 08:53:42
tags: [题解, LeetCode, 中等, 数组, 动态规划, dp, 原地滚动, 最x子xx, 子问题]
---

# 【LetMeFly】152.乘积最大子数组：dp + 原地滚动

力扣题目链接：[https://leetcode.cn/problems/maximum-product-subarray/](https://leetcode.cn/problems/maximum-product-subarray/)

<p>给你一个整数数组 <code>nums</code>&nbsp;，请你找出数组中乘积最大的非空连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。</p>

<p>测试用例的答案是一个&nbsp;<strong>32-位</strong> 整数。</p>

<p><strong>子数组</strong> 是数组的连续子序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [2,3,-2,4]
<strong>输出:</strong> <code>6</code>
<strong>解释:</strong>&nbsp;子数组 [2,3] 有最大乘积 6。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = [-2,0,-1]
<strong>输出:</strong> 0
<strong>解释:</strong>&nbsp;结果不能为 2, 因为 [-2,-1] 不是子数组。</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>-10 &lt;= nums[i] &lt;= 10</code></li>
	<li><code>nums</code> 的任何前缀或后缀的乘积都 <strong>保证</strong>&nbsp;是一个 <strong>32-位</strong> 整数</li>
</ul>


    
## 方法一：dp + 原地滚动

需要两个变量$m$和$M$，分别表示以当前处理到的数字为结尾的```乘积最大子数组```

初始值$m$和$M$都是数组中第一个元素```nums[0]```

$i$从下标```1```开始遍历数组，既然要以下标$i$为连续数组的结尾，那么就有三种选择：

1. 只选择当前这个下标为$i$的元素（$nums[i]$）
2. 使用以上一个元素结尾的子数组的最大乘积 乘上 这个元素（$nums[i] * M$）
2. 使用以上一个元素结尾的子数组的最小乘积 乘上 这个元素（$nums[i] * m$）

每遍历到每一个元素时，计算上述三个新的可能的极值，并更新$m$和$M$，同时记录一下整个遍历过程中答案的最大值即可。

**Q&S:** 为什么还要记录最小值$m$而不是仅仅记录最大值$M$？

> 因为最大值可能由两个负数相乘得到。如果是两个负数相乘的话，负数越小乘积越大。

+ 时间复杂度$O(n)$，其中$n$是数组```nums```中元素的个数
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int m = nums[0], M = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int timesLastm = m * nums[i];
            int timesLastM = M * nums[i];
            m = min(nums[i], min(timesLastm, timesLastM));
            M = max(nums[i], max(timesLastm, timesLastM));
            ans = max(ans, M);
        }
        return ans;
    }
};
```

![运行结果还可以](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/c4685fff14d54e5c9b7d6652eae1b6e9.jpeg#pic_center)

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/08/01/LeetCode%200152.%E4%B9%98%E7%A7%AF%E6%9C%80%E5%A4%A7%E5%AD%90%E6%95%B0%E7%BB%84/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126094071](https://letmefly.blog.csdn.net/article/details/126094071)
