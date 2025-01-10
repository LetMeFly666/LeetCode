---
title: 3297.统计重新排列后包含另一个字符串的子字符串数目 I/II(3298)
date: 2025-01-09 13:11:29
tags: [题解, LeetCode, 中等, 哈希表, 字符串, 滑动窗口]
---

# 【LetMeFly】3297.统计重新排列后包含另一个字符串的子字符串数目 I/II(3298)：滑动窗口

力扣题目链接：

+ [https://leetcode.cn/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-i/](https://leetcode.cn/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-i/)
+ [https://leetcode.cn/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-ii/](https://leetcode.cn/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-ii/)

<p>给你两个字符串&nbsp;<code>word1</code> 和&nbsp;<code>word2</code>&nbsp;。</p>

<p>如果一个字符串 <code>x</code>&nbsp;重新排列后，<code>word2</code>&nbsp;是重排字符串的&nbsp;<span data-keyword="string-prefix">前缀</span>&nbsp;，那么我们称字符串&nbsp;<code>x</code>&nbsp;是&nbsp;<strong>合法的</strong>&nbsp;。</p>

<p>请你返回 <code>word1</code>&nbsp;中 <strong>合法</strong>&nbsp;<span data-keyword="substring-nonempty">子字符串</span>&nbsp;的数目。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>word1 = "bcca", word2 = "abc"</span></p>

<p><span class="example-io"><b>输出：</b>1</span></p>

<p><strong>解释：</strong></p>

<p>唯一合法的子字符串是&nbsp;<code>"bcca"</code>&nbsp;，可以重新排列得到&nbsp;<code>"abcc"</code>&nbsp;，<code>"abc"</code>&nbsp;是它的前缀。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>word1 = "abcabc", word2 = "abc"</span></p>

<p><span class="example-io"><b>输出：</b>10</span></p>

<p><strong>解释：</strong></p>

<p>除了长度为 1 和 2 的所有子字符串都是合法的。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>word1 = "abcabc", word2 = "aaabc"</span></p>

<p><span class="example-io"><b>输出：</b>0</span></p>
</div>

<p>&nbsp;</p>

<p><strong>解释：</strong></p>

<ul>
	<li><code>1 &lt;= word1.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= word2.length &lt;= 10<sup>4</sup></code></li>
	<li><code>word1</code> 和&nbsp;<code>word2</code>&nbsp;都只包含小写英文字母。</li>
</ul>


    
## 解题方法：滑动窗口

首先统计`word2`中每个字符分别出现了多少次，接着开始滑动窗口：

> 窗口起点是`word1`的每个字符，窗口终点是第一次“合法”的最小结束位置。

对于一个起点`l`，若最小合法位置是`r`，则合法方案是`[l, r]`、`[l, r + 1]`、`...`、`[l, len(word1) - 1]`。

+ 时间复杂度$O(len(word1)\times C+len(word2))$，其中$C=26$
+ 空间复杂度$O(C)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-01-09 11:03:16
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-09 12:39:10
 */
typedef long long ll;
class Solution {
private:
    bool ok(int* cnt1, int* cnt2) {
        for (int i = 0; i < 26; i++) {
            if (cnt1[i] < cnt2[i]) {
                return false;
            }
        }
        return true;
    }
public:
    ll validSubstringCount(string& word1, string& word2) {
        int cnt1[26] = {0}, cnt2[26] = {0};
        for (char c : word2) {
            cnt2[c - 'a']++;
        }
        ll ans = 0;
        for (int l = 0, r = 0; l < word1.size(); l++, r = max(r, l)) {
            if (l) {
                cnt1[word1[l - 1] - 'a']--;
            }
            while (!ok(cnt1, cnt2)) {
                if (r == word1.size()) {
                    return ans;
                }
                cnt1[word1[r++] - 'a']++;
            }
            ans += word1.size() - r + 1;
        }
        return ans;
    }
};

#ifdef _WIN32
/*
bcca
abc

1
*/
/*
abcabc
abc

10
*/
int main() {
    Solution sol;
    string a, b;
    while (cin >> a >> b) {
        cout << sol.validSubstringCount(a, b) << endl;
    }
    return 0;
}
#endif
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-01-09 12:39:58
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-09 12:44:30
'''
from collections import Counter, defaultdict


class Solution:
    def ok(self, cnt1: defaultdict) -> bool:
        for k, v in self.cnt2.items():
            if cnt1[k] < v:
                return False
        return True
    
    def validSubstringCount(self, word1: str, word2: str) -> int:
        self.cnt2 = Counter(word2)
        cnt1 = defaultdict(int)
        ans = l = r = 0
        while l < len(word1):
            if l:
                cnt1[word1[l - 1]] -= 1
            while not self.ok(cnt1):
                if r == len(word1):
                    return ans
                cnt1[word1[r]] += 1
                r += 1
            ans += len(word1) - r + 1
            l += 1
        return ans

```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-01-09 12:46:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-09 12:51:13
 */
class Solution {
    private boolean ok(int[] a, int[] b) {
        for (int i = 0; i < 26; i++) {
            if (a[i] < b[i]) {
                return false;
            }
        }
        return true;
    }

    public long validSubstringCount(String word1, String word2) {
        int[] cnt1 = new int[26], cnt2 = new int[26];
        for (char c : word2.toCharArray()) {
            cnt2[c - 'a']++;
        }
        long ans = 0;
        for (int l = 0, r = 0; l < word1.length(); l++) {
            if (l > 0) {
                cnt1[word1.charAt(l - 1) - 'a']--;
            }
            while (!ok(cnt1, cnt2)) {
                if (r == word1.length()) {
                    return ans;
                }
                cnt1[word1.charAt(r++) - 'a']++;
            }
            ans += word1.length() - r + 1;
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-01-09 12:52:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-09 13:10:20
 */
package main

// import "fmt"

func ok(a, b []int) bool {
    for i := range a {
        if a[i] < b[i] {
            return false
        }
    }
    return true
}

func validSubstringCount(word1 string, word2 string) (ans int64) {
    cnt1, cnt2 := make([]int, 26), make([]int, 26)
    for _, c := range word2 {
        cnt2[c - 'a']++
    }
    // fmt.Println(cnt2)
    for l, r := 0, 0; l < len(word1); l++ {
        if l > 0 {
            cnt1[word1[l - 1] - 'a']--
        }
        for !ok(cnt1, cnt2) {
            if r == len(word1) {
                return
            }
            cnt1[word1[r] - 'a']++
            r++
        }
        // fmt.Println(cnt1)
        // fmt.Println(r)
        ans += int64(len(word1) - r + 1)
    }
    return
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/01/09/LeetCode%203297.%E7%BB%9F%E8%AE%A1%E9%87%8D%E6%96%B0%E6%8E%92%E5%88%97%E5%90%8E%E5%8C%85%E5%90%AB%E5%8F%A6%E4%B8%80%E4%B8%AA%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9A%84%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2%E6%95%B0%E7%9B%AEI/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/145031494](https://letmefly.blog.csdn.net/article/details/145031494)
