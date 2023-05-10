---
title: 1331.数组序号转换
date: 2022-07-28 10:48:43
tags: [题解, LeetCode, 简单, 数组, 哈希表, 排序, sort]
---

# 【LetMeFly】1331.数组序号转换

力扣题目链接：[https://leetcode.cn/problems/rank-transform-of-an-array/](https://leetcode.cn/problems/rank-transform-of-an-array/)

<p>给你一个整数数组&nbsp;<code>arr</code> ，请你将数组中的每个元素替换为它们排序后的序号。</p>

<p>序号代表了一个元素有多大。序号编号的规则如下：</p>

<ul>
	<li>序号从 1 开始编号。</li>
	<li>一个元素越大，那么序号越大。如果两个元素相等，那么它们的序号相同。</li>
	<li>每个数字的序号都应该尽可能地小。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [40,10,20,30]
<strong>输出：</strong>[4,1,2,3]
<strong>解释：</strong>40 是最大的元素。 10 是最小的元素。 20 是第二小的数字。 30 是第三小的数字。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [100,100,100]
<strong>输出：</strong>[1,1,1]
<strong>解释：</strong>所有元素有相同的序号。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [37,12,28,9,100,56,80,5,12]
<strong>输出：</strong>[5,3,4,2,8,6,7,1,3]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= arr.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup>&nbsp;&lt;= arr[i] &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 方法一：sort + 哈希表

首先把原始数组拷贝一份到临时数组中，并对临时数组进行排序

排序后，遍历一遍临时数组，把名次记录下来（用一个变量last来存放上一个值，若这个值与上一个不同就名次+1）到哈希表中

遍历原始数组，把值修改“从哈希表中映射为名次后的值”

+ 时间复杂度$O(n\log n)$，其中$n$是数组中元素个数。排序耗时$n\log n$
+ 空间复杂度$O(N\log N)$。哈希表、排序和临时数组消耗空间都是$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> toSort = arr;
        sort(toSort.begin(), toSort.end());
        unordered_map<int, int> ma;
        int th = 0;
        int last = -1e9 - 1;
        for (int i = 0; i < toSort.size(); i++) {
            if (toSort[i] == last)
                continue;
            ma[toSort[i]] = ++th;
            last = toSort[i];
        }
        for (int& t : arr) {
            t = ma[t];
        }
        return arr;
    }
};
```

#### Python

语法糖真简洁

Python代码 Copy From [力扣官方题解](https://leetcode.cn/problems/rank-transform-of-an-array/solution/shu-zu-xu-hao-zhuan-huan-by-leetcode-sol-8zlu/)

```python
class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        ranks = {v: i for i, v in enumerate(sorted(set(arr)), 1)}
        return [ranks[v] for v in arr]
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/07/28/LeetCode%201331.%E6%95%B0%E7%BB%84%E5%BA%8F%E5%8F%B7%E8%BD%AC%E6%8D%A2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126030218](https://letmefly.blog.csdn.net/article/details/126030218)
