---
title: 3740.三个相等元素之间的最小距离 I：今日先暴力，"明日"再哈希
date: 2026-04-11 18:43:10
tags: [题解, LeetCode, 简单, 数组, 暴力, 模拟, 遍历]
categories: [题解, LeetCode]
---

# 【LetMeFly】3740.三个相等元素之间的最小距离 I：今日先暴力，"明日"再哈希

力扣题目链接：[https://leetcode.cn/problems/minimum-distance-between-three-equal-elements-i/](https://leetcode.cn/problems/minimum-distance-between-three-equal-elements-i/)

<p>给你一个整数数组 <code>nums</code>。</p>

<p>如果满足 <code>nums[i] == nums[j] == nums[k]</code>，且 <code>(i, j, k)</code> 是 3 个&nbsp;<strong>不同&nbsp;</strong>下标，那么三元组 <code>(i, j, k)</code> 被称为&nbsp;<strong>有效三元组&nbsp;</strong>。</p>

<p><strong>有效三元组&nbsp;</strong>的&nbsp;<strong>距离&nbsp;</strong>被定义为 <code>abs(i - j) + abs(j - k) + abs(k - i)</code>，其中 <code>abs(x)</code> 表示 <code>x</code> 的&nbsp;<strong>绝对值&nbsp;</strong>。</p>

<p>返回一个整数，表示 <strong>有效三元组&nbsp;</strong>的&nbsp;<strong>最小&nbsp;</strong>可能距离。如果不存在&nbsp;<strong>有效三元组&nbsp;</strong>，返回 <code>-1</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [1,2,1,1,3]</span></p>

<p><strong>输出：</strong> <span class="example-io">6</span></p>

<p><strong>解释：</strong></p>

<p>最小距离对应的有效三元组是&nbsp;<code>(0, 2, 3)</code>&nbsp;。</p>

<p><code>(0, 2, 3)</code> 是一个有效三元组，因为 <code>nums[0] == nums[2] == nums[3] == 1</code>。它的距离为 <code>abs(0 - 2) + abs(2 - 3) + abs(3 - 0) = 2 + 1 + 3 = 6</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [1,1,2,3,2,1,2]</span></p>

<p><strong>输出：</strong> <span class="example-io">8</span></p>

<p><strong>解释：</strong></p>

<p>最小距离对应的有效三元组是&nbsp;<code>(2, 4, 6)</code>&nbsp;。</p>

<p><code>(2, 4, 6)</code> 是一个有效三元组，因为 <code>nums[2] == nums[4] == nums[6] == 2</code>。它的距离为 <code>abs(2 - 4) + abs(4 - 6) + abs(6 - 2) = 2 + 2 + 4 = 8</code>。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [1]</span></p>

<p><strong>输出：</strong> <span class="example-io">-1</span></p>

<p><strong>解释：</strong></p>

<p>不存在有效三元组，因此答案为 -1。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= n</code></li>
</ul>


    
## 解题方法：暴力模拟

三层遍历，第一层使用$i$从$0$遍历到$n-1$，第二层使用$j$从$i+1$到$n-1$遍历，第三层使用$k$从$j+1$到$n-1$遍历。如果$nums[i]$、$nums[j]$、$nums[k]$都相等，则更新答案最小值。

Tips：由于遍历过程中$i$小于$j$小于$k$，所以有`abs(i - j) + abs(j - k) + abs(k - i) = 2 * (k - i)`。

+ 时间复杂度$O(n^3)$，其中$n=len(nums)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-04-10 23:25:26
 */
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = 201;
        for (int i = 0, n = nums.size(); i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] != nums[i]) {
                    continue;
                }
                for (int k = j + 1; k < n; k++) {
                    if (nums[k] == nums[i]) {
                        ans = min(ans, 2 * (k - i));
                    }
                }
            }
        }
        return ans == 201 ? -1 : ans;
    }
};

```

#### Python

```python
'''
LastEditTime: 2026-04-11 10:31:48
'''
from typing import List

class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        ans = 201
        for i, a in enumerate(nums):
            for j in range(i + 1, len(nums)):
                if a != nums[j]:
                    continue
                for k in range(j + 1, len(nums)):
                    if a == nums[k]:
                        ans = min(ans, 2 * (k - i))
        return -1 if ans == 201 else ans

```

> 今天要是就使用哈希表了，明天就没得写了[Doge]。

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/160058233)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/04/10/LeetCode%203740.%E4%B8%89%E4%B8%AA%E7%9B%B8%E7%AD%89%E5%85%83%E7%B4%A0%E4%B9%8B%E9%97%B4%E7%9A%84%E6%9C%80%E5%B0%8F%E8%B7%9D%E7%A6%BBI/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
