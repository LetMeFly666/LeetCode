---
title: 2089.找出数组排序后的目标下标：一次遍历不排序
date: 2026-10-19 21:44:24
tags: [题解, LeetCode, 简单, 数组, 遍历]
categories: [题解, LeetCode]
---

# 【LetMeFly】2089.找出数组排序后的目标下标：一次遍历不排序

力扣题目链接：[https://leetcode.cn/problems/find-target-indices-after-sorting-array/](https://leetcode.cn/problems/find-target-indices-after-sorting-array/)

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 以及一个目标元素 <code>target</code> 。</p>

<p><strong>目标下标</strong> 是一个满足&nbsp;<code>nums[i] == target</code> 的下标 <code>i</code> 。</p>

<p>将 <code>nums</code> 按 <strong>非递减</strong> 顺序排序后，返回由 <code>nums</code> 中目标下标组成的列表。如果不存在目标下标，返回一个 <strong>空</strong> 列表。返回的列表必须按 <strong>递增</strong> 顺序排列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,5,2,3], target = 2
<strong>输出：</strong>[1,2]
<strong>解释：</strong>排序后，nums 变为 [1,<em><strong>2</strong></em>,<em><strong>2</strong></em>,3,5] 。
满足 nums[i] == 2 的下标是 1 和 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,5,2,3], target = 3
<strong>输出：</strong>[3]
<strong>解释：</strong>排序后，nums 变为 [1,2,2,<em><strong>3</strong></em>,5] 。
满足 nums[i] == 3 的下标是 3 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,5,2,3], target = 5
<strong>输出：</strong>[4]
<strong>解释：</strong>排序后，nums 变为 [1,2,2,3,<em><strong>5</strong></em>] 。
满足 nums[i] == 5 的下标是 4 。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,5,2,3], target = 4
<strong>输出：</strong>[]
<strong>解释：</strong>nums 中不含值为 4 的元素。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i], target &lt;= 100</code></li>
</ul>


    
## 解题方法：遍历

遍历一次数组，得到：

1. 小于$target$的元素个数$less$
2. 等于$target$的元素个数$equal$

那么答案就是$[less, less + 1, \ldots, less + equal - 1]$这$equal$个下标。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-10-19 21:43:44
 */
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int less = 0, equal = 0;
        for (int t : nums) {
            if (t < target) {
                less++;
            } else if (t == target) {
                equal++;
            }
        }
        vector<int> ans(equal);
        ranges::iota(ans, less);
        return ans;
    }
};
```

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/168453920)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/10/19/LeetCode%202089.%E6%89%BE%E5%87%BA%E6%95%B0%E7%BB%84%E6%8E%92%E5%BA%8F%E5%90%8E%E7%9A%84%E7%9B%AE%E6%A0%87%E4%B8%8B%E6%A0%87/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
