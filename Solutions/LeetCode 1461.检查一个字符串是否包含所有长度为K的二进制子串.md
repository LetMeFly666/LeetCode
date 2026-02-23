---
title: 1461.检查一个字符串是否包含所有长度为 K 的二进制子串：哈希表存放所有长度为k的子串
date: 2026-02-23 11:39:33
tags: [题解, LeetCode, 中等, 位运算, 哈希表, 字符串, 暴力, 枚举]
categories: [题解, LeetCode]
---

# 【LetMeFly】1461.检查一个字符串是否包含所有长度为 K 的二进制子串：哈希表存放所有长度为k的子串

力扣题目链接：[https://leetcode.cn/problems/check-if-a-string-contains-all-binary-codes-of-size-k/](https://leetcode.cn/problems/check-if-a-string-contains-all-binary-codes-of-size-k/)

<p>给你一个二进制字符串&nbsp;<code>s</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;。如果所有长度为 <code>k</code>&nbsp;的二进制字符串都是 <code>s</code>&nbsp;的子串，请返回 <code>true</code> ，否则请返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "00110110", k = 2
<strong>输出：</strong>true
<strong>解释：</strong>长度为 2 的二进制串包括 "00"，"01"，"10" 和 "11"。它们分别是 s 中下标为 0，1，3，2 开始的长度为 2 的子串。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "0110", k = 1
<strong>输出：</strong>true
<strong>解释：</strong>长度为 1 的二进制串包括 "0" 和 "1"，显然它们都是 s 的子串。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "0110", k = 2
<strong>输出：</strong>false
<strong>解释：</strong>长度为 2 的二进制串 "00" 没有出现在 s 中。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10<sup>5</sup></code></li>
	<li><code>s[i]</code> 不是<code>'0'</code> 就是 <code>'1'</code></li>
	<li><code>1 &lt;= k &lt;= 20</code></li>
</ul>


    
## 解题方法：暴力枚举

使用一个哈希表，存放所有长度为$k$的子串。

最后看看哈希表中子串数量是否等于$2^k$。

+ 时间复杂度$O((len(s) - k)\times k)$
+ 空间复杂度$O((len(s) - k)\times k)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-02-23 11:37:10
 */
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> ma;
        for (int i = 0, to = s.size() - k + 1; i < to; i++) {
            ma.insert(s.substr(i, k));
        }
        return ma.size() == (1 << k);
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/158315342)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/02/23/LeetCode%201461.%E6%A3%80%E6%9F%A5%E4%B8%80%E4%B8%AA%E5%AD%97%E7%AC%A6%E4%B8%B2%E6%98%AF%E5%90%A6%E5%8C%85%E5%90%AB%E6%89%80%E6%9C%89%E9%95%BF%E5%BA%A6%E4%B8%BAK%E7%9A%84%E4%BA%8C%E8%BF%9B%E5%88%B6%E5%AD%90%E4%B8%B2/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
