---
title: 799.香槟塔：一层一层模拟
date: 2022-11-20 11:18:13
tags: [题解, LeetCode, 中等, 动态规划, DP]
categories: [题解, LeetCode]
---

# 【LetMeFly】799.香槟塔：一层一层模拟

力扣题目链接：[https://leetcode.cn/problems/champagne-tower/](https://leetcode.cn/problems/champagne-tower/)

<p>我们把玻璃杯摆成金字塔的形状，其中&nbsp;<strong>第一层</strong>&nbsp;有 <code>1</code> 个玻璃杯， <strong>第二层</strong>&nbsp;有 <code>2</code> 个，依次类推到第 100 层，每个玻璃杯 (250ml) 将盛有香槟。</p>

<p>从顶层的第一个玻璃杯开始倾倒一些香槟，当顶层的杯子满了，任何溢出的香槟都会立刻等流量的流向左右两侧的玻璃杯。当左右两边的杯子也满了，就会等流量的流向它们左右两边的杯子，依次类推。（当最底层的玻璃杯满了，香槟会流到地板上）</p>

<p>例如，在倾倒一杯香槟后，最顶层的玻璃杯满了。倾倒了两杯香槟后，第二层的两个玻璃杯各自盛放一半的香槟。在倒三杯香槟后，第二层的香槟满了 - 此时总共有三个满的玻璃杯。在倒第四杯后，第三层中间的玻璃杯盛放了一半的香槟，他两边的玻璃杯各自盛放了四分之一的香槟，如下图所示。</p>

<p><img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/03/09/tower.png" style="height: 241px; width: 350px;" /></p>

<p>现在当倾倒了非负整数杯香槟后，返回第 <code>i</code> 行 <code>j</code>&nbsp;个玻璃杯所盛放的香槟占玻璃杯容积的比例（ <code>i</code> 和 <code>j</code>&nbsp;都从0开始）。</p>

<p>&nbsp;</p>

<pre>
<strong>示例 1:</strong>
<strong>输入:</strong> poured(倾倒香槟总杯数) = 1, query_glass(杯子的位置数) = 1, query_row(行数) = 1
<strong>输出:</strong> 0.00000
<strong>解释:</strong> 我们在顶层（下标是（0，0））倒了一杯香槟后，没有溢出，因此所有在顶层以下的玻璃杯都是空的。

<strong>示例 2:</strong>
<strong>输入:</strong> poured(倾倒香槟总杯数) = 2, query_glass(杯子的位置数) = 1, query_row(行数) = 1
<strong>输出:</strong> 0.50000
<strong>解释:</strong> 我们在顶层（下标是（0，0）倒了两杯香槟后，有一杯量的香槟将从顶层溢出，位于（1，0）的玻璃杯和（1，1）的玻璃杯平分了这一杯香槟，所以每个玻璃杯有一半的香槟。
</pre>

<p><meta charset="UTF-8" /></p>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> poured = 100000009, query_row = 33, query_glass = 17
<strong>输出:</strong> 1.00000
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>0 &lt;=&nbsp;poured &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= query_glass &lt;= query_row&nbsp;&lt; 100</code></li>
</ul>

## 方法总述

总之我们需要一层一层地往下模拟。

至于**空间分配** ，大致有三种方式：

1. 直接开$100\times 100$的double数组 或 $row\times row$大小的二维数组；
2. 动态开第$i$行长度为$i+1$的二维数组；
3. 开两行一维数组，因为下一行的计算只需要运用到上一行的信息。

至于**计算方式** ，大致有两种方式：

1. 由当前行直接计算并分配给下一行
2. 由上一行信息计算当前行

## 具体方法：以《固定大小空间 + 下层看上层》为例

开辟一个大小为$dp[100][100]$的二维数组

其中$dp[i][j]$代表第$i$行第$j$列玻璃杯的香槟**接收量**（下标从$0$开始）

这样，我们就很容易得到状态转移方程：

$dp[i][j] = (dp[i - 1][j - 1] - 1) / 2 + (dp[i - 1][j] - 1) / 2$（注意边界条件、是否为负）

也就是说，上层玻璃杯在自己盛满（-1）的情况下，会有一半溢到当前玻璃杯中。

最终返回$dp[query_row][query_glass]$即为答案。

+ 时间复杂度$O(qeury_row\times query_glass)$
+ 空间复杂度$O(query_row\times query_glass)$（也可以不开辟大小为$100\times100$的空间，而仅仅开辟大小为$query_row\times query_glass$的空间，这样空间复杂度就变成了$query_row\times query_glass$）

优化：当前这一层的状态之和上一层有关，因此，我们可以只开辟两个一维数组，只存放当前和上一行的状态。这样空间复杂度就变成了$O(max(query_row, query_glass))$

### AC代码

#### C++ - 固定大小空间 + 下层看上层

```cpp
/*
 * @LastEditTime: 2022-11-20 11:06:57
 */
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double glass[100][100];
        glass[0][0] = poured;
        for (int i = 1; i <= query_row; i++) {
            for (int j = 0; j <= query_glass; j++) {
                if (j == 0) {
                    glass[i][j] = max((double)0, (glass[i - 1][j] - 1) / 2);
                }
                else {
                    glass[i][j] = max((double)0, (glass[i - 1][j] - 1) / 2) + max((double)0, (glass[i - 1][j - 1] - 1) / 2);
                }
            }
        }
        return min((double)1, glass[query_row][query_glass]);
    }
};
```

运行结果还不错

![result](https://cors.letmefly.xyz/https://img-blog.csdnimg.cn/e1042e37b17e4c27bdd1083fd3f62719.jpeg#pic_center)

#### C++ - 每行不等长数组 + 上层算下层

```cpp
/*
 * @LastEditTime: 2026-02-14 09:44:57
 */
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> tower(query_row + 1);
        tower[0].resize(1);
        tower[0][0] = poured;
        for (int i = 0; i < query_row; i++) {
            tower[i + 1].resize(i + 2);
            for (int j = 0; j <= i; j++) {
                if (tower[i][j] <= 1) {
                    continue;
                }
                double half_more = (tower[i][j] - 1) / 2;
                tower[i + 1][j] += half_more;
                tower[i + 1][j + 1] += half_more;
            }
        }
        return min(1., tower[query_row][query_glass]);
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/11/20/LeetCode%200799.%E9%A6%99%E6%A7%9F%E5%A1%94/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127946948](https://letmefly.blog.csdn.net/article/details/127946948)
