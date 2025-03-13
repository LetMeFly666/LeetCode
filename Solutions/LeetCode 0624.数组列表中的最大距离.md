---
title: 624.数组列表中的最大距离：只关心最小最大值
date: 2025-02-19 17:55:07
tags: [题解, LeetCode, 中等, 贪心, 数组]
categories: [题解, LeetCode]
---

# 【LetMeFly】624.数组列表中的最大距离：只关心最小最大值

力扣题目链接：[https://leetcode.cn/problems/maximum-distance-in-arrays/](https://leetcode.cn/problems/maximum-distance-in-arrays/)

<p>给定&nbsp;<code>m</code>&nbsp;个数组，每个数组都已经按照升序排好序了。</p>

<p>现在你需要从两个不同的数组中选择两个整数（每个数组选一个）并且计算它们的距离。两个整数&nbsp;<code>a</code>&nbsp;和&nbsp;<code>b</code>&nbsp;之间的距离定义为它们差的绝对值&nbsp;<code>|a-b|</code>&nbsp;。</p>

<p>返回最大距离。</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>[[1,2,3],[4,5],[1,2,3]]
<strong>输出：</strong>4
<strong>解释：</strong>
一种得到答案 4 的方法是从第一个数组或者第三个数组中选择 1，同时从第二个数组中选择 5 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>arrays = [[1],[1]]
<b>输出：</b>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == arrays.length</code></li>
	<li><code>2 &lt;= m &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= arrays[i].length &lt;= 500</code></li>
	<li><code>-10<sup>4</sup> &lt;= arrays[i][j] &lt;= 10<sup>4</sup></code></li>
	<li><code>arrays[i]</code>&nbsp;以&nbsp;<strong>升序</strong>&nbsp;排序。</li>
	<li>所有数组中最多有&nbsp;<code>10<sup>5</sup></code> 个整数。</li>
</ul>

<p>&nbsp;</p>


    
## 解题方法：只关心最小最大值

很不错的一道题。

对于两个数组，抽象的画一画，大约一共有以下三种可能：（若有两端点相等也不影响结果）

1. 不重合

    ```
    ---- 
           -----
    ```

2. 重合不包含

    ```
    -------
        -------
    ```

3. 包含

    ```
    --------
      ----
    ```

分别从两个数组中取一个元素，想让差值的绝对值最大，怎么取？很容易发现**一定要从数组边界取**值（要么取数组的最大值，要么取最小值，否则最大/小值与另一个数组的差值可以更大）。

也就是说：

> 我们只需要维护数组最大值和最小值，并且保证两个值不会取自同一个数组不就行了么。

+ 时间复杂度$O(len(arrays))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-02-19 17:37:04
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-19 17:46:16
 */
/*
---- 
       -----


-------
    -------


--------
 ----
*/
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = 0;
        int mLeft = 100000, MRight = -100000;
        for (vector<int>& a : arrays) {
            ans = max(ans, max(a.back() - mLeft, MRight - a[0]));
            mLeft = min(mLeft, a[0]), MRight = max(MRight, a.back());
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-02-19 17:47:16
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-19 17:49:04
'''
from typing import List

class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        ans = 0
        m, M = 100000, -100000
        for a in arrays:
            ans = max(ans, M - a[0], a[-1] - m)
            m, M = min(m, a[0]), max(M, a[-1])
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-02-19 17:47:53
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-19 17:51:18
 */
import java.util.List;


class Solution {
    public int maxDistance(List<List<Integer>> arrays) {
        int ans = 0;
        int m = 100000, M = -100000;
        for (List<Integer> a : arrays) {
            ans = Math.max(ans, Math.max(a.get(a.size() - 1) - m, M - a.get(0)));
            m = Math.min(m, a.get(0));
            M = Math.max(M, a.get(a.size() - 1));
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-02-19 17:47:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-19 17:53:37
 */
package main

func maxDistance(arrays [][]int) (ans int) {
    m, M := 100000, -100000
    for _, a := range arrays {
        ans = max(ans, max(a[len(a) - 1] - m, M - a[0]))
        m, M = min(m, a[0]), max(M, a[len(a) - 1])
    }
    return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/145735600)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/02/19/LeetCode%200624.%E6%95%B0%E7%BB%84%E5%88%97%E8%A1%A8%E4%B8%AD%E7%9A%84%E6%9C%80%E5%A4%A7%E8%B7%9D%E7%A6%BB/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
>
> Tisfy：[https://blog.letmefly.xyz/2025/02/19/LeetCode 0624.数组列表中的最大距离/](https://blog.letmefly.xyz/2025/02/19/LeetCode%200624.%E6%95%B0%E7%BB%84%E5%88%97%E8%A1%A8%E4%B8%AD%E7%9A%84%E6%9C%80%E5%A4%A7%E8%B7%9D%E7%A6%BB/)
