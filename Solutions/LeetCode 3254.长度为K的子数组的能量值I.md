---
title: 3254.长度为 K 的子数组的能量值 I
date: 2024-11-06 17:26:30
tags: [题解, LeetCode, 中等, 数组, 滑动窗口, 暴力, 模拟]
---

# 【LetMeFly】3254.长度为 K 的子数组的能量值 I：等II再用O(n)的方法，先暴力模拟了再说

力扣题目链接：[https://leetcode.cn/problems/find-the-power-of-k-size-subarrays-i/](https://leetcode.cn/problems/find-the-power-of-k-size-subarrays-i/)

<p>给你一个长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;和一个正整数&nbsp;<code>k</code>&nbsp;。</p>

<p>一个数组的 <strong>能量值</strong> 定义为：</p>

<ul>
	<li>如果 <strong>所有</strong>&nbsp;元素都是依次&nbsp;<strong>连续</strong> 且 <strong>上升</strong> 的，那么能量值为 <strong>最大</strong>&nbsp;的元素。</li>
	<li>否则为 -1 。</li>
</ul>

<p>你需要求出 <code>nums</code>&nbsp;中所有长度为 <code>k</code>&nbsp;的&nbsp;<span data-keyword="subarray-nonempty">子数组</span>&nbsp;的能量值。</p>

<p>请你返回一个长度为 <code>n - k + 1</code>&nbsp;的整数数组&nbsp;<code>results</code>&nbsp;，其中&nbsp;<code>results[i]</code>&nbsp;是子数组&nbsp;<code>nums[i..(i + k - 1)]</code>&nbsp;的能量值。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,3,4,3,2,5], k = 3</span></p>

<p><b>输出：</b>[3,4,-1,-1,-1]</p>

<p><strong>解释：</strong></p>

<p><code>nums</code>&nbsp;中总共有 5 个长度为 3 的子数组：</p>

<ul>
	<li><code>[1, 2, 3]</code>&nbsp;中最大元素为 3 。</li>
	<li><code>[2, 3, 4]</code>&nbsp;中最大元素为 4 。</li>
	<li><code>[3, 4, 3]</code>&nbsp;中元素 <strong>不是</strong>&nbsp;连续的。</li>
	<li><code>[4, 3, 2]</code>&nbsp;中元素 <b>不是</b>&nbsp;上升的。</li>
	<li><code>[3, 2, 5]</code>&nbsp;中元素 <strong>不是</strong>&nbsp;连续的。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [2,2,2,2,2], k = 4</span></p>

<p><span class="example-io"><b>输出：</b>[-1,-1]</span></p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [3,2,3,2,3,2], k = 2</span></p>

<p><span class="example-io"><b>输出：</b>[-1,3,-1,3,-1]</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == nums.length &lt;= 500</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
</ul>


    
## 解题方法：模拟

用$i$从$0$到$n - k$枚举区间的起点，用$j$从$i+1$到$i+k-1$枚举区间中第一个元素之外的其他元素。

如果存在$j$使得$nums[j] != nums[j - 1] + 1$，就令$ans[i] = -1$；否则，令$ans[i] = nums[i + k - 1]$。

+ 时间复杂度$O(nk)$
+ 空间复杂度$O(1)$，力扣返回值不计入算法空间复杂度

$O(n)$时间复杂度的算法请看题解[【LetMeFly】3255.长度为 K 的子数组的能量值 II：和官解思路不同的O(n)做法（附思考过程）](https://blog.letmefly.xyz/2024/11/07/LeetCode%203255.%E9%95%BF%E5%BA%A6%E4%B8%BAK%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84%E7%9A%84%E8%83%BD%E9%87%8F%E5%80%BCII/)。

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans(nums.size() - k + 1);
        for (int i = 0; i + k <= nums.size(); i++) {
            for (int j = i + 1; j < i + k; j++) {
                if (nums[j] != nums[j - 1] + 1) {
                    ans[i] = -1;
                    break;
                }
            }
            if (ans[i] != -1) {
                ans[i] = nums[i + k - 1];
            }
        }
        return ans;
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        return [nums[i + k - 1] if all(nums[j] == nums[j - 1] + 1 for j in range(i + 1, i + k)) else -1 for i in range(len(nums) - k + 1)]
```

#### Java

```java
class Solution {
    public int[] resultsArray(int[] nums, int k) {
        int[] ans = new int[nums.length - k + 1];
        for (int i = 0; i + k <= nums.length; i++) {
            for (int j = i + 1; j < i + k; j++) {
                if (nums[j] != nums[j - 1] + 1) {
                    ans[i] = -1;
                    break;
                }
            }
            ans[i] = ans[i] == -1 ? -1 : nums[i + k - 1];
        }
        return ans;
    }
}
```

#### Go

```go
package main

func resultsArray(nums []int, k int) (ans []int) {
    ans = make([]int, len(nums) - k + 1)
    for i := 0; i + k <= len(nums); i++ {
        for j := i + 1; j < i + k; j++ {
            if nums[j] != nums[j - 1] + 1 {
                ans[i] = -1
                break
            }
        }
        if (ans[i] != -1) {
            ans[i] = nums[i + k - 1]
        }
    }
    return
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/11/06/LeetCode%203254.%E9%95%BF%E5%BA%A6%E4%B8%BAK%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84%E7%9A%84%E8%83%BD%E9%87%8F%E5%80%BCI/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/143575677](https://letmefly.blog.csdn.net/article/details/143575677)
