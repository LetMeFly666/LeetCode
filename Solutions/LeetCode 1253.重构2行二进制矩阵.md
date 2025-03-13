---
title: 1253.重构 2 行二进制矩阵
date: 2023-06-29 08:25:55
tags: [题解, LeetCode, 中等, 贪心, 数组, 矩阵]
categories: [题解, LeetCode]
---

# 【LetMeFly】1253.重构 2 行二进制矩阵

力扣题目链接：[https://leetcode.cn/problems/reconstruct-a-2-row-binary-matrix/](https://leetcode.cn/problems/reconstruct-a-2-row-binary-matrix/)

<p>给你一个&nbsp;<code>2</code>&nbsp;行 <code>n</code> 列的二进制数组：</p>

<ul>
	<li>矩阵是一个二进制矩阵，这意味着矩阵中的每个元素不是&nbsp;<code>0</code>&nbsp;就是&nbsp;<code>1</code>。</li>
	<li>第 <code>0</code> 行的元素之和为&nbsp;<code>upper</code>。</li>
	<li>第 <code>1</code> 行的元素之和为 <code>lower</code>。</li>
	<li>第 <code>i</code> 列（从 <code>0</code> 开始编号）的元素之和为&nbsp;<code>colsum[i]</code>，<code>colsum</code>&nbsp;是一个长度为&nbsp;<code>n</code>&nbsp;的整数数组。</li>
</ul>

<p>你需要利用&nbsp;<code>upper</code>，<code>lower</code>&nbsp;和&nbsp;<code>colsum</code>&nbsp;来重构这个矩阵，并以二维整数数组的形式返回它。</p>

<p>如果有多个不同的答案，那么任意一个都可以通过本题。</p>

<p>如果不存在符合要求的答案，就请返回一个空的二维数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>upper = 2, lower = 1, colsum = [1,1,1]
<strong>输出：</strong>[[1,1,0],[0,0,1]]
<strong>解释：</strong>[[1,0,1],[0,1,0]] 和 [[0,1,1],[1,0,0]] 也是正确答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>upper = 2, lower = 3, colsum = [2,2,1,1]
<strong>输出：</strong>[]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>upper = 5, lower = 5, colsum = [2,1,2,0,1,0,1,2,0,1]
<strong>输出：</strong>[[1,1,1,0,1,0,0,1,0,0],[1,0,1,0,0,0,1,1,0,1]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= colsum.length &lt;= 10^5</code></li>
	<li><code>0 &lt;= upper, lower &lt;= colsum.length</code></li>
	<li><code>0 &lt;= colsum[i] &lt;= 2</code></li>
</ul>


    
## 方法一、方法二：分配（或贪心）

首先：

   + 如果colsum[i]为0，那么ans[0][i]和ans[1][i]必须为0
   + 如果colsum[i]为0，那么ans[0][i]和ans[1][i]必须为1

因此问题的关键就在于colsum[i]为1时如何分配（是令ans[0][i]为1还是ans[1][i]为1）

有两种方法：

   1. 对于所有colsum[i]为2的i，令ans[0][i] = ans[1][i] = 1，并统计upper和lower现在值为多少。接着对于colsum[i]为1的i，如果upper还没达到，就分配给ans[0][i]，否则分配给ans[1][i]，最终判断upper和lower是否同时满足
   2. 统计upper和lower还分别缺少多少个，当colsum[i]为2时lower和upper都分配，当colsum[i]为1时，分配给upper和lower中所需数量更大的那个

即可。

+ 时间复杂度$O(len(colsum))$
+ 空间复杂度$O(1)$ 或 $O(len(colsum))$（所返回答案的不计入算法空间复杂度）

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> ans(2, vector<int>(colsum.size(), 0));
        int cntUpper = 0, cntLower = 0;
        for (int i = 0; i < colsum.size(); i++) {
            if (colsum[i] == 2) {
                ans[0][i] = ans[1][i] = 1;
                cntUpper++, cntLower++;
            }
        }
        for (int i = 0; i < colsum.size(); i++) {
            if (colsum[i] == 1) {
                if (cntUpper < upper) {
                    ans[0][i] = 1;
                    cntUpper++;
                }
                else {
                    ans[1][i] = 1;
                    cntLower++;
                }
            }
        }
        if (cntUpper == upper && cntLower == lower) {
            return ans;
        }
        else {
            return {};
        }
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def reconstructMatrix(self, upper: int, lower: int, colsum: List[int]) -> List[List[int]]:
        ans = [[0] * len(colsum) for _ in range(2)]
        cntUpper, cntLower = 0, 0
        for i in range(len(colsum)):
            if colsum[i] == 2:
                ans[0][i] = ans[1][i] = 1
                cntUpper += 1
                cntLower += 1
        for i in range(len(colsum)):
            if colsum[i] == 1:
                if cntUpper < upper:
                    ans[0][i] = 1
                    cntUpper += 1
                else:
                    ans[1][i] = 1
                    cntLower += 1
        return ans if cntUpper == upper and cntLower == lower else []
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/06/29/LeetCode%201253.%E9%87%8D%E6%9E%842%E8%A1%8C%E4%BA%8C%E8%BF%9B%E5%88%B6%E7%9F%A9%E9%98%B5/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131448811](https://letmefly.blog.csdn.net/article/details/131448811)
