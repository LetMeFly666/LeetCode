---
title: 2147.分隔长廊的方案数：非Hard组合数学
date: 2025-12-14 18:20:28
tags: [题解, LeetCode, 困难, 数学, 组合数学, 排列组合, 字符串, 动态规划]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.com/uploads/2021/12/04/1.png
---

# 【LetMeFly】2147.分隔长廊的方案数：非Hard组合数学

力扣题目链接：[https://leetcode.cn/problems/number-of-ways-to-divide-a-long-corridor/](https://leetcode.cn/problems/number-of-ways-to-divide-a-long-corridor/)

<p>在一个图书馆的长廊里，有一些座位和装饰植物排成一列。给你一个下标从 <strong>0</strong>&nbsp;开始，长度为 <code>n</code>&nbsp;的字符串&nbsp;<code>corridor</code>&nbsp;，它包含字母&nbsp;<code>'S'</code> 和&nbsp;<code>'P'</code>&nbsp;，其中每个&nbsp;<code>'S'</code>&nbsp;表示一个座位，每个&nbsp;<code>'P'</code>&nbsp;表示一株植物。</p>

<p>在下标 <code>0</code>&nbsp;的左边和下标 <code>n - 1</code>&nbsp;的右边 <strong>已经</strong>&nbsp;分别各放了一个屏风。你还需要额外放置一些屏风。每一个位置&nbsp;<code>i - 1</code> 和&nbsp;<code>i</code>&nbsp;之间（<code>1 &lt;= i &lt;= n - 1</code>），至多能放一个屏风。</p>

<p>请你将走廊用屏风划分为若干段，且每一段内都 <strong>恰好有两个座位</strong>&nbsp;，而每一段内植物的数目没有要求。可能有多种划分方案，如果两个方案中有任何一个屏风的位置不同，那么它们被视为 <strong>不同</strong> 方案。</p>

<p>请你返回划分走廊的方案数。由于答案可能很大，请你返回它对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;的结果。如果没有任何方案，请返回&nbsp;<code>0</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/12/04/1.png" style="width: 410px; height: 199px;"></p>

<pre><b>输入：</b>corridor = "SSPPSPS"
<b>输出：</b>3
<b>解释：</b>总共有 3 种不同分隔走廊的方案。
上图中黑色的竖线表示已经放置好的屏风。
上图每种方案中，每一段都恰好有 <strong>两个</strong>&nbsp;座位。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/12/04/2.png" style="width: 357px; height: 68px;"></p>

<pre><b>输入：</b>corridor = "PPSPSP"
<b>输出：</b>1
<b>解释：</b>只有 1 种分隔走廊的方案，就是不放置任何屏风。
放置任何的屏风都会导致有一段无法恰好有 2 个座位。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/12/12/3.png" style="width: 115px; height: 68px;"></p>

<pre><b>输入：</b>corridor = "S"
<b>输出：</b>0
<b>解释：</b>没有任何方案，因为总是有一段无法恰好有 2 个座位。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == corridor.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>corridor[i]</code>&nbsp;要么是&nbsp;<code>'S'</code>&nbsp;，要么是&nbsp;<code>'P'</code> 。</li>
</ul>


    
## 解题方法：遍历

从左往右遍历，每出现总计两个座位就要进行一次分隔，本次分隔方案数为两个座位中后一个座位与**下一个**座位之间的绿植数加一。（若后续再无座位，则不需要放置隔板）

总方案数就是每次放置隔板时的方案数之积。

额外注意，本题给定的答案中，若没有座位，则输出0而非“一个隔板都不放的这唯一一种方案”1。

### 具体做法

使用一个变量ing记录当前是否处在两个座位之后下一个座位之前的数绿植状态，使用一个变量now记录当前总计座位数或绿植数，遍历时候使用几个if-else就好了。

额外注意，可以使用一个变量atLeast2记录是否至少有两个座位，遍历过程中一旦出现累计两个座位则将该值赋值为true。

最终若不是在数绿植状态（不是刚好两个座位后）或一共也没有两个座位，返回0。

### 时空复杂度分析

+ 时间复杂度$O(len(corridor))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2025-12-14 17:37:56
 */
typedef long long ll;
const ll MOD = 1e9 + 7;
class Solution {
public:
    int numberOfWays(string& corridor) {
        ll ans = 1;
        int now = 0;
        bool ing = false;  // 正在处理两块座位之间的绿植
        bool atLeast2 = false;
        for (char c : corridor) {
            if (c == 'S') {
                if (ing) {
                    ans = ans * (now + 1) % MOD;
                    ing = false;
                    now = 1;
                } else {
                    now++;
                    if (now == 2) {
                        ing = true;
                        now = 0;
                        atLeast2 = true;
                    }
                }
            } else {  // 'P'
                if (ing) {
                    now++;
                }
            }
        }
        if (!ing || !atLeast2) {
            return 0;
        }
        return static_cast<int>(ans);
    }
};
```

* 执行用时分布8ms击败96.53%
* 消耗内存分布26.95MB击败100.00%

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/155916226)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/12/14/LeetCode%202147.%E5%88%86%E9%9A%94%E9%95%BF%E5%BB%8A%E7%9A%84%E6%96%B9%E6%A1%88%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
