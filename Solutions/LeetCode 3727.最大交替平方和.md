---
title: 3727.最大交替平方和：排序 (双指针可选)
date: 2026-10-13 22:18:27
tags: [题解, LeetCode, 中等, 贪心, 数组, 排序, 双指针]
categories: [题解, LeetCode]
---

# 【LetMeFly】3727.最大交替平方和：排序 (双指针可选)

力扣题目链接：[https://leetcode.cn/problems/maximum-alternating-sum-of-squares/](https://leetcode.cn/problems/maximum-alternating-sum-of-squares/)

<p>给你一个整数数组 <code>nums</code>。你可以以任意顺序&nbsp;<strong>重新排列元素&nbsp;</strong>。</p>

<p>数组 <code>arr</code> 的&nbsp;<strong>交替得分&nbsp;</strong>定义为：</p>

<ul>
	<li><code>score = arr[0]<sup>2</sup> - arr[1]<sup>2</sup> + arr[2]<sup>2</sup> - arr[3]<sup>2</sup> + ...</code></li>
</ul>

<p>在对 <code>nums</code> 重新排列后，返回其&nbsp;<strong>最大可能的交替得分</strong>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [1,2,3]</span></p>

<p><strong>输出：</strong> <span class="example-io">12</span></p>

<p><strong>解释：</strong></p>

<p><code>nums</code> 的一种可行重排为 <code>[2,1,3]</code>，该排列在所有可能重排中给出了最大交替得分。</p>

<p>交替得分计算如下：</p>

<p><code>score = 2<sup>2</sup> - 1<sup>2</sup> + 3<sup>2</sup> = 4 - 1 + 9 = 12</code></p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [1,-1,2,-2,3,-3]</span></p>

<p><strong>输出：</strong> <span class="example-io">16</span></p>

<p><strong>解释：</strong></p>

<p><code>nums</code> 的一种可行重排为 <code>[-3,-1,-2,1,3,2]</code>，该排列在所有可能重排中给出了最大交替得分。</p>

<p>交替得分计算如下：</p>

<p><code>score = (-3)<sup>2</sup> - (-1)<sup>2</sup> + (-2)<sup>2</sup> - (1)<sup>2</sup> + (3)<sup>2</sup> - (2)<sup>2</sup> = 9 - 1 + 4 - 1 + 9 - 4 = 16</code></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-4 * 10<sup>4</sup> &lt;= nums[i] &lt;= 4 * 10<sup>4</sup></code></li>
</ul>


    
## 解题方法：排序

对数组以元素绝对值为依据排序，假设数组长度为$n$，加上$\lceil\frac{n}{2}\rceil$个最大元素的平方、减去$\lfloor\frac{n}{2}\rfloor$个最小元素的平方即为答案。

+ 时间复杂度$O(n\log n)$，时间复杂度主要来自排序
+ 空间复杂度$O(n)$，如果原地修改参数数组可以将空间复杂度降低到$O(\log n)$

### AC代码

#### C++ —— 直接加前$\lceil\frac{n}{2}\rceil$个 然后减后 $\lfloor\frac{n}{2}\rfloor$ 个

```cpp
/*
 * @LastEditTime: 2026-10-13 22:18:09
 */
typedef long long ll;
class Solution {
public:
    ll maxAlternatingSum(vector<int>& nums) {
        for (int& t : nums) {
            t = abs(t);
        }
        ranges::sort(nums, greater<int>());

        ll ans = 0;
        int half = (nums.size() + 1) / 2;
        for (int i = 0; i < half; i++) {
            ans = ans + nums[i] * nums[i];
        }
        for (int i = half; i < nums.size(); i++) {
            ans = ans - nums[i] * nums[i];
        }
        return ans;
    }
};
```

#### C++ —— 双指针，从两边开始一加一减

```cpp
/*
 * @LastEditTime: 2026-10-13 22:15:35
 */
typedef long long ll;
class Solution {
public:
    ll maxAlternatingSum(vector<int>& nums) {
        for (int& t : nums) {
            t = abs(t);
        }
        ranges::sort(nums);

        ll ans = 0;
        for (int l = 0, r = nums.size() - 1; l <= r; l++, r--) {
            ans += (ll) (nums[r] * nums[r]);
            if (l == r) {
                break;
            }
            ans -= (ll) (nums[l] * nums[l]);
        }
        return ans;
    }
};
```

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/167813613)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/10/13/LeetCode%203727.%E6%9C%80%E5%A4%A7%E4%BA%A4%E6%9B%BF%E5%B9%B3%E6%96%B9%E5%92%8C/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
