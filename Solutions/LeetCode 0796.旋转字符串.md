---
title: 796.旋转字符串：暴力模拟
date: 2026-05-03 17:24:15
tags: [题解, LeetCode, 简单, 字符串, 字符串匹配, 暴力, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】796.旋转字符串：暴力模拟

力扣题目链接：[https://leetcode.cn/problems/rotate-string/](https://leetcode.cn/problems/rotate-string/)

<p>给定两个字符串, <code>s</code>&nbsp;和&nbsp;<code>goal</code>。如果在若干次旋转操作之后，<code>s</code>&nbsp;能变成&nbsp;<code>goal</code>&nbsp;，那么返回&nbsp;<code>true</code>&nbsp;。</p>

<p><code>s</code>&nbsp;的 <strong>旋转操作</strong> 就是将&nbsp;<code>s</code> 最左边的字符移动到最右边。&nbsp;</p>

<ul>
	<li>例如, 若&nbsp;<code>s = 'abcde'</code>，在旋转一次之后结果就是<code>'bcdea'</code>&nbsp;。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> s = "abcde", goal = "cdeab"
<strong>输出:</strong> true
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> s = "abcde", goal = "abced"
<strong>输出:</strong> false
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= s.length, goal.length &lt;= 100</code></li>
	<li><code>s</code>&nbsp;和&nbsp;<code>goal</code>&nbsp;由小写英文字母组成</li>
</ul>


    
## 解题方法：暴力模拟

如果两个字符串不等长，则直接返回`false`。否则(就不需要担心下标越界的问题了)假设字符串长度为$n$：

共计进行$n$次匹配，使用一个变量$diff$从$0$到$n-1$枚举，若存在某个$diff$可以使得$s[(i+diff)\mod n]$和$goal[i]$全部相等，则返回`true`。

否则返回`false`。

+ 时间复杂度$O(len(s)^2)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-05-03 17:22:50
 */
class Solution {
private:
    int n;

    bool ok(const string& s, const string& goal, int diff) {
        for (int i = 0; i < n; i++) {
            if (s[(i + diff) % n] != goal[i]) {
                return false;
            }
        }
        return true;
    }
public:
    bool rotateString(const string& s, const string& goal) {
        n = s.size();
        if (goal.size() != n) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (ok(s, goal, i)) {
                return true;
            }
        }
        return false;
    }
};
```

```cpp
/*
 * @LastEditTime: 2022-04-07 08:13:46
 */
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size())
            return false;
        for (int i = 0; i < s.size(); i++) {
            bool same = true;
            for (int j = 0; j < s.size(); j++) {
                if (s[j] != goal[(i + j) % s.size()]) {
                    same = false;
                    break;
                }
            }
            if (same)
                return true;
        }
        return false;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/160743134)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/05/03/LeetCode%200796.%E6%97%8B%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
