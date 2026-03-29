---
title: 2839.判断通过操作能否让字符串相等 I：if-else（两两判断）
date: 2026-03-29 19:55:01
tags: [题解, LeetCode, 简单, 字符串]
categories: [题解, LeetCode]
---

# 【LetMeFly】2839.判断通过操作能否让字符串相等 I：if-else（两两判断）

力扣题目链接：[https://leetcode.cn/problems/check-if-strings-can-be-made-equal-with-operations-i/](https://leetcode.cn/problems/check-if-strings-can-be-made-equal-with-operations-i/)

<p>给你两个字符串&nbsp;<code>s1</code> 和&nbsp;<code>s2</code>&nbsp;，两个字符串的长度都为&nbsp;<code>4</code>&nbsp;，且只包含 <strong>小写</strong> 英文字母。</p>

<p>你可以对两个字符串中的 <strong>任意一个</strong>&nbsp;执行以下操作 <strong>任意</strong>&nbsp;次：</p>

<ul>
	<li>选择两个下标&nbsp;<code>i</code> 和&nbsp;<code>j</code>&nbsp;且满足&nbsp;<code>j - i = 2</code>&nbsp;，然后 <strong>交换</strong> 这个字符串中两个下标对应的字符。</li>
</ul>

<p>如果你可以让字符串<em>&nbsp;</em><code>s1</code><em> </em>和<em>&nbsp;</em><code>s2</code>&nbsp;相等，那么返回 <code>true</code>&nbsp;，否则返回 <code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>s1 = "abcd", s2 = "cdab"
<b>输出：</b>true
<strong>解释：</strong> 我们可以对 s1 执行以下操作：
- 选择下标 i = 0 ，j = 2 ，得到字符串 s1 = "cbad" 。
- 选择下标 i = 1 ，j = 3 ，得到字符串 s1 = "cdab" = s2 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>s1 = "abcd", s2 = "dacb"
<b>输出：</b>false
<b>解释：</b>无法让两个字符串相等。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>s1.length == s2.length == 4</code></li>
	<li><code>s1</code> 和&nbsp;<code>s2</code>&nbsp;只包含小写英文字母。</li>
</ul>


    
## 解题方法：两两判断

字符串长度固定为$4$，字符$s[i]$只能与字符$s[i+2]$交换，相当于第一个字符只能与第三个字符交换、第二个字符只能与第四个字符交换。

所以判断下两个字符串的第一个和第三个字符是否相等或交换后相等，并且第二第四个字符也相等或交换后相等，就好了。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-03-29 19:41:22
 */
#include <iostream>
class Solution {
private:
    inline bool same2(const string& a, const string& b, int i, int j) {
        return a[i] == b[i] && a[j] == b[j] || a[i] == b[j] && a[j] == b[i];
    }
public:
    bool canBeEqual(const string& s1, const string& s2) {
        return same2(s1, s2, 0, 2) && same2(s1, s2, 1, 3);
    }
};
```

AC,100.00%,100.00%

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/159616700)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/03/29/LeetCode%202839.%E5%88%A4%E6%96%AD%E9%80%9A%E8%BF%87%E6%93%8D%E4%BD%9C%E8%83%BD%E5%90%A6%E8%AE%A9%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9B%B8%E7%AD%89I/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
