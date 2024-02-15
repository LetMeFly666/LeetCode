---
title: 2824.统计和小于目标的下标对数目
date: 2023-11-24 10:00:30
tags: [题解, LeetCode, 简单, 数组, 双指针, 排序, 二分, 二分查找]
---

# 【LetMeFly】2824.统计和小于目标的下标对数目

力扣题目链接：[https://leetcode.cn/problems/count-pairs-whose-sum-is-less-than-target/](https://leetcode.cn/problems/count-pairs-whose-sum-is-less-than-target/)

给你一个下标从 <strong>0</strong>&nbsp;开始长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>target</code>&nbsp;，请你返回满足&nbsp;<code>0 &lt;= i &lt; j &lt; n</code> 且 <code>nums[i] + nums[j] &lt; target</code>&nbsp;的下标对&nbsp;<code>(i, j)</code>&nbsp;的数目。
<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [-1,1,2,3,1], target = 2
<b>输出：</b>3
<b>解释：</b>总共有 3 个下标对满足题目描述：
- (0, 1) ，0 &lt; 1 且 nums[0] + nums[1] = 0 &lt; target
- (0, 2) ，0 &lt; 2 且 nums[0] + nums[2] = 1 &lt; target 
- (0, 4) ，0 &lt; 4 且 nums[0] + nums[4] = 0 &lt; target
注意 (0, 3) 不计入答案因为 nums[0] + nums[3] 不是严格小于 target 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [-6,2,5,-2,-7,-1,3], target = -2
<b>输出：</b>10
<b>解释：</b>总共有 10 个下标对满足题目描述：
- (0, 1) ，0 &lt; 1 且 nums[0] + nums[1] = -4 &lt; target
- (0, 3) ，0 &lt; 3 且 nums[0] + nums[3] = -8 &lt; target
- (0, 4) ，0 &lt; 4 且 nums[0] + nums[4] = -13 &lt; target
- (0, 5) ，0 &lt; 5 且 nums[0] + nums[5] = -7 &lt; target
- (0, 6) ，0 &lt; 6 且 nums[0] + nums[6] = -3 &lt; target
- (1, 4) ，1 &lt; 4 且 nums[1] + nums[4] = -5 &lt; target
- (3, 4) ，3 &lt; 4 且 nums[3] + nums[4] = -9 &lt; target
- (3, 5) ，3 &lt; 5 且 nums[3] + nums[5] = -3 &lt; target
- (4, 5) ，4 &lt; 5 且 nums[4] + nums[5] = -8 &lt; target
- (4, 6) ，4 &lt; 6 且 nums[4] + nums[6] = -4 &lt; target
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length == n &lt;= 50</code></li>
	<li><code>-50 &lt;= nums[i], target &lt;= 50</code></li>
</ul>


    
## 方法一：暴力枚举

两层循环枚举$i$和$j$，统计和小于$target$的个数即可。

+ 时间复杂度$O(n^2)$，其中$n=len(nums)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                ans += nums[i] + nums[j] < target;
            }
        }
        return ans;
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def countPairs(self, nums: List[int], target: int) -> int:
        ans = 0
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                ans += nums[i] + nums[j] < target
        return ans
```

## 方法二：二分查找

先排个序，第一层循环枚举$i$，第二层循环在$[0, i)$范围内通过二分查找$\leq target-nums[i]$的数的个数。

+ 时间复杂度$O(n\log n)$，其中$n=len(nums)$，排序复杂度$O(n\log n)$，单次二分查找时间复杂度$O(\log n)$
+ 空间复杂度$O(\log n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            ans += lower_bound(nums.begin(), it, target - *it) - nums.begin();
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List
# from bisect import bisect_left

class Solution:
    def countPairs(self, nums: List[int], target: int) -> int:
        nums.sort()
        ans = 0
        for i in range(len(nums)):
            ans += bisect_left(nums[:i], target - nums[i])
        return ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/11/24/LeetCode%202824.%E7%BB%9F%E8%AE%A1%E5%92%8C%E5%B0%8F%E4%BA%8E%E7%9B%AE%E6%A0%87%E7%9A%84%E4%B8%8B%E6%A0%87%E5%AF%B9%E6%95%B0%E7%9B%AE/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/134594377](https://letmefly.blog.csdn.net/article/details/134594377)
