---
title: 2116.判断一个括号字符串是否有效：括号匹配(两个变量一次遍历解决)
date: 2025-03-23 11:24:23
tags: [题解, LeetCode, 中等, 栈, 贪心, 字符串, 括号匹配]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.com/uploads/2021/11/06/eg1.png
---

# 【LetMeFly】2116.判断一个括号字符串是否有效：括号匹配(两个变量一次遍历解决)

力扣题目链接：[https://leetcode.cn/problems/check-if-a-parentheses-string-can-be-valid/](https://leetcode.cn/problems/check-if-a-parentheses-string-can-be-valid/)

<p>一个括号字符串是只由&nbsp;<code>'('</code> 和&nbsp;<code>')'</code>&nbsp;组成的&nbsp;<strong>非空</strong>&nbsp;字符串。如果一个字符串满足下面 <b>任意</b>&nbsp;一个条件，那么它就是有效的：</p>

<ul>
	<li>字符串为&nbsp;<code>()</code>.</li>
	<li>它可以表示为 <code>AB</code><span style="">（</span><code>A</code>&nbsp;与&nbsp;<code>B</code>&nbsp;连接），其中<code>A</code> 和&nbsp;<code>B</code>&nbsp;都是有效括号字符串。</li>
	<li>它可以表示为&nbsp;<code>(A)</code>&nbsp;，其中&nbsp;<code>A</code>&nbsp;是一个有效括号字符串。</li>
</ul>

<p>给你一个括号字符串&nbsp;<code>s</code>&nbsp;和一个字符串&nbsp;<code>locked</code>&nbsp;，两者长度都为&nbsp;<code>n</code>&nbsp;。<code>locked</code>&nbsp;是一个二进制字符串，只包含&nbsp;<code>'0'</code>&nbsp;和&nbsp;<code>'1'</code>&nbsp;。对于&nbsp;<code>locked</code>&nbsp;中&nbsp;<strong>每一个</strong>&nbsp;下标&nbsp;<code>i</code> ：</p>

<ul>
	<li>如果&nbsp;<code>locked[i]</code>&nbsp;是&nbsp;<code>'1'</code>&nbsp;，你 <strong>不能</strong>&nbsp;改变&nbsp;<code>s[i]</code>&nbsp;。</li>
	<li>如果&nbsp;<code>locked[i]</code>&nbsp;是&nbsp;<code>'0'</code>&nbsp;，你&nbsp;<strong>可以</strong>&nbsp;将&nbsp;<code>s[i]</code>&nbsp;变为&nbsp;<code>'('</code>&nbsp;或者&nbsp;<code>')'</code>&nbsp;。</li>
</ul>

<p>如果你可以将 <code>s</code>&nbsp;变为有效括号字符串，请你返回&nbsp;<code>true</code>&nbsp;，否则返回&nbsp;<code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/11/06/eg1.png" style="width: 311px; height: 101px;" /></p>
<!-- <p><img alt="" src="https://i-blog.csdnimg.cn/direct/fda45db53c054c9092e67cd6ca2cb8b9.png" style="width: 311px; height: 101px;" /></p> -->

<pre>
<b>输入：</b>s = "))()))", locked = "010100"
<b>输出：</b>true
<b>解释：</b>locked[1] == '1' 和 locked[3] == '1' ，所以我们无法改变 s[1] 或者 s[3] 。
我们可以将 s[0] 和 s[4] 变为 '(' ，不改变 s[2] 和 s[5] ，使 s 变为有效字符串。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>s = "()()", locked = "0000"
<b>输出：</b>true
<b>解释：</b>我们不需要做任何改变，因为 s 已经是有效字符串了。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>s = ")", locked = "0"
<b>输出：</b>false
<b>解释：</b>locked 允许改变 s[0] 。
但无论将 s[0] 变为 '(' 或者 ')' 都无法使 s 变为有效字符串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == s.length == locked.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code>&nbsp;要么是&nbsp;<code>'('</code>&nbsp;要么是&nbsp;<code>')'</code>&nbsp;。</li>
	<li><code>locked[i]</code> 要么是&nbsp;<code>'0'</code>&nbsp;要么是&nbsp;<code>'1'</code> 。</li>
</ul>

很不错的一道题，这题[灵茶山艾府](https://leetcode.cn/u/endlesscheng/)的[题解](https://leetcode.cn/problems/check-if-a-parentheses-string-can-be-valid/solutions/1178043/zheng-fan-liang-ci-bian-li-by-endlessche-z8ac/)很棒。

## 解题方法：一次遍历(贪心)

### 解题思路

整个遍历过程中，要时刻保证：

+ 左括号的数量始终不少于右括号的数量

遍历结束后，要保证左括号的数量和右括号的数量相等。

我们可以使用$diff$来表示左括号的数量减去右括号的数量的差值，则想要返回`true`必须满足：

1. 遍历过程中始终有：$diff\geq 0$
2. 遍历结束时，$diff = 0$

如果每个字符都是确定的话还好说，但是有的字符可以更改（`locked[i] = '0'`）要怎么处理呢？

其实也很简单，是`(`是`)`都试试呗。不难发现：

> 假设$diff=3$时遇到了一个`locked[i] = '0'`，那么`s[i]`为`(`的话$diff$将变成$4$，`s[i]`为`)`的话$diff$将变成$6$。$diff$的取值范围变成了$\{4, 6\}$（全为偶数）
>
> 在此基础上，假设又遇到了`locked[i] = '0'`，那么`s[i]`为`(`的话$diff$将变成$\{3, 5\}$，`s[i]`为`)`的话$diff$将变成$\{5, 7\}$。$diff$的取值范围变成了$\{3, 5, 7\}$（全是奇数）
>
> 不难发现$diff$的取值范围要么是全奇数，要么是全偶数。所以可以用$l$表示$diff$合法取值范围的最小值，$r$表示$diff$合法取值范围的最大值。

### 具体做法

初始值$l = 0, r = 0$，代表`(`和`)`差值的可能范围为$\{0\}$。

开始遍历字符串：

+ 如果`locked[i] = '0'`，说明可`(`可`)`，范围将变成`l - 1`到`r + 1`

    注意如果`l`变成了`-1`则说明`l`本来是`0`，要将`l`重新置为合法范围`1`

+ 否则（`locked[i] = '1'`）

    + 如果`s[i] = '('`：范围将变成`l + 1`到`r + 1`
    + 否则(`s[i] = ')'`)：范围将变成`l - 1`到`r - 1`

        此时如果`r < 0`，则说明合法范围为空，不满足“整个遍历过从始终有$diff\geq 0$”，直接返回`false`

        此时如果`l < 0`（`l`变成了`-1`），则说明`l`本来是`0`，要将`l`重新置为合法范围`1`

最终，若`l`为`0`则说存在`(`和`)`相等的情况，返回`true`。

### 时空复杂度

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-23 09:37:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-23 10:39:28
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/*
*)*(**
()(())


(*)*
(())


(**(
xxxx

(*
()



*/
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int l = 0, r = 0;
        for (int i = 0; i < s.size(); i++) {
            if (locked[i] == '0') {
                l--, r++;
                if (l < 0) {
                    l = 1;
                }
            } else {  // ()
                if (s[i] == '(') {
                    l++, r++;
                } else {
                    l--, r--;
                    if (r < 0) {
                        return false;
                    }
                    if (l < 0) {
                        l = 1;
                    }
                }
            }
        }
        return !l;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-03-23 10:49:44
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-23 10:51:19
'''
class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        l = r = 0
        for i in range(len(s)):
            if locked[i] == '0':
                l -= 1
                r += 1
                if l == -1:
                    l = 1
            else:
                if s[i] == '(':
                    l += 1
                    r += 1
                else:
                    l -= 1
                    r -= 1
                    if r < 0:
                        return False
                    if l < 0:
                        l = 1
        return not l
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-03-23 10:52:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-23 10:53:49
 */
class Solution {
    public boolean canBeValid(String s, String locked) {
        int l = 0, r = 0;
        for (int i = 0; i < s.length(); i++) {
            if (locked.charAt(i) == '0') {
                l--;
                r++;
                if (l < 0) {
                    l = 1;
                }
            } else {
                if (s.charAt(i) == '(') {
                    l++;
                    r++;
                } else {
                    l--;
                    r--;
                    if (r < 0) {
                        return false;
                    }
                    if (l < 0) {
                        l = 1;
                    }
                }
            }
        }
        return l == 0;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-03-23 10:54:53
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-23 10:56:04
 */
package main

func canBeValid(s string, locked string) bool {
    l, r := 0, 0
    for i := range s {
        if locked[i] == '0' {
            l--
            r++
            if l < 0 {
                l = 1
            }
        } else {
            if s[i] == '(' {
                l++
                r++
            } else {
                l--
                r--
                if r < 0 {
                    return false
                }
                if l < 0 {
                    l = 1
                }
            }
        }
    }
    return l == 0
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/146454056)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/03/23/LeetCode%202116.%E5%88%A4%E6%96%AD%E4%B8%80%E4%B8%AA%E6%8B%AC%E5%8F%B7%E5%AD%97%E7%AC%A6%E4%B8%B2%E6%98%AF%E5%90%A6%E6%9C%89%E6%95%88/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
