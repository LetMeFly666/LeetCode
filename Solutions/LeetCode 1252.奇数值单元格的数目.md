---
title: 1252.奇数值单元格的数目
date: 2022-07-12 10:28:21
tags: [题解, LeetCode, 简单, 数组, 数学, 模拟, 奇偶, 计数]
---

# 【LetMeFly】1252.奇数值单元格的数目：低时间复杂度

力扣题目链接：[https://leetcode.cn/problems/cells-with-odd-values-in-a-matrix/](https://leetcode.cn/problems/cells-with-odd-values-in-a-matrix/)

<p>给你一个 <code>m x n</code> 的矩阵，最开始的时候，每个单元格中的值都是 <code>0</code>。</p>

<p>另有一个二维索引数组 <code>indices</code>，<code>indices[i] = [ri, ci]</code> 指向矩阵中的某个位置，其中 <code>ri</code> 和 <code>ci</code> 分别表示指定的行和列（<strong>从 <code>0</code> 开始编号</strong>）。</p>

<p>对 <code>indices[i]</code> 所指向的每个位置，应同时执行下述增量操作：</p>

<ol>
	<li><code>r<sub>i</sub></code> 行上的所有单元格，加 <code>1</code> 。</li>
	<li><code>c<sub>i</sub></code> 列上的所有单元格，加 <code>1</code> 。</li>
</ol>

<p>给你 <code>m</code>、<code>n</code> 和 <code>indices</code> 。请你在执行完所有 <code>indices</code> 指定的增量操作后，返回矩阵中 <strong>奇数值单元格</strong> 的数目。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/11/06/e1.png" style="height: 118px; width: 600px;" /></p>

<pre>
<strong>输入：</strong>m = 2, n = 3, indices = [[0,1],[1,1]]
<strong>输出：</strong>6
<strong>解释：</strong>最开始的矩阵是 [[0,0,0],[0,0,0]]。
第一次增量操作后得到 [[1,2,1],[0,1,0]]。
最后的矩阵是 [[1,3,1],[1,3,1]]，里面有 6 个奇数。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/11/06/e2.png" style="height: 150px; width: 600px;" /></p>

<pre>
<strong>输入：</strong>m = 2, n = 2, indices = [[1,1],[0,0]]
<strong>输出：</strong>0
<strong>解释：</strong>最后的矩阵是 [[2,2],[2,2]]，里面没有奇数。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= m, n <= 50</code></li>
	<li><code>1 <= indices.length <= 100</code></li>
	<li><code>0 <= r<sub>i</sub> < m</code></li>
	<li><code>0 <= c<sub>i</sub> < n</code></li>
</ul>

<p> </p>

<p><strong>进阶：</strong>你可以设计一个时间复杂度为 <code>O(n + m + indices.length)</code> 且仅用 <code>O(n + m)</code> 额外空间的算法来解决此问题吗？</p>


    
## 方法一：模拟 + 计数：低时间复杂度

这道题提出了**进阶**，使用低复杂度完成本题。

下面将直接讲述低复杂度的思路：

首先开辟两个数组，长度分别是$m$和$n$，初始值是$0$

```cpp
vector<int> cols(m, 0);
vector<int> rows(n, 0);
```

然后对于$indices$中的每一个“坐标”，cols和rows的对应行和列分别 + 1

说白了就是统计每一行分别“加”了多少次。

```cpp
for (auto& v : indices) {
    cols[v[0]]++;
    rows[v[1]]++;
}
```

然后，我们统计$m$行中，“加”了计数次的行数、偶数次的行数；$n$列中，“加”了计数次的列数、偶数次的列数。

```cpp
int jiCol = 0;  // 奇行
int jiRow = 0;  // 奇列
for (int i = 0; i < m; 
    if (cols[i] % 2)
        jiCol++;
}
for (int i = 0; i < n; 
    if (rows[i] % 2)
        jiRow++;
}
int ouCol = m - jiCol;  // 偶行
int ouRow = n - jiRow;  // 偶列
```

接下来，**重点**来了：

**一个位置最终值为奇数的前提是：它的行和它的列中，一个加了奇数次，一个加了偶数次**。

同时，行和列互不干扰，因此，最终数值为奇数的格子的个数，就是$奇行\times偶列+偶行\times奇列$

```cpp
return jiCol * ouRow + ouCol * jiRow;
```

+ 时间复杂度$O(n+m+indices.length)$
+ 空间复杂度$O(n+m)$

![最终结果](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/55ade3dfccf9466f8371b2ee23e5e801.jpeg#pic_center)

### AC代码

#### C++

```cpp
class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> cols(m, 0);
        vector<int> rows(n, 0);
        for (auto& v : indices) {
            cols[v[0]]++;
            rows[v[1]]++;
        }
        int jiCol = 0;
        int jiRow = 0;
        for (int i = 0; i < m; i++) {
            if (cols[i] % 2)
                jiCol++;
        }
        for (int i = 0; i < n; i++) {
            if (rows[i] % 2)
                jiRow++;
        }
        int ouCol = m - jiCol;
        int ouRow = n - jiRow;
        return jiCol * ouRow + ouCol * jiRow;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/07/12/LeetCode%201252.%E5%A5%87%E6%95%B0%E5%80%BC%E5%8D%95%E5%85%83%E6%A0%BC%E7%9A%84%E6%95%B0%E7%9B%AE/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125738504](https://letmefly.blog.csdn.net/article/details/125738504)
