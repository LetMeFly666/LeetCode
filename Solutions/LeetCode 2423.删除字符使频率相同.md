---
title: 2423.删除字符使频率相同
date: 2023-04-29 14:12:40
tags: [题解, LeetCode, 简单, 哈希表, 字符串, 计数, 模拟]
---

# 【LetMeFly】2423.删除字符使频率相同

力扣题目链接：[https://leetcode.cn/problems/remove-letter-to-equalize-frequency/](https://leetcode.cn/problems/remove-letter-to-equalize-frequency/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的字符串&nbsp;<code>word</code>&nbsp;，字符串只包含小写英文字母。你需要选择 <strong>一个</strong>&nbsp;下标并 <strong>删除</strong>&nbsp;下标处的字符，使得 <code>word</code>&nbsp;中剩余每个字母出现 <strong>频率</strong>&nbsp;相同。</p>

<p>如果删除一个字母后，<code>word</code>&nbsp;中剩余所有字母的出现频率都相同，那么返回 <code>true</code>&nbsp;，否则返回 <code>false</code>&nbsp;。</p>

<p><strong>注意：</strong></p>

<ul>
	<li>字母&nbsp;<code>x</code>&nbsp;的 <strong>频率</strong><strong>&nbsp;</strong>是这个字母在字符串中出现的次数。</li>
	<li>你 <strong>必须</strong>&nbsp;恰好删除一个字母，不能一个字母都不删除。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>word = "abcc"
<b>输出：</b>true
<b>解释：</b>选择下标 3 并删除该字母，word 变成 "abc" 且每个字母出现频率都为 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>word = "aazz"
<b>输出：</b>false
<b>解释：</b>我们必须删除一个字母，所以要么 "a" 的频率变为 1 且 "z" 的频率为 2 ，要么两个字母频率反过来。所以不可能让剩余所有字母出现频率相同。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= word.length &lt;= 100</code></li>
	<li><code>word</code>&nbsp;只包含小写英文字母。</li>
</ul>


    
## 方法一：模拟

首先开辟一个大小为26的数组$bin$，用来存放26个字母的出现次数（只需要遍历一遍字符串即可得到）

接着用$i$从0遍历到26，如果$bin[i]$非零，就让$bin[i]$减去$1$，如果**其余非零的bin值全部相同**就返回$true$

如果遍历完也没有返回$true$，就返回$false$

怎么判断非零bin的值是否全部相等呢？使用一个变量$val = 0$，遍历$bin$。

+ 如果$bin[i]$非零，就看$val$是否为$0$
    + 如果$val$为$0$，就令$val = bin[i]$
	+ 否则若$val \neq bin[i]$，就返回$false$

若遍历完未返回$false$，就返回$true$

+ 时间复杂度$O(len(word) + C^2)$，其中$C=26$
+ 空间复杂度$O(C)$

### AC代码

#### C++

C++时间击败100%，空间击败93.22%嘿嘿，没有使用自带哈希表

```cpp
class Solution {
private:
    bool isSame(int* a) {
        int val = 0;
        for (int i = 0; i < 26; i++) {
            if (a[i]) {
                if (val) {
                    if (a[i] != val) {
                        return false;
                    }
                }
                else {
                    val = a[i];
                }
            }
        }
        return true;
    }
public:
    bool equalFrequency(string word) {
        int bin[26] = {0};
        for (char c : word) {
            bin[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (bin[i]) {
                bin[i]--;
                if (isSame(bin)) {
                    return true;
                }
                bin[i]++;
            }
        }
        return false;
    }
};
```

#### Python

```python
class Solution:
    def isSame(self, a: list) -> bool:
        val = 0
        for v in a:
            if v:
                if val:
                    if val != v:
                        return False
                else:
                    val = v
        return True
    
    def equalFrequency(self, word: str) -> bool:
        bin = [0] * 26
        for c in word:
            bin[ord(c) - ord('a')] += 1
        for i in range(26):
            if bin[i]:
                bin[i] -= 1
                if self.isSame(bin):
                    return True
                bin[i] += 1
        return False
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/04/29/LeetCode%202423.%E5%88%A0%E9%99%A4%E5%AD%97%E7%AC%A6%E4%BD%BF%E9%A2%91%E7%8E%87%E7%9B%B8%E5%90%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130440474](https://letmefly.blog.csdn.net/article/details/130440474)
