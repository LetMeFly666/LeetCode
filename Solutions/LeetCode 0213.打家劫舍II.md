---
title: 213.打家劫舍 II
date: 2023-09-17 16:06:27
tags: [题解, LeetCode, 中等, 数组, 动态规划, DP]
---

# 【LetMeFly】213.打家劫舍 II：动动态规划

力扣题目链接：[https://leetcode.cn/problems/house-robber-ii/](https://leetcode.cn/problems/house-robber-ii/)

<p>你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 <strong>围成一圈</strong> ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，<strong>如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警</strong> 。</p>

<p>给定一个代表每个房屋存放金额的非负整数数组，计算你 <strong>在不触动警报装置的情况下</strong> ，今晚能够偷窃到的最高金额。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,3,2]
<strong>输出：</strong>3
<strong>解释：</strong>你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,1]
<strong>输出：</strong>4
<strong>解释：</strong>你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
&nbsp;    偷窃到的最高金额 = 1 + 3 = 4 。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3]
<strong>输出：</strong>3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
</ul>


    
## 方法一：动态规划

**假设不考虑“环形”，那么我们应该怎么做？**

很简单，遍历数组，使用两个变量```lastRob```和```lastNot```分别代表上次是否打劫了。

+ 如果上次打劫了，那么这次就不能打劫（$thisNot = \max(lastRob, lastNot)$）
+ 如果上次没打劫，那么这次就打劫（$thisRob = lastNot + nums[i]$）

然后更新lastRob和lastNot为thisRob和thisNot。

最终返回lastRob和lastNot的最大值即为答案。

**加上环形这一限制，应怎么处理？**

很简单，环形的唯一限制就是：打劫第一家的话不能打劫最后一家，打劫最后一家的话不能打劫第一家。

因此，在$[0, len(nums) - 1]$和$[1, len(nums)]$中分别求一次，取最大即可。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
private:
    int realRob(vector<int>& nums, int l, int r) {
        int lastRob = nums[l], lastNot = 0;
        for (int i = l + 1; i < r; i++) {
            int newRob = lastNot + nums[i], newNot = max(lastRob, lastNot);
            lastRob = newRob, lastNot = newNot;
        }
        return max(lastRob, lastNot);
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        return max(realRob(nums, 0, nums.size() - 1), realRob(nums, 1, nums.size()));
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def realRob(self, nums: List[int], l: int, r: int) -> int:
        lastRob, lastNot = nums[l], 0
        for i in range(l + 1, r):
            lastRob, lastNot = lastNot + nums[i], max(lastNot, lastRob)
        return max(lastRob, lastNot)

    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        return max(self.realRob(nums, 0, len(nums) - 1), self.realRob(nums, 1, len(nums)))
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/09/17/LeetCode%200213.%E6%89%93%E5%AE%B6%E5%8A%AB%E8%88%8DII/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/132945449](https://letmefly.blog.csdn.net/article/details/132945449)
