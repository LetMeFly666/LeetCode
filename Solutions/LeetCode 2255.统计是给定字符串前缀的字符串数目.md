---
title: 2255.统计是给定字符串前缀的字符串数目：使用库函数+计数
date: 2025-03-24 18:00:44
tags: [题解, LeetCode, 简单, 数组, 字符串, 计数]
categories: [题解, LeetCode]
---

# 【LetMeFly】2255.统计是给定字符串前缀的字符串数目：使用库函数+计数

力扣题目链接：[https://leetcode.cn/problems/count-prefixes-of-a-given-string/](https://leetcode.cn/problems/count-prefixes-of-a-given-string/)

<p>给你一个字符串数组&nbsp;<code>words</code>&nbsp;和一个字符串&nbsp;<code>s</code>&nbsp;，其中&nbsp;<code>words[i]</code> 和&nbsp;<code>s</code>&nbsp;只包含 <strong>小写英文字母</strong>&nbsp;。</p>

<p>请你返回 <code>words</code>&nbsp;中是字符串 <code>s</code>&nbsp;<strong>前缀&nbsp;</strong>的 <strong>字符串数目</strong>&nbsp;。</p>

<p>一个字符串的 <strong>前缀</strong>&nbsp;是出现在字符串开头的子字符串。<strong>子字符串</strong>&nbsp;是一个字符串中的连续一段字符序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>words = ["a","b","c","ab","bc","abc"], s = "abc"
<b>输出：</b>3
<strong>解释：</strong>
words 中是 s = "abc" 前缀的字符串为：
"a" ，"ab" 和 "abc" 。
所以 words 中是字符串 s 前缀的字符串数目为 3 。</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>words = ["a","a"], s = "aa"
<b>输出：</b>2
<strong>解释：
</strong>两个字符串都是 s 的前缀。
注意，相同的字符串可能在 words 中出现多次，它们应该被计数多次。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length, s.length &lt;= 10</code></li>
	<li><code>words[i]</code> 和&nbsp;<code>s</code>&nbsp;<strong>只</strong>&nbsp;包含小写英文字母。</li>
</ul>


    
## 解题方法：使用库函数+计数

很多编程语言都有判断一个字符串`word`是否为另一个字符串`s`的前缀的函数：

+ `C++`：`s.find(word) == 0`
+ `Python`：`s.startswith(word)`
+ `Java`：`s.startsWith(word)`
+ `Golang`：`strings.HasPrefix(s, word)`

计数即为统计`words`中有多少个`word`是`s`的前缀:

> 使用一个变量`ans`，初始值为`0`，在遍历`words`字符串数组的时候更新`ans`值就行了。

+ 时间复杂度$O(mn)$，其中$m=len(words), n=len(s)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-24 17:41:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-24 17:51:42
 */
class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int ans = 0;
        for (string& word : words) {
            ans += s.find(word) == 0;
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-03-24 17:52:11
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-24 17:52:19
'''
from typing import List

class Solution:
    def countPrefixes(self, words: List[str], s: str) -> int:
        return sum(s.startswith(word) for word in words)
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-03-24 17:53:35
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-24 17:53:41
 */
class Solution {
    public int countPrefixes(String[] words, String s) {
        int ans = 0;
        for (String word : words) {
            ans += s.startsWith(word) ? 1 : 0;
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-03-24 17:55:08
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-24 17:55:24
 */
package main

import "strings"

func countPrefixes(words []string, s string) (ans int) {
    for _, word := range words {
        if strings.HasPrefix(s, word) {
            ans++
        }
    }
    return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/146482564)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/03/24/LeetCode%202255.%E7%BB%9F%E8%AE%A1%E6%98%AF%E7%BB%99%E5%AE%9A%E5%AD%97%E7%AC%A6%E4%B8%B2%E5%89%8D%E7%BC%80%E7%9A%84%E5%AD%97%E7%AC%A6%E4%B8%B2%E6%95%B0%E7%9B%AE/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
