---
title: 3550.数位和等于下标的最小下标：遍历模拟
date: 2026-09-24 08:03:28
tags: [题解, LeetCode, 简单, 数组, 数学, 模拟, 遍历]
categories: [题解, LeetCode]
---

# 【LetMeFly】3550.数位和等于下标的最小下标：遍历模拟

力扣题目链接：[https://leetcode.cn/problems/smallest-index-with-digit-sum-equal-to-index/](https://leetcode.cn/problems/smallest-index-with-digit-sum-equal-to-index/)

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>返回满足 <code>nums[i]</code>&nbsp;的数位和（每一位数字相加求和）等于 <code>i</code>&nbsp;的 <strong>最小</strong>&nbsp;下标&nbsp;<code>i</code> 。</p>

<p>如果不存在满足要求的下标，返回&nbsp;<code>-1</code> 。</p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,3,2]</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><b>解释：</b></p>

<ul>
	<li><code>nums[2] = 2</code>，其数位和等于&nbsp;2 ，与其下标&nbsp;<code>i = 2</code>&nbsp;相等。因此，输出为&nbsp;2 。</li>
</ul>
</div>

<p><b>示例 2：</b></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,10,11]</span></p>

<p><span class="example-io"><b>输出：</b>1</span></p>

<p><b>解释：</b></p>

<ul>
	<li><code>nums[1] = 10</code>，其数位和等于&nbsp;<code>1 + 0 = 1</code>，与其下标 <code>i = 1</code>&nbsp;相等。</li>
	<li><code>nums[2] = 11</code>，其数位和等于是 <code>1 + 1 = 2</code>，与其下标&nbsp;<code>i = 2</code>&nbsp;相等。</li>
	<li>由于下标 1 是满足要求的最小下标，输出为&nbsp;1 。</li>
</ul>
</div>

<p><b>示例 3：</b></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,3]</span></p>

<p><span class="example-io"><b>输出：</b>-1</span></p>

<p><b>解释：</b></p>

<ul>
	<li>由于不存在满足要求的下标，输出为&nbsp;-1 。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
</ul>


    
## 解题方法：遍历

对于一个非负数字$t$，如何求出其十进制下的数位和？

> 当$t$非零时，累加$t$的个位数字$t\mod 10$，并令$t=\lfloor\frac{t}{10}\rfloor$。

所以我们遍历一遍数组，对每个数求出十进制下数位和，遇到第一个数位和等于下标的元素就返回其下标就好了。

+ 时间复杂度$O(len(nums)\times \log nums[i])$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-09-24 08:01:23
 */
class Solution {
private:
    int cnt(int t) {
        int ans = 0;
        while (t) {
            ans += t % 10;
            t /= 10;
        }
        return ans;
    }
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0, n = nums.size(); i < n; i++) {
            if (cnt(nums[i]) == i) {
                return i;
            }
        }
        return -1;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/166556022)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/09/24/LeetCode%203550.%E6%95%B0%E4%BD%8D%E5%92%8C%E7%AD%89%E4%BA%8E%E4%B8%8B%E6%A0%87%E7%9A%84%E6%9C%80%E5%B0%8F%E4%B8%8B%E6%A0%87/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
