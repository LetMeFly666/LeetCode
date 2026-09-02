---
title: 3875.构造奇偶一致的数组 I
date: 2026-09-02 17:02:41
tags: [题解, LeetCode, 简单, 数组, 数学]
categories: [题解, LeetCode]
---

# 【LetMeFly】3875.构造奇偶一致的数组 I

力扣题目链接：[https://leetcode.cn/problems/construct-uniform-parity-array-i/](https://leetcode.cn/problems/construct-uniform-parity-array-i/)

<p>给你一个长度为 <code>n</code> 的数组 <code>nums1</code>，其中包含 <strong>互不相同</strong> 的整数。</p>

<p>你需要构造另一个长度为 <code>n</code> 的数组 <code>nums2</code>，使得 <code>nums2</code> 中的元素要么全部为&nbsp;<strong>奇数</strong>，要么全部为<strong>&nbsp;偶数</strong>。</p>

<p>对于每个下标 <code>i</code>，你必须从以下两种选择中<strong>&nbsp;任选其一</strong>（顺序不限）：</p>

<ul>
	<li><code>nums2[i] = nums1[i]</code></li>
	<li><code>nums2[i] = nums1[i] - nums1[j]</code>，其中 <code>j != i</code></li>
</ul>

<p>如果能够构造出满足条件的数组，则返回 <code>true</code>；否则，返回 <code>false</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums1 = [2,3]</span></p>

<p><strong>输出：</strong> <span class="example-io">true</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>选择 <code>nums2[0] = nums1[0] - nums1[1] = 2 - 3 = -1</code>。</li>
	<li>选择 <code>nums2[1] = nums1[1] = 3</code>。</li>
	<li><code>nums2 = [-1, 3]</code>，两个元素均为奇数。因此答案为 <code>true</code>。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums1 = [4,6]</span></p>

<p><strong>输出：</strong> <span class="example-io">true</span></p>

<p><strong>解释：</strong>​​​​​​​</p>

<ul>
	<li>选择 <code>nums2[0] = nums1[0] = 4</code>。</li>
	<li>选择 <code>nums2[1] = nums1[1] = 6</code>。</li>
	<li><code>nums2 = [4, 6]</code>，两个元素均为偶数。因此答案为 <code>true</code>。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == nums1.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums1[i] &lt;= 100</code></li>
	<li><code>nums1</code> 中的所有整数互不相同。</li>
</ul>


    
## 解题方法：xx

11111

+ 时间复杂度$O(N^2)$
+ 空间复杂度$O(N\log N)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-09-02 16:51:21
 */
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        return true;
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-09-02 17:01:23
'''
class Solution:
    def uniformArray(self, nums1: list[int]) -> bool:
        return True
```

#### Java

```java
/*
 * @LastEditTime: 2026-09-02 16:52:46
 */
class Solution {
    public boolean uniformArray(int[] nums1) {
        return true;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2026-09-02 16:51:34
 */
package main

func uniformArray(nums1 []int) bool {
    return true
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-09-02 17:01:51
 */
impl Solution {
    pub fn uniform_array(nums1: Vec<i32>) -> bool {
        true
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/--------------------------)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/09/02/LeetCode%203875.%E6%9E%84%E9%80%A0%E5%A5%87%E5%81%B6%E4%B8%80%E8%87%B4%E7%9A%84%E6%95%B0%E7%BB%84I/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
