---
title: 678.有效的括号字符串：O(n)+O(1)一次遍历
date: 2026-10-04 18:00:22
tags: [题解, LeetCode, 中等, 栈, 贪心, 字符串, 动态规划, 括号匹配, 字符串构造]
categories: [题解, LeetCode]
---

# 【LetMeFly】678.有效的括号字符串：O(n)+O(1)一次遍历

力扣题目链接：[https://leetcode.cn/problems/valid-parenthesis-string/](https://leetcode.cn/problems/valid-parenthesis-string/)

<p>给你一个只包含三种字符的字符串，支持的字符类型分别是 <code>'('</code>、<code>')'</code> 和 <code>'*'</code>。请你检验这个字符串是否为有效字符串，如果是 <strong>有效</strong> 字符串返回 <code>true</code> 。</p>

<p><strong>有效</strong> 字符串符合如下规则：</p>

<ul>
	<li>任何左括号 <code>'('</code>&nbsp;必须有相应的右括号 <code>')'</code>。</li>
	<li>任何右括号 <code>')'</code>&nbsp;必须有相应的左括号 <code>'('</code>&nbsp;。</li>
	<li>左括号 <code>'('</code> 必须在对应的右括号之前 <code>')'</code>。</li>
	<li><code>'*'</code>&nbsp;可以被视为单个右括号 <code>')'</code>&nbsp;，或单个左括号 <code>'('</code>&nbsp;，或一个空字符串 <code>""</code>。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "()"
<strong>输出：</strong>true
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "(*)"
<strong>输出：</strong>true
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "(*))"
<strong>输出：</strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s[i]</code> 为 <code>'('</code>、<code>')'</code> 或 <code>'*'</code></li>
</ul>


    
## 解题方法：一次遍历

使用两个变量`mx`和`mn`分别表示遍历到当前字符为止，左括号比右括号最多多几个、最少多几个。

+ 遇到`(`则左括号必须比右括号多一个（`mx++, mn++`）
+ 遇到`)`则左括号必须比右括号少一个（`mx--, mn--`）
+ 遇到`*`时候`*`可以变成左括号（`mx++`），可以变成右括号（`mn--`），也可以变成空字符

一旦左括号比右括号最多多负数个（说明不论怎样左括号都比右括号少了）则立刻返回`false`；如果`mn == 0`则不再将`mn - 1`，因为要保证左括号始终`≥`右括号，二者数量相等的时候`*`不能变成`)`。

最终，如果`mn == 0`则说明左括号比右括号最少多0个，说明可以通过将`*`变成`)`来使得左右括号数量相等。

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-10-04 17:59:19
 */
class Solution {
public:
    bool checkValidString(const string& s) {
        int mx = 0, mn = 0;
        for (char c : s) {
            if (c == '(') {
                mx++, mn++;
            } else if (c == ')') {
                mx--, mn--;
                if (mx < 0) {
                    return false;
                }
            } else {
                mx++, mn--;
            }
            mn = max(mn, 0);
        }
        return !mn;
    }
};
```

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/167083377)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/10/04/LeetCode%200678.%E6%9C%89%E6%95%88%E7%9A%84%E6%8B%AC%E5%8F%B7%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
