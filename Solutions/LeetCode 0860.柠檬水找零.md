---
title: 860.柠檬水找零：附C++一行代码版
date: 2023-07-22 09:29:05
tags: [题解, LeetCode, 简单, 贪心, 数组]
---

# 【LetMeFly】860.柠檬水找零：附C++一行代码版

力扣题目链接：[https://leetcode.cn/problems/lemonade-change/](https://leetcode.cn/problems/lemonade-change/)

<p>在柠檬水摊上，每一杯柠檬水的售价为&nbsp;<code>5</code>&nbsp;美元。顾客排队购买你的产品，（按账单 <code>bills</code> 支付的顺序）一次购买一杯。</p>

<p>每位顾客只买一杯柠檬水，然后向你付 <code>5</code> 美元、<code>10</code> 美元或 <code>20</code> 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 <code>5</code> 美元。</p>

<p>注意，一开始你手头没有任何零钱。</p>

<p>给你一个整数数组 <code>bills</code> ，其中 <code>bills[i]</code> 是第 <code>i</code> 位顾客付的账。如果你能给每位顾客正确找零，返回&nbsp;<code>true</code>&nbsp;，否则返回 <code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>bills = [5,5,5,10,20]
<strong>输出：</strong>true
<strong>解释：
</strong>前 3 位顾客那里，我们按顺序收取 3 张 5 美元的钞票。
第 4 位顾客那里，我们收取一张 10 美元的钞票，并返还 5 美元。
第 5 位顾客那里，我们找还一张 10 美元的钞票和一张 5 美元的钞票。
由于所有客户都得到了正确的找零，所以我们输出 true。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>bills = [5,5,10,10,20]
<strong>输出：</strong>false
<strong>解释：</strong>
前 2 位顾客那里，我们按顺序收取 2 张 5 美元的钞票。
对于接下来的 2 位顾客，我们收取一张 10 美元的钞票，然后返还 5 美元。
对于最后一位顾客，我们无法退回 15 美元，因为我们现在只有两张 10 美元的钞票。
由于不是每位顾客都得到了正确的找零，所以答案是 false。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= bills.length &lt;= 10<sup>5</sup></code></li>
	<li><code>bills[i]</code>&nbsp;不是&nbsp;<code>5</code>&nbsp;就是&nbsp;<code>10</code>&nbsp;或是&nbsp;<code>20</code>&nbsp;</li>
</ul>


    
## 方法一：贪心

**一句话概括：**

能找零10元就不找零两个5元。

**具体方法の详细描述：**

使用两个变量```_5```和```_10```分别记录自己手中的5元和10元的数量，使用bill遍历bills数组：

+ 如果bill为5，则$\_5++$
+ 如果bill为10，则看有无5元
   + 如果$\_5 \geq 0$，则$\_5--, \_10++$
   + 否则，返回```false```
+ 否则（bill为20），看是否同时有10元和5元
   + 如果$\_5 \geq 0\ and\ \_10 \geq 0$，则$\_5--, \_10--$
   + 否则看是否有三张及以上的5元
      + 如果$\_5 \geq 3$，$\_5 -= 3$
	  + 否则，返回```false```

若未遍历结束且返回false，则返回true。

+ 时间复杂度$O(len(bills))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int _5 = 0, _10 = 0;
        for (int bill : bills) {
            if (bill == 5) {
                _5++;
            }
            else if (bill == 10) {
                if (_5) {
                    _5--;
                    _10++;
                }
                else {
                    return false;
                }
            }
            else {
                if (_10 && _5) {
                    _10--, _5--;
                }
                else if (_5 >= 3) {
                    _5 -= 3;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        _5, _10 = 0, 0
        for bill in bills:
            if bill == 5:
                _5 += 1
            elif bill == 10:
                if _5:
                    _5 -= 1
                    _10 += 1
                else:
                    return False
            else:
                if _5 and _10:
                    _5 -= 1
                    _10 -= 1
                elif _5 >= 3:
                    _5 -= 3
                else:
                    return False
        return True
```

#### C++一行版

这里使用了一个小技巧：买家付钱20时：自己“若有10元”，则必须找零10元和5元。而不是“自己有10元和20元”时才找10元和5元。

并且其中巧妙运用了自增运算符```a++```和```++a```来确定返回值的非零与否。

```cpp
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        return all_of(bills.begin(), bills.end(), [_5 = 0, _10 = 0](int bill)mutable {return bill == 5 ? ++_5 : bill == 10 ? (_5-- && ++_10) : _10 ? (_10-- && _5--) : ((_5 -= 3) >= 0);});
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/07/22/LeetCode%200860.%E6%9F%A0%E6%AA%AC%E6%B0%B4%E6%89%BE%E9%9B%B6/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131864033](https://letmefly.blog.csdn.net/article/details/131864033)
