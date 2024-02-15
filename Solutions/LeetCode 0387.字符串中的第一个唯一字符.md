---
title: 387.字符串中的第一个唯一字符
date: 2022-10-11 13:56:11
tags: [题解, LeetCode, 简单, 队列, 哈希表, 字符串, 计数]
---

# 【LetMeFly】387.字符串中的第一个唯一字符

力扣题目链接：[https://leetcode.cn/problems/first-unique-character-in-a-string/](https://leetcode.cn/problems/first-unique-character-in-a-string/)

<p>给定一个字符串&nbsp;<code>s</code>&nbsp;，找到 <em>它的第一个不重复的字符，并返回它的索引</em> 。如果不存在，则返回 <code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> s = "leetcode"
<strong>输出:</strong> 0
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> s = "loveleetcode"
<strong>输出:</strong> 2
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> s = "aabb"
<strong>输出:</strong> -1
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code>&nbsp;只包含小写字母</li>
</ul>


    
## 方法一：计数

首先遍历一遍字符串，然后把每个字母的出现次数计算出来。

之后再遍历一遍字符串。遍历过程中，如果遇到了一个值出现过一次的字母，就返回这个字母的下标。

否则（第二次遍历完也没有发现只出现了一次的字母）就返回```-1```。

+ 时间复杂度$O(n)$，其中$n$是字符串长度
+ 空间复杂度$O(C)$，其中$C$是字符集大小。本题中字符集为26个小写英文字母，$C=26$

### AC代码

#### C++

```cpp
class Solution {
public:
    int firstUniqChar(string& s) {
        int cnt[26] = {0};
        for (char& c : s)
            cnt[c - 'a']++;
        for (int i = 0; i < s.size(); i++) {
            if (cnt[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/10/11/LeetCode%200387.%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E7%9A%84%E7%AC%AC%E4%B8%80%E4%B8%AA%E5%94%AF%E4%B8%80%E5%AD%97%E7%AC%A6/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127262237](https://letmefly.blog.csdn.net/article/details/127262237)
