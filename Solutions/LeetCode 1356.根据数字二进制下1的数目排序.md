---
title: 1356.根据数字二进制下 1 的数目排序：自定义排序模拟
date: 2026-02-25 21:40:19
tags: [题解, LeetCode, 简单, 位运算, 数组, 计数, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】1356.根据数字二进制下 1 的数目排序：自定义排序模拟

力扣题目链接：[https://leetcode.cn/problems/sort-integers-by-the-number-of-1-bits/](https://leetcode.cn/problems/sort-integers-by-the-number-of-1-bits/)

<p>给你一个整数数组&nbsp;<code>arr</code>&nbsp;。请你将数组中的元素按照其二进制表示中数字 <strong>1</strong> 的数目升序排序。</p>

<p>如果存在多个数字二进制中&nbsp;<strong>1</strong>&nbsp;的数目相同，则必须将它们按照数值大小升序排列。</p>

<p>请你返回排序后的数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [0,1,2,3,4,5,6,7,8]
<strong>输出：</strong>[0,1,2,4,8,3,5,6,7]
<strong>解释：</strong>[0] 是唯一一个有 0 个 1 的数。
[1,2,4,8] 都有 1 个 1 。
[3,5,6] 有 2 个 1 。
[7] 有 3 个 1 。
按照 1 的个数排序得到的结果数组为 [0,1,2,4,8,3,5,6,7]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [1024,512,256,128,64,32,16,8,4,2,1]
<strong>输出：</strong>[1,2,4,8,16,32,64,128,256,512,1024]
<strong>解释：</strong>数组中所有整数二进制下都只有 1 个 1 ，所以你需要按照数值大小将它们排序。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [10000,10000]
<strong>输出：</strong>[10000,10000]
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>arr = [2,3,5,7,11,13,17,19]
<strong>输出：</strong>[2,3,5,17,7,11,13,19]
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>arr = [10,100,1000,10000]
<strong>输出：</strong>[10,100,10000,1000]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 500</code></li>
	<li><code>0 &lt;= arr[i] &lt;= 10^4</code></li>
</ul>


    
## 解题方法：排序

按题意排序就好。

+ 时间复杂度$O(n\log n)$，其中$n=len(arr)$，忽略内置函数计算整数二进制下所含1个数的时间复杂度
+ 空间复杂度$O(\log n)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-02-25 21:37:54
 */
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](const int& a, const int& b) {
            int ca = __builtin_popcount(a);
            int cb = __builtin_popcount(b);
            return ca != cb ? ca < cb : a < b;
        });
        return arr;
    }
};

```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/158393403)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/02/25/LeetCode%201356.%E6%A0%B9%E6%8D%AE%E6%95%B0%E5%AD%97%E4%BA%8C%E8%BF%9B%E5%88%B6%E4%B8%8B1%E7%9A%84%E6%95%B0%E7%9B%AE%E6%8E%92%E5%BA%8F/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
