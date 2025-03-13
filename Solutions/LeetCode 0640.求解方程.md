---
title: 640.求解方程
date: 2022-08-10 10:54:55
tags: [题解, LeetCode, 中等, 数学, 字符串, 模拟, 字符串解析]
categories: [题解, LeetCode]
---

# 【LetMeFly】640.求解方程：过几天就看不懂了的迷惑性代码，但是是详解

力扣题目链接：[https://leetcode.cn/problems/solve-the-equation/](https://leetcode.cn/problems/solve-the-equation/)

<p>求解一个给定的方程，将<code>x</code>以字符串 <code>"x=#value"</code>&nbsp;的形式返回。该方程仅包含 <code>'+'</code> ， <code>'-'</code> 操作，变量&nbsp;<code>x</code>&nbsp;和其对应系数。</p>

<p>如果方程没有解，请返回&nbsp;<code>"No solution"</code>&nbsp;。如果方程有无限解，则返回 <code>“Infinite solutions”</code> 。</p>

<p>如果方程中只有一个解，要保证返回值 <font color="#c7254e"><font face="Menlo, Monaco, Consolas, Courier New, monospace"><span style="font-size:12.6px"><span style="background-color:#f9f2f4">'x'</span></span></font></font>&nbsp;是一个整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> equation = "x+5-3+x=6+x-2"
<strong>输出:</strong> "x=2"
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> equation = "x=x"
<strong>输出:</strong> "Infinite solutions"
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> equation = "2x=x"
<strong>输出:</strong> "x=0"
</pre>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>3 &lt;= equation.length &lt;= 1000</code></li>
	<li><code>equation</code>&nbsp;只有一个&nbsp;<code>'='</code>.</li>
	<li><code>equation</code>&nbsp;方程由整数组成，其绝对值在&nbsp;<code>[0, 100]</code>&nbsp;范围内，不含前导零和变量 <code>'x'</code> 。&nbsp;<span style="display:block"><span style="height:0px"><span style="position:absolute">​​​</span></span></span></li>
</ul>


    
## 方法一：模拟

**自认为这道题代码写得太具有迷惑性了，推荐一波**[官解](https://leetcode.cn/problems/solve-the-equation/solution/qiu-jie-fang-cheng-by-leetcode-solution-knct/)。如果不嫌弃，也可以看一看我的思路：

首先确定等号的位置，这样我们就可以得知左边的表达式和右边的表达式的范围了。

对于某个表达式，我们求出其中$x$的系数和常数分别为多少。

那么具体怎么求呢？

首先我们把表达式分割成一个一个的小单元“-2”、“+3”、“5”、“-x”、“-2x”、“x”、“3x”等，分割规则是：遇到下一个“加减号”或到表达式结尾。

对于某个“小单元”，可以手写一个```atoi```函数求出这个小单元的值/$x$的系数（如果最后一个字符是```x```就加到$x$的系数上，否则就加到常数上）（如果最后一个字符是```x```，那么调用```atoi```时就把长度减少一位，不把```x```这个字符传递给```atoi```函数）

那么怎么写```atoi```函数呢？

首先要讨论传递到这个函数中的字符串有哪几种情况：

+ ```-2```（来自```-2```或```-2x```）
+ ```+3```（来自```+3```或```+3x```）
+ ```5```（来自```5```或```5x```）
+ ```-```（来自```-x```）
+ ``` ```（来自```x```）

只要我们能处理好上述$5$种情况，那么对于本题来说，就是一个完美的```atoi```函数。（不能使用自带的```atoi```，否则```+```、```-```、``` ```都将被处理为$0$）

最后回到初始问题，我们知道了左边$x$的系数、左边的常数、右边$x$的系数、右边的常数，如果“左边$x$系数等于右边并且左边常数不等于右边”那么就“无解”($x + 1 = x + 2$)，如果“左边$x$系数等于右边并且左边并且左边常数等于右边”那么就“无数解”($x + 1 = x + 1$)，否则方程的解为$x=\frac{右边常数 - 左边常数}{左边x系数 - 右边x系数}$

+ 时间复杂度$O(n)$，其中$n$是字符串长度，每个字符最多遍历$3$次（判断等号位置、确定下一个加减号的位置、确定某个“小单元”的值）
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
private:
    int getEqualLocation(string& s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '=')
                return i;
        }
        return -1;  // Fake Return
    }

    int __LetMeFly_atoi(string& s, int left, int length) {
        if (length == 0) {
            return 1;
        }
        if (length == 1 && s[left] == '-') {
            return -1;
        }
        if (length == 1 && s[left] == '+') {
            return 1;
        }
        int k = 1;
        if (s[left] == '+')
            left++, length--;
        else if (s[left] == '-')
            left++, length--, k = -1;
        int ans = 0;
        while (length--) {
            ans *= 10;
            ans += s[left++] - '0';
        }
        return ans * k;
    }

    pair<int, int> getXandConst(string& s, int l, int r) {  // get [l, r) 's x and const
        pair<int, int> ans;
        int lastLoc = l;
        for (int nowLoc = l; nowLoc <= r; nowLoc++) {
            if (nowLoc != l && (nowLoc == r || s[nowLoc] == '+' || s[nowLoc] == '-')) {
                // (lastLoc, nowLoc)
                (s[nowLoc - 1] == 'x' ? ans.first : ans.second) += __LetMeFly_atoi(s, lastLoc, (s[nowLoc - 1] == 'x' ? nowLoc - 1 : nowLoc) - lastLoc);
                lastLoc = nowLoc;
            }
        }
        return ans;
    }
public:
    string solveEquation(string& equation) {
        int locEqual = getEqualLocation(equation);
        auto [leftX, leftConst] = getXandConst(equation, 0, locEqual);
        auto [rightX, rightConst] = getXandConst(equation, locEqual + 1, equation.size());
        if (leftX == rightX) {
            return leftConst == rightConst ? "Infinite solutions" : "No solution";
        }
        return "x=" + to_string((rightConst - leftConst) / (leftX - rightX));
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/08/10/LeetCode%200640.%E6%B1%82%E8%A7%A3%E6%96%B9%E7%A8%8B/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126262898](https://letmefly.blog.csdn.net/article/details/126262898)
