---
title: 2341.数组能形成多少数对
date: 2023-02-16 09:55:01
tags: [题解, LeetCode, 简单, 数组, 哈希表, 哈希, 计数]
categories: [题解, LeetCode]
---

# 【LetMeFly】2341.数组能形成多少数对

力扣题目链接：[https://leetcode.cn/problems/maximum-number-of-pairs-in-array/](https://leetcode.cn/problems/maximum-number-of-pairs-in-array/)

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 。在一步操作中，你可以执行以下步骤：</p>

<ul>
	<li>从 <code>nums</code> 选出 <strong>两个</strong> <strong>相等的</strong> 整数</li>
	<li>从 <code>nums</code> 中移除这两个整数，形成一个 <strong>数对</strong></li>
</ul>

<p>请你在 <code>nums</code> 上多次执行此操作直到无法继续执行。</p>

<p>返回一个下标从 <strong>0</strong> 开始、长度为 <code>2</code> 的整数数组 <code>answer</code> 作为答案，其中<em> </em><code>answer[0]</code><em> </em>是形成的数对数目，<code>answer[1]</code> 是对 <code>nums</code> 尽可能执行上述操作后剩下的整数数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,3,2,1,3,2,2]
<strong>输出：</strong>[3,1]
<strong>解释：</strong>
nums[0] 和 nums[3] 形成一个数对，并从 nums 中移除，nums = [3,2,3,2,2] 。
nums[0] 和 nums[2] 形成一个数对，并从 nums 中移除，nums = [2,2,2] 。
nums[0] 和 nums[1] 形成一个数对，并从 nums 中移除，nums = [2] 。
无法形成更多数对。总共形成 3 个数对，nums 中剩下 1 个数字。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,1]
<strong>输出：</strong>[1,0]
<strong>解释：</strong>nums[0] 和 nums[1] 形成一个数对，并从 nums 中移除，nums = [] 。
无法形成更多数对。总共形成 1 个数对，nums 中剩下 0 个数字。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [0]
<strong>输出：</strong>[0,1]
<strong>解释：</strong>无法形成数对，nums 中剩下 1 个数字。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 100</code></li>
</ul>


    
## 方法一：哈希表

我们可以使用一个哈希表来统计某个数x是否出现过。（开辟长度为100的数组来统计也可以）

初始时哈希表为空，接着遍历原始数组，如果数组中的某个数在哈希表中，则“配对成功”，成功次数加一并将这个数从哈希表中移除；否则直接将这个数插入哈希表中等待配对即可。

最终返回${配对成功次数, 原始数组长度 - 2\times 配对成功次数}$即可

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_set<int> se;
        int cntPair = 0;
        for (int& t : nums) {
            if (se.count(t)) {
                se.erase(t);
                cntPair++;
            }
            else {
                se.insert(t);
            }
        }
        return {cntPair, (int)nums.size() - cntPair * 2};
    }
};
```

#### Python

```python
# from typing import List


class Solution:
    def numberOfPairs(self, nums: List[int]) -> List[int]:
        se = set()
        cntPair = 0
        for i in nums:
            if i in se:
                se.remove(i)
                cntPair += 1
            else:
                se.add(i)
        return [cntPair, len(nums) - cntPair * 2]
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/02/16/LeetCode%202341.%E6%95%B0%E7%BB%84%E8%83%BD%E5%BD%A2%E6%88%90%E5%A4%9A%E5%B0%91%E6%95%B0%E5%AF%B9/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129055398](https://letmefly.blog.csdn.net/article/details/129055398)
