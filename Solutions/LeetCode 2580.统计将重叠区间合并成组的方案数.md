---
title: 2580.统计将重叠区间合并成组的方案数
date: 2024-03-27 13:17:02
tags: [题解, LeetCode, 中等, 数组, 排序]
---

# 【LetMeFly】2580.统计将重叠区间合并成组的方案数：排序（几行代码解决）——一步步思路描述版

力扣题目链接：[https://leetcode.cn/problems/count-ways-to-group-overlapping-ranges/](https://leetcode.cn/problems/count-ways-to-group-overlapping-ranges/)

<p>给你一个二维整数数组&nbsp;<code>ranges</code>&nbsp;，其中&nbsp;<code>ranges[i] = [start<sub>i</sub>, end<sub>i</sub>]</code>&nbsp;表示&nbsp;<code>start<sub>i</sub></code>&nbsp;到&nbsp;<code>end<sub>i</sub></code>&nbsp;之间（包括二者）的所有整数都包含在第&nbsp;<code>i</code>&nbsp;个区间中。</p>

<p>你需要将&nbsp;<code>ranges</code>&nbsp;分成 <strong>两个</strong>&nbsp;组（可以为空），满足：</p>

<ul>
	<li>每个区间只属于一个组。</li>
	<li>两个有 <strong>交集</strong>&nbsp;的区间必须在 <strong>同一个&nbsp;</strong>组内。</li>
</ul>

<p>如果两个区间有至少 <strong>一个</strong>&nbsp;公共整数，那么这两个区间是 <b>有交集</b>&nbsp;的。</p>

<ul>
	<li>比方说，区间&nbsp;<code>[1, 3]</code> 和&nbsp;<code>[2, 5]</code>&nbsp;有交集，因为&nbsp;<code>2</code>&nbsp;和&nbsp;<code>3</code>&nbsp;在两个区间中都被包含。</li>
</ul>

<p>请你返回将 <code>ranges</code>&nbsp;划分成两个组的 <strong>总方案数</strong>&nbsp;。由于答案可能很大，将它对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;后返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>ranges = [[6,10],[5,15]]
<b>输出：</b>2
<b>解释：</b>
两个区间有交集，所以它们必须在同一个组内。
所以有两种方案：
- 将两个区间都放在第 1 个组中。
- 将两个区间都放在第 2 个组中。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>ranges = [[1,3],[10,20],[2,5],[4,8]]
<b>输出：</b>4
<b>解释：</b>
区间 [1,3] 和 [2,5] 有交集，所以它们必须在同一个组中。
同理，区间 [2,5] 和 [4,8] 也有交集，所以它们也必须在同一个组中。
所以总共有 4 种分组方案：
- 所有区间都在第 1 组。
- 所有区间都在第 2 组。
- 区间 [1,3] ，[2,5] 和 [4,8] 在第 1 个组中，[10,20] 在第 2 个组中。
- 区间 [1,3] ，[2,5] 和 [4,8] 在第 2 个组中，[10,20] 在第 1 个组中。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= ranges.length &lt;= 10<sup>5</sup></code></li>
	<li><code>ranges[i].length == 2</code></li>
	<li><code>0 &lt;= start<sub>i</sub> &lt;= end<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 方法一：排序

### 思路

解决这道题需要明白以下两点：

1. $n$个区间分成两组，有多少种分法。
2. 合并所有有交集的区间后，还剩多少个区间（并将其记为$n$）。

### 方法

**$n$个区间分成两组，有多少种分法：**

根据示例1，一个区间分到2组，有两种分法。也就是说两个小组不同，```[1]、[]```和```[]、[1]```是两种不同的分法。

因此我们只需要从$n$个区间中取$k$个放到第一组，剩下的放到第二组中即可（$1\leq k\leq n$）。每个区间都可以被取和不取，因此共有$2^n$中分法。

**合并所有有交集的区间后，还剩多少个区间：**

很简单，将所有区间排个序（开始时间小的优先，结束时间顺序随意）并遍历。

使用一个变量$lastTo$来记录上一个合并后的区间最右边的元素（初始值为“无穷小”）。

遍历过程中如果当前区间的最左边元素大于$lastTo$，则两个区间无法合并，区间数加一；否则区间数不变。

遍历过程中更新$lastTo$。

```cpp
sort(ranges.begin(), ranges.end());
int lastTo = -1;
int cnt = 0;  // 合并后的区间数
for (vector<int>& range : ranges) {
    if (range[0] > lastTo) {
        cnt++;
    }
    lastTo = max(lastTo, range[1]);
}
```

### 具体实现

按照上述思路，确定好合并后的区间数量后（假设为$cnt$），计算$2^{cnt}\mod 1000000007$即为答案。

我们只需要：

```cpp
int ans = 1;
for (int i = 0; i < cnt; i++) {
    ans = ans * 2 % mod;
}
```

但不难发现，其实我们可以直接在$cnt$加一的时候顺便将$ans\times 2$，因此可写为：

```cpp
sort(ranges.begin(), ranges.end());
int lastTo = -1;
int ans = 1;
for (vector<int>& range : ranges) {
    if (range[0] > lastTo) {
        ans = ans * 2 % MOD;
    }
    lastTo = max(lastTo, range[1]);
}
```

### 时空复杂度

+ 时间复杂度$O(N^2)$
+ 空间复杂度$O(N\log N)$

### AC代码

#### C++

```cpp
const int MOD = 1e9 + 7;
class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end());
        int lastTo = -1;
        int ans = 1;
        for (vector<int>& range : ranges) {
            if (range[0] > lastTo) {
                ans = ans * 2 % MOD;
            }
            lastTo = max(lastTo, range[1]);
        }
        return ans;
    }
};
```

#### Python

```python
from typing import List


MOD = int(1e9) + 7

class Solution:
    def countWays(self, ranges: List[List[int]]) -> int:
        ranges.sort()
        lastTo = -1
        ans = 1
        for from_, to in ranges:
            if from_ > lastTo:
                ans = ans * 2 % MOD
            lastTo = max(lastTo, to)
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/03/27/LeetCode%202580.%E7%BB%9F%E8%AE%A1%E5%B0%86%E9%87%8D%E5%8F%A0%E5%8C%BA%E9%97%B4%E5%90%88%E5%B9%B6%E6%88%90%E7%BB%84%E7%9A%84%E6%96%B9%E6%A1%88%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/137074790](https://letmefly.blog.csdn.net/article/details/137074790)
