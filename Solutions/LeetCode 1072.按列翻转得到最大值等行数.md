---
title: 1072.按列翻转得到最大值等行数：不错的思维题！
date: 2023-05-15 10:56:59
tags: [题解, LeetCode, 中等, 数组, 哈希表, 哈希, map, 矩阵, 思维]
---

# 【LetMeFly】1072.按列翻转得到最大值等行数

力扣题目链接：[https://leetcode.cn/problems/flip-columns-for-maximum-number-of-equal-rows/](https://leetcode.cn/problems/flip-columns-for-maximum-number-of-equal-rows/)

<p>给定&nbsp;<code>m x n</code>&nbsp;矩阵&nbsp;<code>matrix</code>&nbsp;。</p>

<p>你可以从中选出任意数量的列并翻转其上的&nbsp;<strong>每个&nbsp;</strong>单元格。（即翻转后，单元格的值从 <code>0</code> 变成 <code>1</code>，或者从 <code>1</code> 变为 <code>0</code> 。）</p>

<p>返回 <em>经过一些翻转后，行与行之间所有值都相等的最大行数</em>&nbsp;。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>matrix = [[0,1],[1,1]]
<strong>输出：</strong>1
<strong>解释：</strong>不进行翻转，有 1 行所有值都相等。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>matrix = [[0,1],[1,0]]
<strong>输出：</strong>2
<strong>解释：</strong>翻转第一列的值之后，这两行都由相等的值组成。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>matrix = [[0,0,0],[0,0,1],[1,1,0]]
<strong>输出：</strong>2
<strong>解释：</strong>翻转前两列的值之后，后两行由相等的值组成。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 300</code></li>
	<li><code>matrix[i][j] == 0</code> 或&nbsp;<code>1</code></li>
</ul>


    
## 方法一：思维

首先这道题的中文描述有点错误。题目要求的是：一行之内的元素全相等 的 行数 的最大值。

怎么个翻转法呢？我可以选取某些列，将这些列的0变成1，1变成0。

试想这样（完全相同）的多行：

```
011010
011010
011010
...
```

我们只需要把**第2、3、5列翻转**，就能得到：

```
000000
000000
000000
...
```

这些原本完全相同的行，每一行都变成了0

试想这样（完全相反）的两行：

```
011010
100101
```

我们只需要把**第2、3、5列翻转**，就能得到：

```
000000
111111
```

这些完全相反的行，有的变成了全0，有的变成了全1

有没有发现，上面两种情况，我们都是反转的第“2，3，5”行，最终得到的结果是：这些行要么全0，要么全1

也就是说：**原本完全相同或完全相反的行，可以通过题目描述的翻转操作，使得这些行变得要么全0要么全1**

而题目问的，就是“全0行”和“全1行”的最大行数和

因此，我们只需要将完全相同的行 或 完全相反的行 聚成一类，最大的“聚合块”的大小即为答案。

例如：

```
0 0 0
1 1 1
0 0 0
0 1 0
1 1 1
0 0 1
1 1 0
```

可以聚合成三块：

```
1. [0, 0, 0], [1, 1, 1], [0, 0, 0], [1, 1, 1]
2. [0, 1, 0]
3. [0, 0, 1], [1, 1, 0]
```

第1块最大有四个即为答案。

因此剩下的问题就是：如何将完全相同的行或完全相反的行聚成一类？（现在完全不用考虑题目说的什么翻转，什么相等了）

不失一般性，我们可以让每一行的第一个元素全部变成0。

+ 如果某一行第一个元素本来就是0，那么这一行就完全不变
+ 否则（某行第一个元素是1），就将这一行的每个元素都翻转（0变1，1变0）

注意这里的翻转和题目中的翻转没有任何关系，这里翻转只是为了将完全相反的行变成完全相同的行**从而用来统计**

这样，问题就变成了：将完全相同的行聚成一类，最大的“聚合块”的大小是多少

使用一个哈希表就能很方便地解决了。

+ 时间复杂度$O(n\times m)$，其中$matrix$的大小为$n\times m$
+ 空间复杂度$O(n\times m)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<vector<bool>, int> ma;  // 哈希表
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<bool> thisLine(m);  // 这一行
            for (int j = 0; j < m; j++) {  // 使用异或操作，[行首, 本元素] -> 最终结果：[0, 0] -> 0，[0, 1] -> 1，[1, 0] -> 1，[1, 1] -> 0
                thisLine[j] = matrix[i][j] ^ matrix[i][0];
            }
            ma[thisLine]++;
            ans = max(ans, ma[thisLine]);
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List
# from collections import defaultdict

class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        ma = defaultdict(int)
        n, m = len(matrix), len(matrix[0])
        ans = 0
        for i in range(n):
            thisLine = ''
            for j in range(m):
                thisLine += chr(ord('0') + matrix[i][j] ^ matrix[i][0])
            ma[thisLine] += 1
            ans = max(ans, ma[thisLine])
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/05/15/LeetCode%201072.%E6%8C%89%E5%88%97%E7%BF%BB%E8%BD%AC%E5%BE%97%E5%88%B0%E6%9C%80%E5%A4%A7%E5%80%BC%E7%AD%89%E8%A1%8C%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130680800](https://letmefly.blog.csdn.net/article/details/130680800)
