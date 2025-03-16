---
title: 2272.最大波动的子字符串：转为多次的最大子数组和 - 一步步思考推导
date: 2025-03-16 11:23:56
tags: [题解, LeetCode, 困难, 数组, 动态规划, DP, 字符串]
categories: [题解, LeetCode]
---

# 【LetMeFly】2272.最大波动的子字符串：转为多次的最大子数组和 - 一步步思考推导

力扣题目链接：[https://leetcode.cn/problems/substring-with-largest-variance/](https://leetcode.cn/problems/substring-with-largest-variance/)

<p>字符串的 <strong>波动</strong>&nbsp;定义为子字符串中出现次数 <strong>最多</strong>&nbsp;的字符次数与出现次数 <strong>最少</strong>&nbsp;的字符次数之差。</p>

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;，它只包含小写英文字母。请你返回 <code>s</code>&nbsp;里所有 <strong>子字符串的</strong>&nbsp;<strong>最大波动</strong>&nbsp;值。</p>

<p><strong>子字符串</strong> 是一个字符串的一段连续字符序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>s = "aababbb"
<b>输出：</b>3
<strong>解释：</strong>
所有可能的波动值和它们对应的子字符串如以下所示：
- 波动值为 0 的子字符串："a" ，"aa" ，"ab" ，"abab" ，"aababb" ，"ba" ，"b" ，"bb" 和 "bbb" 。
- 波动值为 1 的子字符串："aab" ，"aba" ，"abb" ，"aabab" ，"ababb" ，"aababbb" 和 "bab" 。
- 波动值为 2 的子字符串："aaba" ，"ababbb" ，"abbb" 和 "babb" 。
- 波动值为 3 的子字符串 "babbb" 。
所以，最大可能波动值为 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>s = "abcde"
<b>输出：</b>0
<strong>解释：</strong>
s 中没有字母出现超过 1 次，所以 s 中每个子字符串的波动值都是 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code>&nbsp; 只包含小写英文字母。</li>
</ul>

很不错的一道题。

## 解题方法：动态规划

做本题之前推荐先做一下[53. 最大子数组和](https://leetcode.cn/problems/maximum-subarray/)：

> 一个数组中元素有正有负，如何求其非空子数组和的最大值呢？
>
> 遍历数组并使用一个变量$cnt$统计即可。
>
> 对于当前元素a，可以选择在前面子数组的基础上加上这个元素($cnt + a$)，也可以选择丢弃前面子数组而从这个元素重新开始($a$)。
>
> 因此有状态转移方程$cnt = \max(cnt + a, a)$。

本题如何转为多次的“最大子数组”呢？本题的子数组只需要考虑出现次数最多和出现次数最少的两个元素，因此我直接两层循环枚举所有的“最多元素a”和“最少元素b”不就行了吗？

> 假设出现次数最多的元素是a，出现次数最少的元素是b。因为我们最终求的是$count(a) - count(b)$，所以我们可以将a赋值为1，将b赋值为-1，其他元素直接无视（或赋值为0）。
>
> 之后按照“最大子数组和”的方式求解，是不是就可以了？

不可以，因为“最多次数的a减去最少次数的b”的前提是“子数组中出现了b”。若子数组中全是a，那么出现次数最少的元素并非0次，而是同样为a次。也就是说，我们还需要想办法保证子数组中出现了b。

> “最大子数组和”我们使用了一个变量cnt，本题我们可以使用两个变量$mayNoB$和$hasB$，分别表示子数组中可能不包含b和子数组中一定包含b时的“最大波动”。
>
> 因为mayNoB代表的子数组可以出现B也可以不出现B，所以mayNoB就和“最大子数组和”一样，无脑$mayNoB = \max(mayNoB + t, t)$即可（$t$是字符的映射值$1$或者$-1$或者$0$）。
>
> 但是hasB就比较有意思了，它要求子数组中必须有b，怎么办呢？也很好说，把hasB的初始值定义为“无穷小”就好了。
>
> + 若当前元素为b，则$hasB = mayNoB$，因为$mayNoB$一旦包含当前元素b就一定$hasB$了（其实是$hasB = max(hasB, mayNoB)$，但由于“可能不包含b”一定不小于“必须包含b”，所以可以直接简写为$hasB=mayNoB$）
> + 若当前元素为a，则$hasB += 1$（若从未出现过元素b，则hasB即使加一也仍是无穷小，不影响后续答案的更新）
>
> 更新答案$ans = max(ans, hasB)$

+ 时间复杂度$O(len(s)\times C^2)$，其中$C=26$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-16 10:43:25
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-16 11:03:26
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // WA - 例如baa，一个变量会导致不选b，而只有aa虽然cnt比较大但不一定最优
class Solution {
public:
    int largestVariance(string s) {
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            char a = i + 'a';
            for (int j = 0; j < 26; j++) {
                char b = j + 'a';
                int cnt = 0;
                bool hasB = false;
                for (char c : s) {
                    if (c == a) {
                        cnt++;
                    } else if (c == b) {
                        // cnt = max(cnt - 1, 0);
                        if (cnt - 1 >= 0) {
                            cnt--;
                            hasB = true;
                        } else {
                            cnt = 0;
                            hasB = false;
                        }
                    }
                    if (hasB) {
                        ans = max(ans, cnt);
                    }
                }
                // printf("a = %c, b = %c, ans = %d\n", a, b, ans);
            }
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry
class Solution {
public:
    int largestVariance(string s) {
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            char a = i + 'a';
            for (int j = 0; j < 26; j++) {
                char b = j + 'a';
                int mayNoB = 0, hasB = -10000000;
                for (char c : s) {
                    if (c == a) {
                        mayNoB = max(mayNoB + 1, 1);
                        hasB++;
                    } else if (c == b) {
                        mayNoB = max(mayNoB - 1, -1);
                        hasB = mayNoB;
                    }
                    ans = max(ans, hasB);
                }
            }
        }
        return ans;
    }
};
#endif  // FirstTry
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-03-16 11:06:25
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-16 11:09:05
'''
class Solution:
    def largestVariance(self, s: str) -> int:
        ans = 0
        for i in range(26):
            a = chr(i + ord('a'))
            for j in range(26):
                b = chr(j + ord('a'))
                mayNoB, hasB = 0, -100000
                for c in s:
                    if c == a:
                        mayNoB = max(mayNoB + 1, 1)
                        hasB += 1
                    elif c == b:
                        mayNoB = max(mayNoB - 1, -1)
                        hasB = mayNoB
                    ans = max(ans, hasB)
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-03-16 11:09:39
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-16 11:13:27
 */
class Solution {
    public int largestVariance(String s) {
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            char a = (char)(i + 'a');
            for (int j = 0; j < 26; j++) {
                char b = (char)(j + 'a');
                int mayNoB = 0, hasB = -10000000;
                for (char c : s.toCharArray()) {
                    if (c == a) {
                        mayNoB = Math.max(mayNoB + 1, 1);
                        hasB++;
                    } else if (c == b) {
                        mayNoB = Math.max(mayNoB - 1, -1);
                        hasB = mayNoB;
                    }
                    ans = Math.max(ans, hasB);
                }
            }
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-03-16 11:14:38
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-16 11:18:01
 */
package main

func largestVariance(s string) (ans int) {
    for i := byte(0); i < 26; i++ {
        a := i + 'a'
        for j := byte(0); j < 26; j++ {
            b := j + 'a'
            mayNoB, hasB := 0, -10000000
            for _, c := range s {
                if byte(c) == a {
                    mayNoB = max(mayNoB + 1, 1)
                    hasB++
                } else if byte(c) == b {
                    mayNoB = max(mayNoB - 1, -1)
                    hasB = mayNoB
                }
                ans = max(ans, hasB)
            }
        }
    }
    return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/146292731)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/03/16/LeetCode%202272.%E6%9C%80%E5%A4%A7%E6%B3%A2%E5%8A%A8%E7%9A%84%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
