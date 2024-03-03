---
title: 139.单词拆分
date: 2022-07-26 11:48:48
tags: [题解, LeetCode, 中等, 字典树, 记忆化搜索, 记忆化, 哈希表, 字符串, 动态规划, DP]
---

# 【LetMeFly】139.单词拆分

力扣题目链接：[https://leetcode.cn/problems/word-break/](https://leetcode.cn/problems/word-break/)

<p>给你一个字符串 <code>s</code> 和一个字符串列表 <code>wordDict</code> 作为字典。请你判断是否可以利用字典中出现的单词拼接出 <code>s</code> 。</p>

<p><strong>注意：</strong>不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> s = "leetcode", wordDict = ["leet", "code"]
<strong>输出:</strong> true
<strong>解释:</strong> 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入:</strong> s = "applepenapple", wordDict = ["apple", "pen"]
<strong>输出:</strong> true
<strong>解释:</strong> 返回 true 因为 <code>"</code>applepenapple<code>"</code> 可以由 <code>"</code>apple" "pen" "apple<code>" 拼接成</code>。
&nbsp;    注意，你可以重复使用字典中的单词。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入:</strong> s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
<strong>输出:</strong> false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 300</code></li>
	<li><code>1 &lt;= wordDict.length &lt;= 1000</code></li>
	<li><code>1 &lt;= wordDict[i].length &lt;= 20</code></li>
	<li><code>s</code> 和 <code>wordDict[i]</code> 仅有小写英文字母组成</li>
	<li><code>wordDict</code> 中的所有字符串 <strong>互不相同</strong></li>
</ul>


    
## 方法一：dp

用$dp[i]$表示字符串的前$i$个字母能否由字典中的单词拼接出来。

初始值```dp[0] = true```

用$n$代表待拼接字符串的长度

第一维循环$i$从$1$到$n$，依次判断待拼接字符串的前$i$个字母能否被拼接。

第二维循环$j$从$0$到$i - 1$，依次判断```前i个字母```能否由```已验证的能被拼接出来的前j个字母```和```存在于字典中的 由 第j个到第i个字母 组成的单词```拼接而成。

如果```dp[j]==true```并且```原字符串的子串[j, i]```存在于字典中，就把```dp[i]```标记为```true```

+ 时间复杂度$O(n^2)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> se;
        for (string& s : wordDict) {
            se.insert(s);
        }
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && se.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/07/26/LeetCode%200139.%E5%8D%95%E8%AF%8D%E6%8B%86%E5%88%86/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125991942](https://letmefly.blog.csdn.net/article/details/125991942)
