---
title: 877.石子游戏：脑筋急转弯（两句话道破天机）
date: 2026-08-02 21:34:36
tags: [题解, LeetCode, 中等, 数组, 数学, 动态规划, 博弈, 脑筋急转弯]
categories: [题解, LeetCode]
---

# 【LetMeFly】877.石子游戏：脑筋急转弯（两句话道破天机）

力扣题目链接：[https://leetcode.cn/problems/stone-game/](https://leetcode.cn/problems/stone-game/)

<p>Alice 和 Bob 用几堆石子在做游戏。一共有偶数堆石子，<strong>排成一行</strong>；每堆都有 <strong>正</strong> 整数颗石子，数目为 <code>piles[i]</code>&nbsp;。</p>

<p>游戏以谁手中的石子最多来决出胜负。石子的 <strong>总数</strong> 是 <strong>奇数</strong> ，所以没有平局。</p>

<p>Alice 和 Bob 轮流进行，<strong>Alice 先开始</strong> 。 每回合，玩家从行的 <strong>开始</strong> 或 <strong>结束</strong> 处取走整堆石头。 这种情况一直持续到没有更多的石子堆为止，此时手中 <strong>石子最多</strong> 的玩家 <strong>获胜</strong> 。</p>

<p>假设 Alice 和 Bob 都发挥出最佳水平，当 Alice 赢得比赛时返回&nbsp;<code>true</code>&nbsp;，当 Bob 赢得比赛时返回&nbsp;<code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>piles = [5,3,4,5]
<strong>输出：</strong>true
<strong>解释：</strong>
Alice 先开始，只能拿前 5 颗或后 5 颗石子 。
假设他取了前 5 颗，这一行就变成了 [3,4,5] 。
如果 Bob 拿走前 3 颗，那么剩下的是 [4,5]，Alice 拿走后 5 颗赢得 10 分。
如果 Bob 拿走后 5 颗，那么剩下的是 [3,4]，Alice 拿走后 4 颗赢得 9 分。
这表明，取前 5 颗石子对 Alice 来说是一个胜利的举动，所以返回 true 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>piles = [3,7,2,3]
<strong>输出：</strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= piles.length &lt;= 500</code></li>
	<li><code>piles.length</code> 是 <strong>偶数</strong></li>
	<li><code>1 &lt;= piles[i] &lt;= 500</code></li>
	<li><code>sum(piles[i])</code>&nbsp;是 <strong>奇数</strong></li>
</ul>

不错的题！

## 解题方法：脑筋急转弯

石头分成两类来看，一类是下标为奇数的石头$石_奇$一类是下标为偶数的石头$石_偶$。石头总和为奇数，说明$sum_奇\neq sum_偶$。

Alice具有决定权，如果$sum_奇\gt sum_偶$，她保证自己一直拿$石_奇$好了：拿一个$石_奇$剩下的石头两边都是$石_偶$，Bob只能拿$石_偶$；Alice再次拿$石_奇$，直至游戏结束，Alice就拿下了所有$石_奇$，赢了。and vice versa.

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-08-02 21:30:48
 */
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-08-02 21:31:07
'''
from typing import List

class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        return True
```

#### Java

```java
/*
 * @LastEditTime: 2026-08-02 21:31:03
 */
class Solution {
    public boolean stoneGame(int[] piles) {
        return true;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2026-08-02 21:30:55
 */
package main

func stoneGame(piles []int) bool {
    return true
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-08-02 21:31:11
 */
impl Solution {
    pub fn stone_game(piles: Vec<i32>) -> bool {
        true
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/163420792)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/08/02/LeetCode%200877.%E7%9F%B3%E5%AD%90%E6%B8%B8%E6%88%8F/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)

$石_奇\neq石_矶$
