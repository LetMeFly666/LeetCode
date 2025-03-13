---
title: 3146.两个字符串的排列差
date: 2024-08-24 12:31:12
tags: [题解, LeetCode, 简单, 哈希表, 字符串, 遍历, 模拟, 暴力]
categories: [题解, LeetCode]
---

# 【LetMeFly】3146.两个字符串的排列差：小数据，我选择暴力模拟

力扣题目链接：[https://leetcode.cn/problems/permutation-difference-between-two-strings/](https://leetcode.cn/problems/permutation-difference-between-two-strings/)

<p>给你两个字符串 <code>s</code> 和 <code>t</code>，每个字符串中的字符都不重复，且 <code>t</code> 是 <code>s</code> 的一个排列。</p>

<p><strong>排列差</strong> 定义为 <code>s</code> 和 <code>t</code> 中每个字符在两个字符串中位置的绝对差值之和。</p>

<p>返回 <code>s</code> 和 <code>t</code> 之间的<strong> 排列差 </strong>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "abc", t = "bac"</span></p>

<p><strong>输出：</strong><span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p>对于 <code>s = "abc"</code> 和 <code>t = "bac"</code>，排列差是：</p>

<ul>
	<li><code>"a"</code> 在 <code>s</code> 中的位置与在 <code>t</code> 中的位置之差的绝对值。</li>
	<li><code>"b"</code> 在 <code>s</code> 中的位置与在 <code>t</code> 中的位置之差的绝对值。</li>
	<li><code>"c"</code> 在 <code>s</code> 中的位置与在 <code>t</code> 中的位置之差的绝对值。</li>
</ul>

<p>即，<code>s</code> 和 <code>t</code> 的排列差等于 <code>|0 - 1| + |2 - 2| + |1 - 0| = 2</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "abcde", t = "edbac"</span></p>

<p><strong>输出：</strong><span class="example-io">12</span></p>

<p><strong>解释：</strong> <code>s</code> 和 <code>t</code> 的排列差等于 <code>|0 - 3| + |1 - 2| + |2 - 4| + |3 - 1| + |4 - 0| = 12</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 26</code></li>
	<li>每个字符在 <code>s</code> 中最多出现一次。</li>
	<li><code>t</code> 是 <code>s</code> 的一个排列。</li>
	<li><code>s</code> 仅由小写英文字母组成。</li>
</ul>


    
## 解题方法：暴力模拟

使用一个初始值位0的整型变量$ans$记录差值之和。

遍历字符串s中的每一个字符：

> 对于当前字符s[i]，遍历字符串t。如果t[j]和s[i]相同，则令ans加上$i-j$的绝对值并结束对字符串t的遍历。

最终返回$ans$的值即为答案。

+ 时间复杂度$O(len(s)^2)$
+ 空间复杂度$O(1)$

字符串的最大长度为26，最多匹配$1+2+3+\cdots+26=\frac{(1+26)\times26}2=351$次，因此使用哈希表的意义不大。

### AC代码

#### C++

```cpp
class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < t.size(); j++) {
                if (t[j] == s[i]) {
                    ans += abs(i - j);
                    break;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
package main

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

func findPermutationDifference(s string, t string) int {
    ans := 0
    for i := 0; i < len(s); i++ {
        for j := 0; j < len(t); j++ {
            if s[i] == t[j] {
                ans += abs(i - j)
                break
            }
        }
    }
    return ans
}
```

#### Java

```java
class Solution {
    public int findPermutationDifference(String s, String t) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            ans += Math.abs(i - t.indexOf(s.charAt(i)));
        }
        return ans;
    }
}
```

#### Python

```python
class Solution:
    def findPermutationDifference(self, s: str, t: str) -> int:
        ans = 0
        for i in range(len(s)):
            ans += abs(i - t.find(s[i]))
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/08/24/LeetCode%203146.%E4%B8%A4%E4%B8%AA%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9A%84%E6%8E%92%E5%88%97%E5%B7%AE/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/141497994](https://letmefly.blog.csdn.net/article/details/141497994)
