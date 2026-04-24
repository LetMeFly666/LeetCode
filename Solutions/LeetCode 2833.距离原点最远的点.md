---
title: 2833.距离原点最远的点：计数
date: 2026-04-24 23:10:40
tags: [题解, LeetCode, 简单, 字符串, 计数]
categories: [题解, LeetCode]
---

# 【LetMeFly】2833.距离原点最远的点：计数

力扣题目链接：[https://leetcode.cn/problems/furthest-point-from-origin/](https://leetcode.cn/problems/furthest-point-from-origin/)

<p>给你一个长度为 <code>n</code> 的字符串 <code>moves</code> ，该字符串仅由字符 <code>'L'</code>、<code>'R'</code> 和 <code>'_'</code> 组成。字符串表示你在一条原点为 <code>0</code> 的数轴上的若干次移动。</p>

<p>你的初始位置就在原点（<code>0</code>），第 <code>i</code> 次移动过程中，你可以根据对应字符选择移动方向：</p>

<ul>
	<li>如果 <code>moves[i] = 'L'</code> 或 <code>moves[i] = '_'</code> ，可以选择向左移动一个单位距离</li>
	<li>如果 <code>moves[i] = 'R'</code> 或 <code>moves[i] = '_'</code> ，可以选择向右移动一个单位距离</li>
</ul>

<p>移动 <code>n</code> 次之后，请你找出可以到达的距离原点 <strong>最远</strong> 的点，并返回 <strong>从原点到这一点的距离</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>moves = "L_RL__R"
<strong>输出：</strong>3
<strong>解释：</strong>可以到达的距离原点 0 最远的点是 -3 ，移动的序列为 "LLRLLLR" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>moves = "_R__LL_"
<strong>输出：</strong>5
<strong>解释：</strong>可以到达的距离原点 0 最远的点是 -5 ，移动的序列为 "LRLLLLL" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>moves = "_______"
<strong>输出：</strong>7
<strong>解释：</strong>可以到达的距离原点 0 最远的点是 7 ，移动的序列为 "RRRRRRR" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= moves.length == n &lt;= 50</code></li>
	<li><code>moves</code> 仅由字符 <code>'L'</code>、<code>'R'</code> 和 <code>'_'</code> 组成</li>
</ul>


    
## 解题方法：计数

> 凡是`L`和`R`皆为固定，凡是其他皆自由。

因此两个变量统计：

1. `L`和`R`作用下距离起点的diff；
2. 有多少自由移动的步数。

如果diff大于0（在起点之右），则自由步数全部向右移动；否则全部向左移动就好了。

> 此外，也可以不判断diff是否大于零，直接返回$abs(diff)+flex$就好了。

+ 时间复杂度$O(len(moves))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-04-24 21:00:44
 */
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int flex = 0, diff = 0;
        for (char c : moves) {
            switch (c)
            {
            case 'L':
                diff--;
                break;
            case 'R':
                diff++;
                break;
            default:
                flex++;
            }
        }
        return diff > 0 ? diff + flex : flex - diff;
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-04-24 21:02:38
'''
class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        flex = diff = 0
        for c in moves:
            if c == 'L':
                diff -= 1
            elif c == 'R':
                diff += 1
            else:
                flex += 1
        return flex + diff if diff > 0 else flex - diff
```

#### Java

```java
/*
 * @LastEditTime: 2026-04-24 21:07:01
 */
// java14+
class Solution {
    public int furthestDistanceFromOrigin(String moves) {
        int flex = 0, diff = 0;
        for (int i = 0; i < moves.length(); i++) {
            switch (moves.charAt(i)) {
                case 'L' -> diff--;
                case 'R' -> diff++;
                default -> flex++;
            }
        }
        return diff > 0 ? flex + diff : flex - diff;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2026-04-24 21:25:20
 */
package main

func furthestDistanceFromOrigin(moves string) int {
    flex, diff := 0, 0
    for _, c := range moves {
        switch byte(c) {
        case 'L':
            diff--
        case 'R':
            diff++
        default:
            flex++
        }
    }
    if diff > 0 {
        return diff + flex
    }
    return flex - diff
}
```

#### Rust - abs

```rust
/*
 * @LastEditTime: 2026-04-24 23:09:59
 */
impl Solution {
    pub fn furthest_distance_from_origin(moves: String) -> i32 {
        let mut diff: i32 = 0;
        let mut flex: i32 = 0;
        for c in moves.chars() {
            match c {
                'L' => diff -= 1,
                'R' => diff += 1,
                _ => flex += 1,
            }
        }
        diff.abs() + flex
    }
}
```

#### Rust - if-else

```rust
/*
 * @LastEditTime: 2026-04-24 23:07:48
 */
impl Solution {
    pub fn furthest_distance_from_origin(moves: String) -> i32 {
        let mut diff = 0;
        let mut flex = 0;
        for c in moves.chars() {
            match c {
                'L' => diff -= 1,
                'R' => diff += 1,
                _ => flex += 1,
            }
        }
        if diff > 0 {
            diff + flex
        } else {
            flex - diff
        }
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/160483177)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/04/24/LeetCode%202833.%E8%B7%9D%E7%A6%BB%E5%8E%9F%E7%82%B9%E6%9C%80%E8%BF%9C%E7%9A%84%E7%82%B9/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
