---
title: 2859.计算 K 置位下标对应元素的和
date: 2024-01-25 08:59:34
tags: [题解, LeetCode, 简单, 位运算, 数组, 遍历, 模拟, 二进制, 位运算]
---

# 【LetMeFly】2859.计算 K 置位下标对应元素的和：遍历（附Python一行代码版）

力扣题目链接：[https://leetcode.cn/problems/sum-of-values-at-indices-with-k-set-bits/](https://leetcode.cn/problems/sum-of-values-at-indices-with-k-set-bits/)

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 和一个整数 <code>k</code> 。</p>

<p>请你用整数形式返回 <code>nums</code> 中的特定元素之 <strong>和</strong> ，这些特定元素满足：其对应下标的二进制表示中恰存在 <code>k</code> 个置位。</p>

<p>整数的二进制表示中的 1 就是这个整数的 <strong>置位</strong> 。</p>

<p>例如，<code>21</code> 的二进制表示为 <code>10101</code> ，其中有 <code>3</code> 个置位。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,10,1,5,2], k = 1
<strong>输出：</strong>13
<strong>解释：</strong>下标的二进制表示是： 
0 = 000<sub>2</sub>
1 = 001<sub>2</sub>
2 = 010<sub>2</sub>
3 = 011<sub>2</sub>
4 = 100<sub>2 
</sub>下标 1、2 和 4 在其二进制表示中都存在 k = 1 个置位。
因此，答案为 nums[1] + nums[2] + nums[4] = 13 。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,3,2,1], k = 2
<strong>输出：</strong>1
<strong>解释：</strong>下标的二进制表示是： 
0 = 00<sub>2</sub>
1 = 01<sub>2</sub>
2 = 10<sub>2</sub>
3 = 11<sub>2
</sub>只有下标 3 的二进制表示中存在 k = 2 个置位。
因此，答案为 nums[3] = 1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10</code></li>
</ul>


    
## 方法一：遍历

遍历数组的下标，如果数组下标```i```的二进制中有```k```个```1```，则将```nums[i]```添加到数组中。

+ 时间复杂度$O(len(nums[i]))$，数组的最大长度为```1000```，且内置函数效率很高，暂不考虑```log(i)```带来的复杂度。
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (__builtin_popcount(i) == k) {
                ans += nums[i];
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
    def sumIndicesWithKSetBits(self, nums: List[int], k: int) -> int:
        return sum(nums[i] if bin(i).count('1') == k else 0 for i in range(len(nums)))
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/01/25/LeetCode%202859.%E8%AE%A1%E7%AE%97K%E7%BD%AE%E4%BD%8D%E4%B8%8B%E6%A0%87%E5%AF%B9%E5%BA%94%E5%85%83%E7%B4%A0%E7%9A%84%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135836080](https://letmefly.blog.csdn.net/article/details/135836080)
