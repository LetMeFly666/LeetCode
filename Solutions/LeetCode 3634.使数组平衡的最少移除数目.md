---
title: 3634.使数组平衡的最少移除数目：滑动窗口+优化(一次二分查找+剪枝)
date: 2026-02-06 19:14:46
tags: [题解, LeetCode, 中等, 数组, 排序, 滑动窗口, 二分查找]
categories: [题解, LeetCode]
---

# 【LetMeFly】3634.使数组平衡的最少移除数目：滑动窗口+优化(一次二分查找+剪枝)

力扣题目链接：[https://leetcode.cn/problems/minimum-removals-to-balance-array/](https://leetcode.cn/problems/minimum-removals-to-balance-array/)

<p>给你一个整数数组 <code>nums</code> 和一个整数 <code>k</code>。</p>

<p>如果一个数组的&nbsp;<strong>最大&nbsp;</strong>元素的值&nbsp;<strong>至多&nbsp;</strong>是其&nbsp;<strong>最小&nbsp;</strong>元素的 <code>k</code> 倍，则该数组被称为是&nbsp;<strong>平衡&nbsp;</strong>的。</p>

<p>你可以从 <code>nums</code> 中移除&nbsp;<strong>任意&nbsp;</strong>数量的元素，但不能使其变为&nbsp;<strong>空&nbsp;</strong>数组。</p>

<p>返回为了使剩余数组平衡，需要移除的元素的&nbsp;<strong>最小&nbsp;</strong>数量。</p>

<p><strong>注意：</strong>大小为 1 的数组被认为是平衡的，因为其最大值和最小值相等，且条件总是成立。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [2,1,5], k = 2</span></p>

<p><strong>输出：</strong><span class="example-io">1</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>移除 <code>nums[2] = 5</code> 得到 <code>nums = [2, 1]</code>。</li>
	<li>现在 <code>max = 2</code>, <code>min = 1</code>，且 <code>max &lt;= min * k</code>，因为 <code>2 &lt;= 1 * 2</code>。因此，答案是 1。</li>
</ul>
</div>

<p><strong class="example">示例 2:</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [1,6,2,9], k = 3</span></p>

<p><strong>输出：</strong><span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>移除 <code>nums[0] = 1</code> 和 <code>nums[3] = 9</code> 得到 <code>nums = [6, 2]</code>。</li>
	<li>现在 <code>max = 6</code>, <code>min = 2</code>，且 <code>max &lt;= min * k</code>，因为 <code>6 &lt;= 2 * 3</code>。因此，答案是 2。</li>
</ul>
</div>

<p><strong class="example">示例 3:</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [4,6], k = 2</span></p>

<p><strong>输出：</strong><span class="example-io">0</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>由于 <code>nums</code> 已经平衡，因为 <code>6 &lt;= 4 * 2</code>，所以不需要移除任何元素。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法：滑动窗口

元素顺序不影响结果，首先对原始数组按从小到大排个序。

枚举每一个最小元素的下标，不难发现随着最小元素的增大，最大元素也在增大。

因此可以使用两个指针$l$和$r$分别指向窗口起始下标和结束下标的下一位，那么窗口中元素则是**平衡**的。

从$l=0$开始不断右移左指针，每次确定右指针的位置，$r-l$即位当前方案最多保留的元素。

### 优化

对于初始$r$的确定，一共有三种方法：

1. 从后往前遍历
2. 二分查找第一个大于$nums[0]\times k$的下标 （二分查找小优化）
3. 直接不找了，从$r=0$开始，第一次循环时不断往右遍历就会找到

如果$r$指针已经移出数组边界，则可提前结束左指针的右移。

### 时空复杂度分析

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-02-06 19:14:06
 */
typedef long long ll;
class Solution {
private:
    int getLastRIndex(vector<int>& nums, ll k) {
        if (nums[0] * k > INT_MAX) {
            return nums.size() - 1;
        }
        vector<int>::iterator it = upper_bound(nums.begin(), nums.end(), nums[0] * k);
        return min((long)nums.size() - 1, it - nums.begin());
    }
public:
    int minRemoval(vector<int>& nums, ll k) {
        sort(nums.begin(), nums.end());
        int keep = 1;

        for (int l = 0, r = getLastRIndex(nums, k); ; l++) {
            while (r < nums.size() && nums[r] <= nums[l] * k) {
                r++;
            }
            keep = max(keep, r - l);
            if (r == nums.size()) {
                break;
            }
        }
        return nums.size() - keep;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/157811143)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/02/06/LeetCode%203634.%E4%BD%BF%E6%95%B0%E7%BB%84%E5%B9%B3%E8%A1%A1%E7%9A%84%E6%9C%80%E5%B0%91%E7%A7%BB%E9%99%A4%E6%95%B0%E7%9B%AE/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
