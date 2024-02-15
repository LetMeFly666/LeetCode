---
title: 2409.统计共同度过的日子数
date: 2023-04-17 10:17:49
tags: [题解, LeetCode, 简单, 数学, 字符串, 日期处理, 区间交集]
---

# 【LetMeFly】2409.统计共同度过的日子数

力扣题目链接：[https://leetcode.cn/problems/count-days-spent-together/](https://leetcode.cn/problems/count-days-spent-together/)

<p>Alice 和 Bob 计划分别去罗马开会。</p>

<p>给你四个字符串&nbsp;<code>arriveAlice</code>&nbsp;，<code>leaveAlice</code>&nbsp;，<code>arriveBob</code>&nbsp;和&nbsp;<code>leaveBob</code>&nbsp;。Alice 会在日期&nbsp;<code>arriveAlice</code>&nbsp;到&nbsp;<code>leaveAlice</code>&nbsp;之间在城市里（<strong>日期为闭区间</strong>），而 Bob 在日期&nbsp;<code>arriveBob</code>&nbsp;到&nbsp;<code>leaveBob</code>&nbsp;之间在城市里（<strong>日期为闭区间</strong>）。每个字符串都包含 5 个字符，格式为&nbsp;<code>"MM-DD"</code>&nbsp;，对应着一个日期的月和日。</p>

<p>请你返回 Alice和 Bob 同时在罗马的天数。</p>

<p>你可以假设所有日期都在 <strong>同一个</strong>&nbsp;自然年，而且 <strong>不是</strong>&nbsp;闰年。每个月份的天数分别为：<code>[31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19"
<b>输出：</b>3
<b>解释：</b>Alice 从 8 月 15 号到 8 月 18 号在罗马。Bob 从 8 月 16 号到 8 月 19 号在罗马，他们同时在罗马的日期为 8 月 16、17 和 18 号。所以答案为 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>arriveAlice = "10-01", leaveAlice = "10-31", arriveBob = "11-01", leaveBob = "12-31"
<b>输出：</b>0
<b>解释：</b>Alice 和 Bob 没有同时在罗马的日子，所以我们返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>所有日期的格式均为&nbsp;<code>"MM-DD"</code>&nbsp;。</li>
	<li>Alice 和 Bob 的到达日期都 <strong>早于或等于</strong> 他们的离开日期。</li>
	<li>题目测试用例所给出的日期均为 <strong>非闰年</strong> 的有效日期。</li>
</ul>


    
## 方法一：日期处理 + 区间交集

首先要做的是计算当前日期是一年中的第几天。这个不难，首先提取出“月份m”和“日期d”，将$[1,m)$月每月的天数累加，然后加上日期d记为这天在一年中是第几天。

这样，我们将两人的四个日期转为四个整数后（arriveAlice -> aa, leaveAlice -> la, arriveBob -> ab, leaveBob -> lb），求出区间$[aa, la]$和$[ab, lb]$的交集即为答案。

怎么求两个区间的交集呢？首先我们让$aa\leq ab$（如果$aa>ab$，那么不失一般性，我们可以交换$[aa, la]$和$[ab, lb]$使得$aa\leq ab$）

好了，a来得比b早，如果a走了b还没有来，那么交集就是0天（$la < ab$）

否则，交集为：$a和b离开较早的那天 - b来的那天 + 1$

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
const int dayPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Solution {
private:
    int stringToInt(string& s) {
        int m, d;
        sscanf(s.c_str(), "%d-%d", &m, &d);
        int ans = 0;
        for (int i = 1; i < m; i++) {
            ans += dayPerMonth[i - 1];
        }
        ans += d;
        return ans;
    }
public:
    int countDaysTogether(string& arriveAlice, string& leaveAlice, string& arriveBob, string& leaveBob) {
        int aa = stringToInt(arriveAlice), la = stringToInt(leaveAlice);
        int ab = stringToInt(arriveBob), lb = stringToInt(leaveBob);
        if (aa > ab) {
            swap(aa, ab);
            swap(la, lb);
        }
        if (ab > la) {
            return 0;
        }
        return min(lb, la) - ab + 1;
    }
};
```

#### Python

```python
dayPerMonth = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

class Solution:
    def stringToInt(self, s: str) -> int:
        m, d = map(int, s.split('-'))
        ans = 0
        for i in range(1, m):
            ans += dayPerMonth[i - 1]
        ans += d
        return ans

    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        aa = self.stringToInt(arriveAlice)
        la = self.stringToInt(leaveAlice)
        ab = self.stringToInt(arriveBob)
        lb = self.stringToInt(leaveBob)
        if aa > ab:
            aa, ab = ab, aa
            la, lb = lb, la
        if ab > la:
            return 0
        return min(la, lb) - ab + 1
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/04/17/LeetCode%202409.%E7%BB%9F%E8%AE%A1%E5%85%B1%E5%90%8C%E5%BA%A6%E8%BF%87%E7%9A%84%E6%97%A5%E5%AD%90%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130194499](https://letmefly.blog.csdn.net/article/details/130194499)
