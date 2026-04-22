---
title: 2452.距离字典两次编辑以内的单词：暴力
date: 2026-04-22 23:11:11
tags: [题解, LeetCode, 中等, 字典树, 数组, 字符串, 暴力, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】2452.距离字典两次编辑以内的单词：暴力

力扣题目链接：[https://leetcode.cn/problems/words-within-two-edits-of-dictionary/](https://leetcode.cn/problems/words-within-two-edits-of-dictionary/)

<p>给你两个字符串数组&nbsp;<code>queries</code> 和&nbsp;<code>dictionary</code>&nbsp;。数组中所有单词都只包含小写英文字母，且长度都相同。</p>

<p>一次 <strong>编辑</strong>&nbsp;中，你可以从 <code>queries</code>&nbsp;中选择一个单词，将任意一个字母修改成任何其他字母。从&nbsp;<code>queries</code>&nbsp;中找到所有满足以下条件的字符串：<strong>不超过</strong>&nbsp;两次编辑内，字符串与&nbsp;<code>dictionary</code>&nbsp;中某个字符串相同。</p>

<p>请你返回<em>&nbsp;</em><code>queries</code>&nbsp;中的单词列表，这些单词距离&nbsp;<code>dictionary</code>&nbsp;中的单词&nbsp;<strong>编辑次数</strong>&nbsp;不超过&nbsp;<strong>两次</strong>&nbsp;。单词返回的顺序需要与&nbsp;<code>queries</code>&nbsp;中原本顺序相同。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>queries = ["word","note","ants","wood"], dictionary = ["wood","joke","moat"]
<b>输出：</b>["word","note","wood"]
<strong>解释：</strong>
- 将 "word" 中的 'r' 换成 'o' ，得到 dictionary 中的单词 "wood" 。
- 将 "note" 中的 'n' 换成 'j' 且将 't' 换成 'k' ，得到 "joke" 。
- "ants" 需要超过 2 次编辑才能得到 dictionary 中的单词。
- "wood" 不需要修改（0 次编辑），就得到 dictionary 中相同的单词。
所以我们返回 ["word","note","wood"] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>queries = ["yes"], dictionary = ["not"]
<b>输出：</b>[]
<strong>解释：</strong>
"yes" 需要超过 2 次编辑才能得到 "not" 。
所以我们返回空数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= queries.length, dictionary.length &lt;= 100</code></li>
	<li><code>n == queries[i].length == dictionary[j].length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li>所有&nbsp;<code>queries[i]</code> 和&nbsp;<code>dictionary[j]</code>&nbsp;都只包含小写英文字母。</li>
</ul>


    
## 解题方法：暴力匹配

两层遍历遍历两个字符串数组，字符串两两尝试匹配。

对于两个字符串，统计相同位置不同字符的个数，若不超过$2$则合格。

合格后记得break，防止重复加入到答案数组中。

+ 时间复杂度$O(n\times len(queries)\times len(dictionary))￥
+ 空间复杂度$O(1)$吗，力扣返回值不计入算法空间复杂度

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-04-22 23:10:53
 */
class Solution {
inline bool ok(const string& a, const string& b) {
    int diff = 0;
    for (int i = 0; i < a.size(); i++) {
        diff += a[i] != b[i];
    }
    return diff <= 2;
}
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for (string& a : queries) {
            for (string& b : dictionary) {
                if (ok(a, b)) {
                    ans.push_back(a);
                    break;
                }
            }
        }
        return ans;
    }
};

```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/160419812)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/04/22/LeetCode%202452.%E8%B7%9D%E7%A6%BB%E5%AD%97%E5%85%B8%E4%B8%A4%E6%AC%A1%E7%BC%96%E8%BE%91%E4%BB%A5%E5%86%85%E7%9A%84%E5%8D%95%E8%AF%8D/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
