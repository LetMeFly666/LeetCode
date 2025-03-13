---
title: 1033.移动石子直到连续
date: 2023-04-30 10:15:41
tags: [题解, LeetCode, 中等, 脑筋急转弯, 数学, 思维]
categories: [题解, LeetCode]
---

# 【LetMeFly】1033.移动石子直到连续

力扣题目链接：[https://leetcode.cn/problems/moving-stones-until-consecutive/](https://leetcode.cn/problems/moving-stones-until-consecutive/)

<p>三枚石子放置在数轴上，位置分别为 <code>a</code>，<code>b</code>，<code>c</code>。</p>

<p>每一回合，你可以从两端之一拿起一枚石子（位置最大或最小），并将其放入两端之间的任一空闲位置。形式上，假设这三枚石子当前分别位于位置 <code>x, y, z</code> 且 <code>x < y < z</code>。那么就可以从位置 <code>x</code> 或者是位置 <code>z</code> 拿起一枚石子，并将该石子移动到某一整数位置 <code>k</code> 处，其中 <code>x < k < z</code> 且 <code>k != y</code>。</p>

<p>当你无法进行任何移动时，即，这些石子的位置连续时，游戏结束。</p>

<p>要使游戏结束，你可以执行的最小和最大移动次数分别是多少？ 以长度为 2 的数组形式返回答案：<code>answer = [minimum_moves, maximum_moves]</code></p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>a = 1, b = 2, c = 5
<strong>输出：</strong>[1, 2]
<strong>解释：</strong>将石子从 5 移动到 4 再移动到 3，或者我们可以直接将石子移动到 3。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>a = 4, b = 3, c = 2
<strong>输出：</strong>[0, 0]
<strong>解释：</strong>我们无法进行任何移动。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 <= a <= 100</code></li>
	<li><code>1 <= b <= 100</code></li>
	<li><code>1 <= c <= 100</code></li>
	<li><code>a != b, b != c, c != a</code></li>
</ol>


    
## 方法一：思维

不失一般性，我们先对a、b、c排个序，使得$a<b<c$

接着，我们判断最小距离：

+ 如果**a、b、c相邻**，那么移动所需最小距离就为0
+ 否则如果**a、b相邻或b、c相邻**，我们只需要将不相邻的那一个移动过来即可；如果**a、b间隔为1或b、c间隔为1**，我们只需要将另外一个移动到这两个中间的间隔处。总之，移动最小距离为1。
+ **否则**，我们移动两次，可以使a、b、c相邻

接着，我们计算最大距离：

在a、b、c不全部相邻时：

+ 若a、b不相邻，那么我们就把a往右移动一步
+ 否则，就把b往左移动一步

总之，在没有把a、b、c移动到一起时，我们有办法每次只移动一步。因此最大总移动步数为$c-a+2$

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        // sort(a, b, c)
        if (a > b) {
            swap(a, b);
        }
        if (b > c) {
            swap(b, c);
        }
        if (a > b) {
            swap(a, b);
        }
        // calculate
        if (a + 1 == b && b + 1 == c) {  // 直接相连
            return {0, 0};
        }
        if (a + 1 == b || b + 1 == c || a + 2 == b || b + 2 == c) {  // 有两个相连 或 有两个间隔为2
            return {1, c - a - 2};
        }
        else {  // 三个各不相连
            return {2, c - a - 2};
        }
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
        a, b, c = sorted([a, b, c])
        if a + 1 == b and b + 1 == c:
            return [0, 0]
        elif a + 1 == b or b + 1 == c or a + 2 == b or b + 2 == c:
            return [1, c - a - 2]
        else:
            return [2, c - a - 2]
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/04/30/LeetCode%201033.%E7%A7%BB%E5%8A%A8%E7%9F%B3%E5%AD%90%E7%9B%B4%E5%88%B0%E8%BF%9E%E7%BB%AD/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130446773](https://letmefly.blog.csdn.net/article/details/130446773)
