---
title: 2347.最好的扑克手牌
date: 2023-02-20 08:09:59
tags: [题解, LeetCode, 简单, 数组, 哈希表, 计数, 模拟]
---

# 【LetMeFly】2347.最好的扑克手牌

力扣题目链接：[https://leetcode.cn/problems/best-poker-hand/](https://leetcode.cn/problems/best-poker-hand/)

<p>给你一个整数数组&nbsp;<code>ranks</code>&nbsp;和一个字符数组&nbsp;<code>suit</code>&nbsp;。你有&nbsp;<code>5</code>&nbsp;张扑克牌，第&nbsp;<code>i</code>&nbsp;张牌大小为&nbsp;<code>ranks[i]</code>&nbsp;，花色为&nbsp;<code>suits[i]</code>&nbsp;。</p>

<p>下述是从好到坏你可能持有的 <strong>手牌类型&nbsp;</strong>：</p>

<ol>
	<li><code>"Flush"</code>：同花，五张相同花色的扑克牌。</li>
	<li><code>"Three of a Kind"</code>：三条，有 3 张大小相同的扑克牌。</li>
	<li><code>"Pair"</code>：对子，两张大小一样的扑克牌。</li>
	<li><code>"High Card"</code>：高牌，五张大小互不相同的扑克牌。</li>
</ol>

<p>请你返回一个字符串，表示给定的 5 张牌中，你能组成的 <strong>最好手牌类型</strong>&nbsp;。</p>

<p><strong>注意：</strong>返回的字符串&nbsp;<strong>大小写</strong>&nbsp;需与题目描述相同。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>ranks = [13,2,3,1,9], suits = ["a","a","a","a","a"]
<b>输出：</b>"Flush"
<b>解释：</b>5 张扑克牌的花色相同，所以返回 "Flush" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>ranks = [4,4,2,4,4], suits = ["d","a","a","b","c"]
<b>输出：</b>"Three of a Kind"
<b>解释：</b>第一、二和四张牌组成三张相同大小的扑克牌，所以得到 "Three of a Kind" 。
注意我们也可以得到 "Pair" ，但是 "Three of a Kind" 是更好的手牌类型。
有其他的 3 张牌也可以组成 "Three of a Kind" 手牌类型。</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>ranks = [10,10,2,12,9], suits = ["a","b","c","a","d"]
<b>输出：</b>"Pair"
<b>解释：</b>第一和第二张牌大小相同，所以得到 "Pair" 。
我们无法得到 "Flush" 或者 "Three of a Kind" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>ranks.length == suits.length == 5</code></li>
	<li><code>1 &lt;= ranks[i] &lt;= 13</code></li>
	<li><code>'a' &lt;= suits[i] &lt;= 'd'</code></li>
	<li>任意两张扑克牌不会同时有相同的大小和花色。</li>
</ul>


    
## 方法一：模拟计数

首先判断花色，花色全部相同则返回```Flush```

接着我们对这5个“rank”排序，从第二个开始遍历排序后的rank，如果某个rank和上一个相同，则“连续相同牌数”加一，同时更新“最大连续相同值”

最终根据“最大连续相同值”确定返回的手牌类型

+ 时间复杂度$O(1)$，一共只有5个手牌，常数级运算，可以理解为$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        if (suits[0] == suits[1] && suits[1] == suits[2] && suits[2] == suits[3] && suits[3] == suits[4])
            return "Flush";
        sort(ranks.begin(), ranks.end());
        int maxSame = 1, theSame = 1;
        for (int i = 1; i < 5; i++) {
            if (ranks[i] == ranks[i - 1]) {
                theSame++;
                maxSame = max(maxSame, theSame);
            }
            else {
                theSame = 1;  // 自成一派
            }
        }
        if (maxSame >= 3)  // 不是theSame
            return "Three of a Kind";  // 注意K是大写
        if (maxSame == 2)
            return "Pair";
        return "High Card";
    }
};
```

#### Python

```python
# from typing import List


class Solution:
    def bestHand(self, ranks: List[int], suits: List[str]) -> str:
        if suits[0] == suits[1] == suits[2] ==suits[3] == suits[4]:
            return "Flush"
        ranks.sort()
        maxSame, theSame = 1, 1
        for i in range(1, 5):
            if ranks[i] == ranks[i - 1]:
                theSame += 1
                maxSame = max(maxSame, theSame)
            else:
                theSame = 1
        if maxSame >= 3:
            return "Three of a Kind"
        if maxSame == 2:
            return "Pair"
        return "High Card"
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/02/20/LeetCode%202347.%E6%9C%80%E5%A5%BD%E7%9A%84%E6%89%91%E5%85%8B%E6%89%8B%E7%89%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129117439](https://letmefly.blog.csdn.net/article/details/129117439)
