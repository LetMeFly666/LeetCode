---
title: 3083.字符串及其反转中是否存在同一子字符串
date: 2024-12-26 15:48:45
tags: [题解, LeetCode, 简单, 哈希表, 字符串, set]
categories: [题解, LeetCode]
---

# 【LetMeFly】3083.字符串及其反转中是否存在同一子字符串：哈希表

力扣题目链接：[https://leetcode.cn/problems/existence-of-a-substring-in-a-string-and-its-reverse/](https://leetcode.cn/problems/existence-of-a-substring-in-a-string-and-its-reverse/)

<p>给你一个字符串 <code>s</code> ，请你判断字符串 <code>s</code> 是否存在一个长度为 <code>2</code> 的子字符串，在其反转后的字符串中也出现。</p>

<p>如果存在这样的子字符串，返回 <code>true</code>；如果不存在，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>输入：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">s = "leetcode"</span></p>

<p><strong>输出：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">true</span></p>

<p><strong>解释：</strong>子字符串 <code>"ee"</code> 的长度为 <code>2</code>，它也出现在 <code>reverse(s) == "edocteel"</code> 中。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>输入：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">s = "abcba"</span></p>

<p><strong>输出：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">true</span></p>

<p><strong>解释：</strong>所有长度为 <code>2</code> 的子字符串 <code>"ab"</code>、<code>"bc"</code>、<code>"cb"</code>、<code>"ba"</code> 也都出现在 <code>reverse(s) == "abcba"</code> 中。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>输入：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">s = "abcd"</span></p>

<p><strong>输出：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">false</span></p>

<p><strong>解释：</strong>字符串 <code>s</code> 中不存在满足「在其反转后的字符串中也出现」且长度为 <code>2</code> 的子字符串。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li>字符串 <code>s</code> 仅由小写英文字母组成。</li>
</ul>


    
## 解题方法：哈希表

开辟一个二维数组`visited`，其中`visited[i][j]`表示长度为2的子字符串`('a' + i)('a' + j)`是否出现过。

遍历字符串，将每个长度为2的子字符串加入哈希表中。若这个子字符串翻转后的字符串在哈希表中出现过，则返回`true`。

最终未返回则返回`false`。

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(C^2)$，其中$C=26$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2024-12-26 15:37:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-26 15:39:20
 */
class Solution {
public:
    bool isSubstringPresent(string s) {
        bool visited[26][26] = {false};
        for (int i = 1; i < s.size(); i++) {
            visited[s[i - 1] - 'a'][s[i] - 'a'] = true;
            if (visited[s[i] - 'a'][s[i - 1] - 'a']) {
                return true;
            }
        }
        return false;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2024-12-26 15:40:00
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-26 15:41:59
'''
class Solution:
    def isSubstringPresent(self, s: str) -> bool:
        visited = [[False] * 26 for _ in range(26)]
        for i in range(1, len(s)):
            visited[ord(s[i - 1]) - ord('a')][ord(s[i]) - ord('a')] = True
            if visited[ord(s[i]) - ord('a')][ord(s[i - 1]) - ord('a')]:
                return True
        return False
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2024-12-26 15:42:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-26 15:44:38
 */
class Solution {
    public boolean isSubstringPresent(String s) {
        boolean[][] visited = new boolean[26][26];
        for (int i = 1; i < s.length(); i++) {
            visited[s.charAt(i - 1) - 'a'][s.charAt(i) - 'a'] = true;
            if (visited[s.charAt(i) - 'a'][s.charAt(i - 1) - 'a']) {
                return true;
            }
        }
        return false;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2024-12-26 15:45:02
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-26 15:47:44
 */
package main

func isSubstringPresent(s string) bool {
    var visited [26][26]bool
    for i := 1; i < len(s); i++ {
        visited[s[i - 1] - 'a'][s[i] - 'a'] = true
        if visited[s[i] - 'a'][s[i - 1] - 'a'] {
            return true
        }
    }
    return false
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/12/26/LeetCode%203083.%E5%AD%97%E7%AC%A6%E4%B8%B2%E5%8F%8A%E5%85%B6%E5%8F%8D%E8%BD%AC%E4%B8%AD%E6%98%AF%E5%90%A6%E5%AD%98%E5%9C%A8%E5%90%8C%E4%B8%80%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/144746598](https://letmefly.blog.csdn.net/article/details/144746598)
