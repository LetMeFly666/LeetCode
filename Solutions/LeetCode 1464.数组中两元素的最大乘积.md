---
title: 1464.数组中两元素的最大乘积
date: 2022-08-26 08:57:46
tags: [题解, LeetCode, 简单, 数组, 排序, 堆（优先队列）, 遍历]
---

# 【LetMeFly】1464.数组中两元素的最大乘积：（O(n)+O(1)）

力扣题目链接：[https://leetcode.cn/problems/maximum-product-of-two-elements-in-an-array/](https://leetcode.cn/problems/maximum-product-of-two-elements-in-an-array/)

<p>给你一个整数数组 <code>nums</code>，请你选择数组的两个不同下标 <code>i</code> 和 <code>j</code><em>，</em>使 <code>(nums[i]-1)*(nums[j]-1)</code> 取得最大值。</p>

<p>请你计算并返回该式的最大值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [3,4,5,2]
<strong>输出：</strong>12 
<strong>解释：</strong>如果选择下标 i=1 和 j=2（下标从 0 开始），则可以获得最大值，(nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12 。 
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,5,4,5]
<strong>输出：</strong>16
<strong>解释：</strong>选择下标 i=1 和 j=3（下标从 0 开始），则可以获得最大值 (5-1)*(5-1) = 16 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [3,7]
<strong>输出：</strong>12
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 500</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10^3</code></li>
</ul>


    
## 方法一：排序

初始时所有元素都大于等于1，因此元素减1都大于等于0。只要减1后不会为负数，就不需要考虑负负得正的问题。

因此，直接选取初始时就最大的两个数即可。

+ 时间复杂度$O(n\log n)$，其中$n$是元素个数
+ 空间复杂度$O(\log n)$，时空复杂度都主要来自排序

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        return (nums[0] - 1) * (nums[1] - 1);
    }
};
```

## 方法二：两次遍历（O(n) + O(1)）

与方法一同理，我们还是要找到数组中最大的两个数。

找到数组中最大的数，一次遍历即可。遍历过程中不断更新元素最大值，并更新最大位置的下标。

第二次遍历时，如果当前下标已经被第一次遍历时选择过了，就直接跳过。

这样，经过两次遍历后，我们就得到了数组中最大的两个数。

+ 时间复杂度$O(n)$，其中$n$是元素个数
+ 空间复杂度$O(1)$

运行结果空间使用确实少了一点，但是时间消耗倒是增加了。在$n$较小的时候，效果提升往往不明显，甚至会呈现副作用。

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0, locMax1 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max1) {
                max1 = nums[i];
                locMax1 = i;
            }
        }
        int max2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max2 && i != locMax1) {
                max2 = nums[i];
            }
        }
        return (max1 - 1) * (max2 - 1);
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/08/26/LeetCode%201464.%E6%95%B0%E7%BB%84%E4%B8%AD%E4%B8%A4%E5%85%83%E7%B4%A0%E7%9A%84%E6%9C%80%E5%A4%A7%E4%B9%98%E7%A7%AF/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126536351](https://letmefly.blog.csdn.net/article/details/126536351)
