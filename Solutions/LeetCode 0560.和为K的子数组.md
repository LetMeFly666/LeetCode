---
title: 560.和为 K 的子数组
date: 2023-03-15 10:32:36
tags: [题解, LeetCode, 中等, 数组, 哈希表, 哈希, map, 前缀和]
categories: [题解, LeetCode]
---

# 【LetMeFly】560.和为 K 的子数组

力扣题目链接：[https://leetcode.cn/problems/subarray-sum-equals-k/](https://leetcode.cn/problems/subarray-sum-equals-k/)

<p>给你一个整数数组 <code>nums</code> 和一个整数&nbsp;<code>k</code> ，请你统计并返回 <em>该数组中和为&nbsp;<code>k</code><strong>&nbsp;</strong>的子数组的个数&nbsp;</em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,1], k = 2
<strong>输出：</strong>2
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3], k = 3
<strong>输出：</strong>2
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>-1000 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code>-10<sup>7</sup> &lt;= k &lt;= 10<sup>7</sup></code></li>
</ul>


    
## 方法一：哈希 + 前缀和

使用cnt记录遍历过程中的所有元素的和，使用哈希表统计当前cnt出现过的次数。

既然当前的前缀和为cnt，那么假如前面存在为$cnt - k$的前缀和的话，这两个位置之间的子数组的和就为$k$

因此，我们直接将$cnt - k$在哈希表中出现的次数累加到答案中即可

动画演示可见[官解](https://leetcode.cn/problems/subarray-sum-equals-k/solutions/238572/he-wei-kde-zi-shu-zu-by-leetcode-solution/)方法二的动图

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> ma;
        ma[0] = 1;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt += nums[i];
            if (ma.count(cnt - k)) {
                ans += ma[cnt - k];
            }
            ma[cnt]++;
        }
        return ans;
    }
};
```

#### Python

```python
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        ans = 0
        ma = defaultdict(int)
        ma[0] = 1
        cnt = 0
        for n in nums:
            cnt += n
            if cnt - k in ma:
                ans += ma[cnt - k]
            ma[cnt] += 1
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/03/15/LeetCode%200560.%E5%92%8C%E4%B8%BAK%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129547610](https://letmefly.blog.csdn.net/article/details/129547610)
