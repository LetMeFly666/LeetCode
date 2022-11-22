---
title: 523.连续的子数组和
date: 2022-11-22 11:14:02
tags: [题解, LeetCode, 中等, 数组, 哈希表, 哈希, 数学, 前缀和]
---

# 【LetMeFly】523.连续的子数组和

力扣题目链接：[https://leetcode.cn/problems/continuous-subarray-sum/](https://leetcode.cn/problems/continuous-subarray-sum/)

<p>给你一个整数数组 <code>nums</code> 和一个整数 <code>k</code> ，编写一个函数来判断该数组是否含有同时满足下述条件的连续子数组：</p>

<ul>
	<li>子数组大小 <strong>至少为 2</strong> ，且</li>
	<li>子数组元素总和为 <code>k</code> 的倍数。</li>
</ul>

<p>如果存在，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>如果存在一个整数 <code>n</code> ，令整数 <code>x</code> 符合 <code>x = n * k</code> ，则称 <code>x</code> 是 <code>k</code> 的一个倍数。<code>0</code> 始终视为 <code>k</code> 的一个倍数。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [23<u>,2,4</u>,6,7], k = 6
<strong>输出：</strong>true
<strong>解释：</strong>[2,4] 是一个大小为 2 的子数组，并且和为 6 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [<u>23,2,6,4,7</u>], k = 6
<strong>输出：</strong>true
<strong>解释：</strong>[23, 2, 6, 4, 7] 是大小为 5 的子数组，并且和为 42 。 
42 是 6 的倍数，因为 42 = 7 * 6 且 7 是一个整数。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [23,2,6,4,7], k = 13
<strong>输出：</strong>false
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>0 <= nums[i] <= 10<sup>9</sup></code></li>
	<li><code>0 <= sum(nums[i]) <= 2<sup>31</sup> - 1</code></li>
	<li><code>1 <= k <= 2<sup>31</sup> - 1</code></li>
</ul>


    
## 方法一：哈希 + 前缀和

首先求出原始数组的前缀和$prefix$。$prefix[i] = \sum_{j=0}^{j<i} nums[j]$（说人话就是：$prefix[i]$是$nums$前$i-1$个元素的和）

求出前缀和有什么意义呢？如果我们想知道$nums$数组从$l$到$r$的和$nums[l] + nums[l + 1] + nums[l + 2] + \cdots + nums[r]$，那么我们就可以用前缀和数组$prefix[r] - prefix[l - 1]$在$O(1)$的时间复杂度内求出。

好了，现在我们来看题目，题目要找到是“是否存在$nums$数组从$l$到$r$的和，这个和是$k$的整数倍，且$r > l$”

那么问题就等价于：“是否存在$l$和$r$满足$r>l$且$prefix[r] - prefix[l - 1]$是$k$的整数倍”

“$prefix[r] - prefix[l - 1]$是$k$的整数倍”则说明$prefix[r]$和$prefix[l - 1]$关于$k$同余。

等等，同余？

我们直接记录下$prefix$中每一个元素关于$k$的余数不就好了么

遍历一遍$prefix$数组，如果$prefix$中某个元素关于$k$的余数在之前出现过，那么就说明存在$prefix[i]$和$prefix[j]$，其中$j>i$且$prefix[i]$和$prefix[j]$关于$k$同余。

但是题目要求是$r>l$，也就是说需要满足“$j>i-1$”，即“$j-i\geq 2$”

因此，我们将$prefix[i]$关于$k$的余数，延迟两个元素再插入哈希表中即可。

+ 时间复杂度$O(n)$，其中$n$是数组中元素的个数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        unordered_set<int> se;
        for (int i = 2; i <= n; i++) {
            se.insert(prefix[i - 2] % k);
            if (se.count(prefix[i] % k))
                return true;
        }
        return false;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/11/22/LeetCode%200523.%E8%BF%9E%E7%BB%AD%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127979626](https://letmefly.blog.csdn.net/article/details/127979626)
