---
title: 2918.数组的最小相等和：if-else
date: 2025-05-10 19:39:40
tags: [题解, LeetCode, 中等, 贪心, 数组]
categories: [题解, LeetCode]
---

# 【LetMeFly】2918.数组的最小相等和：if-else

力扣题目链接：[https://leetcode.cn/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/](https://leetcode.cn/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/)

<p>给你两个由正整数和 <code>0</code> 组成的数组 <code>nums1</code> 和 <code>nums2</code> 。</p>

<p>你必须将两个数组中的<strong> 所有</strong> <code>0</code> 替换为 <strong>严格</strong> 正整数，并且满足两个数组中所有元素的和 <strong>相等</strong> 。</p>

<p>返回 <strong>最小</strong> 相等和 ，如果无法使两数组相等，则返回 <code>-1</code><em> </em>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [3,2,0,1,0], nums2 = [6,5,0]
<strong>输出：</strong>12
<strong>解释：</strong>可以按下述方式替换数组中的 0 ：
- 用 2 和 4 替换 nums1 中的两个 0 。得到 nums1 = [3,2,2,1,4] 。
- 用 1 替换 nums2 中的一个 0 。得到 nums2 = [6,5,1] 。
两个数组的元素和相等，都等于 12 。可以证明这是可以获得的最小相等和。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [2,0,2,0], nums2 = [1,4]
<strong>输出：</strong>-1
<strong>解释：</strong>无法使两个数组的和相等。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 10<sup>6</sup></code></li>
</ul>

## 解题方法：讨论

假设$nums1$的和为$s1$且$nums1$中有$c1$个$0$，$nums2$的和以及零的个数分别为$s2$和$c2$，则有：

+ 若$s1 < s2 + c2 and c1 == 0$，说明$nums2$的和至少变为$s2+c2$，比$s1$大并且$s1$中没有$0$可以使其和变大，直接返回$-1$；
+ 若$s1 + c1 > s2 and cs == 0$，同理，直接返回$-1$；
+ 否则，返回$max(s1 + c1, s2 + c2)$。

时空复杂度分析：

+ 时间复杂度$O(len(nums1) + len(nums2))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-05-10 12:07:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-10 19:00:36
 */
typedef long long ll;

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ll s1 = 0, s2 = 0;
        int c1 = 0, c2 = 0;
        for (int t : nums1) {
            s1 += t;
            c1 += t == 0;
        }
        for (int t : nums2) {
            s2 += t;
            c2 += t == 0;
        }
        if (s1 < s2 + c2 && c1 == 0 || s1 + c1 > s2 && c2 == 0) {
            return -1;
        }
        return max(s1 + c1, s2 + c2);
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-05-10 12:07:54
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-10 19:29:26
'''
from typing import List, Tuple

class Solution:
    def cal1(self, nums: List[int]) -> Tuple[int, int]:
        s, c = 0, 0
        for t in nums:
            if t:
                s += t
            else:
                c += 1
        return s, c
    
    def minSum(self, nums1: List[int], nums2: List[int]) -> int:
        s1, c1 = self.cal1(nums1)
        s2, c2 = self.cal1(nums2)
        if s1 < s2 + c2 and c1 == 0 or s1 + c1 > s2 and c2 == 0:
            return -1
        return max(s1 + c1, s2 + c2)
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-05-10 12:07:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-10 19:32:19
 */
class Solution {
    public long minSum(int[] nums1, int[] nums2) {
        long s1 = 0, s2 = 0;
        int c1 = 0, c2 = 0;
        for (int t : nums1) {
            s1 += t;
            if (t == 0) {
                c1++;
            }
        }
        for (int t : nums2) {
            s2 += t;
            if (t == 0) {
                c2++;
            }
        }
        if (s1 < s2 + c2 && c1 == 0 || s1 + c1 > s2 && c2 == 0) {
            return -1;
        }
        return Math.max(s1 + c1, s2 + c2);
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-05-10 12:07:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-10 19:38:55
 */
package main

func cal2918(a []int) (s int64, cnt int64) {
    for _, t := range a {
        if (t == 0) {
            cnt++
        } else {
            s += int64(t)
        }
    }
    return
}

func minSum(nums1 []int, nums2 []int) int64 {
    s1, c1 := cal2918(nums1)
    s2, c2 := cal2918(nums2)
    if s1 < s2 + c2 && c1 == 0 || s1 + c1 > s2 && c2 == 0 {
        return -1
    }
    return max(s1 + c1, s2 + c2)
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/147858203)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/05/10/LeetCode%202918.%E6%95%B0%E7%BB%84%E7%9A%84%E6%9C%80%E5%B0%8F%E7%9B%B8%E7%AD%89%E5%92%8C/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
