---
title: 564.寻找最近的回文数
date: 2022-03-03 14:53:21
tags: [题解, LeetCode, 困难, 贪心, 字符串]
---

[力扣题目链接](https://leetcode-cn.com/problems/find-the-closest-palindrome/)

给定一个表示整数的字符串 $n$ ，返回与它最近的回文整数（不包括自身）。如果不止一个，返回较小的那个。

“最近的”定义为两个整数差的绝对值最小。

**示例 1:**

```
输入: n = "123"
输出: "121"
```

**示例 2:**

```
输入: n = "1"
输出: "0"
解释: 0 和 2是最近的回文，但我们返回最小的，也就是 0。
```

**提示:**

1. $1 \leq n.length \leq 18$
2. $n$ 只由数字组成
3. $n$ 不含前导 $0$
4. $n$ 代表在 $[1, 10^{18} - 1]$ 范围内的整数


# 思路

本题主要思路就是贪心。要想使修改后和修改前差别尽可能小，最容易想到的就是优先修改**低位**的数字。

但是回文串中，低位的修改可能会导致高位同步修改，因此，最小代价的改动就是修改中间的值。

比如数字 $222$ 本身就是回文串，要变成与它绝对值之差最小的回文串，如果把最低位的 $2$ 修改为 $1$，那么最高位的 $2$ 也要相应地修改为 $1$，因此 $222$ 就变成了 $121$ ，$diff=abs(121-222)=101$ 。但是如果我们优先修改中间的值，把十位的 $2$ 修改为 $1$ ，$222$ 就会变成 $212$ ， $diff=abs(212-222)=10$ 。

总之，尽可能优先地修改中间的值即可。修改完中间的值后，只需要把后半部分变成前半部分的对称即可。因为是尽可能小地改动，所以我们只需要考虑 $前半部分-1$ 、 $前半部分不变$ 、 $前半部分+1$ 这 $3$ 种情况，并把后半部分变成前半部分的对称即可。

**特殊情况：**

1. 当给定数字本身就是个位数时，直接 $原数字-1$ 即可。

2. 存在一些特殊的数字，采用上述贪心策略无法得到最优解。
   >
   > 例如 $999$ ，按照上述贪心策略可能会考虑 前半部分 $99+1=100$ 的情况，这样前后做对称就变成了 $100001$ ，显然 $999$ 变成 $1001$ 才是更优解。同理，$10023$ 按上述策略会变成 $999$ ，但其实 $9999$ 才是最优解。
   >
   > 这两种情况是由“前半部分±1后数字位数发生变化”导致的，我们在考虑最优解的时候，把形如 $100..001$ 、 $99..99$ 的数字也考虑进去即可。


# AC代码

## C++

```cpp
typedef long long ll;

class Solution {
public:
    string nearestPalindromic(string n) {
        // 如果直接就是个位数，就返回n-1即可
        if (n.size() == 1) {
            n[0] -= 1;
            return n;
        }
        // 候选的答案（包括 99..99、100..001、前半部分+1做对称、前半部分不变做对称、前半部分-1做对称）
        vector<ll> condidates = {
            (ll)pow(10, n.size()) + 1,  // 100..001  例如99有2位，因此有候选答案101（10 ^ 2 + 1）
            (ll)pow(10, n.size() - 1) - 1  // 99..99  例如100有3位，因此就有候选答案99（10 ^ (3 - 1) - 1）
        };
        string half = n.substr(0, (n.size() + 1) / 2);  // 前半部分  如果是三位数就取2位，四位数也取1位，两位数就取1位，因此前半部分的长度是⌊(n.size() + 1) / 2⌋
        auto repair = [&](string qian){  // 由前半部分还原为整个数字的函数
            /* 
                整个数字：前半部分qian + {后半部分}
                    后半部分：
                        如果原数是奇数位，前半部分的最低位就不需要再重复一次(123的前半部分是12,还原成对称的整个数字是121,2不需要重复)
                        如果原数是偶数位，前半部分的最低为还需要重复一次(1234的前半部分是12,还原成1221,2需要重复)
                        因此原数字是奇数位的话前半部分的迭代器rbegin()+1正好跳过最低位，偶数rbegin()+0就正好包含了最低位
            */
            return qian + string(qian.rbegin() + (n.size() & 1), qian.rend());
        };
        for (int i = -1; i <= 1; i++) {  // 前半部分 +1、不变、-1
            /*
                stol(half)：前半部分(字符串)变成long long类型的数字
                stol(half) + i：前半部分 +1、不变 或 -1
                to_string(stol(half) + i)： repair函数接收的数据类型是string，因此把long long类型的数字变成string类型
                repair(to_string(stol(half) + i))：由前半部分还原出整个数字
                stol(repair(to_string(stol(half) + i)))：把repair函数返回的string类型的数字转换为long long类型
                condidates.push_back(stol(repair(to_string(stol(half) + i))))：将新的候选数字加入候选数字集合中
            */
            condidates.push_back(stol(repair(to_string(stol(half) + i))));
        }
        ll m = 1e18, ans = -1;  // m：新回文数 与 原数字 最小的diff  ans：答案
        for (ll& thisAns : condidates) {  // 对于所有的候选数字
            if (thisAns != stol(n) && m >= abs(thisAns - stol(n))) {  // 首先不是原数，其次这个diff不大于之前候选数字的最小diff
                if (m == abs(thisAns - stol(n))) {  // 如果这个diff正好等于之前的最小diff
                    ans = min(ans, thisAns); // 取最小的那个候选数字 （121 与 {111、131} 的 diff 都是10，但据题意我们需要更小的111）
                }
                else {  // 否则更新答案为 能使diff更小的这个候选数字
                    m = abs(thisAns - stol(n));
                    ans = thisAns;
                }
            }
        }
        return to_string(ans);  // 返回string类型的答案
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://letmefly.blog.csdn.net/article/details/123254172)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/123254172](https://letmefly.blog.csdn.net/article/details/123254172)
