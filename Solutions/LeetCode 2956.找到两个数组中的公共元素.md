---
title: 2956.找到两个数组中的公共元素
date: 2024-07-16 23:37:41
tags: [题解, LeetCode, 简单, 数组, 哈希表, 哈希, Set]
---

# 【LetMeFly】2956.找到两个数组中的公共元素：哈希表

力扣题目链接：[https://leetcode.cn/problems/find-common-elements-between-two-arrays/](https://leetcode.cn/problems/find-common-elements-between-two-arrays/)

<p>给你两个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums1</code>&nbsp;和&nbsp;<code>nums2</code>&nbsp;，它们分别含有 <code>n</code>&nbsp;和 <code>m</code>&nbsp;个元素。</p>

<p>请你计算以下两个数值：</p>

<ul>
	<li>统计&nbsp;<code>0 &lt;= i &lt; n</code>&nbsp;中的下标&nbsp;<code>i</code>&nbsp;，满足&nbsp;<code>nums1[i]</code>&nbsp;在 <code>nums2</code>&nbsp;中 <strong>至少</strong>&nbsp;出现了一次。</li>
	<li>统计&nbsp;<code>0 &lt;= i &lt; m</code>&nbsp;中的下标&nbsp;<code>i</code>&nbsp;，满足&nbsp;<code>nums2[i]</code>&nbsp;在 <code>nums1</code>&nbsp;中 <strong>至少</strong>&nbsp;出现了一次。</li>
</ul>

<p>请你返回一个长度为 <code>2</code>&nbsp;的整数数组<em>&nbsp;</em><code>answer</code>&nbsp;，<strong>按顺序</strong>&nbsp;分别为以上两个数值。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [4,3,2,3,1], nums2 = [2,2,5,2,3,6]
<b>输出：</b>[3,4]
<b>解释：</b>分别计算两个数值：
- nums1 中下标为 1 ，2 和 3 的元素在 nums2 中至少出现了一次，所以第一个值为 3 。
- nums2 中下标为 0 ，1 ，3 和 4 的元素在 nums1 中至少出现了一次，所以第二个值为 4 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums1 = [3,4,2,3], nums2 = [1,5]
<b>输出：</b>[0,0]
<b>解释：</b>两个数组中没有公共元素，所以两个值都为 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums1.length</code></li>
	<li><code>m == nums2.length</code></li>
	<li><code>1 &lt;= n, m &lt;= 100</code></li>
	<li><code>1 &lt;= nums1[i], nums2[i] &lt;= 100</code></li>
</ul>


    
## 解题方法：哈希表

首先将两个数组中的元素放入哈希表中，这样就能在$O(1)$时间内判断一个元素有没有在一个数组中。

接着分别遍历两个数组中，统计有多少个元素在另一个数组中出现过。

+ 时间复杂度$O(len(nums1) + len(nums2))$
+ 空间复杂度$O(len(nums1) + len(nums2))$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
        vector<int> ans(2);
        for (int t : nums1) {
            ans[0] += s2.count(t);
        }
        for (int t : nums2) {
            ans[1] += s1.count(t);
        }
        return ans;
    }
};
```

#### Go

```go
package main

func findIntersectionValues(nums1 []int, nums2 []int) []int {
    s1, s2 := map[int]int{}, map[int]int{}
    for _, t := range nums1 {
        s1[t] = 1
    }
    for _, t := range nums2 {
        s2[t] = 1
    }
    ans := [2]int{}
    for _, t := range nums1 {
        ans[0] += s2[t]
    }
    for _, t := range nums2 {
        ans[1] += s1[t]
    }
    return ans[:]
}
```

#### Java

```java
import java.util.HashSet;

class Solution {
    public int[] findIntersectionValues(int[] nums1, int[] nums2) {
        HashSet<Integer> s1 = new HashSet<>(), s2 = new HashSet<>();
        for (int t : nums1) {
            s1.add(t);
        }
        for (int t : nums2) {
            s2.add(t);
        }
        int[] ans = new int[2];
        for (int t : nums1) {
            ans[0] += s2.contains(t) ? 1 : 0;
        }
        for (int t : nums2) {
            ans[1] += s1.contains(t) ? 1 : 0;
        }
        return ans;
    }
}
```

#### Python

```python
from typing import List

class Solution:
    def findIntersectionValues(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return [sum(t in nums2 for t in nums1), sum(t in nums1 for t in nums2)]
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/07/16/LeetCode%202956.%E6%89%BE%E5%88%B0%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E5%85%AC%E5%85%B1%E5%85%83%E7%B4%A0/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/140479914](https://letmefly.blog.csdn.net/article/details/140479914)
