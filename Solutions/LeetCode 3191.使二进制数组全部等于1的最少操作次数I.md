---
title: 3191.使二进制数组全部等于 1 的最少操作次数 I
date: 2024-10-18 23:09:14
tags: [题解, LeetCode, 中等, 位运算, 队列, 数组, 前缀和, 滑动窗口, 模拟]
---

# 【LetMeFly】3191.使二进制数组全部等于 1 的最少操作次数 I：模拟（说是最小操作次数，其实不重复翻转就是了）

力扣题目链接：[https://leetcode.cn/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/](https://leetcode.cn/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/)

<p>给你一个二进制数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>你可以对数组执行以下操作 <strong>任意</strong>&nbsp;次（也可以 0 次）：</p>

<ul>
	<li>选择数组中 <strong>任意连续</strong>&nbsp;3 个元素，并将它们 <strong>全部反转</strong>&nbsp;。</li>
</ul>

<p><strong>反转</strong>&nbsp;一个元素指的是将它的值从 0 变 1 ，或者从 1 变 0 。</p>

<p>请你返回将 <code>nums</code>&nbsp;中所有元素变为 1 的 <strong>最少</strong>&nbsp;操作次数。如果无法全部变成 1 ，返回 -1 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [0,1,1,1,0,0]</span></p>

<p><span class="example-io"><b>输出：</b>3</span></p>

<p><strong>解释：</strong><br />
我们可以执行以下操作：</p>

<ul>
	<li>选择下标为 0 ，1 和 2 的元素并反转，得到&nbsp;<code>nums = [<u><strong>1</strong></u>,<u><strong>0</strong></u>,<u><strong>0</strong></u>,1,0,0]</code>&nbsp;。</li>
	<li>选择下标为 1 ，2 和 3 的元素并反转，得到&nbsp;<code>nums = [1,<u><strong>1</strong></u>,<u><strong>1</strong></u>,<strong><u>0</u></strong>,0,0]</code>&nbsp;。</li>
	<li>选择下标为 3 ，4 和 5 的元素并反转，得到&nbsp;<code>nums = [1,1,1,<strong><u>1</u></strong>,<u><strong>1</strong></u>,<u><strong>1</strong></u>]</code>&nbsp;。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [0,1,1,1]</span></p>

<p><span class="example-io"><b>输出：</b>-1</span></p>

<p><strong>解释：</strong><br />
无法将所有元素都变为 1 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1</code></li>
</ul>

## 解题方法：模拟（其实是很不严格的证明）

从前到后遍历数组（遍历到倒数第三个元素），遇见$0$则从当前位置开始连续翻转3个元素。

遍历结束后，若最后两个元素都是$1$，则返回总翻转次数；否则则返回$-1$。

**为何这样正常操作就是“最小操作次数”：**

因为这样不会把“同样的三个元素”翻转多次（最小性证明），同时又不得不翻转（必要性证明）。

因为是从前向后遍历的，遇到零的话如果往前翻(前面全是1)，则前面的1变成0后还需要额外次数再次翻转回1。

### 时空复杂度分析

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
011100
100100
100011
111111


011100
100100
111000
111111

0111
1001
1110
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (!nums[i]) {
                ans++;
                // nums[i] ^= 1;  // 这个修改与否都无所谓了
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
            }
        }
        return nums[nums.size() - 1] & nums[nums.size() - 2] ? ans : -1;
    }
};
```

#### Go

```go
package main

func minOperations(nums []int) int {
    ans := 0
    for i := 0; i < len(nums) - 2; i++ {
        if nums[i] == 0 {
            ans++
            nums[i + 1] ^= 1
            nums[i + 2] ^= 1
        }
    }
    if nums[len(nums) - 1] & nums[len(nums) - 2] == 1 {
        return ans
    } else {
        return -1
    }
}
```

#### Java

```java
class Solution {
    public int minOperations(int[] nums) {
        int ans = 0;
        for (int i = 0; i < nums.length - 2; i++) {
            if (nums[i] == 0) {
                ans++;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
            }
        }
        return (nums[nums.length - 1] & nums[nums.length - 2]) == 1 ? ans : -1;
    }
}
```

#### Python

```python
from typing import List

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        ans = 0
        for i in range(len(nums) - 2):
            if not nums[i]:
                ans += 1
                nums[i + 1] ^= 1
                nums[i + 2] ^= 1
        return ans if nums[-1] & nums[-2] else -1

```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/10/18/LeetCode%203191.%E4%BD%BF%E4%BA%8C%E8%BF%9B%E5%88%B6%E6%95%B0%E7%BB%84%E5%85%A8%E9%83%A8%E7%AD%89%E4%BA%8E1%E7%9A%84%E6%9C%80%E5%B0%91%E6%93%8D%E4%BD%9C%E6%AC%A1%E6%95%B0I/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/143064645](https://letmefly.blog.csdn.net/article/details/143064645)
