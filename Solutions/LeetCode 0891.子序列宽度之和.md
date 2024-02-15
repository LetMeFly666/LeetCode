---
title: 891.子序列宽度之和
date: 2022-11-18 09:39:55
tags: [题解, LeetCode, 困难, 数组, 数学, 排序, 贡献]
---

# 【LetMeFly】891.子序列宽度之和

力扣题目链接：[https://leetcode.cn/problems/sum-of-subsequence-widths/](https://leetcode.cn/problems/sum-of-subsequence-widths/)

<p>一个序列的 <strong>宽度</strong> 定义为该序列中最大元素和最小元素的差值。</p>

<p>给你一个整数数组 <code>nums</code> ，返回 <code>nums</code> 的所有非空 <strong>子序列</strong> 的 <strong>宽度之和</strong> 。由于答案可能非常大，请返回对 <code>10<sup>9</sup> + 7</code> <strong>取余</strong> 后的结果。</p>

<p><strong>子序列</strong> 定义为从一个数组里删除一些（或者不删除）元素，但不改变剩下元素的顺序得到的数组。例如，<code>[3,6,2,7]</code> 就是数组 <code>[0,3,1,6,2,2,7]</code> 的一个子序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,1,3]
<strong>输出：</strong>6
<strong>解释：</strong>子序列为 [1], [2], [3], [2,1], [2,3], [1,3], [2,1,3] 。
相应的宽度是 0, 0, 0, 1, 1, 2, 2 。
宽度之和是 6 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 方法一：排序求贡献

本题只关注序列的最大值和最小值，同时，“序列”是不要求“连续”的

因此答案和数组中元素的顺序无关，我们可以对数组先排个序

排序之后，对于下标为$i$的元素，以$nums[i]$为最**大**值的子序列个数为$2^i$个（不考虑两个元素相等的情况），因此$nums[i]$对答案的贡献有$2^i\times nums[i]$；以$nums[i]$为最**小**值的子序列个数为$2^{n - i - 1}$个，因此$nums[i]$对答案的贡献有$-2^{n - i - 1}\times nums[i]$

```
1 5 7 9
    ↑
    下标为2
    以nums[2]为最大值的子序列有：[7], [1, 7], [5, 7], [1, 5, 7]共4个
    以nums[2]为最小值的子序列有：[7], [7, 9]共2个
    这里不需要考虑7计算两次的情况，因为单独一个[7]的“宽度”为0
    这里不需要考虑元素相等的情况。假如原数组为1, 7, 7, 9，那么计算结果是不受影响的
```

我们可以预处理求得$2^i$，也可以使用快速幂

+ 时间复杂度$O(n\log n)$，其中$n$是数组中原神的个数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
typedef long long ll;
const ll MOD = 1e9 + 7;
class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        ll ans = 0;
        int n = nums.size();
        vector<ll> Pow(n);
        Pow[0] = 1;
        for (int i = 1; i < n; i++)
            Pow[i] = (Pow[i - 1] * 2) % MOD;
        for (int i = 0; i < n; i++) {
            ans = (ans + (Pow[i] - Pow[n - i - 1]) * nums[i]) % MOD;
        }
        return (ans % MOD + MOD) % MOD;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/11/18/LeetCode%200891.%E5%AD%90%E5%BA%8F%E5%88%97%E5%AE%BD%E5%BA%A6%E4%B9%8B%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127916253](https://letmefly.blog.csdn.net/article/details/127916253)
