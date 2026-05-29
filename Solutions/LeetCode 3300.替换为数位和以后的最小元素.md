---
title: 3300.替换为数位和以后的最小元素：一次遍历
date: 2026-05-29 14:05:38
tags: [题解, LeetCode, 简单, 数组, 数学]
categories: [题解, LeetCode]
---

# 【LetMeFly】3300.替换为数位和以后的最小元素：一次遍历

力扣题目链接：[https://leetcode.cn/problems/minimum-element-after-replacement-with-digit-sum/](https://leetcode.cn/problems/minimum-element-after-replacement-with-digit-sum/)

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>请你将 <code>nums</code>&nbsp;中每一个元素都替换为它的各个数位之 <strong>和</strong>&nbsp;。</p>

<p>请你返回替换所有元素以后 <code>nums</code>&nbsp;中的 <strong>最小</strong>&nbsp;元素。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [10,12,13,14]</span></p>

<p><span class="example-io"><b>输出：</b>1</span></p>

<p><strong>解释：</strong></p>

<p><code>nums</code>&nbsp;替换后变为&nbsp;<code>[1, 3, 4, 5]</code>&nbsp;，最小元素为 1 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,3,4]</span></p>

<p><span class="example-io"><b>输出：</b>1</span></p>

<p><b>解释：</b></p>

<p><code>nums</code>&nbsp;替换后变为&nbsp;<code>[1, 2, 3, 4]</code>&nbsp;，最小元素为 1 。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [999,19,199]</span></p>

<p><span class="example-io"><b>输出：</b>10</span></p>

<p><strong>解释：</strong></p>

<p><code>nums</code>&nbsp;替换后变为&nbsp;<code>[27, 10, 19]</code>&nbsp;，最小元素为 10 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>


    
## 解题方法：遍历

不超过$10^4$的十进制数最大数位和是$9999$对应的$36$，初始值我们可以选择$36$，然后遍历数组中每一个元素并更新数位和的最小值。

怎么计算一个正整数的数位和呢？当这个数非零时，不断累加其个位$t\%10$，并将这个数除以$10$并向下取整。

+ 时间复杂度$O(len(nums)\times \log_{10}nums[i])$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-05-29 13:59:39
 */
class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = 36;
        for (int t : nums) {
            int s = 0;
            while (t) {
                s += t % 10;
                t /= 10;
            }
            ans = min(ans, s);
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/161516629)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/05/29/LeetCode%203300.%E6%9B%BF%E6%8D%A2%E4%B8%BA%E6%95%B0%E4%BD%8D%E5%92%8C%E4%BB%A5%E5%90%8E%E7%9A%84%E6%9C%80%E5%B0%8F%E5%85%83%E7%B4%A0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
