---
title: 3090.每个字符最多出现两次的最长子字符串：二重循环 / 滑动窗口
date: 2026-08-14 09:45:17
tags: [题解, LeetCode, 简单, 哈希表, 字符串, 滑动窗口, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】3090.每个字符最多出现两次的最长子字符串：二重循环 / 滑动窗口

力扣题目链接：[https://leetcode.cn/problems/maximum-length-substring-with-two-occurrences/](https://leetcode.cn/problems/maximum-length-substring-with-two-occurrences/)

<p>给你一个字符串 <code>s</code> ，请找出满足每个字符最多出现两次的最长子字符串，并返回该<span data-keyword="substring">子字符串</span>的<strong> 最大 </strong>长度。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">s = "bcbbbcba"</span></p>

<p><strong>输出：</strong> <span class="example-io">4</span></p>

<p><strong>解释：</strong></p>

<p>以下子字符串长度为 4，并且每个字符最多出现两次：<code>"bcbb<u>bcba</u>"</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">s = "aaaa"</span></p>

<p><strong>输出：</strong> <span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p>以下子字符串长度为 2，并且每个字符最多出现两次：<code>"<u>aa</u>aa"</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul><!-- 字符串 s 的长度在 2 到 100 之间 -->
	<li><code>2 &lt;= s.length &lt;= 100</code></li>
	<!-- 字符串 s 仅包含小写英文字母 -->
	<li><code>s</code> 仅由小写英文字母组成。</li>
</ul>


    
## 解题方法一：二重循环模拟

第一重循环枚举子字符串起点，第二重循环枚举子字符串终点，并在二重循环期间维护子串中每个字符的出现次数，若有字符出现次数超过两次则结束二重循环，否则更新答案最大值。

+ 时间复杂度$O(len(s)^2\times C)$，其中$C=26$
+ 空间复杂度$O(C)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-08-14 09:33:37
 */
class Solution {
private:
    bool ok(int cnt[26]) {
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 2) {
                return false;
            }
        }
        return true;
    }
public:
    int maximumLengthSubstring(string s) {
        int ans = 0;
        for (int i = 0, n = s.size(); i < n; i++) {
            int cnt[26] = {0};
            for (int j = i; j < n; j++) {
                cnt[s[j] - 'a']++;
                if (ok(cnt)) {
                    ans = max(ans, j - i + 1);
                } else {
                    break;
                }
            }
        }
        return ans;
    }
};
```

## 解题方法二：滑动窗口

左右两个指针$l$、$r$始终维护以$r$为终点时的最大合法子字符串。每次$r$指针右移一位，若新字符出现次数超过$2$次，则不断右移$l$指针直至子字符串再次合法。

+ 时间复杂度$O(len(s))$，可以只关注新加入窗口的这一个字符是否超过2次，从而无需有$O(C)$的复杂度
+ 空间复杂度$O(C)$，其中$C=26$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-08-14 09:38:09
 */
class Solution {
public:
    int maximumLengthSubstring(string& s) {
        int ans = 0;
        int cnt[26] = {0};
        for (int l = 0, r = 0, n = s.size(); r < n; r++) {
            int th = s[r] - 'a';
            cnt[th]++;
            while (cnt[th] > 2) {
                cnt[s[l++] - 'a']--;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
```

+ 执行用时分布 0 ms 击败 100.00%
+ 消耗内存分布 8.82 MB 击败 98.10%


#### Python

```python
'''
LastEditTime: 2026-08-14 09:44:21
'''
class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        ans = 0
        l = r = 0
        cnt = [0] * 26
        for r in range(len(s)):
            th = ord(s[r]) - 97
            cnt[th] += 1
            while cnt[th] > 2:
                cnt[ord(s[l]) - 97] -= 1
                l += 1
            ans = max(ans, r - l + 1)
        return ans
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/163745667)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/08/14/LeetCode%203090.%E6%AF%8F%E4%B8%AA%E5%AD%97%E7%AC%A6%E6%9C%80%E5%A4%9A%E5%87%BA%E7%8E%B0%E4%B8%A4%E6%AC%A1%E7%9A%84%E6%9C%80%E9%95%BF%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
