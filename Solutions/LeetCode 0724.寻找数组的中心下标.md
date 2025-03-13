---
title: 724.寻找数组的中心下标
date: 2024-07-08 13:22:58
tags: [题解, LeetCode, 简单, 数组, 前缀和]
categories: [题解, LeetCode]
---

# 【LetMeFly】724.寻找数组的中心下标：前缀和（时空复杂度O(n)+O(1)）

力扣题目链接：[https://leetcode.cn/problems/find-pivot-index/](https://leetcode.cn/problems/find-pivot-index/)

<p>给你一个整数数组&nbsp;<code>nums</code> ，请计算数组的 <strong>中心下标 </strong>。</p>

<p>数组<strong> 中心下标</strong><strong> </strong>是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。</p>

<p>如果中心下标位于数组最左端，那么左侧数之和视为 <code>0</code> ，因为在下标的左侧不存在元素。这一点对于中心下标位于数组最右端同样适用。</p>

<p>如果数组有多个中心下标，应该返回 <strong>最靠近左边</strong> 的那一个。如果数组不存在中心下标，返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1, 7, 3, 6, 5, 6]
<strong>输出：</strong>3
<strong>解释：</strong>
中心下标是 3 。
左侧数之和 sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11 ，
右侧数之和 sum = nums[4] + nums[5] = 5 + 6 = 11 ，二者相等。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1, 2, 3]
<strong>输出：</strong>-1
<strong>解释：</strong>
数组中不存在满足此条件的中心下标。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [2, 1, -1]
<strong>输出：</strong>0
<strong>解释：</strong>
中心下标是 0 。
左侧数之和 sum = 0 ，（下标 0 左侧不存在元素），
右侧数之和 sum = nums[1] + nums[2] = 1 + -1 = 0 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-1000 &lt;= nums[i] &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>注意：</strong>本题与主站 1991 题相同：<a href="https://leetcode-cn.com/problems/find-the-middle-index-in-array/" target="_blank">https://leetcode-cn.com/problems/find-the-middle-index-in-array/</a></p>


    
## 解题方法：前缀和

“i是中心下标”等价于“i左边的元素之和 * 2 = 数组元素元素之和 - nums[i]”。

因此我们可以先遍历一遍数组得到数组之和，之后从第一个元素开始向后遍历并累加得到（i左侧元素之和），这样就能判断当前遍历到的i是不是“中心下标”了。

若遍历结束后未找到中心下标，则返回-1。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int nowSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (sum - nums[i] == nowSum * 2) {
                return i;
            }
            nowSum += nums[i];
        }
        return -1;
    }
};
```

#### Go

```go
package main

func pivotIndex(nums []int) int {
    sum := 0
    for _, t := range nums {
        sum += t
    }
    nowSum := 0
    for i, t := range nums {
        if sum - t == nowSum * 2 {
            return i
        }
        nowSum += t
    }
    return -1
}
```

#### Python

```python
from typing import List

class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        sum_ =sum(nums)
        nowSum = 0
        for i in range(len(nums)):
            if sum_ - nums[i] == nowSum * 2:
                return i
            nowSum += nums[i]
        return -1
```

#### Java

```java
class Solution {
    public int pivotIndex(int[] nums) {
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
        }
        int nowSum = 0;
        for (int i = 0; i < nums.length; i++) {
            if (sum - nums[i] == nowSum * 2) {
                return i;
            }
            nowSum += nums[i];
        }
        return -1;
    }
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/07/08/LeetCode%200724.%E5%AF%BB%E6%89%BE%E6%95%B0%E7%BB%84%E7%9A%84%E4%B8%AD%E5%BF%83%E4%B8%8B%E6%A0%87/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/140266165](https://letmefly.blog.csdn.net/article/details/140266165)
