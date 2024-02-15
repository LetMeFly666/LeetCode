---
title: 1686.石子游戏 VI
date: 2024-02-02 17:29:47
tags: [题解, LeetCode, 中等, 贪心, 数组, 数学, 博弈, 排序, 堆（优先队列）, 思维, 设计]
---

# 【LetMeFly】1686.石子游戏 VI：贪心（排序）——思维题（换个角度秒懂）

力扣题目链接：[https://leetcode.cn/problems/stone-game-vi/](https://leetcode.cn/problems/stone-game-vi/)

<p>Alice 和 Bob 轮流玩一个游戏，Alice 先手。</p>

<p>一堆石子里总共有 <code>n</code> 个石子，轮到某个玩家时，他可以 <strong>移出</strong> 一个石子并得到这个石子的价值。Alice 和 Bob 对石子价值有 <strong>不一样的的评判标准</strong> 。双方都知道对方的评判标准。</p>

<p>给你两个长度为 <code>n</code> 的整数数组 <code>aliceValues</code> 和 <code>bobValues</code> 。<code>aliceValues[i]</code> 和 <code>bobValues[i]</code> 分别表示 Alice 和 Bob 认为第 <code>i</code> 个石子的价值。</p>

<p>所有石子都被取完后，得分较高的人为胜者。如果两个玩家得分相同，那么为平局。两位玩家都会采用 <b>最优策略</b> 进行游戏。</p>

<p>请你推断游戏的结果，用如下的方式表示：</p>

<ul>
	<li>如果 Alice 赢，返回 <code>1</code> 。</li>
	<li>如果 Bob 赢，返回 <code>-1</code> 。</li>
	<li>如果游戏平局，返回 <code>0</code> 。</li>
</ul>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>aliceValues = [1,3], bobValues = [2,1]
<b>输出：</b>1
<strong>解释：</strong>
如果 Alice 拿石子 1 （下标从 0开始），那么 Alice 可以得到 3 分。
Bob 只能选择石子 0 ，得到 2 分。
Alice 获胜。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>aliceValues = [1,2], bobValues = [3,1]
<b>输出：</b>0
<strong>解释：</strong>
Alice 拿石子 0 ， Bob 拿石子 1 ，他们得分都为 1 分。
打平。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>aliceValues = [2,4,3], bobValues = [1,6,7]
<b>输出：</b>-1
<strong>解释：</strong>
不管 Alice 怎么操作，Bob 都可以得到比 Alice 更高的得分。
比方说，Alice 拿石子 1 ，Bob 拿石子 2 ， Alice 拿石子 0 ，Alice 会得到 6 分而 Bob 得分为 7 分。
Bob 会获胜。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == aliceValues.length == bobValues.length</code></li>
	<li><code>1 <= n <= 10<sup>5</sup></code></li>
	<li><code>1 <= aliceValues[i], bobValues[i] <= 100</code></li>
</ul>


    
## 方法一：贪心（排序）——思维题（换个角度秒懂）

### 思路

我们换个角度思考问题，先让Bob拿走全部的石头，再让Alice从Bob的石头里夺走$\lceil\frac{n}2\rceil$个石头。

现在Bob拿走了所有的石头，Alice要从中夺走哪些呢？

> 我们用变量```a_b```代表Alice的得分减去Bob的得分 所得的结果（$Alice - Bob$）
>
> 假设夺走石头$i$，那么Alice将会获得$a[i]$分，Bob损失$b[i]$分，$Alice - Bob$的变化为$a[i] + b[i]$。
>
> Alice要赢，因此她要让```a_b```尽可能大，因此**她要优先夺走a[i]+b[i]最大的石头**。

### 方法

变量```a_b```的初始值为$-sum(bobValues)$，将$a+b$数组按从大到小的顺序排序，从第一个数开始每间隔一个取一次，将$(a+b)_i$累加到```a_b```中。

看最终```a_b```的值与```0```的大小。（大于零则Alice胜，等于零则平局，小于则Bob胜）

+ 时间复杂度$O(n\log n)$。其中$n=len(aliceValues)$
+ 空间复杂度$O(\log n)$或$O(n)$。这是因为我们可以将$a[i]+b[i]$的结果放到数组$a$中，这样就不需要再额外开辟空间了。但是这样会改变数组$a$的值，若不允许修改原始数组则需要额外开辟大小为$n$的空间

### 问答

**问** ：为什么Alice要间隔一个取一次？

**答** ：因为**实际上**Alice和Bob是**依次**进行的，Bob不傻，Bob也会取剩下所有石头中$a[i]+b[i]$最大的。

### AC代码

#### C++

```cpp
class Solution {  // AC,100.00%,80.77%
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < a.size(); i++) {
            a[i] += b[i];
        }
        sort(a.begin(), a.end(), greater<int>());
        int a_b = -accumulate(b.begin(), b.end(), 0);
        for (int i = 0; i < a.size(); i += 2) {
            a_b += a[i];
        }
        return a_b > 0 ? 1 : a_b ? -1 : 0;
    }
};
```

#### Python

```python
# from typing import List

class Solution:  # AC,71.26%,71.26%
    def stoneGameVI(self, a: List[int], b: List[int]) -> int:
        for i in range(len(a)):
            a[i] += b[i]
        a.sort(key=lambda v: -v)
        a_b = -sum(b)
        for i in range(0, len(a), 2):
            a_b += a[i]
        return 1 if a_b > 0 else -1 if a_b else 0

```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/02/02/LeetCode%201686.%E7%9F%B3%E5%AD%90%E6%B8%B8%E6%88%8FVI/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135998504](https://letmefly.blog.csdn.net/article/details/135998504)
