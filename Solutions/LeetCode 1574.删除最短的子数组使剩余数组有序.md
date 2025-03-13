---
title: 1574.删除最短的子数组使剩余数组有序
date: 2023-03-25 09:54:04
tags: [题解, LeetCode, 中等, 栈, 数组, 双指针, 二分查找, 单调栈]
categories: [题解, LeetCode]
---

# 【LetMeFly】1574.删除最短的子数组使剩余数组有序

力扣题目链接：[https://leetcode.cn/problems/shortest-subarray-to-be-removed-to-make-array-sorted/](https://leetcode.cn/problems/shortest-subarray-to-be-removed-to-make-array-sorted/)

<p>给你一个整数数组 <code>arr</code>&nbsp;，请你删除一个子数组（可以为空），使得 <code>arr</code>&nbsp;中剩下的元素是 <strong>非递减</strong> 的。</p>

<p>一个子数组指的是原数组中连续的一个子序列。</p>

<p>请你返回满足题目要求的最短子数组的长度。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,2,3,10,4,2,3,5]
<strong>输出：</strong>3
<strong>解释：</strong>我们需要删除的最短子数组是 [10,4,2] ，长度为 3 。剩余元素形成非递减数组 [1,2,3,3,5] 。
另一个正确的解为删除子数组 [3,10,4] 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [5,4,3,2,1]
<strong>输出：</strong>4
<strong>解释：</strong>由于数组是严格递减的，我们只能保留一个元素。所以我们需要删除长度为 4 的子数组，要么删除 [5,4,3,2]，要么删除 [4,3,2,1]。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,2,3]
<strong>输出：</strong>0
<strong>解释：</strong>数组已经是非递减的了，我们不需要删除任何元素。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>arr = [1]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10^5</code></li>
	<li><code>0 &lt;= arr[i] &lt;= 10^9</code></li>
</ul>


    
## 方法一：双指针

将数组分成三部分：$原数组 = 开头非递减部分 + 中间被删除部分 + 末尾非递减部分$，其中每一部分都可以为空

单独求一个```开头非递减部分```或```末尾非递减部分```都很好求，但问题是，```开头非递减部分```的最后一个元素要不大于```末尾非递减部分```的第一个元素。这可能就需要我们对开头或结尾的长度进行取舍。

方法也很简单，首先我们求出最长的```末尾非递减部分```，如果整个数组都是非递减的，直接返回0。否则，原数组必定可以被分成非空的三部分。

我们只需要使用再一个指针left从数组头部开始往后**在非递减区间**移动，从数组开头到left所指元素为```开头非递减部分```

如果$arr[left] > arr[right]$，就不断让right后移（减小```末尾非递减部分```以增大```开头非递减部分```），若right已经移出数组范围则不进行此判断

在left后移的过程中，不断判断答案的最小值即可

+ 时间复杂度$O(len(arr))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int right = arr.size() - 1;
        while (right - 1 >= 0 && arr[right - 1] <= arr[right]) {
            right--;
        }
        if (!right) {  // 移动到首个元素了
            return 0;
        }
        int ans = right;
        for (int left = 0; left < arr.size(); left++) {  // left和right肯定不会相遇
            while (right < arr.size() && arr[right] < arr[left]) {
                right++;
            }
            ans = min(ans, right - left - 1);
            // printf("left = %d, right = %d, ans = %d\n", left, right, ans);  //*************
            if (left + 1 < arr.size() && arr[left + 1] < arr[left]) {
                break;
            }
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def findLengthOfShortestSubarray(self, arr: List[int]) -> int:
        right = len(arr) - 1
        while right - 1 >= 0 and arr[right - 1] <= arr[right]:
            right -= 1
        if not right:
            return 0
        ans = right
        for left in range(len(arr)):  # left和right肯定不会相遇
            while right < len(arr) and arr[right] < arr[left]:
                right += 1
            ans = min(ans, right - left - 1)
            if left + 1 < len(arr) and arr[left + 1] < arr[left]:
                break
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/03/25/LeetCode%201574.%E5%88%A0%E9%99%A4%E6%9C%80%E7%9F%AD%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84%E4%BD%BF%E5%89%A9%E4%BD%99%E6%95%B0%E7%BB%84%E6%9C%89%E5%BA%8F/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129763510](https://letmefly.blog.csdn.net/article/details/129763510)
