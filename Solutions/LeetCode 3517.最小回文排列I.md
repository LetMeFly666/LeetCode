---
title: 3517.最小回文排列 I：排序（Python两行版） / 计数（O(n)时间+O(C)空间+字符串原地修改）
date: 2026-07-28 21:47:29
tags: [题解, LeetCode, 中等, 字符串, 计数排序, 排序, 回文, 回文串]
categories: [题解, LeetCode]
---

# 【LetMeFly】3517.最小回文排列 I：排序（Python两行版） / 计数（O(n)时间+O(C)空间+字符串原地修改）

力扣题目链接：[https://leetcode.cn/problems/smallest-palindromic-rearrangement-i/](https://leetcode.cn/problems/smallest-palindromic-rearrangement-i/)

<p>给你一个&nbsp;<strong>回文&nbsp;</strong>字符串 <code>s</code>。</p>

<p>返回 <code>s</code> 的按字典序排列的&nbsp;<strong>最小&nbsp;</strong>回文排列。</p>

<p>如果一个字符串从前往后和从后往前读都相同，那么这个字符串是一个&nbsp;<strong>回文 </strong>字符串。</p>

<p><strong>排列&nbsp;</strong>是字符串中所有字符的重排。</p>
如果字符串 <code>a</code> 按字典序小于字符串 <code>b</code>，则表示在第一个不同的位置，<code>a</code> 中的字符比 <code>b</code> 中的对应字符在字母表中更靠前。<br />
如果在前 <code>min(a.length, b.length)</code> 个字符中没有区别，则较短的字符串按字典序更小。

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">s = "z"</span></p>

<p><strong>输出：</strong> <span class="example-io">"z"</span></p>

<p><strong>解释：</strong></p>

<p>仅由一个字符组成的字符串已经是按字典序最小的回文。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">s = "babab"</span></p>

<p><strong>输出：</strong> <span class="example-io">"abbba"</span></p>

<p><strong>解释：</strong></p>

<p>通过重排 <code>"babab"</code> → <code>"abbba"</code>，可以得到按字典序最小的回文。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">s = "daccad"</span></p>

<p><strong>输出：</strong> <span class="example-io">"acddca"</span></p>

<p><strong>解释：</strong></p>

<p>通过重排 <code>"daccad"</code> → <code>"acddca"</code>，可以得到按字典序最小的回文。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> 由小写英文字母组成。</li>
	<li>保证 <code>s</code> 是回文字符串。</li>
</ul>


    
## 解题方法一：计数

使用一个长度为26的数组统计原始字符串中每个字符都出现了多少次。

如果字符串长度为偶数：

> 从`a`到`z`遍历计数数组，将$\lfloor\frac{该字符出现次数}{2}\rfloor$个该字符拼接到答案字符串中；再从`z`到`a`遍历计数数组并再这样添加一次。

如果字符串长度为奇数，除了上述操作之外，还需要：

> 记下原始字符串中间字符，从`a`到`z`遍历后将该中间字符拼接到答案字符串的中间，之后再开始倒序遍历。
> 
> 这是因为回文字符串长度为奇数的话中间的那个字符一定出现了奇数次，最终组成的回文字符串最中间的字符也一定是这个字符。

也可以直接原地替换掉参数字符串。

+ 时间复杂度$O(len(s)+C)$，其中$C=26$
+ 空间复杂度$O(C)$，也可以粗略地认为是$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-07-28 21:41:30
 */
class Solution {
public:
    string smallestPalindrome(string& s) {
        int cnt[26] = {0};
        for (char c : s) {
            cnt[c - 'a']++;
        }
        
        char middle = 0;
        if (s.size() % 2) {
            middle = s[s.size() / 2];
        }

        int idx = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < cnt[i] / 2; j++) {
                s[idx++] = i + 'a';
            }
        }
        if (middle) {
            s[idx++] = middle;
        }
        for (int i = 25; i >= 0; i--) {
            for (int j = 0; j < cnt[i] / 2; j++) {
                s[idx++] = i + 'a';
            }
        }

        return s;
    }
};
```

## 解题方法二：排序

由于给定的字符串已经是回文字符串（前后对称），所以我们直接把前半个字符串排个序，reverse后拼接到后面就行了。

如果字符串长度为奇数，则最中间字符保持不变。

+ 时间复杂度$O(n\log n)$，，其中$n=len(s)$
+ 空间复杂度$O(n)$

### AC代码

#### Python

```python
'''
LastEditTime: 2026-07-28 21:46:51
'''
class Solution:
    def smallestPalindrome(self, s: str) -> str:
        t = sorted(s[: len(s) // 2])
        return ''.join(t) + (s[len(s) // 2] if len(s) % 2 else '') + ''.join(reversed(t))
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/163282386)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/07/28/LeetCode%203517.%E6%9C%80%E5%B0%8F%E5%9B%9E%E6%96%87%E6%8E%92%E5%88%97I/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
