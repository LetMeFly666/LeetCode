---
title: 2437.有效时间的数目
date: 2023-05-09 09:55:55
tags: [题解, LeetCode, 简单, 字符串, 枚举, 模拟, 特判, 时间]
---

# 【LetMeFly】2437.有效时间的数目

力扣题目链接：[https://leetcode.cn/problems/number-of-valid-clock-times/](https://leetcode.cn/problems/number-of-valid-clock-times/)

<p>给你一个长度为&nbsp;<code>5</code>&nbsp;的字符串&nbsp;<code>time</code>&nbsp;，表示一个电子时钟当前的时间，格式为&nbsp;<code>"hh:mm"</code>&nbsp;。<strong>最早</strong>&nbsp;可能的时间是&nbsp;<code>"00:00"</code>&nbsp;，<strong>最晚</strong>&nbsp;可能的时间是&nbsp;<code>"23:59"</code>&nbsp;。</p>

<p>在字符串&nbsp;<code>time</code>&nbsp;中，被字符&nbsp;<code>?</code>&nbsp;替换掉的数位是 <strong>未知的</strong>&nbsp;，被替换的数字可能是&nbsp;<code>0</code>&nbsp;到&nbsp;<code>9</code>&nbsp;中的任何一个。</p>

<p>请你返回一个整数<em>&nbsp;</em><code>answer</code>&nbsp;，将每一个 <code>?</code>&nbsp;都用<em>&nbsp;</em><code>0</code>&nbsp;到<em>&nbsp;</em><code>9</code>&nbsp;中一个数字替换后，可以得到的有效时间的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>time = "?5:00"
<b>输出：</b>2
<b>解释：</b>我们可以将 ? 替换成 0 或 1 ，得到 "05:00" 或者 "15:00" 。注意我们不能替换成 2 ，因为时间 "25:00" 是无效时间。所以我们有两个选择。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>time = "0?:0?"
<b>输出：</b>100
<b>解释：</b>两个 ? 都可以被 0 到 9 之间的任意数字替换，所以我们总共有 100 种选择。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>time = "??:??"
<b>输出：</b>1440
<b>解释：</b>小时总共有 24 种选择，分钟总共有 60 种选择。所以总共有 24 * 60 = 1440 种选择。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>time</code>&nbsp;是一个长度为 <code>5</code>&nbsp;的有效字符串，格式为&nbsp;<code>"hh:mm"</code>&nbsp;。</li>
	<li><code>"00" &lt;= hh &lt;= "23"</code></li>
	<li><code>"00" &lt;= mm &lt;= "59"</code></li>
	<li>字符串中有的数位是&nbsp;<code>'?'</code>&nbsp;，需要用&nbsp;<code>0</code>&nbsp;到&nbsp;<code>9</code>&nbsp;之间的数字替换。</li>
</ul>


    
## 方法一：特判

写两个函数，分别计算时间有多少种，分钟有多少种。

对于时间：

+ 如果两个位置都是'?'，那么一共有24种
+ 若只第一个位置是'?'，那么第二个位置是'0'-'3'的话有3种，否则有2种（没有25点）
+ 若只第二个位置是'?'，那么第一个位置是'0'-'1'的话有10种，否则有4种
+ 若两个位置都不是'?'，则返回1

同理，对于分钟：

+ 如果两个位置都是'?'，那么一共有60种
+ 若只第一个位置是'?'，那么一共有6种
+ 若只第二个位置是'?'，那么一共有10种
+ 若两个位置都不是'?'，则返回1

最终$小时种类数\times 分钟种类数$即为答案

+ 时间复杂度$O(1)$，全部由if-else组成
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
private:
    int getHour(char a, char b) {
        if (a == '?' && b == '?') {
            return 24;
        }
        if (a == '?') {
            return '0' <= b && b <= '3' ? 3 : 2;
        }
        if (b == '?') {
            return a == '0' || a == '1' ? 10 : 4;
        }
        return 1;
    }

    int getMin(char a, char b) {
        if (a == '?' && b == '?') {
            return 60;
        }
        if (a == '?') {
            return 6;
        }
        if (b == '?') {
            return 10;
        }
        return 1;
    }
public:
    int countTime(string time) {
        return getHour(time[0], time[1]) * getMin(time[3], time[4]);
    }
};
```

## 方法二：枚举

我们只需要枚举每一个合法的时间，然后判断给定时间能否替换'?'成为枚举的时间即可。

枚举合法时间：

```cpp
for (int h = 0; h < 24; h++) {
    for (int m = 0; m < 60; m++) {
        // ...
    }
}
```

判断能否由oldTime变成newTime：

```cpp
bool canChangeTo(string oldTime, string newTime) {
    for (int i = 0; i < 5; i++) {
        if (oldTime[i] != newTime[i] && oldTime[i] != '?') {  // 两字符串此数不同，且oldTime这个数不是?
            return false;
        }
    }
    return true;
}
```

+ 时间复杂度$O(H\times M\times C)$，其中$H=24$，$M=60$，$C$是时间字符串的长度$5$
+ 空间复杂度$O(C)$

### AC代码

#### C++

```cpp
class Solution {
private:
    bool canChangeTo(string oldTime, string newTime) {
        for (int i = 0; i < 5; i++) {
            if (oldTime[i] != newTime[i] && oldTime[i] != '?') {
                return false;
            }
        }
        return true;
    }
public:
    int countTime(string time) {
        int ans = 0;
        for (int h = 0; h < 24; h++) {
            for (int m = 0; m < 60; m++) {
                string thisTime = string("") + (char)('0' + h / 10) + (char)('0' + h % 10) + ':' + (char)('0' + m / 10) + (char)('0' + m % 10);
                ans += canChangeTo(time, thisTime);
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/05/09/LeetCode%202437.%E6%9C%89%E6%95%88%E6%97%B6%E9%97%B4%E7%9A%84%E6%95%B0%E7%9B%AE/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130573965](https://letmefly.blog.csdn.net/article/details/130573965)
