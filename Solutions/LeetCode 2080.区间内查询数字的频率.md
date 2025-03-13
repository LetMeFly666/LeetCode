---
title: 2080.区间内查询数字的频率：哈希表+二分查找
date: 2025-02-18 10:56:27
tags: [题解, LeetCode, 中等, 设计, 线段树, 数组, 哈希表, 二分查找, map, 设计]
categories: [题解, LeetCode]
---

# 【LetMeFly】2080.区间内查询数字的频率：哈希表+二分查找

力扣题目链接：[https://leetcode.cn/problems/range-frequency-queries/](https://leetcode.cn/problems/range-frequency-queries/)

<p>请你设计一个数据结构，它能求出给定子数组内一个给定值的 <strong>频率</strong>&nbsp;。</p>

<p>子数组中一个值的 <strong>频率</strong>&nbsp;指的是这个子数组中这个值的出现次数。</p>

<p>请你实现&nbsp;<code>RangeFreqQuery</code>&nbsp;类：</p>

<ul>
	<li><code>RangeFreqQuery(int[] arr)</code>&nbsp;用下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>arr</code>&nbsp;构造一个类的实例。</li>
	<li><code>int query(int left, int right, int value)</code>&nbsp;返回子数组&nbsp;<code>arr[left...right]</code>&nbsp;中&nbsp;<code>value</code>&nbsp;的&nbsp;<strong>频率</strong>&nbsp;。</li>
</ul>

<p>一个 <strong>子数组</strong> 指的是数组中一段连续的元素。<code>arr[left...right]</code>&nbsp;指的是 <code>nums</code>&nbsp;中包含下标 <code>left</code>&nbsp;和 <code>right</code>&nbsp;<strong>在内</strong>&nbsp;的中间一段连续元素。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>
["RangeFreqQuery", "query", "query"]
[[[12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56]], [1, 2, 4], [0, 11, 33]]
<strong>输出：</strong>
[null, 1, 2]

<strong>解释：</strong>
RangeFreqQuery rangeFreqQuery = new RangeFreqQuery([12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56]);
rangeFreqQuery.query(1, 2, 4); // 返回 1 。4 在子数组 [33, 4] 中出现 1 次。
rangeFreqQuery.query(0, 11, 33); // 返回 2 。33 在整个子数组中出现 2 次。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= arr[i], value &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= left &lt;= right &lt; arr.length</code></li>
	<li>调用&nbsp;<code>query</code>&nbsp;不超过&nbsp;<code>10<sup>5</sup></code>&nbsp;次。</li>
</ul>


    
## 解题方法：哈希表+二分查找

遍历数组，将`value`出现的所有下标放到哈希表`ma[value]`这个数组中。这样，只需要查询`ma[value]`就能得到`value`的所有出现位置下标的递增数组。

接着二分查找这个数组，就能确定在`[left, right]`范围内的下标有几个了。

+ 时间复杂度：初始化$O(n)$，单次查询$O(\log n)$。其中$n=len(arr)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-02-18 10:08:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-18 10:15:30
 */
class RangeFreqQuery {
private:
    unordered_map<int, vector<int>> ma;
public:
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            ma[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        unordered_map<int, vector<int>>::iterator it = ma.find(value);
        if (it == ma.end()) {
            return 0;
        }
        vector<int>& v = it->second;  // 这里必须引用否则会超时
        return upper_bound(v.begin(), v.end(), right) - lower_bound(v.begin(), v.end(), left);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-02-18 10:17:02
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-18 10:36:00
'''
from typing import List
from collections import defaultdict
from bisect import bisect_left, bisect_right


class RangeFreqQuery:

    def __init__(self, arr: List[int]):
        self.ma = defaultdict(list)
        for i, v in enumerate(arr):
            self.ma[v].append(i)

    def query(self, left: int, right: int, value: int) -> int:
        if value not in self.ma:
            return 0
        v = self.ma[value]
        return bisect_right(v, right) - bisect_left(v, left)


# Your RangeFreqQuery object will be instantiated and called as such:
# obj = RangeFreqQuery(arr)
# param_1 = obj.query(left,right,value)
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-02-18 10:17:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-18 10:50:44
 */
package main

import "sort"


type RangeFreqQuery map[int][]int


func Constructor(arr []int) RangeFreqQuery {
    ma := map[int][]int{}
	for i, v := range arr {
		ma[v] = append(ma[v], i)
	}
	return ma
}


func (this *RangeFreqQuery) Query(left int, right int, value int) int {
    v := (*this)[value]
	return sort.SearchInts(v, right + 1) - sort.SearchInts(v, left)
}


/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * obj := Constructor(arr);
 * param_1 := obj.Query(left,right,value);
 */
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/145700724)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/02/18/LeetCode%202080.%E5%8C%BA%E9%97%B4%E5%86%85%E6%9F%A5%E8%AF%A2%E6%95%B0%E5%AD%97%E7%9A%84%E9%A2%91%E7%8E%87/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
>
> Tisfy：[https://blog.letmefly.xyz/2025/02/18/LeetCode 2080.区间内查询数字的频率/](https://blog.letmefly.xyz/2025/02/18/LeetCode%202080.%E5%8C%BA%E9%97%B4%E5%86%85%E6%9F%A5%E8%AF%A2%E6%95%B0%E5%AD%97%E7%9A%84%E9%A2%91%E7%8E%87/)
