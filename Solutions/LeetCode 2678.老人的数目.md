---
title: 2678.老人的数目
date: 2023-10-23 13:22:31
tags: [题解, LeetCode, 简单, 数组, 字符串]
categories: [题解, LeetCode]
---

# 【LetMeFly】2678.老人的数目

力扣题目链接：[https://leetcode.cn/problems/number-of-senior-citizens/](https://leetcode.cn/problems/number-of-senior-citizens/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的字符串&nbsp;<code>details</code>&nbsp;。<code>details</code>&nbsp;中每个元素都是一位乘客的信息，信息用长度为 <code>15</code>&nbsp;的字符串表示，表示方式如下：</p>

<ul>
	<li>前十个字符是乘客的手机号码。</li>
	<li>接下来的一个字符是乘客的性别。</li>
	<li>接下来两个字符是乘客的年龄。</li>
	<li>最后两个字符是乘客的座位号。</li>
</ul>

<p>请你返回乘客中年龄 <strong>严格大于 60 岁</strong>&nbsp;的人数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>details = ["7868190130M7522","5303914400F9211","9273338290F4010"]
<b>输出：</b>2
<b>解释：</b>下标为 0 ，1 和 2 的乘客年龄分别为 75 ，92 和 40 。所以有 2 人年龄大于 60 岁。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>details = ["1313579440F2036","2921522980M5644"]
<b>输出：</b>0
<b>解释：</b>没有乘客的年龄大于 60 岁。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= details.length &lt;= 100</code></li>
	<li><code>details[i].length == 15</code></li>
	<li><code>details[i]</code>&nbsp;中的数字只包含&nbsp;<code>'0'</code>&nbsp;到&nbsp;<code>'9'</code>&nbsp;。</li>
	<li><code>details[i][10]</code>&nbsp;是 <code>'M'</code>&nbsp;，<code>'F'</code>&nbsp;或者&nbsp;<code>'O'</code>&nbsp;之一。</li>
	<li>所有乘客的手机号码和座位号互不相同。</li>
</ul>


    
## 方法一：模拟

按照题意，将第12个字符所对应的数字乘以10，再加上第13个字符所对应的数字，看是否大于60。统计大于60的个数并返回。

+ 时间复杂度$O(len(details))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for (string& d : details) {
            ans += (d[11] - '0') * 10 + (d[12] - '0') > 60;
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def countSeniors(self, details: List[str]) -> int:
        return sum(((ord(d[11]) - ord('0')) * 10 + (ord(d[12]) - ord('0')) > 60) for d in details)
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/10/23/LeetCode%202678.%E8%80%81%E4%BA%BA%E7%9A%84%E6%95%B0%E7%9B%AE/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/133988079](https://letmefly.blog.csdn.net/article/details/133988079)
