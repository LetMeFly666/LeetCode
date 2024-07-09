---
title: 2970.统计移除递增子数组的数目 I
date: 2024-07-10 00:27:29
tags: [题解, LeetCode, 简单, 数组, 双指针, 二分查找, 枚举]
---

# 【LetMeFly】2970.统计移除递增子数组的数目 I：深夜刷题之——50的数据n^3暴力秒了

力扣题目链接：[https://leetcode.cn/problems/count-the-number-of-incremovable-subarrays-i/](https://leetcode.cn/problems/count-the-number-of-incremovable-subarrays-i/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的 <b>正</b>&nbsp;整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>如果 <code>nums</code>&nbsp;的一个子数组满足：移除这个子数组后剩余元素 <strong>严格递增</strong>&nbsp;，那么我们称这个子数组为 <strong>移除递增</strong>&nbsp;子数组。比方说，<code>[5, 3, 4, 6, 7]</code>&nbsp;中的 <code>[3, 4]</code>&nbsp;是一个移除递增子数组，因为移除该子数组后，<code>[5, 3, 4, 6, 7]</code>&nbsp;变为&nbsp;<code>[5, 6, 7]</code>&nbsp;，是严格递增的。</p>

<p>请你返回 <code>nums</code>&nbsp;中 <b>移除递增</b>&nbsp;子数组的总数目。</p>

<p><b>注意</b>&nbsp;，剩余元素为空的数组也视为是递增的。</p>

<p><strong>子数组</strong> 指的是一个数组中一段连续的元素序列。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,3,4]
<b>输出：</b>10
<b>解释：</b>10 个移除递增子数组分别为：[1], [2], [3], [4], [1,2], [2,3], [3,4], [1,2,3], [2,3,4] 和 [1,2,3,4]。移除任意一个子数组后，剩余元素都是递增的。注意，空数组不是移除递增子数组。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [6,5,7,8]
<b>输出：</b>7
<b>解释：</b>7<strong>&nbsp;</strong>个移除递增子数组分别为：[5], [6], [5,7], [6,5], [5,7,8], [6,5,7] 和 [6,5,7,8] 。
nums 中只有这 7 个移除递增子数组。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [8,7,6,6]
<b>输出：</b>3
<b>解释：</b>3 个移除递增子数组分别为：[8,7,6], [7,6,6] 和 [8,7,6,6] 。注意 [8,7] 不是移除递增子数组因为移除 [8,7] 后 nums 变为 [6,6] ，它不是严格递增的。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 50</code></li>
</ul>


    
## 解题方法：暴力模拟

写一个函数判断nums数组除了`[l, r]`的部分是否是严格递增的：

> 使用一个变量last记录上一个遍历到的数（初始值是“极小值”0），
>
> 遍历nums数组的每个元素：
>
> > 若当前下标`i`在`[l, r]`范围内，则跳过；
> >
> > 否则，若`nums[i] <= last`，返回`false`。
> >
> > 让`last = nums[i]`。
>
> 遍历结束未返回`false`则返回`true`。

这样，我们就可以从0到`len(nums) - 1`枚举左端点`l`，从`l`到`len(nums) - 1`枚举右边端点`r`，调用函数判断移除`[l, r]`区间后是否未严格递增数组，若是则累加到答案中。

+ 时间复杂度$O(len(nums)^3)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
private:
    bool isOk(vector<int>& nums, int l, int r) {
        int last = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (l <= i && i <= r) {
                continue;
            }
            if (nums[i] <= last) {
                return false;
            }
            last = nums[i];
        }
        return true;
    }
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int ans = 0;
        for (int l = 0; l < nums.size(); l++) {
            for (int r = l; r < nums.size(); r++) {
                ans += isOk(nums, l, r);
            }
        }
        return ans;
    }
};
```

#### Go

```go
package main

func isOk(nums []int, l int, r int) int {
    last := 0
    for i := 0; i < len(nums); i++ {
        if l <= i && i <= r {
            continue
        }
        if nums[i] <= last {
            return 0
        }
        last = nums[i]
    }
    return 1
}

func incremovableSubarrayCount(nums []int) int {
    ans := 0
    for l := 0; l < len(nums); l++ {
        for r := l; r < len(nums); r++ {
            ans += isOk(nums, l, r)
        }
    }
    return ans
}
```

#### Java

```java
class Solution {
    private boolean isOk(int[] nums, int l, int r) {
        int last = 0;
        for (int i = 0; i < nums.length; i++) {
            if (l <= i && i <= r) {
                continue;
            }
            if (nums[i] <= last) {
                return false;
            }
            last = nums[i];
        }
        return true;
    }

    public int incremovableSubarrayCount(int[] nums) {
        int ans = 0;
        for (int l = 0; l < nums.length; l++) {
            for (int r = l; r < nums.length; r++) {
                ans += isOk(nums, l, r) ? 1 : 0;
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
    def isOk(self, l: int, r: int) -> bool:
        last = 0
        for i in range(len(self.nums)):
            if l <= i <= r:
                continue
            if self.nums[i] <= last:
                return False
            last = self.nums[i]
        return True
    
    def incremovableSubarrayCount(self, nums: List[int]) -> int:
        self.nums = nums
        ans = 0
        for l in range(len(nums)):
            for r in range(l, len(nums)):
                ans += self.isOk(l, r)
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/07/10/LeetCode%202970.%E7%BB%9F%E8%AE%A1%E7%A7%BB%E9%99%A4%E9%80%92%E5%A2%9E%E5%AD%90%E6%95%B0%E7%BB%84%E7%9A%84%E6%95%B0%E7%9B%AEI/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/140310063](https://letmefly.blog.csdn.net/article/details/140310063)
