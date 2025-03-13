---
title: 53.最大子数组和
date: 2023-11-20 11:17:58
tags: [题解, LeetCode, 中等, 数组, 分治, 递归, 动态规划, DP]
categories: [题解, LeetCode]
---

# 【LetMeFly】53.最大子数组和：DP 或 递归（线段树入门题？）

力扣题目链接：[https://leetcode.cn/problems/maximum-subarray/](https://leetcode.cn/problems/maximum-subarray/)

<p>给你一个整数数组 <code>nums</code> ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。</p>

<p><strong>子数组 </strong>是数组中的一个连续部分。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [-2,1,-3,4,-1,2,1,-5,4]
<strong>输出：</strong>6
<strong>解释：</strong>连续子数组&nbsp;[4,-1,2,1] 的和最大，为&nbsp;6 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1]
<strong>输出：</strong>1
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,4,-1,7,8]
<strong>输出：</strong>23
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>如果你已经实现复杂度为 <code>O(n)</code> 的解法，尝试使用更为精妙的 <strong>分治法</strong> 求解。</p>


    
## 方法一：DP

使用动态规划的话思路比较简单，使用一个变量$cnt$记录```以当前元素为结尾的最大子数组和```。

这样，我们只需要遍历一遍$nums$数组，使用公式$cnt = \max(cnt + nums[i], nums[i])$维护$cnt$，并记得更新答案的最大值即可。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int cnt = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            cnt = max(cnt + nums[i], nums[i]);
            ans = max(ans, cnt);
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans, cnt = nums[0], nums[0]
        for i in range(1, len(nums)):
            cnt = max(cnt + nums[i], nums[i])
            ans = max(ans, cnt)
        return ans
```

## 方法二：递归（分治）

写一个函数$get(nums, l, r)$，返回$nums$数组从$l$到$r$的子数组的：

1. lSum: 以$nums[l]$为起点的```最大子数组和```
2. rSum: 以$nums[r]$为终点的```最大子数组和```
3. MSum: ```最大子数组和```
4. iSum: 和

那么，我们就可以愉快地进行递归啦！

对于$get(nums, l, r)$，我们可以分别求出$get(nums, l, \lfloor\frac{l + r}{2}\rfloor)$（记为$lStatus$）和$get(nums, \lfloor\frac{l + r}{2}\rfloor + 1, r)$（记为$rStatus$）。递归终止条件为$l=r$（只有单个元素）。

于是就有：

1. $lSum = \max(lStatus.lSum, lStatus.iSum + rStatus.lSum)$（以$nums[l]$为起点，不跨过$nums[\lfloor\frac{l + r}{2}\rfloor]$和跨过）
2. $rSum = \max(rStatus.rSum, lStatus.rSum + rStatus.iSum)$（以$nums[r]$为终点，不跨过$nums[\lfloor\frac{l + r}{2}\rfloor]$和跨过）
3. $MSum = \max(lStatus.MSum, rStatus.MSum, lStatus.rSum + rStatus.lSum)$（左半部分最大子数组和、右半部分最大子数组和、跨过$nums[\lfloor\frac{l + r}{2}\rfloor]$的子数组和）
4. $iSum = lStatus.iSum + rStatus.iSum$（左半右半数组和 之和）

最终返回$get(nums, 0, len(nums) - 1).MSum$即可。

+ 时间复杂度$O(len(nums))$（相当于后序遍历了一遍二叉树）
+ 空间复杂度$O(\log len(nums))$（空间复杂度主要来源于递归）

### AC代码

#### C++

```cpp
struct Status {
    int lSum, rSum, MSum, iSum;
};

class Solution {
private:
    Status get(vector<int>& a, int l, int r) {  // get[l, r]
        if (l == r) {
            return {a[l], a[l], a[l], a[l]};
        }
        int m = (l + r) >> 1;
        Status lStatus = get(a, l, m);
        Status rStatus = get(a, m + 1, r);
        return {
            max(lStatus.lSum, lStatus.iSum + rStatus.lSum),
            max(rStatus.rSum, lStatus.rSum + rStatus.iSum),
            max(lStatus.MSum, max(rStatus.MSum, lStatus.rSum + rStatus.lSum)),
            lStatus.iSum + rStatus.iSum
        };
    }
public:
    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).MSum;
    }
};
```

#### Python

```python
# from typing import List


class Status:
    def __init__(self, lSum: int, rSum: int, MSum: int, iSum: int) -> None:
        self.lSum = lSum
        self.rSum = rSum
        self.MSum = MSum
        self.iSum = iSum


class Solution:
    def get(self, nums: List[int], l: int, r: int) -> Status:
        if l == r:
            return Status(nums[l], nums[l], nums[l], nums[l])
        m = (l + r) >> 1
        lStatus = self.get(nums, l, m)
        rStatus = self.get(nums, m + 1, r)
        return Status(
            max(lStatus.lSum, lStatus.iSum + rStatus.lSum),
            max(rStatus.rSum, lStatus.rSum + rStatus.iSum),
            max(lStatus.MSum, rStatus.MSum, lStatus.rSum + rStatus.lSum),
            lStatus.iSum + rStatus.iSum
        )
    
    def maxSubArray(self, nums: List[int]) -> int:
        return self.get(nums, 0, len(nums) - 1).MSum


"""为何不用切片作为参数？
>>> a = [1, 2, 3]
>>> a
[1, 2, 3]
>>> b = a[1:2]
>>> b
[2]
>>> b[0] = 99
>>> a
[1, 2, 3]
>>> b
[99]
"""
```

## 方法二意义何在？

相较于方法一，方法二的时间复杂度没有提升，空间复杂度反而更高了。那么方法二的意义何在？

这道题只问了“整个数组的”最大子数组和。但是如果某天遇到了一道题，问你$10^5$次且每次随机问一个$[l, r]$的最大子数组和 呢？

那么我们使用方法二，并且将每层的结果记录下来，就能做到每次查询都在$O(\log n)$的时间复杂度下返回结果。

这就是没有懒标记的线段树。

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/11/20/LeetCode%200053.%E6%9C%80%E5%A4%A7%E5%AD%90%E6%95%B0%E7%BB%84%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/134504375](https://letmefly.blog.csdn.net/article/details/134504375)
