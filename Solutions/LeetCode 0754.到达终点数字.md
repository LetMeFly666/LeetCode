---
title: 754.到达终点数字
date: 2022-11-04 10:05:03
tags: [题解, LeetCode, 中等, 数学, 二分查找]
---

# 【LetMeFly】754.到达终点数字

力扣题目链接：[https://leetcode.cn/problems/reach-a-number/](https://leetcode.cn/problems/reach-a-number/)

<p>在一根无限长的数轴上，你站在<code>0</code>的位置。终点在<code>target</code>的位置。</p>

<p>你可以做一些数量的移动 <code>numMoves</code> :</p>

<ul>
	<li>每次你可以选择向左或向右移动。</li>
	<li>第 <code>i</code>&nbsp;次移动（从 &nbsp;<code>i == 1</code>&nbsp;开始，到&nbsp;<code>i == numMoves</code> ），在选择的方向上走 <code>i</code>&nbsp;步。</li>
</ul>

<p>给定整数&nbsp;<code>target</code> ，返回 <em>到达目标所需的 <strong>最小&nbsp;</strong>移动次数(即最小 <code>numMoves</code> )&nbsp;</em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> target = 2
<strong>输出:</strong> 3
<strong>解释:</strong>
第一次移动，从 0 到 1 。
第二次移动，从 1 到 -1 。
第三次移动，从 -1 到 2 。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> target = 3
<strong>输出:</strong> 2
<strong>解释:</strong>
第一次移动，从 0 到 1 。
第二次移动，从 1 到 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>-10<sup>9</sup>&nbsp;&lt;= target &lt;= 10<sup>9</sup></code></li>
	<li><code>target != 0</code></li>
</ul>


    
## 方法一：枚举

如果$target<0$，那么我们就对$target$取个绝对值，因为走到$-100$和$100$所需的步数是一样的

这样，我们就可以**先头也不回地往右走**，直到恰好走到$target$或超过$target$一两步为止

假设我们走了$n$步，那么总距离就是$result = \frac{n\times(n+1)}{2}$

我们超过了$target$共$result-target$，因此在这$n$步中，我们希望有其中某步是往左的。

假设第$i$步往左，那么我们$n$步的总距离就是$result-2\times i$

也就是说```往左一步```比```一直往右```少走的距离一定是偶数。

因此，我们只需要在$result\geq target$且$result - target$不为偶数时，不断往右走

好了，现在我们超过$target$共$result-target$，怎么办呢？我们将往右走的过程中，第$\frac{result-target}{2}$步改成向左走不就行了么？

问题解决。

有的同学可能不相信，那咱就举例说明一下。

假设目标距离是$2$：

1. $1 = 1 < 2$
2. $1 + 2 = 3 > 2$，但$(1+2)-2=1$是奇数
3. $1+2+3=6>2$且$(1+2+3)-2=4$是偶数

因此，我们只需要将第$\frac{4}{2}=2$步修改为向左走，总行走距离就变成了$1-2+3=2$。

这得益于几个条件：

1. 将target取绝对值后，模板在原点或原点的右边，我们要尽可能地多往右走
2. 如果一直往右走不能恰好到达$target$，那么就一定要往左走“数次”
3. “往左一次”只能比“全部往右”少走**偶数**的距离，这就导致了“把其中某**一**步”改为往左不一定能正好走到$target$
4. 假设这次超过$target$奇数的距离，那么再往前走一步，一定会超过$target$偶数的距离（这是因为我们是奇偶交替走的，总距离也是奇偶交替的），因此超过$target$后最多再往前走一步，就能“将之前某一步改为向左以恰好达到target”（$\frac{result - target}{2}$一定不大于$n$）

总之，头也不回地往右走，直到超过$target$偶数的距离（或恰好位于$target$），修改历史某步为向左（不消耗步数），返回当前步数即可

+ 时间复杂度$O(\sqrt{|target|})$（注意这里是“根号下target的绝对值”，目前力扣新版UI中无法正常显示```\sqrt```）
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int reachNumber(int target) {
        unsigned to = abs(target);
        unsigned n = 0;
        while (true) {
            unsigned result = n * (n + 1) / 2;
            if (result >= to && (result - to) % 2 == 0)
                return n;
            n++;
        }
    }
};
```

## 方法二：基于方法一的小优化

方法一中我们从$1$开始“枚举”了步数$n$找到了$\frac{n\times(n+1)}{2}\geq target$且$\frac{n\times(n+1)}{2}- target$为偶数的**最小**$n$

这导致时间复杂度为$\log target$

但是，$\frac{n\times (n+1)}{2}$恰好略大于$target$，这就说明$n$约等于$\sqrt{target\times2}$

因此我们从$\sqrt{target\times2} - 2$开始枚举$n$就好了，大约不出$5$次就能找到答案。

+ 时间复杂度$O(1)$（CPU有专门的计算平方根的指令，```aqrt()```的复杂度可以视作是$O(1)$）
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int reachNumber(int target) {
        unsigned to = abs(target);
        unsigned simN = max((int)sqrt(to * 2) - 2, 0);
        while (true) {
            unsigned result = simN * (simN + 1) / 2;
            if (result >= to && (result - to) % 2 == 0)
                return simN;
            simN++;
        }
    }
};
```

执行结果确实快了点

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/11/04/LeetCode%200754.%E5%88%B0%E8%BE%BE%E7%BB%88%E7%82%B9%E6%95%B0%E5%AD%97/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127684453](https://letmefly.blog.csdn.net/article/details/127684453)
