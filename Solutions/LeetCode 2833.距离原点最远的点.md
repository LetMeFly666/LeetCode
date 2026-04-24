---
title: 2833.距离原点最远的点
date: 2026-04-24 23:42:13
tags: [题解, LeetCode, 简单, 字符串, 计数]
categories: [题解, LeetCode]
---

# 【LetMeFly】2833.距离原点最远的点

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


    
## 解题方法：xx

11111

+ 时间复杂度$O(N^2)$
+ 空间复杂度$O(N\log N)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-04-24 23:41:54
 */
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        可以
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-04-24 23:41:39
'''
class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        不错
```

#### Java

```java
/*
 * @LastEditTime: 2026-04-24 23:42:02
 */
class Solution {
    public int furthestDistanceFromOrigin(String moves) {
        good
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2026-04-24 23:41:56
 */
package main

func furthestDistanceFromOrigin(moves string) int {
    同样没问题
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-04-24 23:42:10
 */
impl Solution {
    pub fn furthest_distance_from_origin(moves: String) -> i32 {
        hao
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/--------------------------)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/04/24/LeetCode%202833.%E8%B7%9D%E7%A6%BB%E5%8E%9F%E7%82%B9%E6%9C%80%E8%BF%9C%E7%9A%84%E7%82%B9/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
