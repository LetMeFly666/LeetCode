---
title: 540.有序数组中的单一元素
date: 2024-11-10 17:53:24
tags: [题解, LeetCode, 中等, 数组, 二分查找, 位运算]
---

# 【LetMeFly】540.有序数组中的单一元素：二分查找（位运算优化）

力扣题目链接：[https://leetcode.cn/problems/single-element-in-a-sorted-array/](https://leetcode.cn/problems/single-element-in-a-sorted-array/)

<p>给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。</p>

<p>请你找出并返回只出现一次的那个数。</p>

<p>你设计的解决方案必须满足 <code>O(log n)</code> 时间复杂度和 <code>O(1)</code> 空间复杂度。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,1,2,3,3,4,4,8,8]
<strong>输出:</strong> 2
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums =  [3,3,7,7,10,11,11]
<strong>输出:</strong> 10
</pre>

<p>&nbsp;</p>

<p><meta charset="UTF-8" /></p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i]&nbsp;&lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法：二分查找

数组元素有序说明，我们可以直接随机选择一个下标，如果“当前下标为偶数且当前元素和下一个元素相同”或者“当前下标为奇数并且当前元素和上一个元素相同”，则说明从头开始到这个元素为止每个元素都是成对出现的。

因此我们可以直接进行二分操作：每次枚举mid并在$O(1)$的时间内得到$[0, mid]$中的每个元素是否都成对出现。若成对出现则说明答案在$mid + 1$及之后；否则说明答案在$mid$及之前。

位运算优化：

1. $\frac{l+r}2=(l+r)>>1$
2. 如果$mid$是奇数，那么应该判断$nums[mid]$是否和$nums[mid - 1]$相等；如果$mid$是偶数，那么应该判断$nums[mid]$是否和$nums[mid + 1]$相等。总之，我们只需要判断$nums[mid]$和$nums[mid \hat\ 1]$是否相等（其中$\hat\ $是异或符）

(・∀・(・∀・(・∀・*)

+ 时间复杂度$O(\log len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] == nums[mid ^ 1]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return nums[l];
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        while l < r:
            mid = (l + r) >> 1
            if nums[mid] == nums[mid ^ 1]:
                l = mid + 1
            else:
                r = mid
        return nums[l]
```

#### Java

```java
class Solution {
    public int singleNonDuplicate(int[] nums) {
        int l = 0, r = nums.length - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] == nums[mid ^ 1]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return nums[l];
    }
}
```

#### Go

```go
package main

func singleNonDuplicate(nums []int) int {
    l, r := 0, len(nums) - 1
    for l < r {
        mid := (l + r) >> 1
        if nums[mid] == nums[mid + 1] {
            l = mid + 1
        } else {
            r = mid
        }
    }
    return nums[l]
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/11/10/LeetCode%200540.%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E5%8D%95%E4%B8%80%E5%85%83%E7%B4%A0/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/143663976](https://letmefly.blog.csdn.net/article/details/143663976)

emm，某事还是很累，这篇题解写地晕哩糊涂的。
