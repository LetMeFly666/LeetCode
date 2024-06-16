---
title: 521.最长特殊序列 Ⅰ
date: 2024-06-16 18:23:30
tags: [题解, LeetCode, 简单, 字符串, 脑筋急转弯]
---

# 【LetMeFly】521.最长特殊序列 Ⅰ：脑筋急转弯

力扣题目链接：[https://leetcode.cn/problems/longest-uncommon-subsequence-i/](https://leetcode.cn/problems/longest-uncommon-subsequence-i/)

<p>给你两个字符串&nbsp;<code>a</code>&nbsp;和&nbsp;<code>b</code>，请返回 <em>这两个字符串中 <strong>最长的特殊序列</strong>&nbsp;</em> 的长度。如果不存在，则返回 <code>-1</code>&nbsp;。</p>

<p><strong>「最长特殊序列」</strong>&nbsp;定义如下：该序列为&nbsp;<strong>某字符串独有的最长<span data-keyword="subsequence-array">子序列</span>（即不能是其他字符串的子序列）</strong>&nbsp;。</p>

<p>字符串&nbsp;<code>s</code>&nbsp;的子序列是在从&nbsp;<code>s</code>&nbsp;中删除任意数量的字符后可以获得的字符串。</p>

<ul>
	<li>例如，<code>"abc"</code> 是 <code>"aebdc"</code> 的子序列，因为删除 <code>"a<em><strong>e</strong></em>b<strong><em>d</em></strong>c"</code> 中斜体加粗的字符可以得到 <code>"abc"</code> 。 <code>"aebdc"</code> 的子序列还包括 <code>"aebdc"</code> 、 <code>"aeb"</code> 和 <code>""</code> (空字符串)。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> a = "aba", b = "cdc"
<strong>输出:</strong> 3
<strong>解释:</strong> 最长特殊序列可为 "aba" (或 "cdc")，两者均为自身的子序列且不是对方的子序列。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>a = "aaa", b = "bbb"
<strong>输出：</strong>3
<strong>解释:</strong> 最长特殊序列是 "aaa" 和 "bbb" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>a = "aaa", b = "aaa"
<strong>输出：</strong>-1
<strong>解释:</strong> 字符串 a 的每个子序列也是字符串 b 的每个子序列。同样，字符串 b 的每个子序列也是字符串 a 的子序列。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= a.length, b.length &lt;= 100</code></li>
	<li><code>a</code>&nbsp;和&nbsp;<code>b</code>&nbsp;由小写英文字母组成</li>
</ul>


    
## 解题方法：比较

首先，如果两字符串相同，则a的子序列必定也是b的子序列，不存在“独有子序列”，返回-1。

否则，长度较长的字符串一定不是另一个字符串的子序列，返回长度较长的字符串的长度。

+ 时间复杂度$O(len(a)+len(b))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int findLUSlength(string a, string b) {
        return a == b ? -1 : max(a.size(), b.size());
    }
};
```

#### Go

```go
// package main

func findLUSlength(a string, b string) int {
    if a == b {
        return -1
    } else {
        if len(a) > len(b) {
            return len(a)
        } else {
            return len(b)
        }
    }
}
```

#### Java

```java
class Solution {
    public int findLUSlength(String a, String b) {
        return a.equals(b) ? -1 : Math.max(a.length(), b.length());
    }
}
```

#### Python

```python
class Solution:
    def findLUSlength(self, a: str, b: str) -> int:
        return max(len(a), len(b)) if a != b else -1
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/06/16/LeetCode%200521.%E6%9C%80%E9%95%BF%E7%89%B9%E6%AE%8A%E5%BA%8F%E5%88%97%E2%85%A0/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/139724152](https://letmefly.blog.csdn.net/article/details/139724152)
