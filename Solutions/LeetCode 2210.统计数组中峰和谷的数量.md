---
title: 2210.统计数组中峰和谷的数量：一次遍历(记录上一个不同的数)
date: 2025-07-28 22:28:53
tags: [题解, LeetCode, 简单, 数组, 遍历, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】2210.统计数组中峰和谷的数量：一次遍历(记录上一个不同的数)

力扣题目链接：[https://leetcode.cn/problems/count-hills-and-valleys-in-an-array/](https://leetcode.cn/problems/count-hills-and-valleys-in-an-array/)

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 。如果两侧距 <code>i</code> 最近的不相等邻居的值均小于 <code>nums[i]</code> ，则下标 <code>i</code> 是 <code>nums</code> 中，某个峰的一部分。类似地，如果两侧距 <code>i</code> 最近的不相等邻居的值均大于 <code>nums[i]</code> ，则下标 <code>i</code> 是 <code>nums</code> 中某个谷的一部分。对于相邻下标&nbsp;<code>i</code> 和 <code>j</code> ，如果&nbsp;<code>nums[i] == nums[j]</code> ， 则认为这两下标属于 <strong>同一个</strong> 峰或谷。</p>

<p>注意，要使某个下标所做峰或谷的一部分，那么它左右两侧必须 <strong>都</strong> 存在不相等邻居。</p>

<p>返回 <code>nums</code> 中峰和谷的数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,4,1,1,6,5]
<strong>输出：</strong>3
<strong>解释：</strong>
在下标 0 ：由于 2 的左侧不存在不相等邻居，所以下标 0 既不是峰也不是谷。
在下标 1 ：4 的最近不相等邻居是 2 和 1 。由于 4 &gt; 2 且 4 &gt; 1 ，下标 1 是一个峰。
在下标 2 ：1 的最近不相等邻居是 4 和 6 。由于 1 &lt; 4 且 1 &lt; 6 ，下标 2 是一个谷。
在下标 3 ：1 的最近不相等邻居是 4 和 6 。由于 1 &lt; 4 且 1 &lt; 6 ，下标 3 符合谷的定义，但需要注意它和下标 2 是同一个谷的一部分。
在下标 4 ：6 的最近不相等邻居是 1 和 5 。由于 6 &gt; 1 且 6 &gt; 5 ，下标 4 是一个峰。
在下标 5 ：由于 5 的右侧不存在不相等邻居，所以下标 5 既不是峰也不是谷。
共有 3 个峰和谷，所以返回 3 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [6,6,5,5,4,1]
<strong>输出：</strong>0
<strong>解释：</strong>
在下标 0 ：由于 6 的左侧不存在不相等邻居，所以下标 0 既不是峰也不是谷。
在下标 1 ：由于 6 的左侧不存在不相等邻居，所以下标 1 既不是峰也不是谷。
在下标 2 ：5 的最近不相等邻居是 6 和 4 。由于 5 &lt; 6 且 5 &gt; 4 ，下标 2 既不是峰也不是谷。
在下标 3 ：5 的最近不相等邻居是 6 和 4 。由于 5 &lt; 6 且 5 &gt; 4 ，下标 3 既不是峰也不是谷。
在下标 4 ：4 的最近不相等邻居是 5 和 1 。由于 4 &lt; 5 且 4 &gt; 1 ，下标 4 既不是峰也不是谷。
在下标 5 ：由于 1 的右侧不存在不相等邻居，所以下标 5 既不是峰也不是谷。
共有 0 个峰和谷，所以返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>


    
## 解题方法：一次遍历

使用last记录上一个和当前元素不相同的元素，从第一个元素到倒数第二个元素遍历nums数组，如果当前元素比last和下一个元素都大或都小，则答案数量加一。如果当前元素和下一个元素不相同，则更新last为当前元素。

特别的，我们可以将last的初始值设置为nums[0]，这样当nums[1]和nums[0]相等时，last的值其实和含义“上一个不同元素”不匹配，但并不影响结果的判断。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-07-28 21:39:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-28 21:45:22
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans = 0;
        int last = nums[0];
        for (int i = 1; i < nums.size() - 1; i++) {
            if (nums[i] > last && nums[i] > nums[i + 1]) {
                ans++;
            } else if (nums[i] < last && nums[i] < nums[i + 1]) {
                ans++;
            }
            if (nums[i] != nums[i + 1]) {
                last = nums[i];
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
Date: 2025-07-28 21:39:52
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-28 22:23:33
'''
from typing import List

class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        last = nums[0]
        ans = 0
        # for i, t in enumerate(nums[1:-1]):  # 不可！这样i=0时t=nums[1]
        for i in range(1, len(nums) - 1):
            ans += nums[i] > last and nums[i] > nums[i + 1] or nums[i] < last and nums[i] < nums[i + 1]
            if nums[i] != nums[i + 1]:
                last = nums[i]
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-07-28 21:39:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-28 22:25:46
 */
class Solution {
    public int countHillValley(int[] nums) {
        int last = nums[0];
        int ans = 0;
        for (int i = 1; i < nums.length - 1; i++) {
            if (nums[i] > last && nums[i] > nums[i + 1] || nums[i] < last && nums[i] < nums[i + 1]) {
                ans++;
            }
            if (nums[i] != nums[i + 1]) {
                last = nums[i];
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
 * @Date: 2025-07-28 21:39:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-28 22:27:50
 */
package main

func countHillValley(nums []int) (ans int) {
    last := nums[0]
    for i := 1; i < len(nums) - 1; i++ {
        if nums[i] > last && nums[i] > nums[i + 1] || nums[i] < last && nums[i] < nums[i + 1] {
            ans++
        }
        if nums[i] != nums[i + 1] {
            last = nums[i]
        }
    }
    return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/149727208)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/07/28/LeetCode%202210.%E7%BB%9F%E8%AE%A1%E6%95%B0%E7%BB%84%E4%B8%AD%E5%B3%B0%E5%92%8C%E8%B0%B7%E7%9A%84%E6%95%B0%E9%87%8F/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
