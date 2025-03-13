---
title: 3131.找出与数组相加的整数 I
date: 2024-08-08 22:16:02
tags: [题解, LeetCode, 简单, 数组, 思维, 模拟, 遍历]
categories: [题解, LeetCode]
---

# 【LetMeFly】3131.找出与数组相加的整数 I：最小值之差（多语言一行版）

力扣题目链接：[https://leetcode.cn/problems/find-the-integer-added-to-array-i/](https://leetcode.cn/problems/find-the-integer-added-to-array-i/)

<p>给你两个长度相等的数组 <code>nums1</code> 和 <code>nums2</code>。</p>

<p>数组 <code>nums1</code> 中的每个元素都与变量 <code>x</code> 所表示的整数相加。如果 <code>x</code> 为负数，则表现为元素值的减少。</p>

<p>在与 <code>x</code> 相加后，<code>nums1</code> 和 <code>nums2</code> <strong>相等</strong> 。当两个数组中包含相同的整数，并且这些整数出现的频次相同时，两个数组 <strong>相等</strong> 。</p>

<p>返回整数 <code>x</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
">nums1 = [2,6,4], nums2 = [9,7,5]</span></p>

<p><strong>输出：</strong><span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
">3</span></p>

<p><strong>解释：</strong></p>

<p>与 3 相加后，<code>nums1</code> 和 <code>nums2</code> 相等。</p>
</div>

<p><strong class="example">示例 2:</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
">nums1 = [10], nums2 = [5]</span></p>

<p><strong>输出：</strong><span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
">-5</span></p>

<p><strong>解释：</strong></p>

<p>与 <code>-5</code> 相加后，<code>nums1</code> 和 <code>nums2</code> 相等。</p>
</div>

<p><strong class="example">示例 3:</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
">nums1 = [1,1,1,1], nums2 = [1,1,1,1]</span></p>

<p><strong>输出：</strong><span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
">0</span></p>

<p><strong>解释：</strong></p>

<p>与 0 相加后，<code>nums1</code> 和 <code>nums2</code> 相等。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length == nums2.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 1000</code></li>
	<li>测试用例以这样的方式生成：存在一个整数 <code>x</code>，使得 <code>nums1</code> 中的每个元素都与 <code>x</code> 相加后，<code>nums1</code> 与 <code>nums2</code> 相等。</li>
</ul>


    
## 解题方法：模拟

本题没有说“若不存在这样的x返回-1”之类的，也就是说这样的x一定存在。一定存在一个x，使得nums1中的任何一个数加上x后都与nums2中的一个数对应。

那么，nums1中最小的数加上x后是不是一定与nums2中最小的数对应？也就是说，只需要用nums2中最小的数减去nums1中最小的数，就能反向计算出x。

+ 时间复杂度$O(len(nums1))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        return *min_element(nums2.begin(), nums2.end()) - *min_element(nums1.begin(), nums1.end());
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def addedInteger(self, nums1: List[int], nums2: List[int]) -> int:
        return min(nums2) - min(nums1)
```

#### Java

```java
class Solution {
    private int min(int[] nums) {
        int ans = nums[0];
        for (int i = 1; i < nums.length; i++) {
            ans = Math.min(ans, nums[i]);
        }
        return ans;
    }

    public int addedInteger(int[] nums1, int[] nums2) {
        return min(nums2) - min(nums1);
    }
}
```

#### Go

```go
// package main

// import "slices"

func addedInteger(nums1 []int, nums2 []int) int {
    return slices.Min(nums2) - slices.Min(nums1)
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/08/08/LeetCode%203131.%E6%89%BE%E5%87%BA%E4%B8%8E%E6%95%B0%E7%BB%84%E7%9B%B8%E5%8A%A0%E7%9A%84%E6%95%B4%E6%95%B0I/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/141037760](https://letmefly.blog.csdn.net/article/details/141037760)
