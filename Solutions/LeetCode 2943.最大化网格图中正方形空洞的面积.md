---
title: 2943.最大化网格图中正方形空洞的面积：小小思维
date: 2026-01-15 10:28:08
tags: [题解, LeetCode, 中等, 数组, 排序, 连续]
categories: [题解, LeetCode]
---

# 【LetMeFly】2943.最大化网格图中正方形空洞的面积：小小思维

力扣题目链接：[https://leetcode.cn/problems/maximize-area-of-square-hole-in-grid/](https://leetcode.cn/problems/maximize-area-of-square-hole-in-grid/)

<p>给你一个网格图，由&nbsp;<code>n + 2</code>&nbsp;条 <strong>横线段</strong>&nbsp;和&nbsp;<code>m + 2</code>&nbsp;条&nbsp;<strong>竖线段</strong>&nbsp;组成，一开始所有区域均为&nbsp;<code>1 x 1</code>&nbsp;的单元格。</p>

<p>所有线段的编号从 <strong>1</strong>&nbsp;开始。</p>

<p>给你两个整数&nbsp;<code>n</code> 和&nbsp;<code>m</code>&nbsp;。</p>

<p>同时给你两个整数数组&nbsp;<code>hBars</code> 和&nbsp;<code>vBars</code>&nbsp;。</p>

<ul>
	<li><code>hBars</code> 包含区间&nbsp;<code>[2, n + 1]</code>&nbsp;内&nbsp;<strong>互不相同</strong>&nbsp;的横线段编号。</li>
	<li><code>vBars</code>&nbsp;包含&nbsp;<code>[2, m + 1]</code>&nbsp;内&nbsp;<strong>互不相同的</strong>&nbsp;竖线段编号。</li>
</ul>

<p>如果满足以下条件之一，你可以 <strong>移除</strong>&nbsp;两个数组中的部分线段：</p>

<ul>
	<li>如果移除的是横线段，它必须是&nbsp;<code>hBars</code>&nbsp;中的值。</li>
	<li>如果移除的是竖线段，它必须是&nbsp;<code>vBars</code>&nbsp;中的值。</li>
</ul>

<p>请你返回移除一些线段后（<strong>可能不移除任何线段）</strong>，剩余网格图中 <strong>最大正方形</strong>&nbsp;空洞的面积，正方形空洞的意思是正方形 <strong>内部</strong> 不含有任何线段。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2023/11/05/screenshot-from-2023-11-05-22-40-25.png" style="width: 411px; height: 220px;" /></p>

<pre>
<b>输入：</b>n = 2, m = 1, hBars = [2,3], vBars = [2]
<b>输出：</b>4
<b>解释：</b>左边的图是一开始的网格图。
横线编号的范围是区间 [1,4] ，竖线编号的范围是区间 [1,3] 。
可以移除的横线段为 [2,3] ，竖线段为 [2] 。
一种得到最大正方形面积的方法是移除横线段 2 和竖线段 2 。
操作后得到的网格图如右图所示。
正方形空洞面积为 4。
无法得到面积大于 4 的正方形空洞。
所以答案为 4 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2023/11/04/screenshot-from-2023-11-04-17-01-02.png" style="width: 368px; height: 145px;" /></p>

<pre>
<b>输入：</b>n = 1, m = 1, hBars = [2], vBars = [2]
<b>输出：</b>4
<b>解释：</b>左边的图是一开始的网格图。
横线编号的范围是区间 [1,3] ，竖线编号的范围是区间 [1,3] 。
可以移除的横线段为 [2] ，竖线段为 [2] 。
一种得到最大正方形面积的方法是移除横线段 2 和竖线段 2 。
操作后得到的网格图如右图所示。
正方形空洞面积为 4。
无法得到面积大于 4 的正方形空洞。
所以答案为 4 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2023/11/05/screenshot-from-2023-11-05-22-33-35.png" style="width: 648px; height: 218px;" /></p>

<pre>
<b>输入：</b>n = 2, m = 3, hBars = [2,3], vBars = [2,3,4]
<b>输出：</b>9
<b>解释：</b>左边的图是一开始的网格图。
横线编号的范围是区间 [1,4] ，竖线编号的范围是区间 [1,5] 。
可以移除的横线段为 [2,3] ，竖线段为 [2,3,4] 。
一种得到最大正方形面积的方法是移除横线段 2、3 和竖线段 3、4 。
操作后得到的网格图如右图所示。
正方形空洞面积为 9。
无法得到面积大于 9 的正方形空洞。
所以答案为 9 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= m &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= hBars.length &lt;= 100</code></li>
	<li><code>2 &lt;= hBars[i] &lt;= n + 1</code></li>
	<li><code>1 &lt;= vBars.length &lt;= 100</code></li>
	<li><code>2 &lt;= vBars[i] &lt;= m + 1</code></li>
	<li><code>hBars</code>&nbsp;中的值互不相同。</li>
	<li><code>vBars</code> 中的值互不相同。</li>
</ul>


    
## 解题方法：最大连续

简单换个思维，$min(水平方向移除一些线后的最大连续空格, 竖直方向移除一些线后的最大连续空格)$即为**正**方形的最大边长。

水平方向移除一些线后的最大连续空格数是多少呢？很简单，把所有能移除的都移除呗。具体来说：

> 使用一个变量$last$记录当前空格向右处理到哪条线了，使用一个变量$cnt$记录当前空格的连续长度。
>
> 遍历分隔线数组，如果当前能移除的分隔线正好等于$last+1$，则空格可以继续网友拓展（更新$cnt+1$，更新$last+1$）；
>
> 否则，说明上个连续空格无法拓展到这条线，更新答案最大值，并将$cnt$初始化为$2$（这条线可以移除，空格长度为2），更新last为当前这条线。

+ 时间复杂度$O(h\log h+v\log v)$，其中$h=len(hBars)$，$v=len(vBars)$
+ 空间复杂度$O(\log h+\log v)$，时空复杂度的主要来源都是排序，因为题目没说给定分隔线有序。

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-01-15 10:20:39
 */
class Solution {
private:
    int getMaxDiff(vector<int>& v) {
        int last = 1, cnt = 1, ans = 1;
        for (int t : v) {
            if (t == last + 1) {
                cnt++;
                last++;
            } else {
                ans = max(ans, cnt);
                cnt = 2;
                last = t;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int side = min(getMaxDiff(hBars), getMaxDiff(vBars));
        return side * side;
    }

    int testGetMaxDiff(vector<int>& v) {
        return getMaxDiff(v);
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/156981125)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/01/15/LeetCode%202943.%E6%9C%80%E5%A4%A7%E5%8C%96%E7%BD%91%E6%A0%BC%E5%9B%BE%E4%B8%AD%E6%AD%A3%E6%96%B9%E5%BD%A2%E7%A9%BA%E6%B4%9E%E7%9A%84%E9%9D%A2%E7%A7%AF/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
