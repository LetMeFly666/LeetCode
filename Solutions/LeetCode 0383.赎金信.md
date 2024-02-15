---
title: 383.赎金信
date: 2024-01-07 12:37:04
tags: [题解, LeetCode, 简单, 哈希表, 字符串, 计数]
---

# 【LetMeFly】383.赎金信：计数

力扣题目链接：[https://leetcode.cn/problems/ransom-note/](https://leetcode.cn/problems/ransom-note/)

<p>给你两个字符串：<code>ransomNote</code> 和 <code>magazine</code> ，判断 <code>ransomNote</code> 能不能由 <code>magazine</code> 里面的字符构成。</p>

<p>如果可以，返回 <code>true</code> ；否则返回 <code>false</code> 。</p>

<p><code>magazine</code> 中的每个字符只能在 <code>ransomNote</code> 中使用一次。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>ransomNote = "a", magazine = "b"
<strong>输出：</strong>false
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>ransomNote = "aa", magazine = "ab"
<strong>输出：</strong>false
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>ransomNote = "aa", magazine = "aab"
<strong>输出：</strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= ransomNote.length, magazine.length &lt;= 10<sup>5</sup></code></li>
	<li><code>ransomNote</code> 和 <code>magazine</code> 由小写英文字母组成</li>
</ul>


    
## 方法一：计数

使用一个大小为$26$的整数数组$cnt$，$cnt[i]$代表第$i$个小写字母的“可用个数”。

遍历字符串$magazine$并将其字符出现次数累加；遍历字符串$ransomNote$并将其字符出现次数“累减”，若无次数可减，则返回```false```。

遍历完未返回```false```，则返回```true```。

+ 时间复杂度$O(len(ransomNote) + len(magazine))$
+ 空间复杂度$O(C)$，其中$C=26$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[26] = {0};
        for (char c : magazine) {
            cnt[c - 'a']++;
        }
        for (char c : ransomNote) {
            if (!cnt[c - 'a']) {
                return false;
            }
            cnt[c - 'a']--;
        }
        return true;
    }
};
```

#### Python

```python
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        cnt = [0] * 26
        for c in magazine:
            cnt[ord(c) - 97] += 1
        for c in ransomNote:
            if not cnt[ord(c) - 97]:
                return False
            cnt[ord(c) - 97] -= 1
        return True
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/01/07/LeetCode%200383.%E8%B5%8E%E9%87%91%E4%BF%A1/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135438384](https://letmefly.blog.csdn.net/article/details/135438384)
