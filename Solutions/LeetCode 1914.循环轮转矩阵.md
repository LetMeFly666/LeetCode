---
title: 1914.循环轮转矩阵
date: 2026-05-09 22:19:41
tags: [题解, LeetCode, 中等, 数组, 矩阵, 模拟]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.com/uploads/2021/06/22/explanation_grid.jpg
---

# 【LetMeFly】1914.循环轮转矩阵

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


    
## 解题方法：xx

11111

+ 时间复杂度$O(N^2)$
+ 空间复杂度$O(N\log N)$

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

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/--------------------------)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/05/09/LeetCode%201914.%E5%BE%AA%E7%8E%AF%E8%BD%AE%E8%BD%AC%E7%9F%A9%E9%98%B5/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
