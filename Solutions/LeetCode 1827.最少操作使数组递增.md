---
title: 1827.最少操作使数组递增
date: 2022-12-11 11:33:27
tags: [题解, LeetCode, 简单, 贪心, 数组, 遍历]
---

# 【LetMeFly】1827.最少操作使数组递增

力扣题目链接：[https://leetcode.cn/problems/minimum-operations-to-make-the-array-increasing/](https://leetcode.cn/problems/minimum-operations-to-make-the-array-increasing/)

<p>给你一个整数数组 <code>nums</code> （<strong>下标从 0 开始</strong>）。每一次操作中，你可以选择数组中一个元素，并将它增加 <code>1</code> 。</p>

<ul>
	<li>比方说，如果 <code>nums = [1,2,3]</code> ，你可以选择增加 <code>nums[1]</code> 得到 <code>nums = [1,<b>3</b>,3]</code> 。</li>
</ul>

<p>请你返回使 <code>nums</code> <strong>严格递增</strong> 的 <strong>最少</strong> 操作次数。</p>

<p>我们称数组 <code>nums</code> 是 <strong>严格递增的</strong> ，当它满足对于所有的 <code>0 &lt;= i &lt; nums.length - 1</code> 都有 <code>nums[i] &lt; nums[i+1]</code> 。一个长度为 <code>1</code> 的数组是严格递增的一种特殊情况。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [1,1,1]
<b>输出：</b>3
<b>解释：</b>你可以进行如下操作：
1) 增加 nums[2] ，数组变为 [1,1,<strong>2</strong>] 。
2) 增加 nums[1] ，数组变为 [1,<strong>2</strong>,2] 。
3) 增加 nums[2] ，数组变为 [1,2,<strong>3</strong>] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1,5,2,4,1]
<b>输出：</b>14
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = [8]
<b>输出：</b>0
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>


    
## 方法一：遍历

数字只增不减，还想要整个数组递增，那么肯定是从前往后处理一遍数组，如果这个数比前一个数小，那么就让这个数变大。

那么变成多大呢？

为了减少“增加操作”的次数，当然是变得越小越好。

因此，我们从前往后遍历数组，如果数组中某个元素的值**不大于**前一个元素，那么就将这个数通过“数次加一操作”变成$上一个元素+1$

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                ans += nums[i - 1] + 1 - nums[i];
                nums[i] = nums[i - 1] + 1;
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/12/11/LeetCode%201827.%E6%9C%80%E5%B0%91%E6%93%8D%E4%BD%9C%E4%BD%BF%E6%95%B0%E7%BB%84%E9%80%92%E5%A2%9E/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128273168](https://letmefly.blog.csdn.net/article/details/128273168)
