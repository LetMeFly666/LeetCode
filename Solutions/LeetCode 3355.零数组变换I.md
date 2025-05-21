---
title: 3355.零数组变换 I：差分数组
date: 2025-05-21 23:24:54
tags: [题解, LeetCode, 中等, 数组, 前缀和, 差分数组]
categories: [题解, LeetCode]
---

# 【LetMeFly】3355.零数组变换 I：差分数组

力扣题目链接：[https://leetcode.cn/problems/zero-array-transformation-i/](https://leetcode.cn/problems/zero-array-transformation-i/)

<p>给定一个长度为 <code>n</code> 的整数数组 <code>nums</code> 和一个二维数组 <code>queries</code>，其中 <code>queries[i] = [l<sub>i</sub>, r<sub>i</sub>]</code>。</p>

<p>对于每个查询&nbsp;<code>queries[i]</code>：</p>

<ul>
	<li>在&nbsp;<code>nums</code>&nbsp;的下标范围&nbsp;<code>[l<sub>i</sub>, r<sub>i</sub>]</code>&nbsp;内选择一个下标 <span data-keyword="subset">子集</span>。</li>
	<li>将选中的每个下标对应的元素值减 1。</li>
</ul>

<p><strong>零数组&nbsp;</strong>是指所有元素都等于 0 的数组。</p>

<p>如果在按顺序处理所有查询后，可以将 <code>nums</code> 转换为&nbsp;<strong>零数组&nbsp;</strong>，则返回 <code>true</code>，否则返回 <code>false</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [1,0,1], queries = [[0,2]]</span></p>

<p><strong>输出：</strong> <span class="example-io">true</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li><strong>对于 i = 0：</strong>

	<ul>
		<li>选择下标子集 <code>[0, 2]</code> 并将这些下标处的值减 1。</li>
		<li>数组将变为 <code>[0, 0, 0]</code>，这是一个零数组。</li>
	</ul>
	</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [4,3,2,1], queries = [[1,3],[0,2]]</span></p>

<p><strong>输出：</strong> <span class="example-io">false</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li><strong>对于 i = 0：</strong>&nbsp;

	<ul>
		<li>选择下标子集 <code>[1, 2, 3]</code> 并将这些下标处的值减 1。</li>
		<li>数组将变为 <code>[4, 2, 1, 0]</code>。</li>
	</ul>
	</li>
	<li><strong>对于 i = 1：</strong>
	<ul>
		<li>选择下标子集 <code>[0, 1, 2]</code> 并将这些下标处的值减 1。</li>
		<li>数组将变为 <code>[3, 1, 0, 0]</code>，这不是一个零数组。</li>
	</ul>
	</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>0 &lt;= l<sub>i</sub> &lt;= r<sub>i</sub> &lt; nums.length</code></li>
</ul>


    
## 解题方法：差分数组

创建一个$op$数组，假设某个query是从$0$到$3$，那么就将$op[0]$到$op[3]$都加一(代表下标$0$到$3$都可以被操作一次)，其中$op[i]$代表$nums[i]$一共被操作多少次。

创建一个$diff$数组，其中$diff[i]$代表数组$op[i]-op[i-1]$的**差值**。

假设想让$op[l]$到$op[r]$都加一，那么其实只需要$diff[l]$加一$diff[r + 1]$减一，$op$数组直接扔了都行。

执行完所有操作(更新好diff数组)后，$\sum_0^i diff[i]$即为$op[i]$的值。

如果存在任何一个$i$的$nums[i]\gt op[i]$，就说明$nums[i]$无法减为$0$，返回`false`。

+ 时间复杂度$O(len(queries)+len(nums))$
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-05-21 23:06:35
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-21 23:14:28
 */
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> diff(nums.size() + 1);
        for (vector<int>& q : queries) {
            diff[q[0]]++;
            diff[q[1] + 1]--;
        }
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt += diff[i];
            if (nums[i] > cnt) {
                return false;
            }
        }
        return true;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-05-21 23:06:35
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-21 23:19:48
'''
from typing import List

class Solution:
    def isZeroArray(self, nums: List[int], queries: List[List[int]]) -> bool:
        diff = [0] * (len(nums) + 1)
        for l, r in queries:
            diff[l] += 1
            diff[r + 1] -= 1
        cnt = 0
        for i in range(len(nums)):
            cnt += diff[i]
            if nums[i] > cnt:
                return False
        return True
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-05-21 23:06:35
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-21 23:20:50
 */
class Solution {
    public boolean isZeroArray(int[] nums, int[][] queries) {
        int[] diff = new int[nums.length + 1];
        for (int[] q : queries) {
            diff[q[0]]++;
            diff[q[1] + 1]--;
        }
        int cnt = 0;
        for (int i = 0; i < nums.length; i++) {
            cnt += diff[i];
            if (nums[i] > cnt) {
                return false;
            }
        }
        return true;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-05-21 23:06:35
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-21 23:23:00
 */
package main

func isZeroArray(nums []int, queries [][]int) bool {
    diff := make([]int, len(nums) + 1)
    for _, q := range queries {
        diff[q[0]]++
        diff[q[1] + 1]--
    }
    cnt := 0
    for i := 0; i < len(nums); i++ {
        cnt += diff[i]
        if nums[i] > cnt {
            return false
        }
    }
    return true
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/148126611)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/05/21/LeetCode%203355.%E9%9B%B6%E6%95%B0%E7%BB%84%E5%8F%98%E6%8D%A2I/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
