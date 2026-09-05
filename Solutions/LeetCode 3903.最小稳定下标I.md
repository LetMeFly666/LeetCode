---
title: 3903.最小稳定下标 I：O(n^2)或O(n)
date: 2026-09-04 18:39:40
tags: [题解, LeetCode, 简单, 数组, 模拟, 前缀和, 前后缀分解]
categories: [题解, LeetCode]
---

# 【LetMeFly】3903.最小稳定下标 I：O(n^2)或O(n)

力扣题目链接：[https://leetcode.cn/problems/smallest-stable-index-i/](https://leetcode.cn/problems/smallest-stable-index-i/)

<p>给你一个长度为 <code>n</code> 的整数数组 <code>nums</code> 和一个整数 <code>k</code>。</p>

<p>对于每个下标 <code>i</code>，定义它的&nbsp;<strong>不稳定值&nbsp;</strong>为 <code>max(nums[0..i]) - min(nums[i..n - 1])</code>。</p>

<p>换句话说：</p>

<ul>
	<li><code>max(nums[0..i])</code> 表示从下标 0 到下标 <code>i</code> 的元素中的<strong>&nbsp;最大值</strong>&nbsp;。</li>
	<li><code>min(nums[i..n - 1])</code> 表示从下标 <code>i</code> 到下标 <code>n - 1</code> 的元素中的&nbsp;<strong>最小值&nbsp;</strong>。</li>
</ul>

<p>如果某个下标 <code>i</code> 的不稳定值<strong>&nbsp;小于等于</strong> <code>k</code>，则称该下标为&nbsp;<strong>稳定下标</strong>&nbsp;。</p>

<p>返回&nbsp;<strong>最小&nbsp;</strong>的稳定下标。如果不存在这样的下标，则返回 <code>-1</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [5,0,1,4], k = 3</span></p>

<p><strong>输出：</strong> <span class="example-io">3</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>在下标 0 处：<code>[5]</code> 中的最大值是 5，<code>[5, 0, 1, 4]</code> 中的最小值是 0，因此不稳定值为 <code>5 - 0 = 5</code>。</li>
	<li>在下标 1 处：<code>[5, 0]</code> 中的最大值是 5，<code>[0, 1, 4]</code> 中的最小值是 0，因此不稳定值为 <code>5 - 0 = 5</code>。</li>
	<li>在下标 2 处：<code>[5, 0, 1]</code> 中的最大值是 5，<code>[1, 4]</code> 中的最小值是 1，因此不稳定值为 <code>5 - 1 = 4</code>。</li>
	<li>在下标 3 处：<code>[5, 0, 1, 4]</code> 中的最大值是 5，<code>[4]</code> 中的最小值是 4，因此不稳定值为 <code>5 - 4 = 1</code>。</li>
	<li>这是第一个不稳定值小于等于 <code>k = 3</code> 的下标，因此答案是 3。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [3,2,1], k = 1</span></p>

<p><strong>输出：</strong> <span class="example-io">-1</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>在下标 0 处，不稳定值为 <code>3 - 1 = 2</code>。</li>
	<li>在下标 1 处，不稳定值为 <code>3 - 1 = 2</code>。</li>
	<li>在下标 2 处，不稳定值为 <code>3 - 1 = 2</code>。</li>
	<li>这些值都不小于等于 <code>k = 1</code>，因此答案是 <code>-1</code>。</li>
</ul>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [0], k = 0</span></p>

<p><strong>输出：</strong> <span class="example-io">0</span></p>

<p><strong>解释：</strong></p>

<p>在下标 0 处，不稳定值为 <code>0 - 0 = 0</code>，它小于等于 <code>k = 0</code>。因此答案是 0。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法一：模拟

从前到后遍历$nums$数组，对于下标$i$，从$0$到$i$遍历求最大值，从$i$到$n-1$遍历求最小值，若二者之差$\leq k$，则直接返回下标$i$。

若遍历完成未返回则返回$-1$。

+ 时间复杂度$O(len(nums)^2)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-09-04 18:34:14
 */
class Solution {
private:
    int getM(vector<int>& nums, int i) {
        int ans = nums[0];
        for (int j = 0; j <= i; j++) {
            ans = max(ans, nums[j]);
        }
        return ans;
    }

    int getm(vector<int>& nums, int i) {
        int ans = nums[i];
        for (; i < nums.size(); i++) {
            ans = min(ans, nums[i]);
        }
        return ans;
    }
public:
    int firstStableIndex(vector<int>& nums, int k) {
        for (int i = 0, n = nums.size(); i < n; i++) {
            if (getM(nums, i) - getm(nums, i) <= k) {
                return i;
            }
        }
        return -1;
    }
};
```

## 解题方法二：前后缀分解（类似前缀和）

倒序遍历一遍$nums$数组，得到“后续最小值数组”$mini$，其中$mini[i]$表示从下标$i$到下标$n-1$的最小值。

再从前到后遍历$nums$数组，同时维护一个遍历过程中的最大值$M$，若$M-mini[i]\leq k$，则直接返回下标$i$。

若遍历完成未返回则返回$-1$。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(len(nums))$

由于本题数据量较小，所以实际上方法一的平均开销更低。

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-09-04 18:38:35
 */
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mini(n);
        mini.back() = nums.back();
        for (int i = n - 2; i >= 0; i--) {
            mini[i] = min(nums[i], mini[i + 1]);
        }
        for (int i = 0, M = 0; i < n; i++) {
            M = max(M, nums[i]);
            if (M - mini[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/164374442)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/09/04/LeetCode%203903.%E6%9C%80%E5%B0%8F%E7%A8%B3%E5%AE%9A%E4%B8%8B%E6%A0%87I/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
