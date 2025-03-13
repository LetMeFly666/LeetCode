---
title: 2908.元素和最小的山形三元组 I
date: 2024-03-29 17:06:53
tags: [题解, LeetCode, 简单, 数组]
categories: [题解, LeetCode]
---

# 【LetMeFly】2908.元素和最小的山形三元组 I：贪心（两次遍历）——双O(n)复杂度

力扣题目链接：[https://leetcode.cn/problems/minimum-sum-of-mountain-triplets-i/](https://leetcode.cn/problems/minimum-sum-of-mountain-triplets-i/)

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 。</p>

<p>如果下标三元组 <code>(i, j, k)</code> 满足下述全部条件，则认为它是一个 <strong>山形三元组</strong> ：</p>

<ul>
	<li><code>i &lt; j &lt; k</code></li>
	<li><code>nums[i] &lt; nums[j]</code> 且 <code>nums[k] &lt; nums[j]</code></li>
</ul>

<p>请你找出 <code>nums</code> 中 <strong>元素和最小</strong> 的山形三元组，并返回其 <strong>元素和</strong> 。如果不存在满足条件的三元组，返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [8,6,1,5,3]
<strong>输出：</strong>9
<strong>解释：</strong>三元组 (2, 3, 4) 是一个元素和等于 9 的山形三元组，因为： 
- 2 &lt; 3 &lt; 4
- nums[2] &lt; nums[3] 且 nums[4] &lt; nums[3]
这个三元组的元素和等于 nums[2] + nums[3] + nums[4] = 9 。可以证明不存在元素和小于 9 的山形三元组。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,4,8,7,10,2]
<strong>输出：</strong>13
<strong>解释：</strong>三元组 (1, 3, 5) 是一个元素和等于 13 的山形三元组，因为： 
- 1 &lt; 3 &lt; 5 
- nums[1] &lt; nums[3] 且 nums[5] &lt; nums[3]
这个三元组的元素和等于 nums[1] + nums[3] + nums[5] = 13 。可以证明不存在元素和小于 13 的山形三元组。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [6,5,4,3,4,5]
<strong>输出：</strong>-1
<strong>解释：</strong>可以证明 nums 中不存在山形三元组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 50</code></li>
</ul>


    
## 解题方法：两次遍历

我们可以枚举```中间j```的位置。对于```nums[j]```，最优解是加上左边所有数中最小的那个 再加上 右边所有数中最小的那个。（如果两边最小都小于```nums[j]```的话）

因此我们可以开辟一个```leftMin```数组，其中```leftMin[i]```为```nums[0]```到```nums[i]```中所有值的最小值。这个数组只需要遍历一遍```nums```即可得到。

接着从右往左遍历```j```的位置，并使用一个变量```rightMin```记录右边的最小值，遍历完成后即可得知所有合法```山形三元组```中最小的那个了。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minimumSum(vector<int>& nums) {
        vector<int> leftMin(nums.size());
        leftMin[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            leftMin[i] = min(nums[i], leftMin[i - 1]);
        }
        int rightMin = nums.back();
        int ans = 1e7;
        for (int i = nums.size() - 2; i > 0; i--) {
            if (nums[i] > leftMin[i - 1] && nums[i] > rightMin) {
                ans = min(ans, nums[i] + leftMin[i - 1] + rightMin);
            }
            rightMin = min(rightMin, nums[i]);
        }
        return ans == 1e7 ? -1 : ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def minimumSum(self, nums: List[int]) -> int:
        leftMin = [0] * len(nums)
        leftMin[0] = nums[0]
        for i in range(1, len(nums)):
            leftMin[i] = min(leftMin[i - 1], nums[i])
        rightMin = nums[-1]
        ans = 1_000_000
        for i in range(len(nums) - 2, 0, -1):
            if nums[i] > leftMin[i - 1] and nums[i] > rightMin:
                ans = min(ans, nums[i] + leftMin[i - 1] + rightMin)
            rightMin = min(rightMin, nums[i])
        return ans if ans < 1_000_000 else -1
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/03/29/LeetCode%202908.%E5%85%83%E7%B4%A0%E5%92%8C%E6%9C%80%E5%B0%8F%E7%9A%84%E5%B1%B1%E5%BD%A2%E4%B8%89%E5%85%83%E7%BB%84I/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/137151595](https://letmefly.blog.csdn.net/article/details/137151595)
