---
title: 1390.四因数：因数分解+缓存
date: 2026-01-04 18:53:46
tags: [题解, LeetCode, 中等, 数组, 数学]
categories: [题解, LeetCode]
---

# 【LetMeFly】1390.四因数：因数分解+缓存

力扣题目链接：[https://leetcode.cn/problems/four-divisors/](https://leetcode.cn/problems/four-divisors/)

<p>给你一个整数数组 <code>nums</code>，请你返回该数组中恰有四个因数的这些整数的各因数之和。如果数组中不存在满足题意的整数，则返回 <code>0</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [21,4,7]
<strong>输出：</strong>32
<strong>解释：</strong>
21 有 4 个因数：1, 3, 7, 21
4 有 3 个因数：1, 2, 4
7 有 2 个因数：1, 7
答案仅为 21 的所有因数的和。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = [21,21]
<strong>输出:</strong> 64
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,2,3,4,5]
<strong>输出:</strong> 0</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法：因数分解

如何求一个数$n$有多少个因数？

> 用变量$i$从$1$到$\lfloor\sqrt{n}\rfloor$遍历，如果$i$能整除$n$，则因数个数加二。
>
> 特别的，如果$n$是完全平方数，则前面运算中$\sqrt{n}$多统计了一次，要减去。

由于不同的测试用例可能会出现相同的数，所以可以使用一个“全局”缓存或类中的静态变量来避免重复计算。

+ 时间复杂度：单个测试用例$O(n)$，所有测试用例总体还需加上$O(m\log m)$，其中$m=\max(nums[i])$
+ 空间复杂度$O(m)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-01-04 18:51:38
 */
class Solution {
private:
    static unordered_map<int, int> cache;

    int gen(int n) {
        if (cache.count(n)) {
            return cache[n];
        }

        int cnt = 0, sum = 0;
        int k = sqrt(n);
        for (int i = 1; i <= k; i++) {
            if (n % i == 0) {
                cnt += 2;
                sum += i + n / i;
            }
        }
        if (k * k == n) {
            cnt--, sum -= k;
        }
        return cache[n] = cnt == 4 ? sum : 0;
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int t : nums) {
            ans += gen(t);
        }
        return ans;
    }
};

unordered_map<int, int> Solution::cache;
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/156575425)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/01/04/LeetCode%201390.%E5%9B%9B%E5%9B%A0%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
