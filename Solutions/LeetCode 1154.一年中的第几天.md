---
title: 1154.一年中的第几天
date: 2023-12-31 12:30:00
tags: [题解, LeetCode, 简单, 数学, 字符串, 日期处理]
---

# 【LetMeFly】1154.一年中的第几天：2023年最后一道每日一题

力扣题目链接：[https://leetcode.cn/problems/day-of-the-year/](https://leetcode.cn/problems/day-of-the-year/)

<p>给你一个字符串&nbsp;<code>date</code> ，按 <code>YYYY-MM-DD</code> 格式表示一个 <a href="https://baike.baidu.com/item/公元/17855" target="_blank">现行公元纪年法</a> 日期。返回该日期是当年的第几天。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>date = "2019-01-09"
<strong>输出：</strong>9
<strong>解释：</strong>给定日期是2019年的第九天。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>date = "2019-02-10"
<strong>输出：</strong>41
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>date.length == 10</code></li>
	<li><code>date[4] == date[7] == '-'</code>，其他的&nbsp;<code>date[i]</code>&nbsp;都是数字</li>
	<li><code>date</code> 表示的范围从 1900 年 1 月 1 日至 2019 年 12 月 31 日</li>
</ul>


    
## 方法一：日期处理

首先明确一年中的12个月分别有几天（以非闰年为例）：```dayOfMonth = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]```。

如果是闰年，那么```2```月有```29```天（```dayOfMonth[1] = 29```）。

怎么判断一年是否为闰年呢？

+ 如果年份是100的倍数，则只有年份为400的倍数时为闰年
+ 否则，年份为4的倍数时为闰年

从给定字符串中，我们可以很方便地“分离出”年```y```月```m```日```d```，从```1```月到```m - 1```月累加这个月的天数，再加上```d```即为答案。

+ 时间复杂度$O(1)$，将一年的```12```个月视为常数
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
private:
    int dayOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool isRunNian(int y) {
        if (y % 100 == 0) {
            return y % 400 == 0;
        }
        return y % 4 == 0;
    }

public:
    int dayOfYear(string date) {
        int y, m, d;
        sscanf(date.c_str(), "%d-%d-%d", &y, &m, &d);
        if (isRunNian(y)) {
            dayOfMonth[1] = 29;
        }
        int ans = 0;
        for (int i = 1; i < m; i++) {
            ans += dayOfMonth[i - 1];
        }
        ans += d;
        return ans;
    }
};
```

#### Python

```python
class Solution:
    def ifRunNian(self, y: int) -> bool:
        if y % 100 == 0:
            return y % 400 == 0
        return y % 4 == 0
    
    def dayOfYear(self, date: str) -> int:
        dayOfMonth = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        y, m, d = map(int, date.split('-'))
        if self.ifRunNian(y):
            dayOfMonth[1] = 29
        ans = 0
        for i in range(1, m):
            ans += dayOfMonth[i - 1]
        ans += d
        return ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2023/12/31/LeetCode%201154.%E4%B8%80%E5%B9%B4%E4%B8%AD%E7%9A%84%E7%AC%AC%E5%87%A0%E5%A4%A9/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135315004](https://letmefly.blog.csdn.net/article/details/135315004)
