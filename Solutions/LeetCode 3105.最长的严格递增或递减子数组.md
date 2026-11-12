---
title: 3105.最长的严格递增或递减子数组：一次遍历
date: 2026-11-12 13:16:34
tags: [题解, LeetCode, 简单, 数组]
categories: [题解, LeetCode]
---

# 【LetMeFly】3105.最长的严格递增或递减子数组：一次遍历

力扣题目链接：[https://leetcode.cn/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/](https://leetcode.cn/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/)

<p>给你一个整数数组 <code>nums</code> 。</p>

<p>返回数组 <code>nums</code> 中 <strong><span data-keyword="strictly-increasing-array">严格递增</span></strong> 或 <strong><span data-keyword="strictly-decreasing-array">严格递减</span> </strong>的最长非空子数组的长度。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [1,4,3,3,2]</span></p>

<p><strong>输出：</strong><span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p><code>nums</code> 中严格递增的子数组有<code>[1]</code>、<code>[2]</code>、<code>[3]</code>、<code>[3]</code>、<code>[4]</code> 以及 <code>[1,4]</code> 。</p>

<p><code>nums</code> 中严格递减的子数组有<code>[1]</code>、<code>[2]</code>、<code>[3]</code>、<code>[3]</code>、<code>[4]</code>、<code>[3,2]</code> 以及 <code>[4,3]</code> 。</p>

<p>因此，返回 <code>2</code> 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [3,3,3,3]</span></p>

<p><strong>输出：</strong><span class="example-io">1</span></p>

<p><strong>解释：</strong></p>

<p><code>nums</code> 中严格递增的子数组有 <code>[3]</code>、<code>[3]</code>、<code>[3]</code> 以及 <code>[3]</code> 。</p>

<p><code>nums</code> 中严格递减的子数组有 <code>[3]</code>、<code>[3]</code>、<code>[3]</code> 以及 <code>[3]</code> 。</p>

<p>因此，返回 <code>1</code> 。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [3,2,1]</span></p>

<p><strong>输出：</strong><span class="example-io">3</span></p>

<p><strong>解释：</strong></p>

<p><code>nums</code> 中严格递增的子数组有 <code>[3]</code>、<code>[2]</code> 以及 <code>[1]</code> 。</p>

<p><code>nums</code> 中严格递减的子数组有 <code>[3]</code>、<code>[2]</code>、<code>[1]</code>、<code>[3,2]</code>、<code>[2,1]</code> 以及 <code>[3,2,1]</code> 。</p>

<p>因此，返回 <code>3</code> 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 50</code></li>
</ul>


    
## 解题方法：一次遍历

一次遍历能否求出最长严格**递增**子数组？可以：

> 变量$cnt$记录当前连续递增长度，新遍历元素仍递增则长度加一，否则更新答案最大值并将长度置为1。

最长严格**递减**子数组同理，可以和最长**递增**子数组同时求解。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-11-12 13:15:11
 */
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 0;
        int cntAsc = 1, cntDesc = 1;
        size_t n = nums.size();
        for (size_t i = 1; i <= n; i++) {
            if (i == n || nums[i] <= nums[i - 1]) {
                ans = max(ans, cntAsc);
                cntAsc = 0;
            }
            cntAsc++;
            if (i == n || nums[i] >= nums[i - 1]) {
                ans = max(ans, cntDesc);
                cntDesc = 0;
            }
            cntDesc++;
        }
        return ans;
    }
};
```

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/170608523)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/11/12/LeetCode%203105.%E6%9C%80%E9%95%BF%E7%9A%84%E4%B8%A5%E6%A0%BC%E9%80%92%E5%A2%9E%E6%88%96%E9%80%92%E5%87%8F%E5%AD%90%E6%95%B0%E7%BB%84/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
