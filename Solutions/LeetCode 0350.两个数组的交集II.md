---
title: 350.两个数组的交集 II：哈希表/双指针
date: 2022-10-02 09:58:00
tags: [题解, LeetCode, 简单, 数组, 哈希表, 哈希, map, set, 双指针, 二分查找, 排序]
---

# 【LetMeFly】350.两个数组的交集 II：哈希表/双指针

力扣题目链接：[https://leetcode.cn/problems/intersection-of-two-arrays-ii/](https://leetcode.cn/problems/intersection-of-two-arrays-ii/)

<p>给你两个整数数组&nbsp;<code>nums1</code> 和 <code>nums2</code> ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [1,2,2,1], nums2 = [2,2]
<strong>输出：</strong>[2,2]
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入：</strong>nums1 = [4,9,5], nums2 = [9,4,9,8,4]
<strong>输出：</strong>[4,9]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>

<p><strong><strong>进阶</strong>：</strong></p>

<ul>
	<li>如果给定的数组已经排好序呢？你将如何优化你的算法？</li>
	<li>如果&nbsp;<code>nums1</code><em>&nbsp;</em>的大小比&nbsp;<code>nums2</code> 小，哪种方法更优？</li>
	<li>如果&nbsp;<code>nums2</code><em>&nbsp;</em>的元素存储在磁盘上，内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？</li>
</ul>


    
## 方法一：哈希表

类似于[LeetCode 349. 两个数组的交集](https://blog.letmefly.xyz/2022/10/02/LeetCode%200349.%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%BB%84%E7%9A%84%E4%BA%A4%E9%9B%86/)，这道题同样可以使用哈希表来解决。

这次建立一个可以计数的哈希表，遍历一遍第一个数组，将第一个数组中的数字（及其出现次数）存入哈希表中

然后遍历一遍第二个数组，如果这个数在哈希表中存在，并且次数大于0，那么就将这个数添加到答案数组中，并将这个数在哈希表中出现的次数减一。

+ 时间复杂度$O(n+m)$，其中$n$是第一个数组中元素的个数，$m$是第二个数组中元素的个数
+ 空间复杂度$O(n)$

哈希表时空复杂度的常数较大，因此执行结果为：时间/空间 分别超过了6.90%，15.67%的提交。

### AC代码

#### C++（使用map）

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2022-10-02 09:04:56
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-02 09:07:45
 */
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ma;
        for (int& t : nums1) {
            ma[t]++;
        }
        vector<int> ans;
        for (int& t : nums2) {
            if (ma[t] > 0) {
                ans.push_back(t);
                ma[t]--;
            }
        }
        return ans;
    }
};
```

#### C++（使用set）

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-01-30 08:10:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-30 08:17:11
 */
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_multiset<int> se(nums1.begin(), nums1.end());
        vector<int> ans;
        for (int t : nums2) {
            unordered_multiset<int>::iterator it = se.find(t);
            if (it != se.end()) {
                ans.push_back(t);
                se.erase(it);
            }
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-01-30 08:18:20
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-30 08:20:54
'''
from typing import List
from collections import Counter

class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        cnt = Counter(nums1)
        ans = []
        for t in nums2:
            if cnt[t]:
                ans.append(t)
                cnt[t] -= 1
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-01-30 08:21:39
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-30 08:25:09
 */
import java.util.HashMap;
import java.util.Map;
import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        Map<Integer, Integer> ma = new HashMap<>();
        for (int t : nums1) {
            ma.merge(t, 1, Integer::sum);
        }
        List<Integer> temp = new ArrayList<>();
        for (int t : nums2) {
            int c = ma.getOrDefault(t, 0);
            if (c > 0) {
                temp.add(t);
                ma.put(t, c - 1);
            }
        }
        return temp.stream().mapToInt(i -> i).toArray();
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-01-30 08:26:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-30 08:27:29
 */
package main

func intersect(nums1 []int, nums2 []int) (ans []int) {
    ma := map[int]int{}
    for _, t := range nums1 {
        ma[t]++
    }
    for _, t := range nums2 {
        if ma[t] > 0 {
            ans = append(ans, t)
            ma[t]--
        }
    }
    return
}
```

## 方法二：双指针

首先对两个数组分别排序，然后使用两个“指针”，分别指向第一个数组和第二个数组的 第一个元素。

当两个指针都在*有效范围*（不越界）内时，比较两个指针所指元素。

+ 若两元素相等，则将此元素添加到答案数组中，并将两个指针分别后移一位
+ 若两元素不等，则将指向较小元素的指针后移一位

即可。

+ 时间复杂度$O(n\log n + m\log m)$，其中$n$是第一个数组中元素的个数，$m$是第二个数组中元素的个数
+ 空间复杂度$O(\log n + \log m)$

执行结果为：时间/空间 分别超过了86.34%，93.57%的提交。

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int loc1 = 0, loc2 = 0;
        vector<int> ans;
        while (loc1 < nums1.size() && loc2 < nums2.size()) {
            if (nums1[loc1] == nums2[loc2]) {
                ans.push_back(nums1[loc1]);
                loc1++, loc2++;
            }
            else if (nums1[loc1] < nums2[loc2]) {
                loc1++;
            }
            else {
                loc2++;
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/10/02/LeetCode%200350.%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%BB%84%E7%9A%84%E4%BA%A4%E9%9B%86II/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127140436](https://letmefly.blog.csdn.net/article/details/127140436)
