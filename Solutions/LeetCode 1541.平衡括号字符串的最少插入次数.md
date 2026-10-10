---
title: 1541.平衡括号字符串的最少插入次数
date: 2026-10-10 09:31:48
tags: [题解, LeetCode, 中等, 栈, 贪心, 字符串]
categories: [题解, LeetCode]
---

# 【LetMeFly】1541.平衡括号字符串的最少插入次数

力扣题目链接：[https://leetcode.cn/problems/minimum-insertions-to-balance-a-parentheses-string/](https://leetcode.cn/problems/minimum-insertions-to-balance-a-parentheses-string/)

<p>给你一个括号字符串&nbsp;<code>s</code>&nbsp;，它只包含字符&nbsp;<code>&#39;(&#39;</code> 和&nbsp;<code>&#39;)&#39;</code>&nbsp;。一个括号字符串被称为平衡的当它满足：</p>

<ul>
	<li>任何左括号&nbsp;<code>&#39;(&#39;</code>&nbsp;必须对应两个连续的右括号&nbsp;<code>&#39;))&#39;</code>&nbsp;。</li>
	<li>左括号&nbsp;<code>&#39;(&#39;</code>&nbsp;必须在对应的连续两个右括号&nbsp;<code>&#39;))&#39;</code>&nbsp;之前。</li>
</ul>

<p>比方说&nbsp;<code>&quot;())&quot;</code>，&nbsp;<code>&quot;())(())))&quot;</code> 和&nbsp;<code>&quot;(())())))&quot;</code>&nbsp;都是平衡的，&nbsp;<code>&quot;)()&quot;</code>，&nbsp;<code>&quot;()))&quot;</code> 和&nbsp;<code>&quot;(()))&quot;</code>&nbsp;都是不平衡的。</p>

<p>你可以在任意位置插入字符 &#39;(&#39; 和 &#39;)&#39; 使字符串平衡。</p>

<p>请你返回让 <code>s</code>&nbsp;平衡的最少插入次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = &quot;(()))&quot;
<strong>输出：</strong>1
<strong>解释：</strong>第二个左括号有与之匹配的两个右括号，但是第一个左括号只有一个右括号。我们需要在字符串结尾额外增加一个 &#39;)&#39; 使字符串变成平衡字符串 &quot;(())))&quot; 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = &quot;())&quot;
<strong>输出：</strong>0
<strong>解释：</strong>字符串已经平衡了。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = &quot;))())(&quot;
<strong>输出：</strong>3
<strong>解释：</strong>添加 &#39;(&#39; 去匹配最开头的 &#39;))&#39; ，然后添加 &#39;))&#39; 去匹配最后一个 &#39;(&#39; 。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>s = &quot;((((((&quot;
<strong>输出：</strong>12
<strong>解释：</strong>添加 12 个 &#39;)&#39; 得到平衡字符串。
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>s = &quot;)))))))&quot;
<strong>输出：</strong>5
<strong>解释：</strong>在字符串开头添加 4 个 &#39;(&#39; 并在结尾添加 1 个 &#39;)&#39; ，字符串变成平衡字符串 &quot;(((())))))))&quot; 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
	<li><code>s</code>&nbsp;只包含&nbsp;<code>&#39;(&#39;</code> 和&nbsp;<code>&#39;)&#39;</code>&nbsp;。</li>
</ul>


    
## 解题方法一：左右括号匹配

11111

+ 时间复杂度$O(N^2)$
+ 空间复杂度$O(N\log N)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-10-09 10:59:38
 */
class Solution {
public:
    int minInsertions(const string& s) {
        int ans = 0;
        int diff = 0;
        for (size_t i = 0, n = s.size(); i < n; i++) {
            if (s[i] == '(') {
                diff++;
            } else {
                if (diff) {
                    diff--;
                } else {
                    ans++;
                }
                if (i + 1 < n && s[i + 1] == ')') {
                    i++;
                } else {
                    ans++;
                }
            }
        }
        return ans + diff * 2;
    }
};
```

#### Java

```java
/*
 * @LastEditTime: 2026-10-09 11:22:03
 */
class Solution {
    public int minInsertions(String s) {
        int ans = 0;
        int diff = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                diff++;
            } else {
                if (diff > 0) {
                    diff--;
                } else {
                    ans++;
                }
                if (i + 1 < s.length() && s.charAt(i + 1) == ')') {
                    i++;
                } else {
                    ans++;
                }
            }
        }
        return ans + diff * 2;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2026-10-09 11:19:46
 */
package main

func minInsertions(s string) (ans int) {
    diff := 0
    for i := 0; i < len(s); i++ {
        if s[i] == '(' {
            diff++
        } else {
            if diff > 0 {
                diff--
            } else {
                ans++
            }
            if i + 1 < len(s) && s[i + 1] == ')' {
                i++
            } else {
                ans++
            }
        }
    }
    return ans + diff * 2
}
```

## 解题方法二：不要看了，屎山代码

记录未匹配的左括号和右括号数量。

如果遇到左括号，left++，补全未配对的右括号：

1. 若右括号为奇数个，先补上一个
2. 抵消掉能抵消的括号
3. 如果右括号还有剩余，则补上对应数量一半的左括号

如果遇到右括号，right++：

1. 如果左括号已经不够抵消右括号，则补上所需左括号
2. 抵消掉能抵消的括号

相当于遇到右括号就看有无左括号，有就存一个或者直接抵消掉，没有就补上左括号；遇到左括号就清算右括号


+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-10-09 09:51:51
 */
class Solution {
private:
    int meetLeft(int& left, int& right) {
        int ans = 0;
        if (right % 2) {
            right++;
            ans++;
        }
        int loss = min(left, right / 2);
        left -= loss;
        right -= loss * 2;
        ans += right / 2;
        right = 0;
        return ans;
    }

    int meetRight(int& left, int& right) {
        int ans = 0;
        if ((right + 1) / 2 > left) {
            ans += (right + 1) / 2;
            left = (right + 1) / 2;
        }
        int loss = min(left, right / 2);
        left -= loss;
        right -= loss * 2;
        return ans;
    }
public:
    int minInsertions(const string& s) {
        int ans = 0;
        int left = 0, right = 0;
        for (char c : s) {
            if (c == '(') {
                ans += meetLeft(++left, right);
            } else {
                ans += meetRight(left, ++right);
            }
        }
        ans += meetLeft(left, right);
        ans += left * 2;
        return ans;
    }
};
```

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/--------------------------)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/10/10/LeetCode%201541.%E5%B9%B3%E8%A1%A1%E6%8B%AC%E5%8F%B7%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9A%84%E6%9C%80%E5%B0%91%E6%8F%92%E5%85%A5%E6%AC%A1%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
