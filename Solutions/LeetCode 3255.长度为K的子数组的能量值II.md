---
title: 3255.长度为 K 的子数组的能量值 II
date: 2024-11-07 12:35:10
tags: [题解, LeetCode, 中等, 数组, 滑动窗口, 遍历]
---

# 【LetMeFly】3255.长度为 K 的子数组的能量值 II：和官解思路不同的O(n)做法（附思考过程）

力扣题目链接：[https://leetcode.cn/problems/find-the-power-of-k-size-subarrays-ii/](https://leetcode.cn/problems/find-the-power-of-k-size-subarrays-ii/)

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
	<li><code>1 &lt;= n == nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
</ul>


    
## 解题方法：遍历（类似滑动窗口）

本题`长度为 K 的子数组的能量值 II`和上一题[`长度为 K 的子数组的能量值 I`](https://blog.letmefly.xyz/2024/11/06/LeetCode%203254.%E9%95%BF%E5%BA%A6%E4%B8%BAK%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84%E7%9A%84%E8%83%BD%E9%87%8F%E5%80%BCI/)的唯一区别是数据量，本题数据量不支持$O(nk)$时间复杂度的做法。

上一题中我们枚举每个长度为K的区间的左端点，之后遍历区间，若区间中存在“相邻不连续”的两个元素则能量值为-1，否则为区间的最后一个元素。每个区间都可能需要$O(k)$的时间复杂度来完成结果的计算。

但是其实不难发现，区间（假设k很大区间很长）每次向右移动一个元素，区间中大量的元素是不变的，只有区间起始位置元素和结束位置元素发生了变化。

因此解决方案来了，我们使用一个额外的变量$notContinue$记录区间中不连续的“相邻两个元素”有多少对，这样在区间移动的时候只需要根据区间开头元素和末尾元素的变化情况就能在$O(1)$的时间内算出新区间的“notContinue”。

如果一个区间的$notCoutinue$非零，则说明该区间中存在相邻不连续的元素对，区间“能量值”为$-1$；否则区间能量值为区间的最后一个元素（即最大元素）。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$，力扣返回值不计入算法空间复杂度

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans(nums.size() - k + 1);
        int notContinue = 0;
        for (int i = 1; i < k; i++) {
            notContinue += nums[i] != nums[i - 1] + 1;
        }
        ans[0] = notContinue ? -1 : nums[k - 1];
        for (int i = 1; i + k <= nums.size(); i++) {
            notContinue -= nums[i] != nums[i - 1] + 1;
            notContinue += nums[i + k - 1] != nums[i + k - 2] + 1;
            ans[i] = notContinue ? -1 : nums[i + k - 1];
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
        ans = [0] * (len(nums) - k + 1)
        notCoutinue = sum(nums[i] != nums[i -  1] + 1 for i in range(1, k))
        ans[0] = -1 if notCoutinue else nums[k - 1]
        for i in range(1, len(nums) - k + 1):
            notCoutinue -= nums[i] != nums[i - 1] + 1
            notCoutinue += nums[i + k - 1] != nums[i + k - 2] + 1
            ans[i] = -1 if notCoutinue else nums[i + k - 1]
        return ans
```

#### Java

```java
class Solution {
    public int[] resultsArray(int[] nums, int k) {
        int[] ans = new int[nums.length - k + 1];
        int notCoutinue = 0;
        for (int i = 1; i < k; i++) {
            if (nums[i] != nums[i - 1] + 1) {
                notCoutinue++;
            }
        }
        ans[0] = notCoutinue > 0 ? -1 : nums[k - 1];
        for (int i = 1; i + k <= nums.length; i++) {
            if (nums[i] != nums[i - 1] + 1) {
                notCoutinue--;
            }
            if (nums[i + k - 1] != nums[i + k - 2] + 1) {
                notCoutinue++;
            }
            ans[i] = notCoutinue > 0 ? -1 : nums[i + k - 1];
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
    notContinue := 0
    for i := 1; i < k; i++ {
        if nums[i] != nums[i - 1] + 1 {
            notContinue++
        }
    }
    if notContinue > 0 {
        ans[0] = -1
    } else {
        ans[0] = nums[k - 1]
    }
    for i := 1; i + k <= len(nums); i++ {
        if nums[i] != nums[i - 1] + 1 {
            notContinue--
        }
        if nums[i + k - 1] != nums[i + k - 2] + 1 {
            notContinue++
        }
        if notContinue > 0 {
            ans[i] = -1
        } else {
            ans[i] = nums[i + k - 1]
        }
    }
    return
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/11/07/LeetCode%203255.%E9%95%BF%E5%BA%A6%E4%B8%BAK%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84%E7%9A%84%E8%83%BD%E9%87%8F%E5%80%BCII/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/143591327](https://letmefly.blog.csdn.net/article/details/143591327)
