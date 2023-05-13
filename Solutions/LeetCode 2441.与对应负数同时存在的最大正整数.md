---
title: 2441.与对应负数同时存在的最大正整数
date: 2023-05-13 13:20:19
tags: [题解, LeetCode, 简单, 数组, 哈希表, set]
---

# 【LetMeFly】2441.与对应负数同时存在的最大正整数

力扣题目链接：[https://leetcode.cn/problems/largest-positive-integer-that-exists-with-its-negative/](https://leetcode.cn/problems/largest-positive-integer-that-exists-with-its-negative/)

<p>给你一个 <strong>不包含</strong> 任何零的整数数组 <code>nums</code> ，找出自身与对应的负数都在数组中存在的最大正整数 <code>k</code> 。</p>

<p>返回正整数<em> </em><code>k</code> ，如果不存在这样的整数，返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [-1,2,-3,3]
<strong>输出：</strong>3
<strong>解释：</strong>3 是数组中唯一一个满足题目要求的 k 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [-1,10,6,7,-7,1]
<strong>输出：</strong>7
<strong>解释：</strong>数组中存在 1 和 7 对应的负数，7 的值更大。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [-10,8,6,7,-2,-3]
<strong>输出：</strong>-1
<strong>解释：</strong>不存在满足题目要求的 k ，返回 -1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>-1000 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code>nums[i] != 0</code></li>
</ul>


    
## 方法一：哈希表

首先建立一个哈希表，将nums数组中的每个元素存入哈希表中。

接着遍历nums数组中的每一个数字，如果当前数字大于0并且其负值在哈希表中存在，就更新答案的最大值。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> se(nums.begin(), nums.end());
        int ans = -1;
        for (int num : nums) {
            if (num > 0 && se.count(-num)) {
                ans = max(ans, num);
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
    def findMaxK(self, nums: List[int]) -> int:
        se = set(nums)
        ans = -1
        for num in nums:
            if num > 0 and -num in se:
                ans = max(ans, num)
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/05/13/LeetCode%202441.%E4%B8%8E%E5%AF%B9%E5%BA%94%E8%B4%9F%E6%95%B0%E5%90%8C%E6%97%B6%E5%AD%98%E5%9C%A8%E7%9A%84%E6%9C%80%E5%A4%A7%E6%AD%A3%E6%95%B4%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130656433](https://letmefly.blog.csdn.net/article/details/130656433)
