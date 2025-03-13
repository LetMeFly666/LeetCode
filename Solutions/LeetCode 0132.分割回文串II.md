---
title: 132.分割回文串 II：动态规划
date: 2025-03-02 12:45:23
tags: [题解, LeetCode, 困难, 字符串, 动态规划, DP, 回文, 回文串]
categories: [题解, LeetCode]
---

# 【LetMeFly】132.分割回文串 II：动态规划

力扣题目链接：[https://leetcode.cn/problems/palindrome-partitioning-ii/](https://leetcode.cn/problems/palindrome-partitioning-ii/)

<p>给你一个字符串 <code>s</code>，请你将 <code>s</code> 分割成一些子串，使每个子串都是<span data-keyword="palindrome-string">回文串</span>。</p>

<p>返回符合要求的 <strong>最少分割次数</strong> 。</p>

<div class="original__bRMd">
<div>
<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "aab"
<strong>输出：</strong>1
<strong>解释：</strong>只需一次分割就可将&nbsp;<em>s </em>分割成 ["aa","b"] 这样两个回文子串。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "a"
<strong>输出：</strong>0
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "ab"
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 2000</code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
</ul>
</div>
</div>


    
## 解题方法：动态规划

整个过程分为两步：预处理 和 动态规划

**动态规划：**

使用数组$dp$，其中$dp[i]$代表使得子字符串$0...i$为回文字符串组合的最小分割次数，那么$dp[len(s) - 1]$即为答案。

+ 如果$0...i$直接为回文字符串，那么分割次数为0。

+ 否则，对于$j\in 0...i-1$，如果$j + 1..i$是回文字符串，那么有$dp[i] = min(dp[j] + 1)$

**预处理：**

有没有什么办法$O(1)$时间内快速判断下标从$i$到$j$的子字符串是否为回文字符串？有，我们可以先使用$O(n^2)$复杂度的时间预处理。使用$isOk[i][j]$表示子字符串$i...j$是否为回文字符串：

+ 如果子字符串为空或者长度为1，则是回文字符串($i \geq j$)
+ 否则：是回文字符串当且仅当$s[i] == s[j] \text{ AND }isOk[i + 1][j - 1]$

### 时空复杂度分析

+ 时间复杂度$O(n^2)$，预处理和动态规划的时间复杂度都是$O(n^2)$。其中$n = len(s)$
+ 空间复杂度$O(n^2)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-02 12:02:45
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-02 12:26:06
 */
class Solution {
public:
    int minCut(string s) {
        vector<vector<bool>> isOk(s.size(), vector<bool>(s.size(), true));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < s.size(); j++) {
                isOk[i][j] = s[i] == s[j] && isOk[i + 1][j - 1];
            }
        }

        vector<int> dp(s.size(), 1000000);
        for (int i = 0; i < s.size(); i++) {
            if (isOk[0][i]) {
                dp[i] = 0;
                continue;
            }
            for (int j = 0; j < i; j++) {
                if (isOk[j + 1][i]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp.back();
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-03-02 12:26:57
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-02 12:33:40
'''
class Solution:
    def minCut(self, s: str) -> int:
        isOk = [[True] * len(s) for _ in range(len(s))]
        for i in range(len(s) - 1, -1, -1):
            for j in range(i + 1, len(s)):
                isOk[i][j] = s[i] == s[j] and isOk[i + 1][j - 1]
        
        dp = [100000] * len(s)
        for i in range(len(s)):
            if isOk[0][i]:
                dp[i] = 0
                continue
            for j in range(i):
                if isOk[j + 1][i]:
                    dp[i] = min(dp[i], dp[j] + 1)
        return dp[-1]

```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-03-02 12:34:31
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-02 12:38:17
 */
class Solution {
    public int minCut(String s) {
        boolean[][] isOk = new boolean[s.length()][s.length()];
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < s.length(); j++) {
                isOk[i][j] = true;
            }
        }
        for (int i = s.length() - 1; i >= 0; i--) {
            for (int j = i + 1; j < s.length(); j++) {
                isOk[i][j] = s.charAt(i) == s.charAt(j) && isOk[i + 1][j - 1];
            }
        }

        int[] dp = new int[s.length()];
        for (int i = 0; i < s.length(); i++) {
            dp[i] = 100000;
        }
        for (int i = 0; i < s.length(); i++) {
            if (isOk[0][i]) {
                dp[i] = 0;
                continue;
            }
            for (int j = 0; j < i; j++) {
                if (isOk[j + 1][i]) {
                    dp[i] = Math.min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[dp.length - 1];
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-03-02 12:39:13
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-02 12:43:12
 */
package main

func minCut(s string) int {
    isOk := make([][]bool, len(s))
    for i, _ := range isOk {
        isOk[i] = make([]bool, len(s))
        for j, _ := range isOk[i] {
            isOk[i][j] = true
        }
    }
    for i := len(s) - 1; i >= 0; i-- {
        for j := i + 1; j < len(s); j++ {
            isOk[i][j] = s[i] == s[j] && isOk[i + 1][j - 1]
        }
    }

    dp := make([]int, len(s))
    for i, _ := range dp {
        dp[i] = 100000
    }
    for i := 0; i < len(dp); i++ {
        if isOk[0][i] {
            dp[i] = 0
            continue
        }
        for j := 0; j < i; j++ {
            if isOk[j + 1][i] {
                dp[i] = min(dp[i], dp[j] + 1)
            }
        }
    }
    return dp[len(dp) - 1]
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/145961943)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/03/02/LeetCode%200132.%E5%88%86%E5%89%B2%E5%9B%9E%E6%96%87%E4%B8%B2II/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
