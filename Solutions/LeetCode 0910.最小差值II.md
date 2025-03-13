---
title: 910.最小差值 II
date: 2024-10-21 23:16:09
tags: [题解, LeetCode, 中等, 贪心, 数组, 数学, 排序, 枚举, 思维]
categories: [题解, LeetCode]
---

# 【LetMeFly】910.最小差值 II：贪心（排序）-小数大数分界线枚举（思考过程详解）

力扣题目链接：[https://leetcode.cn/problems/smallest-range-ii/](https://leetcode.cn/problems/smallest-range-ii/)

<p>给你一个整数数组 <code>nums</code>，和一个整数&nbsp;<code>k</code> 。</p>

<p>对于每个下标 <code>i</code>（<code>0 &lt;= i &lt; nums.length</code>），将 <code>nums[i]</code> 变成<strong> </strong> <code>nums[i] + k</code> 或 <code>nums[i] - k</code> 。</p>

<p><code>nums</code> 的 <strong>分数</strong> 是 <code>nums</code> 中最大元素和最小元素的差值。</p>

<p>在更改每个下标对应的值之后，返回 <code>nums</code> 的最小 <strong>分数</strong> 。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1], k = 0
<strong>输出：</strong>0
<strong>解释：</strong>分数 = max(nums) - min(nums) = 1 - 1 = 0 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,10], k = 2
<strong>输出：</strong>6
<strong>解释：</strong>将数组变为 [2, 8] 。分数 = max(nums) - min(nums) = 8 - 2 = 6 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,3,6], k = 3
<strong>输出：</strong>3
<strong>解释：</strong>将数组变为 [4, 6, 3] 。分数 = max(nums) - min(nums) = 6 - 3 = 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>4</sup></code></li>
</ul>


    
## 解题方法：贪心（排序）

这次每个数必须得变，考虑数组中最小的数$m$和最大$M$的数：

> + 如果$m$和$M$同时变大/同时变小，则差值$diff=M-m$；
> + 如果$m$变小$M$变大，则差值变大$diff=M-m+2k\geq M-m$；
> + 如果$m$变大$M$变小，则差值为$diff=abs((M-k)-(m+k))=abs(M-m-2k)$。

如果$m$很小$M$很大，那么那么$m$变$M$变小的话差值会变小；如果$m$和$M$相差本来不大，那么$m$变大而$M$变小的话$diff$反而可能会变大。怎么办呢？

> 其实不难发现，除了最小的数和最大的数，其他较小的数和较大的数也是这样的关系。
>
> 我们可以先对数组排个序，然后枚举“小数大数的分界线”。分界线左边的数视为“小数”并且全部$+k$，分界线右边的数视为“大数”并且全部$-k$。
>
> 在所有的方案中，差值最小的那个即为所求。

对于一个方案，如何快速计算$diff$呢？

> 假设$nums[0]$到$nums[i]$每个数$+k$，$nums[i + 1]$到$nums[n - 1]$每个数$-k$，那么：
>
> 数组中最大的数为$nums[i] + k$或者$nums[n - 1] - k$，最小的数为$nums[i + 1] - k$或$nums[0] + k$。
>
> 因此$diff=\max(nums[i] + k, nums[len(nums) - 1] - k) - \min(nums[i + 1] - k, nums[0] + k)$。

+ 时间复杂度$O(n\log n)$，其中$n=len(nums)$
+ 空间复杂度$O(\log n)$，时空复杂度的开销主要来自排序

### AC代码

#### C++

```cpp
class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = nums.back() - nums[0];
        for (int i = 0; i < nums.size() - 1; i++) {  // nums[0..i]变大 nums[i+1..n-1]变小
            ans = min(ans, max(nums[i] + k, nums.back() - k) - min(nums[i + 1] - k, nums[0] + k));
        }
        return ans;
    }
};
```

#### Go

```go
package main

import "slices"

func smallestRangeII(nums []int, k int) int {
    slices.Sort(nums)
    ans := nums[len(nums) - 1] - nums[0]
    for i := 0; i < len(nums) - 1; i++ {
        ans = min(ans, max(nums[i] + k, nums[len(nums) - 1] - k) - min(nums[i + 1] - k, nums[0] + k))
    }
    return ans
}
```

#### Java

```java
import java.util.Arrays;

class Solution {
    public int smallestRangeII(int[] nums, int k) {
        Arrays.sort(nums);
        int ans = nums[nums.length - 1] - nums[0];
        for (int i = 0; i < nums.length - 1; i++) {
            ans = Math.min(ans, Math.max(nums[i] + k, nums[nums.length - 1] - k) - Math.min(nums[i + 1] - k, nums[0] + k));
        }
        return ans;
    }
}
```

#### Python

```python
from typing import List

class Solution:
    def smallestRangeII(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans = nums[-1] - nums[0]
        for i in range(len(nums) - 1):
            ans = min(ans, max(nums[i] + k, nums[-1] - k) - min(nums[i + 1] - k, nums[0] + k))
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/10/21/LeetCode%200910.%E6%9C%80%E5%B0%8F%E5%B7%AE%E5%80%BCII/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/143136177](https://letmefly.blog.csdn.net/article/details/143136177)
