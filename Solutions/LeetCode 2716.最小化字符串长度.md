---
title: 2716.最小化字符串长度：哈希表(位运算)
date: 2025-03-28 13:35:42
tags: [题解, LeetCode, 简单, 哈希表, set, 字符串, 位运算]
categories: [题解, LeetCode]
---

# 【LetMeFly】2716.最小化字符串长度：哈希表(位运算)

力扣题目链接：[https://leetcode.cn/problems/minimize-string-length/](https://leetcode.cn/problems/minimize-string-length/)

<p>给你一个下标从 <strong>0</strong> 开始的字符串 <code>s</code> ，重复执行下述操作 <strong>任意</strong> 次：</p>

<ul>
	<li>在字符串中选出一个下标 <code>i</code> ，并使 <code>c</code> 为字符串下标 <code>i</code> 处的字符。并在 <code>i</code> <strong>左侧</strong>（如果有）和 <strong>右侧</strong>（如果有）各 <strong>删除 </strong>一个距离 <code>i</code> <strong>最近</strong> 的字符 <code>c</code> 。</li>
</ul>

<p>请你通过执行上述操作任意次，使 <code>s</code> 的长度 <strong>最小化</strong> 。</p>

<p>返回一个表示 <strong>最小化</strong> 字符串的长度的整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "aaabc"
<strong>输出：</strong>3
<strong>解释：</strong>在这个示例中，s 等于 "aaabc" 。我们可以选择位于下标 1 处的字符 'a' 开始。接着删除下标 1 左侧最近的那个 'a'（位于下标 0）以及下标 1 右侧最近的那个 'a'（位于下标 2）。执行操作后，字符串变为 "abc" 。继续对字符串执行任何操作都不会改变其长度。因此，最小化字符串的长度是 3 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "cbbd"
<strong>输出：</strong>3
<strong>解释：</strong>我们可以选择位于下标 1 处的字符 'b' 开始。下标 1 左侧不存在字符 'b' ，但右侧存在一个字符 'b'（位于下标 2），所以会删除位于下标 2 的字符 'b' 。执行操作后，字符串变为 "cbd" 。继续对字符串执行任何操作都不会改变其长度。因此，最小化字符串的长度是 3 。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "dddaaa"
<strong>输出：</strong>2
<strong>解释：</strong>我们可以选择位于下标 1 处的字符 'd' 开始。接着删除下标 1 左侧最近的那个 'd'（位于下标 0）以及下标 1 右侧最近的那个 'd'（位于下标 2）。执行操作后，字符串变为 "daaa" 。继续对新字符串执行操作，可以选择位于下标 2 的字符 'a' 。接着删除下标 2 左侧最近的那个 'a'（位于下标 1）以及下标 2 右侧最近的那个 'a'（位于下标 3）。执行操作后，字符串变为 "da" 。继续对字符串执行任何操作都不会改变其长度。因此，最小化字符串的长度是 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
</ul>


    
## 解题方法一：哈希表

题目意思是删除次数不限，但是无论如何一个字母都无法将自身删除，只能由和它相同的其他字母将其删除。所以删到最后种字母都会留下一个，因此我们使用哈希表统计字符串中不同种类的字符的个数即可。

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(\min(len(s), C))$，其中$C$是字符集大小$C=26$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-28 13:27:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-28 13:27:34
 */
class Solution {
public:
    int minimizedStringLength(string s) {
        return unordered_set(s.begin(), s.end()).size();
    }
};
```

## 解题方法二：哈希表(位运算)

字符最多有26种，因此我们可以使用一个整数二进制下的低26位代表每种字符是否出现过，`0`代表未出现过，`1`代表出现过。

遍历字符串，将$mask$的第$c - 'a'$位置$1$，最终统计$mask$二进制下$1$的个数即可。

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-28 13:28:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-28 13:29:13
 * @Description: AC,100.00%,82.68%
 */
class Solution {
public:
    int minimizedStringLength(string s) {
        int mask = 0;
        for (char c : s) {
            mask |= 1 << (c - 'a');
        }
        return __builtin_popcount(mask);
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-03-28 13:29:58
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-28 13:31:10
'''
class Solution:
    def minimizedStringLength(self, s: str) -> int:
        mask = 0
        for c in s:
            mask |= 1 << (ord(c) - 97)
        return mask.bit_count()  # python3.10
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-03-28 13:31:41
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-28 13:31:42
 */
class Solution {
    public int minimizedStringLength(String s) {
        int mask = 0;
        for (char c : s.toCharArray()) {
            mask |= 1 << (c - 'a');
        }
        return Integer.bitCount(mask);
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-03-28 13:32:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-28 13:34:00
 */
package main

import "math/bits"

func minimizedStringLength(s string) int {
    mask := uint(0)
    for _, c := range s {
        mask |= 1 << (c - 'a')
    }
    return bits.OnesCount(mask)
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/146599598)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/03/28/LeetCode%202716.%E6%9C%80%E5%B0%8F%E5%8C%96%E5%AD%97%E7%AC%A6%E4%B8%B2%E9%95%BF%E5%BA%A6/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
