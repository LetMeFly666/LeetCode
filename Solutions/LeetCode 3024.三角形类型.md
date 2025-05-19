---
title: 3024.三角形类：手速题
date: 2025-05-19 13:36:41
tags: [题解, LeetCode, 简单, 数组, 数学, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】3024.三角形类型：手速题

力扣题目链接：[https://leetcode.cn/problems/type-of-triangle/](https://leetcode.cn/problems/type-of-triangle/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始长度为 <code>3</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;，需要用它们来构造三角形。</p>

<ul>
	<li>如果一个三角形的所有边长度相等，那么这个三角形称为&nbsp;<strong>equilateral</strong>&nbsp;。</li>
	<li>如果一个三角形恰好有两条边长度相等，那么这个三角形称为&nbsp;<strong>isosceles</strong>&nbsp;。</li>
	<li>如果一个三角形三条边的长度互不相同，那么这个三角形称为&nbsp;<strong>scalene</strong>&nbsp;。</li>
</ul>

<p>如果这个数组无法构成一个三角形，请你返回字符串&nbsp;<code>"none"</code>&nbsp;，否则返回一个字符串表示这个三角形的类型。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [3,3,3]
<b>输出：</b>"equilateral"
<b>解释：</b>由于三条边长度相等，所以可以构成一个等边三角形，返回 "equilateral" 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [3,4,5]
<b>输出：</b>"scalene"
<b>解释：</b>
nums[0] + nums[1] = 3 + 4 = 7 ，大于 nums[2] = 5 <span style="text-wrap: wrap;">。</span>
nums[0] + nums[2] = 3 + 5 = 8 ，大于 nums[1] = 4 。
nums[1] + nums[2] = 4 + 5 = 9 ，大于 nums[0] = 3 。
由于任意两边之和都大于第三边，所以可以构成一个三角形，因为三条边的长度互不相等，所以返回 "scalene"。
</pre>

<p><strong>提示：</strong></p>

<ul>
	<li><code>nums.length == 3</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>


    
## 解题方法：if-else

为了判断给定三个变长是否满足三角形的基本性质（以及是否有两边等长），可以先将三个数从小到大排个序。

+ 如果两边之和小于等于第三边则不能构成三角形
+ 如果三边全相等则为正三角形
+ 如果有任何两边相等则为等腰三角形
+ 否则为普通三角形

以上。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-05-19 13:22:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-19 13:28:44
 */
class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums[0] + nums[1] <= nums[2]) {
            return "none";
        }
        if (nums[0] == nums[1] && nums[1] == nums[2]) {
            return "equilateral";
        }
        if (nums[0] == nums[1] || nums[1] == nums[2]) {
            return "isosceles";
        }
        return "scalene";
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-05-19 13:22:46
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-19 13:30:25
'''
from typing import List

class Solution:
    def triangleType(self, nums: List[int]) -> str:
        nums.sort()
        a, b, c = nums
        if a + b <= c:
            return "none"
        if a == b == c:
            return "equilateral"
        if a == b or b == c:
            return "isosceles"
        return "scalene"
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-05-19 13:22:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-19 13:32:46
 */
import java.util.Arrays;

class Solution {
    public String triangleType(int[] nums) {
        Arrays.sort(nums);
        if (nums[0] + nums[1] <= nums[2]) {
            return "none";
        }
        if (nums[0] == nums[1] && nums[1] == nums[2]) {
            return "equilateral";
        }
        if (nums[0] == nums[1] || nums[1] == nums[2]) {
            return "isosceles";
        }
        return "scalene";
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-05-19 13:22:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-19 13:35:48
 */
package main

import "sort"

func triangleType(nums []int) string {
    sort.Ints(nums)
    if nums[0] + nums[1] <= nums[2] {
        return "none"
    }
    if nums[0] == nums[1] && nums[1] == nums[2] {
        return "equilateral"
    }
    if nums[0] == nums[1] || nums[1] == nums[2] {
        return "isosceles"
    }
    return "scalene"
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/148061722)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/05/19/LeetCode%203024.%E4%B8%89%E8%A7%92%E5%BD%A2%E7%B1%BB%E5%9E%8B/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
