---
title: 918.环形子数组的最大和：动态规划 + 思维（反转）
date: 2023-07-20 08:30:02
tags: [题解, LeetCode, 中等, 队列, 数组, 分治, 动态规划, DP, 思维, 单调队列]
---

# 【LetMeFly】918.环形子数组的最大和：动态规划 + 思维（反转）

力扣题目链接：[https://leetcode.cn/problems/maximum-sum-circular-subarray/](https://leetcode.cn/problems/maximum-sum-circular-subarray/)

<p>给定一个长度为 <code>n</code> 的<strong>环形整数数组</strong>&nbsp;<code>nums</code>&nbsp;，返回<em>&nbsp;<code>nums</code>&nbsp;的非空 <strong>子数组</strong> 的最大可能和&nbsp;</em>。</p>

<p><strong>环形数组</strong><em>&nbsp;</em>意味着数组的末端将会与开头相连呈环状。形式上， <code>nums[i]</code> 的下一个元素是 <code>nums[(i + 1) % n]</code> ， <code>nums[i]</code>&nbsp;的前一个元素是 <code>nums[(i - 1 + n) % n]</code> 。</p>

<p><strong>子数组</strong> 最多只能包含固定缓冲区&nbsp;<code>nums</code>&nbsp;中的每个元素一次。形式上，对于子数组&nbsp;<code>nums[i], nums[i + 1], ..., nums[j]</code>&nbsp;，不存在&nbsp;<code>i &lt;= k1, k2 &lt;= j</code>&nbsp;其中&nbsp;<code>k1 % n == k2 % n</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,-2,3,-2]
<strong>输出：</strong>3
<strong>解释：</strong>从子数组 [3] 得到最大和 3
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,-3,5]
<strong>输出：</strong>10
<strong>解释：</strong>从子数组 [5,5] 得到最大和 5 + 5 = 10
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,-2,2,-3]
<strong>输出：</strong>3
<strong>解释：</strong>从子数组 [3] 和 [3,-2,2] 都可以得到最大和 3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>-3 * 10<sup>4</sup>&nbsp;&lt;= nums[i] &lt;= 3 * 10<sup>4</sup></code>​​​​​​​</li>
</ul>


    
## 方法一：动态规划 + 思维（反转）

**首先讨论如何求普通数组最大子数组**

很简单，使用$i$遍历数组，使用一个变量$nowM$用来记录```以nums[i]结尾的最大子数组之和```，使用另外一个变量$M$来记录整个过程中的最优解。

```cpp
int nowM = nums[0], M = nums[0];
for (int i = 0; i < n; i++) {
    nowM = max(nowM + nums[i], nums[i]);  // 以nums[i]结尾有两种选择：连上之前的数组 或 从nums[i]单独开始
	M = max(M, nowM)
}
```

**接着讨论如何从普通数组到循环数组**

其实我们换个思路，若是使用了循环数组的特性（$数组后几个元素 + 数组前几个元素$），不就等价于$总数组 - 中间几个元素$吗？

因此我们只需要和“计算最大子数组”的方式相同，计算出“最小子数组”，再使用数组总和减去最小子数组，就得到“跨两端的子数组”的最大和了。

**细节注意**

注意子数组必须非空，因此如果数组中所有元素都小于0的话（M < 0），不能返回0（一个元素都不选）

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int nowM = nums[0], M = nums[0];
        int nowm = nums[0], m = nums[0];
        int s = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            nowM = max(nowM + nums[i], nums[i]);
            M = max(M, nowM);
            nowm = min(nowm + nums[i], nums[i]);
            m = min(m, nowm);
            s += nums[i];
        }
        return M < 0 ? M : max(M, s - m);
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        nowM, M = nums[0], nums[0]
        nowm, m = nums[0], nums[0]
        s = nums[0]
        for i in range(1, len(nums)):
            nowM = max(nowM + nums[i], nums[i])
            M = max(M, nowM)
            nowm = min(nowm + nums[i], nums[i])
            m = min(m, nowm)
            s += nums[i]
        return M if M < 0 else max(M, s - m)
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/07/20/LeetCode%200918.%E7%8E%AF%E5%BD%A2%E5%AD%90%E6%95%B0%E7%BB%84%E7%9A%84%E6%9C%80%E5%A4%A7%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131821911](https://letmefly.blog.csdn.net/article/details/131821911)
