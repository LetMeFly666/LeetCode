---
title: 3138.同位字符串连接的最小长度
date: 2024-12-20 21:22:01
tags: [题解, LeetCode, 中等, 哈希表, 字符串, 计数, 质因数]
---

# 【LetMeFly】3138.同位字符串连接的最小长度：计数（一个数最多128个因数）

力扣题目链接：[https://leetcode.cn/problems/minimum-length-of-anagram-concatenation/](https://leetcode.cn/problems/minimum-length-of-anagram-concatenation/)

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;，它由某个字符串&nbsp;<code>t</code>&nbsp;和若干&nbsp;<code>t</code>&nbsp; 的&nbsp;<strong>同位字符串</strong>&nbsp;连接而成。</p>

<p>请你返回字符串 <code>t</code>&nbsp;的 <strong>最小</strong>&nbsp;可能长度。</p>

<p><strong>同位字符串</strong>&nbsp;指的是重新排列一个单词得到的另外一个字符串，原来字符串中的每个字符在新字符串中都恰好只使用一次。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "abba"</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><strong>解释：</strong></p>

<p>一个可能的字符串&nbsp;<code>t</code>&nbsp;为&nbsp;<code>"ba"</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "cdef"</span></p>

<p><span class="example-io"><b>输出：</b>4</span></p>

<p><strong>解释：</strong></p>

<p>一个可能的字符串&nbsp;<code>t</code>&nbsp;为&nbsp;<code>"cdef"</code>&nbsp;，注意&nbsp;<code>t</code>&nbsp;可能等于&nbsp;<code>s</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
</ul>


    
## 解题方法：计数

$1$到$10^5$范围内的一个数，最多有多少个因子呢？

> ```python
> from math import sqrt
> 
> M, Mi = 0, 0
> 
> def getYin(n: int) -> int:
>     k = int(sqrt(n))
>     ans = 0
>     for i in range(1, k):
>         if n % i == 0:
>             ans += 2
>     if k * k == n:
>         ans += 1
>     return ans
> 
> for n in range(1, 100001):
>     yinN = getYin(n)
>     if yinN > M:
>         M, Mi = yinN, n
> print(f'{Mi}因子数最多，为{M}个')
> ```
> 
> 83160因子数最多，为128个。

首先从$1$到$len(s)$模拟同位字符串的长度$ans$：

> 如果$ans$不是字符串$s$长度的因数，则$ans$一定不可行。
>
> 否则，每$ans$长度统计一次子字符串中每个字母分别出现了多少次。如果全相同，则返回$ans$。

+ 时间复杂度$O(A\times len(s))$，其中$A$为$1$到$len(s)$的整数中的最大因子个数。
+ 空间复杂度$O(C)$，其中$C=26$。

### AC代码

#### C语言

```c
/*
 * @Author: LetMeFly
 * @Date: 2024-12-20 21:06:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-20 21:14:34
 */
void count(int times[], char s[], int l, int r) {
    for (int i = l; i < r; i++) {
        times[s[i] - 'a']++;
    }
}

int same26(int a[], int b[]) {
    for (int i = 0; i < 26; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

int minAnagramLength(char* s) {
    int n = strlen(s);
    for (int ans = 1; ans < n; ans++) {
        if (n % ans) {
            continue;
        }
        int should[26] = {0};
        count(should, s, 0, ans);
        for (int i = ans; i < n; i += ans) {
            int now[26] = {0};
            count(now, s, i, i + ans);
            if (!same26(should, now)) {
                goto loop;
            }
        }
        return ans;
        loop:;
    }
    return n;
}
```

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2024-12-20 20:56:59
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-20 20:57:22
 */
class Solution {
private:
    vector<int> count(string& s, int l, int r) {
        vector<int> ans(26);
        for (int i = l; i < r; i++) {
            ans[s[i] - 'a']++;
        }
        return ans;
    }
public:
    int minAnagramLength(string& s) {
        for (int ans = 1; ans < s.size(); ans++) {
            if (s.size() % ans) {
                continue;
            }
            vector<int> should = count(s, 0, ans);
            for (int i = ans; i < s.size(); i += ans) {
                vector<int> now = count(s, i, i + ans);
                if (should != now) {
                    goto loop;
                }
            }
            return ans;
            loop:;
        }
        return s.size();
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2024-12-20 20:53:20
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-20 20:56:17
'''
from collections import Counter

class Solution:
    def minAnagramLength(self, s: str) -> int:
        for ans in range(1, len(s)):
            if len(s) % ans:
                continue
            should = Counter(s[:ans])
            ok = True
            for i in range(ans, len(s), ans):
                if should != Counter(s[i:i + ans]):
                    ok = False
                    break
            if ok:
                return ans
        return len(s)
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2024-12-20 20:58:29
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-20 21:05:54
 */
import java.util.Arrays;

class Solution {
    private int[] count(char[] s, int l, int r) {
        int[] ans = new int[26];
        for (int i = l; i < r; i++) {
            ans[s[i] - 'a']++;
        }
        return ans;
    }
    public int minAnagramLength(String S) {
        char[] s = S.toCharArray();
        loop:
        for (int ans = 1; ans < s.length; ans++) {
            if (s.length % ans != 0) {
                continue;
            }
            int[] should = count(s, 0, ans);
            for (int i = ans; i < s.length; i += ans) {
                int[] now = count(s, i, i + ans);
                if (!Arrays.equals(should, now)) {
                    continue loop;
                }
            }
            return ans;
        }
        return s.length;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2024-12-20 21:16:18
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-20 21:20:42
 */
package main

func count(s string, l, r int) []int {
    ans := make([]int, 26)
    for i := l; i < r; i++ {
        ans[s[i] - 'a']++
    }
    return ans
}

func same26(a, b []int) bool {
    for i := range a {
        if a[i] != b[i] {
            return false;
        }
    }
    return true;
}

func minAnagramLength(s string) int {
    for ans := 1; ans < len(s); ans++ {
        if len(s) % ans != 0 {
            continue
        }
        should := count(s, 0, ans)
        ok := true
        for i := ans; i < len(s); i += ans {
            if !same26(should, count(s, i, i + ans)) {
                ok = false
                break
            }
        }
        if ok {
            return ans
        }
    }
    return len(s)
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/12/20/LeetCode%203138.%E5%90%8C%E4%BD%8D%E5%AD%97%E7%AC%A6%E4%B8%B2%E8%BF%9E%E6%8E%A5%E7%9A%84%E6%9C%80%E5%B0%8F%E9%95%BF%E5%BA%A6/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/144620449](https://letmefly.blog.csdn.net/article/details/144620449)
