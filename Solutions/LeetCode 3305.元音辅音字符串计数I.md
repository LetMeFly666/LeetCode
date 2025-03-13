---
title: 3305.元音辅音字符串计数 I：今天I先模拟，明天II再开滑
date: 2025-03-12 10:05:15
tags: [题解, LeetCode, 中等, 哈希表, 字符串, 滑动窗口]
categories: [题解, LeetCode]
---

# 【LetMeFly】3305.元音辅音字符串计数 I：今天I先模拟，明天II再开滑

力扣题目链接：[https://leetcode.cn/problems/count-of-substrings-containing-every-vowel-and-k-consonants-i/](https://leetcode.cn/problems/count-of-substrings-containing-every-vowel-and-k-consonants-i/)

<p>给你一个字符串 <code>word</code> 和一个 <strong>非负 </strong>整数 <code>k</code>。</p>

<p>返回 <code>word</code> 的 <span data-keyword="substring-nonempty">子字符串</span> 中，每个元音字母（<code>'a'</code>、<code>'e'</code>、<code>'i'</code>、<code>'o'</code>、<code>'u'</code>）<strong>至少</strong> 出现一次，并且 <strong>恰好 </strong>包含 <code>k</code> 个辅音字母的子字符串的总数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">word = "aeioqq", k = 1</span></p>

<p><strong>输出：</strong><span class="example-io">0</span></p>

<p><strong>解释：</strong></p>

<p>不存在包含所有元音字母的子字符串。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">word = "aeiou", k = 0</span></p>

<p><strong>输出：</strong><span class="example-io">1</span></p>

<p><strong>解释：</strong></p>

<p>唯一一个包含所有元音字母且不含辅音字母的子字符串是 <code>word[0..4]</code>，即 <code>"aeiou"</code>。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">word = "ieaouqqieaouqq", k = 1</span></p>

<p><strong>输出：</strong>3</p>

<p><strong>解释：</strong></p>

<p>包含所有元音字母并且恰好含有一个辅音字母的子字符串有：</p>

<ul>
	<li><code>word[0..5]</code>，即 <code>"ieaouq"</code>。</li>
	<li><code>word[6..11]</code>，即 <code>"qieaou"</code>。</li>
	<li><code>word[7..12]</code>，即 <code>"ieaouq"</code>。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>5 &lt;= word.length &lt;= 250</code></li>
	<li><code>word</code> 仅由小写英文字母组成。</li>
	<li><code>0 &lt;= k &lt;= word.length - 5</code></li>
</ul>


    
## 解题方法：模拟

$O(n^2)$的时间复杂度模拟字符串起止位置范围，并在模拟过程中统计是否符合题意即可。

+ 时间复杂度$O(n^2C)$，其中$C$是小写元音字母个数，$C=5$
+ 空间复杂度$O(C)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-12 09:38:45
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-12 09:40:10
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    static constexpr char yuanyin[] = "aeiou";
    
    inline bool allYuan(int* cnt) {
        for (int i = 0; i < 5; i++) {
            if (!cnt[i]) {
                return false;
            }
        }
        return true;
    }
public:
    int countOfSubstrings(string word, int k) {
        int ans = 0;
        for (int i = 0; i < word.size(); i++) {
            int cnt[5] = {0};
            int cntk = 0;
            for (int j = i; j < word.size(); j++) {
                bool isYuan = false;
                for (int n = 0; n < 5; n++) {
                    if (word[j] == yuanyin[n]) {
                        isYuan = true;
                        cnt[n]++;
                        break;
                    }
                }
                cntk += !isYuan;
                ans += allYuan(cnt) && cntk == k;
            }
        }
        return ans;
    }
};
```

#### C++ - 如果觉得N^2难，N^3倒是也能过

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-12 09:29:51
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-12 09:40:21
 */
class Solution {
private:
    static constexpr char yuanyin[] = "aeiou";
    
    inline bool allYuan(int* cnt) {
        for (int i = 0; i < 5; i++) {
            if (!cnt[i]) {
                return false;
            }
        }
        return true;
    }
public:
    int countOfSubstrings(string word, int k) {
        int ans = 0;
        for (int i = 0; i < word.size(); i++) {
            for (int j = i; j < word.size(); j++) {
                int cnt[5] = {0};
                int cntk = 0;
                for (int m = i; m <= j; m++) {
                    bool isYuan = false;
                    for (int n = 0; n < 5; n++) {
                        if (word[m] == yuanyin[n]) {
                            isYuan = true;
                            cnt[n]++;
                            break;
                        }
                    }
                    cntk += !isYuan;
                }
                ans += allYuan(cnt) && cntk == k;
            }
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-03-12 09:41:17
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-12 09:44:21
'''
AEIOU = 'aeiou'
class Solution:
    def countOfSubstrings(self, word: str, k: int) -> int:
        ans = 0
        for i in range(len(word)):
            cnt5 = [0] * 5
            cntk = 0
            for j in range(i, len(word)):
                for n in range(5):
                    if word[j] == AEIOU[n]:
                        cnt5[n] += 1
                        break
                cntk += word[j] not in AEIOU
                ans += all(cnt5) and cntk == k
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-03-12 09:44:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-12 09:53:33
 */
class Solution {
    private final char[] aeiou = {'a', 'e', 'i', 'o', 'u'};

    private int isaeiou(char c) {
        for (int i = 0; i < 5; i++) {
            if (aeiou[i] == c) {
                return i;
            }
        }
        return -1;
    }

    private boolean all(int[] cnt) {
        for (int i = 0; i < 5; i++) {
            if (cnt[i] == 0) {
                return false;
            }
        }
        return true;
    }

    public int countOfSubstrings(String word, int k) {
        int ans = 0;
        for (int i = 0; i < word.length(); i++) {
            int[] cnt5 = new int[5];
            int cntk = 0;
            for (int j = i; j < word.length(); j++) {
                int index = isaeiou(word.charAt(j));
                if (index == -1) {
                    cntk++;
                } else {
                    cnt5[index]++;
                }
                if (all(cnt5) && cntk == k) {
                    ans++;
                }
            }
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-03-12 09:54:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-12 10:03:41
 */
package main

var aeiou map[byte]bool = map[byte]bool{'a': true, 'e': true, 'i': true, 'o': true, 'u': true}

func countOfSubstrings(word string, k int) (ans int) {
    for i, _ := range word {
        cnt5 := map[byte]bool{}
        cntk := 0
        for _, c := range word[i:] {
            if aeiou[byte(c)] {
                cnt5[byte(c)] = true
            } else {
                cntk++
            }
            if len(cnt5) == 5 && cntk == k {
                ans++
            }
        }
    }
    return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/146197747)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/03/12/LeetCode%203305.%E5%85%83%E9%9F%B3%E8%BE%85%E9%9F%B3%E5%AD%97%E7%AC%A6%E4%B8%B2%E8%AE%A1%E6%95%B0I/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
