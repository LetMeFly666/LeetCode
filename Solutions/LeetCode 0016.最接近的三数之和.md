---
title: 16.最接近的三数之和：排序 + 双指针
date: 2023-07-10 09:12:46
tags: [题解, LeetCode, 中等, 数组, 双指针, 排序]
---

# 【LetMeFly】16.最接近的三数之和：排序 + 双指针

力扣题目链接：[https://leetcode.cn/problems/3sum-closest/](https://leetcode.cn/problems/3sum-closest/)

<p>给你一个长度为 <code>n</code> 的整数数组&nbsp;<code>nums</code><em>&nbsp;</em>和 一个目标值&nbsp;<code>target</code>。请你从 <code>nums</code><em> </em>中选出三个整数，使它们的和与&nbsp;<code>target</code>&nbsp;最接近。</p>

<p>返回这三个数的和。</p>

<p>假定每组输入只存在恰好一个解。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [-1,2,1,-4], target = 1
<strong>输出：</strong>2
<strong>解释：</strong>与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,0,0], target = 1
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>-1000 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code>-10<sup>4</sup> &lt;= target &lt;= 10<sup>4</sup></code></li>
</ul>


    
## 方法一：排序 + 双指针

这道题和昨天的每日一题[0016. 最接近的三数之和](https://blog.tisfy.eu.org/2023/07/09/LeetCode%200015.%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C/)几乎一样，昨天是寻找三个数之和为target的数，今天是找到三个数之和最接近target的数。

因此，我们只需要在移动指针lr时，更新一下最优解即可。这里再次讲解一下大致思路：

第一层循环枚举数组中的每一个数nums[i]，对于一个特定的nums[i]：

使用双指针lr，初始值$l=i+1,r=n-1$。计算$nums[i]+nums[l]+nums[r]$（记为$s$）：

+ 若$s==target$：直接返回target
+ 若$s < target$：则$l$右移，并更新答案的最优值
+ 若$s > target$：则$r$左移，并更新答案的最优值

最终返回最优的答案即可。

+ 时间复杂度$O(n^2)$，其中$n=len(nums)$。
+ 空间复杂度$O(\log n)$，复杂度为排序所致。

### AC代码

#### C++

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = nums[0] + nums[1] + nums[2];
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int finding = target - nums[i];
            int l = i + 1, r = n - 1;
            while (l < r) {
                int diff = finding - nums[l] - nums[r];
                if (diff == 0) {
                    return target;
                }
                else if (diff > 0) {  // target > nums[i] + nums[l] + nums[r]
                    l++;
                }
                else {
                    r--;
                }
                if (abs(diff) < abs(ans - target)) {
                    ans = target - diff;
                }
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
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        ans = sum(nums[:3])
        n = len(nums)
        nums.sort()
        for i in range(n):
            finding = target - nums[i]
            l, r = i + 1, n - 1
            while l < r:
                diff = finding - nums[l] - nums[r]
                if diff == 0:
                    return target
                elif diff > 0:  # target > nums[i] + nums[l] + nums[r]
                    l += 1
                else:
                    r -= 1
                if abs(diff) < abs(ans - target):
                    ans = target - diff
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/07/10/LeetCode%200016.%E6%9C%80%E6%8E%A5%E8%BF%91%E7%9A%84%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131631627](https://letmefly.blog.csdn.net/article/details/131631627)
