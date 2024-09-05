---
title: 3174.清除数字
date: 2024-09-05 19:46:13
tags: [题解, LeetCode, 简单, 栈, 字符串, 模拟]
---

# 【LetMeFly】3174.清除数字：一个不用栈的方法

力扣题目链接：[https://leetcode.cn/problems/clear-digits/](https://leetcode.cn/problems/clear-digits/)

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;。</p>

<p>你的任务是重复以下操作删除 <strong>所有</strong>&nbsp;数字字符：</p>

<ul>
	<li>删除 <strong>第一个数字字符</strong>&nbsp;以及它左边 <strong>最近</strong>&nbsp;的 <strong>非数字</strong>&nbsp;字符。</li>
</ul>

<p>请你返回删除所有数字字符以后剩下的字符串。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "abc"</span></p>

<p><span class="example-io"><b>输出：</b>"abc"</span></p>

<p><strong>解释：</strong></p>

<p>字符串中没有数字。<!-- notionvc: ff07e34f-b1d6-41fb-9f83-5d0ba3c1ecde --></p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "cb34"</span></p>

<p><span class="example-io"><b>输出：</b>""</span></p>

<p><b>解释：</b></p>

<p>一开始，我们对&nbsp;<code>s[2]</code>&nbsp;执行操作，<code>s</code>&nbsp;变为&nbsp;<code>"c4"</code>&nbsp;。</p>

<p>然后对&nbsp;<code>s[1]</code>&nbsp;执行操作，<code>s</code>&nbsp;变为&nbsp;<code>""</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母和数字字符。</li>
	<li>输入保证所有数字都可以按以上操作被删除。</li>
</ul>


    
## 解题方法：计数 + 字符串翻转

一个数字可以抵消一个字母，因此使用一个整数$cntDigit$统计数字的个数。

倒着遍历字符串，遇到一个数字$cntDigit$就加一，遇到一个字符就尝试用数字抵消（如果$cntDigit$大于$0$则直接$cntDigit$减一，否则抵消不了，这个字符就需要加到字符串上）。

将字符串reverse，返回即可。

+ 时间复杂度$O(len(s))$
+ 空间复杂度：对于可变长字符串的编程语言：$O(1)$，因为力扣返回值不计入算法空间复杂度；对于不可变长字符串的编程语言：$O(len(s))$，可以开辟一个列表用来存放每一个字符串。

### AC代码

#### C++

```cpp
class Solution {
public:
    string clearDigits(string s) {
        string ans;
        int cntDigit = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (isdigit(s[i])) {
                cntDigit++;
            }
            else if (cntDigit) {
                cntDigit--;
            }
            else {
                ans += s[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

#### Go

```go
package main
import "unicode"

func clearDigits(s string) string {
    ansList := []rune{}
    cntDigit := 0
    for i := len(s) - 1; i >= 0; i-- {
        if unicode.IsDigit(rune(s[i])) {
            cntDigit++
        } else if cntDigit > 0 {
            cntDigit--
        } else {
            ansList = append(ansList, rune(s[i]))
        }
    }
    for i := 0; i < len(ansList) / 2; i++ {
        ansList[i], ansList[len(ansList) - i - 1] = ansList[len(ansList) - i - 1], ansList[i]
    }
    return string(ansList)
}
```

#### Java

```java
class Solution {
    public String clearDigits(String s) {
        StringBuilder ans = new StringBuilder();
        int cntDigit = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (Character.isDigit(s.charAt(i))) {
                cntDigit++;
            }
            else if (cntDigit > 0) {
                cntDigit--;
            }
            else {
                ans.append(s.charAt(i));
            }
        }
        ans.reverse();
        return ans.toString();
    }
}
```

#### Python

```python
class Solution:
    def clearDigits(self, s: str) -> str:
        ans = []
        cntDigit = 0
        for i in range(len(s) - 1, -1, -1):
            if s[i].isdigit():
                cntDigit += 1
            elif cntDigit:
                cntDigit -= 1
            else:
                ans.append(s[i])
        return ''.join(reversed(ans))
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/09/05/LeetCode%203174.%E6%B8%85%E9%99%A4%E6%95%B0%E5%AD%97/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/141943628](https://letmefly.blog.csdn.net/article/details/141943628)
