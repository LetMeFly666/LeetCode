---
title: 2434.使用机器人打印字典序最小的字符串：贪心(栈)——清晰题解
date: 2025-06-06 23:10:04
tags: [题解, LeetCode, 中等, 栈, 贪心, 字符串]
categories: [题解, LeetCode]
---

# 【LetMeFly】2434.使用机器人打印字典序最小的字符串：贪心(栈)——清晰题解

力扣题目链接：[https://leetcode.cn/problems/using-a-robot-to-print-the-lexicographically-smallest-string/](https://leetcode.cn/problems/using-a-robot-to-print-the-lexicographically-smallest-string/)

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;和一个机器人，机器人当前有一个空字符串&nbsp;<code>t</code>&nbsp;。执行以下操作之一，直到&nbsp;<code>s</code> 和&nbsp;<code>t</code>&nbsp;<strong>都变成空字符串：</strong></p>

<ul>
	<li>删除字符串&nbsp;<code>s</code>&nbsp;的 <strong>第一个</strong>&nbsp;字符，并将该字符给机器人。机器人把这个字符添加到 <code>t</code>&nbsp;的尾部。</li>
	<li>删除字符串&nbsp;<code>t</code>&nbsp;的&nbsp;<strong>最后一个</strong>&nbsp;字符，并将该字符给机器人。机器人将该字符写到纸上。</li>
</ul>

<p>请你返回纸上能写出的字典序最小的字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>s = "zza"
<b>输出：</b>"azz"
<b>解释：</b>用 p 表示写出来的字符串。
一开始，p="" ，s="zza" ，t="" 。
执行第一个操作三次，得到 p="" ，s="" ，t="zza" 。
执行第二个操作三次，得到 p="azz" ，s="" ，t="" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>s = "bac"
<b>输出：</b>"abc"
<b>解释：</b>用 p 表示写出来的字符串。
执行第一个操作两次，得到 p="" ，s="c" ，t="ba" 。
执行第二个操作两次，得到 p="ab" ，s="c" ，t="" 。
执行第一个操作，得到 p="ab" ，s="" ，t="c" 。
执行第二个操作，得到 p="abc" ，s="" ，t="" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>s = "bdda"
<b>输出：</b>"addb"
<b>解释：</b>用 p 表示写出来的字符串。
一开始，p="" ，s="bdda" ，t="" 。
执行第一个操作四次，得到 p="" ，s="" ，t="bdda" 。
执行第二个操作四次，得到 p="addb" ，s="" ，t="" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
</ul>


    
## 解题方法：贪心

机器人的操作等价于：

> 将字符串`s`中的元素按顺序入栈，栈中元素按任意顺序出栈，最终所有元素都要入栈出栈，求出栈元素组成的字符串的最小字典序。

分析这道题最好的例子就是`bac`：

> 首先`b`入栈，这时候`b`应该出栈吗？不应该，因为后面有更小的`a`，应该让`a`排前面；
>
> 接着将`a`入栈，此时栈中元素为`[ba`，`a`应该出栈吗？应该，因为后面元素都比`a`大，一旦`c`入栈时`a`还没出栈，那么`c`一定比`a`出栈早；
>
> `a`出栈后`b`应该出栈吗？应该，和`a`出栈的道理相同，因为`b < c`；
>
> `c`入栈，`c`出栈，最终顺序`abc`。

不知道大家有没有发现，决定一个元素是否出栈的依据是**后面最小的元素是否都大于等于栈顶元素** 。

+ 如果后面元素都大于等于栈顶元素，那么栈顶元素是时候出栈了，否则后面更大的元素入栈只会导致有更大的元素先出栈；
+ 如果后面元素有比栈顶元素更小的，那么栈顶元素就先不出栈，因为更小元素更早出栈结果更优。

具体的：

> 预先后续遍历一遍字符串`s`，求出`mini`数组，其中`mini[i]`代表`s[i:n-1]`的最小字符。
>
> 接着正序遍历字符串`s`，遍历到谁谁入栈，当栈顶元素**小于等于**字符串当前位置之后的所有字符时，栈顶元素不断出栈。

为了方便，也可以假设原始字符串`s`后面还有一个“最大”字符`z`。

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(len(s))$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-06-06 21:49:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-06 22:19:18
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string robotWithString(string s) {
        vector<char> mini(s.size() + 1, 'z');
        for (int i = s.size() - 1; i >= 0; i--) {
            mini[i] = min(mini[i + 1], s[i]);
        }
        stack<char> st;
        string ans;
        for (int i = 0; i < s.size(); i++) {
            st.push(s[i]);
            while (st.size() && st.top() <= mini[i + 1]) {
                ans += st.top();
                st.pop();
            }
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-06-06 21:49:43
LastEditors: LetMeFly.xyz
LastEditTime: 2025-06-06 22:30:06
'''
class Solution:
    def robotWithString(self, s: str) -> str:
        mini = ['z'] * (len(s) + 1)
        for i in range(len(s) - 1, -1, -1):
            mini[i] = min(mini[i + 1], s[i])
        ans = []
        st = []
        for i, c in enumerate(s):
            st.append(c)
            while st and st[-1] <= mini[i + 1]:
                ans.append(st.pop())
        return ''.join(ans)
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-06-06 21:49:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-06 22:38:18
 */
// StringBuilder - java.lang
import java.util.Deque;
import java.util.ArrayDeque;

class Solution {
    public String robotWithString(String s) {
        char[] mini = new char[s.length() + 1];
        mini[s.length()] = 'z';
        for (int i = s.length() - 1; i >= 0; i--) {
            mini[i] = (char) Math.min(mini[i + 1], s.charAt(i));
        }
        StringBuilder ans = new StringBuilder(s.length());
        Deque<Character> st = new ArrayDeque<>();
        for (int i = 0; i < s.length(); i++) {
            st.push(s.charAt(i));
            while (!st.isEmpty() && st.peek() <= mini[i + 1]) {
                ans.append(st.pop());
            }
        }
        return ans.toString();
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-06-06 21:49:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-06 23:06:01
 */
package main

func robotWithString(s string) string {
    mini := make([]byte, len(s) + 1)
    mini[len(s)] = 'z'
    for i := len(s) - 1; i >= 0; i-- {
        mini[i] = min(mini[i + 1], s[i])
    }
    st := mini[:0]
    ans := make([]byte, 0, len(s))
    for i := 0; i < len(s); i++ {
        st = append(st, s[i])
        for len(st) > 0 && st[len(st) - 1] <= mini[i + 1] {
            ans = append(ans, st[len(st) - 1])
            st = st[:len(st) - 1]
        }
    }
    return string(ans)
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/148484075)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/06/06/LeetCode%202434.%E4%BD%BF%E7%94%A8%E6%9C%BA%E5%99%A8%E4%BA%BA%E6%89%93%E5%8D%B0%E5%AD%97%E5%85%B8%E5%BA%8F%E6%9C%80%E5%B0%8F%E7%9A%84%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
