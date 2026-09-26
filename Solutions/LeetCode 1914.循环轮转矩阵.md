---
title: 1914.循环轮转矩阵：大模拟(数组原地轮转) —— 附O(1)空间版本
date: 2026-05-09 22:19:41
tags: [题解, LeetCode, 中等, 数组, 矩阵, 矩阵遍历, 矩阵填充, 模拟, 大模拟]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.com/uploads/2021/06/22/explanation_grid.jpg
---

# 【LetMeFly】1914.循环轮转矩阵：大模拟(数组原地轮转) —— 附O(1)空间版本

力扣题目链接：[https://leetcode.cn/problems/cyclically-rotating-a-grid/](https://leetcode.cn/problems/cyclically-rotating-a-grid/)

<p>给你一个大小为 <code>m x n</code> 的整数矩阵 <code>grid</code>​​​ ，其中 <code>m</code> 和 <code>n</code> 都是 <strong>偶数</strong> ；另给你一个整数 <code>k</code> 。</p>

<p>矩阵由若干层组成，如下图所示，每种颜色代表一层：</p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/06/10/ringofgrid.png" style="width: 231px; height: 258px;"></p>

<p>矩阵的循环轮转是通过分别循环轮转矩阵中的每一层完成的。在对某一层进行一次循环旋转操作时，层中的每一个元素将会取代其 <strong>逆时针 </strong>方向的相邻元素。轮转示例如下：</p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/22/explanation_grid.jpg" style="width: 500px; height: 268px;">
<p>返回执行 <code>k</code> 次循环轮转操作后的矩阵。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/19/rod2.png" style="width: 421px; height: 191px;">
<pre><strong>输入：</strong>grid = [[40,10],[30,20]], k = 1
<strong>输出：</strong>[[10,20],[40,30]]
<strong>解释：</strong>上图展示了矩阵在执行循环轮转操作时每一步的状态。</pre>

<p><strong>示例 2：</strong></p>
<strong><img alt="" src="https://assets.leetcode.com/uploads/2021/06/10/ringofgrid5.png" style="width: 231px; height: 262px;"></strong> <strong><img alt="" src="https://assets.leetcode.com/uploads/2021/06/10/ringofgrid6.png" style="width: 231px; height: 262px;"></strong> <strong><img alt="" src="https://assets.leetcode.com/uploads/2021/06/10/ringofgrid7.png" style="width: 231px; height: 262px;"></strong>

<pre><strong>输入：</strong>grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2
<strong>输出：</strong>[[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]
<strong>解释：</strong>上图展示了矩阵在执行循环轮转操作时每一步的状态。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>2 &lt;= m, n &lt;= 50</code></li>
	<li><code>m</code> 和 <code>n</code> 都是 <strong>偶数</strong></li>
	<li><code>1 &lt;= grid[i][j] &lt;=<sup> </sup>5000</code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>

虽然本题打了<a href="https://blog.letmefly.xyz/tags/%E5%A4%A7%E6%A8%A1%E6%8B%9F/">大模拟</a>的tag，但充其量也只是个中模拟罢了。

## 解题方法：大模拟

这道题目包含两个部分：

1. 把矩阵拆成一圈一圈的（共计能拆$\frac{\min \{m,n\}}2$圈）、把一圈的数据写到一个数组中方便进行轮转处理，轮转完成后把数组写回矩阵的这一圈；
2. 对于一个（上一部分拆分出来的）数组，轮转$k$次。

对于1.的模拟部分，当我们处理到从外到内第$th$圈时，这一圈共有$(m + n) \times 2 - 4-8\times th$个元素（记为$all$个元素）。创建一个长度为$all$的数组，逆时针遍历这一圈并将数据放入临时一维数组中，待数组完成$k$-轮转后再次遍历并放回原始矩阵。

对于2.的轮转部分，数组长度为$all$，首先令$k$对$all$取模，接着把数组向左轮转$k$次。由于$k\lt (m+n)\times 2-4$，所以直接模拟$k$次也行（时间复杂度$O(all\times k)$）；或者使用一个时间复杂度$O(all)$空间复杂度$O(1)$的方法更好（懂得原理后也会觉得更加简单）：

> $[1, 2, 3, 4, 5, 6, 7]$如何向左轮转$3$次变成$[4,5,6,7,1,2,3]$呢？三次翻转操作即可。
> 
> 第一次翻转直接翻转整个数组，第二次翻转前$all-k$个元素，第三次翻转后$k$个元素就行了。是的，就这么简单。
> 
> ```
> 1 2 3 4 5 6 7
> -------------
>       ↓
> 7 6 5 4 3 2 1
> -------
>    ↓
> 4 5 6 7 3 2 1
>         -----
>           ↓
> 4 5 6 7 1 2 3
> ```

+ 时间复杂度$O(mn)$
+ 空间复杂度$O(m+n)$，使用了一圈的临时空间

如果你是狠人的话(如ChatGPT)，甚至能写个$O(1)$空间的原地翻转，记得处理好下标映射就好了。

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-05-09 22:15:48
 */
class Solution {
private:
    int n, m, k;
    vector<vector<int>> grid;

    void init(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        this->grid = move(grid);
        this->k = k;
    }

    void rotate(int th) {
        int m = this->m - 2 * th;
        int n = this->n - 2 * th;
        int all = (m + n) * 2 - 4;
        int k = this->k % all;
        vector<int> round;
        round.reserve(all);

        for (int j = 0; j < m - 1; j++) {
            round.push_back(grid[th][th + j]);
        }
        for (int i = 0; i < n - 1; i++) {
            round.push_back(grid[th + i][th + m - 1]);
        }
        for (int j = m - 1; j > 0; j--) {
            round.push_back(grid[th + n - 1][th + j]);
        }
        for (int i = n - 1; i > 0; i--) {
            round.push_back(grid[th + i][th]);
        }

        reverse(round.begin(), round.end());
        reverse(round.begin(), round.begin() + all - k);
        reverse(round.begin() + all - k, round.end());

        int idx = 0;
        for (int j = 0; j < m - 1; j++) {
            grid[th][th + j] = round[idx++];
        }
        for (int i = 0; i < n - 1; i++) {
            grid[th + i][th + m - 1] = round[idx++];
        }
        for (int j = m - 1; j > 0; j--) {
            grid[th + n - 1][th + j] = round[idx++];
        }
        for (int i = n - 1; i > 0; i--) {
            grid[th + i][th] = round[idx++];
        }
    }
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        init(grid, k);
        
        for (int th = 0; th < min(m, n) / 2; th++) {
            rotate(th);
        }
        return move(this->grid);
    }
};
```

#### C++ - GPT写的O(1)空间复杂度版本

相当于把人写的“临时放到数组中”的操作直接给写了个函数映射到原始矩阵中了。

```cpp
/*
 * @LastEditTime: 2026-05-09 22:42:01
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int n, m, k;
    vector<vector<int>> grid;

    void init(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        this->grid = move(grid);
        this->k = k;
    }

    pair<int, int> locate(int th, int idx) {
        int m = this->m - 2 * th;
        int n = this->n - 2 * th;

        int top = th;
        int bottom = th + n - 1;
        int left = th;
        int right = th + m - 1;

        // 上
        if (idx < m - 1) {
            return {top, left + idx};
        }
        idx -= m - 1;

        // 右
        if (idx < n - 1) {
            return {top + idx, right};
        }
        idx -= n - 1;

        // 下
        if (idx < m - 1) {
            return {bottom, right - idx};
        }
        idx -= m - 1;

        // 左
        return {bottom - idx, left};
    }

    void reverse(int th, int l, int r) {
        while (l < r) {
            auto [x1, y1] = locate(th, l);
            auto [x2, y2] = locate(th, r);
            swap(grid[x1][y1], grid[x2][y2]);
            l++;
            r--;
        }
    }

    void rotate(int th) {
        int m = this->m - 2 * th;
        int n = this->n - 2 * th;

        int all = (m + n) * 2 - 4;
        int k = this->k % all;

        // 左轮转k次
        reverse(th, 0, all - 1);
        reverse(th, 0, all - k - 1);
        reverse(th, all - k, all - 1);
    }

public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        init(grid, k);
        
        for (int th = 0; th < min(m, n) / 2; th++) {
            rotate(th);
        }

        return move(this->grid);
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/160935294)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/05/09/LeetCode%201914.%E5%BE%AA%E7%8E%AF%E8%BD%AE%E8%BD%AC%E7%9F%A9%E9%98%B5/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
