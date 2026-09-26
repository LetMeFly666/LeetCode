---
title: 1846.减小和重新排列数组后的最大元素：排序(5行代码搞定)(贪心)
date: 2026-06-28 20:02:30
tags: [题解, LeetCode, 中等, 贪心, 数组, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】1846.减小和重新排列数组后的最大元素：排序(5行代码搞定)(贪心)

力扣题目链接：[https://leetcode.cn/problems/maximum-element-after-decreasing-and-rearranging/](https://leetcode.cn/problems/maximum-element-after-decreasing-and-rearranging/)

<p>给你一个正整数数组 <code>arr</code> 。请你对 <code>arr</code> 执行一些操作（也可以不进行任何操作），使得数组满足以下条件：</p>

<ul>
	<li><code>arr</code> 中 <strong>第一个</strong> 元素必须为 <code>1</code> 。</li>
	<li>任意相邻两个元素的差的绝对值 <strong>小于等于</strong> <code>1</code> ，也就是说，对于任意的 <code>1 <= i < arr.length</code> （<strong>数组下标从 0 开始</strong>），都满足 <code>abs(arr[i] - arr[i - 1]) <= 1</code> 。<code>abs(x)</code> 为 <code>x</code> 的绝对值。</li>
</ul>

<p>你可以执行以下 2 种操作任意次：</p>

<ul>
	<li><strong>减小</strong> <code>arr</code> 中任意元素的值，使其变为一个 <strong>更小的正整数</strong> 。</li>
	<li><strong>重新排列</strong> <code>arr</code> 中的元素，你可以以任意顺序重新排列。</li>
</ul>

<p>请你返回执行以上操作后，在满足前文所述的条件下，<code>arr</code> 中可能的 <strong>最大值</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>arr = [2,2,1,2,1]
<b>输出：</b>2
<b>解释：</b>
我们可以重新排列 arr 得到 <code>[1,2,2,2,1] ，该数组满足所有条件。</code>
arr 中最大元素为 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>arr = [100,1,1000]
<b>输出：</b>3
<b>解释：</b>
一个可行的方案如下：
1. 重新排列 <code>arr</code> 得到 <code>[1,100,1000] 。</code>
2. 将第二个元素减小为 2 。
3. 将第三个元素减小为 3 。
现在 <code>arr = [1,2,3] ，满足所有条件。</code>
arr 中最大元素为 3 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>arr = [1,2,3,4,5]
<b>输出：</b>5
<b>解释：</b>数组已经满足所有条件，最大元素为 5 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= arr.length <= 10<sup>5</sup></code></li>
	<li><code>1 <= arr[i] <= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：排序

使用一个变量$ans$代表答案（合法数组能达到的最大值），$ans$初始值为$0$。

将$arr$数组从小到大排序，遍历$arr$数组，如果当前元素大于$ans$则将当前元素和$ans$都变成$ans+1$。

最后直接返回$ans$就好。

+ 时间复杂度$O(n\log n)$，其中$n=len(arr)$
+ 空间复杂度$O(\log n)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-06-28 20:00:21
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int ans = 0;
        for (int t : arr) {
            ans += t > ans;
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/162397229)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/06/28/LeetCode%201846.%E5%87%8F%E5%B0%8F%E5%92%8C%E9%87%8D%E6%96%B0%E6%8E%92%E5%88%97%E6%95%B0%E7%BB%84%E5%90%8E%E7%9A%84%E6%9C%80%E5%A4%A7%E5%85%83%E7%B4%A0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
