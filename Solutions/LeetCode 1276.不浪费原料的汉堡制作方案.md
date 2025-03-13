---
title: 1276.不浪费原料的汉堡制作方案
date: 2023-12-25 12:13:13
tags: [题解, LeetCode, 中等, 数学]
categories: [题解, LeetCode]
---

# 【LetMeFly】1276.不浪费原料的汉堡制作方案：鸡兔同笼解方程

力扣题目链接：[https://leetcode.cn/problems/number-of-burgers-with-no-waste-of-ingredients/](https://leetcode.cn/problems/number-of-burgers-with-no-waste-of-ingredients/)

<p>圣诞活动预热开始啦，汉堡店推出了全新的汉堡套餐。为了避免浪费原料，请你帮他们制定合适的制作计划。</p>

<p>给你两个整数&nbsp;<code>tomatoSlices</code>&nbsp;和&nbsp;<code>cheeseSlices</code>，分别表示番茄片和奶酪片的数目。不同汉堡的原料搭配如下：</p>

<ul>
	<li><strong>巨无霸汉堡：</strong>4 片番茄和 1 片奶酪</li>
	<li><strong>小皇堡：</strong>2 片番茄和&nbsp;1 片奶酪</li>
</ul>

<p>请你以&nbsp;<code>[total_jumbo, total_small]</code>（[巨无霸汉堡总数，小皇堡总数]）的格式返回恰当的制作方案，使得剩下的番茄片&nbsp;<code>tomatoSlices</code>&nbsp;和奶酪片&nbsp;<code>cheeseSlices</code>&nbsp;的数量都是&nbsp;<code>0</code>。</p>

<p>如果无法使剩下的番茄片&nbsp;<code>tomatoSlices</code>&nbsp;和奶酪片&nbsp;<code>cheeseSlices</code>&nbsp;的数量为&nbsp;<code>0</code>，就请返回&nbsp;<code>[]</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>tomatoSlices = 16, cheeseSlices = 7
<strong>输出：</strong>[1,6]
<strong>解释：</strong>制作 1 个巨无霸汉堡和 6 个小皇堡需要 4*1 + 2*6 = 16 片番茄和 1 + 6 = 7 片奶酪。不会剩下原料。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>tomatoSlices = 17, cheeseSlices = 4
<strong>输出：</strong>[]
<strong>解释：</strong>只制作小皇堡和巨无霸汉堡无法用光全部原料。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>tomatoSlices = 4, cheeseSlices = 17
<strong>输出：</strong>[]
<strong>解释：</strong>制作 1 个巨无霸汉堡会剩下 16 片奶酪，制作 2 个小皇堡会剩下 15 片奶酪。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>tomatoSlices = 0, cheeseSlices = 0
<strong>输出：</strong>[0,0]
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>tomatoSlices = 2, cheeseSlices = 1
<strong>输出：</strong>[0,1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= tomatoSlices &lt;= 10^7</code></li>
	<li><code>0 &lt;= cheeseSlices &lt;= 10^7</code></li>
</ul>


    
## 方法一：鸡兔同笼解方程

这道题可以概况为：

> 一只鸡1头2腿，一只兔1头4腿。共有c头t腿，问鸡兔各几何？

解法很简单，一个二元一次方程：

> 设x鸡y兔，则有：
>
> + $4x + 2y = t$, 
> + $x + y = c$
>
> 于是有：$2x + 2y = 2c$
>
> 所以：$x = 0.5t - c$, $y = c - x = 2c - 0.5t$

因为鸡兔不能为负数且不能为半数，所以要满足 $x>=0$、$y>=0$、$4x+2y=t$（其中$x = \lfloor 0.5t-c\rfloor$）

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int x = 0.5 * tomatoSlices - cheeseSlices, y = cheeseSlices - x;
        if (x < 0 || y < 0 || 4 * x + 2 * y != tomatoSlices) {
            return {};
        }
        return {x, y};
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def numOfBurgers(self, tomatoSlices: int, cheeseSlices: int) -> List[int]:
        x, y = int(0.5 * tomatoSlices - cheeseSlices), int(2 * cheeseSlices - 0.5 * tomatoSlices)
        if x < 0 or y < 0 or 4 * x + 2 * y != tomatoSlices:
            return []
        return [x, y]
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/12/25/LeetCode%201276.%E4%B8%8D%E6%B5%AA%E8%B4%B9%E5%8E%9F%E6%96%99%E7%9A%84%E6%B1%89%E5%A0%A1%E5%88%B6%E4%BD%9C%E6%96%B9%E6%A1%88/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135196793](https://letmefly.blog.csdn.net/article/details/135196793)
