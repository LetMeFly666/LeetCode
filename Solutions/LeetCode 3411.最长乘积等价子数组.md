---
title: 3411.最长乘积等价子数组：二重循环“暴力”计算
date: 2026-11-24 18:29:08
tags: [题解, LeetCode, 简单, 数组, 数学, 枚举, 数论, 滑动窗口]
categories: [题解, LeetCode]
---

# 【LetMeFly】3411.最长乘积等价子数组：二重循环“暴力”计算

力扣题目链接：[https://leetcode.cn/problems/maximum-subarray-with-equal-products/](https://leetcode.cn/problems/maximum-subarray-with-equal-products/)

<p>给你一个由&nbsp;<strong>正整数&nbsp;</strong>组成的数组 <code>nums</code>。</p>

<p>如果一个数组 <code>arr</code> 满足 <code>prod(arr) == lcm(arr) * gcd(arr)</code>，则称其为&nbsp;<strong>乘积等价数组&nbsp;</strong>，其中：</p>

<ul>
	<li><code>prod(arr)</code> 表示 <code>arr</code> 中所有元素的乘积。</li>
	<li><code>gcd(arr)</code> 表示 <code>arr</code> 中所有元素的最大公因数 (<span data-keyword="gcd-function">GCD</span>)。</li>
	<li><code>lcm(arr)</code> 表示 <code>arr</code> 中所有元素的最小公倍数 (<span data-keyword="lcm-function">LCM</span>)。</li>
</ul>

<p>返回数组 <code>nums</code> 的&nbsp;<strong>最长</strong> <strong>乘积等价 <span data-keyword="subarray-nonempty">子数组</span>&nbsp;</strong>的长度。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [1,2,1,2,1,1,1]</span></p>

<p><strong>输出：</strong> <span class="example-io">5</span></p>

<p><strong>解释：</strong>&nbsp;</p>

<p>最长的乘积等价子数组是 <code>[1, 2, 1, 1, 1]</code>，其中&nbsp;<code>prod([1, 2, 1, 1, 1]) = 2</code>，&nbsp;<code>gcd([1, 2, 1, 1, 1]) = 1</code>，以及&nbsp;<code>lcm([1, 2, 1, 1, 1]) = 2</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [2,3,4,5,6]</span></p>

<p><strong>输出：</strong> <span class="example-io">3</span></p>

<p><strong>解释：</strong>&nbsp;</p>

<p>最长的乘积等价子数组是 <code>[3, 4, 5]</code>。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [1,2,3,1,4,5,1]</span></p>

<p><strong>输出：</strong> <span class="example-io">5</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10</code></li>
</ul>


    
## 解题方法：二重循环

直接枚举子数组的起点和终点，并且在枚举的过程中实时计算子数组的`prod`、`gcd`和`lcm`，如果$prod=gcd\times lcm$则更新答案最大值。

但是需要注意，所有数的乘积可能会很大。因此我们可以预先计算出一个乘积可能的上界$\max (nums[i]) \times \text{lcm}(nums)$，一旦子数组乘积大于这个值则立刻退出这层循环。

由于$1\leq nums[i] \leq 10$，因此上界不会很大。

+ 时间复杂度$O(len(nums)^2\log \max nums[i])$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-11-24 18:28:15
 */
class Solution {
public:
    int maxLength(vector<int>& nums) {
        size_t n = nums.size();
        int mx = nums[0], all_lcm = nums[0];
        for (size_t i = 1; i < n; i++) {
            mx = max(mx, nums[i]);
            all_lcm = lcm(all_lcm, nums[i]);
        }
        int up_to = mx * all_lcm;
        
        size_t ans = 1;
        for (size_t i = 0; i < n; i++) {
            int prod = nums[i], this_gcd = nums[i], this_lcm = nums[i];
            for (size_t j = i + 1; j < n; j++) {
                prod *= nums[j];
                if (prod > up_to) {
                    break;
                }
                this_gcd = gcd(this_gcd, nums[j]);
                this_lcm = lcm(this_lcm, nums[j]);
                if (prod == this_gcd * this_lcm) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return static_cast<int>(ans);
    }
};
```

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/171314515)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/11/24/LeetCode%203411.%E6%9C%80%E9%95%BF%E4%B9%98%E7%A7%AF%E7%AD%89%E4%BB%B7%E5%AD%90%E6%95%B0%E7%BB%84/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
