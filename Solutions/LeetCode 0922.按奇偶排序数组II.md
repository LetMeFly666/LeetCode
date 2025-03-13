---
title: 922.按奇偶排序数组 II：O(1)空间复杂度-一次遍历双指针
date: 2025-02-04 22:33:47
tags: [题解, LeetCode, 简单, 数组, 双指针, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】922.按奇偶排序数组 II：O(1)空间复杂度-一次遍历双指针

力扣题目链接：[https://leetcode.cn/problems/sort-array-by-parity-ii/](https://leetcode.cn/problems/sort-array-by-parity-ii/)

<p>给定一个非负整数数组&nbsp;<code>nums</code>，&nbsp;&nbsp;<code>nums</code> 中一半整数是 <strong>奇数</strong> ，一半整数是 <strong>偶数</strong> 。</p>

<p>对数组进行排序，以便当&nbsp;<code>nums[i]</code> 为奇数时，<code>i</code>&nbsp;也是 <strong>奇数</strong> ；当&nbsp;<code>nums[i]</code>&nbsp;为偶数时， <code>i</code> 也是 <strong>偶数</strong> 。</p>

<p>你可以返回 <em>任何满足上述条件的数组作为答案</em> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,2,5,7]
<strong>输出：</strong>[4,5,2,7]
<strong>解释：</strong>[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [2,3]
<b>输出：</b>[2,3]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>nums.length</code>&nbsp;是偶数</li>
	<li><code>nums</code>&nbsp;中一半是偶数</li>
	<li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>可以不使用额外空间解决问题吗？</p>


    
## 解题方法：双指针

使用两个指针分别指向奇数下标和偶数下标。

当偶数下标指针不越界时，如果偶数下标指针指向的是偶数，就右移到下一个偶数下标；否则如果奇数下标指针指向的是奇数，就右移到下一个奇数下标；否则（奇数指针指偶数，偶数指针指奇数）就交换二者并集体右移。

为什么“当偶数下标指针不越界”这一个条件就够了？因为偶数下标越界时，说明偶数下标的元素全部符合，也说明奇数下标的元素全部合规了。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-02-04 22:15:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-04 22:23:51
 */
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        for (int i = 0, j = 1; i < nums.size();) {
            if (nums[i] % 2 == 0) {
                i += 2;
            } else if (nums[j] % 2) {
                j += 2;
            } else {
                swap(nums[i], nums[j]);
                i += 2;
                j += 2;
            }
        }
        return nums;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-02-04 22:25:05
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-04 22:26:17
'''
from typing import List

class Solution:
    def sortArrayByParityII(self, nums: List[int]) -> List[int]:
        i, j = 0, 1
        while i < len(nums):
            if nums[i] % 2 == 0:
                i += 2
            elif nums[j] % 2:
                j += 2
            else:
                nums[i], nums[j] = nums[j], nums[i]
                i += 2
                j += 2
        return nums
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-02-04 22:25:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-04 22:28:26
 */
class Solution {
    public int[] sortArrayByParityII(int[] nums) {
        for (int i = 0, j = 1; i < nums.length;) {
            if (nums[i] % 2 == 0) {
                i += 2;
            } else if (nums[j] % 2 != 0) {
                j += 2;
            } else {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i += 2;
                j += 2;
            }
        }
        return nums;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-02-04 22:25:07
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-04 22:32:30
 */
package main

func sortArrayByParityII(nums []int) []int {
    for i, j := 0, 1; i < len(nums); {
		if nums[i] % 2 == 0 {
			i += 2
		} else if nums[j] % 2 == 1 {
			j += 2
		} else {
			nums[i], nums[j] = nums[j], nums[i]
			i += 2
			j += 2
		}
	}
	return nums
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/02/04/LeetCode%200922.%E6%8C%89%E5%A5%87%E5%81%B6%E6%8E%92%E5%BA%8F%E6%95%B0%E7%BB%84II/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/145445952](https://letmefly.blog.csdn.net/article/details/145445952)
