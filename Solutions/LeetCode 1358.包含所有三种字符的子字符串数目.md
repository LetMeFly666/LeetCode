---
title: 1358.包含所有三种字符的子字符串数目：滑动窗口(两种写法直接推荐方法二)
date: 2026-07-01 15:39:10
tags: [题解, LeetCode, 中等, 哈希表, 字符串, 滑动窗口]
categories: [题解, LeetCode]
---

# 【LetMeFly】1358.包含所有三种字符的子字符串数目：滑动窗口(两种写法直接推荐方法二)

力扣题目链接：[https://leetcode.cn/problems/number-of-substrings-containing-all-three-characters/](https://leetcode.cn/problems/number-of-substrings-containing-all-three-characters/)

<p>给你一个字符串 <code>s</code>&nbsp;，它只包含三种字符 a, b 和 c 。</p>

<p>请你返回 a，b 和 c 都&nbsp;<strong>至少&nbsp;</strong>出现过一次的子字符串数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = &quot;abcabc&quot;
<strong>输出：</strong>10
<strong>解释：</strong>包含 a，b 和 c 各至少一次的子字符串为<em> &quot;</em>abc<em>&quot;, &quot;</em>abca<em>&quot;, &quot;</em>abcab<em>&quot;, &quot;</em>abcabc<em>&quot;, &quot;</em>bca<em>&quot;, &quot;</em>bcab<em>&quot;, &quot;</em>bcabc<em>&quot;, &quot;</em>cab<em>&quot;, &quot;</em>cabc<em>&quot; </em>和<em> &quot;</em>abc<em>&quot; </em>(<strong>相同</strong><strong>字符串算多次</strong>)<em>。</em>
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = &quot;aaacb&quot;
<strong>输出：</strong>3
<strong>解释：</strong>包含 a，b 和 c 各至少一次的子字符串为<em> &quot;</em>aaacb<em>&quot;, &quot;</em>aacb<em>&quot; </em>和<em> &quot;</em>acb<em>&quot; 。</em>
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = &quot;abc&quot;
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= s.length &lt;= 5 x 10^4</code></li>
	<li><code>s</code>&nbsp;只包含字符 a，b 和 c 。</li>
</ul>


    
## 解题方法：滑动窗口

使用两个指针，时刻满足指针之间的“窗口”是最短的同时包含abc的窗口。

### 滑动方法一：枚举窗口起点l（l 到 r-1以及r的右边 全合法）——推荐方法二

两个指针，每次左指针$l$右移一位，不断右移右指针$r$直到窗口$[l, r)$中含有三种字母。

那么对于起点$l$，其到$r-1$合法到话，其到$r$、$r+1$、$\cdots$、$n-1$（共计$n-r+1$个）都合法。

### 滑动方法二：枚举窗口终点r（l-1以及l-1的左边 到 r 全合法）

两个指针，每次右指针$r$右移一位，不断右移左指针$l$直到*首次满足*窗口$[l, r]$中不含有三种字母。

那么$[l-1, r]$、$[l-2, r]$、$\cdots$、$[0, r]$（如果存在）(共计l个)均合法。

## 时空复杂度分析

+ 时间复杂度$O(len(s))$，每个字母最多被遍历两次
+ 空间复杂度$O(1)$

## AC代码

### C++——方法二

```cpp
/*
 * @LastEditTime: 2026-07-01 15:38:27
 */
class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int cnt[3] = {0};
        for (int l = 0, r = 0, n = s.size(); r < n; r++) {
            cnt[s[r] - 'a']++;
            while (cnt[0] && cnt[1] && cnt[2]) {
                cnt[s[l++] - 'a']--;
            }
            ans += l;
        }
        return ans;
    }
};
```

### C++——方法一

```cpp
/*
 * @LastEditTime: 2026-07-01 15:34:43
 */
class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int cnt[3] = {0};
        for (int l = 0, r = 0, n = s.size(); l < n; l++) {
            while (r < n && !(cnt[0] && cnt[1] && cnt[2])) {
                cnt[s[r++] - 'a']++;
            }
            ans += (cnt[0] && cnt[1] && cnt[2]) ? n - r + 1 : 0;
            cnt[s[l] - 'a']--;
        }
        return ans;
    }
};
```

### Python——方法二

```python
'''
LastEditTime: 2026-07-01 15:49:11
'''
class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        ans = 0
        cnt = [0, 0, 0]
        l = 0
        for r in range(len(s)):
            cnt[ord(s[r]) - ord('a')] += 1
            while cnt[0] and cnt[1] and cnt[2]:
                cnt[ord(s[l]) - ord('a')] -= 1
                l += 1
            ans += l
        return ans
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/162490761)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/06/30/LeetCode%201358.%E5%8C%85%E5%90%AB%E6%89%80%E6%9C%89%E4%B8%89%E7%A7%8D%E5%AD%97%E7%AC%A6%E7%9A%84%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2%E6%95%B0%E7%9B%AE/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
