---
title: 1753.移除石子的最大得分
date: 2022-12-21 22:49:26
tags: [题解, LeetCode, 中等, 贪心, 数学, 堆（优先队列）, 模拟]
---

# 【LetMeFly】1753.移除石子的最大得分

力扣题目链接：[https://leetcode.cn/problems/maximum-score-from-removing-stones/](https://leetcode.cn/problems/maximum-score-from-removing-stones/)

<p>你正在玩一个单人游戏，面前放置着大小分别为 <code>a</code>​​​​​​、<code>b</code> 和 <code>c</code>​​​​​​ 的 <strong>三堆</strong> 石子。</p>

<p>每回合你都要从两个 <strong>不同的非空堆</strong> 中取出一颗石子，并在得分上加 <code>1</code> 分。当存在 <strong>两个或更多</strong> 的空堆时，游戏停止。</p>

<p>给你三个整数 <code>a</code> 、<code>b</code> 和 <code>c</code> ，返回可以得到的 <strong>最大分数</strong> 。</p>
 

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>a = 2, b = 4, c = 6
<strong>输出：</strong>6
<strong>解释：</strong>石子起始状态是 (2, 4, 6) ，最优的一组操作是：
- 从第一和第三堆取，石子状态现在是 (1, 4, 5)
- 从第一和第三堆取，石子状态现在是 (0, 4, 4)
- 从第二和第三堆取，石子状态现在是 (0, 3, 3)
- 从第二和第三堆取，石子状态现在是 (0, 2, 2)
- 从第二和第三堆取，石子状态现在是 (0, 1, 1)
- 从第二和第三堆取，石子状态现在是 (0, 0, 0)
总分：6 分 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>a = 4, b = 4, c = 6
<strong>输出：</strong>7
<strong>解释：</strong>石子起始状态是 (4, 4, 6) ，最优的一组操作是：
- 从第一和第二堆取，石子状态现在是 (3, 3, 6)
- 从第一和第三堆取，石子状态现在是 (2, 3, 5)
- 从第一和第三堆取，石子状态现在是 (1, 3, 4)
- 从第一和第三堆取，石子状态现在是 (0, 3, 3)
- 从第二和第三堆取，石子状态现在是 (0, 2, 2)
- 从第二和第三堆取，石子状态现在是 (0, 1, 1)
- 从第二和第三堆取，石子状态现在是 (0, 0, 0)
总分：7 分 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>a = 1, b = 8, c = 8
<strong>输出：</strong>8
<strong>解释：</strong>最优的一组操作是连续从第二和第三堆取 8 回合，直到将它们取空。
注意，由于第二和第三堆已经空了，游戏结束，不能继续从第一堆中取石子。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= a, b, c <= 10<sup>5</sup></code></li>
</ul>


    
## 方法一：贪心

贪心的思路较容易想到，就是在游戏没有结束的时候，每次选取石头数量最多的两个石堆进行移除操作。

数据量是$10^5$级别，可以很快计算出结果。

## 方法二：贪心 + 数学

有没有在方法一的基础上，更快地计算出结果的方法呢？

不失一般性，我们将石头堆排个序，令$a\leq b\leq c$

**1. 假设c足够大**

那么我们将在消耗完$a$和消耗完$b$后，$c$堆剩余$c-a-b$颗石头。尽管我们每次操作都从$c$中移除石头，但是$c$的石头数量太多了，到最后也没用完。因此我们得到了最大分数$a+b$

此时有$a+b<c$

**2. 假设c没有那么大**

也就是说$a+b\geq c$的时候，我们每次仍然从数量最大的两个石头堆中取石头，那么最终的结果要么是$0, 0, 0$，要么是$0, 0, 1$（或$001$的其他顺序）。

这是因为：

+ 首先，$c$石头最多（排序后），并且$c$不足以消耗完$ab$后仍有剩余（$a+b\geq c$），那么就不可能出现$0, 0, 100$的情况
+ 其次，假设能出现$0, 1, 1$的情况，那么我们就能从两个$1$中各取一石，这样就变成了$0, 0, 0$

综上，假如$a+b\geq c$，那么最终至多剩下一颗石头，也就是说消耗了$a+b+c$或$a+b+c-1$颗石头，得到的分数为$\lfloor\frac{a+b+c}{2}\rfloor$

**1和2总结**

首先对三个石头堆排序使得$a<b<c$

+ 若$a+b<c$，则得分$a+b$
+ 否则得分$\lfloor\frac{a+b+c}{2}\rfloor$

+ 时间复杂度$O(1)$，三个数的排序时空消耗可以忽略不计
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int v[3] = {a, b, c};
        sort(v, v + 3);
        if (v[0] + v[1] < v[2])
            return v[0] + v[1];
        return (v[0] + v[1] + v[2]) / 2;
    }
};
```

## 相似题目推荐

[LeetCode 2335.装满杯子需要的最短总时长](https://leetcode.cn/problems/minimum-amount-of-time-to-fill-cups)

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/12/21/LeetCode%201753.%E7%A7%BB%E9%99%A4%E7%9F%B3%E5%AD%90%E7%9A%84%E6%9C%80%E5%A4%A7%E5%BE%97%E5%88%86/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128403163](https://letmefly.blog.csdn.net/article/details/128403163)
