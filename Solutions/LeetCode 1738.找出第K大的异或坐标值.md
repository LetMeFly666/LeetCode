---
title: 1738.找出第 K 大的异或坐标值
date: 2024-05-26 09:56:56
tags: [题解, LeetCode, 中等, 位运算, 数组, 分治, 矩阵, 前缀和, 快速选择, 堆（优先队列）]
categories: [题解, LeetCode]
---

# 【LetMeFly】1738.找出第 K 大的异或坐标值：二维前缀和

力扣题目链接：[https://leetcode.cn/problems/find-kth-largest-xor-coordinate-value/](https://leetcode.cn/problems/find-kth-largest-xor-coordinate-value/)

<p>给你一个二维矩阵 <code>matrix</code> 和一个整数 <code>k</code> ，矩阵大小为 <code>m x n</code> 由非负整数组成。</p>

<p>矩阵中坐标 <code>(a, b)</code> 的 <strong>值</strong> 可由对所有满足 <code>0 &lt;= i &lt;= a &lt; m</code> 且 <code>0 &lt;= j &lt;= b &lt; n</code> 的元素 <code>matrix[i][j]</code>（<strong>下标从 0 开始计数</strong>）执行异或运算得到。</p>

<p>请你找出 <code>matrix</code> 的所有坐标中第 <code>k</code> 大的值（<strong><code>k</code> 的值从 1 开始计数</strong>）。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>matrix = [[5,2],[1,6]], k = 1
<strong>输出：</strong>7
<strong>解释：</strong>坐标 (0,1) 的值是 5 XOR 2 = 7 ，为最大的值。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>matrix = [[5,2],[1,6]], k = 2
<strong>输出：</strong>5
<strong>解释：</strong>坐标 (0,0) 的值是 5 = 5 ，为第 2 大的值。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>matrix = [[5,2],[1,6]], k = 3
<strong>输出：</strong>4
<strong>解释：</strong>坐标 (1,0) 的值是 5 XOR 1 = 4 ，为第 3 大的值。</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>matrix = [[5,2],[1,6]], k = 4
<strong>输出：</strong>0
<strong>解释：</strong>坐标 (1,1) 的值是 5 XOR 2 XOR 1 XOR 6 = 0 ，为第 4 大的值。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 1000</code></li>
	<li><code>0 &lt;= matrix[i][j] &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= k &lt;= m * n</code></li>
</ul>


    
## 解题方法：二维前缀和

二位前缀和的介绍可以参考[304.二维区域和检索 - 矩阵不可变](https://blog.letmefly.xyz/2022/09/17/LeetCode%200304.%E4%BA%8C%E7%BB%B4%E5%8C%BA%E5%9F%9F%E5%92%8C%E6%A3%80%E7%B4%A2-%E7%9F%A9%E9%98%B5%E4%B8%8D%E5%8F%AF%E5%8F%98/)

简单来说，就是使用一个前缀(异或)和数组```prefix```，保证```prefix[i + 1][j + 1]```的值为“```matrix[0][0]```到```matrix[i][j]```所有值的异或和”。

由于```a ⊕ a = 0 ```，因此若想求得图中“左上角到<font color="#e9e983">黄色</font>方块的异或和”，只需要<font color="#ff0000">红色</font>⊕<font color="#548235">绿色</font>⊕<font color="#e9e983">黄色</font>⊕<font color="#819cce">蓝色</font>即可。（<font color="#ff0000">红色</font>⊕<font color="#548235">绿色</font>后<font color="#819cce">蓝色</font>部分抵消了，再异或一次<font color="#819cce">蓝色</font>正好）。

![前缀和示意图](https://cdn.letmefly.xyz/img/blog/_LeetCode/1738_2D_prefix_xor.jpg)

<!-- https://pic.leetcode.cn/1716691163-OBEfrg-1738_2D_prefix_xor.jpg -->
<!-- https://img-blog.csdnimg.cn/img_convert/6690a546bc9702b5d584dbc6642d250a.jpeg -->

上图PPT地址：[Tisfy - 1738.找出第 K 大的异或坐标值.pptx](https://cdn.letmefly.xyz/ppt/blog/Tisfy_leetcode_1738__find_kth_largest_xor_coordinate_value.pptx)。

+ 时间复杂度$O(N^2)$
+ 空间复杂度$O(N\log N)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        vector<vector<int>> prefix(matrix.size() + 1, vector<int>(matrix[0].size() + 1));
        vector<int> vals;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                prefix[i + 1][j + 1] = prefix[i + 1][j] ^ prefix[i][j + 1] ^ prefix[i][j] ^ matrix[i][j];
                vals.push_back(prefix[i + 1][j + 1]);
            }
        }
        sort(vals.begin(), vals.end());
        return vals[vals.size() - k];
    }
};
```

#### Go

```go
// package main

// import "sort"

func kthLargestValue(matrix [][]int, k int) int {
    prefix := make([][]int, len(matrix) + 1)
    prefix[0] = make([]int, len(matrix[0]) + 1)
    vals := make([]int, 0)
    for i := 0; i < len(matrix); i++ {
        prefix[i + 1] = make([]int, len(matrix[0]) + 1)
        for j := 0; j < len(matrix[0]); j++ {
            prefix[i + 1][j + 1] = prefix[i + 1][j] ^ prefix[i][j + 1] ^ prefix[i][j] ^ matrix[i][j]
            vals = append(vals, prefix[i + 1][j + 1])
        }
    }
    sort.Ints(vals)
    return vals[len(vals) - k]
}
```

#### Java

```java
// import java.util.ArrayList;
// import java.util.Comparator;

class Solution {
    public int kthLargestValue(int[][] matrix, int k) {
        int[][] prefix = new int[matrix.length + 1][matrix[0].length + 1];
        ArrayList<Integer> vals = new ArrayList<>();
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                prefix[i + 1][j + 1] = prefix[i + 1][j] ^ prefix[i][j + 1] ^ prefix[i][j] ^ matrix[i][j];
                vals.add(prefix[i + 1][j + 1]);
            }
        }
        vals.sort(Comparator.naturalOrder());
        return vals.get(vals.size() - k);
    }
}
```

#### Python

```python
# from typing import List

class Solution:
    def kthLargestValue(self, matrix: List[List[int]], k: int) -> int:
        prefix = [[0] * (len(matrix[0]) + 1) for _ in range(len(matrix) + 1)]
        vals = []
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                prefix[i + 1][j + 1] = prefix[i + 1][j] ^ prefix[i][j + 1] ^ prefix[i][j] ^ matrix[i][j]
                vals.append(prefix[i + 1][j + 1])
        vals.sort()
        return vals[-k]
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/05/26/LeetCode%201738.%E6%89%BE%E5%87%BA%E7%AC%ACK%E5%A4%A7%E7%9A%84%E5%BC%82%E6%88%96%E5%9D%90%E6%A0%87%E5%80%BC/)哦~
>
> 若题解不是“五彩斑斓”的，也可以点击上述“原文链接”查看五彩斑斓版本。
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/139211887](https://letmefly.blog.csdn.net/article/details/139211887)
