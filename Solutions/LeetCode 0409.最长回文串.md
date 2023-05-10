---
title: 409.最长回文串
date: 2022-10-17 10:51:16
tags: [题解, LeetCode, 简单, 贪心, 哈希表, 字符串, 回文, 回文串]
---

# 【LetMeFly】409.最长回文串

力扣题目链接：[https://leetcode.cn/problems/longest-palindrome/](https://leetcode.cn/problems/longest-palindrome/)

<p>给定一个包含大写字母和小写字母的字符串<meta charset="UTF-8" />&nbsp;<code>s</code>&nbsp;，返回&nbsp;<em>通过这些字母构造成的 <strong>最长的回文串</strong></em>&nbsp;。</p>

<p>在构造过程中，请注意 <strong>区分大小写</strong> 。比如&nbsp;<code>"Aa"</code>&nbsp;不能当做一个回文字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1: </strong></p>

<pre>
<strong>输入:</strong>s = "abccccdd"
<strong>输出:</strong>7
<strong>解释:</strong>
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong>s = "a"
<strong>输入:</strong>1
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong>s = "bb"
<strong>输入:</strong> 2
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 2000</code></li>
	<li><code>s</code>&nbsp;只能由小写和/或大写英文字母组成</li>
</ul>


    
## 方法一：统计

char类型的数据最多有256种，因此我们可以开辟一个大小为256的数组，分别统计字符串中每种字符的出现次数。

想要构成回文串，就尽量“前后一致且对应”

只要某个字符每出现两次，我们就可以将这两个字符一前一后地对称起来。

同时，回文串的长度如果是奇数，那么回文串最中间的那个字符可以没有其他字符与其对称，也就是说“自我对称”

但是“最中间”的字符最多有一个。

因此我们遍历一遍256个字符，将每种字符出现次数的偶数部分累加进答案。

如果存在出现奇数次的字符，就将答案的长度再加一。

+ 时间复杂度$O(n+C)$，其中$n$是字符串长度，$C$是字符种类数（这里取所有单字节字符的种类数$2^8=256$）
+ 空间复杂度$O(C)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int longestPalindrome(string& s) {
        int cnt[256] = {0};
        for (char& c : s) {
            cnt[c]++;
        }
        bool hasOdd = false;
        int ans = 0;
        for (int i = 0; i < 256; i++) {
            if (cnt[i] % 2) {
                hasOdd = true;
                ans += cnt[i] - 1;
            }
            else {
                ans += cnt[i];
            }
        }
        ans += hasOdd;
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/10/17/LeetCode%200409.%E6%9C%80%E9%95%BF%E5%9B%9E%E6%96%87%E4%B8%B2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127359550](https://letmefly.blog.csdn.net/article/details/127359550)
