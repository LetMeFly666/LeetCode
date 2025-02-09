---
title: 80.删除有序数组中的重复项 II：双指针 - C++/Java5 行版
date: 2025-02-09 09:08:46
tags: [题解, LeetCode, 中等, 数组, 双指针]
---

# 【LetMeFly】80.删除有序数组中的重复项 II：双指针 - C++/Java5 行版

力扣题目链接：[https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/](https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/)

<p>给你一个有序数组 <code>nums</code> ，请你<strong><a href="http://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95" target="_blank"> 原地</a></strong> 删除重复出现的元素，使得出现次数超过两次的元素<strong>只出现两次</strong> ，返回删除后数组的新长度。</p>

<p>不要使用额外的数组空间，你必须在 <strong><a href="https://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95" target="_blank">原地 </a>修改输入数组 </strong>并在使用 O(1) 额外空间的条件下完成。</p>

<p>&nbsp;</p>

<p><strong>说明：</strong></p>

<p>为什么返回数值是整数，但输出的答案是数组呢？</p>

<p>请注意，输入数组是以<strong>「引用」</strong>方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。</p>

<p>你可以想象内部操作如下:</p>

<pre>
// <strong>nums</strong> 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
int len = removeDuplicates(nums);

// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中<strong> 该长度范围内</strong> 的所有元素。
for (int i = 0; i &lt; len; i++) {
&nbsp; &nbsp; print(nums[i]);
}
</pre>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,1,2,2,3]
<strong>输出：</strong>5, nums = [1,1,2,2,3]
<strong>解释：</strong>函数应返回新长度 length = <strong><code>5</code></strong>, 并且原数组的前五个元素被修改为 <strong><code>1, 1, 2, 2, 3</code></strong>。 不需要考虑数组中超出新长度后面的元素。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,0,1,1,1,1,2,3,3]
<strong>输出：</strong>7, nums = [0,0,1,1,2,3,3]
<strong>解释：</strong>函数应返回新长度 length = <strong><code>7</code></strong>, 并且原数组的前七个元素被修改为&nbsp;<strong><code>0, 0, 1, 1, 2, 3, 3</code></strong>。不需要考虑数组中超出新长度后面的元素。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>nums</code> 已按升序排列</li>
</ul>


    
## 解题方法一：快慢指针

使用一个慢指针指向数组中已经合法的元素（初始值为1，因为前两个元素必合法），使用一个快指针指向当前遍历到的元素。

快指针从下标`2`开始遍历，如果快指针指向元素和慢指针指向元素的前一个元素不同，则快指针指向元素可以合法地加入数组（慢指针右移一位，快指针元素放到慢指针位置）。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-02-09 08:44:41
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-09 08:48:30
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 1;
        for (int fast = 2; fast < nums.size(); fast++) {
            if (nums[fast] != nums[slow - 1]) {
                nums[++slow] = nums[fast];
            }
        }
        return min((int)nums.size(), slow + 1);
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-02-09 08:53:38
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-09 08:55:23
'''
from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        slow = 1
        for fast in range(2, len(nums)):
            if nums[fast] != nums[slow - 1]:
                slow += 1
                nums[slow] = nums[fast]
        return min(len(nums), slow + 1)
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-02-09 08:53:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-09 08:58:07
 */
class Solution {
    public int removeDuplicates(int[] nums) {
        int slow = 1;
        for (int fast = 2; fast < nums.length; fast++) {
            if (nums[fast] != nums[slow - 1]) {
                nums[++slow] = nums[fast];
            }
        }
        return Math.min(slow + 1, nums.length);
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-02-09 08:53:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-09 09:00:09
 */
package main

func removeDuplicates(nums []int) int {
    slow := 1
    for fast := 2; fast < len(nums); fast++ {
        if nums[fast] != nums[slow - 1] {
            slow++
            nums[slow] = nums[fast]
        }
    }
    return min(slow + 1, len(nums))
}
```

## 解题方法二：易想版本

> 来[自](https://github.com/LetMeFly666/LeetCode/blob/64231493342ec7c9a18147c5f32d4e6211df7e33/Codes/0080-remove-duplicates-from-sorted-array-ii.cpp)2022.6.19，当时就想[写题解](https://github.com/LetMeFly666/LeetCode/blob/64231493342ec7c9a18147c5f32d4e6211df7e33/Codes/0080-remove-duplicates-from-sorted-array-ii.cpp#L11)了。

如果[方法一](#解题方法一快慢指针)难想怎么办？很简单，使用两个指针指向“相同连续元素”的始末位置总可以了吧。

每次得到一种元素的始末位置后，就放置`min(2, 这种元素个数)`个这种元素到“合法数组”中就好了。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### [AC](https://github.com/LetMeFly666/LeetCode/blob/64231493342ec7c9a18147c5f32d4e6211df7e33/Codes/0080-remove-duplicates-from-sorted-array-ii.cpp#L1-L6)[代码](https://github.com/LetMeFly666/LeetCode/blob/64231493342ec7c9a18147c5f32d4e6211df7e33/Codes/0080-remove-duplicates-from-sorted-array-ii.cpp#L42-L58)

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2022-06-19 09:51:38
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-19 10:31:22
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 0;
        int l = 0, r = 1;  // [l, r)相同
        nums.push_back(1e5);
        for (; r < nums.size(); r++) {
            if (nums[r] != nums[l]) {
                for (int i = 0; i < min(2, r - l); i++) {
                    nums[cnt++] = nums[r - 1];
                }
                l = r;
            }
        }
        return cnt;
    }
};
```

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/145528267)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/02/09/LeetCode%200080.%E5%88%A0%E9%99%A4%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E9%87%8D%E5%A4%8D%E9%A1%B9II/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
>
> Tisfy：[https://blog.letmefly.xyz/2025/02/09/LeetCode 0080.删除有序数组中的重复项II](https://blog.letmefly.xyz/2025/02/09/LeetCode%200080.%E5%88%A0%E9%99%A4%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E9%87%8D%E5%A4%8D%E9%A1%B9II/)
