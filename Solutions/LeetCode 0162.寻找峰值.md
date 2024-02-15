---
title: 162.寻找峰值
date: 2023-12-18 14:27:17
tags: [题解, LeetCode, 中等, 数组, 二分查找, 二分]
---

# 【LetMeFly】162.寻找峰值：二分查找

力扣题目链接：[https://leetcode.cn/problems/find-peak-element/](https://leetcode.cn/problems/find-peak-element/)

<p>峰值元素是指其值严格大于左右相邻值的元素。</p>

<p>给你一个整数数组&nbsp;<code>nums</code>，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 <strong>任何一个峰值</strong> 所在位置即可。</p>

<p>你可以假设&nbsp;<code>nums[-1] = nums[n] = -∞</code> 。</p>

<p>你必须实现时间复杂度为 <code>O(log n)</code><em> </em>的算法来解决此问题。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = <code>[1,2,3,1]</code>
<strong>输出：</strong>2
<strong>解释：</strong>3 是峰值元素，你的函数应该返回其索引 2。</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入：</strong>nums = <code>[</code>1,2,1,3,5,6,4]
<strong>输出：</strong>1 或 5 
<strong>解释：</strong>你的函数可以返回索引 1，其峰值元素为 2；
&nbsp;    或者返回索引 5， 其峰值元素为 6。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li>对于所有有效的 <code>i</code> 都有 <code>nums[i] != nums[i + 1]</code></li>
</ul>


    
## 方法一：遍历

直接无脑遍历即可。

## 方法二：二分查找

根据题目条件不难看出：相邻两个元素不等（数据范围课看出）、数组越界处的值相当于无限小。因此答案一定存在：加上数组外侧两元素，从最左到最右，元素先增后减（不可能一直增），第一个“增后减”的元素即为第一个“波峰”。

这怎么用二分解决呢？用二分查找的思路，对于元素$nums[mid]$：

   + 若左右相邻元素都小于它，则直接返回
   + 若左边元素小于它，则这个元素右边一定存在“波峰”（将[mid + 1, len(nums)]看成新的数组）
   + 若右边元素小于它，则这个元素左边一定存在“波峰”（将[-1, mid - 1]看成新的数组）
   + 若左右相邻元素都大于它，则左右都一定存在“波峰”（可以和第三条一同考虑）

+ 时间复杂度$O(\log len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = (l + r) >> 1;
            if ((mid - 1 < 0 || nums[mid - 1] < nums[mid]) && (mid + 1 == nums.size() || nums[mid + 1] < nums[mid])) {
                return mid;
            }
            if (mid - 1 < 0 || nums[mid - 1] < nums[mid]) {  // 左边小 说明右边大
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        return -1;  // FakeReturn
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        l, r = 0, len(nums)
        while l < r:
            mid = (l + r) >> 1
            if (mid - 1 < 0 or nums[mid - 1] < nums[mid]) and (mid + 1 == len(nums) or nums[mid + 1] < nums[mid]):
                return mid
            if mid - 1 < 0 or nums[mid - 1] < nums[mid]:
                l = mid + 1
            else:
                r = mid
        return -1
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/12/18/LeetCode%200162.%E5%AF%BB%E6%89%BE%E5%B3%B0%E5%80%BC/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135067872](https://letmefly.blog.csdn.net/article/details/135067872)
