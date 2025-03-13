---
title: 2661.找出叠涂元素
date: 2023-12-01 10:02:16
tags: [题解, LeetCode, 中等, 数组, 哈希表, 矩阵]
categories: [题解, LeetCode]
---

# 【LetMeFly】2661.找出叠涂元素：多次映射

力扣题目链接：[https://leetcode.cn/problems/first-completely-painted-row-or-column/](https://leetcode.cn/problems/first-completely-painted-row-or-column/)

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>arr</code> 和一个 <code>m x n</code> 的整数 <strong>矩阵</strong> <code>mat</code> 。<code>arr</code> 和 <code>mat</code> 都包含范围 <code>[1，m * n]</code> 内的 <strong>所有</strong> 整数。</p>

<p>从下标 <code>0</code> 开始遍历 <code>arr</code> 中的每个下标 <code>i</code> ，并将包含整数 <code>arr[i]</code> 的 <code>mat</code> 单元格涂色。</p>

<p>请你找出 <code>arr</code> 中在 <code>mat</code> 的某一行或某一列上都被涂色且下标最小的元素，并返回其下标 <code>i</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="image explanation for example 1" src="https://assets.leetcode.com/uploads/2023/01/18/grid1.jpg" style="width: 321px; height: 81px;" />
<pre>
<strong>输入：</strong>arr = [1,3,4,2], mat = [[1,4],[2,3]]
<strong>输出：</strong>2
<strong>解释：</strong>遍历如上图所示，arr[2] 在矩阵中的第一行或第二列上都被涂色。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="image explanation for example 2" src="https://assets.leetcode.com/uploads/2023/01/18/grid2.jpg" style="width: 601px; height: 121px;" />
<pre>
<strong>输入：</strong>arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
<strong>输出：</strong>3
<strong>解释：</strong>遍历如上图所示，arr[3] 在矩阵中的第二列上都被涂色。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n = mat[i].length</code></li>
	<li><code>arr.length == m * n</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= arr[i], mat[r][c] &lt;= m * n</code></li>
	<li><code>arr</code> 中的所有整数 <strong>互不相同</strong></li>
	<li><code>mat</code> 中的所有整数 <strong>互不相同</strong></li>
</ul>


    
## 方法一：多次映射

**思路：**

遍历arr数组，将arr[now]映射到mat中的i行j列，并将i行中被命中的次数+1，j列中被命中的次数加一。

首次i行全部命中或j列全部命中则返回arr中当前下标now。

**具体方法：**

怎么快速将$arr[now]$快速映射到mat中的i行j列呢？可以使用一个“哈希表”：

> 开辟一个mat大小的一维数组a，数组中a[index]存放值为index - 1的mat的横纵下标```i, j```
>
> 只需要遍历一遍mat数组即可得到“哈希表”数组a

怎么记录某行或某列的命中次数呢？

> 开辟两个数组，rowCnt[i]记录第i行的命中次数，colCnt[j]记录第j行的命中次数即可。

+ 时间复杂度$O(len(arr))$，因为$len(arr) = size(mat)$
+ 空间复杂度$O(len(arr))$

### AC代码

#### C++

```cpp
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<pair<int, int>> a(m * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[mat[i][j] - 1] = {i, j};
            }
        }
        vector<int> cntRow(n), cntCol(m);
        for (int i = 0; i < arr.size(); i++) {
            int t = arr[i] - 1;
            cntRow[a[t].first]++;
            cntCol[a[t].second]++;
            if (cntRow[a[t].first] == m || cntCol[a[t].second] == n) {
                return i;
            }
        }
        return -1;  // Fake Return
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def firstCompleteIndex(self, arr: List[int], mat: List[List[int]]) -> int:
        n, m = len(mat), len(mat[0])
        a = [[] for _ in range(n * m)]
        for i in range(n):
            for j in range(m):
                a[mat[i][j] - 1] = [i, j]
        rowCnt, colCnt = [0] * n, [0] * m
        for i in range(len(arr)):
            t = arr[i] - 1
            rowCnt[a[t][0]] += 1
            colCnt[a[t][1]] += 1
            if rowCnt[a[t][0]] == m or colCnt[a[t][1]] == n:
                return i
        return -1  # Fake Return
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/12/01/LeetCode%202661.%E6%89%BE%E5%87%BA%E5%8F%A0%E6%B6%82%E5%85%83%E7%B4%A0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/134729002](https://letmefly.blog.csdn.net/article/details/134729002)
