---
title: 1608.特殊数组的特征值
date: 2022-09-12 09:32:58
tags: [题解, LeetCode, 简单, 数组, 二分查找, 排序, 暴力, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】1608.特殊数组的特征值

力扣题目链接：[https://leetcode.cn/problems/special-array-with-x-elements-greater-than-or-equal-x/](https://leetcode.cn/problems/special-array-with-x-elements-greater-than-or-equal-x/)

<p>给你一个非负整数数组 <code>nums</code> 。如果存在一个数 <code>x</code> ，使得 <code>nums</code> 中恰好有 <code>x</code> 个元素 <strong>大于或者等于</strong> <code>x</code> ，那么就称 <code>nums</code> 是一个 <strong>特殊数组</strong> ，而 <code>x</code> 是该数组的 <strong>特征值</strong> 。</p>

<p>注意： <code>x</code> <strong>不必</strong> 是 <code>nums</code> 的中的元素。</p>

<p>如果数组 <code>nums</code> 是一个 <strong>特殊数组</strong> ，请返回它的特征值 <code>x</code> 。否则，返回<em> </em><code>-1</code> 。可以证明的是，如果 <code>nums</code> 是特殊数组，那么其特征值 <code>x</code> 是 <strong>唯一的</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [3,5]
<strong>输出：</strong>2
<strong>解释：</strong>有 2 个元素（3 和 5）大于或等于 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [0,0]
<strong>输出：</strong>-1
<strong>解释：</strong>没有满足题目要求的特殊数组，故而也不存在特征值 x 。
如果 x = 0，应该有 0 个元素 &gt;= x，但实际有 2 个。
如果 x = 1，应该有 1 个元素 &gt;= x，但实际有 0 个。
如果 x = 2，应该有 2 个元素 &gt;= x，但实际有 0 个。
x 不能取更大的值，因为 nums 中只有两个元素。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [0,4,3,0,4]
<strong>输出：</strong>3
<strong>解释：</strong>有 3 个元素大于或等于 3 。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>nums = [3,6,7,7,0]
<strong>输出：</strong>-1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
</ul>


    
## 方法一：枚举答案，O(n^2), O(1)

从0到n枚举答案，每次枚举答案ans时，遍历一遍元素数组，统计大于等于ans的元素的个数。如果正好等于ans，就返回ans。

遍历完未找到答案则返回-1。

+ 时间复杂度$O(n^2)$，其中$n$是数组中元素的个数
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int specialArray(vector<int>& nums) {
        for (int ans = 0; ans <= nums.size(); ans++) {
            int cnt = 0;
            for (int& t : nums) {
                cnt += t >= ans;
            }
            if (cnt == ans) {
                return ans;
            }
        }
        return -1;
    }
};
```


## 方法二：排序+遍历，O(n log n), O(log n)

将数组元素从大到小排序，之后从$1$到$n$枚举答案。

如果ans为答案，那么数组中大于等于ans的元素个数为ans。也就是说，nums的前ans个元素都大于等于ans，剩余元素都小于ans。

因此，如果nums[ans - 1] >= ans（前ans个元素）并且nums[ans] < ans（剩余元素），就说明ans是答案。

若未找到答案则返回-1。

+ 时间复杂度$O(n \log n)$，其中$n$是数组中元素的个数
+ 空间复杂度$O(\log n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        for (int ans = 1; ans <= nums.size(); ans++) {
            if (nums[ans - 1] >= ans && (ans == nums.size() || nums[ans] < ans)) {
                return ans;
            }
        }
        return -1;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/09/12/LeetCode%201608.%E7%89%B9%E6%AE%8A%E6%95%B0%E7%BB%84%E7%9A%84%E7%89%B9%E5%BE%81%E5%80%BC/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126813374](https://letmefly.blog.csdn.net/article/details/126813374)
