---
title: 2740.找出分区值
date: 2024-07-26 15:29:02
tags: [题解, LeetCode, 中等, 数组, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】2740.找出分区值：排序

力扣题目链接：[https://leetcode.cn/problems/find-the-value-of-the-partition/](https://leetcode.cn/problems/find-the-value-of-the-partition/)

<p>给你一个 <strong>正</strong> 整数数组 <code>nums</code> 。</p>

<p>将 <code>nums</code> 分成两个数组：<code>nums1</code> 和 <code>nums2</code> ，并满足下述条件：</p>

<ul>
	<li>数组 <code>nums</code> 中的每个元素都属于数组 <code>nums1</code> 或数组 <code>nums2</code> 。</li>
	<li>两个数组都 <strong>非空</strong> 。</li>
	<li>分区值 <strong>最小</strong> 。</li>
</ul>

<p>分区值的计算方法是 <code>|max(nums1) - min(nums2)|</code> 。</p>

<p>其中，<code>max(nums1)</code> 表示数组 <code>nums1</code> 中的最大元素，<code>min(nums2)</code> 表示数组 <code>nums2</code> 中的最小元素。</p>

<p>返回表示分区值的整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,3,2,4]
<strong>输出：</strong>1
<strong>解释：</strong>可以将数组 nums 分成 nums1 = [1,2] 和 nums2 = [3,4] 。
- 数组 nums1 的最大值等于 2 。
- 数组 nums2 的最小值等于 3 。
分区值等于 |2 - 3| = 1 。
可以证明 1 是所有分区方案的最小值。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [100,1,10]
<strong>输出：</strong>9
<strong>解释：</strong>可以将数组 nums 分成 nums1 = [10] 和 nums2 = [100,1] 。 
- 数组 nums1 的最大值等于 10 。 
- 数组 nums2 的最小值等于 1 。 
分区值等于 |10 - 1| = 9 。 
可以证明 9 是所有分区方案的最小值。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：排序

<!-- 将一个数组分成两个，第一个数组的最大值与第二个数组的最小值的绝对值之差怎么求呢？

> 很简单，将第一个数组从小到大排序，将第二个数组从小到大排序，第一个数组的最后一个元素与第二个数组的第一个元素的绝对值之差即为所求。
>
> 而我们要找的，就是这个绝对值之差的最小值。 -->

这个要求的绝对值之差的最小值，有没有可能就是原始数组中任意两个数绝对值之差的最小值呢？

答案是Yes。假设原始数组中a和b的绝对值之差最小。

> + 如果a小于b，那么我们可以将所有小于等于a的元素分到一个数组中，将所有大于等于b的元素分到一个数组中。而一定不存在大于a且小于b的元素（否则a与b的绝对值之差一定不会是最小），完美。
> + 如果a大于b，同理。
> + 如果a等于b，将所有小于等于a的元素分到第一个数组中，将所有大于a的元素分到第二个数组中，再从第一个数组中拿出一个a放到第二个数组中，完美。

如何求元素数组中任意两个数绝对值之差的最小值？

> 只需将原始数组从小到大排序，所有相邻两元素的绝对值之差的最小值即为所求。
>
> 其实可以发现，这个问题的实质就是对原始数组排序，之后选择一个位置切一刀，就分成了两个数组。问你在哪里切会使被分开的两个元素之差的绝对值最小。

+ 时间复杂度$O(n\log n)$，其中$n=len(nums)$
+ 空间复杂度$O(\log n)$

### AC代码

以下代码中都多了一个无用操作：取绝对值。因为排序后后面元素一定不小于前面元素，因此可以不用求`nums[i] - nums[i - 1]`的绝对值。

~~但这丝毫不影响Java的提交时间击败100.00%空间击败97.03%(bushi)~~

#### C++

```cpp
class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 1'000'000'000;
        for (int i = 1; i < nums.size(); i++) {
            ans = min(ans, abs(nums[i] - nums[i - 1]));
        }
        return ans;
    }
};
```

#### Go

```go
package main

import "sort"

func min(a int, b int) int {
    if a <= b {
        return a
    }
    return b
}

func abs(a int) int {
    if a >= 0 {
        return a
    }
    return -a
}

func findValueOfPartition(nums []int) int {
    sort.Ints(nums);
    ans := 1000000000;
    for i := 1; i < len(nums); i++ {
        ans = min(ans, abs(nums[i] - nums[i - 1]))
    }
    return ans;
}
```

#### Java

```java
import java.util.Arrays;

class Solution {
    public int findValueOfPartition(int[] nums) {
        Arrays.sort(nums);
        int ans = 1000000000;
        for (int i = 1; i < nums.length; i++) {
            ans = Math.min(ans, Math.abs(nums[i] - nums[i - 1]));
        }
        return ans;
    }
}
```

#### Python

```python
from typing import List

class Solution:
    def findValueOfPartition(self, nums: List[int]) -> int:
        nums.sort()
        return min(abs(nums[i] - nums[i - 1]) for i in range(1, len(nums)))
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/07/26/LeetCode%202740.%E6%89%BE%E5%87%BA%E5%88%86%E5%8C%BA%E5%80%BC/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/140717473](https://letmefly.blog.csdn.net/article/details/140717473)
