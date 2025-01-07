---
title: 3019.按键变更的次数
date: 2025-01-07 13:14:51
tags: [题解, LeetCode, 简单, 字符串]
---

# 【LetMeFly】3019.按键变更的次数：遍历（转小写）

力扣题目链接：[https://leetcode.cn/problems/number-of-changing-keys/](https://leetcode.cn/problems/number-of-changing-keys/)

<p>给你一个下标从<strong> 0</strong> 开始的字符串 <code>s</code> ，该字符串由用户输入。按键变更的定义是：使用与上次使用的按键不同的键。例如 <code>s = "ab"</code> 表示按键变更一次，而 <code>s = "bBBb"</code> 不存在按键变更。</p>

<p>返回用户输入过程中按键变更的次数。</p>

<p><strong>注意：</strong><code>shift</code> 或 <code>caps lock</code> 等修饰键不计入按键变更，也就是说，如果用户先输入字母 <code>'a'</code> 然后输入字母 <code>'A'</code> ，不算作按键变更。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "aAbBcC"
<strong>输出：</strong>2
<strong>解释：</strong> 
从 s[0] = 'a' 到 s[1] = 'A'，不存在按键变更，因为不计入 caps lock 或 shift 。
从 s[1] = 'A' 到 s[2] = 'b'，按键变更。
从 s[2] = 'b' 到 s[3] = 'B'，不存在按键变更，因为不计入 caps lock 或 shift 。
从 s[3] = 'B' 到 s[4] = 'c'，按键变更。
从 s[4] = 'c' 到 s[5] = 'C'，不存在按键变更，因为不计入 caps lock 或 shift 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "AaAaAaaA"
<strong>输出：</strong>0
<strong>解释：</strong> 不存在按键变更，因为这个过程中只按下字母 'a' 和 'A' ，不需要进行按键变更。<!-- notionvc: 8849fe75-f31e-41dc-a2e0-b7d33d8427d2 -->
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> 仅由英文大写字母和小写字母组成。</li>
</ul>


    
## 解题方法：遍历

从第二个字符开始遍历字符串，如果当前字符串的小写和前一个字符的小写不相同，则答案数量加一。

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-01-07 13:03:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-07 13:08:37
 */
class Solution {
public:
    int countKeyChanges(string& s) {
        int ans = 0;
        for (int i = 1; i < s.size(); i++) {
            ans += tolower(s[i]) != tolower(s[i - 1]);
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-01-07 13:09:14
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-07 13:09:43
'''
class Solution:
    def countKeyChanges(self, s: str) -> int:
        return sum(s[i].lower() != s[i - 1].lower() for i in range(1, len(s)))
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-01-07 13:10:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-07 13:11:25
 */
class Solution {
    public int countKeyChanges(String s) {
        int ans = 0;
        for (int i = 1; i < s.length(); i++) {
            if (Character.toLowerCase(s.charAt(i)) != Character.toLowerCase(s.charAt(i - 1))) {
                ans++;
            }
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-01-07 13:11:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-07 13:13:25
 */
package main
import "strings"

func countKeyChanges(s string) (ans int) {
    for i := 1; i < len(s); i++ {
        if strings.ToLower(string(s[i])) != strings.ToLower(string(s[i - 1])) {
            ans++
        }
    }
    return
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/01/07/LeetCode%203019.%E6%8C%89%E9%94%AE%E5%8F%98%E6%9B%B4%E7%9A%84%E6%AC%A1%E6%95%B0/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/144983704](https://letmefly.blog.csdn.net/article/details/144983704)
