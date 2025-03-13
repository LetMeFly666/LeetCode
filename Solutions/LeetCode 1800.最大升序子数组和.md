---
title: 1800.最大升序子数组和
date: 2022-10-07 13:47:34
tags: [题解, LeetCode, 简单, 数组, 子问题]
categories: [题解, LeetCode]
---

# 【LetMeFly】1800.最大升序子数组和

力扣题目链接：[https://leetcode.cn/problems/maximum-ascending-subarray-sum/](https://leetcode.cn/problems/maximum-ascending-subarray-sum/)

<p>给你一个正整数组成的数组 <code>nums</code> ，返回 <code>nums</code> 中一个 <strong>升序 </strong>子数组的最大可能元素和。</p>

<p>子数组是数组中的一个连续数字序列。</p>

<p>已知子数组 <code>[nums<sub>l</sub>, nums<sub>l+1</sub>, ..., nums<sub>r-1</sub>, nums<sub>r</sub>]</code> ，若对所有 <code>i</code>（<code>l <= i < r</code>），<code>nums<sub>i </sub> < nums<sub>i+1</sub></code> 都成立，则称这一子数组为 <strong>升序</strong> 子数组。注意，大小为 <code>1</code> 的子数组也视作 <strong>升序</strong> 子数组。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [10,20,30,5,10,50]
<strong>输出：</strong>65
<strong>解释：</strong>[5,10,50] 是元素和最大的升序子数组，最大元素和为 65 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [10,20,30,40,50]
<strong>输出：</strong>150
<strong>解释：</strong>[10,20,30,40,50] 是元素和最大的升序子数组，最大元素和为 150 。 
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [12,17,15,13,10,11,12]
<strong>输出：</strong>33
<strong>解释：</strong>[10,11,12] 是元素和最大的升序子数组，最大元素和为 33 。 
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>nums = [100,10,1]
<strong>输出：</strong>100
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 100</code></li>
	<li><code>1 <= nums[i] <= 100</code></li>
</ul>


    
## 方法一：模拟

用一个变量```nowCnt```来记录当前“递增子数组的和”

用一个变量```ans```来记录当前答案最优解

初始值```ans = 0```，而```nowCnt = arr[0]```

之后从第二个元素开始遍历数组，如果这个元素没有上一个元素大，那么就说明上一个元素是某个“递增子数组”的最后一个元素，就更新答案最大值，并且将```nowCnt```置为0

最后，遍历完数组之后，再次更新答案最大值即可。

+ 时间复杂度$O(n)$，其中$n$是数组大小
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0;
        int nowCnt = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                ans = max(ans, nowCnt);
                nowCnt = 0;
            }
            nowCnt += nums[i];
        }
        ans = max(ans, nowCnt);
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/10/07/LeetCode%201800.%E6%9C%80%E5%A4%A7%E5%8D%87%E5%BA%8F%E5%AD%90%E6%95%B0%E7%BB%84%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127193583](https://letmefly.blog.csdn.net/article/details/127193583)
