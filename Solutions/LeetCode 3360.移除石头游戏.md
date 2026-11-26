---
title: 3360.移除石头游戏：while一下（不算了）
date: 2026-11-26 08:06:28
tags: [题解, LeetCode, 简单, 数学, 模拟, 博弈]
categories: [题解, LeetCode]
---

# 【LetMeFly】3360.移除石头游戏：while一下（不算了）

力扣题目链接：[https://leetcode.cn/problems/stone-removal-game/](https://leetcode.cn/problems/stone-removal-game/)

<p>Alice 和 Bob 在玩一个游戏，他们俩轮流从一堆石头中移除石头，Alice 先进行操作。</p>

<ul>
	<li>Alice 在第一次操作中移除 <strong>恰好</strong>&nbsp;10 个石头。</li>
	<li>接下来的每次操作中，每位玩家移除的石头数 <strong>恰好</strong>&nbsp;为另一位玩家上一次操作的石头数减 1 。</li>
</ul>

<p>第一位没法进行操作的玩家输掉这个游戏。</p>

<p>给你一个正整数&nbsp;<code>n</code>&nbsp;表示一开始石头的数目，如果 Alice 赢下这个游戏，请你返回&nbsp;<code>true</code>&nbsp;，否则返回 <code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>n = 12</span></p>

<p><span class="example-io"><b>输出：</b>true</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>Alice 第一次操作中移除 10 个石头，剩下 2 个石头给 Bob 。</li>
	<li>Bob 无法移除 9 个石头，所以 Alice 赢下游戏。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>n = 1</span></p>

<p><span class="example-io"><b>输出：</b>false</span></p>

<p><b>解释：</b></p>

<ul>
	<li>Alice 无法移除 10 个石头，所以 Alice 输掉游戏。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 50</code></li>
</ul>


    
## 解题方法：模拟

默认状态（$state$）是Alice输（如果Alice不做点什么的话会输），她需要（$need$）移除10个石头，移除完：

+ 输赢状态暂时改变
+ 石头总数减少
+ 下次需要移除的石头数量减少1

当石头总数不足一次移除时，输赢状态已成定局，返回之。

+ 时间复杂度$O(1)$，$10+9+8+7+6+5+4+3+2+1=52$，所以最多循环$7$次
+ 空间复杂度$O(1)$

当然也可以直接$O(1)$算出总共能移除几轮，但是这个数据量说实话不是很有必要。

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-11-26 07:55:55
 */
class Solution {
public:
    bool canAliceWin(int n) {
        bool state = false;
        int need = 10;
        while (true) {
            if (n < need) {
                return state;
            }
            n -= need--;
            state = !state;
        }
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-11-26 08:04:25
'''
class Solution:
    def canAliceWin(self, n: int) -> bool:
        state, need = False, 10
        while n >= need:
            n -= need
            need -= 1
            state = not state
        return state
```

#### Java

```java
/*
 * @LastEditTime: 2026-11-26 08:03:30
 */
class Solution {
    public boolean canAliceWin(int n) {
        boolean state = false;
        int need = 10;
        while (n >= need) {
            n -= need--;
            state = !state;
        }
        return state;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2026-11-26 08:01:55
 */
package main

func canAliceWin(n int) (state bool) {
    need := 10
    for n >= need {
        n -= need
        need--
        state = !state
    }
    return
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-11-26 08:05:26
 */
impl Solution {
    pub fn can_alice_win(mut n: i32) -> bool {
        let mut state = false;
        let mut need = 10;
        while n >= need {
            n -= need;
            need -= 1;
            state = !state;
        }
        state
    }
}
```

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/171406645)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/11/26/LeetCode%203360.%E7%A7%BB%E9%99%A4%E7%9F%B3%E5%A4%B4%E6%B8%B8%E6%88%8F/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
