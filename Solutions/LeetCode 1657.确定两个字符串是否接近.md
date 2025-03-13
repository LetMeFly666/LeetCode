---
title: 1657.确定两个字符串是否接近
date: 2023-11-30 20:41:54
tags: [题解, LeetCode, 中等, 哈希表, 字符串, 排序, 思维]
categories: [题解, LeetCode]
---

# 【LetMeFly】1657.确定两个字符串是否接近：思维题

力扣题目链接：[https://leetcode.cn/problems/determine-if-two-strings-are-close/](https://leetcode.cn/problems/determine-if-two-strings-are-close/)

<p>如果可以使用以下操作从一个字符串得到另一个字符串，则认为两个字符串 <strong>接近</strong> ：</p>

<ul>
	<li>操作 1：交换任意两个 <strong>现有</strong> 字符。

	<ul>
		<li>例如，<code>a<strong>b</strong>cd<strong>e</strong> -> a<strong>e</strong>cd<strong>b</strong></code></li>
	</ul>
	</li>
	<li>操作 2：将一个 <strong>现有</strong> 字符的每次出现转换为另一个 <strong>现有</strong> 字符，并对另一个字符执行相同的操作。
	<ul>
		<li>例如，<code><strong>aa</strong>c<strong>abb</strong> -> <strong>bb</strong>c<strong>baa</strong></code>（所有 <code>a</code> 转化为 <code>b</code> ，而所有的 <code>b</code> 转换为 <code>a</code> ）</li>
	</ul>
	</li>
</ul>

<p>你可以根据需要对任意一个字符串多次使用这两种操作。</p>

<p>给你两个字符串，<code>word1</code> 和 <code>word2</code> 。如果<em> </em><code>word1</code><em> </em>和<em> </em><code>word2</code><em> </em><strong>接近 </strong>，就返回 <code>true</code> ；否则，返回<em> </em><code>false</code><em> </em>。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>word1 = "abc", word2 = "bca"
<strong>输出：</strong>true
<strong>解释：</strong>2 次操作从 word1 获得 word2 。
执行操作 1："a<strong>bc</strong>" -> "a<strong>cb</strong>"
执行操作 1："<strong>a</strong>c<strong>b</strong>" -> "<strong>b</strong>c<strong>a</strong>"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>word1 = "a", word2 = "aa"
<strong>输出：</strong>false
<strong>解释：</strong>不管执行多少次操作，都无法从 word1 得到 word2 ，反之亦然。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>word1 = "cabbba", word2 = "abbccc"
<strong>输出：</strong>true
<strong>解释：</strong>3 次操作从 word1 获得 word2 。
执行操作 1："ca<strong>b</strong>bb<strong>a</strong>" -> "ca<strong>a</strong>bb<strong>b</strong>"
执行操作 2：<code>"</code><strong>c</strong>aa<strong>bbb</strong>" -> "<strong>b</strong>aa<strong>ccc</strong>"
执行操作 2："<strong>baa</strong>ccc" -> "<strong>abb</strong>ccc"
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>word1 = "cabbba", word2 = "aabbss"
<strong>输出：</strong>false
<strong>解释：</strong>不管执行多少次操作，都无法从 word1 得到 word2 ，反之亦然。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= word1.length, word2.length <= 10<sup>5</sup></code></li>
	<li><code>word1</code> 和 <code>word2</code> 仅包含小写英文字母</li>
</ul>


    
## 方法一：思维题

**思路**：

首先要保证两个字符串出现的字符相同（不能一个出现了```a```一个没出现过```a```）。

之后，假设字符串1的前26个字母分别出现了```1```次、```0```次、```3```次、```5```次、```0```次、```0```次、...，字符串2的前26个字母分别出现了```3```次、```5```次、```1```次、```0```次、```0```次、...，（```sorted[1, 3, 5] = sorted[3, 5, 1]```），则二者“接近”。

因为就像冒泡排序一样两两交换，总能换为对应字母出现次数相同。

**方法**：

开辟两个大小为26的数组，记录两个字符串中每个字符出现的次数。

1. 判断两个数组的“为0非0”情况是否相同
2. 判断两个数组排序后是否相等

若满足条件则返回```true```。

+ 时间复杂度$O(len(word1) + len(word2) + C\log C)$，其中$C=26$
+ 空间复杂度$O(C)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int bin1[26] = {0}, bin2[26] = {0};
        for (char c : word1) {
            bin1[c - 'a']++;
        }
        for (char c : word2) {
            bin2[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if ((bin1[i] || 0) != (bin2[i] || 0)) {
                return false;
            }
        }
        sort(bin1, bin1 + 26);
        sort(bin2, bin2 + 26);
        for (int i = 0; i < 26; i++) {
            if (bin1[i] != bin2[i]) {
                return false;
            }
        }
        return true;
    }
};
```

#### Python

```python
class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        bin1 = [0] * 26
        bin2 = [0] * 26
        for c in word1:
            bin1[ord(c) - ord('a')] += 1
        for c in word2:
            bin2[ord(c) - ord('a')] += 1
        for i in range(26):
            if (bin1[i] == 0) != (bin2[i] == 0):
                return False
        bin1.sort()
        bin2.sort()
        return bin1 == bin2
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/11/30/LeetCode%201657.%E7%A1%AE%E5%AE%9A%E4%B8%A4%E4%B8%AA%E5%AD%97%E7%AC%A6%E4%B8%B2%E6%98%AF%E5%90%A6%E6%8E%A5%E8%BF%91/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/134721619](https://letmefly.blog.csdn.net/article/details/134721619)
