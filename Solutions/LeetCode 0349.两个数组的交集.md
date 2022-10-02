---
title: 349.两个数组的交集
date: 2022-10-02 09:09:25
tags: [题解, LeetCode, 简单, 数组, 哈希表, 哈希, 双指针, 二分查找, 排序]
---

# 【LetMeFly】349.两个数组的交集

力扣题目链接：[https://leetcode.cn/problems/intersection-of-two-arrays/](https://leetcode.cn/problems/intersection-of-two-arrays/)

<p>给定两个数组&nbsp;<code>nums1</code>&nbsp;和&nbsp;<code>nums2</code> ，返回 <em>它们的交集</em>&nbsp;。输出结果中的每个元素一定是 <strong>唯一</strong> 的。我们可以 <strong>不考虑输出结果的顺序</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [1,2,2,1], nums2 = [2,2]
<strong>输出：</strong>[2]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [4,9,5], nums2 = [9,4,9,8,4]
<strong>输出：</strong>[9,4]
<strong>解释：</strong>[4,9] 也是可通过的
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 1000</code></li>
</ul>


    
## 方法一：哈希

首先遍历一遍第一个数组，将第一个数组中的元素存入哈希表中

接着将第二个数组排序去重，如果第二个数组中的某个元素在哈希表中存在，那么就将这个元素放到答案数组中。

+ 时间复杂度$O(n+m\log m)$，其中$n$是第一个数组中元素的个数，$m$是第二个数组中元素的个数
+ 空间复杂度$O(n + \log m)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> se;
        for (int& t : nums1) {
            se.insert(t);
        }
        sort(nums2.begin(), nums2.end());
        auto end = unique(nums2.begin(), nums2.end());
        vector<int> ans;
        for (auto it = nums2.begin(); it < end; it++) {
            if (se.count(*it))
                ans.push_back(*it);
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/10/02/LeetCode%200349.%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%BB%84%E7%9A%84%E4%BA%A4%E9%9B%86/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127139979](https://letmefly.blog.csdn.net/article/details/127139979)
