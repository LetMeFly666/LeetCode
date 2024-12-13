---
title: 3264.K 次乘运算后的最终数组 I
date: 2024-12-13 09:43:07
tags: [题解, LeetCode, 简单, 数组, 数学, 模拟, 堆（优先队列）]
---

# 【LetMeFly】3264.K 次乘运算后的最终数组 I：模拟

力扣题目链接：[https://leetcode.cn/problems/final-array-state-after-k-multiplication-operations-i/](https://leetcode.cn/problems/final-array-state-after-k-multiplication-operations-i/)

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;，一个整数&nbsp;<code>k</code>&nbsp;&nbsp;和一个整数&nbsp;<code>multiplier</code>&nbsp;。</p>

<p>你需要对 <code>nums</code>&nbsp;执行 <code>k</code>&nbsp;次操作，每次操作中：</p>

<ul>
	<li>找到 <code>nums</code>&nbsp;中的 <strong>最小</strong>&nbsp;值&nbsp;<code>x</code>&nbsp;，如果存在多个最小值，选择最 <strong>前面</strong>&nbsp;的一个。</li>
	<li>将 <code>x</code>&nbsp;替换为&nbsp;<code>x * multiplier</code>&nbsp;。</li>
</ul>

<p>请你返回执行完 <code>k</code>&nbsp;次乘运算之后，最终的 <code>nums</code>&nbsp;数组。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [2,1,3,5,6], k = 5, multiplier = 2</span></p>

<p><span class="example-io"><b>输出：</b>[8,4,6,5,6]</span></p>

<p><strong>解释：</strong></p>

<table>
	<tbody>
		<tr>
			<th>操作</th>
			<th>结果</th>
		</tr>
		<tr>
			<td>1 次操作后</td>
			<td>[2, 2, 3, 5, 6]</td>
		</tr>
		<tr>
			<td>2 次操作后</td>
			<td>[4, 2, 3, 5, 6]</td>
		</tr>
		<tr>
			<td>3 次操作后</td>
			<td>[4, 4, 3, 5, 6]</td>
		</tr>
		<tr>
			<td>4 次操作后</td>
			<td>[4, 4, 6, 5, 6]</td>
		</tr>
		<tr>
			<td>5 次操作后</td>
			<td>[8, 4, 6, 5, 6]</td>
		</tr>
	</tbody>
</table>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b></span>nums = [1,2], k = 3, multiplier = 4</p>

<p><span class="example-io"><b>输出：</b></span>[16,8]</p>

<p><strong>解释：</strong></p>

<table>
	<tbody>
		<tr>
			<th>操作</th>
			<th>结果</th>
		</tr>
		<tr>
			<td>1 次操作后</td>
			<td>[4, 2]</td>
		</tr>
		<tr>
			<td>2 次操作后</td>
			<td>[4, 8]</td>
		</tr>
		<tr>
			<td>3 次操作后</td>
			<td>[16, 8]</td>
		</tr>
	</tbody>
</table>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
	<li><code>1 &lt;= k &lt;= 10</code></li>
	<li><code>1 &lt;= multiplier &lt;= 5</code></li>
</ul>


    
## 解题方法：模拟

进行$k$次如下操作：

> 每次找到最小值所在位置，将最小值乘以$multiplier$

最后返回$nums$原数组。

+ 时间复杂度$O(len(nums)\times k)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while (k--) {
            int m = nums[0], loc = 0;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] < m) {
                    m = nums[i];
                    loc = i;
                }
            }
            nums[loc] *= multiplier;
        }
        return nums;
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        for _ in range(k):
            m, loc = nums[0], 0
            for i, val in enumerate(nums):
                if val < m:
                    m, loc = val, i
            nums[loc] *= multiplier
        return nums
```

#### Java

```java
class Solution {
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        for (int round = 0; round < k; round++) {
            int m = nums[0], loc = 0;
            for (int i = 1; i < nums.length; i++) {
                if (nums[i] < m) {
                    m = nums[i];
                    loc = i;
                }
            }
            nums[loc] *= multiplier;
        }
        return nums;
    }
}
```

#### Go

```go
package main

func getFinalState(nums []int, k int, multiplier int) []int {
    for round := 0; round < k; round++ {
        m, loc := nums[0], 0
        for i, val := range nums {
            if val < m {
                m, loc = val, i
            }
        }
        nums[loc] *= multiplier
    }
    return nums
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/12/13/LeetCode%203264.K%E6%AC%A1%E4%B9%98%E8%BF%90%E7%AE%97%E5%90%8E%E7%9A%84%E6%9C%80%E7%BB%88%E6%95%B0%E7%BB%84I/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/144442552](https://letmefly.blog.csdn.net/article/details/144442552)
