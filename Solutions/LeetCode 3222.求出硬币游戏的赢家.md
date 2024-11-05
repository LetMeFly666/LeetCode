---
title: 3222.求出硬币游戏的赢家
date: 2024-11-05 09:57:57
tags: [题解, LeetCode, 简单, 数学, 博弈, 模拟]
---

# 【LetMeFly】3222.求出硬币游戏的赢家：伪博弈真思维O(1)

力扣题目链接：[https://leetcode.cn/problems/find-the-winning-player-in-coin-game/](https://leetcode.cn/problems/find-the-winning-player-in-coin-game/)

<p>给你两个 <strong>正</strong>&nbsp;整数&nbsp;<code>x</code>&nbsp;和&nbsp;<code>y</code>&nbsp;，分别表示价值为 75 和 10 的硬币的数目。</p>

<p>Alice 和 Bob 正在玩一个游戏。每一轮中，Alice&nbsp;先进行操作，Bob 后操作。每次操作中，玩家需要拿出价值 <b>总和</b>&nbsp;为 115 的硬币。如果一名玩家无法执行此操作，那么这名玩家 <strong>输掉</strong>&nbsp;游戏。</p>

<p>两名玩家都采取 <strong>最优</strong>&nbsp;策略，请你返回游戏的赢家。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>x = 2, y = 7</span></p>

<p><span class="example-io"><b>输出：</b>"Alice"</span></p>

<p><strong>解释：</strong></p>

<p>游戏一次操作后结束：</p>

<ul>
	<li>Alice 拿走 1 枚价值为 75 的硬币和 4 枚价值为 10 的硬币。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>x = 4, y = 11</span></p>

<p><span class="example-io"><b>输出：</b>"Bob"</span></p>

<p><strong>解释：</strong></p>

<p>游戏 2 次操作后结束：</p>

<ul>
	<li>Alice 拿走&nbsp;1 枚价值为 75 的硬币和 4 枚价值为 10 的硬币。</li>
	<li>Bob 拿走&nbsp;1 枚价值为 75 的硬币和 4 枚价值为 10 的硬币。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= x, y &lt;= 100</code></li>
</ul>


    
## 解题方法：计算

价值75和10的硬币组成价值115的硬币只有一种方法：1枚75的硬币和4枚10的硬币：

> 首先115就要求硬币里面一定有75，因为个位的5是没法用10组成的。
>
> 其次75只能有1枚，因为$75\times 2\gt 115$。
>
> 所以其实只有一种方案。

所以根本不是什么博弈，也没有什么“最优”策略。两个人只能按照单一的方式轮换拿硬币，如果有奇数份“75+4*10”则Alice获胜否则Bob获胜。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

BTW. 今日每日一题没有官方题解诶。

### AC代码

#### C++

```cpp
class Solution {
public:
    string losingPlayer(int x, int y) {
        return min(x, y / 4) % 2 ? "Alice" : "Bob";
    }
};
```

#### Python

```python
class Solution:
    def losingPlayer(self, x: int, y: int) -> str:
        return "Alice" if min(x, y // 4) % 2 else "Bob"
```

#### Java

```java
class Solution {
    public String losingPlayer(int x, int y) {
        return Math.min(x, y / 4) % 2 == 1 ? "Alice" : "Bob";
    }
}
```

#### Go

```go
package main

func losingPlayer(x int, y int) string {
    if min(x, y / 4) % 2 == 1 {
        return "Alice"
    }
    return "Bob"
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/11/05/LeetCode%203222.%E6%B1%82%E5%87%BA%E7%A1%AC%E5%B8%81%E6%B8%B8%E6%88%8F%E7%9A%84%E8%B5%A2%E5%AE%B6/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/143501415](https://letmefly.blog.csdn.net/article/details/143501415)
