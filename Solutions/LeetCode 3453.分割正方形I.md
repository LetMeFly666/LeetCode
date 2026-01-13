---
title: 3453.分割正方形 I：二分查找
date: 2026-01-13 23:46:15
tags: [题解, LeetCode, 中等, 数组, 二分查找, 二分]
categories: [题解, LeetCode]
index_img: https://pic.leetcode.cn/1739609465-UaFzhk-4062example1drawio.png
---

# 【LetMeFly】3453.分割正方形 I：二分查找

力扣题目链接：[https://leetcode.cn/problems/separate-squares-i/](https://leetcode.cn/problems/separate-squares-i/)

<p>给你一个二维整数数组 <code>squares</code>&nbsp;，其中&nbsp;<code>squares[i] = [x<sub>i</sub>, y<sub>i</sub>, l<sub>i</sub>]</code> 表示一个与 x 轴平行的正方形的左下角坐标和正方形的边长。</p>

<p>找到一个<strong>最小的</strong> y 坐标，它对应一条水平线，该线需要满足它以上正方形的总面积 <strong>等于</strong> 该线以下正方形的总面积。</p>

<p>答案如果与实际答案的误差在 <code>10<sup>-5</sup></code> 以内，将视为正确答案。</p>

<p><strong>注意</strong>：正方形&nbsp;<strong>可能会&nbsp;</strong>重叠。重叠区域应该被&nbsp;<strong>多次计数&nbsp;</strong>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">squares = [[0,0,1],[2,2,1]]</span></p>

<p><strong>输出：</strong> <span class="example-io">1.00000</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://pic.leetcode.cn/1739609465-UaFzhk-4062example1drawio.png" style="width: 378px; height: 352px;" /></p>

<p>任何在 <code>y = 1</code> 和 <code>y = 2</code> 之间的水平线都会有 1 平方单位的面积在其上方，1 平方单位的面积在其下方。最小的 y 坐标是 1。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">squares = [[0,0,2],[1,1,1]]</span></p>

<p><strong>输出：</strong> <span class="example-io">1.16667</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://pic.leetcode.cn/1739609527-TWqefZ-4062example2drawio.png" style="width: 378px; height: 352px;" /></p>

<p>面积如下：</p>

<ul>
	<li>线下的面积：<code>7/6 * 2 (红色) + 1/6 (蓝色) = 15/6 = 2.5</code>。</li>
	<li>线上的面积：<code>5/6 * 2 (红色) + 5/6 (蓝色) = 15/6 = 2.5</code>。</li>
</ul>

<p>由于线以上和线以下的面积相等，输出为 <code>7/6 = 1.16667</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= squares.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>squares[i] = [x<sub>i</sub>, y<sub>i</sub>, l<sub>i</sub>]</code></li>
	<li><code>squares[i].length == 3</code></li>
	<li><code>0 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= l<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li>所有正方形的总面积不超过 <code>10<sup>12</sup></code>。</li>
</ul>


    
## 解题方法：二分查找

先算下所有正方形的总面积，然后二分分割线高度，太低就高点太高就低点。

终止条件：两次计算结果分割线移动返回不超过$10^{-5}$或直接进行$50$次求值。

```python
>>> 10**9 / 2**46
1.4210854715202004e-05
>>> 10**9 / 2**47
7.105427357601002e-06
```

+ 时间复杂度$O(C\times len(squares))$，其中$C=50$或$C=\log_2{max(squires[i][1])-min(squires[i][1])}$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-01-13 22:21:20
 */
class Solution {
private:
    double half = 0;
    vector<vector<int>> squares;

    bool check(double h) {
        double total = 0;
        for (vector<int>& s : squares) {
            double from = max(double(s[1]), h);
            double to = s[1] + s[2];
            total += max(0., (to - from) * s[2]);
        }

        return total > half;
    }
public:
    double separateSquares(vector<vector<int>>& squares) {
        long long total = 0;  // !!!!!记得初始化
        for (vector<int>& s : squares) {
            total += ((long long) s[2]) * s[2];
        }
        this->squares = move(squares);
        half = 1. * total / 2;

        double l = 0, r = 1000000000;
        for (int _ = 0; _ < 50; _++) {
            double mid = (l + r) / 2;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/156915633)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/01/13/LeetCode%203453.%E5%88%86%E5%89%B2%E6%AD%A3%E6%96%B9%E5%BD%A2I/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
