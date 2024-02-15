---
title: 2335.装满杯子需要的最短总时长
date: 2023-02-11 10:01:25
tags: [题解, LeetCode, 简单, 贪心, 数组, 堆（优先队列）, 数学, 模拟]
---

# 【LetMeFly】2335.装满杯子需要的最短总时长

力扣题目链接：[https://leetcode.cn/problems/minimum-amount-of-time-to-fill-cups/](https://leetcode.cn/problems/minimum-amount-of-time-to-fill-cups/)

<p>现有一台饮水机，可以制备冷水、温水和热水。每秒钟，可以装满 <code>2</code> 杯 <strong>不同</strong> 类型的水或者 <code>1</code> 杯任意类型的水。</p>

<p>给你一个下标从 <strong>0</strong> 开始、长度为 <code>3</code> 的整数数组 <code>amount</code> ，其中 <code>amount[0]</code>、<code>amount[1]</code> 和 <code>amount[2]</code> 分别表示需要装满冷水、温水和热水的杯子数量。返回装满所有杯子所需的 <strong>最少</strong> 秒数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>amount = [1,4,2]
<strong>输出：</strong>4
<strong>解释：</strong>下面给出一种方案：
第 1 秒：装满一杯冷水和一杯温水。
第 2 秒：装满一杯温水和一杯热水。
第 3 秒：装满一杯温水和一杯热水。
第 4 秒：装满一杯温水。
可以证明最少需要 4 秒才能装满所有杯子。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>amount = [5,4,4]
<strong>输出：</strong>7
<strong>解释：</strong>下面给出一种方案：
第 1 秒：装满一杯冷水和一杯热水。
第 2 秒：装满一杯冷水和一杯温水。
第 3 秒：装满一杯冷水和一杯温水。
第 4 秒：装满一杯温水和一杯热水。
第 5 秒：装满一杯冷水和一杯热水。
第 6 秒：装满一杯冷水和一杯温水。
第 7 秒：装满一杯热水。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>amount = [5,0,0]
<strong>输出：</strong>5
<strong>解释：</strong>每秒装满一杯冷水。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>amount.length == 3</code></li>
	<li><code>0 &lt;= amount[i] &lt;= 100</code></li>
</ul>



## 写在前面：

这道题与[LeetCode 1753. 移除石子的最大得分](https://leetcode.cn/problems/maximum-score-from-removing-stones/)非常类似，也可以参考1753的题解：[https://blog.letmefly.xyz/2022/12/21/LeetCode 1753.移除石子的最大得分/](https://blog.letmefly.xyz/2022/12/21/LeetCode%201753.%E7%A7%BB%E9%99%A4%E7%9F%B3%E5%AD%90%E7%9A%84%E6%9C%80%E5%A4%A7%E5%BE%97%E5%88%86/)

## 方法一：贪心 + 模拟

每次在三个数里面取**最大的两个**，接满这两个中不为0的那个，直到这三个数全部为0。

## 方法二：贪心 + 数学

有没有在方法一的基础上，更快地计算出结果的方法呢？

不失一般性，我们对这三个数排个序，令$amount[0]\leq amount[1]\leq amount[2]$，并将排序后的这三个数分别记为$a$、$b$、$c$。

**1. 假设c足够大**

那么我们优先以这样的顺序接水：

1. 同时接满一杯$a$和$c$直到$a$接够
2. 同时接满一杯$b$和$c$直到$b$接够

因为$c$是足够大的，所以在接够$a$和接够$b$后，$c$还需要再接$c-a-b$杯。

因此总次数就等于$a+b+(c-a-b)=c$

相当于是每次都往$c$里面倒水，在$a$或$b$没接完的时候附带着给$a$和$b$也接了。

此时有$a+b<c$

**2. 假设c没有那么大**

也就是说$a+b\geq c$的时候，我们每次仍然从数量最大的两个数中选择，那么最终的结果要么是$0, 0, 0$，要么是$0, 0, 1$（或$0,0,1$的其他顺序）。这里的“最终”是指，在“只同时接一杯水”之前的空杯状态。

这是因为：

+ 首先，$c$需要量最多，并且$c$不足以消耗完$ab$后仍有剩余（$a+b\geq c$），那么就不可能出现$0, 0, 2$的情况
+ 其次，假设能出现$0, 1, 1$的情况，那么我们就能从两个$1$中各取一杯接满，这样就变成了$0, 0, 0$

综上，假如$a+b\geq c$，那么最终至多剩下1个空杯子，也就是说几乎全部是“同时接两杯水”，至多一次接水操作是“只接了一杯水”，因此总接水次数是$\lceil \frac{a+b+c}{2} \rceil$

**1和2总结**

首先对三种杯子排序使得$a<b<c$

+ 若$a+b<c$，则需要接水$c$次
+ 否则需要接水$\lceil\frac{a+b+c}{2}\rceil$

+ 时间复杂度$O(1)$，三个数的排序时空消耗可以忽略不计
+ 空间复杂度$O(1)$

### AC代码

**备注：** $\lceil\frac{a+b+c}{2}\rceil=\lfloor\frac{a+b+c+1}{2}\rfloor$

#### C++

```cpp
class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(), amount.end());
        if (amount[0] + amount[1] <= amount[2])
            return amount[2];
        return (amount[0] + amount[1] + amount[2] + 1) / 2;
    }
};
```

#### Python

```python
class Solution:
    def fillCups(self, amount: List[int]) -> int:
        amount.sort()
        if amount[0] + amount[1] <= amount[2]:
            return amount[2]
        return (amount[0] + amount[1] + amount[2] + 1) // 2
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/02/11/LeetCode%202335.%E8%A3%85%E6%BB%A1%E6%9D%AF%E5%AD%90%E9%9C%80%E8%A6%81%E7%9A%84%E6%9C%80%E7%9F%AD%E6%80%BB%E6%97%B6%E9%95%BF/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128980819](https://letmefly.blog.csdn.net/article/details/128980819)
