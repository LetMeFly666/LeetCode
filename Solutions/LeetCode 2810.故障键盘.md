---
title: 2810.故障键盘
date: 2024-04-01 18:13:37
tags: [题解, LeetCode, 简单, 字符串, 模拟, 队列, 双端队列]
categories: [题解, LeetCode]
---

# 【LetMeFly】2810.故障键盘：双端队列模拟

力扣题目链接：[https://leetcode.cn/problems/faulty-keyboard/](https://leetcode.cn/problems/faulty-keyboard/)

<p>你的笔记本键盘存在故障，每当你在上面输入字符 <code>'i'</code> 时，它会反转你所写的字符串。而输入其他字符则可以正常工作。</p>

<p>给你一个下标从 <strong>0</strong> 开始的字符串 <code>s</code> ，请你用故障键盘依次输入每个字符。</p>

<p>返回最终笔记本屏幕上输出的字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "string"
<strong>输出：</strong>"rtsng"
<strong>解释：</strong>
输入第 1 个字符后，屏幕上的文本是："s" 。
输入第 2 个字符后，屏幕上的文本是："st" 。
输入第 3 个字符后，屏幕上的文本是："str" 。
因为第 4 个字符是 'i' ，屏幕上的文本被反转，变成 "rts" 。
输入第 5 个字符后，屏幕上的文本是："rtsn" 。
输入第 6 个字符后，屏幕上的文本是： "rtsng" 。
因此，返回 "rtsng" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "poiinter"
<strong>输出：</strong>"ponter"
<strong>解释：</strong>
输入第 1 个字符后，屏幕上的文本是："p" 。
输入第 2 个字符后，屏幕上的文本是："po" 。
因为第 3 个字符是 'i' ，屏幕上的文本被反转，变成 "op" 。
因为第 4 个字符是 'i' ，屏幕上的文本被反转，变成 "po" 。
输入第 5 个字符后，屏幕上的文本是："pon" 。
输入第 6 个字符后，屏幕上的文本是："pont" 。
输入第 7 个字符后，屏幕上的文本是："ponte" 。
输入第 8 个字符后，屏幕上的文本是："ponter" 。
因此，返回 "ponter" 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> 由小写英文字母组成</li>
	<li><code>s[0] != 'i'</code></li>
</ul>


    
## 解题方法：双端队列模拟

使用一个双端队列来存放要输出的字符们，默认将字符添加到双端队列的右边（后面）。

使用一个布尔类型的变量```push_front```来记录当前字符是否应该添加到双端队列的右边。

遍历字符串：

+ 如果当前字符为```i```，则说明需要“翻转字符串”。我们不需要真正翻转字符串，只需要标记一下说“原来字符串的头，现在你变成尾了”（翻转变量```push_front```的值）。
+ 否则，依据变量```push_front```的值将字符添加到字符串的头或尾。

最终依据变量```push_front```的值从头到尾或从尾到头将队列中的字符拼接成字符串。

### 时空复杂度分析

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(len(s))$

虽然这种方法时间复杂度为$O(n)$，但是题目的数据返回是$10^2$级别，因此效果可能不如直接的模拟。

### AC代码

#### C++

```cpp
class Solution {
public:
    string finalString(string s) {
        deque<char> q;
        bool push_front = false;
        for (char c : s) {
            if (c == 'i') {
                push_front = !push_front;
                continue;
            }
            if (push_front) {
                q.push_front(c);
            }
            else {
                q.push_back(c);
            }
        }
        return push_front ? string{q.rbegin(), q.rend()} : string{q.begin(), q.end()};
    }
};
```

#### Python

```python
# from collections import deque

class Solution:
    def finalString(self, s: str) -> str:
        q = deque()
        appendleft = False
        for c in s:
            if c == 'i':
                appendleft = not appendleft
                continue
            if appendleft:
                q.appendleft(c)
            else:
                q.append(c)
        return ''.join(q)[::-1] if appendleft else ''.join(q)
```

愚人节快乐！

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/04/01/LeetCode%202810.%E6%95%85%E9%9A%9C%E9%94%AE%E7%9B%98/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/137242651](https://letmefly.blog.csdn.net/article/details/137242651)
