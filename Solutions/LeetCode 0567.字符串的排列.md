---
title: 567.字符串的排列
date: 2023-03-18 14:36:14
tags: [题解, LeetCode, 中等, 哈希表, 双指针, 字符串, 滑动窗口, 子串, 排列]
---

# 【LetMeFly】567.字符串的排列

力扣题目链接：[https://leetcode.cn/problems/permutation-in-string/](https://leetcode.cn/problems/permutation-in-string/)

<p>给你两个字符串&nbsp;<code>s1</code>&nbsp;和&nbsp;<code>s2</code> ，写一个函数来判断 <code>s2</code> 是否包含 <code>s1</code><strong>&nbsp;</strong>的排列。如果是，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>换句话说，<code>s1</code> 的排列之一是 <code>s2</code> 的 <strong>子串</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s1 = "ab" s2 = "eidbaooo"
<strong>输出：</strong>true
<strong>解释：</strong>s2 包含 s1 的排列之一 ("ba").
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s1= "ab" s2 = "eidboaoo"
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s1.length, s2.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s1</code> 和 <code>s2</code> 仅包含小写字母</li>
</ul>


    
## 方法一：滑动窗口 / 双指针

题目问的是“s1的排列之一是否为s2的子串”，因此s1中字符出现的顺序不重要。

我们只需要统计$s1$中每个字母分别出现了几次，然后在s2中，判断是否存在**相同长度**的字符串，其中字母的出现次数和s1完全相同。

因此，首先统计s2中前len(s1)个字母是什么，接着不断加上这个区间后面的字符，减去这个区间前面的字符。中途遇到两字符串中字母相同的情况的话，返回true即可

+ 时间复杂度$O((len(s1) + len(s2)) \times C)$，其中$C = 26$
+ 空间复杂度$O(C)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool checkInclusion(string& s1, string& s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        vector<int> cnt1(26), cnt2(26);
        for (char c : s1) {
            cnt1[c - 'a']++;
        }
        for (int i = 0; i < s1.size(); i++) {
            cnt2[s2[i] - 'a']++;
        }
        if (cnt1 == cnt2) {
            return true;
        }
        for (int i = s1.size(); i < s2.size(); i++) {
            cnt2[s2[i] - 'a']++;
            cnt2[s2[i - s1.size()] - 'a']--;
            if (cnt1 == cnt2) {
                return true;
            }
        }
        return false;
    }
};
```

#### Python

```python
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        cnt1 = [0 for _ in range(26)]
        cnt2 = [0 for _ in range(26)]
        for c in s1:
            cnt1[ord(c) - ord('a')] += 1
        for i in range(len(s1)):
            cnt2[ord(s2[i]) - ord('a')] += 1
        if cnt1 == cnt2:
            return True
        for i in range(len(s1), len(s2)):
            cnt2[ord(s2[i]) - ord('a')] += 1
            cnt2[ord(s2[i - len(s1)]) - ord('a')] -= 1
            if cnt1 == cnt2:
                return True
        return False
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/03/18/LeetCode%200567.%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9A%84%E6%8E%92%E5%88%97/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129636871](https://letmefly.blog.csdn.net/article/details/129636871)
