---
title: 1144.递减元素使数组呈锯齿状
date: 2023-02-27 09:40:26
tags: [题解, LeetCode, 中等, 贪心, 数组, 思维]
---

# 【LetMeFly】1144.递减元素使数组呈锯齿状

力扣题目链接：[https://leetcode.cn/problems/decrease-elements-to-make-array-zigzag/](https://leetcode.cn/problems/decrease-elements-to-make-array-zigzag/)

<p>给你一个整数数组&nbsp;<code>nums</code>，每次 <strong>操作</strong>&nbsp;会从中选择一个元素并 <strong>将该元素的值减少&nbsp;1</strong>。</p>

<p>如果符合下列情况之一，则数组&nbsp;<code>A</code>&nbsp;就是 <strong>锯齿数组</strong>：</p>

<ul>
	<li>每个偶数索引对应的元素都大于相邻的元素，即&nbsp;<code>A[0] &gt; A[1] &lt; A[2] &gt; A[3] &lt; A[4] &gt; ...</code></li>
	<li>或者，每个奇数索引对应的元素都大于相邻的元素，即&nbsp;<code>A[0] &lt; A[1] &gt; A[2] &lt; A[3] &gt; A[4] &lt; ...</code></li>
</ul>

<p>返回将数组&nbsp;<code>nums</code>&nbsp;转换为锯齿数组所需的最小操作次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3]
<strong>输出：</strong>2
<strong>解释：</strong>我们可以把 2 递减到 0，或把 3 递减到 1。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [9,6,1,6,2]
<strong>输出：</strong>4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
</ul>


    
## 方法一：贪心

**注意**，这道题只能“减小元素”不能“增大元素”。

要想把数组中的元素修改为“锯齿状”，那就两种情况，要么所有下标为奇数的元素比它的相邻元素小，要么下标为偶数的元素比它的相邻元素小。

那么我们只需要计算这两种情况（将奇数下标的元素变小/将偶数下标的元素变小）。

假设我们计算的是奇数下标的元素比其左右相邻两元素小，那么我们把这个数变成$min(左边元素, 右边元素) - 1$（如果其左边或右边没有元素或者本来就比左右两元素小则不必考虑）

偶数下标变小的情况同理，两种情况中取一个“最小步数”即为答案。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int ansOdd = 0, ansEven = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2) {
                ansOdd += max(0, max(nums[i] - nums[i - 1] + 1, i + 1 < nums.size() ? nums[i] - nums[i + 1] + 1 : 0));
            }
            else {
                ansEven += max(0, max(i - 1 >= 0 ? nums[i] - nums[i - 1] + 1 : 0, i + 1 < nums.size() ? nums[i] - nums[i + 1] + 1 : 0));
            }
        }
        return min(ansEven, ansOdd);
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def movesToMakeZigzag(self, nums: List[int]) -> int:
        ansOdd, ansEven = 0, 0
        for i in range(len(nums)):
            if i % 2:
                ansOdd += max(0, nums[i] - nums[i - 1] + 1, nums[i] - nums[i + 1] + 1 if i + 1 < len(nums) else 0)
            else:
                ansEven += max(0, nums[i] - nums[i - 1] + 1 if i - 1 >= 0 else 0, nums[i] - nums[i + 1] + 1 if i + 1 < len(nums) else 0)
        return min(ansOdd, ansEven)
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2023/02/27/LeetCode%201144.%E9%80%92%E5%87%8F%E5%85%83%E7%B4%A0%E4%BD%BF%E6%95%B0%E7%BB%84%E5%91%88%E9%94%AF%E9%BD%BF%E7%8A%B6/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129235998](https://letmefly.blog.csdn.net/article/details/129235998)
