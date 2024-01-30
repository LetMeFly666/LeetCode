---
title: 2808.使循环数组所有元素相等的最少秒数
date: 2024-01-30 11:51:50
tags: [题解, LeetCode, 中等, 数组, 哈希表, 哈希, map]
---

# 【LetMeFly】2808.使循环数组所有元素相等的最少秒数

力扣题目链接：[https://leetcode.cn/problems/minimum-seconds-to-equalize-a-circular-array/](https://leetcode.cn/problems/minimum-seconds-to-equalize-a-circular-array/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始长度为 <code>n</code>&nbsp;的数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>每一秒，你可以对数组执行以下操作：</p>

<ul>
	<li>对于范围在&nbsp;<code>[0, n - 1]</code>&nbsp;内的每一个下标&nbsp;<code>i</code>&nbsp;，将&nbsp;<code>nums[i]</code> 替换成&nbsp;<code>nums[i]</code>&nbsp;，<code>nums[(i - 1 + n) % n]</code>&nbsp;或者&nbsp;<code>nums[(i + 1) % n]</code>&nbsp;三者之一。</li>
</ul>

<p><strong>注意</strong>，所有元素会被同时替换。</p>

<p>请你返回将数组 <code>nums</code>&nbsp;中所有元素变成相等元素所需要的 <strong>最少</strong>&nbsp;秒数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [1,2,1,2]
<b>输出：</b>1
<b>解释：</b>我们可以在 1 秒内将数组变成相等元素：
- 第 1 秒，将每个位置的元素分别变为 [nums[3],nums[1],nums[3],nums[3]] 。变化后，nums = [2,2,2,2] 。
1 秒是将数组变成相等元素所需要的最少秒数。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [2,1,3,3,2]
<b>输出：</b>2
<b>解释：</b>我们可以在 2 秒内将数组变成相等元素：
- 第 1 秒，将每个位置的元素分别变为 [nums[0],nums[2],nums[2],nums[2],nums[3]] 。变化后，nums = [2,3,3,3,3] 。
- 第 2 秒，将每个位置的元素分别变为 [nums[1],nums[1],nums[2],nums[3],nums[4]] 。变化后，nums = [3,3,3,3,3] 。
2 秒是将数组变成相等元素所需要的最少秒数。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = [5,5,5,5]
<b>输出：</b>0
<b>解释：</b>不需要执行任何操作，因为一开始数组中的元素已经全部相等。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 方法一：哈希表

其实不难发现，最终数组中元素的值一定是数组中某个原有元素的值。

因此使用一个哈希表，记录每个元素$a$在nums数组中出现的位置。

这样，假设数组中所有元素最终都变成了$a$，那么我们只需要枚举$a$在原始数组中的所有出现位置，间隔最大的两个位置决定了“感染其他元素”所需要的时间。

枚举原始数组中所有出现过的元素（哈希表的键值），对于这个元素的所有出现位置，假设间距最大的是$thisMax$，则将数组权变成这个元素所需最小时间为$\lfloor\frac{thisMax}2\rfloor$。

所有的最小时间中最小的那个即为答案。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, vector<int>> ma;
        for (int i = 0; i < nums.size(); i++) {
            ma[nums[i]].push_back(i);
        }
        int ans = nums.size() - 1;
        for (auto&& [num, positions] : ma) {
            int thisMax = positions[0] + nums.size() - positions.back();
            for (int i = 1; i < positions.size(); i++) {
                thisMax = max(thisMax, positions[i] - positions[i - 1]);
            }
            ans = min(ans, thisMax / 2);
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List
# from collections import defaultdict

class Solution:
    def minimumSeconds(self, nums: List[int]) -> int:
        ma = defaultdict(list)
        for i, val in enumerate(nums):
            ma[val].append(i)
        ans = len(nums) - 1
        for num, positions in ma.items():
            thisMax = positions[0] + len(nums) - positions[-1]
            for i in range(1, len(positions)):
                thisMax = max(thisMax, positions[i] - positions[i - 1])
            ans = min(ans, thisMax // 2)
        return ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2024/01/30/LeetCode%202808.%E4%BD%BF%E5%BE%AA%E7%8E%AF%E6%95%B0%E7%BB%84%E6%89%80%E6%9C%89%E5%85%83%E7%B4%A0%E7%9B%B8%E7%AD%89%E7%9A%84%E6%9C%80%E5%B0%91%E7%A7%92%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135930013](https://letmefly.blog.csdn.net/article/details/135930013)
