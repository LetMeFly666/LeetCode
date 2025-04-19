---
title: 2563.统计公平数对的数目：排序 + 二分查找
date: 2025-04-19 16:46:20
tags: [题解, LeetCode, 中等, 数组, 双指针, 二分查找, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】2563.统计公平数对的数目：排序 + 二分查找

力扣题目链接：[https://leetcode.cn/problems/count-the-number-of-fair-pairs/](https://leetcode.cn/problems/count-the-number-of-fair-pairs/)

<p>给你一个下标从 <strong>0</strong> 开始、长度为 <code>n</code> 的整数数组&nbsp;<code>nums</code>&nbsp;，和两个整数&nbsp;<code>lower</code> 和&nbsp;<code>upper</code> ，返回 <strong>公平数对的数目</strong> 。</p>

<p>如果&nbsp;<code>(i, j)</code>&nbsp;数对满足以下情况，则认为它是一个 <strong>公平数对</strong>&nbsp;：</p>

<ul>
	<li><code>0 &lt;= i &lt; j &lt; n</code>，且</li>
	<li><code>lower &lt;= nums[i] + nums[j] &lt;= upper</code></li>
</ul>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre>
<b>输入：</b>nums = [0,1,7,4,4,5], lower = 3, upper = 6
<b>输出：</b>6
<b>解释：</b>共计 6 个公平数对：(0,3)、(0,4)、(0,5)、(1,3)、(1,4) 和 (1,5) 。
</pre>

<p><b>示例 2：</b></p>

<pre>
<b>输入：</b>nums = [1,7,9,2,5], lower = 11, upper = 11
<b>输出：</b>1
<b>解释：</b>只有单个公平数对：(2,3) 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums.length == n</code></li>
	<li><code>-10<sup>9</sup>&nbsp;&lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>-10<sup>9</sup>&nbsp;&lt;= lower &lt;= upper &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：排序 + 二分查找

要找的是值在一定范围内的$nums[i] + nums[j]$，且加法满足交换律($a+b=b+a$)，所以查找结果和元素顺序无关。

所以只需要遍历$nums$的下标作为$i$，并在$i+1$到数组末尾的范围内查找$j$的范围，最终累加到答案中即可。

> 如何确定$j$的范围？$upper\_bound(upper - i) - lower\_bound(lower - i)$或$lower\_bound(upper - i + 1) - lower_bound(lower - i)$均可。
> 
> 其中$lower_bound(t)$是非递减数组中第一个插入$t$后数组仍非递减的下标，$upper_bound(t)$是非递减数组中最后一个插入$t$后数组仍非递减的下标。

+ 时间复杂度$O(n\log n)$，其中$n=len(nums)$
+ 空间复杂度$O(\log n)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-04-19 15:51:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-19 16:12:44
 */
/*
l: first j 满足 nums[j] + nums[i] >= lower | nums[j] >= lower - nums[i]
r: last  j 满足 nums[j] + nums[i] <= upper | nums[j] <= upper - nums[i]

l: lower_bound(lower - nums[i])
r: upper_bound(upper - nums[i])
*/
typedef long long ll;
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        ll ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            // cout << i << ": " << i << "[" << lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin() << ", " << upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin() << ')' << endl;
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-04-19 16:13:37
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-19 16:23:38
'''
from typing import List
from bisect import bisect_left, bisect_right


class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()
        return sum(bisect_right(nums, upper - nums[i], i + 1) - bisect_left(nums, lower - nums[i], i + 1) for i in range(len(nums)))
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-04-19 16:24:08
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-19 16:37:36
 */
import java.util.Arrays;

class Solution {
    private int search(int[] nums, int x, int l) {  // search [l, len(nums)) 范围内第一个大于等于x的下标
        int r = nums.length;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    public long countFairPairs(int[] nums, int lower, int upper) {
        Arrays.sort(nums);
        long ans = 0;
        for (int i = 0; i < nums.length; i++) {
            ans += search(nums, upper - nums[i] + 1, i + 1) - search(nums, lower - nums[i], i + 1);
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-04-19 16:24:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-19 16:43:06
 */
package main
import (
    "sort"
)

func countFairPairs(nums []int, lower int, upper int) (ans int64) {
    sort.Ints(nums)
    for i, v := range nums {
        l := sort.Search(len(nums), func(x int) bool {return x > i && nums[x] >= lower - v})
        r := sort.Search(len(nums), func(x int) bool {return x > i && nums[x] >= upper - v + 1})
        ans += int64(r - l)
    }
    return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/147354620)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/04/19/LeetCode%202563.%E7%BB%9F%E8%AE%A1%E5%85%AC%E5%B9%B3%E6%95%B0%E5%AF%B9%E7%9A%84%E6%95%B0%E7%9B%AE/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
