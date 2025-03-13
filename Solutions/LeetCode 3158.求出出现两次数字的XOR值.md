---
title: 3158.求出出现两次数字的 XOR 值
date: 2024-10-12 14:36:28
tags: [题解, LeetCode, 简单, 位运算, 数组, 哈希表, 哈希, set]
categories: [题解, LeetCode]
---

# 【LetMeFly】3158.求出出现两次数字的 XOR 值：化整数为哈希，一次遍历O(1)空间解决

力扣题目链接：[https://leetcode.cn/problems/find-the-xor-of-numbers-which-appear-twice/](https://leetcode.cn/problems/find-the-xor-of-numbers-which-appear-twice/)

<p>给你一个数组&nbsp;<code>nums</code>&nbsp;，数组中的数字 <strong>要么</strong> 出现一次，<strong>要么</strong>&nbsp;出现两次。</p>

<p>请你返回数组中所有出现两次数字的按位<em>&nbsp;</em><code>XOR</code>&nbsp;值，如果没有数字出现过两次，返回 0 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,1,3]</span></p>

<p><span class="example-io"><b>输出：</b>1</span></p>

<p><strong>解释：</strong></p>

<p><code>nums</code>&nbsp;中唯一出现过两次的数字是 1 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,3]</span></p>

<p><span class="example-io"><b>输出：</b>0</span></p>

<p><strong>解释：</strong></p>

<p><code>nums</code>&nbsp;中没有数字出现两次。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,2,1]</span></p>

<p><span class="example-io"><b>输出：</b>3</span></p>

<p><strong>解释：</strong></p>

<p>数字 1 和&nbsp;2 出现过两次。<code>1 XOR 2 == 3</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 50</code></li>
	<li><code>nums</code>&nbsp;中每个数字要么出现过一次，要么出现过两次。</li>
</ul>


    
## 解题方法：哈希表

本题中一个数要么出现1次要么出现2次，因此可以使用一个哈希表记录一个数是否出现过。

遍历数组，若一个数出现过，则ans异或之；否则将其加入哈希表中。

因为数据范围是1到50，因此可以使用一个整数的第i位是否为1来表示i是否在哈希表中。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        long long ma = 0;
        int ans = 0;
        for (int t : nums) {
            if (ma >> t & 1) {
                ans ^= t;
            } else {
                ma |= 1LL << t;
            }
        }
        return ans;
    }
};

```

#### Go

```go
package main

func duplicateNumbersXOR(nums []int) int {
    ma := int64(0)
    ans := 0
    for _, t := range nums {
        if (ma >> t & 1) > 0 {
            ans ^= t
        } else {
            ma |= int64(1) << t
        }
    }
    return ans
}
```

#### Java

```java
class Solution {
    public int duplicateNumbersXOR(int[] nums) {
        long ma = 0;
        int ans = 0;
        for (int t : nums) {
            if ((ma >> t & 1) > 0) {
                ans ^= t;
            } else {
                ma ^= (long)(1) << t;
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
    def duplicateNumbersXOR(self, nums: List[int]) -> int:
        ans = ma = 0
        for t in nums:
            if ma >> t & 1:
                ans ^= t
            else:
                ma |= 1 << t
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/10/12/LeetCode%203158.%E6%B1%82%E5%87%BA%E5%87%BA%E7%8E%B0%E4%B8%A4%E6%AC%A1%E6%95%B0%E5%AD%97%E7%9A%84XOR%E5%80%BC/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/142877697](https://letmefly.blog.csdn.net/article/details/142877697)
