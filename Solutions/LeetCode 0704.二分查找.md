---
title: 704.二分查找
date: 2023-10-06 13:13:22
tags: [题解, LeetCode, 简单, 数组, 二分查找, 二分]
categories: [题解, LeetCode]
---

# 【LetMeFly】704.二分查找

力扣题目链接：[https://leetcode.cn/problems/binary-search/](https://leetcode.cn/problems/binary-search/)

<p>给定一个&nbsp;<code>n</code>&nbsp;个元素有序的（升序）整型数组&nbsp;<code>nums</code> 和一个目标值&nbsp;<code>target</code> &nbsp;，写一个函数搜索&nbsp;<code>nums</code>&nbsp;中的 <code>target</code>，如果目标值存在返回下标，否则返回 <code>-1</code>。</p>

<p><br>
<strong>示例 1:</strong></p>

<pre><strong>输入:</strong> <code>nums</code> = [-1,0,3,5,9,12], <code>target</code> = 9
<strong>输出:</strong> 4
<strong>解释:</strong> 9 出现在 <code>nums</code> 中并且下标为 4
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> <code>nums</code> = [-1,0,3,5,9,12], <code>target</code> = 2
<strong>输出:</strong> -1
<strong>解释:</strong> 2 不存在 <code>nums</code> 中因此返回 -1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li>你可以假设 <code>nums</code>&nbsp;中的所有元素是不重复的。</li>
	<li><code>n</code>&nbsp;将在&nbsp;<code>[1, 10000]</code>之间。</li>
	<li><code>nums</code>&nbsp;的每个元素都将在&nbsp;<code>[-9999, 9999]</code>之间。</li>
</ol>


    
## 方法一：二分查找

二分查找主要有两种写法：对于区间$l$到$r$，采用```闭区间```还是```左闭右开```区间。

关于二分查找过程中：
   + ```while (l < r)```还是```while (l <= r)```的关键是：保证```while```过程中区间不空
   + ```r = mid```还是```r = mid - 1```的关键是：判定过的元素坚决不留在区间内

以```C++ lower_bound```等左闭右开的二分方法为例：

> 数组$nums$的有效范围是$[0, n - 1]$，则初始值令$l = 0, r = n$（左闭右开）。
>
> 在循环过程中，保证区间不空，则需要$r > l$（因为如果$l$等于$r$，则因左闭右开区间已经空了）
>
> 若$nums[mid] > target$，则$mid$已经被排除了，下次的区间中不应包含$mid$，因此令$r = mid$（右边是开区间，取不到）
>
> ```cpp
> while (l < r) {  // [l, r)不空
>     int mid = (l + r) / 2;
>     if (nums[mid] > target) r = mid;  // 新区间[l, mid)
>     if (nums[mid] < target) l = mid + 1;  // 新区间[mid + 1, r)
>     if (nums[mid] == target) return mid;
> }
> ```

同理，若以闭区间的方法来写：

> 初始值$l = 0, r = n - 1$
>
> ```cpp
> while (l <= r) {  // [l, r]不空
>     int mid = (l + r) / 2;
>     if (nums[mid] > target) r = mid - 1;  // 新区间[l, mid - 1]
>     if (nums[mid] < target) l = mid + 1;  // 新区间[mid + 1, r]
>     if (nums[mid] == target) return mid;
> }
> ```

+ 时间复杂度$O(\log len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

左闭右开：

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] > target) {
                r = mid;
            }
            else if (nums[mid] < target) {
                l = mid + 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
};
```
闭区间：

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
        int mid = (l + r) / 2;
        if (nums[mid] > target) r = mid - 1;
        if (nums[mid] < target) l = mid + 1;
        if (nums[mid] == target) return mid;
    }
        return -1;
    }
};
```

#### Python

左闭右开：

```python
# from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums)
        while l < r:
            mid = (l + r) // 2
            if nums[mid] > target:
                r = mid
            elif nums[mid] < target:
                l = mid + 1
            else:
                return mid
        return -1
```

闭区间：

```python
# from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = (l + r) // 2
            if nums[mid] > target:
                r = mid - 1
            elif nums[mid] == target:
                return mid
            else:
                l = mid + 1
        return -1
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/10/06/LeetCode%200704.%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/133610614](https://letmefly.blog.csdn.net/article/details/133610614)
