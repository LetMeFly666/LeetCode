---
title: 3120.统计特殊字母的数量 I：(手写)哈希表
date: 2026-05-26 23:55:19
tags: [题解, LeetCode, 简单, 哈希表, set, 字符串]
categories: [题解, LeetCode]
---

# 【LetMeFly】3120.统计特殊字母的数量 I：(手写)哈希表

力扣题目链接：[https://leetcode.cn/problems/count-the-number-of-special-characters-i/](https://leetcode.cn/problems/count-the-number-of-special-characters-i/)

<p>给你一个字符串 <code>word</code>。如果 <code>word</code> 中同时存在某个字母的小写形式和大写形式，则称这个字母为 <strong>特殊字母</strong> 。</p>

<p>返回 <code>word</code> 中<strong> </strong><strong>特殊字母 </strong>的数量。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">word = "aaAbcBC"</span></p>

<p><strong>输出：</strong><span class="example-io">3</span></p>

<p><strong>解释：</strong></p>

<p><code>word</code> 中的特殊字母是 <code>'a'</code>、<code>'b'</code> 和 <code>'c'</code>。</p>
</div>

<p><strong class="example">示例 2:</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">word = "abc"</span></p>

<p><strong>输出：</strong><span class="example-io">0</span></p>

<p><strong>解释：</strong></p>

<p><code>word</code> 中不存在大小写形式同时出现的字母。</p>
</div>

<p><strong class="example">示例 3:</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">word = "abBCab"</span></p>

<p><strong>输出：</strong>1</p>

<p><strong>解释：</strong></p>

<p><code>word</code> 中唯一的特殊字母是 <code>'b'</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 50</code></li>
	<li><code>word</code> 仅由小写和大写英文字母组成。</li>
</ul>


    
## 解题方法：哈希表

遍历一般字符串并把所有出现过的字符放入哈希表中，从0到25遍历这26个字母，看哪个字母的大小写都出现过。

有办法使用数组代替(作为)哈希表吗？以及有办法使用52长度的数组作为哈希表吗？有，判断下大小写放入数组对应的位置就好。

+ 时间复杂度$O(len(word)+C)$，其中$C=26\times 2$
+ 空间复杂度$O(C)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-05-26 23:53:14
 */
class Solution {
public:
    int numberOfSpecialChars(string word) {
        bool lower[26] = {false}, upper[26] = {false};
        for (char c : word) {
            if ('a' <= c && c <= 'z') {
                lower[c - 'a'] = true;
            } else {
                upper[c - 'A'] = true;
            }
        }

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans += lower[i] && upper[i];
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/161432822)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/05/26/LeetCode%203120.%E7%BB%9F%E8%AE%A1%E7%89%B9%E6%AE%8A%E5%AD%97%E6%AF%8D%E7%9A%84%E6%95%B0%E9%87%8FI/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
