---
title: 828.统计子串中的唯一字符
date: 2022-09-06 10:46:54
tags: [题解, LeetCode, 困难, 哈希表, 字符串, 动态规划, 存下标]
---

# 【LetMeFly】828.统计子串中的唯一字符

力扣题目链接：[https://leetcode.cn/problems/count-unique-characters-of-all-substrings-of-a-given-string/](https://leetcode.cn/problems/count-unique-characters-of-all-substrings-of-a-given-string/)

<p>我们定义了一个函数 <code>countUniqueChars(s)</code> 来统计字符串 <code>s</code> 中的唯一字符，并返回唯一字符的个数。</p>

<p>例如：<code>s = "LEETCODE"</code> ，则其中 <code>"L"</code>, <code>"T"</code>,<code>"C"</code>,<code>"O"</code>,<code>"D"</code> 都是唯一字符，因为它们只出现一次，所以 <code>countUniqueChars(s) = 5</code> 。</p>

<p>本题将会给你一个字符串 <code>s</code> ，我们需要返回 <code>countUniqueChars(t)</code> 的总和，其中 <code>t</code> 是 <code>s</code> 的子字符串。注意，某些子字符串可能是重复的，但你统计时也必须算上这些重复的子字符串（也就是说，你必须统计 <code>s</code> 的所有子字符串中的唯一字符）。</p>

<p>由于答案可能非常大，请将结果 <strong>mod 10 ^ 9 + 7</strong> 后再返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入: </strong>s = "ABC"
<strong>输出: </strong>10
<strong>解释:</strong> 所有可能的子串为："A","B","C","AB","BC" 和 "ABC"。
     其中，每一个子串都由独特字符构成。
     所以其长度总和为：1 + 1 + 1 + 2 + 2 + 3 = 10
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入: </strong>s = "ABA"
<strong>输出: </strong>8
<strong>解释: </strong>除<code>了 countUniqueChars</code>("ABA") = 1 之外，其余与示例 1 相同。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "LEETCODE"
<strong>输出：</strong>92
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= s.length &lt;= 10^5</code></li>
	<li><code>s</code> 只包含大写英文字符</li>
</ul>


    
## 方法一：存下标

每个字符之间互不影响，因此我们分别统计每个字母即可。

对于某个字母，要找到包含这个字母一次有且仅有一次的字符串，可以从某个“这个字母出现的位置”开始，左边选数个字母（不包含这个字母）、右边选数个字母。

因此，如果字母$X$的三个相邻的出现位置分别是$i$、$j$和$k$，那么包含$s[j]$一次的字符串种类有$(j-i)\times(k-j)$个。

因此，预处理一遍，统计每个字母出现的位置，再进行上述运算即可。

+ 时间复杂度$O(n)$，其中$n$是字符串长度
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int uniqueLetterString(string& s) {
        int n = s.size();
        vector<int> location[26];
        for (int i = 0; i < 26; i++) {
            location[i].push_back(-1);
        }
        for (int i = 0; i < n; i++) {
            location[s[i] - 'A'].push_back(i);
        }
        for (int i = 0; i < 26; i++) {
            location[i].push_back(n);
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (location[i].size() == 2)
                continue;
            for (int j = 1; j + 1 < location[i].size(); j++) {
                ans += (location[i][j] - location[i][j - 1]) * (location[i][j + 1] - location[i][j]);
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/09/06/LeetCode%200828.%E7%BB%9F%E8%AE%A1%E5%AD%90%E4%B8%B2%E4%B8%AD%E7%9A%84%E5%94%AF%E4%B8%80%E5%AD%97%E7%AC%A6/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126722643](https://letmefly.blog.csdn.net/article/details/126722643)
