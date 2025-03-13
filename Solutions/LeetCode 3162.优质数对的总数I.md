---
title: 3162.优质数对的总数 I
date: 2024-10-10 13:08:51
tags: [题解, LeetCode, 简单, 数组, 哈希表, 暴力]
categories: [题解, LeetCode]
---

# 【LetMeFly】3162.优质数对的总数 I：暴力模拟

力扣题目链接：[https://leetcode.cn/problems/find-the-number-of-good-pairs-i/](https://leetcode.cn/problems/find-the-number-of-good-pairs-i/)

<p>给你两个整数数组 <code>nums1</code> 和 <code>nums2</code>，长度分别为 <code>n</code> 和 <code>m</code>。同时给你一个<strong>正整数</strong> <code>k</code>。</p>

<p>如果 <code>nums1[i]</code> 可以被 <code>nums2[j] * k</code> 整除，则称数对 <code>(i, j)</code> 为 <strong>优质数对</strong>（<code>0 &lt;= i &lt;= n - 1</code>, <code>0 &lt;= j &lt;= m - 1</code>）。</p>

<p>返回<strong> 优质数对 </strong>的总数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums1 = [1,3,4], nums2 = [1,3,4], k = 1</span></p>

<p><strong>输出：</strong><span class="example-io">5</span></p>

<p><strong>解释：</strong></p>

<p>5个优质数对分别是 <code>(0, 0)</code>, <code>(1, 0)</code>, <code>(1, 1)</code>, <code>(2, 0)</code>, 和 <code>(2, 2)</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums1 = [1,2,4,12], nums2 = [2,4], k = 3</span></p>

<p><strong>输出：</strong><span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p>2个优质数对分别是 <code>(3, 0)</code> 和 <code>(3, 1)</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n, m &lt;= 50</code></li>
	<li><code>1 &lt;= nums1[i], nums2[j] &lt;= 50</code></li>
	<li><code>1 &lt;= k &lt;= 50</code></li>
</ul>


    
## 解题方法：暴力模拟

使用一个变量`ans`记录优质数对的数量，使用双层循环，第一层枚举`nums1`的每个数(记为`n1`)，第二层枚举`nums2`的每个数(记为`n2`)，如果`n1 % (n2 * k)`等于`0`，则`ans+=1`。

+ 时间复杂度$O(nm)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int ans = 0;
        for (int n1 : nums1) {
            for (int n2 : nums2) {
                ans += n1 % (n2 * k) == 0;
            }
        }
        return ans;
    }
};
```

#### Go

```go
package main

func numberOfPairs(nums1 []int, nums2 []int, k int) int {
    ans := 0
    for _, n1 := range nums1 {
        for _, n2 := range nums2 {
            if n1 % (n2 * k) == 0 {
                ans++
            }
        }
    }
    return ans
}
```

#### Java

```java
class Solution {
    public int numberOfPairs(int[] nums1, int[] nums2, int k) {
        int ans = 0;
        for (int n1 : nums1) {
            for (int n2 : nums2) {
                if (n1 % (n2 * k) == 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
}
```

#### Python

```python
from typing import List

class Solution:
    def numberOfPairs(self, nums1: List[int], nums2: List[int], k: int) -> int:
        return sum(n1 % (n2 * k) == 0 for n2 in nums2 for n1 in nums1)
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/10/10/LeetCode%203162.%E4%BC%98%E8%B4%A8%E6%95%B0%E5%AF%B9%E7%9A%84%E6%80%BB%E6%95%B0I/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/142818980](https://letmefly.blog.csdn.net/article/details/142818980)
