---
title: 2131.连接两字母单词得到的最长回文串：分类讨论(贪心)
date: 2025-05-25 23:56:17
tags: [题解, LeetCode, 中等, 贪心, 数组, 哈希表, 字符串, 计数, 回文, 回文串]
categories: [题解, LeetCode]
---

# 【LetMeFly】2131.连接两字母单词得到的最长回文串：分类讨论(贪心)

力扣题目链接：[https://leetcode.cn/problems/longest-palindrome-by-concatenating-two-letter-words/](https://leetcode.cn/problems/longest-palindrome-by-concatenating-two-letter-words/)

<p>给你一个字符串数组&nbsp;<code>words</code>&nbsp;。<code>words</code>&nbsp;中每个元素都是一个包含 <strong>两个</strong>&nbsp;小写英文字母的单词。</p>

<p>请你从 <code>words</code>&nbsp;中选择一些元素并按 <b>任意顺序</b>&nbsp;连接它们，并得到一个 <strong>尽可能长的回文串</strong>&nbsp;。每个元素 <strong>至多</strong>&nbsp;只能使用一次。</p>

<p>请你返回你能得到的最长回文串的 <strong>长度</strong>&nbsp;。如果没办法得到任何一个回文串，请你返回 <code>0</code>&nbsp;。</p>

<p><strong>回文串</strong>&nbsp;指的是从前往后和从后往前读一样的字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>words = ["lc","cl","gg"]
<b>输出：</b>6
<b>解释：</b>一个最长的回文串为 "lc" + "gg" + "cl" = "lcggcl" ，长度为 6 。
"clgglc" 是另一个可以得到的最长回文串。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>words = ["ab","ty","yt","lc","cl","ab"]
<b>输出：</b>8
<strong>解释：</strong>最长回文串是 "ty" + "lc" + "cl" + "yt" = "tylcclyt" ，长度为 8 。
"lcyttycl" 是另一个可以得到的最长回文串。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>words = ["cc","ll","xx"]
<b>输出：</b>2
<b>解释：</b>最长回文串是 "cc" ，长度为 2 。
"ll" 是另一个可以得到的最长回文串。"xx" 也是。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 10<sup>5</sup></code></li>
	<li><code>words[i].length == 2</code></li>
	<li><code>words[i]</code>&nbsp;仅包含小写英文字母。</li>
</ul>


    
## 解题方法：分类讨论

### 解题思路

有的字符串自对称(如`aa`)，有的字符串非自对称(如`ab`)。

非对称的字符串只能和和它对称的字符串放到对称的位置(如`ab**ba`)，而自对称的字符串不但能和自身放到对称的位置(如`aa**aa`)也可以自身单独放到最中间的位置(如`**aa**`)。

但是，在整个最终构造的字符串中，自对称放字符串放到最中间的至多只能有一个。

### 具体方法

使用一个哈希表或`26x26`大小的数组统计每种字符串的出现次数。

使用变量`i`从`0`到`25`遍历：

> 首先对于自对称的字符串(如`aa`)，假设有$n$个，则可以拿$\lfloor\frac{n}2\rfloor$对放到对称的位置。若$n$为奇数，则还可以保留一个放到最中间的位置。
>
> 接着使用变量`j`从`i+1`到`26`遍历，可以互相放到对称位置的字符串一共有$\min(times[i][j], times[j][i])$对。

最终，由于中间位置最多只能放一对，所以$(对称对数\times2+中间个数)\times 2$即为所求。

### 时空复杂度分析

+ 时间复杂度$O(N^2)$
+ 空间复杂度$O(N\log N)$

### AC代码

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-05-25 23:39:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-25 23:54:22
 */
package main

func longestPalindrome(words []string) int {
    times := make([][]int, 26)
    for i := range times {
        times[i] = make([]int, 26)
    }
    for _, word := range words {
        times[word[0] - 'a'][word[1] - 'a']++
    }
    side, mid := 0, 0
    for i := range times {
        side += times[i][i] / 2 * 2
        mid |= times[i][i] % 2
        for j := i + 1; j < 26; j++ {
            side += min(times[i][j], times[j][i]) * 2
        }
    }
    return (side + mid) * 2
}
```

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-05-25 23:39:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-26 00:04:19
 */
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int cnt[26][26] = {0};
        for (string& word : words) {
            cnt[word[0] - 'a'][word[1] - 'a']++;
        }
        int ans = 0, middle = 0;
        for (int i = 0; i < 26; i++) {
            ans += cnt[i][i] / 2 * 2;
            middle |= cnt[i][i] % 2;
            for (int j = i + 1; j < 26; j++) {
                ans += min(cnt[i][j], cnt[j][i]) * 2;
            }
        }
        return (ans + middle) * 2;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-05-25 23:39:17
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-25 23:47:11
'''
from typing import List

class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        cnt = [[0] * 26 for _ in range(26)]
        for word in words:
            cnt[ord(word[0]) - ord('a')][ord(word[1]) - ord('a')] += 1
        ans = middle = 0
        for i in range(26):
            ans += cnt[i][i] // 2 * 2
            middle |= cnt[i][i] % 2
            for j in range(i + 1, 26):
                ans += min(cnt[i][j], cnt[j][i]) * 2
        return (ans + middle) * 2
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-05-25 23:39:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-25 23:51:33
 */
class Solution {
    public int longestPalindrome(String[] words) {
        int[][] times = new int[26][26];
        for (String word : words) {
            times[word.charAt(0) - 'a'][word.charAt(1) - 'a']++;
        }
        int side = 0, middle = 0;
        for (int i = 0; i < 26; i++) {
            side += times[i][i] / 2 * 2;
            middle |= times[i][i] % 2;
            for (int j = i + 1; j < 26; j++) {
                side += Math.min(times[i][j], times[j][i]) * 2;
            }
        }
        return (side + middle) * 2;
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/148216376)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/05/25/LeetCode%202131.%E8%BF%9E%E6%8E%A5%E4%B8%A4%E5%AD%97%E6%AF%8D%E5%8D%95%E8%AF%8D%E5%BE%97%E5%88%B0%E7%9A%84%E6%9C%80%E9%95%BF%E5%9B%9E%E6%96%87%E4%B8%B2/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)

（最近CSDN发文时咋不出默认封面图了）
