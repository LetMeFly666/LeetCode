---
title: 1745.分割回文串 IV：动态规划（用III或II能直接秒）
date: 2025-03-04 10:50:58
tags: [题解, LeetCode, 困难, 字符串, 回文, 回文串, 动态规划, DP]
---

# 【LetMeFly】1745.分割回文串 IV：动态规划（用III或II能直接秒）

力扣题目链接：[https://leetcode.cn/problems/palindrome-partitioning-iv/](https://leetcode.cn/problems/palindrome-partitioning-iv/)

<p>给你一个字符串 <code>s</code> ，如果可以将它分割成三个 <strong>非空</strong> 回文子字符串，那么返回 <code>true</code> ，否则返回 <code>false</code> 。</p>

<p>当一个字符串正着读和反着读是一模一样的，就称其为 <strong>回文字符串</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>s = "abcbdd"
<b>输出：</b>true
<strong>解释：</strong>"abcbdd" = "a" + "bcb" + "dd"，三个子字符串都是回文的。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>s = "bcbddxy"
<b>输出：</b>false
<strong>解释：</strong>s 没办法被分割成 3 个回文子字符串。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 <= s.length <= 2000</code></li>
	<li><code>s</code>​​​​​​ 只包含小写英文字母。</li>
</ul>


    
## 解题方法：动态规划

如果想用之前的方法直接AC：

+ [1278.分割回文串 III](https://blog.letmefly.xyz/2025/03/03/LeetCode%201278.%E5%88%86%E5%89%B2%E5%9B%9E%E6%96%87%E4%B8%B2III/)：令`k = 3`，复杂度$O(n^2k)$
+ [132.分割回文串 II](https://blog.letmefly.xyz/2025/03/02/LeetCode%200132.%E5%88%86%E5%89%B2%E5%9B%9E%E6%96%87%E4%B8%B2II/)：也就是今天的方法。

在`132.分割回文串 II`中我们通过预处理可以在$O(n^2)$时间复杂度内得到字符串s的任一字串是否为回文串（方法简述如下：）

> 使用isok[i][j]表示字符串s从下标i到下标j的子串是否为回文串。若$i\geq j$则视为回文串，否则有状态转移方程$isok[i][j] = s[i] == s[j]\text{ AND } isok[i + 1][j - 1]$。

都知道任意一个字串是否是回文串了，我直接枚举两个分割位置，每次使用$O(1)$时间看看被分成的三段是否都为回文字符串不就可以了么？

+ 时间复杂度$O(n^2)$，其中$n=len(s)$
+ 空间复杂度$O(n^2)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-04 10:18:19
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-04 10:28:38
 */
class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<bool>> isok(n, vector<bool>(n, true));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                isok[i][j] = s[i] == s[j] && isok[i + 1][j - 1];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                if (isok[0][i] && isok[i + 1][j] && isok[j + 1][n - 1]) {
                    return true;
                }
            }
        }
        return false;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-03-04 10:30:23
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-04 10:33:30
'''
class Solution:
    def checkPartitioning(self, s: str) -> bool:
        n = len(s)
        isok = [[True] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                isok[i][j] = s[i] == s[j] and isok[i + 1][j - 1]
        for i in range(n):
            for j in range(i + 1, n - 1):
                if isok[0][i] and isok[i + 1][j] and isok[j + 1][n - 1]:
                    return True
        return False
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-03-04 10:42:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-04 10:46:32
 */
package main

func checkPartitioning(s string) bool {
    n := len(s)
    isok := make([][]bool, n)
    for i, _ := range isok {
        isok[i] = make([]bool, n)
        for j, _ := range isok[i] {
            isok[i][j] = true
        }
    }
    for i := n - 1; i >= 0; i-- {
        for j := i + 1; j < n; j++ {
            isok[i][j] = s[i] == s[j] && isok[i + 1][j - 1]
        }
    }
    
    for i := 0; i < n; i++ {
        for j := i + 1; j < n - 1; j++ {
            if isok[0][i] && isok[i + 1][j] && isok[j + 1][n - 1] {
                return true
            }
        }
    }
    return false
}
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-03-04 10:47:02
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-04 10:49:14
 */
class Solution {
    public boolean checkPartitioning(String s) {
        int n = s.length();
        boolean[][] isok = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                isok[i][j] = true;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                isok[i][j] = s.charAt(i) == s.charAt(j) && isok[i + 1][j - 1];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                if (isok[0][i] && isok[i + 1][j] && isok[j + 1][n - 1]) {
                    return true;
                }
            }
        }
        return false;
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/146009195)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/03/04/LeetCode%201745.%E5%88%86%E5%89%B2%E5%9B%9E%E6%96%87%E4%B8%B2IV/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
