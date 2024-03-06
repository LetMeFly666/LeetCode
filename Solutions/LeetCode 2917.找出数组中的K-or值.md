---
title: 2917.找出数组中的 K-or 值
date: 2024-03-06 09:55:09
tags: [题解, LeetCode, 简单, 位运算, 数组]
---

# 【LetMeFly】2917.找出数组中的 K-or 值：基础位运算

力扣题目链接：[https://leetcode.cn/problems/find-the-k-or-of-an-array/](https://leetcode.cn/problems/find-the-k-or-of-an-array/)

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 和一个整数 <code>k</code> 。</p>

<p><code>nums</code> 中的 <strong>K-or</strong> 是一个满足以下条件的非负整数：</p>

<ul>
	<li>只有在 <code>nums</code> 中，至少存在 <code>k</code> 个元素的第 <code>i</code> 位值为 1 ，那么 K-or 中的第 <code>i</code> 位的值才是 1 。</li>
</ul>

<p>返回 <code>nums</code> 的 <strong>K-or</strong> 值。</p>

<p><strong>注意</strong> ：对于整数 <code>x</code> ，如果&nbsp;<code>(2<sup>i</sup> AND x) == 2<sup>i</sup></code> ，则 <code>x</code> 中的第 <code>i</code> 位值为 1 ，其中 <code>AND</code> 为按位与运算符。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [7,12,9,8,9,15], k = 4
<strong>输出：</strong>9
<strong>解释：</strong>nums[0]、nums[2]、nums[4] 和 nums[5] 的第 0 位的值为 1 。
nums[0] 和 nums[5] 的第 1 位的值为 1 。
nums[0]、nums[1] 和 nums[5] 的第 2 位的值为 1 。
nums[1]、nums[2]、nums[3]、nums[4] 和 nums[5] 的第 3 位的值为 1 。
只有第 0 位和第 3 位满足数组中至少存在 k 个元素在对应位上的值为 1 。因此，答案为 2^0 + 2^3 = 9 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,12,1,11,4,5], k = 6
<strong>输出：</strong>0
<strong>解释：</strong>因为 k == 6 == nums.length ，所以数组的 6-or 等于其中所有元素按位与运算的结果。因此，答案为 2 AND 12 AND 1 AND 11 AND 4 AND 5 = 0 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [10,8,5,9,11,6,8], k = 1
<strong>输出：</strong>15
<strong>解释：</strong>因为 k == 1 ，数组的 1-or 等于其中所有元素按位或运算的结果。因此，答案为 10 OR 8 OR 5 OR 9 OR 11 OR 6 OR 8 = 15 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 50</code></li>
	<li><code>0 &lt;= nums[i] &lt; 2<sup>31</sup></code></li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>
</ul>


    
## 方法一：基础位运算

想<span title="Accepted">AC</span>这道题，只需要懂得两个位运算操作：

1. 计算$t$二进制下第$i+1$位**是否为**$1$：$(t >> i) & 1$
2. 将$ans$二进制下的第$i+1$位**置为**$1$：$ans |= (1 << i)$

因$0\leq nums[i] \le 2^{31}$，所以用变量$i$从$0$到$30$枚举每一位，统计所有数字中这一位为$1$的个数，若达到$k$则令答案的这一位为$1$。

+ 时间复杂度$O(len(nums)\times \log nums[i])$，其中$\log nums[i]=31$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {  // nums[i] < 2^31不是≤，因此这里其实i = 0到i < 31即可
            int cnt = 0;
            for (int t : nums) {
                cnt += ((t >> i) & 1);
            }
            if (cnt >= k) {
                ans |= (1 << i);
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
    def findKOr(self, nums: List[int], k: int) -> int:
        ans = 0
        for i in range(31):
            cnt = 0
            for t in nums:
                cnt += ((t >> i) & 1)
            if cnt >= k:
                ans |= (1 << i)
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/03/06/LeetCode%202917.%E6%89%BE%E5%87%BA%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84K-or%E5%80%BC/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136497896](https://letmefly.blog.csdn.net/article/details/136497896)
