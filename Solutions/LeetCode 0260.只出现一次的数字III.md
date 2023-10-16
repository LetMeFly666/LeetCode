---
title: 260.只出现一次的数字 III
date: 2023-10-16 22:53:59
tags: [题解, LeetCode, 中等, 位运算, 数组]
---

# 【LetMeFly】260.只出现一次的数字 III

力扣题目链接：[https://leetcode.cn/problems/single-number-iii/](https://leetcode.cn/problems/single-number-iii/)

<p>给你一个整数数组&nbsp;<code>nums</code>，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 <strong>任意顺序</strong> 返回答案。</p>

<p>你必须设计并实现线性时间复杂度的算法且仅使用常量额外空间来解决此问题。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,1,3,2,5]
<strong>输出：</strong>[3,5]
<strong>解释：</strong>[5, 3] 也是有效的答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [-1,0]
<strong>输出：</strong>[-1,0]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,1]
<strong>输出：</strong>[1,0]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li>除两个只出现一次的整数外，<code>nums</code> 中的其他数字都出现两次</li>
</ul>


    
## 方法一：位运算（异或）

这道题的本质思路是：将所有的数分成两组，只出现了一次的数分别分到两组中，其余数根据“与单独的数的相似程度”分到这两个组中。这个过程保证了相等的两个数会被分到同一组中。

依据什么将只出现了一次的两个数分到两组中呢？我们只需要将所有的数异或，异或的结果就是“只出现一次的两个数”的异或结果。这两个数不相等，因此这个异或结果一定不为零。

异或结果中，为0的位代表两数这一位也相等，为1的位代表两数的这一位不同。那么，我们就可以根据这个异或结果的“最低一个不为0的位”为依据，将所有的数分为两组。这样，不相同的两个数一定会被分到不同的组中。

这样，对于单个组，只有一个只出现了一次的数字 和 出现了两次的数字，按照[136.只出现一次的数字](https://blog.tisfy.eu.org/2022/07/25/LeetCode%200136.%E5%8F%AA%E5%87%BA%E7%8E%B0%E4%B8%80%E6%AC%A1%E7%9A%84%E6%95%B0%E5%AD%97/)的方法分别提取出这两个数了。

关于如何求得一个数二进制下第一个不为0的位，可以依据[lowbit](https://web.letmefly.eu.org/Notes/ACM/%E7%AE%97%E6%B3%95%E7%AB%9E%E8%B5%9B%E8%BF%9B%E9%98%B6%E6%8C%87%E5%8D%97%E7%AC%94%E8%AE%B0/)的原理。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int temp = 0;
        for (int t : nums) {
            temp ^= t;
        }
        int mask = temp & (-temp);
        vector<int> ans(2);
        for (int t : nums) {
            ans[(t & mask) != 0] ^= t;
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        temp = 0
        for t in nums:
            temp ^= t
        mask = temp & (-temp)
        ans = [0, 0]
        for t in nums:
            ans[(t & mask) != 0] ^= t
        return ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2023/10/16/LeetCode%200260.%E5%8F%AA%E5%87%BA%E7%8E%B0%E4%B8%80%E6%AC%A1%E7%9A%84%E6%95%B0%E5%AD%97III/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/133872707](https://letmefly.blog.csdn.net/article/details/133872707)
