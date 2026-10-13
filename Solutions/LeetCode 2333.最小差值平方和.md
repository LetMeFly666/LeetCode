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

1. 假设有多个正整数只能选其中一个减少$1$，想要使平方和最小，应该减小哪个数？

    应该减小最大的那个数。

    > 假设$a\gt b$，那么$(a-1)^2 + b^2 = a^2 + b^2 + 1 - 2a$，$a^2 + (b-1)^2 = a^2 + b^2 + 1 - 2b$，因为$a\gt b$，所以$-2a \lt -2b$，所以减小$a$更优。

2. 对`nums1`的操作，总有办法对`nums2`的等价操作。

    所以对`nums1`进行最多`k1`次操作、对`nums2`进行最多`k2`次操作，相当于最多进行`k1 + k2`次加减一操作。

    > 因为如果想要对`nums1[i] + 1`然后和`nums2[i]`求差值平方但是`k1`已经用完了的话，直接让`nums2[i] - 1`然后和`nums1[i]`求差值平方是等价的。

所以，我们直接求出两个数组一一对应两元素的差值数组`diffs`，其中`diffs[i] = abs(nums1[i] - nums2[i])`，每次减少`diffs`中最大的元素共计操作至多`k1 + k2`次（最多减少到$0$），最终的`diffs`数组中每个元素的平方和即为所求。

但是，`k1 + k2`可能是$10^9$级别的，所以我们不能真的一个一个地去试，而是一次减多个元素，每个元素减好几。

具体而言，对`diffs`数组从大到小排序。假设当前元素是`diffs[i]`（下一个元素是`diffs[i + 1]`），那么我们可以尽量把从`diffs[0]`到`diffs[i]`的所有元素都减小到`diffs[i + 1]`（共计需要减少$(diffs[i] - diffs[i + 1]) \times (i + 1)$次）：

1. 如果剩余的`k`足够多（$k\geq (diffs[i] - diffs[i + 1]) * (i + 1)$），那么就把`diffs[0]`到`diffs[i]`都减小到`diffs[i + 1]`（消耗$(diffs[i] - diffs[i + 1]) \times (i + 1)$次操作），然后继续处理下一个元素。
2. 如果剩余的`k`不够多（$k < (diffs[i] - diffs[i + 1]) * (i + 1)$），那么只能把$k \mod (i + 1)$个元素减少$\lfloor\frac{k}{i+1}\rfloor+1$以及把$i+1-(k \mod (i + 1))$个元素减少$\lfloor\frac{k}{i+1}\rfloor$。

    到此为止，`k`已经消耗完毕，就不需要再继续遍历了，开始计算。$0$到$i$的`diff`中有$k \mod (i + 1)$个`diff`是$diffs[i] - \lfloor\frac{k}{i+1}\rfloor - 1$，有$i + 1 - (k \mod (i + 1))$个`diff`是$diffs[i] - \lfloor\frac{k}{i+1}\rfloor$，剩余的`diffs[i + 1]`到`diffs[n - 1]`是原值不变。

特别的，我们可以向`diffs`数组后面插入一个哨兵元素$0$。如果循环结束了，说明每个`diff`都减少到了$0$，直接返回$0$。

### 时空复杂度

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

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/167811473)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/10/12/LeetCode%202333.%E6%9C%80%E5%B0%8F%E5%B7%AE%E5%80%BC%E5%B9%B3%E6%96%B9%E5%92%8C/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
