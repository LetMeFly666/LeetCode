---
title: 3144.分割字符频率相等的最少子字符串
date: 2024-08-28 23:51:45
tags: [题解, LeetCode, 中等, 哈希表, 哈希, map, 字符串, 动态规划, 计数]
categories: [题解, LeetCode]
---

# 【LetMeFly】3144.分割字符频率相等的最少子字符串：动态规划+哈希表

力扣题目链接：[https://leetcode.cn/problems/minimum-substring-partition-of-equal-character-frequency/](https://leetcode.cn/problems/minimum-substring-partition-of-equal-character-frequency/)

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;，你需要将它分割成一个或者更多的&nbsp;<strong>平衡</strong>&nbsp;子字符串。比方说，<code>s == "ababcc"</code>&nbsp;那么&nbsp;<code>("abab", "c", "c")</code>&nbsp;，<code>("ab", "abc", "c")</code>&nbsp;和&nbsp;<code>("ababcc")</code>&nbsp;都是合法分割，但是&nbsp;<code>("a", <strong>"bab"</strong>, "cc")</code>&nbsp;，<code>(<strong>"aba"</strong>, "bc", "c")</code>&nbsp;和&nbsp;<code>("ab", <strong>"abcc"</strong>)</code>&nbsp;不是，不平衡的子字符串用粗体表示。</p>

<p>请你返回 <code>s</code>&nbsp;<strong>最少</strong> 能分割成多少个平衡子字符串。</p>

<p><b>注意：</b>一个 <strong>平衡</strong>&nbsp;字符串指的是字符串中所有字符出现的次数都相同。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "fabccddg"</span></p>

<p><span class="example-io"><b>输出：</b>3</span></p>

<p><strong>解释：</strong></p>

<p>我们可以将 <code>s</code>&nbsp;分割成 3 个子字符串：<code>("fab, "ccdd", "g")</code>&nbsp;或者&nbsp;<code>("fabc", "cd", "dg")</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "abababaccddb"</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><strong>解释：</strong></p>

<p>我们可以将&nbsp;<code>s</code>&nbsp;分割成 2 个子字符串：<code>("abab", "abaccddb")</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
</ul>


    
## 解题方法：动态规划

使用一个动态规划数组$dp$，其中$dp[i]$代表字符串$s$的前$i$个字符最少能分割成多少个平衡子字符串。初始值除了$dp[0]=0$外都是“无穷大”。

接着使用下标$i$从前往后遍历字符串。假设字符串的$j$到$i$子串是平衡字符串，那么有$dp[i + 1] = \min (dp[i + 1], dp[j] + 1)$。

对于一个下标$i$，如何判断是否存在一个$j\lt i$，使得$j$到$i$的子串是平衡字符串呢？我们可以使用$j$从$i$往前开始遍历字符串，并使用一个哈希表统计每个字符出现的次数，再使用两个变量$types$和$maxTimes$分别统计$j$到$i$的子串中字符种类数和字符最大出现次数。如果$字符种类数\times 字符最大出现次数=子串长度$，就说明子串是平衡字符串（每个字符出现次数相等，都是$maxTimes$次）。

+ 时间复杂度$O(len(s)^2)$
+ 空间复杂度$O(len(s) + C)$，其中$C$是字符种类数，$C=26$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minimumSubstringsInPartition(string& s) {
        vector<int> dp(s.size() + 1, 1000000);
        dp[0] = 0;
        unordered_map<char, int> ma;
        for (int i = 0; i < s.size(); i++) {
            ma.clear();
            int types = 0, maxTimes = 0;
            for (int j = i; j >= 0; j--) {
                maxTimes = max(maxTimes, ++ma[s[j]]);
                if (ma[s[j]] == 1) {
                    types++;
                }
                if (maxTimes * types == i - j + 1) {
                    dp[i + 1] = min(dp[i + 1], dp[j] + 1);
                }
            }
        }
        return dp.back();
    }
};
```

#### Go

```go
package main

func min(a int, b int) int {
    if (a > b) {
        return b
    }
    return a
}

func max(a int, b int) int {
    if (a < b) {
        return b
    }
    return a
}

func minimumSubstringsInPartition(s string) int {
    dp := make([]int, len(s) + 1)
    for i := range dp {
        dp[i] = 100000
    }
    dp[0] = 0
    for i := range s {
        ma := map[byte]int{}
        types, maxTimes := 0, 0
        for j := i; j >= 0; j-- {
            ma[s[j]]++
            maxTimes = max(maxTimes, ma[s[j]])
            if ma[s[j]] == 1 {
                types++
            }
            if types * maxTimes == i - j + 1 {
                dp[i + 1] = min(dp[i + 1], dp[j] + 1)
            }
        }
    }
    return dp[len(s)]
}


```

#### Java

```java
import java.util.Map;
import java.util.HashMap;
import java.util.Arrays;

class Solution {
    public int minimumSubstringsInPartition(String s) {
        int[] dp = new int[s.length() + 1];
        Arrays.fill(dp, 100000);
        dp[0] = 0;
        Map<Character, Integer> ma = new HashMap<Character, Integer>();
        for (int i = 0; i < s.length(); i++) {
            ma.clear();
            int types = 0, maxTimes = 0;
            for (int j = i; j >= 0; j--) {
                int originalTimes = ma.getOrDefault(s.charAt(j), 0);
                ma.put(s.charAt(j), originalTimes + 1);
                maxTimes = Math.max(maxTimes, originalTimes + 1);
                if (originalTimes == 0) {
                    types++;
                }
                if (maxTimes * types == i - j + 1) {
                    dp[i + 1] = Math.min(dp[i + 1], dp[j] + 1);
                }
            }
        }
        return dp[s.length()];
    }
}
```

#### Python

```python
from collections import defaultdict

class Solution:
    def minimumSubstringsInPartition(self, s: str) -> int:
        dp = [100000] * (len(s) + 1)
        dp[0] = 0
        ma = defaultdict(int)
        for i in range(len(s)):
            ma.clear()
            types, maxTimes = 0, 0
            for j in range(i, -1, -1):
                ma[s[j]] += 1
                maxTimes = max(maxTimes, ma[s[j]])
                if ma[s[j]] == 1:
                    types += 1
                if maxTimes * types == i - j + 1:
                    dp[i + 1] = min(dp[i + 1], dp[j] + 1)
        return dp[-1]
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/08/28/LeetCode%203144.%E5%88%86%E5%89%B2%E5%AD%97%E7%AC%A6%E9%A2%91%E7%8E%87%E7%9B%B8%E7%AD%89%E7%9A%84%E6%9C%80%E5%B0%91%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/141652980](https://letmefly.blog.csdn.net/article/details/141652980)
