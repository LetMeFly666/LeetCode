---
title: 2333.最小差值平方和：排序 + 数学计算（不用二分）
date: 2026-10-12 19:32:56
tags: [题解, LeetCode, 中等, 贪心, 数组, 排序, 数学]
categories: [题解, LeetCode]
---

# 【LetMeFly】2333.最小差值平方和：排序 + 数学计算（不用二分）

力扣题目链接：[https://leetcode.cn/problems/minimum-sum-of-squared-difference/](https://leetcode.cn/problems/minimum-sum-of-squared-difference/)

<p>给你两个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums1</code> 和&nbsp;<code>nums2</code>&nbsp;，长度为&nbsp;<code>n</code>&nbsp;。</p>

<p>数组&nbsp;<code>nums1</code> 和&nbsp;<code>nums2</code>&nbsp;的 <strong>差值平方和</strong>&nbsp;定义为所有满足&nbsp;<code>0 &lt;= i &lt; n</code>&nbsp;的&nbsp;<code>(nums1[i] - nums2[i])<sup>2</sup></code>&nbsp;之和。</p>

<p>同时给你两个正整数&nbsp;<code>k1</code> 和&nbsp;<code>k2</code>&nbsp;。你可以将&nbsp;<code>nums1</code>&nbsp;中的任意元素&nbsp;<code>+1</code> 或者&nbsp;<code>-1</code>&nbsp;至多&nbsp;<code>k1</code>&nbsp;次。类似的，你可以将&nbsp;<code>nums2</code>&nbsp;中的任意元素&nbsp;<code>+1</code> 或者&nbsp;<code>-1</code>&nbsp;至多&nbsp;<code>k2</code>&nbsp;次。</p>

<p>请你返回修改数组<em>&nbsp;</em><code>nums1</code><em>&nbsp;</em>至多<em>&nbsp;</em><code>k1</code>&nbsp;次且修改数组<em>&nbsp;</em><code>nums2</code>&nbsp;至多 <code>k2</code><em>&nbsp;</em>次后的最小&nbsp;<strong>差值平方和</strong>&nbsp;。</p>

<p><strong>注意：</strong>你可以将数组中的元素变成&nbsp;<strong>负</strong>&nbsp;整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums1 = [1,2,3,4], nums2 = [2,10,20,19], k1 = 0, k2 = 0
<b>输出：</b>579
<b>解释：</b>nums1 和 nums2 中的元素不能修改，因为 k1 = 0 和 k2 = 0 。
差值平方和为：(1 - 2)<sup>2 </sup>+ (2 - 10)<sup>2 </sup>+ (3 - 20)<sup>2 </sup>+ (4 - 19)<sup>2</sup>&nbsp;= 579 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums1 = [1,4,10,12], nums2 = [5,8,6,9], k1 = 1, k2 = 1
<b>输出：</b>43
<b>解释：</b>一种得到最小差值平方和的方式为：
- 将 nums1[0] 增加一次。
- 将 nums2[2] 增加一次。
最小差值平方和为：
(2 - 5)<sup>2 </sup>+ (4 - 8)<sup>2 </sup>+ (10 - 7)<sup>2 </sup>+ (12 - 9)<sup>2</sup>&nbsp;= 43 。
注意，也有其他方式可以得到最小差值平方和，但没有得到比 43 更小答案的方案。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums1.length == nums2.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= k1, k2 &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：排序 + 数学计算

已知两个前提：

1. 假设有多个正整数只能选

+ 时间复杂度$O(N^2)$
+ 空间复杂度$O(N\log N)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-10-12 19:25:34
 */
typedef long long ll;
class Solution {
public:
    ll minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> diffs(nums1.size() + 1);  // 末尾多一个哨兵
        for (int i = 0; i < n; i++) {
            diffs[i] = abs(nums1[i] - nums2[i]);
        }
        ranges::sort(diffs, greater<int>());

        int k = k1 + k2;
        for (int i = 0; i < n; i++) {
            ll per_diff = diffs[i] - diffs[i + 1];
            ll all_need = per_diff * (i + 1);
            if (k >= all_need) {
                k -= all_need;
                continue;
            }
            /*
                不够全部减小到目标值了，看看能减小到多少。
                假设k = 3, i = 1, all_need = 5
                k // 2 = 1，2个数每个减少1
                k % 2 = 1，其中1个数再减少一
            */
            ll all_sub = k / (i + 1);
            ll more_sub_1 = k % (i + 1);
            ll not_more_sub_1 = i + 1 - more_sub_1;
            diffs[i] -= all_sub;
            ll ans = not_more_sub_1 * diffs[i] * diffs[i];
            ans += more_sub_1 * (diffs[i] - 1) * (diffs[i] - 1);
            for (i++; i < n; i++) {
                ans += (ll) diffs[i] * diffs[i];
            }
            return ans;
        }
        return 0;
    }
};
```

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/--------------------------)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/10/12/LeetCode%202333.%E6%9C%80%E5%B0%8F%E5%B7%AE%E5%80%BC%E5%B9%B3%E6%96%B9%E5%92%8C/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
