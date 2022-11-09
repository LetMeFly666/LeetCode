---
title: 1624.两个相同字符之间的最长子字符串
date: 2022-09-17 08:38:54
tags: [题解, LeetCode, 简单, 哈希表, 字符串]
---

# 【LetMeFly】1624.两个相同字符之间的最长子字符串

力扣题目链接：[https://leetcode.cn/problems/largest-substring-between-two-equal-characters/](https://leetcode.cn/problems/largest-substring-between-two-equal-characters/)

<p>给你一个字符串 <code>s</code>，请你返回 <strong>两个相同字符之间的最长子字符串的长度</strong> <em>，</em>计算长度时不含这两个字符。如果不存在这样的子字符串，返回 <code>-1</code> 。</p>

<p><strong>子字符串</strong> 是字符串中的一个连续字符序列。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "aa"
<strong>输出：</strong>0
<strong>解释：</strong>最优的子字符串是两个 'a' 之间的空子字符串。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "abca"
<strong>输出：</strong>2
<strong>解释：</strong>最优的子字符串是 "bc" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "cbzxy"
<strong>输出：</strong>-1
<strong>解释：</strong>s 中不存在出现出现两次的字符，所以返回 -1 。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>s = "cabbac"
<strong>输出：</strong>4
<strong>解释：</strong>最优的子字符串是 "abba" ，其他的非最优解包括 "bb" 和 "" 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 300</code></li>
	<li><code>s</code> 只含小写英文字母</li>
</ul>


    
## 方法一：存最大最小

开辟两个大小为26的数组，分别存放二十六个字母第一次出现、最后一次出现的位置。

一次遍历字符串，更新最大最小位置。

再遍历一次26个字母，对出现过的字母（出现位置不是开辟数组时设置的不在范围内的初始值），计算第一次出现位置和最后一次出现位置的间距。

+ 时间复杂度$O(n + C)$，其中$n$是字符串长度，$C$是字符集大小。本题中$C=26$
+ 空间复杂度$O(C)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string& s) {
        int n = s.size();
        vector<int> firstLoc(26, n);
        vector<int> lastLoc(26, -1);
        for (int i = 0; i < n; i++) {
            int th = s[i] - 'a';
            firstLoc[th] = min(firstLoc[th], i);
            lastLoc[th] = max(lastLoc[th], i);
        }
        int ans = -1;
        for (int i = 0; i < 26; i++) {
            if (firstLoc[i] != n) {
                ans = max(ans, lastLoc[i] - firstLoc[i] - 1);
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/09/17/LeetCode%201624.%E4%B8%A4%E4%B8%AA%E7%9B%B8%E5%90%8C%E5%AD%97%E7%AC%A6%E4%B9%8B%E9%97%B4%E7%9A%84%E6%9C%80%E9%95%BF%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126900794](https://letmefly.blog.csdn.net/article/details/126900794)
