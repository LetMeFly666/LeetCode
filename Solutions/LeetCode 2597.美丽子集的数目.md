---
title: 2597.美丽子集的数目：二进制枚举-一个实现起来容易但非最优的方法
date: 2025-03-08 00:11:06
tags: [题解, LeetCode, 中等, 数组, 哈希表, 数学, 动态规划, 回溯, 组合数学, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】2597.美丽子集的数目：二进制枚举-一个实现起来容易但非最优的方法

力扣题目链接：[https://leetcode.cn/problems/the-number-of-beautiful-subsets/](https://leetcode.cn/problems/the-number-of-beautiful-subsets/)

<p>给你一个由正整数组成的数组 <code>nums</code> 和一个 <strong>正</strong> 整数 <code>k</code> 。</p>

<p>如果 <code>nums</code> 的子集中，任意两个整数的绝对差均不等于 <code>k</code> ，则认为该子数组是一个 <strong>美丽</strong> 子集。</p>

<p>返回数组 <code>nums</code> 中 <strong>非空</strong> 且 <strong>美丽</strong> 的子集数目。</p>

<p><code>nums</code> 的子集定义为：可以经由 <code>nums</code> 删除某些元素（也可能不删除）得到的一个数组。只有在删除元素时选择的索引不同的情况下，两个子集才会被视作是不同的子集。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [2,4,6], k = 2
<strong>输出：</strong>4
<strong>解释：</strong>数组 nums 中的美丽子集有：[2], [4], [6], [2, 6] 。
可以证明数组 [2,4,6] 中只存在 4 个美丽子集。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1], k = 1
<strong>输出：</strong>1
<strong>解释：</strong>数组 nums 中的美丽数组有：[1] 。
可以证明数组 [1] 中只存在 1 个美丽子集。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 20</code></li>
	<li><code>1 &lt;= nums[i], k &lt;= 1000</code></li>
</ul>


    
## 解题方法：二进制枚举

使用二进制下长度为$len(nums)$的一个数，第$i$位为$0$代表选择$nums[i]$否则代表不选$nums[i]$。

从$1$到$2^{len(nums)}$枚举这个数，就能得到所有的非空子集。

对于每个子集，暴力判断是否存在两个数只差为$k$即可。

+ 时间复杂度$O(2^nk^2)$，其中$n=len(nums)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-07 23:32:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-07 23:49:07
 * @Description: AC,6771ms击败5.56%,567.46MB击败5.56%
 */
class Solution {
private:
    bool isok(vector<int>& v, int k) {
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                if (abs(v[i] - v[j]) == k) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size(), end = 1 << n;
        for (int i = 1; i < end; i++) {
            vector<int> v;
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) {
                    v.push_back(nums[j]);
                }
            }
            ans += isok(v, k);
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/146108576)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/03/07/LeetCode%202597.%E7%BE%8E%E4%B8%BD%E5%AD%90%E9%9B%86%E7%9A%84%E6%95%B0%E7%9B%AE/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
