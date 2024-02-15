---
title: 921.使括号有效的最少添加
date: 2022-10-04 07:59:39
tags: [题解, LeetCode, 中等, 栈, 贪心, 字符串]
---

# 【LetMeFly】921.使括号有效的最少添加

力扣题目链接：[https://leetcode.cn/problems/minimum-add-to-make-parentheses-valid/](https://leetcode.cn/problems/minimum-add-to-make-parentheses-valid/)

<p>只有满足下面几点之一，括号字符串才是有效的：</p>

<ul>
	<li>它是一个空字符串，或者</li>
	<li>它可以被写成&nbsp;<code>AB</code>&nbsp;（<code>A</code>&nbsp;与&nbsp;<code>B</code>&nbsp;连接）, 其中&nbsp;<code>A</code> 和&nbsp;<code>B</code>&nbsp;都是有效字符串，或者</li>
	<li>它可以被写作&nbsp;<code>(A)</code>，其中&nbsp;<code>A</code>&nbsp;是有效字符串。</li>
</ul>

<p>给定一个括号字符串 <code>s</code> ，移动N次，你就可以在字符串的任何位置插入一个括号。</p>

<ul>
	<li>例如，如果 <code>s = "()))"</code> ，你可以插入一个开始括号为 <code>"(()))"</code> 或结束括号为 <code>"())))"</code> 。</li>
</ul>

<p>返回 <em>为使结果字符串 <code>s</code> 有效而必须添加的最少括号数</em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "())"
<strong>输出：</strong>1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "((("
<strong>输出：</strong>3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> 只包含&nbsp;<code>'('</code> 和&nbsp;<code>')'</code>&nbsp;字符。</li>
</ul>


    
## 方法一：栈

用栈的思想：如果遇到左括号就入栈，遇到右括号就看栈是否为空。如果栈不空，就出栈一个左括号；否则就将右括号入栈。

最终输出栈中元素的个数，就是未匹配的括号数，也就是“使括号有效的最少添加”

+ 时间复杂度$O(n)$，其中$n$是字符串长度
+ 空间复杂度$O(n)$

## 方法二：模拟栈

延续方法一的思想，能否不真正用栈来实现呢？

只需要使用两个变量，```left```记录栈中有多少个左括号，```right```记录栈中有多少个右括号。

注意，一旦右括号入栈，就说明前面没有“未匹配的左括号”了，右括号将永远留在栈底无法出栈。

因此，在遍历字符串的过程中，遇到左括号就```left++```，遇到右括号就看```left```是否为0。若不为零，就说明栈中有左括号，就```left--```；否则说明栈中无左括号，就```right++```

+ 时间复杂度$O(n)$，其中$n$是字符串长度
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minAddToMakeValid(string& s) {
        int left = 0;
        int right = 0;
        for (char& c : s) {
            if (c == '(') {
                left++;
            }
            else {
                if (left) {
                    left--;
                }
                else {
                    right++;
                }
            }
        }
        return right + left;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/10/04/LeetCode%200921.%E4%BD%BF%E6%8B%AC%E5%8F%B7%E6%9C%89%E6%95%88%E7%9A%84%E6%9C%80%E5%B0%91%E6%B7%BB%E5%8A%A0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127158816](https://letmefly.blog.csdn.net/article/details/127158816)
