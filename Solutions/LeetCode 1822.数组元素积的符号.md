---
title: 1822.数组元素积的符号
date: 2022-10-27 08:15:30
tags: [题解, LeetCode, 简单, 数组, 数学]
---

# 【LetMeFly】1822.数组元素积的符号

力扣题目链接：[https://leetcode.cn/problems/sign-of-the-product-of-an-array/](https://leetcode.cn/problems/sign-of-the-product-of-an-array/)

<p>已知函数 <code>signFunc(x)</code> 将会根据 <code>x</code> 的正负返回特定值：</p>

<ul>
	<li>如果 <code>x</code> 是正数，返回 <code>1</code> 。</li>
	<li>如果 <code>x</code> 是负数，返回 <code>-1</code> 。</li>
	<li>如果 <code>x</code> 是等于 <code>0</code> ，返回 <code>0</code> 。</li>
</ul>

<p>给你一个整数数组 <code>nums</code> 。令 <code>product</code> 为数组 <code>nums</code> 中所有元素值的乘积。</p>

<p>返回 <code>signFunc(product)</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [-1,-2,-3,-4,3,2,1]
<strong>输出：</strong>1
<strong>解释：</strong>数组中所有值的乘积是 144 ，且 signFunc(144) = 1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,5,0,2,-3]
<strong>输出：</strong>0
<strong>解释：</strong>数组中所有值的乘积是 0 ，且 signFunc(0) = 0
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [-1,1,-1,1,-1]
<strong>输出：</strong>-1
<strong>解释：</strong>数组中所有值的乘积是 -1 ，且 signFunc(-1) = -1
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 1000</code></li>
	<li><code>-100 <= nums[i] <= 100</code></li>
</ul>


    
## 方法一：只看符号

结果只和符号有关，因此我们只关注结果的正负即可（特殊地，若有$0$出现，则直接返回$0$）

初始值符号为```正1```

每遇到一个负数，符号翻转（$\times -1$）

最终返回这个符号就是答案。

+ 时间复杂度$O(n)$，其中$n$是数组中元素的个数
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 1;
        for (int& num : nums) {
            if (num < 0)
                ans *= -1;
            else if (!num)
                return 0;
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/10/27/LeetCode%201822.%E6%95%B0%E7%BB%84%E5%85%83%E7%B4%A0%E7%A7%AF%E7%9A%84%E7%AC%A6%E5%8F%B7/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127544741](https://letmefly.blog.csdn.net/article/details/127544741)
