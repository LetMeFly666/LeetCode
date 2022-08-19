---
title: 205.同构字符串
date: 2022-08-19 09:01:38
tags: [题解, LeetCode, 简单, 哈希表, 字符串, 哈希]
---

# 【LetMeFly】205.同构字符串

力扣题目链接：[https://leetcode.cn/problems/isomorphic-strings/](https://leetcode.cn/problems/isomorphic-strings/)

<p>给定两个字符串&nbsp;<code>s</code>&nbsp;和&nbsp;<code>t</code>&nbsp;，判断它们是否是同构的。</p>

<p>如果&nbsp;<code>s</code>&nbsp;中的字符可以按某种映射关系替换得到&nbsp;<code>t</code>&nbsp;，那么这两个字符串是同构的。</p>

<p>每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>s = <code>"egg", </code>t = <code>"add"</code>
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = <code>"foo", </code>t = <code>"bar"</code>
<strong>输出：</strong>false</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = <code>"paper", </code>t = <code>"title"</code>
<strong>输出：</strong>true</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<p><meta charset="UTF-8" /></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>t.length == s.length</code></li>
	<li><code>s</code>&nbsp;和&nbsp;<code>t</code>&nbsp;由任意有效的 ASCII 字符组成</li>
</ul>


    
## 方法一：哈希

使用两个哈希表：

+ 一个用来映射，记录```s```中的某个字符要映射为```t```的哪个字符。
+ 一个用来记录，记录```t```中的某个字符是否被映射过。

遍历一遍原始字符串，如果```s```中的当前字符已经被映射过了，就看```t```中当前字符是否和```s```上次映射的字符相同。如果不同就返回```false```。

反之，如果```s```中出现了一个还没有被映射过的字符，那么就判断```t```中对应的字符是否已经被映射过。如果已经被别的字母映射过，那么就返回```false```，否则就建立映射。

遍历结束，返回```true```。

+ 时间复杂度$O(n)$，其中$n$是单个字符串的长度
+ 空间复杂度$O(C)$，其中$C$是字符集的大小（本题为26）

### AC代码

#### C++

```cpp
class Solution {
public:
    bool isIsomorphic(string& s, string& t) {
        unordered_map<char, char> ma;  // 映射
        unordered_set<char> se;  // 出现过
        for (int i = t.size() - 1; i >= 0; i--) {  // 遍历
            if (ma.count(s[i])) {  // s[i]已经映射过
                if (ma[s[i]] != t[i])  // 看t[i]是否和上次映射的字符相同
                    return false;  // 不同就返回false
            }
            else {  // s[i]还没建立过映射
                if (se.count(t[i]))  // 如果t[i]已经被映射过了
                    return false;
                se.insert(t[i]);  // 建立映射
                ma[s[i]] = t[i];
            }
        }
        return true;
    }
};
```

总体效果还可以：

<!-- ![result.jpg](https://pic.leetcode-cn.com/1660871526-JCjlBn-result.jpg) -->

![result](https://img-blog.csdnimg.cn/44b49e5b43474538b10cb20c8df5b881.jpeg#pic_center)

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/08/19/LeetCode%200205.%E5%90%8C%E6%9E%84%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126417676](https://letmefly.blog.csdn.net/article/details/126417676)
