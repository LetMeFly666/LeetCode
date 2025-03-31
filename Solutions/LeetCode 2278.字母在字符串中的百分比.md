---
title: 2278.字母在字符串中的百分比：计数
date: 2025-03-31 13:48:39
tags: [题解, LeetCode, 简单, 字符串, 计数, 遍历]
categories: [题解, LeetCode]
---

# 【LetMeFly】2278.字母在字符串中的百分比：计数

力扣题目链接：[https://leetcode.cn/problems/percentage-of-letter-in-string/](https://leetcode.cn/problems/percentage-of-letter-in-string/)

<p>给你一个字符串 <code>s</code> 和一个字符 <code>letter</code> ，返回在 <code>s</code> 中等于&nbsp;<code>letter</code>&nbsp;字符所占的 <strong>百分比</strong> ，向下取整到最接近的百分比。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "foobar", letter = "o"
<strong>输出：</strong>33
<strong>解释：</strong>
等于字母 'o' 的字符在 s 中占到的百分比是 2 / 6 * 100% = 33% ，向下取整，所以返回 33 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "jjjj", letter = "k"
<strong>输出：</strong>0
<strong>解释：</strong>
等于字母 'k' 的字符在 s 中占到的百分比是 0% ，所以返回 0 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> 由小写英文字母组成</li>
	<li><code>letter</code> 是一个小写英文字母</li>
</ul>


    
## 解题方法：遍历计数

遍历一遍字符串，统计`letter`出现了多少次。

将出现次数乘以100除以字符串总长，向下取整即为所求。

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-31 13:28:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-31 13:29:07
 */
class Solution {
public:
    int percentageLetter(string s, char letter) {
        int cnt = 0;
        for (char c : s) {
            cnt += c == letter;
        }
        return cnt * 100 / s.size();
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-03-31 13:31:06
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-31 13:31:35
'''
class Solution:
    def percentageLetter(self, s: str, letter: str) -> int:
        return s.count(letter) * 100 // len(s)
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-03-31 13:33:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-31 13:40:38
 */
class Solution {
    public int percentageLetter(String s, char letter) {
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (letter == s.charAt(i)) {
                cnt++;
            }
        }
        return cnt * 100 / s.length();
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-03-31 13:32:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-31 13:32:19
 */
package main

import "strings"

func percentageLetter(s string, letter byte) int {
    return strings.Count(s, string(letter)) * 100 / len(s)
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/146821680)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/03/31/LeetCode%202278.%E5%AD%97%E6%AF%8D%E5%9C%A8%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E7%9A%84%E7%99%BE%E5%88%86%E6%AF%94/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
