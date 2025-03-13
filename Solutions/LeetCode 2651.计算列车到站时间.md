---
title: 2651.计算列车到站时间
date: 2023-09-08 09:27:14
tags: [题解, LeetCode, 简单, 数学, 取模]
categories: [题解, LeetCode]
---

# 【LetMeFly】2651.计算列车到站时间

力扣题目链接：[https://leetcode.cn/problems/calculate-delayed-arrival-time/](https://leetcode.cn/problems/calculate-delayed-arrival-time/)

<p>给你一个正整数 <code>arrivalTime</code> 表示列车正点到站的时间（单位：小时），另给你一个正整数 <code>delayedTime</code> 表示列车延误的小时数。</p>

<p>返回列车实际到站的时间。</p>

<p>注意，该问题中的时间采用 24 小时制。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arrivalTime = 15, delayedTime = 5 
<strong>输出：</strong>20 
<strong>解释：</strong>列车正点到站时间是 15:00 ，延误 5 小时，所以列车实际到站的时间是 15 + 5 = 20（20:00）。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arrivalTime = 13, delayedTime = 11
<strong>输出：</strong>0
<strong>解释：</strong>列车正点到站时间是 13:00 ，延误 11 小时，所以列车实际到站的时间是 13 + 11 = 24（在 24 小时制中表示为 00:00 ，所以返回 0）。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arrivaltime &lt;&nbsp;24</code></li>
	<li><code>1 &lt;= delayedTime &lt;= 24</code></li>
</ul>


    
## 方法一：取模

+ 24点 == 0点
+ 25点 == 1点
+ ...

因此，直接将```arrivalTime```和```delayedTime```相加后对24取模即可。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime + delayedTime) % 24;
    }
};
```

#### Python

```python
class Solution:
    def findDelayedArrivalTime(self, arrivalTime: int, delayedTime: int) -> int:
        return (arrivalTime + delayedTime) % 24
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/09/08/LeetCode%202651.%E8%AE%A1%E7%AE%97%E5%88%97%E8%BD%A6%E5%88%B0%E7%AB%99%E6%97%B6%E9%97%B4/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/132753201](https://letmefly.blog.csdn.net/article/details/132753201)
