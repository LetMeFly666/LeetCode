---
title: 598.区间加法 II：最小值
date: 2025-02-02 11:11:35
tags: [题解, LeetCode, 简单, 数组, 数学, 思维]
categories: [题解, LeetCode]
---

# 【LetMeFly】598.区间加法 II：最小值

力扣题目链接：[https://leetcode.cn/problems/range-addition-ii/](https://leetcode.cn/problems/range-addition-ii/)

<p>给你一个 <code>m x&nbsp;n</code> 的矩阵&nbsp;<code>M</code><strong> </strong>和一个操作数组 <code>op</code> 。矩阵初始化时所有的单元格都为 <code>0</code> 。<code>ops[i] = [ai, bi]</code> 意味着当所有的 <code>0 &lt;= x &lt; ai</code> 和 <code>0 &lt;= y &lt; bi</code> 时， <code>M[x][y]</code> 应该加 1。</p>

<p>在&nbsp;<em>执行完所有操作后</em>&nbsp;，计算并返回&nbsp;<em>矩阵中最大整数的个数</em>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/10/02/ex1.jpg" style="height: 176px; width: 750px;" /></p>

<pre>
<strong>输入:</strong> m = 3, n = 3，ops = [[2,2],[3,3]]
<strong>输出:</strong> 4
<strong>解释:</strong> M 中最大的整数是 2, 而且 M 中有4个值为2的元素。因此返回 4。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> m = 3, n = 3, ops = [[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3]]
<strong>输出:</strong> 4
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> m = 3, n = 3, ops = []
<strong>输出:</strong> 9
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<p><meta charset="UTF-8" /></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 4 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= ops.length &lt;= 10<sup>4</sup></code></li>
	<li><code>ops[i].length == 2</code></li>
	<li><code>1 &lt;= a<sub>i</sub>&nbsp;&lt;= m</code></li>
	<li><code>1 &lt;= b<sub>i</sub>&nbsp;&lt;= n</code></li>
</ul>


    
## 解题方法：最小值

这道题很有意思，每次都是左上角的一小块加一。

最终最大整数的个数，不就是每次都被加一的那些元素么。

横纵坐标可以分开计算，对于横坐标，每次都覆盖掉的就是所有操作中在最小值；纵坐标同理。

文字描述不如代码描述，还不懂的话，看完代码就懂了。

+ 时间复杂度$O(len(ops))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-02-02 10:31:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-02 11:05:10
 */
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (vector<int>& op : ops) {
            m = min(m, op[0]);
            n = min(n, op[1]);
        }
        return m * n;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-02-02 11:06:10
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-02 11:07:44
'''
from typing import List

class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        for a, b in ops:
            m = min(m, a)
            n = min(n, b)
        return m * n
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-02-02 11:08:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-02 11:08:11
 */
class Solution {
    public int maxCount(int m, int n, int[][] ops) {
        for (int[] op : ops) {
            m = Math.min(m, op[0]);
            n = Math.min(n, op[1]);
        }
        return m * n;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-02-02 11:09:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-02 11:10:27
 */
package main

func min_RA2(m, n int) int {
    if m < n {
        return m
    }
    return n
}

func maxCount(m int, n int, ops [][]int) int {
    for _, op := range ops {
        m = min_RA2(m, op[0])
        n = min_RA2(n, op[1])
    }
    return m * n
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/02/02/LeetCode%200598.%E5%8C%BA%E9%97%B4%E5%8A%A0%E6%B3%95II/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/145418564](https://letmefly.blog.csdn.net/article/details/145418564)
