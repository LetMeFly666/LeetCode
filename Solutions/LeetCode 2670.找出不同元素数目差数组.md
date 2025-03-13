---
title: 2670.找出不同元素数目差数组
date: 2024-01-31 11:16:42
tags: [题解, LeetCode, 简单, 数组, 哈希表, 哈希, set]
categories: [题解, LeetCode]
---

# 【LetMeFly】2670.找出不同元素数目差数组：哈希表（预处理）

力扣题目链接：[https://leetcode.cn/problems/find-the-distinct-difference-array/](https://leetcode.cn/problems/find-the-distinct-difference-array/)

<p>给你一个下标从 <strong>0</strong> 开始的数组 <code>nums</code> ，数组长度为 <code>n</code> 。</p>

<p><code>nums</code> 的 <strong>不同元素数目差</strong> 数组可以用一个长度为 <code>n</code> 的数组 <code>diff</code> 表示，其中 <code>diff[i]</code> 等于前缀 <code>nums[0, ..., i]</code> 中不同元素的数目 <strong>减去</strong> 后缀 <code>nums[i + 1, ..., n - 1]</code> 中不同元素的数目。</p>

<p>返回<em> </em><code>nums</code> 的 <strong>不同元素数目差</strong> 数组。</p>

<p>注意 <code>nums[i, ..., j]</code> 表示 <code>nums</code> 的一个从下标 <code>i</code> 开始到下标 <code>j</code> 结束的子数组（包含下标 <code>i</code> 和 <code>j</code> 对应元素）。特别需要说明的是，如果 <code>i &gt; j</code> ，则 <code>nums[i, ..., j]</code> 表示一个空子数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4,5]
<strong>输出：</strong>[-3,-1,1,3,5]
<strong>解释：
</strong>对于 i = 0，前缀中有 1 个不同的元素，而在后缀中有 4 个不同的元素。因此，diff[0] = 1 - 4 = -3 。
对于 i = 1，前缀中有 2 个不同的元素，而在后缀中有 3 个不同的元素。因此，diff[1] = 2 - 3 = -1 。
对于 i = 2，前缀中有 3 个不同的元素，而在后缀中有 2 个不同的元素。因此，diff[2] = 3 - 2 = 1 。
对于 i = 3，前缀中有 4 个不同的元素，而在后缀中有 1 个不同的元素。因此，diff[3] = 4 - 1 = 3 。
对于 i = 4，前缀中有 5 个不同的元素，而在后缀中有 0 个不同的元素。因此，diff[4] = 5 - 0 = 5 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,2,3,4,2]
<strong>输出：</strong>[-2,-1,0,2,3]
<strong>解释：</strong>
对于 i = 0，前缀中有 1 个不同的元素，而在后缀中有 3 个不同的元素。因此，diff[0] = 1 - 3 = -2 。
对于 i = 1，前缀中有 2 个不同的元素，而在后缀中有 3 个不同的元素。因此，diff[1] = 2 - 3 = -1 。
对于 i = 2，前缀中有 2 个不同的元素，而在后缀中有 2 个不同的元素。因此，diff[2] = 2 - 2 = 0 。
对于 i = 3，前缀中有 3 个不同的元素，而在后缀中有 1 个不同的元素。因此，diff[3] = 3 - 1 = 2 。
对于 i = 4，前缀中有 3 个不同的元素，而在后缀中有 0 个不同的元素。因此，diff[4] = 3 - 0 = 3 。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == nums.length&nbsp;&lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 50</code></li>
</ul>


    
## 方法一：哈希表

使用哈希表可以快速地统计出“不同元素的个数”。

使用一个长为$n + 1$的数组$suffix$，其中$suffix[i]$表示$nums[i]$及其之后一共有多少个不同的元素。

新建一个哈希表$se$统计不同元素出现的个数，从后到前遍历$nums$数组，将当前元素插入哈希表中，此时哈希表的大小即为这个元素及其之后一共有多少个不同的元素。

得到$suffix$数组后，清空哈希表$se$。再从前向后遍历一遍$nums$数组，将当前元素插入哈希表中，此时$len(se) - suffix[i + 1]$即为$nums[0, ..., i]$中不同元素的个数减去$nums[i + 1, ..., n - 1]$中不同元素的数目。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        unordered_set<int> se;
        vector<int> suffix(nums.size() + 1);
        for (int i = nums.size() - 1; i >= 0; i--) {
            se.insert(nums[i]);
            suffix[i] = se.size();
        }
        se.clear();
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            se.insert(nums[i]);
            ans[i] = se.size() - suffix[i + 1];
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def distinctDifferenceArray(self, nums: List[int]) -> List[int]:
        se = set()
        suffix = [0] * (len(nums) + 1)
        for i in range(len(nums) - 1, -1, -1):
            se.add(nums[i])
            suffix[i] = len(se)
        se.clear()
        ans = [0] * len(nums)
        for i in range(len(nums)):
            se.add(nums[i])
            ans[i] = len(se) - suffix[i + 1]
        return ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/01/31/LeetCode%202670.%E6%89%BE%E5%87%BA%E4%B8%8D%E5%90%8C%E5%85%83%E7%B4%A0%E6%95%B0%E7%9B%AE%E5%B7%AE%E6%95%B0%E7%BB%84/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135949670](https://letmefly.blog.csdn.net/article/details/135949670)
