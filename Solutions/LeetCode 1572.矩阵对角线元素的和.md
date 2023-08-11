---
title: 1572.矩阵对角线元素的和
date: 2023-08-11 08:01:54
tags: [题解, LeetCode, 简单, 数组, 矩阵]
---

# 【LetMeFly】1572.矩阵对角线元素的和

力扣题目链接：[https://leetcode.cn/problems/matrix-diagonal-sum/](https://leetcode.cn/problems/matrix-diagonal-sum/)

<p>给你一个正方形矩阵 <code>mat</code>，请你返回矩阵对角线元素的和。</p>

<p>请你返回在矩阵主对角线上的元素和副对角线上且不在主对角线上元素的和。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp; 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/08/14/sample_1911.png" style="height:174px; width:336px" /></p>

<pre>
<strong>输入：</strong>mat = [[<strong>1</strong>,2,<strong>3</strong>],
&nbsp;           [4,<strong>5</strong>,6],
&nbsp;           [<strong>7</strong>,8,<strong>9</strong>]]
<strong>输出：</strong>25
<strong>解释：</strong>对角线的和为：1 + 5 + 9 + 3 + 7 = 25
请注意，元素 mat[1][1] = 5 只会被计算一次。
</pre>

<p><strong>示例&nbsp; 2：</strong></p>

<pre>
<strong>输入：</strong>mat = [[<strong>1</strong>,1,1,<strong>1</strong>],
&nbsp;           [1,<strong>1</strong>,<strong>1</strong>,1],
&nbsp;           [1,<strong>1</strong>,<strong>1</strong>,1],
&nbsp;           [<strong>1</strong>,1,1,<strong>1</strong>]]
<strong>输出：</strong>8
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>mat = [[<strong>5</strong>]]
<strong>输出：</strong>5
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == mat.length == mat[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= mat[i][j] &lt;= 100</code></li>
</ul>


    
## 方法一：模拟

假设$mat$的大小是$n\times n$，则可以：

用$i$从$0$到$n - 1$遍历$mat$的每一行，$ans$加上这一行的$i$和$n - i - 1$。

最后，如果$n$是奇数，则还需要减去对主副对角线重叠的元素$mat[\lfloor\frac{n}{2}\rfloor][\lfloor\frac{n}{2}\rfloor]$

+ 时间复杂度$O(n)$，其中$size(mat) = n\times n$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += mat[i][i] + mat[i][n - i - 1];
        }
        if (n % 2) {
            ans -= mat[n / 2][n / 2];
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        n = len(mat)
        ans = 0
        for i in range(n):
            ans += mat[i][i] + mat[i][n - i - 1]
        if n % 2:
            ans -= mat[n // 2][n // 2]
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/08/11/LeetCode%201572.%E7%9F%A9%E9%98%B5%E5%AF%B9%E8%A7%92%E7%BA%BF%E5%85%83%E7%B4%A0%E7%9A%84%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/132223172](https://letmefly.blog.csdn.net/article/details/132223172)
