---
title: 1963.使字符串平衡的最小交换次数：计数模拟(不需要麻烦的“三种写法一步步优化”)
date: 2025-03-17 12:24:38
tags: [题解, LeetCode, 中等, 栈, 贪心, 双指针, 字符串, 计数, 模拟, 括号匹配]
categories: [题解, LeetCode]
---

# 【LetMeFly】1963.使字符串平衡的最小交换次数：计数模拟(不需要麻烦的“三种写法一步步优化”)

力扣题目链接：[https://leetcode.cn/problems/minimum-number-of-swaps-to-make-the-string-balanced/](https://leetcode.cn/problems/minimum-number-of-swaps-to-make-the-string-balanced/)

<p>给你一个字符串 <code>s</code> ，<strong>下标从 0 开始</strong> ，且长度为偶数 <code>n</code> 。字符串 <strong>恰好</strong> 由 <code>n / 2</code> 个开括号 <code>'['</code> 和 <code>n / 2</code> 个闭括号 <code>']'</code> 组成。</p>

<p>只有能满足下述所有条件的字符串才能称为 <strong>平衡字符串</strong> ：</p>

<ul>
	<li>字符串是一个空字符串，或者</li>
	<li>字符串可以记作 <code>AB</code> ，其中 <code>A</code> 和 <code>B</code> 都是 <strong>平衡字符串</strong> ，或者</li>
	<li>字符串可以写成 <code>[C]</code> ，其中 <code>C</code> 是一个 <strong>平衡字符串</strong> 。</li>
</ul>

<p>你可以交换 <strong>任意</strong> 两个下标所对应的括号 <strong>任意</strong> 次数。</p>

<p>返回使<em> </em><code>s</code> 变成 <strong>平衡字符串</strong> 所需要的 <strong>最小</strong> 交换次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "][]["
<strong>输出：</strong>1
<strong>解释：</strong>交换下标 0 和下标 3 对应的括号，可以使字符串变成平衡字符串。
最终字符串变成 "[[]]" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "]]][[["
<strong>输出：</strong>2
<strong>解释：</strong>执行下述操作可以使字符串变成平衡字符串：
- 交换下标 0 和下标 4 对应的括号，s = "[]][][" 。
- 交换下标 1 和下标 5 对应的括号，s = "[[][]]" 。
最终字符串变成 "[[][]]" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "[]"
<strong>输出：</strong>0
<strong>解释：</strong>这个字符串已经是平衡字符串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == s.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>6</sup></code></li>
	<li><code>n</code> 为偶数</li>
	<li><code>s[i]</code> 为<code>'['</code> 或 <code>']'</code></li>
	<li>开括号 <code>'['</code> 的数目为 <code>n / 2</code> ，闭括号 <code>']'</code> 的数目也是 <code>n / 2</code></li>
</ul>


    
## 解题方法：计数模拟

题目保证`[`和`]`的数量是相同的，也就是说一定可以通过交换达成配对。

使用两个变量：$zuoQianYou$(左前右)和$zuo$分别记录“`[`前`]`”的数量和“未被消耗的`[`”的数量。

遍历字符串

+ 如果当前字符是`[`，就说明后续可以有一个`]`来和它配对并将他“消费”，$zuo+=1$
+ 如果当前字符是`]`，就看有无`[`以供配对：

    + 如果$zuo\gt 0$，说明有未配对的`[`，消耗之（$zuo-=1$）
    + 否则(没有未配对的`[`)，$zuoQianYou+=1$

存在“无法配对的`[`前`]`”就说明要发生交换。但是注意$zuoQianYou$个“`[`前`]`”只需要交换$\lceil\frac{zuoQianYou}{2}\rceil$次，因为`]`和后面某个`[`交换后，实际上`[`的数量也加一了，顺便就还能与一个`]`配对。

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(1)$

对于<span title="https://leetcode.cn/problems/minimum-number-of-swaps-to-make-the-string-balanced/solutions/922728/go-tan-xin-by-endlesscheng-7h9n/">某“三种写法，一步步优化”</span>，看似看完恍然大悟，实则完全没必要那么麻烦。因为这“一步步优化”实则大概是其作者的思考过程罢了。若能直接想到简单方法，就直接想吧！尝试几次就能发现之前想法可能存在的漏洞了。但不可否认这位作者绝大多数文章还是十分优质的。

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-17 12:16:25
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-17 12:17:39
 */
class Solution {
public:
    int minSwaps(string s) {
        int zuoQianYou = 0, zuo = 0;
        for (char c : s) {
            if (c == '[') {
                zuo++;
            } else {
                if (zuo) {
                    zuo--;
                } else {
                    zuoQianYou++;
                }
            }
        }
        return (zuoQianYou + 1) / 2;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-03-17 12:18:42
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-17 12:18:42
'''
class Solution:
    def minSwaps(self, s: str) -> int:
        zuoQianYou = zuo = 0
        for c in s:
            if c == '[':
                zuo += 1
            else:
                if zuo:
                    zuo -= 1
                else:
                    zuoQianYou += 1
        return (zuoQianYou + 1) // 2
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-03-17 12:21:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-17 12:21:49
 */
class Solution {
    public int minSwaps(String s) {
        int zuoQianYou = 0, zuo = 0;
        for (char c : s.toCharArray()) {
            if (c == '[') {
                zuo++;
            } else {
                if (zuo > 0) {
                    zuo--;
                } else {
                    zuoQianYou++;
                }
            }
        }
        return (zuoQianYou + 1) / 2;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-03-17 12:20:26
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-17 12:21:31
 */
package main

func minSwaps(s string) int {
    zuoQianYou, zuo := 0, 0
    for i := range s {
        if s[i] == '[' {
            zuo++
        } else {
            if zuo > 0 {
                zuo--
            } else {
                zuoQianYou++
            }
        }
    }
    return (zuoQianYou + 1) / 2
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/146312262)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/03/17/LeetCode%201963.%E4%BD%BF%E5%AD%97%E7%AC%A6%E4%B8%B2%E5%B9%B3%E8%A1%A1%E7%9A%84%E6%9C%80%E5%B0%8F%E4%BA%A4%E6%8D%A2%E6%AC%A1%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
