---
title: 2591.将钱分给最多的儿童
date: 2023-09-22 13:19:10
tags: [题解, LeetCode, 简单, 贪心, 数学]
---

# 【LetMeFly】2591.将钱分给最多的儿童

力扣题目链接：[https://leetcode.cn/problems/distribute-money-to-maximum-children/](https://leetcode.cn/problems/distribute-money-to-maximum-children/)

<p>给你一个整数&nbsp;<code>money</code>&nbsp;，表示你总共有的钱数（单位为美元）和另一个整数&nbsp;<code>children</code>&nbsp;，表示你要将钱分配给多少个儿童。</p>

<p>你需要按照如下规则分配：</p>

<ul>
	<li>所有的钱都必须被分配。</li>
	<li>每个儿童至少获得&nbsp;<code>1</code>&nbsp;美元。</li>
	<li>没有人获得 <code>4</code>&nbsp;美元。</li>
</ul>

<p>请你按照上述规则分配金钱，并返回 <strong>最多</strong>&nbsp;有多少个儿童获得 <strong>恰好</strong><em>&nbsp;</em><code>8</code>&nbsp;美元。如果没有任何分配方案，返回&nbsp;<code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>money = 20, children = 3
<b>输出：</b>1
<b>解释：</b>
最多获得 8 美元的儿童数为 1 。一种分配方案为：
- 给第一个儿童分配 8 美元。
- 给第二个儿童分配 9 美元。
- 给第三个儿童分配 3 美元。
没有分配方案能让获得 8 美元的儿童数超过 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>money = 16, children = 2
<b>输出：</b>2
<b>解释：</b>每个儿童都可以获得 8 美元。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= money &lt;= 200</code></li>
	<li><code>2 &lt;= children &lt;= 30</code></li>
</ul>


    
## 方法一：数学（贪心）

分情况讨论：

+ 如果money比儿童数还少，返回-1
+ 如果money特别多（每人分8美元还有剩余），就$children - 1$个儿童每人分8美元，剩下的全给另一个儿童
+ 否则，每个儿童先分1美元，接着尽可能地给每个儿童分7美元，则8美元儿童的个数为$\lfloor\frac{money - children}{7}\rfloor$，将剩余钱（≤7）分给其他儿童：
   + 如果恰好剩余3元且恰好剩余1个儿童，因为不能给他4美元，所以要从一个8美元儿童中转给他1美元（此时money = children * 8 - 4，8美元儿童数量为children - 2）
   + 否则，一定存在一种方案使得非8美元儿童的钱都不是4。

注意儿童数是≥2的，所以不存在“仅有1个儿童且恰好有4美元的情况”。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children) {
            return -1;
        }
        if (money > 8 * children) {
            return children - 1;
        }
        if (money == 8 * children - 4) {
            return children - 2;
        }
        return (money - children) / 7;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def distMoney(self, money: int, children: int) -> int:
        if money < children:
            return -1
        if money > children * 8:
            return children - 1
        if money == children * 8 - 4:
            return children - 2
        return (money - children) // 7
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2023/09/22/LeetCode%202591.%E5%B0%86%E9%92%B1%E5%88%86%E7%BB%99%E6%9C%80%E5%A4%9A%E7%9A%84%E5%84%BF%E7%AB%A5/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/133167460](https://letmefly.blog.csdn.net/article/details/133167460)
