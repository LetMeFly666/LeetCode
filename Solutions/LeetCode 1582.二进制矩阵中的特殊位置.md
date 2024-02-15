---
title: 1582.二进制矩阵中的特殊位置
date: 2022-09-04 14:59:22
tags: [题解, LeetCode, 简单, 数组, 矩阵]
---

# 【LetMeFly】1582.二进制矩阵中的特殊位置

力扣题目链接：[https://leetcode.cn/problems/special-positions-in-a-binary-matrix/](https://leetcode.cn/problems/special-positions-in-a-binary-matrix/)

<p>给你一个大小为 <code>rows x cols</code> 的矩阵 <code>mat</code>，其中 <code>mat[i][j]</code> 是 <code>0</code> 或 <code>1</code>，请返回 <strong>矩阵&nbsp;<em><code>mat</code></em> 中特殊位置的数目</strong> 。</p>

<p><strong>特殊位置</strong> 定义：如果 <code>mat[i][j] == 1</code> 并且第 <code>i</code> 行和第 <code>j</code> 列中的所有其他元素均为 <code>0</code>（行和列的下标均 <strong>从 0 开始</strong> ），则位置 <code>(i, j)</code> 被称为特殊位置。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>mat = [[1,0,0],
&nbsp;           [0,0,<strong>1</strong>],
&nbsp;           [1,0,0]]
<strong>输出：</strong>1
<strong>解释：</strong>(1,2) 是一个特殊位置，因为 mat[1][2] == 1 且所处的行和列上所有其他元素都是 0
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>mat = [[<strong>1</strong>,0,0],
&nbsp;           [0,<strong>1</strong>,0],
&nbsp;           [0,0,<strong>1</strong>]]
<strong>输出：</strong>3
<strong>解释：</strong>(0,0), (1,1) 和 (2,2) 都是特殊位置
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>mat = [[0,0,0,<strong>1</strong>],
&nbsp;           [<strong>1</strong>,0,0,0],
&nbsp;           [0,1,1,0],
&nbsp;           [0,0,0,0]]
<strong>输出：</strong>2
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>mat = [[0,0,0,0,0],
&nbsp;           [<strong>1</strong>,0,0,0,0],
&nbsp;           [0,<strong>1</strong>,0,0,0],
&nbsp;           [0,0,<strong>1</strong>,0,0],
&nbsp;           [0,0,0,1,1]]
<strong>输出：</strong>3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>rows == mat.length</code></li>
	<li><code>cols == mat[i].length</code></li>
	<li><code>1 &lt;= rows, cols &lt;= 100</code></li>
	<li><code>mat[i][j]</code> 是 <code>0</code> 或 <code>1</code></li>
</ul>


    
## 方法一：直接模拟

直接遍历一遍原始矩阵，如果当前元素是1，就判断是否这一行除此元素外都是0并且这一列除此元素外都是0。

+ 时间复杂度$O(mn(m+n))$，其中原始矩阵的大小为$n\times m$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        int n = mat.size(), m = mat[0].size();
        function<bool(int, int)> ok = [&](int x, int y) {
            for (int i = 0; i < n; i++) {
                if (i == x)
                    continue;
                if (mat[i][y])
                    return false;
            }
            for (int j = 0; j < m; j++) {
                if (j == y)
                    continue;
                if (mat[x][j])
                    return false;
            }
            return true;
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] && ok(i, j)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
```

## 方法二：记录当前行/列有多少个1

首先遍历一遍原始矩阵，记录下每一行有多少个1、每一列有多少个1

之后再遍历一遍矩阵，如果当前位置元素为1，并且这一行只有一个1并且这一列也只有一个1，那么答案数量加一

+ 时间复杂度$O(mn)$，其中原始矩阵的大小为$n\times m$
+ 空间复杂度$O(m+n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        int n = mat.size(), m = mat[0].size();
        vector<int> row(n, 0), col(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                row[i] += mat[i][j];
                col[j] += mat[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] && row[i] == 1 && col[j] == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/09/04/LeetCode%201582.%E4%BA%8C%E8%BF%9B%E5%88%B6%E7%9F%A9%E9%98%B5%E4%B8%AD%E7%9A%84%E7%89%B9%E6%AE%8A%E4%BD%8D%E7%BD%AE/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126689744](https://letmefly.blog.csdn.net/article/details/126689744)
