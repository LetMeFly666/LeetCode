---
title: 115.不同的子序列
date: 2022-07-16 15:07:14
tags: [题解, LeetCode, 困难, 字符串, 动态规划, DP]
---

# 【LetMeFly】115.不同的子序列

力扣题目链接：[https://leetcode.cn/problems/distinct-subsequences/](https://leetcode.cn/problems/distinct-subsequences/)

<p>给定一个字符串 <code>s</code><strong> </strong>和一个字符串 <code>t</code> ，计算在 <code>s</code> 的子序列中 <code>t</code> 出现的个数。</p>

<p>字符串的一个 <strong>子序列</strong> 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，<code>"ACE"</code> 是 <code>"ABCDE"</code> 的一个子序列，而 <code>"AEC"</code> 不是）</p>

<p>题目数据保证答案符合 32 位带符号整数范围。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "rabbbit", t = "rabbit"<code>
<strong>输出</strong></code><strong>：</strong><code>3
</code><strong>解释：</strong>
如下图所示, 有 3 种可以从 s 中得到 <code>"rabbit" 的方案</code>。
<code><strong><u>rabb</u></strong>b<strong><u>it</u></strong></code>
<code><strong><u>ra</u></strong>b<strong><u>bbit</u></strong></code>
<code><strong><u>rab</u></strong>b<strong><u>bit</u></strong></code></pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "babgbag", t = "bag"
<code><strong>输出</strong></code><strong>：</strong><code>5
</code><strong>解释：</strong>
如下图所示, 有 5 种可以从 s 中得到 <code>"bag" 的方案</code>。 
<code><strong><u>ba</u></strong>b<u><strong>g</strong></u>bag</code>
<code><strong><u>ba</u></strong>bgba<strong><u>g</u></strong></code>
<code><u><strong>b</strong></u>abgb<strong><u>ag</u></strong></code>
<code>ba<u><strong>b</strong></u>gb<u><strong>ag</strong></u></code>
<code>babg<strong><u>bag</u></strong></code>
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 <= s.length, t.length <= 1000</code></li>
	<li><code>s</code> 和 <code>t</code> 由英文字母组成</li>
</ul>


    
## 方法一：动态规划

$dp[i][j]$：```s的前i个字符的子串```的子序列中，```t的前j个字符的子串```出现的次数

转移方程:

$\begin{cases}dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]& \text{ if } s[i]=s[j] \\dp[i][j] = dp[i - 1][j]& \text{ if } s[i]\neq s[j] \end{cases}$

初始值$dp[i][0]=1$（T为空的时候，方案数为1）

+ 时间复杂度$O(mn)$，其中$m=s.size(), n=t.size()$
+ 空间复杂度$O(mn)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int numDistinct(string s, string t) {
        /* dp[i][j]：```s的前i个字符的子串```的子序列中，```t的前j个字符的子串```出现的次数 */
        vector<vector<unsigned int>> dp(s.size() + 1, vector<unsigned int>(t.size() + 1, 0));
        for (int i = 0; i < s.size() + 1; i++) {  // T为空的时候，方案数为1
            dp[i][0] = 1;
        }
        for (int i = 1; i < s.size() + 1; i++) {
            for (int j = 1; j < t.size() + 1; j++) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp.back().back();
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/07/16/LeetCode%200115.%E4%B8%8D%E5%90%8C%E7%9A%84%E5%AD%90%E5%BA%8F%E5%88%97/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125820358](https://letmefly.blog.csdn.net/article/details/125820358)
