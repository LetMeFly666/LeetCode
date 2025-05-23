---
title: 1619.删除某些元素后的数组均值
date: 2022-09-14 13:37:08
tags: [题解, LeetCode, 简单, 数组, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】1619.删除某些元素后的数组均值

力扣题目链接：[https://leetcode.cn/problems/mean-of-array-after-removing-some-elements/](https://leetcode.cn/problems/mean-of-array-after-removing-some-elements/)

<p>给你一个整数数组 <code>arr</code> ，请你删除最小 <code>5%</code> 的数字和最大 <code>5%</code> 的数字后，剩余数字的平均值。</p>

<p>与 <strong>标准答案</strong> 误差在 <code>10<sup>-5</sup></code> 的结果都被视为正确结果。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>arr = [1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3]
<b>输出：</b>2.00000
<b>解释：</b>删除数组中最大和最小的元素后，所有元素都等于 2，所以平均值为 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>arr = [6,2,7,5,1,2,0,3,10,2,5,0,5,5,0,8,7,6,8,0]
<b>输出：</b>4.00000
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>arr = [6,0,7,0,7,5,7,8,3,4,0,7,8,1,6,8,1,1,2,4,8,1,9,5,4,3,8,5,10,8,6,6,1,0,6,10,8,2,3,4]
<b>输出：</b>4.77778
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<b>输入：</b>arr = [9,7,8,7,7,8,4,4,6,8,8,7,6,8,8,9,2,6,0,0,1,10,8,6,3,3,5,1,10,9,0,7,10,0,10,4,1,10,6,9,3,6,0,0,2,7,0,6,7,2,9,7,7,3,0,1,6,1,10,3]
<b>输出：</b>5.27778
</pre>

<p><strong>示例 5：</strong></p>

<pre>
<b>输入：</b>arr = [4,8,4,10,0,7,1,3,7,8,8,3,4,1,6,2,1,1,8,0,9,8,0,3,9,10,3,10,1,10,7,3,2,1,4,9,10,7,6,4,0,8,5,1,2,1,6,2,5,0,7,10,9,10,3,7,10,5,8,5,7,6,7,6,10,9,5,10,5,5,7,2,10,7,7,8,2,0,1,1]
<b>输出：</b>5.29167
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>20 <= arr.length <= 1000</code></li>
	<li><code>arr.length</code><b> </b>是 <code>20</code> 的<strong> 倍数</strong> </li>
	<li><code>0 <= arr[i] <= 10<sup>5</sup></code></li>
</ul>


    
## 方法一：排序

首先对原始数组进行排序，然后对中间部分求和，最后除以中间部分的元素个数即可。

+ 时间复杂度$O(n\log n)$，其中$n$是数组中元素的个数
+ 空间复杂度$O(\log n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int cnt = 0;
        int from = arr.size() * 0.05, to = arr.size() * 0.95;
        for (int i = from; i < to; i++) {
            cnt += arr[i];
        }
        return ((double) cnt) / (arr.size() * 0.9);
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/09/14/LeetCode%201619.%E5%88%A0%E9%99%A4%E6%9F%90%E4%BA%9B%E5%85%83%E7%B4%A0%E5%90%8E%E7%9A%84%E6%95%B0%E7%BB%84%E5%9D%87%E5%80%BC/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126850931](https://letmefly.blog.csdn.net/article/details/126850931)
