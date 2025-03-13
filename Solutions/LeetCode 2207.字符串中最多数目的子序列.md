---
title: 2207.字符串中最多数目的子序列
date: 2024-09-24 18:56:50
tags: [题解, LeetCode, 中等, 贪心, 字符串, 前缀和]
categories: [题解, LeetCode]
---

# 【LetMeFly】2207.字符串中最多数目的子序列：计数

力扣题目链接：[https://leetcode.cn/problems/maximize-number-of-subsequences-in-a-string/](https://leetcode.cn/problems/maximize-number-of-subsequences-in-a-string/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的字符串&nbsp;<code>text</code>&nbsp;和另一个下标从 <strong>0</strong>&nbsp;开始且长度为 <code>2</code>&nbsp;的字符串&nbsp;<code>pattern</code>&nbsp;，两者都只包含小写英文字母。</p>

<p>你可以在 <code>text</code>&nbsp;中任意位置插入 <strong>一个</strong> 字符，这个插入的字符必须是&nbsp;<code>pattern[0]</code>&nbsp;<b>或者</b>&nbsp;<code>pattern[1]</code>&nbsp;。注意，这个字符可以插入在 <code>text</code>&nbsp;开头或者结尾的位置。</p>

<p>请你返回插入一个字符后，<code>text</code>&nbsp;中最多包含多少个等于 <code>pattern</code>&nbsp;的 <strong>子序列</strong>&nbsp;。</p>

<p><strong>子序列</strong> 指的是将一个字符串删除若干个字符后（也可以不删除），剩余字符保持原本顺序得到的字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>text = "abdcdbc", pattern = "ac"
<b>输出：</b>4
<strong>解释：</strong>
如果我们在 text[1] 和 text[2] 之间添加 pattern[0] = 'a' ，那么我们得到 "ab<em><strong>a</strong></em>dcdbc" 。那么 "ac" 作为子序列出现 4 次。
其他得到 4 个 "ac" 子序列的方案还有 "<em><strong>a</strong></em>abdcdbc" 和 "abd<em><strong>a</strong></em>cdbc" 。
但是，"abdc<em><strong>a</strong></em>dbc" ，"abd<em><strong>c</strong></em>cdbc" 和 "abdcdbc<em><strong>c</strong></em>" 这些字符串虽然是可行的插入方案，但是只出现了 3 次 "ac" 子序列，所以不是最优解。
可以证明插入一个字符后，无法得到超过 4 个 "ac" 子序列。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>text = "aabb", pattern = "ab"
<b>输出：</b>6
<strong>解释：</strong>
可以得到 6 个 "ab" 子序列的部分方案为 "<em><strong>a</strong></em>aabb" ，"aa<em><strong>a</strong></em>bb" 和 "aab<em><strong>b</strong></em>b" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 10<sup>5</sup></code></li>
	<li><code>pattern.length == 2</code></li>
	<li><code>text</code> 和&nbsp;<code>pattern</code>&nbsp;都只包含小写英文字母。</li>
</ul>


    
## 解题方法：计数

首先考虑不能往字符串中添加一个字符的情况，应该怎么做呢？

> 使用两个变量`cnt0`和`cnt1`分别记录`pattern[0]`和`pattern[1]`出现了多少次，使用`ans`记录答案数量。
>
> 遍历字符串，如果当前字符和`pattern[1]`相同，那么`ans += cnt0`（这是因为之前的每个`pattern[0]`都可以和当前字符组成`pattern`，并且`cnt1 += 1`；
> 
> 如果当前字符和`pattern[0]`相同，那么`cnt0 += 1`。

很好，现在考虑可以往字符串中添加一个字符的情况，要把字符加到哪里呢？

> 如果要添加`pattern[0]`到字符串中，那么肯定要将`pattern[0]`添加到字符串开头，这样后面每个`pattern[1]`都可以和开头新增的这个`pattern[0]`组成`pattern`，答案数量增加`cnt1`（有多少个`pattern[1]`技能多组成多少个`pattern`）；
>
> 如果要添加`pattern[1]`到字符串中，那么肯定要添加到字符串尾，这样答案数量就会增加`cnt0`。

也就是说，往字符串中添加一个字符，最多可以令答案增加`max(cnt0, cnt1)`。

+ 时间复杂度$O(len(text))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
typedef long long ll;

class Solution {
public:
    ll maximumSubsequenceCount(string text, string pattern) {
        ll ans = 0;
        ll cnt0= 0, cnt1 = 0;
        for (char c : text) {
            if (c == pattern[1]) {
                cnt1++;
                ans += cnt0;
            }
            if (c == pattern[0]) {
                cnt0++;
            }
        }
        return ans + max(cnt0, cnt1);
    }
};
```

#### Go

```go
package main

func maximumSubsequenceCount(text string, pattern string) int64 {
    ans, cnt0, cnt1 := int64(0), int64(0), int64(0)
    for i := range text  {
        if text[i] == pattern[1] {
            ans += cnt0
            cnt1++
        }
        if text[i] == pattern[0] {
            cnt0++
        }
    }
    if cnt0 > cnt1 {
        ans += cnt0
    } else {
        ans += cnt1
    }
    return ans
}
```

#### Java

```java
class Solution {
    public long maximumSubsequenceCount(String text, String pattern) {
        long ans = 0, cnt0 = 0, cnt1 = 0;
        for (char c : text.toCharArray()) {
            if (c == pattern.charAt(1)) {
                ans += cnt0;
                cnt1++;
            }
            if (c == pattern.charAt(0)) {
                cnt0++;
            }
        }
        return ans + Math.max(cnt0, cnt1);
    }
}
```

#### Python

```python
class Solution:
    def maximumSubsequenceCount(self, text: str, pattern: str) -> int:
        ans = cnt0 = cnt1 = 0
        for c in text:
            if c == pattern[1]:
                ans += cnt0
                cnt1 += 1
            if c == pattern[0]:
                cnt0 += 1
        return ans + max(cnt0, cnt1)
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/09/24/LeetCode%202207.%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E6%9C%80%E5%A4%9A%E6%95%B0%E7%9B%AE%E7%9A%84%E5%AD%90%E5%BA%8F%E5%88%97/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/142497503](https://letmefly.blog.csdn.net/article/details/142497503)
