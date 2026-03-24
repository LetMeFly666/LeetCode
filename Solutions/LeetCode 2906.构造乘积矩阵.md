---
title: 2906.构造乘积矩阵：前后缀分解
date: 2026-03-24 22:10:07
tags: [题解, LeetCode, 中等, 数组, 矩阵, 前缀和, 前后缀分解]
categories: [题解, LeetCode]
---

# 【LetMeFly】2906.构造乘积矩阵：前后缀分解

力扣题目链接：[https://leetcode.cn/problems/construct-product-matrix/](https://leetcode.cn/problems/construct-product-matrix/)

<p>给你一个下标从 <strong>0</strong> 开始、大小为 <code>n * m</code> 的二维整数矩阵 <code><font face="monospace">grid</font></code><font face="monospace"> ，定义一个下标从 <strong>0</strong> 开始、大小为 <code>n * m</code> 的的二维矩阵</font> <code>p</code>。如果满足以下条件，则称 <code>p</code> 为 <code>grid</code> 的 <strong>乘积矩阵</strong> ：</p>

<ul>
	<li>对于每个元素 <code>p[i][j]</code> ，它的值等于除了 <code>grid[i][j]</code> 外所有元素的乘积。乘积对 <code>12345</code> 取余数。</li>
</ul>

<p>返回 <code>grid</code> 的乘积矩阵。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>grid = [[1,2],[3,4]]
<strong>输出：</strong>[[24,12],[8,6]]
<strong>解释：</strong>p[0][0] = grid[0][1] * grid[1][0] * grid[1][1] = 2 * 3 * 4 = 24
p[0][1] = grid[0][0] * grid[1][0] * grid[1][1] = 1 * 3 * 4 = 12
p[1][0] = grid[0][0] * grid[0][1] * grid[1][1] = 1 * 2 * 4 = 8
p[1][1] = grid[0][0] * grid[0][1] * grid[1][0] = 1 * 2 * 3 = 6
所以答案是 [[24,12],[8,6]] 。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>grid = [[12345],[2],[1]]
<strong>输出：</strong>[[2],[0],[0]]
<strong>解释：</strong>p[0][0] = grid[0][1] * grid[0][2] = 2 * 1 = 2
p[0][1] = grid[0][0] * grid[0][2] = 12345 * 1 = 12345. 12345 % 12345 = 0 ，所以 p[0][1] = 0
p[0][2] = grid[0][0] * grid[0][1] = 12345 * 2 = 24690. 24690 % 12345 = 0 ，所以 p[0][2] = 0
所以答案是 [[2],[0],[0]] 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == grid.length&nbsp;&lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m == grid[i].length&nbsp;&lt;= 10<sup>5</sup></code></li>
	<li><code>2 &lt;= n * m &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 10<sup>9</sup></code></li>
</ul>

一维版本：[238. 除了自身以外数组的乘积](https://leetcode.cn/problems/product-of-array-except-self/)

## 解题方法一：前后缀分解 O(mn)空间

由于模数并非质数，所以不方便全部求积后通过模逆元做除法，因此可以使用前缀和和后缀和两个数组，分别记录每个位置前面元素的乘积以及后面元素的乘积。

二维数组怎么定义“前面的元素”和“后面的元素”呢？很简单，把$n$行$m$列的二维数组看成$n\times m$大小的一维数组就好了，一维数组的下标$t$在原始二维数组中的下标是$(\lfloor\frac{t}{m}\rfloor, t\ \%\ m)$。

+ 时间复杂度$O(nm)$
+ 空间复杂度$O(nm)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-03-24 22:02:21
 */
typedef long long ll;
const ll MOD = 12345;
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        auto getIndex = [&](const int& t) {
            return pair<int, int>{t / m, t % m};
        };

        vector<vector<ll>> prefix(n, vector<ll>(m, 1));
        for (int t = 1; t < m * n; t++) {
            auto [i1, j1] = getIndex(t);
            auto [i0, j0] = getIndex(t - 1);
            prefix[i1][j1] = prefix[i0][j0] * grid[i0][j0] % MOD;
        }

        vector<vector<ll>> suffix(n, vector<ll>(m, 1));
        for (int t = m * n - 2; t >= 0; t--) {
            auto [i0, j0] = getIndex(t);
            auto [i1, j1] = getIndex(t + 1);
            suffix[i0][j0] = suffix[i1][j1] * grid[i1][j1] % MOD;
        }

        vector<vector<int>> ans(n, vector<int>(m, 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = prefix[i][j] * suffix[i][j] % MOD;
            }
        }
        return ans;
    }
};
```

## 解题方法二：前后缀分解 O(1)空间

函数返回值是不计入算法空间复杂度的，所以在计算前缀数组时，我们可以直接把前缀数组保存在答案数组中；在计算后缀数组的过程中，顺便把答案也算出来就好了。

+ 时间复杂度$O(nm)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-03-24 22:07:50
 */
typedef long long ll;
const ll MOD = 12345;
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        auto getIndex = [&](const int& t) {
            return pair<int, int>{t / m, t % m};
        };

        vector<vector<int>> ans(n, vector<int>(m, 1));
        for (int t = 1; t < m * n; t++) {
            auto [i1, j1] = getIndex(t);
            auto [i0, j0] = getIndex(t - 1);
            ans[i1][j1] = (ll)ans[i0][j0] * grid[i0][j0] % MOD;
        }

        ll suffix = 1;
        for (int t = m * n - 2; t >= 0; t--) {
            auto [i0, j0] = getIndex(t);
            auto [i1, j1] = getIndex(t + 1);
            suffix = suffix * grid[i1][j1] % MOD;
            ans[i0][j0] = ans[i0][j0] * suffix % MOD;
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/159436536)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/03/24/LeetCode%202906.%E6%9E%84%E9%80%A0%E4%B9%98%E7%A7%AF%E7%9F%A9%E9%98%B5/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
