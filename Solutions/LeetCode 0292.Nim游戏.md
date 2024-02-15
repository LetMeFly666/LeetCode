---
title: 292.Nim 游戏
date: 2024-02-04 13:38:44
tags: [题解, LeetCode, 简单, 脑筋急转弯, 数学, 博弈]
---

# 【LetMeFly】292.Nim 游戏：脑筋急转弯

力扣题目链接：[https://leetcode.cn/problems/nim-game/](https://leetcode.cn/problems/nim-game/)

<p>你和你的朋友，两个人一起玩&nbsp;<a href="https://baike.baidu.com/item/Nim游戏/6737105" target="_blank">Nim 游戏</a>：</p>

<ul>
	<li>桌子上有一堆石头。</li>
	<li>你们轮流进行自己的回合，&nbsp;<strong>你作为先手&nbsp;</strong>。</li>
	<li>每一回合，轮到的人拿掉&nbsp;1 - 3 块石头。</li>
	<li>拿掉最后一块石头的人就是获胜者。</li>
</ul>

<p>假设你们每一步都是最优解。请编写一个函数，来判断你是否可以在给定石头数量为 <code>n</code> 的情况下赢得游戏。如果可以赢，返回 <code>true</code>；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong><code>n = 4</code>
<strong>输出：</strong>false 
<strong>解释：</strong>以下是可能的结果:
1. 移除1颗石头。你的朋友移走了3块石头，包括最后一块。你的朋友赢了。
2. 移除2个石子。你的朋友移走2块石头，包括最后一块。你的朋友赢了。
3.你移走3颗石子。你的朋友移走了最后一块石头。你的朋友赢了。
在所有结果中，你的朋友是赢家。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>true
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


    
## 方法一：脑筋急转弯（看能否整除4）

这种题可以模拟几个试试。当轮到我时：

+ 1、2、3必胜
+ 4必输（不论拿多少个剩下的必定是1、2、3，下一个人必胜）
+ 5、6、7必胜（5、6、7都有办法在一次拿石子后剩下4个，下一个人必输）
+ 8必输（不论拿多少个剩下的必定是5、6、7，下一个人必胜）
+ ...

相信聪明的你一定已经发现规律了。轮到自己时，$4$的倍数必输，否则必胜。

由于自己是先手，就看初始数量是否为$4$的倍数，若是则必输，否则就一次操作将剩下的石子数量变成$4$的倍数。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4;
    }
};
```

#### Python

```python
class Solution:
    def canWinNim(self, n: int) -> bool:
        return n % 4 != 0  # 注意这里不能像C一样只return一个n%4
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/02/04/LeetCode%200292.Nim%E6%B8%B8%E6%88%8F/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136024724](https://letmefly.blog.csdn.net/article/details/136024724)
