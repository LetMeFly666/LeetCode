---
title: 2414.最长的字母序连续子字符串的长度
date: 2024-09-19 17:58:36
tags: [题解, LeetCode, 中等, 字符串]
---

# 【LetMeFly】2414.最长的字母序连续子字符串的长度：一次遍历

力扣题目链接：[https://leetcode.cn/problems/length-of-the-longest-alphabetical-continuous-substring/](https://leetcode.cn/problems/length-of-the-longest-alphabetical-continuous-substring/)

<p><strong>字母序连续字符串</strong> 是由字母表中连续字母组成的字符串。换句话说，字符串 <code>"abcdefghijklmnopqrstuvwxyz"</code> 的任意子字符串都是 <strong>字母序连续字符串</strong> 。</p>

<ul>
	<li>例如，<code>"abc"</code> 是一个字母序连续字符串，而 <code>"acb"</code> 和 <code>"za"</code> 不是。</li>
</ul>

<p>给你一个仅由小写英文字母组成的字符串 <code>s</code> ，返回其 <strong>最长</strong> 的 字母序连续子字符串 的长度。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "abacaba"
<strong>输出：</strong>2
<strong>解释：</strong>共有 4 个不同的字母序连续子字符串 "a"、"b"、"c" 和 "ab" 。
"ab" 是最长的字母序连续子字符串。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "abcde"
<strong>输出：</strong>5
<strong>解释：</strong>"abcde" 是最长的字母序连续子字符串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> 由小写英文字母组成</li>
</ul>


    
## 解题方法：一次遍历

使用一个变量nowCnt记录当前“连续字符串”的长度，使用一个变量ans记录最终答案。

从第二个元素开始遍历字符串，若当前元素是上一个元素的“下一个字母”，则nowCnt加一，更新ans；否则将nowCnt重制为1。

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = 1, nowCnt = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1] + 1) {
                nowCnt++;
                ans = max(ans, nowCnt);
            }
            else {
                nowCnt = 1;
            }
        }
        return ans;
    }
};
```

#### Go

```go
package main

func longestContinuousSubstring(s string) int {
    ans, nowCnt := 1, 1
    for i := 1; i < len(s); i++ {
        if s[i] == s[i - 1] + 1 {
            nowCnt++
            if nowCnt > ans {
                ans = nowCnt
            }
        } else {
            nowCnt = 1
        }
    }
    return ans
}
```

#### Java

```java
class Solution {
    public int longestContinuousSubstring(String s) {
        int ans = 1, nowCnt = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == s.charAt(i - 1) + 1) {
                nowCnt++;
                ans = Math.max(ans, nowCnt);
            }
            else {
                nowCnt = 1;
            }
        }
        return ans;
    }
}
```

#### Python

```python
class Solution:
    def longestContinuousSubstring(self, s: str) -> int:
        nowCnt, ans = 1, 1
        for i in range(1, len(s)):
            if ord(s[i]) == ord(s[i - 1]) + 1:
                nowCnt += 1
                ans = max(ans, nowCnt)
            else:
                nowCnt = 1
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/09/19/LeetCode%202414.%E6%9C%80%E9%95%BF%E7%9A%84%E5%AD%97%E6%AF%8D%E5%BA%8F%E8%BF%9E%E7%BB%AD%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9A%84%E9%95%BF%E5%BA%A6/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/142366701](https://letmefly.blog.csdn.net/article/details/142366701)
