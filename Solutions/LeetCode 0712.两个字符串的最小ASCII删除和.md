---
title: 712.两个字符串的最小ASCII删除和：反向思维保留最大（动态规划）
date: 2026-01-10 23:17:37
tags: [题解, LeetCode, 中等, 字符串, 动态规划, DP, 子序列]
categories: [题解, LeetCode]
---

# 【LetMeFly】712.两个字符串的最小ASCII删除和：反向思维保留最大（动态规划）

力扣题目链接：[https://leetcode.cn/problems/minimum-ascii-delete-sum-for-two-strings/](https://leetcode.cn/problems/minimum-ascii-delete-sum-for-two-strings/)

<p>给定两个字符串<code>s1</code>&nbsp;和&nbsp;<code>s2</code>，返回 <em>使两个字符串相等所需删除字符的&nbsp;<strong>ASCII&nbsp;</strong>值的最小和&nbsp;</em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> s1 = "sea", s2 = "eat"
<strong>输出:</strong> 231
<strong>解释:</strong> 在 "sea" 中删除 "s" 并将 "s" 的值(115)加入总和。
在 "eat" 中删除 "t" 并将 116 加入总和。
结束时，两个字符串相等，115 + 116 = 231 就是符合条件的最小和。
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入:</strong> s1 = "delete", s2 = "leet"
<strong>输出:</strong> 403
<strong>解释:</strong> 在 "delete" 中删除 "dee" 字符串变成 "let"，
将 100[d]+101[e]+101[e] 加入总和。在 "leet" 中删除 "e" 将 101[e] 加入总和。
结束时，两个字符串都等于 "let"，结果即为 100+101+101+101 = 403 。
如果改为将两个字符串转换为 "lee" 或 "eet"，我们会得到 433 或 417 的结果，比答案更大。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>0 &lt;= s1.length, s2.length &lt;= 1000</code></li>
	<li><code>s1</code>&nbsp;和&nbsp;<code>s2</code>&nbsp;由小写英文字母组成</li>
</ul>


    
## 解题方法：动态规划

问：两个字符串相同子序列最大ASCII和为多少？

好算吧，定义`dp[i][j]`代表`s1[0..i]`与`s2[0..j]`相同子序列最大ASCII和，于是就有动态转移方程：

$dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])$ （不选`s1[i]`和`s2[j]`）

以及当`s1[i] == s2[j]`时，$dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + ASCII(s1[i]))$。

为了方便不进行下标为$-1$的特判，也可以使`dp`数组多开辟一行一列。

对了，求完最大保留ASCII和（记为s），记得用两字符串ASCII总和减去二倍的s来计算最小移除ASCII之和。

+ 时间复杂度$O(len(s1)\times len(s2))$
+ 空间复杂度$O(len(s1)\times len(s2))$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-01-10 09:24:25
 */
class Solution {
public:
    int minimumDeleteSum(string& s1, string& s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + s1[i - 1]);
                }
            }
        }
        int total = 0;
        for (char c : s1) {
            total += c;
        }
        for (char c : s2) {
            total += c;
        }
        return total - 2 * dp[n][m];
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/156808608)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/01/10/LeetCode%200712.%E4%B8%A4%E4%B8%AA%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9A%84%E6%9C%80%E5%B0%8FASCII%E5%88%A0%E9%99%A4%E5%92%8C/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
