---
title: 3442.奇偶频次间的最大差值 I：计数
date: 2025-06-10 23:41:55
tags: [题解, LeetCode, 简单, 哈希表, 字符串, 计数]
categories: [题解, LeetCode]
---

# 【LetMeFly】3442.奇偶频次间的最大差值 I：计数

力扣题目链接：[https://leetcode.cn/problems/maximum-difference-between-even-and-odd-frequency-i/](https://leetcode.cn/problems/maximum-difference-between-even-and-odd-frequency-i/)

<p>给你一个由小写英文字母组成的字符串&nbsp;<code>s</code> 。请你找出字符串中两个字符的出现频次之间的 <strong>最大</strong> 差值，这两个字符需要满足：</p>

<ul>
	<li>一个字符在字符串中出现 <strong>偶数次</strong> 。</li>
	<li>另一个字符在字符串中出现 <strong>奇数次</strong>&nbsp;。</li>
</ul>

<p>返回 <strong>最大</strong> 差值，计算方法是出现 <strong>奇数次</strong> 字符的次数 <strong>减去</strong> 出现 <strong>偶数次</strong> 字符的次数。</p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "aaaaabbc"</span></p>

<p><b>输出：</b>3</p>

<p><b>解释：</b></p>

<ul>
	<li>字符&nbsp;<code>'a'</code>&nbsp;出现 <strong>奇数次</strong>&nbsp;，次数为&nbsp;<code><font face="monospace">5</font></code><font face="monospace"> ；字符</font>&nbsp;<code>'b'</code>&nbsp;出现 <strong>偶数次</strong> ，次数为&nbsp;<code><font face="monospace">2</font></code>&nbsp;。</li>
	<li>最大差值为&nbsp;<code>5 - 2 = 3</code>&nbsp;。</li>
</ul>
</div>

<p><b>示例 2：</b></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "abcabcab"</span></p>

<p><b>输出：</b>1</p>

<p><b>解释：</b></p>

<ul>
	<li>字符&nbsp;<code>'a'</code>&nbsp;出现 <strong>奇数次</strong>&nbsp;，次数为&nbsp;<code><font face="monospace">3</font></code><font face="monospace"> ；字符</font>&nbsp;<code>'c'</code>&nbsp;出现 <strong>偶数次</strong>&nbsp;，次数为&nbsp;<font face="monospace">2 。</font></li>
	<li>最大差值为&nbsp;<code>3 - 2 = 1</code> 。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>3 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code>&nbsp;仅由小写英文字母组成。</li>
	<li><code>s</code>&nbsp;至少由一个出现奇数次的字符和一个出现偶数次的字符组成。</li>
</ul>


    
## 解题方法：计数

遍历一遍字符串，统计出每种字符的出现次数。

遍历英文单词的每种字符：

+ 若这种字符出现次数为奇数次，则更新a1的值
+ 否则若这种字符出现次数大于0，则更新a2的值

最终返回$a_1-a_2$。

+ 时间复杂度$O(len(s)+C)$，其中$C=26$
+ 空间复杂度$O(C)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-06-10 23:07:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-10 23:14:08
 */
class Solution {
public:
    int maxDifference(string s) {
        int cnt[26] = {0};
        for (char c : s) {
            cnt[c - 'a']++;
        }
        int a1 = 0, a2 = 100;
        for (int c : cnt) {
            if (c % 2) {
                a1 = max(a1, c);
            } else if (c) {
                a2 = min(a2, c);
            }
        }
        return a1 - a2;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-06-10 23:07:14
LastEditors: LetMeFly.xyz
LastEditTime: 2025-06-10 23:18:45
'''
from collections import Counter

class Solution:
    def maxDifference(self, s: str) -> int:
        cnt = Counter(s)
        return max(v for v in cnt.values() if v % 2) - min(v for v in cnt.values() if v % 2 == 0)
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-06-10 23:07:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-10 23:40:04
 */
class Solution {
    public int maxDifference(String s) {
        int[] cnt = new int[26];
        for (char c : s.toCharArray()) {
            cnt[c - 'a']++;
        }
        int a1 = 0, a2 = 100;
        for (int t : cnt) {
            if (t % 2 == 1) {
                a1 = Math.max(a1, t);
            } else if (t > 0) {
                a2 = Math.min(a2, t);
            }
        }
        return a1 - a2;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-06-10 23:07:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-10 23:20:56
 */
package main

func maxDifference(s string) int {
    cnt := [26]int{}
    for _, c := range s {
        cnt[c - 'a']++
    }
    a1, a2 := 0, 100
    for _, t := range cnt {
        if t % 2 == 1 {
            a1 = max(a1, t)
        } else if t > 0 {
            a2 = min(a2, t)
        }
    }
    return a1 - a2
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/148570777)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/06/10/LeetCode%203442.%E5%A5%87%E5%81%B6%E9%A2%91%E6%AC%A1%E9%97%B4%E7%9A%84%E6%9C%80%E5%A4%A7%E5%B7%AE%E5%80%BCI/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
