---
title: 915.分割数组
date: 2022-10-24 19:11:26
tags: [题解, LeetCode, 中等, 数组]
---

# 【LetMeFly】915.分割数组

力扣题目链接：[https://leetcode.cn/problems/partition-array-into-disjoint-intervals/](https://leetcode.cn/problems/partition-array-into-disjoint-intervals/)

<p>给定一个数组&nbsp;<code>nums</code>&nbsp;，将其划分为两个连续子数组&nbsp;<code>left</code>&nbsp;和&nbsp;<code>right</code>，&nbsp;使得：</p>

<ul>
	<li><code>left</code>&nbsp;中的每个元素都小于或等于&nbsp;<code>right</code>&nbsp;中的每个元素。</li>
	<li><code>left</code> 和&nbsp;<code>right</code>&nbsp;都是非空的。</li>
	<li><code>left</code> 的长度要尽可能小。</li>
</ul>

<p><em>在完成这样的分组后返回&nbsp;<code>left</code>&nbsp;的&nbsp;<strong>长度&nbsp;</strong></em>。</p>

<p>用例可以保证存在这样的划分方法。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,0,3,8,6]
<strong>输出：</strong>3
<strong>解释：</strong>left = [5,0,3]，right = [8,6]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,1,0,6,12]
<strong>输出：</strong>4
<strong>解释：</strong>left = [1,1,1,0]，right = [6,12]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
	<li>可以保证至少有一种方法能够按题目所描述的那样对 <code>nums</code> 进行划分。</li>
</ul>


    
## 方法一：遍历

如果某个位置是“正确的划分位置”，那么这个位置**右边**的所有元素都要大于这个位置**之前**的最大元素

如果这样的“切割”位置有多个，那么我们返回第一个

怎么确定这样的位置呢？我们只需要一个变量来记录当前位置及之前的最大值，如果在之后的遍历过程中，所有元素都大于等于这个最大值，那么这个位置就是答案。

否则，只要出现了右边元素比左边最大值小的情况，就要更新划分位置。

伪代码如下：

```cpp
int leftMax = nums[0], cutAfter = 0;  // 初始时在第一个元素后面划分
for i in [1, nums.size() - 1]:
    if nums[i] < leftMax:  // 需要重新划分
        cutAfter = i;  // 要把这个元素也划分到左边
        update(leftMax);
return cutAfter + 1;  // 因为下标是从0开始的
```

但是其中存在一个问题，就是当需要重新确定划分位置时，划分位置左边的最大值“leftMax”怎么快速确定呢？

如果从$0$到$i$遍历一遍，那么总的时间复杂度就变成了$O(n^2)$

好说好说，直接用一个变量来记录不就行了么？

我们添加一个变量“M”，用来代表从$0$到$i$的最大值

那么：

```cpp
int leftMax = nums[0], cutAfter = 0;  // 初始时在第一个元素后面划分
int M = nums[0];
for i in [1, nums.size() - 1]:
    M = max(M, nums[i]);
    if nums[i] < leftMax:  // 需要重新划分
        cutAfter = i;  // 要把这个元素也划分到左边
        leftMax = M;
return cutAfter + 1;  // 因为下标是从0开始的
```

+ 时间复杂度$O(n)$，其中$n$是元素个数
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        int M = nums[0], lM = M, ans = 1;
        for (int i = 1; i < n; i++) {
            M = max(M, nums[i]);
            if (nums[i] < lM) {
                lM = M, ans = i + 1;
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/10/24/LeetCode%200915.%E5%88%86%E5%89%B2%E6%95%B0%E7%BB%84/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127499260](https://letmefly.blog.csdn.net/article/details/127499260)
