---
title: 966.元音拼写检查器：三个哈希表实现
date: 2025-09-14 22:53:03
tags: [题解, LeetCode, 中等, 数组, 哈希表, set, map, 字符串]
categories: [题解, LeetCode]
---

# 【LetMeFly】966.元音拼写检查器：三个哈希表实现

力扣题目链接：[https://leetcode.cn/problems/vowel-spellchecker/](https://leetcode.cn/problems/vowel-spellchecker/)

<p>在给定单词列表&nbsp;<code>wordlist</code>&nbsp;的情况下，我们希望实现一个拼写检查器，将查询单词转换为正确的单词。</p>

<p>对于给定的查询单词&nbsp;<code>query</code>，拼写检查器将会处理两类拼写错误：</p>

<ul>
	<li>大小写：如果查询匹配单词列表中的某个单词（<strong>不区分大小写</strong>），则返回的正确单词与单词列表中的大小写相同。

	<ul>
		<li>例如：<code>wordlist = ["yellow"]</code>, <code>query = "YellOw"</code>: <code>correct = "yellow"</code></li>
		<li>例如：<code>wordlist = ["Yellow"]</code>, <code>query = "yellow"</code>: <code>correct = "Yellow"</code></li>
		<li>例如：<code>wordlist = ["yellow"]</code>, <code>query = "yellow"</code>: <code>correct = "yellow"</code></li>
	</ul>
	</li>
	<li>元音错误：如果在将查询单词中的元音 <code>('a', 'e', 'i', 'o', 'u')</code>&nbsp;&nbsp;分别替换为任何元音后，能与单词列表中的单词匹配（<strong>不区分大小写</strong>），则返回的正确单词与单词列表中的匹配项大小写相同。
	<ul>
		<li>例如：<code>wordlist = ["YellOw"]</code>, <code>query = "yollow"</code>: <code>correct = "YellOw"</code></li>
		<li>例如：<code>wordlist = ["YellOw"]</code>, <code>query = "yeellow"</code>: <code>correct = ""</code> （无匹配项）</li>
		<li>例如：<code>wordlist = ["YellOw"]</code>, <code>query = "yllw"</code>: <code>correct = ""</code> （无匹配项）</li>
	</ul>
	</li>
</ul>

<p>此外，拼写检查器还按照以下优先级规则操作：</p>

<ul>
	<li>当查询完全匹配单词列表中的某个单词（<strong>区分大小写</strong>）时，应返回相同的单词。</li>
	<li>当查询匹配到大小写问题的单词时，您应该返回单词列表中的第一个这样的匹配项。</li>
	<li>当查询匹配到元音错误的单词时，您应该返回单词列表中的第一个这样的匹配项。</li>
	<li>如果该查询在单词列表中没有匹配项，则应返回空字符串。</li>
</ul>

<p>给出一些查询 <code>queries</code>，返回一个单词列表 <code>answer</code>，其中 <code>answer[i]</code> 是由查询 <code>query = queries[i]</code> 得到的正确单词。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
<strong>输出：</strong>["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]</pre>

<p><strong>示例 2:</strong></p>

<pre>
<b>输入：</b>wordlist = ["yellow"], queries = ["YellOw"]
<b>输出：</b>["yellow"]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= wordlist.length, queries.length &lt;= 5000</code></li>
	<li><code>1 &lt;= wordlist[i].length, queries[i].length &lt;= 7</code></li>
	<li><code>wordlist[i]</code>&nbsp;和&nbsp;<code>queries[i]</code>&nbsp;只包含英文字母</li>
</ul>


    
## 解题方法：哈希表

第一优先级：字符串完全相同。我们只需要使用一个哈希表把原始字符加入哈希表中，对于一个query就能知道是否存在完全匹配的word了。若存在则返回，不存在进入第二优先级。

第二优先级：字符串忽略大小写看是否相同。我们只需要将每个字符串全转为小写字母后插入哈希表即可。键为小写字符串，值为第一个对应这个小写字符串的原始字符串。对于一个query，小写字符化后看是否在哈希表中，若在则返回否则进入第三优先级。

第三优先级：字符串忽略大小写且可以自由替换元音音符。将字符串小写后并将所有元音音符替换为'a'并插入哈希表中。插入方式和query方式同上。

第四优先级：直接返回空字符串。

+ 时间复杂度$O((w+q)L)$，其中$w=len(wordlist)$，$q=len(queries)$，$L$是平均一个单词的长度
+ 空间复杂度$O(wL)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-09-14 15:21:26
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-14 15:33:04
 */
class Solution {
private:
    string toLower(string s) {
        for (char& c : s) {
            if ('A' <= c && c <= 'Z') {
                c = tolower(c);
            }
        }
        return s;
    }

    string toAeiou(string s) {
        for (char& c : s) {
            if (c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                c = 'a';
            }
        }
        return s;
    }
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> original;
        unordered_map<string, string> lowers, aeious;  // 其实改为<string, int>只存下标也行
        for (string& s : wordlist) {
            original.insert(s);
            string lower = toLower(s);
            if (!lowers.count(lower)) {
                lowers[lower] = s;
            }
            string aeiou = toAeiou(lower);
            if (!aeious.count(aeiou)) {
                aeious[aeiou] = s;
            }
        }
        for (string& q : queries) {
            if (original.count(q)) {
                continue;
            }
            string lower = toLower(q);
            if (lowers.count(lower)) {
                q = lowers[lower];
                continue;
            }
            string aeiou = toAeiou(lower);
            if (aeious.count(aeiou)) {
                q = aeious[aeiou];
                continue;
            }
            q = "";  // 这个别忘了
        }
        return queries;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/151690858)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/09/14/LeetCode%200966.%E5%85%83%E9%9F%B3%E6%8B%BC%E5%86%99%E6%A3%80%E6%9F%A5%E5%99%A8/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
