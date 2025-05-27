---
title: 3068.最大节点价值之和：脑筋急转弯+动态规划（O(1)空间）
date: 2025-05-27 23:50:42
tags: [题解, LeetCode, 困难, 位运算, 树, 数组, 动态规划, DP, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】3068.最大节点价值之和：脑筋急转弯+动态规划（O(1)空间）

力扣题目链接：[https://leetcode.cn/problems/find-the-maximum-sum-of-node-values/](https://leetcode.cn/problems/find-the-maximum-sum-of-node-values/)

<p>给你一棵 <code>n</code>&nbsp;个节点的 <strong>无向</strong>&nbsp;树，节点从 <code>0</code>&nbsp;到 <code>n - 1</code>&nbsp;编号。树以长度为 <code>n - 1</code>&nbsp;下标从 <strong>0</strong>&nbsp;开始的二维整数数组 <code>edges</code>&nbsp;的形式给你，其中&nbsp;<code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>]</code>&nbsp;表示树中节点&nbsp;<code>u<sub>i</sub></code>&nbsp;和&nbsp;<code>v<sub>i</sub></code>&nbsp;之间有一条边。同时给你一个 <strong>正</strong>&nbsp;整数&nbsp;<code>k</code>&nbsp;和一个长度为 <code>n</code>&nbsp;下标从&nbsp;<strong>0</strong>&nbsp;开始的&nbsp;<strong>非负</strong>&nbsp;整数数组&nbsp;<code>nums</code>&nbsp;，其中&nbsp;<code>nums[i]</code>&nbsp;表示节点 <code>i</code>&nbsp;的 <strong>价值</strong>&nbsp;。</p>

<p>Alice&nbsp;想 <strong>最大化</strong>&nbsp;树中所有节点价值之和。为了实现这一目标，Alice 可以执行以下操作 <strong>任意</strong>&nbsp;次（<strong>包括</strong><strong>&nbsp;0 次</strong>）：</p>

<ul>
	<li>选择连接节点&nbsp;<code>u</code>&nbsp;和&nbsp;<code>v</code>&nbsp;的边&nbsp;<code>[u, v]</code>&nbsp;，并将它们的值更新为：

	<ul>
		<li><code>nums[u] = nums[u] XOR k</code></li>
		<li><code>nums[v] = nums[v] XOR k</code></li>
	</ul>
	</li>
</ul>

<p>请你返回 Alice 通过执行以上操作 <strong>任意次</strong>&nbsp;后，可以得到所有节点 <strong>价值之和</strong>&nbsp;的 <strong>最大值</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2023/11/09/screenshot-2023-11-10-012513.png" style="width: 300px; height: 277px;padding: 10px; background: #fff; border-radius: .5rem;" /></p>

<pre>
<b>输入：</b>nums = [1,2,1], k = 3, edges = [[0,1],[0,2]]
<b>输出：</b>6
<b>解释：</b>Alice 可以通过一次操作得到最大价值和 6 ：
- 选择边 [0,2] 。nums[0] 和 nums[2] 都变为：1 XOR 3 = 2 ，数组 nums 变为：[1,2,1] -&gt; [2,2,2] 。
所有节点价值之和为 2 + 2 + 2 = 6 。
6 是可以得到最大的价值之和。
</pre>

<p><strong class="example">示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/01/09/screenshot-2024-01-09-220017.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 300px; height: 239px;" /></p>

<pre>
<b>输入：</b>nums = [2,3], k = 7, edges = [[0,1]]
<b>输出：</b>9
<b>解释：</b>Alice 可以通过一次操作得到最大和 9 ：
- 选择边 [0,1] 。nums[0] 变为：2 XOR 7 = 5 ，nums[1] 变为：3 XOR 7 = 4 ，数组 nums 变为：[2,3] -&gt; [5,4] 。
所有节点价值之和为 5 + 4 = 9 。
9 是可以得到最大的价值之和。
</pre>

<p><strong class="example">示例 3：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2023/11/09/screenshot-2023-11-10-012641.png" style="width: 600px; height: 233px;padding: 10px; background: #fff; border-radius: .5rem;" /></p>

<pre>
<b>输入：</b>nums = [7,7,7,7,7,7], k = 3, edges = [[0,1],[0,2],[0,3],[0,4],[0,5]]
<b>输出：</b>42
<b>解释：</b>Alice 不需要执行任何操作，就可以得到最大价值之和 42 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n == nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= edges[i][0], edges[i][1] &lt;= n - 1</code></li>
	<li>输入保证&nbsp;<code>edges</code>&nbsp;构成一棵合法的树。</li>
</ul>

挺有意思的题

## 解题方法：动态规划

### 推导一

前提：

1. 一个数异或$k$两次相当于没异或
2. 选择树中一条路径上的所有边，相当于只有路径两端的两个元素异或了$k$（中间每个元素都会异或$k$两次）
3. 树上任意两点之间存在一条路径

结论：

1. 相当于我可以从$nums$数组中任选两个数异或，实际上我连边都有哪些都不用管，edges数组直接删！

### 推导二

前提：

1. 每次操作都会作用两个数

    1. 如果操作前两个数都异或过，操作后相当于两个数都没异或过
    2. 如果操作前两个数都没异或过，操作后相当于两个数都异或过
    3. 如果操作前两个数一个异或过一个没异或过，操作后相当于两个数一个没异或过一个异过

结论：

1. 无论操作多少次，都相当于有偶数个数被异或了

### 解题思路

我们可以使用动态规划数组$odd[i]$代表$nums$前$i$个数中有**奇数个**被异或过的元素最大和，$even[i]$代表$nums$前$i$个数中有**偶数个**被异或过的元素最大和。

对于一个数$nums[i]$，可以选择也可以不选，对应

$odd[i]=\max(odd[i]+nums[i], even[i]+(nums[i]\verb|^|k))$

$even[i]=\max(even[i]+nums[i], odd[i]+(nums[i]\verb|^|k))$

当然也可以原地滚动优化空间。

### 时空复杂度分析

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-05-27 23:28:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-27 23:34:08
 */
typedef long long ll;

class Solution {
public:
    ll maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll odd = LLONG_MIN, even = 0;
        for (int t : nums) {
            ll newO = max(odd + t, even + (t ^ k));
            ll newE = max(even + t, odd + (t ^ k));
            odd = newO, even = newE;
        }
        return even;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-05-27 23:28:05
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-27 23:40:11
'''
from typing import List

class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        odd, even = -100000000000000, 0
        for t in nums:
            odd, even = max(odd + t, even + (t ^ k)), max(even + t, odd + (t ^ k))
        return even
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-05-27 23:28:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-27 23:45:06
 */
class Solution {
    public long maximumValueSum(int[] nums, int k, int[][] edges) {
        long even = 0, odd = -1000000000000000L;  // 记得带“L”
        for (int t : nums) {
            long newO = Math.max(odd + t, even + (t ^ k));
            long newE = Math.max(even + t, odd + (t ^ k));
            odd = newO;
            even = newE;
        }
        return even;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-05-27 23:28:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-27 23:49:20
 */
package main

func maximumValueSum(nums []int, k int, edges [][]int) int64 {
    odd, even := int64(-10000000000000000), int64(0)  // -1...0也可能是int
    for _, t := range nums {
        odd, even = max(odd + int64(t), even + int64(t ^ k)), max(even + int64(t), odd + int64(t ^ k))
    }
    return even
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/148267428)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/05/27/LeetCode%203068.%E6%9C%80%E5%A4%A7%E8%8A%82%E7%82%B9%E4%BB%B7%E5%80%BC%E4%B9%8B%E5%92%8C/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
