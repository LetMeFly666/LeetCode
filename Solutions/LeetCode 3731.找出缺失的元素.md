---
title: 3731.找出缺失的元素：哈希 / 排序
date: 2026-08-04 11:09:04
tags: [题解, LeetCode, 简单, 数组, 哈希表, 排序, set]
categories: [题解, LeetCode]
---

# 【LetMeFly】3731.找出缺失的元素：哈希 / 排序

力扣题目链接：[https://leetcode.cn/problems/find-missing-elements/](https://leetcode.cn/problems/find-missing-elements/)

<p>给你一个整数数组 <code>nums</code> ，数组由若干&nbsp;<b>互不相同</b> 的整数组成。</p>

<p>数组 <code>nums</code> 原本包含了某个范围内的&nbsp;<strong>所有整数&nbsp;</strong>。但现在，其中可能 <strong>缺失</strong> 部分整数。</p>

<p>该范围内的&nbsp;<strong>最小&nbsp;</strong>整数和&nbsp;<strong>最大&nbsp;</strong>整数仍然存在于 <code>nums</code> 中。</p>

<p>返回一个&nbsp;<strong>有序&nbsp;</strong>列表，包含该范围内缺失的所有整数，并&nbsp;<strong>按从小到大排序</strong>。如果没有缺失的整数，返回一个&nbsp;<strong>空&nbsp;</strong>列表。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [1,4,2,5]</span></p>

<p><strong>输出：</strong> <span class="example-io">[3]</span></p>

<p><strong>解释：</strong></p>

<p>最小整数为 1，最大整数为 5，因此完整的范围应为 <code>[1,2,3,4,5]</code>。其中只有 3 缺失。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [7,8,6,9]</span></p>

<p><strong>输出：</strong> <span class="example-io">[]</span></p>

<p><strong>解释：</strong></p>

<p>最小整数为 6，最大整数为 9，因此完整的范围为 <code>[6,7,8,9]</code>。所有整数均已存在，因此没有缺失的整数。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [5,1]</span></p>

<p><strong>输出：</strong> <span class="example-io">[2,3,4]</span></p>

<p><strong>解释：</strong></p>

<p>最小整数为 1，最大整数为 5，因此完整的范围应为 <code>[1,2,3,4,5]</code>。缺失的整数为 2、3 和 4。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>


    
## 解题方法一：哈希表

创建一个大小为$100$的布尔类型的集合作为哈希表统计每个数字是否出现过。遍历一次原始数组可得到都出现过哪些数字，再遍历一遍哈希表可得都缺少哪些数字。

+ 时间复杂度$O(len(nums)+M)$
+ 空间复杂度$O(M)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-08-04 11:04:35
 */
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<bool> ma(101);
        int m = nums[0], M = nums[0];
        for (int t : nums) {
            m = min(m, t);
            M = max(M, t);
            ma[t] = true;
        }
        
        vector<int> ans;
        ans.reserve(M - m + 1 - nums.size());
        for (int i = m + 1; i < M; i++) {
            if (!ma[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```

## 解题方法二：排序

对$nums$数组排序，用变量$i$从最小值到最大值枚举，若排序后数组的下一个元素和$i$不相等则说明缺失。

+ 时间复杂度$O(len(nums)\log len(nums) + M)$
+ 空间复杂度$O(\log len(nums))$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-08-04 11:08:22
 */
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int m = nums[0], M = nums.back(), n = nums.size();
        vector<int> ans;
        ans.reserve(M - m + 1 - n);
        for (int i = m, idx = 0; i <= M; i++) {
            if (idx == n || nums[idx] != i) {
                ans.push_back(i);
            } else {
                idx++;
            }
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/163467279)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/08/04/LeetCode%203731.%E6%89%BE%E5%87%BA%E7%BC%BA%E5%A4%B1%E7%9A%84%E5%85%83%E7%B4%A0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
