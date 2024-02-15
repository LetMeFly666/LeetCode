---
title: 1684.统计一致字符串的数目
date: 2022-11-08 08:58:41
tags: [题解, LeetCode, 简单, 位运算, 数组, 哈希表, 字符串, 遍历]
---

# 【LetMeFly】1684.统计一致字符串的数目

力扣题目链接：[https://leetcode.cn/problems/count-the-number-of-consistent-strings/](https://leetcode.cn/problems/count-the-number-of-consistent-strings/)

<p>给你一个由不同字符组成的字符串 <code>allowed</code> 和一个字符串数组 <code>words</code> 。如果一个字符串的每一个字符都在 <code>allowed</code> 中，就称这个字符串是 <strong>一致字符串 </strong>。</p>

<p>请你返回 <code>words</code> 数组中 <strong>一致字符串</strong> 的数目。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
<b>输出：</b>2
<b>解释：</b>字符串 "aaab" 和 "baa" 都是一致字符串，因为它们只包含字符 'a' 和 'b' 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
<b>输出：</b>7
<b>解释：</b>所有字符串都是一致的。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
<b>输出：</b>4
<b>解释：</b>字符串 "cc"，"acd"，"ac" 和 "d" 是一致字符串。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= words.length <= 10<sup>4</sup></code></li>
	<li><code>1 <= allowed.length <=<sup> </sup>26</code></li>
	<li><code>1 <= words[i].length <= 10</code></li>
	<li><code>allowed</code> 中的字符 <strong>互不相同</strong> 。</li>
	<li><code>words[i]</code> 和 <code>allowed</code> 只包含小写英文字母。</li>
</ul>


    
## 方法一：遍历

因为字符集为26个小写英文字母，因此我们开辟大小为$26$的数组，来记录每个字母是否在$allowed$中出现过

```cpp
bool bin[26] = {false};
```

之后遍历一遍$allowed$，将出现过的字母标记为$true$

```cpp
for (char& c : allowed)
	bin[c - 'a'] = true;
```

接下来就能愉快地处理每一个字符串了

对于字符串数组中的某一个字符串，使用一个变量$ok = true$来记录字符串是否有“不能出现的字符”

遍历字符串，如果某个字符没有在$allowed$中出现过（$bin$为$false$），那么就将$ok$置为$false$并结束遍历这个字符串

若字符串遍历结束$ok$仍为$true$，那么答案数量就加一

```cpp
int ans = 0;
for (string& s : words) {  // 遍历字符串数组中的每一个字符串s
    bool ok = true;
    for (char& c : s) {
        if (!bin[c - 'a']) {  // 未在allowed中出现过的字符出现过
            ok = false;
            break;
        }
    }
    ans += ok;
}
```

+ 时间复杂度$O(len(allowed) + N)$，其中$N$是$words$中所有字符的个数
+ 空间复杂度$O(C)$，其中$C$是字符集大小，这里为26个小写英文字母$C=26$

### AC代码

#### C++

```cpp
class Solution {
public:
    int countConsistentStrings(string& allowed, vector<string>& words) {
        bool bin[26] = {false};
        for (char& c : allowed)
            bin[c - 'a'] = true;
        int ans = 0;
        for (string& s : words) {
            bool ok = true;
            for (char& c : s) {
                if (!bin[c - 'a']) {
                    ok = false;
                    break;
                }
            }
            ans += ok;
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/11/08/LeetCode%201684.%E7%BB%9F%E8%AE%A1%E4%B8%80%E8%87%B4%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9A%84%E6%95%B0%E7%9B%AE/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127743936](https://letmefly.blog.csdn.net/article/details/127743936)
