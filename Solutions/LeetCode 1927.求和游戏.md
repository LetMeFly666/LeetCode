---
title: 1927.求和游戏：抵消+看最值
date: 2026-08-23 13:47:13
tags: [题解, LeetCode, 中等, 贪心, 数学, 字符串, 博弈, 博弈论]
categories: [题解, LeetCode]
---

# 【LetMeFly】1927.求和游戏：抵消+看最值

力扣题目链接：[https://leetcode.cn/problems/sum-game/](https://leetcode.cn/problems/sum-game/)

<p>Alice 和 Bob 玩一个游戏，两人轮流行动，<strong>Alice 先手</strong> 。</p>

<p>给你一个 <strong>偶数长度</strong> 的字符串 <code>num</code> ，每一个字符为数字字符或者 <code>'?'</code> 。每一次操作中，如果 <code>num</code> 中至少有一个 <code>'?'</code> ，那么玩家可以执行以下操作：</p>

<ol>
	<li>选择一个下标 <code>i</code> 满足 <code>num[i] == '?'</code> 。</li>
	<li>将 <code>num[i]</code> 用 <code>'0'</code> 到 <code>'9'</code> 之间的一个数字字符替代。</li>
</ol>

<p>当 <code>num</code> 中没有<span style=""> </span><code>'?'</code> 时，游戏结束。</p>

<p>Bob 获胜的条件是 <code>num</code> 中前一半数字的和 <strong>等于</strong> 后一半数字的和。Alice 获胜的条件是前一半的和与后一半的和 <strong>不相等</strong> 。</p>

<ul>
	<li>比方说，游戏结束时 <code>num = "243801"</code> ，那么 Bob 获胜，因为 <code>2+4+3 = 8+0+1</code> 。如果游戏结束时 <code>num = "243803"</code> ，那么 Alice 获胜，因为 <code>2+4+3 != 8+0+3</code> 。</li>
</ul>

<p>在 Alice 和 Bob 都采取 <strong>最优</strong> 策略的前提下，如果 Alice 获胜，请返回 <code>true</code> ，如果 Bob 获胜，请返回 <code>false</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>num = "5023"
<b>输出：</b>false
<b>解释：</b>num 中没有 '?' ，没法进行任何操作。
前一半的和等于后一半的和：5 + 0 = 2 + 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>num = "25??"
<b>输出：</b>true
<strong>解释：</strong>Alice 可以将两个 '?' 中的一个替换为 '9' ，Bob 无论如何都无法使前一半的和等于后一半的和。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>num = "?3295???"
<b>输出：</b>false
<b>解释：</b>Bob 总是能赢。一种可能的结果是：
- Alice 将第一个 '?' 用 '9' 替换。num = "93295???" 。
- Bob 将后面一半中的一个 '?' 替换为 '9' 。num = "932959??" 。
- Alice 将后面一半中的一个 '?' 替换为 '2' 。num = "9329592?" 。
- Bob 将后面一半中最后一个 '?' 替换为 '7' 。num = "93295927" 。
Bob 获胜，因为 9 + 3 + 2 + 9 = 5 + 9 + 2 + 7 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= num.length <= 10<sup>5</sup></code></li>
	<li><code>num.length</code> 是 <strong>偶数</strong> 。</li>
	<li><code>num</code> 只包含数字字符和 <code>'?'</code> 。</li>
</ul>


    
## 解题方法：先抵消，然后看最值

先算算前半个字符串总值是多少、问号有多少；再算算后半字符串总值是多少、问号有多少。

> 不妨令后半字符串的问号不少于前半字符串（如果少于则交换前后两字符串的总值、问号数，不影响填写结果）。

计算前半字符串比后半字符串的总值差值 $diff$，以及问号数差值 $times$。

> 为何可以计算两字符串问号数量的差值？因为(假设前半字符串问号数量少)Alice在前半段填写什么，Bob就可以在后半段填写一样的数抵消差值，且**Alice的最佳方案可以只填9或0**。

现在问题变成了，前半段总值比后半段多$diff$，后半段字符串有$times$个问号，Alice先手，能否导致后面总值不等于$diff$。

> 算下先手Alice想让后半段字符串问号总和最大的话（Alice全填9Bob全填0）能有多大；算下先手Alice想让后半段字符串问号总和最小的话（Alice全填0Bob全填9）能有多小。如果bob全填0的后半段问号最大值$M$大于$diff$则Alice获胜、如果bob全填9的后半段问号最小值$m$小于$diff$则Alice获胜；否则Bob获胜。

+ 时间复杂度$O(len(num))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-08-23 13:46:29
 */
typedef pair<int, int> pii;
class Solution {
private:
    pii cal(string& s, int l, int r) {
        int val = 0, cnt = 0;
        for (int i = l; i < r; i++) {
            if ('0' <= s[i] && s[i] <= '9') {
                val += s[i] - '0';
            } else {
                cnt++;
            }
        }
        return {val, cnt};
    }

    int getM(int n) {
        return 9 * ((n + 1) / 2);
    }

    int getm(int n) {
        return 9 * (n / 2);
    }
public:
    bool sumGame(string& num) {
        int n = num.size();
        auto [val1, cnt1] = cal(num, 0, n / 2);
        auto [val2, cnt2] = cal(num, n / 2, n);
        if (cnt1 > cnt2) {
            swap(val1, val2);
            swap(cnt1, cnt2);
        }
        int diff = val1 - val2, times = cnt2 - cnt1;
        int M = getM(times), m = getm(times);
        return M > diff || m < diff;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/163996898)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/08/23/LeetCode%201927.%E6%B1%82%E5%92%8C%E6%B8%B8%E6%88%8F/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
