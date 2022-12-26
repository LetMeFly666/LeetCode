---
title: 1759.统计同构子字符串的数目
date: 2022-12-26 16:37:49
tags: [题解, LeetCode, 中等, 数学, 字符串, 遍历]
---

# 【LetMeFly】1759.统计同构子字符串的数目

力扣题目链接：[https://leetcode.cn/problems/count-number-of-homogenous-substrings/](https://leetcode.cn/problems/count-number-of-homogenous-substrings/)

<p>给你一个字符串 <code>s</code> ，返回<em> </em><code>s</code><em> </em>中 <strong>同构子字符串</strong> 的数目。由于答案可能很大，只需返回对 <code>10<sup>9</sup> + 7</code> <strong>取余 </strong>后的结果。</p>

<p><strong>同构字符串</strong> 的定义为：如果一个字符串中的所有字符都相同，那么该字符串就是同构字符串。</p>

<p><strong>子字符串</strong> 是字符串中的一个连续字符序列。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "abbcccaa"
<strong>输出：</strong>13
<strong>解释：</strong>同构子字符串如下所列：
"a"   出现 3 次。
"aa"  出现 1 次。
"b"   出现 2 次。
"bb"  出现 1 次。
"c"   出现 3 次。
"cc"  出现 2 次。
"ccc" 出现 1 次。
3 + 1 + 2 + 1 + 3 + 2 + 1 = 13</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "xy"
<strong>输出：</strong>2
<strong>解释：</strong>同构子字符串是 "x" 和 "y" 。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "zzzzz"
<strong>输出：</strong>15
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> 由小写字符串组成</li>
</ul>


    
## 方法一：遍历统计

“同构”要求字符串中的所有字符必须相同；“子串”要求字符串必须连续。

所以，目标明确了，这不就是让我们统计原串中的“连续且相同子串”吗？

我们需要做的，是将原串“abbddd”解析为“1个a”、“2个b”、“3个d”。

接下来问题就变成了，连续的“n个a”，有多少子串？答案是$\frac{n(n+1)}{2}$个。

问题解决了。

**Q&A:**

1. 为什么长度为$n$的字符串，有$\frac{n(n+1)}{2}$个子串？

   长度为$1$的子串有$n$个，长度为$2$的子串有$$，......，长度为$n$的子串有$1$个，$1+2+\cdots+n=\frac{n(n+1)}{2}$

2. 如何将“abbddd”解析为“1个a”、“2个b”、“3个d”这种格式？

   我们使用一个变量$lastChar$，记录上一个字符是什么。再使用一个变量$cnt$，记录当前字符连续出现了多少个。如果当前字符和上一个字符不同，就说明刚刚出现了连续$cnt$个$lastChar$

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
typedef long long ll;
const ll mod = 1e9 + 7;
class Solution {
public:
    int countHomogenous(string s) {
        ll ans = 0;
        char lastChar = s[0];
        ll cnt = 0;
        for (char c : s) {
            if (c != lastChar) {
                ans = (ans + cnt * (cnt + 1) / 2) % mod;
                printf("ans = %lld\n", ans);  //**********
                cnt = 1, lastChar = c;
            }
            else {
                cnt++;
            }
        }
        ans = (ans + cnt * (cnt + 1) / 2) % mod;
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/12/26/LeetCode%201759.%E7%BB%9F%E8%AE%A1%E5%90%8C%E6%9E%84%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9A%84%E6%95%B0%E7%9B%AE/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128446642](https://letmefly.blog.csdn.net/article/details/128446642)
