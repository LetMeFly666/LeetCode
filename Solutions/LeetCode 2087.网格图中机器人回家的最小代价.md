---
title: 2087.网格图中机器人回家的最小代价：脑筋急转弯（固定走法）
date: 2026-04-04 14:43:15
tags: [题解, LeetCode, 中等, 贪心, 数组, 脑筋急转弯]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.com/uploads/2021/10/11/eg-1.png
---

# 【LetMeFly】2087.网格图中机器人回家的最小代价：脑筋急转弯（固定走法）

力扣题目链接：[https://leetcode.cn/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/](https://leetcode.cn/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/)

<p>给你一个&nbsp;<code>m x n</code>&nbsp;的网格图，其中&nbsp;<code>(0, 0)</code>&nbsp;是最左上角的格子，<code>(m - 1, n - 1)</code>&nbsp;是最右下角的格子。给你一个整数数组&nbsp;<code>startPos</code>&nbsp;，<code>startPos = [start<sub>row</sub>, start<sub>col</sub>]</code>&nbsp;表示 <strong>初始</strong>&nbsp;有一个 <strong>机器人</strong>&nbsp;在格子&nbsp;<code>(start<sub>row</sub>, start<sub>col</sub>)</code>&nbsp;处。同时给你一个整数数组&nbsp;<code>homePos</code>&nbsp;，<code>homePos = [home<sub>row</sub>, home<sub>col</sub>]</code>&nbsp;表示机器人的 <strong>家</strong>&nbsp;在格子&nbsp;<code>(home<sub>row</sub>, home<sub>col</sub>)</code>&nbsp;处。</p>

<p>机器人需要回家。每一步它可以往四个方向移动：<strong>上</strong>，<strong>下</strong>，<strong>左</strong>，<strong>右</strong>，同时机器人不能移出边界。每一步移动都有一定代价。再给你两个下标从&nbsp;<strong>0</strong>&nbsp;开始的额整数数组：长度为&nbsp;<code>m</code>&nbsp;的数组&nbsp;<code>rowCosts</code> &nbsp;和长度为 <code>n</code>&nbsp;的数组&nbsp;<code>colCosts</code>&nbsp;。</p>

<ul>
	<li>如果机器人往 <strong>上</strong>&nbsp;或者往 <strong>下</strong>&nbsp;移动到第 <code>r</code>&nbsp;<strong>行</strong>&nbsp;的格子，那么代价为&nbsp;<code>rowCosts[r]</code>&nbsp;。</li>
	<li>如果机器人往 <strong>左</strong>&nbsp;或者往 <strong>右</strong>&nbsp;移动到第 <code>c</code>&nbsp;<strong>列</strong> 的格子，那么代价为&nbsp;<code>colCosts[c]</code>&nbsp;。</li>
</ul>

<p>请你返回机器人回家需要的 <strong>最小总代价</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/10/11/eg-1.png" style="width: 282px; height: 217px;"></p>

<pre><strong>输入：</strong>startPos = [1, 0], homePos = [2, 3], rowCosts = [5, 4, 3], colCosts = [8, 2, 6, 7]
<b>输出：</b>18
<b>解释：</b>一个最优路径为：
从 (1, 0) 开始
-&gt; 往下走到 (<em><strong>2</strong></em>, 0) 。代价为 rowCosts[2] = 3 。
-&gt; 往右走到 (2, <em><strong>1</strong></em>) 。代价为 colCosts[1] = 2 。
-&gt; 往右走到 (2, <em><strong>2</strong></em>) 。代价为 colCosts[2] = 6 。
-&gt; 往右走到 (2, <em><strong>3</strong></em>) 。代价为 colCosts[3] = 7 。
总代价为 3 + 2 + 6 + 7 = 18</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>startPos = [0, 0], homePos = [0, 0], rowCosts = [5], colCosts = [26]
<b>输出：</b>0
<b>解释：</b>机器人已经在家了，所以不需要移动。总代价为 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == rowCosts.length</code></li>
	<li><code>n == colCosts.length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= rowCosts[r], colCosts[c] &lt;= 10<sup>4</sup></code></li>
	<li><code>startPos.length == 2</code></li>
	<li><code>homePos.length == 2</code></li>
	<li><code>0 &lt;= start<sub>row</sub>, home<sub>row</sub> &lt; m</code></li>
	<li><code>0 &lt;= start<sub>col</sub>, home<sub>col</sub> &lt; n</code></li>
</ul>


    
## 解题方法：脑筋急转弯（固定走法）

想想我们是怎么计算代价的，如果上下移动到了某一行，不论是在哪一列移动到的，都加上这一行的“代价”；列同理。

假设起点终点不在同一行，那么竖直方向上从起点到终点的移动是不可避免的。并且我们没有必要往上移动后再往下移动这样来回绕路；竖直方向同理。

也就是说，任何场景我们都直接像样例中那样一个L形路径走过去就行了。

+ 时间复杂度$O(\mathcal{O}(|start_{row} - home_{row}| + |start_{col} - home_{col}|))$
+ 空间复杂度$O(1)$，前提是不使用python普通切片改为循环

### AC代码

#### C++

$(起点, 终点]$

```cpp
/*
 * @LastEditTime: 2026-04-04 14:05:23
 */
class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int ans = 0;
        for (int from = startPos[0], to = homePos[0], direction = to > from ? 1 : -1; from != to; from += direction) {
            ans += rowCosts[from + direction];
        }
        for (int from = startPos[1], to = homePos[1], direction = to > from ? 1 : -1; from != to; from += direction) {
            ans += colCosts[from + direction];
        }
        return ans;
    }
};
```

#### Python

$[起点, 终点] - 起点$

```python
'''
LastEditTime: 2026-04-04 14:10:12
'''
from typing import List

class Solution:
    def minCost(self, startPos: List[int], homePos: List[int], rowCosts: List[int], colCosts: List[int]) -> int:
        sx, sy = startPos
        ex, ey = homePos
        return sum(rowCosts[min(sx, ex) : max(sx, ex) + 1]) + sum(colCosts[min(sy, ey) : max(sy, ey) + 1]) - rowCosts[sx] - colCosts[sy]
```

python切片会拷贝不可变元素

```python
>>> a = [1, 2, 3, 4]
>>> b = a[1:3]
>>> print(b)
[2, 3]
>>> b[0] = 0
>>> print(b)
[0, 3]
>>> print(a)
[1, 2, 3, 4]
```

<details><summary>啥都没说系列</summary>虽说是固定走法，但其实是固定中又偏自由的走法。<br/>可先左再下，也可先下再左，也可一左一下，反正拐弯不要钱，只要别同时存在往左和往右就好了。</details>

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/159828365)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/04/04/LeetCode%202087.%E7%BD%91%E6%A0%BC%E5%9B%BE%E4%B8%AD%E6%9C%BA%E5%99%A8%E4%BA%BA%E5%9B%9E%E5%AE%B6%E7%9A%84%E6%9C%80%E5%B0%8F%E4%BB%A3%E4%BB%B7/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
