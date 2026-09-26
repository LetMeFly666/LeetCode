---
title: 1477.找两个和为目标值且不重叠的子数组：滑动窗口 + 记录前值(动态规划)
date: 2026-09-17 13:26:42
tags: [题解, LeetCode, 中等, 数组, 哈希表, 二分查找, 动态规划, 滑动窗口]
categories: [题解, LeetCode]
---

# 【LetMeFly】1477.找两个和为目标值且不重叠的子数组：滑动窗口 + 记录前值(动态规划)

力扣题目链接：[https://leetcode.cn/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/](https://leetcode.cn/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/)

<p>给你一个整数数组&nbsp;<code>arr</code> 和一个整数值&nbsp;<code>target</code>&nbsp;。</p>

<p>请你在 <code>arr</code>&nbsp;中找 <strong>两个互不重叠的子数组</strong>&nbsp;且它们的和都等于&nbsp;<code>target</code>&nbsp;。可能会有多种方案，请你返回满足要求的两个子数组长度和的 <strong>最小值</strong> 。</p>

<p>请返回满足要求的最小长度和，如果无法找到这样的两个子数组，请返回 <strong>-1</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [3,2,2,4,3], target = 3
<strong>输出：</strong>2
<strong>解释：</strong>只有两个子数组和为 3 （[3] 和 [3]）。它们的长度和为 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [7,3,4,7], target = 7
<strong>输出：</strong>2
<strong>解释：</strong>尽管我们有 3 个互不重叠的子数组和为 7 （[7], [3,4] 和 [7]），但我们会选择第一个和第三个子数组，因为它们的长度和 2 是最小值。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [4,3,2,6,2,3,4], target = 6
<strong>输出：</strong>-1
<strong>解释：</strong>我们只有一个和为 6 的子数组。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>arr = [5,5,4,4,5], target = 3
<strong>输出：</strong>-1
<strong>解释：</strong>我们无法找到和为 3 的子数组。
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>arr = [3,1,1,1,5,1,2,1], target = 3
<strong>输出：</strong>3
<strong>解释：</strong>注意子数组 [1,2] 和 [2,1] 不能成为一个方案因为它们重叠了。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 1000</code></li>
	<li><code>1 &lt;= target &lt;= 10^8</code></li>
</ul>


    
## 解题方法：滑动窗口

如果这道题只需要求一个和为`target`的最短子数组的长度，那么一个滑动窗口就可以解决：

> 用两个指针`l`和`r`表示滑动窗口的左右边界，用变量`cnt`表示当前窗口内元素的和。
> 
> 每次右指针`r`右移一位，当`cnt > target`时，不断右移左指针。如果`cnt == target`，则更新最短子数组的长度。

现在变成了两个和为`target`的不重叠子数组，怎么办？也好办，用一个数组把 从下标`0`到`l`为止最短的`target`和子数组 记录下来就好了。

当滑动窗口中和为`target`时候，我们要做的事情就变成了两个：

+ 一是更新答案最小值，可能是 当前窗口中的一段($r-l+1$) + 当前窗口之前范围内的最短子数组长度($minL[l]$)
+ 二是更新从$0$到$r$为止的最短子数组长度$minL[r+1]$，可能是当前窗口中的这一段($r-l+1$)，或者是之前的最短子数组长度($minL[r]$)

以上。

+ 时间复杂度$O(len(arr))$，每个元素最多入队一次出队一次；
+ 空间复杂度$O(len(arr))$。

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-09-17 13:26:14
 */
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> minL(n + 1, 1e7);
        int ans = 1e7;
        for (int l = 0, r = 0, cnt = 0; r < n; r++) {
            cnt += arr[r];
            while (cnt > target) {
                cnt -= arr[l++];
            }
            minL[r + 1] = minL[r];
            if (cnt == target) {
                minL[r + 1] = min(minL[r + 1], r - l + 1);
                ans = min(ans, minL[l] + r - l + 1);
            }
        }
        return ans > n ? -1 : ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/165740106)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/09/17/LeetCode%201477.%E6%89%BE%E4%B8%A4%E4%B8%AA%E5%92%8C%E4%B8%BA%E7%9B%AE%E6%A0%87%E5%80%BC%E4%B8%94%E4%B8%8D%E9%87%8D%E5%8F%A0%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
