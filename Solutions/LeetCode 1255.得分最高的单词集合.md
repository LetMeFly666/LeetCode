---
title: 1255.得分最高的单词集合
date: 2023-02-26 21:21:07
tags: [题解, LeetCode, 困难, 位运算, 数组, 字符串, 动态规划, 回溯, 状态压缩]
---

# 【LetMeFly】1255.得分最高的单词集合

力扣题目链接：[https://leetcode.cn/problems/maximum-score-words-formed-by-letters/](https://leetcode.cn/problems/maximum-score-words-formed-by-letters/)

<p>你将会得到一份单词表&nbsp;<code>words</code>，一个字母表&nbsp;<code>letters</code>&nbsp;（可能会有重复字母），以及每个字母对应的得分情况表&nbsp;<code>score</code>。</p>

<p>请你帮忙计算玩家在单词拼写游戏中所能获得的「最高得分」：能够由&nbsp;<code>letters</code>&nbsp;里的字母拼写出的&nbsp;<strong>任意</strong>&nbsp;属于 <code>words</code>&nbsp;单词子集中，分数最高的单词集合的得分。</p>

<p>单词拼写游戏的规则概述如下：</p>

<ul>
	<li>玩家需要用字母表&nbsp;<code>letters</code> 里的字母来拼写单词表&nbsp;<code>words</code>&nbsp;中的单词。</li>
	<li>可以只使用字母表&nbsp;<code>letters</code> 中的部分字母，但是每个字母最多被使用一次。</li>
	<li>单词表 <code>words</code>&nbsp;中每个单词只能计分（使用）一次。</li>
	<li>根据字母得分情况表<code>score</code>，字母 <code>&#39;a&#39;</code>,&nbsp;<code>&#39;b&#39;</code>,&nbsp;<code>&#39;c&#39;</code>, ... ,&nbsp;<code>&#39;z&#39;</code> 对应的得分分别为 <code>score[0]</code>, <code>score[1]</code>,&nbsp;...,&nbsp;<code>score[25]</code>。</li>
	<li>本场游戏的「得分」是指：玩家所拼写出的单词集合里包含的所有字母的得分之和。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>words = [&quot;dog&quot;,&quot;cat&quot;,&quot;dad&quot;,&quot;good&quot;], letters = [&quot;a&quot;,&quot;a&quot;,&quot;c&quot;,&quot;d&quot;,&quot;d&quot;,&quot;d&quot;,&quot;g&quot;,&quot;o&quot;,&quot;o&quot;], score = [1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]
<strong>输出：</strong>23
<strong>解释：</strong>
字母得分为  a=1, c=9, d=5, g=3, o=2
使用给定的字母表 letters，我们可以拼写单词 &quot;dad&quot; (5+1+5)和 &quot;good&quot; (3+2+2+5)，得分为 23 。
而单词 &quot;dad&quot; 和 &quot;dog&quot; 只能得到 21 分。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>words = [&quot;xxxz&quot;,&quot;ax&quot;,&quot;bx&quot;,&quot;cx&quot;], letters = [&quot;z&quot;,&quot;a&quot;,&quot;b&quot;,&quot;c&quot;,&quot;x&quot;,&quot;x&quot;,&quot;x&quot;], score = [4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10]
<strong>输出：</strong>27
<strong>解释：</strong>
字母得分为  a=4, b=4, c=4, x=5, z=10
使用给定的字母表 letters，我们可以组成单词 &quot;ax&quot; (4+5)， &quot;bx&quot; (4+5) 和 &quot;cx&quot; (4+5) ，总得分为 27 。
单词 &quot;xxxz&quot; 的得分仅为 25 。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>words = [&quot;leetcode&quot;], letters = [&quot;l&quot;,&quot;e&quot;,&quot;t&quot;,&quot;c&quot;,&quot;o&quot;,&quot;d&quot;], score = [0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0]
<strong>输出：</strong>0
<strong>解释：</strong>
字母 &quot;e&quot; 在字母表 letters 中只出现了一次，所以无法组成单词表 words 中的单词。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 14</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 15</code></li>
	<li><code>1 &lt;= letters.length &lt;= 100</code></li>
	<li><code>letters[i].length == 1</code></li>
	<li><code>score.length ==&nbsp;26</code></li>
	<li><code>0 &lt;= score[i] &lt;= 10</code></li>
	<li><code>words[i]</code>&nbsp;和&nbsp;<code>letters[i]</code>&nbsp;只包含小写的英文字母。</li>
</ul>


    
## 方法一：状态压缩（二进制枚举）

这道题不难发现，单词表中最多有14个单词。咦，$2^{14}=16384$，很小诶有没有发现

因此我们可以枚举所有的“拼成单词”的情况，（我们将单词的个数$len(words)$记为$n$）也就是说用变量$mask$从$0$到$2^{n} - 1$。对于$maks$二进制下其中的每一位（我们只关注低$n$位），如果这一位是1就选这个对应的单词，否则就不选。

总之，就是枚举所有的“拼成的单词”的组合情况（上面的描述），然后判断给定字母能否拼出这些单词，如果能，就更新“答案分数的最大值”

+ 时间复杂度$O(2^{len(words)}\times len(word))$，其中$len(word)$代表单词的平均长度。
+ 空间复杂度$O(C)$，其中$C$是字符集的大小，本题中$C=26$，用来记录字母的个数。

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int ans = 0;
        vector<int> letter(26);
        for (char l : letters){
            letter[l - 'a']++;
        }

        int n = words.size();
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> letterLefted = letter;
            int thisScore = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    for (char thisChar : words[i]) {
                        thisScore += score[thisChar - 'a'];
                        if (!letterLefted[thisChar - 'a']) {
                            goto loop;
                        }
                        letterLefted[thisChar - 'a']--;
                    }
                }
            }
            ans = max(ans, thisScore);
            loop:;
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List


class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        ans = 0
        letter = [0] * 26
        for l in letters:
            letter[ord(l) - ord('a')] += 1
        
        n = len(words)
        for mask in range(1 << n):
            letterLefted = letter.copy()
            thisScore = 0
            ok = True
            for i in range(n):
                if mask & (1 << i):
                    for thisChar in words[i]:
                        thisScore += score[ord(thisChar) - ord('a')]
                        if not letterLefted[ord(thisChar) - ord('a')]:
                            ok = False
                            break
                        letterLefted[ord(thisChar) - ord('a')] -= 1
            if ok:
                ans = max(ans, thisScore)
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2023/02/26/LeetCode%201255.%E5%BE%97%E5%88%86%E6%9C%80%E9%AB%98%E7%9A%84%E5%8D%95%E8%AF%8D%E9%9B%86%E5%90%88/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129232008](https://letmefly.blog.csdn.net/article/details/129232008)
