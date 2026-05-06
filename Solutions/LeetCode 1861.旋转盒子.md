---
title: 1861.旋转盒子：模拟(双指针)
date: 2026-05-06 20:03:11
tags: [题解, LeetCode, 中等, 数组, 双指针, 矩阵, 矩阵旋转, 矩阵填充, 模拟]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.com/uploads/2021/04/08/rotatingtheboxleetcodewithstones.png
---

# 【LetMeFly】1861.旋转盒子：模拟(双指针)

力扣题目链接：[https://leetcode.cn/problems/rotating-the-box/](https://leetcode.cn/problems/rotating-the-box/)

<p>给你一个&nbsp;<code>m x n</code>&nbsp;的字符矩阵&nbsp;<code>boxGrid</code>&nbsp;，它表示一个箱子的侧视图。箱子的每一个格子可能为：</p>

<ul>
	<li><code>'#'</code>&nbsp;表示石头</li>
	<li><code>'*'</code>&nbsp;表示固定的障碍物</li>
	<li><code>'.'</code>&nbsp;表示空位置</li>
</ul>

<p>这个箱子被 <strong>顺时针旋转 90 度</strong>&nbsp;，由于重力原因，部分石头的位置会发生改变。每个石头会垂直掉落，直到它遇到障碍物，另一个石头或者箱子的底部。重力 <strong>不会</strong>&nbsp;影响障碍物的位置，同时箱子旋转不会产生<strong>惯性</strong>&nbsp;，也就是说石头的水平位置不会发生改变。</p>

<p>题目保证初始时&nbsp;<code>boxGrid</code>&nbsp;中的石头要么在一个障碍物上，要么在另一个石头上，要么在箱子的底部。</p>

<p>请你返回一个<em>&nbsp;</em><code>n x m</code>&nbsp;的矩阵，表示按照上述旋转后，箱子内的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/04/08/rotatingtheboxleetcodewithstones.png" style="width: 300px; height: 150px;" /></p>

<pre>
<b>输入：</b>box = [["#",".","#"]]
<b>输出：</b>[["."],
&nbsp;     ["#"],
&nbsp;     ["#"]]
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/04/08/rotatingtheboxleetcode2withstones.png" style="width: 375px; height: 195px;" /></p>

<pre>
<b>输入：</b>box = [["#",".","*","."],
&nbsp;           ["#","#","*","."]]
<b>输出：</b>[["#","."],
&nbsp;     ["#","#"],
&nbsp;     ["*","*"],
&nbsp;     [".","."]]
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/04/08/rotatingtheboxleetcode3withstone.png" style="width: 400px; height: 218px;" /></p>

<pre>
<b>输入：</b>box = [["#","#","*",".","*","."],
&nbsp;           ["#","#","#","*",".","."],
&nbsp;           ["#","#","#",".","#","."]]
<b>输出：</b>[[".","#","#"],
&nbsp;     [".","#","#"],
&nbsp;     ["#","#","*"],
&nbsp;     ["#","*","."],
&nbsp;     ["#",".","*"],
&nbsp;     ["#",".","."]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == boxGrid.length</code></li>
	<li><code>n == boxGrid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 500</code></li>
	<li><code>boxGrid[i][j]</code>&nbsp;只可能是&nbsp;<code>'#'</code>&nbsp;，<code>'*'</code>&nbsp;或者&nbsp;<code>'.'</code>&nbsp;。</li>
</ul>


    
## 解题方法：先向右，后旋转

首先让盒子里面的所有石头尽可能右移，然后把矩阵顺时针旋转90°C。

**石头右移**

一行一行地处理。

双指针，一个指针指向起始位置，一个指针向右移动，移动过程中记录一共多少石头。

当右指针遇到障碍或移出盒子，则从新分配这片连通区域的石头(先数个空格子、后数个石头)。

**矩阵旋转**

令$ans[n - i - 1] = boxGrid[i][j]$即可。

**时空复杂度**

+ 时间复杂度$O(mn)$
+ 空间复杂度$O(1)$，力扣返回值不计入算法空间复杂度

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-05-06 20:02:37
 */
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size(), m = boxGrid[0].size();
        for (int i = 0; i < n; i++) {
            for (int start = 0, now = 0, cnt = 0; now <= m; now++) {
                if (now == m || boxGrid[i][now] == '*') {  // 障碍
                    int empty = now - start - cnt;
                    for (int j = start; j < start + empty; j++) {
                        boxGrid[i][j] = '.';
                    }
                    for (int j = start + empty; j < now; j++) {
                        boxGrid[i][j] = '#';
                    }
                    start = now + 1;
                    cnt = 0;
                } else {
                    cnt += boxGrid[i][now] == '#';
                }
            }
        }

        vector<vector<char>> ans(m, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[j][n - i - 1] = boxGrid[i][j];
            }
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/160831430)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/05/06/LeetCode%201861.%E6%97%8B%E8%BD%AC%E7%9B%92%E5%AD%90/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
