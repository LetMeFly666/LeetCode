---
title: 2483.商店的最少代价：两次遍历 -> 一次遍历
date: 2025-12-26 18:45:20
tags: [题解, LeetCode, 中等, 字符串, 遍历]
categories: [题解, LeetCode]
---

# 【LetMeFly】2483.商店的最少代价：两次遍历 -> 一次遍历

力扣题目链接：[https://leetcode.cn/problems/minimum-penalty-for-a-shop/](https://leetcode.cn/problems/minimum-penalty-for-a-shop/)

<p>给你一个顾客访问商店的日志，用一个下标从 <strong>0</strong>&nbsp;开始且只包含字符&nbsp;<code>'N'</code> 和&nbsp;<code>'Y'</code>&nbsp;的字符串&nbsp;<code>customers</code>&nbsp;表示：</p>

<ul>
	<li>如果第&nbsp;<code>i</code>&nbsp;个字符是&nbsp;<code>'Y'</code>&nbsp;，它表示第&nbsp;<code>i</code>&nbsp;小时有顾客到达。</li>
	<li>如果第&nbsp;<code>i</code>&nbsp;个字符是&nbsp;<code>'N'</code>&nbsp;，它表示第 <code>i</code>&nbsp;小时没有顾客到达。</li>
</ul>

<p>如果商店在第&nbsp;<code>j</code>&nbsp;小时关门（<code>0 &lt;= j &lt;= n</code>），代价按如下方式计算：</p>

<ul>
	<li>在开门期间，如果某一个小时没有顾客到达，代价增加 <code>1</code>&nbsp;。</li>
	<li>在关门期间，如果某一个小时有顾客到达，代价增加&nbsp;<code>1</code>&nbsp;。</li>
</ul>

<p>请你返回在确保代价 <strong>最小</strong>&nbsp;的前提下，商店的&nbsp;<strong>最早</strong>&nbsp;关门时间。</p>

<p>注意，商店在第 <code>j</code>&nbsp;小时关门表示在第 <code>j</code> 小时以及之后商店处于关门状态。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>customers = "YYNY"
<b>输出：</b>2
<b>解释：</b>
- 第 0 小时关门，总共 1+1+0+1 = 3 代价。
- 第 1 小时关门，总共 0+1+0+1 = 2 代价。
- 第 2 小时关门，总共 0+0+0+1 = 1 代价。
- 第 3 小时关门，总共 0+0+1+1 = 2 代价。
- 第 4 小时关门，总共 0+0+1+0 = 1 代价。
在第 2 或第 4 小时关门代价都最小。由于第 2 小时更早，所以最优关门时间是 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>customers = "NNNNN"
<b>输出：</b>0
<b>解释：</b>最优关门时间是 0 ，因为自始至终没有顾客到达。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>customers = "YYYY"
<b>输出：</b>4
<b>解释：</b>最优关门时间是 4 ，因为每一小时均有顾客到达。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= customers.length &lt;= 10<sup>5</sup></code></li>
	<li><code>customers</code>&nbsp;只包含字符&nbsp;<code>'Y'</code>&nbsp;和&nbsp;<code>'N'</code>&nbsp;。</li>
</ul>


    
## 解题方法一：两次遍历

先计算下直接不开门的话总代价是多少。

接着遍历顾客字符串，遍历到第i天时计算这个顾客走之后关门的总代价是多少。

取一个最小总代价对应的关门时间；如有相同则取最早的那个。

假设当前总代价为`x`，准备改为往后一个顾客时间再关门，那么就看下一个时间是`Y`还是`N`。如果为`Y`则总代价减1否则总代价加1。

+ 时间复杂度$O(len(customers))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2025-12-26 18:42:18
 */
class Solution {
public:
    int bestClosingTime(string customers) {
        int maxium = 0, ans = 0;
        for (char c : customers) {
            maxium += c == 'Y';
        }
        int thisCost = maxium;
        for (int i = 0; i < customers.size(); i++) {
            if (customers[i] == 'Y') {
                thisCost--;
            } else {
                thisCost++;
            }
            if (thisCost < maxium) {
                maxium = thisCost;
                ans = i + 1;
            }
        }
        return ans;
    }
};
```

## 解题方法二：一次遍历

不难发现第一次遍历计算得到的“直接不开门”状态下的代价其实没有意义，将其视为0且后续顾客在此基础上浮动即可。

+ 时间复杂度$O(len(customers))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2025-12-26 18:46:24
 */
class Solution {
public:
    int bestClosingTime(string customers) {
        int maxium = 0, ans = 0;
        int thisCost = 0;
        for (int i = 0; i < customers.size(); i++) {
            if (customers[i] == 'Y') {
                thisCost--;
            } else {
                thisCost++;
            }
            if (thisCost < maxium) {
                maxium = thisCost;
                ans = i + 1;
            }
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/156312519)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/12/26/LeetCode%202483.%E5%95%86%E5%BA%97%E7%9A%84%E6%9C%80%E5%B0%91%E4%BB%A3%E4%BB%B7/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
