---
title: 1749.任意子数组和的绝对值的最大值
date: 2023-08-08 08:00:50
tags: [题解, LeetCode, 中等, 数组, 动态规划, DP]
---

# 【LetMeFly】1749.任意子数组和的绝对值的最大值

力扣题目链接：[https://leetcode.cn/problems/maximum-absolute-sum-of-any-subarray/](https://leetcode.cn/problems/maximum-absolute-sum-of-any-subarray/)

<p>给你一个整数数组 <code>nums</code> 。一个子数组 <code>[nums<sub>l</sub>, nums<sub>l+1</sub>, ..., nums<sub>r-1</sub>, nums<sub>r</sub>]</code> 的 <strong>和的绝对值</strong> 为 <code>abs(nums<sub>l</sub> + nums<sub>l+1</sub> + ... + nums<sub>r-1</sub> + nums<sub>r</sub>)</code> 。</p>

<p>请你找出 <code>nums</code> 中 <strong>和的绝对值</strong> 最大的任意子数组（<b>可能为空</b>），并返回该 <strong>最大值</strong> 。</p>

<p><code>abs(x)</code> 定义如下：</p>

<ul>
	<li>如果 <code>x</code> 是负整数，那么 <code>abs(x) = -x</code> 。</li>
	<li>如果 <code>x</code> 是非负整数，那么 <code>abs(x) = x</code> 。</li>
</ul>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,-3,2,3,-4]
<b>输出：</b>5
<b>解释：</b>子数组 [2,3] 和的绝对值最大，为 abs(2+3) = abs(5) = 5 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [2,-5,1,-4,3,-2]
<b>输出：</b>8
<b>解释：</b>子数组 [-5,1,-4] 和的绝对值最大，为 abs(-5+1-4) = abs(-8) = 8 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> <= nums[i] <= 10<sup>4</sup></code></li>
</ul>


    
## 方法一：动态规划

**首先想数组的最大子数组怎么求**

遍历数组，使用一个变量$M$记录以当前元素结尾时的最大子数组。

$M = max(nums[i], M + nums[i])$

可以只选择当前元素，也可以和前面的元素连起来。

**接着想子数组的最大和绝对值怎么求**

$$\max(abs(subarray)) = max(max(subarray), -min(subarray))$$

最大的和的绝对值 要么等于 最大和 要么等于 最小和的相反数。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans = abs(nums[0]), m = nums[0], M = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            M = max(nums[i], M + nums[i]);
            m = min(nums[i], m + nums[i]);
            ans = max(ans, max(M, -m));
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        ans, m, M = abs(nums[0]), nums[0], nums[0]
        for i in range(1, len(nums)):
            M = max(nums[i], M + nums[i])
            m = min(nums[i], m + nums[i])
            ans = max(ans, M, -m)
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/08/08/LeetCode%201749.%E4%BB%BB%E6%84%8F%E5%AD%90%E6%95%B0%E7%BB%84%E5%92%8C%E7%9A%84%E7%BB%9D%E5%AF%B9%E5%80%BC%E7%9A%84%E6%9C%80%E5%A4%A7%E5%80%BC/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/132158662](https://letmefly.blog.csdn.net/article/details/132158662)
