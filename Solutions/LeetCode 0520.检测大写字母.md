---
title: 520.检测大写字母
date: 2024-06-23 19:09:56
tags: [题解, LeetCode, 简单, 字符串, 计数]
categories: [题解, LeetCode]
---

# 【LetMeFly】520.检测大写字母：计数

力扣题目链接：[https://leetcode.cn/problems/detect-capital/](https://leetcode.cn/problems/detect-capital/)

<p>我们定义，在以下情况时，单词的大写用法是正确的：</p>

<ul>
	<li>全部字母都是大写，比如 <code>"USA"</code> 。</li>
	<li>单词中所有字母都不是大写，比如 <code>"leetcode"</code> 。</li>
	<li>如果单词不只含有一个字母，只有首字母大写，&nbsp;比如&nbsp;<code>"Google"</code> 。</li>
</ul>

<p>给你一个字符串 <code>word</code> 。如果大写用法正确，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>word = "USA"
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>word = "FlaG"
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 100</code></li>
	<li><code>word</code> 由小写和大写英文字母组成</li>
</ul>


    
## 解题方法：计数

我是按这个角度思考的：

> 单词正确有两种情况：
>
> > 1. 除首字母外所有字符都是小写
> > 2. 除首字母外所有字符都是大写 并且 首字母也是大写

因此可以统计从第二个字母开始有多少个小写字母，记为cntLower：

> 1. 上述第一种情况对应：cntLower为len(word) - 1
> 2. 上述第一种情况对应：cntLower为0 且 首字母为大写

+ 时间复杂度$O(len(word))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool detectCapitalUse(string& word) {
        bool small = true, big = true;
        for (int i = 1; i < word.size(); i++) {
            if (islower(word[i])) {
                big = false;
            }
            else {
                small = false;
            }
        }
        return small || (big && isupper(word[0]));
    }
};
```

#### Go

```go
// package main

// import "unicode"

func detectCapitalUse(word string) bool {
    cntLower := 0
    for i := 1; i < len(word); i++ {
        if unicode.IsLower(rune(word[i])) {
            cntLower++
        }
    }
    return cntLower == len(word) - 1 || cntLower == 0 && unicode.IsUpper(rune(word[0]))
}
```

#### Java

```java
class Solution {
    public boolean detectCapitalUse(String word) {
        int cntLower = 0;
        for (int i = 1; i < word.length(); i++) {
            if (Character.isLowerCase(word.charAt(i))) {
                cntLower++;
            }
        }
        return cntLower == word.length() - 1 || (cntLower == 0 && Character.isUpperCase(word.charAt(0)));
    }
}
```

#### Python

```python
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        cntLower = sum(word[i].islower() for i in range(1, len(word)))
        return cntLower == len(word) - 1 or cntLower == 0 and word[0].isupper()
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/06/23/LeetCode%200520.%E6%A3%80%E6%B5%8B%E5%A4%A7%E5%86%99%E5%AD%97%E6%AF%8D/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/139904679](https://letmefly.blog.csdn.net/article/details/139904679)
