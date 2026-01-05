---
title: 1975.最大方阵和：脑筋急转弯
date: 2026-01-05 18:46:34
tags: [题解, LeetCode, 中等, 贪心, 数组, 矩阵, 脑筋急转弯]
categories: [题解, LeetCode]
---

# 【LetMeFly】1975.最大方阵和：脑筋急转弯

力扣题目链接：[https://leetcode.cn/problems/maximum-matrix-sum/](https://leetcode.cn/problems/maximum-matrix-sum/)

<p>给你一个&nbsp;<code>n x n</code>&nbsp;的整数方阵&nbsp;<code>matrix</code>&nbsp;。你可以执行以下操作&nbsp;<strong>任意次</strong>&nbsp;：</p>

<ul>
	<li>选择&nbsp;<code>matrix</code>&nbsp;中&nbsp;<strong>相邻</strong>&nbsp;两个元素，并将它们都 <strong>乘以</strong>&nbsp;<code>-1</code>&nbsp;。</li>
</ul>

<p>如果两个元素有 <strong>公共边</strong>&nbsp;，那么它们就是 <strong>相邻</strong>&nbsp;的。</p>

<p>你的目的是 <strong>最大化</strong>&nbsp;方阵元素的和。请你在执行以上操作之后，返回方阵的&nbsp;<strong>最大</strong>&nbsp;和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/16/pc79-q2ex1.png" style="width: 401px; height: 81px;">
<pre><b>输入：</b>matrix = [[1,-1],[-1,1]]
<b>输出：</b>4
<b>解释：</b>我们可以执行以下操作使和等于 4 ：
- 将第一行的 2 个元素乘以 -1 。
- 将第一列的 2 个元素乘以 -1 。
</pre>

<p><strong>示例&nbsp;2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/16/pc79-q2ex2.png" style="width: 321px; height: 121px;">
<pre><b>输入：</b>matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]
<b>输出：</b>16
<b>解释：</b>我们可以执行以下操作使和等于 16 ：
- 将第二行的最后 2 个元素乘以 -1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == matrix.length == matrix[i].length</code></li>
	<li><code>2 &lt;= n &lt;= 250</code></li>
	<li><code>-10<sup>5</sup> &lt;= matrix[i][j] &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法：脑筋急转弯

解这道题只需要明白：

1. 只能相邻取负 等价于 可任意两元素取负

就够了。

But Why?

知道链式效应么（名字瞎起的），`[a, b, c, d]`中若想实现`a, d`取负则可通过`a, b`、`b, c`、`c, d`取负的方式实现，其中中间的`b`、`c`都取负了偶数次，相当于没变。

所以我们可以得到：

* 若matrix中有偶数个负数，那么两两配对并取反，相当于全是正数！
* 若matrix中有奇数个负数，那么最终一定会有一个负数无法通过负数们“内部消化”，这个负数找一个矩阵中绝对值最小的数并让它当负数自己当正数就好了。

具体而言，遍历一遍矩阵，累加每个数的绝对值，并记下绝对值最小的数、负数的个数。

若负数有奇数个，则累加结果减去两倍最小绝对值。

+ 时间复杂度$O(n^2)$，其中$SIZE(matrix)=n\times n$。
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-01-05 13:39:00
 */
typedef long long ll;
class Solution {
public:
    ll maxMatrixSum(vector<vector<int>>& matrix) {
        int minium = 1000000;
        int cntNeg = 0;
        ll ans = 0;
        for (vector<int>& row : matrix) {
            for (int t : row) {
                ans += abs(t);
                if (t < 0) {
                    cntNeg++;
                }
                minium = min(minium, abs(t));
            }
        }
        if (cntNeg % 2) {
            ans -= minium * 2;
        }
        return ans;
    }
};

/*
[[-1,0,-1],[-2,1,3],[3,2,2]]

-1 0 -1
-2 1 3
3  2 2
*/

/*
[[2,9,3],[5,4,-4],[1,7,1]]

2 9 3
5 4 -4
1 7 1

34
*/
```

#### Python

```python
'''
LastEditTime: 2026-01-05 13:41:10
'''
from typing import List

class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        mini = 1000000
        cntNeg = 0
        ans = 0
        for row in matrix:
            for t in row:
                ans += abs(t)
                if t < 0:
                    cntNeg += 1
                mini = min(mini, abs(t))
        if cntNeg % 2:
            ans -= 2 * mini
        return ans
```

#### Java

```java
/*
 * @LastEditTime: 2026-01-05 18:43:31
 */
class Solution {
    public long maxMatrixSum(int[][] matrix) {
        long ans = 0;
        int cnt = 0, min = 1000000;
        for (int[] row : matrix) {
            for (int t : row) {
                if (t < 0) {
                    cnt++;
                }
                t = Math.abs(t);
                ans += t;
                min = Math.min(min, t);
            }
        }
        if (cnt % 2 == 1) {
            ans -= 2 * min;
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2026-01-05 18:45:13
 */
package main

func abs1975(a int) int {
    if a < 0 {
        return -a
    }
    return a
}

func maxMatrixSum(matrix [][]int) (ans int64) {
    cnt, mini := 0, 1000000
    for _, row := range matrix {
        for _, t := range row {
            if t < 0 {
                cnt++
            }
            t = abs1975(t)
            ans += int64(t)
            mini = min(mini, t)
        }
    }
    if cnt % 2 == 1 {
        ans -= 2 * int64(mini)
    }
    return
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-01-05 13:43:32
 */
impl Solution {
    pub fn max_matrix_sum(matrix: Vec<Vec<i32>>) -> i64 {
        let mut ans: i64 = 0;
        let mut mini: i32 = 1000000;
        let mut cnt_neg: i32 = 0;
        for row in matrix.iter() {
            for t in row.iter() {
                ans += t.abs() as i64;
                if *t < 0 {
                    cnt_neg += 1;
                }
                mini = mini.min(t.abs());
            }
        }
        if cnt_neg % 2 == 1 {
            ans -= 2 * mini as i64;
        }
        ans
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/156614059)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/01/05/LeetCode%201975.%E6%9C%80%E5%A4%A7%E6%96%B9%E9%98%B5%E5%92%8C/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
