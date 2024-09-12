---
title: 2576.求出最多标记下标
date: 2024-09-12 21:42:46
tags: [题解, LeetCode, 中等, 贪心, 数组, 双指针, 二分查找, 排序]
---

# 【LetMeFly】2576.求出最多标记下标：排序+双指针

力扣题目链接：[https://leetcode.cn/problems/find-the-maximum-number-of-marked-indices/](https://leetcode.cn/problems/find-the-maximum-number-of-marked-indices/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>一开始，所有下标都没有被标记。你可以执行以下操作任意次：</p>

<ul>
	<li>选择两个 <strong>互不相同且未标记</strong>&nbsp;的下标&nbsp;<code>i</code> 和&nbsp;<code>j</code>&nbsp;，满足&nbsp;<code>2 * nums[i] &lt;= nums[j]</code>&nbsp;，标记下标&nbsp;<code>i</code> 和&nbsp;<code>j</code>&nbsp;。</li>
</ul>

<p>请你执行上述操作任意次，返回<em>&nbsp;</em><code>nums</code>&nbsp;中最多可以标记的下标数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [3,5,2,4]
<b>输出：</b>2
<strong>解释：</strong>第一次操作中，选择 i = 2 和 j = 1 ，操作可以执行的原因是 2 * nums[2] &lt;= nums[1] ，标记下标 2 和 1 。
没有其他更多可执行的操作，所以答案为 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [9,2,5,4]
<b>输出：</b>4
<strong>解释：</strong>第一次操作中，选择 i = 3 和 j = 0 ，操作可以执行的原因是 2 * nums[3] &lt;= nums[0] ，标记下标 3 和 0 。
第二次操作中，选择 i = 1 和 j = 2 ，操作可以执行的原因是 2 * nums[1] &lt;= nums[2] ，标记下标 1 和 2 。
没有其他更多可执行的操作，所以答案为 4 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [7,6,8]
<b>输出：</b>0
<strong>解释：</strong>没有任何可以执行的操作，所以答案为 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：排序+双指针

最多能凑够$\lfloor \frac{len(nums)}{2}\rfloor$对，因此可以先对原始数组排个序，$r$指针从下标$\lfloor \frac{len(nums)+1}{2}\rfloor$的元素开始向后遍历，$l$指针默认指向下标$0$。

如果$nums[l] \times 2\leq nums[r]$，则把$nums[l]$和$nums[r]$配成一对（$ans+=2,l++,r++$）；否则，$l$不变$r++$。

**问：** 为何不能从最小的元素开始二分查找大于等于它的二倍的第一个数？

**答：** 反例如下：`[2, 4, 5, 9]`。若`2`和`4`配成一对，则`5`和`9`不能再配对；而若`2`和`5`配对，则`4`和`9`还能配对。这也就是说为什么要从后半数组`5`开始找。

+ 时间复杂度$O(n\log n)$，其中$n=len(nums)$
+ 空间复杂度$O(\log n)$

时空复杂度主要来自排序。

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int l = 0, r = (nums.size() + 1) / 2; r < nums.size(); r++) {
            if (nums[l] * 2 <= nums[r]) {
                ans += 2, l++;
            }
        }
        return ans;
    }
};
```

#### Go

```go
package main
import "sort"

func maxNumOfMarkedIndices(nums []int) int {
    sort.Ints(nums)
    ans := 0
    for l, r := 0, (len(nums) + 1) / 2; r < len(nums); r++ {
        if nums[l] * 2 <= nums[r] {
            ans += 2
            l++
        }
    }
    return ans
}
```

#### Java

```java
import java.util.Arrays;

class Solution {
    public int maxNumOfMarkedIndices(int[] nums) {
        Arrays.sort(nums);
        int ans = 0;
        for (int i = 0, r = (nums.length + 1) / 2; r < nums.length; r++) {
            if (nums[i] * 2 <= nums[r]) {
                ans += 2;
                i++;
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
    def maxNumOfMarkedIndices(self, nums: List[int]) -> int:
        nums.sort()
        ans = 0
        l, r = 0, (len(nums) + 1) // 2
        while r < len(nums):
            if nums[l] * 2 <= nums[r]:
                ans += 2
                l += 1
            r += 1
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/09/12/LeetCode%202576.%E6%B1%82%E5%87%BA%E6%9C%80%E5%A4%9A%E6%A0%87%E8%AE%B0%E4%B8%8B%E6%A0%87/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/142188013](https://letmefly.blog.csdn.net/article/details/142188013)
