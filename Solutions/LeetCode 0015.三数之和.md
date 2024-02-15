---
title: 15.三数之和：排序 + 双指针
date: 2023-07-09 07:36:14
tags: [题解, LeetCode, 中等, 数组, 双指针, 排序]
---

# 【LetMeFly】15.三数之和：排序 + 双指针

力扣题目链接：[https://leetcode.cn/problems/3sum/](https://leetcode.cn/problems/3sum/)

<p>给你一个整数数组 <code>nums</code> ，判断是否存在三元组 <code>[nums[i], nums[j], nums[k]]</code> 满足 <code>i != j</code>、<code>i != k</code> 且 <code>j != k</code> ，同时还满足 <code>nums[i] + nums[j] + nums[k] == 0</code> 。请</p>

<p>你返回所有和为 <code>0</code> 且不重复的三元组。</p>

<p><strong>注意：</strong>答案中不可以包含重复的三元组。</p>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [-1,0,1,2,-1,-4]
<strong>输出：</strong>[[-1,-1,2],[-1,0,1]]
<strong>解释：</strong>
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,1,1]
<strong>输出：</strong>[]
<strong>解释：</strong>唯一可能的三元组和不为 0 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,0,0]
<strong>输出：</strong>[[0,0,0]]
<strong>解释：</strong>唯一可能的三元组和为 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 3000</code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 方法一：排序 + 双指针

这道题其实和昨天的每日一题[167.两数之和 II - 输入有序数组](https://blog.letmefly.xyz/2022/08/04/LeetCode%200167.%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8CII-%E8%BE%93%E5%85%A5%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84/)一样。

昨天的问题就是：

**如何在非递减数组中找到和为target的两个数？**

很简单，使用两个指针l和r，l指向数组中第一个元素，r指向数组中最后一个元素。

判断$nums[l], nums[r]$之和$s$：

+ 如果$s == target$，则Got it!
+ 如果$s < target$，则令$l$指针右移（这样s会变大）
+ 如果$s > target$，则令$r$指针左移（这样s会变小）

因为l和r加起来最多遍历数组一次，所以总时间复杂度为$O(n)$，空间复杂度为$O(1)$

**回到这道题，如何找到和为0的三个数？**

只需要多一层循环从$0$到$n - 1$枚举$i$，对于给定的$nums[i]$，要做的就是在$[i+1$, n)$中寻找和为$target=-nums[i]$的两个数。

咦，是不是和昨天那道题一样了？

因为多了一层循环，所以总时间复杂度为$O(n^2)$，空间复杂度仍为$O(1)$

**细节处理**

Q：给定数组无序？

A：排个序就好了。

Q：答案中不得包含重复三元组？

A：枚举i时，若$nums[i] == nums[i - 1]$则continue；如果找到了和为target的lr，则$nums[l] == nums[l - 1]$时不断地$l++$，$nums[r] == nums[r + 1]$时不断$r--$

+ 时间复杂度$O(n^2)$。其中$n = len(nums)$。
+ 空间复杂度$O(\log n)$。空间为排序产生。

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // 不能去重
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int target = -nums[i];
            for (int l = i + 1, r = nums.size() - 1; l < r;) {
                int s = nums[l] + nums[r];
                if (s == target) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while (l + 1 < r && nums[l + 1] == nums[l]) {
                        l++;
                    }
                    while (r - 1 > l && nums[r - 1] == nums[r]) {
                        r--;
                    }
                    l++, r--;
                }
                else if (s < target) {
                    l++;
                }
                else {
                    r--;
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
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = []
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            target = -nums[i]
            l, r = i + 1, len(nums) - 1
            while l < r:
                s = nums[l] + nums[r]
                if s == target:
                    ans.append([nums[i], nums[l], nums[r]])
                    while l + 1 < r and nums[l + 1] == nums[l]:
                        l += 1
                    while r - 1 > l and nums[r - 1] == nums[r]:
                        r -= 1
                    l += 1
                    r -= 1
                elif s < target:
                    l += 1
                else:
                    r -= 1
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/07/09/LeetCode%200015.%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131619103](https://letmefly.blog.csdn.net/article/details/131619103)
