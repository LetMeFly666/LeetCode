---
title: 2697.字典序最小回文串
date: 2023-12-13 09:31:33
tags: [题解, LeetCode, 简单, 双指针, 字符串, 回文, 回文串]
---

# 【LetMeFly】2697.字典序最小回文串

力扣题目链接：[https://leetcode.cn/problems/lexicographically-smallest-palindrome/](https://leetcode.cn/problems/lexicographically-smallest-palindrome/)

<p>给你一个由 <strong>小写英文字母</strong> 组成的字符串 <code>s</code> ，你可以对其执行一些操作。在一步操作中，你可以用其他小写英文字母 <strong>替换</strong>&nbsp; <code>s</code> 中的一个字符。</p>

<p>请你执行 <strong>尽可能少的操作</strong> ，使 <code>s</code> 变成一个 <strong>回文串</strong> 。如果执行 <strong>最少</strong> 操作次数的方案不止一种，则只需选取 <strong>字典序最小</strong> 的方案。</p>

<p>对于两个长度相同的字符串 <code>a</code> 和 <code>b</code> ，在 <code>a</code> 和 <code>b</code> 出现不同的第一个位置，如果该位置上 <code>a</code> 中对应字母比 <code>b</code> 中对应字母在字母表中出现顺序更早，则认为 <code>a</code> 的字典序比 <code>b</code> 的字典序要小。</p>

<p>返回最终的回文字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "egcfe"
<strong>输出：</strong>"efcfe"
<strong>解释：</strong>将 "egcfe" 变成回文字符串的最小操作次数为 1 ，修改 1 次得到的字典序最小回文字符串是 "efcfe"，只需将 'g' 改为 'f' 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abcd"
<strong>输出：</strong>"abba"
<strong>解释：</strong>将 "abcd" 变成回文字符串的最小操作次数为 2 ，修改 2 次得到的字典序最小回文字符串是 "abba" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "seven"
<strong>输出：</strong>"neven"
<strong>解释：</strong>将 "seven" 变成回文字符串的最小操作次数为 1 ，修改 1 次得到的字典序最小回文字符串是 "neven" 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
</ul>


    
## 方法一：模拟

从第一个字符遍历到字符串的中间：

> 如果```这个字符串```与```其对称的字符串```不同，就无脑将这两个字符都变成 这两个中较小的那个。

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(1)$或$O(len(s))$。对于不可变字符串的编程语言，可能需要额外的空间（如数组）来存储字符串的中间形态。

### AC代码

#### C++

```cpp
class Solution {
public:
    string makeSmallestPalindrome(string& s) {
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - i - 1]) {
                s[i] = s[s.size() - i - 1] = min(s[i], s[s.size() - i - 1]);
            }
        }
        return s;
    }
};
```

#### Python

```python
class Solution:
    def makeSmallestPalindrome(self, s: str) -> str:
        li = list(s)
        for i in range(len(s) // 2):
            if s[i] != s[len(s) - i - 1]:
                li[i] = li[len(s) - i - 1] = min(s[i], s[len(s) - i - 1])
        return ''.join(li)
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/12/13/LeetCode%202697.%E5%AD%97%E5%85%B8%E5%BA%8F%E6%9C%80%E5%B0%8F%E5%9B%9E%E6%96%87%E4%B8%B2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/134964337](https://letmefly.blog.csdn.net/article/details/134964337)
