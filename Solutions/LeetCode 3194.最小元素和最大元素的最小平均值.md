---
title: 3194.最小元素和最大元素的最小平均值
date: 2024-10-16 23:14:57
tags: [题解, LeetCode, 简单, 数组, 双指针, 排序, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】3194.最小元素和最大元素的最小平均值：排序

力扣题目链接：[https://leetcode.cn/problems/minimum-average-of-smallest-and-largest-elements/](https://leetcode.cn/problems/minimum-average-of-smallest-and-largest-elements/)

<p>你有一个初始为空的浮点数数组 <code>averages</code>。另给你一个包含 <code>n</code> 个整数的数组 <code>nums</code>，其中 <code>n</code> 为偶数。</p>

<p>你需要重复以下步骤 <code>n / 2</code> 次：</p>

<ul>
	<li>从 <code>nums</code> 中移除<strong> 最小 </strong>的元素 <code>minElement</code> 和<strong> 最大 </strong>的元素 <code>maxElement</code>。</li>
	<li>将 <code>(minElement + maxElement) / 2</code> 加入到 <code>averages</code> 中。</li>
</ul>

<p>返回 <code>averages</code> 中的 <strong>最小 </strong>元素。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [7,8,3,4,15,13,4,1]</span></p>

<p><strong>输出：</strong> <span class="example-io">5.5</span></p>

<p><strong>解释：</strong></p>

<table>
	<tbody>
		<tr>
			<th>步骤</th>
			<th>nums</th>
			<th>averages</th>
		</tr>
		<tr>
			<td>0</td>
			<td>[7,8,3,4,15,13,4,1]</td>
			<td>[]</td>
		</tr>
		<tr>
			<td>1</td>
			<td>[7,8,3,4,13,4]</td>
			<td>[8]</td>
		</tr>
		<tr>
			<td>2</td>
			<td>[7,8,4,4]</td>
			<td>[8,8]</td>
		</tr>
		<tr>
			<td>3</td>
			<td>[7,4]</td>
			<td>[8,8,6]</td>
		</tr>
		<tr>
			<td>4</td>
			<td>[]</td>
			<td>[8,8,6,5.5]</td>
		</tr>
	</tbody>
</table>
返回 averages 中最小的元素，即 5.5。</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [1,9,8,3,10,5]</span></p>

<p><strong>输出：</strong> <span class="example-io">5.5</span></p>

<p><strong>解释：</strong></p>

<table>
	<tbody>
		<tr>
			<th>步骤</th>
			<th>nums</th>
			<th>averages</th>
		</tr>
		<tr>
			<td>0</td>
			<td>[1,9,8,3,10,5]</td>
			<td>[]</td>
		</tr>
		<tr>
			<td>1</td>
			<td>[9,8,3,5]</td>
			<td>[5.5]</td>
		</tr>
		<tr>
			<td>2</td>
			<td>[8,5]</td>
			<td>[5.5,6]</td>
		</tr>
		<tr>
			<td>3</td>
			<td>[]</td>
			<td>[5.5,6,6.5]</td>
		</tr>
	</tbody>
</table>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [1,2,3,7,8,9]</span></p>

<p><strong>输出：</strong> <span class="example-io">5.0</span></p>

<p><strong>解释：</strong></p>

<table>
	<tbody>
		<tr>
			<th>步骤</th>
			<th>nums</th>
			<th>averages</th>
		</tr>
		<tr>
			<td>0</td>
			<td>[1,2,3,7,8,9]</td>
			<td>[]</td>
		</tr>
		<tr>
			<td>1</td>
			<td>[2,3,7,8]</td>
			<td>[5]</td>
		</tr>
		<tr>
			<td>2</td>
			<td>[3,7]</td>
			<td>[5,5]</td>
		</tr>
		<tr>
			<td>3</td>
			<td>[]</td>
			<td>[5,5,5]</td>
		</tr>
	</tbody>
</table>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n == nums.length &lt;= 50</code></li>
	<li><code>n</code> 为偶数。</li>
	<li><code>1 &lt;= nums[i] &lt;= 50</code></li>
</ul>


    
## 解题方法：排序

二话不说对原始数组排个序，使用$i$从$0$到$\frac{len(nums)}2-1$遍历，更新$nums[i]+nums[len(nums)-i-1]$的最小值。

遍历结束后，将最小值除以$2$并返回。

+ 时间复杂度$O(n\log n)$
+ 空间复杂度$O(\log n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 1000;
        for (int i = 0; i < nums.size() / 2; i++) {
            ans = min(ans, nums[i] + nums[nums.size() - i - 1]);
        }
        return 1. * ans / 2;
    }
};
```

#### Go

```go
package main
import "sort"

func minimumAverage(nums []int) float64 {
    sort.Ints(nums)
    ans := 1000
    for i := 0; i < len(nums) / 2; i++ {
        ans = min(ans, nums[i] + nums[len(nums) - i - 1])
    }
    return float64(ans) / 2
}
```

#### Java

```java
import java.util.Arrays;

class Solution {
    public double minimumAverage(int[] nums) {
        Arrays.sort(nums);
        int ans = 1000;
        for (int i = 0; i < nums.length / 2; i++) {
            ans = Math.min(ans, nums[i] + nums[nums.length - i - 1]);
        }
        return 1. * ans / 2;
    }
}
```

#### Python

```python
from typing import List

class Solution:
    def minimumAverage(self, nums: List[int]) -> float:
        nums.sort()
        ans = 1000
        for i in range(len(nums) // 2):
            ans = min(ans, nums[i] + nums[-(i + 1)])
        return ans / 2
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/10/16/LeetCode%203194.%E6%9C%80%E5%B0%8F%E5%85%83%E7%B4%A0%E5%92%8C%E6%9C%80%E5%A4%A7%E5%85%83%E7%B4%A0%E7%9A%84%E6%9C%80%E5%B0%8F%E5%B9%B3%E5%9D%87%E5%80%BC/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/142994095](https://letmefly.blog.csdn.net/article/details/142994095)
