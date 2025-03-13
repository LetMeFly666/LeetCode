---
title: 2239.找到最接近 0 的数字：遍历
date: 2025-01-20 16:02:06
tags: [题解, LeetCode, 简单, 数组]
categories: [题解, LeetCode]
---

# 【LetMeFly】2239.找到最接近 0 的数字：遍历

力扣题目链接：[https://leetcode.cn/problems/find-closest-number-to-zero/](https://leetcode.cn/problems/find-closest-number-to-zero/)

<p>给你一个长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;，请你返回 <code>nums</code>&nbsp;中最 <strong>接近</strong>&nbsp;<code>0</code>&nbsp;的数字。如果有多个答案，请你返回它们中的 <strong>最大值</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [-4,-2,1,4,8]
<b>输出：</b>1
<strong>解释：</strong>
-4 到 0 的距离为 |-4| = 4 。
-2 到 0 的距离为 |-2| = 2 。
1 到 0 的距离为 |1| = 1 。
4 到 0 的距离为 |4| = 4 。
8 到 0 的距离为 |8| = 8 。
所以，数组中距离 0 最近的数字为 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [2,-1,1]
<b>输出：</b>1
<b>解释：</b>1 和 -1 都是距离 0 最近的数字，所以返回较大值 1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法：遍历

使用变量`ans`记录当前的最优答案，初始值为`nums[0]`。

遍历`nums`数组，对于其中元素`t`，若以下则说明`t`比`ans`更优，更新`ans`为`t`：

1. `abs(t) < abs(ans)`
2. `abs(t) == abs(ans)`且`ans < 0`

最终返回`ans`。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-01-20 13:25:25
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-20 13:29:40
 */
class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans = nums[0];
        for (int t : nums) {
            if (abs(t) < abs(ans) || abs(t) == abs(ans) && ans < 0) {
                ans = t;
            }
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-01-20 13:31:49
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-20 13:32:00
'''
from typing import List

class Solution:
    def findClosestNumber(self, nums: List[int]) -> int:
        ans = nums[0]
        for t in nums:
            if abs(t) < abs(ans) or abs(t) == abs(ans) and ans < 0:
                ans = t
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-01-20 13:33:12
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-20 13:33:16
 */
class Solution {
    public int findClosestNumber(int[] nums) {
        int ans = nums[0];
        for (int t : nums) {
            if (Math.abs(t) < Math.abs(ans) || Math.abs(t) == Math.abs(ans) && ans < 0) {
                ans = t;
            }
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-01-20 13:34:23
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-20 16:00:01
 */
package main

func abs(a int) int {
    if a < 0 {
        return -a
    }
    return a
}

func findClosestNumber(nums []int) int {
    ans := nums[0]
    for _, t := range nums {
        if abs(t) < abs(ans) || abs(t) == abs(ans) && ans < 0 {
            ans = t
        }
    }
    return ans
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/01/20/LeetCode%202239.%E6%89%BE%E5%88%B0%E6%9C%80%E6%8E%A5%E8%BF%910%E7%9A%84%E6%95%B0%E5%AD%97/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/145264674](https://letmefly.blog.csdn.net/article/details/145264674)
