---
title: 1386.安排电影院座位：哈希表+位运算
date: 2026-08-19 11:43:42
tags: [题解, LeetCode, 中等, 贪心, 位运算, 数组, 哈希表, map, 离散化]
categories: [题解, LeetCode]
index_img: https://files.letmefly.xyz/d/n/leetcode/1386-cinema_seats_3.png
---

# 【LetMeFly】1386.安排电影院座位：哈希表+位运算

力扣题目链接：[https://leetcode.cn/problems/cinema-seat-allocation/](https://leetcode.cn/problems/cinema-seat-allocation/)

<p><img alt="" src="https://assets.leetcode.cn/aliyun-lc-upload/uploads/2020/03/21/cinema_seats_1.png" style="height: 149px; width: 400px;" /></p>

<p>如上图所示，电影院的观影厅中有 <code>n</code>&nbsp;行座位，行编号从 1&nbsp;到 <code>n</code>&nbsp;，且每一行内总共有 10 个座位，列编号从 1 到 10 。</p>

<p>给定一个二维数组&nbsp;<code>reservedSeats</code>&nbsp;，其中&nbsp;<code>reservedSeats[i] = [row<sub>i</sub>, seat<sub>i</sub>]</code> 表示第&nbsp;<code>row<sub>i</sub></code> 行的座位&nbsp;<code>seat<sub>i</sub></code> 已经被预定。</p>

<p>四人小组必须被安排在同一排的四个座位上。该小组可以坐在以下座位块之一：</p>

<ul>
	<li>座位 <code>2, 3, 4, 5</code></li>
	<li>座位 <code>4, 5, 6, 7</code></li>
	<li>座位 <code>6, 7, 8, 9</code></li>
</ul>

<p>只有当该块中的所有座位都 <strong>没有</strong> 被预订时，才能使用该块。每个座位 <strong>最多</strong> 只能分配给一个小组。</p>

<p>返回一个整数，表示可以分配的 <strong>最大</strong> 四人小组数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.cn/aliyun-lc-upload/uploads/2020/03/21/cinema_seats_3.png" style="height: 96px; width: 400px;" /></p>

<pre>
<strong>输入：</strong>n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
<strong>输出：</strong>4
<strong>解释：</strong>上图所示是最优的安排方案，总共可以安排 4 个家庭。蓝色的叉表示被预约的座位，橙色的连续座位表示一个 4 人家庭。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 2, reservedSeats = [[2,1],[1,8],[2,6]]
<strong>输出：</strong>2
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 4, reservedSeats = [[4,3],[1,4],[4,6],[1,7]]
<strong>输出：</strong>4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;=&nbsp;reservedSeats.length &lt;= min(10 * n, 10<sup>4</sup>)</code></li>
	<li><code>reservedSeats[i]&nbsp;== [row<sub>i</sub>, seat<sub>i</sub>]</code></li>
	<li><code>1&nbsp;&lt;=&nbsp;row<sub>i</sub> &lt;= n</code></li>
	<li><code>1 &lt;=&nbsp;seat<sub>i</sub> &lt;= 10</code></li>
	<li>所有&nbsp;<code>reservedSeats[i]</code> 都是互不相同的。</li>
</ul>

What a huge cinema.

## 解题方法：哈希表 + 位运算

$n$的范围是$10^9$所以需要使用哈希表离散化处理，可以使用一个哈希表记录每一行的预订情况：

> 怎么记录某行的预订情况呢？使用一个整数即可。某行第$i$个座位被预订的话，就将第$i$位置`1`。

遍历一遍`reservedSeats`得到哈希表，看下哈希表大小（即有多少行被预订）。

+ 对于没有被预订的行，最多可以安排两个四人小组。
+ 对于有预订的行：如果$2\sim 9$都空则可座两组；否则如果$2\sim 5$空或者$4\sim 7$空或者$6\sim 9$空则可座一组。

> 怎么看某行$2\sim 9$是否*全空*呢？可以使用位运算，提前算出$2\sim 9$位都为`1`的mask，和*此行预订情况*做或运算，结果非零则*全空*。

### 时空复杂度

+ 时间复杂度$O(len(reservedSeats))$
+ 空间复杂度$O(len(reservedSeats))$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-08-19 11:43:10
 */
const int mask1 = 1 << 2 | 1 << 3 | 1 << 4 | 1 << 5;
const int mask2 = 1 << 4 | 1 << 5 | 1 << 6 | 1 << 7;
const int mask3 = 1 << 6 | 1 << 7 | 1 << 8 | 1 << 9;
const int mask4 = mask1 | mask3;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> reserved;
        for (vector<int>& people : reservedSeats) {
            reserved[people[0]] |= 1 << people[1];
        }
        int ans = (n - reserved.size()) * 2;
        for (auto [_, line] : reserved) {
            if (!(line & mask4)) {
                ans += 2;
            } else if (!(line & mask1) || !(line & mask2) || !(line & mask3)) {
                ans += 1;
            }
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/163883572)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/08/19/LeetCode%201386.%E5%AE%89%E6%8E%92%E7%94%B5%E5%BD%B1%E9%99%A2%E5%BA%A7%E4%BD%8D/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
