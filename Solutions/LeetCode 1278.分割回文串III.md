---
title: 1278.分割回文串 III：动态规划
date: 2025-03-03 13:54:09
tags: [题解, LeetCode, 困难, 字符串, 回文, 回文串, 动态规划, DP]
categories: [题解, LeetCode]
---

# 【LetMeFly】1278.分割回文串 III：动态规划

力扣题目链接：[https://leetcode.cn/problems/palindrome-partitioning-iii/](https://leetcode.cn/problems/palindrome-partitioning-iii/)

<p>给你一个由小写字母组成的字符串&nbsp;<code>s</code>，和一个整数&nbsp;<code>k</code>。</p>

<p>请你按下面的要求分割字符串：</p>

<ul>
	<li>首先，你可以将&nbsp;<code>s</code>&nbsp;中的部分字符修改为其他的小写英文字母。</li>
	<li>接着，你需要把&nbsp;<code>s</code>&nbsp;分割成&nbsp;<code>k</code>&nbsp;个非空且不相交的子串，并且每个子串都是回文串。</li>
</ul>

<p>请返回以这种方式分割字符串所需修改的最少字符数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = &quot;abc&quot;, k = 2
<strong>输出：</strong>1
<strong>解释：</strong>你可以把字符串分割成 &quot;ab&quot; 和 &quot;c&quot;，并修改 &quot;ab&quot; 中的 1 个字符，将它变成回文串。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = &quot;aabbc&quot;, k = 3
<strong>输出：</strong>0
<strong>解释：</strong>你可以把字符串分割成 &quot;aa&quot;、&quot;bb&quot; 和 &quot;c&quot;，它们都是回文串。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = &quot;leetcode&quot;, k = 8
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code>&nbsp;中只含有小写英文字母。</li>
</ul>


    
## 解题方法：动态规划

很容易想到，使用$dp[i][j]$表示$s.substr(0, i)$被切割$j$次变成非空回文串列表所需修改的最小次数。（其中$s.substr(0, i)$表示字符串$s$下标`[0, i]`的子串。）

因此有转移方程$dp[i][j] = \min(dp[i0][j - 1] + minop[i0 + 1][i])$，其中$0 \leq i0 \lt i$。（在$s.substr(0, i0)$被切割$j-1$次的基础上，$s.substr(i0 + 1, i)$只通过字符变换成回文。）

也就是说$minop[i][j]$代表$s.substr(i, j)$通过修改字符变成回文串所需的最小修改次数。这个数组如何得到？

又有转移方程$minop[i][j] = minop[i + 1][j - 1] + (s[i] \neq s[j])$。（如果$s[i]\neq s[j]$则需要变换其中一个字符。）

+ 时间复杂度$O(n^2k)$，预处理$O(nk)$，计算结果$O(n^2k)$
+ 空间复杂度$O(nk)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-03 12:44:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-03 13:27:33
 */
class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> minop(n, vector<int>(n));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                minop[i][j] = (s[i] != s[j]) + minop[i + 1][j - 1];
            }
        }
        vector<vector<int>> dp(n, vector<int>(k, 1000));  // 本身原本字符串长度就已经是1了，最多再切k-1次
        for (int i = 0; i < n; i++) {
            dp[i][0] = minop[0][i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < min(k, i + 1); j++) {
                for (int i0 = 0; i0 < i; i0++) {
                    dp[i][j] = min(dp[i][j], dp[i0][j - 1] + minop[i0 + 1][i]);
                }
            }
        }
        return dp.back().back();
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-03-03 13:30:41
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-03 13:36:20
'''
class Solution:
    def palindromePartition(self, s: str, k: int) -> int:
        n = len(s)
        minop = [[0] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                minop[i][j] = (s[i] != s[j]) + minop[i + 1][j - 1]
        dp = [[1000] * k for _ in range(n)]
        dp[0][0] = 0
        for i in range(n):
            dp[i][0] = minop[0][i]
        for i in range(1, n):
            for j in range(1, min(k, i + 1)):
                for i0 in range(i):
                    dp[i][j] = min(dp[i][j], dp[i0][j - 1] + minop[i0 + 1][i])
        return dp[-1][-1]
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-03-03 13:45:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-03 13:51:57
 */
class Solution {
    public int palindromePartition(String s, int k) {
        int n = s.length();
        int[][] minop = new int[n][n];
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                minop[i][j] = minop[i + 1][j - 1];
                if (s.charAt(i) != s.charAt(j)) {
                    minop[i][j]++;
                }
            }
        }
        int[][] dp = new int[n][k];
        for (int i = 0; i < n; i++) {
            dp[i][0] = minop[0][i];
            for (int j = 1; j < k; j++) {
                dp[i][j] = 1000;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < Math.min(k, i + 1); j++) {
                for (int i0 = 0; i0 < i; i0++) {
                    dp[i][j] = Math.min(dp[i][j], dp[i0][j - 1] + minop[i0 + 1][i]);
                }
            }
        }
        return dp[n - 1][k - 1];
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-03-03 13:40:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-03 13:48:33
 */
package main

func palindromePartition(s string, k int) int {
    n := len(s)
    minop := make([][]int, n)
    for i, _ := range minop {
        minop[i] = make([]int, n)
    }
    for i := n - 1; i >= 0; i-- {
        for j := i + 1; j < n; j++ {
            minop[i][j] = minop[i + 1][j - 1]
            if s[i] != s[j] {
                minop[i][j]++
            }
        }
    }
    dp := make([][]int, n)
    for i, _ := range dp {
        dp[i] = make([]int, k)
        for j, _ := range dp[i] {
            dp[i][j] = 1000
        }
    }
    for i, _ := range dp {
        dp[i][0] = minop[0][i]
    }
    for i := 1; i < n; i++ {
        for j := 1; j < min(k, i + 1); j++ {
            for i0 := 0; i0 < i; i0++ {
                dp[i][j] = min(dp[i][j], dp[i0][j - 1] + minop[i0 + 1][i])
            }
        }
    }
    return dp[n - 1][k - 1]
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/145986494)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/03/03/LeetCode%201278.%E5%88%86%E5%89%B2%E5%9B%9E%E6%96%87%E4%B8%B2III/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
