---
title: 410.分割数组的最大值
date: 2024-01-21 13:35:04
tags: [题解, LeetCode, 困难, 贪心, 数组, 二分查找, 二分, 动态规划, 前缀和]
categories: [题解, LeetCode]
---

# 【LetMeFly】410.分割数组的最大值：二分

力扣题目链接：[https://leetcode.cn/problems/split-array-largest-sum/](https://leetcode.cn/problems/split-array-largest-sum/)

<p>给定一个非负整数数组 <code>nums</code> 和一个整数&nbsp;<code>m</code> ，你需要将这个数组分成&nbsp;<code>m</code><em>&nbsp;</em>个非空的连续子数组。</p>

<p>设计一个算法使得这&nbsp;<code>m</code><em>&nbsp;</em>个子数组各自和的最大值最小。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [7,2,5,10,8], m = 2
<strong>输出：</strong>18
<strong>解释：</strong>
一共有四种方法将 nums 分割为 2 个子数组。 
其中最好的方式是将其分为 [7,2,5] 和 [10,8] 。
因为此时这两个子数组各自的和的最大值为18，在所有情况中最小。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4,5], m = 2
<strong>输出：</strong>9
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,4,4], m = 3
<strong>输出：</strong>4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= m &lt;= min(50, nums.length)</code></li>
</ul>


    
## 方法一：二分

写一个函数```check(s)```，返回```能否```将数组```nums```划分为```k```部分且每一部分的最大值不超过```s```。

> 实现方法很简单，使用一个变量```cnt```来记录当前部分的元素和。
>
> 遍历数组，如果当前元素大于```s```，则必不可能成功划分，直接返回```false```。
>
> 若```cnt```加上当前元素超过了```s```，则将当前元素划分为一组（```k--```、```cnt = 0```）。
>
> 令```cnt```加上当前元素。
>
> 遍历结束后，判断```k - 1```是否大于等于```0```。若是，则返回```true```，否则返回```false```。

有了这样的函数，我们只需要在主函数中写一个二分，枚举值```mid```是否能通过```check```。

> 令```l```初始值为```0```，```r```初始值为“无穷大”（数组中所有元素之和再加一）。
>
> 当```l < r```时，令$mid = \lfloor \frac{l+r}{2} \rfloor$。
>
> 如果```check(mid)```通过了，则说明```mid```为一种合法分法，尝试更小的值能否成功划分（令```r = mid```）
>
> 否则，说明```mid```太小了，无法划分，尝试更大的值能否成功划分（令```l = mid + 1```）

二分结束后，```l = r```，返回```l```即为答案。

+ 时间复杂度$O(len(nums)\times \log \sum nums)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
private:
    bool check(vector<int>& nums, int k, int s) {
        int cnt = 0;
        for (int t : nums) {
            if (t > s) {
                return false;
            }
            if (t + cnt > s) {
                k--;
                cnt = 0;
            }
            cnt += t;
        }
        return --k >= 0;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int l = 0, r = accumulate(nums.begin(), nums.end(), 0) + 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(nums, k, mid)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def check(self, k: int, s: int) -> bool:
        cnt = 0
        for t in self.nums:
            if t > s:
                return False
            if cnt + t > s:
                k -= 1
                cnt = 0
            cnt += t
        return k - 1 >= 0

    def splitArray(self, nums: List[int], k: int) -> int:
        self.nums = nums
        l, r = 0, sum(nums) + 1
        while l < r:
            mid = (l + r) >> 1
            if self.check(k, mid):
                r = mid
            else:
                l = mid + 1
        return l
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/01/21/LeetCode%200410.%E5%88%86%E5%89%B2%E6%95%B0%E7%BB%84%E7%9A%84%E6%9C%80%E5%A4%A7%E5%80%BC/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135728821](https://letmefly.blog.csdn.net/article/details/135728821)
