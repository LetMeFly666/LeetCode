---
title: 1920.基于排列构建数组
date: 2025-05-06 21:41:37
tags: [题解, LeetCode, 简单, 数组, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】1920.基于排列构建数组

力扣题目链接：[https://leetcode.cn/problems/build-array-from-permutation/](https://leetcode.cn/problems/build-array-from-permutation/)

<p>给你一个 <strong>从 0 开始的排列</strong> <code>nums</code>（<strong>下标也从 0 开始</strong>）。请你构建一个 <strong>同样长度</strong> 的数组 <code>ans</code> ，其中，对于每个 <code>i</code>（<code>0 &lt;= i &lt; nums.length</code>），都满足 <code>ans[i] = nums[nums[i]]</code> 。返回构建好的数组 <code>ans</code> 。</p>

<p><strong>从 0 开始的排列</strong> <code>nums</code> 是一个由 <code>0</code> 到&nbsp;<code>nums.length - 1</code>（<code>0</code> 和 <code>nums.length - 1</code> 也包含在内）的不同整数组成的数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,2,1,5,3,4]
<strong>输出：</strong>[0,1,2,4,5,3]<strong>
解释：</strong>数组 ans 构建如下：
ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
    = [nums[0], nums[2], nums[1], nums[5], nums[3], nums[4]]
    = [0,1,2,4,5,3]</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,0,1,2,3,4]
<strong>输出：</strong>[4,5,0,1,2,3]
<strong>解释：</strong>数组 ans 构建如下：
ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
    = [nums[5], nums[0], nums[1], nums[2], nums[3], nums[4]]
    = [4,5,0,1,2,3]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums[i] &lt; nums.length</code></li>
	<li><code>nums</code> 中的元素 <strong>互不相同</strong></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你能在不使用额外空间的情况下解决此问题吗（即 <code>O(1)</code> 内存）？</p>


    
## 解题方法：模拟

创建一个长度和`nums`相等的数组，从$0$到$len(nums)-1$遍历，令$ans[i]$的值为$nums[nums[i]]$即可。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$，力扣算法返回值不计入算法空间复杂度

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-05-06 21:30:01
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-06 21:32:46
 */
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-05-06 21:30:01
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-06 21:34:14
'''
from typing import List

class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        ans = [0] * len(nums)
        for i in range(len(nums)):
            ans[i] = nums[nums[i]]
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-05-06 21:30:01
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-06 21:37:52
 */
class Solution {
    public int[] buildArray(int[] nums) {
        int[] ans = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-05-06 21:30:01
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-06 21:39:38
 */
package main

func buildArray(nums []int) []int {
    ans := make([]int, len(nums))
    for i := range nums {
        ans[i] = nums[nums[i]]
    }
    return ans
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/147748208)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/05/06/LeetCode%201920.%E5%9F%BA%E4%BA%8E%E6%8E%92%E5%88%97%E6%9E%84%E5%BB%BA%E6%95%B0%E7%BB%84/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
